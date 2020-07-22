#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: TauToolsInitializer(){

  Info( "TauToolsInitializer()", "Initializing Tau corrections tools ... " );
  
  /* Tau Selection Tool - Loose, Medium, Tight and ELOR */
  std::string SelConf = "", ELORConf="";
  if( m_NoTauId ){
    SelConf = "TauSelConfNoID.conf"; ELORConf="TauElORNoID.conf";
  }
  else if( m_FailTauId ){
    SelConf = "TauSelConfFailLoose.conf"; ELORConf="TauElORFailLoose.conf";
  }
  else{
    SelConf = "TauSelConfLoose.conf"; ELORConf="TauElORLoose.conf";
    //SelConf = "TauSelConfMedium.conf"; ELORConf="TauElORMedium.conf";
  }
  m_tauSelLoo = new TauAnalysisTools::TauSelectionTool( "TauSelectionToolLoose" );
  m_tauElOR   = new TauAnalysisTools::TauSelectionTool( "TauSelectionToolElORLoose" );

  if( !m_tauSelLoo->setProperty( "ConfigPath", ("$UserAnalysis_DIR/data/HighMassLFVSel/"+SelConf).c_str() ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauSelectionTool (ID WP) setting ConfigPath" );
  }
  if( !m_tauSelLoo->setProperty( "CreateControlPlots", false ).isSuccess() ){
    Info( "InitializeTauSelectTool()", "Error in TauSelectionTool (Loose) setting control plots flag" );
  }
  if( !m_tauSelLoo->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauSelectionTool (ID WP) " );
  }
  else{
    Info( "TauToolsInitializer()", "TauSelectionTool (ID WP) initialized!" );
  }
  
  if( !m_tauElOR->setProperty( "ConfigPath", ("$UserAnalysis_DIR/data/HighMassLFVSel/"+ELORConf).c_str() ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauSelectionTool (ElOR) setting ConfigPath" );
  }
  if( !m_tauElOR->setProperty( "CreateControlPlots", false ).isSuccess() ){
    Info( "InitializeTauSelectTool()", "Error in TauSelectionTool (ElOR) setting control plots flag" );
  }
  if( !m_tauElOR->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauSelectionTool (ElOR) " );
  }
  else{
    Info( "TauToolsInitializer()", "TauSelectionTool (ElOR) initialized!" );
  }

  
  /* Tau Likelihood Decorator Tool */
  m_tauEleLLH = new TauAnalysisTools::TauOverlappingElectronLLHDecorator( "TauOverlappingElectronLLHDecorator");
  if( !m_tauEleLLH->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauOverlappingElectronLLHDecorator" );
  }
  else{
    Info( "TauToolsInitializer()", "TauOverlappingElectronLLHDecorator initialized!" );
  }

  
  /* Tau Truth Matching Tool */
  m_tauTrMtc = new TauAnalysisTools::TauTruthMatchingTool( "TauTruthMatchingTool" );
  if( !m_tauTrMtc->setProperty( "WriteTruthTaus", true ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauTruthMatchingTool setting WriteTruthTaus" );
  }
  if( !m_tauTrMtc->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauTruthMatchingTool" );
  }
  else{
    Info( "TauToolsInitializer()", "TauTruthMatchingTool initialized!" );
  }
  
  
  /* Tau Smearing Tool */
  m_tauSmear = new TauAnalysisTools::TauSmearingTool( "TauSmearingTool" );
  if( !m_tauSmear->setProperty( "ApplyMVATES", true ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauSmearingTool MVA TES setting " );
  }
  if( !m_tauSmear->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauSmearingTool" );
  }
  else{
    Info( "TauToolsInitializer()", "TauSmearingTool initialized!" );
  }

  
  /* Tau Efficiency Correction - Reco SF */
  m_tauRecoSF = new TauAnalysisTools::TauEfficiencyCorrectionsTool( "TauEfficiencyCorrectionsTool_RecoSF" );
  if( !m_tauRecoSF->setProperty( "EfficiencyCorrectionTypes", std::vector<int>({TauAnalysisTools::EfficiencyCorrectionType::SFRecoHadTau}) ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool efficiency correction type for Reco SF setting" );
  }
  if( !m_tauRecoSF->setProperty( "IDLevel", (int)TauAnalysisTools::e_JETID::JETIDBDTLOOSE ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool ID level for Reco SF setting" );
  }
  if( !m_tauRecoSF->setProperty( "UseHighPtUncert", true ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool High pT Uncertainties for Reco SF setting" );
  }
  //m_tauRecoSF->msg().setLevel( MSG::DEBUG );
  if( !m_tauRecoSF->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauEfficiencyCorrectionsTool for Reco SF" );
  }
  else{
    Info( "TauToolsInitializer()", "TauEfficiencyCorrectionsTool for Reco SF initialized!" );
  }
  
  
  /* Tau Efficiency Correction - EleOlr SF */
  m_tauElOlrSF = new TauAnalysisTools::TauEfficiencyCorrectionsTool( "TauEfficiencyCorrectionsTool_EleOlrSF" );
  if( !m_tauElOlrSF->setProperty( "EfficiencyCorrectionTypes", std::vector<int>({TauAnalysisTools::EfficiencyCorrectionType::SFEleOLRHadTau}) ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool efficiency correction type for EleOlr SF setting" );
  }
  if( !m_tauElOlrSF->setProperty( "IDLevel", (int)TauAnalysisTools::e_JETID::JETIDBDTLOOSE ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool ID level for EleOlr SF setting" );
  }
  if( !m_tauElOlrSF->setProperty( "UseHighPtUncert", true ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool High pT Uncertainties for EleOlr SF setting" );
  }
  //m_tauElOlrSF->msg().setLevel( MSG::DEBUG );
  if( !m_tauElOlrSF->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauEfficiencyCorrectionsTool for EleOlr SF" );
  }
  else{ 
    Info( "TauToolsInitializer()", "TauEfficiencyCorrectionsTool for EleOlr SF initialized!" );
  }
  
  
  /* Tau Efficiency Correction - JetID SF */
  m_tauJetIDSF = new TauAnalysisTools::TauEfficiencyCorrectionsTool( "TauEfficiencyCorrectionsTool_JetIDSF" );
  if( !m_tauJetIDSF->setProperty( "EfficiencyCorrectionTypes", std::vector<int>({TauAnalysisTools::EfficiencyCorrectionType::SFJetIDHadTau}) ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool efficiency correction type for JetID SF setting" );
  }
  if( !m_tauJetIDSF->setProperty( "IDLevel", (int)TauAnalysisTools::e_JETID::JETIDBDTLOOSE ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool ID level for JetID SF setting" );
  }
  if( !m_tauJetIDSF->setProperty( "UseHighPtUncert", true ).isSuccess() ){
    Info( "TauToolsInitializer()", "Error in TauEfficiencyCorrectionsTool High pT Uncertainties for JetID SF setting" );
  }
  //m_tauJetIDSF->msg().setLevel( MSG::DEBUG );
  if( !m_tauJetIDSF->initialize().isSuccess() ){
    Info( "TauToolsInitializer()", "Cannot initialize TauEfficiencyCorrectionsTool for JetID SF" );
  }
  else{
    Info( "TauToolsInitializer()", "TauEfficiencyCorrectionsTool for JetID SF initialized!" );
  }

  Info( "TauToolsInitializer()", "Tau tools successfully initialized!" );
  
}

void HighMassLFV :: TauToolsDestructor(){

  Info( "TauToolsDestructor()", "Deleting Analysis Tau tools objects ... " );

  if( m_tauSelLoo )   delete m_tauSelLoo;
  if( m_tauElOR )     delete m_tauElOR;
  if( m_tauEleLLH )   delete m_tauEleLLH;
  if( m_tauTrMtc )    delete m_tauTrMtc;
  if( m_tauSmear )    delete m_tauSmear;
  if( m_tauRecoSF )   delete m_tauRecoSF;
  if( m_tauElOlrSF )  delete m_tauElOlrSF;
  if( m_tauJetIDSF )  delete m_tauJetIDSF;
  
  Info( "TauToolsDestructor()", "Tau tools objects successfully deleted!" );

}
