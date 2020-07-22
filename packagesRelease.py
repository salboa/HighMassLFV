#!/usr/bin/python
import os
import sys
import subprocess
import getopt
import string

IsolationTool = "IsolationSelection"
IsolCorrTool  = "IsolationCorrections"
PuReweighting = "PileupReweighting"
GoodRunList   = "GoodRunsLists"
TrackHelpers  = "xAODTracking"
ElecSelection = "ElectronPhotonSelectorTools"
ElecEffyCorr  = "ElectronEfficiencyCorrection"        
ElecMomCorr   = "ElectronPhotonFourMomentumCorrection"
MuonSelection = "MuonSelectorTools"
MuomMonCorr   = "MuonMomentumCorrections"
MuonEffyCorr  = "MuonEfficiencyCorrections"
LepTrigMatch  = "TriggerMatchingTool"
TauAnalyTool  = "TauAnalysisTools"
JetMomentum   = "JetMomentTools"
JetSelection  = "JetSelectorTools"
JetJvtEffTool = "JetJvtEfficiency"
JetCalibTool  = "JetCalibTools"
JetResoTool   = "JetResolution"
JetUncTool    = "JetUncertainties"
BTaggingTool  = "xAODBTaggingEfficiency"
METInterface  = "METInterface"
METUtilities  = "METUtilities"
OverlapTool   = "AssociationUtils"


Packages = [ IsolationTool , IsolCorrTool  , PuReweighting , GoodRunList   ,
             TrackHelpers  , LepTrigMatch  , ElecSelection , ElecEffyCorr  ,
             ElecMomCorr   , MuonSelection , MuomMonCorr   , MuonEffyCorr  ,
             TauAnalyTool  , JetMomentum   , JetSelection  , JetJvtEffTool ,
             JetCalibTool  , JetResoTool   , JetUncTool    , BTaggingTool  , 
             METInterface  , METUtilities  , OverlapTool ]


#Download packages if needed
for pack in Packages:

    print "Checking package "+pack
    check  = "rc version | grep "+pack
    os.system(check)
