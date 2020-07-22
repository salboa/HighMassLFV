#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: DefineSystematicsVariations(){

  m_NominalSysSet.insert( CP::SystematicSet() );
  DefineMuonSystematics();
  DefineElectronSystematics();
  DefineTauSystematics();
  DefineJetSystematics();
  DefinePileUpWgtSystematics();
  DefineMETSystematics();
  FillSystematicsMaps();
  FillSystematicsNames();
  
}

void HighMassLFV :: DefineMuonSystematics(){

  /* Reconstruction Efficiency SF-Sys */
  m_MuReco_StatUp.insert(   CP::SystematicVariation( "MUON_EFF_STAT" ,  1) );
  m_MuReco_StatDown.insert( CP::SystematicVariation( "MUON_EFF_STAT" , -1) );
  m_MuReco_SysUp.insert(    CP::SystematicVariation( "MUON_EFF_SYS"  ,  1) );
  m_MuReco_SysDown.insert(  CP::SystematicVariation( "MUON_EFF_SYS"  , -1) );
  /* Isolation Efficiency SF-Sys */
  m_MuIso_StatUp.insert(   CP::SystematicVariation("MUON_ISO_STAT" ,  1) );
  m_MuIso_StatDown.insert( CP::SystematicVariation("MUON_ISO_STAT" , -1) );
  m_MuIso_SysUp.insert(    CP::SystematicVariation("MUON_ISO_SYS"  ,  1) );
  m_MuIso_SysDown.insert(  CP::SystematicVariation("MUON_ISO_SYS"  , -1) );
  /* Trigger Efficiency SF-Sys */
  m_MuTrg_StatUp.insert(    CP::SystematicVariation("MUON_EFF_TrigStatUncertainty" ,  1) );
  m_MuTrg_StatDown.insert(  CP::SystematicVariation("MUON_EFF_TrigStatUncertainty" , -1) );
  m_MuTrg_SysUp.insert(     CP::SystematicVariation("MUON_EFF_TrigSystUncertainty" ,  1) );
  m_MuTrg_SysDown.insert(   CP::SystematicVariation("MUON_EFF_TrigSystUncertainty" , -1) );
  m_MuTTVA_StatUp.insert(   CP::SystematicVariation("MUON_TTVA_STAT"               ,  1) );
  m_MuTTVA_StatDown.insert( CP::SystematicVariation("MUON_TTVA_STAT"               , -1) );
  m_MuTTVA_SysUp.insert(    CP::SystematicVariation("MUON_TTVA_SYS"                ,  1) );
  m_MuTTVA_SysDown.insert(  CP::SystematicVariation("MUON_TTVA_SYS"                , -1) );
  /* Scale and Smearing Sys */
  m_MuSmeID_SysUp.insert(    CP::SystematicVariation("MUON_ID"              ,  1) );
  m_MuSmeID_SysDown.insert(  CP::SystematicVariation("MUON_ID"              , -1) );
  m_MuSmeMS_SysUp.insert(    CP::SystematicVariation("MUON_MS"              ,  1) );
  m_MuSmeMS_SysDown.insert(  CP::SystematicVariation("MUON_MS"              , -1) );
  m_MuScale_SysUp.insert(    CP::SystematicVariation("MUON_SCALE"           ,  1) );
  m_MuScale_SysDown.insert(  CP::SystematicVariation("MUON_SCALE"           , -1) );
  m_MuSagRho_SysUp.insert(   CP::SystematicVariation("MUON_SAGITTA_RHO"     ,  1) );
  m_MuSagRho_SysDown.insert( CP::SystematicVariation("MUON_SAGITTA_RHO"     , -1) );
  m_MuSagRes_SysUp.insert(   CP::SystematicVariation("MUON_SAGITTA_RESBIAS" ,  1) );
  m_MuSagRes_SysDown.insert( CP::SystematicVariation("MUON_SAGITTA_RESBIAS" , -1) );
  
}

void HighMassLFV :: DefineElectronSystematics(){

  /* Reconstruction Efficiency SF-Sys */
  m_ElReco_SysUp.insert(   CP::SystematicVariation("EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR" ,  1) );
  m_ElReco_SysDown.insert( CP::SystematicVariation("EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR" , -1) );
  /* Identification Efficiency SF-Sys */
  m_ElID_SysUp.insert(   CP::SystematicVariation("EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR" ,  1) );
  m_ElID_SysDown.insert( CP::SystematicVariation("EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR" , -1) );
  /* Isolation Efficiency SF-Sys */
  m_ElIso_SysUp.insert(   CP::SystematicVariation("EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR" ,  1) );
  m_ElIso_SysDown.insert( CP::SystematicVariation("EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR" , -1) );
  /* Trigger Efficiency SF-Sys */
  m_ElTrg_SysUp.insert(   CP::SystematicVariation("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR",  1) );
  m_ElTrg_SysDown.insert( CP::SystematicVariation("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR", -1) );
  /* Scale and Smearing Sys */
  m_ElSme_SysUp.insert(     CP::SystematicVariation("EG_RESOLUTION_ALL" ,  1) );
  m_ElSme_SysDown.insert(   CP::SystematicVariation("EG_RESOLUTION_ALL" , -1) );
  m_ElScale_SysUp.insert(   CP::SystematicVariation("EG_SCALE_ALL"      ,  1) );
  m_ElScale_SysDown.insert( CP::SystematicVariation("EG_SCALE_ALL"      , -1) );
  
}

void HighMassLFV :: DefineTauSystematics(){

  /* Reconstruction Efficiency SF-Sys */
  m_TaReco_SysUp.insert(      CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_RECO_TOTAL",  1) );
  m_TaReco_SysDown.insert(    CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_RECO_TOTAL", -1) );
  m_TaRecoHpt_SysUp.insert(   CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_RECO_HIGHPT",  1) );
  m_TaRecoHpt_SysDown.insert( CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_RECO_HIGHPT", -1) );
  /* Electron Overlap Efficiency SF-Sys */
  m_TaEleOlr_SysUp.insert(   CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL" ,  1) );
  m_TaEleOlr_SysDown.insert( CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_ELEOLR_TOTAL" , -1) );
  /* Jet Identification Efficiency SF-Sys */
  m_TaJetID_SysUp.insert(      CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_JETID_TOTAL",  1) );
  m_TaJetID_SysDown.insert(    CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_JETID_TOTAL", -1) );
  m_TaJetIDHpt_SysUp.insert(   CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_JETID_HIGHPT",  1) );
  m_TaJetIDHpt_SysDown.insert( CP::SystematicVariation("TAUS_TRUEHADTAU_EFF_JETID_HIGHPT", -1) );
  /* Smearing */
  m_TaSme_SysUp.insert(      CP::SystematicVariation("TAUS_TRUEHADTAU_SME_TES_INSITU",  1 ) );
  m_TaSme_SysDown.insert(    CP::SystematicVariation("TAUS_TRUEHADTAU_SME_TES_INSITU", -1 ) );
  m_TaSmeDet_SysUp.insert(   CP::SystematicVariation("TAUS_TRUEHADTAU_SME_TES_DETECTOR",  1 ) );
  m_TaSmeDet_SysDown.insert( CP::SystematicVariation("TAUS_TRUEHADTAU_SME_TES_DETECTOR", -1 ) );
  m_TaSmeMod_SysUp.insert(   CP::SystematicVariation("TAUS_TRUEHADTAU_SME_TES_MODEL",  1 ) );
  m_TaSmeMod_SysDown.insert( CP::SystematicVariation("TAUS_TRUEHADTAU_SME_TES_MODEL", -1 ) );

  /*update tau sys*/

}

void HighMassLFV :: DefineJetSystematics(){

  /* B-Tagging Efficiency SF-Sys */
  m_JtBeff_SysUp.insert(   CP::SystematicVariation("FT_EFF_B_systematics",  1) );
  m_JtBeff_SysDown.insert( CP::SystematicVariation("FT_EFF_B_systematics", -1) );
  m_JtCeff_SysUp.insert(   CP::SystematicVariation("FT_EFF_C_systematics",  1) );
  m_JtCeff_SysDown.insert( CP::SystematicVariation("FT_EFF_C_systematics", -1) );
  m_JtLeff_SysUp.insert(   CP::SystematicVariation("FT_EFF_Light_systematics",  1) );
  m_JtLeff_SysDown.insert( CP::SystematicVariation("FT_EFF_Light_systematics", -1) );
  m_JtExtCeff_SysUp.insert(   CP::SystematicVariation("FT_EFF_extrapolation from charm",  1) );
  m_JtExtCeff_SysDown.insert( CP::SystematicVariation("FT_EFF_extrapolation from charm", -1) );
  m_JtExtEff_SysUp.insert(    CP::SystematicVariation("FT_EFF_extrapolation",  1) );
  m_JtExtEff_SysDown.insert(  CP::SystematicVariation("FT_EFF_extrapolation", -1) );
  /* Jet Jvt Sys */
  m_JtJvt_SysUp.insert(   CP::SystematicVariation("JET_JvtEfficiency",  1) );
  m_JtJvt_SysDown.insert( CP::SystematicVariation("JET_JvtEfficiency", -1) );
  /* Jet Smearing Sys */
  m_JtSme_SysUp.insert( CP::SystematicVariation("JET_JER_SINGLE_NP", 1) );
  /* Jet Reco/Calib/ID Sys */
  m_JtUncNP1_SysUp.insert(   CP::SystematicVariation( "JET_GroupedNP_1",  1) );
  m_JtUncNP1_SysDown.insert( CP::SystematicVariation( "JET_GroupedNP_1", -1) );
  m_JtUncNP2_SysUp.insert(   CP::SystematicVariation( "JET_GroupedNP_2",  1) );
  m_JtUncNP2_SysDown.insert( CP::SystematicVariation( "JET_GroupedNP_2", -1) );
  m_JtUncNP3_SysUp.insert(   CP::SystematicVariation( "JET_GroupedNP_3",  1) );
  m_JtUncNP3_SysDown.insert( CP::SystematicVariation( "JET_GroupedNP_3", -1) );
  m_JtUncETA_SysUp.insert(   CP::SystematicVariation( "JET_EtaIntercalibration_NonClosure",  1 ) );
  m_JtUncETA_SysDown.insert( CP::SystematicVariation( "JET_EtaIntercalibration_NonClosure", -1 ) );
			   
}

void HighMassLFV :: DefinePileUpWgtSystematics(){
  
  /* PileUp Reweighting SF-Sys */
  m_PuWgt_SysUp.insert(   CP::SystematicVariation("PRW_DATASF",  1) );
  m_PuWgt_SysDown.insert( CP::SystematicVariation("PRW_DATASF", -1) );
  
}

void HighMassLFV :: DefineMETSystematics(){
  
  /* MET systematics */
  m_MetResPara.insert( CP::SystematicVariation("MET_SoftTrk_ResoPara") );
  m_MetResPerp.insert( CP::SystematicVariation("MET_SoftTrk_ResoPerp") );
  m_MetScl_SysUp.insert(   CP::SystematicVariation("MET_SoftTrk_ScaleUp") );
  m_MetScl_SysDown.insert( CP::SystematicVariation("MET_SoftTrk_ScaleDown") );
  
}


void HighMassLFV :: FillSystematicsMaps(){
  
  m_MuSFVar [ Mu_SFSys::MuReco_StatUp   ] = m_MuReco_StatUp;
  m_MuSFVar [ Mu_SFSys::MuReco_StatDown ] = m_MuReco_StatDown;
  m_MuSFVar [ Mu_SFSys::MuReco_SysUp    ] = m_MuReco_SysUp;
  m_MuSFVar [ Mu_SFSys::MuReco_SysDown  ] = m_MuReco_SysDown;
  m_MuSFVar [ Mu_SFSys::MuIso_StatUp    ] = m_MuIso_StatUp;
  m_MuSFVar [ Mu_SFSys::MuIso_StatDown  ] = m_MuIso_StatDown;
  m_MuSFVar [ Mu_SFSys::MuIso_SysUp     ] = m_MuIso_SysUp;
  m_MuSFVar [ Mu_SFSys::MuIso_SysDown   ] = m_MuIso_SysDown;
  m_MuSFVar [ Mu_SFSys::MuTrg_StatUp    ] = m_MuTrg_StatUp;
  m_MuSFVar [ Mu_SFSys::MuTrg_StatDown  ] = m_MuTrg_StatDown;
  m_MuSFVar [ Mu_SFSys::MuTrg_SysUp     ] = m_MuTrg_SysUp;
  m_MuSFVar [ Mu_SFSys::MuTrg_SysDown   ] = m_MuTrg_SysDown;
  m_MuSFVar [ Mu_SFSys::MuTTVA_StatUp   ] = m_MuTTVA_StatUp;
  m_MuSFVar [ Mu_SFSys::MuTTVA_StatDown ] = m_MuTTVA_StatDown;
  m_MuSFVar [ Mu_SFSys::MuTTVA_SysUp    ] = m_MuTTVA_SysUp;
  m_MuSFVar [ Mu_SFSys::MuTTVA_SysDown  ] = m_MuTTVA_SysDown;

  m_MuSHVar [ Mu_SHSys::MuSmeID_SysUp    ] = m_MuSmeID_SysUp;
  m_MuSHVar [ Mu_SHSys::MuSmeID_SysDown  ] = m_MuSmeID_SysDown;
  m_MuSHVar [ Mu_SHSys::MuSmeMS_SysUp    ] = m_MuSmeMS_SysUp;
  m_MuSHVar [ Mu_SHSys::MuSmeMS_SysDown  ] = m_MuSmeMS_SysDown;
  m_MuSHVar [ Mu_SHSys::MuScale_SysUp    ] = m_MuScale_SysUp;
  m_MuSHVar [ Mu_SHSys::MuScale_SysDown  ] = m_MuScale_SysDown;
  m_MuSHVar [ Mu_SHSys::MuSagRho_SysUp   ] = m_MuSagRho_SysUp;
  m_MuSHVar [ Mu_SHSys::MuSagRho_SysDown ] = m_MuSagRho_SysDown;
  m_MuSHVar [ Mu_SHSys::MuSagRes_SysUp   ] = m_MuSagRes_SysUp;
  m_MuSHVar [ Mu_SHSys::MuSagRes_SysDown ] = m_MuSagRes_SysDown;
  
  m_ElSFVar [ El_SFSys::ElReco_SysUp    ] = m_ElReco_SysUp;
  m_ElSFVar [ El_SFSys::ElReco_SysDown  ] = m_ElReco_SysDown;
  m_ElSFVar [ El_SFSys::ElID_SysUp      ] = m_ElID_SysUp;
  m_ElSFVar [ El_SFSys::ElID_SysDown    ] = m_ElID_SysDown;
  m_ElSFVar [ El_SFSys::ElIso_SysUp     ] = m_ElIso_SysUp;
  m_ElSFVar [ El_SFSys::ElIso_SysDown   ] = m_ElIso_SysDown;
  m_ElSFVar [ El_SFSys::ElTrg_SysUp     ] = m_ElTrg_SysUp;
  m_ElSFVar [ El_SFSys::ElTrg_SysDown   ] = m_ElTrg_SysDown;

  m_ElSHVar [ El_SHSys::ElSme_SysUp     ] = m_ElSme_SysUp;
  m_ElSHVar [ El_SHSys::ElSme_SysDown   ] = m_ElSme_SysDown;
  m_ElSHVar [ El_SHSys::ElScale_SysUp   ] = m_ElScale_SysUp;
  m_ElSHVar [ El_SHSys::ElScale_SysDown ] = m_ElScale_SysDown;

  m_TaSFVar [ Ta_SFSys::TaReco_SysUp	   ] = m_TaReco_SysUp;	 
  m_TaSFVar [ Ta_SFSys::TaReco_SysDown     ] = m_TaReco_SysDown;	 
  m_TaSFVar [ Ta_SFSys::TaRecoHpt_SysUp    ] = m_TaRecoHpt_SysUp;	 
  m_TaSFVar [ Ta_SFSys::TaRecoHpt_SysDown  ] = m_TaRecoHpt_SysDown;
  m_TaSFVar [ Ta_SFSys::TaEleOlr_SysUp     ] = m_TaEleOlr_SysUp;	 
  m_TaSFVar [ Ta_SFSys::TaEleOlr_SysDown   ] = m_TaEleOlr_SysDown; 
  m_TaSFVar [ Ta_SFSys::TaJetID_SysUp  	   ] = m_TaJetID_SysUp;	 
  m_TaSFVar [ Ta_SFSys::TaJetID_SysDown    ] = m_TaJetID_SysDown;	 
  m_TaSFVar [ Ta_SFSys::TaJetIDHpt_SysUp   ] = m_TaJetIDHpt_SysUp; 
  m_TaSFVar [ Ta_SFSys::TaJetIDHpt_SysDown ] = m_TaJetIDHpt_SysDown;

  m_TaSHVar [ Ta_SHSys::TaSme_SysUp      ] = m_TaSme_SysUp;
  m_TaSHVar [ Ta_SHSys::TaSme_SysDown    ] = m_TaSme_SysDown;
  m_TaSHVar [ Ta_SHSys::TaSmeDet_SysUp   ] = m_TaSmeDet_SysUp;
  m_TaSHVar [ Ta_SHSys::TaSmeDet_SysDown ] = m_TaSmeDet_SysDown;
  m_TaSHVar [ Ta_SHSys::TaSmeMod_SysUp   ] = m_TaSmeMod_SysUp;
  m_TaSHVar [ Ta_SHSys::TaSmeMod_SysDown ] = m_TaSmeMod_SysDown;
  
  m_JtSFVar [ Jt_SFSys::JtBeff_SysUp      ] = m_JtBeff_SysUp;
  m_JtSFVar [ Jt_SFSys::JtBeff_SysDown    ] = m_JtBeff_SysDown;
  m_JtSFVar [ Jt_SFSys::JtCeff_SysUp      ] = m_JtCeff_SysUp;
  m_JtSFVar [ Jt_SFSys::JtCeff_SysDown    ] = m_JtCeff_SysDown;
  m_JtSFVar [ Jt_SFSys::JtLeff_SysUp      ] = m_JtLeff_SysUp;
  m_JtSFVar [ Jt_SFSys::JtLeff_SysDown    ] = m_JtLeff_SysDown;
  m_JtSFVar [ Jt_SFSys::JtExtCeff_SysUp   ] = m_JtExtCeff_SysUp;
  m_JtSFVar [ Jt_SFSys::JtExtCeff_SysDown ] = m_JtExtCeff_SysDown;
  m_JtSFVar [ Jt_SFSys::JtExtEff_SysUp    ] = m_JtExtEff_SysUp;
  m_JtSFVar [ Jt_SFSys::JtExtEff_SysDown  ] = m_JtExtEff_SysDown;
  m_JtSFVar [ Jt_SFSys::JtJvt_SysUp       ] = m_JtJvt_SysUp;
  m_JtSFVar [ Jt_SFSys::JtJvt_SysDown     ] = m_JtJvt_SysDown;

  m_JtSHVar [ Jt_SHSys::JtSme_SysUp      ] = m_JtSme_SysUp;
  
  m_JtUNVar [ Jt_UNSys::JtUncNP1_SysUp   ] = m_JtUncNP1_SysUp;
  m_JtUNVar [ Jt_UNSys::JtUncNP1_SysDown ] = m_JtUncNP1_SysDown;
  m_JtUNVar [ Jt_UNSys::JtUncNP2_SysUp   ] = m_JtUncNP2_SysUp;
  m_JtUNVar [ Jt_UNSys::JtUncNP2_SysDown ] = m_JtUncNP2_SysDown;
  m_JtUNVar [ Jt_UNSys::JtUncNP3_SysUp   ] = m_JtUncNP3_SysUp;
  m_JtUNVar [ Jt_UNSys::JtUncNP3_SysDown ] = m_JtUncNP3_SysDown;
  m_JtUNVar [ Jt_UNSys::JtUncETA_SysUp   ] = m_JtUncETA_SysUp;
  m_JtUNVar [ Jt_UNSys::JtUncETA_SysDown ] = m_JtUncETA_SysDown;

  m_PuWgtVar [ Pu_WgtSys::PuWgt_SysUp   ] = m_PuWgt_SysUp;
  m_PuWgtVar [ Pu_WgtSys::PuWgt_SysDown ] = m_PuWgt_SysDown;

  m_MetVar [ Met_SHSys::MetResPara     ] = m_MetResPara;
  m_MetVar [ Met_SHSys::MetResPerp     ] = m_MetResPerp;    
  m_MetVar [ Met_SHSys::MetScl_SysUp   ] = m_MetScl_SysUp;
  m_MetVar [ Met_SHSys::MetScl_SysDown ] = m_MetScl_SysDown;

}

void HighMassLFV :: FillSystematicsNames(){

  m_MuSFVarName [ Mu_SFSys::MuReco_StatUp   ] = "MuReco_StatUp";
  m_MuSFVarName [ Mu_SFSys::MuReco_StatDown ] = "MuReco_StatDown";
  m_MuSFVarName [ Mu_SFSys::MuReco_SysUp    ] = "MuReco_SysUp";
  m_MuSFVarName [ Mu_SFSys::MuReco_SysDown  ] = "MuReco_SysDown";
  m_MuSFVarName [ Mu_SFSys::MuIso_StatUp    ] = "MuIso_StatUp";
  m_MuSFVarName [ Mu_SFSys::MuIso_StatDown  ] = "MuIso_StatDown";
  m_MuSFVarName [ Mu_SFSys::MuIso_SysUp     ] = "MuIso_SysUp";
  m_MuSFVarName [ Mu_SFSys::MuIso_SysDown   ] = "MuIso_SysDown";
  m_MuSFVarName [ Mu_SFSys::MuTrg_StatUp    ] = "MuTrg_StatUp";
  m_MuSFVarName [ Mu_SFSys::MuTrg_StatDown  ] = "MuTrg_StatDown";
  m_MuSFVarName [ Mu_SFSys::MuTrg_SysUp     ] = "MuTrg_SysUp";
  m_MuSFVarName [ Mu_SFSys::MuTrg_SysDown   ] = "MuTrg_SysDown";
  m_MuSFVarName [ Mu_SFSys::MuTTVA_StatUp   ] = "MuTTVA_StatUp";
  m_MuSFVarName [ Mu_SFSys::MuTTVA_StatDown ] = "MuTTVA_StatDown";
  m_MuSFVarName [ Mu_SFSys::MuTTVA_SysUp    ] = "MuTTVA_SysUp";
  m_MuSFVarName [ Mu_SFSys::MuTTVA_SysDown  ] = "MuTTVA_SysDown";

  m_MuSHVarName [ Mu_SHSys::MuSmeID_SysUp    ] = "MuSmeID_SysUp";
  m_MuSHVarName [ Mu_SHSys::MuSmeID_SysDown  ] = "MuSmeID_SysDown";
  m_MuSHVarName [ Mu_SHSys::MuSmeMS_SysUp    ] = "MuSmeMS_SysUp";
  m_MuSHVarName [ Mu_SHSys::MuSmeMS_SysDown  ] = "MuSmeMS_SysDown";
  m_MuSHVarName [ Mu_SHSys::MuScale_SysUp    ] = "MuScale_SysUp";
  m_MuSHVarName [ Mu_SHSys::MuScale_SysDown  ] = "MuScale_SysDown";
  m_MuSHVarName [ Mu_SHSys::MuSagRho_SysUp   ] = "MuSagRho_SysUp";
  m_MuSHVarName [ Mu_SHSys::MuSagRho_SysDown ] = "MuSagRho_SysDown";
  m_MuSHVarName [ Mu_SHSys::MuSagRes_SysUp   ] = "MuSagRes_SysUp";
  m_MuSHVarName [ Mu_SHSys::MuSagRes_SysDown ] = "MuSagRes_SysDown";

  m_ElSFVarName [ El_SFSys::ElReco_SysUp    ] = "ElReco_SysUp";
  m_ElSFVarName [ El_SFSys::ElReco_SysDown  ] = "ElReco_SysDown";
  m_ElSFVarName [ El_SFSys::ElID_SysUp      ] = "ElID_SysUp";
  m_ElSFVarName [ El_SFSys::ElID_SysDown    ] = "ElID_SysDown";
  m_ElSFVarName [ El_SFSys::ElIso_SysUp     ] = "ElIso_SysUp";
  m_ElSFVarName [ El_SFSys::ElIso_SysDown   ] = "ElIso_SysDown";
  m_ElSFVarName [ El_SFSys::ElTrg_SysUp     ] = "ElTrg_SysUp";
  m_ElSFVarName [ El_SFSys::ElTrg_SysDown   ] = "ElTrg_SysDown";

  m_ElSHVarName [ El_SHSys::ElSme_SysUp     ] = "ElSme_SysUp";
  m_ElSHVarName [ El_SHSys::ElSme_SysDown   ] = "ElSme_SysDown";
  m_ElSHVarName [ El_SHSys::ElScale_SysUp   ] = "ElScale_SysUp";
  m_ElSHVarName [ El_SHSys::ElScale_SysDown ] = "ElScale_SysDown";

  m_TaSFVarName [ Ta_SFSys::TaReco_SysUp       ] = "TaReco_SysUp";
  m_TaSFVarName [ Ta_SFSys::TaReco_SysDown     ] = "TaReco_SysDown";
  m_TaSFVarName [ Ta_SFSys::TaRecoHpt_SysUp    ] = "TaRecoHpt_SysUp";
  m_TaSFVarName [ Ta_SFSys::TaRecoHpt_SysDown  ] = "TaRecoHpt_SysDown";
  m_TaSFVarName [ Ta_SFSys::TaEleOlr_SysUp     ] = "TaEleOlr_SysUp";
  m_TaSFVarName [ Ta_SFSys::TaEleOlr_SysDown   ] = "TaEleOlr_SysDown";
  m_TaSFVarName [ Ta_SFSys::TaJetID_SysUp      ] = "TaJetID_SysUp";
  m_TaSFVarName [ Ta_SFSys::TaJetID_SysDown    ] = "TaJetID_SysDown";
  m_TaSFVarName [ Ta_SFSys::TaJetIDHpt_SysUp   ] = "TaJetIDHpt_SysUp";
  m_TaSFVarName [ Ta_SFSys::TaJetIDHpt_SysDown ] = "TaJetIDHpt_SysDown";

  m_TaSHVarName [ Ta_SHSys::TaSme_SysUp      ] = "TauSme_SysUp";
  m_TaSHVarName [ Ta_SHSys::TaSme_SysDown    ] = "TauSme_SysDown";
  m_TaSHVarName [ Ta_SHSys::TaSmeDet_SysUp   ] = "TaSmeDet_SysUp";
  m_TaSHVarName [ Ta_SHSys::TaSmeDet_SysDown ] = "TaSmeDet_SysDown";
  m_TaSHVarName [ Ta_SHSys::TaSmeMod_SysUp   ] = "TaSmeMod_SysUp";
  m_TaSHVarName [ Ta_SHSys::TaSmeMod_SysDown ] = "TaSmeMod_SysDown";

  m_JtSFVarName [ Jt_SFSys::JtBeff_SysUp      ] = "JtBeff_SysUp";    
  m_JtSFVarName [ Jt_SFSys::JtBeff_SysDown    ] = "JtBeff_SysDown";  
  m_JtSFVarName [ Jt_SFSys::JtCeff_SysUp      ] = "JtCeff_SysUp";    
  m_JtSFVarName [ Jt_SFSys::JtCeff_SysDown    ] = "JtCeff_SysDown";  
  m_JtSFVarName [ Jt_SFSys::JtLeff_SysUp      ] = "JtLeff_SysUp";    
  m_JtSFVarName [ Jt_SFSys::JtLeff_SysDown    ] = "JtLeff_SysDown";  
  m_JtSFVarName [ Jt_SFSys::JtExtCeff_SysUp   ] = "JtExtCeff_SysUp"; 
  m_JtSFVarName [ Jt_SFSys::JtExtCeff_SysDown ] = "JtExtCeff_SysDown";
  m_JtSFVarName [ Jt_SFSys::JtExtEff_SysUp    ] = "JtExtEff_SysUp";  
  m_JtSFVarName [ Jt_SFSys::JtExtEff_SysDown  ] = "JtExtEff_SysDown";
  m_JtSFVarName [ Jt_SFSys::JtJvt_SysUp       ] = "JtJvt_SysUp";
  m_JtSFVarName [ Jt_SFSys::JtJvt_SysDown     ] = "JtJvt_SysDown";

  m_JtSHVarName [ Jt_SHSys::JtSme_SysUp      ] = "JtSme_SysUp";
  
  m_JtUNVarName [ Jt_UNSys::JtUncNP1_SysUp   ] = "JtUncNP1_SysUp";
  m_JtUNVarName [ Jt_UNSys::JtUncNP1_SysDown ] = "JtUncNP1_SysDown";
  m_JtUNVarName [ Jt_UNSys::JtUncNP2_SysUp   ] = "JtUncNP2_SysUp";
  m_JtUNVarName [ Jt_UNSys::JtUncNP2_SysDown ] = "JtUncNP2_SysDown";
  m_JtUNVarName [ Jt_UNSys::JtUncNP3_SysUp   ] = "JtUncNP3_SysUp";
  m_JtUNVarName [ Jt_UNSys::JtUncNP3_SysDown ] = "JtUncNP3_SysDown";
  m_JtUNVarName [ Jt_UNSys::JtUncETA_SysUp   ] = "JtUncETA_SysUp";
  m_JtUNVarName [ Jt_UNSys::JtUncETA_SysDown ] = "JtUncETA_SysDown";

  m_PuWgtVarName [ Pu_WgtSys::PuWgt_SysUp   ] = "PUwgt_SysUp";
  m_PuWgtVarName [ Pu_WgtSys::PuWgt_SysDown ] = "PUwgt_SysDown";

  m_MetVarName [ Met_SHSys::MetResPara     ] = "MetResPara";
  m_MetVarName [ Met_SHSys::MetResPerp     ] = "MetResPerp";
  m_MetVarName [ Met_SHSys::MetScl_SysUp   ] = "MetScl_SysUp";
  m_MetVarName [ Met_SHSys::MetScl_SysDown ] = "MetScl_SysDown";
    
}

void HighMassLFV :: CreateSystematicsVector(){
  
  m_Systs.push_back( 0 );
  if( m_doSyst ){
    m_Systs.push_back( Mu_SHSys::MuSmeID_SysUp    );
    m_Systs.push_back( Mu_SHSys::MuSmeID_SysDown  );
    m_Systs.push_back( Mu_SHSys::MuSmeMS_SysUp    );
    m_Systs.push_back( Mu_SHSys::MuSmeMS_SysDown  );
    m_Systs.push_back( Mu_SHSys::MuScale_SysUp    );
    m_Systs.push_back( Mu_SHSys::MuScale_SysDown  );
    m_Systs.push_back( Mu_SHSys::MuSagRho_SysUp   );
    m_Systs.push_back( Mu_SHSys::MuSagRho_SysDown );
    m_Systs.push_back( Mu_SHSys::MuSagRes_SysUp   );
    m_Systs.push_back( Mu_SHSys::MuSagRes_SysDown );
    m_Systs.push_back( El_SHSys::ElSme_SysUp      );
    m_Systs.push_back( El_SHSys::ElSme_SysDown    );
    m_Systs.push_back( El_SHSys::ElScale_SysUp    );
    m_Systs.push_back( El_SHSys::ElScale_SysDown  );
    m_Systs.push_back( Ta_SHSys::TaSme_SysUp      );
    m_Systs.push_back( Ta_SHSys::TaSme_SysDown    );
    m_Systs.push_back( Ta_SHSys::TaSmeDet_SysUp   );
    m_Systs.push_back( Ta_SHSys::TaSmeDet_SysDown );
    m_Systs.push_back( Ta_SHSys::TaSmeMod_SysUp   );
    m_Systs.push_back( Ta_SHSys::TaSmeMod_SysDown );
    m_Systs.push_back( Jt_SHSys::JtSme_SysUp      );
    m_Systs.push_back( Jt_UNSys::JtUncNP1_SysUp   );
    m_Systs.push_back( Jt_UNSys::JtUncNP1_SysDown );
    m_Systs.push_back( Jt_UNSys::JtUncNP2_SysUp   );
    m_Systs.push_back( Jt_UNSys::JtUncNP2_SysDown );
    m_Systs.push_back( Jt_UNSys::JtUncNP3_SysUp   );
    m_Systs.push_back( Jt_UNSys::JtUncNP3_SysDown );
    m_Systs.push_back( Jt_UNSys::JtUncETA_SysUp   );
    m_Systs.push_back( Jt_UNSys::JtUncETA_SysDown );
    m_Systs.push_back( Met_SHSys::MetResPara      );
    m_Systs.push_back( Met_SHSys::MetResPerp      );
    m_Systs.push_back( Met_SHSys::MetScl_SysUp    );
    m_Systs.push_back( Met_SHSys::MetScl_SysDown  );
  }
  Info( "CreateSystematicsVector()", "Systematics Variation vector initialized!" );
  
}

void HighMassLFV :: PrintSystematics(){
  
  Info( "PrintSystematics()", "-------------------------------" );

  m_recSysSet[ "PileUp Syst."     ] = m_puTool->recommendedSystematics();
  m_recSysSet[ "Mu Smear Syst."   ] = m_muSmear2016->recommendedSystematics();
  m_recSysSet[ "Mu RecoSF Syst."  ] = m_muRecoSF->recommendedSystematics();
  m_recSysSet[ "Mu TrigSF Syst."  ] = m_muTrigSF->recommendedSystematics();
  m_recSysSet[ "Mu IsoSF Syst."   ] = m_muIsoSF->recommendedSystematics();
  m_recSysSet[ "Mu TTVASF Syst."  ] = m_muTTVASF->recommendedSystematics();
  m_recSysSet[ "El Smear Syst."   ] = m_elSmear->recommendedSystematics();
  m_recSysSet[ "El RecoSF Syst."  ] = m_elRecoSF->recommendedSystematics();
  m_recSysSet[ "El IDSF Syst."    ] = m_elIDSF_Tig->recommendedSystematics();
  m_recSysSet[ "El TrigSF Syst."  ] = m_elTrigSF_Tig->recommendedSystematics();
  m_recSysSet[ "El IsoSF Syst."   ] = m_elIsoSF_Tig->recommendedSystematics();
  m_recSysSet[ "Tau Smear Syst."  ] = m_tauSmear->recommendedSystematics();
  m_recSysSet[ "Tau RecoSF Syst." ] = m_tauRecoSF->recommendedSystematics();
  m_recSysSet[ "Tau IDSF Syst."   ] = m_tauJetIDSF->recommendedSystematics();
  m_recSysSet[ "Tau ElORSF Syst." ] = m_tauElOlrSF->recommendedSystematics();
  m_recSysSet[ "Jet Resol. Syst." ] = m_jetSmear->recommendedSystematics();
  m_recSysSet[ "Jet JvtSF Syst."  ] = m_jetJvtSF->recommendedSystematics();
  m_recSysSet[ "Jet Uncer. Syst." ] = m_jetUnc->recommendedSystematics();
  m_recSysSet[ "Jet btagSF Syst." ] = m_btagSF->recommendedSystematics();
  m_recSysSet[ "MET Syst."        ] = m_metSys->recommendedSystematics();
  
  std::map<std::string, CP::SystematicSet>::iterator source = m_recSysSet.begin();
  for(; source != m_recSysSet.end(); source++) {
    
    std::vector< CP::SystematicSet > sysList;
    for( CP::SystematicSet::const_iterator sysItr = source->second.begin(); sysItr != source->second.end(); ++sysItr ) {
      sysList.push_back( CP::SystematicSet() );
      sysList.back().insert( *sysItr );
    }
    std::vector< CP::SystematicSet >::const_iterator sysListItr;
    for( sysListItr = sysList.begin(); sysListItr != sysList.end(); ++sysListItr ) {
      Info( "PrintSystematics()", " %s ---> %s ", source->first.c_str(), sysListItr->name().c_str() );
      
    }
    Info( "PrintSystematics()", "   " );
    
  }
  
  Info( "PrintSystematics()", "-------------------------------" );
  
}
