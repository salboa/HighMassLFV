#!/usr/bin/python
import os
import sys

Signals = ["Zprime", "QBH", "RPV", "AllSig"]

Zprime = { "mc16a": [],
           "mc16d": [],
           "mc16e": [] }

QBH    = { "mc16a": [],
           "mc16d": [],
           "mc16e": [] }

RPV    = { "mc16a": [],
           "mc16d": [],
           "mc16e": [] }

Zprime_mc16a = [ #Zprime mc16a samples
    
    ["mc15_13TeV.301954.Pythia8EvtGen_A14NNPDF23LO_Zprime0500emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301955.Pythia8EvtGen_A14NNPDF23LO_Zprime0600emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301956.Pythia8EvtGen_A14NNPDF23LO_Zprime0700emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301957.Pythia8EvtGen_A14NNPDF23LO_Zprime0800emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301958.Pythia8EvtGen_A14NNPDF23LO_Zprime0900emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301959.Pythia8EvtGen_A14NNPDF23LO_Zprime1000emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301960.Pythia8EvtGen_A14NNPDF23LO_Zprime1100emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301961.Pythia8EvtGen_A14NNPDF23LO_Zprime1200emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301962.Pythia8EvtGen_A14NNPDF23LO_Zprime1300emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301963.Pythia8EvtGen_A14NNPDF23LO_Zprime1400emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301964.Pythia8EvtGen_A14NNPDF23LO_Zprime1500emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301965.Pythia8EvtGen_A14NNPDF23LO_Zprime1600emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301966.Pythia8EvtGen_A14NNPDF23LO_Zprime1700emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301967.Pythia8EvtGen_A14NNPDF23LO_Zprime1800emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301968.Pythia8EvtGen_A14NNPDF23LO_Zprime1900emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301969.Pythia8EvtGen_A14NNPDF23LO_Zprime2000emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301970.Pythia8EvtGen_A14NNPDF23LO_Zprime2200emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301971.Pythia8EvtGen_A14NNPDF23LO_Zprime2400emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301972.Pythia8EvtGen_A14NNPDF23LO_Zprime2600emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301973.Pythia8EvtGen_A14NNPDF23LO_Zprime2800emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301974.Pythia8EvtGen_A14NNPDF23LO_Zprime3000emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301975.Pythia8EvtGen_A14NNPDF23LO_Zprime3500emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301976.Pythia8EvtGen_A14NNPDF23LO_Zprime4000emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301977.Pythia8EvtGen_A14NNPDF23LO_Zprime4500emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301978.Pythia8EvtGen_A14NNPDF23LO_Zprime5000emu.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301979.Pythia8EvtGen_A14NNPDF23LO_Zprime0500etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301980.Pythia8EvtGen_A14NNPDF23LO_Zprime0600etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301981.Pythia8EvtGen_A14NNPDF23LO_Zprime0700etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301982.Pythia8EvtGen_A14NNPDF23LO_Zprime0800etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301983.Pythia8EvtGen_A14NNPDF23LO_Zprime0900etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301984.Pythia8EvtGen_A14NNPDF23LO_Zprime1000etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301985.Pythia8EvtGen_A14NNPDF23LO_Zprime1100etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301986.Pythia8EvtGen_A14NNPDF23LO_Zprime1200etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301987.Pythia8EvtGen_A14NNPDF23LO_Zprime1300etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301988.Pythia8EvtGen_A14NNPDF23LO_Zprime1400etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301989.Pythia8EvtGen_A14NNPDF23LO_Zprime1500etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301990.Pythia8EvtGen_A14NNPDF23LO_Zprime1600etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301991.Pythia8EvtGen_A14NNPDF23LO_Zprime1700etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301992.Pythia8EvtGen_A14NNPDF23LO_Zprime1800etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301993.Pythia8EvtGen_A14NNPDF23LO_Zprime1900etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301994.Pythia8EvtGen_A14NNPDF23LO_Zprime2000etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301995.Pythia8EvtGen_A14NNPDF23LO_Zprime2200etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301996.Pythia8EvtGen_A14NNPDF23LO_Zprime2400etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301997.Pythia8EvtGen_A14NNPDF23LO_Zprime2600etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301998.Pythia8EvtGen_A14NNPDF23LO_Zprime2800etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.301999.Pythia8EvtGen_A14NNPDF23LO_Zprime3000etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302000.Pythia8EvtGen_A14NNPDF23LO_Zprime3500etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302001.Pythia8EvtGen_A14NNPDF23LO_Zprime4000etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302002.Pythia8EvtGen_A14NNPDF23LO_Zprime4500etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302003.Pythia8EvtGen_A14NNPDF23LO_Zprime5000etau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302004.Pythia8EvtGen_A14NNPDF23LO_Zprime0500mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302005.Pythia8EvtGen_A14NNPDF23LO_Zprime0600mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302006.Pythia8EvtGen_A14NNPDF23LO_Zprime0700mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302007.Pythia8EvtGen_A14NNPDF23LO_Zprime0800mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302008.Pythia8EvtGen_A14NNPDF23LO_Zprime0900mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302009.Pythia8EvtGen_A14NNPDF23LO_Zprime1000mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302010.Pythia8EvtGen_A14NNPDF23LO_Zprime1100mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302011.Pythia8EvtGen_A14NNPDF23LO_Zprime1200mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302012.Pythia8EvtGen_A14NNPDF23LO_Zprime1300mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302013.Pythia8EvtGen_A14NNPDF23LO_Zprime1400mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302014.Pythia8EvtGen_A14NNPDF23LO_Zprime1500mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302015.Pythia8EvtGen_A14NNPDF23LO_Zprime1600mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302016.Pythia8EvtGen_A14NNPDF23LO_Zprime1700mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302017.Pythia8EvtGen_A14NNPDF23LO_Zprime1800mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302018.Pythia8EvtGen_A14NNPDF23LO_Zprime1900mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302019.Pythia8EvtGen_A14NNPDF23LO_Zprime2000mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302020.Pythia8EvtGen_A14NNPDF23LO_Zprime2200mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302021.Pythia8EvtGen_A14NNPDF23LO_Zprime2400mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302022.Pythia8EvtGen_A14NNPDF23LO_Zprime2600mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302023.Pythia8EvtGen_A14NNPDF23LO_Zprime2800mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302024.Pythia8EvtGen_A14NNPDF23LO_Zprime3000mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302025.Pythia8EvtGen_A14NNPDF23LO_Zprime3500mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302026.Pythia8EvtGen_A14NNPDF23LO_Zprime4000mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302027.Pythia8EvtGen_A14NNPDF23LO_Zprime4500mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.302028.Pythia8EvtGen_A14NNPDF23LO_Zprime5000mutau.merge.DAOD_HIGG4D2.e3922_a766_a821_r7676_p2949/", True, False]

    ]

Zprime_mc16d = [ #Zprime mc16d samples

]

Zprime_mc16e = [ #Zprime mc16e samples

]

QBH_mc16a = [ #QBH mc16a samples
    
    ["mc15_13TeV.303610.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth01000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303611.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth01500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303612.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth02000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303613.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth02500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303614.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth03000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303615.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth03500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303616.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth04000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303617.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth04500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303618.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth05000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303619.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth05500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303620.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n1_Mth06000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303577.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth03000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303578.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth03500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303579.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth04000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303580.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth04500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303581.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth05000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303582.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth05500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303583.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth06000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303584.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth06500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303585.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth07000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303586.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth07500.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303587.QBHPythia8EvtGen_A14CTEQ6L1_QBH_emu_n6_Mth08000.merge.DAOD_HIGG4D2.e4327_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.303621.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth01000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303622.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth01500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303623.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth02000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303624.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth02500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303625.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth03000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303626.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth03500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303627.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth04000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303628.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth04500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303629.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth05000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303630.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth05500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303631.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n1_Mth06000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303588.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth03000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303589.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth03500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303590.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth04000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303591.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth04500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303592.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth05000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303593.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth05500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303594.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth06000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303595.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth06500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303596.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth07000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303597.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth07500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303598.QBHPythia8EvtGen_A14CTEQ6L1_QBH_etau_n6_Mth08000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303632.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth01000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303633.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth01500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303634.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth02000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303635.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth02500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303636.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth03000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303637.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth03500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303638.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth04000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303639.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth04500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303640.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth05000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303641.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth05500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303642.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n1_Mth06000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303599.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth03000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303600.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth03500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303601.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth04000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303602.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth04500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303603.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth05000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303604.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth05500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303605.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth06000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303606.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth06500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303607.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth07000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303608.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth07500.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False],
    ["mc15_13TeV.303609.QBHPythia8EvtGen_A14CTEQ6L1_QBH_mutau_n6_Mth08000.merge.DAOD_HIGG4D2.e4327_s2726_r7772_r7676_p2949/", False, False]

    ]

QBH_mc16d = [ #QBH mc16d samples

]

QBH_mc16e = [ #QBH mc16e samples

]

SVT_mc16a = [ #RPV SVT mc16a samples

    ["mc15_13TeV.402970.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402971.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402972.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m700.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402973.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402974.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m900.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402975.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402976.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1100.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402977.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1200.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402978.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1300.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402979.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1400.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402980.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402981.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402982.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1700.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402983.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402984.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m1900.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402985.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m2000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402986.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m2200.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402987.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m2400.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402988.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m2600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402989.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m2800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402990.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m3000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402991.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m3500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402992.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m4000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402993.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m4500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402994.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_emu_m5000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402995.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402996.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402997.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m700.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402998.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.402999.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m900.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403000.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403001.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1100.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403002.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1200.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403003.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1300.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403004.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1400.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403005.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403006.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403007.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1700.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403008.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403009.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m1900.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403010.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m2000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403011.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m2200.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403012.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m2400.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403013.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m2600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403014.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m2800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403015.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m3000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403016.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m3500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403017.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m4000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403018.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m4500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403019.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_etau_tauhad_m5000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403020.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403021.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403022.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m700.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403023.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403024.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m900.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403025.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403026.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1100.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403027.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1200.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403028.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1300.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403029.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1400.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403030.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403031.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403032.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1700.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403033.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403034.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m1900.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403035.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m2000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403036.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m2200.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403037.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m2400.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403038.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m2600.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403039.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m2800.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403040.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m3000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403041.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m3500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403042.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m4000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403043.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m4500.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False],
    ["mc15_13TeV.403044.MadGraphPythia8EvtGen_A14NNPDF23LO_SVT_mutau_tauhad_m5000.merge.DAOD_HIGG4D2.e5466_a766_a821_r7676_p2949/", True, False]
        
    ]

SVT_mc16d = [ #RPV SVT mc16d samples

]

SVT_mc16e = [ #RPV SVT mc16e samples

]
