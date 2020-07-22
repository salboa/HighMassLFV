#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: DefineHistograms(){
  
  TH1::SetDefaultSumw2(kTRUE);
  
  /* MC INFO */
  MCInfo = new TH1F("MCInfo", "MCInfo", 5, 0, 5);
  
  /* EventFlow histos */
  EMU_EventFlow    = new TH1F( "EMU_EventFlow"   , "EMU Event CutFlow"   , m_EvtFlowBins, 0, m_EvtFlowBins );
  ETAU_EventFlow   = new TH1F( "ETAU_EventFlow"  , "ETAU Event CutFlow"  , m_EvtFlowBins, 0, m_EvtFlowBins );
  MUTAU_EventFlow  = new TH1F( "MUTAU_EventFlow" , "MUTAU Event CutFlow" , m_EvtFlowBins, 0, m_EvtFlowBins );
  if( m_doSyst ){
    EMU_EventFlow_MuSmeID_SysUp    = new TH1F( "EMU_EventFlow_MuSmeID_SysUp"    , "EMU Event CutFlow systematic MuSmeID_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuSmeID_SysDown  = new TH1F( "EMU_EventFlow_MuSmeID_SysDown"  , "EMU Event CutFlow systematic MuSmeID_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuSmeMS_SysUp    = new TH1F( "EMU_EventFlow_MuSmeMS_SysUp"    , "EMU Event CutFlow systematic MuSmeMS_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuSmeMS_SysDown  = new TH1F( "EMU_EventFlow_MuSmeMS_SysDown"  , "EMU Event CutFlow systematic MuSmeMS_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuScale_SysUp    = new TH1F( "EMU_EventFlow_MuScale_SysUp"    , "EMU Event CutFlow systematic MuScale_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuScale_SysDown  = new TH1F( "EMU_EventFlow_MuScale_SysDown"  , "EMU Event CutFlow systematic MuScale_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuSagRho_SysUp   = new TH1F( "EMU_EventFlow_MuSagRho_SysUp"   , "EMU Event CutFlow systematic MuSagRho_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuSagRho_SysDown = new TH1F( "EMU_EventFlow_MuSagRho_SysDown" , "EMU Event CutFlow systematic MuSagRho_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuSagRes_SysUp   = new TH1F( "EMU_EventFlow_MuSagRes_SysUp"   , "EMU Event CutFlow systematic MuSagRes_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MuSagRes_SysDown = new TH1F( "EMU_EventFlow_MuSagRes_SysDown" , "EMU Event CutFlow systematic MuSagRes_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_ElSme_SysUp      = new TH1F( "EMU_EventFlow_ElSme_SysUp"      , "EMU Event CutFlow systematic ElSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_ElSme_SysDown    = new TH1F( "EMU_EventFlow_ElSme_SysDown"    , "EMU Event CutFlow systematic ElSme_SysDown"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_ElScale_SysUp    = new TH1F( "EMU_EventFlow_ElScale_SysUp"    , "EMU Event CutFlow systematic ElScale_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_ElScale_SysDown  = new TH1F( "EMU_EventFlow_ElScale_SysDown"  , "EMU Event CutFlow systematic MuScale_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_TaSme_SysUp      = new TH1F( "EMU_EventFlow_TaSme_SysUp"      , "EMU Event CutFlow systematic TaSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_TaSme_SysDown    = new TH1F( "EMU_EventFlow_TaSme_SysDown"    , "EMU Event CutFlow systematic TaSme_SysDown"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_TaSmeDet_SysUp   = new TH1F( "EMU_EventFlow_TaSmeDet_SysUp"   , "EMU Event CutFlow systematic TaSmeDet_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_TaSmeDet_SysDown = new TH1F( "EMU_EventFlow_TaSmeDet_SysDown" , "EMU Event CutFlow systematic TaSmeDet_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_TaSmeMod_SysUp   = new TH1F( "EMU_EventFlow_TaSmeMod_SysUp"   , "EMU Event CutFlow systematic TaSmeMod_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_TaSmeMod_SysDown = new TH1F( "EMU_EventFlow_TaSmeMod_SysDown" , "EMU Event CutFlow systematic TaSmeMod_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtSme_SysUp      = new TH1F( "EMU_EventFlow_JtSme_SysUp"      , "EMU Event CutFlow systematic JtSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncNP1_SysUp   = new TH1F( "EMU_EventFlow_JtUncNP1_SysUp"   , "EMU Event CutFlow systematic JtUncNP1_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncNP1_SysDown = new TH1F( "EMU_EventFlow_JtUncNP1_SysDown" , "EMU Event CutFlow systematic JtUncNP1_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncNP2_SysUp   = new TH1F( "EMU_EventFlow_JtUncNP2_SysUp"   , "EMU Event CutFlow systematic JtUncNP2_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncNP2_SysDown = new TH1F( "EMU_EventFlow_JtUncNP2_SysDown" , "EMU Event CutFlow systematic JtUncNP2_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncNP3_SysUp   = new TH1F( "EMU_EventFlow_JtUncNP3_SysUp"   , "EMU Event CutFlow systematic JtUncNP3_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncNP3_SysDown = new TH1F( "EMU_EventFlow_JtUncNP3_SysDown" , "EMU Event CutFlow systematic JtUncNP3_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncETA_SysUp   = new TH1F( "EMU_EventFlow_JtUncETA_SysUp"   , "EMU Event CutFlow systematic JtUncETA_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_JtUncETA_SysDown = new TH1F( "EMU_EventFlow_JtUncETA_SysDown" , "EMU Event CutFlow systematic JtUncETA_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MetResPara       = new TH1F( "EMU_EventFlow_MetResPara"       , "EMU Event CutFlow systematic MetResPara    "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MetResPerp       = new TH1F( "EMU_EventFlow_MetResPerp"       , "EMU Event CutFlow systematic MetResPerp    "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MetScl_SysUp     = new TH1F( "EMU_EventFlow_MetScl_SysUp"     , "EMU Event CutFlow systematic MetScl_SysUp  "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    EMU_EventFlow_MetScl_SysDown   = new TH1F( "EMU_EventFlow_MetScl_SysDown"   , "EMU Event CutFlow systematic MetScl_SysDown"   , m_EvtFlowBins, 0, m_EvtFlowBins );

    ETAU_EventFlow_MuSmeID_SysUp    = new TH1F( "ETAU_EventFlow_MuSmeID_SysUp"    , "ETAU Event CutFlow systematic MuSmeID_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuSmeID_SysDown  = new TH1F( "ETAU_EventFlow_MuSmeID_SysDown"  , "ETAU Event CutFlow systematic MuSmeID_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuSmeMS_SysUp    = new TH1F( "ETAU_EventFlow_MuSmeMS_SysUp"    , "ETAU Event CutFlow systematic MuSmeMS_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuSmeMS_SysDown  = new TH1F( "ETAU_EventFlow_MuSmeMS_SysDown"  , "ETAU Event CutFlow systematic MuSmeMS_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuScale_SysUp    = new TH1F( "ETAU_EventFlow_MuScale_SysUp"    , "ETAU Event CutFlow systematic MuScale_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuScale_SysDown  = new TH1F( "ETAU_EventFlow_MuScale_SysDown"  , "ETAU Event CutFlow systematic MuScale_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuSagRho_SysUp   = new TH1F( "ETAU_EventFlow_MuSagRho_SysUp"   , "ETAU Event CutFlow systematic MuSagRho_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuSagRho_SysDown = new TH1F( "ETAU_EventFlow_MuSagRho_SysDown" , "ETAU Event CutFlow systematic MuSagRho_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuSagRes_SysUp   = new TH1F( "ETAU_EventFlow_MuSagRes_SysUp"   , "ETAU Event CutFlow systematic MuSagRes_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MuSagRes_SysDown = new TH1F( "ETAU_EventFlow_MuSagRes_SysDown" , "ETAU Event CutFlow systematic MuSagRes_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_ElSme_SysUp      = new TH1F( "ETAU_EventFlow_ElSme_SysUp"      , "ETAU Event CutFlow systematic ElSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_ElSme_SysDown    = new TH1F( "ETAU_EventFlow_ElSme_SysDown"    , "ETAU Event CutFlow systematic ElSme_SysDown"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_ElScale_SysUp    = new TH1F( "ETAU_EventFlow_ElScale_SysUp"    , "ETAU Event CutFlow systematic ElScale_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_ElScale_SysDown  = new TH1F( "ETAU_EventFlow_ElScale_SysDown"  , "ETAU Event CutFlow systematic MuScale_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_TaSme_SysUp      = new TH1F( "ETAU_EventFlow_TaSme_SysUp"      , "ETAU Event CutFlow systematic TaSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_TaSme_SysDown    = new TH1F( "ETAU_EventFlow_TaSme_SysDown"    , "ETAU Event CutFlow systematic TaSme_SysDown"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtSme_SysUp      = new TH1F( "ETAU_EventFlow_JtSme_SysUp"      , "ETAU Event CutFlow systematic JtSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_TaSmeDet_SysUp   = new TH1F( "ETAU_EventFlow_TaSmeDet_SysUp"   , "ETAY Event CutFlow systematic TaSmeDet_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_TaSmeDet_SysDown = new TH1F( "ETAU_EventFlow_TaSmeDet_SysDown" , "ETAY Event CutFlow systematic TaSmeDet_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_TaSmeMod_SysUp   = new TH1F( "ETAU_EventFlow_TaSmeMod_SysUp"   , "ETAY Event CutFlow systematic TaSmeMod_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_TaSmeMod_SysDown = new TH1F( "ETAU_EventFlow_TaSmeMod_SysDown" , "ETAY Event CutFlow systematic TaSmeMod_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncNP1_SysUp   = new TH1F( "ETAU_EventFlow_JtUncNP1_SysUp"   , "ETAU Event CutFlow systematic JtUncNP1_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncNP1_SysDown = new TH1F( "ETAU_EventFlow_JtUncNP1_SysDown" , "ETAU Event CutFlow systematic JtUncNP1_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncNP2_SysUp   = new TH1F( "ETAU_EventFlow_JtUncNP2_SysUp"   , "ETAU Event CutFlow systematic JtUncNP2_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncNP2_SysDown = new TH1F( "ETAU_EventFlow_JtUncNP2_SysDown" , "ETAU Event CutFlow systematic JtUncNP2_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncNP3_SysUp   = new TH1F( "ETAU_EventFlow_JtUncNP3_SysUp"   , "ETAU Event CutFlow systematic JtUncNP3_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncNP3_SysDown = new TH1F( "ETAU_EventFlow_JtUncNP3_SysDown" , "ETAU Event CutFlow systematic JtUncNP3_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncETA_SysUp   = new TH1F( "ETAU_EventFlow_JtUncETA_SysUp"   , "ETAU Event CutFlow systematic JtUncETA_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_JtUncETA_SysDown = new TH1F( "ETAU_EventFlow_JtUncETA_SysDown" , "ETAU Event CutFlow systematic JtUncETA_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MetResPara       = new TH1F( "ETAU_EventFlow_MetResPara"       , "ETAU Event CutFlow systematic MetResPara    "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MetResPerp       = new TH1F( "ETAU_EventFlow_MetResPerp"       , "ETAU Event CutFlow systematic MetResPerp    "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MetScl_SysUp     = new TH1F( "ETAU_EventFlow_MetScl_SysUp"     , "ETAU Event CutFlow systematic MetScl_SysUp  "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    ETAU_EventFlow_MetScl_SysDown   = new TH1F( "ETAU_EventFlow_MetScl_SysDown"   , "ETAU Event CutFlow systematic MetScl_SysDown"   , m_EvtFlowBins, 0, m_EvtFlowBins );

    MUTAU_EventFlow_MuSmeID_SysUp    = new TH1F( "MUTAU_EventFlow_MuSmeID_SysUp"    , "MUTAU Event CutFlow systematic MuSmeID_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuSmeID_SysDown  = new TH1F( "MUTAU_EventFlow_MuSmeID_SysDown"  , "MUTAU Event CutFlow systematic MuSmeID_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuSmeMS_SysUp    = new TH1F( "MUTAU_EventFlow_MuSmeMS_SysUp"    , "MUTAU Event CutFlow systematic MuSmeMS_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuSmeMS_SysDown  = new TH1F( "MUTAU_EventFlow_MuSmeMS_SysDown"  , "MUTAU Event CutFlow systematic MuSmeMS_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuScale_SysUp    = new TH1F( "MUTAU_EventFlow_MuScale_SysUp"    , "MUTAU Event CutFlow systematic MuScale_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuScale_SysDown  = new TH1F( "MUTAU_EventFlow_MuScale_SysDown"  , "MUTAU Event CutFlow systematic MuScale_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuSagRho_SysUp   = new TH1F( "MUTAU_EventFlow_MuSagRho_SysUp"   , "MUTAU Event CutFlow systematic MuSagRho_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuSagRho_SysDown = new TH1F( "MUTAU_EventFlow_MuSagRho_SysDown" , "MUTAU Event CutFlow systematic MuSagRho_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuSagRes_SysUp   = new TH1F( "MUTAU_EventFlow_MuSagRes_SysUp"   , "MUTAU Event CutFlow systematic MuSagRes_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MuSagRes_SysDown = new TH1F( "MUTAU_EventFlow_MuSagRes_SysDown" , "MUTAU Event CutFlow systematic MuSagRes_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_ElSme_SysUp      = new TH1F( "MUTAU_EventFlow_ElSme_SysUp"      , "MUTAU Event CutFlow systematic ElSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_ElSme_SysDown    = new TH1F( "MUTAU_EventFlow_ElSme_SysDown"    , "MUTAU Event CutFlow systematic ElSme_SysDown"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_ElScale_SysUp    = new TH1F( "MUTAU_EventFlow_ElScale_SysUp"    , "MUTAU Event CutFlow systematic ElScale_SysUp"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_ElScale_SysDown  = new TH1F( "MUTAU_EventFlow_ElScale_SysDown"  , "MUTAU Event CutFlow systematic MuScale_SysDown"  , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_TaSme_SysUp      = new TH1F( "MUTAU_EventFlow_TaSme_SysUp"      , "MUTAU Event CutFlow systematic TaSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_TaSme_SysDown    = new TH1F( "MUTAU_EventFlow_TaSme_SysDown"    , "MUTAU Event CutFlow systematic TaSme_SysDown"    , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_TaSmeDet_SysUp   = new TH1F( "MUTAU_EventFlow_TaSmeDet_SysUp"   , "MUTAU Event CutFlow systematic TaSmeDet_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_TaSmeDet_SysDown = new TH1F( "MUTAU_EventFlow_TaSmeDet_SysDown" , "MUTAU Event CutFlow systematic TaSmeDet_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_TaSmeMod_SysUp   = new TH1F( "MUTAU_EventFlow_TaSmeMod_SysUp"   , "MUTAU Event CutFlow systematic TaSmeMod_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_TaSmeMod_SysDown = new TH1F( "MUTAU_EventFlow_TaSmeMod_SysDown" , "MUTAU Event CutFlow systematic TaSmeMod_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtSme_SysUp      = new TH1F( "MUTAU_EventFlow_JtSme_SysUp"      , "MUTAU Event CutFlow systematic JtSme_SysUp"      , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncNP1_SysUp   = new TH1F( "MUTAU_EventFlow_JtUncNP1_SysUp"   , "MUTAU Event CutFlow systematic JtUncNP1_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncNP1_SysDown = new TH1F( "MUTAU_EventFlow_JtUncNP1_SysDown" , "MUTAU Event CutFlow systematic JtUncNP1_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncNP2_SysUp   = new TH1F( "MUTAU_EventFlow_JtUncNP2_SysUp"   , "MUTAU Event CutFlow systematic JtUncNP2_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncNP2_SysDown = new TH1F( "MUTAU_EventFlow_JtUncNP2_SysDown" , "MUTAU Event CutFlow systematic JtUncNP2_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncNP3_SysUp   = new TH1F( "MUTAU_EventFlow_JtUncNP3_SysUp"   , "MUTAU Event CutFlow systematic JtUncNP3_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncNP3_SysDown = new TH1F( "MUTAU_EventFlow_JtUncNP3_SysDown" , "MUTAU Event CutFlow systematic JtUncNP3_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncETA_SysUp   = new TH1F( "MUTAU_EventFlow_JtUncETA_SysUp"   , "MUTAU Event CutFlow systematic JtUncETA_SysUp"   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_JtUncETA_SysDown = new TH1F( "MUTAU_EventFlow_JtUncETA_SysDown" , "MUTAU Event CutFlow systematic JtUncETA_SysDown" , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MetResPara       = new TH1F( "MUTAU_EventFlow_MetResPara"       , "MUTAU Event CutFlow systematic MetResPara    "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MetResPerp       = new TH1F( "MUTAU_EventFlow_MetResPerp"       , "MUTAU Event CutFlow systematic MetResPerp    "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MetScl_SysUp     = new TH1F( "MUTAU_EventFlow_MetScl_SysUp"     , "MUTAU Event CutFlow systematic MetScl_SysUp  "   , m_EvtFlowBins, 0, m_EvtFlowBins );
    MUTAU_EventFlow_MetScl_SysDown   = new TH1F( "MUTAU_EventFlow_MetScl_SysDown"   , "MUTAU Event CutFlow systematic MetScl_SysDown"   , m_EvtFlowBins, 0, m_EvtFlowBins );

  }

  /* MuonFlow histos */
  MuonFlow     = new TH1F( "MuonFlow"    , "Muon CutFlow"    , m_MuFlowBins , 0, m_MuFlowBins  );
  if( m_doSyst ){
    MuonFlow_MuSmeID_SysUp    = new TH1F( "MuonFlow_MuSmeID_SysUp"    , "Muon CutFlow systematic MuSmeID_SysUp"    , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuSmeID_SysDown  = new TH1F( "MuonFlow_MuSmeID_SysDown"  , "Muon CutFlow systematic MuSmeID_SysDown"  , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuSmeMS_SysUp    = new TH1F( "MuonFlow_MuSmeMS_SysUp"    , "Muon CutFlow systematic MuSmeMS_SysUp"    , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuSmeMS_SysDown  = new TH1F( "MuonFlow_MuSmeMS_SysDown"  , "Muon CutFlow systematic MuSmeMS_SysDown"  , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuScale_SysUp    = new TH1F( "MuonFlow_MuScale_SysUp"    , "Muon CutFlow systematic MuScale_SysUp"    , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuScale_SysDown  = new TH1F( "MuonFlow_MuScale_SysDown"  , "Muon CutFlow systematic MuScale_SysDown"  , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuSagRho_SysUp   = new TH1F( "MuonFlow_MuSagRho_SysUp"   , "Muon CutFlow systematic MuSagRho_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuSagRho_SysDown = new TH1F( "MuonFlow_MuSagRho_SysDown" , "Muon CutFlow systematic MuSagRho_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuSagRes_SysUp   = new TH1F( "MuonFlow_MuSagRes_SysUp"   , "Muon CutFlow systematic MuSagRes_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MuSagRes_SysDown = new TH1F( "MuonFlow_MuSagRes_SysDown" , "Muon CutFlow systematic MuSagRes_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_ElSme_SysUp      = new TH1F( "MuonFlow_ElSme_SysUp"      , "Muon CutFlow systematic ElSme_SysUp"      , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_ElSme_SysDown    = new TH1F( "MuonFlow_ElSme_SysDown"    , "Muon CutFlow systematic ElSme_SysDown"    , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_ElScale_SysUp    = new TH1F( "MuonFlow_ElScale_SysUp"    , "Muon CutFlow systematic ElScale_SysUp"    , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_ElScale_SysDown  = new TH1F( "MuonFlow_ElScale_SysDown"  , "Muon CutFlow systematic MuScale_SysDown"  , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_TaSme_SysUp      = new TH1F( "MuonFlow_TaSme_SysUp"      , "Muon CutFlow systematic TaSme_SysUp"      , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_TaSme_SysDown    = new TH1F( "MuonFlow_TaSme_SysDown"    , "Muon CutFlow systematic TaSme_SysDown"    , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_TaSmeDet_SysUp   = new TH1F( "MuonFlow_TaSmeDet_SysUp"   , "Muon CutFlow systematic TaSmeDet_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_TaSmeDet_SysDown = new TH1F( "MuonFlow_TaSmeDet_SysDown" , "Muon CutFlow systematic TaSmeDet_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_TaSmeMod_SysUp   = new TH1F( "MuonFlow_TaSmeMod_SysUp"   , "Muon CutFlow systematic TaSmeMod_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_TaSmeMod_SysDown = new TH1F( "MuonFlow_TaSmeMod_SysDown" , "Muon CutFlow systematic TaSmeMod_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtSme_SysUp      = new TH1F( "MuonFlow_JtSme_SysUp"      , "Muon CutFlow systematic JtSme_SysUp"      , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncNP1_SysUp   = new TH1F( "MuonFlow_JtUncNP1_SysUp"   , "Muon CutFlow systematic JtUncNP1_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncNP1_SysDown = new TH1F( "MuonFlow_JtUncNP1_SysDown" , "Muon CutFlow systematic JtUncNP1_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncNP2_SysUp   = new TH1F( "MuonFlow_JtUncNP2_SysUp"   , "Muon CutFlow systematic JtUncNP2_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncNP2_SysDown = new TH1F( "MuonFlow_JtUncNP2_SysDown" , "Muon CutFlow systematic JtUncNP2_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncNP3_SysUp   = new TH1F( "MuonFlow_JtUncNP3_SysUp"   , "Muon CutFlow systematic JtUncNP3_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncNP3_SysDown = new TH1F( "MuonFlow_JtUncNP3_SysDown" , "Muon CutFlow systematic JtUncNP3_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncETA_SysUp   = new TH1F( "MuonFlow_JtUncETA_SysUp"   , "Muon CutFlow systematic JtUncETA_SysUp"   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_JtUncETA_SysDown = new TH1F( "MuonFlow_JtUncETA_SysDown" , "Muon CutFlow systematic JtUncETA_SysDown" , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MetResPara       = new TH1F( "MuonFlow_MetResPara"       , "Muon CutFlow systematic MetResPara    "   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MetResPerp       = new TH1F( "MuonFlow_MetResPerp"       , "Muon CutFlow systematic MetResPerp    "   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MetScl_SysUp     = new TH1F( "MuonFlow_MetScl_SysUp"     , "Muon CutFlow systematic MetScl_SysUp  "   , m_MuFlowBins, 0, m_MuFlowBins );
    MuonFlow_MetScl_SysDown   = new TH1F( "MuonFlow_MetScl_SysDown"   , "Muon CutFlow systematic MetScl_SysDown"   , m_MuFlowBins, 0, m_MuFlowBins );
  }

  /* ElectronFlow histos */
  ElectronFlow = new TH1F( "ElectronFlow", "Electron CutFlow", m_ElFlowBins , 0, m_ElFlowBins  );
  if( m_doSyst ){
    ElectronFlow_MuSmeID_SysUp    = new TH1F( "ElectronFlow_MuSmeID_SysUp"    , "Electron CutFlow systematic MuSmeID_SysUp"    , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuSmeID_SysDown  = new TH1F( "ElectronFlow_MuSmeID_SysDown"  , "Electron CutFlow systematic MuSmeID_SysDown"  , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuSmeMS_SysUp    = new TH1F( "ElectronFlow_MuSmeMS_SysUp"    , "Electron CutFlow systematic MuSmeMS_SysUp"    , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuSmeMS_SysDown  = new TH1F( "ElectronFlow_MuSmeMS_SysDown"  , "Electron CutFlow systematic MuSmeMS_SysDown"  , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuScale_SysUp    = new TH1F( "ElectronFlow_MuScale_SysUp"    , "Electron CutFlow systematic MuScale_SysUp"    , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuScale_SysDown  = new TH1F( "ElectronFlow_MuScale_SysDown"  , "Electron CutFlow systematic MuScale_SysDown"  , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuSagRho_SysUp   = new TH1F( "ElectronFlow_MuSagRho_SysUp"   , "Electron CutFlow systematic MuSagRho_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuSagRho_SysDown = new TH1F( "ElectronFlow_MuSagRho_SysDown" , "Electron CutFlow systematic MuSagRho_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuSagRes_SysUp   = new TH1F( "ElectronFlow_MuSagRes_SysUp"   , "Electron CutFlow systematic MuSagRes_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MuSagRes_SysDown = new TH1F( "ElectronFlow_MuSagRes_SysDown" , "Electron CutFlow systematic MuSagRes_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_ElSme_SysUp      = new TH1F( "ElectronFlow_ElSme_SysUp"      , "Electron CutFlow systematic ElSme_SysUp"      , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_ElSme_SysDown    = new TH1F( "ElectronFlow_ElSme_SysDown"    , "Electron CutFlow systematic ElSme_SysDown"    , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_ElScale_SysUp    = new TH1F( "ElectronFlow_ElScale_SysUp"    , "Electron CutFlow systematic ElScale_SysUp"    , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_ElScale_SysDown  = new TH1F( "ElectronFlow_ElScale_SysDown"  , "Electron CutFlow systematic MuScale_SysDown"  , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_TaSme_SysUp      = new TH1F( "ElectronFlow_TaSme_SysUp"      , "Electron CutFlow systematic TaSme_SysUp"      , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_TaSme_SysDown    = new TH1F( "ElectronFlow_TaSme_SysDown"    , "Electron CutFlow systematic TaSme_SysDown"    , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_TaSmeDet_SysUp   = new TH1F( "ElectronFlow_TaSmeDet_SysUp"   , "Electron CutFlow systematic TaSmeDet_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_TaSmeDet_SysDown = new TH1F( "ElectronFlow_TaSmeDet_SysDown" , "Electron CutFlow systematic TaSmeDet_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_TaSmeMod_SysUp   = new TH1F( "ElectronFlow_TaSmeMod_SysUp"   , "Electron CutFlow systematic TaSmeMod_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_TaSmeMod_SysDown = new TH1F( "ElectronFlow_TaSmeMod_SysDown" , "Electron CutFlow systematic TaSmeMod_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtSme_SysUp      = new TH1F( "ElectronFlow_JtSme_SysUp"      , "Electron CutFlow systematic JtSme_SysUp"      , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncNP1_SysUp   = new TH1F( "ElectronFlow_JtUncNP1_SysUp"   , "Electron CutFlow systematic JtUncNP1_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncNP1_SysDown = new TH1F( "ElectronFlow_JtUncNP1_SysDown" , "Electron CutFlow systematic JtUncNP1_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncNP2_SysUp   = new TH1F( "ElectronFlow_JtUncNP2_SysUp"   , "Electron CutFlow systematic JtUncNP2_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncNP2_SysDown = new TH1F( "ElectronFlow_JtUncNP2_SysDown" , "Electron CutFlow systematic JtUncNP2_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncNP3_SysUp   = new TH1F( "ElectronFlow_JtUncNP3_SysUp"   , "Electron CutFlow systematic JtUncNP3_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncNP3_SysDown = new TH1F( "ElectronFlow_JtUncNP3_SysDown" , "Electron CutFlow systematic JtUncNP3_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncETA_SysUp   = new TH1F( "ElectronFlow_JtUncETA_SysUp"   , "Electron CutFlow systematic JtUncETA_SysUp"   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_JtUncETA_SysDown = new TH1F( "ElectronFlow_JtUncETA_SysDown" , "Electron CutFlow systematic JtUncETA_SysDown" , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MetResPara       = new TH1F( "ElectronFlow_MetResPara"       , "Electron CutFlow systematic MetResPara    "   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MetResPerp       = new TH1F( "ElectronFlow_MetResPerp"       , "Electron CutFlow systematic MetResPerp    "   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MetScl_SysUp     = new TH1F( "ElectronFlow_MetScl_SysUp"     , "Electron CutFlow systematic MetScl_SysUp  "   , m_ElFlowBins, 0, m_ElFlowBins );
    ElectronFlow_MetScl_SysDown   = new TH1F( "ElectronFlow_MetScl_SysDown"   , "Electron CutFlow systematic MetScl_SysDown"   , m_ElFlowBins, 0, m_ElFlowBins );
  }

  /* TauFlow histos */
  TauFlow = new TH1F( "TauFlow", "Tau CutFlow", m_ElFlowBins , 0, m_ElFlowBins  );
  if( m_doSyst ){
    TauFlow_MuSmeID_SysUp    = new TH1F( "TauFlow_MuSmeID_SysUp"    , "Tau CutFlow systematic MuSmeID_SysUp"    , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuSmeID_SysDown  = new TH1F( "TauFlow_MuSmeID_SysDown"  , "Tau CutFlow systematic MuSmeID_SysDown"  , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuSmeMS_SysUp    = new TH1F( "TauFlow_MuSmeMS_SysUp"    , "Tau CutFlow systematic MuSmeMS_SysUp"    , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuSmeMS_SysDown  = new TH1F( "TauFlow_MuSmeMS_SysDown"  , "Tau CutFlow systematic MuSmeMS_SysDown"  , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuScale_SysUp    = new TH1F( "TauFlow_MuScale_SysUp"    , "Tau CutFlow systematic MuScale_SysUp"    , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuScale_SysDown  = new TH1F( "TauFlow_MuScale_SysDown"  , "Tau CutFlow systematic MuScale_SysDown"  , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuSagRho_SysUp   = new TH1F( "TauFlow_MuSagRho_SysUp"   , "Tau CutFlow systematic MuSagRho_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuSagRho_SysDown = new TH1F( "TauFlow_MuSagRho_SysDown" , "Tau CutFlow systematic MuSagRho_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuSagRes_SysUp   = new TH1F( "TauFlow_MuSagRes_SysUp"   , "Tau CutFlow systematic MuSagRes_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MuSagRes_SysDown = new TH1F( "TauFlow_MuSagRes_SysDown" , "Tau CutFlow systematic MuSagRes_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_ElSme_SysUp      = new TH1F( "TauFlow_ElSme_SysUp"      , "Tau CutFlow systematic ElSme_SysUp"      , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_ElSme_SysDown    = new TH1F( "TauFlow_ElSme_SysDown"    , "Tau CutFlow systematic ElSme_SysDown"    , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_ElScale_SysUp    = new TH1F( "TauFlow_ElScale_SysUp"    , "Tau CutFlow systematic ElScale_SysUp"    , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_ElScale_SysDown  = new TH1F( "TauFlow_ElScale_SysDown"  , "Tau CutFlow systematic MuScale_SysDown"  , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_TaSme_SysUp      = new TH1F( "TauFlow_TaSme_SysUp"      , "Tau CutFlow systematic TaSme_SysUp"      , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_TaSme_SysDown    = new TH1F( "TauFlow_TaSme_SysDown"    , "Tau CutFlow systematic TaSme_SysDown"    , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_TaSmeDet_SysUp   = new TH1F( "TauFlow_TaSmeDet_SysUp"   , "Tau CutFlow systematic TaSmeDet_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_TaSmeDet_SysDown = new TH1F( "TauFlow_TaSmeDet_SysDown" , "Tau CutFlow systematic TaSmeDet_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_TaSmeMod_SysUp   = new TH1F( "TauFlow_TaSmeMod_SysUp"   , "Tau CutFlow systematic TaSmeMod_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_TaSmeMod_SysDown = new TH1F( "TauFlow_TaSmeMod_SysDown" , "Tau CutFlow systematic TaSmeMod_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtSme_SysUp      = new TH1F( "TauFlow_JtSme_SysUp"      , "Tau CutFlow systematic JtSme_SysUp"      , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncNP1_SysUp   = new TH1F( "TauFlow_JtUncNP1_SysUp"   , "Tau CutFlow systematic JtUncNP1_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncNP1_SysDown = new TH1F( "TauFlow_JtUncNP1_SysDown" , "Tau CutFlow systematic JtUncNP1_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncNP2_SysUp   = new TH1F( "TauFlow_JtUncNP2_SysUp"   , "Tau CutFlow systematic JtUncNP2_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncNP2_SysDown = new TH1F( "TauFlow_JtUncNP2_SysDown" , "Tau CutFlow systematic JtUncNP2_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncNP3_SysUp   = new TH1F( "TauFlow_JtUncNP3_SysUp"   , "Tau CutFlow systematic JtUncNP3_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncNP3_SysDown = new TH1F( "TauFlow_JtUncNP3_SysDown" , "Tau CutFlow systematic JtUncNP3_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncETA_SysUp   = new TH1F( "TauFlow_JtUncETA_SysUp"   , "Tau CutFlow systematic JtUncETA_SysUp"   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_JtUncETA_SysDown = new TH1F( "TauFlow_JtUncETA_SysDown" , "Tau CutFlow systematic JtUncETA_SysDown" , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MetResPara       = new TH1F( "TauFlow_MetResPara"       , "Tau CutFlow systematic MetResPara    "   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MetResPerp       = new TH1F( "TauFlow_MetResPerp"       , "Tau CutFlow systematic MetResPerp    "   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MetScl_SysUp     = new TH1F( "TauFlow_MetScl_SysUp"     , "Tau CutFlow systematic MetScl_SysUp  "   , m_TauFlowBins, 0, m_TauFlowBins );
    TauFlow_MetScl_SysDown   = new TH1F( "TauFlow_MetScl_SysDown"   , "Tau CutFlow systematic MetScl_SysDown"   , m_TauFlowBins, 0, m_TauFlowBins );
  }
  
  /* JetFlow histos */
  JetFlow = new TH1F( "JetFlow"     , "Jet CutFlow"     , m_JtFlowBins , 0, m_JtFlowBins  );
  if( m_doSyst ){
    JetFlow_MuSmeID_SysUp    = new TH1F( "JetFlow_MuSmeID_SysUp"    , "Jet CutFlow systematic MuSmeID_SysUp"    , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuSmeID_SysDown  = new TH1F( "JetFlow_MuSmeID_SysDown"  , "Jet CutFlow systematic MuSmeID_SysDown"  , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuSmeMS_SysUp    = new TH1F( "JetFlow_MuSmeMS_SysUp"    , "Jet CutFlow systematic MuSmeMS_SysUp"    , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuSmeMS_SysDown  = new TH1F( "JetFlow_MuSmeMS_SysDown"  , "Jet CutFlow systematic MuSmeMS_SysDown"  , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuScale_SysUp    = new TH1F( "JetFlow_MuScale_SysUp"    , "Jet CutFlow systematic MuScale_SysUp"    , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuScale_SysDown  = new TH1F( "JetFlow_MuScale_SysDown"  , "Jet CutFlow systematic MuScale_SysDown"  , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuSagRho_SysUp   = new TH1F( "JetFlow_MuSagRho_SysUp"   , "Jet CutFlow systematic MuSagRho_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuSagRho_SysDown = new TH1F( "JetFlow_MuSagRho_SysDown" , "Jet CutFlow systematic MuSagRho_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuSagRes_SysUp   = new TH1F( "JetFlow_MuSagRes_SysUp"   , "Jet CutFlow systematic MuSagRes_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MuSagRes_SysDown = new TH1F( "JetFlow_MuSagRes_SysDown" , "Jet CutFlow systematic MuSagRes_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_ElSme_SysUp      = new TH1F( "JetFlow_ElSme_SysUp"      , "Jet CutFlow systematic ElSme_SysUp"      , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_ElSme_SysDown    = new TH1F( "JetFlow_ElSme_SysDown"    , "Jet CutFlow systematic ElSme_SysDown"    , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_ElScale_SysUp    = new TH1F( "JetFlow_ElScale_SysUp"    , "Jet CutFlow systematic ElScale_SysUp"    , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_ElScale_SysDown  = new TH1F( "JetFlow_ElScale_SysDown"  , "Jet CutFlow systematic MuScale_SysDown"  , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_TaSme_SysUp      = new TH1F( "JetFlow_TaSme_SysUp"      , "Jet CutFlow systematic TaSme_SysUp"      , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_TaSme_SysDown    = new TH1F( "JetFlow_TaSme_SysDown"    , "Jet CutFlow systematic TaSme_SysDown"    , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_TaSmeDet_SysUp   = new TH1F( "JetFlow_TaSmeDet_SysUp"   , "Jet CutFlow systematic TaSmeDet_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_TaSmeDet_SysDown = new TH1F( "JetFlow_TaSmeDet_SysDown" , "Jet CutFlow systematic TaSmeDet_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_TaSmeMod_SysUp   = new TH1F( "JetFlow_TaSmeMod_SysUp"   , "Jet CutFlow systematic TaSmeMod_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_TaSmeMod_SysDown = new TH1F( "JetFlow_TaSmeMod_SysDown" , "Jet CutFlow systematic TaSmeMod_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtSme_SysUp      = new TH1F( "JetFlow_JtSme_SysUp"      , "Jet CutFlow systematic JtSme_SysUp"      , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncNP1_SysUp   = new TH1F( "JetFlow_JtUncNP1_SysUp"   , "Jet CutFlow systematic JtUncNP1_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncNP1_SysDown = new TH1F( "JetFlow_JtUncNP1_SysDown" , "Jet CutFlow systematic JtUncNP1_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncNP2_SysUp   = new TH1F( "JetFlow_JtUncNP2_SysUp"   , "Jet CutFlow systematic JtUncNP2_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncNP2_SysDown = new TH1F( "JetFlow_JtUncNP2_SysDown" , "Jet CutFlow systematic JtUncNP2_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncNP3_SysUp   = new TH1F( "JetFlow_JtUncNP3_SysUp"   , "Jet CutFlow systematic JtUncNP3_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncNP3_SysDown = new TH1F( "JetFlow_JtUncNP3_SysDown" , "Jet CutFlow systematic JtUncNP3_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncETA_SysUp   = new TH1F( "JetFlow_JtUncETA_SysUp"   , "Jet CutFlow systematic JtUncETA_SysUp"   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_JtUncETA_SysDown = new TH1F( "JetFlow_JtUncETA_SysDown" , "Jet CutFlow systematic JtUncETA_SysDown" , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MetResPara       = new TH1F( "JetFlow_MetResPara"       , "Jet CutFlow systematic MetResPara    "   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MetResPerp       = new TH1F( "JetFlow_MetResPerp"       , "Jet CutFlow systematic MetResPerp    "   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MetScl_SysUp     = new TH1F( "JetFlow_MetScl_SysUp"     , "Jet CutFlow systematic MetScl_SysUp  "   , m_JtFlowBins, 0, m_JtFlowBins );
    JetFlow_MetScl_SysDown   = new TH1F( "JetFlow_MetScl_SysDown"   , "Jet CutFlow systematic MetScl_SysDown"   , m_JtFlowBins, 0, m_JtFlowBins );
  }

  /* JetFlow histos */
  PhFlow = new TH1F( "PhFlow"     , "Photon CutFlow"     , m_PhFlowBins , 0, m_PhFlowBins  );
  if( m_doSyst ){
    PhFlow_MuSmeID_SysUp    = new TH1F( "PhFlow_MuSmeID_SysUp"    , "Photon CutFlow systematic MuSmeID_SysUp"    , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuSmeID_SysDown  = new TH1F( "PhFlow_MuSmeID_SysDown"  , "Photon CutFlow systematic MuSmeID_SysDown"  , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuSmeMS_SysUp    = new TH1F( "PhFlow_MuSmeMS_SysUp"    , "Photon CutFlow systematic MuSmeMS_SysUp"    , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuSmeMS_SysDown  = new TH1F( "PhFlow_MuSmeMS_SysDown"  , "Photon CutFlow systematic MuSmeMS_SysDown"  , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuScale_SysUp    = new TH1F( "PhFlow_MuScale_SysUp"    , "Photon CutFlow systematic MuScale_SysUp"    , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuScale_SysDown  = new TH1F( "PhFlow_MuScale_SysDown"  , "Photon CutFlow systematic MuScale_SysDown"  , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuSagRho_SysUp   = new TH1F( "PhFlow_MuSagRho_SysUp"   , "Photon CutFlow systematic MuSagRho_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuSagRho_SysDown = new TH1F( "PhFlow_MuSagRho_SysDown" , "Photon CutFlow systematic MuSagRho_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuSagRes_SysUp   = new TH1F( "PhFlow_MuSagRes_SysUp"   , "Photon CutFlow systematic MuSagRes_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MuSagRes_SysDown = new TH1F( "PhFlow_MuSagRes_SysDown" , "Photon CutFlow systematic MuSagRes_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_ElSme_SysUp      = new TH1F( "PhFlow_ElSme_SysUp"      , "Photon CutFlow systematic ElSme_SysUp"      , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_ElSme_SysDown    = new TH1F( "PhFlow_ElSme_SysDown"    , "Photon CutFlow systematic ElSme_SysDown"    , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_ElScale_SysUp    = new TH1F( "PhFlow_ElScale_SysUp"    , "Photon CutFlow systematic ElScale_SysUp"    , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_ElScale_SysDown  = new TH1F( "PhFlow_ElScale_SysDown"  , "Photon CutFlow systematic MuScale_SysDown"  , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_TaSme_SysUp      = new TH1F( "PhFlow_TaSme_SysUp"      , "Photon CutFlow systematic TaSme_SysUp"      , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_TaSme_SysDown    = new TH1F( "PhFlow_TaSme_SysDown"    , "Photon CutFlow systematic TaSme_SysDown"    , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_TaSmeDet_SysUp   = new TH1F( "PhFlow_TaSmeDet_SysUp"   , "Photon CutFlow systematic TaSmeDet_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_TaSmeDet_SysDown = new TH1F( "PhFlow_TaSmeDet_SysDown" , "Photon CutFlow systematic TaSmeDet_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_TaSmeMod_SysUp   = new TH1F( "PhFlow_TaSmeMod_SysUp"   , "Photon CutFlow systematic TaSmeMod_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_TaSmeMod_SysDown = new TH1F( "PhFlow_TaSmeMod_SysDown" , "Photon CutFlow systematic TaSmeMod_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtSme_SysUp      = new TH1F( "PhFlow_JtSme_SysUp"      , "Photon CutFlow systematic JtSme_SysUp"      , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncNP1_SysUp   = new TH1F( "PhFlow_JtUncNP1_SysUp"   , "Photon CutFlow systematic JtUncNP1_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncNP1_SysDown = new TH1F( "PhFlow_JtUncNP1_SysDown" , "Photon CutFlow systematic JtUncNP1_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncNP2_SysUp   = new TH1F( "PhFlow_JtUncNP2_SysUp"   , "Photon CutFlow systematic JtUncNP2_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncNP2_SysDown = new TH1F( "PhFlow_JtUncNP2_SysDown" , "Photon CutFlow systematic JtUncNP2_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncNP3_SysUp   = new TH1F( "PhFlow_JtUncNP3_SysUp"   , "Photon CutFlow systematic JtUncNP3_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncNP3_SysDown = new TH1F( "PhFlow_JtUncNP3_SysDown" , "Photon CutFlow systematic JtUncNP3_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncETA_SysUp   = new TH1F( "PhFlow_JtUncETA_SysUp"   , "Photon CutFlow systematic JtUncETA_SysUp"   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_JtUncETA_SysDown = new TH1F( "PhFlow_JtUncETA_SysDown" , "Photon CutFlow systematic JtUncETA_SysDown" , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MetResPara       = new TH1F( "PhFlow_MetResPara"       , "Photon CutFlow systematic MetResPara    "   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MetResPerp       = new TH1F( "PhFlow_MetResPerp"       , "Photon CutFlow systematic MetResPerp    "   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MetScl_SysUp     = new TH1F( "PhFlow_MetScl_SysUp"     , "Photon CutFlow systematic MetScl_SysUp  "   , m_PhFlowBins, 0, m_PhFlowBins );
    PhFlow_MetScl_SysDown   = new TH1F( "PhFlow_MetScl_SysDown"   , "Photon CutFlow systematic MetScl_SysDown"   , m_PhFlowBins, 0, m_PhFlowBins );
  }
  
  /* Weights histos */
  EMU_Weights     = new TH1F( "EMU_Weights"     , "EMU_Weights"     , m_WeightBins   , 0, m_WeightBins   );
  ETAU_Weights    = new TH1F( "ETAU_Weights"    , "ETAU_Weights"    , m_WeightBins   , 0, m_WeightBins   );
  MUTAU_Weights   = new TH1F( "MUTAU_Weights"   , "MUTAU_Weights"   , m_WeightBins   , 0, m_WeightBins   );
  EMU_WeightsBJ   = new TH1F( "EMU_WeightsBJ"   , "EMU_WeightsBJ"   , m_WeightBJBins , 0, m_WeightBJBins );
  ETAU_WeightsBJ  = new TH1F( "ETAU_WeightsBJ"  , "ETAU_WeightsBJ"  , m_WeightBJBins , 0, m_WeightBJBins );
  MUTAU_WeightsBJ = new TH1F( "MUTAU_WeightsBJ" , "MUTAU_WeightsBJ" , m_WeightBJBins , 0, m_WeightBJBins );

  if( m_verbose ) Info( "DefineHistograms()", "Histograms Defined!" );

}

void HighMassLFV :: FillHistogramsMaps(){
  
  m_EMU_EvtFlow [ 0 ] = EMU_EventFlow;
  if( m_doSyst ){
    m_EMU_EvtFlow [ Mu_SHSys::MuSmeID_SysUp    ] = EMU_EventFlow_MuSmeID_SysUp;
    m_EMU_EvtFlow [ Mu_SHSys::MuSmeID_SysDown  ] = EMU_EventFlow_MuSmeID_SysDown;
    m_EMU_EvtFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = EMU_EventFlow_MuSmeMS_SysUp;
    m_EMU_EvtFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = EMU_EventFlow_MuSmeMS_SysDown;
    m_EMU_EvtFlow [ Mu_SHSys::MuScale_SysUp    ] = EMU_EventFlow_MuScale_SysUp;
    m_EMU_EvtFlow [ Mu_SHSys::MuScale_SysDown  ] = EMU_EventFlow_MuScale_SysDown;
    m_EMU_EvtFlow [ Mu_SHSys::MuSagRho_SysUp   ] = EMU_EventFlow_MuSagRho_SysUp;
    m_EMU_EvtFlow [ Mu_SHSys::MuSagRho_SysDown ] = EMU_EventFlow_MuSagRho_SysDown;
    m_EMU_EvtFlow [ Mu_SHSys::MuSagRes_SysUp   ] = EMU_EventFlow_MuSagRes_SysUp;
    m_EMU_EvtFlow [ Mu_SHSys::MuSagRes_SysDown ] = EMU_EventFlow_MuSagRes_SysDown;
    m_EMU_EvtFlow [ El_SHSys::ElSme_SysUp      ] = EMU_EventFlow_ElSme_SysUp;
    m_EMU_EvtFlow [ El_SHSys::ElSme_SysDown    ] = EMU_EventFlow_ElSme_SysDown;
    m_EMU_EvtFlow [ El_SHSys::ElScale_SysUp    ] = EMU_EventFlow_ElScale_SysUp;
    m_EMU_EvtFlow [ El_SHSys::ElScale_SysDown  ] = EMU_EventFlow_ElScale_SysDown;
    m_EMU_EvtFlow [ Ta_SHSys::TaSme_SysUp      ] = EMU_EventFlow_TaSme_SysUp;
    m_EMU_EvtFlow [ Ta_SHSys::TaSme_SysDown    ] = EMU_EventFlow_TaSme_SysDown;
    m_EMU_EvtFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = EMU_EventFlow_TaSmeDet_SysUp;
    m_EMU_EvtFlow [ Ta_SHSys::TaSmeDet_SysDown ] = EMU_EventFlow_TaSmeDet_SysDown;
    m_EMU_EvtFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = EMU_EventFlow_TaSmeMod_SysUp;
    m_EMU_EvtFlow [ Ta_SHSys::TaSmeMod_SysDown ] = EMU_EventFlow_TaSmeMod_SysDown;
    m_EMU_EvtFlow [ Jt_SHSys::JtSme_SysUp      ] = EMU_EventFlow_JtSme_SysUp;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = EMU_EventFlow_JtUncNP1_SysUp;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncNP1_SysDown ] = EMU_EventFlow_JtUncNP1_SysDown;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = EMU_EventFlow_JtUncNP2_SysUp;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncNP2_SysDown ] = EMU_EventFlow_JtUncNP2_SysDown;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = EMU_EventFlow_JtUncNP3_SysUp;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncNP3_SysDown ] = EMU_EventFlow_JtUncNP3_SysDown;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncETA_SysUp   ] = EMU_EventFlow_JtUncETA_SysUp;
    m_EMU_EvtFlow [ Jt_UNSys::JtUncETA_SysDown ] = EMU_EventFlow_JtUncETA_SysDown;
    m_EMU_EvtFlow [ Met_SHSys::MetResPara      ] = EMU_EventFlow_MetResPara;
    m_EMU_EvtFlow [ Met_SHSys::MetResPerp      ] = EMU_EventFlow_MetResPerp;
    m_EMU_EvtFlow [ Met_SHSys::MetScl_SysUp    ] = EMU_EventFlow_MetScl_SysUp;
    m_EMU_EvtFlow [ Met_SHSys::MetScl_SysDown  ] = EMU_EventFlow_MetScl_SysDown;

  }
  
  m_ETAU_EvtFlow [ 0 ] = ETAU_EventFlow;
  if( m_doSyst ){
    m_ETAU_EvtFlow [ Mu_SHSys::MuSmeID_SysUp    ] = ETAU_EventFlow_MuSmeID_SysUp;
    m_ETAU_EvtFlow [ Mu_SHSys::MuSmeID_SysDown  ] = ETAU_EventFlow_MuSmeID_SysDown;
    m_ETAU_EvtFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = ETAU_EventFlow_MuSmeMS_SysUp;
    m_ETAU_EvtFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = ETAU_EventFlow_MuSmeMS_SysDown;
    m_ETAU_EvtFlow [ Mu_SHSys::MuScale_SysUp    ] = ETAU_EventFlow_MuScale_SysUp;
    m_ETAU_EvtFlow [ Mu_SHSys::MuScale_SysDown  ] = ETAU_EventFlow_MuScale_SysDown;
    m_ETAU_EvtFlow [ Mu_SHSys::MuSagRho_SysUp   ] = ETAU_EventFlow_MuSagRho_SysUp;
    m_ETAU_EvtFlow [ Mu_SHSys::MuSagRho_SysDown ] = ETAU_EventFlow_MuSagRho_SysDown;
    m_ETAU_EvtFlow [ Mu_SHSys::MuSagRes_SysUp   ] = ETAU_EventFlow_MuSagRes_SysUp;
    m_ETAU_EvtFlow [ Mu_SHSys::MuSagRes_SysDown ] = ETAU_EventFlow_MuSagRes_SysDown;
    m_ETAU_EvtFlow [ El_SHSys::ElSme_SysUp      ] = ETAU_EventFlow_ElSme_SysUp;
    m_ETAU_EvtFlow [ El_SHSys::ElSme_SysDown    ] = ETAU_EventFlow_ElSme_SysDown;
    m_ETAU_EvtFlow [ El_SHSys::ElScale_SysUp    ] = ETAU_EventFlow_ElScale_SysUp;
    m_ETAU_EvtFlow [ El_SHSys::ElScale_SysDown  ] = ETAU_EventFlow_ElScale_SysDown;
    m_ETAU_EvtFlow [ Ta_SHSys::TaSme_SysUp      ] = ETAU_EventFlow_TaSme_SysUp;
    m_ETAU_EvtFlow [ Ta_SHSys::TaSme_SysDown    ] = ETAU_EventFlow_TaSme_SysDown;
    m_ETAU_EvtFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = ETAU_EventFlow_TaSmeDet_SysUp;
    m_ETAU_EvtFlow [ Ta_SHSys::TaSmeDet_SysDown ] = ETAU_EventFlow_TaSmeDet_SysDown;
    m_ETAU_EvtFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = ETAU_EventFlow_TaSmeMod_SysUp;
    m_ETAU_EvtFlow [ Ta_SHSys::TaSmeMod_SysDown ] = ETAU_EventFlow_TaSmeMod_SysDown;
    m_ETAU_EvtFlow [ Jt_SHSys::JtSme_SysUp      ] = ETAU_EventFlow_JtSme_SysUp;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = ETAU_EventFlow_JtUncNP1_SysUp;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncNP1_SysDown ] = ETAU_EventFlow_JtUncNP1_SysDown;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = ETAU_EventFlow_JtUncNP2_SysUp;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncNP2_SysDown ] = ETAU_EventFlow_JtUncNP2_SysDown;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = ETAU_EventFlow_JtUncNP3_SysUp;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncNP3_SysDown ] = ETAU_EventFlow_JtUncNP3_SysDown;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncETA_SysUp   ] = ETAU_EventFlow_JtUncETA_SysUp;
    m_ETAU_EvtFlow [ Jt_UNSys::JtUncETA_SysDown ] = ETAU_EventFlow_JtUncETA_SysDown;
    m_ETAU_EvtFlow [ Met_SHSys::MetResPara      ] = ETAU_EventFlow_MetResPara;
    m_ETAU_EvtFlow [ Met_SHSys::MetResPerp      ] = ETAU_EventFlow_MetResPerp;
    m_ETAU_EvtFlow [ Met_SHSys::MetScl_SysUp    ] = ETAU_EventFlow_MetScl_SysUp;
    m_ETAU_EvtFlow [ Met_SHSys::MetScl_SysDown  ] = ETAU_EventFlow_MetScl_SysDown;
  }
  
  m_MUTAU_EvtFlow [ 0 ] = MUTAU_EventFlow;
  if( m_doSyst ){
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSmeID_SysUp    ] = MUTAU_EventFlow_MuSmeID_SysUp;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSmeID_SysDown  ] = MUTAU_EventFlow_MuSmeID_SysDown;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = MUTAU_EventFlow_MuSmeMS_SysUp;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = MUTAU_EventFlow_MuSmeMS_SysDown;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuScale_SysUp    ] = MUTAU_EventFlow_MuScale_SysUp;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuScale_SysDown  ] = MUTAU_EventFlow_MuScale_SysDown;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSagRho_SysUp   ] = MUTAU_EventFlow_MuSagRho_SysUp;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSagRho_SysDown ] = MUTAU_EventFlow_MuSagRho_SysDown;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSagRes_SysUp   ] = MUTAU_EventFlow_MuSagRes_SysUp;
    m_MUTAU_EvtFlow [ Mu_SHSys::MuSagRes_SysDown ] = MUTAU_EventFlow_MuSagRes_SysDown;
    m_MUTAU_EvtFlow [ El_SHSys::ElSme_SysUp      ] = MUTAU_EventFlow_ElSme_SysUp;
    m_MUTAU_EvtFlow [ El_SHSys::ElSme_SysDown    ] = MUTAU_EventFlow_ElSme_SysDown;
    m_MUTAU_EvtFlow [ El_SHSys::ElScale_SysUp    ] = MUTAU_EventFlow_ElScale_SysUp;
    m_MUTAU_EvtFlow [ El_SHSys::ElScale_SysDown  ] = MUTAU_EventFlow_ElScale_SysDown;
    m_MUTAU_EvtFlow [ Ta_SHSys::TaSme_SysUp      ] = MUTAU_EventFlow_TaSme_SysUp;
    m_MUTAU_EvtFlow [ Ta_SHSys::TaSme_SysDown    ] = MUTAU_EventFlow_TaSme_SysDown;
    m_MUTAU_EvtFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = MUTAU_EventFlow_TaSmeDet_SysUp;
    m_MUTAU_EvtFlow [ Ta_SHSys::TaSmeDet_SysDown ] = MUTAU_EventFlow_TaSmeDet_SysDown;
    m_MUTAU_EvtFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = MUTAU_EventFlow_TaSmeMod_SysUp;
    m_MUTAU_EvtFlow [ Ta_SHSys::TaSmeMod_SysDown ] = MUTAU_EventFlow_TaSmeMod_SysDown;
    m_MUTAU_EvtFlow [ Jt_SHSys::JtSme_SysUp      ] = MUTAU_EventFlow_JtSme_SysUp;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = MUTAU_EventFlow_JtUncNP1_SysUp;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncNP1_SysDown ] = MUTAU_EventFlow_JtUncNP1_SysDown;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = MUTAU_EventFlow_JtUncNP2_SysUp;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncNP2_SysDown ] = MUTAU_EventFlow_JtUncNP2_SysDown;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = MUTAU_EventFlow_JtUncNP3_SysUp;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncNP3_SysDown ] = MUTAU_EventFlow_JtUncNP3_SysDown;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncETA_SysUp   ] = MUTAU_EventFlow_JtUncETA_SysUp;
    m_MUTAU_EvtFlow [ Jt_UNSys::JtUncETA_SysDown ] = MUTAU_EventFlow_JtUncETA_SysDown;
    m_MUTAU_EvtFlow [ Met_SHSys::MetResPara      ] = MUTAU_EventFlow_MetResPara;
    m_MUTAU_EvtFlow [ Met_SHSys::MetResPerp      ] = MUTAU_EventFlow_MetResPerp;
    m_MUTAU_EvtFlow [ Met_SHSys::MetScl_SysUp    ] = MUTAU_EventFlow_MetScl_SysUp;
    m_MUTAU_EvtFlow [ Met_SHSys::MetScl_SysDown  ] = MUTAU_EventFlow_MetScl_SysDown;
  }
  
  m_MuFlow [ 0 ] = MuonFlow;
  if( m_doSyst ){
    m_MuFlow [ Mu_SHSys::MuSmeID_SysUp    ] = MuonFlow_MuSmeID_SysUp;
    m_MuFlow [ Mu_SHSys::MuSmeID_SysDown  ] = MuonFlow_MuSmeID_SysDown;
    m_MuFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = MuonFlow_MuSmeMS_SysUp;
    m_MuFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = MuonFlow_MuSmeMS_SysDown;
    m_MuFlow [ Mu_SHSys::MuScale_SysUp    ] = MuonFlow_MuScale_SysUp;
    m_MuFlow [ Mu_SHSys::MuScale_SysDown  ] = MuonFlow_MuScale_SysDown;
    m_MuFlow [ Mu_SHSys::MuSagRho_SysUp   ] = MuonFlow_MuSagRho_SysUp;
    m_MuFlow [ Mu_SHSys::MuSagRho_SysDown ] = MuonFlow_MuSagRho_SysDown;
    m_MuFlow [ Mu_SHSys::MuSagRes_SysUp   ] = MuonFlow_MuSagRes_SysUp;
    m_MuFlow [ Mu_SHSys::MuSagRes_SysDown ] = MuonFlow_MuSagRes_SysDown;
    m_MuFlow [ El_SHSys::ElSme_SysUp      ] = MuonFlow_ElSme_SysUp;
    m_MuFlow [ El_SHSys::ElSme_SysDown    ] = MuonFlow_ElSme_SysDown;
    m_MuFlow [ El_SHSys::ElScale_SysUp    ] = MuonFlow_ElScale_SysUp;
    m_MuFlow [ El_SHSys::ElScale_SysDown  ] = MuonFlow_ElScale_SysDown;
    m_MuFlow [ Ta_SHSys::TaSme_SysUp      ] = MuonFlow_TaSme_SysUp;
    m_MuFlow [ Ta_SHSys::TaSme_SysDown    ] = MuonFlow_TaSme_SysDown;
    m_MuFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = MuonFlow_TaSmeDet_SysUp;
    m_MuFlow [ Ta_SHSys::TaSmeDet_SysDown ] = MuonFlow_TaSmeDet_SysDown;
    m_MuFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = MuonFlow_TaSmeMod_SysUp;
    m_MuFlow [ Ta_SHSys::TaSmeMod_SysDown ] = MuonFlow_TaSmeMod_SysDown;
    m_MuFlow [ Jt_SHSys::JtSme_SysUp      ] = MuonFlow_JtSme_SysUp;
    m_MuFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = MuonFlow_JtUncNP1_SysUp;
    m_MuFlow [ Jt_UNSys::JtUncNP1_SysDown ] = MuonFlow_JtUncNP1_SysDown;
    m_MuFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = MuonFlow_JtUncNP2_SysUp;
    m_MuFlow [ Jt_UNSys::JtUncNP2_SysDown ] = MuonFlow_JtUncNP2_SysDown;
    m_MuFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = MuonFlow_JtUncNP3_SysUp;
    m_MuFlow [ Jt_UNSys::JtUncNP3_SysDown ] = MuonFlow_JtUncNP3_SysDown;
    m_MuFlow [ Jt_UNSys::JtUncETA_SysUp   ] = MuonFlow_JtUncETA_SysUp;
    m_MuFlow [ Jt_UNSys::JtUncETA_SysDown ] = MuonFlow_JtUncETA_SysDown;
    m_MuFlow [ Met_SHSys::MetResPara      ] = MuonFlow_MetResPara;
    m_MuFlow [ Met_SHSys::MetResPerp      ] = MuonFlow_MetResPerp;
    m_MuFlow [ Met_SHSys::MetScl_SysUp    ] = MuonFlow_MetScl_SysUp;
    m_MuFlow [ Met_SHSys::MetScl_SysDown  ] = MuonFlow_MetScl_SysDown;
  }

  m_ElFlow [ 0 ] = ElectronFlow;
  if( m_doSyst ){
    m_ElFlow [ Mu_SHSys::MuSmeID_SysUp    ] = ElectronFlow_MuSmeID_SysUp;
    m_ElFlow [ Mu_SHSys::MuSmeID_SysDown  ] = ElectronFlow_MuSmeID_SysDown;
    m_ElFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = ElectronFlow_MuSmeMS_SysUp;
    m_ElFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = ElectronFlow_MuSmeMS_SysDown;
    m_ElFlow [ Mu_SHSys::MuScale_SysUp    ] = ElectronFlow_MuScale_SysUp;
    m_ElFlow [ Mu_SHSys::MuScale_SysDown  ] = ElectronFlow_MuScale_SysDown;
    m_ElFlow [ Mu_SHSys::MuSagRho_SysUp   ] = ElectronFlow_MuSagRho_SysUp;
    m_ElFlow [ Mu_SHSys::MuSagRho_SysDown ] = ElectronFlow_MuSagRho_SysDown;
    m_ElFlow [ Mu_SHSys::MuSagRes_SysUp   ] = ElectronFlow_MuSagRes_SysUp;
    m_ElFlow [ Mu_SHSys::MuSagRes_SysDown ] = ElectronFlow_MuSagRes_SysDown;
    m_ElFlow [ El_SHSys::ElSme_SysUp      ] = ElectronFlow_ElSme_SysUp;
    m_ElFlow [ El_SHSys::ElSme_SysDown    ] = ElectronFlow_ElSme_SysDown;
    m_ElFlow [ El_SHSys::ElScale_SysUp    ] = ElectronFlow_ElScale_SysUp;
    m_ElFlow [ El_SHSys::ElScale_SysDown  ] = ElectronFlow_ElScale_SysDown;
    m_ElFlow [ Ta_SHSys::TaSme_SysUp      ] = ElectronFlow_TaSme_SysUp;
    m_ElFlow [ Ta_SHSys::TaSme_SysDown    ] = ElectronFlow_TaSme_SysDown;
    m_ElFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = ElectronFlow_TaSmeDet_SysUp;
    m_ElFlow [ Ta_SHSys::TaSmeDet_SysDown ] = ElectronFlow_TaSmeDet_SysDown;
    m_ElFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = ElectronFlow_TaSmeMod_SysUp;
    m_ElFlow [ Ta_SHSys::TaSmeMod_SysDown ] = ElectronFlow_TaSmeMod_SysDown;
    m_ElFlow [ Jt_SHSys::JtSme_SysUp      ] = ElectronFlow_JtSme_SysUp;
    m_ElFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = ElectronFlow_JtUncNP1_SysUp;
    m_ElFlow [ Jt_UNSys::JtUncNP1_SysDown ] = ElectronFlow_JtUncNP1_SysDown;
    m_ElFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = ElectronFlow_JtUncNP2_SysUp;
    m_ElFlow [ Jt_UNSys::JtUncNP2_SysDown ] = ElectronFlow_JtUncNP2_SysDown;
    m_ElFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = ElectronFlow_JtUncNP3_SysUp;
    m_ElFlow [ Jt_UNSys::JtUncNP3_SysDown ] = ElectronFlow_JtUncNP3_SysDown;
    m_ElFlow [ Jt_UNSys::JtUncETA_SysUp   ] = ElectronFlow_JtUncETA_SysUp;
    m_ElFlow [ Jt_UNSys::JtUncETA_SysDown ] = ElectronFlow_JtUncETA_SysDown;
    m_ElFlow [ Met_SHSys::MetResPara      ] = ElectronFlow_MetResPara;
    m_ElFlow [ Met_SHSys::MetResPerp      ] = ElectronFlow_MetResPerp;
    m_ElFlow [ Met_SHSys::MetScl_SysUp    ] = ElectronFlow_MetScl_SysUp;
    m_ElFlow [ Met_SHSys::MetScl_SysDown  ] = ElectronFlow_MetScl_SysDown;
  }

  m_TaFlow [ 0 ] = TauFlow;
  if( m_doSyst ){
    m_TaFlow [ Mu_SHSys::MuSmeID_SysUp    ] = TauFlow_MuSmeID_SysUp;
    m_TaFlow [ Mu_SHSys::MuSmeID_SysDown  ] = TauFlow_MuSmeID_SysDown;
    m_TaFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = TauFlow_MuSmeMS_SysUp;
    m_TaFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = TauFlow_MuSmeMS_SysDown;
    m_TaFlow [ Mu_SHSys::MuScale_SysUp    ] = TauFlow_MuScale_SysUp;
    m_TaFlow [ Mu_SHSys::MuScale_SysDown  ] = TauFlow_MuScale_SysDown;
    m_TaFlow [ Mu_SHSys::MuSagRho_SysUp   ] = TauFlow_MuSagRho_SysUp;
    m_TaFlow [ Mu_SHSys::MuSagRho_SysDown ] = TauFlow_MuSagRho_SysDown;
    m_TaFlow [ Mu_SHSys::MuSagRes_SysUp   ] = TauFlow_MuSagRes_SysUp;
    m_TaFlow [ Mu_SHSys::MuSagRes_SysDown ] = TauFlow_MuSagRes_SysDown;
    m_TaFlow [ El_SHSys::ElSme_SysUp      ] = TauFlow_ElSme_SysUp;
    m_TaFlow [ El_SHSys::ElSme_SysDown    ] = TauFlow_ElSme_SysDown;
    m_TaFlow [ El_SHSys::ElScale_SysUp    ] = TauFlow_ElScale_SysUp;
    m_TaFlow [ El_SHSys::ElScale_SysDown  ] = TauFlow_ElScale_SysDown;
    m_TaFlow [ Ta_SHSys::TaSme_SysUp      ] = TauFlow_TaSme_SysUp;
    m_TaFlow [ Ta_SHSys::TaSme_SysDown    ] = TauFlow_TaSme_SysDown;
    m_TaFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = TauFlow_TaSmeDet_SysUp;
    m_TaFlow [ Ta_SHSys::TaSmeDet_SysDown ] = TauFlow_TaSmeDet_SysDown;
    m_TaFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = TauFlow_TaSmeMod_SysUp;
    m_TaFlow [ Ta_SHSys::TaSmeMod_SysDown ] = TauFlow_TaSmeMod_SysDown;
    m_TaFlow [ Jt_SHSys::JtSme_SysUp      ] = TauFlow_JtSme_SysUp;
    m_TaFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = TauFlow_JtUncNP1_SysUp;
    m_TaFlow [ Jt_UNSys::JtUncNP1_SysDown ] = TauFlow_JtUncNP1_SysDown;
    m_TaFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = TauFlow_JtUncNP2_SysUp;
    m_TaFlow [ Jt_UNSys::JtUncNP2_SysDown ] = TauFlow_JtUncNP2_SysDown;
    m_TaFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = TauFlow_JtUncNP3_SysUp;
    m_TaFlow [ Jt_UNSys::JtUncNP3_SysDown ] = TauFlow_JtUncNP3_SysDown;
    m_TaFlow [ Jt_UNSys::JtUncETA_SysUp   ] = TauFlow_JtUncETA_SysUp;
    m_TaFlow [ Jt_UNSys::JtUncETA_SysDown ] = TauFlow_JtUncETA_SysDown;
    m_TaFlow [ Met_SHSys::MetResPara      ] = TauFlow_MetResPara;
    m_TaFlow [ Met_SHSys::MetResPerp      ] = TauFlow_MetResPerp;
    m_TaFlow [ Met_SHSys::MetScl_SysUp    ] = TauFlow_MetScl_SysUp;
    m_TaFlow [ Met_SHSys::MetScl_SysDown  ] = TauFlow_MetScl_SysDown;
  }

  m_JetFlow [ 0 ] = JetFlow;
  if( m_doSyst ){
    m_JetFlow [ Mu_SHSys::MuSmeID_SysUp    ] = JetFlow_MuSmeID_SysUp;
    m_JetFlow [ Mu_SHSys::MuSmeID_SysDown  ] = JetFlow_MuSmeID_SysDown;
    m_JetFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = JetFlow_MuSmeMS_SysUp;
    m_JetFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = JetFlow_MuSmeMS_SysDown;
    m_JetFlow [ Mu_SHSys::MuScale_SysUp    ] = JetFlow_MuScale_SysUp;
    m_JetFlow [ Mu_SHSys::MuScale_SysDown  ] = JetFlow_MuScale_SysDown;
    m_JetFlow [ Mu_SHSys::MuSagRho_SysUp   ] = JetFlow_MuSagRho_SysUp;
    m_JetFlow [ Mu_SHSys::MuSagRho_SysDown ] = JetFlow_MuSagRho_SysDown;
    m_JetFlow [ Mu_SHSys::MuSagRes_SysUp   ] = JetFlow_MuSagRes_SysUp;
    m_JetFlow [ Mu_SHSys::MuSagRes_SysDown ] = JetFlow_MuSagRes_SysDown;
    m_JetFlow [ El_SHSys::ElSme_SysUp      ] = JetFlow_ElSme_SysUp;
    m_JetFlow [ El_SHSys::ElSme_SysDown    ] = JetFlow_ElSme_SysDown;
    m_JetFlow [ El_SHSys::ElScale_SysUp    ] = JetFlow_ElScale_SysUp;
    m_JetFlow [ El_SHSys::ElScale_SysDown  ] = JetFlow_ElScale_SysDown;
    m_JetFlow [ Ta_SHSys::TaSme_SysUp      ] = JetFlow_TaSme_SysUp;
    m_JetFlow [ Ta_SHSys::TaSme_SysDown    ] = JetFlow_TaSme_SysDown;
    m_JetFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = JetFlow_TaSmeDet_SysUp;
    m_JetFlow [ Ta_SHSys::TaSmeDet_SysDown ] = JetFlow_TaSmeDet_SysDown;
    m_JetFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = JetFlow_TaSmeMod_SysUp;
    m_JetFlow [ Ta_SHSys::TaSmeMod_SysDown ] = JetFlow_TaSmeMod_SysDown;
    m_JetFlow [ Jt_SHSys::JtSme_SysUp      ] = JetFlow_JtSme_SysUp;
    m_JetFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = JetFlow_JtUncNP1_SysUp;
    m_JetFlow [ Jt_UNSys::JtUncNP1_SysDown ] = JetFlow_JtUncNP1_SysDown;
    m_JetFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = JetFlow_JtUncNP2_SysUp;
    m_JetFlow [ Jt_UNSys::JtUncNP2_SysDown ] = JetFlow_JtUncNP2_SysDown;
    m_JetFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = JetFlow_JtUncNP3_SysUp;
    m_JetFlow [ Jt_UNSys::JtUncNP3_SysDown ] = JetFlow_JtUncNP3_SysDown;
    m_JetFlow [ Jt_UNSys::JtUncETA_SysUp   ] = JetFlow_JtUncETA_SysUp;
    m_JetFlow [ Jt_UNSys::JtUncETA_SysDown ] = JetFlow_JtUncETA_SysDown;
    m_JetFlow [ Met_SHSys::MetResPara      ] = JetFlow_MetResPara;
    m_JetFlow [ Met_SHSys::MetResPerp      ] = JetFlow_MetResPerp;
    m_JetFlow [ Met_SHSys::MetScl_SysUp    ] = JetFlow_MetScl_SysUp;
    m_JetFlow [ Met_SHSys::MetScl_SysDown  ] = JetFlow_MetScl_SysDown;
  }

  m_PhFlow [ 0 ] = PhFlow;
  if( m_doSyst ){
    m_PhFlow [ Mu_SHSys::MuSmeID_SysUp    ] = PhFlow_MuSmeID_SysUp;
    m_PhFlow [ Mu_SHSys::MuSmeID_SysDown  ] = PhFlow_MuSmeID_SysDown;
    m_PhFlow [ Mu_SHSys::MuSmeMS_SysUp    ] = PhFlow_MuSmeMS_SysUp;
    m_PhFlow [ Mu_SHSys::MuSmeMS_SysDown  ] = PhFlow_MuSmeMS_SysDown;
    m_PhFlow [ Mu_SHSys::MuScale_SysUp    ] = PhFlow_MuScale_SysUp;
    m_PhFlow [ Mu_SHSys::MuScale_SysDown  ] = PhFlow_MuScale_SysDown;
    m_PhFlow [ Mu_SHSys::MuSagRho_SysUp   ] = PhFlow_MuSagRho_SysUp;
    m_PhFlow [ Mu_SHSys::MuSagRho_SysDown ] = PhFlow_MuSagRho_SysDown;
    m_PhFlow [ Mu_SHSys::MuSagRes_SysUp   ] = PhFlow_MuSagRes_SysUp;
    m_PhFlow [ Mu_SHSys::MuSagRes_SysDown ] = PhFlow_MuSagRes_SysDown;
    m_PhFlow [ El_SHSys::ElSme_SysUp      ] = PhFlow_ElSme_SysUp;
    m_PhFlow [ El_SHSys::ElSme_SysDown    ] = PhFlow_ElSme_SysDown;
    m_PhFlow [ El_SHSys::ElScale_SysUp    ] = PhFlow_ElScale_SysUp;
    m_PhFlow [ El_SHSys::ElScale_SysDown  ] = PhFlow_ElScale_SysDown;
    m_PhFlow [ Ta_SHSys::TaSme_SysUp      ] = PhFlow_TaSme_SysUp;
    m_PhFlow [ Ta_SHSys::TaSme_SysDown    ] = PhFlow_TaSme_SysDown;
    m_PhFlow [ Ta_SHSys::TaSmeDet_SysUp   ] = PhFlow_TaSmeDet_SysUp;
    m_PhFlow [ Ta_SHSys::TaSmeDet_SysDown ] = PhFlow_TaSmeDet_SysDown;
    m_PhFlow [ Ta_SHSys::TaSmeMod_SysUp   ] = PhFlow_TaSmeMod_SysUp;
    m_PhFlow [ Ta_SHSys::TaSmeMod_SysDown ] = PhFlow_TaSmeMod_SysDown;
    m_PhFlow [ Jt_SHSys::JtSme_SysUp      ] = PhFlow_JtSme_SysUp;
    m_PhFlow [ Jt_UNSys::JtUncNP1_SysUp   ] = PhFlow_JtUncNP1_SysUp;
    m_PhFlow [ Jt_UNSys::JtUncNP1_SysDown ] = PhFlow_JtUncNP1_SysDown;
    m_PhFlow [ Jt_UNSys::JtUncNP2_SysUp   ] = PhFlow_JtUncNP2_SysUp;
    m_PhFlow [ Jt_UNSys::JtUncNP2_SysDown ] = PhFlow_JtUncNP2_SysDown;
    m_PhFlow [ Jt_UNSys::JtUncNP3_SysUp   ] = PhFlow_JtUncNP3_SysUp;
    m_PhFlow [ Jt_UNSys::JtUncNP3_SysDown ] = PhFlow_JtUncNP3_SysDown;
    m_PhFlow [ Jt_UNSys::JtUncETA_SysUp   ] = PhFlow_JtUncETA_SysUp;
    m_PhFlow [ Jt_UNSys::JtUncETA_SysDown ] = PhFlow_JtUncETA_SysDown;
    m_PhFlow [ Met_SHSys::MetResPara      ] = PhFlow_MetResPara;
    m_PhFlow [ Met_SHSys::MetResPerp      ] = PhFlow_MetResPerp;
    m_PhFlow [ Met_SHSys::MetScl_SysUp    ] = PhFlow_MetScl_SysUp;
    m_PhFlow [ Met_SHSys::MetScl_SysDown  ] = PhFlow_MetScl_SysDown;
  }

  m_Weights [ Channel::EMU   ] = EMU_Weights;
  m_Weights [ Channel::ETAU  ] = ETAU_Weights;
  m_Weights [ Channel::MUTAU ] = MUTAU_Weights;
  
  m_WeightsBJ [ Channel::EMU   ] = EMU_WeightsBJ;
  m_WeightsBJ [ Channel::ETAU  ] = ETAU_WeightsBJ;
  m_WeightsBJ [ Channel::MUTAU ] = MUTAU_WeightsBJ;

  if( m_verbose ) Info( "FillHistogramsMaps()", "Histograms Maps Filled!" );
  
}

void HighMassLFV :: CreateListOfHistograms(){

  FillHistogramsMaps();
  
  m_Hist.push_back(MCInfo);
  for( uint h=0; h<m_EMU_EvtFlow.size(); h++ ){
    m_Hist.push_back( m_EMU_EvtFlow[h]   );
    m_Hist.push_back( m_ETAU_EvtFlow[h]  );
    m_Hist.push_back( m_MUTAU_EvtFlow[h] );
    m_Hist.push_back( m_MuFlow[h]  );
    m_Hist.push_back( m_ElFlow[h]  );
    m_Hist.push_back( m_TaFlow[h]  );
    m_Hist.push_back( m_JetFlow[h] );
    m_Hist.push_back( m_PhFlow[h]  );
  }
  for( int i=1; i<4; i++ ){
    m_Hist.push_back( m_Weights[i] );
    m_Hist.push_back( m_WeightsBJ[i] );
  }

  if( m_verbose ) Info( "CreateListOfHistograms()", "Histograms List Made!" );
  
}
