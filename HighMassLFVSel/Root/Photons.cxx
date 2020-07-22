#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: SelectPhotons(int sysVar){

  if( m_debug ) Info( "SelectPhotons()", "Selecting Photons ..." );

  m_MetPhotons->clear();
  for( auto ph: *m_phContCopy) {
    if( m_elSmear->applyCorrection(*ph) == CP::CorrectionCode::Error ){
      Info( "SelectPhotons()", "PhotonCalibrationAndSmearingTool returns Error CorrectionCode");
    }
    double pt       = ph->pt();
    double eta      = ph->caloCluster()->etaBE(2);
    uint16_t author = ph->author();
    
    if( m_verbose ){
      Info( "SelectPhotons()", "  Photon found --> pt = %f , eta = %f , author = %i ", pt/GeV, eta, author );
    }
    
    if( pt/GeV<10. ){ ph->auxdecor<char>("isPreSel") = false; continue; }
    
    UpdatePhFlow( sysVar, PhFlow::Pt, 1 );
    
    if( fabs(eta)>2.47 ){ ph->auxdecor<char>("isPreSel") = false; continue; }
    if( fabs(eta)>1.37 && fabs(eta)<1.52 ){ ph->auxdecor<char>("isPreSel") = false; continue; }
    UpdatePhFlow( sysVar, PhFlow::Eta, 1 );
    
    if( author!=xAOD::EgammaParameters::AuthorPhoton &&
        author!=xAOD::EgammaParameters::AuthorAmbiguous ){ ph->auxdecor<char>("isPreSel") = false; continue; }
    UpdatePhFlow( sysVar, PhFlow::Author, 1 );

    bool ObjQual    = ph->isGoodOQ(xAOD::EgammaParameters::BADCLUSPHOTON);
    bool clean      = false;
    bool cleanDel   = false;
    if(m_evalEgQuant){
      clean      = PhotonHelpers::passOQquality(ph);
      cleanDel   = PhotonHelpers::passOQqualityDelayed(ph);
    }
    else{
      clean    = ph->auxdata<char>("DFCommonPhotonsCleaning");
      cleanDel = ph->auxdata<char>("DFCommonPhotonsCleaningNoTime");
    }
    
    if( !ObjQual ){ ph->auxdecor<char>("isPreSel") = false; continue; }
    UpdatePhFlow( sysVar, PhFlow::ObjQual, 1 );
    
    if( !clean    ){ ph->auxdecor<char>("isPreSel") = false; continue; }
    if( !cleanDel ){ ph->auxdecor<char>("isPreSel") = false; continue; }
    UpdatePhFlow( sysVar, PhFlow::Clean, 1 );
    
    if( m_debug ){
      Info( "SelectPhotons()", "  GOOD Photon --> pt = %f , eta = %f , author = %i , ObjQua = %i , Cleaning = %i",
            pt/GeV, eta, author, ObjQual, clean );
    }
    
    m_MetPhotons->push_back(ph);
    ph->auxdecor<char>("isPreSel") = true;
   
  }
  
}
