#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: PreSelectJets(int sysVar){

  if( m_debug ) Info( "PreselectJets()", "Applying Pre-Selection to Jets ..." );
  
  m_Jets.clear();
  if( m_JtSHVar.find(sysVar) == m_JtSHVar.end() ){
    if( m_debug ) Info( "PreselectJets()", "Systematic set not found, applying nominal one (no systematics)!");
    if( m_jetSmear->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectJets()", "JetSmearingTool variation 'empty' (Nominal) not supported" );
    }
  }
  else{
    if( m_debug ) Info( "PreselectJets()", "Applying variation %s", m_JtSHVarName[sysVar].c_str() );
    if( m_jetSmear->applySystematicVariation( m_JtSHVar[sysVar] ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectJets()", "JetSmearingTool variation %s not supported", m_JtSHVarName[sysVar].c_str() );
    }
  }
  if( m_JtUNVar.find(sysVar) == m_JtUNVar.end() ){
    if( m_debug ) Info( "PreselectJets()", "Uncertanties Systematic set not found, applying nominal one (no systematics)!");
    if( m_jetUnc->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectJets()", "JetUncertanties Tool variation 'empty' (Nominal) not supported" ); //JetUncertaintiesTool
    }
  }  
  else{
    if( m_debug ) Info( "PreselectJets()", "Applying Uncertanties variation %s", m_JtUNVarName[sysVar].c_str() );
    if( m_jetUnc->applySystematicVariation( m_JtUNVar[sysVar] ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectJets()", "JetUncertanties Tool variation %s not supported", m_JtUNVarName[sysVar].c_str() );
    }
  }

  for( auto jt: *m_jetContCopy ) { //auto specifier, type deduced
    
    if( m_jetCalib->applyCalibration(*jt) == CP::CorrectionCode::Error ){
      Info( "PreselectJets()", "JetCalibrationTool returns Error CorrectionCode in applying corrections");
    }
    float jvt = m_jetVtxTagUp->updateJvt(*jt);
    jt->auxdecor<float>("Jvt") = jvt;
    
    if( !m_UseData ){
      if( m_jetSmear->applyCorrection(*jt) == CP::CorrectionCode::Error ){
    	Info( "PreselectJets()", "JetSmearingTool returns Error CorrectionCode in applying corrections");
      }
      if( m_jetUnc->applyCorrection(*jt) == CP::CorrectionCode::Error ){
      	Info( "PreselectJets()", "JetUncertainties returns Error CorrectionCode in applying corrections");
      }
    }
  }
  if( m_jetFrwJvtTool->modify(*m_jetContCopy)!=0 ){
  Info( "PreselectJets()", "JetForwardJvtTool failed to apply changes to jet container" );
  }
  for( auto jt: *m_jetContCopy ) {

    bool clean   = m_jetClean->accept(*jt);
    double pt    = jt->pt();
    double eta   = JetEta(jt);
    double etaEM = JetEta(jt,true);
    double phi   = jt->phi();
    int nTracks  = jt->numConstituents();
    
    if( m_verbose ){
      Info( "PreselectJets()    ", "  Jet found    --> pt = %f , etaEM = %f , eta = %f , phi = %f , clean = %i , nTracks = %i",
	    pt/GeV, etaEM, eta, phi, (int)clean, nTracks );
    }
    
    if( pt/GeV<m_JetPt ){ jt->auxdecor<char>("isPreSel") = false;  continue; }
    UpdateJetFlow( sysVar, JtFlow::Pt, 1 );

    if( fabs(eta)>m_JetEta ){ jt->auxdecor<char>("isPreSel") = false;  continue; }
    UpdateJetFlow( sysVar, JtFlow::Eta, 1 );
    
    jt->auxdecor<char>("isPreSel") = true;
    
    if( m_verbose ){
      Info( "PreselectJets()    ", "  PRESELECTED Jet   --> pt = %f , etaEM = %f , eta = %f , phi = %f , clean = %i , nTracks = %i",
            pt/GeV, etaEM, eta, phi, (int)clean, nTracks );
    }

  }
  
}

void HighMassLFV :: CheckJets(int sysVar){

  if( m_debug ) Info( "CheckJets()", "Checking Jets ..." );

  for( auto jt: *m_jetContCopy ) {

    if( !jt->auxdata<char>("isPreSel") ) continue;
    bool clean   = m_jetClean->accept(*jt);
    double pt    = jt->pt();
    double eta   = JetEta(jt);
    double etaEM = JetEta(jt,true);
    double phi   = jt->phi();
    int nTracks  = jt->numConstituents();
    float jvt    = jt->auxdata<float>("Jvt");
    
    if( m_verbose )
      Info( "CheckJets()    ", "  Preselected Jet     --> pt = %f , etaEM = %f , eta = %f , phi = %f , jvt = %f , clean = %i, nTracks = %i",
	    pt/GeV, etaEM, eta, phi, jvt, (int)clean, nTracks );
    
    if( jt->auxdata<char>("isOverlap") ){
      if( m_verbose ) Info( "CheckJets()    ", "  OVERLAPPING Jet     --> pt = %f , etaEM = %f , eta = %f , phi = %f , jvt = %f , clean = %i, nTracks = %i",
			    pt/GeV, etaEM, eta, phi, jvt, (int)clean, nTracks );
      continue;
    }
    UpdateJetFlow( sysVar, JtFlow::Overlaps, 1 );    
    
      bool jetelOv = IsJetElectronOverlap(jt);
    if( !jetelOv ) //continue;
      UpdateJetFlow( sysVar, JtFlow::JetElOverlap, 1 );

    bool jettauOv = IsJetTauOverlap(jt);
    if( !jettauOv ) //continue;
      UpdateJetFlow( sysVar, JtFlow::JetTauOverlap, 1 );

    bool jetmuOv = IsJetMuonOverlap(jt);
    if( !jetmuOv ) //continue;
      UpdateJetFlow( sysVar, JtFlow::JetMuOverlap, 1 );

    JetBasedEventCleaning(jt, jvt);
    
    bool jvtPass = true;
    if( pt/GeV<m_JetPtJVT && fabs(etaEM)<m_JetEtaJVT )
      if( jvt<m_JetJVT ) jvtPass = false;
    if(!jvtPass) continue;
    UpdateJetFlow( sysVar, JtFlow::JVT, 1 );
    //std::cout<<"passed JVT"<<std::endl;

    if( !clean ) continue;
    UpdateJetFlow( sysVar, JtFlow::Clean, 1 );
    //std::cout<<"passed clean"<<std::endl;
    
    if( IsBTaggedJet(jt) )
      UpdateJetFlow( sysVar, JtFlow::Bjet, 1 );

    if( m_debug ){
      Info( "CheckJets()    ", "  GOOD Jet     --> pt = %f , etaEM = %f , eta = %f , phi = %f , jvt = %f , clean = %i, nTracks = %i", 
	    pt/GeV, etaEM, eta, phi, jvt, (int)clean, nTracks );
      Info( "CheckJets()    ", "                   jvtPass = %i , jet-el Overlap = %i , jet-tau Overlap = %i , jet-mu Overlap = %i",
	    (int)jvtPass, (int)jetelOv, (int)jettauOv, (int)jetmuOv );
    }
    m_Jets.push_back(jt);
    
  }

}

bool HighMassLFV :: IsJetElectronOverlap(const xAOD::Jet* jet){
  
  bool m_check = false;
  for(uint e=0; e<m_Electrons.size(); e++){
    const xAOD::Electron *el = m_Electrons.at(e);
    if( CheckJetLepDR(jet, el) ){
      m_check = true;
      break;
    }
  }
  for(uint e=0; e<m_AddElectrons.size(); e++){
    const xAOD::Electron *el = m_AddElectrons.at(e);
    if( CheckJetLepDR(jet, el) ){
      m_check = true;
      break;
    }
  } 
  if( m_debug ) Info( "IsJetElectronOverlap()", "Jet-Electron overlap = %i" , m_check ); 
  if( m_check ) 
    if( m_debug ) Info( "IsJetElectronOverlap()", "Rejecting jet" );
    
  return m_check;
  
}

bool HighMassLFV :: IsJetTauOverlap(const xAOD::Jet* jet){

  bool m_check = false;
  for(uint t=0; t<m_Taus.size(); t++){
    const xAOD::TauJet *tau = m_Taus.at(t);
    if( CheckJetLepDR(jet, tau) ){
      m_check = true;
      break;
    }
  }
  if( m_debug ) Info( "IsJetTauOverlap()", "Jet-Tau overlap = %i" , m_check );
  if( m_check )
    if( m_debug ) Info( "IsJetTauOverlap()", "Rejecting jet" );

  return m_check;

}

bool HighMassLFV :: IsJetMuonOverlap(const xAOD::Jet* jet){

  bool m_check = false;
  for(uint m=0; m<m_Muons.size(); m++){
    const xAOD::Muon *mu = m_Muons.at(m);
    if( CheckJetLepDR(jet,mu) ){
      m_check = true;
      break;
    }
  }
  for(uint m=0; m<m_AddMuons.size(); m++){
    const xAOD::Muon *mu = m_AddMuons.at(m);
    if( CheckJetLepDR(jet, mu) ){
      m_check = true;
      break;
    }
  }  
  if( m_debug ) Info( "IsJetMuonOverlap()", "Jet-Muon overlap = %i" , m_check );
  if( m_check )
    if( m_debug ) Info( "IsJetMuonOverlap()", "Rejecting jet" );

  return m_check;
  
}

double HighMassLFV :: JetsScaleFactor(bool useBtag){
  
  double m_sf = 1;
  if( m_UseWgt ){
    for(uint j=0; j<m_Jets.size(); j++){
      const xAOD::Jet* jt = m_Jets.at(j);
      m_sf *= GetJetJvtSF(jt);
      if( useBtag )
	m_sf *= GetBtagSF(jt);
    }
  }
  if( m_debug ) Info( "JetsScaleFactor()" ,"Jets SF (total) = %f", m_sf );
  return m_sf;
  
}

double HighMassLFV :: GetBtagDiscriminant(const xAOD::Jet* jet){
  
  double m_bjetMvx = -1;
  jet->btagging()->MVx_discriminant( "MV2c10", m_bjetMvx );
  if( m_verbose ) Info( "GetBtagDiscriminant()", "Mvx discriminant values = %f", m_bjetMvx );
  return m_bjetMvx;
  
}

bool HighMassLFV :: IsBTaggedJet(const xAOD::Jet* jet){
  
  bool m_check = false;
  if( m_btagSel->accept(jet) )
    m_check = true;
  return m_check;
  
}

double HighMassLFV :: GetJetJvtSF(const xAOD::Jet* jet, int sysVar){

  float m_effsf = 1, m_ineffsf = 1, m_sf = 1;
  if( m_UseWgt){
    if( m_JtSFVar.find(sysVar) == m_JtSFVar.end() ){
      if( m_debug ) Info( "GetJetJvtSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_jetJvtSF->sysApplySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetJetJvtSF()", "JetJvyEfficiencyTool variation 'empty' (Nominal) not supported" );
      }
    }
    else{
      if( m_debug ) Info( "GetJetJvtSF()", "Applying variation %s", m_JtSFVarName[sysVar].c_str() );
      if( m_jetJvtSF->sysApplySystematicVariation( m_JtSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetJetJvtSF()", "JetJvtEfficiencyTool variation %s not supported", m_JtSFVarName[sysVar].c_str() );
      }
    }
    if( m_jetJvtSF->passesJvtCut(*jet) ){
      if( m_jetJvtSF->getEfficiencyScaleFactor(*jet,m_effsf) == CP::CorrectionCode::Error )
	Info( "GetJetJvt()", "JetJvtEfficiencyTool returns Error CorrectionCode in getting SF");
    }
    else{
      if( m_jetJvtSF->getInefficiencyScaleFactor(*jet,m_ineffsf) == CP::CorrectionCode::Error )
	Info( "GetJetJvt()", "JetJvtEfficiencyTool returns Error CorrectionCode in getting SF");
    }
    m_sf = m_effsf*m_ineffsf;
  }
  if( m_debug ) Info( "GetJetJvtSF()", "JevtJvt SF (Eff*Ineff) = %f x %f = %f", m_effsf, m_ineffsf, m_sf );
  return (double)m_sf;
  
}

double HighMassLFV :: GetBtagSF(const xAOD::Jet* jet, int sysVar){
  
  float m_sf = 1;
  if( m_UseWgt ){
    if( m_JtSFVar.find(sysVar) == m_JtSFVar.end() ){
      if( m_debug ) Info( "GetBtagSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_btagSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
	Info( "GetBtagSF()", "BTaggingEfficiencyTool variation 'empty' (Nominal) not supported" );
      }
    }
    else{
      if( m_debug ) Info( "GetBtagSF()", "Applying variation %s", m_JtSFVarName[sysVar].c_str() );
      if( m_btagSF->applySystematicVariation( m_JtSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
	Info( "GetBtagSF()", "BTaggingEfficiencyTool variation %s not supported", m_JtSFVarName[sysVar].c_str() );
      }
    }
    if( IsBTaggedJet(jet) ){
      if( m_btagSF->getScaleFactor(*jet,m_sf) == CP::CorrectionCode::Error )
    	Info( "GetBtagSF()", "BTaggingEfficiencyTool returns Error CorrectionCode in getting SF");
    }
    else{
      if( m_btagSF->getInefficiencyScaleFactor(*jet,m_sf) == CP::CorrectionCode::Error )
    	Info( "GetBtagSF()", "BTaggingEfficiencyTool returns Error CorrectionCode in getting SF");
    }
  }
  if( m_debug ) Info( "GetBtagSF()", "Btag SF = %f", m_sf );
  return (double)m_sf;
  
}

double HighMassLFV :: JetEta(const xAOD::Jet *jet, bool EMScale){
  
  double m_eta = 0;
  if(EMScale) m_eta = jet->getAttribute<float>("DetectorEta");
  else m_eta = jet->eta();
  return m_eta;
  
}

void HighMassLFV :: JetBasedEventCleaning(const xAOD::Jet *jet, double jvt){
  
  if( jet->pt()/GeV<m_JetPtJVT ){
    if( fabs(JetEta(jet,true))<m_JetEtaJVT ){
      if( !m_jetClean->accept(*jet) && jvt>=m_JetJVT ) m_badJetEvt = true;
    }
    else if( fabs(JetEta(jet,true))>=m_JetEtaJVT ){
      if( !m_jetClean->accept(*jet) ) m_badJetEvt = true;
    }
  }
  if( jet->pt()/GeV>=m_JetPtJVT && !m_jetClean->accept(*jet) ) m_badJetEvt = true;

  if( m_debug ) Info( "JetBasedEventCleaning()", " is Bad Jet Found = %i", m_badJetEvt );
  
}

void HighMassLFV :: FillJetQuantities(int sysVar){

  if( m_debug ) Info( "FillJetQuantities()", "Filling jet quantities" );
  
  double m_nom=1, m_jvt=1;
  double m_beffup=1, m_ceffup=1, m_leffup=1, m_excup=1, m_exup=1, m_jvtup=1;
  double m_beffdw=1, m_ceffdw=1, m_leffdw=1, m_excdw=1, m_exdw=1, m_jvtdw=1;
  for(uint j=0; j<m_Jets.size(); j++){
    const xAOD::Jet*jet = m_Jets.at(j);
    Jet_pt.push_back( jet->pt()/GeV );
    Jet_eta.push_back( JetEta(jet) );
    Jet_etaEM.push_back( JetEta(jet,true) );
    Jet_phi.push_back( jet->phi() );
    Jet_JvtSF.push_back( GetJetJvtSF(jet) );
    Jet_JvtSF_SysUp.push_back( GetJetJvtSF(jet,Jt_SFSys::JtJvt_SysUp) );
    Jet_JvtSF_SysDown.push_back( GetJetJvtSF(jet,Jt_SFSys::JtJvt_SysDown) );
    Jet_isBjet.push_back( IsBTaggedJet(jet) );
    Jet_BtagSF.push_back( GetBtagSF(jet) );
    Jet_BtagSF_Beff_SysUp.push_back( GetBtagSF(jet,Jt_SFSys::JtBeff_SysUp) );
    Jet_BtagSF_Beff_SysDown.push_back( GetBtagSF(jet,Jt_SFSys::JtBeff_SysDown) );
    Jet_BtagSF_Ceff_SysUp.push_back( GetBtagSF(jet,Jt_SFSys::JtCeff_SysUp) );
    Jet_BtagSF_Ceff_SysDown.push_back( GetBtagSF(jet,Jt_SFSys::JtCeff_SysDown) );
    Jet_BtagSF_Leff_SysUp.push_back( GetBtagSF(jet,Jt_SFSys::JtLeff_SysUp) );
    Jet_BtagSF_Leff_SysDown.push_back( GetBtagSF(jet,Jt_SFSys::JtLeff_SysDown) );
    Jet_BtagSF_ExtCeff_SysUp.push_back( GetBtagSF(jet,Jt_SFSys::JtExtCeff_SysUp) );
    Jet_BtagSF_ExtCeff_SysDown.push_back( GetBtagSF(jet,Jt_SFSys::JtExtCeff_SysDown) );
    Jet_BtagSF_ExtEff_SysUp.push_back( GetBtagSF(jet,Jt_SFSys::JtExtEff_SysUp) );
    Jet_BtagSF_ExtEff_SysDown.push_back( GetBtagSF(jet,Jt_SFSys::JtExtEff_SysDown) );
    m_nom    *= Jet_BtagSF.at(j);
    m_beffup *= Jet_BtagSF_Beff_SysUp.at(j);
    m_beffdw *= Jet_BtagSF_Beff_SysDown.at(j);
    m_ceffup *= Jet_BtagSF_Ceff_SysUp.at(j);
    m_ceffdw *= Jet_BtagSF_Ceff_SysDown.at(j);
    m_leffup *= Jet_BtagSF_Leff_SysUp.at(j);
    m_leffdw *= Jet_BtagSF_Leff_SysDown.at(j);
    m_excup  *= Jet_BtagSF_ExtCeff_SysUp.at(j);
    m_excdw  *= Jet_BtagSF_ExtCeff_SysDown.at(j);
    m_exup   *= Jet_BtagSF_ExtEff_SysUp.at(j);
    m_exdw   *= Jet_BtagSF_ExtEff_SysDown.at(j);
    m_jvt    *= Jet_JvtSF.at(j);
    m_jvtup  *= Jet_JvtSF_SysUp.at(j);
    m_jvtdw  *= Jet_JvtSF_SysDown.at(j);

  }
  if( sysVar==0 && isBTBGood ){
    UpdateWeight( m_Chan, Weights::JtJvt                  , 1, m_jvt    );
    UpdateWeight( m_Chan, Weights::JtJvt_SysUp            , 1, m_jvtup  );
    UpdateWeight( m_Chan, Weights::JtJvt_SysDown          , 1, m_jvtdw  );
    UpdateWeight( m_Chan, Weights::BtagSF                 , 1, m_nom    );
    UpdateWeight( m_Chan, Weights::BtagSF_Beff_SysUp      , 1, m_beffup );
    UpdateWeight( m_Chan, Weights::BtagSF_Beff_SysDown    , 1, m_beffdw );
    UpdateWeight( m_Chan, Weights::BtagSF_Ceff_SysUp      , 1, m_ceffup );
    UpdateWeight( m_Chan, Weights::BtagSF_Ceff_SysDown    , 1, m_ceffdw );
    UpdateWeight( m_Chan, Weights::BtagSF_Leff_SysUp      , 1, m_leffup );
    UpdateWeight( m_Chan, Weights::BtagSF_Leff_SysDown    , 1, m_leffdw );
    UpdateWeight( m_Chan, Weights::BtagSF_ExtCeff_SysUp   , 1, m_excup  );
    UpdateWeight( m_Chan, Weights::BtagSF_ExtCeff_SysDown , 1, m_excdw  );
    UpdateWeight( m_Chan, Weights::BtagSF_ExtEff_SysUp    , 1, m_exup   );
    UpdateWeight( m_Chan, Weights::BtagSF_ExtEff_SysDown  , 1, m_exdw   );
    if( !isBjetEvt ){
      UpdateWeightBJ( m_Chan, Weights::JtJvt                  , 1, m_jvt    );
      UpdateWeightBJ( m_Chan, Weights::JtJvt_SysUp            , 1, m_jvtup  );
      UpdateWeightBJ( m_Chan, Weights::JtJvt_SysDown          , 1, m_jvtdw  );
      UpdateWeightBJ( m_Chan, Weights::BtagSF                 , 1, m_nom    );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_Beff_SysUp      , 1, m_beffup );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_Beff_SysDown    , 1, m_beffdw );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_Ceff_SysUp      , 1, m_ceffup );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_Ceff_SysDown    , 1, m_ceffdw );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_Leff_SysUp      , 1, m_leffup );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_Leff_SysDown    , 1, m_leffdw );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_ExtCeff_SysUp   , 1, m_excup  );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_ExtCeff_SysDown , 1, m_excdw  );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_ExtEff_SysUp    , 1, m_exup   );
      UpdateWeightBJ( m_Chan, Weights::BtagSF_ExtEff_SysDown  , 1, m_exdw   );
    }
  }
  
}
