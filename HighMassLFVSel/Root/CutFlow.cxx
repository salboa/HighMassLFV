#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: CutFlowInit(){
  
  FillCutLevelNames();
  FillWeightsNames();
  InitializeCutLevelMaps();
  InitializeWeightsMaps();
  m_EvtFlowBins  = (int)m_EvtFlowName.size()+(int)m_EMUFlowName.size();
  m_MuFlowBins   = (int)m_MuFlowName.size();
  m_ElFlowBins   = (int)m_ElFlowName.size();
  m_TauFlowBins  = (int)m_TauFlowName.size();
  m_JtFlowBins   = (int)m_JtFlowName.size();
  m_PhFlowBins   = (int)m_PhFlowName.size();
  m_WeightBins   = (int)m_WeightName.size();
  m_WeightBJBins = (int)m_WeightName.size();
  Info( "CutFlowInit()" , "CutFlow variables and maps initialized" );
  
}

void HighMassLFV :: FillCutLevelNames(){

  m_EvtFlowName [ EvtFlow::Start     ] = "Start";
  m_EvtFlowName [ EvtFlow::EvtClean  ] = "Event Cleaning";
  m_EvtFlowName [ EvtFlow::Vertex    ] = "Vertex";
  m_EvtFlowName [ EvtFlow::Trigger   ] = "Trigger";
  m_EvtFlowName [ EvtFlow::BadMuon   ] = "Bad Muon";
  m_EvtFlowName [ EvtFlow::BadJet    ] = "Bad Jet";
  m_EvtFlowName [ EvtFlow::Leptons   ] = "Leptons";
  
  m_EMUFlowName [ EvtFlow::ThirdLepV ] = "3rd Lepton Veto";
  m_EMUFlowName [ EvtFlow::TrigMatch ] = "Trigger Match";
  m_EMUFlowName [ EvtFlow::OS_Pair   ] = "OS pair";
  m_EMUFlowName [ EvtFlow::DeltaPhi  ] = "DeltaPhi";
  m_EMUFlowName [ EvtFlow::BjetVeto  ] = "B-Jet Veto";
  m_EMUFlowName [ EvtFlow::MET       ] = "MET";
  
  m_ETAUFlowName [ EvtFlow::ThirdLepV ] = "3rd Lepton Veto";
  m_ETAUFlowName [ EvtFlow::TrigMatch ] = "Trigger Match";
  m_ETAUFlowName [ EvtFlow::OS_Pair   ] = "OS pair";
  m_ETAUFlowName [ EvtFlow::DeltaPhi  ] = "DeltaPhi";
  m_ETAUFlowName [ EvtFlow::BjetVeto  ] = "B-Jet Veto";
  m_ETAUFlowName [ EvtFlow::MET       ] = "MET";

  m_MUTAUFlowName [ EvtFlow::ThirdLepV ] = "3rd Lepton Veto";
  m_MUTAUFlowName [ EvtFlow::TrigMatch ] = "Trigger Match";
  m_MUTAUFlowName [ EvtFlow::OS_Pair   ] = "OS pair";
  m_MUTAUFlowName [ EvtFlow::DeltaPhi  ] = "DeltaPhi";
  m_MUTAUFlowName [ EvtFlow::BjetVeto  ] = "B-Jet Veto";
  m_MUTAUFlowName [ EvtFlow::MET       ] = "MET";

  m_MuFlowName [ MuFlow::Start     ] = "Start";
  m_MuFlowName [ MuFlow::EvtClean  ] = "Event Cleaning";
  m_MuFlowName [ MuFlow::Vertex    ] = "Vertex";
  m_MuFlowName [ MuFlow::Trigger   ] = "Trigger";
  m_MuFlowName [ MuFlow::TrigMatch ] = "Trigger Match";
  m_MuFlowName [ MuFlow::Pt        ] = "Pt";
  m_MuFlowName [ MuFlow::Eta_ID_Q  ] = "Eta/ID/Quality";
  m_MuFlowName [ MuFlow::HighPtCut ] = "HighPtCuts";
  m_MuFlowName [ MuFlow::D0Sign    ] = "IP Sign (d0)";
  m_MuFlowName [ MuFlow::DeltaZ0   ] = "Delta z0";
  m_MuFlowName [ MuFlow::Overlaps  ] = "Overlaps";
  m_MuFlowName [ MuFlow::Isolation ] = "Isolation";
  m_MuFlowName [ MuFlow::TightMu   ] = "Tight Muons";
  m_MuFlowName [ MuFlow::LooseMu   ] = "Loose Muons";
	       
  m_ElFlowName [ ElFlow::Start     ] = "Start";
  m_ElFlowName [ ElFlow::EvtClean  ] = "Event Cleaning";
  m_ElFlowName [ ElFlow::Vertex    ] = "Vertex";
  m_ElFlowName [ ElFlow::Trigger   ] = "Trigger";
  m_ElFlowName [ ElFlow::TrigMatch ] = "Trigger Match";
  m_ElFlowName [ ElFlow::Author    ] = "Author";
  m_ElFlowName [ ElFlow::Pt        ] = "Pt";
  m_ElFlowName [ ElFlow::Eta       ] = "Eta";
  m_ElFlowName [ ElFlow::ObjectQ   ] = "Obj Quality";
  m_ElFlowName [ ElFlow::ElecID    ] = "Likelihood ID";
  m_ElFlowName [ ElFlow::D0Sign    ] = "IP Sign (d0)";
  m_ElFlowName [ ElFlow::DeltaZ0   ] = "Delta z0";
  m_ElFlowName [ ElFlow::Overlaps  ] = "Overlaps";
  m_ElFlowName [ ElFlow::MuElOve   ] = "Mu-El Overlap";
  m_ElFlowName [ ElFlow::Isolation ] = "Isolation";
  m_ElFlowName [ ElFlow::TightEl   ] = "Tight Electrons";
  m_ElFlowName [ ElFlow::LooseEl   ] = "Loose Electrons";
  
  m_TauFlowName [ TauFlow::Start     ] = "Start";
  m_TauFlowName [ TauFlow::EvtClean  ] = "Event Cleaning";
  m_TauFlowName [ TauFlow::Vertex    ] = "Vertex";
  m_TauFlowName [ TauFlow::Trigger   ] = "Trigger";
  m_TauFlowName [ TauFlow::TrigMatch ] = "Trigger Match";
  m_TauFlowName [ TauFlow::Pt        ] = "Pt";
  m_TauFlowName [ TauFlow::Eta       ] = "Eta";
  m_TauFlowName [ TauFlow::Charge    ] = "Charge";
  m_TauFlowName [ TauFlow::nTracks   ] = "nTracks";
  m_TauFlowName [ TauFlow::BDTscore  ] = "BDTscore";
  m_TauFlowName [ TauFlow::JetIDWP   ] = "JetIDWP";
  m_TauFlowName [ TauFlow::ElOR      ] = "Electron OR";
  m_TauFlowName [ TauFlow::Overlaps  ] = "Overlaps";
  m_TauFlowName [ TauFlow::TaMuOve   ] = "Tau-Mu Overlap";
  m_TauFlowName [ TauFlow::TaElOve   ] = "Tau-El Overlap";
  
  m_JtFlowName [ JtFlow::Start         ] = "Start";
  m_JtFlowName [ JtFlow::EvtClean      ] = "Event Cleaning";
  m_JtFlowName [ JtFlow::Vertex        ] = "Vertex";
  m_JtFlowName [ JtFlow::Trigger       ] = "Trigger";
  m_JtFlowName [ JtFlow::Pt            ] = "Pt";
  m_JtFlowName [ JtFlow::Eta           ] = "Eta";
  m_JtFlowName [ JtFlow::Overlaps      ] = "Overlaps";
  m_JtFlowName [ JtFlow::JetElOverlap  ] = "Jet-Electron Overlap";
  m_JtFlowName [ JtFlow::JetTauOverlap ] = "Jet-Tau Overlap";
  m_JtFlowName [ JtFlow::JetMuOverlap  ] = "Jet-Muon Overlap";
  m_JtFlowName [ JtFlow::JVT           ] = "JTV";
  m_JtFlowName [ JtFlow::Clean         ] = "Clean";
  m_JtFlowName [ JtFlow::BjetVeto      ] = "B-Jet Veto";
  m_JtFlowName [ JtFlow::Bjet          ] = "B-Jets";

  m_PhFlowName [ PhFlow::Start    ] = "Start";
  m_PhFlowName [ PhFlow::EvtClean ] = "Event Cleaning";
  m_PhFlowName [ PhFlow::Vertex   ] = "Vertex";
  m_PhFlowName [ PhFlow::Trigger  ] = "Trigger";
  m_PhFlowName [ PhFlow::Pt       ] = "Pt";
  m_PhFlowName [ PhFlow::Eta      ] = "Eta";
  m_PhFlowName [ PhFlow::Author   ] = "Author";
  m_PhFlowName [ PhFlow::ObjQual  ] = "Obj Quality";
  m_PhFlowName [ PhFlow::Clean    ] = "Clean";

  if( m_verbose ) Info( "FillCutLevelNames()", "Cut Level Maps Filled!" );
  
}

void HighMassLFV :: FillWeightsNames(){
  
  m_WeightName [ Weights::MC                     ] = "MC weight";
  m_WeightName [ Weights::PU                     ] = "PU weight";
  m_WeightName [ Weights::PU_SysUp               ] = "PU_SysUp weight";
  m_WeightName [ Weights::PU_SysDown             ] = "PU_SysDown  weight";
  m_WeightName [ Weights::ElReco                 ] = "ElReco weight";
  m_WeightName [ Weights::ElReco_SysUp           ] = "ElReco_SysUp    weight";
  m_WeightName [ Weights::ElReco_SysDown         ] = "ElReco_SysDown  weight";
  m_WeightName [ Weights::ElID                   ] = "ElID weight";
  m_WeightName [ Weights::ElID_SysUp             ] = "ElID_SysUp    weight";
  m_WeightName [ Weights::ElID_SysDown           ] = "ElID_SysDown  weight";
  m_WeightName [ Weights::ElIso                  ] = "ElIso weight";
  m_WeightName [ Weights::ElIso_SysUp            ] = "ElIso_SysUp    weight";
  m_WeightName [ Weights::ElIso_SysDown          ] = "ElIso_SysDown  weight";
  m_WeightName [ Weights::ElTrig                 ] = "ElTrig weight";
  m_WeightName [ Weights::ElTrig_SysUp           ] = "ElTrig_SysUp    weight";
  m_WeightName [ Weights::ElTrig_SysDown         ] = "ElTrig_SysDown  weight";
  m_WeightName [ Weights::ElL1Calo               ] = "ElL1Calo";
  m_WeightName [ Weights::MuReco                 ] = "MuReco weight";
  m_WeightName [ Weights::MuReco_StatUp          ] = "MuReco_StatUp   weight";
  m_WeightName [ Weights::MuReco_StatDown        ] = "MuReco_StatDown weight";
  m_WeightName [ Weights::MuReco_SysUp           ] = "MuReco_SysUp    weight";
  m_WeightName [ Weights::MuReco_SysDown         ] = "MuReco_SysDown  weight";
  m_WeightName [ Weights::MuIso                  ] = "MuIso weight";	  
  m_WeightName [ Weights::MuIso_StatUp           ] = "MuIso_StatUp   weight"; 
  m_WeightName [ Weights::MuIso_StatDown         ] = "MuIso_StatDown weight"; 
  m_WeightName [ Weights::MuIso_SysUp            ] = "MuIso_SysUp    weight"; 
  m_WeightName [ Weights::MuIso_SysDown          ] = "MuIso_SysDown  weight"; 
  m_WeightName [ Weights::MuTrig                 ] = "MuTrig weight";	  
  m_WeightName [ Weights::MuTrig_StatUp          ] = "MuTrig_StatUp   weight";
  m_WeightName [ Weights::MuTrig_StatDown        ] = "MuTrig_StatDown weight";
  m_WeightName [ Weights::MuTrig_SysUp           ] = "MuTrig_SysUp    weight";
  m_WeightName [ Weights::MuTrig_SysDown         ] = "MuTrig_SysDown  weight";
  m_WeightName [ Weights::MuTTVA                 ] = "MuTTVA weight";
  m_WeightName [ Weights::MuTTVA_StatUp          ] = "MuTTVA_StatUp   weight";
  m_WeightName [ Weights::MuTTVA_StatDown        ] = "MuTTVA_StatDown weight";
  m_WeightName [ Weights::MuTTVA_SysUp           ] = "MuTTVA_SysUp    weight";
  m_WeightName [ Weights::MuTTVA_SysDown         ] = "MuTTVA_SysDown  weight";
  m_WeightName [ Weights::TaReco                 ] = "TaReco weight";
  m_WeightName [ Weights::TaReco_SysUp           ] = "TaReco_SysUp       weight";
  m_WeightName [ Weights::TaReco_SysDown         ] = "TaReco_SysDown     weight";
  m_WeightName [ Weights::TaReco_Hpt_SysUp       ] = "TaReco_Hpt_SysUp   weight";
  m_WeightName [ Weights::TaReco_Hpt_SysDown     ] = "TaReco_Hpt_SysDown weight";
  m_WeightName [ Weights::TaID                   ] = "TaID             weight";
  m_WeightName [ Weights::TaID_SysUp             ] = "TaID_SysUp       weight";
  m_WeightName [ Weights::TaID_SysDown           ] = "TaID_SysDown     weight";
  m_WeightName [ Weights::TaID_Hpt_SysUp         ] = "TaID_Hpt_SysUp   weight";
  m_WeightName [ Weights::TaID_Hpt_SysDown       ] = "TaID_Hpt_SysDown weight";
  m_WeightName [ Weights::TaElOlr                ] = "TaElOlr         weight";
  m_WeightName [ Weights::TaElOlr_SysUp          ] = "TaElOlr_SysUp   weight";
  m_WeightName [ Weights::TaElOlr_SysDown        ] = "TaElOlr_SysDown weight";
  m_WeightName [ Weights::JtJvt                  ] = "JtJvt weight";
  m_WeightName [ Weights::JtJvt_SysUp            ] = "JtJvt_SysUp    weight";
  m_WeightName [ Weights::JtJvt_SysDown          ] = "JtJvt_SysDown  weight";
  m_WeightName [ Weights::BtagSF                 ] = "BtagSF weight";
  m_WeightName [ Weights::BtagSF_Beff_SysUp      ] = "BtagSF_Beff_SysUp   weight";
  m_WeightName [ Weights::BtagSF_Beff_SysDown    ] = "BtagSF_Beff_SysDown weight";
  m_WeightName [ Weights::BtagSF_Ceff_SysUp      ] = "BtagSF_Ceff_SysUp   weight";
  m_WeightName [ Weights::BtagSF_Ceff_SysDown    ] = "BtagSF_Ceff_SysDown weight";
  m_WeightName [ Weights::BtagSF_Leff_SysUp      ] = "BtagSF_Leff_SysUp   weight";
  m_WeightName [ Weights::BtagSF_Leff_SysDown    ] = "BtagSF_Leff_SysDown weight";
  m_WeightName [ Weights::BtagSF_ExtCeff_SysUp   ] = "BtagSF_ExtCeff_SysUp    weight";
  m_WeightName [ Weights::BtagSF_ExtCeff_SysDown ] = "BtagSF_ExtCeff_SysDownn weight";
  m_WeightName [ Weights::BtagSF_ExtEff_SysUp    ] = "BtagSF_ExtEff_SysUp     weight";
  m_WeightName [ Weights::BtagSF_ExtEff_SysDown  ] = "BtagSF_ExtEff_SysDown   weight";

  if( m_verbose ) Info( "FillWeightsNames()", "Weights Maps Filled!" );

}

void HighMassLFV :: InitializeCutLevelMaps(){

  for(uint t=0; t<m_Systs.size(); t++){
    /* Event Flow */
    m_EvtFlowMap [ m_Systs.at(t) ][ EvtFlow::Start     ] = 0;
    m_EvtFlowMap [ m_Systs.at(t) ][ EvtFlow::EvtClean  ] = 0;
    m_EvtFlowMap [ m_Systs.at(t) ][ EvtFlow::Vertex    ] = 0;
    m_EvtFlowMap [ m_Systs.at(t) ][ EvtFlow::Trigger   ] = 0;
    m_EvtFlowMap [ m_Systs.at(t) ][ EvtFlow::BadMuon   ] = 0;
    m_EvtFlowMap [ m_Systs.at(t) ][ EvtFlow::BadJet    ] = 0;
    m_EvtFlowMap [ m_Systs.at(t) ][ EvtFlow::Leptons   ] = 0;
    /* EMU Flow */
    m_EMUFlowMap [ m_Systs.at(t) ][ EvtFlow::ThirdLepV ] = 0;
    m_EMUFlowMap [ m_Systs.at(t) ][ EvtFlow::TrigMatch ] = 0;
    m_EMUFlowMap [ m_Systs.at(t) ][ EvtFlow::OS_Pair   ] = 0;
    m_EMUFlowMap [ m_Systs.at(t) ][ EvtFlow::DeltaPhi  ] = 0;
    m_EMUFlowMap [ m_Systs.at(t) ][ EvtFlow::BjetVeto  ] = 0;
    m_EMUFlowMap [ m_Systs.at(t) ][ EvtFlow::MET       ] = 0;
    /* ETAU Flow */
    m_ETAUFlowMap [ m_Systs.at(t) ][ EvtFlow::ThirdLepV ] = 0;
    m_ETAUFlowMap [ m_Systs.at(t) ][ EvtFlow::TrigMatch ] = 0;
    m_ETAUFlowMap [ m_Systs.at(t) ][ EvtFlow::OS_Pair   ] = 0;
    m_ETAUFlowMap [ m_Systs.at(t) ][ EvtFlow::DeltaPhi  ] = 0;
    m_ETAUFlowMap [ m_Systs.at(t) ][ EvtFlow::BjetVeto  ] = 0;
    m_ETAUFlowMap [ m_Systs.at(t) ][ EvtFlow::MET       ] = 0;
    /* MUTAU Flow */
    m_MUTAUFlowMap [ m_Systs.at(t) ][ EvtFlow::ThirdLepV ] = 0;
    m_MUTAUFlowMap [ m_Systs.at(t) ][ EvtFlow::TrigMatch ] = 0;
    m_MUTAUFlowMap [ m_Systs.at(t) ][ EvtFlow::OS_Pair   ] = 0;
    m_MUTAUFlowMap [ m_Systs.at(t) ][ EvtFlow::DeltaPhi  ] = 0;
    m_MUTAUFlowMap [ m_Systs.at(t) ][ EvtFlow::BjetVeto  ] = 0;   
    m_MUTAUFlowMap [ m_Systs.at(t) ][ EvtFlow::MET       ] = 0;
    /* Muon Flow*/
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::Start     ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::EvtClean  ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::Vertex    ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::Trigger   ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::TrigMatch ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::Pt        ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::Eta_ID_Q  ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::HighPtCut ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::D0Sign    ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::DeltaZ0   ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::Overlaps  ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::Isolation ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::TightMu   ] = 0;
    m_MuFlowMap [ m_Systs.at(t) ][ MuFlow::LooseMu   ] = 0;
    /* Electron Flow*/
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Start     ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::EvtClean  ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Vertex    ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Trigger   ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::TrigMatch ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Author    ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Pt        ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Eta       ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::ObjectQ   ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::ElecID    ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::D0Sign    ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::DeltaZ0   ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Overlaps  ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::MuElOve   ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::Isolation ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::TightEl   ] = 0;
    m_ElFlowMap [ m_Systs.at(t) ][ ElFlow::LooseEl   ] = 0;
    /* Tau Flow */
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::Start     ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::EvtClean  ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::Vertex    ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::Trigger   ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::TrigMatch ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::Pt        ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::Eta       ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::Charge    ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::nTracks   ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::BDTscore  ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::JetIDWP   ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::ElOR      ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::Overlaps  ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::TaMuOve   ] = 0;
    m_TauFlowMap [ m_Systs.at(t) ][ TauFlow::TaElOve   ] = 0;
    /* Jet Flow*/
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Start         ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::EvtClean      ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Vertex        ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Trigger       ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Pt            ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Eta           ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Overlaps      ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::JetElOverlap  ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::JetTauOverlap ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::JetMuOverlap  ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::JVT           ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Clean         ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::BjetVeto      ] = 0;
    m_JtFlowMap [ m_Systs.at(t) ][ JtFlow::Bjet          ] = 0;
    /*Photon Flow */
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::Start    ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::EvtClean ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::Vertex   ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::Trigger  ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::Pt       ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::Eta      ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::Author   ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::ObjQual  ] = 0;
    m_PhFlowMap [ m_Systs.at(t) ][ PhFlow::Clean    ] = 0;
  }

  if( m_verbose ) Info( "InitializeCutLevelMaps()", "Cut Level Maps Initialized!" );
  
}

void HighMassLFV :: InitializeWeightsMaps(){
  
  for(int i=1; i<4; i++){
    /* Weights w/o B-jet veto */
    m_WeightMap [i][ Weights::MC                     ] = 0;
    m_WeightMap [i][ Weights::PU                     ] = 0;
    m_WeightMap [i][ Weights::PU_SysUp               ] = 0;
    m_WeightMap [i][ Weights::PU_SysDown             ] = 0;
    m_WeightMap [i][ Weights::ElReco                 ] = 0;
    m_WeightMap [i][ Weights::ElReco_SysUp           ] = 0;
    m_WeightMap [i][ Weights::ElReco_SysDown         ] = 0;
    m_WeightMap [i][ Weights::ElID                   ] = 0;
    m_WeightMap [i][ Weights::ElID_SysUp             ] = 0;
    m_WeightMap [i][ Weights::ElID_SysDown           ] = 0;
    m_WeightMap [i][ Weights::ElIso                  ] = 0;
    m_WeightMap [i][ Weights::ElIso_SysUp            ] = 0;
    m_WeightMap [i][ Weights::ElIso_SysDown          ] = 0;
    m_WeightMap [i][ Weights::ElTrig                 ] = 0;
    m_WeightMap [i][ Weights::ElTrig_SysUp           ] = 0;
    m_WeightMap [i][ Weights::ElTrig_SysDown         ] = 0;
    m_WeightMap [i][ Weights::ElL1Calo               ] = 0;
    m_WeightMap [i][ Weights::MuReco                 ] = 0;
    m_WeightMap [i][ Weights::MuReco_StatUp          ] = 0;
    m_WeightMap [i][ Weights::MuReco_StatDown        ] = 0;
    m_WeightMap [i][ Weights::MuReco_SysUp           ] = 0;
    m_WeightMap [i][ Weights::MuReco_SysDown         ] = 0;
    m_WeightMap [i][ Weights::MuIso                  ] = 0;
    m_WeightMap [i][ Weights::MuIso_StatUp           ] = 0;
    m_WeightMap [i][ Weights::MuIso_StatDown         ] = 0;
    m_WeightMap [i][ Weights::MuIso_SysUp            ] = 0;
    m_WeightMap [i][ Weights::MuIso_SysDown          ] = 0;
    m_WeightMap [i][ Weights::MuTrig                 ] = 0;
    m_WeightMap [i][ Weights::MuTrig_StatUp          ] = 0;
    m_WeightMap [i][ Weights::MuTrig_StatDown        ] = 0;
    m_WeightMap [i][ Weights::MuTrig_SysUp           ] = 0;
    m_WeightMap [i][ Weights::MuTrig_SysDown         ] = 0;
    m_WeightMap [i][ Weights::MuTTVA                 ] = 0;
    m_WeightMap [i][ Weights::MuTTVA_StatUp          ] = 0;
    m_WeightMap [i][ Weights::MuTTVA_StatDown        ] = 0;
    m_WeightMap [i][ Weights::MuTTVA_SysUp           ] = 0;
    m_WeightMap [i][ Weights::MuTTVA_SysDown         ] = 0;
    m_WeightMap [i][ Weights::TaReco                 ] = 0;
    m_WeightMap [i][ Weights::TaReco_SysUp           ] = 0;
    m_WeightMap [i][ Weights::TaReco_SysDown         ] = 0;
    m_WeightMap [i][ Weights::TaReco_Hpt_SysUp       ] = 0;
    m_WeightMap [i][ Weights::TaReco_Hpt_SysDown     ] = 0;
    m_WeightMap [i][ Weights::TaID                   ] = 0;
    m_WeightMap [i][ Weights::TaID_SysUp             ] = 0;
    m_WeightMap [i][ Weights::TaID_SysDown           ] = 0;
    m_WeightMap [i][ Weights::TaID_Hpt_SysUp         ] = 0;
    m_WeightMap [i][ Weights::TaID_Hpt_SysDown       ] = 0;
    m_WeightMap [i][ Weights::TaElOlr                ] = 0;
    m_WeightMap [i][ Weights::TaElOlr_SysUp          ] = 0;
    m_WeightMap [i][ Weights::TaElOlr_SysDown        ] = 0;
    m_WeightMap [i][ Weights::JtJvt                  ] = 0;
    m_WeightMap [i][ Weights::JtJvt_SysUp            ] = 0;
    m_WeightMap [i][ Weights::JtJvt_SysDown          ] = 0;
    m_WeightMap [i][ Weights::BtagSF                 ] = 0;
    m_WeightMap [i][ Weights::BtagSF_Beff_SysUp      ] = 0;
    m_WeightMap [i][ Weights::BtagSF_Beff_SysDown    ] = 0;
    m_WeightMap [i][ Weights::BtagSF_Ceff_SysUp      ] = 0;
    m_WeightMap [i][ Weights::BtagSF_Ceff_SysDown    ] = 0;
    m_WeightMap [i][ Weights::BtagSF_Leff_SysUp      ] = 0;
    m_WeightMap [i][ Weights::BtagSF_Leff_SysDown    ] = 0;
    m_WeightMap [i][ Weights::BtagSF_ExtCeff_SysUp   ] = 0;
    m_WeightMap [i][ Weights::BtagSF_ExtCeff_SysDown ] = 0;
    m_WeightMap [i][ Weights::BtagSF_ExtEff_SysUp    ] = 0;
    m_WeightMap [i][ Weights::BtagSF_ExtEff_SysDown  ] = 0;
    
    /* Weights with B-jet veto */
    m_WeightBJMap [i][ Weights::MC                     ] = 0;
    m_WeightBJMap [i][ Weights::PU                     ] = 0;
    m_WeightBJMap [i][ Weights::PU_SysUp               ] = 0;
    m_WeightBJMap [i][ Weights::PU_SysDown             ] = 0;
    m_WeightBJMap [i][ Weights::ElReco                 ] = 0;
    m_WeightBJMap [i][ Weights::ElReco_SysUp           ] = 0;
    m_WeightBJMap [i][ Weights::ElReco_SysDown         ] = 0;
    m_WeightBJMap [i][ Weights::ElID                   ] = 0;
    m_WeightBJMap [i][ Weights::ElID_SysUp             ] = 0;
    m_WeightBJMap [i][ Weights::ElID_SysDown           ] = 0;
    m_WeightBJMap [i][ Weights::ElIso                  ] = 0;
    m_WeightBJMap [i][ Weights::ElIso_SysUp            ] = 0;
    m_WeightBJMap [i][ Weights::ElIso_SysDown          ] = 0;
    m_WeightBJMap [i][ Weights::ElTrig                 ] = 0;
    m_WeightBJMap [i][ Weights::ElTrig_SysUp           ] = 0;
    m_WeightBJMap [i][ Weights::ElTrig_SysDown         ] = 0;
    m_WeightBJMap [i][ Weights::ElL1Calo               ] = 0;
    m_WeightBJMap [i][ Weights::MuReco                 ] = 0;
    m_WeightBJMap [i][ Weights::MuReco_StatUp          ] = 0;
    m_WeightBJMap [i][ Weights::MuReco_StatDown        ] = 0;
    m_WeightBJMap [i][ Weights::MuReco_SysUp           ] = 0;
    m_WeightBJMap [i][ Weights::MuReco_SysDown         ] = 0;
    m_WeightBJMap [i][ Weights::MuIso                  ] = 0;
    m_WeightBJMap [i][ Weights::MuIso_StatUp           ] = 0;
    m_WeightBJMap [i][ Weights::MuIso_StatDown         ] = 0;
    m_WeightBJMap [i][ Weights::MuIso_SysUp            ] = 0;
    m_WeightBJMap [i][ Weights::MuIso_SysDown          ] = 0;
    m_WeightBJMap [i][ Weights::MuTrig                 ] = 0;
    m_WeightBJMap [i][ Weights::MuTrig_StatUp          ] = 0;
    m_WeightBJMap [i][ Weights::MuTrig_StatDown        ] = 0;
    m_WeightBJMap [i][ Weights::MuTrig_SysUp           ] = 0;
    m_WeightBJMap [i][ Weights::MuTrig_SysDown         ] = 0;
    m_WeightBJMap [i][ Weights::MuTTVA                 ] = 0;
    m_WeightBJMap [i][ Weights::MuTTVA_StatUp          ] = 0;
    m_WeightBJMap [i][ Weights::MuTTVA_StatDown        ] = 0;
    m_WeightBJMap [i][ Weights::MuTTVA_SysUp           ] = 0;
    m_WeightBJMap [i][ Weights::MuTTVA_SysDown         ] = 0;
    m_WeightBJMap [i][ Weights::TaReco                 ] = 0;
    m_WeightBJMap [i][ Weights::TaReco_SysUp           ] = 0;
    m_WeightBJMap [i][ Weights::TaReco_SysDown         ] = 0;
    m_WeightBJMap [i][ Weights::TaReco_Hpt_SysUp       ] = 0;
    m_WeightBJMap [i][ Weights::TaReco_Hpt_SysDown     ] = 0;
    m_WeightBJMap [i][ Weights::TaID                   ] = 0;
    m_WeightBJMap [i][ Weights::TaID_SysUp             ] = 0;
    m_WeightBJMap [i][ Weights::TaID_SysDown           ] = 0;
    m_WeightBJMap [i][ Weights::TaID_Hpt_SysUp         ] = 0;
    m_WeightBJMap [i][ Weights::TaID_Hpt_SysDown       ] = 0;
    m_WeightBJMap [i][ Weights::TaElOlr                ] = 0;
    m_WeightBJMap [i][ Weights::TaElOlr_SysUp          ] = 0;
    m_WeightBJMap [i][ Weights::TaElOlr_SysDown        ] = 0;
    m_WeightBJMap [i][ Weights::JtJvt                  ] = 0;
    m_WeightBJMap [i][ Weights::JtJvt_SysUp            ] = 0;
    m_WeightBJMap [i][ Weights::JtJvt_SysDown          ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF                 ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_Beff_SysUp      ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_Beff_SysDown    ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_Ceff_SysUp      ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_Ceff_SysDown    ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_Leff_SysUp      ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_Leff_SysDown    ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_ExtCeff_SysUp   ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_ExtCeff_SysDown ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_ExtEff_SysUp    ] = 0;
    m_WeightBJMap [i][ Weights::BtagSF_ExtEff_SysDown  ] = 0;
  }
  
  if( m_verbose ) Info( "InitializeWeightsMaps()", "Weights Maps Initialized!" );

}

void HighMassLFV :: UpdateEvtFlow(int sysVar, int cutLevel, int valToAdd, double weight){

  if( m_EvtFlowMap[sysVar].find(cutLevel) == m_EvtFlowMap[sysVar].end() ){
    Info( "UpdateEvtFlow()" , "Requested Cut Level %i is not in the Event Flow map for variation %i", 
	  cutLevel, sysVar );
    return;
  }
  m_EvtFlowMap[sysVar][cutLevel] += valToAdd*weight;
  
}

void HighMassLFV :: UpdateChannelFlow(int sysVar, int cutLevel, int valToAdd, double weight){

  if( m_Chan==Channel::EMU )
    UpdateEMUFlow(sysVar, cutLevel, valToAdd, weight);
  else if( m_Chan==Channel::ETAU )
    UpdateETAUFlow(sysVar, cutLevel, valToAdd, weight);
  else if( m_Chan==Channel::MUTAU )
    UpdateMUTAUFlow(sysVar, cutLevel, valToAdd, weight);
  
}

void HighMassLFV :: UpdateEMUFlow(int sysVar, int cutLevel, int valToAdd, double weight){
  
  if( m_EMUFlowMap[sysVar].find(cutLevel) == m_EMUFlowMap[sysVar].end() ){
    Info( "UpdateEMUFlow()" , "Requested Cut Level %i is not in the EMU Flow map for variation %i",
          cutLevel, sysVar );
    return;
  }
  m_EMUFlowMap[sysVar][cutLevel] += valToAdd*weight;
  
}

void HighMassLFV :: UpdateETAUFlow(int sysVar, int cutLevel, int valToAdd, double weight){

  if( m_ETAUFlowMap[sysVar].find(cutLevel) == m_ETAUFlowMap[sysVar].end() ){
    Info( "UpdateEMUFlow()" , "Requested Cut Level %i is not in the ETAU Flow map for variation %i",
          cutLevel, sysVar );
    return;
  }
  m_ETAUFlowMap[sysVar][cutLevel] += valToAdd*weight;

}

void HighMassLFV :: UpdateMUTAUFlow(int sysVar, int cutLevel, int valToAdd, double weight){

  if( m_MUTAUFlowMap[sysVar].find(cutLevel) == m_MUTAUFlowMap[sysVar].end() ){
    Info( "UpdateEMUFlow()" , "Requested Cut Level %i is not in the MUTAU Flow map for variation %i",
          cutLevel, sysVar );
    return;
  }
  m_MUTAUFlowMap[sysVar][cutLevel] += valToAdd*weight;

}

void HighMassLFV :: UpdateMuFlow(int sysVar, int cutLevel, int valToAdd, double weight){
  
  if( m_MuFlowMap[sysVar].find(cutLevel) == m_MuFlowMap[sysVar].end() ){
    Info( "UpdateEvtFlow()" , "Requested Cut Level %i is not in the Muon Flow map for variation %i", 
	  cutLevel, sysVar );
    return;
  }
  m_MuFlowMap[sysVar][cutLevel] += valToAdd*weight;
  
}

void HighMassLFV :: UpdateElFlow(int sysVar, int cutLevel, int valToAdd, double weight){
  
  if( m_ElFlowMap[sysVar].find(cutLevel) == m_ElFlowMap[sysVar].end() ){
    Info( "UpdateElFlow()" , "Requested Cut Level %i is not in the Electron Flow map for variation %i",
	  cutLevel, sysVar );
    return;
  }
  m_ElFlowMap[sysVar][cutLevel] += valToAdd*weight;
  
}

void HighMassLFV :: UpdateTauFlow(int sysVar, int cutLevel, int valToAdd, double weight){
  
  if( m_TauFlowMap[sysVar].find(cutLevel) == m_TauFlowMap[sysVar].end() ){
    Info( "UpdateTauFlow()" , "Requested Cut Level %i is not in the Tau Flow map for variation %i",
          cutLevel, sysVar );
    return;
  }
  m_TauFlowMap[sysVar][cutLevel] += valToAdd*weight;
  
}

void HighMassLFV :: UpdateJetFlow(int sysVar, int cutLevel, int valToAdd, double weight){

  if( m_JtFlowMap[sysVar].find(cutLevel) == m_JtFlowMap[sysVar].end() ){
    Info( "UpdateJetFlow()" , "Requested Cut Level %i is not in the Jet Flow map for variation %i!", 
	  cutLevel, sysVar );
    return;
  }
  m_JtFlowMap[sysVar][cutLevel] += valToAdd*weight;

}

void HighMassLFV :: UpdatePhFlow(int sysVar, int cutLevel, int valToAdd, double weight){
  
  if( m_PhFlowMap[sysVar].find(cutLevel) == m_PhFlowMap[sysVar].end() ){
    Info( "UpdatePhFlow()" , "Requested Cut Level %i is not in the Photon Flow map for variation %i!",
          cutLevel, sysVar );
    return;
  }
  m_PhFlowMap[sysVar][cutLevel] += valToAdd*weight;
  
}

void HighMassLFV :: UpdateWeight(int channel, int cutLevel, int valToAdd, double weight){
  
  if( m_WeightMap[channel].find(cutLevel) == m_WeightMap[channel].end() ){
    Info( "UpdateWeight()" , "Requested Cut Level %i is not in the Weight map for channel %i", 
	  cutLevel, channel );
    return;
  }
  m_WeightMap[channel][cutLevel] += valToAdd*weight;
  
}

void HighMassLFV :: UpdateWeightBJ(int channel, int cutLevel, int valToAdd, double weight){

  if( m_WeightBJMap[channel].find(cutLevel) == m_WeightBJMap[channel].end() ){
    Info( "UpdateWeightBJ()" , "Requested Cut Level %i is not in the WeightBJ map for channel %i",
	  cutLevel, channel );
    return;
  }
  m_WeightBJMap[channel][cutLevel] += valToAdd*weight;

}

void HighMassLFV :: FillCutFlowHists(int sysVar){

  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Start     , m_EvtFlowMap[ sysVar ][ EvtFlow::Start     ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::EvtClean  , m_EvtFlowMap[ sysVar ][ EvtFlow::EvtClean  ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Vertex    , m_EvtFlowMap[ sysVar ][ EvtFlow::Vertex    ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Trigger   , m_EvtFlowMap[ sysVar ][ EvtFlow::Trigger   ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BadMuon   , m_EvtFlowMap[ sysVar ][ EvtFlow::BadMuon   ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BadJet    , m_EvtFlowMap[ sysVar ][ EvtFlow::BadJet    ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Leptons   , m_EvtFlowMap[ sysVar ][ EvtFlow::Leptons   ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::ThirdLepV , m_EMUFlowMap[ sysVar ][ EvtFlow::ThirdLepV ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::TrigMatch , m_EMUFlowMap[ sysVar ][ EvtFlow::TrigMatch ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::OS_Pair   , m_EMUFlowMap[ sysVar ][ EvtFlow::OS_Pair   ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::DeltaPhi  , m_EMUFlowMap[ sysVar ][ EvtFlow::DeltaPhi  ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BjetVeto  , m_EMUFlowMap[ sysVar ][ EvtFlow::BjetVeto  ] );
  m_EMU_EvtFlow[sysVar]->SetBinContent( EvtFlow::MET       , m_EMUFlowMap[ sysVar ][ EvtFlow::MET       ] );

  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Start     , m_EvtFlowName[ EvtFlow::Start     ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::EvtClean  , m_EvtFlowName[ EvtFlow::EvtClean  ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Vertex    , m_EvtFlowName[ EvtFlow::Vertex    ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Trigger   , m_EvtFlowName[ EvtFlow::Trigger   ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BadMuon   , m_EvtFlowName[ EvtFlow::BadMuon   ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BadJet    , m_EvtFlowName[ EvtFlow::BadJet    ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Leptons   , m_EvtFlowName[ EvtFlow::Leptons   ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::ThirdLepV , m_EMUFlowName[ EvtFlow::ThirdLepV ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::TrigMatch , m_EMUFlowName[ EvtFlow::TrigMatch ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::OS_Pair   , m_EMUFlowName[ EvtFlow::OS_Pair   ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::DeltaPhi  , m_EMUFlowName[ EvtFlow::DeltaPhi  ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BjetVeto  , m_EMUFlowName[ EvtFlow::BjetVeto  ].c_str() );
  m_EMU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::MET       , m_EMUFlowName[ EvtFlow::MET       ].c_str() );

  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Start     , m_EvtFlowMap [ sysVar ][ EvtFlow::Start     ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::EvtClean  , m_EvtFlowMap [ sysVar ][ EvtFlow::EvtClean  ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Vertex    , m_EvtFlowMap [ sysVar ][ EvtFlow::Vertex    ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Trigger   , m_EvtFlowMap [ sysVar ][ EvtFlow::Trigger   ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BadMuon   , m_EvtFlowMap [ sysVar ][ EvtFlow::BadMuon   ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BadJet    , m_EvtFlowMap [ sysVar ][ EvtFlow::BadJet    ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Leptons   , m_EvtFlowMap [ sysVar ][ EvtFlow::Leptons   ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::ThirdLepV , m_ETAUFlowMap[ sysVar ][ EvtFlow::ThirdLepV ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::TrigMatch , m_ETAUFlowMap[ sysVar ][ EvtFlow::TrigMatch ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::OS_Pair   , m_ETAUFlowMap[ sysVar ][ EvtFlow::OS_Pair   ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::DeltaPhi  , m_ETAUFlowMap[ sysVar ][ EvtFlow::DeltaPhi  ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BjetVeto  , m_ETAUFlowMap[ sysVar ][ EvtFlow::BjetVeto  ] );
  m_ETAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::MET       , m_ETAUFlowMap[ sysVar ][ EvtFlow::MET       ] );

  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Start     , m_EvtFlowName [ EvtFlow::Start     ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::EvtClean  , m_EvtFlowName [ EvtFlow::EvtClean  ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Vertex    , m_EvtFlowName [ EvtFlow::Vertex    ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Trigger   , m_EvtFlowName [ EvtFlow::Trigger   ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BadMuon   , m_EvtFlowName [ EvtFlow::BadMuon   ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BadJet    , m_EvtFlowName [ EvtFlow::BadJet    ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Leptons   , m_EvtFlowName [ EvtFlow::Leptons   ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::ThirdLepV , m_ETAUFlowName[ EvtFlow::ThirdLepV ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::TrigMatch , m_ETAUFlowName[ EvtFlow::TrigMatch ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::OS_Pair   , m_ETAUFlowName[ EvtFlow::OS_Pair   ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::DeltaPhi  , m_ETAUFlowName[ EvtFlow::DeltaPhi  ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BjetVeto  , m_ETAUFlowName[ EvtFlow::BjetVeto  ].c_str() );
  m_ETAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::MET       , m_ETAUFlowName[ EvtFlow::MET       ].c_str() );

  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Start     , m_EvtFlowMap  [ sysVar ][ EvtFlow::Start     ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::EvtClean  , m_EvtFlowMap  [ sysVar ][ EvtFlow::EvtClean  ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Vertex    , m_EvtFlowMap  [ sysVar ][ EvtFlow::Vertex    ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Trigger   , m_EvtFlowMap  [ sysVar ][ EvtFlow::Trigger   ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BadMuon   , m_EvtFlowMap  [ sysVar ][ EvtFlow::BadMuon   ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BadJet    , m_EvtFlowMap  [ sysVar ][ EvtFlow::BadJet    ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::Leptons   , m_EvtFlowMap  [ sysVar ][ EvtFlow::Leptons   ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::ThirdLepV , m_MUTAUFlowMap[ sysVar ][ EvtFlow::ThirdLepV ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::TrigMatch , m_MUTAUFlowMap[ sysVar ][ EvtFlow::TrigMatch ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::OS_Pair   , m_MUTAUFlowMap[ sysVar ][ EvtFlow::OS_Pair   ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::DeltaPhi  , m_MUTAUFlowMap[ sysVar ][ EvtFlow::DeltaPhi  ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::BjetVeto  , m_MUTAUFlowMap[ sysVar ][ EvtFlow::BjetVeto  ] );
  m_MUTAU_EvtFlow[sysVar]->SetBinContent( EvtFlow::MET       , m_MUTAUFlowMap[ sysVar ][ EvtFlow::MET       ] );

  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Start     , m_EvtFlowName  [ EvtFlow::Start     ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::EvtClean  , m_EvtFlowName  [ EvtFlow::EvtClean  ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Vertex    , m_EvtFlowName  [ EvtFlow::Vertex    ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Trigger   , m_EvtFlowName  [ EvtFlow::Trigger   ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BadMuon   , m_EvtFlowName  [ EvtFlow::BadMuon   ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BadJet    , m_EvtFlowName  [ EvtFlow::BadJet    ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::Leptons   , m_EvtFlowName  [ EvtFlow::Leptons   ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::ThirdLepV , m_MUTAUFlowName[ EvtFlow::ThirdLepV ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::TrigMatch , m_MUTAUFlowName[ EvtFlow::TrigMatch ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::OS_Pair   , m_MUTAUFlowName[ EvtFlow::OS_Pair   ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::DeltaPhi  , m_MUTAUFlowName[ EvtFlow::DeltaPhi  ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::BjetVeto  , m_MUTAUFlowName[ EvtFlow::BjetVeto  ].c_str() );
  m_MUTAU_EvtFlow[sysVar]->GetXaxis()->SetBinLabel( EvtFlow::MET       , m_MUTAUFlowName[ EvtFlow::MET       ].c_str() );
  
  m_MuFlow[sysVar]->SetBinContent( MuFlow::Start     , m_MuFlowMap[ sysVar ][ MuFlow::Start     ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::EvtClean  , m_MuFlowMap[ sysVar ][ MuFlow::EvtClean  ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::Vertex    , m_MuFlowMap[ sysVar ][ MuFlow::Vertex    ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::Trigger   , m_MuFlowMap[ sysVar ][ MuFlow::Trigger   ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::TrigMatch , m_MuFlowMap[ sysVar ][ MuFlow::TrigMatch ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::Pt        , m_MuFlowMap[ sysVar ][ MuFlow::Pt        ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::Eta_ID_Q  , m_MuFlowMap[ sysVar ][ MuFlow::Eta_ID_Q  ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::HighPtCut , m_MuFlowMap[ sysVar ][ MuFlow::HighPtCut ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::D0Sign    , m_MuFlowMap[ sysVar ][ MuFlow::D0Sign    ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::DeltaZ0   , m_MuFlowMap[ sysVar ][ MuFlow::DeltaZ0   ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::Overlaps  , m_MuFlowMap[ sysVar ][ MuFlow::Overlaps  ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::Isolation , m_MuFlowMap[ sysVar ][ MuFlow::Isolation ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::TightMu   , m_MuFlowMap[ sysVar ][ MuFlow::TightMu   ] );
  m_MuFlow[sysVar]->SetBinContent( MuFlow::LooseMu   , m_MuFlowMap[ sysVar ][ MuFlow::LooseMu   ] );

  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::Start     , m_MuFlowName[ MuFlow::Start     ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::EvtClean  , m_MuFlowName[ MuFlow::EvtClean  ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::Vertex    , m_MuFlowName[ MuFlow::Vertex    ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::Trigger   , m_MuFlowName[ MuFlow::Trigger   ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::TrigMatch , m_MuFlowName[ MuFlow::TrigMatch ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::Pt        , m_MuFlowName[ MuFlow::Pt        ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::Eta_ID_Q  , m_MuFlowName[ MuFlow::Eta_ID_Q  ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::HighPtCut , m_MuFlowName[ MuFlow::HighPtCut ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::D0Sign    , m_MuFlowName[ MuFlow::D0Sign    ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::DeltaZ0   , m_MuFlowName[ MuFlow::DeltaZ0   ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::Overlaps  , m_MuFlowName[ MuFlow::Overlaps  ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::Isolation , m_MuFlowName[ MuFlow::Isolation ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::TightMu   , m_MuFlowName[ MuFlow::TightMu   ].c_str() );
  m_MuFlow[sysVar]->GetXaxis()->SetBinLabel( MuFlow::LooseMu   , m_MuFlowName[ MuFlow::LooseMu   ].c_str() );

  m_ElFlow[sysVar]->SetBinContent( ElFlow::Start     , m_ElFlowMap[ sysVar ][ ElFlow::Start     ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::EvtClean  , m_ElFlowMap[ sysVar ][ ElFlow::EvtClean  ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::Vertex    , m_ElFlowMap[ sysVar ][ ElFlow::Vertex    ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::Trigger   , m_ElFlowMap[ sysVar ][ ElFlow::Trigger   ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::TrigMatch , m_ElFlowMap[ sysVar ][ ElFlow::TrigMatch ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::Author    , m_ElFlowMap[ sysVar ][ ElFlow::Author    ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::Pt        , m_ElFlowMap[ sysVar ][ ElFlow::Pt        ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::Eta       , m_ElFlowMap[ sysVar ][ ElFlow::Eta       ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::ObjectQ   , m_ElFlowMap[ sysVar ][ ElFlow::ObjectQ   ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::ElecID    , m_ElFlowMap[ sysVar ][ ElFlow::ElecID    ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::D0Sign    , m_ElFlowMap[ sysVar ][ ElFlow::D0Sign    ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::DeltaZ0   , m_ElFlowMap[ sysVar ][ ElFlow::DeltaZ0   ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::Overlaps  , m_ElFlowMap[ sysVar ][ ElFlow::Overlaps  ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::MuElOve   , m_ElFlowMap[ sysVar ][ ElFlow::MuElOve   ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::Isolation , m_ElFlowMap[ sysVar ][ ElFlow::Isolation ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::TightEl   , m_ElFlowMap[ sysVar ][ ElFlow::TightEl   ] );
  m_ElFlow[sysVar]->SetBinContent( ElFlow::LooseEl   , m_ElFlowMap[ sysVar ][ ElFlow::LooseEl   ] );

  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Start     , m_ElFlowName[ ElFlow::Start     ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::EvtClean  , m_ElFlowName[ ElFlow::EvtClean  ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Vertex    , m_ElFlowName[ ElFlow::Vertex    ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Trigger   , m_ElFlowName[ ElFlow::Trigger   ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::TrigMatch , m_ElFlowName[ ElFlow::TrigMatch ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Author    , m_ElFlowName[ ElFlow::Author    ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Pt        , m_ElFlowName[ ElFlow::Pt        ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Eta       , m_ElFlowName[ ElFlow::Eta       ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::ObjectQ   , m_ElFlowName[ ElFlow::ObjectQ   ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::ElecID    , m_ElFlowName[ ElFlow::ElecID    ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::D0Sign    , m_ElFlowName[ ElFlow::D0Sign    ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::DeltaZ0   , m_ElFlowName[ ElFlow::DeltaZ0   ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Overlaps  , m_ElFlowName[ ElFlow::Overlaps  ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::MuElOve   , m_ElFlowName[ ElFlow::MuElOve   ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::Isolation , m_ElFlowName[ ElFlow::Isolation ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::TightEl   , m_ElFlowName[ ElFlow::TightEl   ].c_str() );
  m_ElFlow[sysVar]->GetXaxis()->SetBinLabel( ElFlow::LooseEl   , m_ElFlowName[ ElFlow::LooseEl   ].c_str() );

  m_TaFlow[sysVar]->SetBinContent( TauFlow::Start     , m_TauFlowMap[ sysVar ][ TauFlow::Start     ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::EvtClean  , m_TauFlowMap[ sysVar ][ TauFlow::EvtClean  ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::Vertex    , m_TauFlowMap[ sysVar ][ TauFlow::Vertex    ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::Trigger   , m_TauFlowMap[ sysVar ][ TauFlow::Trigger   ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::TrigMatch , m_TauFlowMap[ sysVar ][ TauFlow::TrigMatch ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::Pt        , m_TauFlowMap[ sysVar ][ TauFlow::Pt        ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::Eta       , m_TauFlowMap[ sysVar ][ TauFlow::Eta       ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::Charge    , m_TauFlowMap[ sysVar ][ TauFlow::Charge    ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::nTracks   , m_TauFlowMap[ sysVar ][ TauFlow::nTracks   ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::BDTscore  , m_TauFlowMap[ sysVar ][ TauFlow::BDTscore  ] );  
  m_TaFlow[sysVar]->SetBinContent( TauFlow::JetIDWP   , m_TauFlowMap[ sysVar ][ TauFlow::JetIDWP   ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::ElOR      , m_TauFlowMap[ sysVar ][ TauFlow::ElOR      ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::Overlaps  , m_TauFlowMap[ sysVar ][ TauFlow::Overlaps  ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::TaMuOve   , m_TauFlowMap[ sysVar ][ TauFlow::TaMuOve   ] );
  m_TaFlow[sysVar]->SetBinContent( TauFlow::TaElOve   , m_TauFlowMap[ sysVar ][ TauFlow::TaElOve   ] );
  
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::Start     , m_TauFlowName [ TauFlow::Start     ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::EvtClean  , m_TauFlowName [ TauFlow::EvtClean  ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::Vertex    , m_TauFlowName [ TauFlow::Vertex    ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::Trigger   , m_TauFlowName [ TauFlow::Trigger   ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::TrigMatch , m_TauFlowName [ TauFlow::TrigMatch ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::Pt        , m_TauFlowName [ TauFlow::Pt        ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::Eta       , m_TauFlowName [ TauFlow::Eta       ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::Charge    , m_TauFlowName [ TauFlow::Charge    ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::nTracks   , m_TauFlowName [ TauFlow::nTracks   ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::BDTscore  , m_TauFlowName [ TauFlow::BDTscore  ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::JetIDWP   , m_TauFlowName [ TauFlow::JetIDWP   ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::ElOR      , m_TauFlowName [ TauFlow::ElOR      ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::Overlaps  , m_TauFlowName [ TauFlow::Overlaps  ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::TaMuOve   , m_TauFlowName [ TauFlow::TaMuOve   ].c_str() );
  m_TaFlow[sysVar]->GetXaxis()->SetBinLabel( TauFlow::TaElOve   , m_TauFlowName [ TauFlow::TaElOve   ].c_str() );
				   
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Start         , m_JtFlowMap[ sysVar ][ JtFlow::Start         ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::EvtClean      , m_JtFlowMap[ sysVar ][ JtFlow::EvtClean      ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Vertex        , m_JtFlowMap[ sysVar ][ JtFlow::Vertex        ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Trigger       , m_JtFlowMap[ sysVar ][ JtFlow::Trigger       ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Pt            , m_JtFlowMap[ sysVar ][ JtFlow::Pt            ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Eta           , m_JtFlowMap[ sysVar ][ JtFlow::Eta           ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Overlaps      , m_JtFlowMap[ sysVar ][ JtFlow::Overlaps      ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::JetElOverlap  , m_JtFlowMap[ sysVar ][ JtFlow::JetElOverlap  ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::JetTauOverlap , m_JtFlowMap[ sysVar ][ JtFlow::JetTauOverlap ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::JetMuOverlap  , m_JtFlowMap[ sysVar ][ JtFlow::JetMuOverlap  ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::JVT           , m_JtFlowMap[ sysVar ][ JtFlow::JVT           ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Clean         , m_JtFlowMap[ sysVar ][ JtFlow::Clean         ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::BjetVeto      , m_JtFlowMap[ sysVar ][ JtFlow::BjetVeto      ] );
  m_JetFlow[sysVar]->SetBinContent( JtFlow::Bjet          , m_JtFlowMap[ sysVar ][ JtFlow::Bjet          ] );

  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Start         , m_JtFlowName[ JtFlow::Start         ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::EvtClean      , m_JtFlowName[ JtFlow::EvtClean      ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Vertex        , m_JtFlowName[ JtFlow::Vertex        ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Trigger       , m_JtFlowName[ JtFlow::Trigger       ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Pt            , m_JtFlowName[ JtFlow::Pt            ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Eta           , m_JtFlowName[ JtFlow::Eta           ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Overlaps      , m_JtFlowName[ JtFlow::Overlaps      ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::JetElOverlap  , m_JtFlowName[ JtFlow::JetElOverlap  ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::JetTauOverlap , m_JtFlowName[ JtFlow::JetTauOverlap ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::JetMuOverlap  , m_JtFlowName[ JtFlow::JetMuOverlap  ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::JVT           , m_JtFlowName[ JtFlow::JVT           ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Clean         , m_JtFlowName[ JtFlow::Clean         ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::BjetVeto      , m_JtFlowName[ JtFlow::BjetVeto      ].c_str() );
  m_JetFlow[sysVar]->GetXaxis()->SetBinLabel( JtFlow::Bjet          , m_JtFlowName[ JtFlow::Bjet          ].c_str() );
  
  m_PhFlow[sysVar]->SetBinContent( PhFlow::Start    , m_PhFlowMap[ sysVar ][ PhFlow::Start    ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::EvtClean , m_PhFlowMap[ sysVar ][ PhFlow::EvtClean ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::Vertex   , m_PhFlowMap[ sysVar ][ PhFlow::Vertex   ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::Trigger  , m_PhFlowMap[ sysVar ][ PhFlow::Trigger  ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::Pt       , m_PhFlowMap[ sysVar ][ PhFlow::Pt       ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::Eta      , m_PhFlowMap[ sysVar ][ PhFlow::Eta      ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::Author   , m_PhFlowMap[ sysVar ][ PhFlow::Author   ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::ObjQual  , m_PhFlowMap[ sysVar ][ PhFlow::ObjQual  ] );
  m_PhFlow[sysVar]->SetBinContent( PhFlow::Clean    , m_PhFlowMap[ sysVar ][ PhFlow::Clean    ] );
  
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::Start    , m_PhFlowName[ PhFlow::Start    ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::EvtClean , m_PhFlowName[ PhFlow::EvtClean ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::Vertex   , m_PhFlowName[ PhFlow::Vertex   ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::Trigger  , m_PhFlowName[ PhFlow::Trigger  ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::Pt       , m_PhFlowName[ PhFlow::Pt       ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::Eta      , m_PhFlowName[ PhFlow::Eta      ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::Author   , m_PhFlowName[ PhFlow::Author   ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::ObjQual  , m_PhFlowName[ PhFlow::ObjQual  ].c_str() );
  m_PhFlow[sysVar]->GetXaxis()->SetBinLabel( PhFlow::Clean    , m_PhFlowName[ PhFlow::Clean    ].c_str() );

  Info( "FillCutFlowHists()", "CutFlow Information filled in histograms" );

}

void HighMassLFV :: FillWeightsHists(int channel){
  
  m_Weights[channel]->SetBinContent( Weights::MC                     , m_WeightMap[channel] [ Weights::MC                     ] );
  m_Weights[channel]->SetBinContent( Weights::PU                     , m_WeightMap[channel] [ Weights::PU                     ] );
  m_Weights[channel]->SetBinContent( Weights::PU_SysUp               , m_WeightMap[channel] [ Weights::PU_SysUp               ] );
  m_Weights[channel]->SetBinContent( Weights::PU_SysDown             , m_WeightMap[channel] [ Weights::PU_SysDown             ] );
  m_Weights[channel]->SetBinContent( Weights::ElReco                 , m_WeightMap[channel] [ Weights::ElReco                 ] );
  m_Weights[channel]->SetBinContent( Weights::ElReco_SysUp           , m_WeightMap[channel] [ Weights::ElReco_SysUp           ] );
  m_Weights[channel]->SetBinContent( Weights::ElReco_SysDown         , m_WeightMap[channel] [ Weights::ElReco_SysDown         ] );
  m_Weights[channel]->SetBinContent( Weights::ElID                   , m_WeightMap[channel] [ Weights::ElID                   ] );
  m_Weights[channel]->SetBinContent( Weights::ElID_SysUp             , m_WeightMap[channel] [ Weights::ElID_SysUp             ] );
  m_Weights[channel]->SetBinContent( Weights::ElID_SysDown           , m_WeightMap[channel] [ Weights::ElID_SysDown           ] );
  m_Weights[channel]->SetBinContent( Weights::ElIso                  , m_WeightMap[channel] [ Weights::ElIso                  ] );
  m_Weights[channel]->SetBinContent( Weights::ElIso_SysUp            , m_WeightMap[channel] [ Weights::ElIso_SysUp            ] );
  m_Weights[channel]->SetBinContent( Weights::ElIso_SysDown          , m_WeightMap[channel] [ Weights::ElIso_SysDown          ] );
  m_Weights[channel]->SetBinContent( Weights::ElTrig                 , m_WeightMap[channel] [ Weights::ElTrig                 ] );
  m_Weights[channel]->SetBinContent( Weights::ElTrig_SysUp           , m_WeightMap[channel] [ Weights::ElTrig_SysUp           ] );
  m_Weights[channel]->SetBinContent( Weights::ElTrig_SysDown         , m_WeightMap[channel] [ Weights::ElTrig_SysDown         ] );
  m_Weights[channel]->SetBinContent( Weights::ElL1Calo               , m_WeightMap[channel] [ Weights::ElL1Calo               ] );
  m_Weights[channel]->SetBinContent( Weights::MuReco                 , m_WeightMap[channel] [ Weights::MuReco                 ] );
  m_Weights[channel]->SetBinContent( Weights::MuReco_StatUp          , m_WeightMap[channel] [ Weights::MuReco_StatUp          ] );
  m_Weights[channel]->SetBinContent( Weights::MuReco_StatDown        , m_WeightMap[channel] [ Weights::MuReco_StatDown        ] );
  m_Weights[channel]->SetBinContent( Weights::MuReco_SysUp           , m_WeightMap[channel] [ Weights::MuReco_SysUp           ] );
  m_Weights[channel]->SetBinContent( Weights::MuReco_SysDown         , m_WeightMap[channel] [ Weights::MuReco_SysDown         ] );
  m_Weights[channel]->SetBinContent( Weights::MuIso                  , m_WeightMap[channel] [ Weights::MuIso                  ] );
  m_Weights[channel]->SetBinContent( Weights::MuIso_StatUp           , m_WeightMap[channel] [ Weights::MuIso_StatUp           ] );
  m_Weights[channel]->SetBinContent( Weights::MuIso_StatDown         , m_WeightMap[channel] [ Weights::MuIso_StatDown         ] );
  m_Weights[channel]->SetBinContent( Weights::MuIso_SysUp            , m_WeightMap[channel] [ Weights::MuIso_SysUp            ] );
  m_Weights[channel]->SetBinContent( Weights::MuIso_SysDown          , m_WeightMap[channel] [ Weights::MuIso_SysDown          ] );
  m_Weights[channel]->SetBinContent( Weights::MuTrig                 , m_WeightMap[channel] [ Weights::MuTrig                 ] );
  m_Weights[channel]->SetBinContent( Weights::MuTrig_StatUp          , m_WeightMap[channel] [ Weights::MuTrig_StatUp          ] );
  m_Weights[channel]->SetBinContent( Weights::MuTrig_StatDown        , m_WeightMap[channel] [ Weights::MuTrig_StatDown        ] );
  m_Weights[channel]->SetBinContent( Weights::MuTrig_SysUp           , m_WeightMap[channel] [ Weights::MuTrig_SysUp           ] );
  m_Weights[channel]->SetBinContent( Weights::MuTrig_SysDown         , m_WeightMap[channel] [ Weights::MuTrig_SysDown         ] );
  m_Weights[channel]->SetBinContent( Weights::MuTTVA                 , m_WeightMap[channel] [ Weights::MuTTVA                 ] );
  m_Weights[channel]->SetBinContent( Weights::MuTTVA_StatUp          , m_WeightMap[channel] [ Weights::MuTTVA_StatUp          ] );
  m_Weights[channel]->SetBinContent( Weights::MuTTVA_StatDown        , m_WeightMap[channel] [ Weights::MuTTVA_StatDown        ] );
  m_Weights[channel]->SetBinContent( Weights::MuTTVA_SysUp           , m_WeightMap[channel] [ Weights::MuTTVA_SysUp           ] );
  m_Weights[channel]->SetBinContent( Weights::MuTTVA_SysDown         , m_WeightMap[channel] [ Weights::MuTTVA_SysDown         ] );
  m_Weights[channel]->SetBinContent( Weights::TaReco                 , m_WeightMap[channel] [ Weights::TaReco                 ] );
  m_Weights[channel]->SetBinContent( Weights::TaReco_SysUp           , m_WeightMap[channel] [ Weights::TaReco_SysUp           ] );
  m_Weights[channel]->SetBinContent( Weights::TaReco_SysDown         , m_WeightMap[channel] [ Weights::TaReco_SysDown         ] );
  m_Weights[channel]->SetBinContent( Weights::TaReco_Hpt_SysUp       , m_WeightMap[channel] [ Weights::TaReco_Hpt_SysUp       ] );
  m_Weights[channel]->SetBinContent( Weights::TaReco_Hpt_SysDown     , m_WeightMap[channel] [ Weights::TaReco_Hpt_SysDown     ] );
  m_Weights[channel]->SetBinContent( Weights::TaID                   , m_WeightMap[channel] [ Weights::TaID                   ] );
  m_Weights[channel]->SetBinContent( Weights::TaID_SysUp             , m_WeightMap[channel] [ Weights::TaID_SysUp             ] );
  m_Weights[channel]->SetBinContent( Weights::TaID_SysDown           , m_WeightMap[channel] [ Weights::TaID_SysDown           ] );
  m_Weights[channel]->SetBinContent( Weights::TaID_Hpt_SysUp         , m_WeightMap[channel] [ Weights::TaID_Hpt_SysUp         ] );
  m_Weights[channel]->SetBinContent( Weights::TaID_Hpt_SysDown       , m_WeightMap[channel] [ Weights::TaID_Hpt_SysDown       ] );
  m_Weights[channel]->SetBinContent( Weights::TaElOlr                , m_WeightMap[channel] [ Weights::TaElOlr                ] );
  m_Weights[channel]->SetBinContent( Weights::TaElOlr_SysUp          , m_WeightMap[channel] [ Weights::TaElOlr_SysUp          ] );
  m_Weights[channel]->SetBinContent( Weights::TaElOlr_SysDown        , m_WeightMap[channel] [ Weights::TaElOlr_SysDown        ] );
  m_Weights[channel]->SetBinContent( Weights::JtJvt                  , m_WeightMap[channel] [ Weights::JtJvt                  ] );
  m_Weights[channel]->SetBinContent( Weights::JtJvt_SysUp            , m_WeightMap[channel] [ Weights::JtJvt_SysUp            ] );
  m_Weights[channel]->SetBinContent( Weights::JtJvt_SysDown          , m_WeightMap[channel] [ Weights::JtJvt_SysDown          ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF                 , m_WeightMap[channel] [ Weights::BtagSF                 ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_Beff_SysUp      , m_WeightMap[channel] [ Weights::BtagSF_Beff_SysUp      ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_Beff_SysDown    , m_WeightMap[channel] [ Weights::BtagSF_Beff_SysDown    ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_Ceff_SysUp      , m_WeightMap[channel] [ Weights::BtagSF_Ceff_SysUp      ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_Ceff_SysDown    , m_WeightMap[channel] [ Weights::BtagSF_Ceff_SysDown    ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_Leff_SysUp      , m_WeightMap[channel] [ Weights::BtagSF_Leff_SysUp      ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_Leff_SysDown    , m_WeightMap[channel] [ Weights::BtagSF_Leff_SysDown    ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_ExtCeff_SysUp   , m_WeightMap[channel] [ Weights::BtagSF_ExtCeff_SysUp   ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_ExtCeff_SysDown , m_WeightMap[channel] [ Weights::BtagSF_ExtCeff_SysDown ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_ExtEff_SysUp    , m_WeightMap[channel] [ Weights::BtagSF_ExtEff_SysUp    ] );
  m_Weights[channel]->SetBinContent( Weights::BtagSF_ExtEff_SysDown  , m_WeightMap[channel] [ Weights::BtagSF_ExtEff_SysDown  ] );

  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MC                     , m_WeightName [ Weights::MC                     ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::PU                     , m_WeightName [ Weights::PU                     ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::PU_SysUp               , m_WeightName [ Weights::PU_SysUp               ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::PU_SysDown             , m_WeightName [ Weights::PU_SysDown             ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElReco                 , m_WeightName [ Weights::ElReco                 ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElReco_SysUp           , m_WeightName [ Weights::ElReco_SysUp           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElReco_SysDown         , m_WeightName [ Weights::ElReco_SysDown         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElID                   , m_WeightName [ Weights::ElID                   ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElID_SysUp             , m_WeightName [ Weights::ElID_SysUp             ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElID_SysDown           , m_WeightName [ Weights::ElID_SysDown           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElIso                  , m_WeightName [ Weights::ElIso                  ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElIso_SysUp            , m_WeightName [ Weights::ElIso_SysUp            ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElIso_SysDown          , m_WeightName [ Weights::ElIso_SysDown          ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElTrig                 , m_WeightName [ Weights::ElTrig                 ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElTrig_SysUp           , m_WeightName [ Weights::ElTrig_SysUp           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElTrig_SysDown         , m_WeightName [ Weights::ElTrig_SysDown         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::ElL1Calo               , m_WeightName [ Weights::ElL1Calo               ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuReco                 , m_WeightName [ Weights::MuReco                 ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_StatUp          , m_WeightName [ Weights::MuReco_StatUp          ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_StatDown        , m_WeightName [ Weights::MuReco_StatDown        ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_SysUp           , m_WeightName [ Weights::MuReco_SysUp           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_SysDown         , m_WeightName [ Weights::MuReco_SysDown         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuIso                  , m_WeightName [ Weights::MuIso                  ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_StatUp           , m_WeightName [ Weights::MuIso_StatUp           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_StatDown         , m_WeightName [ Weights::MuIso_StatDown         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_SysUp            , m_WeightName [ Weights::MuIso_SysUp            ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_SysDown          , m_WeightName [ Weights::MuIso_SysDown          ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig                 , m_WeightName [ Weights::MuTrig                 ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_StatUp          , m_WeightName [ Weights::MuTrig_StatUp          ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_StatDown        , m_WeightName [ Weights::MuTrig_StatDown        ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_SysUp           , m_WeightName [ Weights::MuTrig_SysUp           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_SysDown         , m_WeightName [ Weights::MuTrig_SysDown         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA                 , m_WeightName [ Weights::MuTTVA                 ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_StatUp          , m_WeightName [ Weights::MuTTVA_StatUp          ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_StatDown        , m_WeightName [ Weights::MuTTVA_StatDown        ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_SysUp           , m_WeightName [ Weights::MuTTVA_SysUp           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_SysDown         , m_WeightName [ Weights::MuTTVA_SysDown         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaReco                 , m_WeightName [ Weights::TaReco                 ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_SysUp           , m_WeightName [ Weights::TaReco_SysUp           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_SysDown         , m_WeightName [ Weights::TaReco_SysDown         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_Hpt_SysUp       , m_WeightName [ Weights::TaReco_Hpt_SysUp       ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_Hpt_SysDown     , m_WeightName [ Weights::TaReco_Hpt_SysDown     ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaID                   , m_WeightName [ Weights::TaID                   ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaID_SysUp             , m_WeightName [ Weights::TaID_SysUp             ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaID_SysDown           , m_WeightName [ Weights::TaID_SysDown           ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaID_Hpt_SysUp         , m_WeightName [ Weights::TaID_Hpt_SysUp         ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaID_Hpt_SysDown       , m_WeightName [ Weights::TaID_Hpt_SysDown       ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaElOlr                , m_WeightName [ Weights::TaElOlr                ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaElOlr_SysUp          , m_WeightName [ Weights::TaElOlr_SysUp          ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::TaElOlr_SysDown        , m_WeightName [ Weights::TaElOlr_SysDown        ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::JtJvt                  , m_WeightName [ Weights::JtJvt                  ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::JtJvt_SysUp            , m_WeightName [ Weights::JtJvt_SysUp            ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::JtJvt_SysDown          , m_WeightName [ Weights::JtJvt_SysDown          ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF                 , m_WeightName [ Weights::BtagSF                 ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Beff_SysUp      , m_WeightName [ Weights::BtagSF_Beff_SysUp      ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Beff_SysDown    , m_WeightName [ Weights::BtagSF_Beff_SysDown    ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Ceff_SysUp      , m_WeightName [ Weights::BtagSF_Ceff_SysUp      ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Ceff_SysDown    , m_WeightName [ Weights::BtagSF_Ceff_SysDown    ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Leff_SysUp      , m_WeightName [ Weights::BtagSF_Leff_SysUp      ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Leff_SysDown    , m_WeightName [ Weights::BtagSF_Leff_SysDown    ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtCeff_SysUp   , m_WeightName [ Weights::BtagSF_ExtCeff_SysUp   ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtCeff_SysDown , m_WeightName [ Weights::BtagSF_ExtCeff_SysDown ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtEff_SysUp    , m_WeightName [ Weights::BtagSF_ExtEff_SysUp    ].c_str() );
  m_Weights[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtEff_SysDown  , m_WeightName [ Weights::BtagSF_ExtEff_SysDown  ].c_str() );

  m_WeightsBJ[channel]->SetBinContent( Weights::MC                     , m_WeightBJMap[channel] [ Weights::MC                     ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::PU                     , m_WeightBJMap[channel] [ Weights::PU                     ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::PU_SysUp               , m_WeightBJMap[channel] [ Weights::PU_SysUp               ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::PU_SysDown             , m_WeightBJMap[channel] [ Weights::PU_SysDown             ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElReco                 , m_WeightBJMap[channel] [ Weights::ElReco                 ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElReco_SysUp           , m_WeightBJMap[channel] [ Weights::ElReco_SysUp           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElReco_SysDown         , m_WeightBJMap[channel] [ Weights::ElReco_SysDown         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElID                   , m_WeightBJMap[channel] [ Weights::ElID                   ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElID_SysUp             , m_WeightBJMap[channel] [ Weights::ElID_SysUp             ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElID_SysDown           , m_WeightBJMap[channel] [ Weights::ElID_SysDown           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElIso                  , m_WeightBJMap[channel] [ Weights::ElIso                  ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElIso_SysUp            , m_WeightBJMap[channel] [ Weights::ElIso_SysUp            ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElIso_SysDown          , m_WeightBJMap[channel] [ Weights::ElIso_SysDown          ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElTrig                 , m_WeightBJMap[channel] [ Weights::ElTrig                 ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElTrig_SysUp           , m_WeightBJMap[channel] [ Weights::ElTrig_SysUp           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElTrig_SysDown         , m_WeightBJMap[channel] [ Weights::ElTrig_SysDown         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::ElL1Calo               , m_WeightBJMap[channel] [ Weights::ElL1Calo               ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuReco                 , m_WeightBJMap[channel] [ Weights::MuReco                 ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuReco_StatUp          , m_WeightBJMap[channel] [ Weights::MuReco_StatUp          ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuReco_StatDown        , m_WeightBJMap[channel] [ Weights::MuReco_StatDown        ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuReco_SysUp           , m_WeightBJMap[channel] [ Weights::MuReco_SysUp           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuReco_SysDown         , m_WeightBJMap[channel] [ Weights::MuReco_SysDown         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuIso                  , m_WeightBJMap[channel] [ Weights::MuIso                  ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuIso_StatUp           , m_WeightBJMap[channel] [ Weights::MuIso_StatUp           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuIso_StatDown         , m_WeightBJMap[channel] [ Weights::MuIso_StatDown         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuIso_SysUp            , m_WeightBJMap[channel] [ Weights::MuIso_SysUp            ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuIso_SysDown          , m_WeightBJMap[channel] [ Weights::MuIso_SysDown          ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTrig                 , m_WeightBJMap[channel] [ Weights::MuTrig                 ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTrig_StatUp          , m_WeightBJMap[channel] [ Weights::MuTrig_StatUp          ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTrig_StatDown        , m_WeightBJMap[channel] [ Weights::MuTrig_StatDown        ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTrig_SysUp           , m_WeightBJMap[channel] [ Weights::MuTrig_SysUp           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTrig_SysDown         , m_WeightBJMap[channel] [ Weights::MuTrig_SysDown         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTTVA                 , m_WeightBJMap[channel] [ Weights::MuTTVA                 ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTTVA_StatUp          , m_WeightBJMap[channel] [ Weights::MuTTVA_StatUp          ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTTVA_StatDown        , m_WeightBJMap[channel] [ Weights::MuTTVA_StatDown        ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTTVA_SysUp           , m_WeightBJMap[channel] [ Weights::MuTTVA_SysUp           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::MuTTVA_SysDown         , m_WeightBJMap[channel] [ Weights::MuTTVA_SysDown         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaReco                 , m_WeightBJMap[channel] [ Weights::TaReco                 ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaReco_SysUp           , m_WeightBJMap[channel] [ Weights::TaReco_SysUp           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaReco_SysDown         , m_WeightBJMap[channel] [ Weights::TaReco_SysDown         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaReco_Hpt_SysUp       , m_WeightBJMap[channel] [ Weights::TaReco_Hpt_SysUp       ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaReco_Hpt_SysDown     , m_WeightBJMap[channel] [ Weights::TaReco_Hpt_SysDown     ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaID                   , m_WeightBJMap[channel] [ Weights::TaID                   ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaID_SysUp             , m_WeightBJMap[channel] [ Weights::TaID_SysUp             ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaID_SysDown           , m_WeightBJMap[channel] [ Weights::TaID_SysDown           ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaID_Hpt_SysUp         , m_WeightBJMap[channel] [ Weights::TaID_Hpt_SysUp         ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaID_Hpt_SysDown       , m_WeightBJMap[channel] [ Weights::TaID_Hpt_SysDown       ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaElOlr                , m_WeightBJMap[channel] [ Weights::TaElOlr                ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaElOlr_SysUp          , m_WeightBJMap[channel] [ Weights::TaElOlr_SysUp          ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::TaElOlr_SysDown        , m_WeightBJMap[channel] [ Weights::TaElOlr_SysDown        ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::JtJvt                  , m_WeightBJMap[channel] [ Weights::JtJvt                  ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::JtJvt_SysUp            , m_WeightBJMap[channel] [ Weights::JtJvt_SysUp            ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::JtJvt_SysDown          , m_WeightBJMap[channel] [ Weights::JtJvt_SysDown          ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF                 , m_WeightBJMap[channel] [ Weights::BtagSF                 ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_Beff_SysUp      , m_WeightBJMap[channel] [ Weights::BtagSF_Beff_SysUp      ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_Beff_SysDown    , m_WeightBJMap[channel] [ Weights::BtagSF_Beff_SysDown    ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_Ceff_SysUp      , m_WeightBJMap[channel] [ Weights::BtagSF_Ceff_SysUp      ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_Ceff_SysDown    , m_WeightBJMap[channel] [ Weights::BtagSF_Ceff_SysDown    ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_Leff_SysUp      , m_WeightBJMap[channel] [ Weights::BtagSF_Leff_SysUp      ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_Leff_SysDown    , m_WeightBJMap[channel] [ Weights::BtagSF_Leff_SysDown    ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_ExtCeff_SysUp   , m_WeightBJMap[channel] [ Weights::BtagSF_ExtCeff_SysUp   ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_ExtCeff_SysDown , m_WeightBJMap[channel] [ Weights::BtagSF_ExtCeff_SysDown ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_ExtEff_SysUp    , m_WeightBJMap[channel] [ Weights::BtagSF_ExtEff_SysUp    ] );
  m_WeightsBJ[channel]->SetBinContent( Weights::BtagSF_ExtEff_SysDown  , m_WeightBJMap[channel] [ Weights::BtagSF_ExtEff_SysDown  ] );

  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MC                     , m_WeightName [ Weights::MC                     ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::PU                     , m_WeightName [ Weights::PU                     ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::PU_SysUp               , m_WeightName [ Weights::PU_SysUp               ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::PU_SysDown             , m_WeightName [ Weights::PU_SysDown             ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElReco                 , m_WeightName [ Weights::ElReco                 ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElReco_SysUp           , m_WeightName [ Weights::ElReco_SysUp           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElReco_SysDown         , m_WeightName [ Weights::ElReco_SysDown         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElID                   , m_WeightName [ Weights::ElID                   ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElID_SysUp             , m_WeightName [ Weights::ElID_SysUp             ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElID_SysDown           , m_WeightName [ Weights::ElID_SysDown           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElIso                  , m_WeightName [ Weights::ElIso                  ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElIso_SysUp            , m_WeightName [ Weights::ElIso_SysUp            ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElIso_SysDown          , m_WeightName [ Weights::ElIso_SysDown          ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElTrig                 , m_WeightName [ Weights::ElTrig                 ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElTrig_SysUp           , m_WeightName [ Weights::ElTrig_SysUp           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElTrig_SysDown         , m_WeightName [ Weights::ElTrig_SysDown         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::ElL1Calo               , m_WeightName [ Weights::ElL1Calo               ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuReco                 , m_WeightName [ Weights::MuReco                 ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_StatUp          , m_WeightName [ Weights::MuReco_StatUp          ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_StatDown        , m_WeightName [ Weights::MuReco_StatDown        ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_SysUp           , m_WeightName [ Weights::MuReco_SysUp           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuReco_SysDown         , m_WeightName [ Weights::MuReco_SysDown         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuIso                  , m_WeightName [ Weights::MuIso                  ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_StatUp           , m_WeightName [ Weights::MuIso_StatUp           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_StatDown         , m_WeightName [ Weights::MuIso_StatDown         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_SysUp            , m_WeightName [ Weights::MuIso_SysUp            ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuIso_SysDown          , m_WeightName [ Weights::MuIso_SysDown          ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig                 , m_WeightName [ Weights::MuTrig                 ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_StatUp          , m_WeightName [ Weights::MuTrig_StatUp          ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_StatDown        , m_WeightName [ Weights::MuTrig_StatDown        ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_SysUp           , m_WeightName [ Weights::MuTrig_SysUp           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTrig_SysDown         , m_WeightName [ Weights::MuTrig_SysDown         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA                 , m_WeightName [ Weights::MuTTVA                 ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_StatUp          , m_WeightName [ Weights::MuTTVA_StatUp          ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_StatDown        , m_WeightName [ Weights::MuTTVA_StatDown        ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_SysUp           , m_WeightName [ Weights::MuTTVA_SysUp           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::MuTTVA_SysDown         , m_WeightName [ Weights::MuTTVA_SysDown         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaReco                 , m_WeightName [ Weights::TaReco                 ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_SysUp           , m_WeightName [ Weights::TaReco_SysUp           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_SysDown         , m_WeightName [ Weights::TaReco_SysDown         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_Hpt_SysUp       , m_WeightName [ Weights::TaReco_Hpt_SysUp       ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaReco_Hpt_SysDown     , m_WeightName [ Weights::TaReco_Hpt_SysDown     ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaID                   , m_WeightName [ Weights::TaID                   ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaID_SysUp             , m_WeightName [ Weights::TaID_SysUp             ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaID_SysDown           , m_WeightName [ Weights::TaID_SysDown           ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaID_Hpt_SysUp         , m_WeightName [ Weights::TaID_Hpt_SysUp         ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaID_Hpt_SysDown       , m_WeightName [ Weights::TaID_Hpt_SysDown       ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaElOlr                , m_WeightName [ Weights::TaElOlr                ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaElOlr_SysUp          , m_WeightName [ Weights::TaElOlr_SysUp          ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::TaElOlr_SysDown        , m_WeightName [ Weights::TaElOlr_SysDown        ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::JtJvt                  , m_WeightName [ Weights::JtJvt                  ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::JtJvt_SysUp            , m_WeightName [ Weights::JtJvt_SysUp            ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::JtJvt_SysDown          , m_WeightName [ Weights::JtJvt_SysDown          ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF                 , m_WeightName [ Weights::BtagSF                 ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Beff_SysUp      , m_WeightName [ Weights::BtagSF_Beff_SysUp      ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Beff_SysDown    , m_WeightName [ Weights::BtagSF_Beff_SysDown    ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Ceff_SysUp      , m_WeightName [ Weights::BtagSF_Ceff_SysUp      ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Ceff_SysDown    , m_WeightName [ Weights::BtagSF_Ceff_SysDown    ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Leff_SysUp      , m_WeightName [ Weights::BtagSF_Leff_SysUp      ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_Leff_SysDown    , m_WeightName [ Weights::BtagSF_Leff_SysDown    ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtCeff_SysUp   , m_WeightName [ Weights::BtagSF_ExtCeff_SysUp   ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtCeff_SysDown , m_WeightName [ Weights::BtagSF_ExtCeff_SysDown ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtEff_SysUp    , m_WeightName [ Weights::BtagSF_ExtEff_SysUp    ].c_str() );
  m_WeightsBJ[channel]->GetXaxis()->SetBinLabel( Weights::BtagSF_ExtEff_SysDown  , m_WeightName [ Weights::BtagSF_ExtEff_SysDown  ].c_str() );

  Info( "FillWeightsHists()", "Weights Information filled in histograms" );
  
}

void HighMassLFV :: PrintCutFlows(){

  PrintEventFlow();
  PrintMuonFlow();
  PrintElectronFlow();
  PrintTauFlow();
  PrintJetFlow();
  PrintPhotonFlow();
  
}

void HighMassLFV :: PrintEventFlow(){
  
  std::cout << "  Event Flow: " << std::endl;
  std::cout << "        " << m_EvtFlowName [ EvtFlow::Start     ] << " = " << m_EvtFlowMap [0][ EvtFlow::Start     ] << std::endl;
  std::cout << "        " << m_EvtFlowName [ EvtFlow::EvtClean  ] << " = " << m_EvtFlowMap [0][ EvtFlow::EvtClean  ] << std::endl;
  std::cout << "        " << m_EvtFlowName [ EvtFlow::Vertex    ] << " = " << m_EvtFlowMap [0][ EvtFlow::Vertex    ] << std::endl;
  std::cout << "        " << m_EvtFlowName [ EvtFlow::Trigger   ] << " = " << m_EvtFlowMap [0][ EvtFlow::Trigger   ] << std::endl;
  std::cout << "        " << m_EvtFlowName [ EvtFlow::BadMuon   ] << " = " << m_EvtFlowMap [0][ EvtFlow::BadMuon   ] << std::endl;
  std::cout << "        " << m_EvtFlowName [ EvtFlow::BadJet    ] << " = " << m_EvtFlowMap [0][ EvtFlow::BadJet    ] << std::endl;
  std::cout << "        " << m_EvtFlowName [ EvtFlow::Leptons   ] << " = " << m_EvtFlowMap [0][ EvtFlow::Leptons   ] << std::endl;
  std::cout << "" << std::endl;
  std::cout << "  ----------- EMU Channel ---------- " << std::endl;
  std::cout << "        " << m_EMUFlowName [ EvtFlow::ThirdLepV ] << " = " << m_EMUFlowMap [0][ EvtFlow::ThirdLepV ] << std::endl;
  std::cout << "        " << m_EMUFlowName [ EvtFlow::TrigMatch ] << " = " << m_EMUFlowMap [0][ EvtFlow::TrigMatch ] << std::endl;
  std::cout << "        " << m_EMUFlowName [ EvtFlow::OS_Pair   ] << " = " << m_EMUFlowMap [0][ EvtFlow::OS_Pair   ] << std::endl;
  std::cout << "        " << m_EMUFlowName [ EvtFlow::DeltaPhi  ] << " = " << m_EMUFlowMap [0][ EvtFlow::DeltaPhi  ] << std::endl;
  std::cout << "        " << m_EMUFlowName [ EvtFlow::BjetVeto  ] << " = " << m_EMUFlowMap [0][ EvtFlow::BjetVeto  ] << std::endl;
  std::cout << "        " << m_EMUFlowName [ EvtFlow::MET       ] << " = " << m_EMUFlowMap [0][ EvtFlow::MET       ] << std::endl;
  std::cout << "  ----------- ETAU Channel ---------- " << std::endl;
  std::cout << "        " << m_ETAUFlowName [ EvtFlow::ThirdLepV ] << " = " << m_ETAUFlowMap [0][ EvtFlow::ThirdLepV ] << std::endl;
  std::cout << "        " << m_ETAUFlowName [ EvtFlow::TrigMatch ] << " = " << m_ETAUFlowMap [0][ EvtFlow::TrigMatch ] << std::endl;
  std::cout << "        " << m_ETAUFlowName [ EvtFlow::OS_Pair   ] << " = " << m_ETAUFlowMap [0][ EvtFlow::OS_Pair   ] << std::endl;
  std::cout << "        " << m_ETAUFlowName [ EvtFlow::DeltaPhi  ] << " = " << m_ETAUFlowMap [0][ EvtFlow::DeltaPhi  ] << std::endl;
  std::cout << "        " << m_ETAUFlowName [ EvtFlow::BjetVeto  ] << " = " << m_ETAUFlowMap [0][ EvtFlow::BjetVeto  ] << std::endl;
  std::cout << "        " << m_ETAUFlowName [ EvtFlow::MET       ] << " = " << m_ETAUFlowMap [0][ EvtFlow::MET       ] << std::endl;
  std::cout << "  ----------- MUTAU Channel ---------- " << std::endl;
  std::cout << "        " << m_MUTAUFlowName [ EvtFlow::ThirdLepV ] << " = " << m_MUTAUFlowMap [0][ EvtFlow::ThirdLepV ] << std::endl;
  std::cout << "        " << m_MUTAUFlowName [ EvtFlow::TrigMatch ] << " = " << m_MUTAUFlowMap [0][ EvtFlow::TrigMatch ] << std::endl;
  std::cout << "        " << m_MUTAUFlowName [ EvtFlow::OS_Pair   ] << " = " << m_MUTAUFlowMap [0][ EvtFlow::OS_Pair   ] << std::endl;
  std::cout << "        " << m_MUTAUFlowName [ EvtFlow::DeltaPhi  ] << " = " << m_MUTAUFlowMap [0][ EvtFlow::DeltaPhi  ] << std::endl;
  std::cout << "        " << m_MUTAUFlowName [ EvtFlow::BjetVeto  ] << " = " << m_MUTAUFlowMap [0][ EvtFlow::BjetVeto  ] << std::endl;
  std::cout << "        " << m_MUTAUFlowName [ EvtFlow::MET       ] << " = " << m_MUTAUFlowMap [0][ EvtFlow::MET       ] << std::endl;
  std::cout << "" << std::endl;
  
}

void HighMassLFV :: PrintMuonFlow(){
  
  std::cout << "  Muon Flow: " << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::Start     ] <<  " = " << m_MuFlowMap [0][ MuFlow::Start     ] << std::endl; 
  std::cout << "       " << m_MuFlowName [ MuFlow::EvtClean  ] <<  " = " << m_MuFlowMap [0][ MuFlow::EvtClean  ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::Vertex    ] <<  " = " << m_MuFlowMap [0][ MuFlow::Vertex    ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::Trigger   ] <<  " = " << m_MuFlowMap [0][ MuFlow::Trigger   ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::TrigMatch ] <<  " = " << m_MuFlowMap [0][ MuFlow::TrigMatch ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::Pt        ] <<  " = " << m_MuFlowMap [0][ MuFlow::Pt        ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::Eta_ID_Q  ] <<  " = " << m_MuFlowMap [0][ MuFlow::Eta_ID_Q  ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::HighPtCut ] <<  " = " << m_MuFlowMap [0][ MuFlow::HighPtCut ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::D0Sign    ] <<  " = " << m_MuFlowMap [0][ MuFlow::D0Sign    ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::DeltaZ0   ] <<  " = " << m_MuFlowMap [0][ MuFlow::DeltaZ0   ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::Overlaps  ] <<  " = " << m_MuFlowMap [0][ MuFlow::Overlaps  ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::Isolation ] <<  " = " << m_MuFlowMap [0][ MuFlow::Isolation ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::TightMu   ] <<  " = " << m_MuFlowMap [0][ MuFlow::TightMu   ] << std::endl;
  std::cout << "       " << m_MuFlowName [ MuFlow::LooseMu   ] <<  " = " << m_MuFlowMap [0][ MuFlow::LooseMu   ] << std::endl;
  std::cout << "" << std::endl;
  
}

void HighMassLFV :: PrintElectronFlow(){
  
  std::cout << "  Electron Flow: " << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Start     ] << " = " << m_ElFlowMap [0][ ElFlow::Start     ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::EvtClean  ] << " = " << m_ElFlowMap [0][ ElFlow::EvtClean  ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Vertex    ] << " = " << m_ElFlowMap [0][ ElFlow::Vertex    ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Trigger   ] << " = " << m_ElFlowMap [0][ ElFlow::Trigger   ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::TrigMatch ] << " = " << m_ElFlowMap [0][ ElFlow::TrigMatch ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Author    ] << " = " << m_ElFlowMap [0][ ElFlow::Author    ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Pt        ] << " = " << m_ElFlowMap [0][ ElFlow::Pt        ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Eta       ] << " = " << m_ElFlowMap [0][ ElFlow::Eta       ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::ObjectQ   ] << " = " << m_ElFlowMap [0][ ElFlow::ObjectQ   ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::ElecID    ] << " = " << m_ElFlowMap [0][ ElFlow::ElecID    ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::D0Sign    ] << " = " << m_ElFlowMap [0][ ElFlow::D0Sign    ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::DeltaZ0   ] << " = " << m_ElFlowMap [0][ ElFlow::DeltaZ0   ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Overlaps  ] << " = " << m_ElFlowMap [0][ ElFlow::Overlaps  ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::MuElOve   ] << " = " << m_ElFlowMap [0][ ElFlow::MuElOve   ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::Isolation ] << " = " << m_ElFlowMap [0][ ElFlow::Isolation ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::TightEl   ] << " = " << m_ElFlowMap [0][ ElFlow::TightEl   ] << std::endl;
  std::cout << "           " << m_ElFlowName [ ElFlow::LooseEl   ] << " = " << m_ElFlowMap [0][ ElFlow::LooseEl   ] << std::endl;
  std::cout << "" << std::endl;
  
}

void HighMassLFV :: PrintTauFlow(){

  std::cout << "  Tau Flow: " << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::Start     ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::Start     ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::EvtClean  ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::EvtClean  ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::Vertex    ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::Vertex    ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::Trigger   ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::Trigger   ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::TrigMatch ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::TrigMatch ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::Pt        ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::Pt        ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::Eta       ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::Eta       ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::Charge    ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::Charge    ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::nTracks   ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::nTracks   ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::BDTscore  ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::BDTscore  ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::JetIDWP   ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::JetIDWP   ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::ElOR      ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::ElOR      ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::Overlaps  ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::Overlaps  ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::TaMuOve   ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::TaMuOve   ] << std::endl;
  std::cout << "      " << m_TauFlowName [ TauFlow::TaElOve   ] << " = " << m_TauFlowMap[ 0 ][ TauFlow::TaElOve   ] << std::endl;
  std::cout << "" << std::endl;
  
}

void HighMassLFV :: PrintJetFlow(){
  
  std::cout << "  Jet Flow: " << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Start         ] << " = " << m_JtFlowMap [0][ JtFlow::Start         ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::EvtClean      ] << " = " << m_JtFlowMap [0][ JtFlow::EvtClean      ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Vertex        ] << " = " << m_JtFlowMap [0][ JtFlow::Vertex        ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Trigger       ] << " = " << m_JtFlowMap [0][ JtFlow::Trigger       ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Pt            ] << " = " << m_JtFlowMap [0][ JtFlow::Pt            ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Eta           ] << " = " << m_JtFlowMap [0][ JtFlow::Eta           ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Overlaps      ] << " = " << m_JtFlowMap [0][ JtFlow::Overlaps      ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::JetElOverlap  ] << " = " << m_JtFlowMap [0][ JtFlow::JetElOverlap  ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::JetTauOverlap ] << " = " << m_JtFlowMap [0][ JtFlow::JetTauOverlap ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::JetMuOverlap  ] << " = " << m_JtFlowMap [0][ JtFlow::JetMuOverlap  ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::JVT           ] << " = " << m_JtFlowMap [0][ JtFlow::JVT           ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Clean         ] << " = " << m_JtFlowMap [0][ JtFlow::Clean         ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::BjetVeto      ] << " = " << m_JtFlowMap [0][ JtFlow::BjetVeto      ] << std::endl;
  std::cout << "      " << m_JtFlowName [ JtFlow::Bjet          ] << " = " << m_JtFlowMap [0][ JtFlow::Bjet          ] << std::endl;
  std::cout << "" << std::endl;
  
}

void HighMassLFV :: PrintPhotonFlow(){
  
  std::cout << "  Photon Flow: " << std::endl;
  
  std::cout << "         " << m_PhFlowName [ PhFlow::Start    ] << " = " << m_PhFlowMap [0][ PhFlow::Start    ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::EvtClean ] << " = " << m_PhFlowMap [0][ PhFlow::EvtClean ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::Vertex   ] << " = " << m_PhFlowMap [0][ PhFlow::Vertex   ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::Trigger  ] << " = " << m_PhFlowMap [0][ PhFlow::Trigger  ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::Pt       ] << " = " << m_PhFlowMap [0][ PhFlow::Pt       ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::Eta      ] << " = " << m_PhFlowMap [0][ PhFlow::Eta      ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::Author   ] << " = " << m_PhFlowMap [0][ PhFlow::Author   ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::ObjQual  ] << " = " << m_PhFlowMap [0][ PhFlow::ObjQual  ] << std::endl;
  std::cout << "         " << m_PhFlowName [ PhFlow::Clean    ] << " = " << m_PhFlowMap [0][ PhFlow::Clean    ] << std::endl;
  
  std::cout << "" << std::endl;
  
}

void HighMassLFV :: PrintWeights(){

  for( int ch=1; ch<4; ch++){
    PrintChannelWeights(ch);
  }

}

void HighMassLFV :: PrintChannelWeights(int channel){

  std::cout<< " CHANNEL ----> " << channel << std::endl;
  std::cout<< "" << std::endl;
  std::cout<< "   Weights for events before b-jet Veto:" << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MC                     ] << " = " << m_WeightMap[channel][ Weights::MC                     ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::PU                     ] << " = " << m_WeightMap[channel][ Weights::PU                     ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::PU_SysUp               ] << " = " << m_WeightMap[channel][ Weights::PU_SysUp               ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::PU_SysDown             ] << " = " << m_WeightMap[channel][ Weights::PU_SysDown             ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElReco                 ] << " = " << m_WeightMap[channel][ Weights::ElReco                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElReco_SysUp           ] << " = " << m_WeightMap[channel][ Weights::ElReco_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElReco_SysDown         ] << " = " << m_WeightMap[channel][ Weights::ElReco_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElID                   ] << " = " << m_WeightMap[channel][ Weights::ElID                   ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElID_SysUp             ] << " = " << m_WeightMap[channel][ Weights::ElID_SysUp             ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElID_SysDown           ] << " = " << m_WeightMap[channel][ Weights::ElID_SysDown           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElIso                  ] << " = " << m_WeightMap[channel][ Weights::ElIso                  ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElIso_SysUp            ] << " = " << m_WeightMap[channel][ Weights::ElIso_SysUp            ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElIso_SysDown          ] << " = " << m_WeightMap[channel][ Weights::ElIso_SysDown          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElTrig                 ] << " = " << m_WeightMap[channel][ Weights::ElTrig                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElTrig_SysUp           ] << " = " << m_WeightMap[channel][ Weights::ElTrig_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElTrig_SysDown         ] << " = " << m_WeightMap[channel][ Weights::ElTrig_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElL1Calo               ] << " = " << m_WeightMap[channel][ Weights::ElL1Calo               ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco                 ] << " = " << m_WeightMap[channel][ Weights::MuReco                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_StatUp          ] << " = " << m_WeightMap[channel][ Weights::MuReco_StatUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_StatDown        ] << " = " << m_WeightMap[channel][ Weights::MuReco_StatDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_SysUp           ] << " = " << m_WeightMap[channel][ Weights::MuReco_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_SysDown         ] << " = " << m_WeightMap[channel][ Weights::MuReco_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso                  ] << " = " << m_WeightMap[channel][ Weights::MuIso                  ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_StatUp           ] << " = " << m_WeightMap[channel][ Weights::MuIso_StatUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_StatDown         ] << " = " << m_WeightMap[channel][ Weights::MuIso_StatDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_SysUp            ] << " = " << m_WeightMap[channel][ Weights::MuIso_SysUp            ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_SysDown          ] << " = " << m_WeightMap[channel][ Weights::MuIso_SysDown          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig                 ] << " = " << m_WeightMap[channel][ Weights::MuTrig                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_StatUp          ] << " = " << m_WeightMap[channel][ Weights::MuTrig_StatUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_StatDown        ] << " = " << m_WeightMap[channel][ Weights::MuTrig_StatDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_SysUp           ] << " = " << m_WeightMap[channel][ Weights::MuTrig_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_SysDown         ] << " = " << m_WeightMap[channel][ Weights::MuTrig_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA                 ] << " = " << m_WeightMap[channel][ Weights::MuTTVA                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_StatUp          ] << " = " << m_WeightMap[channel][ Weights::MuTTVA_StatUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_StatDown        ] << " = " << m_WeightMap[channel][ Weights::MuTTVA_StatDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_SysUp           ] << " = " << m_WeightMap[channel][ Weights::MuTTVA_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_SysDown         ] << " = " << m_WeightMap[channel][ Weights::MuTTVA_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco                 ] << " = " << m_WeightMap[channel][ Weights::TaReco                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_SysUp           ] << " = " << m_WeightMap[channel][ Weights::TaReco_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_SysDown         ] << " = " << m_WeightMap[channel][ Weights::TaReco_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_Hpt_SysUp       ] << " = " << m_WeightMap[channel][ Weights::TaReco_Hpt_SysUp       ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_Hpt_SysDown     ] << " = " << m_WeightMap[channel][ Weights::TaReco_Hpt_SysDown     ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID                   ] << " = " << m_WeightMap[channel][ Weights::TaID                   ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_SysUp             ] << " = " << m_WeightMap[channel][ Weights::TaID_SysUp             ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_SysDown           ] << " = " << m_WeightMap[channel][ Weights::TaID_SysDown           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_Hpt_SysUp         ] << " = " << m_WeightMap[channel][ Weights::TaID_Hpt_SysUp         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_Hpt_SysDown       ] << " = " << m_WeightMap[channel][ Weights::TaID_Hpt_SysDown       ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaElOlr                ] << " = " << m_WeightMap[channel][ Weights::TaElOlr                ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaElOlr_SysUp          ] << " = " << m_WeightMap[channel][ Weights::TaElOlr_SysUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaElOlr_SysDown        ] << " = " << m_WeightMap[channel][ Weights::TaElOlr_SysDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::JtJvt                  ] << " = " << m_WeightMap[channel][ Weights::JtJvt                  ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::JtJvt_SysUp            ] << " = " << m_WeightMap[channel][ Weights::JtJvt_SysUp            ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::JtJvt_SysDown          ] << " = " << m_WeightMap[channel][ Weights::JtJvt_SysDown          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF                 ] << " = " << m_WeightMap[channel][ Weights::BtagSF                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Beff_SysUp      ] << " = " << m_WeightMap[channel][ Weights::BtagSF_Beff_SysUp      ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Beff_SysDown    ] << " = " << m_WeightMap[channel][ Weights::BtagSF_Beff_SysDown    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Ceff_SysUp      ] << " = " << m_WeightMap[channel][ Weights::BtagSF_Ceff_SysUp      ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Ceff_SysDown    ] << " = " << m_WeightMap[channel][ Weights::BtagSF_Ceff_SysDown    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Leff_SysUp      ] << " = " << m_WeightMap[channel][ Weights::BtagSF_Leff_SysUp      ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Leff_SysDown    ] << " = " << m_WeightMap[channel][ Weights::BtagSF_Leff_SysDown    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtCeff_SysUp   ] << " = " << m_WeightMap[channel][ Weights::BtagSF_ExtCeff_SysUp   ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtCeff_SysDown ] << " = " << m_WeightMap[channel][ Weights::BtagSF_ExtCeff_SysDown ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtEff_SysUp    ] << " = " << m_WeightMap[channel][ Weights::BtagSF_ExtEff_SysUp    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtEff_SysDown  ] << " = " << m_WeightMap[channel][ Weights::BtagSF_ExtEff_SysDown  ] << std::endl;
  std::cout<< "" << std::endl;
  
  std::cout<< "   Weights for events after b-jet Veto: " << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MC                     ] << " = " << m_WeightBJMap[channel][ Weights::MC                     ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::PU                     ] << " = " << m_WeightBJMap[channel][ Weights::PU                     ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::PU_SysUp               ] << " = " << m_WeightBJMap[channel][ Weights::PU_SysUp               ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::PU_SysDown             ] << " = " << m_WeightBJMap[channel][ Weights::PU_SysDown             ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElReco                 ] << " = " << m_WeightBJMap[channel][ Weights::ElReco                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElReco_SysUp           ] << " = " << m_WeightBJMap[channel][ Weights::ElReco_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElReco_SysDown         ] << " = " << m_WeightBJMap[channel][ Weights::ElReco_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElID                   ] << " = " << m_WeightBJMap[channel][ Weights::ElID                   ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElID_SysUp             ] << " = " << m_WeightBJMap[channel][ Weights::ElID_SysUp             ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElID_SysDown           ] << " = " << m_WeightBJMap[channel][ Weights::ElID_SysDown           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElIso                  ] << " = " << m_WeightBJMap[channel][ Weights::ElIso                  ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElIso_SysUp            ] << " = " << m_WeightBJMap[channel][ Weights::ElIso_SysUp            ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElIso_SysDown          ] << " = " << m_WeightBJMap[channel][ Weights::ElIso_SysDown          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElTrig                 ] << " = " << m_WeightBJMap[channel][ Weights::ElTrig                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElTrig_SysUp           ] << " = " << m_WeightBJMap[channel][ Weights::ElTrig_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElTrig_SysDown         ] << " = " << m_WeightBJMap[channel][ Weights::ElTrig_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::ElL1Calo               ] << " = " << m_WeightBJMap[channel][ Weights::ElL1Calo               ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco                 ] << " = " << m_WeightBJMap[channel][ Weights::MuReco                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_StatUp          ] << " = " << m_WeightBJMap[channel][ Weights::MuReco_StatUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_StatDown        ] << " = " << m_WeightBJMap[channel][ Weights::MuReco_StatDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_SysUp           ] << " = " << m_WeightBJMap[channel][ Weights::MuReco_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuReco_SysDown         ] << " = " << m_WeightBJMap[channel][ Weights::MuReco_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso                  ] << " = " << m_WeightBJMap[channel][ Weights::MuIso                  ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_StatUp           ] << " = " << m_WeightBJMap[channel][ Weights::MuIso_StatUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_StatDown         ] << " = " << m_WeightBJMap[channel][ Weights::MuIso_StatDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_SysUp            ] << " = " << m_WeightBJMap[channel][ Weights::MuIso_SysUp            ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuIso_SysDown          ] << " = " << m_WeightBJMap[channel][ Weights::MuIso_SysDown          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig                 ] << " = " << m_WeightBJMap[channel][ Weights::MuTrig                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_StatUp          ] << " = " << m_WeightBJMap[channel][ Weights::MuTrig_StatUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_StatDown        ] << " = " << m_WeightBJMap[channel][ Weights::MuTrig_StatDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_SysUp           ] << " = " << m_WeightBJMap[channel][ Weights::MuTrig_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTrig_SysDown         ] << " = " << m_WeightBJMap[channel][ Weights::MuTrig_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA                 ] << " = " << m_WeightBJMap[channel][ Weights::MuTTVA                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_StatUp          ] << " = " << m_WeightBJMap[channel][ Weights::MuTTVA_StatUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_StatDown        ] << " = " << m_WeightBJMap[channel][ Weights::MuTTVA_StatDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_SysUp           ] << " = " << m_WeightBJMap[channel][ Weights::MuTTVA_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::MuTTVA_SysDown         ] << " = " << m_WeightBJMap[channel][ Weights::MuTTVA_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco                 ] << " = " << m_WeightBJMap[channel][ Weights::TaReco                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_SysUp           ] << " = " << m_WeightBJMap[channel][ Weights::TaReco_SysUp           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_SysDown         ] << " = " << m_WeightBJMap[channel][ Weights::TaReco_SysDown         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_Hpt_SysUp       ] << " = " << m_WeightBJMap[channel][ Weights::TaReco_Hpt_SysUp       ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaReco_Hpt_SysDown     ] << " = " << m_WeightBJMap[channel][ Weights::TaReco_Hpt_SysDown     ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID                   ] << " = " << m_WeightBJMap[channel][ Weights::TaID                   ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_SysUp             ] << " = " << m_WeightBJMap[channel][ Weights::TaID_SysUp             ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_SysDown           ] << " = " << m_WeightBJMap[channel][ Weights::TaID_SysDown           ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_Hpt_SysUp         ] << " = " << m_WeightBJMap[channel][ Weights::TaID_Hpt_SysUp         ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaID_Hpt_SysDown       ] << " = " << m_WeightBJMap[channel][ Weights::TaID_Hpt_SysDown       ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaElOlr                ] << " = " << m_WeightBJMap[channel][ Weights::TaElOlr                ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaElOlr_SysUp          ] << " = " << m_WeightBJMap[channel][ Weights::TaElOlr_SysUp          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::TaElOlr_SysDown        ] << " = " << m_WeightBJMap[channel][ Weights::TaElOlr_SysDown        ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::JtJvt                  ] << " = " << m_WeightBJMap[channel][ Weights::JtJvt                  ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::JtJvt_SysUp            ] << " = " << m_WeightBJMap[channel][ Weights::JtJvt_SysUp            ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::JtJvt_SysDown          ] << " = " << m_WeightBJMap[channel][ Weights::JtJvt_SysDown          ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF                 ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF                 ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Beff_SysUp      ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_Beff_SysUp      ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Beff_SysDown    ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_Beff_SysDown    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Ceff_SysUp      ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_Ceff_SysUp      ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Ceff_SysDown    ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_Ceff_SysDown    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Leff_SysUp      ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_Leff_SysUp      ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_Leff_SysDown    ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_Leff_SysDown    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtCeff_SysUp   ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_ExtCeff_SysUp   ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtCeff_SysDown ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_ExtCeff_SysDown ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtEff_SysUp    ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_ExtEff_SysUp    ] << std::endl;
  std::cout<< "           " << m_WeightName[ Weights::BtagSF_ExtEff_SysDown  ] << " = " << m_WeightBJMap[channel][ Weights::BtagSF_ExtEff_SysDown  ] << std::endl;
  std::cout<< "" << std::endl;
  std::cout<< "" << std::endl;
  
}
