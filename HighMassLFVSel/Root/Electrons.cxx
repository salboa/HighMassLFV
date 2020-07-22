#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: PreSelectElectrons(int sysVar){
  
  if( m_debug ) Info( "PreselectElectrons()", "Applying Pre-Selection to Electrons ..." );

  m_Electrons.clear();
  m_AddElectrons.clear();
  m_MetElectrons->clear();
  if( m_ElSHVar.find(sysVar) == m_ElSHVar.end() ){
    if( m_debug ) Info( "PreselectElectrons()", "Systematic set not found, applying nominal one (no systematics)!");
    if( m_elSmear->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectElectrons()", "ElectronCalibrationAndSmearingTool variation 'empty' (Nominal)" );
    }
  }
  else{
    if( m_debug ) Info( "PreselectElectrons()", "Applying variation %s", m_ElSHVarName[sysVar].c_str() );
    if( m_elSmear->applySystematicVariation( m_ElSHVar[sysVar] ) == CP::SystematicCode::Unsupported ){
      Info( "PreselectElectrons()", "ElectronCalibrationAndSmearingTool variation %s not supported", m_ElSHVarName[sysVar].c_str() );
    }
  }
  
  for( auto el: *m_elecContCopy ) {
    if( m_elSmear->applyCorrection(*el) == CP::CorrectionCode::Error ){
    Info( "PreselectElectrons()", "ElectronCalibrationAndSmearingTool returns Error CorrectionCode");
    }
    if( m_isoCorr->applyCorrection(*el) == CP::CorrectionCode::Error ){
      Info( "PreselectElectrons()", "IsolationCorrectionTool returns Error CorrectionCode");
    }
    
    double pt     = el->pt();
    double eta    = LeptonEta(el,true);
    double etaTrk = LeptonEta(el);
    double phi    = el->phi();
    double e      = el->e();
    int author    = el->author();
    double Dz0    = LeptonDeltaZ0(el);
    int charge    = LeptonCharge(el);
    double d0sig  = LeptonD0Sign(el);
    bool trgmatc  = CheckElectronTriggerMatching(el);
    bool isol     = (bool)m_iso->accept(*el);
    bool ObjQual  = el->isGoodOQ(xAOD::EgammaParameters::BADCLUSELECTRON);
    bool isTight  = false;
    bool isMedium = false;
    if(m_evalEgQuant){
      isTight  = m_elSelTig->accept(el);
      isMedium = m_elSelMed->accept(el);
    }
    else{
      isTight  = el->auxdata<char>("DFCommonElectronsLHTight");
      isMedium = el->auxdata<char>("DFCommonElectronsLHMedium");
    }
    
    if( m_verbose ){
      Info( "PreselectElectrons()", "  Electron found --> charge = %i , pt = %f , eta = %f , etaTrk = %f , phi = %f , E = %f", 
	    charge, pt/GeV, eta, etaTrk, phi, e/GeV );
      Info( "PreselectElectrons()", "                    d0sig = %f , z0 = %f , author = %i , isolation = %i , quality = %i , trigMatch = %i",
            d0sig, Dz0, author, isol, ObjQual , trgmatc );
    }
    
    //if( !trgmatc ) continue;
    UpdateElFlow( sysVar, ElFlow::TrigMatch, 1 );
    
    if( author!=1 && author!=16){ el->auxdecor<char>("isPreSel") = false; continue; }
    UpdateElFlow( sysVar, ElFlow::Author, 1 );

    if( pt/GeV<m_ElPt ){ el->auxdecor<char>("isPreSel") = false; continue; }
    UpdateElFlow( sysVar, ElFlow::Pt, 1 );

    if( fabs(eta)>m_ElEta ){ el->auxdecor<char>("isPreSel") = false; continue; }
    if( fabs(eta)>1.37 && fabs(eta)<1.52 ){ el->auxdecor<char>("isPreSel") = false; continue; }
    UpdateElFlow( sysVar, ElFlow::Eta, 1 );
    
    if( !ObjQual ){ el->auxdecor<char>("isPreSel") = false; continue; }
    UpdateElFlow( sysVar, ElFlow::ObjectQ, 1 );
    
    if( !isTight && !isMedium ){ el->auxdecor<char>("isPreSel") = false; continue; }
    UpdateElFlow( sysVar, ElFlow::ElecID, 1 );
    
    if( d0sig>m_ElD0SignCut ){ el->auxdecor<char>("isPreSel") = false; continue; }
    UpdateElFlow( sysVar, ElFlow::D0Sign, 1 );
    
    if( Dz0>m_ElDeltaZ0 ){ el->auxdecor<char>("isPreSel") = false; continue; }
    UpdateElFlow( sysVar, ElFlow::DeltaZ0, 1 );
    
    m_MetElectrons->push_back(el);
    
    el->auxdecor<char>("isPreSel") = true;
    
    if( m_verbose ){
      Info( "PreselectElectrons()", "  PRESELECTED Electron --> charge = %i , pt = %f , eta = %f , etaTrk = %f , phi = %f , E = %f",
            charge, pt/GeV, eta, etaTrk, phi, e/GeV );
      Info( "PreselectElectrons()", "                           d0sig = %f , z0 = %f , author = %i , isolation = %i , quality = %i , trigMatch = %i",
            d0sig, Dz0, author, isol, ObjQual , trgmatc );
      
    }
  }
  
}

void HighMassLFV :: CheckElectrons(int sysVar){

  if( m_debug ) Info( "CheckElectrons()", "Checking Electrons ..." );

  for( auto el: *m_elecContCopy ) {
    
    if( !el->auxdata<char>("isPreSel") ) continue;
    double pt     = el->pt();
    double eta    = LeptonEta(el,true);
    double etaTrk = LeptonEta(el);
    double phi    = el->phi();
    double e      = el->e();
    int author    = el->author();
    double Dz0    = LeptonDeltaZ0(el);
    int charge    = LeptonCharge(el);
    double d0sig  = LeptonD0Sign(el);
    bool trgmatc  = CheckElectronTriggerMatching(el);
    bool isol     = (bool)m_iso->accept(*el);
    bool ObjQual  = el->isGoodOQ(xAOD::EgammaParameters::BADCLUSELECTRON);
    bool isTight  = false;
    bool isMedium = false;
    if(m_evalEgQuant){
      isTight  = m_elSelTig->accept(el);
      isMedium = m_elSelMed->accept(el);
    }
    else{
      isTight  = el->auxdata<char>("DFCommonElectronsLHTight");
      isMedium = el->auxdata<char>("DFCommonElectronsLHMedium");
    }
    
    if( m_verbose ){
      Info( "CheckElectrons()", "  PRESELECTED Electron --> charge = %i , pt = %f , eta = %f , etaTrk = %f , phi = %f , E = %f",
	    charge, pt/GeV, eta, etaTrk, phi, e/GeV );
      Info( "CheckElectrons()", "                           d0sig = %f , z0 = %f , author = %i , isolation = %i , quality = %i , trigMatch = %i",
	    d0sig, Dz0, author, isol, ObjQual , trgmatc );

    }
    
    if( el->auxdata<char>("isOverlap") ){
      if( m_verbose ){
	Info( "CheckElectrons()", "  OVERLAPPING Electron --> charge = %i , pt = %f , eta = %f , etaTrk = %f , phi = %f , E = %f",
	      charge, pt/GeV, eta, etaTrk, phi, e/GeV );
	Info( "CheckElectrons()", "                           d0sig = %f , z0 = %f , author = %i , isolation = %i , quality = %i , trigMatch = %i",
	      d0sig, Dz0, author, isol, ObjQual , trgmatc );
	
      }
      continue;
    }
    UpdateElFlow( sysVar, ElFlow::Overlaps, 1 );
    
    if( !IsElectronMuonOverlap(el) ) //continue;
      UpdateElFlow( sysVar, ElFlow::MuElOve, 1 );
        
    if( m_debug ){
      Info( "CheckElectrons()", "  GOOD Electron --> charge = %i , pt = %f , eta = %f , etaTrk = %f , phi = %f , E = %f", 
	    charge, pt/GeV, eta, etaTrk, phi, e/GeV );
      Info( "CheckElectrons()", "                    d0sig = %f , z0 = %f , author = %i , isolation = %i , quality = %i , trigMatch = %i",
            d0sig, Dz0, author, isol, ObjQual , trgmatc );
      Info( "CheckElectrons()", "                    isTight = %i , isMedium = %i ", isTight, isMedium );
    }
    
    if( m_QcdCR ){
      if( isTight && !isol ){
        m_Electrons.push_back(el);
        UpdateElFlow( sysVar, ElFlow::Isolation, 1 );
      }
      else{
        m_AddElectrons.push_back(el);
      }
    }
    else{
      if( isTight && isol ){
	m_Electrons.push_back(el);
	UpdateElFlow( sysVar, ElFlow::Isolation, 1 );
      }
      else{
	m_AddElectrons.push_back(el);
      }
    }
  }
  UpdateElFlow( sysVar, ElFlow::TightEl, (int)m_Electrons.size() );
  UpdateElFlow( sysVar, ElFlow::LooseEl, (int)m_AddElectrons.size() );

}

double HighMassLFV :: GetElectronIDSF(const xAOD::IParticle *p, int sysVar){
  
  double m_sf = 1;
  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "GetElectronIDSF()" , "Particle is not an electron!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    int Tpos = 0;
    if( m_ElSFVar.find(sysVar) == m_ElSFVar.end() ){
      if( m_debug ) Info( "GetElectronIDSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_elIDSF.at(Tpos)->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported )
	Info( "GetElectronIDSF()", "ElectronEfficiencyCorrection variation 'empty' (Nominal)" );
    }
    else{
      if( m_debug ) Info( "GetElectronIDSF()", "Applying variation %s", m_ElSFVarName[sysVar].c_str() );
      if( m_elIDSF.at(Tpos)->applySystematicVariation( m_ElSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
        Info( "GetElectronIDSF()", "ElectronEfficiencyCorrection variation %s not supported", m_ElSFVarName[sysVar].c_str() );
      }
    }
    if( m_elIDSF.at(Tpos)->getEfficiencyScaleFactor(*el,m_sf) == CP::CorrectionCode::Error )
      Info( "GetElectronIDSF()", "ElectronEfficiencyCorrection returns Error CorrectionCode");
  }
  if( m_debug ) Info( "GetElectronIDSF()" , "ID SF = %f ", m_sf );
  return m_sf;
  
}

double HighMassLFV :: GetElectronRecoSF(const xAOD::IParticle *p, int sysVar){

  double m_sf = 1;
  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "GetElectronRecoSF()" , "Particle is not an electron!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    if( m_ElSFVar.find(sysVar) == m_ElSFVar.end() ){
      if( m_debug ) Info( "GetElectronRecoSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_elRecoSF->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetElectronRecoSF()", "ElectronEfficiencyCorrection variation 'empty' (Nominal)" );
      }
    }
    else{
      if( m_debug ) Info( "GetElectronRecoSF()", "Applying variation %s", m_ElSFVarName[sysVar].c_str() );
      if( m_elRecoSF->applySystematicVariation( m_ElSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
	Info( "GetElectronRecoSF()", "ElectronEfficiencyCorrection variation %s not supported", m_ElSFVarName[sysVar].c_str() );
      }
    }
    if( m_elRecoSF->getEfficiencyScaleFactor(*el,m_sf) == CP::CorrectionCode::Error )
      Info( "GetElectronRecoSF()", "ElectronEfficiencyCorrection returns Error CorrectionCode");
  }
  if( m_debug ) Info( "GetElectronRecoSF()" , "Reco SF = %f ", m_sf );
  return m_sf;
  
}

double HighMassLFV :: GetElectronIsoSF(const xAOD::IParticle *p, int sysVar){

  double m_sf = 1;
  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "GetElectronIsoSF()" , "Particle is not an electron!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    int Tpos = 0;
    if( m_ElSFVar.find(sysVar) == m_ElSFVar.end() ){
      if( m_debug ) Info( "GetElectronIsoSF()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_elIsoSF.at(Tpos)->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
        Info( "GetElectronIsoSF()", "ElectronEfficiencyCorrection variation 'empty' (Nominal)" );
      }
    }
    else{
      if( m_debug ) Info( "GetElectronIsoSF()", "Applying variation %s", m_ElSFVarName[sysVar].c_str() );
      if( m_elIsoSF.at(Tpos)->applySystematicVariation( m_ElSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
	Info( "GetElectronIsoSF()", "ElectronEfficiencyCorrection variation %s not supported", m_ElSFVarName[sysVar].c_str() );
      }
    }
    if( m_elIsoSF.at(Tpos)->getEfficiencyScaleFactor(*el,m_sf) == CP::CorrectionCode::Error )
      Info( "GetElectronIsoSF()", "ElectronEfficiencyCorrection returns Error CorrectionCode");
  }
  if( m_debug ) Info( "GetElectronIsoSF()" , "Iso SF = %f ", m_sf );
  return m_sf;
  
}

double HighMassLFV :: GetElectronTrigSF(const xAOD::IParticle *p, int sysVar){
  
  double m_sf = 1;
  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "GetElectronRecoSF()" , "Particle is not an electron!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    int Tpos = 0;
    if( isElecTrig && CheckElectronTriggerMatching(el) ){
      if( m_ElSFVar.find(sysVar) == m_ElSFVar.end() ){
	if( m_debug ) Info( "GetElectronTrigSF()", "Systematic set not found, applying nominal one (no systematics)!");
	if( m_elTrigSF.at(Tpos)->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
	  Info( "GetElectronTrigSF()", "ElectronEfficiencyCorrection variation 'empty' (Nominal)" );
	}
      }
      else{
	if( m_debug ) Info( "GetElectronTrigSF()", "Applying variation %s", m_ElSFVarName[sysVar].c_str() );
	if( m_elTrigSF.at(Tpos)->applySystematicVariation( m_ElSFVar[sysVar] ) == CP::SystematicCode::Unsupported ){
	  Info( "GetElectronTrigSF()", "ElectronEfficiencyCorrection variation %s not supported", m_ElSFVarName[sysVar].c_str() );
	}
      }
      if( m_elTrigSF.at(Tpos)->getEfficiencyScaleFactor(*el,m_sf) == CP::CorrectionCode::Error )
	Info( "GetElectronTrigSF()", "ElectronEfficiencyCorrection returns Error CorrectionCode");
    }
  }
  if( m_debug ) Info( "GetElectronTrigSF()" , "Trig SF = %f ", m_sf );
  return m_sf;
  
}

double HighMassLFV :: GetElectronL1CaloSF(const xAOD::IParticle *p){
  
  double m_sf = 1;
  /* blocking it for now - need to understand if still needed */
  return m_sf;

  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "GetElectronL1CaloSF()" , "Particle is not an electron!!!  returning 1" );
    return 1;
  }
  if( m_UseWgt ){
    if(m_year==DataYear::Year2016){ //to be applied eventually to 2015 MC only
      const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
      float EMthresh[50] = {2008.96,1777.98,2053.32,1643.75,2016.56,1930.7,2485.62,2738.57,2712.91,1936.1,
			    4152.37,1825.52,1783.29,2188.33,2520.03,2545.74,2947.04,3086.35,4090.8,3371.26,
			    3773.61,4203.79,4813.52,5420.25,4753.5,4923.54,4338.46,4210.73,4182.22,3626.3,
			    3460.46,3326.42,2916.75,2317.44,2443.85,2144.06,2026.63,1828.14,1685.24,4284.14,
			    2063.57,2656.55,2617.98,2300.39,2029.07,2053.82,1903.34,2280.31,2139.5,2106.39};
      
      float EMsigma[50] = {488.849,477.262,692.451,667.071,709.393,535.159,807.23,868.081,514.064,568.739,
			   2680.53,570.615,646.978,346.33,643.672,458.567,551.28,804.826,808.753,1155.14,
			   1198.67,1388.94,1304.77,1079.12,1658.89,1596.59,1538.42,1526.29,1544.7,1114.52,
			   1266.86,1225.65,979.65,657.256,517.2,482.163,537.074,458.072,578.225,2583.39,
			   788.964,625.561,810.542,762.759,632.171,617.855,684.52,618.986,600.584,551.851};
      float pt = el->pt()/GeV;
      float eta = el->eta();
      int keta = eta*10 + 25;
      float sigma = sqrt( pt*(EMsigma[keta]/EMthresh[keta])*EMsigma[keta]);
      float thresh = EMthresh[keta];
      float wt =  erfc( (thresh - pt)/(sqrt(2.)*sigma) )/2.0 ; 
      m_sf = 1-wt;
    }
    else
      m_sf = 1;
  }
  if( m_debug ) Info( "GetElectronL1CaloSF()" , "L1Calo SF = %f ", m_sf );
  return m_sf;
  
}

double HighMassLFV :: GetElectronTrkIso(const xAOD::IParticle *p){

  float m_trkIso = 0;
  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "GetElectronTrkIso()" , "Particle is not an electron!!!  returning 0" );
    return 0;
  }
  const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
  el->isolation(m_trkIso,xAOD::Iso::ptvarcone20);
  if( m_debug ) Info( "GetElectronTrkIso()", "Track Isolation value (ptvarcone20) = %f", m_trkIso );
  return (double)m_trkIso;

}

double HighMassLFV :: GetElectronCaloIso(const xAOD::IParticle *p){

  float m_caloIso = 0;
  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "GetElectronCaloIso()" , "Particle is not an electron!!!  returning 0" );
    return 0;
  }
  const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
  el->isolation(m_caloIso,xAOD::Iso::topoetcone20);
  if( m_debug ) Info( "GetElectronCaloIso()", "Calo Isolation value (topoetcone20) = %f", m_caloIso );
  return (double)m_caloIso;

}

void HighMassLFV :: FillElectronQuantities(int sysVar){

  for( uint e=0; e<m_Electrons.size(); e++ ){
    const xAOD::Electron* el = m_Electrons.at(e);
    Lep_Id.push_back( -m_ElectronId*LeptonCharge(el) );
    Lep_pt.push_back( el->pt()/GeV );
    Lep_E.push_back( el->e()/GeV );
    Lep_eta.push_back( LeptonEta(el,true) );//el->caloCluster()->etaBE(2) );
    Lep_etaTrk.push_back( LeptonEta(el) );//el->eta();
    Lep_phi.push_back( el->phi() );
    Lep_d0.push_back( LeptonD0(el) );
    Lep_d0sig.push_back( LeptonD0Sign(el) );
    Lep_z0.push_back( LeptonZ0(el) );
    Lep_deltaz0.push_back( LeptonDeltaZ0(el) );
    Lep_Iso.push_back( m_iso->accept(*el) );
    Lep_trkIsoPt.push_back( GetElectronTrkIso(el)/GeV );
    Lep_caloIsoPt.push_back( GetElectronCaloIso(el)/GeV );
    Lep_trigMat.push_back( CheckElectronTriggerMatching(el) );
    Lep_nProngs.push_back( 1 );
    
    Lep_TrigSF.push_back( GetElectronTrigSF(el) );
    Lep_TrigSF_StatUp.push_back( GetElectronTrigSF(el) );
    Lep_TrigSF_StatDown.push_back( GetElectronTrigSF(el) );
    Lep_TrigSF_SysUp.push_back( GetElectronTrigSF(el,El_SFSys::ElTrg_SysUp) );
    Lep_TrigSF_SysDown.push_back( GetElectronTrigSF(el,El_SFSys::ElTrg_SysDown) );

    Lep_RecoSF.push_back( GetElectronRecoSF(el) );
    Lep_RecoSF_StatUp.push_back( GetElectronRecoSF(el) );
    Lep_RecoSF_StatDown.push_back( GetElectronRecoSF(el) );
    Lep_RecoSF_SysUp.push_back( GetElectronRecoSF(el,El_SFSys::ElReco_SysUp) );
    Lep_RecoSF_SysDown.push_back( GetElectronRecoSF(el,El_SFSys::ElReco_SysDown) );
    Lep_RecoSF_Hpt_SysUp.push_back( GetElectronRecoSF(el) );
    Lep_RecoSF_Hpt_SysDown.push_back( GetElectronRecoSF(el) );

    Lep_IDSF.push_back( GetElectronIDSF(el) );
    Lep_IDSF_StatUp.push_back( GetElectronIDSF(el) );
    Lep_IDSF_StatDown.push_back( GetElectronIDSF(el) );
    Lep_IDSF_SysUp.push_back( GetElectronIDSF(el,El_SFSys::ElID_SysUp) );
    Lep_IDSF_SysDown.push_back( GetElectronIDSF(el,El_SFSys::ElID_SysDown) );
    Lep_IDSF_Hpt_SysUp.push_back( GetElectronIDSF(el) );
    Lep_IDSF_Hpt_SysDown.push_back( GetElectronIDSF(el) );

    Lep_IsoSF.push_back( GetElectronIsoSF(el) );
    Lep_IsoSF_StatUp.push_back( GetElectronIsoSF(el) );
    Lep_IsoSF_StatDown.push_back( GetElectronIsoSF(el) );
    Lep_IsoSF_SysUp.push_back( GetElectronIsoSF(el,El_SFSys::ElIso_SysUp) );
    Lep_IsoSF_SysDown.push_back( GetElectronIsoSF(el,El_SFSys::ElIso_SysDown) );

    Lep_TtvaSF.push_back( 1. );
    Lep_TtvaSF_StatUp.push_back( 1. );
    Lep_TtvaSF_StatDown.push_back( 1. );
    Lep_TtvaSF_SysUp.push_back( 1. );
    Lep_TtvaSF_SysDown.push_back( 1. );

    Lep_BadMuSF.push_back( 1. );
    //addsys if exists
    Lep_L1CaloSF.push_back( GetElectronL1CaloSF(el) );
    
    Lep_ElOlrSF.push_back( 1. );
    Lep_ElOlrSF_SysUp.push_back( 1. );
    Lep_ElOlrSF_SysDown.push_back( 1. );    
  }
  
  if( sysVar==0 ){
    for( uint e=0; e<Lep_Id.size(); e++ ){
      if( abs(Lep_Id.at(e))==m_ElectronId && isBTBGood ){
	UpdateWeight( m_Chan, Weights::ElTrig         , 1, Lep_TrigSF.at(e)          );
	UpdateWeight( m_Chan, Weights::ElTrig_SysUp   , 1, Lep_TrigSF_SysUp.at(e)    );
	UpdateWeight( m_Chan, Weights::ElTrig_SysDown , 1, Lep_TrigSF_SysDown.at(e)  );

	UpdateWeight( m_Chan, Weights::ElReco         , 1, Lep_RecoSF.at(e)          );
	UpdateWeight( m_Chan, Weights::ElReco_SysUp   , 1, Lep_RecoSF_SysUp.at(e)    );
	UpdateWeight( m_Chan, Weights::ElReco_SysDown , 1, Lep_RecoSF_SysDown.at(e)  );

	UpdateWeight( m_Chan, Weights::ElID         , 1, Lep_IDSF.at(e)          );
	UpdateWeight( m_Chan, Weights::ElID_SysUp   , 1, Lep_IDSF_SysUp.at(e)    );
	UpdateWeight( m_Chan, Weights::ElID_SysDown , 1, Lep_IDSF_SysDown.at(e)  );

	UpdateWeight( m_Chan, Weights::ElIso         , 1, Lep_IsoSF.at(e)          );
	UpdateWeight( m_Chan, Weights::ElIso_SysUp   , 1, Lep_IsoSF_SysUp.at(e)    );
	UpdateWeight( m_Chan, Weights::ElIso_SysDown , 1, Lep_IsoSF_SysDown.at(e)  );

	UpdateWeight( m_Chan, Weights::ElL1Calo      , 1, Lep_L1CaloSF.at(e)       );

	if( !isBjetEvt ){
	  UpdateWeightBJ( m_Chan, Weights::ElTrig         , 1, Lep_TrigSF.at(e)          );
	  UpdateWeightBJ( m_Chan, Weights::ElTrig_SysUp   , 1, Lep_TrigSF_SysUp.at(e)    );
	  UpdateWeightBJ( m_Chan, Weights::ElTrig_SysDown , 1, Lep_TrigSF_SysDown.at(e)  );

	  UpdateWeightBJ( m_Chan, Weights::ElReco         , 1, Lep_RecoSF.at(e)          );
	  UpdateWeightBJ( m_Chan, Weights::ElReco_SysUp   , 1, Lep_RecoSF_SysUp.at(e)    );
	  UpdateWeightBJ( m_Chan, Weights::ElReco_SysDown , 1, Lep_RecoSF_SysDown.at(e)  );

	  UpdateWeightBJ( m_Chan, Weights::ElID         , 1, Lep_IDSF.at(e)          );
	  UpdateWeightBJ( m_Chan, Weights::ElID_SysUp   , 1, Lep_IDSF_SysUp.at(e)    );
	  UpdateWeightBJ( m_Chan, Weights::ElID_SysDown , 1, Lep_IDSF_SysDown.at(e)  );

	  UpdateWeightBJ( m_Chan, Weights::ElIso         , 1, Lep_IsoSF.at(e)          );
	  UpdateWeightBJ( m_Chan, Weights::ElIso_SysUp   , 1, Lep_IsoSF_SysUp.at(e)    );
	  UpdateWeightBJ( m_Chan, Weights::ElIso_SysDown , 1, Lep_IsoSF_SysDown.at(e)  );

	  UpdateWeightBJ( m_Chan, Weights::ElL1Calo      , 1, Lep_L1CaloSF.at(e)       );
	}
      }
    }
  }
  
}
