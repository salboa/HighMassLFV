#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: ToolsInitializer(){

  Info( "ToolsInitializer()", "Initializing Analysis tools ... " );
  
  /* GoodRunsList */
  m_grl = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
  std::string GRL_Year2015 = "GoodRunsLists/data15_13TeV/20170619/data15_13TeV.periodAllYear_DetStatus-v89-pro21-02_Unknown_PHYS_StandardGRL_All_Good_25ns.xml";
  std::string GRL_Year2016 = "GoodRunsLists/data16_13TeV/20180129/data16_13TeV.periodAllYear_DetStatus-v89-pro21-01_DQDefects-00-02-04_PHYS_StandardGRL_All_Good_25ns.xml";
  std::string GRL_Year2017 = "GoodRunsLists/data17_13TeV/20180619/data17_13TeV.periodAllYear_DetStatus-v99-pro22-01_Unknown_PHYS_StandardGRL_All_Good_25ns_Triggerno17e33prim.xml";
  std::string GRL_Year2018 = "GoodRunsLists/data18_13TeV/20180906/data18_13TeV.periodAllYear_DetStatus-v102-pro22-03_Unknown_PHYS_StandardGRL_All_Good_25ns_Triggerno17e33prim.xml";
  
  const char* GRL_Path2015 = gSystem->ExpandPathName( GRL_Year2015.c_str() );
  const char* GRL_Path2016 = gSystem->ExpandPathName( GRL_Year2016.c_str() );
  const char* GRL_Path2017 = gSystem->ExpandPathName( GRL_Year2017.c_str() );
  const char* GRL_Path2018 = gSystem->ExpandPathName( GRL_Year2018.c_str() );
  std::vector<std::string> vecStringGRL;
  vecStringGRL.push_back(GRL_Path2015);
  vecStringGRL.push_back(GRL_Path2016);
  vecStringGRL.push_back(GRL_Path2017);
  vecStringGRL.push_back(GRL_Path2018);
  
  if( !m_grl->setProperty( "GoodRunsListVec", vecStringGRL ).isSuccess() ){
    Info( "ToolsInitializer()", "Error in GoodRunsListSelectionTool vector GRL setting");
  }
  if( !m_grl->setProperty( "PassThrough", false ).isSuccess() ){ // if true (default) will ignore result of GRL and will just pass all events
    Info( "ToolsInitializer()", "Error in GoodRunsListSelectionTool PassTrough setting");
  }
  if( !m_grl->initialize().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize GoodRunsListSelectionTool!" );
  }
  else{
    Info( "ToolsInitializer()", "GoodRunsListSelectionTool initialized!" );
  }

  
  /* Pileup Reweighting Tool */
  m_puTool = new CP::PileupReweightingTool("prw");
  std::vector<std::string> ConfFiles;
  std::vector<std::string> LumiCalcFiles;
  ConfFiles.push_back( ("$UserAnalysis_DIR/data/HighMassLFVSel/PU/PURW_Background_"+m_MCtype+".root").c_str() ); //to be updated
  ConfFiles.push_back( ("$UserAnalysis_DIR/data/HighMassLFVSel/PU/PURW_Signal_"+m_MCtype+".root").c_str() ); //to be updated
  if(m_MCtype=="mc16a"){
    LumiCalcFiles.push_back( "GoodRunsLists/data15_13TeV/20170619/PHYS_StandardGRL_All_Good_25ns_276262-284484_OflLumi-13TeV-008.root" );
    LumiCalcFiles.push_back( "GoodRunsLists/data16_13TeV/20180129/PHYS_StandardGRL_All_Good_25ns_297730-311481_OflLumi-13TeV-009.root" );
  }
  else if(m_MCtype=="mc16d"){
    LumiCalcFiles.push_back( "GoodRunsLists/data17_13TeV/20180619/physics_25ns_Triggerno17e33prim.lumicalc.OflLumi-13TeV-010.root" );
  }
  else if(m_MCtype=="mc16e"){
    LumiCalcFiles.push_back( "GoodRunsLists/data18_13TeV/20180906/physics_25ns_Triggerno17e33prim.lumicalc.OflLumi-13TeV-001.root" );
  }
  else{
    Info( "ToolsInitializer()", "Error in PileUpReweighting LumiCalcFiles setting: wrong mcType %s set! exiting ... ", m_MCtype.c_str() );
    exit(0);
  }
  if( !m_puTool->setProperty( "ConfigFiles", ConfFiles).isSuccess() ){
    Info( "ToolsInitializer()", "Error in PileupReweightingTool Config Files setting");
  }
  if( !m_puTool->setProperty( "LumiCalcFiles", LumiCalcFiles).isSuccess() ){
    Info( "ToolsInitializer()", "Error in PileupReweightingTool Lumi Calc Files setting");
  }
  //if( !m_puTool->setProperty( "DataScaleFactor", 1.0/1.09 ).isSuccess() ){
  //  Info( "ToolsInitializer()", "Error in PileupReweightingTool Data Scale Factor setting");
  //}
  //if( !m_puTool->setProperty( "DataScaleFactorUP", 1.0/1.0).isSuccess() ){
  //  Info( "ToolsInitializer()", "Error in PileupReweightingTool Data Scale Factor UP setting");
  //}
  //if( !m_puTool->setProperty( "DataScaleFactorDOWN", 1.0/1.18).isSuccess() ){
  //  Info( "ToolsInitializer()", "Error in PileupReweightingTool Data Scale Factor DOWN setting");
  //}
  if( m_fixPuCh ){
    if( !m_puTool->setProperty( "DefaultChannel", 410000 ).isSuccess() ){ //set the new ttbar sample
      Info( "ToolsInitializer()", "Error in PileupReweightingTool Default Channel setting");
    }
  }
  if( !m_puTool->initialize() ){
    Info( "ToolsInitializer()", "Cannot initialize PileupReweightingTool!" );
  }
  else{
    Info( "ToolsInitializer()", "PileupReweightingTool initialized!" );
  }
  m_PRWth = m_puTool;
  
  
  /* Trigger Config Tool */
  m_confTool = new TrigConf::xAODConfigTool( "xAODConfigTool" );
  if( !m_confTool->initialize().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize TrigConf::xAODConfigTool" );
    return;
  }
  else{
    Info( "ToolsInitializer()", "TrigConf::xAODConfigTool initialized!" );
  }
  
  
  /* Trigger Decision Tool */
  m_tdt = new Trig::TrigDecisionTool( "TrigDecisionTool" );
  if( !m_tdt->setProperty( "ConfigTool",ToolHandle<TrigConf::ITrigConfigTool>(m_confTool) ).isSuccess() ){
    Info( "ToolsInitializer()", "Error in TrigDecisionTool configuration" );
  }
  if( !m_tdt->setProperty( "TrigDecisionKey", "xTrigDecision" ).isSuccess() ){
    Info( "ToolsInitializer()", "Error in TrigDecisionTool decisionn key" );
  }
  if( !m_tdt->initialize().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize Trig::TrigDecisionTool!" );
    return;
  }
  else{
    Info( "ToolsInitializer()", "Trig::TrigDecisionTool initialized!" );
  }
  
  
  /* Trigger Matching Tool */
  m_trigMatch = new Trig::MatchingTool("MatchingTool");
  //m_trigMatch->msg().setLevel( MSG::WARNING );
  if( !m_trigMatch->initialize().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize Trig::TrigMatchingTool!" );
  }
  else{
    Info( "ToolsInitializer()", "Trig::TrigMatchingTool initialized!" );
  }
  
  
  /* Isolation Tool */
  m_iso = new CP::IsolationSelectionTool( "ElectronIsolation" );
  if( !m_iso->setProperty( "ElectronWP", "FixedCutHighPtCaloOnly" ).isSuccess() ){
    Info( "ToolsInitializer()", "Error in IsolationSelectionTool working point configuration for electrons" );
  }
  if( !m_iso->setProperty( "MuonWP", "FixedCutHighPtTrackOnly" ).isSuccess() ){
    Info( "ToolsInitializer()", "Error in IsolationSelectionTool working point configuration for muons" );
  }
  if( !m_iso->initialize().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize IsolationSelectionTool!" );
  }
  else{
    Info( "ToolsInitializer()", "IsolationSelectionTool initialized!" );
  }

  
  /* Isolation Correction Tool */
  m_isoCorr = new CP::IsolationCorrectionTool("IsolationCorrection");
  if( !m_isoCorr->setProperty( "IsMC", !m_UseData ).isSuccess() ){  //it should be removed
    Info( "ToolsInitializer()", "Error in IsolationCorrectionTool MC flag setting" );
  }
  if( !m_isoCorr->setProperty( "AFII_corr", m_FastSim ).isSuccess() ){
    Info( "ToolsInitializer()", "Error in IsolationCorrectionTool AFII setting" );
  }
  //if( !m_isoCorr->setProperty( "CorrFile", "IsolationCorrections/v1/isolation_ptcorrections_rel207.root" ).isSuccess() ){
  //Info( "ToolsInitializer()", "Error in IsolationCorrectionTool Correction File setting" );
  //}
  if( !m_isoCorr->initialize().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize IsolationCorrectionTool!" );
  }
  else{
    Info( "ToolsInitializer()", "IsolationCorrectionTool initialized!" );
  }
  
  
  /* Missing Energy Builder */
  m_metMaker = asg::AnaToolHandle<IMETMaker>("met::METMaker/metMaker");
  //if( m_verbose ) m_metMaker->msg().setLevel( MSG::VERBOSE );
  //if( !m_metMaker.setProperty( "DoMuonEloss", true) .isSuccess() ){
  //  Info( "ToolsInitializer()", "Error in MetMaker DoMuonEloss setting" );
  //}
  //if( !m_metMaker.setProperty( "DoIsolMuonEloss", true ).isSuccess() ){
  //  Info( "ToolsInitializer()", "Error in MetMaker DoIsolMuonEloss setting" );
  //}
  
  //if( !m_metMaker.setProperty( "JetRejectionDec", "passFJVT" ).isSuccess() ){
  //  std::cout<<"Problem"<<std::endl;
  //}
  
  if( !m_metMaker.retrieve().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot intialize METMaker!" );
  }
  else{
    Info( "Tools Initializer()", "METMaker initialized!" );
  }     
  
  
  /* Missing Energy Systematics */
  m_metPrefix = "METUtilities/data17_13TeV/prerec_Jan16";
  m_metSoftFile = "TrackSoftTerms.config";
  
  m_metSys = asg::AnaToolHandle<IMETSystematicsTool>("met::METSystematicsTool/metSystTool");
  //if( !m_metSys.setProperty( "ConfigPrefix", m_metPrefix.c_str() ).isSuccess() ){
  //  Info( "ToolsInitializer()", "Error in METSystematicsTool ConfigPrefix setting" );
  //}
  //if( !m_metSys.setProperty( "ConfigSoftTrkFile", m_metSoftFile.c_str() ).isSuccess() ){
  //  Info( "ToolsInitializer()", "Error in METSystematicsTool ConfigSoftTrkFile setting" );
  //}
  if( !m_metSys.retrieve().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize METSystematicsTool" );
  }
  else{
    Info( "ToolsInitializer()", "METSystematicsTool initialized!" );
  }


  /* Overlap Removal Tool */
  m_orFlags = ORUtils::ORFlags("OverlapRemovalTool", "isPreSel", "isOverlap");
  m_orFlags.doElectrons = true;
  m_orFlags.doMuons     = true;
  m_orFlags.doJets      = true;
  m_orFlags.doTaus      = true;
  m_orFlags.doPhotons   = false;
  ORUtils::recommendedTools(m_orFlags, m_toolBox);
  if( !m_toolBox.initialize().isSuccess() ){
    Info( "ToolsInitializer()", "Cannot initialize toolBox for OverlapRemovalTool" );
  }
  else{
    Info( "ToolsInitializer()", "toolBox for OverlapRemovalTool initialized" );
  }
  m_ORTool = std::move(m_toolBox.masterTool);
  Info( "ToolsInitializer()", "OverlapRemovalTool initialized" );
  
  /* MC Samples Information */
  m_mcInfo = new LFVUtils::MCSampleInfo(EcmEnergy::LHCEnergy::ThirteenTeV,m_debug);
  Info( "ToolsInitializer()", "MCSampleInfo initialized!" );
  
  
  /* MC Sample Overlap */
  m_mcOverlap = new LFVUtils::MCSampleOverlap(m_debug);
  Info( "ToolsInitializer()", "MCSampleOverlap initialized!" );

  
  Info( "ToolsInitializer()", "Analysis tools successfully initialized!" );
  
  
  /* Muon Tools */
  MuonToolsInitializer();
  
  
  /* Electron Tools */
  ElectronToolsInitializer();

  
  /* Tau Tools */
  TauToolsInitializer();

  
  /* Jet Tools */
  JetToolsInitializer();
  
  if( m_SystList )
    PrintSystematics();
    
}

void HighMassLFV :: ToolsDestructor(){

  Info( "ToolsDestructor()", "Deleting Analysis tools objects ... " );
  
  if( m_grl )        delete m_grl;
  if( m_puTool )     delete m_puTool;
  if( m_confTool )   delete m_confTool;
  if( m_tdt )        delete m_tdt;
  if( m_trigMatch)   delete m_trigMatch;
  if( m_iso )        delete m_iso;
  if( m_mcInfo )     delete m_mcInfo;
  if( m_mcOverlap )  delete m_mcOverlap;
  
  Info( "ToolsDestructor()", "Analysis tools objects successfully deleted!" );
  
  MuonToolsDestructor();
  ElectronToolsDestructor();
  TauToolsDestructor();
  JetToolsDestructor();
  
}
