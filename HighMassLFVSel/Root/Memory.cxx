#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: CreateShallowCopies(){

  if( m_debug ) Info( "CreateShallowCopies()", "Creating Shallow Copies ..." );
  
  if( m_UseCorr || m_UseData){ //before was only m_UseCorre // to be removed
    m_taus_shallowCopy = xAOD::shallowCopyContainer( *m_tauCont );
    m_tauContCopy = m_taus_shallowCopy.first;
    //}
    //if( m_UseCorr || m_UseData ){ //to be removed
    m_electrons_shallowCopy = xAOD::shallowCopyContainer( *m_elecCont );
    m_elecContCopy = m_electrons_shallowCopy.first;
    m_jets_shallowCopy = xAOD::shallowCopyContainer( *m_jetCont );
    m_jetContCopy = m_jets_shallowCopy.first;
    m_photons_shallowCopy = xAOD::shallowCopyContainer( *m_phCont );
    m_phContCopy = m_photons_shallowCopy.first;
    m_muons_shallowCopy = xAOD::shallowCopyContainer( *m_muonCont );
    m_muonContCopy = m_muons_shallowCopy.first;
  }

  if( m_debug ) Info( "CreateShallowCopies()", "Shallow Copies Created!" );
  
}

void HighMassLFV :: DeleteShallowCopies(bool useStore){
  
  if( m_debug ) Info( "DeleteShallowCopies()", "Deleting Shallow Copies ..." );
  
  if( m_UseCorr || m_UseData ){ //before was only m_UseCorre // to be removed
    if(!useStore)
      delete m_taus_shallowCopy.first;
    delete m_taus_shallowCopy.second;
  }
  if( m_UseCorr || m_UseData ){ //to be removed
    if(!useStore){
      delete m_electrons_shallowCopy.first;
      delete m_photons_shallowCopy.first;
      delete m_muons_shallowCopy.first;
      delete m_jets_shallowCopy.first;
    }
    delete m_electrons_shallowCopy.second;
    delete m_photons_shallowCopy.second;
    delete m_muons_shallowCopy.second;
    delete m_jets_shallowCopy.second; 
  }
  if( m_debug ) Info( "DeleteShallowCopies()", "Shallow Copies Deleted!" );
  
}

void HighMassLFV :: CleanObjVectors(){

  if( m_debug ) Info( "CleanObjVectors()", "Cleaning Object Vectors ..." );

  /* objetcs */
  m_Muons.clear();
  m_AddMuons.clear();
  m_Electrons.clear();
  m_AddElectrons.clear();
  m_Taus.clear();
  m_Jets.clear();
  
  /* objetcs for MET */
  m_MetMuons->clear();
  m_MetElectrons->clear();
  m_MetTaus->clear();
  m_MetPhotons->clear();

  if( m_debug ) Info( "CleanObjVectors()", "Object Vectors Cleaned!" );

}

void HighMassLFV :: ResetContainers(){

  if( m_debug ) Info( "ResetContainers()", "Resetting Data Containers ..." );

  //m_vertexCont = 0;
  //m_muonCont   = 0;
  //m_elecCont   = 0;
  //m_tauCont    = 0;
  //m_jetCont    = 0;
  //m_phCont     = 0;
  //m_metCont    = 0;
  //m_metMapCont = 0;
  //m_thpartCont = 0;

  m_SelectedMuon->clear();
  //m_SelectedMuonAux = 0; //check
  m_newMuon = 0;
  m_BuildMet->clear();
  //m_BuildMetAux = 0; //check
  m_softTrkMet = 0;
  m_store->clear();

  if( m_debug ) Info( "ResetContainers()", "Data Containers Reset!" );
  
}

void HighMassLFV:: CleanMemory(bool useStore){

  if( m_debug ) Info( "CleanMemory()", "Cleaning Memory ... " );
  
  CleanObjVectors();
  ResetVariables();
  DeleteShallowCopies(useStore);
  ResetContainers();

  if( m_debug ) Info( "CleanMemory()", "Memory Cleaned!" );
  
}
