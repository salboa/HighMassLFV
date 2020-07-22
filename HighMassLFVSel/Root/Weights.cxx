#include <HighMassLFVSel/HighMassLFV.h>

double HighMassLFV :: GetMCweight(){
  
  double m_wg = 1;
  if( isMC && m_UseWgt ){
    m_wg = m_eventInfo->mcEventWeights().at(0);
  }
  if( m_debug ) Info( "GetMCweight()", "MC weight = %f", m_wg );
  return m_wg;

}

double HighMassLFV :: GetPUweight(int sysVar){

  double m_wg = 1;
  if( isMC && m_UseWgt ){
    if( m_PuWgtVar.find(sysVar) == m_PuWgtVar.end() ){
      if( m_debug ) Info( "GetPUweight()", "Systematic set not found, applying nominal one (no systematics)!");
      if( m_puTool->applySystematicVariation( m_NominalSysSet ) == CP::SystematicCode::Unsupported ){
	Info( "GetPUweight()", "PileupReweightingTool variation 'empty' (Nominal) not supported" );
      }
    }
    else{
      if( m_debug ) Info( "GetPUweight()", "Applying variation %s", m_MuSFVarName[sysVar].c_str() );
      if( m_puTool->applySystematicVariation( m_PuWgtVar[sysVar] ) == CP::SystematicCode::Unsupported ){
	Info( "GetPUweight()", "PileupReweightingTool variation %s not supported", m_MuSFVarName[sysVar].c_str() );
      }
    }
    m_wg = m_puTool->getCombinedWeight( *m_eventInfo );
  }
  if( m_debug ) Info( "GetPUweight()", "PU weight = %f", m_wg );
  return m_wg;
  
}

double HighMassLFV :: GetEventWeight(bool useLepWeight, bool useJetWeight, bool useBtagWeight){
  
  double m_wg = 1;
  if( isMC && m_UseWgt ){
    m_wg = GetMCweight() * GetPUweight();
    if( useLepWeight )
      m_wg *= GetLeptonsWeight();
    if( useJetWeight )
      m_wg *= GetJetsWeight(useBtagWeight);
  }
  if( m_debug ) Info( "GetEventWeight()", "Event weight = %f", m_wg );
  return m_wg;
  
}

double HighMassLFV :: GetLeptonsWeight(){
  
  double m_wg = 1;
  if( isMC && m_UseWgt){
    m_wg = ComputeLeptonsScaleFactor();
  }
  if( m_debug ) Info( "GetLeptonsWeight()", "Leptons weight = %f", m_wg );
  return m_wg;
  
}

double HighMassLFV :: GetJetsWeight(bool useBtag){
  
  double m_wg = 1;
  if( isMC && m_UseWgt ){
    m_wg = ComputeJetsScaleFactor(useBtag);
  }
  if( m_debug ) Info( "GetJetsWeight()", "Jets weight= %f", m_wg );
  return m_wg;
  
}
