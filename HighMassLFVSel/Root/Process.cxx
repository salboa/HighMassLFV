#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: ProcessEvent(int sysVar){

  ResetVariables();
  
  event  = m_eventInfo->eventNumber();
  run    = m_eventInfo->runNumber();
  if( m_UseData )
    rndRun = m_eventInfo->runNumber();
  else
    rndRun = m_puTool->getRandomRunNumber(*m_eventInfo,true);
  
  DetectYear(rndRun);
  lbn    = m_eventInfo->lumiBlock();
  if( !m_isDeriv && !m_UseData){
    m_evtWeightSample += GetMCweight();
    m_evtSample       += 1;
  }
  
  //if( isMC ) ditauTrueM = TrueDiTauMass();
  //if( isMC ){ 
  //isTauContr = CheckTauContr();
  //std::cout<<"Normalisation "
  //<< m_mcInfo->GetSampleNormalization( m_eventInfo->mcChannelNumber(), 1., 
  //m_thpartCont, true) << std::endl;
  //}
  
  UpdateEvtFlow( sysVar, EvtFlow::Start, 1, GetEventWeight(false,false,false) );
  UpdateMuFlow ( sysVar, MuFlow::Start , (int)m_muonCont->size()   );
  UpdateElFlow ( sysVar, ElFlow::Start , (int)m_elecCont->size()   );
  UpdateTauFlow( sysVar, TauFlow::Start, (int)m_tauCont->size()    );
  UpdateJetFlow( sysVar, JtFlow::Start , (int)m_jetCont->size()    );
  UpdatePhFlow ( sysVar, PhFlow::Start , (int)m_phCont->size()     );
  
  /* Check Event */
  isEvtGood  = EventCheck();
  if( !isEvtGood ) return;
  UpdateEvtFlow( sysVar, EvtFlow::EvtClean, 1, GetEventWeight(false,false,false) );
  UpdateMuFlow ( sysVar, MuFlow::EvtClean , (int)m_muonCont->size()   );
  UpdateElFlow ( sysVar, ElFlow::EvtClean , (int)m_elecCont->size()   );
  UpdateTauFlow( sysVar, TauFlow::EvtClean, (int)m_tauCont->size()    );
  UpdateJetFlow( sysVar, JtFlow::EvtClean , (int)m_jetCont->size()    );
  UpdatePhFlow ( sysVar, PhFlow::EvtClean , (int)m_phCont->size()     );

  /* Check Primary Vertex */
  FindPriVtx();
  isVertexGood = VertexCheck();
  if( !isVertexGood ) return;
  UpdateEvtFlow( sysVar, EvtFlow::Vertex, 1, GetEventWeight(false,false,false) );
  UpdateMuFlow ( sysVar, MuFlow::Vertex , (int)m_muonCont->size()   );
  UpdateElFlow ( sysVar, ElFlow::Vertex , (int)m_elecCont->size()   );
  UpdateTauFlow( sysVar, TauFlow::Vertex, (int)m_tauCont->size()    );
  UpdateJetFlow( sysVar, JtFlow::Vertex , (int)m_jetCont->size()    );
  UpdatePhFlow ( sysVar, PhFlow::Vertex , (int)m_phCont->size()     );
  
  /* Check Trigger */
  isTrigGood = TriggerCheck();
  if( !m_DbgStream ){
    if( !isTrigGood ) return;
  }
  UpdateEvtFlow( sysVar, EvtFlow::Trigger, 1, GetEventWeight(false,false,false) );
  UpdateMuFlow ( sysVar, MuFlow::Trigger , (int)m_muonCont->size()   );
  UpdateElFlow ( sysVar, ElFlow::Trigger , (int)m_elecCont->size()   );
  UpdateTauFlow( sysVar, TauFlow::Trigger, (int)m_tauCont->size()    );
  UpdateJetFlow( sysVar, JtFlow::Trigger , (int)m_jetCont->size()    );
  UpdatePhFlow ( sysVar, PhFlow::Trigger , (int)m_phCont->size()     );
  
  if( m_UseCorr || m_UseWgt )
    m_eventInfo->auxdecor<unsigned int>("RandomRunNumber") = rndRun;
  
  /* Select Leptons */
  CreateShallowCopies();
  if( isMC && m_UseWgt) m_jetFrwJvtTool->tagTruth(m_jetContCopy,m_thjetCont); //DecorateJets();
  PreSelectMuons(sysVar);
  PreSelectElectrons(sysVar);
  PreSelectTaus(sysVar);
  PreSelectJets(sysVar);
  SelectPhotons(sysVar);
  CheckObjectsOverlap();
  CheckMuons(sysVar);
  CheckElectrons(sysVar);
  CheckTaus(sysVar);
  CheckJets(sysVar);

  isBadMuonEvt = MuonBasedEventCleaning();
  if( isBadMuonEvt ){
    CleanMemory();
    return;
  }
  UpdateEvtFlow( sysVar, EvtFlow::BadMuon, 1, GetEventWeight(false,false,false) );
    
  isBadJetEvt = m_badJetEvt;
  if( isBadJetEvt ){
    CleanMemory();
    return;
  }
  UpdateEvtFlow( sysVar, EvtFlow::BadJet, 1, GetEventWeight(false,false,false) );

  isTwoLep = CheckLeptons();
  if( !isTwoLep ){
    CleanMemory();
    return;
  }
  UpdateEvtFlow( sysVar, EvtFlow::Leptons, 1, GetEventWeight(false,false,false) );
  
  isNlepGood = CheckNumOfLeptons();
  if( !isNlepGood ){
    CleanMemory();
    return;
  }
  DetectChannel();
  
  UpdateChannelFlow( sysVar, EvtFlow::ThirdLepV, 1, GetEventWeight(true,false,false) );
  
  isTrgMtcGood = CheckTriggerMatch();
  if( !m_DbgStream ){
    if( !isTrgMtcGood ){
      CleanMemory();
      return;
    }
  }
  UpdateChannelFlow( sysVar, EvtFlow::TrigMatch, 1, GetEventWeight(true,false,false) );
  
  /* Check Lepton Pair */
  isOSGood  = CheckOS();
  /*
    if( !isOSGood ){
    CleanMemory();
    return;
    }
    if(isOSGood)
  */
  UpdateChannelFlow( sysVar, EvtFlow::OS_Pair, 1, GetEventWeight(true,false,false) );
  
  /* Check DeltaPhi*/
  isBTBGood = CheckDeltaPhi();
  /*
    if( !isBTBGood ){
    CleanMemory();
    return;
    }
  */
  if( isBTBGood )
    UpdateChannelFlow( sysVar, EvtFlow::DeltaPhi, 1, GetEventWeight(true,true,false) );
  
  isBjetEvt = CheckBjet();
  if( isBTBGood && !isBjetEvt ){
    UpdateChannelFlow( sysVar, EvtFlow::BjetVeto, 1, GetEventWeight(true,true,true) );
    UpdateJetFlow( sysVar, JtFlow::BjetVeto, (int)m_Jets.size() );
  }
  
  avgIntxCross     = m_eventInfo->averageInteractionsPerCrossing();
  actIntxCross     = m_eventInfo->actualInteractionsPerCrossing();
  mcweight         = GetMCweight();
  puweight         = GetPUweight();
  puweight_SysUp   = GetPUweight(Pu_WgtSys::PuWgt_SysUp);
  puweight_SysDown = GetPUweight(Pu_WgtSys::PuWgt_SysDown);
  weight           = GetEventWeight(true,false,false);
  weightWjetSF     = GetEventWeight(true,true,false);
  weightWbtagSF    = GetEventWeight(true,true,false);
  xsec             = GetCrossSection();
  kfact            = GetKfactor();
  isKeepEvent      = CheckOverlap();
  
  if( sysVar==0 && isBTBGood ){
    UpdateWeight( m_Chan, Weights::MC, 1, mcweight );
    UpdateWeight( m_Chan, Weights::PU, 1, puweight );
    if( !isBjetEvt ){
      UpdateWeightBJ( m_Chan, Weights::MC, 1, mcweight );
      UpdateWeightBJ( m_Chan, Weights::PU, 1, puweight );
    }
  }

  BuildMET(sysVar);
  FillMETQuantities();
  if( (*m_BuildMet)["FinalTrk"]->met()/GeV < m_MetCut && isBTBGood && !isBjetEvt ){
    isMetGood = true;
    UpdateChannelFlow( sysVar, EvtFlow::MET, 1, GetEventWeight(true,true,true) );
  }
  channel = m_Chan;
  FillDiLeptonQuantities();
  FillLeptonQuantities(sysVar);
  FillJetQuantities(sysVar);
  filename = m_tmpName;
  
  m_TreesMap[sysVar]->Fill();
  
  CleanMemory(true);
  
}
