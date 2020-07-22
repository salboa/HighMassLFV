#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: JetToolsInitializer(){

  Info( "JetToolsInitializer()", "Initializing Jet corrections tools ... " );

  /* Jet Vertex Tagger Tool */
  m_jetVtxTag = new JetVertexTaggerTool( "JetVertexTagger" );
  m_jetVtxTagUp = ToolHandle<IJetUpdateJvt>( "JetVertexTagger" );
  if( !m_jetVtxTag->setProperty( "JVTFileName", "JetMomentTools/JVTlikelihood_20140805.root" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetVertexTaggerTool setting JVT File Name" );
  }
  if( !m_jetVtxTag->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize JetVertexTaggerTool" );
  }
  else{
    Info( "JetToolsInitializer()", "JetVertexTaggerTool initialized!" );
  }

  /* Jet Cleaning Tool */
  m_jetClean = new JetCleaningTool( "JetCleaning" );
  if( !m_jetClean->setProperty( "CutLevel", "LooseBad" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetCleaningTool CutLevel setting" );
  }
  if( m_jetClean->setProperty( "DoUgly", false ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetCleaningTool DoUgly setting" );    
  }
  if( !m_jetClean->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize JetCleaningTool" );
  }
  else{
    Info( "JetToolsInitializer()", "JetCleaningTool initialized!" );
  }

  /* Jet Forward JVT Tool */
  m_jetFrwJvtTool = new JetForwardJvtTool( "JetForwardJvtTool" );
  //if( !m_jetFrwJvtTool->setProperty( "CentralMaxPt",60e3 ).isSuccess() ){
  //  Info( "JetToolsInitialized()", "Error in JetForwardJvtTool setting CentralMaxPt value" );
  //}
  if( !m_jetFrwJvtTool->initialize().isSuccess() ){
    Info( "JetToolsInitialized()", "Cannot intialize JetForwardJvtTool!" );
  }
  else{
    Info( "JetToolsInitializer()", "JetForwardJvtTool initialized!" );
  }
  
  /* Jet JVT Efficiency Tool */
  m_jetJvtSF = new CP::JetJvtEfficiency( "jetJvtSF" );
  if( !m_jetJvtSF->setProperty( "SFFile", "JetJvtEfficiency/Moriond2018/JvtSFFile_EMTopoJets.root" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetJvtEfficiency setting SF File");
  }
  if( !m_jetJvtSF->setProperty( "WorkingPoint", "Medium").isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetJvtEfficiency setting WorkingPoint Option");
  }
  if( !m_jetJvtSF->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize JetJvtEfficiencyTool" );
  }
  else{
    Info( "JetToolsInitializer()", "JetJvtEfficiencyTool initialized!" );
  }
  
  /* Jet Calibration Tool */
  m_jetConf     = "JES_data2017_2016_2015_Consolidated_EMTopo_2018_Rel21.config";
  m_jetCalibSeq = "JetArea_Residual_EtaJES_GSC_Smear";
  if( m_FastSim ){
    m_jetConf     = "JES_MC16Recommendation_AFII_EMTopo_April2018_rel21.config";
    m_jetCalibSeq = "JetArea_Residual_EtaJES_GSC";
  }
  if( m_UseData )  
    m_jetCalibSeq = "JetArea_Residual_EtaJES_GSC_Insitu";
  
  m_jetCalib = new JetCalibrationTool( "JetCalib" );
  if( !m_jetCalib->setProperty( "JetCollection", "AntiKt4EMTopo" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetCalibrationTool setting Jet Colletion" );
  }
  if( !m_jetCalib->setProperty( "CalibSequence", m_jetCalibSeq.c_str() ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetCalibrationTool setting Calibration Sequence" );
  }
  if( !m_jetCalib->setProperty( "ConfigFile", m_jetConf.c_str() ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetCalibrationTool setting Config File" );
  }
  if( !m_jetCalib->setProperty( "IsData", m_UseData ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetCalibrationTool setting IsData flag" );
  }
  if( !m_jetCalib->setProperty( "CalibArea", "00-04-82").isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetCalibrationTool setting CalibArea" );
  }
  if( !m_jetCalib->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize JetCalibrationTool" );
  }
  else{
    Info( "JetToolsInitializer()", "JetCalibrationTool initialized!" );
  }

  /* Jet Resolution Tool */
  m_jetReso = new JERTool( "JetResolution" );
  if( !m_jetReso->setProperty( "PlotFileName", "JetResolution/Prerec2015_xCalib_2012JER_ReducedTo9NP_Plots_v2.root" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JERTool setting Plot File Name" );
  }
  if( !m_jetReso->setProperty( "CollectionName", "AntiKt4EMTopoJets" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JERTool setting jet CollectionName" );
  }
  if( !m_jetReso->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize JERTool (JetResolution)" );
  }
  else{
    Info( "JetToolsInitializer()", "JERTool (JetResolution) initialized!" );
  }
  
  /* Jet Smearing Tool */
  m_jetSmear = new JERSmearingTool( "JetSmearing" );
  m_jetResoHand = ToolHandle<IJERTool>("JetResolution");
  if( !m_jetSmear->setProperty( "JERTool", m_jetResoHand ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JERSmearingTool setting JERTool Handle" );
  }
  if( !m_jetSmear->setProperty("ApplyNominalSmearing", false ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JERSmearingTool setting ApplyNominalSmearing Option" );
  }
  if( !m_jetSmear->setProperty("isMC", !m_UseData ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JERSmearingTool setting isMC Option" );
  }
  if( !m_jetSmear->setProperty("SystematicMode", "Simple" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JERSmearingTool setting SystematicMode Option" );
  }
  if( !m_jetSmear->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize JERSmearingTool (JetSmearing)" );
  }
  else{
    Info( "JetToolsInitializer()", "JERSmearingTool (JetSmearing) initialized!" );
  }

  /* Jet Uncertainties Tool */
  m_jetUnc = new JetUncertaintiesTool( "JESTool" );
  if( !m_jetUnc->setProperty( "JetDefinition", "AntiKt4EMTopo").isSuccess() ){
    Info( "JetToolsInitializer()", "Error in JetUncertaintiesTool setting Jet Definition Option" );
  }
  if( !m_jetUnc->setProperty( "MCType", "MC16" ).isSuccess() ){ 
    Info( "JetToolsInitializer()", "Error in JetUncertaintiesTool setting MC Type Option" );
  }
  if( !m_jetUnc->setProperty( "ConfigFile", "rel21/Fall2018/R4_SR_Scenario1_SimpleJER.config" ) ){
    Info( "JetToolsInitializer()", "Error in JetUncertaintiesTool setting Config File Option" );
  }
  if( !m_jetUnc->setProperty( "CalibArea", "CalibArea-06") ){
    Info( "JetToosInitializer()", "Error in JetUncertaintiesTool setting CalibArea Option");
  }
  if( !m_jetUnc->setProperty( "IsData", m_UseData ).isSuccess() ){
    Info( "JetToosInitializer()", "Error in JetUncertaintiesTool setting IsData Option");
  }
  if( !m_jetUnc->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize JetUncertaintiesTool" );
  }
  else{
    Info( "JetToolsInitializer()", "JetUncertaintiesTool initialized!" );
  }

  /* b-tagging Selector */
  m_btagSel = new BTaggingSelectionTool( "BTagSelector" );
  if( !m_btagSel->setProperty( "MaxEta", 2.5 ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingSelectionTool setting MaxEta" );
  }
  if( !m_btagSel->setProperty( "MinPt", 25000. ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingSelectionTool setting MinPt" );
  }
  if( !m_btagSel->setProperty( "FlvTagCutDefinitionsFileName", "xAODBTaggingEfficiency/13TeV/2017-21-13TeV-MC16-CDI-2018-10-19_v1.root" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingSelectionTool setting Cut Definition File" );
  }
  if( !m_btagSel->setProperty( "TaggerName", "MV2c10"  ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingSelectionTool setting Tagger Name" );
  }
  if( !m_btagSel->setProperty( "OperatingPoint", "FixedCutBEff_77" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingSelectionTool setting Operating point" );
  }
  if( !m_btagSel->setProperty( "JetAuthor", "AntiKt4EMTopoJets" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingSelectionTool setting Jet Author (algorithm)" );
  }
  if( !m_btagSel->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize BTaggingSelectionTool" );
  }
  else{
    Info( "JetToolsInitializer()", "BTaggingSelectionTool initialized!" );
  }

  /* b-Tagging Efficiency SF */
  m_btagSF = new BTaggingEfficiencyTool( "BTaggingEfficiency" );
  if( !m_btagSF->setProperty( "TaggerName", "MV2c10" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingEfficiencyTool setting Tagger Name" );
  }
  if( !m_btagSF->setProperty( "OperatingPoint", "FixedCutBEff_77" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingEfficiencyTool setting Operating point" );
  }
  if( !m_btagSF->setProperty( "JetAuthor", "AntiKt4EMTopoJets" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingEfficiencyTool setting Jet Author (algorithm)" );
  }
  if( !m_btagSF->setProperty( "ScaleFactorFileName", "xAODBTaggingEfficiency/13TeV/2017-21-13TeV-MC16-CDI-2018-10-19_v1.root" ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingEfficiencyTool setting ScaleFactor File" );
  }
  if( !m_btagSF->setProperty( "ConeFlavourLabel", true ).isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingEfficiencyTool setting Cone Flavour Label" );
  }
  if( !m_btagSF->setProperty( "SystematicsStrategy", "Envelope").isSuccess() ){
    Info( "JetToolsInitializer()", "Error in BTaggingEfficiencyTool setting Systematics Strategy" );
  }
  if( !m_btagSF->initialize().isSuccess() ){
    Info( "JetToolsInitializer()", "Cannot initialize BTaggingEfficiencyTool" );
  }
  else{
    Info( "JetToolsInitializer()", "BTaggingEfficiencyTool initialized!" );
  }
  
  Info( "JetToolsInitializer()", "Jet tools successfully initialized!" );
  
}

void HighMassLFV :: JetToolsDestructor(){

  Info( "JetToolsDestructor()", "Deleting Analysis Jet tools objects ... " );

  if( m_jetVtxTag )     delete m_jetVtxTag;
  if( m_jetClean )      delete m_jetClean;
  if( m_jetJvtSF )      delete m_jetJvtSF;
  if( m_jetFrwJvtTool ) delete m_jetFrwJvtTool; 
  if( m_jetCalib )      delete m_jetCalib;
  if( m_jetReso  )      delete m_jetReso;
  if( m_jetSmear )      delete m_jetSmear;
  if( m_jetUnc)         delete m_jetUnc;
  if( m_btagSel )       delete m_btagSel;
  if( m_btagSF )        delete m_btagSF;
  
  Info( "JetToolsDestructor()", "Jet tools objects successfully deleted!" );

}

