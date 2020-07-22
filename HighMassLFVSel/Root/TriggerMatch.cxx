#include <HighMassLFVSel/HighMassLFV.h>

bool HighMassLFV :: CheckMuonTriggerMatching(const xAOD::IParticle *p){
  
  bool m_check = false;
  if(p->type() != xAOD::Type::Muon){
    if( m_debug ) Info( "CheckMuonTriggerMatching()" , "Particle is not a muon!!!  returning false" );
    return false;
  }
  const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
  for(uint i=0; i<m_MuTrigChains[m_year].size(); i++){
    if( m_trigMatch->match( *mu, m_MuTrigChains[m_year].at(i), 0.1, false ) )
      m_check =true;
  }
  if( m_debug ) Info( "CheckMuonTriggerMatching()" , "trigger matched = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: CheckElectronTriggerMatching(const xAOD::IParticle *p){
  
  bool m_check = false;
  if(p->type() != xAOD::Type::Electron){
    if( m_debug ) Info( "CheckElectronTriggerMatching()" , "Particle is not an electron!!!  returning false" );
    return false;
  }
  const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
  for(uint i=0; i<m_ElTrigChains[m_year].size(); i++){
    if( m_trigMatch->match( *el, m_ElTrigChains[m_year].at(i), 0.07, false ) )
      m_check =true;
  }
  if( m_debug ) Info( "CheckElectronTriggerMatching()" , "trigger matched = %i", m_check );
  return m_check;
  
}
