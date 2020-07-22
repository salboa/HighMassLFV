#!/usr/bin/python
import os
import sys
import subprocess
import getopt
import string

IsolationTool = [ "IsolationSelection"                   , "00-06-07"    ]
IsolCorrTool  = [ "IsolationCorrections"                 , "00-01-27"    ]
PuReweighting = [ "PileupReweighting"                    , "00-04-04"    ]
GoodRunList   = [ "GoodRunsLists"                        , "00-01-34"    ]
TrackHelpers  = [ "xAODTracking"                         , "00-13-27"    ]
LepTrigMatch  = [ "TriggerMatchingTool"                  , "00-00-12"    ]
ElecSelection = [ "ElectronPhotonSelectorTools"          , "00-02-92-24" ]
ElecEffyCorr  = [ "ElectronEfficiencyCorrection"         , "00-02-03"    ] #04
ElecMomCorr   = [ "ElectronPhotonFourMomentumCorrection" , "02-03-13"    ]
EgammaCalib   = [ "egammaLayerRecalibTool"               , "00-02-13"    ]
MuonSelection = [ "MuonSelectorTools"                    , "00-05-41"    ]
MuomMonCorr   = [ "MuonMomentumCorrections"              , "01-00-60"    ]
MuonEffyCorr  = [ "MuonEfficiencyCorrections"            , "04-00-14"    ]
TauAnalyTool  = [ "TauAnalysisTools"                     , "00-02-60"    ]
JetMomentum   = [ "JetMomentTools"                       , "00-03-52-01" ]
JetSelection  = [ "JetSelectorTools"                     , "00-06-03"    ]
JetJvtEffTool = [ "JetJvtEfficiency"                     , "00-00-13"    ]
JetCalibTool  = [ "JetCalibTools"                        , "00-04-77"    ]
JetResoTool   = [ "JetResolution"                        , "03-00-49"    ]
JetUncTool    = [ "JetUncertainties"                     , "00-09-63"    ]
BTaggingTool  = [ "xAODBTaggingEfficiency"               , "00-00-36"    ]
METInterface  = [ "METInterface"                         , "00-02-08"    ]
METUtilities  = [ "METUtilities"                         , "00-02-47"    ] 
OverlapTool   = [ "AssociationUtils"                     , "01-01-50"    ]
EventLoop     = [ "EventLoop"                            , "00-01-55"    ]
EventLoopAlg  = [ "EventLoopAlgs"                        , "00-00-32"    ]
EventLoopGrid = [ "EventLoopGrid"                        , "00-00-53"    ]
LFVUtils      = [ "LFVUtils"                             , "00-01-04"    ]


Packages = [ IsolationTool , IsolCorrTool  , PuReweighting , GoodRunList   ,
             TrackHelpers  , LepTrigMatch  , ElecSelection , ElecEffyCorr  ,
             ElecMomCorr   , EgammaCalib   , MuonSelection , MuomMonCorr   , 
             MuonEffyCorr  , TauAnalyTool  , JetMomentum   , JetSelection  , 
             JetJvtEffTool , JetCalibTool  , JetResoTool   , JetUncTool    , 
             BTaggingTool  , METInterface  , METUtilities  , OverlapTool   ,
             EventLoop     , EventLoopAlg  , EventLoopGrid ] #, LFVUtils     ]


#Download packages if needed
for pack in Packages:

    if pack[0]=="LFVUtils":
        print "Checking package "+pack[0]
        cmd  = "svn co svn+ssh://svn.cern.ch/reps/atlasphys-exo/Physics/Exotic/LPX/LFVHighMassDilepton/Run2/AnalysisCode/LFVUtils/tags/"
        cmd +=pack[0]+"-"+pack[1]+" "+pack[0]
        os.system(cmd)
    else:
        print "Checking package "+pack[0]
        check  = "rc version | grep "+pack[0]
        output = subprocess.check_output(check, shell=True)
        value,key = output.split('tags/'+pack[0]+'-',1)
        version = key.rstrip()
        path    = value
	print path
        print "         version found = "+version
        if version == pack[1]:
            print "         package up to date"
        else:
            print "         Updating from version "+version+" to "+pack[1]
            co = "rc checkout_pkg "+path+"tags/"+pack[0]+"-"+pack[1]
            os.system(co)
    
        print ""
