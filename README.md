#    HighMassLFV selection package   #

#    Description   #

This project contains the selection code used for the Exotics LFV search.

   - performs emu, etau and mutau selection
   - creates a flat Ntuple as output

#    Compiling: first compilation  #

This package needs ATLAS Analysis Base.

   - login on lxplus
   - setup ATLAS software (type 'setupATLAS')
   - create a 'source'
   - download 'LFVUtils' package in this directory
   - go back and creat a 'build' directory and enter it
   - setup analysis base release (type 'lsetup 'asetup AnalysisBase, 21.2.51')
   - run 'cmake ../source'
   - compile ('make')

#    Running   #
   - at compilation finished, type 'source x86_64-slc6-gcc62-opt/setup.sh'
   - once done you are ready to either run locally or submit jobs on the grid
   - to see all possible options type 'RunAnalysis --help' , below the output:

```
RunAnlysis: Run HighMass LFV analysis!!
  Usage  :  RunAnalysis [Options]
              --submitDir          [Set Output Directory: default is 'submitDir']
              --sampleHandlingMode [Define samples handling mode: default is 'readFileList'
                                    other options are: 'scanRucio', 'addGrid', 'ScanDir' ]
              --localPath          [Set local path to sample/files: default is '' ]
              --localSamplePattern [Set local sample pattern: default is '*.root'
                                    use all files found in local path]
              --maxEventNumber     [Set maximum number of events to process: default is -1 (all)]
              --inputDS            [Set input dataset: default is '' 
              --useGrid            [Enable Grid submission:  default is false (local submission)]
              --nickname           [Define Grid nickname: default is 'salvucci']
              --tagVersion         [Define output dataset tag version: default is 'current date' ]
              --projectName        [Define outout dataset project name: defaul is 'xAODrun']
              --maxFileJob         [Set maximum number of files per job: defaul is 2]
              --mergeOutput        [Set merging output flag: default is false
              --useCorrections     [Enable leptons correction: default is false]
              --useWeights         [Enable events and leptons weights: default is false]
              --useData            [Enable electron calibration for Data: default is false]
              --isDebugStream      [Enable running on Data Debug Stream: default is false]
              --fixPuChannel       [Set Default Channel for PileUp Reweighting: default is false]
              --mcType             [Specify a MC version: default is 'mc16a']
              --doSystematics      [Enable shape Systematics evaluation: default is false]
              --debug              [Enable debug mode: default is false]
              --verbose            [Enable verbose mode: default is false 
                                    (if true also debug is enabled) ]
              --isFastSim          [Enable Fast Simulation flag: default is false]
              --isQcdCR            [Enable QCD Control Region selection flag: default is false]
              --noTauId            [Enable Tau selection without Tau ID: default is false]
              --failTauId          [Enable QCD Control Region with fail Tau ID: default is false]
              --evalEgammaQuant    [Enable evaluating Egamma quantities: default is false]
              --useBDTcut          [Enable TauBDTcut when noTauId is requested: default is false]
              --BDTscore           [Set TauJetBDT score value: default is 0.40]
              --printFlow          [Enable Event/Objects Flows print: default is false]
              --printTrigList      [Enable print available Trigger chains: default is false]
              --printSystList      [Enable print recommended systematics: default is false]
              --singleEvent        [Specify event number to run on: default is '0' (all events)]
```

## Type of local runs on simulation ##

   - run main analysis:
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useCorrections --useWeights 
```

   - if simulation is fastSim (i.e. signal samples), add the option --isFastSim
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useCorrections --useWeights --isFastSim
```

   - if you would like to create also systematics tree, add option --doSystematics
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useCorrections --useWeights --doSystematics
```

   - run analysis without tau Identification requirement (usually done only on W+jets sample)
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useCorrections --useWeights --noTauId
```

   - run analysis with category FakeLep-RealLep for QCD estimation (done for etau/mutau channels)
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useCorrections --useWeights --isQcdCR
```

   - run analysis with category FakeLep-FakeLep for QCD estimation (done for etau/mutau channels)
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useCorrections --useWeights --isQcdCR --failTauId
```

## Type of local runs on data ##

   - run main analysis:
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useData
```

   - run main analysis on Data Debug Stream:
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useData --isDebugStream
```

   - run analysis without tau Identification requirement (usually done only on W+jets sample)
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useData --noTauId
```

   - run analysis with category FakeLep-RealLep for QCD estimation (done for etau/mutau channels)
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useData --isQcdCR
```

   - run analysis with category FakeLep-FakeLep for QCD estimation (done for etau/mutau channels)
```
RunAnalysis --submitDir OutDirName --localPath PathToDir --useData --isQcdCR --failTauId
```


#  Submitting Jobs on the ATLAS Grid  #

   - for jobs submission, a python script (SubmitJobs.py) should be used
   - List of Background, Signal and Data samples are defined in Background.py, Data.py and Signal.py respectively (for both 50ns and 25ns)
   - if you would like to send jobs on a single samples, you have to modify the list in previous files
   - to see all possible options type 'python SubmitJobs.py --help' , below the output:
```
Script to run HighMassLFV selection over all datasets!
  Usage   : ./SubmitJobs.py [Options]!
            Options:  
                     nickname=salvucci            : default is 'salvucci'
                     tag=v1.0                     : default is current date and time
                     maxFileJob=10                : default is 10 (5) for Standard (Systematics) Jobs
                     numFileJob=10                : default is 10 (5) for Standard (Systematics) Jobs
                     useCorrections=[True/False]  : default is False
                     useWeights=[True/False]      : default is False
                     isData=[True/False]          : default is False (run on MC)
                     isDebugStream=[True/False]   : default is False 
                     isSignal=[True/False]        : default is False (run on Bkg or Data)
		     mcType=mc15c                 : default is 'mc15c'
                     doSystematics=[True/False]   : default is False
                     isQcdCR=[True/False]         : default is False
                     noTauId=[True/False]         : default is False
                     failTauId=[True/False]       : default is False
```

## Jobs on simulation ##

   - jobs main analysis on backgrounds:
```
python SubmitJobs.py nickname=yournickname useCorrections=True useWeight=True
```

   - jobs main analysis on signals:
```
python SubmitJobs.py nickname=yournickname useCorrections=True useWeight=True isSignal=True
```

   - jobs main analysis with systematic trees creations:
```
python SubmitJobs.py nickname=yournickname useCorrections=True useWeight=True doSystematics=True
```

   - jobs without tau Identification requirement (usually done only on W+jets sample)
```
python SubmitJobs.py nickname=yournickname useCorrections=True useWeight=True noTauId=True
```

   - jobs with category FakeLep-RealLep for QCD estimation (done for etau/mutau channels)
```
python SubmitJobs.py nickname=yournickname useCorrections=True useWeight=True isQcdCR=True
```

   - jobs with category FakeLep-FakeLep for QCD estimation (done for etau/mutau channels)
```
python SubmitJobs.py nickname=yournickname useCorrections=True useWeight=True isQcdCR=True failTauId=True
```

## Jobs on data ##

   - jobs main analysis on data:
```
python SubmitJobs.py nickname=yournickname isData=True
```

   - jobs main analysis on data Debug Stream:
```
python SubmitJobs.py nickname=yournickname isData=True isDebugStream=True
```

   - jobs without tau Identification requirement (usually done only on W+jets sample)
```
python SubmitJobs.py nickname=yournickname isData=True noTauId=True
```

   - jobs with category FakeLep-RealLep for QCD estimation (done for etau/mutau channels)
```
python SubmitJobs.py nickname=yournickname isData=True isQcdCR=True
```

   - jobs with category FakeLep-FakeLep for QCD estimation (done for etau/mutau channels)
```
python SubmitJobs.py nickname=yournickname isData=True isQcdCR=True failTauId=True
```
