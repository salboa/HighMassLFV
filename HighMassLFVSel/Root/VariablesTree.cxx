#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: SetTreeBranches(){

  for( uint i=0; i<m_TreesMap.size(); i++ ){
    if(m_UseData)
       m_TreesMap[i]->Branch( "filename"      ,  &filename         );
       
    m_TreesMap[i]->Branch( "event"            ,  &event            );
    m_TreesMap[i]->Branch( "run"              ,  &run              );
    m_TreesMap[i]->Branch( "rndRun"           ,  &rndRun           );
    m_TreesMap[i]->Branch( "lbn"              ,  &lbn              );
    m_TreesMap[i]->Branch( "avgIntxCross"     ,  &avgIntxCross     );
    m_TreesMap[i]->Branch( "actIntxCross"     ,  &actIntxCross     );
    m_TreesMap[i]->Branch( "mcweight"         ,  &mcweight         );
    m_TreesMap[i]->Branch( "puweight"         ,  &puweight         );
    m_TreesMap[i]->Branch( "puweight_SysUp"   ,  &puweight_SysUp   );
    m_TreesMap[i]->Branch( "puweight_SysDown" ,  &puweight_SysDown );
    m_TreesMap[i]->Branch( "weight"           ,  &weight           );
    m_TreesMap[i]->Branch( "weightWjetSF"     ,  &weightWjetSF     );
    m_TreesMap[i]->Branch( "weightWbtagSF"    ,  &weightWbtagSF    );
    m_TreesMap[i]->Branch( "xsec"             ,  &xsec             );
    m_TreesMap[i]->Branch( "kfact"            ,  &kfact            );
    m_TreesMap[i]->Branch( "isKeepEvent"      ,  &isKeepEvent      );
    m_TreesMap[i]->Branch( "isEvtGood"        ,  &isEvtGood        );
    m_TreesMap[i]->Branch( "isVertexGood"     ,  &isVertexGood     );
    m_TreesMap[i]->Branch( "isTrigGood"       ,  &isTrigGood       );
    m_TreesMap[i]->Branch( "isMuonTrig"       ,  &isMuonTrig       );
    m_TreesMap[i]->Branch( "isElecTrig"       ,  &isElecTrig       );
    m_TreesMap[i]->Branch( "channel"          ,  &channel          );
    m_TreesMap[i]->Branch( "isTrgMtcGood"     ,  &isTrgMtcGood     );
    m_TreesMap[i]->Branch( "isNlepGood"       ,  &isNlepGood       );
    m_TreesMap[i]->Branch( "isOSGood"         ,  &isOSGood         );
    m_TreesMap[i]->Branch( "isBTBGood"        ,  &isBTBGood        );
    m_TreesMap[i]->Branch( "isBjetEvt"        ,  &isBjetEvt        );
    m_TreesMap[i]->Branch( "isMetGood"        ,  &isMetGood        );
    m_TreesMap[i]->Branch( "dilepMass"        ,  &dilepMass        );
    m_TreesMap[i]->Branch( "dilepCorrMass"    ,  &dilepCorrMass    );
    m_TreesMap[i]->Branch( "dilepPt"          ,  &dilepPt          );
    m_TreesMap[i]->Branch( "dilepCorrPt"      ,  &dilepCorrPt      );
    m_TreesMap[i]->Branch( "dilepEta"         ,  &dilepEta         );
    m_TreesMap[i]->Branch( "dilepPhi"         ,  &dilepPhi         );
    m_TreesMap[i]->Branch( "dilepDeltaPhi"    ,  &dilepDeltaPhi    );
    m_TreesMap[i]->Branch( "ditauTrueM"       ,  &ditauTrueM       );
    m_TreesMap[i]->Branch( "isTauContr"       ,  &isTauContr       );
    m_TreesMap[i]->Branch( "met_px"           ,  &met_px           );
    m_TreesMap[i]->Branch( "met_py"           ,  &met_py           );
    m_TreesMap[i]->Branch( "met_phi"          ,  &met_phi          );
    m_TreesMap[i]->Branch( "met_et"           ,  &met_et           );
    m_TreesMap[i]->Branch( "met_sumet"        ,  &met_sumet        );
    
    /* Leptons */			   		     
    m_TreesMap[i]->Branch( "Lep_Id"                 ,  &Lep_Id                 );
    m_TreesMap[i]->Branch( "Lep_pt"                 ,  &Lep_pt                 );
    m_TreesMap[i]->Branch( "Lep_E"                  ,  &Lep_E                  );
    m_TreesMap[i]->Branch( "Lep_eta"                ,  &Lep_eta                );
    m_TreesMap[i]->Branch( "Lep_etaTrk"             ,  &Lep_etaTrk             );
    m_TreesMap[i]->Branch( "Lep_phi"                ,  &Lep_phi                );
    m_TreesMap[i]->Branch( "Lep_d0"                 ,  &Lep_d0                 );
    m_TreesMap[i]->Branch( "Lep_d0sig"              ,  &Lep_d0sig              );
    m_TreesMap[i]->Branch( "Lep_z0"                 ,  &Lep_z0                 );
    m_TreesMap[i]->Branch( "Lep_deltaz0"            ,  &Lep_deltaz0            );
    m_TreesMap[i]->Branch( "Lep_Iso"                ,  &Lep_Iso                );
    m_TreesMap[i]->Branch( "Lep_trkIsoPt"           ,  &Lep_trkIsoPt           );
    m_TreesMap[i]->Branch( "Lep_caloIsoPt"          ,  &Lep_caloIsoPt          );
    m_TreesMap[i]->Branch( "Lep_trigMat"            ,  &Lep_trigMat            );
    m_TreesMap[i]->Branch( "Lep_nProngs"            ,  &Lep_nProngs            );
    						    			       
    m_TreesMap[i]->Branch( "Lep_TrigSF"             ,  &Lep_TrigSF             );
    m_TreesMap[i]->Branch( "Lep_TrigSF_StatUp"      ,  &Lep_TrigSF_StatUp      );
    m_TreesMap[i]->Branch( "Lep_TrigSF_StatDown"    ,  &Lep_TrigSF_StatDown    );
    m_TreesMap[i]->Branch( "Lep_TrigSF_SysUp"       ,  &Lep_TrigSF_SysUp       );
    m_TreesMap[i]->Branch( "Lep_TrigSF_SysDown"     ,  &Lep_TrigSF_SysDown     );
    						    			       
    m_TreesMap[i]->Branch( "Lep_RecoSF"             ,  &Lep_RecoSF             );
    m_TreesMap[i]->Branch( "Lep_RecoSF_StatUp"      ,  &Lep_RecoSF_StatUp      );
    m_TreesMap[i]->Branch( "Lep_RecoSF_StatDown"    ,  &Lep_RecoSF_StatDown    );
    m_TreesMap[i]->Branch( "Lep_RecoSF_SysUp"       ,  &Lep_RecoSF_SysUp       );
    m_TreesMap[i]->Branch( "Lep_RecoSF_SysDown"     ,  &Lep_RecoSF_SysDown     );
    m_TreesMap[i]->Branch( "Lep_RecoSF_Hpt_SysUp"   ,  &Lep_RecoSF_Hpt_SysUp   );
    m_TreesMap[i]->Branch( "Lep_RecoSF_Hpt_SysDown" ,  &Lep_RecoSF_Hpt_SysDown );
    
    m_TreesMap[i]->Branch( "Lep_IDSF"               ,  &Lep_IDSF               );
    m_TreesMap[i]->Branch( "Lep_IDSF_StatUp"        ,  &Lep_IDSF_StatUp        );
    m_TreesMap[i]->Branch( "Lep_IDSF_StatDown"      ,  &Lep_IDSF_StatDown      );
    m_TreesMap[i]->Branch( "Lep_IDSF_SysUp"         ,  &Lep_IDSF_SysUp         );
    m_TreesMap[i]->Branch( "Lep_IDSF_SysDown"       ,  &Lep_IDSF_SysDown       );
    m_TreesMap[i]->Branch( "Lep_IDSF_Hpt_SysUp"     ,  &Lep_IDSF_Hpt_SysUp     );
    m_TreesMap[i]->Branch( "Lep_IDSF_Hpt_SysDown"   ,  &Lep_IDSF_Hpt_SysDown   );
    
    m_TreesMap[i]->Branch( "Lep_IsoSF"              ,  &Lep_IsoSF              );
    m_TreesMap[i]->Branch( "Lep_IsoSF_StatUp"       ,  &Lep_IsoSF_StatUp       );
    m_TreesMap[i]->Branch( "Lep_IsoSF_StatDown"     ,  &Lep_IsoSF_StatDown     );
    m_TreesMap[i]->Branch( "Lep_IsoSF_SysUp"        ,  &Lep_IsoSF_SysUp        );
    m_TreesMap[i]->Branch( "Lep_IsoSF_SysDown"      ,  &Lep_IsoSF_SysDown      ); 

    m_TreesMap[i]->Branch( "Lep_TtvaSF"             ,  &Lep_TtvaSF             );
    m_TreesMap[i]->Branch( "Lep_TtvaSF_StatUp"      ,  &Lep_TtvaSF_StatUp      );
    m_TreesMap[i]->Branch( "Lep_TtvaSF_StatDown"    ,  &Lep_TtvaSF_StatDown    );
    m_TreesMap[i]->Branch( "Lep_TtvaSF_SysUp"       ,  &Lep_TtvaSF_SysUp       );
    m_TreesMap[i]->Branch( "Lep_TtvaSF_SysDown"     ,  &Lep_TtvaSF_SysDown     );
    
    m_TreesMap[i]->Branch( "Lep_BadMuSF"            ,  &Lep_BadMuSF            );
    //add badmuonveto SF sys if exists

    m_TreesMap[i]->Branch( "Lep_L1CaloSF"           ,  &Lep_L1CaloSF           );

    m_TreesMap[i]->Branch( "Lep_ElOlrSF"            ,  &Lep_ElOlrSF            );
    m_TreesMap[i]->Branch( "Lep_ElOlrSF_SysUp"      ,  &Lep_ElOlrSF_SysUp      );
    m_TreesMap[i]->Branch( "Lep_ElOlrSF_SysDown"    ,  &Lep_ElOlrSF_SysDown    );

    
    /* Jets */
    m_TreesMap[i]->Branch( "Jet_pt"            ,  &Jet_pt            );
    m_TreesMap[i]->Branch( "Jet_etaEM"         ,  &Jet_etaEM         );
    m_TreesMap[i]->Branch( "Jet_eta"           ,  &Jet_eta           );
    m_TreesMap[i]->Branch( "Jet_phi"           ,  &Jet_phi           );
    m_TreesMap[i]->Branch( "Jet_JvtSF"         ,  &Jet_JvtSF         );
    m_TreesMap[i]->Branch( "Jet_JvtSF_SysUp"   ,  &Jet_JvtSF_SysUp   );
    m_TreesMap[i]->Branch( "Jet_JvtSF_SysDown" ,  &Jet_JvtSF_SysDown );
    m_TreesMap[i]->Branch( "Jet_isBjet"        ,  &Jet_isBjet        );
    m_TreesMap[i]->Branch( "Jet_BtagSF"        ,  &Jet_BtagSF        );
    
    m_TreesMap[i]->Branch( "Jet_BtagSF_Beff_SysUp"      , &Jet_BtagSF_Beff_SysUp      );
    m_TreesMap[i]->Branch( "Jet_BtagSF_Beff_SysDown"    , &Jet_BtagSF_Beff_SysDown    );
    m_TreesMap[i]->Branch( "Jet_BtagSF_Ceff_SysUp"      , &Jet_BtagSF_Ceff_SysUp      );
    m_TreesMap[i]->Branch( "Jet_BtagSF_Ceff_SysDown"    , &Jet_BtagSF_Ceff_SysDown    );
    m_TreesMap[i]->Branch( "Jet_BtagSF_Leff_SysUp"      , &Jet_BtagSF_Leff_SysUp      );
    m_TreesMap[i]->Branch( "Jet_BtagSF_Leff_SysDown"    , &Jet_BtagSF_Leff_SysDown    );
    m_TreesMap[i]->Branch( "Jet_BtagSF_ExtCeff_SysUp"   , &Jet_BtagSF_ExtCeff_SysUp   );
    m_TreesMap[i]->Branch( "Jet_BtagSF_ExtCeff_SysDown" , &Jet_BtagSF_ExtCeff_SysDown );    
    m_TreesMap[i]->Branch( "Jet_BtagSF_ExtEff_SysUp"    , &Jet_BtagSF_ExtEff_SysUp    );
    m_TreesMap[i]->Branch( "Jet_BtagSF_ExtEff_SysDown"  , &Jet_BtagSF_ExtEff_SysDown  );
    
  }

  if( m_verbose ) Info( "SetTreeBranches()", "Tree Branches setup!" );
  
}

void HighMassLFV :: ResetVariables(){
  
  m_priVtxFound    = false;
  m_priVtx         = 0;
  m_badJetEvt      = false;
  
  filename         = "";
  event            = -1;
  run              = -1;
  rndRun           = -1;
  lbn              = -1;
  mcweight         =  1;
  puweight         =  1;
  puweight_SysUp   =  1;
  puweight_SysDown =  1;
  weight           =  1;
  weightWjetSF     =  1;
  weightWbtagSF    =  1;
  xsec             =  1;
  kfact            =  1;
  avgIntxCross     = -1;
  actIntxCross     = -1;
  isKeepEvent      = false;
  isEvtGood        = false;
  isVertexGood     = false;
  isTrigGood       = false;
  isMuonTrig       = false;
  isElecTrig       = false;
  
  channel          = -1;
  isTrgMtcGood     = false;
  isTwoLep         = false;
  isNlepGood       = false;
  isBadMuonEvt     = false;
  isBadJetEvt      = false;
  isOSGood         = false;
  isBTBGood        = false;
  isBjetEvt        = false;
  isMetGood        = false;
  dilepMass        = -999999;
  dilepCorrMass    = -999999;
  dilepPt          = -999999;
  dilepCorrPt      = -999999;
  dilepEta         = -999999;
  dilepPhi         = -999999;
  dilepDeltaPhi    = -999999;
  ditauTrueM       = -999999;
  isTauContr       = false;
  met_px           = -999999;
  met_py           = -999999;
  met_phi          = -999999;
  met_et           = -999999;
  met_sumet        = -999999;

  Lep_Id.clear();
  Lep_pt.clear();
  Lep_E.clear();
  Lep_eta.clear();
  Lep_etaTrk.clear();
  Lep_phi.clear();
  Lep_d0.clear();
  Lep_d0sig.clear();
  Lep_z0.clear();
  Lep_deltaz0.clear();
  Lep_Iso.clear();
  Lep_trkIsoPt.clear();
  Lep_caloIsoPt.clear();
  Lep_trigMat.clear();
  Lep_nProngs.clear();

  Lep_TrigSF.clear();
  Lep_TrigSF_StatUp.clear();
  Lep_TrigSF_StatDown.clear();
  Lep_TrigSF_SysUp.clear();
  Lep_TrigSF_SysDown.clear();
  
  Lep_RecoSF.clear();
  Lep_RecoSF_StatUp.clear();
  Lep_RecoSF_StatDown.clear();
  Lep_RecoSF_SysUp.clear();
  Lep_RecoSF_SysDown.clear();
  Lep_RecoSF_Hpt_SysUp.clear();
  Lep_RecoSF_Hpt_SysDown.clear();

  Lep_IDSF.clear();
  Lep_IDSF_StatUp.clear();
  Lep_IDSF_StatDown.clear();
  Lep_IDSF_SysUp.clear();
  Lep_IDSF_SysDown.clear();
  Lep_IDSF_Hpt_SysUp.clear();
  Lep_IDSF_Hpt_SysDown.clear();

  Lep_IsoSF.clear();
  Lep_IsoSF_StatUp.clear();
  Lep_IsoSF_StatDown.clear();
  Lep_IsoSF_SysUp.clear();
  Lep_IsoSF_SysDown.clear();

  Lep_TtvaSF.clear();
  Lep_TtvaSF_StatUp.clear();
  Lep_TtvaSF_StatDown.clear();
  Lep_TtvaSF_SysUp.clear();
  Lep_TtvaSF_SysDown.clear();

  Lep_BadMuSF.clear();

  Lep_L1CaloSF.clear();
  
  Lep_ElOlrSF.clear();
  Lep_ElOlrSF_SysUp.clear();
  Lep_ElOlrSF_SysDown.clear(); 
  
  Jet_pt.clear();
  Jet_etaEM.clear();
  Jet_eta.clear();
  Jet_phi.clear();
  Jet_JvtSF.clear();
  Jet_JvtSF_SysUp.clear();
  Jet_JvtSF_SysDown.clear();
  Jet_isBjet.clear();
  Jet_BtagSF.clear();

  Jet_BtagSF_Beff_SysUp.clear();
  Jet_BtagSF_Beff_SysDown.clear();
  Jet_BtagSF_Ceff_SysUp.clear();
  Jet_BtagSF_Ceff_SysDown.clear();
  Jet_BtagSF_Leff_SysUp.clear();
  Jet_BtagSF_Leff_SysDown.clear();
  Jet_BtagSF_ExtCeff_SysUp.clear();
  Jet_BtagSF_ExtCeff_SysDown.clear();
  Jet_BtagSF_ExtEff_SysUp.clear();
  Jet_BtagSF_ExtEff_SysDown.clear();

  if( m_verbose ) Info( "ResetVariables()", "Variables Reset to default value!" );
  
}
