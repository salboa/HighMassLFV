#include <HighMassLFVSel/HighMassLFV.h>

/*
  xAOD::Muon::Combined       0
  xAOD::Muon::MuonStandAlone 1
  xAOD::Muon::SegmentTagged  2
  xAOD::Muon::CaloTagged     3
  xAOD::Muon::SiliconAssociatedForwardMuon 4  
*/

void HighMassLFV :: PreSelectMuons(int sysVar){

  if( m_debug ) Info( "PreselectMuons()", "Applying Pre-Selection to Muons ..." );
  
  m_Muons.clear();
  m_AddMuons.clear();
  m_MetMuons->clear();
  if( m_MuSHVar.find(sysVar) == m_MuSHVar.end() ){
    if( m_debug ) Info( "PreselectMuons()", "Systematic set not found, applying nominal one (no systematics)!");
    if( m_muSmear.at(m_year)->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectMuons()", "MuonCalibrationAndSmearingTool variation 'empty' (Nominal) not supported" );
    }
  }
  else{
    if( m_debug ) Info( "PreselectMuons()", "Applying variation %s", m_MuSHVarName[sysVar].c_str() );
    if( m_muSmear.at(m_year)->applySystematicVariation( m_MuSHVar[sysVar] ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectMuons()", "MuonCalibrationAndSmearingTool variation %s not supported", m_MuSHVarName[sysVar].c_str() );
    }
  }
  for( auto mu: *m_muonContCopy ) {
    
    if( m_muSmear.at(m_year)->applyCorrection(*mu) == CP::CorrectionCode::Error ){
      Info( "PreselectMuons()", "MuonCalibrationAndSmearingTool returns Error CorrectionCode in applying corrections");
    }
    double pt    = mu->pt();
    double eta   = mu->eta();
    double phi   = mu->phi();
    double e     = mu->e();
    int type     = mu->muonType();
            
    /*
    //isolation values 
    float isoVal = 0;
    mu->isolation(isoVal,xAOD::Iso::ptvarcone30);
    std::cout<<" ptvarcone30 = "<<isoVal<<" pt = "<<mu->pt()<<" eta = "<<mu->eta()<<std::endl;
    CP::IsolationWP *WP = m_iso->getMuonWPs().at(0);
    WP->saveCutValues();
    bool isol    = (bool)m_iso->accept(*mu);
    std::map<xAOD::Iso::IsolationType, float>* cuts = WP->cutValues();
    float cut = cuts->at(xAOD::Iso::ptvarcone30);
    //std::cout<<" ptvarcone30/pt = "<<isoVal/mu->pt()<<" iso cut value = "<<cut<<"  iso passed "<<isol<<std::endl;
    std::cout<<" ptvarcone30 =  "<<isoVal<<" iso cut value "<< cut << " iso cut value*pt = "<<cut*mu->pt() <<"  iso passed "<<isol<<std::endl;
    */
    
    if( m_verbose ){
      Info( "PreselectMuons()    ", "  Muon found    --> pt = %f , eta = %f , phi = %f , E = %f , type = %i",
	    pt/GeV, eta, phi, e/GeV, type );
    }
    
    //if( !trgmatc ) continue;
    UpdateMuFlow( sysVar, MuFlow::TrigMatch, 1 );
    
    if( type != xAOD::Muon::Combined ){ mu->auxdecor<char>("isPreSel") = false;  continue; }
    
    if( pt/GeV<m_MuPt ){ mu->auxdecor<char>("isPreSel") = false;  continue; }
    UpdateMuFlow( sysVar, MuFlow::Pt, 1 );
    
    if( !m_muSel->accept(*mu) ){ mu->auxdecor<char>("isPreSel") = false;  continue; }
    UpdateMuFlow( sysVar, MuFlow::Eta_ID_Q, 1 );
    
    if( !m_muSel->passedHighPtCuts(*mu) ){ mu->auxdecor<char>("isPreSel") = false;  continue; }
    UpdateMuFlow( sysVar, MuFlow::HighPtCut, 1 );

    double d0sig = LeptonD0Sign(mu);
    double Dz0   = LeptonDeltaZ0(mu);
    
    if( d0sig>m_MuD0SignCut ){ mu->auxdecor<char>("isPreSel") = false;  continue; }
    UpdateMuFlow( sysVar, MuFlow::D0Sign, 1 );
    
    if( Dz0>m_MuDeltaZ0 ){ mu->auxdecor<char>("isPreSel") = false;  continue; }
    UpdateMuFlow( sysVar, MuFlow::DeltaZ0, 1 );
    
    m_MetMuons->push_back(mu);
    mu->auxdecor<char>("isPreSel") = true;

    if( m_verbose ){
      Info( "PreselectMuons()    ", "  PRESELECTED Muon    --> pt = %f , eta = %f , phi = %f , E = %f , type = %i",
            pt/GeV, eta, phi, e/GeV, type );
    }
    
  }

}

void HighMassLFV :: CheckMuons(int sysVar){

  if( m_debug ) Info( "CheckMuons()", "Checking Muons ..." );
  
  for( auto mu: *m_muonContCopy ) {
    
    if( !mu->auxdata<char>("isPreSel") ) continue;
    double pt    = mu->pt();
    double eta   = mu->eta();
    double phi   = mu->phi();
    double e     = mu->e();
    int type     = mu->muonType();
    bool trgmatc = CheckMuonTriggerMatching(mu);
    bool isol    = (bool)m_iso->accept(*mu);
    double d0    = LeptonD0(mu);
    int charge   = LeptonCharge(mu);
    double d0sig = LeptonD0Sign(mu);
    double Dz0   = LeptonDeltaZ0(mu);
    
    if( m_verbose ){
      Info( "CheckMuons()    ", "  PRESELECTED Muon    --> pt = %f , eta = %f , phi = %f , E = %f , type = %i",
            pt/GeV, eta, phi, e/GeV, type );
    }
    
    if( mu->auxdata<char>("isOverlap") ){
      if( m_verbose ){
	Info( "CheckMuons()    ", "  OVERLAPPING Muon    --> pt = %f , eta = %f , phi = %f , E = %f , type = %i",
	      pt/GeV, eta, phi, e/GeV, type );
      }
      continue;
    }
    UpdateMuFlow( sysVar, MuFlow::Overlaps, 1 );
    
    if( m_debug ){ 
      Info( "CheckMuons()    ", "  GOOD Muon     --> charge = %i , pt = %f , eta = %f , phi = %f , E = %f , type = %i",
	    charge, pt/GeV, eta, phi, e/GeV, type );
      Info( "CheckMuons()    ", "                    d0 = %f , d0sig = %f , z0 = %f , quality = %i , isolation = %i , trigMatch = %i",
	    d0 , d0sig, Dz0, m_muSel->getQuality(*mu), isol, trgmatc );
    }
    
    if( m_QcdCR ){
      if( !isol ){
        m_Muons.push_back(mu);
        UpdateMuFlow( sysVar, MuFlow::Isolation, 1 );
      } 
      else{
        m_AddMuons.push_back(mu);
      }
    }
    else{
      if( isol ){
	m_Muons.push_back(mu);
	UpdateMuFlow( sysVar, MuFlow::Isolation, 1 );
      }
      else{
	m_AddMuons.push_back(mu);
      }
    }
  }
  UpdateMuFlow( sysVar, MuFlow::TightMu, (int)m_Muons.size() );
  UpdateMuFlow( sysVar, MuFlow::LooseMu, (int)m_AddMuons.size() );
  
}

double HighMassLFV :: GetMuonTriggerSF(const xAOD::IParticle *p, int sysVar){

  double m_sf = 1;
  if( p->type() != xAOD::Type::Muon ){
    if( m_debug ) Info( "GetMuonTriggerSF()" , "Particle is not a muon!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    if( isMuonTrig && CheckMuonTriggerMatching(mu) ){
      m_newMuon = new xAOD::Muon;
      m_newMuon->makePrivateStore(*mu);
      m_SelectedMuon->setStore(m_SelectedMuonAux);
      m_SelectedMuon->push_back(m_newMuon);
      
      if( m_MuSFVar.find(sysVar) == m_MuSFVar.end() ){
	if( m_debug ) Info( "GetMuonTriggerSF()", "Systematic set not found, applying nominal one (no systematics)!");
	if( m_muTrigSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
	  Info( "GetMuonTriggerSF()", "MuonTriggerScaleFactors variation 'empty' (Nominal) not supported" );
	}
      }
      else{
	if( m_debug ) Info( "GetMuonTriggerSF()", "Applying variation %s", m_MuSFVarName[sysVar].c_str() );
	if( m_muTrigSF->applySystematicVariation( m_MuSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
	  Info( "GetMuonTriggerSF()", "MuonTriggerScaleFactors variation %s not supported", m_MuSFVarName[sysVar].c_str() );
	}
      }
      if( m_muTrigSF->getTriggerScaleFactor(*m_SelectedMuon,m_sf,m_muTMstring) == CP::CorrectionCode::Error ){
	Info( "GetMuonTriggerSF()", "MuonTriggerScaleFactors returns Error CorrectionCode in getting SF");
      }
      
    }
  }
  if( m_debug ) Info( "GetMuonTriggerSF()" , "Trigger SF = %f ", m_sf );
  m_SelectedMuon->clear();
  m_newMuon = 0;
  return m_sf;
  
}

double HighMassLFV :: GetMuonRecoSF(const xAOD::IParticle *p, int sysVar){
  
  float m_sf = 1;
  if( p->type() != xAOD::Type::Muon ){
    if( m_debug ) Info( "GetMuonRecoSF()" , "Particle is not a muon!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    if( m_MuSFVar.find(sysVar) == m_MuSFVar.end() ){
      if( m_debug ) Info( "GetMuonRecoSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_muRecoSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
	Info( "GetMuonRecoSF()", "MuonEfficiencyScaleFactors variation 'empty' (Nominal) not supported" );
      }
    }
    else{
      if( m_debug ) Info( "GetMuonRecoSF()", "Applying variation %s", m_MuSFVarName[sysVar].c_str() );
      if( m_muRecoSF->applySystematicVariation( m_MuSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetMuonRecoSF()", "MuonEfficiencyScaleFactors variation %s not supported", m_MuSFVarName[sysVar].c_str() );
      }
    }
    if( m_muRecoSF->getEfficiencyScaleFactor(*mu,m_sf) == CP::CorrectionCode::Error )
      Info( "GetMuonRecoSF()", "MuonEfficiencyScaleFactors returns Error CorrectionCode in getting SF");
  }
  if( m_debug ) Info( "GetMuonRecoSF()" , "Reco SF = %f ", m_sf );
  return (double)m_sf;
  
}

double HighMassLFV :: GetBadMuonVetoSF(const xAOD::IParticle *p, int sysVar){

  float m_sf = 1;
  if( p->type() != xAOD::Type::Muon ){
    if( m_debug ) Info( "GetBadMuonVetoSF()" , "Particle is not a muon!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    if( m_MuSFVar.find(sysVar) == m_MuSFVar.end() ){
      if( m_debug ) Info( "GetBadMuonVetoSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_muBadMuSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetBadMuonVetoSF()", "MuonEfficiencyScaleFactors (BadMuonVeto) variation 'empty' (Nominal) not supported" );
      }
    }
    else{
      if( m_debug ) Info( "GetBadMuonVetoSF()", "Applying variation %s", m_MuSFVarName[sysVar].c_str() );
      if( m_muBadMuSF->applySystematicVariation( m_MuSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetMuonRecoSF()", "MuonEfficiencyScaleFactors (BadMuonVeto) variation %s not supported", m_MuSFVarName[sysVar].c_str() );
      }
    }
    if( m_muBadMuSF->getEfficiencyScaleFactor(*mu,m_sf) == CP::CorrectionCode::Error )
      Info( "GetBadMuonVetoSF()", "MuonEfficiencyScaleFactors (BadMuonVeto) returns Error CorrectionCode in getting SF");
  }
  if( m_debug ) Info( "GetBadMuonVetoSF()" , "BadMuonVeto SF = %f ", m_sf );
  return (double)m_sf;
  
}

double HighMassLFV :: GetMuonIsoSF(const xAOD::IParticle *p, int sysVar){
  
  float m_sf = 1;
  if( p->type() != xAOD::Type::Muon ){
    if( m_debug ) Info( "GetMuonRecoSF()" , "Particle is not a muon!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    if( m_MuSFVar.find(sysVar) == m_MuSFVar.end() ){
      if( m_debug ) Info( "GetMuonIsoSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_muIsoSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
	Info( "GetMuonIsoSF()", "MuonTriggerScaleFactors variation 'empty' (Nominal) not supported" );
      }
    }
    else{
      if( m_debug ) Info( "GetMuonIsoSF()", "Applying variation %s", m_MuSFVarName[sysVar].c_str() );
      if( m_muIsoSF->applySystematicVariation( m_MuSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
	Info( "GetMuonIsoSF()", "MuonEfficiencyScaleFactors variation %s not supported", m_MuSFVarName[sysVar].c_str() );
      }
    }
    if( m_muIsoSF->getEfficiencyScaleFactor(*mu,m_sf) == CP::CorrectionCode::Error ){
      Info( "GetMuonIsoSF()", "MuonEfficiencyScaleFactors returns Error CorrectionCode in getting SF");
    }
  }
  if( m_debug ) Info( "GetMuonIsoSF()", "Iso SF = %f ", m_sf );
  return (double)m_sf;
  
}

double HighMassLFV :: GetMuonTtvaSF(const xAOD::IParticle *p, int sysVar){

  float m_sf = 1;
  if( p->type() != xAOD::Type::Muon ){
    if( m_debug ) Info( "GetMuonTtvaSF()" , "Particle is not a muon!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    if( m_MuSFVar.find(sysVar) == m_MuSFVar.end() ){
      if( m_debug ) Info( "GetMuonTtvaSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_muTTVASF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetMuonTtvaSF()", "MuonTrackToVertexAssociationScaleFactors variation 'empty' (Nominal) not supported" );
      }
    }
    else{
      if( m_debug ) Info( "GetMuonTtvaSF()", "Applying variation %s", m_MuSFVarName[sysVar].c_str() );
      if( m_muTTVASF->applySystematicVariation( m_MuSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetMuonTtvaSF()", "MuonTrackToVertexAssociationScaleFactors variation %s not supported", m_MuSFVarName[sysVar].c_str() );
      }
    }
    if( m_muTTVASF->getEfficiencyScaleFactor(*mu,m_sf) == CP::CorrectionCode::Error )
      Info( "GetMuonTtvaSF()", "MuonTrackToVertexAssociationScaleFactors returns Error CorrectionCode in getting SF");
  }
  if( m_debug ) Info( "GetMuonTtvaSF()" , "TTVA SF = %f ", m_sf );
  return (double)m_sf;

}

double HighMassLFV :: GetMuonTrkIso(const xAOD::IParticle *p){
  
  float m_trkIso = 0;
  if( p->type() != xAOD::Type::Muon ){
    if( m_debug ) Info( "GetMuonTrkIso()", "Particle is not a muon!!!  returning 0" );
    return 0;
  }
  const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
  mu->isolation(m_trkIso,xAOD::Iso::ptvarcone30);
  if( m_debug ) Info( "GetMuonTrkIso()", "Track Isolation value (ptvarcone30) = %f", m_trkIso );
  return (double)m_trkIso;
  
}

double HighMassLFV :: GetMuonCaloIso(const xAOD::IParticle *p){
  
  float m_caloIso = 0;
  if( p->type() != xAOD::Type::Muon ){
    if( m_debug ) Info( "GetMuonCaloIso()" , "Particle is not a muon!!!  returning 0" );
    return 0;
  }
  const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
  mu->isolation(m_caloIso,xAOD::Iso::topoetcone20);
  if( m_debug ) Info( "GetMuonCaloIso()", "Calo Isolation value (topoetcone20) = %f", m_caloIso );
  return (double)m_caloIso;
  
}

bool HighMassLFV :: MuonBasedEventCleaning(){

  if( m_debug ) Info( "MuonBasedEventCleaning()", "Checking selected muons for bad flag");
  
  bool m_check = false;
  for( uint m=0; m<m_Muons.size(); m++ ){
    const xAOD::Muon* mu = m_Muons.at(m);
    if( m_muSel->isBadMuon(*mu) ) m_check = true;
  }
  for( uint m=0; m<m_AddMuons.size(); m++ ){
    const xAOD::Muon* mu = m_AddMuons.at(m);
    if( m_muSel->isBadMuon(*mu) ) m_check = true;
  }
  
  if( m_debug ) Info( "MuonBasedEventCleaning()", "Bad Muon found = %i", m_check );
  return m_check;
  
}

void HighMassLFV :: FillMuonQuantities(int sysVar){
  
  for( uint m=0; m<m_Muons.size(); m++ ){
    const xAOD::Muon* mu = m_Muons.at(m);
    Lep_Id.push_back( -m_MuonId*LeptonCharge(mu) );
    Lep_pt.push_back( mu->pt()/GeV );
    Lep_E.push_back( mu->e()/GeV );
    Lep_eta.push_back( mu->eta() );
    Lep_etaTrk.push_back( mu->eta() );
    Lep_phi.push_back( mu->phi() );
    Lep_d0.push_back( LeptonD0(mu) );
    Lep_d0sig.push_back( LeptonD0Sign(mu) );
    Lep_z0.push_back( LeptonZ0(mu) );
    Lep_deltaz0.push_back( LeptonDeltaZ0(mu) );
    Lep_Iso.push_back( m_iso->accept(*mu)   );
    Lep_trkIsoPt.push_back( GetMuonTrkIso(mu)/GeV );
    Lep_caloIsoPt.push_back( GetMuonCaloIso(mu)/GeV );
    Lep_trigMat.push_back( CheckMuonTriggerMatching(mu) );
    Lep_nProngs.push_back( 1 );
    
    Lep_TrigSF.push_back( GetMuonTriggerSF(mu) );
    Lep_TrigSF_StatUp.push_back( GetMuonTriggerSF(mu,Mu_SFSys::MuTrg_StatUp) );
    Lep_TrigSF_StatDown.push_back( GetMuonTriggerSF(mu,Mu_SFSys::MuTrg_StatDown) );
    Lep_TrigSF_SysUp.push_back( GetMuonTriggerSF(mu,Mu_SFSys::MuTrg_SysUp) );
    Lep_TrigSF_SysDown.push_back( GetMuonTriggerSF(mu,Mu_SFSys::MuTrg_SysDown) );

    Lep_RecoSF.push_back( GetMuonRecoSF(mu) );
    Lep_RecoSF_StatUp.push_back( GetMuonRecoSF(mu,Mu_SFSys::MuReco_StatUp) );
    Lep_RecoSF_StatDown.push_back( GetMuonRecoSF(mu,Mu_SFSys::MuReco_StatDown) );
    Lep_RecoSF_SysUp.push_back( GetMuonRecoSF(mu,Mu_SFSys::MuReco_SysUp) );
    Lep_RecoSF_SysDown.push_back( GetMuonRecoSF(mu,Mu_SFSys::MuReco_SysDown) );
    Lep_RecoSF_Hpt_SysUp.push_back( GetMuonRecoSF(mu) );
    Lep_RecoSF_Hpt_SysDown.push_back( GetMuonRecoSF(mu) );

    Lep_IDSF.push_back( 1. );
    Lep_IDSF_StatUp.push_back( 1. );
    Lep_IDSF_StatDown.push_back( 1. );
    Lep_IDSF_SysUp.push_back( 1. );
    Lep_IDSF_SysDown.push_back( 1. );
    Lep_IDSF_Hpt_SysUp.push_back( 1. );
    Lep_IDSF_Hpt_SysDown.push_back( 1. );
        
    Lep_IsoSF.push_back( GetMuonIsoSF(mu) );
    Lep_IsoSF_StatUp.push_back( GetMuonIsoSF(mu,Mu_SFSys::MuIso_StatUp) );
    Lep_IsoSF_StatDown.push_back( GetMuonIsoSF(mu,Mu_SFSys::MuIso_StatDown) );
    Lep_IsoSF_SysUp.push_back( GetMuonIsoSF(mu,Mu_SFSys::MuIso_SysUp) );
    Lep_IsoSF_SysDown.push_back( GetMuonIsoSF(mu,Mu_SFSys::MuIso_SysDown) );

    Lep_TtvaSF.push_back( GetMuonTtvaSF(mu) );
    Lep_TtvaSF_StatUp.push_back( GetMuonTtvaSF(mu,Mu_SFSys::MuTTVA_StatUp) );
    Lep_TtvaSF_StatDown.push_back( GetMuonTtvaSF(mu,Mu_SFSys::MuTTVA_StatDown) );
    Lep_TtvaSF_SysUp.push_back( GetMuonTtvaSF(mu,Mu_SFSys::MuTTVA_SysUp) );
    Lep_TtvaSF_SysDown.push_back( GetMuonTtvaSF(mu,Mu_SFSys::MuTTVA_SysDown) );
    
    Lep_BadMuSF.push_back( GetBadMuonVetoSF(mu) );
    //add sys if exists
    
    Lep_L1CaloSF.push_back( 1.);

    Lep_ElOlrSF.push_back( 1. );
    Lep_ElOlrSF_SysUp.push_back( 1. );
    Lep_ElOlrSF_SysDown.push_back( 1. );
  }
  
  if( sysVar==0 ){
    for( uint m=0; m<Lep_Id.size(); m++ ){
      if( abs(Lep_Id.at(m))==m_MuonId && isBTBGood ){
	UpdateWeight( m_Chan, Weights::MuTrig         , 1, Lep_TrigSF.at(m)          );
	UpdateWeight( m_Chan, Weights::MuTrig_StatUp  , 1, Lep_TrigSF_StatUp.at(m)   );
	UpdateWeight( m_Chan, Weights::MuTrig_StatDown, 1, Lep_TrigSF_StatDown.at(m) );
	UpdateWeight( m_Chan, Weights::MuTrig_SysUp   , 1, Lep_TrigSF_SysUp.at(m)    );
	UpdateWeight( m_Chan, Weights::MuTrig_SysDown , 1, Lep_TrigSF_SysDown.at(m)  );

	UpdateWeight( m_Chan, Weights::MuReco         , 1, Lep_RecoSF.at(m)          );
	UpdateWeight( m_Chan, Weights::MuReco_StatUp  , 1, Lep_RecoSF_StatUp.at(m)   );
	UpdateWeight( m_Chan, Weights::MuReco_StatDown, 1, Lep_RecoSF_StatDown.at(m) );
	UpdateWeight( m_Chan, Weights::MuReco_SysUp   , 1, Lep_RecoSF_SysUp.at(m)    );
	UpdateWeight( m_Chan, Weights::MuReco_SysDown , 1, Lep_RecoSF_SysDown.at(m)  );

	UpdateWeight( m_Chan, Weights::MuIso         , 1, Lep_IsoSF.at(m)          );
	UpdateWeight( m_Chan, Weights::MuIso_StatUp  , 1, Lep_IsoSF_StatUp.at(m)   );
	UpdateWeight( m_Chan, Weights::MuIso_StatDown, 1, Lep_IsoSF_StatDown.at(m) );
	UpdateWeight( m_Chan, Weights::MuIso_SysUp   , 1, Lep_IsoSF_SysUp.at(m)    );
	UpdateWeight( m_Chan, Weights::MuIso_SysDown , 1, Lep_IsoSF_SysDown.at(m)  );

	UpdateWeight( m_Chan, Weights::MuTTVA         , 1, Lep_TtvaSF.at(m)          );
        UpdateWeight( m_Chan, Weights::MuTTVA_StatUp  , 1, Lep_TtvaSF_StatUp.at(m)   );
        UpdateWeight( m_Chan, Weights::MuTTVA_StatDown, 1, Lep_TtvaSF_StatDown.at(m) );
        UpdateWeight( m_Chan, Weights::MuTTVA_SysUp   , 1, Lep_TtvaSF_SysUp.at(m)    );
        UpdateWeight( m_Chan, Weights::MuTTVA_SysDown , 1, Lep_TtvaSF_SysDown.at(m)  );
	
	if( !isBjetEvt ){
	  UpdateWeightBJ( m_Chan, Weights::MuTrig         , 1, Lep_TrigSF.at(m)          );
	  UpdateWeightBJ( m_Chan, Weights::MuTrig_StatUp  , 1, Lep_TrigSF_StatUp.at(m)   );
	  UpdateWeightBJ( m_Chan, Weights::MuTrig_StatDown, 1, Lep_TrigSF_StatDown.at(m) );
	  UpdateWeightBJ( m_Chan, Weights::MuTrig_SysUp   , 1, Lep_TrigSF_SysUp.at(m)    );
	  UpdateWeightBJ( m_Chan, Weights::MuTrig_SysDown , 1, Lep_TrigSF_SysDown.at(m)  );
	  
	  UpdateWeightBJ( m_Chan, Weights::MuReco         , 1, Lep_RecoSF.at(m)          );
	  UpdateWeightBJ( m_Chan, Weights::MuReco_StatUp  , 1, Lep_RecoSF_StatUp.at(m)   );
	  UpdateWeightBJ( m_Chan, Weights::MuReco_StatDown, 1, Lep_RecoSF_StatDown.at(m) );
	  UpdateWeightBJ( m_Chan, Weights::MuReco_SysUp   , 1, Lep_RecoSF_SysUp.at(m)    );
	  UpdateWeightBJ( m_Chan, Weights::MuReco_SysDown , 1, Lep_RecoSF_SysDown.at(m)  );
	
	  UpdateWeightBJ( m_Chan, Weights::MuIso         , 1, Lep_IsoSF.at(m)          );
	  UpdateWeightBJ( m_Chan, Weights::MuIso_StatUp  , 1, Lep_IsoSF_StatUp.at(m)   );
	  UpdateWeightBJ( m_Chan, Weights::MuIso_StatDown, 1, Lep_IsoSF_StatDown.at(m) );
	  UpdateWeightBJ( m_Chan, Weights::MuIso_SysUp   , 1, Lep_IsoSF_SysUp.at(m)    );
	  UpdateWeightBJ( m_Chan, Weights::MuIso_SysDown , 1, Lep_IsoSF_SysDown.at(m)  );
	
	  UpdateWeightBJ( m_Chan, Weights::MuTTVA         , 1, Lep_TtvaSF.at(m)          );
	  UpdateWeightBJ( m_Chan, Weights::MuTTVA_StatUp  , 1, Lep_TtvaSF_StatUp.at(m)   );
	  UpdateWeightBJ( m_Chan, Weights::MuTTVA_StatDown, 1, Lep_TtvaSF_StatDown.at(m) );
	  UpdateWeightBJ( m_Chan, Weights::MuTTVA_SysUp   , 1, Lep_TtvaSF_SysUp.at(m)    );
	  UpdateWeightBJ( m_Chan, Weights::MuTTVA_SysDown , 1, Lep_TtvaSF_SysDown.at(m)  );
	}
      }
    }
  }
  
}
