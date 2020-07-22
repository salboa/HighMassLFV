#include <HighMassLFVSel/HighMassLFV.h>

bool HighMassLFV :: CheckLeptons(){
  
  bool m_check = false;
  if( (m_Muons.size()+m_Electrons.size()+m_Taus.size())>1 ){
    m_check = true;
    if( m_debug ) Info( "CheckLeptons()", "At least 2 leptons found: Muons = %i , electrons = %i , taus = %i ",
                        (int)m_Muons.size(), (int)m_Electrons.size(), (int)m_Taus.size() );
  }
  return m_check;
  
}

bool HighMassLFV :: CheckNumOfLeptons(){

  bool m_check = true;
  if( m_Muons.size()>1 || m_Electrons.size()>1 || m_Taus.size()>1 ||
      (m_Muons.size()==1 && m_Electrons.size()==1 && m_Taus.size()==1) ){
    m_check = false;
    if( m_debug ) Info( "CheckNumOfLeptons()", "Too many Leptons found: Muons = %i , electrons = %i , taus = %i ",
			(int)m_Muons.size(), (int)m_Electrons.size(), (int)m_Taus.size() );
  }
  else if( (m_Muons.size()+m_Electrons.size()+m_Taus.size())<2 ){
    m_check = false;
    if( m_debug ) Info( "CheckNumOfLeptons()", "Not enough Leptons found: Muons = %i , electrons = %i , taus = %i",
			(int)m_Muons.size(), (int)m_Electrons.size(), (int)m_Taus.size() );
  }
  else{
    if( m_debug ) Info( "CheckNumOfLeptons()", "Enough Leptons found: Muons = %i , electrons = %i , taus = %i",
                        (int)m_Muons.size(), (int)m_Electrons.size(), (int)m_Taus.size() );
    if( m_Muons.size()==1 && m_Electrons.size()==1 && ( m_AddMuons.size()>0 || m_AddElectrons.size()>0 ) ){
      m_check = false;
      if( m_debug ) Info( "                   ", "  but too many Loose Leptons found: AddMuons = %i , AddElectrons = %i ",
			  (int)m_AddMuons.size(), (int)m_AddElectrons.size() );
      }
  }
  return m_check;
  
}

int HighMassLFV :: LeptonCharge(const xAOD::IParticle *p){
  
  int charge = 0;
  
  if( p->type() == xAOD::Type::Electron ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    charge = el->trackParticle()->charge();
  }
  else if( p->type() == xAOD::Type::Muon ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    charge = mu->primaryTrackParticle()->charge();
  }
  else if( p->type() == xAOD::Type::Tau ){
    const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    charge = tau->charge();
  }
  return charge;
    
}

double HighMassLFV :: LeptonZ0(const xAOD::IParticle *p){
  
  double z0 = 9999;
  if( p->type() == xAOD::Type::Electron ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    z0 = el->trackParticle()->z0();
  }
  else if( p->type() == xAOD::Type::Muon ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    z0 = mu->primaryTrackParticle()->z0();
  }
  else if( p->type() == xAOD::Type::Tau ){
    //const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    z0 = 9999;
  }
  return z0;
  
}

double HighMassLFV :: LeptonDeltaZ0(const xAOD::IParticle *p){
  
  double delta_z0 = 9999;
  if( p->type() == xAOD::Type::Electron ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    const xAOD::TrackParticle* trk = el->trackParticle();
    const xAOD::Vertex* vtx = m_priVtx;
    delta_z0 = fabs( ( trk->z0() + trk->vz() - vtx->z() ) * sin(trk->theta()) );
  }
  else if( p->type() == xAOD::Type::Muon ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    const xAOD::TrackParticle* trk = mu->primaryTrackParticle();//trackParticle(xAOD::Muon::TrackParticleType::CombinedTrackParticle);
    const xAOD::Vertex* vtx = m_priVtx;
    delta_z0 = fabs( ( trk->z0() + trk->vz() - vtx->z() ) * sin(trk->theta()) );
  }
  else if( p->type() == xAOD::Type::Tau ){
    //const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    delta_z0 = 9999;
  }

  return delta_z0;
  
}

double HighMassLFV :: LeptonD0(const xAOD::IParticle *p){
  
  double d0 = 9999;
  if( p->type() == xAOD::Type::Electron ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    d0 = el->trackParticle()->d0();
  }
  else if( p->type() == xAOD::Type::Muon ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    d0 = mu->primaryTrackParticle()->d0();
  }
  else if( p->type() == xAOD::Type::Tau ){
    //const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    d0 = 9999;
  }

  return d0;
  
}

double HighMassLFV :: LeptonD0Sign(const xAOD::IParticle *p){
  
  double d0sig = 9999;
  if( p->type() == xAOD::Type::Electron ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    //double d0   = el->trackParticle()->d0();
    //double cov  = el->trackParticle()->definingParametersCovMatrix()(TrkParam::d0,TrkParam::d0);
    //double beam = m_eventInfo->beamPosSigmaX()*m_eventInfo->beamPosSigmaX() + m_eventInfo->beamPosSigmaY()*m_eventInfo->beamPosSigmaY();
    //d0sig = fabs( d0/sqrt(cov+beam) );
    const xAOD::TrackParticle* trk = el->trackParticle();
    d0sig = fabs( xAOD::TrackingHelpers::d0significance( trk, m_eventInfo->beamPosSigmaX(), m_eventInfo->beamPosSigmaY(), m_eventInfo->beamPosSigmaXY() ) );
  }
  else if( p->type() == xAOD::Type::Muon ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    const xAOD::TrackParticle* trk = mu->primaryTrackParticle();//trackParticle(xAOD::Muon::TrackParticleType::CombinedTrackParticle);
    //double d0   = trk->d0();
    //double cov  = trk->definingParametersCovMatrix()(TrkParam::d0,TrkParam::d0);
    //double beam = m_eventInfo->beamPosSigmaX()*m_eventInfo->beamPosSigmaX() + m_eventInfo->beamPosSigmaY()*m_eventInfo->beamPosSigmaY();
    //d0sig = fabs( d0/sqrt(cov+beam) );
    d0sig = fabs( xAOD::TrackingHelpers::d0significance( trk, m_eventInfo->beamPosSigmaX(), m_eventInfo->beamPosSigmaY(), m_eventInfo->beamPosSigmaXY() ) );
  }
  else if( p->type() == xAOD::Type::Tau ){
    //const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    d0sig = 9999;
  }
  return d0sig;
  
}

double HighMassLFV :: LeptonMass(const xAOD::IParticle *p){

  double lepMass = 0;
  if( p->type() == xAOD::Type::Electron )
    lepMass = ElectronMass;
  else if( p->type() == xAOD::Type::Muon )
    lepMass = MuonMass;
  else if( p->type() == xAOD::Type::Tau )
    lepMass = TauMass;
  
  return lepMass;

}

double HighMassLFV :: LeptonEta(const xAOD::IParticle *p, bool elCalo){
  
  double lepEta = 0;
  if( p->type() == xAOD::Type::Electron ){
    const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
    if(elCalo) lepEta = el->caloCluster()->etaBE(2);
    else       lepEta = el->eta();
  }
  else if( p->type() == xAOD::Type::Muon ){
    const xAOD::Muon* mu = dynamic_cast<const xAOD::Muon*> (p);
    lepEta = mu->eta();
  }
  else if( p->type() == xAOD::Type::Tau ){
    const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
    lepEta = tau->eta();
  }
  
  return lepEta;
  
}

double HighMassLFV :: LeptonSF(const xAOD::IParticle *p){
  
  double m_sf = 1;
  if(p->type() == xAOD::Type::Electron){
    m_sf = GetElectronRecoSF(p)*GetElectronIDSF(p)*GetElectronIsoSF(p)*GetElectronTrigSF(p)*GetElectronL1CaloSF(p);
    if( m_debug ) Info( "LeptonSF()", "Electron SF (total) = %f", m_sf );
  }
  else if( p->type() == xAOD::Type::Muon ){
    m_sf = GetMuonRecoSF(p)*GetMuonIsoSF(p)*GetMuonTriggerSF(p)*GetMuonTtvaSF(p)*GetBadMuonVetoSF(p);
    if( m_debug ) Info( "LeptonSF()", "Muon SF (total) = %f", m_sf );
  }
  else if( p->type() == xAOD::Type::Tau ){
    m_sf = GetTauRecoSF(p)*GetTauEleOlrSF(p)*GetTauJetIDSF(p);
    if( m_debug ) Info( "LeptonSF()", "Tau SF (total) = %f", m_sf );
  }
  return m_sf;
  
}

bool HighMassLFV :: IsElectronMuonOverlap(const xAOD::IParticle *p){
  
  bool m_check = false;
  if( p->type() != xAOD::Type::Electron ){
    if( m_debug ) Info( "IsElectronMuonOverlap()" , "Particle is not an electron!!!  returning 0" );
    return false;
  }
  const xAOD::Electron* el = dynamic_cast<const xAOD::Electron*> (p);
  for( uint m=0; m<m_Muons.size(); m++ ){
    const xAOD::Muon* mu = m_Muons.at(m);
    if( CheckLepsDR(el,mu) ){
      m_check = true;
      break;
    }
  }
  for( uint m=0; m<m_AddMuons.size(); m++ ){
    const xAOD::Muon* mu = m_AddMuons.at(m);
    if( CheckLepsDR(el,mu) ){
      m_check = true;
      break;
    }
  }
  if( m_debug ) Info( "IsElectronMuonOverlap()", "Electron-Muon overlap = %i", m_check );
  if( m_check )
    if( m_debug ) Info( "IsElectronMuonOverlap()", "Rejecting electron" );
  
  return m_check;
}

bool HighMassLFV :: IsTauMuonOverlap(const xAOD::IParticle *p){

  bool m_check = false;
  if( p->type() != xAOD::Type::Tau ){
    if( m_debug ) Info( "CheckTauMuonOverlap()" , "Particle is not a tau!!!  returning 0" );
    return false;
  }
  const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
  for( uint m=0; m<m_Muons.size(); m++ ){
    const xAOD::Muon* mu = m_Muons.at(m);
    if( CheckLepsDR(tau,mu) ){
      m_check = true;
      break;
    }
  }
  for( uint m=0; m<m_AddMuons.size(); m++ ){
    const xAOD::Muon* mu = m_AddMuons.at(m);
    if( CheckLepsDR(tau,mu) ){
      m_check = true;
      break;
    }
  }
  if( m_debug ) Info( "IsTauMuonOverlap()", "Tau-Muon overlap = %i", m_check );
  if( m_check )
    if( m_debug ) Info( "IsTauMuonOverlap()", "Rejecting tau" );

  return m_check;
}

bool HighMassLFV :: IsTauElecOverlap(const xAOD::IParticle *p){

  bool m_check = false;
  if( p->type() != xAOD::Type::Tau ){
    if( m_debug ) Info( "CheckTauElecOverlap()" , "Particle is not a tau!!!  returning 0" );
    return false;
  }
  const xAOD::TauJet* tau = dynamic_cast<const xAOD::TauJet*> (p);
  for( uint e=0; e<m_Electrons.size(); e++ ){
    const xAOD::Electron* el = m_Electrons.at(e);
    if( CheckLepsDR(tau,el) ){
      m_check = true;
      break;
    }
  }
  for( uint e=0; e<m_AddElectrons.size(); e++ ){
    const xAOD::Electron* el = m_AddElectrons.at(e);
    if( CheckLepsDR(tau,el) ){
      m_check = true;
      break;
    }
  }
  if( m_debug ) Info( "IsTauElecOverlap()", "Tau-Elec overlap = %i", m_check );
  if( m_check )
    if( m_debug ) Info( "IsTauElecOverlap()", "Rejecting tau" );

  return m_check;
  
}

void HighMassLFV :: FillLeptonQuantities(int sysVar){
  
  if( m_Chan==Channel::EMU ){
    FillMuonQuantities(sysVar);
    FillElectronQuantities(sysVar);
  }
  else if( m_Chan==Channel::ETAU ){
    FillElectronQuantities(sysVar);
    FillTauQuantities(sysVar);
  }
  else if( m_Chan==Channel::MUTAU ){
    FillMuonQuantities(sysVar);
    FillTauQuantities(sysVar);
  }
  
}
