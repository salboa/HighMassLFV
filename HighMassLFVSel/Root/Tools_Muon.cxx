#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: MuonToolsInitializer(){

  Info( "MuonToolsInitializer()", "Initializing Muon corrections tools ... " );
  
  /* Muon Selector Tool */
  m_muSel = new CP::MuonSelectionTool( "MuSelector" );
  if( !m_muSel->setProperty( "MaxEta", 2.5 ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonSelectionTool eta cut" );
  }
  if(!m_muSel->setProperty( "MuQuality", 4 ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonSelectionTool quality cut" );
  }
  if(!m_muSel->initialize().isSuccess()){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonSelectionTool!" );
    return;
  }
  else{
    Info( "MuonToolsInitializer()", "MuonSelectionTool initialized!" );
  }
  
  
  /* Muon Calibration and Smearing Tool */
  m_muSmear2016 = new CP::MuonCalibrationAndSmearingTool( "MuonCorrectionTool2016" );
  m_muSmear2017 = new CP::MuonCalibrationAndSmearingTool( "MuonCorrectionTool2017" );
  m_muSmear2018 = new CP::MuonCalibrationAndSmearingTool( "MuonCorrectionTool2018" );
  
  if( !m_muSmear2016->setProperty( "Year", "Data16" ).isSuccess() ){ 
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2016) Year setting" );
  }
  if( !m_muSmear2016->setProperty( "StatComb", false ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2016) StatComb setting" );
  }
  if( !m_muSmear2016->setProperty( "SagittaRelease", "sagittaBiasDataAll_25_07_17" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2016) SagittaRelease setting" );
  }
  if( !m_muSmear2016->setProperty( "SagittaCorr", true ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2016) SagittaCorr setting" );
  }
  if( !m_muSmear2016->setProperty( "doSagittaMCDistortion" , false ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2016) doSagittaMCDistortion setting" );
  }
  if( !m_muSmear2016->setProperty( "SagittaCorrPhaseSpace", true ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2016) SagittaCorrPhaseSpace setting" );
  }
  if( !m_muSmear2016->setProperty( "Release", "Recs2017_08_02" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2016) Release setting" );
  }
  if( !m_muSmear2016->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonCalibrationAndSmearingTool (2016)!" );
  }
  else{
    Info( "MuonToolsInitializer()", "MuonCalibrationAndSmearingTool (2016) initialized!" );
  }

  if( !m_muSmear2017->setProperty( "Year", "Data17" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2017) Year setting" );
  }
  if( !m_muSmear2017->setProperty( "StatComb", false ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2017) StatComb setting" );
  }
  if( !m_muSmear2017->setProperty( "SagittaRelease", "sagittaBiasDataAll_30_07_18" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2017) SagittaRelease setting" );
  }
  if( !m_muSmear2017->setProperty( "SagittaCorr", true ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2017) SagittaCorr setting" );
  }
  if( !m_muSmear2017->setProperty( "doSagittaMCDistortion" , false ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2017) doSagittaMCDistortion setting" );
  }
  if( !m_muSmear2017->setProperty( "SagittaCorrPhaseSpace", true ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2017) SagittaCorrPhaseSpace setting" );
  }
  if( !m_muSmear2017->setProperty( "Release", "Recs2017_08_02" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2017) Release setting" );
  }
  if( !m_muSmear2017->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonCalibrationAndSmearingTool (2017)!" );
  }
  else{
    Info( "MuonToolsInitializer()", "MuonCalibrationAndSmearingTool (2017) initialized!" );
  }

  if( !m_muSmear2018->setProperty( "Year", "Data17" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2018) Year setting" );
  }
  if( !m_muSmear2018->setProperty( "StatComb", false ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2018) StatComb setting" );
  }
  if( !m_muSmear2018->setProperty( "SagittaRelease", "sagittaBiasDataAll_30_07_18" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2018) SagittaRelease setting" );
  }
  if( !m_muSmear2018->setProperty( "SagittaCorr", false ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2018) SagittaCorr setting" );
  }
  if( !m_muSmear2018->setProperty( "doSagittaMCDistortion" , true ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2018) doSagittaMCDistortion setting" );
  }
  if( !m_muSmear2018->setProperty( "SagittaCorrPhaseSpace", false ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2018) SagittaCorrPhaseSpace setting" );
  }
  if( !m_muSmear2018->setProperty( "Release", "Recs2017_08_02" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonCalibrationAndSmearing Tool (2018) Release setting" );
  }
  if( !m_muSmear2018->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonCalibrationAndSmearingTool (2018)!" );
  }
  else{ 
    Info( "MuonToolsInitializer()", "MuonCalibrationAndSmearingTool (2018) initialized!" );
  }
  
  
  /* Muon Effiency Correction - Trig SF */
  m_muTrigSF = new CP::MuonTriggerScaleFactors("TrigSFClass");
  
  if( !m_muTrigSF->setProperty( "MuonQuality", "HighPt" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonTriggerScaleFactors muon quality setting" );
  }
  if( !m_muTrigSF->setProperty( "CalibrationRelease", "180905_TriggerUpdate" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonTriggerScaleFactors calibration realease setting" );
  }
  if( !m_muTrigSF->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonTriggerScaleFactors" );
  }
  else{
    Info( "MuonToolsInitializer()", "MuonTriggerScaleFactors initialized!" );
  }

  /* Muon Effiency Correction - Reco SF */
  m_muRecoSF = new CP::MuonEfficiencyScaleFactors("MuonRecoSF");
  if( !m_muRecoSF->setProperty( "WorkingPoint", "HighPt" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonEfficiencyScaleFactors working point setting" );
  }
  if( !m_muRecoSF->setProperty( "CalibrationRelease", "180808_SummerUpdate" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonEfficiencyScaleFactors calibration release setting" );
  }
  if( !m_muRecoSF->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonEfficiencyScaleFactors" );
  }
  else{
    Info( "MuonToolsInitializer()", "MuonEfficiencyScaleFactors initialized!" );
  }


  /* Muon Effiency Correction - BadMuonVeto SF */
  m_muBadMuSF = new CP::MuonEfficiencyScaleFactors("BadMuonVetoSF");
  if( !m_muBadMuSF->setProperty( "WorkingPoint", "BadMuonVeto_HighPt" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonEfficiencyScaleFactors (BadMuonVeto) working point setting" );
  }
  if( !m_muBadMuSF->setProperty( "CalibrationRelease", "180808_SummerUpdate" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonEfficiencyScaleFactors (BadMuonVeto) calibration release setting" );
  }
  if( !m_muBadMuSF->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonEfficiencyScaleFactors (BadMuonVeto)" );
  }
  else{
    Info( "MuonToolsInitializer()", "MuonEfficiencyScaleFactors (BadMuonVeto) initialized!" );
  }

  
  /* Muon Efficiency Correction - Iso SF */
  m_muIsoSF = new CP::MuonEfficiencyScaleFactors("MuonIsoSF");
  if( !m_muIsoSF->setProperty( "WorkingPoint", "FixedCutHighPtTrackOnlyIso" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonIsolationScaleFactors working point setting" );
  }
  if( !m_muIsoSF->setProperty( "CalibrationRelease", "180808_SummerUpdate" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonIsolationScaleFactors calibration release setting" );
  }
  if( !m_muIsoSF->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonIsolationScaleFactors" );
  }
  else{
    Info( "MuonToolsInitializer()", "MuonIsolationScaleFactors initialized!" );
  }

  /* Muon Efficiency Correction - TTVA SF */
  m_muTTVASF = new CP::MuonEfficiencyScaleFactors("MuonTTVASF");
  if( !m_muTTVASF->setProperty( "WorkingPoint", "TTVA" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonTrackToVertexAssociationScaleFactors working point setting" );
  }
  if( !m_muTTVASF->setProperty( "CalibrationRelease", "180808_SummerUpdate" ).isSuccess() ){
    Info( "MuonToolsInitializer()", "Error in MuonTrackToVertexAssociationScaleFactors calibration release setting" );
  }
  if( !m_muTTVASF->initialize().isSuccess() ){
    Info( "MuonToolsInitializer()", "Cannot initialize MuonTrackToVertexAssociationScaleFactors" );
  }
  else{
    Info( "MuonToolsInitializer()", "MuonTrackToVertexAssociationScaleFactors initialized!" );
  }

  m_muSmear.push_back(m_muSmear2016);
  m_muSmear.push_back(m_muSmear2017);
  m_muSmear.push_back(m_muSmear2018);

  Info( "MuonToolsInitializer()", "Muon tools successfully initialized!" );
  
}

void HighMassLFV :: MuonToolsDestructor(){

  Info( "MuonToolsDestructor()", "Deleting Analysis Muon tools objects ... " );

  m_muSmear.clear();
  if( m_muSel )        delete m_muSel;
  if( m_muSmear2016)   delete m_muSmear2016;
  if( m_muSmear2017)   delete m_muSmear2017;
  if( m_muSmear2018)   delete m_muSmear2018;
  if( m_muTrigSF )     delete m_muTrigSF;
  if( m_muRecoSF )     delete m_muRecoSF;
  if( m_muBadMuSF )    delete m_muBadMuSF;
  if( m_muIsoSF )      delete m_muIsoSF;
  if( m_muTTVASF )     delete m_muTTVASF;
  
  Info( "MuonToolsDestructor()", "Muon tools objects successfully deleted!" );

}
