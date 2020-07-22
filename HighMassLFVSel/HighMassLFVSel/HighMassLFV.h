#ifndef HighMassLFVSel_HighMassLFV_H
#define HighMassLFVSel_HighMassLFV_H

#include <EventLoop/Algorithm.h>

/* xAOD includes */
#include "xAODRootAccess/tools/Message.h"
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"
#include "xAODMuon/Muon.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODMuon/MuonAuxContainer.h"
#include "xAODEgamma/Egamma.h"
#include "xAODEgamma/Electron.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODEgamma/ElectronAuxContainer.h"
#include "xAODEgamma/PhotonContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODTau/TauJetAuxContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODJet/JetAuxContainer.h"
#include "xAODTruth/TruthParticle.h"
#include "xAODTruth/TruthParticleContainer.h"
#include "xAODBase/IParticle.h"
#include "xAODBase/IParticleContainer.h"
#include "xAODBase/IParticleHelpers.h"
#include "xAODCore/ShallowAuxContainer.h"
#include "xAODCore/ShallowCopy.h"
#include "xAODCutFlow/CutBookkeeper.h"
#include "xAODCutFlow/CutBookkeeperContainer.h"
#include "xAODMissingET/MissingETContainer.h"
#include "xAODMissingET/MissingETAssociationMap.h"
#include "xAODMissingET/MissingETAuxContainer.h"

/* Tools includes */
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include "PileupReweighting/PileupReweightingTool.h"
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "TriggerMatchingTool/MatchingTool.h"
#include "MuonSelectorTools/MuonSelectionTool.h"
#include "MuonMomentumCorrections/MuonCalibrationAndSmearingTool.h"
#include "MuonEfficiencyCorrections/MuonTriggerScaleFactors.h"
#include "MuonEfficiencyCorrections/MuonEfficiencyScaleFactors.h"
#include "ElectronPhotonSelectorTools/AsgElectronLikelihoodTool.h"
#include "ElectronPhotonFourMomentumCorrection/EgammaCalibrationAndSmearingTool.h"
#include "EgammaAnalysisHelpers/PhotonHelpers.h"
#include "ElectronPhotonSelectorTools/AsgPhotonIsEMSelector.h"
#include "ElectronEfficiencyCorrection/AsgElectronEfficiencyCorrectionTool.h"
#include "TauAnalysisTools/TauSelectionTool.h"
#include "TauAnalysisTools/TauEfficiencyCorrectionsTool.h"
#include "TauAnalysisTools/TauOverlappingElectronLLHDecorator.h"
#include "TauAnalysisTools/TauTruthMatchingTool.h"
#include "TauAnalysisTools/TauSmearingTool.h"
#include "IsolationSelection/IsolationSelectionTool.h"
#include "IsolationCorrections/IsolationCorrectionTool.h"
#include "JetMomentTools/JetVertexTaggerTool.h"
#include "JetMomentTools/JetForwardJvtTool.h"
#include "JetSelectorTools/JetCleaningTool.h"
#include "JetJvtEfficiency/JetJvtEfficiency.h"
#include "JetCalibTools/JetCalibrationTool.h"
#include "JetResolution/JERTool.h"
#include "JetResolution/JERSmearingTool.h"
#include "JetUncertainties/JetUncertaintiesTool.h"
#include "xAODBTaggingEfficiency/BTaggingSelectionTool.h"
#include "xAODBTaggingEfficiency/BTaggingEfficiencyTool.h"
#include "xAODPrimitives/IsolationType.h"
#include "METUtilities/METMaker.h"
#include "METUtilities/CutsMETMaker.h"
#include "METUtilities/METSystematicsTool.h"
#include "AssociationUtils/OverlapRemovalInit.h"
#include "AssociationUtils/OverlapRemovalDefs.h"
#include "PATInterfaces/CorrectionCode.h"
#include "PATInterfaces/ISystematicsTool.h"
#include "LFVUtils/MCSampleInfo.h"
#include "LFVUtils/MCSampleOverlap.h"

/* ROOT includes */
#include <TH1.h>
#include <TObject.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include <TFile.h>

/* Package includes */
#include <HighMassLFVSel/EnumDef.h>

/* ---------------------------------------------------- */
/* Helper for checking xAOD::TReturnCode return values */
#define CHECK( CONTEXT, EXP )                           \
  do {                                                  \
    if( ! EXP.isSuccess() ) {                           \
      Error( CONTEXT,                                   \
	     XAOD_MESSAGE( "Failed to execute: %s" ),   \
	     #EXP );                                    \
      return EL::StatusCode::FAILURE;                   \
    }                                                   \
  } while( false )
/* -----------------------------------------------------*/

class HighMassLFV : public EL::Algorithm{
//class HighMassLFV : public EL::AnaAlgorithm{

private:
  xAOD::TEvent *m_event; //!
  
  
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  /* Object Cuts */
  double m_MuPt;        //!
  double m_MuEta;       //!
  double m_MuDeltaZ0;   //!
  double m_MuD0SignCut; //!
  double m_ElPt;        //!
  double m_ElEta;       //!
  double m_ElDeltaZ0;   //!
  double m_ElD0SignCut; //!
  double m_ElPt_IDThr;  //!
  double m_TauPt;       //!
  double m_TauEta;      //!
  int m_TauCharge;      //!
  double m_JetPt;       //!
  double m_JetEta;      //!
  double m_JetPtJVT;    //!
  double m_JetEtaJVT;   //!
  double m_JetJVT;      //!
  double m_JetElDR;     //!
  double m_DeltaPhi;    //!
  double m_bjetMvxCut;  //!
  double m_MetCut;      //!
  

  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  /* Constructors */
  HighMassLFV ();
  
  /* inherited functions from Algorithm */
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();
  
  //virtual StatusCode initialize () override;
  //virtual StatusCode execute() override;
  //virtual StatusCode finalize() override;

  /* Process Event */
  void ProcessEvent(int sysVar);
  
  /* Event and Data Pre-Selection */
  bool IsSimulation();
  void FindPriVtx();
  const xAOD::Vertex* PriVtx();
  bool VertexCheck();
  bool EventCheck();
  bool larErrorCheck();
  bool tileErrorCheck();
  bool coreFlagCheck();
  bool tileTripCheck();
  bool sctErrorCheck();
  bool GRLCheck();

  /* Trigger Selection */
  void FillTriggerChains();
  void CreateMuTrigString();
  bool TriggerCheck();
  bool MuonTrigger();
  bool ElectronTrigger();
  bool MuonElectronTrigger();

  /* Trigger Matching */
  bool CheckMuonTriggerMatching(const xAOD::IParticle *p);
  bool CheckElectronTriggerMatching(const xAOD::IParticle *p);
  
  /* Objects Selectors */
  void PreSelectMuons(int sysVar=0);
  void CheckMuons(int sysVar=0);
  void PreSelectElectrons(int sysVar=0);
  void CheckElectrons(int sysVar=0);
  void DecorateTau(const xAOD::TauJet *tau);
  void PreSelectTaus(int sysVar=0);
  void CheckTaus(int sysVar=0);
  void PreSelectJets(int sysVar=0);
  void CheckJets(int sysVar=0);
  void SelectPhotons(int sysVar=0);
  void CheckObjectsOverlap();
  bool IsJetElectronOverlap(const xAOD::Jet *jet);
  bool IsJetTauOverlap(const xAOD::Jet *jet);
  bool IsJetMuonOverlap(const xAOD::Jet *jet);
  bool IsElectronMuonOverlap(const xAOD::IParticle *p);
  bool IsTauMuonOverlap(const xAOD::IParticle *p);
  bool IsTauElecOverlap(const xAOD::IParticle *p);
  double GetElectronIDSF(const xAOD::IParticle *p, int sysVar=0);
  double GetElectronRecoSF(const xAOD::IParticle *p, int sysVar=0);
  double GetElectronIsoSF(const xAOD::IParticle *p, int sysVar=0);
  double GetElectronTrigSF(const xAOD::IParticle *p, int sysVar=0);
  double GetElectronL1CaloSF(const xAOD::IParticle *p);
  double GetElectronTrkIso(const xAOD::IParticle *p);
  double GetElectronCaloIso(const xAOD::IParticle *p);
  double GetMuonTriggerSF(const xAOD::IParticle *p, int sysVar=0);
  double GetMuonRecoSF(const xAOD::IParticle *p, int sysVar=0);
  double GetBadMuonVetoSF(const xAOD::IParticle *p, int sysVar=0);
  double GetMuonIsoSF(const xAOD::IParticle *p, int sysVar=0);
  double GetMuonTtvaSF(const xAOD::IParticle *p, int sysVar=0);
  double GetMuonTrkIso(const xAOD::IParticle *p);
  double GetMuonCaloIso(const xAOD::IParticle *p);
  double GetTauRecoSF(const xAOD::IParticle *p, int sysVar=0);
  double GetTauEleOlrSF(const xAOD::IParticle *p, int sysVar=0);
  double GetTauJetIDSF(const xAOD::IParticle *p, int sysVar=0);
  double GetBtagDiscriminant(const xAOD::Jet* jet);
  bool IsBTaggedJet(const xAOD::Jet* jet);
  double GetBtagSF(const xAOD::Jet* jet, int sysVar=0);
  double GetJetJvtSF(const xAOD::Jet* jet, int sysVar=0);
  double JetEta(const xAOD::Jet *jet, bool EMScale=false);
  void JetBasedEventCleaning(const xAOD::Jet *jet, double jvt);
  bool MuonBasedEventCleaning();
  void FillLeptonQuantities(int sysVar=0);
  void FillMuonQuantities(int sysVar=0);
  void FillElectronQuantities(int sysVar=0);
  void FillTauQuantities(int sysVar=0);
  void FillJetQuantities(int sysVar=0);
  bool CheckLeptons();
  bool CheckNumOfLeptons();
  int LeptonCharge(const xAOD::IParticle* p);
  double LeptonZ0(const xAOD::IParticle *p);
  double LeptonDeltaZ0(const xAOD::IParticle *p);
  double LeptonD0(const xAOD::IParticle *p);
  double LeptonD0Sign(const xAOD::IParticle *p);
  double LeptonMass(const xAOD::IParticle *p);
  double LeptonEta(const xAOD::IParticle *p, bool elCalo=false);
  double LeptonSF(const xAOD::IParticle *p);
  double JetsScaleFactor(bool useBtag);
  void BuildMET(int sysVar=0);
  void LinkObjects();
  void StoreObjects();
  void FeedMetMaker();
  void FillMETQuantities();
  void CleanMET();
  
  /* Lepton Pair Selection */
  void DetectChannel();
  bool CheckTriggerMatch();
  bool CheckElecMuonTrigMatch();
  bool CheckElecTauTrigMatch();
  bool CheckMuonTauTrigMatch();
  bool CheckOS();
  bool CheckDeltaPhi();
  bool CheckBjet();
  double ComputeDiLeptonMass();
  double ComputeDiLeptonCorrMass();
  double ComputeDiLeptonPt();
  double ComputeDiLeptonCorrPt();
  double ComputeDiLeptonEta();
  double ComputeDiLeptonPhi();
  double ComputeDiLeptonDeltaPhi();
  double ComputeLeptonsScaleFactor();
  double ComputeJetsScaleFactor(bool useBtag); 
  double DiLepMass(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  double DiLepCorrMass(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  double DiLepPt(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  double DiLepCorrPt(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  double DiLepEta(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  double DiLepPhi(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  double DiLepDeltaPhi(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  double LeptonsScaleFactor(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  void FillDiLeptonQuantities();

  /* Weight Computation */
  double GetMCweight();
  double GetPUweight(int sysVar=0);
  double GetEventWeight(bool useLepWeight, bool useJetWeight, bool useBtagWeight);
  double GetLeptonsWeight();
  double GetJetsWeight(bool useBtag);
  
  /* Event Information */
  int m_eventCounter; //!
  int m_TnegWgt;      //!
  int m_TposWgt;      //!
  int nEvt;           //!
  int m_Chan;         //!
  int m_year;         //!
  bool m_badJetEvt; 

  /* Leptons Id */
  int m_MuonId    ;      //!
  int m_ElectronId;      //!
  int m_TauId;           //!
  int m_ZprimeId  ;      //!
  int m_ZprimeStatus;    //!
  int m_LepStatus ;      //!
  double ZMass    ;      //!
  double MuonMass;       //!
  double ElectronMass;   //!
  double TauMass;        //!
  double GeV      ;      //!
  double pi       ;      //!

  /* Class Options */
  int m_printEvt      ;     //!
  bool m_debug        ;      
  bool m_verbose      ;      
  bool m_UseCorr      ;
  bool m_UseWgt       ;
  bool m_doSyst       ;
  bool m_QcdCR        ;
  bool m_NoTauId      ;
  bool m_FailTauId    ;
  bool m_useBDTcut    ;
  bool m_UseData      ;
  bool m_fixPuCh      ;
  bool m_DbgStream    ;
  std::string m_MCtype;
  bool m_FastSim      ;
  bool m_PrintFlow    ;
  bool m_TrigList     ;
  bool m_SystList     ;
  bool m_evalEgQuant  ;
  bool m_evalElLH     ;
  double m_TauBDTscore;
  unsigned long long m_runEvent;
    
  /* Out Trees and Maps */
  TTree* lfvTree; //!
  TTree* lfvTree_MuSmeID_SysUp;    //!
  TTree* lfvTree_MuSmeID_SysDown;  //!
  TTree* lfvTree_MuSmeMS_SysUp;    //!
  TTree* lfvTree_MuSmeMS_SysDown;  //!
  TTree* lfvTree_MuScale_SysUp;    //!
  TTree* lfvTree_MuScale_SysDown;  //!
  TTree* lfvTree_MuSagRho_SysUp;   //!
  TTree* lfvTree_MuSagRho_SysDown; //!
  TTree* lfvTree_MuSagRes_SysUp;   //!
  TTree* lfvTree_MuSagRes_SysDown; //!
  TTree* lfvTree_ElSme_SysUp;      //!
  TTree* lfvTree_ElSme_SysDown;    //!
  TTree* lfvTree_ElScale_SysUp;    //!
  TTree* lfvTree_ElScale_SysDown;  //!
  TTree* lfvTree_TaSme_SysUp;      //!
  TTree* lfvTree_TaSme_SysDown;    //!
  TTree* lfvTree_TaSmeDet_SysUp;   //!
  TTree* lfvTree_TaSmeDet_SysDown; //!
  TTree* lfvTree_TaSmeMod_SysUp;   //!
  TTree* lfvTree_TaSmeMod_SysDown; //!
  TTree* lfvTree_JtSme_SysUp;      //!
  TTree* lfvTree_JtUncNP1_SysUp;   //!
  TTree* lfvTree_JtUncNP1_SysDown; //!
  TTree* lfvTree_JtUncNP2_SysUp;   //!
  TTree* lfvTree_JtUncNP2_SysDown; //!
  TTree* lfvTree_JtUncNP3_SysUp;   //!
  TTree* lfvTree_JtUncNP3_SysDown; //!
  TTree* lfvTree_JtUncETA_SysUp;   //!
  TTree* lfvTree_JtUncETA_SysDown; //!
  TTree* lfvTree_MetResPara;       //!
  TTree* lfvTree_MetResPerp;       //!
  TTree* lfvTree_MetScl_SysUp;     //!
  TTree* lfvTree_MetScl_SysDown;   //!
  std::map<int,TTree*> m_TreesMap; //!
  void DefineTrees();
  void DefineTreesMap();
  
  /* Input File Metadata */
  TTree *m_MetaData;        //!
  double m_evtSample;       //!
  double m_evtWeightSample; //!
  double m_tmpEvt;          //!
  double m_tmpEvtWeight;    //!
  bool m_isDeriv;           //!
  const xAOD::CutBookkeeperContainer* m_incompleteCBC; //!
  const xAOD::CutBookkeeperContainer* m_completeCBC;   //!
  const xAOD::CutBookkeeper* m_allEvtsCBK;             //!

  /* xAOD Data Containers */  
  const xAOD::EventInfo* m_eventInfo;                //!
  const xAOD::VertexContainer* m_vertexCont;         //!
  const xAOD::Vertex* m_priVtx;                      //!
  const xAOD::MuonContainer* m_muonCont;             //!
  const xAOD::ElectronContainer* m_elecCont;         //!
  const xAOD::TauJetContainer* m_tauCont;            //!
  const xAOD::JetContainer* m_jetCont;               //!
  const xAOD::PhotonContainer* m_phCont;             //!
  const xAOD::MissingETContainer* m_metCont;         //!
  const xAOD::MissingETAssociationMap* m_metMapCont; //!
  const xAOD::TruthParticleContainer* m_thpartCont;  //!
  const xAOD::JetContainer* m_thjetCont;             //!
  std::pair< xAOD::MuonContainer*, xAOD::ShallowAuxContainer* > m_muons_shallowCopy;         //!
  std::pair< xAOD::ElectronContainer*, xAOD::ShallowAuxContainer* > m_electrons_shallowCopy; //!
  std::pair< xAOD::TauJetContainer*, xAOD::ShallowAuxContainer* > m_taus_shallowCopy;        //!
  std::pair< xAOD::JetContainer*, xAOD::ShallowAuxContainer* > m_jets_shallowCopy;           //!
  std::pair< xAOD::PhotonContainer*, xAOD::ShallowAuxContainer* > m_photons_shallowCopy;     //!
  xAOD::MuonContainer* m_muonContCopy;     //!
  xAOD::ElectronContainer* m_elecContCopy; //!
  xAOD::TauJetContainer* m_tauContCopy;    //!
  xAOD::JetContainer* m_jetContCopy;       //!
  xAOD::PhotonContainer* m_phContCopy;     //!
  
  /* CutFlow Methods and Variables */
  std::map<int,std::string>  m_EvtFlowName;   //!
  std::map<int,std::string>  m_EMUFlowName;   //!
  std::map<int,std::string>  m_ETAUFlowName;  //!
  std::map<int,std::string>  m_MUTAUFlowName; //!
  std::map<int,std::string>  m_MuFlowName;    //!
  std::map<int,std::string>  m_ElFlowName;    //!
  std::map<int,std::string>  m_TauFlowName;   //!
  std::map<int,std::string>  m_JtFlowName;    //!
  std::map<int,std::string>  m_PhFlowName;    //!
  std::map<int,std::string>  m_WeightName;    //!
  std::map<int,std::map<int,double> > m_EvtFlowMap;   //!
  std::map<int,std::map<int,double> > m_EMUFlowMap;   //!
  std::map<int,std::map<int,double> > m_ETAUFlowMap;  //!
  std::map<int,std::map<int,double> > m_MUTAUFlowMap; //!
  std::map<int,std::map<int,int> >    m_MuFlowMap;    //!
  std::map<int,std::map<int,int> >    m_ElFlowMap;    //!
  std::map<int,std::map<int,int> >    m_TauFlowMap;   //!
  std::map<int,std::map<int,int> >    m_JtFlowMap;    //!
  std::map<int,std::map<int,int> >    m_PhFlowMap;    //!
  std::map<int,std::map<int,double> > m_WeightMap;    //!
  std::map<int,std::map<int,double> > m_WeightBJMap;  //!
  int m_EvtFlowBins;  //!
  int m_MuFlowBins;   //!
  int m_ElFlowBins;   //!
  int m_TauFlowBins;  //!
  int m_JtFlowBins;   //!
  int m_PhFlowBins;   //!
  int m_WeightBins;   //!
  int m_WeightBJBins; //!
  void CutFlowInit();
  void UpdateEvtFlow(int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateChannelFlow(int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateEMUFlow(int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateETAUFlow(int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateMUTAUFlow(int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateMuFlow (int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateElFlow (int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateTauFlow (int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateJetFlow(int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdatePhFlow(int sysVar, int cutLevel, int valToAdd, double weight=1);
  void UpdateWeight(int channel, int cutLevel, int valToAdd, double weight=1);
  void UpdateWeightBJ(int channel, int cutLevel, int valToAdd, double weight=1);
  void FillCutLevelNames();
  void FillWeightsNames();
  void InitializeCutLevelMaps();
  void InitializeWeightsMaps();
  void FillCutFlowHists(int sysVar);
  void FillWeightsHists(int channel);
  void PrintCutFlows();
  void PrintEventFlow();
  void PrintMuonFlow();
  void PrintElectronFlow();
  void PrintTauFlow();
  void PrintJetFlow();
  void PrintPhotonFlow();
  void PrintWeights();
  void PrintChannelWeights(int channel);
  
  /* Sample Information */
  void SampleInformation();
  void FillSampleInformation();
  
  /* Info Histograms */
  TH1F *MCInfo;           //!
  TH1F *EMU_Weights;      //!
  TH1F *ETAU_Weights;     //!
  TH1F *MUTAU_Weights;    //!
  TH1F *EMU_WeightsBJ;    //!
  TH1F *ETAU_WeightsBJ;   //!
  TH1F *MUTAU_WeightsBJ;  //!
  
  TH1F *EMU_EventFlow;                     //!
  TH1F *EMU_EventFlow_MuSmeID_SysUp;       //!
  TH1F *EMU_EventFlow_MuSmeID_SysDown;     //!
  TH1F *EMU_EventFlow_MuSmeMS_SysUp;       //!
  TH1F *EMU_EventFlow_MuSmeMS_SysDown;     //!
  TH1F *EMU_EventFlow_MuScale_SysUp;       //!
  TH1F *EMU_EventFlow_MuScale_SysDown;     //!
  TH1F *EMU_EventFlow_MuSagRho_SysUp;      //!
  TH1F *EMU_EventFlow_MuSagRho_SysDown;    //!
  TH1F *EMU_EventFlow_MuSagRes_SysUp;      //!
  TH1F *EMU_EventFlow_MuSagRes_SysDown;    //!
  TH1F *EMU_EventFlow_ElSme_SysUp;         //!
  TH1F *EMU_EventFlow_ElSme_SysDown;       //!
  TH1F *EMU_EventFlow_ElScale_SysUp;       //!
  TH1F *EMU_EventFlow_ElScale_SysDown;     //!
  TH1F *EMU_EventFlow_TaSme_SysUp;         //!
  TH1F *EMU_EventFlow_TaSme_SysDown;       //!
  TH1F *EMU_EventFlow_TaSmeDet_SysUp;      //!
  TH1F *EMU_EventFlow_TaSmeDet_SysDown;    //!
  TH1F *EMU_EventFlow_TaSmeMod_SysUp;      //!
  TH1F *EMU_EventFlow_TaSmeMod_SysDown;    //!
  TH1F *EMU_EventFlow_JtSme_SysUp;         //!
  TH1F *EMU_EventFlow_JtUncNP1_SysUp;      //!
  TH1F *EMU_EventFlow_JtUncNP1_SysDown;    //!
  TH1F *EMU_EventFlow_JtUncNP2_SysUp;      //!
  TH1F *EMU_EventFlow_JtUncNP2_SysDown;    //!
  TH1F *EMU_EventFlow_JtUncNP3_SysUp;      //!
  TH1F *EMU_EventFlow_JtUncNP3_SysDown;    //!
  TH1F *EMU_EventFlow_JtUncETA_SysUp;      //!
  TH1F *EMU_EventFlow_JtUncETA_SysDown;    //!
  TH1F *EMU_EventFlow_MetResPara;          //!
  TH1F *EMU_EventFlow_MetResPerp;          //!
  TH1F *EMU_EventFlow_MetScl_SysUp;        //!
  TH1F *EMU_EventFlow_MetScl_SysDown;      //!
  TH1F *ETAU_EventFlow;                    //!
  TH1F *ETAU_EventFlow_MuSmeID_SysUp;      //!
  TH1F *ETAU_EventFlow_MuSmeID_SysDown;    //!
  TH1F *ETAU_EventFlow_MuSmeMS_SysUp;      //!
  TH1F *ETAU_EventFlow_MuSmeMS_SysDown;    //!
  TH1F *ETAU_EventFlow_MuScale_SysUp;      //!
  TH1F *ETAU_EventFlow_MuScale_SysDown;    //!
  TH1F *ETAU_EventFlow_MuSagRho_SysUp;     //!
  TH1F *ETAU_EventFlow_MuSagRho_SysDown;   //!
  TH1F *ETAU_EventFlow_MuSagRes_SysUp;     //!
  TH1F *ETAU_EventFlow_MuSagRes_SysDown;   //!
  TH1F *ETAU_EventFlow_ElSme_SysUp;        //!
  TH1F *ETAU_EventFlow_ElSme_SysDown;      //!
  TH1F *ETAU_EventFlow_ElScale_SysUp;      //!
  TH1F *ETAU_EventFlow_ElScale_SysDown;    //!
  TH1F *ETAU_EventFlow_TaSme_SysUp;        //!
  TH1F *ETAU_EventFlow_TaSme_SysDown;      //!
  TH1F *ETAU_EventFlow_TaSmeDet_SysUp;     //!
  TH1F *ETAU_EventFlow_TaSmeDet_SysDown;   //!
  TH1F *ETAU_EventFlow_TaSmeMod_SysUp;     //!
  TH1F *ETAU_EventFlow_TaSmeMod_SysDown;   //!
  TH1F *ETAU_EventFlow_JtSme_SysUp;        //!
  TH1F *ETAU_EventFlow_JtUncNP1_SysUp;     //!
  TH1F *ETAU_EventFlow_JtUncNP1_SysDown;   //!
  TH1F *ETAU_EventFlow_JtUncNP2_SysUp;     //!
  TH1F *ETAU_EventFlow_JtUncNP2_SysDown;   //!
  TH1F *ETAU_EventFlow_JtUncNP3_SysUp;     //!
  TH1F *ETAU_EventFlow_JtUncNP3_SysDown;   //!
  TH1F *ETAU_EventFlow_JtUncETA_SysUp;     //!
  TH1F *ETAU_EventFlow_JtUncETA_SysDown;   //!
  TH1F *ETAU_EventFlow_MetResPara;         //!
  TH1F *ETAU_EventFlow_MetResPerp;         //!
  TH1F *ETAU_EventFlow_MetScl_SysUp;       //!
  TH1F *ETAU_EventFlow_MetScl_SysDown;     //!
  TH1F *MUTAU_EventFlow;                   //!
  TH1F *MUTAU_EventFlow_MuSmeID_SysUp;     //!
  TH1F *MUTAU_EventFlow_MuSmeID_SysDown;   //!
  TH1F *MUTAU_EventFlow_MuSmeMS_SysUp;     //!
  TH1F *MUTAU_EventFlow_MuSmeMS_SysDown;   //!
  TH1F *MUTAU_EventFlow_MuScale_SysUp;     //!
  TH1F *MUTAU_EventFlow_MuScale_SysDown;   //!
  TH1F *MUTAU_EventFlow_MuSagRho_SysUp;    //!
  TH1F *MUTAU_EventFlow_MuSagRho_SysDown;  //!
  TH1F *MUTAU_EventFlow_MuSagRes_SysUp;    //!
  TH1F *MUTAU_EventFlow_MuSagRes_SysDown;  //!
  TH1F *MUTAU_EventFlow_ElSme_SysUp;       //!
  TH1F *MUTAU_EventFlow_ElSme_SysDown;     //!
  TH1F *MUTAU_EventFlow_ElScale_SysUp;     //!
  TH1F *MUTAU_EventFlow_ElScale_SysDown;   //!
  TH1F *MUTAU_EventFlow_TaSme_SysUp;       //!
  TH1F *MUTAU_EventFlow_TaSme_SysDown;     //!
  TH1F *MUTAU_EventFlow_TaSmeDet_SysUp;    //!
  TH1F *MUTAU_EventFlow_TaSmeDet_SysDown;  //!
  TH1F *MUTAU_EventFlow_TaSmeMod_SysUp;    //!
  TH1F *MUTAU_EventFlow_TaSmeMod_SysDown;  //!
  TH1F *MUTAU_EventFlow_JtSme_SysUp;       //!
  TH1F *MUTAU_EventFlow_JtUncNP1_SysUp;    //!
  TH1F *MUTAU_EventFlow_JtUncNP1_SysDown;  //!
  TH1F *MUTAU_EventFlow_JtUncNP2_SysUp;    //!
  TH1F *MUTAU_EventFlow_JtUncNP2_SysDown;  //!
  TH1F *MUTAU_EventFlow_JtUncNP3_SysUp;    //!
  TH1F *MUTAU_EventFlow_JtUncNP3_SysDown;  //!
  TH1F *MUTAU_EventFlow_JtUncETA_SysUp;    //!
  TH1F *MUTAU_EventFlow_JtUncETA_SysDown;  //!
  TH1F *MUTAU_EventFlow_MetResPara;        //!
  TH1F *MUTAU_EventFlow_MetResPerp;        //!
  TH1F *MUTAU_EventFlow_MetScl_SysUp;      //!
  TH1F *MUTAU_EventFlow_MetScl_SysDown;    //!
  TH1F *MuonFlow;                      //!
  TH1F *MuonFlow_MuSmeID_SysUp;        //!
  TH1F *MuonFlow_MuSmeID_SysDown;      //!
  TH1F *MuonFlow_MuSmeMS_SysUp;        //!
  TH1F *MuonFlow_MuSmeMS_SysDown;      //!
  TH1F *MuonFlow_MuScale_SysUp;        //!
  TH1F *MuonFlow_MuScale_SysDown;      //!
  TH1F *MuonFlow_MuSagRho_SysUp;       //!
  TH1F *MuonFlow_MuSagRho_SysDown;     //!
  TH1F *MuonFlow_MuSagRes_SysUp;       //!
  TH1F *MuonFlow_MuSagRes_SysDown;     //!
  TH1F *MuonFlow_ElSme_SysUp;          //!
  TH1F *MuonFlow_ElSme_SysDown;        //!
  TH1F *MuonFlow_ElScale_SysUp;        //!
  TH1F *MuonFlow_ElScale_SysDown;      //!
  TH1F *MuonFlow_TaSme_SysUp;          //!
  TH1F *MuonFlow_TaSme_SysDown;        //!
  TH1F *MuonFlow_TaSmeDet_SysUp;       //!
  TH1F *MuonFlow_TaSmeDet_SysDown;     //!
  TH1F *MuonFlow_TaSmeMod_SysUp;       //!
  TH1F *MuonFlow_TaSmeMod_SysDown;     //!
  TH1F *MuonFlow_JtSme_SysUp;          //!
  TH1F *MuonFlow_JtUncNP1_SysUp;       //!
  TH1F *MuonFlow_JtUncNP1_SysDown;     //!
  TH1F *MuonFlow_JtUncNP2_SysUp;       //!
  TH1F *MuonFlow_JtUncNP2_SysDown;     //!
  TH1F *MuonFlow_JtUncNP3_SysUp;       //!
  TH1F *MuonFlow_JtUncNP3_SysDown;     //!
  TH1F *MuonFlow_JtUncETA_SysUp;       //!
  TH1F *MuonFlow_JtUncETA_SysDown;     //!
  TH1F *MuonFlow_MetResPara;           //!
  TH1F *MuonFlow_MetResPerp;           //!
  TH1F *MuonFlow_MetScl_SysUp;         //!
  TH1F *MuonFlow_MetScl_SysDown;       //!
  TH1F *ElectronFlow;                  //!
  TH1F *ElectronFlow_MuSmeID_SysUp;    //!
  TH1F *ElectronFlow_MuSmeID_SysDown;  //!
  TH1F *ElectronFlow_MuSmeMS_SysUp;    //!
  TH1F *ElectronFlow_MuSmeMS_SysDown;  //!
  TH1F *ElectronFlow_MuScale_SysUp;    //!
  TH1F *ElectronFlow_MuScale_SysDown;  //!
  TH1F *ElectronFlow_MuSagRho_SysUp;   //!
  TH1F *ElectronFlow_MuSagRho_SysDown; //!
  TH1F *ElectronFlow_MuSagRes_SysUp;   //!
  TH1F *ElectronFlow_MuSagRes_SysDown; //!
  TH1F *ElectronFlow_ElSme_SysUp;      //!
  TH1F *ElectronFlow_ElSme_SysDown;    //!
  TH1F *ElectronFlow_ElScale_SysUp;    //!
  TH1F *ElectronFlow_ElScale_SysDown;  //!
  TH1F *ElectronFlow_TaSme_SysUp;      //!
  TH1F *ElectronFlow_TaSme_SysDown;    //!
  TH1F *ElectronFlow_TaSmeDet_SysUp;   //!
  TH1F *ElectronFlow_TaSmeDet_SysDown; //!
  TH1F *ElectronFlow_TaSmeMod_SysUp;   //!
  TH1F *ElectronFlow_TaSmeMod_SysDown; //!
  TH1F *ElectronFlow_JtSme_SysUp;      //!
  TH1F *ElectronFlow_JtUncNP1_SysUp;   //!
  TH1F *ElectronFlow_JtUncNP1_SysDown; //!
  TH1F *ElectronFlow_JtUncNP2_SysUp;   //!
  TH1F *ElectronFlow_JtUncNP2_SysDown; //!
  TH1F *ElectronFlow_JtUncNP3_SysUp;   //!
  TH1F *ElectronFlow_JtUncNP3_SysDown; //!
  TH1F *ElectronFlow_JtUncETA_SysUp;   //!
  TH1F *ElectronFlow_JtUncETA_SysDown; //!
  TH1F *ElectronFlow_MetResPara;       //!
  TH1F *ElectronFlow_MetResPerp;       //!
  TH1F *ElectronFlow_MetScl_SysUp;     //!
  TH1F *ElectronFlow_MetScl_SysDown;   //!
  TH1F *JetFlow;                       //!
  TH1F *JetFlow_MuSmeID_SysUp;         //!
  TH1F *JetFlow_MuSmeID_SysDown;       //!
  TH1F *JetFlow_MuSmeMS_SysUp;         //!
  TH1F *JetFlow_MuSmeMS_SysDown;       //!
  TH1F *JetFlow_MuScale_SysUp;         //!
  TH1F *JetFlow_MuScale_SysDown;       //!
  TH1F *JetFlow_MuSagRho_SysUp;        //!
  TH1F *JetFlow_MuSagRho_SysDown;      //!
  TH1F *JetFlow_MuSagRes_SysUp;        //!
  TH1F *JetFlow_MuSagRes_SysDown;      //!
  TH1F *JetFlow_ElSme_SysUp;           //!
  TH1F *JetFlow_ElSme_SysDown;         //!
  TH1F *JetFlow_ElScale_SysUp;         //!
  TH1F *JetFlow_ElScale_SysDown;       //!
  TH1F *JetFlow_TaSme_SysUp;           //!
  TH1F *JetFlow_TaSme_SysDown;         //!
  TH1F *JetFlow_TaSmeDet_SysUp;        //!
  TH1F *JetFlow_TaSmeDet_SysDown;      //!
  TH1F *JetFlow_TaSmeMod_SysUp;        //!
  TH1F *JetFlow_TaSmeMod_SysDown;      //!
  TH1F *JetFlow_JtSme_SysUp;           //!
  TH1F *JetFlow_JtUncNP1_SysUp;        //!
  TH1F *JetFlow_JtUncNP1_SysDown;      //!
  TH1F *JetFlow_JtUncNP2_SysUp;        //!
  TH1F *JetFlow_JtUncNP2_SysDown;      //!
  TH1F *JetFlow_JtUncNP3_SysUp;        //!
  TH1F *JetFlow_JtUncNP3_SysDown;      //!
  TH1F *JetFlow_JtUncETA_SysUp;        //!
  TH1F *JetFlow_JtUncETA_SysDown;      //!
  TH1F *JetFlow_MetResPara;            //!
  TH1F *JetFlow_MetResPerp;            //!
  TH1F *JetFlow_MetScl_SysUp;          //!
  TH1F *JetFlow_MetScl_SysDown;        //!
  TH1F *TauFlow;                       //!
  TH1F *TauFlow_MuSmeID_SysUp;         //!
  TH1F *TauFlow_MuSmeID_SysDown;       //!
  TH1F *TauFlow_MuSmeMS_SysUp;         //!
  TH1F *TauFlow_MuSmeMS_SysDown;       //!
  TH1F *TauFlow_MuScale_SysUp;         //!
  TH1F *TauFlow_MuScale_SysDown;       //!
  TH1F *TauFlow_MuSagRho_SysUp;        //!
  TH1F *TauFlow_MuSagRho_SysDown;      //!
  TH1F *TauFlow_MuSagRes_SysUp;        //!
  TH1F *TauFlow_MuSagRes_SysDown;      //!
  TH1F *TauFlow_ElSme_SysUp;           //!
  TH1F *TauFlow_ElSme_SysDown;         //!
  TH1F *TauFlow_ElScale_SysUp;         //!
  TH1F *TauFlow_ElScale_SysDown;       //!
  TH1F *TauFlow_TaSme_SysUp;           //!
  TH1F *TauFlow_TaSme_SysDown;         //!
  TH1F *TauFlow_TaSmeDet_SysUp;        //!
  TH1F *TauFlow_TaSmeDet_SysDown;      //!
  TH1F *TauFlow_TaSmeMod_SysUp;        //!
  TH1F *TauFlow_TaSmeMod_SysDown;      //!
  TH1F *TauFlow_JtSme_SysUp;           //!
  TH1F *TauFlow_JtUncNP1_SysUp;        //!
  TH1F *TauFlow_JtUncNP1_SysDown;      //!
  TH1F *TauFlow_JtUncNP2_SysUp;        //!
  TH1F *TauFlow_JtUncNP2_SysDown;      //!
  TH1F *TauFlow_JtUncNP3_SysUp;        //!
  TH1F *TauFlow_JtUncNP3_SysDown;      //!
  TH1F *TauFlow_JtUncETA_SysUp;        //!
  TH1F *TauFlow_JtUncETA_SysDown;      //!
  TH1F *TauFlow_MetResPara;            //!
  TH1F *TauFlow_MetResPerp;            //!
  TH1F *TauFlow_MetScl_SysUp;          //!
  TH1F *TauFlow_MetScl_SysDown;        //!
  TH1F *PhFlow;                        //!
  TH1F *PhFlow_MuSmeID_SysUp;          //!
  TH1F *PhFlow_MuSmeID_SysDown;        //!
  TH1F *PhFlow_MuSmeMS_SysUp;          //!
  TH1F *PhFlow_MuSmeMS_SysDown;        //!
  TH1F *PhFlow_MuScale_SysUp;          //!
  TH1F *PhFlow_MuScale_SysDown;        //!
  TH1F *PhFlow_MuSagRho_SysUp;         //!
  TH1F *PhFlow_MuSagRho_SysDown;       //!
  TH1F *PhFlow_MuSagRes_SysUp;         //!
  TH1F *PhFlow_MuSagRes_SysDown;       //!
  TH1F *PhFlow_ElSme_SysUp;            //!
  TH1F *PhFlow_ElSme_SysDown;          //!
  TH1F *PhFlow_ElScale_SysUp;          //!
  TH1F *PhFlow_ElScale_SysDown;        //!
  TH1F *PhFlow_TaSme_SysUp;            //!
  TH1F *PhFlow_TaSme_SysDown;          //!
  TH1F *PhFlow_TaSmeDet_SysUp;         //!
  TH1F *PhFlow_TaSmeDet_SysDown;       //!
  TH1F *PhFlow_TaSmeMod_SysUp;         //!
  TH1F *PhFlow_TaSmeMod_SysDown;       //!
  TH1F *PhFlow_JtSme_SysUp;            //!
  TH1F *PhFlow_JtUncNP1_SysUp;         //!
  TH1F *PhFlow_JtUncNP1_SysDown;       //!
  TH1F *PhFlow_JtUncNP2_SysUp;         //!
  TH1F *PhFlow_JtUncNP2_SysDown;       //!
  TH1F *PhFlow_JtUncNP3_SysUp;         //!
  TH1F *PhFlow_JtUncNP3_SysDown;       //!
  TH1F *PhFlow_JtUncETA_SysUp;         //!
  TH1F *PhFlow_JtUncETA_SysDown;       //!
  TH1F *PhFlow_MetResPara;             //!
  TH1F *PhFlow_MetResPerp;             //!
  TH1F *PhFlow_MetScl_SysUp;           //!
  TH1F *PhFlow_MetScl_SysDown;         //!
  void DefineHistograms();
  void FillHistogramsMaps();
  void CreateListOfHistograms();
  std::map<int,TH1F*> m_EMU_EvtFlow;   //!
  std::map<int,TH1F*> m_ETAU_EvtFlow;  //!
  std::map<int,TH1F*> m_MUTAU_EvtFlow; //!
  std::map<int,TH1F*> m_MuFlow;        //!
  std::map<int,TH1F*> m_ElFlow;        //!
  std::map<int,TH1F*> m_TaFlow;        //!
  std::map<int,TH1F*> m_JetFlow;       //!
  std::map<int,TH1F*> m_PhFlow;        //!
  std::map<int,TH1F*> m_Weights;       //!
  std::map<int,TH1F*> m_WeightsBJ;     //!

  std::string m_tmpName; //!
  
  /* Tree Variables */
  void SetTreeBranches();
  void ResetVariables();
  std::string filename;     //! 
  unsigned long long event; //!
  int run;                  //!
  int rndRun;               //!
  int lbn;                  //!
  double mcweight;          //!
  double puweight;          //!
  double puweight_SysUp;    //!
  double puweight_SysDown;  //!
  double weight;            //!
  double weightWjetSF;      //!
  double weightWbtagSF;     //!
  double xsec;              //!
  double kfact;             //!
  double avgIntxCross;      //!
  double actIntxCross;      //!
  double dilepMass;         //!
  double dilepCorrMass;     //!
  double dilepPt;           //!
  double dilepCorrPt;       //!
  double dilepEta;          //!
  double dilepPhi;          //!
  double dilepDeltaPhi;     //!
  double ditauTrueM;        //!
  bool isTauContr;          //!
  double met_px;            //!
  double met_py;            //!
  double met_phi;           //!
  double met_et;            //!
  double met_sumet;         //!
  int channel;              //!
  std::vector<int>    Lep_Id;       //!
  std::vector<double> Lep_pt;       //!
  std::vector<double> Lep_E;        //!
  std::vector<double> Lep_eta;      //!
  std::vector<double> Lep_etaTrk;   //!
  std::vector<double> Lep_phi;      //!
  std::vector<double> Lep_d0;       //!
  std::vector<double> Lep_d0sig;    //!
  std::vector<double> Lep_z0;       //!
  std::vector<double> Lep_deltaz0;  //!
  std::vector<int>    Lep_Iso;      //!
  std::vector<double> Lep_trkIsoPt; //!
  std::vector<double> Lep_caloIsoPt;//!
  std::vector<int>    Lep_trigMat;  //!
  std::vector<int>    Lep_nProngs;  //!
  
  std::vector<double> Lep_TrigSF;          //!
  std::vector<double> Lep_TrigSF_StatUp;   //!
  std::vector<double> Lep_TrigSF_StatDown; //!
  std::vector<double> Lep_TrigSF_SysUp;    //!
  std::vector<double> Lep_TrigSF_SysDown;  //!

  std::vector<double> Lep_RecoSF;             //!
  std::vector<double> Lep_RecoSF_StatUp;      //!
  std::vector<double> Lep_RecoSF_StatDown;    //!
  std::vector<double> Lep_RecoSF_SysUp;       //!
  std::vector<double> Lep_RecoSF_SysDown;     //!
  std::vector<double> Lep_RecoSF_Hpt_SysUp;   //! 
  std::vector<double> Lep_RecoSF_Hpt_SysDown; //!
  
  std::vector<double> Lep_IDSF;               //!
  std::vector<double> Lep_IDSF_StatUp;        //!
  std::vector<double> Lep_IDSF_StatDown;      //!
  std::vector<double> Lep_IDSF_SysUp;         //!
  std::vector<double> Lep_IDSF_SysDown;       //!
  std::vector<double> Lep_IDSF_Hpt_SysUp;     //!
  std::vector<double> Lep_IDSF_Hpt_SysDown;   //!
  					      
  std::vector<double> Lep_IsoSF;              //!
  std::vector<double> Lep_IsoSF_StatUp;       //!
  std::vector<double> Lep_IsoSF_StatDown;     //!
  std::vector<double> Lep_IsoSF_SysUp;        //!
  std::vector<double> Lep_IsoSF_SysDown;      //!
					      
  std::vector<double> Lep_TtvaSF;             //!
  std::vector<double> Lep_TtvaSF_StatUp;      //!
  std::vector<double> Lep_TtvaSF_StatDown;    //!
  std::vector<double> Lep_TtvaSF_SysUp;       //!
  std::vector<double> Lep_TtvaSF_SysDown;     //!

  std::vector<double> Lep_BadMuSF;            //!
					      
  std::vector<double> Lep_L1CaloSF;           //!
    					      
  std::vector<double> Lep_ElOlrSF;            //!
  std::vector<double> Lep_ElOlrSF_SysUp;      //!
  std::vector<double> Lep_ElOlrSF_SysDown;    //!
  
  std::vector<double> Jet_pt;                     //!
  std::vector<double> Jet_eta;                    //!
  std::vector<double> Jet_etaEM;                  //!
  std::vector<double> Jet_phi;                    //!
  std::vector<double> Jet_JvtSF;                  //!
  std::vector<double> Jet_JvtSF_SysUp;            //!
  std::vector<double> Jet_JvtSF_SysDown;          //!
  std::vector<int>    Jet_isBjet;                 //!
  std::vector<double> Jet_BtagSF;                 //!
  std::vector<double> Jet_BtagSF_Beff_SysUp;      //!
  std::vector<double> Jet_BtagSF_Beff_SysDown;	  //!
  std::vector<double> Jet_BtagSF_Ceff_SysUp;	  //!
  std::vector<double> Jet_BtagSF_Ceff_SysDown;	  //!
  std::vector<double> Jet_BtagSF_Leff_SysUp;	  //!
  std::vector<double> Jet_BtagSF_Leff_SysDown;	  //!
  std::vector<double> Jet_BtagSF_ExtCeff_SysUp;	  //!
  std::vector<double> Jet_BtagSF_ExtCeff_SysDown; //!
  std::vector<double> Jet_BtagSF_ExtEff_SysUp;	  //!
  std::vector<double> Jet_BtagSF_ExtEff_SysDown;  //!
    
  /* Utils */
  double ComputeDeltaR(double eta1, double phi1, double eta2, double phi2);
  double ComputeDeltaPhi(double phi1, double phi2);
  bool CheckLepsDR(const xAOD::IParticle *p1, const xAOD::IParticle *p2);
  bool CheckJetLepDR(const xAOD::Jet *jet, const xAOD::IParticle *p); 
  double GetCrossSection();
  double GetKfactor();
  bool CheckOverlap();
  void DetectYear(Int_t runNumber);
  std::string GetFileName(std::string);
  
  /* MC Truth Selection */
  void MCTruthSel();
  double TrueDiTauMass();
  bool CheckTauContr();
  void DecorateJets();
  
  /* Event and Object variables */
  bool isMC        ; //!
  bool isKeepEvent ; //!
  bool isVertexGood; //!
  bool isEvtGood   ; //!
  bool isTrigGood  ; //!
  bool isMuonTrig  ; //!
  bool isElecTrig  ; //!
  //bool isHLT_e120_lhloose;        //!
  //bool isHLT_e24_lhmedium_iloose; //!
  //bool isHLT_e60_lhmedium;        //!
  //bool isHLT_mu20_iloose_L1MU15;  //!
  //bool isHLT_mu24_iloose_L1MU15;  //!
  //bool isHLT_mu24_imedium;        //!
  //bool isHLT_mu26_imedium;        //!
  //bool isHLT_mu50;                //!
  bool isTrgMtcGood; //!
  bool isTwoLep    ; //!
  bool isNlepGood  ; //!
  bool isBadMuonEvt; //!
  bool isBadJetEvt ; //!
  bool isOSGood    ; //!
  bool isBTBGood   ; //!
  bool isBjetEvt   ; //!
  bool isMetGood   ; //!  
  
  /* Internal Methods variables */
  std::vector<const xAOD::TruthParticle*> m_TrueTaus;       //!
  std::vector<const xAOD::Muon*> m_Muons;                   //!
  std::vector<const xAOD::Muon*> m_AddMuons;                //!
  std::vector<const xAOD::Electron*> m_Electrons;           //!
  std::vector<const xAOD::Electron*> m_AddElectrons;        //!
  std::vector<const xAOD::TauJet*> m_Taus;                  //!
  std::vector<const xAOD::Jet*> m_Jets;                     //!
  std::vector<TObject*> m_Hist;                             //!
  std::map<int, std::vector<std::string> > m_MuTrigChains;  //!
  std::map<int, std::vector<std::string> > m_ElTrigChains;  //!
  std::string m_muTMstring;                                 //!
  bool m_priVtxFound;                                       //!
  xAOD::MuonContainer *m_SelectedMuon;                      //!
  xAOD::MuonAuxContainer *m_SelectedMuonAux;                //!
  xAOD::MissingETContainer *m_BuildMet;                     //!
  xAOD::MissingETAuxContainer *m_BuildMetAux;               //!
  xAOD::Muon* m_newMuon;                                    //!
  xAOD::MissingET* m_softTrkMet;                            //!
  xAOD::TStore* m_store;                                    //!
  xAOD::MuonContainer *m_MetMuons;                          //!
  xAOD::ElectronContainer *m_MetElectrons;                  //!
  xAOD::TauJetContainer *m_MetTaus;                         //!
  xAOD::PhotonContainer *m_MetPhotons;                      //!
  
  /* Manage Memory */
  void CleanMemory(bool useStore=false);
  void CreateShallowCopies();
  void DeleteShallowCopies(bool useStore=false);
  void CleanObjVectors();
  void ResetContainers();
  
  /* Tools objects */
  void ToolsInitializer();
  void MuonToolsInitializer();
  void ElectronToolsInitializer();
  void TauToolsInitializer();
  void JetToolsInitializer();
  void ToolsDestructor();
  void MuonToolsDestructor();
  void ElectronToolsDestructor();
  void TauToolsDestructor();
  void JetToolsDestructor();
  std::string m_jetConf;     //!
  std::string m_jetCalibSeq; //!
  std::string m_metPrefix;   //!
  std::string m_metSoftFile; //!
  GoodRunsListSelectionTool*  m_grl;                                 //!
  CP::PileupReweightingTool*  m_puTool;                              //! 
  ToolHandle<CP::IPileupReweightingTool> m_PRWth;                    //!
  TrigConf::xAODConfigTool*   m_confTool;                            //!
  Trig::TrigDecisionTool*     m_tdt;                                 //!
  CP::MuonSelectionTool*      m_muSel;                               //!
  AsgElectronLikelihoodTool*  m_elSelTig;                            //!
  AsgElectronLikelihoodTool*  m_elSelMed;                            //!
  CP::IsolationSelectionTool* m_iso;                                 //!
  CP::IsolationCorrectionTool* m_isoCorr;                            //!
  CP::MuonCalibrationAndSmearingTool* m_muSmear2016;                 //!
  CP::MuonCalibrationAndSmearingTool* m_muSmear2017;                 //!
  CP::MuonCalibrationAndSmearingTool* m_muSmear2018;                 //!
  CP::EgammaCalibrationAndSmearingTool* m_elSmear;                   //!
  Trig::MatchingTool* m_trigMatch;                                   //! 
  AsgElectronEfficiencyCorrectionTool* m_elIDSF_Tig;                 //!
  AsgElectronEfficiencyCorrectionTool* m_elIDSF_Med;                 //!
  AsgElectronEfficiencyCorrectionTool* m_elRecoSF;                   //!
  AsgElectronEfficiencyCorrectionTool* m_elIsoSF_Tig;                //!
  AsgElectronEfficiencyCorrectionTool* m_elIsoSF_Med;                //!
  AsgElectronEfficiencyCorrectionTool* m_elTrigSF_Tig;               //!
  AsgElectronEfficiencyCorrectionTool* m_elTrigSF_Med;               //!
  CP::MuonTriggerScaleFactors* m_muTrigSF;                           //!
  CP::MuonEfficiencyScaleFactors* m_muRecoSF;                        //!
  CP::MuonEfficiencyScaleFactors* m_muBadMuSF;                       //!
  CP::MuonEfficiencyScaleFactors* m_muIsoSF;                         //!
  CP::MuonEfficiencyScaleFactors* m_muTTVASF;                        //!
  TauAnalysisTools::TauSelectionTool* m_tauSelLoo;                   //!
  TauAnalysisTools::TauSelectionTool* m_tauElOR;                     //!
  TauAnalysisTools::TauOverlappingElectronLLHDecorator* m_tauEleLLH; //!
  TauAnalysisTools::TauTruthMatchingTool* m_tauTrMtc;                //!
  TauAnalysisTools::TauSmearingTool* m_tauSmear;                     //!
  TauAnalysisTools::TauEfficiencyCorrectionsTool* m_tauRecoSF;       //!
  TauAnalysisTools::TauEfficiencyCorrectionsTool* m_tauElOlrSF;      //!
  TauAnalysisTools::TauEfficiencyCorrectionsTool* m_tauJetIDSF;      //!
  JetVertexTaggerTool* m_jetVtxTag;                                  //!
  ToolHandle<IJetUpdateJvt> m_jetVtxTagUp;                           //!
  JetForwardJvtTool* m_jetFrwJvtTool;                                //!
  JetCleaningTool* m_jetClean;                                       //!
  CP::JetJvtEfficiency *m_jetJvtSF;                                  //!
  JetCalibrationTool* m_jetCalib;                                    //!
  JERTool* m_jetReso;                                                //!
  JERSmearingTool* m_jetSmear;                                       //!
  ToolHandle<IJERTool> m_jetResoHand;                                //!
  JetUncertaintiesTool *m_jetUnc;                                    //!
  BTaggingSelectionTool * m_btagSel;                                 //!
  BTaggingEfficiencyTool* m_btagSF;                                  //!
  asg::AnaToolHandle<IMETMaker> m_metMaker;                          //!
  asg::AnaToolHandle<IMETSystematicsTool> m_metSys;                  //!
  asg::AnaToolHandle<ORUtils::IOverlapRemovalTool> m_ORTool;         //!
  ORUtils::ORFlags m_orFlags;                                        //!
  ORUtils::ToolBox m_toolBox;                                        //!
  LFVUtils::MCSampleInfo* m_mcInfo;                                  //!
  LFVUtils::MCSampleOverlap* m_mcOverlap;                            //!
  std::vector<AsgElectronEfficiencyCorrectionTool*> m_elIDSF;        //!
  std::vector<AsgElectronEfficiencyCorrectionTool*> m_elIsoSF;       //!
  std::vector<AsgElectronEfficiencyCorrectionTool*> m_elTrigSF;      //!
  std::vector<CP::MuonCalibrationAndSmearingTool*> m_muSmear;        //!

  /* Systematic Uncertainties */
  void DefineSystematicsVariations();
  void DefineMuonSystematics();
  void DefineElectronSystematics();
  void DefineTauSystematics();
  void DefineJetSystematics();
  void DefinePileUpWgtSystematics();
  void DefineMETSystematics();
  void FillSystematicsMaps();
  void FillSystematicsNames();
  void CreateSystematicsVector();
  void PrintSystematics();
  std::vector<int> m_Systs; //!
  std::map<int,CP::SystematicSet> m_MuSFVar;  //!
  std::map<int,CP::SystematicSet> m_MuSHVar;  //!
  std::map<int,CP::SystematicSet> m_ElSFVar;  //!
  std::map<int,CP::SystematicSet> m_ElSHVar;  //!
  std::map<int,CP::SystematicSet> m_TaSFVar;  //!
  std::map<int,CP::SystematicSet> m_TaSHVar;  //!
  std::map<int,CP::SystematicSet> m_JtSFVar;  //!
  std::map<int,CP::SystematicSet> m_JtSHVar;  //!
  std::map<int,CP::SystematicSet> m_JtUNVar;  //!
  std::map<int,CP::SystematicSet> m_PuWgtVar; //!
  std::map<int,CP::SystematicSet> m_MetVar;   //!
  std::map<int,std::string> m_MuSFVarName;    //!
  std::map<int,std::string> m_MuSHVarName;    //!
  std::map<int,std::string> m_ElSFVarName;    //!
  std::map<int,std::string> m_ElSHVarName;    //!
  std::map<int,std::string> m_TaSFVarName;    //!
  std::map<int,std::string> m_TaSHVarName;    //!
  std::map<int,std::string> m_JtSFVarName;    //!
  std::map<int,std::string> m_JtSHVarName;    //!
  std::map<int,std::string> m_JtUNVarName;    //!
  std::map<int,std::string> m_PuWgtVarName;   //!
  std::map<int,std::string> m_MetVarName;     //!
  CP::SystematicSet m_NominalSysSet;      //!
  CP::SystematicSet m_MuReco_StatUp;	  //!
  CP::SystematicSet m_MuReco_StatDown;	  //!
  CP::SystematicSet m_MuReco_SysUp;	  //!
  CP::SystematicSet m_MuReco_SysDown;	  //!
  CP::SystematicSet m_MuIso_StatUp;	  //!
  CP::SystematicSet m_MuIso_StatDown;	  //!
  CP::SystematicSet m_MuIso_SysUp;	  //!
  CP::SystematicSet m_MuIso_SysDown;	  //!
  CP::SystematicSet m_MuTrg_StatUp;	  //!
  CP::SystematicSet m_MuTrg_StatDown;	  //!
  CP::SystematicSet m_MuTrg_SysUp;	  //!
  CP::SystematicSet m_MuTrg_SysDown;	  //!
  CP::SystematicSet m_MuTTVA_StatUp;      //!
  CP::SystematicSet m_MuTTVA_StatDown;    //!
  CP::SystematicSet m_MuTTVA_SysUp;       //!
  CP::SystematicSet m_MuTTVA_SysDown;     //!
  CP::SystematicSet m_MuSmeID_SysUp;	  //!
  CP::SystematicSet m_MuSmeID_SysDown;	  //!
  CP::SystematicSet m_MuSmeMS_SysUp;	  //!
  CP::SystematicSet m_MuSmeMS_SysDown;	  //!
  CP::SystematicSet m_MuScale_SysUp;	  //!
  CP::SystematicSet m_MuScale_SysDown;	  //!
  CP::SystematicSet m_MuSagRho_SysUp;     //!
  CP::SystematicSet m_MuSagRho_SysDown;   //!
  CP::SystematicSet m_MuSagRes_SysUp;     //!
  CP::SystematicSet m_MuSagRes_SysDown;   //!
  CP::SystematicSet m_ElReco_SysUp;	  //!
  CP::SystematicSet m_ElReco_SysDown;	  //!
  CP::SystematicSet m_ElID_SysUp;	  //!
  CP::SystematicSet m_ElID_SysDown;	  //!
  CP::SystematicSet m_ElIso_SysUp;	  //!
  CP::SystematicSet m_ElIso_SysDown;	  //!
  CP::SystematicSet m_ElTrg_SysUp;	  //!
  CP::SystematicSet m_ElTrg_SysDown;	  //!
  CP::SystematicSet m_ElSme_SysUp;	  //!
  CP::SystematicSet m_ElSme_SysDown;	  //!
  CP::SystematicSet m_ElScale_SysUp;	  //!
  CP::SystematicSet m_ElScale_SysDown;    //!
  CP::SystematicSet m_TaReco_SysUp;       //!
  CP::SystematicSet m_TaReco_SysDown;     //!
  CP::SystematicSet m_TaRecoHpt_SysUp;    //!
  CP::SystematicSet m_TaRecoHpt_SysDown;  //!
  CP::SystematicSet m_TaEleOlr_SysUp;	  //!
  CP::SystematicSet m_TaEleOlr_SysDown;	  //!
  CP::SystematicSet m_TaJetID_SysUp;	  //!
  CP::SystematicSet m_TaJetID_SysDown;	  //!
  CP::SystematicSet m_TaJetIDHpt_SysUp;	  //!
  CP::SystematicSet m_TaJetIDHpt_SysDown; //!
  CP::SystematicSet m_TaSme_SysUp;        //!
  CP::SystematicSet m_TaSme_SysDown;      //!
  CP::SystematicSet m_TaSmeDet_SysUp;     //!
  CP::SystematicSet m_TaSmeDet_SysDown;   //!
  CP::SystematicSet m_TaSmeMod_SysUp;     //!
  CP::SystematicSet m_TaSmeMod_SysDown;   //!
  CP::SystematicSet m_JtBeff_SysUp;       //!
  CP::SystematicSet m_JtBeff_SysDown;	  //!
  CP::SystematicSet m_JtCeff_SysUp;	  //!
  CP::SystematicSet m_JtCeff_SysDown;	  //!
  CP::SystematicSet m_JtLeff_SysUp;	  //!
  CP::SystematicSet m_JtLeff_SysDown;	  //!
  CP::SystematicSet m_JtExtCeff_SysUp;	  //!
  CP::SystematicSet m_JtExtCeff_SysDown;  //!
  CP::SystematicSet m_JtExtEff_SysUp;	  //!
  CP::SystematicSet m_JtExtEff_SysDown;   //!
  CP::SystematicSet m_JtJvt_SysUp;        //!
  CP::SystematicSet m_JtJvt_SysDown;      //!
  CP::SystematicSet m_JtSme_SysUp;        //!
  CP::SystematicSet m_JtUncNP1_SysUp;     //!
  CP::SystematicSet m_JtUncNP1_SysDown;	  //!
  CP::SystematicSet m_JtUncNP2_SysUp;	  //!
  CP::SystematicSet m_JtUncNP2_SysDown;	  //!
  CP::SystematicSet m_JtUncNP3_SysUp;	  //!
  CP::SystematicSet m_JtUncNP3_SysDown;   //!
  CP::SystematicSet m_JtUncETA_SysUp;     //!
  CP::SystematicSet m_JtUncETA_SysDown;   //!
  CP::SystematicSet m_PuWgt_SysUp;        //!
  CP::SystematicSet m_PuWgt_SysDown;      //!
  CP::SystematicSet m_MetResPara;         //!
  CP::SystematicSet m_MetResPerp;         //!
  CP::SystematicSet m_MetScl_SysUp;       //!
  CP::SystematicSet m_MetScl_SysDown;     //!
  std::map<std::string, CP::SystematicSet> m_recSysSet; //!
  
  
  /* Needed to distribute the algorithm to the workers */
  ClassDef(HighMassLFV, 1);
};

#endif
