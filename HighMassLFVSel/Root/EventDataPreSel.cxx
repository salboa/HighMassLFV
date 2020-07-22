#include <HighMassLFVSel/HighMassLFV.h>

bool HighMassLFV :: IsSimulation(){
  
  if( m_eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION ) ){
    return true;
  }
  return false;
  
}

bool HighMassLFV :: VertexCheck(){
  
  bool m_check = false;
  if(m_priVtxFound)
    if( m_priVtx->nTrackParticles() >= 2 ) m_check = true;
  if( m_debug ) Info( "VertexCheck()", "vertex check = %i", m_check );  
  return m_check;
  
}

void HighMassLFV :: FindPriVtx(){

  m_priVtx = PriVtx();
  
  
}

const xAOD::Vertex* HighMassLFV :: PriVtx(){
  
  m_priVtxFound = false;
  const xAOD::Vertex* vtx = NULL;
  for(uint i = 0; i<m_vertexCont->size(); i++){
    const xAOD::Vertex* vx = m_vertexCont->at(i);
    if( vx->vertexType() == xAOD::VxType::PriVtx ){
      vtx = vx;
      if( m_debug ) Info( "PriVtx()", "Primary vertex found!" );
      m_priVtxFound = true;
      break;
    }
  }
  return vtx;
  
}

bool HighMassLFV :: EventCheck(){

  bool m_check = true;
  
  if( isMC ){
    if( m_debug ) Info( "EventCheck()", "Running on Simulation: Event GOOD!" );
    return m_check;
  }
  else{
    if( !larErrorCheck() )  m_check = false;
    if( !tileErrorCheck() ) m_check = false;
    if( !coreFlagCheck() )  m_check = false;
    if( !tileTripCheck() )  m_check = false;
    if( !sctErrorCheck() )  m_check = false;
    if( !GRLCheck() )       m_check = false;
  }
  if( m_debug ) Info( "EventCheck()", "Running on Data: passed all check = %i", m_check );
  
  return m_check;
  
}

bool HighMassLFV :: larErrorCheck(){
  
  bool m_check = true;
  if( m_eventInfo->errorState(xAOD::EventInfo::LAr) == xAOD::EventInfo::Error ) m_check = false;
  if( m_debug ) Info( "larErrorCheck()", "LAr check = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: tileErrorCheck(){
  
  bool m_check = true;
  if(m_eventInfo->errorState(xAOD::EventInfo::Tile) == xAOD::EventInfo::Error) m_check = false;
  if( m_debug ) Info( "tileErrorCheck()", "Tile check = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: coreFlagCheck(){
  
  bool m_check = true;
  if(m_eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core, 18)) m_check = false;
  if( m_debug ) Info( "coreFlagCheck()", "CoreFlag check = %i", m_check );
  return m_check;
    
}

bool HighMassLFV :: tileTripCheck(){
  
  /*to be updated*/
  bool m_check = true;
  if( m_debug ) Info( "tileTripCheck()", "TileTrip check = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: sctErrorCheck(){
  
  bool m_check = true;
  if( m_eventInfo->errorState(xAOD::EventInfo::SCT) == xAOD::EventInfo::Error ) m_check = false;
  if( m_debug ) Info( "sctErrorCheck()", "SCT check = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: GRLCheck(){
  
  bool m_check  = m_grl->passRunLB( m_eventInfo->runNumber(), m_eventInfo->lumiBlock() );
  if( m_debug ) Info( "GRLCheck()", "GRL check = %i", m_check );
  return m_check;
  
}
