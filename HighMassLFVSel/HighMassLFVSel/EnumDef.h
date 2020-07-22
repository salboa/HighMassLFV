#ifndef ENUMDEF_H
#define ENUMDEF_H


/* Data year */
namespace DataYear{
  enum DataYear{
    Year2016 = 0,
    Year2017 = 1,
    Year2018 = 2
  };
}

/* covariance matrix parameters */
namespace TrkParam{
  enum TrkParam{
    d0     = 0,
    z0     = 1,
    phi0   = 2,
    theta  = 3,
    qOverP = 4,
    x      = 0,
    y      = 1,
    z      = 2
  };
}

/* LFV channels */
namespace Channel{
  enum Channel{
    EMU   = 1,
    ETAU  = 2,
    MUTAU = 3
  };
}

/* LFV event flow*/
namespace EvtFlow{
  enum EvtFlow{
    Start     = 1,
    EvtClean  = 2,
    Vertex    = 3,
    Trigger   = 4,
    BadMuon   = 5,
    BadJet    = 6,
    Leptons   = 7,
    ThirdLepV = 8,
    TrigMatch = 9,
    OS_Pair   = 10,
    DeltaPhi  = 11,
    BjetVeto  = 12,
    MET       = 13
  };
}

/* muon flow */
namespace MuFlow{
  enum MuFlow{
    Start     = 1,
    EvtClean  = 2,
    Vertex    = 3,
    Trigger   = 4,
    TrigMatch = 5,
    Pt        = 6,
    Eta_ID_Q  = 7,
    HighPtCut = 8,
    D0Sign    = 9,
    DeltaZ0   = 10,
    Overlaps  = 11,
    Isolation = 12,
    TightMu   = 13,
    LooseMu   = 14
  };
}

/* electron flow */
namespace ElFlow{
  enum ElFlow{
    Start     = 1,
    EvtClean  = 2,
    Vertex    = 3,
    Trigger   = 4,
    TrigMatch = 5,
    Author    = 6,
    Pt        = 7,
    Eta       = 8,
    ObjectQ   = 9,
    ElecID    = 10,
    D0Sign    = 11,
    DeltaZ0   = 12,
    Overlaps  = 13,
    MuElOve   = 14,
    Isolation = 15,
    TightEl   = 16,
    LooseEl   = 17
  };
}

/* tau flow */
namespace TauFlow{
  enum TauFlow{
    Start     = 1,
    EvtClean  = 2,
    Vertex    = 3,
    Trigger   = 4,
    TrigMatch = 5,
    Pt        = 6,
    Eta       = 7,
    Charge    = 8,
    nTracks   = 9,
    BDTscore  = 10,
    JetIDWP   = 11,
    ElOR      = 12, 
    Overlaps  = 13,
    TaMuOve   = 14,
    TaElOve   = 15
  };
}

/* jet flow */
namespace JtFlow{
  enum JtFlow{
    Start         = 1,
    EvtClean      = 2,
    Vertex        = 3,
    Trigger       = 4,
    Pt            = 5,
    Eta           = 6,
    Overlaps      = 7,
    JetElOverlap  = 8,
    JetTauOverlap = 9,
    JetMuOverlap  = 10,
    JVT           = 11,
    Clean         = 12,
    BjetVeto      = 13,
    Bjet          = 14
  };
}

/* photon flow */
namespace PhFlow{
  enum PhFlow{
    Start    = 1,
    EvtClean = 2,
    Vertex   = 3,
    Trigger  = 4,
    Pt       = 5,
    Eta      = 6,
    Author   = 7,
    ObjQual  = 8,
    Clean    = 9
  };
}

/* muon SF systematics */
namespace Mu_SFSys{
  enum Mu_SFSys{
    MuReco_StatUp   = 1,
    MuReco_StatDown = 2,
    MuReco_SysUp    = 3,
    MuReco_SysDown  = 4,
    MuIso_StatUp    = 5,
    MuIso_StatDown  = 6,
    MuIso_SysUp     = 7,
    MuIso_SysDown   = 8,
    MuTrg_StatUp    = 9,
    MuTrg_StatDown  = 10,
    MuTrg_SysUp     = 11,
    MuTrg_SysDown   = 12,
    MuTTVA_StatUp   = 13,
    MuTTVA_StatDown = 14,
    MuTTVA_SysUp    = 15,
    MuTTVA_SysDown  = 16
  };
}

/* electron SF systematics */
namespace El_SFSys{
  enum El_SFSys{
    ElReco_SysUp   = 1,
    ElReco_SysDown = 2,
    ElID_SysUp     = 3,
    ElID_SysDown   = 4,
    ElIso_SysUp    = 5,
    ElIso_SysDown  = 6,
    ElTrg_SysUp    = 7,
    ElTrg_SysDown  = 8
  };
}

/* tau SF systematics */
namespace Ta_SFSys{
  enum Ta_SFSys{
    TaReco_SysUp       = 1,
    TaReco_SysDown     = 2,
    TaRecoHpt_SysUp    = 3,
    TaRecoHpt_SysDown  = 4,
    TaEleOlr_SysUp     = 5,
    TaEleOlr_SysDown   = 6,
    TaJetID_SysUp      = 7,
    TaJetID_SysDown    = 8,
    TaJetIDHpt_SysUp   = 9,
    TaJetIDHpt_SysDown = 10
  };
}

/* jet SF systematics */
namespace Jt_SFSys{
  enum Jt_SFSys{
    JtBeff_SysUp      = 1,
    JtBeff_SysDown    = 2,
    JtCeff_SysUp      = 3,
    JtCeff_SysDown    = 4,
    JtLeff_SysUp      = 5,
    JtLeff_SysDown    = 6,
    JtExtCeff_SysUp   = 7,
    JtExtCeff_SysDown = 8,
    JtExtEff_SysUp    = 9,
    JtExtEff_SysDown  = 10,
    JtJvt_SysUp       = 11, 
    JtJvt_SysDown     = 12
  };
}

/* muon Shape systematics */
namespace Mu_SHSys{
  enum Mu_SHSys{
    MuSmeID_SysUp    = 1,
    MuSmeID_SysDown  = 2,
    MuSmeMS_SysUp    = 3,
    MuSmeMS_SysDown  = 4,
    MuScale_SysUp    = 5,
    MuScale_SysDown  = 6,
    MuSagRho_SysUp   = 7,
    MuSagRho_SysDown = 8,
    MuSagRes_SysUp   = 9,
    MuSagRes_SysDown = 10
  };
}

/* electron Shape systematics */
namespace El_SHSys{
  enum El_SHSys{
    ElSme_SysUp     = 11,
    ElSme_SysDown   = 12,
    ElScale_SysUp   = 13,
    ElScale_SysDown = 14
  };
}

/* tau Shape systematics */
namespace Ta_SHSys{
  enum Ta_SHSys{
    TaSme_SysUp      = 15,
    TaSme_SysDown    = 16,
    TaSmeDet_SysUp   = 17,
    TaSmeDet_SysDown = 18,
    TaSmeMod_SysUp   = 19,
    TaSmeMod_SysDown = 20
  };
}

/* jet Shape systematics */
namespace Jt_SHSys{
  enum Jt_SHSys{
    JtSme_SysUp      = 21
  };
}

/* jet Uncertainties systematics */
namespace Jt_UNSys{
  enum Jt_UNSys{
    JtUncNP1_SysUp   = 22,
    JtUncNP1_SysDown = 23,
    JtUncNP2_SysUp   = 24,
    JtUncNP2_SysDown = 25,
    JtUncNP3_SysUp   = 26,
    JtUncNP3_SysDown = 27,
    JtUncETA_SysUp   = 28,
    JtUncETA_SysDown = 29
  };
}

/* pileup weight systematics */
namespace Pu_WgtSys{
  enum Pu_WgtSys{
    PuWgt_SysUp   = 1,
    PuWgt_SysDown = 2
  };
}

/* met systematics */
namespace Met_SHSys{
  enum Met_SHSys{
    MetResPara     = 30,
    MetResPerp     = 31,
    MetScl_SysUp   = 32, 
    MetScl_SysDown = 33
  };
}

/* weights */
namespace Weights{
  enum Weights{
    MC                     = 1,
    PU                     = 2,
    PU_SysUp               = 3,
    PU_SysDown             = 4,
    ElReco                 = 5,
    ElReco_SysUp           = 6,
    ElReco_SysDown         = 7,
    ElID                   = 8,
    ElID_SysUp             = 9,
    ElID_SysDown           = 10,
    ElIso                  = 11,
    ElIso_SysUp            = 12,
    ElIso_SysDown          = 13,
    ElTrig                 = 14,
    ElTrig_SysUp           = 15,
    ElTrig_SysDown         = 16,
    ElL1Calo               = 17,
    MuReco                 = 18,
    MuReco_StatUp          = 19,
    MuReco_StatDown        = 20,
    MuReco_SysUp           = 21,
    MuReco_SysDown         = 22,
    MuIso                  = 23,
    MuIso_StatUp           = 24,
    MuIso_StatDown         = 25,
    MuIso_SysUp            = 26,
    MuIso_SysDown          = 27,
    MuTrig                 = 28,
    MuTrig_StatUp          = 29,
    MuTrig_StatDown        = 30,
    MuTrig_SysUp           = 31,
    MuTrig_SysDown         = 32,
    MuTTVA                 = 33,
    MuTTVA_StatUp          = 34,
    MuTTVA_StatDown        = 35,
    MuTTVA_SysUp           = 36,
    MuTTVA_SysDown         = 37,
    TaReco                 = 38,
    TaReco_SysUp	   = 39,
    TaReco_SysDown	   = 40,
    TaReco_Hpt_SysUp	   = 41,
    TaReco_Hpt_SysDown	   = 42,
    TaID		   = 43,
    TaID_SysUp		   = 44,
    TaID_SysDown	   = 45,
    TaID_Hpt_SysUp	   = 46,
    TaID_Hpt_SysDown	   = 47,
    TaElOlr		   = 48,
    TaElOlr_SysUp	   = 49,
    TaElOlr_SysDown        = 50,
    JtJvt                  = 51,
    JtJvt_SysUp            = 52,
    JtJvt_SysDown          = 53,
    BtagSF                 = 54,
    BtagSF_Beff_SysUp      = 55,
    BtagSF_Beff_SysDown    = 56,
    BtagSF_Ceff_SysUp      = 57,
    BtagSF_Ceff_SysDown    = 58,
    BtagSF_Leff_SysUp      = 59,
    BtagSF_Leff_SysDown    = 60,
    BtagSF_ExtCeff_SysUp   = 61,
    BtagSF_ExtCeff_SysDown = 62,
    BtagSF_ExtEff_SysUp    = 63,
    BtagSF_ExtEff_SysDown  = 64
  };
}

#endif
