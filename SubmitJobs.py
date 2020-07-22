#!/usr/bin/python
import os
import sys
import subprocess
import getopt
import string
import argparse
import numpy as np
from Data import *
from Background import *
from Signal import *

parser = argparse.ArgumentParser()
parser.add_argument("--nickname"      , type=str           , default='salvucci', help="specify your nickname on the ATLAS grid: default is 'salvucci'"   )
parser.add_argument("--tagVersion"    , type=str           , default=''        , help="specify the Output dataset tag: default is '' (current date/time)")
parser.add_argument("--maxFileJob"    , type=int           , default=2         , help="specify the maximum # files to process per job: defaul is '2'"    )
parser.add_argument("--numFileJob"    , type=int           , default=2         , help="specify the # files to process per job: defaul is '2'"            )
parser.add_argument("--useCorrections", action='store_true', default=False     , help="enable corrections for events: default is 'False'"                )
parser.add_argument("--useWeights"    , action='store_true', default=False     , help="enable weights for events: default is 'False'"                    )
parser.add_argument("--process"       , type=str           , default='Top'     , help="specify the process to be processed: default 'Top'"               )
parser.add_argument("--isData"        , action='store_true', default=False     , help="specify if running on Data: default is 'False'"                   )
parser.add_argument("--isDbgStream"   , action='store_true', default=False     , help="specify if running on Data debug stream: default is 'False'"      )
parser.add_argument("--usePeriods"    , action='store_true', default=False     , help="enable using data periods datasets: default is 'False'"           )
parser.add_argument("--year"          , type=str           , default='2015'    , help="specify year of data to be processed: default is '2015'"          )
parser.add_argument("--isWjets"       , action='store_true', default=False     , help="enable running on W+jets samples only: default is 'False'"        )
parser.add_argument("--isTopSys"      , action='store_true', default=False     , help="enable running on ttbar sys samples only: default is 'False'"     )
parser.add_argument("--isSignal"      , action='store_true', default=False     , help="enable running on signal samples only: default is 'False'"        )
parser.add_argument("--isZprime"      , action='store_true', default=False     , help="specify Zprime as signal samples only: default is 'False'"        )
parser.add_argument("--isQBH"         , action='store_true', default=False     , help="specify QBH as signal samples only: default is 'False'"           )
parser.add_argument("--isSVT"         , action='store_true', default=False     , help="specify RPV SVT as signal samples only: default is 'False'"       )
parser.add_argument("--mcType"        , type=str           , default='mc16a'   , help="specify MC version to be processed: default is 'mc16a'"           )
parser.add_argument("--doSystematics" , action='store_true', default=False     , help="enable running over systematics: default is 'False'"              )
parser.add_argument("--isQcdCR"       , action='store_true', default=False     , help="enable QCD control region selection: default is 'False'"          )
parser.add_argument("--noTauId"       , action='store_true', default=False     , help="enable removing TauId requirement: default is 'False'"            )
parser.add_argument("--failTauId"     , action='store_true', default=False     , help="enable failure of TauId requirement: default is 'False'"          )
parser.add_argument("--useBDTcut"     , action='store_true', default=False     , help="enable using JetBDTScore for tau selection: default is 'False'"   )
parser.add_argument("--BDTscore"      , type=float         , default=0.40      , help="specify the JetBDTScore cut to be applied: default is '0.40'"     )
args = parser.parse_args()

def main():

    useData = False
    if args.process.find("data")==0:
        useData = True;
        print "Data flag set -> running on Monte Carlo samples!"
    else:
        print "Data flag not set -> running on Data samples!"
    print "nickname set to its default option 'salvucci'"

                
    if useData and args.doSystematics:
        print "Data and systematics flag set -> wrong configuration: "
        print "            turning off systematics ... "
        args.doSystematics=False
    if useData and args.useCorrections:
        print "Data and corrections flag set -> wrong configuration: "
        print "            turning off corrections ... "
        args.useCorrections=False
    if useData and args.useWeights:
        print "Data and weights flag set -> wrong configuration: "
        print "            turning off weights ... "
        args.useWeights=False
    #if not args.isData and args.isDbgStream:
    #    print "Debug Stream flag set and Data flag off -> wrong configuration: "
    #    print "            turning off Debug Stream"
    #    args.isDbgStream=False
        
    SubmitJobs(useData)


def SubmitJobs(useData):

    #Configuration:
    Nickname      = args.nickname
    Tag           = args.tagVersion
    MaxFileJob    = args.maxFileJob
    NumFileJob    = args.numFileJob
    Corrections   = args.useCorrections
    Weights       = args.useWeights
    UsePeriods    = args.usePeriods
    Year          = args.year
    IsDebugStream = args.isDbgStream
    IsSignal      = args.isSignal
    IsZprime      = args.isZprime
    IsQBH         = args.isQBH
    IsSVT         = args.isSVT
    IsWjets       = args.isWjets
    IsTopSys      = args.isTopSys
    Systematics   = args.doSystematics
    QcdCR         = args.isQcdCR
    NoTauId       = args.noTauId
    FailTauId     = args.failTauId
    UseBDTcut     = args.useBDTcut
    BDTscore      = args.BDTscore

    #Internal settings
    Samples    = None
    DirPrefix  = None
    NamePrefix = None

    Samples = GetSamples()
    print Samples
    print ""
    print DY
    print ""
    print BKG
    if useData:
        DirPrefix  = "data"+args.year.strip('20')+"_run"
        NamePrefix = "data"+args.year.strip('20')+"_run"
    else:
        DirPrefix  = args.mcType+"_dsid"
        NamePrefix = args.mcType+"_DSID"
        
    exit(0);
    
    """
    if IsData:
        DirPrefix  = "data"+Year.strip('20')+"_run"
        NamePrefix = "data"+Year.strip('20')+"_run"
        if IsDebugStream:
            if Year=="2015":
                Samples = Data15_Debug
            elif Year=="2016":
                Samples = Data16_Debug
            elif Year=="2017":
                Samples = Data17_Debug
            else:
                Samples = Data18_Debug
        else:
            if Year=="2015":
                if UsePeriods:
                    Samples = Data15_Periods
                else:
                    Samples = Data15
            elif Year=="2016":
                if UsePeriods:
                    Samples = Data16_Periods
                else:
                    Samples = Data16
            elif Year=="2017":
                if UsePeriods:
                    Samples = Data17_Periods
                else:
                    Samples = Data17
            else:
                if UsePeriods:
                    Samples = Data18_Periods
                else:
                    Samples = Data18
    else:
        DirPrefix  = "mc_dsid"
        NamePrefix = "MC_DSID"
        if IsZprime:
            if MCtype=="mc16a":
                Samples = Zprime_mc16a
            elif MCtype=="mc16d":
                Samples = Zprime_mc16d
            else:
                Samples = Zprime_mc16e
        elif IsQBH:
            if MCtype=="mc16a":
                Samples = QBH_mc16a
            elif MCtype=="mc16d":
                Samples = QBH_mc16d
            else:
                Samples = QBH_mc16e
        elif IsSVT:
            if MCtype=="mc16a":
                Samples = SVT_mc16a
            elif MCtype=="mc16d":
                Samples = SVT_mc16d
            else:
                Samples = SVT_mc16e
        elif IsWjets:
            if MCtype=="mc16a":
                Samples = Wjets_mc16a
            elif MCtype=="mc16d":
                Samples = Wjets_mc16d
            else:
                Samples = Wjets_mc16e
        elif IsTopSys:
            Samples = TopSys
        else:
            if MCtype=="mc16a":
                Samples = Bkg_mc16a
            elif MCtype=="mc16d":
                Samples = Bkg_mc16d
            else:
                Samples = Bkg_mc16e
    """
    
    for sample in Samples:

        SubDir    = ""
        ProjName  = ""
        inDS      = sample[0]
        DSID      = str(sample[0].split('.')[1])
        SubDir   += DirPrefix+DSID+"_"+Tag
        ProjName += NamePrefix+DSID
        cmd  = "RunAnalysis --sampleHandlingMode addGrid --useGrid"
        cmd += " --nickname "+Nickname
        cmd += " --projectName "+ProjName
        cmd += " --submitDir "+SubDir
        cmd += " --inputDS "+inDS
        cmd += " --mcType "+args.mcType
        if sample[1]:
            cmd += " --isFastSim"
        if sample[2]:
            cmd += " --fixPuChannel"
        if Corrections:
            cmd += " --useCorrections"
        if Weights:
            cmd += " --useWeights"
        if Systematics:
            cmd += " --doSystematics"
        if Tag!="":
            cmd += " --tagVersion "+Tag
        if useData:
            cmd += " --useData"
        if QcdCR:
            cmd += " --isQcdCR "
        if NoTauId:
            cmd += " --noTauId "
        if FailTauId:
            cmd += " --failTauId "
        if UseBDTcut:
            cmd += " --useBDTcut "
            cmd += " --BDTscore "+str(BDTscore)
        if IsDebugStream:
            cmd += " --localSamplePattern \"data*\" "
            cmd += " --isDebugStream"
        cmd += " --maxFileJob "+str(MaxFileJob)

        print "Sending HighMassLFV selection for MC/data sample with DSID "+DSID
        print cmd
        os.system(cmd)
        print "                              JOB SENT!!                "
        print ""
        os.system("rm -rf "+SubDir)


def GetSamples():

    print "Retrieving the list of samples ..."
    samples = [];
    
    process = args.process
    mcType  = args.mcType
    
    if process in Backgrounds:
        samples = GetBackgroundSamples(process,mcType);
    elif process in Signals:
        samples = GetSignalSamples(process,mcType)
    elif process.find("data")==0:
        samples = GetDataSamples(process)
    else:
        print "no valid process!! exiting ... "
        exit(0)

    return samples

def GetBackgroundSamples(process,mcType):

    print "in Background Samples "
    samples = [];
    
    if process == "DY":
        samples.extend(DY[mcType])
    elif process == "Top":
        samples = Top[mcType]
    elif process == "DiBoson":
        samples = DiBoson[mcType]
    elif process == "Wjets":
        samples = Wjets[mcType]
    elif process == "AllBkg":
        samples = DY[mcType]
        samples.extend(Top[mcType])
        samples.extend(DiBoson[mcType])
        samples.extend(Wjets[mcType])
    
    return samples

def GetSignalSamples(process,mcType):

    print "in Signal Samples "

    samples = [];
    
    if process == "Zprime":
        samples = Zprime[mcType]
    elif process == "QBH":
        samples = QBH[mcType]
    elif process == "RPV":
        samples = RPV[mcType]
    elif process == "AllSig":
        samples = Zprime[mcType]
        samples.extend(QBH[mcType])
        samples.extend(RPV[mcType])
    else:
        print "no valid signal process!!"
        exit(0)

    return samples

def GetDataSamples(process):

    samples = [];
    year = args.year;
    if process == "dataAll":
        for yr in Data:
            samples.extend(Data[yr])
    else:
        samples.extend(Data[year]);
        
    return samples

if __name__ == "__main__":
    main()
