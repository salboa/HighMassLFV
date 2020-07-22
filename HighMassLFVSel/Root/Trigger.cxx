#include <HighMassLFVSel/HighMassLFV.h>

bool HighMassLFV :: TriggerCheck(){
  
  bool m_check = false;
  isMuonTrig = MuonTrigger();
  isElecTrig = ElectronTrigger();
  
  if( isMuonTrig || isElecTrig )
    m_check = true;
  
  if( m_debug ) Info( "TriggerCheck()", "trigger fired = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: MuonTrigger(){

  bool m_check = false;
  for(uint i=0; i<m_MuTrigChains[m_year].size(); i++){
    if( m_verbose ) Info( "MuonTrigger()", "checking muon trigger = %s", m_MuTrigChains[m_year].at(i).c_str() );
    if( m_tdt->isPassed( m_MuTrigChains[m_year].at(i) ) )
      m_check = true;
  }
  if( m_debug ) Info( "MuonTrigger()", "muon trigger fired = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: ElectronTrigger(){

  bool m_check = false;
  for(uint i=0; i<m_ElTrigChains[m_year].size(); i++){
    if( m_verbose ) Info( "ElectronTrigger()", "checking electron trigger = %s", m_ElTrigChains[m_year].at(i).c_str() );
    if( m_tdt->isPassed( m_ElTrigChains[m_year].at(i) ) )
      m_check = true;
  }
  if( m_debug ) Info( "ElectronTrigger()", "electron trigger fired = %i", m_check );
  return m_check;
  
}

bool HighMassLFV :: MuonElectronTrigger(){

  /*do not test for now */
  return false;
  
  bool m_check = false;
  if( m_tdt->isPassed("HLT_e17_medium1_mu12") ){
    m_check = true;
  }
  if( m_debug ) Info( "MuonElectronTrigger()", "muon-electron trigger fired = %i", m_check );
  return m_check;

}


void HighMassLFV :: FillTriggerChains(){
  
  /* muon trig chains */
  m_MuTrigChains[DataYear::Year2016].push_back("HLT_mu50");
  m_MuTrigChains[DataYear::Year2017].push_back("HLT_mu50");
  m_MuTrigChains[DataYear::Year2018].push_back("HLT_mu50");

  /* electron trig chains */
  //m_ElTrigChains[DataYear::Year2015].push_back("HLT_e60_lhmedium");
  //m_ElTrigChains[DataYear::Year2015].push_back("HLT_e120_lhloose");
  m_ElTrigChains[DataYear::Year2016].push_back("HLT_e60_lhmedium_nod0");
  m_ElTrigChains[DataYear::Year2016].push_back("HLT_e140_lhloose_nod0");
  m_ElTrigChains[DataYear::Year2017].push_back("HLT_e60_lhmedium_nod0");
  m_ElTrigChains[DataYear::Year2017].push_back("HLT_e140_lhloose_nod0");
  m_ElTrigChains[DataYear::Year2018].push_back("HLT_e60_lhmedium_nod0");
  m_ElTrigChains[DataYear::Year2018].push_back("HLT_e140_lhloose_nod0");
  
  if( m_debug ) Info( "FillTriggerChains()", "trigger chains filled!" );
  CreateMuTrigString();
  
}

void HighMassLFV :: CreateMuTrigString(){ 

  for(uint i=0; i<m_MuTrigChains[DataYear::Year2016].size(); i++){
    if( i==0 )
      m_muTMstring = m_MuTrigChains[DataYear::Year2016].at(i);
    else
      m_muTMstring += "_OR_"+m_MuTrigChains[DataYear::Year2016].at(i);
  }
  Info( "CreateMuTrigString()", "Muon Trigger string = %s", m_muTMstring.c_str() );

}
