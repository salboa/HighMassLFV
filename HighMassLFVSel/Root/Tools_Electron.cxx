#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: ElectronToolsInitializer(){

  Info( "ElectronToolsInitializer()", "Initializing Electron corrections tools ... " );

  /* Electron Selector Tools - Tight, Medium and Loose */
  m_elSelTig = new AsgElectronLikelihoodTool( "TighLH"   );
  m_elSelMed = new AsgElectronLikelihoodTool( "MediumLH" );
  std::string confDir = "ElectronPhotonSelectorTools/offline/mc16_20170828/";
    
  if( !m_elSelTig->setProperty( "WorkingPoint", "TightLHElectron").isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in AsgElectronLikelihoodTool (Tight) configuration" );
  }
  if( !m_elSelMed->setProperty( "WorkingPoint", "MediumLHElectron").isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in AsgElectronLikelihoodTool (Medium) configuration" );
  }
  
  if( !m_elSelTig->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize AsgElectronLikelihoodTool (Tight) !" );
    return;
  }
  else{
    Info( "ElectronToolsInitializer()", "AsgElectronLikelihoodTool (Tight) initialized!" );
  }
  
  if( !m_elSelMed->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize AsgElectronLikelihoodTool (Medium)!" );
    return;
  }
  else{
    Info( "ElectronToolsInitializer()", "AsgElectronLikelihoodTool initialized (Medium)!" );
  }

  /* Electron Calibration and Smearing Tool */
  m_elSmear = new CP::EgammaCalibrationAndSmearingTool( "EgammaCalibrationAndSmearingTool" );
  if( !m_elSmear->setProperty( "ESModel", "es2017_R21_v1" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in EgammaCalibrationAndSmearingTool ESModel setting" );
  }
  if( !m_elSmear->setProperty( "decorrelationModel", "1NP_v1" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in EgammaCalibrationAndSmearingTool decorrelation Model setting" );
  }
  if( !m_elSmear->setProperty( "useAFII", (int)m_FastSim ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in EgammaCalibrationAndSmearingTool FastSim setting" );
  }
  if( !m_elSmear->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize EgammaCalibrationAndSmearingTool" );
  }
  else{
    Info( "ElectronToolsInitializer()", "EgammaCalibrationAndSmearingTool initialized!" );
  }

  
  int SimType = 1;
  if( m_FastSim ) { SimType = 3; }
  std::string m_ElecSFPath = "ElectronEfficiencyCorrection/2015_2017/rel21.2/Moriond_February2018_v1/";
  /* Electron Efficiency Correction - ID SF (Tight and Medium) */
  m_elIDSF_Tig = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_IDSF_Tight");
  m_elIDSF_Med = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_IDSF_Medium");
  std::vector<std::string> Input_elIDSF_Tig;
  std::vector<std::string> Input_elIDSF_Med;
  Input_elIDSF_Tig.push_back(m_ElecSFPath+"offline/efficiencySF.offline.TightLLH_d0z0_v13.root");
  Input_elIDSF_Med.push_back(m_ElecSFPath+"offline/efficiencySF.offline.MediumLLH_d0z0_v13.root");
    
  if( !m_elIDSF_Tig->setProperty( "CorrectionFileNameList", Input_elIDSF_Tig ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool input file for ID SF (Tight) setting" );
  }
  if( !m_elIDSF_Tig->setProperty( "ForceDataType", SimType ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool data type for ID SF (Tight) setting" );
  }
  if( !m_elIDSF_Tig->setProperty( "CorrelationModel", "TOTAL" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool Correlation Model for ID SF (Tight) setting" );
  }
  if( !m_elIDSF_Tig->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize ElectronEfficiencyCorrectionTool for ID SF (Tight)" );
  }
  else{
    Info( "ElectronToolsInitializer()", "ElectronEfficiencyCorrectionTool for ID SF (Tight) initialized!" );
  }

  if( !m_elIDSF_Med->setProperty( "CorrectionFileNameList", Input_elIDSF_Med ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool input file for ID SF (Medium) setting" );
  }
  if( !m_elIDSF_Med->setProperty( "ForceDataType", SimType ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool data type for ID SF (Medium) setting" );
  }
  if( !m_elIDSF_Med->setProperty( "CorrelationModel", "TOTAL" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool Correlation Model for ID SF (Medium) setting" );
  }
  if( !m_elIDSF_Med->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize ElectronEfficiencyCorrectionTool for ID SF (Medium)" );
  }
  else{ 
    Info( "ElectronToolsInitializer()", "ElectronEfficiencyCorrectionTool for ID SF (Medium) initialized!" );
  }
  m_elIDSF.push_back(m_elIDSF_Tig);
  m_elIDSF.push_back(m_elIDSF_Med);
  
  
  /* Electron Efficiency Correction - Reco SF */
  m_elRecoSF = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_RecoSF");
  std::vector<std::string> Input_elRecoSF;
  Input_elRecoSF.push_back(m_ElecSFPath+"offline/efficiencySF.offline.RecoTrk.root");
  if( !m_elRecoSF->setProperty( "CorrectionFileNameList", Input_elRecoSF ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool input file for Reco SF setting" );
  }
  if( !m_elRecoSF->setProperty( "ForceDataType", SimType ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool data type for Reco SF setting" );
  }
  if( !m_elRecoSF->setProperty( "CorrelationModel", "TOTAL" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool Correlation Model for Reco SF setting" );
  }
  if( m_verbose ) m_elRecoSF->msg().setLevel( MSG::VERBOSE );
  if( !m_elRecoSF->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize ElectronEfficiencyCorrectionTool for Reco SF" );
  }
  else{ 
    Info( "ElectronToolsInitializer()", "ElectronEfficiencyCorrectionTool for Reco SF initialized!" );
  }

  
  /* Electron Efficiency Correction - Iso SF (Tight and Medium) */
  m_elIsoSF_Tig = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_IsoSF_Tight");
  m_elIsoSF_Med = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_IsoSF_Medium");
  std::vector<std::string> Input_elIsoSF_Tig;
  std::vector<std::string> Input_elIsoSF_Med;
  Input_elIsoSF_Tig.push_back(m_ElecSFPath+"isolation/efficiencySF.Isolation.TightLLH_d0z0_v13_isolFixedCutHighPtCaloOnly.root");
  Input_elIsoSF_Med.push_back(m_ElecSFPath+"isolation/efficiencySF.Isolation.MediumLLH_d0z0_v13_isolFixedCutHighPtCaloOnly.root");
  
  if( !m_elIsoSF_Tig->setProperty( "CorrectionFileNameList", Input_elIsoSF_Tig ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool input file for Iso SF (Tight) setting" );
  }
  if( !m_elIsoSF_Tig->setProperty( "ForceDataType", SimType ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool data type for Iso SF (Tight) setting" );
  }
  if( !m_elIsoSF_Tig->setProperty( "CorrelationModel", "TOTAL" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool Correlation Model for Iso SF (Tight) setting" );
  }
  if( !m_elIsoSF_Tig->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize ElectronEfficiencyCorrectionTool for Iso SF (Tight)" );
  }
  else{
    Info( "ElectronToolsInitializer()", "ElectronEfficiencyCorrectionTool for Iso SF (Tight) initialized!" );
  }

  if( !m_elIsoSF_Med->setProperty( "CorrectionFileNameList", Input_elIsoSF_Med ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool input file for Iso SF (Medium) setting" );
  }
  if( !m_elIsoSF_Med->setProperty( "ForceDataType", SimType ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool data type for Iso SF (Medium) setting" );
  }
  if( !m_elIsoSF_Med->setProperty( "CorrelationModel", "TOTAL" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool Correlation Model for Iso SF (Medium) setting" );
  }
  if( !m_elIsoSF_Med->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize ElectronEfficiencyCorrectionTool for Iso SF (Medium)" );
  }
  else{ 
    Info( "ElectronToolsInitializer()", "ElectronEfficiencyCorrectionTool for Iso SF (Medium) initialized!" );
  }
  m_elIsoSF.push_back(m_elIsoSF_Tig);
  m_elIsoSF.push_back(m_elIsoSF_Med);
  

  /* Electron Efficiency Correction - Trig SF (Tight and Medium) */
  m_elTrigSF_Tig = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_TrigSF_Tight");
  m_elTrigSF_Med = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_TrigSF_Medium");
  std::vector<std::string> Input_elTrigSF_Tig;
  std::vector<std::string> Input_elTrigSF_Med;
  Input_elTrigSF_Tig.push_back(m_ElecSFPath+"trigger/efficiencySF.SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2017_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0.TightLLH_d0z0_v13_isolFixedCutHighPtCaloOnly.root");
  Input_elTrigSF_Med.push_back(m_ElecSFPath+"trigger/efficiencySF.SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2017_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0.MediumLLH_d0z0_v13_isolFixedCutHighPtCaloOnly.root");

  if( !m_elTrigSF_Tig->setProperty( "CorrectionFileNameList", Input_elTrigSF_Tig ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool input file for Trig SF (Tight) setting" );
  }
  if( !m_elTrigSF_Tig->setProperty( "ForceDataType", SimType ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool data type for Trig SF (Tight) setting" );
  }
  if( !m_elTrigSF_Tig->setProperty( "CorrelationModel", "TOTAL" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool Correlation Model for Trig SF (Tight) setting" );
  }
  if( !m_elTrigSF_Tig->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize ElectronEfficiencyCorrectionTool for Trig SF (Tight) " );
  }
  else{
    Info( "ElectronToolsInitializer()", "ElectronEfficiencyCorrectionTool for Trig SF (Tight) initialized!" );
  }

  if( !m_elTrigSF_Med->setProperty( "CorrectionFileNameList", Input_elTrigSF_Med ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool input file for Trig SF (Medium) setting" );
  }
  if( !m_elTrigSF_Med->setProperty( "ForceDataType", SimType ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool data type for Trig SF (Medium) setting" );
  }
  if( !m_elTrigSF_Med->setProperty( "CorrelationModel", "TOTAL" ).isSuccess() ){
    Info( "ElectronToolsInitializer()", "Error in ElectronEfficiencyCorrectionTool Correlation Model for Trig SF (Medium) setting" );
  }
  if( !m_elTrigSF_Med->initialize().isSuccess() ){
    Info( "ElectronToolsInitializer()", "Cannot initialize ElectronEfficiencyCorrectionTool for Trig SF (Medium) " );
  }
  else{ 
    Info( "ElectronToolsInitializer()", "ElectronEfficiencyCorrectionTool for Trig SF (Medium) initialized!" );
  }
  m_elTrigSF.push_back(m_elTrigSF_Tig);
  m_elTrigSF.push_back(m_elTrigSF_Med);

  Info( "ElectronToolsInitializer()", "Electron tools successfully initialized!" );
  
}

void HighMassLFV :: ElectronToolsDestructor(){

  Info( "ElectronToolsDestructor()", "Deleting Analysis Electron tools objects ... " );
  
  if( m_elSelTig )     delete m_elSelTig;
  if( m_elSelMed )     delete m_elSelMed;
  if( m_elSmear)       delete m_elSmear;
  if( m_elIDSF_Tig )   delete m_elIDSF_Tig;
  if( m_elIDSF_Med )   delete m_elIDSF_Med;
  if( m_elRecoSF )     delete m_elRecoSF;
  if( m_elIsoSF_Tig )  delete m_elIsoSF_Tig;
  if( m_elIsoSF_Med )  delete m_elIsoSF_Med;
  if( m_elTrigSF_Tig ) delete m_elTrigSF_Tig;
  if( m_elTrigSF_Med ) delete m_elTrigSF_Med;
    
  Info( "ElectronToolsDestructor()", "Electron tools objects successfully deleted!" );

}
