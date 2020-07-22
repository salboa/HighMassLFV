#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: DefineTrees(){
  
  lfvTree = new TTree("lfv","lfv tree");
  if( m_doSyst ){
    lfvTree_MuSmeID_SysUp    = new TTree("lfv_MuSmeID_SysUp"    , "lfv tree systematic MuSmeID_SysUp"    );
    lfvTree_MuSmeID_SysDown  = new TTree("lfv_MuSmeID_SysDown"  , "lfv tree systematic MuSmeID_SysDown"  );
    lfvTree_MuSmeMS_SysUp    = new TTree("lfv_MuSmeMS_SysUp"    , "lfv tree systematic MuSmeMS_SysUp"    );
    lfvTree_MuSmeMS_SysDown  = new TTree("lfv_MuSmeMS_SysDown"  , "lfv tree systematic MuSmeMS_SysDown"  );
    lfvTree_MuScale_SysUp    = new TTree("lfv_MuScale_SysUp"    , "lfv tree systematic MuScale_SysUp"    );
    lfvTree_MuScale_SysDown  = new TTree("lfv_MuScale_SysDown"  , "lfv tree systematic MuScale_SysDown"  );
    lfvTree_MuSagRho_SysUp   = new TTree("lfv_MuSagRho_SysUp"   , "lfv tree systematic MuSagRho_SysUp"   );
    lfvTree_MuSagRho_SysDown = new TTree("lfv_MuSagRho_SysDown" , "lfv tree systematic MuSagRho_SysDown" );
    lfvTree_MuSagRes_SysUp   = new TTree("lfv_MuSagRes_SysUp"   , "lfv tree systematic MuSagRes_SysUp"   );
    lfvTree_MuSagRes_SysDown = new TTree("lfv_MuSagRes_SysDown" , "lfv tree systematic MuSagRes_SysDown" );
    lfvTree_ElSme_SysUp      = new TTree("lfv_ElSme_SysUp"      , "lfv tree systematic ElSme_SysUp"      );
    lfvTree_ElSme_SysDown    = new TTree("lfv_ElSme_SysDown"    , "lfv tree systematic ElSme_SysDown"    );
    lfvTree_ElScale_SysUp    = new TTree("lfv_ElScale_SysUp"    , "lfv tree systematic ElScale_SysUp"    );
    lfvTree_ElScale_SysDown  = new TTree("lfv_ElScale_SysDown"  , "lfv tree systematic MuScale_SysDown"  );
    lfvTree_TaSme_SysUp      = new TTree("lfv_TaSme_SysUp"      , "lfv tree systematic TaSme_SysUp"      );
    lfvTree_TaSme_SysDown    = new TTree("lfv_TaSme_SysDown"    , "lfv tree systematic TaSme_SysDown"    );
    lfvTree_TaSmeDet_SysUp   = new TTree("lfv_TaSmeDet_SysUp"   , "lfv tree systematic TaSmeDet_SysUp"   );
    lfvTree_TaSmeDet_SysDown = new TTree("lfv_TaSmeDet_SysDown" , "lfv tree systematic TaSmeDet_SysDown" );
    lfvTree_TaSmeMod_SysUp   = new TTree("lfv_TaSmeMod_SysUp"   , "lfv tree systematic TaSmeMod_SysUp"   );
    lfvTree_TaSmeMod_SysDown = new TTree("lfv_TaSmeMod_SysDown" , "lfv tree systematic TaSmeMod_SysDown" );
    lfvTree_JtSme_SysUp      = new TTree("lfv_JtSme_SysUp"      , "lfv tree systematic JtSme_SysUp"      );
    lfvTree_JtUncNP1_SysUp   = new TTree("lfv_JtUncNP1_SysUp"   , "lfv tree systematic JtUncNP1_SysUp"   );
    lfvTree_JtUncNP1_SysDown = new TTree("lfv_JtUncNP1_SysDown" , "lfv tree systematic JtUncNP1_SysDown" );
    lfvTree_JtUncNP2_SysUp   = new TTree("lfv_JtUncNP2_SysUp"   , "lfv tree systematic JtUncNP2_SysUp"   );
    lfvTree_JtUncNP2_SysDown = new TTree("lfv_JtUncNP2_SysDown" , "lfv tree systematic JtUncNP2_SysDown" );
    lfvTree_JtUncNP3_SysUp   = new TTree("lfv_JtUncNP3_SysUp"   , "lfv tree systematic JtUncNP3_SysUp"   );
    lfvTree_JtUncNP3_SysDown = new TTree("lfv_JtUncNP3_SysDown" , "lfv tree systematic JtUncNP3_SysDown" );
    lfvTree_JtUncETA_SysUp   = new TTree("lfv_JtUncETA_SysUp"   , "lfv tree systematic JtUncETA_SysUp"   );
    lfvTree_JtUncETA_SysDown = new TTree("lfv_JtUncETA_SysDown" , "lfv tree systematic JtUncETA_SysDown" );
    lfvTree_MetResPara       = new TTree("lfv_MetResPara"       , "lfv tree systematic MetResPara"       );
    lfvTree_MetResPerp       = new TTree("lfv_MetResPer"        , "lfv tree systematic MetResPer"        );
    lfvTree_MetScl_SysUp     = new TTree("lfv_MetScl_SysUp"     , "lfv tree systematic MetScl_SysUp"     );
    lfvTree_MetScl_SysDown   = new TTree("lfv_MetScl_SysDown"   , "lfv tree systematic MetScl_SysDown"   );
    
  }

  if( m_verbose ) Info( "DefineTrees()", "Trees Defined!" );
  
}

void HighMassLFV :: DefineTreesMap(){
  
  m_TreesMap [ 0 ] = lfvTree;
  if( m_doSyst ){
    m_TreesMap [ Mu_SHSys::MuSmeID_SysUp    ] = lfvTree_MuSmeID_SysUp;
    m_TreesMap [ Mu_SHSys::MuSmeID_SysDown  ] = lfvTree_MuSmeID_SysDown;
    m_TreesMap [ Mu_SHSys::MuSmeMS_SysUp    ] = lfvTree_MuSmeMS_SysUp;
    m_TreesMap [ Mu_SHSys::MuSmeMS_SysDown  ] = lfvTree_MuSmeMS_SysDown;
    m_TreesMap [ Mu_SHSys::MuScale_SysUp    ] = lfvTree_MuScale_SysUp;
    m_TreesMap [ Mu_SHSys::MuScale_SysDown  ] = lfvTree_MuScale_SysDown;
    m_TreesMap [ Mu_SHSys::MuSagRho_SysUp   ] = lfvTree_MuSagRho_SysUp;
    m_TreesMap [ Mu_SHSys::MuSagRho_SysDown ] = lfvTree_MuSagRho_SysDown;
    m_TreesMap [ Mu_SHSys::MuSagRes_SysUp   ] = lfvTree_MuSagRes_SysUp;
    m_TreesMap [ Mu_SHSys::MuSagRes_SysDown ] = lfvTree_MuSagRes_SysDown;
    m_TreesMap [ El_SHSys::ElSme_SysUp      ] = lfvTree_ElSme_SysUp;
    m_TreesMap [ El_SHSys::ElSme_SysDown    ] = lfvTree_ElSme_SysDown;
    m_TreesMap [ El_SHSys::ElScale_SysUp    ] = lfvTree_ElScale_SysUp;
    m_TreesMap [ El_SHSys::ElScale_SysDown  ] = lfvTree_ElScale_SysDown;
    m_TreesMap [ Ta_SHSys::TaSme_SysUp      ] = lfvTree_TaSme_SysUp;
    m_TreesMap [ Ta_SHSys::TaSme_SysDown    ] = lfvTree_TaSme_SysDown;
    m_TreesMap [ Ta_SHSys::TaSmeDet_SysUp   ] = lfvTree_TaSmeDet_SysUp;
    m_TreesMap [ Ta_SHSys::TaSmeDet_SysDown ] = lfvTree_TaSmeDet_SysDown;
    m_TreesMap [ Ta_SHSys::TaSmeMod_SysUp   ] = lfvTree_TaSmeMod_SysUp;
    m_TreesMap [ Ta_SHSys::TaSmeMod_SysDown ] = lfvTree_TaSmeMod_SysDown;
    m_TreesMap [ Jt_SHSys::JtSme_SysUp      ] = lfvTree_JtSme_SysUp; 
    m_TreesMap [ Jt_UNSys::JtUncNP1_SysUp   ] = lfvTree_JtUncNP1_SysUp;	 
    m_TreesMap [ Jt_UNSys::JtUncNP1_SysDown ] = lfvTree_JtUncNP1_SysDown;
    m_TreesMap [ Jt_UNSys::JtUncNP2_SysUp   ] = lfvTree_JtUncNP2_SysUp;	 
    m_TreesMap [ Jt_UNSys::JtUncNP2_SysDown ] = lfvTree_JtUncNP2_SysDown;
    m_TreesMap [ Jt_UNSys::JtUncNP3_SysUp   ] = lfvTree_JtUncNP3_SysUp;	 
    m_TreesMap [ Jt_UNSys::JtUncNP3_SysDown ] = lfvTree_JtUncNP3_SysDown;
    m_TreesMap [ Jt_UNSys::JtUncETA_SysUp   ] = lfvTree_JtUncETA_SysUp;	 
    m_TreesMap [ Jt_UNSys::JtUncETA_SysDown ] = lfvTree_JtUncETA_SysDown;	 
    m_TreesMap [ Met_SHSys::MetResPara      ] = lfvTree_MetResPara;
    m_TreesMap [ Met_SHSys::MetResPerp      ] = lfvTree_MetResPerp;
    m_TreesMap [ Met_SHSys::MetScl_SysUp    ] = lfvTree_MetScl_SysUp;
    m_TreesMap [ Met_SHSys::MetScl_SysDown  ] = lfvTree_MetScl_SysDown;
  }

  if( m_verbose ) Info( "DefineTreesMap()", "Trees Map Defined!" );

}
