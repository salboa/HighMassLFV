#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: DecorateTau(const xAOD::TauJet *tau){

  if( !m_tauEleLLH->decorate(*tau).isSuccess() )
    if( m_debug ) Info( "DecorateTau()", "Error in TauOverlappingElectronLLHDecorator decorating tau" );

}

void HighMassLFV :: PreSelectTaus(int sysVar){

  if( m_debug ) Info( "PreselectTaus()", "Applying Pre-Selection to Taus ..." );
  
  m_Taus.clear();
  m_MetTaus->clear();
  if( m_TaSHVar.find(sysVar) == m_TaSHVar.end() ){
    if( m_debug ) Info( "PreselectTaus()", "Systematic set not found, applying nominal one (no systematics)!");
    if( m_tauSmear->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectTaus()", "TauSmearingTool variation 'empty' (Nominal)" );
    }
  }
  else{
    if( m_debug ) Info( "PreselectTaus()", "Applying variation %s", m_TaSHVarName[sysVar].c_str() );
    if( m_tauSmear->applySystematicVariation( m_TaSHVar[sysVar] ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectTaus()", "TauSmearingTool variation %s not supported", m_TaSHVarName[sysVar].c_str() );
    }
  }
  for( auto tau: *m_tauContCopy ) {
    
    m_tauTrMtc->getTruth(*tau);
    if( !m_UseData ){
      if( m_tauSmear->applyCorrection(*tau) == CP::CorrectionCode::Error ){
	Info( "PreselectTaus()", "TauSmearingTool returns Error CorrectionCode");
      }
    }
    double pt    = tau->pt();
    double eta   = tau->eta();
    double phi   = tau->phi();
    double e     = tau->e();
    int nTracks  = tau->nTracks();
    int charge   = tau->charge();
    bool isLoose = m_tauSelLoo->accept(*tau);
    double bdt   = tau->discriminant(xAOD::TauJetParameters::BDTJetScore);
    
    if( m_verbose ){
      Info( "PreselectTaus()    ", "  Tau found    --> charge = %i , pt = %f , eta = %f , phi = %f , E = %f , nTracks = %i",
            charge, pt/GeV, eta, phi, e/GeV, nTracks );
      Info( "PreselectTaus()    ", "                   isLoose = %i , JetBDTscore = %f", isLoose, bdt );
    }

    UpdateTauFlow( sysVar, TauFlow::TrigMatch, 1);

    if( pt/GeV<m_TauPt ){ tau->auxdecor<char>("isPreSel") = false; continue; }
    UpdateTauFlow( sysVar, TauFlow::Pt, 1 );
          
    if( fabs(eta)>m_TauEta ){ tau->auxdecor<char>("isPreSel") = false; continue; }
    if( fabs(eta)>1.37 && fabs(eta)<1.52 ){ tau->auxdecor<char>("isPreSel") = false; continue; }
    UpdateTauFlow( sysVar, TauFlow::Eta, 1 );
    
    if( abs(charge)!=m_TauCharge ){ tau->auxdecor<char>("isPreSel") = false; continue; }
    UpdateTauFlow( sysVar, TauFlow::Charge, 1 );
    
    if( nTracks!=1 && nTracks!=3 ){ tau->auxdecor<char>("isPreSel") = false; continue; }
    UpdateTauFlow( sysVar, TauFlow::nTracks, 1 );
    
    if(m_useBDTcut){ 
      if(bdt<m_TauBDTscore){ tau->auxdecor<char>("isPreSel") = false; continue; } 
    }
    UpdateTauFlow( sysVar, TauFlow::BDTscore, 1);

    if( !isLoose ){ tau->auxdecor<char>("isPreSel") = false; continue; }
    UpdateTauFlow( sysVar, TauFlow::JetIDWP, 1 );
    
    m_MetTaus->push_back(tau);
    
    DecorateTau(tau);
    if( !m_tauElOR->accept(*tau) ){ tau->auxdecor<char>("isPreSel") = false; continue; }
    UpdateTauFlow( sysVar, TauFlow::ElOR, 1 );
    
    tau->auxdecor<char>("isPreSel") = true;

    if( m_verbose ){
      Info( "PreselectTaus()    ", "  PRESELECTED Tau    --> charge = %i , pt = %f , eta = %f , phi = %f , E = %f , nTracks = %i",
            charge, pt/GeV, eta, phi, e/GeV, nTracks );
      Info( "PreselectTaus()    ", "                         isLoose = %i , JetBDTscore = %f", isLoose, bdt );
    }

    
  }

}

void HighMassLFV :: CheckTaus(int sysVar){

  if( m_debug ) Info( "CheckTaus()", "Checking Taus ..." );

  for( auto tau: *m_tauContCopy ) {

    if( !tau->auxdata<char>("isPreSel") ) continue;
    if( tau->auxdata<char>("isOverlap") ) continue;
    UpdateTauFlow( sysVar, TauFlow::Overlaps, 1 );

    double pt    = tau->pt();
    double eta   = tau->eta();
    double phi   = tau->phi();
    double e     = tau->e();
    int nTracks  = tau->nTracks();
    int charge   = tau->charge();
    bool isLoose = m_tauSelLoo->accept(*tau);
    double bdt   = tau->discriminant(xAOD::TauJetParameters::BDTJetScore);
      
    if( !IsTauMuonOverlap(tau) ) //continue;
      UpdateTauFlow( sysVar, TauFlow::TaMuOve, 1);
    
    if( !IsTauElecOverlap(tau) ) //continue;
      UpdateTauFlow( sysVar, TauFlow::TaElOve, 1);
    
    if( m_debug ){
      Info( "CheckTaus()    ", "  GOOD Tau     --> charge = %i , pt = %f , eta = %f , phi = %f , E = %f , nTracks = %i",
            charge, pt/GeV, eta, phi, e/GeV, nTracks );
      Info( "CheckTaus()    ", "                   isLoose = %i , JetBDTscore = %f", isLoose, bdt );
    }
    
    m_Taus.push_back(tau);
    
  }
  
}

double HighMassLFV :: GetTauRecoSF(const xAOD::IParticle *p, int sysVar){

  double m_sf = 1;
  if( p->type() != xAOD::Type::Tau ){
    if( m_debug ) Info( "GetTauRecoSF()" , "Particle is not a tau!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    if( m_TaSFVar.find(sysVar) == m_TaSFVar.end() ){
      if( m_debug ) Info( "GetTauRecoSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_tauRecoSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetTauRecoSF()", " variation 'empty' (Nominal)" );
      }
    }
    else{
      if( m_debug ) Info( "GetTauRecoSF()", "Applying variation %s", m_TaSFVarName[sysVar].c_str() );
      if( m_tauRecoSF->applySystematicVariation( m_TaSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetTauRecoSF()", " variation %s not supported", m_TaSFVarName[sysVar].c_str() );
      }
    }
    if( m_tauRecoSF->getEfficiencyScaleFactor(*tau,m_sf) == CP::CorrectionCode::Error )
      Info( "GetTauRecoSF()", " returns Error CorrectionCode");
  }
  if( m_debug ) Info( "GetTauRecoSF()" , "Reco SF = %f ", m_sf );
  
  return m_sf;
  
}

double HighMassLFV :: GetTauEleOlrSF(const xAOD::IParticle *p, int sysVar){
  
  double m_sf = 1;
  if( p->type() != xAOD::Type::Tau ){
    if( m_debug ) Info( "GetTauEleOlrSF()" , "Particle is not a tau!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    if( m_TaSFVar.find(sysVar) == m_TaSFVar.end() ){
      if( m_debug ) Info( "GetTauEleOlrSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_tauElOlrSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetTauEleOlrSF()", " variation 'empty' (Nominal)" );
      }
    }
    else{
      if( m_debug ) Info( "GetTauRecoSF()", "Applying variation %s", m_TaSFVarName[sysVar].c_str() );
      if( m_tauElOlrSF->applySystematicVariation( m_TaSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetTauEleOlrSF()", " variation %s not supported", m_TaSFVarName[sysVar].c_str() );
      }
    }
    if( m_tauElOlrSF->getEfficiencyScaleFactor(*tau,m_sf) == CP::CorrectionCode::Error )
      Info( "GetTauEleOlrSF()", " returns Error CorrectionCode");
  }
  if( m_debug ) Info( "GetTauRecoSF()" , "Reco SF = %f ", m_sf );

  return m_sf;
  
}

double HighMassLFV :: GetTauJetIDSF(const xAOD::IParticle *p, int sysVar){
  
  double m_sf = 1;
  if( p->type() != xAOD::Type::Tau ){
    if( m_debug ) Info( "GetTauJetIDSF()" , "Particle is not a tau!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    if( m_TaSFVar.find(sysVar) == m_TaSFVar.end() ){
      if( m_debug ) Info( "GetTauJetIDSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_tauJetIDSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetTauJetIDSF()", " variation 'empty' (Nominal)" );
      }
    }
    else{
      if( m_debug ) Info( "GetTauJetIDSF()", "Applying variation %s", m_TaSFVarName[sysVar].c_str() );
      if( m_tauJetIDSF->applySystematicVariation( m_TaSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetTauJetIDSF()", " variation %s not supported", m_TaSFVarName[sysVar].c_str() );
      }
    }
    if( m_tauJetIDSF->getEfficiencyScaleFactor(*tau,m_sf) == CP::CorrectionCode::Error )
      Info( "GetTauJetIDSF()", " returns Error CorrectionCode");
  }
  if( m_debug ) Info( "GetTauJetIDSF()" , "Jet ID SF = %f ", m_sf );

  return m_sf;
  
}

void HighMassLFV :: FillTauQuantities(int sysVar){

  for( uint t=0; t<m_Taus.size(); t++ ){
    const xAOD::TauJet* tau = m_Taus.at(t);
    Lep_Id.push_back( -m_TauId*LeptonCharge(tau) );
    Lep_pt.push_back( tau->pt()/GeV );
    Lep_E.push_back( tau->e()/GeV );
    Lep_eta.push_back( tau->eta() );
    Lep_etaTrk.push_back( tau->eta() );
    Lep_phi.push_back( tau->phi() );
    Lep_d0.push_back( LeptonD0(tau) );
    Lep_d0sig.push_back( LeptonD0Sign(tau) );
    Lep_z0.push_back( LeptonZ0(tau) );
    Lep_deltaz0.push_back( LeptonDeltaZ0(tau) );
    Lep_Iso.push_back( 0 );
    Lep_trkIsoPt.push_back( 9999 );
    Lep_caloIsoPt.push_back( 9999 );
    Lep_trigMat.push_back( 0 );
    Lep_nProngs.push_back( tau->nTracks() );

    Lep_TrigSF.push_back( 1. );
    Lep_TrigSF_StatUp.push_back( 1. );
    Lep_TrigSF_StatDown.push_back( 1. );
    Lep_TrigSF_SysUp.push_back( 1. );
    Lep_TrigSF_SysDown.push_back( 1. );

    Lep_RecoSF.push_back( GetTauRecoSF(tau) );
    Lep_RecoSF_StatUp.push_back( GetTauRecoSF(tau) );
    Lep_RecoSF_StatDown.push_back( GetTauRecoSF(tau) );
    Lep_RecoSF_SysUp.push_back( GetTauRecoSF(tau,Ta_SFSys::TaReco_SysUp) );
    Lep_RecoSF_SysDown.push_back( GetTauRecoSF(tau,Ta_SFSys::TaReco_SysDown) );
    Lep_RecoSF_Hpt_SysUp.push_back( GetTauRecoSF(tau,Ta_SFSys::TaRecoHpt_SysUp) );
    Lep_RecoSF_Hpt_SysDown.push_back( GetTauRecoSF(tau,Ta_SFSys::TaRecoHpt_SysDown) );

    Lep_IDSF.push_back( GetTauJetIDSF(tau) );
    Lep_IDSF_StatUp.push_back( GetTauJetIDSF(tau) );
    Lep_IDSF_StatDown.push_back( GetTauJetIDSF(tau) );
    Lep_IDSF_SysUp.push_back( GetTauJetIDSF(tau,Ta_SFSys::TaJetID_SysUp) );
    Lep_IDSF_SysDown.push_back( GetTauJetIDSF(tau,Ta_SFSys::TaJetID_SysDown) );
    Lep_IDSF_Hpt_SysUp.push_back( GetTauJetIDSF(tau,Ta_SFSys::TaJetIDHpt_SysUp) );
    Lep_IDSF_Hpt_SysDown.push_back( GetTauJetIDSF(tau,Ta_SFSys::TaJetIDHpt_SysDown) );

    Lep_IsoSF.push_back( 1. );
    Lep_IsoSF_StatUp.push_back( 1. );
    Lep_IsoSF_StatDown.push_back( 1. );
    Lep_IsoSF_SysUp.push_back( 1. );
    Lep_IsoSF_SysDown.push_back( 1.);
    
    Lep_TtvaSF.push_back( 1. );
    Lep_TtvaSF_StatUp.push_back( 1. );
    Lep_TtvaSF_StatDown.push_back( 1. );
    Lep_TtvaSF_SysUp.push_back( 1. );
    Lep_TtvaSF_SysDown.push_back( 1. );

    Lep_L1CaloSF.push_back( 1. );

    Lep_ElOlrSF.push_back( GetTauEleOlrSF(tau) );
    Lep_ElOlrSF_SysUp.push_back( GetTauEleOlrSF(tau,Ta_SFSys::TaEleOlr_SysUp) );
    Lep_ElOlrSF_SysDown.push_back( GetTauEleOlrSF(tau,Ta_SFSys::TaEleOlr_SysDown) );
  }
  if( sysVar==0 ){
    for( uint t=0; t<Lep_Id.size(); t++ ){
      if( abs(Lep_Id.at(t))==m_TauId && isBTBGood ){
	UpdateWeight( m_Chan, Weights::TaReco             , 1, Lep_RecoSF.at(t)             );
	UpdateWeight( m_Chan, Weights::TaReco_SysUp       , 1, Lep_RecoSF_SysUp.at(t)       );
	UpdateWeight( m_Chan, Weights::TaReco_SysDown     , 1, Lep_RecoSF_SysDown.at(t)     );
	UpdateWeight( m_Chan, Weights::TaReco_Hpt_SysUp   , 1, Lep_RecoSF_Hpt_SysUp.at(t)   );
	UpdateWeight( m_Chan, Weights::TaReco_Hpt_SysDown , 1, Lep_RecoSF_Hpt_SysDown.at(t) );
	UpdateWeight( m_Chan, Weights::TaID               , 1, Lep_IDSF.at(t)               );
	UpdateWeight( m_Chan, Weights::TaID_SysUp         , 1, Lep_IDSF_SysUp.at(t)         );
	UpdateWeight( m_Chan, Weights::TaID_SysDown       , 1, Lep_IDSF_SysDown.at(t)       );
	UpdateWeight( m_Chan, Weights::TaID_Hpt_SysUp     , 1, Lep_IDSF_Hpt_SysUp.at(t)     );
	UpdateWeight( m_Chan, Weights::TaID_Hpt_SysDown   , 1, Lep_IDSF_Hpt_SysDown.at(t)   );
	UpdateWeight( m_Chan, Weights::TaElOlr            , 1, Lep_ElOlrSF.at(t)            );
	UpdateWeight( m_Chan, Weights::TaElOlr_SysUp      , 1, Lep_ElOlrSF_SysUp.at(t)      );
	UpdateWeight( m_Chan, Weights::TaElOlr_SysDown    , 1, Lep_ElOlrSF_SysDown.at(t)    );
	
	if( !isBjetEvt ){
	  UpdateWeightBJ( m_Chan, Weights::TaReco             , 1, Lep_RecoSF.at(t)             );
	  UpdateWeightBJ( m_Chan, Weights::TaReco_SysUp       , 1, Lep_RecoSF_SysUp.at(t)       );
	  UpdateWeightBJ( m_Chan, Weights::TaReco_SysDown     , 1, Lep_RecoSF_SysDown.at(t)     );
	  UpdateWeightBJ( m_Chan, Weights::TaReco_Hpt_SysUp   , 1, Lep_RecoSF_Hpt_SysUp.at(t)   );
	  UpdateWeightBJ( m_Chan, Weights::TaReco_Hpt_SysDown , 1, Lep_RecoSF_Hpt_SysDown.at(t) );
	  UpdateWeightBJ( m_Chan, Weights::TaID               , 1, Lep_IDSF.at(t)               );
	  UpdateWeightBJ( m_Chan, Weights::TaID_SysUp         , 1, Lep_IDSF_SysUp.at(t)         );
	  UpdateWeightBJ( m_Chan, Weights::TaID_SysDown       , 1, Lep_IDSF_SysDown.at(t)       );
	  UpdateWeightBJ( m_Chan, Weights::TaID_Hpt_SysUp     , 1, Lep_IDSF_Hpt_SysUp.at(t)     );
	  UpdateWeightBJ( m_Chan, Weights::TaID_Hpt_SysDown   , 1, Lep_IDSF_Hpt_SysDown.at(t)   );
	  UpdateWeightBJ( m_Chan, Weights::TaElOlr            , 1, Lep_ElOlrSF.at(t)            );
	  UpdateWeightBJ( m_Chan, Weights::TaElOlr_SysUp      , 1, Lep_ElOlrSF_SysUp.at(t)      );
	  UpdateWeightBJ( m_Chan, Weights::TaElOlr_SysDown    , 1, Lep_ElOlrSF_SysDown.at(t)    );
	}
	
      }
    }
  }
  
}
