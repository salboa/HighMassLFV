#include <HighMassLFVSel/HighMassLFV.h>

double HighMassLFV :: TrueDiTauMass(){
  
  double m = -999;
  m_TrueTaus.clear();
    
  for( auto thP: *m_thpartCont ) {
    if( abs(thP->pdgId()) == 23 && thP->status() == 62 ){
      
      for( int ch=0; ch<(int)thP->nChildren(); ch++ ){
	if( abs(thP->child(ch)->pdgId()) == 15 &&
	    (thP->child(ch)->status() == 2 || thP->child(ch)->status() == 10902 ) )
	  m_TrueTaus.push_back( thP->child(ch) );
      }
    }  
  }  
  if( m_debug )
    std::cout << "Info in <MCSampleOverlap()::KeepEvent()>: Number of taus found = " << (int)m_TrueTaus.size() << std::endl;
  
  if( m_TrueTaus.size()<2 ){
    std::cout<<" PROBLEM with number of taus"<<std::endl;
  }
  else{
    for( uint p1=0; p1<m_TrueTaus.size()-1; p1++){
      const xAOD::TruthParticle* tau1 = m_TrueTaus.at(p1);
      for( uint p2=p1+1; p2<m_TrueTaus.size(); p2++){
	const xAOD::TruthParticle* tau2 = m_TrueTaus.at(p2);
	
	if( tau1->charge()*tau2->charge()<0 ){
	  TLorentzVector Tau1, Tau2;
	  Tau1.SetPtEtaPhiM( tau1->pt()/GeV, tau1->eta(), tau1->phi(), tau1->m()/GeV );
	  Tau2.SetPtEtaPhiM( tau2->pt()/GeV, tau2->eta(), tau2->phi(), tau2->m()/GeV );
	  
	  if( m_debug )
	    std::cout << "Info in <MCSampleOverlap()::KeepEvent()>: tau-tau mass = " << (Tau1+Tau2).M() << " GeV" << std::endl;
	  
	  m=(Tau1+Tau2).M();
	}
      }
    }
  }
  return m;
  
}

bool HighMassLFV :: CheckTauContr(){

  bool m_check = false;
  if( m_eventInfo->mcChannelNumber()!=361068 ){
    return false;
  }
  else{
    for( auto thP: *m_thpartCont ) {
      if( abs(thP->pdgId()) == 15 && thP->status() == 3 ){
	m_check = true;
	break;
      }
    }
  }
  return m_check;
  
}

void HighMassLFV :: DecorateJets(){

  if( m_debug )
    Info( "DecorateJets()", "Decorating jets for JvtSF calculation ... " );

  for(auto jet: *m_jetContCopy) {
    bool ishs = false;
    bool ispu = true;
    for( auto tjet: *m_thjetCont) {
      if (tjet->p4().DeltaR(jet->p4())<0.3 && tjet->pt()>10000) ishs = true;
      if (tjet->p4().DeltaR(jet->p4())<0.6) ispu = false;
    }
    jet->auxdecor<char>("isJvtHS") = ishs;
    jet->auxdecor<char>("isJvtPU") = ispu;
  }
  
}
