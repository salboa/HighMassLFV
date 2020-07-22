#include <HighMassLFVSel/HighMassLFV.h>

void HighMassLFV :: BuildMET(int sysVar){

  //below shoud be removed before USeCorr will be default
  //if( !m_UseCorr && !m_UseData ){ 
  //  m_jets_shallowCopy = xAOD::shallowCopyContainer( *m_jetCont );
  //  m_jetContCopy = m_jets_shallowCopy.first;
  //  
  //  for( auto jt: *m_jetContCopy ) {
  //    if( m_jetCalib->applyCalibration(*jt) == CP::CorrectionCode::Error ){
  //	Info( "BuildMET()", "JetCalibrationTool returns Error CorrectionCode in applying corrections");
  //    }
  //    float jvt = m_jetVtxTagUp->updateJvt(*jt);
  //    jt->auxdecor<float>("Jvt") = jvt;
  //    
  //  }
  //  if( m_jetFrwJvtTool->modify(*m_jetContCopy)!=0 ){
  //    Info( "CheckCorrectedJets()", "JetForwardJvtTool failed to apply changes to jet container" );
  //  }
  //}
  
  LinkObjects();
  StoreObjects();
  FeedMetMaker();
  
  if( m_MetVar.find(sysVar) == m_MetVar.end() ){
    if( m_debug ) Info( "BuildMET()", "Systematic set not found, applying nominal one (no systematics)!");
    if( m_metSys->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
      Info( "BuildMET()", "METSystematicsTool variation 'empty' (Nominal) not supported" );
    }
  }
  else{
    if( m_debug ) Info( "BuildMET()", "Applying variation %s", m_MetVarName[sysVar].c_str() );
    if( m_metSys->applySystematicVariation( m_MetVar[sysVar] ) == CP::SystematicCode::Unsupported ){
      Info( "BuildMET()", "METSystematicsTool variation %s not supported", m_MetVarName[sysVar].c_str() );
    }
  }

  m_softTrkMet = (*m_BuildMet)["PVSoftTrk"];
  if( m_UseCorr ){
    if(m_metSys->applyCorrection(*m_softTrkMet) == CP::CorrectionCode::Error){
      Info( "BuidMET()", "METSystematicsTool returns Error CorrectionCode in applying corrections" );
    }
  }
  
  if( !m_metMaker->buildMETSum( "FinalTrk" , m_BuildMet, MissingETBase::Source::Track ).isSuccess() )
    Info( "BuidMET()", "METMaker returns Error in building METSum" );
  
  if( m_debug ) Info( "BuildMET()", "Missing Energy Built!" );
  
}

void HighMassLFV :: LinkObjects(){
  
  if( !xAOD::setOriginalObjectLink( *m_jetCont, *m_jetContCopy ) )
    Info( "LinkObjects()", "ERROR::Failed to set the original jet object links!" );
  
  if( m_UseCorr || m_UseData ){ //before was only m_UseCorr
    if( !xAOD::setOriginalObjectLink( *m_tauCont, *m_tauContCopy ) )
      Info( "LinkObjects()", "ERROR::Failed to set the original tau object links!" );
  }
  
  if( m_UseCorr || m_UseData ){
    if( !xAOD::setOriginalObjectLink( *m_elecCont, *m_elecContCopy ) )
      Info( "LinkObjects()", "ERROR::Failed to set the original electron object links!" );
    if( !xAOD::setOriginalObjectLink( *m_phCont, *m_phContCopy ) )
      Info( "LinkObjects()", "ERROR::Failed to set the original photon object links!" );
    if( !xAOD::setOriginalObjectLink( *m_muonCont, *m_muonContCopy ) )
      Info( "LinkObjects()", "ERROR::Failed to set the original muon object links!" );
  }

  if( m_debug ) Info( "LinkObjects()", "Corrected and Orignal Objects Linked" );
  
}

void HighMassLFV :: StoreObjects(){

  /* jets*/
  if( !m_store->record(m_jetContCopy, "CalibJets").isSuccess() )
    Info( "StoreObjects()", "ERROR::Failed to store CalibJets in Event Store" );
  
  /* taus */
  if( m_UseCorr || m_UseData ){ //before was only m_UseCorr //to be removed
    if( !m_store->record(m_tauContCopy, "CalibTaus").isSuccess() )
      Info( "StoreObjects()", "ERROR::Failed to store CalibTaus in Event Store" );
  }
  
  if( m_UseCorr || m_UseData ){ //to be removed
    /* electrons */
    if( !m_store->record(m_elecContCopy, "CalibElectrons").isSuccess() )
      Info( "StoreObjects()", "ERROR::Failed to store CalibElectrons in Event Store" );
    /* photons */
    if( !m_store->record(m_phContCopy, "CalibPhotons").isSuccess() )
      Info( "StoreObjects()", "ERROR::Failed to store CalibPhotons in Event Store" );
    /* muons */
    if( !m_store->record(m_muonContCopy, "CalibMuons").isSuccess() )
      Info( "StoreObjects()", "ERROR::Failed to store CalibMuons in Event Store" );
  }

  if( m_debug ) Info( "StoreObjects()", "Corrected Objects Store in Event Store" );
  
}

void HighMassLFV :: FeedMetMaker(){

  m_BuildMet->setStore(m_BuildMetAux);
  m_metMapCont->resetObjSelectionFlags();

  if( m_verbose ) Info( "FeedMetMaker()", "MetMap Selection Flag reset!" );
  
  /* Add Electrons, Photons and Muons */
  //if( m_UseCorr || m_UseData ){
  if( !m_metMaker->rebuildMET( "RefEle", xAOD::Type::Electron, m_BuildMet, m_MetElectrons, m_metMapCont ).isSuccess() ){
    Info( "FeedMetMaker()", "Error in feeding MetMaker with corrected electrons" );
  }
  if( !m_metMaker->rebuildMET( "RefPhoton", xAOD::Type::Photon, m_BuildMet, m_MetPhotons, m_metMapCont ).isSuccess() ){
    Info( "FeedMetMaker()", "Error in feeding MetMaker with corrected photons" );
  }
  if( !m_metMaker->rebuildMET( "RefMuon", xAOD::Type::Muon, m_BuildMet, m_MetMuons, m_metMapCont ).isSuccess() ){
    Info( "FeedMetMaker()", "Error in feeding MetMaker with corrected muons" );
  }
  if( !m_metMaker->rebuildMET( "RefTau", xAOD::Type::Tau, m_BuildMet, m_MetTaus, m_metMapCont ).isSuccess() ){
    Info( "FeedMetMaker()", "Error in feeding MetMaker with corrected taus" );
  }
  if( m_verbose )
    Info( "FeedMetMaker()", "Corrected objects: Electrons = %i , Photons = %i , Muons = %i , Taus = %i", 
	  (int)m_MetElectrons->size(), (int)m_MetPhotons->size(), (int)m_MetMuons->size(), (int)m_MetTaus->size() );
  //}
  //else{
  //  assert( m_metMaker->rebuildMET( "RefEle", xAOD::Type::Electron, m_BuildMet, m_MetElectrons->asDataVector(), m_metMapCont ) );
  //  assert( m_metMaker->rebuildMET( "RefPhoton", xAOD::Type::Photon, m_BuildMet, m_MetPhotons->asDataVector(), m_metMapCont ) );
  //  assert( m_metMaker->rebuildMET( "RefMuon", xAOD::Type::Muon, m_BuildMet, m_MetMuons->asDataVector(), m_metMapCont ) );
  //  if( m_verbose )
  //    Info( "FeedMetMaker()", "Raw objects: Electrons = %i , Photons = %i , Muons = %i", 
  //          (int)m_MetElectrons->size(), (int)m_MetPhotons->size(), (int)m_MetMuons->size() );
  //}
    
  /* Adding Taus */
  //if( !m_UseCorr || !m_UseData ){ // before was m_UseData
  //  assert( m_metMaker->rebuildMET( "RefTau", xAOD::Type::Tau, m_BuildMet, m_MetTaus->asDataVector(), m_metMapCont ) );
  //  if( m_verbose )
  //    Info( "FeedMetMaker()", "Raw objects: Taus = %i , Muons = %i ", (int)m_MetTaus->size(), (int)m_MetMuons->size() );
  //  }
  //else{
  //assert( m_metMaker->rebuildMET( "RefTau", xAOD::Type::Tau, m_BuildMet, m_MetCorrTaus, m_metMapCont ) );
  //if( !m_metMaker->rebuildMET( "RefTau", xAOD::Type::Tau, m_BuildMet, m_MetTaus, m_metMapCont ).isSuccess() ){
  //Info( "FeedMetMaker()", "Error in feeding MetMaker with corrected taus" );
  //}
  //if( m_verbose )
  //Info( "FeedMetMaker()", "Corrected objects: Taus = %i", (int)m_MetCorrTaus->size() );
  //}
  
  /* Adding Jets */
  //assert(  m_metMaker->rebuildJetMET( "RefJet", "SoftClus", "PVSoftTrk", m_BuildMet, m_jetContCopy, m_metCont, m_metMapCont, true ) );
  if( !m_metMaker->rebuildJetMET( "RefJet", "SoftClus", "PVSoftTrk", m_BuildMet, m_jetContCopy, m_metCont, m_metMapCont, true ).isSuccess() ){
    Info( "FeedMetMaker()", "Error in feeding MetMaker with corrected jets" );
  }
  if( m_verbose ) Info( "FeedMetMaker()", "Corrected objects: Jets =%i ", (int)m_jetContCopy->size() );
  
  if( m_debug ) Info("FeedMetMaker()", "MetMaker filled with all needed Objects");
  
}

void HighMassLFV :: FillMETQuantities(){
	
  met_et    = (*m_BuildMet)["FinalTrk"]->met()/GeV;
  met_px    = (*m_BuildMet)["FinalTrk"]->mpx()/GeV;
  met_py    = (*m_BuildMet)["FinalTrk"]->mpy()/GeV;
  met_phi   = (*m_BuildMet)["FinalTrk"]->phi();
  met_sumet = (*m_BuildMet)["FinalTrk"]->sumet()/GeV;
  
  if( m_verbose ) 
    Info( "FillMETQuantities()"," MET Values: et = %f , px = %f , py = %f , phi = %f , sumet = %f",
	  met_et, met_px, met_py, met_phi, met_sumet);
  
}

void HighMassLFV :: CleanMET(){
  
  m_BuildMet->clear();
  m_softTrkMet = 0;
  m_store->clear();
  
}
