#include <HighMassLFVSel/HighMassLFV.h>

bool HighMassLFV :: CheckTriggerMatch(){
  
  bool m_check = false;
  if( m_Chan==Channel::EMU )
    m_check = CheckElecMuonTrigMatch();
  else if( m_Chan==Channel::ETAU )
    m_check = CheckElecTauTrigMatch();
  else if( m_Chan==Channel::MUTAU )
    m_check = CheckMuonTauTrigMatch();

  if( m_debug ) Info( "CheckTriggerMatch()", "At least one lepton firing the trigger = %i", m_check);
  return m_check;
  
}

bool HighMassLFV :: CheckElecMuonTrigMatch(){

  bool m_check = false;
  if( isMuonTrig && isElecTrig ){
    if( m_verbose ) Info( "CheckElecMuonTrigMatch()", "Muon and Electron triggers fired" );
    for(uint m=0; m<m_Muons.size(); m++){
      const xAOD::Muon* mu = m_Muons.at(m);
      if( CheckMuonTriggerMatching(mu) ){
	m_check = true;
	break;
      }
    }
    if( !m_check ){
      for(uint e=0; e<m_Electrons.size(); e++ ){
	const xAOD::Electron* el = m_Electrons.at(e);
	if( CheckElectronTriggerMatching(el) ){
	  m_check = true;
	  break;
	}   
      }
    }
  }
  else if( isMuonTrig ){
    if( m_verbose ) Info( "CheckElecMuonTrigMatch()", "Muon trigger only fired" );
    for(uint m=0; m<m_Muons.size(); m++){
      const xAOD::Muon* mu = m_Muons.at(m);
      if( CheckMuonTriggerMatching(mu) ){
  	m_check = true;
  	break;
      }
    }
  }
  else if( isElecTrig ){
    if( m_verbose ) Info( "CheckElecMuonTrigMatch()", "Electron trigger only fired" );
    for(uint e=0; e<m_Electrons.size(); e++ ){
      const xAOD::Electron* el = m_Electrons.at(e);
      if( CheckElectronTriggerMatching(el) ){
  	m_check = true;
        break;
      }
    }
  }
  if( m_debug ) Info("CheckElecMuonTrigMatch()", "Muon or Electron firing the trigger = %i", m_check);
  return m_check;
  
}

bool HighMassLFV :: CheckElecTauTrigMatch(){
  
  bool m_check = false;  
  if( isElecTrig ){
    if( m_verbose ) Info( "CheckElecTauTrigMatch()", "Electron trigger only fired" );
    for(uint e=0; e<m_Electrons.size(); e++ ){
      const xAOD::Electron* el = m_Electrons.at(e);
      if( CheckElectronTriggerMatching(el) ){
        m_check = true;
        break;
      }
    }
  }
  if( m_debug ) Info("CheckElecTauTrigMatch()", "Electron firing the trigger = %i", m_check);
  return m_check;
  
}

bool HighMassLFV :: CheckMuonTauTrigMatch(){
  
  bool m_check = false;
  if( isMuonTrig ){
    if( m_verbose ) Info( "CheckMuonTauTrigMatch()", "Muon trigger fired" );
    for(uint m=0; m<m_Muons.size(); m++){
      const xAOD::Muon* mu = m_Muons.at(m);
      if( CheckMuonTriggerMatching(mu) ){
        m_check = true;
        break;
      }
    }
  }
  if( m_debug ) Info("CheckMuonTauTrigMatch()", "Muon firing the trigger = %i", m_check);
  return m_check;
  
}

bool HighMassLFV :: CheckOS(){
  
  bool m_check = false;
  int ch1 = 0, ch2 = 0;
  if( m_Chan==Channel::EMU ){
    ch1 = LeptonCharge(m_Muons.at(0));
    ch2 = LeptonCharge(m_Electrons.at(0));
  }
  else if( m_Chan==Channel::ETAU ){
    ch1 = LeptonCharge(m_Electrons.at(0));
    ch2 = LeptonCharge(m_Taus.at(0));
  }
  else if( m_Chan==Channel::MUTAU ){
    ch1 = LeptonCharge(m_Muons.at(0));
    ch2 = LeptonCharge(m_Taus.at(0));
  }

  if( ch1*ch2<0) m_check = true;
  
  if( m_debug ) Info( "CheckOS()", "Leptons OS = %i", m_check );
  
  return m_check;
  
}

bool HighMassLFV :: CheckDeltaPhi(){

  bool m_check = true;
  if( fabs(ComputeDiLeptonDeltaPhi())<m_DeltaPhi ) m_check = false;
  if( m_debug ) Info( "CheckDeltaPhi()", "Leptons Back-To-Back = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: CheckBjet(){
  
  bool m_check = false;
  for(uint j=0; j<m_Jets.size(); j++){
    const xAOD::Jet* jt = m_Jets.at(j);
    if( IsBTaggedJet(jt) ){
      m_check = true;
      break;
    }
  }
  if( m_debug ) Info( "CheckBjet()", "Good b-jet found = %i", m_check );
  return m_check;
  
}

double HighMassLFV :: ComputeDiLeptonMass(){
  
  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = DiLepMass(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = DiLepMass(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = DiLepMass(m_Muons.at(0),m_Taus.at(0));
  
  return m_val;

}

double HighMassLFV :: ComputeDiLeptonCorrMass(){

  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = DiLepMass(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = DiLepCorrMass(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = DiLepCorrMass(m_Muons.at(0),m_Taus.at(0));

  return m_val;

}

double HighMassLFV :: ComputeDiLeptonPt(){

  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = DiLepPt(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = DiLepPt(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = DiLepPt(m_Muons.at(0),m_Taus.at(0));
  
  return m_val;

}

double HighMassLFV :: ComputeDiLeptonCorrPt(){
  
  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = DiLepPt(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = DiLepCorrPt(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = DiLepCorrPt(m_Muons.at(0),m_Taus.at(0));

  return m_val;
  
}

double HighMassLFV :: ComputeDiLeptonEta(){
  
  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = DiLepEta(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = DiLepEta(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = DiLepEta(m_Muons.at(0),m_Taus.at(0));

  return m_val;
  
}

double HighMassLFV :: ComputeDiLeptonPhi(){
  
  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = DiLepPhi(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = DiLepPhi(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = DiLepPhi(m_Muons.at(0),m_Taus.at(0));

  return m_val;

}

double HighMassLFV :: ComputeDiLeptonDeltaPhi(){
  
  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = DiLepDeltaPhi(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = DiLepDeltaPhi(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = DiLepDeltaPhi(m_Muons.at(0),m_Taus.at(0));
  
  return m_val;
  
}

double HighMassLFV :: ComputeLeptonsScaleFactor(){
  
  double m_val = 0;
  if( m_Chan==Channel::EMU )
    m_val = LeptonsScaleFactor(m_Muons.at(0),m_Electrons.at(0));
  else if( m_Chan==Channel::ETAU )
    m_val = LeptonsScaleFactor(m_Electrons.at(0),m_Taus.at(0));
  else if( m_Chan==Channel::MUTAU )
    m_val = LeptonsScaleFactor(m_Muons.at(0),m_Taus.at(0));
  
  return m_val;
  
}

double HighMassLFV :: ComputeJetsScaleFactor(bool useBtag){

  return JetsScaleFactor(useBtag);

}

double HighMassLFV :: DiLepMass(const xAOD::IParticle *p1, const xAOD::IParticle *p2){
  
  double m = 0;
  TLorentzVector Lep1, Lep2;
  Lep1.SetPtEtaPhiM( p1->pt(), LeptonEta(p1), p1->phi(), LeptonMass(p1)*GeV );
  Lep2.SetPtEtaPhiM( p2->pt(), LeptonEta(p2), p2->phi(), LeptonMass(p2)*GeV );
  m = (Lep1+Lep2).M()/GeV;
  if( m_debug ) Info( "DiLepMass()", "m_ll = %f", m );
  
  return m;
  
}

double HighMassLFV :: DiLepCorrMass(const xAOD::IParticle *p1, const xAOD::IParticle *p2){

  double m = 0;
  TLorentzVector Lep1, Lep2, Nu;
  Lep1.SetPtEtaPhiM( p1->pt(), LeptonEta(p1), p1->phi(), LeptonMass(p1)*GeV );
  Lep2.SetPtEtaPhiM( p2->pt(), LeptonEta(p2), p2->phi(), LeptonMass(p2)*GeV );
  Nu.SetPtEtaPhiM( (*m_BuildMet)["FinalTrk"]->met(), p2->eta(), 
		   (*m_BuildMet)["FinalTrk"]->phi(), 0 );
  m = (Lep1+Lep2+Nu).M()/GeV;
  if( m_debug ) Info( "DiLepCorrMass()", "m_ll = %f", m );

  return m;

}

double HighMassLFV :: DiLepPt(const xAOD::IParticle *p1, const xAOD::IParticle *p2){

  double pt = 0;
  TLorentzVector Lep1, Lep2;
  Lep1.SetPtEtaPhiM( p1->pt(), LeptonEta(p1), p1->phi(), LeptonMass(p1)*GeV );
  Lep2.SetPtEtaPhiM( p2->pt(), LeptonEta(p2), p2->phi(), LeptonMass(p2)*GeV );
  pt = (Lep1+Lep2).Pt()/GeV;
  if( m_debug ) Info( "DiLepPt()", "pT_ll = %f", pt );

  return pt;

}

double HighMassLFV :: DiLepCorrPt(const xAOD::IParticle *p1, const xAOD::IParticle *p2){

  double pt = 0;
  TLorentzVector Lep1, Lep2, Nu;
  Lep1.SetPtEtaPhiM( p1->pt(), LeptonEta(p1), p1->phi(), LeptonMass(p1)*GeV );
  Lep2.SetPtEtaPhiM( p2->pt(), LeptonEta(p2), p2->phi(), LeptonMass(p2)*GeV );
  Nu.SetPtEtaPhiM( (*m_BuildMet)["FinalTrk"]->met(), p2->eta(), 
		   (*m_BuildMet)["FinalTrk"]->phi(), 0 );
  pt = (Lep1+Lep2+Nu).Pt()/GeV;
  if( m_debug ) Info( "DiLepCorrPt()", "pT_ll = %f", pt );

  return pt;

}

double HighMassLFV :: DiLepEta(const xAOD::IParticle *p1, const xAOD::IParticle *p2){

  double eta = 0;
  TLorentzVector Lep1, Lep2;
  Lep1.SetPtEtaPhiM( p1->pt(), LeptonEta(p1), p1->phi(), LeptonMass(p1)*GeV );
  Lep2.SetPtEtaPhiM( p2->pt(), LeptonEta(p2), p2->phi(), LeptonMass(p2)*GeV );
  eta = (Lep1+Lep2).Eta();
  if( m_debug ) Info( "DiLepEta()", "eta_ll = %f", eta );

  return eta;

}

double HighMassLFV :: DiLepPhi(const xAOD::IParticle *p1, const xAOD::IParticle *p2){

  double phi = 0;
  TLorentzVector Lep1, Lep2;
  Lep1.SetPtEtaPhiM( p1->pt(), LeptonEta(p1), p1->phi(), LeptonMass(p1)*GeV );
  Lep2.SetPtEtaPhiM( p2->pt(), LeptonEta(p2), p2->phi(), LeptonMass(p2)*GeV );
  phi = (Lep1+Lep2).Phi();
  if( m_debug ) Info( "DiLepPhi()", "phi_ll = %f", phi );

  return phi;

}

double HighMassLFV :: DiLepDeltaPhi(const xAOD::IParticle *p1, const xAOD::IParticle *p2){

  double Dphi = 0;
  double p1_phi = p1->phi();
  double p2_phi = p2->phi();
  Dphi = ComputeDeltaPhi(p1_phi,p2_phi);
  if( m_debug ) Info( "DiLepDphi()", "DeltaPhi_ll = %f", Dphi );
  
  return Dphi;
  
}

double HighMassLFV :: LeptonsScaleFactor(const xAOD::IParticle *p1, const xAOD::IParticle *p2){
  
  double sf = 0;
  double p1_sf = LeptonSF(p1);
  double p2_sf = LeptonSF(p2);
  sf = p1_sf*p2_sf;
  if( m_debug ) Info( "LeptonsScaleFactor()", "Leptons SF (total) = %f", sf );
  
  return sf;
  
}

void HighMassLFV :: FillDiLeptonQuantities(){
  
  dilepMass     = ComputeDiLeptonMass();
  dilepCorrMass = ComputeDiLeptonCorrMass();
  dilepPt       = ComputeDiLeptonPt();
  dilepCorrPt   = ComputeDiLeptonCorrPt();
  dilepEta      = ComputeDiLeptonEta();
  dilepPhi      = ComputeDiLeptonPhi();
  dilepDeltaPhi = ComputeDiLeptonDeltaPhi();
  
}
