/* EventLoop includes */
#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>

//#include <AsgTools/MessageCheck.h>

/* C++ includes */
#include <iostream>
#include <iomanip>

/* Package includes */
#include <HighMassLFVSel/HighMassLFV.h>

ClassImp(HighMassLFV) //removed for now - to check

HighMassLFV :: HighMassLFV (){
//HighMassLFV :: HighMassLFV( const std::string &name, 
//                            ISvcLocator *pSvcLocator)
//: EL::AnaAlgorithm( name, pSvcLocator){
  
  /* Muon Selection Cuts */
  m_MuPt         = 65.;
  m_MuEta        = 2.5;
  m_MuDeltaZ0    = 0.5;
  m_MuD0SignCut  = 3.0;
  
  /* Electron Selection Cuts */
  m_ElPt         = 65.;
  m_ElEta        = 2.47;
  m_ElDeltaZ0    = 0.5;
  m_ElD0SignCut  = 5.;
  m_ElPt_IDThr   = 125.;

  /* Taus Selection Cuts */
  m_TauPt        = 65;
  m_TauEta       = 2.5;
  m_TauCharge    = 1;
  //m_TauBDTscore  = 0.40;
  
  /* Jet Selection Cuts */
  m_JetPt        = 25;
  m_JetEta       = 2.5;
  m_JetPtJVT     = 60;
  m_JetEtaJVT    = 2.4;
  m_JetJVT       = 0.59;
  m_JetElDR      = 0.2;
  
  /* Event Level Cuts */
  m_DeltaPhi     = 2.7;
  m_bjetMvxCut   = 0.645925;
  m_MetCut       = 30.;
  
  /* Particle Identification */
  m_MuonId       = 13;
  m_ElectronId   = 11;
  m_TauId        = 15;
  m_ZprimeId     = 32;
  m_ZprimeStatus = 62;
  m_LepStatus    = 1;

  /* General Quantities */
  ZMass          = 91.180;
  MuonMass       = 0.1056583715;
  ElectronMass   = 0.000510998928;
  TauMass        = 1.77682;
  GeV            = 1000.;
  pi             = TMath::Pi();

  /* Debug and Sample Information */
  m_printEvt        = 100;
  isMC              = false;
  m_isDeriv         = false;
  m_evtSample       = 0;
  m_evtWeightSample = 0;

}



EL::StatusCode HighMassLFV :: setupJob (EL::Job& job){
  
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.
  
  job.useXAOD ();
  CHECK( "setupJob()", xAOD::Init() );
  //xAOD::Init(); // call before opening first file

  return EL::StatusCode::SUCCESS;
  
}



EL::StatusCode HighMassLFV :: histInitialize (){
  
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.
  
  // check status codes
  //StatusCode::enableFailure();

  CreateSystematicsVector();
  CutFlowInit();
  DefineHistograms();
  CreateListOfHistograms();
  for( uint h=0; h<m_Hist.size(); h++ ){
    wk()->addOutput( m_Hist.at(h) );
  }

  DefineTrees();
  DefineTreesMap();
  SetTreeBranches();

  for( uint t=0; t<m_TreesMap.size(); t++ ){
    wk()->addOutput( m_TreesMap[t] );
  }
  
  return EL::StatusCode::SUCCESS;
  
}



EL::StatusCode HighMassLFV :: fileExecute (){

  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  
  m_isDeriv      = false;
  m_tmpEvt       = 0;
  m_tmpEvtWeight = 0;
  
  m_tmpName = GetFileName( (wk()->inputFile())->GetName() );
  
  if( !m_UseData ){
    m_event = wk()->xaodEvent();
    m_MetaData = dynamic_cast<TTree*>(wk()->inputFile()->Get("MetaData"));
    if( !m_MetaData ){
      Error( "fileExecute()", "Tree MetaData not found! Exiting" );
      return EL::StatusCode::FAILURE;
    }
    m_MetaData->LoadTree(0);
    m_isDeriv = !m_MetaData->GetBranch("StreamAOD");
    if( m_isDeriv ){
      
      if( m_debug ) Info( "fileExecute()", "Running On A Derivation ... " );
      /* retrieve information */
      m_completeCBC = 0;
      if( !m_event->retrieveMetaInput(m_completeCBC, "CutBookkeepers").isSuccess() ){
	Error( "fileExecute()", "Failed to retrieve CutBookkeepers from MetaData! Exiting" );
	return EL::StatusCode::FAILURE;
      }
      m_allEvtsCBK = 0;
      int maxcycle=-1;
      for( auto cbk : *m_completeCBC ){
	if( cbk->name() == "AllExecutedEvents" && cbk->inputStream() == "StreamAOD" &&
	    cbk->cycle() > maxcycle ){
	  maxcycle = cbk->cycle();
	  m_allEvtsCBK = cbk;
	}
      }
      if(m_allEvtsCBK){
	m_tmpEvt       = m_allEvtsCBK->nAcceptedEvents();
	m_tmpEvtWeight = m_allEvtsCBK->sumOfEventWeights();
      }
      else
	if( m_debug ) Info( "fileExecute()", "No relevant CutBookKeepers found" );
    }
  }
  m_evtSample       += m_tmpEvt; 
  m_evtWeightSample += m_tmpEvtWeight;
  if( m_debug ){
    Info( "fileExecute()", "Number of events / file (pre-derivartion) = %f", m_tmpEvt );
    Info( "fileExecute()", "Number of weighted events / file (pre-derivartion) = %f", m_tmpEvtWeight );
    Info( "fileExecute()", "Total number of events (pre-derivartion) = %f", m_evtSample );
    Info( "fileExecute()", "Total number of weighted events (pre-derivartion) = %f", m_evtWeightSample );
  }
  
  return EL::StatusCode::SUCCESS;
  
}



EL::StatusCode HighMassLFV :: changeInput (bool firstFile){
  
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  return EL::StatusCode::SUCCESS;
  
}



EL::StatusCode HighMassLFV :: initialize (){
  
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.
  
  Info( "initialize()", " Class Options: " );
  Info( "            ", "    Use Corrections  = %i", m_UseCorr        );
  Info( "            ", "    Use Weights      = %i", m_UseWgt         );
  Info( "            ", "    Use Data         = %i", m_UseData        );
  Info( "            ", "    Use Debug Stream = %i", m_DbgStream      );
  Info( "            ", "    Fix Pu Def. Chan = %i", m_fixPuCh        );
  Info( "            ", "    MC type          = %s", m_MCtype.c_str() );
  Info( "            ", "    do Systematics   = %i", m_doSyst         );
  Info( "            ", "    is FastSim       = %i", m_FastSim        );
  Info( "            ", "    Debug Enabled    = %i", m_debug          );
  Info( "            ", "    Verbose Enabled  = %i", m_verbose        );
  Info( "            ", "    is QCD Cont. Reg = %i", m_QcdCR          );
  Info( "            ", "    Not use Tau ID   = %i", m_NoTauId        );
  Info( "            ", "    Fail Tau ID      = %i", m_FailTauId      );
  Info( "            ", "    Use Tau BDT cut  = %i", m_useBDTcut      );
  Info( "            ", "    Tau BDT Score    = %f", m_TauBDTscore    );
  Info( "            ", "    eval Egamma qua. = %i", m_evalEgQuant    );
  Info( "            ", "    Do Print Flow    = %i", m_PrintFlow      );
  Info( "            ", "    Print Trig List  = %i", m_TrigList       );
  Info( "            ", "    Print Syst List  = %i", m_SystList       );
  Info( "            ", "    Run Single Event = %s", std::to_string(m_runEvent).c_str() );
    
  m_eventCounter     = 0;
  m_TnegWgt          = 0;
  m_TposWgt          = 0;
  m_event            = wk()->xaodEvent();
  m_SelectedMuon     = new xAOD::MuonContainer;
  m_SelectedMuonAux  = new xAOD::MuonAuxContainer;
  m_BuildMet         = new xAOD::MissingETContainer;
  m_BuildMetAux      = new xAOD::MissingETAuxContainer;
  m_MetMuons         = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  m_MetElectrons     = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  m_MetTaus          = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  m_MetPhotons       = new xAOD::PhotonContainer(SG::VIEW_ELEMENTS);
  m_store            = new xAOD::TStore;

  FillTriggerChains();
  ToolsInitializer();
  DefineSystematicsVariations();

  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode HighMassLFV :: execute (){

  if( m_debug ) m_printEvt=1;
  
  if( ( m_eventCounter % m_printEvt) ==0 ) Info( "execute()", "Event counter = %i", m_eventCounter );
  m_eventCounter++;
  
  /* xAOD Event Info Container check */
  m_eventInfo = 0;
  CHECK( "execute()", m_event->retrieve( m_eventInfo, "EventInfo") );

  /* Check Data Type */
  isMC = IsSimulation();
  
  /*xAOD Objects Containers check */
  m_vertexCont = 0;
  CHECK( "execute()", m_event->retrieve( m_vertexCont, "PrimaryVertices" ) );
  m_muonCont = 0;
  CHECK( "execute()", m_event->retrieve( m_muonCont, "Muons" ) );
  m_elecCont = 0;
  CHECK( "execute()", m_event->retrieve( m_elecCont, "Electrons" ) );
  m_tauCont = 0;
  CHECK( "execute()", m_event->retrieve( m_tauCont, "TauJets" ) );
  m_jetCont = 0;
  CHECK( "execute()", m_event->retrieve( m_jetCont, "AntiKt4EMTopoJets" ) );
  m_phCont = 0;
  CHECK( "execute()", m_event->retrieve( m_phCont, "Photons" ) );
  m_metCont = 0;
  CHECK( "execute()", m_event->retrieve( m_metCont, "MET_Core_AntiKt4EMTopo" ) );
  m_metMapCont = 0;
  CHECK( "execute()", m_event->retrieve( m_metMapCont, "METAssoc_AntiKt4EMTopo" ) );
  m_thpartCont = 0;
  m_thjetCont = 0;
  if(isMC){
    CHECK( "execute()", m_event->retrieve( m_thpartCont, "TruthParticles" ) );
    CHECK( "execute()", m_event->retrieve( m_thjetCont, "AntiKt4TruthJets" ) );
  }
  
  if( m_TrigList ){
    auto chainGroup_3 = m_tdt->getChainGroup(".*");
    for(auto &trig : chainGroup_3->getListOfTriggers()) { // get a list of triggers for the event
      std::cout << trig << std::endl;
    }
  }
  
  if( m_runEvent!=0 )
    if( m_eventInfo->eventNumber()!=m_runEvent ) return EL::StatusCode::SUCCESS;
  
  if( m_debug ) Info( "execute()", "EventNumber = %i , RunNumber = %i , LumiBlock = %i", 
		      (int)m_eventInfo->eventNumber(), (int)m_eventInfo->runNumber(), (int)m_eventInfo->lumiBlock() );
  
  SampleInformation();
  
  for( uint s=0; s<m_Systs.size(); s++ ){
    //std::cout<<"s = " << s <<"  m_Systs.at(s) = " << m_Systs.at(s) <<std::endl;
    ProcessEvent( m_Systs.at(s) );
  }
  
  return EL::StatusCode::SUCCESS;
  
}



EL::StatusCode HighMassLFV :: postExecute (){
  
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  return EL::StatusCode::SUCCESS;
  
}



EL::StatusCode HighMassLFV :: finalize (){
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.
  
  for( uint s=0; s<m_Systs.size(); s++ ){
    FillCutFlowHists( m_Systs.at(s) );
  }
  for( int ch=1; ch<4; ch++ ){
    FillWeightsHists(ch);
  }
  FillSampleInformation();
  if( m_PrintFlow ){
    PrintCutFlows();
    PrintWeights();
  }
  ToolsDestructor();
  
  return EL::StatusCode::SUCCESS;
  
}

EL::StatusCode HighMassLFV :: histFinalize (){
  
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.
  return EL::StatusCode::SUCCESS;
  
}
