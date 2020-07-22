/* EventLoop includes */
#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <EventLoop/DirectDriver.h>
#include <EventLoopGrid/PrunDriver.h>
#include <EventLoop/OutputStream.h>                                                                                                                                                 
#include <EventLoopAlgs/NTupleSvc.h>

/* SampleHandler includes */
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "SampleHandler/DiskListLocal.h"
#include <SampleHandler/Global.h>
#include <SampleHandler/Sample.h>
#include <SampleHandler/ScanDir.h>

/* xAOD includes */
#include "xAODRootAccess/tools/Message.h"

/* ROOT includes */
#include <TSystem.h>

/* C++ includes */
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <ctime>

/* package includes */
#include <HighMassLFVSel/HighMassLFV.h>


class Options{
  
public:
  std::string submitDir          ;
  std::string sampleHandlingMode ;
  std::string localPath          ;
  std::string localSamplePattern ;
  int         maxEventNumber     ;
  std::string inputDS            ;
  bool        useGrid            ;
  std::string nickname           ;
  std::string tagVersion         ;
  std::string projectName        ;
  int         maxFileJob         ;
  std::string numFileJob         ;
  bool        mergeOutput        ;
  /* Analysis Class Options */
  bool useCorrections            ;
  bool useWeights                ;
  bool useData                   ;
  bool isDebugStream             ;
  std::string mcType             ;
  bool doSystematics             ;
  bool debug                     ;
  bool verbose                   ;
  bool isFastSim                 ;
  bool isQcdCR                   ;
  bool noTauId                   ;
  bool failTauId                 ;
  bool evalEgammaQuant           ;
  bool useBDTcut                 ;
  double BDTscore                ;
  bool printFlow                 ;
  bool printTrigList             ;
  bool printSystList             ;
  bool fixPuChannel              ;
  unsigned long long singleEvent ;
  
  std::string GetDateTime(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,80,"%d.%m.%Y_%I.%M.%S",timeinfo);
    std::string str(buffer);
    return str;
  }
  
  void SetDefault(){
    submitDir          = "submitDir"    ;
    sampleHandlingMode = "readFileList" ;
    localPath          = ""             ;
    localSamplePattern = "*.root*"      ;
    maxEventNumber     = -1             ;
    inputDS            = ""             ;
    useGrid            = false          ;
    nickname           = "salvucci"     ;
    tagVersion         = GetDateTime()  ;
    projectName        = "xAODrun"      ;
    maxFileJob         = 2              ;
    numFileJob         = "2"            ;
    mergeOutput        = false          ;
    useCorrections     = false          ;
    useWeights         = false          ;
    useData            = false          ;
    isDebugStream      = false          ;
    mcType             = "mc16a"        ;
    doSystematics      = false          ;
    debug              = false          ;
    verbose            = false          ;
    isFastSim          = false          ;
    isQcdCR            = false          ;
    noTauId            = false          ;
    failTauId          = false          ;
    evalEgammaQuant    = false          ;
    useBDTcut          = false          ;
    BDTscore           = 0.40           ;
    printFlow          = false          ;
    printTrigList      = false          ;
    printSystList      = false          ;
    fixPuChannel       = false          ;
    singleEvent        = 0              ;
  }

  bool checkOpt(char* opt, char* value){
    std::string val = value;
    if( 0==val.find("-") ){
      std::cout << "WARNING:: Option " << opt <<
	" requires value -> skipping " << std::endl;
      return false;
    }
    return true;
  }
  
};

int main( int argc, char* argv[] ) {

  assert(argc>1);

  Options opt;
  opt.SetDefault();
  bool printHelp = false;

  for(int i = 1; i < argc; ++i){
    if( !strcmp(argv[i],"--submitDir")                ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.submitDir          = argv[i+1]; }
    else if( !strcmp(argv[i],"--sampleHandlingMode" ) ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.sampleHandlingMode = argv[i+1]; }
    else if( !strcmp(argv[i],"--localPath" ) ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.localPath          = argv[i+1]; }
    else if( !strcmp(argv[i],"--localSamplePattern" ) ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.localSamplePattern = argv[i+1]; }
    else if( !strcmp(argv[i],"--maxEventNumber" )     ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.maxEventNumber     = std::stoi(argv[i+1]); }
    else if( !strcmp(argv[i],"--inputDS" )            ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.inputDS            = argv[i+1]; }
    else if( !strcmp(argv[i],"--useGrid")             ){ opt.useGrid            = true;      }
    else if( !strcmp(argv[i],"--nickname")            ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.nickname           = argv[i+1]; }
    else if( !strcmp(argv[i],"--tagVersion")          ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.tagVersion         = argv[i+1]; }
    else if( !strcmp(argv[i],"--projectName")         ){
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.projectName        = argv[i+1]; }
    else if( !strcmp(argv[i],"--maxFileJob")          ){
      if( opt.checkOpt(argv[i],argv[i+1]) ) {             
	opt.maxFileJob         = std::stoi(argv[i+1]);   opt.numFileJob = argv[i+1]; }       }
    else if( !strcmp(argv[i],"--mergeOutput")         ){ opt.mergeOutput        = true;      }
    else if( !strcmp(argv[i],"--useCorrections")      ){ opt.useCorrections     = true;      }
    else if( !strcmp(argv[i],"--useWeights")          ){ opt.useWeights         = true;      }
    else if( !strcmp(argv[i],"--useData")             ){ opt.useData            = true;      }
    else if( !strcmp(argv[i],"--fixPuChannel")        ){ opt.fixPuChannel       = true;      }
    else if( !strcmp(argv[i],"--isDebugStream")       ){ opt.isDebugStream      = true;      }
    else if( !strcmp(argv[i],"--mcType")              ){ 
      if( opt.checkOpt(argv[i],argv[i+1]) )              opt.mcType             = argv[i+1]; }
    else if( !strcmp(argv[i],"--doSystematics")       ){ opt.doSystematics      = true;      }
    else if( !strcmp(argv[i],"--debug")               ){ opt.debug              = true;      }
    else if( !strcmp(argv[i],"--verbose")             ){ opt.verbose            = true;      }
    else if( !strcmp(argv[i],"--isFastSim")           ){ opt.isFastSim          = true;      }
    else if( !strcmp(argv[i],"--isQcdCR")             ){ opt.isQcdCR            = true;      }
    else if( !strcmp(argv[i],"--noTauId")             ){ opt.noTauId            = true;      }
    else if( !strcmp(argv[i],"--failTauId")           ){ opt.failTauId          = true;      }
    else if( !strcmp(argv[i],"--evalEgammaQuant")     ){ opt.evalEgammaQuant    = true;      }
    else if( !strcmp(argv[i],"--useBDTcut")           ){ opt.useBDTcut          = true;      }
    else if( !strcmp(argv[i],"--BDTscore")            ){ opt.BDTscore           = std::stod(argv[i+1]); }
    else if( !strcmp(argv[i],"--printFlow")           ){ opt.printFlow          = true;      }
    else if( !strcmp(argv[i],"--printTrigList")       ){ opt.printTrigList      = true;      }
    else if( !strcmp(argv[i],"--printSystList")       ){ opt.printSystList      = true;      }
    else if( !strcmp(argv[i],"--singleEvent")         ){ opt.singleEvent        = std::stoull(argv[i+1]); }
    else if( !strcmp(argv[i],"--help")                ){ printHelp              = true;      }
  }
  if(printHelp){
    std::cout << "RunAnlysis: Run HighMass LFV analysis!!" << std::endl;
    std::cout << "  Usage  :  RunAnalysis [Options]"     << std::endl;
    std::cout << "              --submitDir          [Set Output Directory: default is 'submitDir']"                  << std::endl;
    std::cout << "              --sampleHandlingMode [Define samples handling mode: default is 'readFileList'"        << std::endl;
    std::cout << "                                    other options are: 'scanRucio', 'addGrid', 'ScanDir' ]"         << std::endl;
    std::cout << "              --localPath          [Set local path to sample/files: default is '' ]"                << std::endl;
    std::cout << "              --localSamplePattern [Set local sample pattern: default is '*.root'"                  << std::endl;
    std::cout << "                                    use all files found in local path]"                             << std::endl;
    std::cout << "              --maxEventNumber     [Set maximum number of events to process: default is -1 (all)]"  << std::endl;
    std::cout << "              --inputDS            [Set input dataset: default is '' "                              << std::endl;
    std::cout << "              --useGrid            [Enable Grid submission:  default is false (local submission)]"  << std::endl;
    std::cout << "              --nickname           [Define Grid nickname: default is 'salvucci']"                   << std::endl;
    std::cout << "              --tagVersion         [Define output dataset tag version: default is 'current date' ]" << std::endl;
    std::cout << "              --projectName        [Define outout dataset project name: defaul is 'xAODrun']"       << std::endl;
    std::cout << "              --maxFileJob         [Set maximum number of files per job: defaul is 2]"              << std::endl;
    std::cout << "              --mergeOutput        [Set merging output flag: default is false"                      << std::endl;
    std::cout << "              --useCorrections     [Enable leptons correction: default is false]"                   << std::endl;
    std::cout << "              --useWeights         [Enable events and leptons weights: default is false]"           << std::endl;
    std::cout << "              --useData            [Enable electron calibration for Data: default is false]"        << std::endl;
    std::cout << "              --isDebugStream      [Enable running on Data Debug Stream: default is false]"         << std::endl;
    std::cout << "              --fixPuChannel       [Set Default Channel for PileUp Reweighting: default is false]"  << std::endl;
    std::cout << "              --mcType             [Specify a MC version: default is 'mc16a']"                      << std::endl;
    std::cout << "              --doSystematics      [Enable shape Systematics evaluation: default is false]"         << std::endl;
    std::cout << "              --debug              [Enable debug mode: default is false]"                           << std::endl;
    std::cout << "              --verbose            [Enable verbose mode: default is false "                         << std::endl;
    std::cout << "                                    (if true also debug is enabled) ]"                              << std::endl;
    std::cout << "              --isFastSim          [Enable Fast Simulation flag: default is false]"                 << std::endl;
    std::cout << "              --isQcdCR            [Enable QCD Control Region selection flag: default is false]"    << std::endl;
    std::cout << "              --noTauId            [Enable Tau selection without Tau ID: default is false]"         << std::endl;
    std::cout << "              --failTauId          [Enable QCD Control Region with fail Tau ID: default is false]"  << std::endl;
    std::cout << "              --evalEgammaQuant    [Enable evaluating Egamma quantities: default is false]"         << std::endl;
    std::cout << "              --useBDTcut          [Enable TauBDTcut when noTauId is requested: default is false]"  << std::endl;
    std::cout << "              --BDTscore           [Set TauJetBDT score value: default is 0.40]"                    << std::endl;
    std::cout << "              --printFlow          [Enable Event/Objects Flows print: default is false]"            << std::endl;
    std::cout << "              --printTrigList      [Enable print available Trigger chains: default is false]"       << std::endl;
    std::cout << "              --printSystList      [Enable print recommended systematics: default is false]"        << std::endl;
    std::cout << "              --singleEvent        [Specify event number to run on: default is '0' (all events)]"   << std::endl;
    exit(0);
  }
  if( opt.tagVersion=="" && opt.useGrid ){
    std::cout<<" ERROR: Using Grid and output Dataset tag version (tagVersion) not set!"<<std::endl;
    exit(0);
  }
  if( opt.useGrid && (opt.sampleHandlingMode!="scanRucio" && opt.sampleHandlingMode!="addGrid") ){
    std::cout<<" ERROR: Using Grid and handling mode set for local run!"<<std::endl;
    exit(0);
  }
  if( !opt.useGrid && (opt.sampleHandlingMode=="scanRucio" || opt.sampleHandlingMode=="addGrid") ){
    std::cout<<" ERROR: Using local run and handling mode set for Grid run!"<<std::endl;
    exit(0);
  }
  if( opt.useGrid && opt.inputDS=="" ){
    std::cout<<" ERROR: Using Grid and input Dataset not defined!"<<std::endl;
    exit(0);
  }
  if( !opt.useGrid && opt.localPath=="" ){
    std::cout<<" ERROR: Using local run and local path not defined!"<<std::endl;
    exit(0);
  }

  if( opt.mcType!="mc16a" && opt.mcType!="mc16d" && opt.mcType!="mc16e"){
    std::cout<<" ERROR: Invalid mcType provided: "<<opt.mcType<<std::endl;
    exit(0);
  }

  if( opt.doSystematics ){
    opt.numFileJob = "2";
    opt.maxFileJob = 2;
  }

  if( opt.useBDTcut && !opt.noTauId ){
    std::cout << "WARNING: using TauBDTcut but noTauId is false: settinn TauBDTcut off" << std::endl;
    opt.useBDTcut=false;
  }

  if( opt.singleEvent!=0) opt.verbose = true;

  if( opt.verbose ) opt.debug=true;

  
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << " RunAnalysis configured with the following options: " << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << "submitDir              : " << opt.submitDir           << std::endl;
  std::cout << "sampleHandlingMode     : " << opt.sampleHandlingMode  << std::endl;
  std::cout << "localPath              : " << opt.localPath           << std::endl;
  std::cout << "localSamplePattern     : " << opt.localSamplePattern  << std::endl;
  std::cout << "maxEventNumber         : " << opt.maxEventNumber      << std::endl;
  std::cout << "inputDS                : " << opt.inputDS             << std::endl;
  std::cout << "useGrid                : " << opt.useGrid             << std::endl;
  std::cout << "nickname               : " << opt.nickname            << std::endl;
  std::cout << "tagVersion             : " << opt.tagVersion          << std::endl;
  std::cout << "projectName            : " << opt.projectName         << std::endl;
  std::cout << "maxFileJob             : " << opt.maxFileJob          << std::endl;
  std::cout << "numFileJob             : " << opt.numFileJob          << std::endl;
  std::cout << "mergeOutput            : " << opt.mergeOutput         << std::endl;
  std::cout << "useCorrections         : " << opt.useCorrections      << std::endl;
  std::cout << "useWeights             : " << opt.useWeights          << std::endl;
  std::cout << "useData                : " << opt.useData             << std::endl;
  std::cout << "isDebugStream          : " << opt.isDebugStream       << std::endl;
  std::cout << "fixPuChannel           : " << opt.fixPuChannel        << std::endl;
  std::cout << "mcType                 : " << opt.mcType              << std::endl;
  std::cout << "doSystematics          : " << opt.doSystematics       << std::endl;
  std::cout << "debug                  : " << opt.debug               << std::endl;
  std::cout << "verbose                : " << opt.verbose             << std::endl;
  std::cout << "isFastSim              : " << opt.isFastSim           << std::endl;
  std::cout << "isQcdCR                : " << opt.isQcdCR             << std::endl;
  std::cout << "noTauId                : " << opt.noTauId             << std::endl;
  std::cout << "failTauId              : " << opt.failTauId           << std::endl;
  std::cout << "evalEgammaQuant        : " << opt.evalEgammaQuant     << std::endl;
  std::cout << "useBDTcut              : " << opt.useBDTcut           << std::endl;
  std::cout << "BDTscore               : " << opt.BDTscore            << std::endl;
  std::cout << "printFlow              : " << opt.printFlow           << std::endl;
  std::cout << "printTrigList          : " << opt.printTrigList       << std::endl;
  std::cout << "printSystList          : " << opt.printSystList       << std::endl;
  std::cout << "singleEvent            : " << opt.singleEvent         << std::endl;
  
  /* Set up the job for xAOD access */
  xAOD::Init().ignore();
  
  /* Construct the samples to run on */
  SH::SampleHandler sh;

  /* Setting SampleHandler */
  if( opt.sampleHandlingMode=="scanRucio" ){
    SH::scanRucio(sh, opt.inputDS);//wild-card is available as we use in rucio ls
  }
  else if( opt.sampleHandlingMode=="addGrid" ){
    SH::addGrid(sh, opt.inputDS);//requiring exact inputDS
    sh.setMetaString( "nc_grid_filter", opt.localSamplePattern.c_str() );
  }
  else if( opt.sampleHandlingMode=="readFileList"){

    const char* localPathEx = gSystem->ExpandPathName( opt.localPath.c_str() );
    SH::DiskListLocal list (localPathEx);
    SH::ScanDir().sampleDepth(0).filePattern(opt.localSamplePattern).scan(sh,localPathEx);
    //SH::ScanDir (sh, list, opt.localSamplePattern.c_str());
    
    
  }
  else if( opt.sampleHandlingMode=="ScanDir" ){
    const char* localPathEx = gSystem->ExpandPathName( opt.localPath.c_str() );
    SH::ScanDir().sampleDepth(1).samplePattern(opt.localSamplePattern).scan(sh,localPathEx);
  }
  else{
    std::cout << "No matching sampleHandlingMode. exit." << std::endl;
    exit(0);
  }

  /* set input TTree name and print information */
  sh.setMetaString( "nc_tree", "CollectionTree" );
  sh.print();

  /* Create an EventLoop job */
  EL::Job job;
  job.sampleHandler( sh );

  /* Add HighMass LFV analysis algorithm to the job */
  HighMassLFV* alg = new HighMassLFV();
  job.algsAdd( alg );
  alg->m_UseCorr     = opt.useCorrections;
  alg->m_UseWgt      = opt.useWeights;
  alg->m_UseData     = opt.useData;
  alg->m_DbgStream   = opt.isDebugStream;
  alg->m_MCtype      = opt.mcType;
  alg->m_doSyst      = opt.doSystematics;
  alg->m_debug       = opt.debug;
  alg->m_verbose     = opt.verbose;
  alg->m_FastSim     = opt.isFastSim;
  alg->m_QcdCR       = opt.isQcdCR;
  alg->m_NoTauId     = opt.noTauId;
  alg->m_FailTauId   = opt.failTauId;
  alg->m_evalEgQuant = opt.evalEgammaQuant;
  alg->m_useBDTcut   = opt.useBDTcut;
  alg->m_TauBDTscore = opt.BDTscore;
  alg->m_PrintFlow   = opt.printFlow;
  alg->m_TrigList    = opt.printTrigList;
  alg->m_SystList    = opt.printSystList;
  alg->m_runEvent    = opt.singleEvent;
  alg->m_fixPuCh     = opt.fixPuChannel;
  
  /* Setting job options */
  job.options()->setDouble(EL::Job::optMaxEvents, opt.maxEventNumber);
  job.options()->setDouble(EL::Job::optRemoveSubmitDir, 1);
  job.options()->setDouble(EL::Job::optCacheSize, 10*1024*1024);
  job.options()->setDouble(EL::Job::optCacheLearnEntries, 20);
  //if(!jo.opt_isR20){ job.options()->setString(EL::Job::optXaodAccessMode, EL::Job::optXaodAccessMode_branch ); }
  
  /* Submitting the job using using local/direct driver */
  if(opt.useGrid){
    EL::PrunDriver driver;
    //const std::string outDSName = "user."+opt.nickname+"."+opt.projectName+".%in:name[2]%.%in:name[6]%."+opt.tagVersion;
    const std::string outDSName = "user."+opt.nickname+"."+opt.projectName+".%in:name[2]%_"+opt.tagVersion;
    driver.options()->setString("nc_outputSampleName", outDSName);
    driver.options()->setDouble(EL::Job::optGridMaxNFilesPerJob, opt.maxFileJob); 
    driver.options()->setString(EL::Job::optGridNFilesPerJob, opt.numFileJob);
    driver.options()->setDouble(EL::Job::optGridExpress,1);
    driver.options()->setDouble(EL::Job::optGridMergeOutput, opt.mergeOutput);
    driver.submitOnly( job, opt.submitDir );
  }
  else{
    EL::DirectDriver driver;
    driver.submit( job, opt.submitDir );
  }
  
  return 0;
  
}
