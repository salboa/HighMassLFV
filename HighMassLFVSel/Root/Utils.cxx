#include <HighMassLFVSel/HighMassLFV.h>

bool HighMassLFV :: CheckLepsDR(const xAOD::IParticle *p1,
				const xAOD::IParticle *p2){
  
  bool m_check = false;
  double m_DeltaRCutOF = 0.2;

  double DR = ComputeDeltaR( LeptonEta(p1), p1->phi(),
			     LeptonEta(p2), p2->phi() );
  
  if( DR<m_DeltaRCutOF )
    m_check = true;

  if( m_debug ) Info( "CheckLepsDR()", "found overlap = %i", m_check );
  
  return m_check;

}

bool HighMassLFV :: CheckJetLepDR(const xAOD::Jet *jet,
				  const xAOD::IParticle *p){
  
  bool m_check = false;
  double m_LepJetDRCut = 0.2;
  
  double DR = ComputeDeltaR( JetEta(jet) , jet->phi(),  
			     LeptonEta(p), p->phi()   );
			     
  
  if( DR<m_LepJetDRCut )
    m_check = true;
  
  if( m_debug ) Info( "CheckLepJetDR()", "found overlap = %i", m_check );

  return m_check;
  
}

double HighMassLFV :: ComputeDeltaR(double eta1, double phi1,
				    double eta2, double phi2){

  double deltaR=0;
  double Dphi=phi1-phi2;
  double Deta=eta1-eta2;

  if( fabs(Dphi)>pi ) {
    if( Dphi>0 ){
      Dphi = 2*pi-Dphi;
    }
    else{
      Dphi = 2*pi+Dphi;
    }
  }

  deltaR=sqrt( pow(Deta,2)+pow(Dphi,2) );
  
  if( m_verbose ) Info( "CompureDeltaR()", "DeltaR = %f", deltaR );

  return deltaR;

}

double HighMassLFV :: ComputeDeltaPhi(double phi1, double phi2){
  
  double Dphi=phi1-phi2;
  if( fabs(Dphi)>pi ) {
    if( Dphi>0 ){
      Dphi = 2*pi-Dphi;
    }
    else{
      Dphi = 2*pi+Dphi;
    }
  }
  
  if( m_verbose ) if( m_debug ) Info( "ComputeDeltaPhi()", "DeltaPhi = %f", Dphi );
    
  return Dphi;
  
}

double HighMassLFV :: GetCrossSection(){
  
  double m_xsec  = 1;
  if(isMC){
    m_xsec = m_mcInfo->GetSampleCrossSection( m_eventInfo->mcChannelNumber() );
    if( m_debug ) Info( "GetCrossSection()", "sample = %i , xsec = %f ", m_eventInfo->mcChannelNumber(), m_xsec );
  }
  else
    if( m_debug ) Info( "GetCrossSection()", "Running on Data, xsec value = 1 !!" );
  return m_xsec;
  
}

double HighMassLFV :: GetKfactor(){

  double m_kfact = 1;
  if(isMC){
    if( (m_eventInfo->mcChannelNumber()>=301560 && m_eventInfo->mcChannelNumber()<=301579) ||
        (m_eventInfo->mcChannelNumber()>=301540 && m_eventInfo->mcChannelNumber()<=301559) ||
        (m_eventInfo->mcChannelNumber()>=303437 && m_eventInfo->mcChannelNumber()<=303455) ||
        (m_eventInfo->mcChannelNumber()>=301000 && m_eventInfo->mcChannelNumber()<=301018) ||
        (m_eventInfo->mcChannelNumber()>=301020 && m_eventInfo->mcChannelNumber()<=301038) ||
        (m_eventInfo->mcChannelNumber()>=301040 && m_eventInfo->mcChannelNumber()<=301058) ||
        (m_eventInfo->mcChannelNumber()>=361106 && m_eventInfo->mcChannelNumber()<=361108)  ){
      m_kfact = m_mcInfo->GetDYkFactor( m_eventInfo->mcChannelNumber(), m_thpartCont );
    }
    if( (m_eventInfo->mcChannelNumber()>=402970 && m_eventInfo->mcChannelNumber()<=403044) ){
      m_kfact = m_mcInfo->GetRPVkFactor( m_eventInfo->mcChannelNumber() );
    }
    if( (m_eventInfo->mcChannelNumber()>=301954 && m_eventInfo->mcChannelNumber()<=302028) ){
      m_kfact = m_mcInfo->GetZPRIMEkFactor( m_eventInfo->mcChannelNumber(), m_thpartCont );
    }
    if( m_debug ) Info( "GetKfactor()", "sample = %i , kfact = %f ", m_eventInfo->mcChannelNumber(), m_kfact );
  }
  else
    if( m_debug ) Info( "GetKfactor()", "Running on Data, kfact value = 1 !!" );
  return m_kfact;

}

void HighMassLFV :: SampleInformation(){
  
  if(isMC){
    if( m_eventInfo->mcEventWeights().at(0)< 0) m_TnegWgt++ ;
    else m_TposWgt++;
  }
  else{
    m_TposWgt++;
  }
  
}

void HighMassLFV :: FillSampleInformation(){
  
  if( m_debug ) Info( "FillSampleInformation()", "Filling Samplem ... " );
  
  MCInfo->SetBinContent( 1, m_evtSample );
  MCInfo->GetXaxis()->SetBinLabel( 1, "Evt. Sample" );
  MCInfo->SetBinContent( 2, m_evtWeightSample );
  MCInfo->GetXaxis()->SetBinLabel( 2, "Evt. Weighted Sample" );
  MCInfo->SetBinContent( 3, m_eventCounter );
  MCInfo->GetXaxis()->SetBinLabel( 3, "Evt. Processed" );
  MCInfo->SetBinContent( 4, m_TposWgt );
  MCInfo->GetXaxis()->SetBinLabel( 4, "Evt. Pos. Wgt" );
  MCInfo->SetBinContent( 5, m_TnegWgt );
  MCInfo->GetXaxis()->SetBinLabel( 5, "Evt. Neg. Wgt" );
  
}

bool HighMassLFV :: CheckOverlap(){
  
  bool m_keep = true;
  if( isMC ){
    m_keep = m_mcOverlap->KeepEvent(m_thpartCont, m_eventInfo->mcChannelNumber() );
    if( m_debug ) Info( "CheckOverlap()", " Overlap with other sample: keep event = %i", m_keep );
  }
  else
    if( m_debug ) Info( "CheckOverlap()", " Running on Data: nothing to be checked" );
  return  m_keep;
  
}

void HighMassLFV :: DetectYear(Int_t runNumber){
  
  if( runNumber<=311481 )     m_year = DataYear::Year2016;
  else if( runNumber<=340453) m_year = DataYear::Year2017;
  else                        m_year = DataYear::Year2018;
  
  if( m_debug ) Info( "DetectYear", "RunNumber = %i ---> Data Year is = %i", runNumber, m_year );
  
}

void HighMassLFV :: DetectChannel(){

  if( m_Muons.size()==1 && m_Electrons.size()==1 ){
    m_Chan = Channel::EMU;
    if( m_debug ) Info( "DetectChannel()", "Channel = %i --> Analysing Electron-Muon channel", m_Chan );
  }
  else if( m_Muons.size()==0 ){
    m_Chan = Channel::ETAU;
    if( m_debug ) Info( "DetectChannel()", "Channel = %i --> Analysing Electron-Tau channel", m_Chan );
  }
  else if( m_Electrons.size()==0 ){
    m_Chan = Channel::MUTAU;
    if( m_debug ) Info( "DetectChannel()", "Channel = %i --> Analysing Muon-Tau channel", m_Chan );
  }

}

std::string HighMassLFV :: GetFileName(std::string name){
  
  std::string delim = "/";
  std::string m_InName;
  size_t pos = 0;
  std::vector<std::string> m_file;
  while( (pos = name.find(delim)) != std::string::npos ){
    m_file.push_back( name.substr(0, pos) );
    name.erase(0, pos + delim.length());
  }
  
  m_InName = name;
  
  if( m_verbose ) Info( "GetFileName()", "FileName = %s", m_InName.c_str() );
    
  return m_InName;
  
}

void HighMassLFV :: CheckObjectsOverlap(){
  
  if(m_debug) Info( "CheckObjectsOverlap()", "Checking mu/el/tau/jets overlap ... " );
    
  if( !m_ORTool->removeOverlaps( m_elecContCopy, m_muonContCopy, m_jetContCopy, 
				 m_tauContCopy, m_phContCopy).isSuccess() ){
    Info( "CheckObjectsOverlap()", "Error in checking objects overlap" );
  }
  
}
