# uBCC2P
code repository for the muon neutrino CC2Proton analysis at uB (MCC8) 

Scripts in this repository are for offline analyisis: 


analysisOnBeam: scripts for OnBeam data. Input root file: "/uboone/data/users/rcastill/CC2PFiles/data/OnBeam.root"
  #hanalysis_fOnBeam_PID.C (&.h), running using runhanalysis_PID_OnBeam.C: 
  already selected numu CC inclusive data events (from Marco's MCC8 PRL), applies selection cuts to get CC2Proton (number of tracks, proton containment, minimum number of hits per track, PID). Perform all the kinematical studies to observe NN-SRC (nucleon-nucleon short range correlation events), several plots (data-only are made). Few seconds running.
  #hanalysis_fOnBeam_SB.C (&.h), running using runhanalysis_SB_OnBeam.C:
    first stage to select a side-band for the CC2Proton to test the kinematical configuration versus those from CC2Proton NN-SRC. The main idea was to select numu CC1Pion, so, the PID cut for the proton candidates is switch wrt to CC2Protons. Stills needs to be more pure selection. All the kinematical reconstruction follows same approach as CC2Porotn SRC, to prove that the kinematical configuration of NN-SRc is not accidental and is unique wrt to other interactions (i.e. the sideband on pion production)
    
analysisMC: scripts for MC. 
Input root files (from the different scrits): 
"/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/PlotsPID/files/merged_output_Aug0\
92018_2135_v4/ubxsec_output_mc_bnbcosmic_merged.root" GENIE default (Tune1)
"/pnfs/uboone/persistent/users/rcastill/CC0Pion2P/MCC8_Tune1_CCNProton/resultMCtune3_3.root" GENIE alternative (Tune 3)

  #hanalysis_fMC_Tune1(3).C (&.h), running using runhanalysis_Tune1(3)_MCBNB.C: 
  Same as data analysis but includes truth information and splits per topology: already selected numu CC inclusive data events (from Marco's MCC8 PRL), applies selection cuts to get CC2Proton (number of tracks, proton containment, minimum number of hits per track, PID). Perform all the kinematical studies to observe NN-SRC (nucleon-nucleon short range correlation events), several plots (data-only are made). Few seconds running.
  #hanalysis_MC_Resolution.C (&.h), runhanalysis_Resolution_MCBNB.C (GENIE default):
    applies selection and perform several resolutions studies (appendix plots at the techncial note) on the reconstructed kinematics, includes the error calculation that is later inlcuded in final plots (DataMC directory). Some of the resolutions are studied under different approaches (as the neutrino energy reconstruction).
    
analysisOffBeam: scripts for OffBeam data. Input root file: "/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/PlotsPID/files/merged_output_Aug0\
92018_2135_v4/ubxsec_output_data_extbnb_merged.root"
  #hanalysis_fOffBeam_PID.C (&.h), running using runhanalysis_OffBeam.C: 
  already selected numu CC inclusive data events (from Marco's MCC8 PRL), applies selection cuts to get CC2Proton (number of tracks, proton containment, minimum number of hits per track, PID). Perform all the kinematical studies to observe NN-SRC (nucleon-nucleon short range correlation events). Only stored output as Tree to include background from cosmics in the data/MC, the contribution is minimal (<1%). Few seconds running.
  
  
DataMC: scripts for data/MC comparison plots (including OffBEam data as background). Input root file comes from running the previous running using runhanalysis_PID_OnBeam.C, running using runhanalysis_Tune1(3)_MCBNB, runhanalysis_OffBeam.C.

  #DataMC_PRL_data.C, run directly from ROOT (.X DataMC_PRL_data.C): 
  plots OnBeam data only and adds errors (stats+syst)
  
  #DataMC_PRL_Tune1(3).C, run directly from ROOT (.X DataMC_PRL_Tune1(3).C): 
  plots OnBeam data, MC and OffBeam together PoT normalized (different normalization Tune 1 vs Tune 3, because Tune 3 has larger statistics). All plots are per topology, interaction type or particle type. Includes function to calculate chi2 of the OnBeam data with respect MC+OffBeam (shape-only).
  
  #DataMC_PRL_ratio.C. Additional plots playing with ratios, but not too much. 
  
  
  Original repository to create the ROOT files (input to OnBeam/OffBeam/MC offline analysis): (within the uB gpvm, user/app/rcastill/cc1muNp_git_integration
  
