# The name of the package:
atlas_subdir (HighMassLFVSel)

set( extra_dep)
if( XAOD_STANDALONE )
  set( extra_dep Control/xAODRootAccess )
else()
  set( extra_dep GaudiKernel)
endif()

atlas_add_root_dictionary( HighMassLFVSelLib HighMassLFVSelLibDictSource
  ROOT_HEADERS HighMassLFVSel/HighMassLFV.h Root/LinkDef.h
  EXTERNAL_PACKAGES ROOT )


# Add the shared library:
atlas_add_library (HighMassLFVSelLib
  HighMassLFVSel/*.h Root/*.cxx ${HighMassLFVSelLibDictSource}
  LFVUtilsLib ../LFVUtils/LFVUtils/*.h ../LFVUtils/Root/*.cxx
  PUBLIC_HEADERS HighMassLFVSel
  LINK_LIBRARIES EventLoop EventLoopGrid EventLoopAlgs xAODRootAccess xAODEventInfo xAODTracking xAODMuon ElectronPhotonSelectorToolsLib xAODTau xAODCutFlow xAODMissingET GoodRunsListsLib PileupReweightingLib TrigConfxAODLib TrigDecisionToolLib TriggerMatchingToolLib MuonSelectorToolsLib MuonMomentumCorrectionsLib MuonEfficiencyCorrectionsLib ElectronPhotonFourMomentumCorrectionLib ElectronEfficiencyCorrectionLib TauAnalysisToolsLib IsolationSelectionLib IsolationCorrectionsLib JetMomentToolsLib JetSelectorToolsLib JetJvtEfficiencyLib JetCalibToolsLib JetResolutionLib JetUncertaintiesLib xAODBTaggingEfficiencyLib xAODPrimitives METUtilitiesLib AssociationUtilsLib PATInterfaces EgammaAnalysisHelpersLib LFVUtilsLib) #AnaAlgorithmLib

# Add the dictionary:
#atlas_add_dictionary (HighMassLFVSelDict
#  HighMassLFVSel/HighMassLFVDict.h
#  HighMassLFVSel/selection.xml
#  LINK_LIBRARIES HighMassLFVSelLib)


if (NOT XAOD_STANDALONE)
  # Add a component library for AthAnalysis only:
  atlas_add_component (HighMassLFVSel
    src/components/*.cxx
    LINK_LIBRARIES HighMassLFVSelLib)
endif ()

if ( XAOD_STANDALONE )
   atlas_add_executable( RunAnalysis
     util/RunAnalysis.cxx
     INCLUDE_DIRS ${ROOT_INCLUDE_DIRS}  
     LINK_LIBRARIES ${ROOT_LIBRARIES} EventLoop EventLoopGrid EventLoopAlgs xAODRootAccess xAODEventInfo xAODTracking xAODMuon ElectronPhotonSelectorToolsLib xAODTau xAODCutFlow xAODMissingET GoodRunsListsLib PileupReweightingLib TrigConfxAODLib TrigDecisionToolLib TriggerMatchingToolLib MuonSelectorToolsLib MuonMomentumCorrectionsLib MuonEfficiencyCorrectionsLib ElectronPhotonFourMomentumCorrectionLib ElectronEfficiencyCorrectionLib TauAnalysisToolsLib IsolationSelectionLib IsolationCorrectionsLib JetMomentToolsLib JetSelectorToolsLib JetJvtEfficiencyLib JetCalibToolsLib JetResolutionLib JetUncertaintiesLib xAODBTaggingEfficiencyLib xAODPrimitives METUtilitiesLib AssociationUtilsLib PATInterfaces EgammaAnalysisHelpersLib LFVUtilsLib HighMassLFVSelLib)
endif ()

# Install files from the package:
atlas_install_joboptions( share/*.py )

#install files from the package:
atlas_install_data( share/* )
