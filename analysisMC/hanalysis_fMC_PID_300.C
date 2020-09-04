#define hanalysis_fMC_PID_300_cxx
// The class definition in hanalysis_fMC_PID_300.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("hanalysis_fMC_PID_300.C")
// root> T->Process("hanalysis_fMC_PID_300.C","some options")
// root> T->Process("hanalysis_fMC_PID_300.C+")
//


#include "hanalysis_fMC_PID_300.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TMath.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfileMC_PID_300;
TFile *fanalysis_PID_300;

/// muon candidate properties
TH1D *selmuon_lenght_CC0Pion0Proton_PID_300;
TH1D *selmuon_lenght_CC0Pion1Proton_PID_300;
TH1D *selmuon_lenght_CC0Pion2Proton_PID_300;
TH1D *selmuon_lenght_CC0PionNProton_PID_300;
TH1D *selmuon_lenght_CC1PionNProton_PID_300;
TH1D *selmuon_lenght_CCNPionNProton_PID_300;
TH1D *selmuon_lenght_CCNue_PID_300;
TH1D *selmuon_lenght_NC_PID_300;
TH1D *selmuon_lenght_OOFV_PID_300;
TH1D *selmuon_lenght_EXT_PID_300;
TH1D *selmuon_lenght_other_PID_300;

TH1D *selmuon_mom_CC0Pion0Proton_PID_300;
TH1D *selmuon_mom_CC0Pion1Proton_PID_300;
TH1D *selmuon_mom_CC0Pion2Proton_PID_300;
TH1D *selmuon_mom_CC0PionNProton_PID_300;
TH1D *selmuon_mom_CC1PionNProton_PID_300;
TH1D *selmuon_mom_CCNPionNProton_PID_300;
TH1D *selmuon_mom_CCNue_PID_300;
TH1D *selmuon_mom_NC_PID_300;
TH1D *selmuon_mom_OOFV_PID_300;
TH1D *selmuon_mom_EXT_PID_300;
TH1D *selmuon_mom_other_PID_300;

TH1D *selmuon_contained_mom_CC0Pion0Proton_PID_300;
TH1D *selmuon_contained_mom_CC0Pion1Proton_PID_300;
TH1D *selmuon_contained_mom_CC0Pion2Proton_PID_300;
TH1D *selmuon_contained_mom_CC0PionNProton_PID_300;
TH1D *selmuon_contained_mom_CC1PionNProton_PID_300;
TH1D *selmuon_contained_mom_CCNPionNProton_PID_300;
TH1D *selmuon_contained_mom_CCNue_PID_300;
TH1D *selmuon_contained_mom_NC_PID_300;
TH1D *selmuon_contained_mom_OOFV_PID_300;
TH1D *selmuon_contained_mom_EXT_PID_300;
TH1D *selmuon_contained_mom_other_PID_300;

TH1D *selmuon_uncontained_mom_CC0Pion0Proton_PID_300;
TH1D *selmuon_uncontained_mom_CC0Pion1Proton_PID_300;
TH1D *selmuon_uncontained_mom_CC0Pion2Proton_PID_300;
TH1D *selmuon_uncontained_mom_CC0PionNProton_PID_300;
TH1D *selmuon_uncontained_mom_CC1PionNProton_PID_300;
TH1D *selmuon_uncontained_mom_CCNPionNProton_PID_300;
TH1D *selmuon_uncontained_mom_CCNue_PID_300;
TH1D *selmuon_uncontained_mom_NC_PID_300;
TH1D *selmuon_uncontained_mom_OOFV_PID_300;
TH1D *selmuon_uncontained_mom_EXT_PID_300;
TH1D *selmuon_uncontained_mom_other_PID_300;

TH1D *selmuon_costheta_CC0Pion0Proton_PID_300;
TH1D *selmuon_costheta_CC0Pion1Proton_PID_300;
TH1D *selmuon_costheta_CC0Pion2Proton_PID_300;
TH1D *selmuon_costheta_CC0PionNProton_PID_300;
TH1D *selmuon_costheta_CC1PionNProton_PID_300;
TH1D *selmuon_costheta_CCNPionNProton_PID_300;
TH1D *selmuon_costheta_CCNue_PID_300;
TH1D *selmuon_costheta_NC_PID_300;
TH1D *selmuon_costheta_OOFV_PID_300;
TH1D *selmuon_costheta_EXT_PID_300;
TH1D *selmuon_costheta_other_PID_300;

TH1D *selmuon_phi_CC0Pion0Proton_PID_300;
TH1D *selmuon_phi_CC0Pion1Proton_PID_300;
TH1D *selmuon_phi_CC0Pion2Proton_PID_300;
TH1D *selmuon_phi_CC0PionNProton_PID_300;
TH1D *selmuon_phi_CC1PionNProton_PID_300;
TH1D *selmuon_phi_CCNPionNProton_PID_300;
TH1D *selmuon_phi_CCNue_PID_300;
TH1D *selmuon_phi_NC_PID_300;
TH1D *selmuon_phi_OOFV_PID_300;
TH1D *selmuon_phi_EXT_PID_300;
TH1D *selmuon_phi_other_PID_300;

TH1D *selmuon_lenght_muon_PID_300;
TH1D *selmuon_lenght_proton_PID_300;
TH1D *selmuon_lenght_pion_PID_300;
TH1D *selmuon_lenght_electron_PID_300;
TH1D *selmuon_lenght_pother_PID_300;

TH1D *selmuon_mom_muon_PID_300;
TH1D *selmuon_mom_proton_PID_300;
TH1D *selmuon_mom_pion_PID_300;
TH1D *selmuon_mom_electron_PID_300;
TH1D *selmuon_mom_pother_PID_300;

TH1D *selmuon_contained_mom_muon_PID_300;
TH1D *selmuon_contained_mom_proton_PID_300;
TH1D *selmuon_contained_mom_pion_PID_300;
TH1D *selmuon_contained_mom_electron_PID_300;
TH1D *selmuon_contained_mom_pother_PID_300;

TH1D *selmuon_uncontained_mom_muon_PID_300;
TH1D *selmuon_uncontained_mom_proton_PID_300;
TH1D *selmuon_uncontained_mom_pion_PID_300;
TH1D *selmuon_uncontained_mom_electron_PID_300;
TH1D *selmuon_uncontained_mom_pother_PID_300;

TH1D *selmuon_costheta_muon_PID_300;
TH1D *selmuon_costheta_proton_PID_300;
TH1D *selmuon_costheta_pion_PID_300;
TH1D *selmuon_costheta_electron_PID_300;
TH1D *selmuon_costheta_pother_PID_300;

TH1D *selmuon_phi_muon_PID_300;
TH1D *selmuon_phi_proton_PID_300;
TH1D *selmuon_phi_pion_PID_300;
TH1D *selmuon_phi_electron_PID_300;
TH1D *selmuon_phi_pother_PID_300;

TH1D *selmuon_chi2proton_muon_PID_300;
TH1D *selmuon_chi2proton_proton_PID_300;
TH1D *selmuon_chi2proton_pion_PID_300;
TH1D *selmuon_chi2proton_electron_PID_300;
TH1D *selmuon_chi2proton_pother_PID_300;

TH1D *selmuon_chi2proton_cont_muon_PID_300;
TH1D *selmuon_chi2proton_cont_proton_PID_300;
TH1D *selmuon_chi2proton_cont_pion_PID_300;
TH1D *selmuon_chi2proton_cont_electron_PID_300;
TH1D *selmuon_chi2proton_cont_pother_PID_300;

TH2D *selmuon_dEdx_vs_resrange_muon_PID_300;
TH2D *selmuon_dEdx_vs_resrange_proton_PID_300;
TH2D *selmuon_dEdx_vs_resrange_pion_PID_300;

TH1D *selmuon_chi2proton_uncont_muon_PID_300;
TH1D *selmuon_chi2proton_uncont_proton_PID_300;
TH1D *selmuon_chi2proton_uncont_pion_PID_300;
TH1D *selmuon_chi2proton_uncont_electron_PID_300;
TH1D *selmuon_chi2proton_uncont_pother_PID_300;

///proton properties

TH1D *selproton1_lenght_CC0Pion0Proton_PID_300;
TH1D *selproton1_lenght_CC0Pion1Proton_PID_300;
TH1D *selproton1_lenght_CC0Pion2Proton_PID_300;
TH1D *selproton1_lenght_CC0PionNProton_PID_300;
TH1D *selproton1_lenght_CC1PionNProton_PID_300;
TH1D *selproton1_lenght_CCNPionNProton_PID_300;
TH1D *selproton1_lenght_CCNue_PID_300;
TH1D *selproton1_lenght_NC_PID_300;
TH1D *selproton1_lenght_OOFV_PID_300;
TH1D *selproton1_lenght_EXT_PID_300;
TH1D *selproton1_lenght_other_PID_300;

TH1D *selproton1_costheta_CC0Pion0Proton_PID_300;
TH1D *selproton1_costheta_CC0Pion1Proton_PID_300;
TH1D *selproton1_costheta_CC0Pion2Proton_PID_300;
TH1D *selproton1_costheta_CC0PionNProton_PID_300;
TH1D *selproton1_costheta_CC1PionNProton_PID_300;
TH1D *selproton1_costheta_CCNPionNProton_PID_300;
TH1D *selproton1_costheta_CCNue_PID_300;
TH1D *selproton1_costheta_NC_PID_300;
TH1D *selproton1_costheta_OOFV_PID_300;
TH1D *selproton1_costheta_EXT_PID_300;
TH1D *selproton1_costheta_other_PID_300;

TH1D *selproton1_phi_CC0Pion0Proton_PID_300;
TH1D *selproton1_phi_CC0Pion1Proton_PID_300;
TH1D *selproton1_phi_CC0Pion2Proton_PID_300;
TH1D *selproton1_phi_CC0PionNProton_PID_300;
TH1D *selproton1_phi_CC1PionNProton_PID_300;
TH1D *selproton1_phi_CCNPionNProton_PID_300;
TH1D *selproton1_phi_CCNue_PID_300;
TH1D *selproton1_phi_NC_PID_300;
TH1D *selproton1_phi_OOFV_PID_300;
TH1D *selproton1_phi_EXT_PID_300;
TH1D *selproton1_phi_other_PID_300;

TH1D *selproton1_mom_CC0Pion0Proton_PID_300;
TH1D *selproton1_mom_CC0Pion1Proton_PID_300;
TH1D *selproton1_mom_CC0Pion2Proton_PID_300;
TH1D *selproton1_mom_CC0PionNProton_PID_300;
TH1D *selproton1_mom_CC1PionNProton_PID_300;
TH1D *selproton1_mom_CCNPionNProton_PID_300;
TH1D *selproton1_mom_CCNue_PID_300;
TH1D *selproton1_mom_NC_PID_300;
TH1D *selproton1_mom_OOFV_PID_300;
TH1D *selproton1_mom_EXT_PID_300;
TH1D *selproton1_mom_other_PID_300;

TH1D *selproton1_lenght_muon_PID_300;
TH1D *selproton1_lenght_proton_PID_300;
TH1D *selproton1_lenght_pion_PID_300;
TH1D *selproton1_lenght_electron_PID_300;
TH1D *selproton1_lenght_pother_PID_300;

TH1D *selproton1_costheta_muon_PID_300;
TH1D *selproton1_costheta_proton_PID_300;
TH1D *selproton1_costheta_pion_PID_300;
TH1D *selproton1_costheta_electron_PID_300;
TH1D *selproton1_costheta_pother_PID_300;

TH1D *selproton1_phi_muon_PID_300;
TH1D *selproton1_phi_proton_PID_300;
TH1D *selproton1_phi_pion_PID_300;
TH1D *selproton1_phi_electron_PID_300;
TH1D *selproton1_phi_pother_PID_300;

TH1D *selproton1_chi2proton_muon_PID_300;
TH1D *selproton1_chi2proton_proton_PID_300;
TH1D *selproton1_chi2proton_pion_PID_300;
TH1D *selproton1_chi2proton_electron_PID_300;
TH1D *selproton1_chi2proton_pother_PID_300;

TH2D *selproton1_dEdx_vs_resrange_muon_PID_300;
TH2D *selproton1_dEdx_vs_resrange_proton_PID_300;
TH2D *selproton1_dEdx_vs_resrange_pion_PID_300;

/////////////////////////////////////////////

TH1D *selproton2_lenght_CC0Pion0Proton_PID_300;
TH1D *selproton2_lenght_CC0Pion1Proton_PID_300;
TH1D *selproton2_lenght_CC0Pion2Proton_PID_300;
TH1D *selproton2_lenght_CC0PionNProton_PID_300;
TH1D *selproton2_lenght_CC1PionNProton_PID_300;
TH1D *selproton2_lenght_CCNPionNProton_PID_300;
TH1D *selproton2_lenght_CCNue_PID_300;
TH1D *selproton2_lenght_NC_PID_300;
TH1D *selproton2_lenght_OOFV_PID_300;
TH1D *selproton2_lenght_EXT_PID_300;
TH1D *selproton2_lenght_other_PID_300;

TH1D *selproton2_costheta_CC0Pion0Proton_PID_300;
TH1D *selproton2_costheta_CC0Pion1Proton_PID_300;
TH1D *selproton2_costheta_CC0Pion2Proton_PID_300;
TH1D *selproton2_costheta_CC0PionNProton_PID_300;
TH1D *selproton2_costheta_CC1PionNProton_PID_300;
TH1D *selproton2_costheta_CCNPionNProton_PID_300;
TH1D *selproton2_costheta_CCNue_PID_300;
TH1D *selproton2_costheta_NC_PID_300;
TH1D *selproton2_costheta_OOFV_PID_300;
TH1D *selproton2_costheta_EXT_PID_300;
TH1D *selproton2_costheta_other_PID_300;

TH1D *selproton2_phi_CC0Pion0Proton_PID_300;
TH1D *selproton2_phi_CC0Pion1Proton_PID_300;
TH1D *selproton2_phi_CC0Pion2Proton_PID_300;
TH1D *selproton2_phi_CC0PionNProton_PID_300;
TH1D *selproton2_phi_CC1PionNProton_PID_300;
TH1D *selproton2_phi_CCNPionNProton_PID_300;
TH1D *selproton2_phi_CCNue_PID_300;
TH1D *selproton2_phi_NC_PID_300;
TH1D *selproton2_phi_OOFV_PID_300;
TH1D *selproton2_phi_EXT_PID_300;
TH1D *selproton2_phi_other_PID_300;

TH1D *selproton2_mom_CC0Pion0Proton_PID_300;
TH1D *selproton2_mom_CC0Pion1Proton_PID_300;
TH1D *selproton2_mom_CC0Pion2Proton_PID_300;
TH1D *selproton2_mom_CC0PionNProton_PID_300;
TH1D *selproton2_mom_CC1PionNProton_PID_300;
TH1D *selproton2_mom_CCNPionNProton_PID_300;
TH1D *selproton2_mom_CCNue_PID_300;
TH1D *selproton2_mom_NC_PID_300;
TH1D *selproton2_mom_OOFV_PID_300;
TH1D *selproton2_mom_EXT_PID_300;
TH1D *selproton2_mom_other_PID_300;

TH1D *selproton2_lenght_muon_PID_300;
TH1D *selproton2_lenght_proton_PID_300;
TH1D *selproton2_lenght_pion_PID_300;
TH1D *selproton2_lenght_electron_PID_300;
TH1D *selproton2_lenght_pother_PID_300;

TH1D *selproton2_costheta_muon_PID_300;
TH1D *selproton2_costheta_proton_PID_300;
TH1D *selproton2_costheta_pion_PID_300;
TH1D *selproton2_costheta_electron_PID_300;
TH1D *selproton2_costheta_pother_PID_300;

TH1D *selproton2_phi_muon_PID_300;
TH1D *selproton2_phi_proton_PID_300;
TH1D *selproton2_phi_pion_PID_300;
TH1D *selproton2_phi_electron_PID_300;
TH1D *selproton2_phi_pother_PID_300;

TH1D *selproton2_PID_300A_muon_PID_300;
TH1D *selproton2_PID_300A_proton_PID_300;
TH1D *selproton2_PID_300A_pion_PID_300;
TH1D *selproton2_PID_300A_electron_PID_300;
TH1D *selproton2_PID_300A_pother_PID_300;

TH1D *selproton2_chi2proton_muon_PID_300;
TH1D *selproton2_chi2proton_proton_PID_300;
TH1D *selproton2_chi2proton_pion_PID_300;
TH1D *selproton2_chi2proton_electron_PID_300;
TH1D *selproton2_chi2proton_pother_PID_300;

TH2D *selproton2_dEdx_vs_resrange_muon_PID_300;
TH2D *selproton2_dEdx_vs_resrange_proton_PID_300;
TH2D *selproton2_dEdx_vs_resrange_pion_PID_300;

TH1D *selproton_dEdx_PID_MC;

//// Opening angles
TH1D *angle_mup1_CC0Pion0Proton_PID_300;
TH1D *angle_mup1_CC0Pion1Proton_PID_300;
TH1D *angle_mup1_CC0Pion2Proton_PID_300;
TH1D *angle_mup1_CC0PionNProton_PID_300;
TH1D *angle_mup1_CC1PionNProton_PID_300;
TH1D *angle_mup1_CCNPionNProton_PID_300;
TH1D *angle_mup1_CCNue_PID_300;
TH1D *angle_mup1_NC_PID_300;
TH1D *angle_mup1_OOFV_PID_300;
TH1D *angle_mup1_EXT_PID_300;
TH1D *angle_mup1_other_PID_300;

TH1D *angle_mup2_CC0Pion0Proton_PID_300;
TH1D *angle_mup2_CC0Pion1Proton_PID_300;
TH1D *angle_mup2_CC0Pion2Proton_PID_300;
TH1D *angle_mup2_CC0PionNProton_PID_300;
TH1D *angle_mup2_CC1PionNProton_PID_300;
TH1D *angle_mup2_CCNPionNProton_PID_300;
TH1D *angle_mup2_CCNue_PID_300;
TH1D *angle_mup2_NC_PID_300;
TH1D *angle_mup2_OOFV_PID_300;
TH1D *angle_mup2_EXT_PID_300;
TH1D *angle_mup2_other_PID_300;

TH1D *angle_p1p2_CC0Pion0Proton_PID_300;
TH1D *angle_p1p2_CC0Pion1Proton_PID_300;
TH1D *angle_p1p2_CC0Pion2Proton_PID_300;
TH1D *angle_p1p2_CC0PionNProton_PID_300;
TH1D *angle_p1p2_CC1PionNProton_PID_300;
TH1D *angle_p1p2_CCNPionNProton_PID_300;
TH1D *angle_p1p2_CCNue_PID_300;
TH1D *angle_p1p2_NC_PID_300;
TH1D *angle_p1p2_OOFV_PID_300;
TH1D *angle_p1p2_EXT_PID_300;
TH1D *angle_p1p2_other_PID_300;

TH1D *cosangle_p1p2_CC0Pion0Proton_PID_300;
TH1D *cosangle_p1p2_CC0Pion1Proton_PID_300;
TH1D *cosangle_p1p2_CC0Pion2Proton_PID_300;
TH1D *cosangle_p1p2_CC0PionNProton_PID_300;
TH1D *cosangle_p1p2_CC1PionNProton_PID_300;
TH1D *cosangle_p1p2_CCNPionNProton_PID_300;
TH1D *cosangle_p1p2_CCNue_PID_300;
TH1D *cosangle_p1p2_NC_PID_300;
TH1D *cosangle_p1p2_OOFV_PID_300;
TH1D *cosangle_p1p2_EXT_PID_300;
TH1D *cosangle_p1p2_other_PID_300;

///// resolutions
TH2D *selmuon_mom_res_PID_300;
TH2D *selmuon_costheta_res_PID_300;
TH2D *selmuon_phi_res_PID_300;

TH2D *selproton1_mom_res_PID_300;
TH2D *selproton1_costheta_res_PID_300;
TH2D *selproton1_phi_res_PID_300;

TH2D *selproton2_mom_res_PID_300;
TH2D *selproton2_costheta_res_PID_300;
TH2D *selproton2_phi_res_PID_300;

////////////////////////////////////////////////////////////////////////////////////
//// ArgoNeuT studies on opening angles -- reconstructed variables by reaction type/// cut on 300 MeV proton momenta
////////////////////////////////////////////////////////////////////////////////////


/// reconstructed neutrino energy

TH1D *reco_Enu_CCQE_PID_300;
TH1D *reco_Enu_CCRes_PID_300;
TH1D *reco_Enu_CCCoh_PID_300;
TH1D *reco_Enu_CCDIS_PID_300;
TH1D *reco_Enu_CCMEC_PID_300;
TH1D *reco_Enu_CCNue_PID_300;
TH1D *reco_Enu_NC_PID_300;
TH1D *reco_Enu_other_PID_300;

/// reconstructed neutrino energy

TH1D *reco_PT_CCQE_PID_300;
TH1D *reco_PT_CCRes_PID_300;
TH1D *reco_PT_CCCoh_PID_300;
TH1D *reco_PT_CCDIS_PID_300;
TH1D *reco_PT_CCMEC_PID_300;
TH1D *reco_PT_CCNue_PID_300;
TH1D *reco_PT_NC_PID_300;
TH1D *reco_PT_other_PID_300;

TH1D *reco_PT_CCQE_1binCM_PID_300;
TH1D *reco_PT_CCRes_1binCM_PID_300;
TH1D *reco_PT_CCCoh_1binCM_PID_300;
TH1D *reco_PT_CCDIS_1binCM_PID_300;
TH1D *reco_PT_CCMEC_1binCM_PID_300;
TH1D *reco_PT_CCNue_1binCM_PID_300;
TH1D *reco_PT_NC_1binCM_PID_300;
TH1D *reco_PT_other_1binCM_PID_300;

//// p1+p2
TH1D *reco_p1p2_CCQE_PID_300;
TH1D *reco_p1p2_CCRes_PID_300;
TH1D *reco_p1p2_CCCoh_PID_300;
TH1D *reco_p1p2_CCDIS_PID_300;
TH1D *reco_p1p2_CCMEC_PID_300;
TH1D *reco_p1p2_CCNue_PID_300;
TH1D *reco_p1p2_NC_PID_300;
TH1D *reco_p1p2_other_PID_300;

//// p1-p2
TH1D *reco_dp1p2_CCQE_PID_300;
TH1D *reco_dp1p2_CCRes_PID_300;
TH1D *reco_dp1p2_CCCoh_PID_300;
TH1D *reco_dp1p2_CCDIS_PID_300;
TH1D *reco_dp1p2_CCMEC_PID_300;
TH1D *reco_dp1p2_CCNue_PID_300;
TH1D *reco_dp1p2_NC_PID_300;
TH1D *reco_dp1p2_other_PID_300;

//// KE p1+p2
TH1D *reco_kp1p2_CCQE_PID_300;
TH1D *reco_kp1p2_CCRes_PID_300;
TH1D *reco_kp1p2_CCCoh_PID_300;
TH1D *reco_kp1p2_CCDIS_PID_300;
TH1D *reco_kp1p2_CCMEC_PID_300;
TH1D *reco_kp1p2_CCNue_PID_300;
TH1D *reco_kp1p2_NC_PID_300;
TH1D *reco_kp1p2_other_PID_300;

//// KE p1+p2 btb
TH1D *reco_kp1p2_CCQE_PID_300_btb;
TH1D *reco_kp1p2_CCRes_PID_300_btb;
TH1D *reco_kp1p2_CCCoh_PID_300_btb;
TH1D *reco_kp1p2_CCDIS_PID_300_btb;
TH1D *reco_kp1p2_CCMEC_PID_300_btb;
TH1D *reco_kp1p2_CCNue_PID_300_btb;
TH1D *reco_kp1p2_NC_PID_300_btb;
TH1D *reco_kp1p2_other_PID_300_btb;

/// momenta struck nucleon

TH1D *reco_pn_CCQE_PID_300;
TH1D *reco_pn_CCRes_PID_300;
TH1D *reco_pn_CCCoh_PID_300;
TH1D *reco_pn_CCDIS_PID_300;
TH1D *reco_pn_CCMEC_PID_300;
TH1D *reco_pn_CCNue_PID_300;
TH1D *reco_pn_NC_PID_300;
TH1D *reco_pn_other_PID_300;

/// reconstructed neutrino energymomenta p1 vs p2

TH2D *p1p2_PID_300;
TH2D *reco_angle_p1p2_p2_PID_300_LF;
TH2D *reco_angle_p1p2_PID_300_LF_CM;

/// opening angle lab frame

TH1D *reco_angle_p1p2_CCQE_PID_300_LF;
TH1D *reco_angle_p1p2_CCRes_PID_300_LF;
TH1D *reco_angle_p1p2_CCCoh_PID_300_LF;
TH1D *reco_angle_p1p2_CCDIS_PID_300_LF;
TH1D *reco_angle_p1p2_CCMEC_PID_300_LF;
TH1D *reco_angle_p1p2_CCNue_PID_300_LF;
TH1D *reco_angle_p1p2_NC_PID_300_LF;
TH1D *reco_angle_p1p2_other_PID_300_LF;

TH1D *reco_angle_p1p2_CCQE_PID_300_LF_zoom;
TH1D *reco_angle_p1p2_CCRes_PID_300_LF_zoom;
TH1D *reco_angle_p1p2_CCCoh_PID_300_LF_zoom;
TH1D *reco_angle_p1p2_CCDIS_PID_300_LF_zoom;
TH1D *reco_angle_p1p2_CCMEC_PID_300_LF_zoom;
TH1D *reco_angle_p1p2_CCNue_PID_300_LF_zoom;
TH1D *reco_angle_p1p2_NC_PID_300_LF_zoom;
TH1D *reco_angle_p1p2_other_PID_300_LF_zoom;

//// Opening angles in CM/// pn= p_p1 -q_3 (vector), q from Evis and muon kinematics--opeing angle between nucleon reco and recoil proton in the np initial pair, p>300
TH1D *reco_angle_p1p2_CCQE_PID_300_CM;
TH1D *reco_angle_p1p2_CCRes_PID_300_CM;
TH1D *reco_angle_p1p2_CCCoh_PID_300_CM;
TH1D *reco_angle_p1p2_CCDIS_PID_300_CM;
TH1D *reco_angle_p1p2_CCMEC_PID_300_CM;
TH1D *reco_angle_p1p2_CCNue_PID_300_CM;
TH1D *reco_angle_p1p2_NC_PID_300_CM;
TH1D *reco_angle_p1p2_other_PID_300_CM;

TH1D *reco_angle_p1p2_CCQE_PID_300_CM_zoom;
TH1D *reco_angle_p1p2_CCRes_PID_300_CM_zoom;
TH1D *reco_angle_p1p2_CCCoh_PID_300_CM_zoom;
TH1D *reco_angle_p1p2_CCDIS_PID_300_CM_zoom;
TH1D *reco_angle_p1p2_CCMEC_PID_300_CM_zoom;
TH1D *reco_angle_p1p2_CCNue_PID_300_CM_zoom;
TH1D *reco_angle_p1p2_NC_PID_300_CM_zoom;
TH1D *reco_angle_p1p2_other_PID_300_CM_zoom;

//////
/// final angular plots with all requirements on LF and CM
TH2D *reco_angle_p1p2_p2_PID_300_LF_btb;

TH1D *reco_angle_p1p2_CCQE_PID_300_LF_btb;
TH1D *reco_angle_p1p2_CCRes_PID_300_LF_btb;
TH1D *reco_angle_p1p2_CCCoh_PID_300_LF_btb;
TH1D *reco_angle_p1p2_CCDIS_PID_300_LF_btb;
TH1D *reco_angle_p1p2_CCMEC_PID_300_LF_btb;
TH1D *reco_angle_p1p2_CCNue_PID_300_LF_btb;
TH1D *reco_angle_p1p2_NC_PID_300_LF_btb;
TH1D *reco_angle_p1p2_other_PID_300_LF_btb;

TH1D *reco_angle_p1p2_CCQE_PID_300_CM_btb;
TH1D *reco_angle_p1p2_CCRes_PID_300_CM_btb;
TH1D *reco_angle_p1p2_CCCoh_PID_300_CM_btb;
TH1D *reco_angle_p1p2_CCDIS_PID_300_CM_btb;
TH1D *reco_angle_p1p2_CCMEC_PID_300_CM_btb;
TH1D *reco_angle_p1p2_CCNue_PID_300_CM_btb;
TH1D *reco_angle_p1p2_NC_PID_300_CM_btb;
TH1D *reco_angle_p1p2_other_PID_300_CM_btb;

TH1D *reco_angle_p1p2_CCQE_PID_300_LF_btb_zoom;
TH1D *reco_angle_p1p2_CCRes_PID_300_LF_btb_zoom;
TH1D *reco_angle_p1p2_CCCoh_PID_300_LF_btb_zoom;
TH1D *reco_angle_p1p2_CCDIS_PID_300_LF_btb_zoom;
TH1D *reco_angle_p1p2_CCMEC_PID_300_LF_btb_zoom;
TH1D *reco_angle_p1p2_CCNue_PID_300_LF_btb_zoom;
TH1D *reco_angle_p1p2_NC_PID_300_LF_btb_zoom;
TH1D *reco_angle_p1p2_other_PID_300_LF_btb_zoom;

TH1D *reco_angle_p1p2_CCQE_PID_300_CM_btb_zoom;
TH1D *reco_angle_p1p2_CCRes_PID_300_CM_btb_zoom;
TH1D *reco_angle_p1p2_CCCoh_PID_300_CM_btb_zoom;
TH1D *reco_angle_p1p2_CCDIS_PID_300_CM_btb_zoom;
TH1D *reco_angle_p1p2_CCMEC_PID_300_CM_btb_zoom;
TH1D *reco_angle_p1p2_CCNue_PID_300_CM_btb_zoom;
TH1D *reco_angle_p1p2_NC_PID_300_CM_btb_zoom;
TH1D *reco_angle_p1p2_other_PID_300_CM_btb_zoom;

/// btb in CM

TH1D *reco_angle_SRCrest_p1p2_CCQE_PID_300_CM;
TH1D *reco_angle_SRCrest_p1p2_CCRes_PID_300_CM;
TH1D *reco_angle_SRCrest_p1p2_CCCoh_PID_300_CM;
TH1D *reco_angle_SRCrest_p1p2_CCDIS_PID_300_CM;
TH1D *reco_angle_SRCrest_p1p2_CCMEC_PID_300_CM;
TH1D *reco_angle_SRCrest_p1p2_CCNue_PID_300_CM;
TH1D *reco_angle_SRCrest_p1p2_NC_PID_300_CM;
TH1D *reco_angle_SRCrest_p1p2_other_PID_300_CM;


///resolution Enu

TH2D *res_Enu_PID_300;

//////////////////////////////////////////////////////
////////////////////// MC-truth information///////////
//////////////////////////////////////////////////////

//// Opening angles in lab frame/// p1,p2>250MeV, p1=-p2 (delta p< 50 MeV), PTMiss>300 MeV. Truth variables
TH1D *angle_p1p2_CCQE_PID_300_LF;
TH1D *angle_p1p2_CCRes_PID_300_LF;
TH1D *angle_p1p2_CCCoh_PID_300_LF;
TH1D *angle_p1p2_CCDIS_PID_300_LF;
TH1D *angle_p1p2_CCMEC_PID_300_LF;
TH1D *angle_p1p2_CCNue_PID_300_LF;
TH1D *angle_p1p2_NC_PID_300_LF;

//// Opening angles in CM_Tune3/// pn= p_p1 -q_3 (vector), q from Evis and muon kinematics--opeing angle between nucleon reco and recoil proton in the np initial pair, p>300
TH1D *angle_p1p2_CCQE_PID_300_CM;
TH1D *angle_p1p2_CCRes_PID_300_CM;
TH1D *angle_p1p2_CCCoh_PID_300_CM;
TH1D *angle_p1p2_CCDIS_PID_300_CM;
TH1D *angle_p1p2_CCMEC_PID_300_CM;
TH1D *angle_p1p2_CCNue_PID_300_CM;
TH1D *angle_p1p2_NC_PID_300_CM;

///proton multiplicity

TH1D *NP_CCQE_PID_300;
TH1D *NP_CCRes_PID_300;
TH1D *NP_CCCoh_PID_300;
TH1D *NP_CCDIS_PID_300;
TH1D *NP_CCMEC_PID_300;
TH1D *NP_CCNue_PID_300;
TH1D *NP_NC_PID_300;

/////////////////////////
int numpairs=0;
int totentries =0;
int topo1 =0;
int topo2 =0;
int topo3 =0;
int topo4 =0;
int topo5 =0;
int topo6 =0;
int topo7 =0;
int topo8 =0;
int topo9 =0;
int topo10 =0;
int topo11 =0;

int topo1_300 =0;/// 300MeV proton threshold
int topo2_300 =0;
int topo3_300 =0;
int topo4_300 =0;
int topo5_300 =0;
int topo6_300 =0;
int topo7_300 =0;

int topo1_btb =0;/// with p1~p2
int topo2_btb =0;
int topo3_btb =0;
int topo4_btb =0;
int topo5_btb =0;
int topo6_btb =0;
int topo7_btb =0;

int topo1_p1p2 =0;/// with p1+p2<200MeV
int topo2_p1p2 =0;
int topo3_p1p2 =0;
int topo4_p1p2 =0;
int topo5_p1p2 =0;
int topo6_p1p2 =0;
int topo7_p1p2 =0;

float FVx = 256.35;
float FVy = 233;
float FVz = 1036.8;
float borderx = 12.;
float bordery = 35.;
float borderz = 25.;

int num300 =0;

//This function returns if a 3D point is within the fiducial volume
bool inFV(float x, float y, float z) {
    if(x < (FVx - borderx) && (x > borderx) && (y < (FVy/2. - bordery)) && (y > (-FVy/2. + bordery)) && (z < (FVz - 85)) && (z > borderz)) return true;
    else return false;
}

double Ecalomiss(double Esum, double PTmiss, int np) {
  Esum *= 1000; //convert to MeV
  PTmiss *= 1000; //convert to MeV
  double Eexcit = 30.4; //in MeV
  double Mass = 0; // in MeV
  if(np == 0) Mass = 37.2050e3; //Ar40
  else if(np == 1) Mass = 36.2758e3; //Ar39
  else if(np == 2) Mass = 35.3669e3; //Cl38
  else if(np == 3) Mass = 34.4201e3; //S37
  else if(np == 4) Mass = 33.4957e3; //P36
  else if(np == 5) Mass = 32.5706e3; //Si35
  else if(np == 6) Mass = 31.6539e3; //Al34
  else if(np == 7) Mass = 30.7279e3; //Mg33
  else if(np == 8) Mass = 29.8111e3; //Na32
  else if(np == 9) Mass = 28.8918e3; //Ne31
  else if(np >= 10) Mass = 27.9789e3; //F30

  double Ekinrecoil = sqrt(PTmiss*PTmiss + Mass*Mass) - Mass;
  return Esum + Eexcit + Ekinrecoil; // return result in MeV
}

//********************************************************************
double PPCM_Tune3 (double dmumom, double dp1mom, double dp2mom, TVector3 NeuDir, TVector3 MuDir, TVector3 P1Dir, TVector3 P2Dir, double Enu, double Emuon, double Eproton1, double Eproton2) {
//********************************************************************

  if( Enu  < 0  || dmumom < 0 || dp1mom < 0 || dp2mom < 0) return -1000;

  double mumass = 105.658/1000.;
  double protonmass = 938.272/1000.;
  double bindE = 30.4/1000.;
  
  double Edelta = (protonmass-bindE) + Enu - Emuon;  // Assume target nucleon at rest. (q0)
  
  double delta[3];/// this is just Q_3 
  for( int i = 0; i < 3; i++ ) delta[i] = Enu*NeuDir[i] - dmumom*MuDir[i];////vector directors must be normalized

  double beta[3];/// proper of the boost to the Delta rest frame
  double b2 = 0.;
  
  for(int i = 0; i < 3; i++ ) {
    beta[i] = delta[i]/Edelta;
    b2 += beta[i]*beta[i]; 
  }

  double gamma = 1./TMath::Sqrt(1.-b2); 
  
  double b = TMath::Sqrt(b2);

  //std::cout<<" modulo de beta debe ser menor que 1 ----->    "<<b<<std::endl;
 
  TVector3 p1parallel;
  TVector3 p1perpend;
  TVector3 p1boost;
  double p1boostabs = 0.;

  TVector3 p2parallel;
  TVector3 p2perpend;
  TVector3 p2boost;
  double p2boostabs = 0.;
  
  TVector3 nuparallel;
  TVector3 nuperpend;
  TVector3 nuboost;
  double nuboostabs = 0.;

  TVector3 muparallel;
  TVector3 muperpend;
  TVector3 muboost;
  double muboostabs = 0.;
  
  TVector3 pnboost;
  double pnboostabs=0.;

  for(int i = 0; i < 3; i++ ) {   
    p1parallel[i] = beta[i]/b*(beta[0]/b*dp1mom*P1Dir[0]+beta[1]/b*dp1mom*P1Dir[1]+beta[2]/b*dp1mom*P1Dir[2]); // Pre boost 
    p1perpend[i] = dp1mom*P1Dir[i]-p1parallel[i];
    p1parallel[i] = gamma*(p1parallel[i]-beta[i]*Eproton1); // After boost
    p1boost[i] =  p1parallel[i]+p1perpend[i];
    p1boostabs += p1boost[i]*p1boost[i];

    p2parallel[i] = beta[i]/b*(beta[0]/b*dp2mom*P2Dir[0]+beta[1]/b*dp2mom*P2Dir[1]+beta[2]/b*dp2mom*P2Dir[2]); // Pre boost 
    p2perpend[i] = dp2mom*P2Dir[i]-p2parallel[i];
    p2parallel[i] = gamma*(p2parallel[i]-beta[i]*Eproton2); // After boost
    p2boost[i] =  p2parallel[i]+p2perpend[i];
    p2boostabs += p2boost[i]*p2boost[i];
    
    nuparallel[i] = beta[i]/b*(beta[0]/b*Enu*NeuDir[0]+beta[1]/b*Enu*NeuDir[1]+beta[2]/b*Enu*NeuDir[2]); // Pre boost
    nuperpend[i] = Enu*NeuDir[i]-nuparallel[i];
    nuparallel[i] = gamma*(nuparallel[i]-beta[i]*Enu); // After boost
    nuboost[i] =  nuparallel[i]+nuperpend[i];
    nuboostabs += nuboost[i]*nuboost[i];

    muparallel[i] = beta[i]/b*(beta[0]/b*dmumom*MuDir[0]+beta[1]/b*dmumom*MuDir[1]+beta[2]/b*dmumom*MuDir[2]); // Pre boost 
    muperpend[i] = dmumom*MuDir[i]-muparallel[i];
    muparallel[i] = gamma*(muparallel[i]-beta[i]*Emuon); // After boost
    muboost[i] =  muparallel[i]+muperpend[i];
    muboostabs += muboost[i]*muboost[i];

    pnboost[i]=p1boost[i] - delta[i];
    pnboostabs +=pnboost[i]*pnboost[i]; 
  }

  p1boostabs = TMath::Sqrt(p1boostabs);
  p2boostabs = TMath::Sqrt(p2boostabs);
  nuboostabs = TMath::Sqrt(nuboostabs);
  muboostabs = TMath::Sqrt(muboostabs);
  pnboostabs = TMath::Sqrt(pnboostabs);

  //  double p1p2CM_Tune3 = p1boost.Dot(p2boost);  // scalar product
  // p1p2CM_Tune3 =  p1p2CM_Tune3/((p1boost.Mag())*(p2boost.Mag()));

  double p1p2CM_Tune3 = p1boost.Dot(pnboost);  // scalar product
  p1p2CM_Tune3 =  p1p2CM_Tune3/(p1boostabs*pnboostabs);

  return p1p2CM_Tune3;

}/// fin del calculo de CM angle
//////////


int Topology(int nmuons, int nelectrons, int npions, int npi0, int nprotons, bool cosmicflag, int OOFVflag) {
  //// This function return the true topology of the event, numu & anti-numu                                                        
  ////1. CC0Pion0Proton                                                                                                            
  ////2. CC0Pion1Proton                                  
  ////3. CC0Pion2Proton                                                                                                            
  ////4. CC0PionNProton                                                                                                            
  ////5. CC1PionNProton (1 Pion= 1 charged pion || 1 neutral pion)
  ////6. CCNPionNProton    
  ////7. CCnue-antinue   
  ////8. NC                                                                                            
  ////9. OOFV (nu event out of FV)                                                                                                 
  ////10. Cosmic                                                                                                       
  ////11. Other (just in case, let's check!)                                                                     
  /// e.g. numu CC inclusive= Topology >0 && Topology < 7

  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons ==0 ) return 1;
  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons ==1 ) return 2;
  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons ==2 ) return 3;
  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons >2 ) return 4;
  if (nmuons >0 && (nelectrons ) == 0 && (npions + npi0) == 1 ) return 5;
  if (nmuons >0 && (nelectrons ) == 0 && (npions + npi0) > 1 ) return 6;
  if (nmuons == 0 && nelectrons > 0 ) return 7;
  if (nmuons==0  && nelectrons ==0) return 8;
//  if (OOFVflag) return 9;
//  if (cosmicflag) return 10;  //check with colton how to select cosmic event

  else return 11;

}

void hanalysis_fMC_PID_300::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void hanalysis_fMC_PID_300::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   fanalysis_PID_300= new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_300_BNBMC.root","RECREATE");
   outfileMC_PID_300.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_PID_300_MC.txt");

   std::cout<<"declaring histos"<<endl;
/////////////////// muon candidate properties

   selmuon_lenght_CC0Pion0Proton_PID_300= new TH1D("selmuon_lenght_CC0Pion0Proton_PID_300", "selmuon_lenght_CC0Pion0Proton_PID_300", 10, 0, 500);
   selmuon_lenght_CC0Pion1Proton_PID_300= new TH1D("selmuon_lenght_CC0Pion1Proton_PID_300", "selmuon_lenght_CC0Pion1Proton_PID_300", 10, 0, 500);
   selmuon_lenght_CC0Pion2Proton_PID_300= new TH1D("selmuon_lenght_CC0Pion2Proton_PID_300", "selmuon_lenght_CC0Pion2Proton_PID_300", 10, 0, 500);
   selmuon_lenght_CC0PionNProton_PID_300= new TH1D("selmuon_lenght_CC0PionNProton_PID_300", "selmuon_lenght_CC0PionNProton_PID_300", 10, 0, 500);
   selmuon_lenght_CC1PionNProton_PID_300= new TH1D("selmuon_lenght_CC1PionNProton_PID_300", "selmuon_lenght_CC1PionNProton_PID_300", 10, 0, 500);
   selmuon_lenght_CCNPionNProton_PID_300= new TH1D("selmuon_lenght_CCNPionNProton_PID_300", "selmuon_lenght_CCNPionNProton_PID_300", 10, 0, 500);
   selmuon_lenght_CCNue_PID_300= new TH1D("selmuon_lenght_CCNue_PID_300", "selmuon_lenght_CCNue_PID_300", 10, 0, 500);   
   selmuon_lenght_NC_PID_300= new TH1D("selmuon_lenght_NC_PID_300", "selmuon_lenght_NC_PID_300", 10, 0, 500);
   selmuon_lenght_OOFV_PID_300= new TH1D("selmuon_lenght_OOFV_PID_300", "selmuon_lenght_OOFV_PID_300", 10, 0, 500);
   selmuon_lenght_EXT_PID_300= new TH1D("selmuon_lenght_EXT_PID_300", "selmuon_lenght_EXT_PID_300", 10, 0, 500);
   selmuon_lenght_other_PID_300= new TH1D("selmuon_lenght_other_PID_300", "selmuon_lenght_other_PID_300", 10, 0, 500);   
   ////
   selmuon_mom_CC0Pion0Proton_PID_300= new TH1D("selmuon_mom_CC0Pion0Proton_PID_300", "selmuon_mom_CC0Pion0Proton_PID_300", 10, 0, 3);
   selmuon_mom_CC0Pion1Proton_PID_300= new TH1D("selmuon_mom_CC0Pion1Proton_PID_300", "selmuon_mom_CC0Pion1Proton_PID_300", 10, 0, 3);
   selmuon_mom_CC0Pion2Proton_PID_300= new TH1D("selmuon_mom_CC0Pion2Proton_PID_300", "selmuon_mom_CC0Pion2Proton_PID_300", 10, 0, 3);
   selmuon_mom_CC0PionNProton_PID_300= new TH1D("selmuon_mom_CC0PionNProton_PID_300", "selmuon_mom_CC0PionNProton_PID_300", 10, 0, 3);
   selmuon_mom_CC1PionNProton_PID_300= new TH1D("selmuon_mom_CC1PionNProton_PID_300", "selmuon_mom_CC1PionNProton_PID_300", 10, 0, 3);
   selmuon_mom_CCNPionNProton_PID_300= new TH1D("selmuon_mom_CCNPionNProton_PID_300", "selmuon_mom_CCNPionNProton_PID_300", 10, 0, 3);
   selmuon_mom_CCNue_PID_300= new TH1D("selmuon_mom_CCNue_PID_300", "selmuon_mom_CCNue_PID_300", 10, 0, 3);   
   selmuon_mom_NC_PID_300= new TH1D("selmuon_mom_NC_PID_300", "selmuon_mom_NC_PID_300", 10, 0, 3);
   selmuon_mom_OOFV_PID_300= new TH1D("selmuon_mom_OOFV_PID_300", "selmuon_mom_OOFV_PID_300", 10, 0, 3);
   selmuon_mom_EXT_PID_300= new TH1D("selmuon_mom_EXT_PID_300", "selmuon_mom_EXT_PID_300", 10, 0, 3);
   selmuon_mom_other_PID_300= new TH1D("selmuon_mom_other_PID_300", "selmuon_mom_other_PID_300", 10, 0, 3);   
   ///
   
   selmuon_contained_mom_CC0Pion0Proton_PID_300= new TH1D("selmuon_contained_mom_CC0Pion0Proton_PID_300", "selmuon_contained_mom_CC0Pion0Proton_PID_300", 10, 0, 3);
   selmuon_contained_mom_CC0Pion1Proton_PID_300= new TH1D("selmuon_contained_mom_CC0Pion1Proton_PID_300", "selmuon_contained_mom_CC0Pion1Proton_PID_300", 10, 0, 3);
   selmuon_contained_mom_CC0Pion2Proton_PID_300= new TH1D("selmuon_contained_mom_CC0Pion2Proton_PID_300", "selmuon_contained_mom_CC0Pion2Proton_PID_300", 10, 0, 3);
   selmuon_contained_mom_CC0PionNProton_PID_300= new TH1D("selmuon_contained_mom_CC0PionNProton_PID_300", "selmuon_contained_mom_CC0PionNProton_PID_300", 10, 0, 3);
   selmuon_contained_mom_CC1PionNProton_PID_300= new TH1D("selmuon_contained_mom_CC1PionNProton_PID_300", "selmuon_contained_mom_CC1PionNProton_PID_300", 10, 0, 3);
   selmuon_contained_mom_CCNPionNProton_PID_300= new TH1D("selmuon_contained_mom_CCNPionNProton_PID_300", "selmuon_contained_mom_CCNPionNProton_PID_300", 10, 0, 3);
   selmuon_contained_mom_CCNue_PID_300= new TH1D("selmuon_contained_mom_CCNue_PID_300", "selmuon_contained_mom_CCNue_PID_300", 10, 0, 3);   
   selmuon_contained_mom_NC_PID_300= new TH1D("selmuon_contained_mom_NC_PID_300", "selmuon_contained_mom_NC_PID_300", 10, 0, 3);
   selmuon_contained_mom_OOFV_PID_300= new TH1D("selmuon_contained_mom_OOFV_PID_300", "selmuon_contained_mom_OOFV_PID_300", 10, 0, 3);
   selmuon_contained_mom_EXT_PID_300= new TH1D("selmuon_contained_mom_EXT_PID_300", "selmuon_contained_mom_EXT_PID_300", 10, 0, 3);
   selmuon_contained_mom_other_PID_300= new TH1D("selmuon_contained_mom_other_PID_300", "selmuon_contained_mom_other_PID_300", 10, 0, 3);   
   ////

   selmuon_uncontained_mom_CC0Pion0Proton_PID_300= new TH1D("selmuon_uncontained_mom_CC0Pion0Proton_PID_300", "selmuon_uncontained_mom_CC0Pion0Proton_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_CC0Pion1Proton_PID_300= new TH1D("selmuon_uncontained_mom_CC0Pion1Proton_PID_300", "selmuon_uncontained_mom_CC0Pion1Proton_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_CC0Pion2Proton_PID_300= new TH1D("selmuon_uncontained_mom_CC0Pion2Proton_PID_300", "selmuon_uncontained_mom_CC0Pion2Proton_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_CC0PionNProton_PID_300= new TH1D("selmuon_uncontained_mom_CC0PionNProton_PID_300", "selmuon_uncontained_mom_CC0PionNProton_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_CC1PionNProton_PID_300= new TH1D("selmuon_uncontained_mom_CC1PionNProton_PID_300", "selmuon_uncontained_mom_CC1PionNProton_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_CCNPionNProton_PID_300= new TH1D("selmuon_uncontained_mom_CCNPionNProton_PID_300", "selmuon_uncontained_mom_CCNPionNProton_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_CCNue_PID_300= new TH1D("selmuon_uncontained_mom_CCNue_PID_300", "selmuon_uncontained_mom_CCNue_PID_300", 10, 0, 3);   
   selmuon_uncontained_mom_NC_PID_300= new TH1D("selmuon_uncontained_mom_NC_PID_300", "selmuon_uncontained_mom_NC_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_OOFV_PID_300= new TH1D("selmuon_uncontained_mom_OOFV_PID_300", "selmuon_uncontained_mom_OOFV_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_EXT_PID_300= new TH1D("selmuon_uncontained_mom_EXT_PID_300", "selmuon_uncontained_mom_EXT_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_other_PID_300= new TH1D("selmuon_uncontained_mom_other_PID_300", "selmuon_uncontained_mom_other_PID_300", 10, 0, 3);   
   ////
   selmuon_costheta_CC0Pion0Proton_PID_300= new TH1D("selmuon_costheta_CC0Pion0Proton_PID_300", "selmuon_costheta_CC0Pion0Proton_PID_300", 10, -1, 1);
   selmuon_costheta_CC0Pion1Proton_PID_300= new TH1D("selmuon_costheta_CC0Pion1Proton_PID_300", "selmuon_costheta_CC0Pion1Proton_PID_300", 10, -1, 1);
   selmuon_costheta_CC0Pion2Proton_PID_300= new TH1D("selmuon_costheta_CC0Pion2Proton_PID_300", "selmuon_costheta_CC0Pion2Proton_PID_300", 10, -1, 1);
   selmuon_costheta_CC0PionNProton_PID_300= new TH1D("selmuon_costheta_CC0PionNProton_PID_300", "selmuon_costheta_CC0PionNProton_PID_300", 10, -1, 1);
   selmuon_costheta_CC1PionNProton_PID_300= new TH1D("selmuon_costheta_CC1PionNProton_PID_300", "selmuon_costheta_CC1PionNProton_PID_300", 10, -1, 1);
   selmuon_costheta_CCNPionNProton_PID_300= new TH1D("selmuon_costheta_CCNPionNProton_PID_300", "selmuon_costheta_CCNPionNProton_PID_300", 10, -1, 1);
   selmuon_costheta_CCNue_PID_300= new TH1D("selmuon_costheta_CCNue_PID_300", "selmuon_costheta_CCNue_PID_300", 10, -1, 1);   
   selmuon_costheta_NC_PID_300= new TH1D("selmuon_costheta_NC_PID_300", "selmuon_costheta_NC_PID_300", 10, -1, 1);
   selmuon_costheta_OOFV_PID_300= new TH1D("selmuon_costheta_OOFV_PID_300", "selmuon_costheta_OOFV_PID_300", 10, -1, 1);
   selmuon_costheta_EXT_PID_300= new TH1D("selmuon_costheta_EXT_PID_300", "selmuon_costheta_EXT_PID_300", 10, -1, 1);
   selmuon_costheta_other_PID_300= new TH1D("selmuon_costheta_other_PID_300", "selmuon_costheta_other_PID_300", 10, -1, 1); 
   /////
   selmuon_phi_CC0Pion0Proton_PID_300= new TH1D("selmuon_phi_CC0Pion0Proton_PID_300", "selmuon_phi_CC0Pion0Proton_PID_300", 10, -3.14, 3.14);
   selmuon_phi_CC0Pion1Proton_PID_300= new TH1D("selmuon_phi_CC0Pion1Proton_PID_300", "selmuon_phi_CC0Pion1Proton_PID_300", 10, -3.14, 3.14);
   selmuon_phi_CC0Pion2Proton_PID_300= new TH1D("selmuon_phi_CC0Pion2Proton_PID_300", "selmuon_phi_CC0Pion2Proton_PID_300", 10, -3.14, 3.14);
   selmuon_phi_CC0PionNProton_PID_300= new TH1D("selmuon_phi_CC0PionNProton_PID_300", "selmuon_phi_CC0PionNProton_PID_300", 10, -3.14, 3.14);
   selmuon_phi_CC1PionNProton_PID_300= new TH1D("selmuon_phi_CC1PionNProton_PID_300", "selmuon_phi_CC1PionNProton_PID_300", 10, -3.14, 3.14);
   selmuon_phi_CCNPionNProton_PID_300= new TH1D("selmuon_phi_CCNPionNProton_PID_300", "selmuon_phi_CCNPionNProton_PID_300", 10, -3.14, 3.14);
   selmuon_phi_CCNue_PID_300= new TH1D("selmuon_phi_CCNue_PID_300", "selmuon_phi_CCNue_PID_300", 10, -3.14, 3.14);   
   selmuon_phi_NC_PID_300= new TH1D("selmuon_phi_NC_PID_300", "selmuon_phi_NC_PID_300", 10, -3.14, 3.14);
   selmuon_phi_OOFV_PID_300= new TH1D("selmuon_phi_OOFV_PID_300", "selmuon_phi_OOFV_PID_300", 10, -3.14, 3.14);
   selmuon_phi_EXT_PID_300= new TH1D("selmuon_phi_EXT_PID_300", "selmuon_phi_EXT_PID_300", 10, -3.14, 3.14);
   selmuon_phi_other_PID_300= new TH1D("selmuon_phi_other_PID_300", "selmuon_phi_other_PID_300", 10, -3.14, 3.14); 
   /////

   selmuon_lenght_muon_PID_300= new TH1D("selmuon_lenght_muon_PID_300", "selmuon_lenght_muon_PID_300", 10, 0, 500);
   selmuon_lenght_proton_PID_300= new TH1D("selmuon_lenght_proton_PID_300", "selmuon_lenght_proton_PID_300", 10, 0, 500);
   selmuon_lenght_pion_PID_300= new TH1D("selmuon_lenght_pion_PID_300", "selmuon_lenght_pion_PID_300", 10, 0, 500);
   selmuon_lenght_electron_PID_300= new TH1D("selmuon_lenght_electron_PID_300", "selmuon_lenght_electron_PID_300", 10, 0, 500);
   selmuon_lenght_pother_PID_300= new TH1D("selmuon_lenght_pother_PID_300", "selmuon_lenght_pother_PID_300", 10, 0, 500);
   ////   
   selmuon_mom_muon_PID_300= new TH1D("selmuon_mom_muon_PID_300", "selmuon_mom_muon_PID_300", 10, 0, 3);
   selmuon_mom_proton_PID_300= new TH1D("selmuon_mom_proton_PID_300", "selmuon_mom_proton_PID_300", 10, 0, 3);
   selmuon_mom_pion_PID_300= new TH1D("selmuon_mom_pion_PID_300", "selmuon_mom_pion_PID_300", 10, 0, 3);
   selmuon_mom_electron_PID_300= new TH1D("selmuon_mom_electron_PID_300", "selmuon_mom_electron_PID_300", 10, 0, 3);
   selmuon_mom_pother_PID_300= new TH1D("selmuon_mom_pother_PID_300", "selmuon_mom_pother_PID_300", 10, 0, 3);
   ///
   selmuon_contained_mom_muon_PID_300= new TH1D("selmuon_contained_mom_muon_PID_300", "selmuon_contained_mom_muon_PID_300", 10, 0, 3);
   selmuon_contained_mom_proton_PID_300= new TH1D("selmuon_contained_mom_proton_PID_300", "selmuon_contained_mom_proton_PID_300", 10, 0, 3);
   selmuon_contained_mom_pion_PID_300= new TH1D("selmuon_contained_mom_pion_PID_300", "selmuon_contained_mom_pion_PID_300", 10, 0, 3);
   selmuon_contained_mom_electron_PID_300= new TH1D("selmuon_contained_mom_electron_PID_300", "selmuon_contained_mom_electron_PID_300", 10, 0, 3);
   selmuon_contained_mom_pother_PID_300= new TH1D("selmuon_contained_mom_pother_PID_300", "selmuon_contained_mom_pother_PID_300", 10, 0, 3);
   ///
   selmuon_uncontained_mom_muon_PID_300= new TH1D("selmuon_uncontained_mom_muon_PID_300", "selmuon_uncontained_mom_muon_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_proton_PID_300= new TH1D("selmuon_uncontained_mom_proton_PID_300", "selmuon_uncontained_mom_proton_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_pion_PID_300= new TH1D("selmuon_uncontained_mom_pion_PID_300", "selmuon_uncontained_mom_pion_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_electron_PID_300= new TH1D("selmuon_uncontained_mom_electron_PID_300", "selmuon_uncontained_mom_electron_PID_300", 10, 0, 3);
   selmuon_uncontained_mom_pother_PID_300= new TH1D("selmuon_uncontained_mom_pother_PID_300", "selmuon_uncontained_mom_pother_PID_300", 10, 0, 3);

   ///
   selmuon_costheta_muon_PID_300= new TH1D("selmuon_costheta_muon_PID_300", "selmuon_costheta_muon_PID_300", 10, -1, 1);
   selmuon_costheta_proton_PID_300= new TH1D("selmuon_costheta_proton_PID_300", "selmuon_costheta_proton_PID_300", 10, -1, 1);
   selmuon_costheta_pion_PID_300= new TH1D("selmuon_costheta_pion_PID_300", "selmuon_costheta_pion_PID_300", 10, -1, 1);
   selmuon_costheta_electron_PID_300= new TH1D("selmuon_costheta_electron_PID_300", "selmuon_costheta_electron_PID_300", 10, -1, 1);
   selmuon_costheta_pother_PID_300= new TH1D("selmuon_costheta_pother_PID_300", "selmuon_costheta_pother_PID_300", 10, -1, 1);
   ///
   selmuon_phi_muon_PID_300= new TH1D("selmuon_phi_muon_PID_300", "selmuon_phi_muon_PID_300", 10, -3.14, 3.14);
   selmuon_phi_proton_PID_300= new TH1D("selmuon_phi_proton_PID_300", "selmuon_phi_proton_PID_300", 10, -3.14, 3.14);
   selmuon_phi_pion_PID_300= new TH1D("selmuon_phi_pion_PID_300", "selmuon_phi_pion_PID_300", 10, -3.14, 3.14);
   selmuon_phi_electron_PID_300= new TH1D("selmuon_phi_electron_PID_300", "selmuon_phi_electron_PID_300", 10, -3.14, 3.14);
   selmuon_phi_pother_PID_300= new TH1D("selmuon_phi_pother_PID_300", "selmuon_phi_pother_PID_300", 10, -3.14, 3.14);

   selmuon_chi2proton_muon_PID_300= new TH1D("selmuon_chi2proton_muon_PID_300", "selmuon_chi2proton_muon_PID_300", 30, 0, 300);
   selmuon_chi2proton_proton_PID_300= new TH1D("selmuon_chi2proton_proton_PID_300", "selmuon_chi2proton_proton_PID_300", 30, 0, 300);
   selmuon_chi2proton_pion_PID_300= new TH1D("selmuon_chi2proton_pion_PID_300", "selmuon_chi2proton_pion_PID_300", 30, 0, 300);
   selmuon_chi2proton_electron_PID_300= new TH1D("selmuon_chi2proton_electron_PID_300", "selmuon_chi2proton_electron_PID_300", 30, 0, 300);
   selmuon_chi2proton_pother_PID_300= new TH1D("selmuon_chi2proton_pother_PID_300", "selmuon_chi2proton_pother_PID_300", 30, 0, 300);

   selmuon_chi2proton_cont_muon_PID_300= new TH1D("selmuon_chi2proton_cont_muon_PID_300", "selmuon_chi2proton_cont_muon_PID_300", 30, 0, 300);
   selmuon_chi2proton_cont_proton_PID_300= new TH1D("selmuon_chi2proton_cont_proton_PID_300", "selmuon_chi2proton_cont_proton_PID_300", 30, 0, 300);
   selmuon_chi2proton_cont_pion_PID_300= new TH1D("selmuon_chi2proton_cont_pion_PID_300", "selmuon_chi2proton_cont_pion_PID_300", 30, 0, 300);
   selmuon_chi2proton_cont_electron_PID_300= new TH1D("selmuon_chi2proton_cont_electron_PID_300", "selmuon_chi2proton_cont_electron_PID_300", 30, 0, 300);
   selmuon_chi2proton_cont_pother_PID_300= new TH1D("selmuon_chi2proton_cont_pother_PID_300", "selmuon_chi2proton_cont_pother_PID_300", 30, 0, 300);

   selmuon_chi2proton_uncont_muon_PID_300= new TH1D("selmuon_chi2proton_uncont_muon_PID_300", "selmuon_chi2proton_uncont_muon_PID_300", 30, 0, 300);
   selmuon_chi2proton_uncont_proton_PID_300= new TH1D("selmuon_chi2proton_uncont_proton_PID_300", "selmuon_chi2proton_uncont_proton_PID_300", 30, 0, 300);
   selmuon_chi2proton_uncont_pion_PID_300= new TH1D("selmuon_chi2proton_uncont_pion_PID_300", "selmuon_chi2proton_uncont_pion_PID_300", 30, 0, 300);
   selmuon_chi2proton_uncont_electron_PID_300= new TH1D("selmuon_chi2proton_uncont_electron_PID_300", "selmuon_chi2proton_uncont_electron_PID_300", 30, 0, 300);
   selmuon_chi2proton_uncont_pother_PID_300= new TH1D("selmuon_chi2proton_uncont_pother_PID_300", "selmuon_chi2proton_uncont_pother_PID_300", 30, 0, 300);
   
   selmuon_dEdx_vs_resrange_muon_PID_300 = new TH2D("selmuon_dEdx_vs_resrange_muon_PID_300", "selmuon_dEdx_vs_resrange_muon_PID_300", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_proton_PID_300 = new TH2D("selmuon_dEdx_vs_resrange_proton_PID_300", "selmuon_dEdx_vs_resrange_proton_PID_300", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_pion_PID_300 = new TH2D("selmuon_dEdx_vs_resrange_pion_PID_300", "selmuon_dEdx_vs_resrange_pion_PID_300", 50,0,50,20, 0, 20);

///proton properties
   selproton1_lenght_CC0Pion0Proton_PID_300= new TH1D("selproton1_lenght_CC0Pion0Proton_PID_300", "selproton1_lenght_CC0Pion0Proton_PID_300", 10, 0, 100);
   selproton1_lenght_CC0Pion1Proton_PID_300= new TH1D("selproton1_lenght_CC0Pion1Proton_PID_300", "selproton1_lenght_CC0Pion1Proton_PID_300", 10, 0, 100);
   selproton1_lenght_CC0Pion2Proton_PID_300= new TH1D("selproton1_lenght_CC0Pion2Proton_PID_300", "selproton1_lenght_CC0Pion2Proton_PID_300", 10, 0, 100);
   selproton1_lenght_CC0PionNProton_PID_300= new TH1D("selproton1_lenght_CC0PionNProton_PID_300", "selproton1_lenght_CC0PionNProton_PID_300", 10, 0, 100);
   selproton1_lenght_CC1PionNProton_PID_300= new TH1D("selproton1_lenght_CC1PionNProton_PID_300", "selproton1_lenght_CC1PionNProton_PID_300", 10, 0, 100);
   selproton1_lenght_CCNPionNProton_PID_300= new TH1D("selproton1_lenght_CCNPionNProton_PID_300", "selproton1_lenght_CCNPionNProton_PID_300", 10, 0, 100);
   selproton1_lenght_CCNue_PID_300= new TH1D("selproton1_lenght_CCNue_PID_300", "selproton1_lenght_CCNue_PID_300", 10, 0, 100);   
   selproton1_lenght_NC_PID_300= new TH1D("selproton1_lenght_NC_PID_300", "selproton1_lenght_NC_PID_300", 10, 0, 100);
   selproton1_lenght_OOFV_PID_300= new TH1D("selproton1_lenght_OOFV_PID_300", "selproton1_lenght_OOFV_PID_300", 10, 0, 100);
   selproton1_lenght_EXT_PID_300= new TH1D("selproton1_lenght_EXT_PID_300", "selproton1_lenght_EXT_PID_300", 10, 0, 100);
   selproton1_lenght_other_PID_300= new TH1D("selproton1_lenght_other_PID_300", "selproton1_lenght_other_PID_300", 10, 0, 100);
   
   //////////////////////
   selproton1_costheta_CC0Pion0Proton_PID_300= new TH1D("selproton1_costheta_CC0Pion0Proton_PID_300", "selproton1_costheta_CC0Pion0Proton_PID_300", 10, -1, 1);
   selproton1_costheta_CC0Pion1Proton_PID_300= new TH1D("selproton1_costheta_CC0Pion1Proton_PID_300", "selproton1_costheta_CC0Pion1Proton_PID_300", 10, -1, 1);
   selproton1_costheta_CC0Pion2Proton_PID_300= new TH1D("selproton1_costheta_CC0Pion2Proton_PID_300", "selproton1_costheta_CC0Pion2Proton_PID_300", 10, -1, 1);
   selproton1_costheta_CC0PionNProton_PID_300= new TH1D("selproton1_costheta_CC0PionNProton_PID_300", "selproton1_costheta_CC0PionNProton_PID_300", 10, -1, 1);
   selproton1_costheta_CC1PionNProton_PID_300= new TH1D("selproton1_costheta_CC1PionNProton_PID_300", "selproton1_costheta_CC1PionNProton_PID_300", 10, -1, 1);
   selproton1_costheta_CCNPionNProton_PID_300= new TH1D("selproton1_costheta_CCNPionNProton_PID_300", "selproton1_costheta_CCNPionNProton_PID_300", 10, -1, 1);
   selproton1_costheta_CCNue_PID_300= new TH1D("selproton1_costheta_CCNue_PID_300", "selproton1_costheta_CCNue_PID_300", 10, -1, 1);   
   selproton1_costheta_NC_PID_300= new TH1D("selproton1_costheta_NC_PID_300", "selproton1_costheta_NC_PID_300", 10, -1, 1);
   selproton1_costheta_OOFV_PID_300= new TH1D("selproton1_costheta_OOFV_PID_300", "selproton1_costheta_OOFV_PID_300", 10, -1, 1);
   selproton1_costheta_EXT_PID_300= new TH1D("selproton1_costheta_EXT_PID_300", "selproton1_costheta_EXT_PID_300", 10, -1, 1);
   selproton1_costheta_other_PID_300= new TH1D("selproton1_costheta_other_PID_300", "selproton1_costheta_other_PID_300", 10, -1, 1); 
   /////
   selproton1_phi_CC0Pion0Proton_PID_300= new TH1D("selproton1_phi_CC0Pion0Proton_PID_300", "selproton1_phi_CC0Pion0Proton_PID_300", 10, -3.14, 3.14);
   selproton1_phi_CC0Pion1Proton_PID_300= new TH1D("selproton1_phi_CC0Pion1Proton_PID_300", "selproton1_phi_CC0Pion1Proton_PID_300", 10, -3.14, 3.14);
   selproton1_phi_CC0Pion2Proton_PID_300= new TH1D("selproton1_phi_CC0Pion2Proton_PID_300", "selproton1_phi_CC0Pion2Proton_PID_300", 10, -3.14, 3.14);
   selproton1_phi_CC0PionNProton_PID_300= new TH1D("selproton1_phi_CC0PionNProton_PID_300", "selproton1_phi_CC0PionNProton_PID_300", 10, -3.14, 3.14);
   selproton1_phi_CC1PionNProton_PID_300= new TH1D("selproton1_phi_CC1PionNProton_PID_300", "selproton1_phi_CC1PionNProton_PID_300", 10, -3.14, 3.14);
   selproton1_phi_CCNPionNProton_PID_300= new TH1D("selproton1_phi_CCNPionNProton_PID_300", "selproton1_phi_CCNPionNProton_PID_300", 10, -3.14, 3.14);
   selproton1_phi_CCNue_PID_300= new TH1D("selproton1_phi_CCNue_PID_300", "selproton1_phi_CCNue_PID_300", 10, -3.14, 3.14);   
   selproton1_phi_NC_PID_300= new TH1D("selproton1_phi_NC_PID_300", "selproton1_phi_NC_PID_300", 10, -3.14, 3.14);
   selproton1_phi_OOFV_PID_300= new TH1D("selproton1_phi_OOFV_PID_300", "selproton1_phi_OOFV_PID_300", 10, -3.14, 3.14);
   selproton1_phi_EXT_PID_300= new TH1D("selproton1_phi_EXT_PID_300", "selproton1_phi_EXT_PID_300", 10, -3.14, 3.14);
   selproton1_phi_other_PID_300= new TH1D("selproton1_phi_other_PID_300", "selproton1_phi_other_PID_300", 10, -3.14, 3.14); 
 
   selproton1_mom_CC0Pion0Proton_PID_300= new TH1D("selproton1_mom_CC0Pion0Proton_PID_300", "selproton1_mom_CC0Pion0Proton_PID_300", 10, 0, 1.5);
   selproton1_mom_CC0Pion1Proton_PID_300= new TH1D("selproton1_mom_CC0Pion1Proton_PID_300", "selproton1_mom_CC0Pion1Proton_PID_300", 10, 0, 1.5);
   selproton1_mom_CC0Pion2Proton_PID_300= new TH1D("selproton1_mom_CC0Pion2Proton_PID_300", "selproton1_mom_CC0Pion2Proton_PID_300", 10, 0, 1.5);
   selproton1_mom_CC0PionNProton_PID_300= new TH1D("selproton1_mom_CC0PionNProton_PID_300", "selproton1_mom_CC0PionNProton_PID_300", 10, 0, 1.5);
   selproton1_mom_CC1PionNProton_PID_300= new TH1D("selproton1_mom_CC1PionNProton_PID_300", "selproton1_mom_CC1PionNProton_PID_300", 10, 0, 1.5);
   selproton1_mom_CCNPionNProton_PID_300= new TH1D("selproton1_mom_CCNPionNProton_PID_300", "selproton1_mom_CCNPionNProton_PID_300", 10, 0, 1.5);
   selproton1_mom_CCNue_PID_300= new TH1D("selproton1_mom_CCNue_PID_300", "selproton1_mom_CCNue_PID_300", 10, 0, 1.5);   
   selproton1_mom_NC_PID_300= new TH1D("selproton1_mom_NC_PID_300", "selproton1_mom_NC_PID_300", 10, 0, 1.5);
   selproton1_mom_OOFV_PID_300= new TH1D("selproton1_mom_OOFV_PID_300", "selproton1_mom_OOFV_PID_300", 10, 0, 1.5);
   selproton1_mom_EXT_PID_300= new TH1D("selproton1_mom_EXT_PID_300", "selproton1_mom_EXT_PID_300", 10, 0, 1.5);
   selproton1_mom_other_PID_300= new TH1D("selproton1_mom_other_PID_300", "selproton1_mom_other_PID_300", 10, 0, 1.5);

  //////

   selproton1_lenght_muon_PID_300= new TH1D("selproton1_lenght_muon_PID_300", "selproton1_lenght_muon_PID_300", 10, 0, 100);
   selproton1_lenght_proton_PID_300= new TH1D("selproton1_lenght_proton_PID_300", "selproton1_lenght_proton_PID_300", 10, 0, 100);
   selproton1_lenght_pion_PID_300= new TH1D("selproton1_lenght_pion_PID_300", "selproton1_lenght_pion_PID_300", 10, 0, 100);
   selproton1_lenght_electron_PID_300= new TH1D("selproton1_lenght_electron_PID_300", "selproton1_lenght_electron_PID_300", 10, 0, 100);
   selproton1_lenght_pother_PID_300= new TH1D("selproton1_lenght_pother_PID_300", "selproton1_lenght_pother_PID_300", 10, 0, 100);
   ////
   selproton1_costheta_muon_PID_300= new TH1D("selproton1_costheta_muon_PID_300", "selproton1_costheta_muon_PID_300", 10, -1, 1);
   selproton1_costheta_proton_PID_300= new TH1D("selproton1_costheta_proton_PID_300", "selproton1_costheta_proton_PID_300", 10, -1, 1);
   selproton1_costheta_pion_PID_300= new TH1D("selproton1_costheta_pion_PID_300", "selproton1_costheta_pion_PID_300", 10, -1, 1);
   selproton1_costheta_electron_PID_300= new TH1D("selproton1_costheta_electron_PID_300", "selproton1_costheta_electron_PID_300", 10, -1, 1);
   selproton1_costheta_pother_PID_300= new TH1D("selproton1_costheta_pother_PID_300", "selproton1_costheta_pother_PID_300", 10, -1, 1);
   ///
   selproton1_phi_muon_PID_300= new TH1D("selproton1_phi_muon_PID_300", "selproton1_phi_muon_PID_300", 10, -3.14, 3.14);
   selproton1_phi_proton_PID_300= new TH1D("selproton1_phi_proton_PID_300", "selproton1_phi_proton_PID_300", 10, -3.14, 3.14);
   selproton1_phi_pion_PID_300= new TH1D("selproton1_phi_pion_PID_300", "selproton1_phi_pion_PID_300", 10, -3.14, 3.14);
   selproton1_phi_electron_PID_300= new TH1D("selproton1_phi_electron_PID_300", "selproton1_phi_electron_PID_300", 10, -3.14, 3.14);
   selproton1_phi_pother_PID_300= new TH1D("selproton1_phi_pother_PID_300", "selproton1_phi_pother_PID_300", 10, -3.14, 3.14);

   selproton1_chi2proton_muon_PID_300= new TH1D("selproton1_chi2proton_muon_PID_300", "selproton1_chi2proton_muon_PID_300", 10, 0, 300);
   selproton1_chi2proton_proton_PID_300= new TH1D("selproton1_chi2proton_proton_PID_300", "selproton1_chi2proton_proton_PID_300", 10, 0, 300);
   selproton1_chi2proton_pion_PID_300= new TH1D("selproton1_chi2proton_pion_PID_300", "selproton1_chi2proton_pion_PID_300", 10, 0, 300);
   selproton1_chi2proton_electron_PID_300= new TH1D("selproton1_chi2proton_electron_PID_300", "selproton1_chi2proton_electron_PID_300", 10, 0, 300);
   selproton1_chi2proton_pother_PID_300= new TH1D("selproton1_chi2proton_pother_PID_300", "selproton1_chi2proton_pother_PID_300", 10, 0, 300);

   selproton1_dEdx_vs_resrange_muon_PID_300 = new TH2D("selproton1_dEdx_vs_resrange_muon_PID_300", "selproton1_dEdx_vs_resrange_muon_PID_300", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_proton_PID_300 = new TH2D("selproton1_dEdx_vs_resrange_proton_PID_300", "selproton1_dEdx_vs_resrange_proton_PID_300", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_pion_PID_300 = new TH2D("selproton1_dEdx_vs_resrange_pion_PID_300", "selproton1_dEdx_vs_resrange_pion_PID_300", 50,0,50,20, 0, 20);

   //////////////////////////////// proton 2///////////////
   
   selproton2_lenght_CC0Pion0Proton_PID_300= new TH1D("selproton2_lenght_CC0Pion0Proton_PID_300", "selproton2_lenght_CC0Pion0Proton_PID_300", 10, 0, 40);
   selproton2_lenght_CC0Pion1Proton_PID_300= new TH1D("selproton2_lenght_CC0Pion1Proton_PID_300", "selproton2_lenght_CC0Pion1Proton_PID_300", 10, 0, 40);
   selproton2_lenght_CC0Pion2Proton_PID_300= new TH1D("selproton2_lenght_CC0Pion2Proton_PID_300", "selproton2_lenght_CC0Pion2Proton_PID_300", 10, 0, 40);
   selproton2_lenght_CC0PionNProton_PID_300= new TH1D("selproton2_lenght_CC0PionNProton_PID_300", "selproton2_lenght_CC0PionNProton_PID_300", 10, 0, 40);
   selproton2_lenght_CC1PionNProton_PID_300= new TH1D("selproton2_lenght_CC1PionNProton_PID_300", "selproton2_lenght_CC1PionNProton_PID_300", 10, 0, 40);
   selproton2_lenght_CCNPionNProton_PID_300= new TH1D("selproton2_lenght_CCNPionNProton_PID_300", "selproton2_lenght_CCNPionNProton_PID_300", 10, 0, 40);
   selproton2_lenght_CCNue_PID_300= new TH1D("selproton2_lenght_CCNue_PID_300", "selproton2_lenght_CCNue_PID_300", 10, 0, 40);
   selproton2_lenght_NC_PID_300= new TH1D("selproton2_lenght_NC_PID_300", "selproton2_lenght_NC_PID_300", 10, 0, 40);
   selproton2_lenght_OOFV_PID_300= new TH1D("selproton2_lenght_OOFV_PID_300", "selproton2_lenght_OOFV_PID_300", 10, 0, 40);
   selproton2_lenght_EXT_PID_300= new TH1D("selproton2_lenght_EXT_PID_300", "selproton2_lenght_EXT_PID_300", 10, 0, 40);
   selproton2_lenght_other_PID_300= new TH1D("selproton2_lenght_other_PID_300", "selproton2_lenght_other_PID_300", 10, 0, 40);

   selproton2_costheta_CC0Pion0Proton_PID_300= new TH1D("selproton2_costheta_CC0Pion0Proton_PID_300", "selproton2_costheta_CC0Pion0Proton_PID_300", 10, -1, 1);
   selproton2_costheta_CC0Pion1Proton_PID_300= new TH1D("selproton2_costheta_CC0Pion1Proton_PID_300", "selproton2_costheta_CC0Pion1Proton_PID_300", 10, -1, 1);
   selproton2_costheta_CC0Pion2Proton_PID_300= new TH1D("selproton2_costheta_CC0Pion2Proton_PID_300", "selproton2_costheta_CC0Pion2Proton_PID_300", 10, -1, 1);
   selproton2_costheta_CC0PionNProton_PID_300= new TH1D("selproton2_costheta_CC0PionNProton_PID_300", "selproton2_costheta_CC0PionNProton_PID_300", 10, -1, 1);
   selproton2_costheta_CC1PionNProton_PID_300= new TH1D("selproton2_costheta_CC1PionNProton_PID_300", "selproton2_costheta_CC1PionNProton_PID_300", 10, -1, 1);
   selproton2_costheta_CCNPionNProton_PID_300= new TH1D("selproton2_costheta_CCNPionNProton_PID_300", "selproton2_costheta_CCNPionNProton_PID_300", 10, -1, 1);
   selproton2_costheta_CCNue_PID_300= new TH1D("selproton2_costheta_CCNue_PID_300", "selproton2_costheta_CCNue_PID_300", 10, -1, 1);   
   selproton2_costheta_NC_PID_300= new TH1D("selproton2_costheta_NC_PID_300", "selproton2_costheta_NC_PID_300", 10, -1, 1);
   selproton2_costheta_OOFV_PID_300= new TH1D("selproton2_costheta_OOFV_PID_300", "selproton2_costheta_OOFV_PID_300", 10, -1, 1);
   selproton2_costheta_EXT_PID_300= new TH1D("selproton2_costheta_EXT_PID_300", "selproton2_costheta_EXT_PID_300", 10, -1, 1);
   selproton2_costheta_other_PID_300= new TH1D("selproton2_costheta_other_PID_300", "selproton2_costheta_other_PID_300", 10, -1, 1); 
   /////
   selproton2_phi_CC0Pion0Proton_PID_300= new TH1D("selproton2_phi_CC0Pion0Proton_PID_300", "selproton2_phi_CC0Pion0Proton_PID_300", 10, -3.14, 3.14);
   selproton2_phi_CC0Pion1Proton_PID_300= new TH1D("selproton2_phi_CC0Pion1Proton_PID_300", "selproton2_phi_CC0Pion1Proton_PID_300", 10, -3.14, 3.14);
   selproton2_phi_CC0Pion2Proton_PID_300= new TH1D("selproton2_phi_CC0Pion2Proton_PID_300", "selproton2_phi_CC0Pion2Proton_PID_300", 10, -3.14, 3.14);
   selproton2_phi_CC0PionNProton_PID_300= new TH1D("selproton2_phi_CC0PionNProton_PID_300", "selproton2_phi_CC0PionNProton_PID_300", 10, -3.14, 3.14);
   selproton2_phi_CC1PionNProton_PID_300= new TH1D("selproton2_phi_CC1PionNProton_PID_300", "selproton2_phi_CC1PionNProton_PID_300", 10, -3.14, 3.14);
   selproton2_phi_CCNPionNProton_PID_300= new TH1D("selproton2_phi_CCNPionNProton_PID_300", "selproton2_phi_CCNPionNProton_PID_300", 10, -3.14, 3.14);
   selproton2_phi_CCNue_PID_300= new TH1D("selproton2_phi_CCNue_PID_300", "selproton2_phi_CCNue_PID_300", 10, -3.14, 3.14);   
   selproton2_phi_NC_PID_300= new TH1D("selproton2_phi_NC_PID_300", "selproton2_phi_NC_PID_300", 10, -3.14, 3.14);
   selproton2_phi_OOFV_PID_300= new TH1D("selproton2_phi_OOFV_PID_300", "selproton2_phi_OOFV_PID_300", 10, -3.14, 3.14);
   selproton2_phi_EXT_PID_300= new TH1D("selproton2_phi_EXT_PID_300", "selproton2_phi_EXT_PID_300", 10, -3.14, 3.14);
   selproton2_phi_other_PID_300= new TH1D("selproton2_phi_other_PID_300", "selproton2_phi_other_PID_300", 10, -3.14, 3.14); 
   //////
   selproton2_mom_CC0Pion0Proton_PID_300= new TH1D("selproton2_mom_CC0Pion0Proton_PID_300", "selproton2_mom_CC0Pion0Proton_PID_300", 10, 0, 1.);
   selproton2_mom_CC0Pion1Proton_PID_300= new TH1D("selproton2_mom_CC0Pion1Proton_PID_300", "selproton2_mom_CC0Pion1Proton_PID_300", 10, 0, 1.);
   selproton2_mom_CC0Pion2Proton_PID_300= new TH1D("selproton2_mom_CC0Pion2Proton_PID_300", "selproton2_mom_CC0Pion2Proton_PID_300", 10, 0, 1.);
   selproton2_mom_CC0PionNProton_PID_300= new TH1D("selproton2_mom_CC0PionNProton_PID_300", "selproton2_mom_CC0PionNProton_PID_300", 10, 0, 1.);
   selproton2_mom_CC1PionNProton_PID_300= new TH1D("selproton2_mom_CC1PionNProton_PID_300", "selproton2_mom_CC1PionNProton_PID_300", 10, 0, 1.);
   selproton2_mom_CCNPionNProton_PID_300= new TH1D("selproton2_mom_CCNPionNProton_PID_300", "selproton2_mom_CCNPionNProton_PID_300", 10, 0, 1.);
   selproton2_mom_CCNue_PID_300= new TH1D("selproton2_mom_CCNue_PID_300", "selproton2_mom_CCNue_PID_300", 10, 0, 1.);   
   selproton2_mom_NC_PID_300= new TH1D("selproton2_mom_NC_PID_300", "selproton2_mom_NC_PID_300", 10, 0, 1.);
   selproton2_mom_OOFV_PID_300= new TH1D("selproton2_mom_OOFV_PID_300", "selproton2_mom_OOFV_PID_300", 10, 0, 1.);
   selproton2_mom_EXT_PID_300= new TH1D("selproton2_mom_EXT_PID_300", "selproton2_mom_EXT_PID_300", 10, 0, 1.);
   selproton2_mom_other_PID_300= new TH1D("selproton2_mom_other_PID_300", "selproton2_mom_other_PID_300", 10, 0, 1.);

   /////

   selproton2_lenght_muon_PID_300= new TH1D("selproton2_lenght_muon_PID_300", "selproton2_lenght_muon_PID_300", 10, 0, 40);
   selproton2_lenght_proton_PID_300= new TH1D("selproton2_lenght_proton_PID_300", "selproton2_lenght_proton_PID_300", 10, 0, 40);
   selproton2_lenght_pion_PID_300= new TH1D("selproton2_lenght_pion_PID_300", "selproton2_lenght_pion_PID_300", 10, 0, 40);
   selproton2_lenght_electron_PID_300= new TH1D("selproton2_lenght_electron_PID_300", "selproton2_lenght_electron_PID_300", 10, 0, 40);
   selproton2_lenght_pother_PID_300= new TH1D("selproton2_lenght_pother_PID_300", "selproton2_lenght_pother_PID_300", 10, 0, 40);
   ////
   selproton2_costheta_muon_PID_300= new TH1D("selproton2_costheta_muon_PID_300", "selproton2_costheta_muon_PID_300", 10, -1, 1);
   selproton2_costheta_proton_PID_300= new TH1D("selproton2_costheta_proton_PID_300", "selproton2_costheta_proton_PID_300", 10, -1, 1);
   selproton2_costheta_pion_PID_300= new TH1D("selproton2_costheta_pion_PID_300", "selproton2_costheta_pion_PID_300", 10, -1, 1);
   selproton2_costheta_electron_PID_300= new TH1D("selproton2_costheta_electron_PID_300", "selproton2_costheta_electron_PID_300", 10, -1, 1);
   selproton2_costheta_pother_PID_300= new TH1D("selproton2_costheta_pother_PID_300", "selproton2_costheta_pother_PID_300", 10, -1, 1);
   ///
   selproton2_phi_muon_PID_300= new TH1D("selproton2_phi_muon_PID_300", "selproton2_phi_muon_PID_300", 10, -3.14, 3.14);
   selproton2_phi_proton_PID_300= new TH1D("selproton2_phi_proton_PID_300", "selproton2_phi_proton_PID_300", 10, -3.14, 3.14);
   selproton2_phi_pion_PID_300= new TH1D("selproton2_phi_pion_PID_300", "selproton2_phi_pion_PID_300", 10, -3.14, 3.14);
   selproton2_phi_electron_PID_300= new TH1D("selproton2_phi_electron_PID_300", "selproton2_phi_electron_PID_300", 10, -3.14, 3.14);
   selproton2_phi_pother_PID_300= new TH1D("selproton2_phi_pother_PID_300", "selproton2_phi_pother_PID_300", 10, -3.14, 3.14);

   selproton2_chi2proton_muon_PID_300= new TH1D("selproton2_chi2proton_muon_PID_300", "selproton2_chi2proton_muon_PID_300", 10, 0, 300);
   selproton2_chi2proton_proton_PID_300= new TH1D("selproton2_chi2proton_proton_PID_300", "selproton2_chi2proton_proton_PID_300", 10, 0, 300);
   selproton2_chi2proton_pion_PID_300= new TH1D("selproton2_chi2proton_pion_PID_300", "selproton2_chi2proton_pion_PID_300", 10, 0, 300);
   selproton2_chi2proton_electron_PID_300= new TH1D("selproton2_chi2proton_electron_PID_300", "selproton2_chi2proton_electron_PID_300", 10, 0, 300);
   selproton2_chi2proton_pother_PID_300= new TH1D("selproton2_chi2proton_pother_PID_300", "selproton2_chi2proton_pother_PID_300", 10, 0, 300);

   selproton2_dEdx_vs_resrange_muon_PID_300 = new TH2D("selproton2_dEdx_vs_resrange_muon_PID_300", "selproton2_dEdx_vs_resrange_muon_PID_300", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_proton_PID_300 = new TH2D("selproton2_dEdx_vs_resrange_proton_PID_300", "selproton2_dEdx_vs_resrange_proton_PID_300", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_pion_PID_300 = new TH2D("selproton2_dEdx_vs_resrange_pion_PID_300", "selproton2_dEdx_vs_resrange_pion_PID_300", 50,0,50,20, 0, 20);

   ///
   selproton_dEdx_PID_MC = new TH1D("selproton_dEdx_PID_MC","selproton_dEdx_PID_MC",100,0,20);

   //// Opening angles
   angle_mup1_CC0Pion0Proton_PID_300= new TH1D("angle_mup1_CC0Pion0Proton_PID_300", "angle_mup1_CC0Pion0Proton_PID_300", 10, -1,1);
   angle_mup1_CC0Pion1Proton_PID_300= new TH1D("angle_mup1_CC0Pion1Proton_PID_300", "angle_mup1_CC0Pion1Proton_PID_300", 10, -1,1);
   angle_mup1_CC0Pion2Proton_PID_300= new TH1D("angle_mup1_CC0Pion2Proton_PID_300", "angle_mup1_CC0Pion2Proton_PID_300", 10, -1,1);
   angle_mup1_CC0PionNProton_PID_300= new TH1D("angle_mup1_CC0PionNProton_PID_300", "angle_mup1_CC0PionNProton_PID_300", 10, -1,1);
   angle_mup1_CC1PionNProton_PID_300= new TH1D("angle_mup1_CC1PionNProton_PID_300", "angle_mup1_CC1PionNProton_PID_300", 10, -1,1);
   angle_mup1_CCNPionNProton_PID_300= new TH1D("angle_mup1_CCNPionNProton_PID_300", "angle_mup1_CCNPionNProton_PID_300", 10, -1,1);
   angle_mup1_CCNue_PID_300= new TH1D("angle_mup1_CCNue_PID_300", "angle_mup1_CCNue_PID_300", 10, -1,1);
   angle_mup1_NC_PID_300= new TH1D("angle_mup1_NC_PID_300", "angle_mup1_NC_PID_300", 10, -1,1);
   angle_mup1_OOFV_PID_300= new TH1D("angle_mup1_OOFV_PID_300", "angle_mup1_OOFV_PID_300", 10, -1,1);
   angle_mup1_EXT_PID_300= new TH1D("angle_mup1_EXT_PID_300", "angle_mup1_EXT_PID_300", 10, -1,1);
   angle_mup1_other_PID_300= new TH1D("angle_mup1_other_PID_300", "angle_mup1_other_PID_300", 10, -1,1);   
 
   angle_mup2_CC0Pion0Proton_PID_300= new TH1D("angle_mup2_CC0Pion0Proton_PID_300", "angle_mup2_CC0Pion0Proton_PID_300", 10, -1,1);
   angle_mup2_CC0Pion1Proton_PID_300= new TH1D("angle_mup2_CC0Pion1Proton_PID_300", "angle_mup2_CC0Pion1Proton_PID_300", 10, -1,1);
   angle_mup2_CC0Pion2Proton_PID_300= new TH1D("angle_mup2_CC0Pion2Proton_PID_300", "angle_mup2_CC0Pion2Proton_PID_300", 10, -1,1);
   angle_mup2_CC0PionNProton_PID_300= new TH1D("angle_mup2_CC0PionNProton_PID_300", "angle_mup2_CC0PionNProton_PID_300", 10, -1,1);
   angle_mup2_CC1PionNProton_PID_300= new TH1D("angle_mup2_CC1PionNProton_PID_300", "angle_mup2_CC1PionNProton_PID_300", 10, -1,1);
   angle_mup2_CCNPionNProton_PID_300= new TH1D("angle_mup2_CCNPionNProton_PID_300", "angle_mup2_CCNPionNProton_PID_300", 10, -1,1);
   angle_mup2_CCNue_PID_300= new TH1D("angle_mup2_CCNue_PID_300", "angle_mup2_CCNue_PID_300", 10, -1,1);
   angle_mup2_NC_PID_300= new TH1D("angle_mup2_NC_PID_300", "angle_mup2_NC_PID_300", 10, -1,1);
   angle_mup2_OOFV_PID_300= new TH1D("angle_mup2_OOFV_PID_300", "angle_mup2_OOFV_PID_300", 10, -1,1);
   angle_mup2_EXT_PID_300= new TH1D("angle_mup2_EXT_PID_300", "angle_mup2_EXT_PID_300", 10, -1,1);
   angle_mup2_other_PID_300= new TH1D("angle_mup2_other_PID_300", "angle_mup2_other_PID_300", 10, -1,1);   
 
   angle_p1p2_CC0Pion0Proton_PID_300= new TH1D("angle_p1p2_CC0Pion0Proton_PID_300", "angle_p1p2_CC0Pion0Proton_PID_300", 10, -1,1);
   angle_p1p2_CC0Pion1Proton_PID_300= new TH1D("angle_p1p2_CC0Pion1Proton_PID_300", "angle_p1p2_CC0Pion1Proton_PID_300", 10, -1,1);
   angle_p1p2_CC0Pion2Proton_PID_300= new TH1D("angle_p1p2_CC0Pion2Proton_PID_300", "angle_p1p2_CC0Pion2Proton_PID_300", 10, -1,1);
   angle_p1p2_CC0PionNProton_PID_300= new TH1D("angle_p1p2_CC0PionNProton_PID_300", "angle_p1p2_CC0PionNProton_PID_300", 10, -1,1);
   angle_p1p2_CC1PionNProton_PID_300= new TH1D("angle_p1p2_CC1PionNProton_PID_300", "angle_p1p2_CC1PionNProton_PID_300", 10, -1,1);
   angle_p1p2_CCNPionNProton_PID_300= new TH1D("angle_p1p2_CCNPionNProton_PID_300", "angle_p1p2_CCNPionNProton_PID_300", 10, -1,1);
   angle_p1p2_CCNue_PID_300= new TH1D("angle_p1p2_CCNue_PID_300", "angle_p1p2_CCNue_PID_300", 10, -1,1);
   angle_p1p2_NC_PID_300= new TH1D("angle_p1p2_NC_PID_300", "angle_p1p2_NC_PID_300", 10, -1,1);
   angle_p1p2_OOFV_PID_300= new TH1D("angle_p1p2_OOFV_PID_300", "angle_p1p2_OOFV_PID_300", 10, -1,1);
   angle_p1p2_EXT_PID_300= new TH1D("angle_p1p2_EXT_PID_300", "angle_p1p2_EXT_PID_300", 10, -1,1);
   angle_p1p2_other_PID_300= new TH1D("angle_p1p2_other_PID_300", "angle_p1p2_other_PID_300", 10, -1,1);   
  
   cosangle_p1p2_CC0Pion0Proton_PID_300= new TH1D("cosangle_p1p2_CC0Pion0Proton_PID_300", "cosangle_p1p2_CC0Pion0Proton_PID_300", 10, -1,1);
   cosangle_p1p2_CC0Pion1Proton_PID_300= new TH1D("cosangle_p1p2_CC0Pion1Proton_PID_300", "cosangle_p1p2_CC0Pion1Proton_PID_300", 10, -1,1);
   cosangle_p1p2_CC0Pion2Proton_PID_300= new TH1D("cosangle_p1p2_CC0Pion2Proton_PID_300", "cosangle_p1p2_CC0Pion2Proton_PID_300", 10, -1,1);
   cosangle_p1p2_CC0PionNProton_PID_300= new TH1D("cosangle_p1p2_CC0PionNProton_PID_300", "cosangle_p1p2_CC0PionNProton_PID_300", 10, -1,1);
   cosangle_p1p2_CC1PionNProton_PID_300= new TH1D("cosangle_p1p2_CC1PionNProton_PID_300", "cosangle_p1p2_CC1PionNProton_PID_300", 10, -1,1);
   cosangle_p1p2_CCNPionNProton_PID_300= new TH1D("cosangle_p1p2_CCNPionNProton_PID_300", "cosangle_p1p2_CCNPionNProton_PID_300", 10, -1,1);
   cosangle_p1p2_CCNue_PID_300= new TH1D("cosangle_p1p2_CCNue_PID_300", "cosangle_p1p2_CCNue_PID_300", 10, -1,1);
   cosangle_p1p2_NC_PID_300= new TH1D("cosangle_p1p2_NC_PID_300", "cosangle_p1p2_NC_PID_300", 10, -1,1);
   cosangle_p1p2_OOFV_PID_300= new TH1D("cosangle_p1p2_OOFV_PID_300", "cosangle_p1p2_OOFV_PID_300", 10, -1,1);
   cosangle_p1p2_EXT_PID_300= new TH1D("cosangle_p1p2_EXT_PID_300", "cosangle_p1p2_EXT_PID_300", 10, -1, 1);
   cosangle_p1p2_other_PID_300= new TH1D("cosangle_p1p2_other_PID_300", "cosangle_p1p2_other_PID_300", 10, -1,1);   
  
   //// resolutions

   selmuon_mom_res_PID_300 = new TH2D("selmuon_mom_res_PID_300", "selmuon_mom_res_PID_300",10, 0, 2, 10,-2,2);
   selmuon_costheta_res_PID_300 = new TH2D("selmuon_costheta_res_PID_300", "selmuon_costheta_res_PID_300", 10, -1, 1,10,-2,2);
   selmuon_phi_res_PID_300 = new TH2D("selmuon_phi_res_PID_300", "selmuon_phi_res_PID_300",10, -3.1415, 3.1415, 10,-6,6);

   selproton1_mom_res_PID_300 = new TH2D("selproton1_mom_res_PID_300", "selproton1_mom_res_PID_300",10, 0, 2, 10,-2,2);
   selproton1_costheta_res_PID_300 = new TH2D("selproton1_costheta_res_PID_300", "selproton1_costheta_res_PID_300",10, -1, 1, 10,-2,2);
   selproton1_phi_res_PID_300 = new TH2D("selproton1_phi_res_PID_300", "selproton1_phi_res_PID_300",10, -3.1415, 3.1415, 10,-6,6);

   selproton2_mom_res_PID_300 = new TH2D("selproton2_mom_res_PID_300", "selproton2_mom_res_PID_300",10, 0, 2, 10,-2,2);
   selproton2_costheta_res_PID_300 = new TH2D("selproton2_costheta_res_PID_300", "selproton2_costheta_res_PID_300",10, -1, 1, 10,-2,2);
   selproton2_phi_res_PID_300 = new TH2D("selproton2_phi_res_PID_300", "selproton2_phi_res_PID_300",10, -3.1415, 3.1415, 10,-6,6);

   //
   /// truth info only
   angle_p1p2_CCQE_PID_300_LF= new TH1D("angle_p1p2_CCQE_PID_300_LF", "angle_p1p2_CCQE_PID_300_LF", 20, -1,1);
   angle_p1p2_CCRes_PID_300_LF= new TH1D("angle_p1p2_CCRes_PID_300_LF", "angle_p1p2_CCRes_PID_300_LF", 20, -1,1);
   angle_p1p2_CCCoh_PID_300_LF= new TH1D("angle_p1p2_CCCoh_PID_300_LF", "angle_p1p2_CCCoh_PID_300_LF", 20, -1,1);
   angle_p1p2_CCDIS_PID_300_LF= new TH1D("angle_p1p2_CCDIS_PID_300_LF", "angle_p1p2_CCDIS_PID_300_LF", 20, -1,1);
   angle_p1p2_CCMEC_PID_300_LF= new TH1D("angle_p1p2_CCMEC_PID_300_LF", "angle_p1p2_CCMEC_PID_300_LF", 20, -1,1);
   angle_p1p2_CCNue_PID_300_LF= new TH1D("angle_p1p2_CCNue_PID_300_LF", "angle_p1p2_CCNue_PID_300_LF", 20, -1,1);
   angle_p1p2_NC_PID_300_LF= new TH1D("angle_p1p2_NC_PID_300_LF", "angle_p1p2_NC_PID_300_LF", 20, -1,1);

   angle_p1p2_CCQE_PID_300_CM= new TH1D("angle_p1p2_CCQE_PID_300_CM", "angle_p1p2_CCQE_PID_300_CM", 20, -1,1);
   angle_p1p2_CCRes_PID_300_CM= new TH1D("angle_p1p2_CCRes_PID_300_CM", "angle_p1p2_CCRes_PID_300_CM", 20, -1,1);
   angle_p1p2_CCCoh_PID_300_CM= new TH1D("angle_p1p2_CCCoh_PID_300_CM", "angle_p1p2_CCCoh_PID_300_CM", 20, -1,1);
   angle_p1p2_CCDIS_PID_300_CM= new TH1D("angle_p1p2_CCDIS_PID_300_CM", "angle_p1p2_CCDIS_PID_300_CM", 20, -1,1);
   angle_p1p2_CCMEC_PID_300_CM= new TH1D("angle_p1p2_CCMEC_PID_300_CM", "angle_p1p2_CCMEC_PID_300_CM", 20, -1,1);
   angle_p1p2_CCNue_PID_300_CM= new TH1D("angle_p1p2_CCNue_PID_300_CM", "angle_p1p2_CCNue_PID_300_CM", 20, -1,1);
   angle_p1p2_NC_PID_300_CM= new TH1D("angle_p1p2_NC_PID_300_CM", "angle_p1p2_NC_PID_300_CM", 20, -1,1);
   
   NP_CCQE_PID_300= new TH1D("NP_CCQE_PID_300", "NP_CCQE_PID_300", 10, 0,10);
   NP_CCRes_PID_300= new TH1D("NP_CCRes_PID_300", "NP_CCRes_PID_300", 10, 0,10);
   NP_CCCoh_PID_300= new TH1D("NP_CCCoh_PID_300", "NP_CCCoh_PID_300", 10, 0,10);
   NP_CCDIS_PID_300= new TH1D("NP_CCDIS_PID_300", "NP_CCDIS_PID_300", 10, 0,10);
   NP_CCMEC_PID_300= new TH1D("NP_CCMEC_PID_300", "NP_CCMEC_PID_300", 10, 0,10);
   NP_CCNue_PID_300= new TH1D("NP_CCNue_PID_300", "NP_CCNue_PID_300", 10, 0,10);
   NP_NC_PID_300= new TH1D("NP_NC_PID_300", "NP_NC_PID_300", 10, 0,10);

   ///// reco ArgoNeuT studies///

   reco_Enu_CCQE_PID_300= new TH1D("reco_Enu_CCQE_PID_300", "reco_Enu_CCQE_PID_300", 10, 0.,2.5);
   reco_Enu_CCRes_PID_300= new TH1D("reco_Enu_CCRes_PID_300", "reco_Enu_CCRes_PID_300", 10, 0.,2.5);
   reco_Enu_CCCoh_PID_300= new TH1D("reco_Enu_CCCoh_PID_300", "reco_Enu_CCCoh_PID_300", 10, 0.,2.5);
   reco_Enu_CCDIS_PID_300= new TH1D("reco_Enu_CCDIS_PID_300", "reco_Enu_CCDIS_PID_300", 10, 0.,2.5);
   reco_Enu_CCMEC_PID_300= new TH1D("reco_Enu_CCMEC_PID_300", "reco_Enu_CCMEC_PID_300", 10, 0.,2.5);
   reco_Enu_CCNue_PID_300= new TH1D("reco_Enu_CCNue_PID_300", "reco_Enu_CCNue_PID_300", 10, 0.,2.5);
   reco_Enu_NC_PID_300= new TH1D("reco_Enu_NC_PID_300", "reco_Enu_NC_PID_300", 10, 0.,2.5);
   reco_Enu_other_PID_300= new TH1D("reco_Enu_other_PID_300", "reco_Enu_other_PID_300", 10, 0.,2.5);

   reco_PT_CCQE_PID_300= new TH1D("reco_PT_CCQE_PID_300", "reco_PT_CCQE_PID_300", 10, 0.,2.);
   reco_PT_CCRes_PID_300= new TH1D("reco_PT_CCRes_PID_300", "reco_PT_CCRes_PID_300", 10, 0.,2.);
   reco_PT_CCCoh_PID_300= new TH1D("reco_PT_CCCoh_PID_300", "reco_PT_CCCoh_PID_300", 10, 0.,2.);
   reco_PT_CCDIS_PID_300= new TH1D("reco_PT_CCDIS_PID_300", "reco_PT_CCDIS_PID_300", 10, 0.,2.);
   reco_PT_CCMEC_PID_300= new TH1D("reco_PT_CCMEC_PID_300", "reco_PT_CCMEC_PID_300", 10, 0.,2.);
   reco_PT_CCNue_PID_300= new TH1D("reco_PT_CCNue_PID_300", "reco_PT_CCNue_PID_300", 10, 0.,2.);
   reco_PT_NC_PID_300= new TH1D("reco_PT_NC_PID_300", "reco_PT_NC_PID_300", 10, 0.,2.);
   reco_PT_other_PID_300= new TH1D("reco_PT_other_PID_300", "reco_PT_other_PID_300", 10, 0.,2.);

   reco_PT_CCQE_1binCM_PID_300= new TH1D("reco_PT_CCQE_1binCM_PID_300", "reco_PT_CCQE_1binCM_PID_300", 10, 0.,2.);
   reco_PT_CCRes_1binCM_PID_300= new TH1D("reco_PT_CCRes_1binCM_PID_300", "reco_PT_CCRes_1binCM_PID_300", 10, 0.,2.);
   reco_PT_CCCoh_1binCM_PID_300= new TH1D("reco_PT_CCCoh_1binCM_PID_300", "reco_PT_CCCoh_1binCM_PID_300", 10, 0.,2.);
   reco_PT_CCDIS_1binCM_PID_300= new TH1D("reco_PT_CCDIS_1binCM_PID_300", "reco_PT_CCDIS_1binCM_PID_300", 10, 0.,2.);
   reco_PT_CCMEC_1binCM_PID_300= new TH1D("reco_PT_CCMEC_1binCM_PID_300", "reco_PT_CCMEC_1binCM_PID_300", 10, 0.,2.);
   reco_PT_CCNue_1binCM_PID_300= new TH1D("reco_PT_CCNue_1binCM_PID_300", "reco_PT_CCNue_1binCM_PID_300", 10, 0.,2.);
   reco_PT_NC_1binCM_PID_300= new TH1D("reco_PT_NC_1binCM_PID_300", "reco_PT_NC_1binCM_PID_300", 10, 0.,2.);
   reco_PT_other_1binCM_PID_300= new TH1D("reco_PT_other_1binCM_PID_300", "reco_PT_other_1binCM_PID_300", 10, 0.,2.);

   reco_p1p2_CCQE_PID_300= new TH1D("reco_p1p2_CCQE_PID_300", "reco_p1p2_CCQE_PID_300", 10, 0.5,2.);
   reco_p1p2_CCRes_PID_300= new TH1D("reco_p1p2_CCRes_PID_300", "reco_p1p2_CCRes_PID_300", 10, 0.5,2.);
   reco_p1p2_CCCoh_PID_300= new TH1D("reco_p1p2_CCCoh_PID_300", "reco_p1p2_CCCoh_PID_300", 10, 0.5,2.);
   reco_p1p2_CCDIS_PID_300= new TH1D("reco_p1p2_CCDIS_PID_300", "reco_p1p2_CCDIS_PID_300", 10, 0.5,2.);
   reco_p1p2_CCMEC_PID_300= new TH1D("reco_p1p2_CCMEC_PID_300", "reco_p1p2_CCMEC_PID_300", 10, 0.5,2.);
   reco_p1p2_CCNue_PID_300= new TH1D("reco_p1p2_CCNue_PID_300", "reco_p1p2_CCNue_PID_300", 10, 0.5,2.);
   reco_p1p2_NC_PID_300= new TH1D("reco_p1p2_NC_PID_300", "reco_p1p2_NC_PID_300", 10, 0.5,2.);
   reco_p1p2_other_PID_300= new TH1D("reco_p1p2_other_PID_300", "reco_p1p2_other_PID_300", 10, 0.5,2.);

   reco_dp1p2_CCQE_PID_300= new TH1D("reco_dp1p2_CCQE_PID_300", "reco_dp1p2_CCQE_PID_300", 10, 0.,1.);
   reco_dp1p2_CCRes_PID_300= new TH1D("reco_dp1p2_CCRes_PID_300", "reco_dp1p2_CCRes_PID_300", 10, 0.,1.);
   reco_dp1p2_CCCoh_PID_300= new TH1D("reco_dp1p2_CCCoh_PID_300", "reco_dp1p2_CCCoh_PID_300", 10, 0.,1.);
   reco_dp1p2_CCDIS_PID_300= new TH1D("reco_dp1p2_CCDIS_PID_300", "reco_dp1p2_CCDIS_PID_300", 10, 0.,1.);
   reco_dp1p2_CCMEC_PID_300= new TH1D("reco_dp1p2_CCMEC_PID_300", "reco_dp1p2_CCMEC_PID_300", 10, 0.,1.);
   reco_dp1p2_CCNue_PID_300= new TH1D("reco_dp1p2_CCNue_PID_300", "reco_dp1p2_CCNue_PID_300", 10, 0.,1.);
   reco_dp1p2_NC_PID_300= new TH1D("reco_dp1p2_NC_PID_300", "reco_dp1p2_NC_PID_300", 10, 0.,1.);
   reco_dp1p2_other_PID_300= new TH1D("reco_dp1p2_other_PID_300", "reco_dp1p2_other_PID_300", 10, 0.,1.);

   reco_kp1p2_CCQE_PID_300= new TH1D("reco_kp1p2_CCQE_PID_300", "reco_kp1p2_CCQE_PID_300", 20, 0.,1.5);
   reco_kp1p2_CCRes_PID_300= new TH1D("reco_kp1p2_CCRes_PID_300", "reco_kp1p2_CCRes_PID_300", 20, 0.,1.5);
   reco_kp1p2_CCCoh_PID_300= new TH1D("reco_kp1p2_CCCoh_PID_300", "reco_kp1p2_CCCoh_PID_300", 20, 0.,1.5);
   reco_kp1p2_CCDIS_PID_300= new TH1D("reco_kp1p2_CCDIS_PID_300", "reco_kp1p2_CCDIS_PID_300", 20, 0.,1.5);
   reco_kp1p2_CCMEC_PID_300= new TH1D("reco_kp1p2_CCMEC_PID_300", "reco_kp1p2_CCMEC_PID_300", 20, 0.,1.5);
   reco_kp1p2_CCNue_PID_300= new TH1D("reco_kp1p2_CCNue_PID_300", "reco_kp1p2_CCNue_PID_300", 20, 0.,1.5);
   reco_kp1p2_NC_PID_300= new TH1D("reco_kp1p2_NC_PID_300", "reco_kp1p2_NC_PID_300", 20, 0.,1.5);
   reco_kp1p2_other_PID_300= new TH1D("reco_kp1p2_other_PID_300", "reco_kp1p2_other_PID_300", 20, 0.,1.5);

   reco_kp1p2_CCQE_PID_300_btb= new TH1D("reco_kp1p2_CCQE_PID_300_btb", "reco_kp1p2_CCQE_PID_300_btb", 20, 0.,1.5);
   reco_kp1p2_CCRes_PID_300_btb= new TH1D("reco_kp1p2_CCRes_PID_300_btb", "reco_kp1p2_CCRes_PID_300_btb", 20, 0.,1.5);
   reco_kp1p2_CCCoh_PID_300_btb= new TH1D("reco_kp1p2_CCCoh_PID_300_btb", "reco_kp1p2_CCCoh_PID_300_btb", 20, 0.,1.5);
   reco_kp1p2_CCDIS_PID_300_btb= new TH1D("reco_kp1p2_CCDIS_PID_300_btb", "reco_kp1p2_CCDIS_PID_300_btb", 20, 0.,1.5);
   reco_kp1p2_CCMEC_PID_300_btb= new TH1D("reco_kp1p2_CCMEC_PID_300_btb", "reco_kp1p2_CCMEC_PID_300_btb", 20, 0.,1.5);
   reco_kp1p2_CCNue_PID_300_btb= new TH1D("reco_kp1p2_CCNue_PID_300_btb", "reco_kp1p2_CCNue_PID_300_btb", 20, 0.,1.5);
   reco_kp1p2_NC_PID_300_btb= new TH1D("reco_kp1p2_NC_PID_300_btb", "reco_kp1p2_NC_PID_300_btb", 20, 0.,1.5);
   reco_kp1p2_other_PID_300_btb= new TH1D("reco_kp1p2_other_PID_300_btb", "reco_kp1p2_other_PID_300_btb", 20, 0.,1.5);

   reco_pn_CCQE_PID_300= new TH1D("reco_pn_CCQE_PID_300", "reco_pn_CCQE_PID_300", 10, 0.,2.);
   reco_pn_CCRes_PID_300= new TH1D("reco_pn_CCRes_PID_300", "reco_pn_CCRes_PID_300", 10, 0.,2.);
   reco_pn_CCCoh_PID_300= new TH1D("reco_pn_CCCoh_PID_300", "reco_pn_CCCoh_PID_300", 10, 0.,2.);
   reco_pn_CCDIS_PID_300= new TH1D("reco_pn_CCDIS_PID_300", "reco_pn_CCDIS_PID_300", 10, 0.,2.);
   reco_pn_CCMEC_PID_300= new TH1D("reco_pn_CCMEC_PID_300", "reco_pn_CCMEC_PID_300", 10, 0.,2.);
   reco_pn_CCNue_PID_300= new TH1D("reco_pn_CCNue_PID_300", "reco_pn_CCNue_PID_300", 10, 0.,2.);
   reco_pn_NC_PID_300= new TH1D("reco_pn_NC_PID_300", "reco_pn_NC_PID_300", 10, 0.,2.);
   reco_pn_other_PID_300= new TH1D("reco_pn_other_PID_300", "reco_pn_other_PID_300", 10, 0.,2.);

   reco_angle_p1p2_CCQE_PID_300_CM= new TH1D("reco_angle_p1p2_CCQE_PID_300_CM", "reco_angle_p1p2_CCQE_PID_300_CM", 10, -1,1);
   reco_angle_p1p2_CCRes_PID_300_CM= new TH1D("reco_angle_p1p2_CCRes_PID_300_CM", "reco_angle_p1p2_CCRes_PID_300_CM", 10, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_CM= new TH1D("reco_angle_p1p2_CCCoh_PID_300_CM", "reco_angle_p1p2_CCCoh_PID_300_CM", 10, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_CM= new TH1D("reco_angle_p1p2_CCDIS_PID_300_CM", "reco_angle_p1p2_CCDIS_PID_300_CM", 10, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_CM= new TH1D("reco_angle_p1p2_CCMEC_PID_300_CM", "reco_angle_p1p2_CCMEC_PID_300_CM", 10, -1,1);
   reco_angle_p1p2_CCNue_PID_300_CM= new TH1D("reco_angle_p1p2_CCNue_PID_300_CM", "reco_angle_p1p2_CCNue_PID_300_CM", 10, -1,1);
   reco_angle_p1p2_NC_PID_300_CM= new TH1D("reco_angle_p1p2_NC_PID_300_CM", "reco_angle_p1p2_NC_PID_300_CM", 10, -1,1);
   reco_angle_p1p2_other_PID_300_CM= new TH1D("reco_angle_p1p2_other_PID_300_CM", "reco_angle_p1p2_other_PID_300_CM", 10, -1,1);

   reco_angle_p1p2_CCQE_PID_300_LF= new TH1D("reco_angle_p1p2_CCQE_PID_300_LF", "reco_angle_p1p2_CCQE_PID_300_LF", 10, -1,1);
   reco_angle_p1p2_CCRes_PID_300_LF= new TH1D("reco_angle_p1p2_CCRes_PID_300_LF", "reco_angle_p1p2_CCRes_PID_300_LF", 10, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_LF= new TH1D("reco_angle_p1p2_CCCoh_PID_300_LF", "reco_angle_p1p2_CCCoh_PID_300_LF", 10, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_LF= new TH1D("reco_angle_p1p2_CCDIS_PID_300_LF", "reco_angle_p1p2_CCDIS_PID_300_LF", 10, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_LF= new TH1D("reco_angle_p1p2_CCMEC_PID_300_LF", "reco_angle_p1p2_CCMEC_PID_300_LF", 10, -1,1);
   reco_angle_p1p2_CCNue_PID_300_LF= new TH1D("reco_angle_p1p2_CCNue_PID_300_LF", "reco_angle_p1p2_CCNue_PID_300_LF", 10, -1,1);
   reco_angle_p1p2_NC_PID_300_LF= new TH1D("reco_angle_p1p2_NC_PID_300_LF", "reco_angle_p1p2_NC_PID_300_LF", 10, -1,1);
   reco_angle_p1p2_other_PID_300_LF= new TH1D("reco_angle_p1p2_other_PID_300_LF", "reco_angle_p1p2_other_PID_300_LF", 10, -1,1);

   /////
   reco_angle_p1p2_CCQE_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_CCQE_PID_300_CM_zoom", "reco_angle_p1p2_CCQE_PID_300_CM_zoom", 20, -1,1);
   reco_angle_p1p2_CCRes_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_CCRes_PID_300_CM_zoom", "reco_angle_p1p2_CCRes_PID_300_CM_zoom", 20, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_CCCoh_PID_300_CM_zoom", "reco_angle_p1p2_CCCoh_PID_300_CM_zoom", 20, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_CCDIS_PID_300_CM_zoom", "reco_angle_p1p2_CCDIS_PID_300_CM_zoom", 20, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_CCMEC_PID_300_CM_zoom", "reco_angle_p1p2_CCMEC_PID_300_CM_zoom", 20, -1,1);
   reco_angle_p1p2_CCNue_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_CCNue_PID_300_CM_zoom", "reco_angle_p1p2_CCNue_PID_300_CM_zoom", 20, -1,1);
   reco_angle_p1p2_NC_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_NC_PID_300_CM_zoom", "reco_angle_p1p2_NC_PID_300_CM_zoom", 20, -1,1);
   reco_angle_p1p2_other_PID_300_CM_zoom= new TH1D("reco_angle_p1p2_other_PID_300_CM_zoom", "reco_angle_p1p2_other_PID_300_CM_zoom", 20, -1,1);

   reco_angle_p1p2_CCQE_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_CCQE_PID_300_LF_zoom", "reco_angle_p1p2_CCQE_PID_300_LF_zoom", 20, -1,1);
   reco_angle_p1p2_CCRes_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_CCRes_PID_300_LF_zoom", "reco_angle_p1p2_CCRes_PID_300_LF_zoom", 20, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_CCCoh_PID_300_LF_zoom", "reco_angle_p1p2_CCCoh_PID_300_LF_zoom", 20, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_CCDIS_PID_300_LF_zoom", "reco_angle_p1p2_CCDIS_PID_300_LF_zoom", 20, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_CCMEC_PID_300_LF_zoom", "reco_angle_p1p2_CCMEC_PID_300_LF_zoom", 20, -1,1);
   reco_angle_p1p2_CCNue_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_CCNue_PID_300_LF_zoom", "reco_angle_p1p2_CCNue_PID_300_LF_zoom", 20, -1,1);
   reco_angle_p1p2_NC_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_NC_PID_300_LF_zoom", "reco_angle_p1p2_NC_PID_300_LF_zoom", 20, -1,1);
   reco_angle_p1p2_other_PID_300_LF_zoom= new TH1D("reco_angle_p1p2_other_PID_300_LF_zoom", "reco_angle_p1p2_other_PID_300_LF_zoom", 20, -1,1);

   ////
   p1p2_PID_300= new TH2D("p1p2_PID_300", "p1p2_PID_300",10,0.,2., 10, 0.,2.);
   reco_angle_p1p2_p2_PID_300_LF= new TH2D("reco_angle_p1p2_p2_PID_300_LF", "reco_angle_p1p2_p2_PID_300_LF",10,0.,2., 10, -1,1.);
   reco_angle_p1p2_PID_300_LF_CM= new TH2D("reco_angle_p1p2_PID_300_LF_CM", "reco_angle_p1p2_PID_300_LF_CM",10,-1.,1., 10, -1,1.);

   //////
   reco_angle_p1p2_p2_PID_300_LF_btb= new TH2D("reco_angle_p1p2_p2_PID_300_LF_btb", "reco_angle_p1p2_p2_PID_300_LF_btb", 10,0.,2., 10, -1,1);

   reco_angle_p1p2_CCQE_PID_300_CM_btb= new TH1D("reco_angle_p1p2_CCQE_PID_300_CM_btb", "reco_angle_p1p2_CCQE_PID_300_CM_btb", 10, -1,1);
   reco_angle_p1p2_CCRes_PID_300_CM_btb= new TH1D("reco_angle_p1p2_CCRes_PID_300_CM_btb", "reco_angle_p1p2_CCRes_PID_300_CM_btb", 10, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_CM_btb= new TH1D("reco_angle_p1p2_CCCoh_PID_300_CM_btb", "reco_angle_p1p2_CCCoh_PID_300_CM_btb", 10, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_CM_btb= new TH1D("reco_angle_p1p2_CCDIS_PID_300_CM_btb", "reco_angle_p1p2_CCDIS_PID_300_CM_btb", 10, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_CM_btb= new TH1D("reco_angle_p1p2_CCMEC_PID_300_CM_btb", "reco_angle_p1p2_CCMEC_PID_300_CM_btb", 10, -1,1);
   reco_angle_p1p2_CCNue_PID_300_CM_btb= new TH1D("reco_angle_p1p2_CCNue_PID_300_CM_btb", "reco_angle_p1p2_CCNue_PID_300_CM_btb", 10, -1,1);
   reco_angle_p1p2_NC_PID_300_CM_btb= new TH1D("reco_angle_p1p2_NC_PID_300_CM_btb", "reco_angle_p1p2_NC_PID_300_CM_btb", 10, -1,1);
   reco_angle_p1p2_other_PID_300_CM_btb= new TH1D("reco_angle_p1p2_other_PID_300_CM_btb", "reco_angle_p1p2_other_PID_300_CM_btb", 10, -1,1);

   reco_angle_p1p2_CCQE_PID_300_LF_btb= new TH1D("reco_angle_p1p2_CCQE_PID_300_LF_btb", "reco_angle_p1p2_CCQE_PID_300_LF_btb", 10, -1,1);
   reco_angle_p1p2_CCRes_PID_300_LF_btb= new TH1D("reco_angle_p1p2_CCRes_PID_300_LF_btb", "reco_angle_p1p2_CCRes_PID_300_LF_btb", 10, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_LF_btb= new TH1D("reco_angle_p1p2_CCCoh_PID_300_LF_btb", "reco_angle_p1p2_CCCoh_PID_300_LF_btb", 10, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_LF_btb= new TH1D("reco_angle_p1p2_CCDIS_PID_300_LF_btb", "reco_angle_p1p2_CCDIS_PID_300_LF_btb", 10, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_LF_btb= new TH1D("reco_angle_p1p2_CCMEC_PID_300_LF_btb", "reco_angle_p1p2_CCMEC_PID_300_LF_btb", 10, -1,1);
   reco_angle_p1p2_CCNue_PID_300_LF_btb= new TH1D("reco_angle_p1p2_CCNue_PID_300_LF_btb", "reco_angle_p1p2_CCNue_PID_300_LF_btb", 10, -1,1);
   reco_angle_p1p2_NC_PID_300_LF_btb= new TH1D("reco_angle_p1p2_NC_PID_300_LF_btb", "reco_angle_p1p2_NC_PID_300_LF_btb", 10, -1,1);
   reco_angle_p1p2_other_PID_300_LF_btb= new TH1D("reco_angle_p1p2_other_PID_300_LF_btb", "reco_angle_p1p2_other_PID_300_LF_btb", 10, -1,1);
   //////

   reco_angle_p1p2_CCQE_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_CCQE_PID_300_CM_btb_zoom", "reco_angle_p1p2_CCQE_PID_300_CM_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCRes_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_CCRes_PID_300_CM_btb_zoom", "reco_angle_p1p2_CCRes_PID_300_CM_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_CCCoh_PID_300_CM_btb_zoom", "reco_angle_p1p2_CCCoh_PID_300_CM_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_CCDIS_PID_300_CM_btb_zoom", "reco_angle_p1p2_CCDIS_PID_300_CM_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_CCMEC_PID_300_CM_btb_zoom", "reco_angle_p1p2_CCMEC_PID_300_CM_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCNue_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_CCNue_PID_300_CM_btb_zoom", "reco_angle_p1p2_CCNue_PID_300_CM_btb_zoom", 20, -1,1);
   reco_angle_p1p2_NC_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_NC_PID_300_CM_btb_zoom", "reco_angle_p1p2_NC_PID_300_CM_btb_zoom", 20, -1,1);
   reco_angle_p1p2_other_PID_300_CM_btb_zoom= new TH1D("reco_angle_p1p2_other_PID_300_CM_btb_zoom", "reco_angle_p1p2_other_PID_300_CM_btb_zoom", 20, -1,1);

   reco_angle_p1p2_CCQE_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_CCQE_PID_300_LF_btb_zoom", "reco_angle_p1p2_CCQE_PID_300_LF_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCRes_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_CCRes_PID_300_LF_btb_zoom", "reco_angle_p1p2_CCRes_PID_300_LF_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCCoh_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_CCCoh_PID_300_LF_btb_zoom", "reco_angle_p1p2_CCCoh_PID_300_LF_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCDIS_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_CCDIS_PID_300_LF_btb_zoom", "reco_angle_p1p2_CCDIS_PID_300_LF_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCMEC_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_CCMEC_PID_300_LF_btb_zoom", "reco_angle_p1p2_CCMEC_PID_300_LF_btb_zoom", 20, -1,1);
   reco_angle_p1p2_CCNue_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_CCNue_PID_300_LF_btb_zoom", "reco_angle_p1p2_CCNue_PID_300_LF_btb_zoom", 20, -1,1);
   reco_angle_p1p2_NC_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_NC_PID_300_LF_btb_zoom", "reco_angle_p1p2_NC_PID_300_LF_btb_zoom", 20, -1,1);
   reco_angle_p1p2_other_PID_300_LF_btb_zoom= new TH1D("reco_angle_p1p2_other_PID_300_LF_btb_zoom", "reco_angle_p1p2_other_PID_300_LF_btb_zoom", 20, -1,1);

   ////////

   reco_angle_SRCrest_p1p2_CCQE_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_CCQE_PID_300_CM", "reco_angle_SRCrest_p1p2_CCQE_PID_300_CM", 20, -1,1);
   reco_angle_SRCrest_p1p2_CCRes_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_CCRes_PID_300_CM", "reco_angle_SRCrest_p1p2_CCRes_PID_300_CM", 20, -1,1);
   reco_angle_SRCrest_p1p2_CCCoh_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_CCCoh_PID_300_CM", "reco_angle_SRCrest_p1p2_CCCoh_PID_300_CM", 20, -1,1);
   reco_angle_SRCrest_p1p2_CCDIS_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_CCDIS_PID_300_CM", "reco_angle_SRCrest_p1p2_CCDIS_PID_300_CM", 20, -1,1);
   reco_angle_SRCrest_p1p2_CCMEC_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_CCMEC_PID_300_CM", "reco_angle_SRCrest_p1p2_CCMEC_PID_300_CM", 20, -1,1);
   reco_angle_SRCrest_p1p2_CCNue_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_CCNue_PID_300_CM", "reco_angle_SRCrest_p1p2_CCNue_PID_300_CM", 20, -1,1);
   reco_angle_SRCrest_p1p2_NC_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_NC_PID_300_CM", "reco_angle_SRCrest_p1p2_NC_PID_300_CM", 20, -1,1);
   reco_angle_SRCrest_p1p2_other_PID_300_CM= new TH1D("reco_angle_SRCrest_p1p2_other_PID_300_CM", "reco_angle_SRCrest_p1p2_other_PID_300_CM", 20, -1,1);

   ///resolution Enu

   res_Enu_PID_300= new TH2D("res_Enu_PID_300", "res_Enu_PID_300",10,0.,2., 10, -2,2.);

   std::cout<<"histos declared"<<endl;
}

Bool_t hanalysis_fMC_PID_300::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);
   //std::cout<<"before process"<<endl;

   int IDTmuon= -1;
   int IDTproton1= -1;
   int IDTproton2= -1;
   bool CC2P =false;
   bool Thadrons =true;
   int num2P =0;
   double tempmomp =-999.;
   double tempmomp2 =-999.;

   ///
   int IDTmuonT= -1;
   int IDTproton1T= -1;
   int IDTproton2T= -1;
   bool ThadronsT =true;
   int num2Ptot =0;

   if(*nu_energy >0.){
     
     if(fhg4parpdg.GetSize()>2){// at least 3 particles from the neutrino, we don't care about neutrons or photons
       for(int nT=0; nT<fhg4parpdg.GetSize(); nT++){
	 if(abs(fhg4parpdg[nT])==211 || abs(fhg4parpdg[nT])==111) Thadrons=false;
	 else if(abs(fhg4parpdg[nT])==13) IDTmuon=nT;
	 else if(fhg4parpdg[nT]==2212){
	   if(fhg4parp[nT]>0.3){
	     num2P++;
	     if(tempmomp<fhg4parp[nT]){
	       IDTproton1=nT;
	       tempmomp=fhg4parp[nT];
	     }
	     if(IDTproton2==-1 || fhg4parp[nT] <tempmomp){
	       IDTproton2=nT;
	       tempmomp2=fhg4parp[nT];
	     }
	   }/// proton momenta>0.3
	 }//protons
       }/// loop on geant4 particle
     }//at least 2 particles

     ////// at least 1 particle
     if(fhg4parpdg.GetSize()>0){// at least 3 particles from the neutrino, we don't care about neutrons or photons
       for(int nT=0; nT<fhg4parpdg.GetSize(); nT++){
	 if(abs(fhg4parpdg[nT])==211 || abs(fhg4parpdg[nT])==111) ThadronsT=false;
	 else if(abs(fhg4parpdg[nT])==13) IDTmuonT=nT;
	 else if(fhg4parpdg[nT]==2212){
	   if(fhg4parp[nT]>0.3){
	     num2Ptot++;
	   }/// proton momenta>0.3
	 }//protons
       }/// loop on geant4 particle
     }//at least 2 particles

   }//enu>0

   if( ThadronsT && IDTmuonT!=-1  && *nu_ccnc==0){
     if(*nu_mode== 0) NP_CCQE_PID_300->Fill(num2Ptot);
     else if(*nu_mode== 1) NP_CCRes_PID_300->Fill(num2Ptot);
     else if(*nu_mode== 3) NP_CCCoh_PID_300->Fill(num2Ptot);
     else if(*nu_mode== 2) NP_CCDIS_PID_300->Fill(num2Ptot);
     else if(*nu_mode== 10) NP_CCMEC_PID_300->Fill(num2Ptot);
     else if(abs(fhg4parpdg[IDTmuonT])==11){/// no se esta rellenando, numu ya esta seleccionado
       NP_CCNue_PID_300->Fill(num2Ptot);
     }
     else NP_NC_PID_300->Fill(num2Ptot);/// no se esta rellenando, numu ya esta seleccionado
   }

   if(num2P==2 && Thadrons && IDTmuon!=-1  && IDTproton1!=-1 && IDTproton2!=-1 && *nu_ccnc==0){
     
     double deltax= fhg4parpx[IDTmuon]+fhg4parpx[IDTproton1]+fhg4parpx[IDTproton2];
     double deltay= fhg4parpy[IDTmuon]+fhg4parpy[IDTproton1]+fhg4parpy[IDTproton2];
     double PTmiss = sqrt(deltax*deltax+deltay*deltay);
     // muon energy
     double  Emuon = sqrt(pow(105.6/1000.,2) + pow(fhg4parp[IDTmuon],2));  ///

   // protons energy
     double Eprotons = sqrt(pow(938.272/1000.,2) + pow(fhg4parp[IDTproton1],2)) + sqrt(pow(938.272/1000.,2) + pow(fhg4parp[IDTproton2],2));
     double Eproton1 = pow(fhg4parp[IDTproton1],2)/(2*938.272/1000.);
     double Eproton2 = pow(fhg4parp[IDTproton2],2)/(2*938.272/1000.);
     
     //double Esum= Emuon + Eprotons;
     double Esum= Emuon + pow(fhg4parp[IDTproton1],2)/(2*938.272/1000.) + pow(fhg4parp[IDTproton2],2)/(2*938.272/1000.);
     double Enuvis = Ecalomiss(Esum, PTmiss, 2)/1000.;
     
	 /// opening angles in Lab frame
      TVector3 P1dirT;
      P1dirT[0] = fhg4parpx[IDTproton1];
      P1dirT[1] = fhg4parpy[IDTproton1];
      P1dirT[2] = fhg4parpz[IDTproton1];

      TVector3 P2dirT;
      P2dirT[0] = fhg4parpx[IDTproton2];
      P2dirT[1] = fhg4parpy[IDTproton2];
      P2dirT[2] = fhg4parpz[IDTproton2];

      TVector3 udirT;
      udirT[0] = fhg4parpx[IDTmuon];
      udirT[1] = fhg4parpy[IDTmuon];
      udirT[2] = fhg4parpz[IDTmuon];

     double norm_P1dirT = sqrt(pow(P1dirT[0],2) + pow(P1dirT[1],2)+ pow(P1dirT[2],2));
     double norm_P2dirT = sqrt(pow(P2dirT[0],2) + pow(P2dirT[1],2)+ pow(P2dirT[2],2));
     double norm_udirT = sqrt(pow(udirT[0],2) + pow(udirT[1],2)+ pow(udirT[2],2));

     float TPlep=fhg4parp[IDTmuon];
     float TPhad1=fhg4parp[IDTproton1];
     float TPhad2=fhg4parp[IDTproton2];

     double TCosAnglep1p2; // scalar product
     if(Enuvis>0) TCosAnglep1p2 = P1dirT.Dot(P2dirT);
     TCosAnglep1p2 =  TCosAnglep1p2/(norm_P1dirT*norm_P2dirT);

     if(abs(TCosAnglep1p2)>1.) std::cout<<"valor fuera de rango......................................................................."<<std::endl;

     double TCosAnglep1p2CM_Tune3 =-999.;
     TVector3 NeuDir;
     NeuDir.SetXYZ(0,0,1);

     double Q3[3];/// this is just Q_3 
     for( int i = 0; i < 3; i++ ) Q3[i] = Enuvis*NeuDir[i] - udirT[i];

     TVector3 Pn;
     for( int i = 0; i < 3; i++ ) Pn[i] = P1dirT[i] - Q3[i]; 

     //     if(Enuvis>0) TCosAnglep1p2CM_Tune3 = P1dirT.Dot(Pn);
     if(Enuvis>0) TCosAnglep1p2CM_Tune3 = P2dirT.Dot(Pn);
     double norm_pndirT = sqrt(pow(Pn[0],2) + pow(Pn[1],2)+ pow(Pn[2],2));

     //     TCosAnglep1p2CM_Tune3 =  TCosAnglep1p2CM_Tune3/(norm_P1dirT*norm_pndirT);
     TCosAnglep1p2CM_Tune3 =  TCosAnglep1p2CM_Tune3/(norm_P2dirT*norm_pndirT);

     for(int ipi = 0; ipi < 3 ;ipi++ ) P1dirT[ipi] = P1dirT[ipi]/norm_P1dirT;
     for(int ipi = 0; ipi < 3 ;ipi++ ) P2dirT[ipi] = P2dirT[ipi]/norm_P2dirT;
     for(int ipi = 0; ipi < 3 ;ipi++ ) udirT[ipi] = udirT[ipi]/norm_udirT;

     
     //  if(Enuvis>0) TCosAnglep1p2CM_Tune3= PPCM_Tune3(TPlep, TPhad1, TPhad2, NeuDir, udirT, P1dirT, P2dirT, Enuvis, Emuon, Eproton1, Eproton2);


     std::cout<<"cos theta CM_Tune3: "<<TCosAnglep1p2CM_Tune3<<"        Lab frame "<< TCosAnglep1p2<<std::endl;

     if(*nu_ccnc==0){
       if(abs(fhg4parpdg[IDTmuon])==13){
	 if(*nu_mode== 0) angle_p1p2_CCQE_PID_300_CM->Fill(TCosAnglep1p2CM_Tune3);
	 else if(*nu_mode== 1) angle_p1p2_CCRes_PID_300_CM->Fill(TCosAnglep1p2CM_Tune3);
	 else if(*nu_mode== 3) angle_p1p2_CCCoh_PID_300_CM->Fill(TCosAnglep1p2CM_Tune3);
	 else if(*nu_mode== 2) angle_p1p2_CCDIS_PID_300_CM->Fill(TCosAnglep1p2CM_Tune3);
	 else if(*nu_mode== 10) angle_p1p2_CCMEC_PID_300_CM->Fill(TCosAnglep1p2CM_Tune3);
       }
       else if(abs(fhg4parpdg[IDTmuon])==11){
	 angle_p1p2_CCNue_PID_300_CM->Fill(TCosAnglep1p2CM_Tune3);
       }
     } ///CC interaction
     else{
       angle_p1p2_NC_PID_300_CM->Fill(TCosAnglep1p2CM_Tune3);
     }
   	      
     //if(abs(fhg4parp[IDTproton1]-fhg4parp[IDTproton2])<0.05){/// difference in momentum <50MeV
       //if(PTmiss >0.3){
   
       //neutrino nucleus 0=Quasi-elastic or Elastic, 1=Resonant (RES), 2=DIS, 3=Coherent production, 10=MEC
	 if(*nu_ccnc==0){
	   if(abs(fhg4parpdg[IDTmuon])==13){
	     if(*nu_mode== 0) angle_p1p2_CCQE_PID_300_LF->Fill(TCosAnglep1p2);
	     else if(*nu_mode== 1) angle_p1p2_CCRes_PID_300_LF->Fill(TCosAnglep1p2);
	     else if(*nu_mode== 3) angle_p1p2_CCCoh_PID_300_LF->Fill(TCosAnglep1p2);
	     else if(*nu_mode== 2) angle_p1p2_CCDIS_PID_300_LF->Fill(TCosAnglep1p2);
	     else if(*nu_mode== 10) angle_p1p2_CCMEC_PID_300_LF->Fill(TCosAnglep1p2);
	   }
	   else if(abs(fhg4parpdg[IDTmuon])==11){
	     angle_p1p2_CCNue_PID_300_LF->Fill(TCosAnglep1p2);
	   }
	 } ///CC interaction
	 else{
	   angle_p1p2_NC_PID_300_LF->Fill(TCosAnglep1p2);
	 }
	 //	  }// PTmiss condition
	 // }/// p1 ~ -p2
   } /// CC2P

   ////
   if(track_pfp_Id.GetSize()<1) std::cout<<"Oooops, there are less than 1 tracks"<<std::endl;

   ///scpecific cuts////
   if(track_pfp_Id.GetSize()==3){/// PID requirement
   
     double trklength_temp=0;
     double trklength_temp2=0;
     double trklength_temp3=0;
     int muind=-1;
     int p1ind=-1;
     int p2ind=-1;
     bool muoninFV = true;

     bool trackfromneutrino=true;// by default from neutrino interation
     for(int ncand=0; ncand<pfp_origin.GetSize(); ncand++){
       if(pfp_origin[ncand] !=1) trackfromneutrino=false;
     }/// check if all pfp true associated particles are from neutrino, otherwise is a cosmic
     
     for(int allp=0; allp< track_pfp_Id.GetSize(); ++allp){
       if(track_pfp_length[allp]>trklength_temp){
	 muind=allp;
	 trklength_temp=track_pfp_length[allp];
       }
     }
     bool tempflag=true;
     bool minColl = true;
     if(muind>-1 && !inFV(*_nuvtxx_reco, *_nuvtxy_reco,*_nuvtxx_reco)) muoninFV=false;
     ///loop over all the proton candidates
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       if (!*pfp_upinFVflag) tempflag=false;
       //if(!inFV(track_pfp_startx[np], track_pfp_starty[np], track_pfp_startz[np]) || !inFV(track_pfp_endx[np], track_pfp_endy[np], track_pfp_endz[np])) {tempflag=false;};
       if(tempflag==false) continue;
       if(track_pfp_length[np]>trklength_temp2) {
	 p1ind=np;
	 trklength_temp2=track_pfp_length[np];
       }
     }

     ////loop over all the proton candidates
   
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       if(p1ind==np) continue;
       if(tempflag==false) continue;
       if(track_pfp_length[np]>trklength_temp3) {
	 p2ind=np;
	 trklength_temp3=track_pfp_length[np];
       }
     } //end of loop over proton candidates //second proton selected   

     /// check topology (look at true particles associated and proton momenta)
     int numMuon =0;
     int numPion =0;
     int numPi0 = 0;
     int numEle = 0;
     int numProton = 0;
     int cosmicflag= 0;
     if(pfp_parId.GetSize()>0){
       for(int nt =0; nt<pfp_parId.GetSize(); nt++){
	 if(pfp_status[nt]!=1) continue;
	 if(*nu_ccnc!=0)continue;
	 if(abs(pfp_pdg[nt])==13) numMuon++;
	 if(abs(pfp_pdg[nt])==211) numPion++;
	 if(abs(pfp_pdg[nt])==111) numPi0++;
	 if(abs(pfp_pdg[nt])==11) numPi0++;
	 if(abs(pfp_pdg[nt])==2212 &&  pfp_mom[nt]>0.3) numProton++;
       }
     }
     else cosmicflag= 1;
   
     if(!trackfromneutrino) cosmicflag= 1;
     
     Int_t TopFlag=Topology(numMuon, numEle , numPion, numPi0, numProton, cosmicflag, *OOFVflag);
     //truthtop=TopFlag;

     //if(muind !=-1 &&p1ind !=-1 && p2ind !=-1 && muoninFV && tempflag){/// requirements
     if(muind !=-1 &&p1ind !=-1 && p2ind !=-1 && tempflag){/// requirements
       if(track_pfp_dEdx[muind].size()<5 ||track_pfp_dEdx[p1ind].size()<5 ||track_pfp_dEdx[p2ind].size()<5)  minColl=false;/// min coll hits
       if(minColl){
       if(track_pfp_chi2_proton[muind]>88. && track_pfp_chi2_proton[p1ind]<88. &&track_pfp_chi2_proton[p2ind]<88.){

       totentries++;

       std::cout<<"hola "<<std::endl;
       if(pfp_pdg[p1ind] ==2212){
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton_dEdx_PID_MC->Fill(track_pfp_dEdx[p1ind][i]);
	 }
       }
       if(pfp_pdg[p2ind] ==2212){
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton_dEdx_PID_MC->Fill(track_pfp_dEdx[p2ind][i]);
	 }
       }

       /// opening angles

       float fPlep=*track_pfp_mom_mucand;
       float fPhad1=track_pfp_Mom_p[p1ind];
       float fPhad2=track_pfp_Mom_p[p2ind];
       float fThetaLep=track_pfp_theta[muind];
       float fThetaHad1=track_pfp_theta[p1ind];
       float fThetaHad2=track_pfp_theta[p2ind];
       float fPhiLep=track_pfp_phi[muind];
       float fPhiHad1=track_pfp_phi[p1ind];
       float fPhiHad2=track_pfp_phi[p2ind];
       TVector3 muonP(fPlep*(TMath::Sin(fThetaLep))*(TMath::Cos(fPhiLep)), fPlep*(TMath::Sin(fThetaLep))*(TMath::Sin(fPhiLep)), fPlep*(TMath::Cos(fThetaLep)));
       TVector3 protonP1(fPhad1*(TMath::Sin(fThetaHad1))*(TMath::Cos(fPhiHad1)), fPhad1*(TMath::Sin(fThetaHad1))*(TMath::Sin(fPhiHad1)), fPhad1*(TMath::Cos(fThetaHad1)));
       TVector3 protonP2(fPhad2*(TMath::Sin(fThetaHad2))*(TMath::Cos(fPhiHad2)), fPhad2*(TMath::Sin(fThetaHad2))*(TMath::Sin(fPhiHad2)), fPhad2*(TMath::Cos(fThetaHad2)));

       TVector3 trackpdir_mu;
       TVector3 trackpdir_p1;
       TVector3 trackpdir_p2;
       /*
       trackpdir_mu.SetXYZ(TMath::Cos(fPhiLep),TMath::Sqrt(1-pow(TMath::Cos(fPhiLep),2)- pow(TMath::Cos(fThetaLep),2)), TMath::Cos(fThetaLep));
       trackpdir_p1.SetXYZ(TMath::Cos(fPhiHad1),TMath::Sqrt(1-pow(TMath::Cos(fPhiHad1),2)- pow(TMath::Cos(fThetaHad1),2)), TMath::Cos(fThetaHad1));
       trackpdir_p2.SetXYZ(TMath::Cos(fPhiHad2),TMath::Sqrt(1-pow(TMath::Cos(fPhiHad2),2)- pow(TMath::Cos(fThetaHad2),2)), TMath::Cos(fThetaHad2));
       */
       trackpdir_mu.SetXYZ(TMath::Sin(track_pfp_theta[muind])*TMath::Cos(track_pfp_phi[muind]),TMath::Sin(track_pfp_phi[muind])*TMath::Sin(track_pfp_theta[muind]),track_pfp_costheta[muind]);
       trackpdir_p1.SetXYZ(TMath::Sin(track_pfp_theta[p1ind])*TMath::Cos(track_pfp_phi[p1ind]),TMath::Sin(track_pfp_phi[p1ind])*TMath::Sin(track_pfp_theta[p1ind]),track_pfp_costheta[p1ind]);
       trackpdir_p2.SetXYZ(TMath::Sin(track_pfp_theta[p2ind])*TMath::Cos(track_pfp_phi[p2ind]),TMath::Sin(track_pfp_phi[p2ind])*TMath::Sin(track_pfp_theta[p2ind]),track_pfp_costheta[p2ind]);
   
       Double_t m1 = trackpdir_p1.Mag();
       Double_t m2 = trackpdir_p2.Mag();
       Double_t mu = trackpdir_mu.Mag();

       // std::cout<<"norm p1: "<<m1<<" norm p2: "<<m2<<" norm mu: "<<mu<<std::endl;
 
       double CosAnglep1p2 = trackpdir_p1.Dot(trackpdir_p2);   // scalar product
       CosAnglep1p2 =  CosAnglep1p2/(m1*m2);

       double CosAnglemup1 = trackpdir_mu.Dot(trackpdir_p1);   // scalar product
       CosAnglemup1 =  CosAnglemup1/(mu*m1);

       double CosAnglemup2 = trackpdir_mu.Dot(trackpdir_p2);   // scalar product
       CosAnglemup2 =  CosAnglemup2/(mu*m2);

       double anglemup1=CosAnglemup1;
       double anglemup2=CosAnglemup2;
       double anglep1p2=CosAnglep1p2;/// LF angle

       ///// reco Enu & PT
       double reco_deltax= muonP.X()+protonP1.X()+protonP2.X();
       double reco_deltay= muonP.Y()+protonP1.Y()+protonP2.Y();
       double reco_PTmiss = sqrt(reco_deltax*reco_deltax + reco_deltay*reco_deltay);
       // muon energy
       double  reco_Emuon = sqrt(pow(105.6/1000.,2) + pow(fPlep,2));

       // protons energy
       double reco_Eprotons = sqrt(pow(938.272/1000.,2) + pow(fPhad1,2)) + sqrt(pow(938.272/1000.,2) + pow(fPhad2,2));
       double reco_Eproton1 = pow(fPhad1,2)/(2*938.272/1000.);
       double reco_Eproton2 = pow(fPhad2,2)/(2*938.272/1000.);
     
       //double Esum= Emuon + Eprotons;
       double reco_Esum= reco_Emuon + pow(fPhad1,2)/(2*938.272/1000.) + pow(fPhad2,2)/(2*938.272/1000.);
       double reco_Enuvis = Ecalomiss(reco_Esum, reco_PTmiss, 2)/1000.;
     
       /////
       double reco_CosAnglep1p2CM =-999.;
       TVector3 reco_NeuDir;
       reco_NeuDir.SetXYZ(0,0,1);

       double reco_Q3[3];/// this is Q_3 
       for( int i = 0; i < 3; i++ ) reco_Q3[i] = reco_Enuvis*reco_NeuDir[i] - muonP[i];

       TVector3 reco_Pn;
       for( int i = 0; i < 3; i++) reco_Pn[i] = protonP1[i] - reco_Q3[i]; 

       if(reco_Enuvis>0) reco_CosAnglep1p2CM = protonP2.Dot(reco_Pn);
       double norm_recopndirT = sqrt(pow(reco_Pn[0],2) + pow(reco_Pn[1],2)+ pow(reco_Pn[2],2));
       double norm_recop2dirT = sqrt(pow(protonP2[0],2) + pow(protonP2[1],2)+ pow(protonP2[2],2));

       reco_CosAnglep1p2CM =  reco_CosAnglep1p2CM/(norm_recop2dirT*norm_recopndirT);

       ////
       selmuon_mom_res_PID_300->Fill(pfp_mom[muind],pfp_mom[muind]-track_pfp_Mom_p[muind]);
       selmuon_costheta_res_PID_300->Fill( pfp_costheta[muind],pfp_costheta[muind]-track_pfp_costheta[muind]);
       selmuon_phi_res_PID_300->Fill(pfp_phi[muind],pfp_phi[muind]-track_pfp_phi[muind]);

       selproton1_mom_res_PID_300->Fill(pfp_mom[p1ind],pfp_mom[p1ind]-track_pfp_Mom_p[p1ind]);
       selproton1_costheta_res_PID_300->Fill(pfp_costheta[p1ind],pfp_costheta[p1ind]-track_pfp_costheta[p1ind]);
       selproton1_phi_res_PID_300->Fill(pfp_phi[p1ind],pfp_phi[p1ind]-track_pfp_phi[p1ind]);

       selproton2_mom_res_PID_300->Fill(pfp_mom[p2ind],pfp_mom[p2ind]-track_pfp_Mom_p[p2ind]);
       selproton2_costheta_res_PID_300->Fill(pfp_costheta[p2ind],pfp_costheta[p2ind]-track_pfp_costheta[p2ind]);
       selproton2_phi_res_PID_300->Fill(pfp_phi[p2ind],pfp_phi[p2ind]-track_pfp_phi[p2ind]);

       if(TopFlag ==1 && trackfromneutrino){
	 topo1++;
	 selmuon_lenght_CC0Pion0Proton_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion0Proton_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion0Proton_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion0Proton_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion0Proton_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion0Proton_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion0Proton_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion0Proton_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion0Proton_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion0Proton_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0Pion0Proton_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0Pion0Proton_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0Pion0Proton_PID_300->Fill(anglemup1);
	 angle_mup2_CC0Pion0Proton_PID_300->Fill(anglemup2);
	 angle_p1p2_CC0Pion0Proton_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_CC0Pion0Proton_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo1

       else if(TopFlag ==2 && trackfromneutrino){
	 topo2++;
	 selmuon_lenght_CC0Pion1Proton_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion1Proton_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion1Proton_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion1Proton_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion1Proton_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion1Proton_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion1Proton_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion1Proton_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion1Proton_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion1Proton_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0Pion1Proton_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0Pion1Proton_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0Pion1Proton_PID_300->Fill(anglemup1);
	 angle_mup2_CC0Pion1Proton_PID_300->Fill(anglemup2);
	 angle_p1p2_CC0Pion1Proton_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_CC0Pion1Proton_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo2

       else if(TopFlag ==3 && trackfromneutrino){
	 topo3++;
	 selmuon_lenght_CC0Pion2Proton_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion2Proton_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion2Proton_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion2Proton_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion2Proton_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion2Proton_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion2Proton_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion2Proton_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion2Proton_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion2Proton_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0Pion2Proton_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0Pion2Proton_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0Pion2Proton_PID_300->Fill(anglemup1);
	 angle_mup2_CC0Pion2Proton_PID_300->Fill(anglemup2);
	 angle_p1p2_CC0Pion2Proton_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_CC0Pion2Proton_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo3

       else if(TopFlag ==4 && trackfromneutrino){
	 topo4++;
	 selmuon_lenght_CC0PionNProton_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0PionNProton_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0PionNProton_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0PionNProton_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0PionNProton_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0PionNProton_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0PionNProton_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0PionNProton_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0PionNProton_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0PionNProton_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0PionNProton_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0PionNProton_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0PionNProton_PID_300->Fill(anglemup1);
	 angle_mup2_CC0PionNProton_PID_300->Fill(anglemup2);
	 angle_p1p2_CC0PionNProton_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_CC0PionNProton_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo4

       else if(TopFlag ==5 && trackfromneutrino){
	 topo5++;
	 selmuon_lenght_CC1PionNProton_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC1PionNProton_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC1PionNProton_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC1PionNProton_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC1PionNProton_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC1PionNProton_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC1PionNProton_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC1PionNProton_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC1PionNProton_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC1PionNProton_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC1PionNProton_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC1PionNProton_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC1PionNProton_PID_300->Fill(anglemup1);
	 angle_mup2_CC1PionNProton_PID_300->Fill(anglemup2);
	 angle_p1p2_CC1PionNProton_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_CC1PionNProton_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo5

       else if(TopFlag ==6 && trackfromneutrino){
	 topo6++;
	 selmuon_lenght_CCNPionNProton_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNPionNProton_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNPionNProton_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNPionNProton_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNPionNProton_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNPionNProton_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNPionNProton_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNPionNProton_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNPionNProton_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNPionNProton_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CCNPionNProton_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CCNPionNProton_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CCNPionNProton_PID_300->Fill(anglemup1);
	 angle_mup2_CCNPionNProton_PID_300->Fill(anglemup2);
	 angle_p1p2_CCNPionNProton_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_CCNPionNProton_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo6

       else if(TopFlag ==7 && trackfromneutrino){
	 topo7++;
	 selmuon_lenght_CCNue_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNue_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNue_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNue_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNue_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNue_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNue_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNue_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNue_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNue_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CCNue_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CCNue_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CCNue_PID_300->Fill(anglemup1);
	 angle_mup2_CCNue_PID_300->Fill(anglemup2);
	 angle_p1p2_CCNue_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_CCNue_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo7

       else if(TopFlag ==8 && trackfromneutrino){
	 topo8++;
	 selmuon_lenght_NC_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_NC_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_NC_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_NC_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_NC_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_NC_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_NC_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_NC_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_NC_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_NC_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_NC_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_NC_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_NC_PID_300->Fill(anglemup1);
	 angle_mup2_NC_PID_300->Fill(anglemup2);
	 angle_p1p2_NC_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_NC_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo8
       
       //else if(trackfromneutrino==1 && *OOFVflag==1){
       //else if(TopFlag ==9){
	 else if(*OOFVflag==1){
	 topo9++;
	 selmuon_lenght_OOFV_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_OOFV_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_OOFV_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_OOFV_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_OOFV_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_OOFV_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_OOFV_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_OOFV_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_OOFV_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_OOFV_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_OOFV_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_OOFV_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_OOFV_PID_300->Fill(anglemup1);
	 angle_mup2_OOFV_PID_300->Fill(anglemup2);
	 angle_p1p2_OOFV_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_OOFV_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo9

       else if(!trackfromneutrino){
	 topo10++;
	 selmuon_lenght_EXT_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_EXT_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_EXT_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_EXT_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_EXT_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_EXT_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_EXT_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_EXT_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_EXT_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_EXT_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_EXT_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_EXT_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_EXT_PID_300->Fill(anglemup1);
	 angle_mup2_EXT_PID_300->Fill(anglemup2);
	 angle_p1p2_EXT_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_EXT_PID_300->Fill(TMath::Cos(anglep1p2));
       }// topo9

       else{
	 topo11++;
	 selmuon_lenght_other_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_other_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_other_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_other_PID_300->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_other_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_other_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_other_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_other_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_other_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_other_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_other_PID_300->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_other_PID_300->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_other_PID_300->Fill(anglemup1);
	 angle_mup2_other_PID_300->Fill(anglemup2);
	 angle_p1p2_other_PID_300->Fill(anglep1p2);
	 cosangle_p1p2_other_PID_300->Fill(TMath::Cos(anglep1p2));
       }//else

       //outfileMC_PID_300<<"p1 "<<track_pfp_Mom_p[p1ind]<<std::endl;
       //if(track_pfp_Mom_p[p1ind]>0.3) outfileMC_PID_300<<"p1> 300. "<<std::endl;
       //if(track_pfp_Mom_p[p2ind]>0.3) outfileMC_PID_300<<"p2> 300. "<<std::endl;
       //if(track_pfp_Mom_p[p1ind]>0.3 && track_pfp_Mom_p[p2ind]>0.3) outfileMC_PID_300<<"p1p2> 300. "<<std::endl;
       
       ///////// plots by rection type for *ArgoNeut* studies///// 
       if(track_pfp_Mom_p[p1ind]>0.3 && track_pfp_Mom_p[p2ind]>0.3){ /// require proton momenta>300 MeV

	 num300++;

	 p1p2_PID_300->Fill(track_pfp_Mom_p[p1ind],track_pfp_Mom_p[p2ind]);
	 reco_angle_p1p2_p2_PID_300_LF->Fill(track_pfp_Mom_p[p2ind],anglep1p2);
	 reco_angle_p1p2_PID_300_LF_CM->Fill(anglep1p2,reco_CosAnglep1p2CM);

	 /// resolution in reco energy
	 res_Enu_PID_300->Fill(*nu_energy,*nu_energy - reco_Enuvis);

	 double res_Enu = abs((*nu_energy - reco_Enuvis)/ (*nu_energy));
	 if(res_Enu>0.1) outfileMC_PID_300<<"Enu resolution > 0.1 interaction "<<*nu_ccnc<<" "<<*nu_mode<<" resolution "<<res_Enu<<std::endl;
	 
	 double kp1p2 = ((track_pfp_Mom_p[p1ind]*track_pfp_Mom_p[p1ind])+(track_pfp_Mom_p[p2ind]*track_pfp_Mom_p[p2ind]))/(2*0.938272);

	 if(trackfromneutrino){
	   if(*nu_ccnc==0){/// CC interaction
	     if(*nu_mode== 0) { //CCQE
	       reco_Enu_CCQE_PID_300->Fill(reco_Enuvis);
	       reco_PT_CCQE_PID_300->Fill(reco_PTmiss);
	       reco_pn_CCQE_PID_300->Fill(norm_recopndirT);
	       reco_angle_p1p2_CCQE_PID_300_LF->Fill(anglep1p2);
	       reco_angle_p1p2_CCQE_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       reco_angle_p1p2_CCQE_PID_300_LF_zoom->Fill(anglep1p2);
	       reco_angle_p1p2_CCQE_PID_300_CM_zoom->Fill(reco_CosAnglep1p2CM);
	       reco_p1p2_CCQE_PID_300->Fill(track_pfp_Mom_p[p1ind]+track_pfp_Mom_p[p2ind]);
	       reco_dp1p2_CCQE_PID_300->Fill(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind]);
	       reco_kp1p2_CCQE_PID_300->Fill(kp1p2);
	       if(reco_CosAnglep1p2CM < -0.9){
		 reco_PT_CCQE_1binCM_PID_300->Fill(reco_PTmiss);
	       }
	       if(anglep1p2<-0.8){
		 reco_kp1p2_CCQE_PID_300_btb->Fill(kp1p2);
	       }
	       //// back-to-back in CM

	       if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.05){
		 reco_angle_SRCrest_p1p2_CCQE_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       }
	     }
	     else if(*nu_mode== 1) {
	       reco_Enu_CCRes_PID_300->Fill(reco_Enuvis);
	       reco_PT_CCRes_PID_300->Fill(reco_PTmiss);
	       reco_pn_CCRes_PID_300->Fill(norm_recopndirT);
	       reco_angle_p1p2_CCRes_PID_300_LF->Fill(anglep1p2);
	       reco_angle_p1p2_CCRes_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       reco_angle_p1p2_CCRes_PID_300_LF_zoom->Fill(anglep1p2);
	       reco_angle_p1p2_CCRes_PID_300_CM_zoom->Fill(reco_CosAnglep1p2CM);
	       reco_p1p2_CCRes_PID_300->Fill(track_pfp_Mom_p[p1ind]+track_pfp_Mom_p[p2ind]);
	       reco_dp1p2_CCRes_PID_300->Fill(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind]);
	       reco_kp1p2_CCRes_PID_300->Fill(kp1p2);
	       if(reco_CosAnglep1p2CM < -0.9){
		 reco_PT_CCRes_1binCM_PID_300->Fill(reco_PTmiss);
	       }
	       if(anglep1p2<-0.8){
		 reco_kp1p2_CCRes_PID_300_btb->Fill(kp1p2);
	       }
	       if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.05){
		 reco_angle_SRCrest_p1p2_CCRes_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       }
	     }
	   else if(*nu_mode== 3) {
	     reco_Enu_CCCoh_PID_300->Fill(reco_Enuvis);
	     reco_PT_CCCoh_PID_300->Fill(reco_PTmiss);
	     reco_pn_CCCoh_PID_300->Fill(norm_recopndirT);
	     reco_angle_p1p2_CCCoh_PID_300_LF->Fill(anglep1p2);
	     reco_angle_p1p2_CCCoh_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	     reco_angle_p1p2_CCCoh_PID_300_LF_zoom->Fill(anglep1p2);
	     reco_angle_p1p2_CCCoh_PID_300_CM_zoom->Fill(reco_CosAnglep1p2CM);
	     reco_p1p2_CCCoh_PID_300->Fill(track_pfp_Mom_p[p1ind]+track_pfp_Mom_p[p2ind]);
	     reco_dp1p2_CCCoh_PID_300->Fill(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind]);
	     reco_kp1p2_CCCoh_PID_300->Fill(kp1p2);
	       if(reco_CosAnglep1p2CM < -0.9){
		 reco_PT_CCCoh_1binCM_PID_300->Fill(reco_PTmiss);
	       }
	       if(anglep1p2<-0.8){
		 reco_kp1p2_CCCoh_PID_300_btb->Fill(kp1p2);
	       }
	       if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.05){
		 reco_angle_SRCrest_p1p2_CCCoh_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       }
	   }
	   else if(*nu_mode== 2) {
	     reco_Enu_CCDIS_PID_300->Fill(reco_Enuvis);
	     reco_PT_CCDIS_PID_300->Fill(reco_PTmiss);
	     reco_pn_CCDIS_PID_300->Fill(norm_recopndirT);
	     reco_angle_p1p2_CCDIS_PID_300_LF->Fill(anglep1p2);
	     reco_angle_p1p2_CCDIS_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	     reco_angle_p1p2_CCDIS_PID_300_LF_zoom->Fill(anglep1p2);
	     reco_angle_p1p2_CCDIS_PID_300_CM_zoom->Fill(reco_CosAnglep1p2CM);
	     reco_p1p2_CCDIS_PID_300->Fill(track_pfp_Mom_p[p1ind]+track_pfp_Mom_p[p2ind]);
	     reco_dp1p2_CCDIS_PID_300->Fill(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind]);
	     reco_kp1p2_CCDIS_PID_300->Fill(kp1p2);
	       if(reco_CosAnglep1p2CM < -0.9){
		 reco_PT_CCDIS_1binCM_PID_300->Fill(reco_PTmiss);
	       }
	       if(anglep1p2<-0.8){
		 reco_kp1p2_CCDIS_PID_300_btb->Fill(kp1p2);
	       }
	       if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.05){
		 reco_angle_SRCrest_p1p2_CCDIS_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       }
	   }
	   else if(*nu_mode== 10) {
	     reco_Enu_CCMEC_PID_300->Fill(reco_Enuvis);
	     reco_PT_CCMEC_PID_300->Fill(reco_PTmiss);
	     reco_pn_CCMEC_PID_300->Fill(norm_recopndirT);
	     reco_angle_p1p2_CCMEC_PID_300_LF->Fill(anglep1p2);
	     reco_angle_p1p2_CCMEC_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	     reco_angle_p1p2_CCMEC_PID_300_LF_zoom->Fill(anglep1p2);
	     reco_angle_p1p2_CCMEC_PID_300_CM_zoom->Fill(reco_CosAnglep1p2CM);
	     reco_p1p2_CCMEC_PID_300->Fill(track_pfp_Mom_p[p1ind]+track_pfp_Mom_p[p2ind]);
	     reco_dp1p2_CCMEC_PID_300->Fill(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind]);
	     reco_kp1p2_CCMEC_PID_300->Fill(kp1p2);
	       if(reco_CosAnglep1p2CM < -0.9){
		 reco_PT_CCMEC_1binCM_PID_300->Fill(reco_PTmiss);
	       }
	       if(anglep1p2<-0.8){
		 reco_kp1p2_CCMEC_PID_300_btb->Fill(kp1p2);
	       }
	       if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.05){
		 reco_angle_SRCrest_p1p2_CCMEC_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       }
	   }
	   	 
	   else if(abs(fhg4parpdg[IDTmuon])==11){/// ? hacerlo de otra manera...
	     reco_Enu_CCNue_PID_300->Fill(reco_Enuvis);
	     reco_PT_CCNue_PID_300->Fill(reco_PTmiss);
	     reco_pn_CCNue_PID_300->Fill(norm_recopndirT);
	     reco_angle_p1p2_CCNue_PID_300_LF->Fill(anglep1p2);
	     reco_angle_p1p2_CCNue_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	     reco_angle_p1p2_CCNue_PID_300_LF_zoom->Fill(anglep1p2);
	     reco_angle_p1p2_CCNue_PID_300_CM_zoom->Fill(reco_CosAnglep1p2CM);
	     reco_p1p2_CCNue_PID_300->Fill(track_pfp_Mom_p[p1ind]+track_pfp_Mom_p[p2ind]);
	     reco_dp1p2_CCNue_PID_300->Fill(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind]);
	     reco_kp1p2_CCNue_PID_300->Fill(kp1p2);
	       if(reco_CosAnglep1p2CM < -0.9){
		 reco_PT_CCNue_1binCM_PID_300->Fill(reco_PTmiss);
	       }
	       if(anglep1p2<-0.8){
		 reco_kp1p2_CCNue_PID_300_btb->Fill(kp1p2);
	       }
	       if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.05){
		 reco_angle_SRCrest_p1p2_CCNue_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       }
	   }
	   
	   } ///CC interaction
	   else{
	     reco_Enu_NC_PID_300->Fill(reco_Enuvis);
	     reco_PT_NC_PID_300->Fill(reco_PTmiss);
	     reco_pn_NC_PID_300->Fill(norm_recopndirT);
	     reco_angle_p1p2_NC_PID_300_LF->Fill(anglep1p2);
	     reco_angle_p1p2_NC_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	     reco_angle_p1p2_NC_PID_300_LF_zoom->Fill(anglep1p2);
	     reco_angle_p1p2_NC_PID_300_CM_zoom->Fill(reco_CosAnglep1p2CM);
	     reco_p1p2_NC_PID_300->Fill(track_pfp_Mom_p[p1ind]+track_pfp_Mom_p[p2ind]);
	     reco_dp1p2_NC_PID_300->Fill(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind]);
	     reco_kp1p2_NC_PID_300->Fill(kp1p2);
	       if(reco_CosAnglep1p2CM < -0.9){
		 reco_PT_NC_1binCM_PID_300->Fill(reco_PTmiss);
	       }
	       if(anglep1p2<-0.8){
		 reco_kp1p2_NC_PID_300_btb->Fill(kp1p2);
	       }
	       if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.05){
		 reco_angle_SRCrest_p1p2_NC_PID_300_CM->Fill(reco_CosAnglep1p2CM);
	       }
	   }
	 	   
	 }/// trackfromneutrino
	 ///// p1 ~ -p2 (para LF plots)
	 bool p1p2delta =false;
	 /////exclude back-to-back(LF) from CM
	 if(abs(track_pfp_Mom_p[p1ind]-track_pfp_Mom_p[p2ind])<0.05){/// hacer tag a los q son back-to-back para excluir luego
	   numpairs++;
	   if(anglep1p2 < -0.8) p1p2delta =true;

	   reco_angle_p1p2_p2_PID_300_LF_btb->Fill(track_pfp_Mom_p[p2ind],anglep1p2);

	   if(trackfromneutrino){
	     if(*nu_ccnc==0){/// CC interaction
	       if(*nu_mode== 0) { //CCQE
		 reco_angle_p1p2_CCQE_PID_300_LF_btb->Fill(anglep1p2);
		 reco_angle_p1p2_CCQE_PID_300_LF_btb_zoom->Fill(anglep1p2);
	       }
	       else if(*nu_mode== 1) {
		 reco_angle_p1p2_CCRes_PID_300_LF_btb->Fill(anglep1p2);
		 reco_angle_p1p2_CCRes_PID_300_LF_btb_zoom->Fill(anglep1p2);
	       }
	       else if(*nu_mode== 3) {
		 reco_angle_p1p2_CCCoh_PID_300_LF_btb->Fill(anglep1p2);
		 reco_angle_p1p2_CCCoh_PID_300_LF_btb_zoom->Fill(anglep1p2);
	       }
	       else if(*nu_mode== 2) {
		 reco_angle_p1p2_CCDIS_PID_300_LF_btb->Fill(anglep1p2);
		 reco_angle_p1p2_CCDIS_PID_300_LF_btb_zoom->Fill(anglep1p2);
	       }
	       else if(*nu_mode== 10) {
		 reco_angle_p1p2_CCMEC_PID_300_LF_btb->Fill(anglep1p2);
		 reco_angle_p1p2_CCMEC_PID_300_LF_btb_zoom->Fill(anglep1p2);
	       }
	       else if(abs(fhg4parpdg[IDTmuon])==11){/// ? hacerlo de otra manera...
		 reco_angle_p1p2_CCNue_PID_300_LF_btb->Fill(anglep1p2);
		 reco_angle_p1p2_CCNue_PID_300_LF_btb_zoom->Fill(anglep1p2);
	       }
	     } ///CC interaction
	     else{
	       reco_angle_p1p2_NC_PID_300_LF_btb->Fill(anglep1p2);
	       reco_angle_p1p2_NC_PID_300_LF_btb_zoom->Fill(anglep1p2);
	     }
	   }/// trackfromneutrino
	 }/// (LF plots)

	 if(!p1p2delta){// plos nuevos CM (necesita quita unos eventos de LF parte)
	   p1p2delta=true;

	   if(trackfromneutrino){
	     if(*nu_ccnc==0){/// CC interaction
	       if(*nu_mode== 0) { //CCQE
		 reco_angle_p1p2_CCQE_PID_300_CM_btb->Fill(reco_CosAnglep1p2CM);
		 reco_angle_p1p2_CCQE_PID_300_CM_btb_zoom->Fill(reco_CosAnglep1p2CM);
	       }
	       else if(*nu_mode== 1) {
		 reco_angle_p1p2_CCRes_PID_300_CM_btb->Fill(reco_CosAnglep1p2CM);
		 reco_angle_p1p2_CCRes_PID_300_CM_btb_zoom->Fill(reco_CosAnglep1p2CM);
	       }
	       else if(*nu_mode== 3) {
		 reco_angle_p1p2_CCCoh_PID_300_CM_btb->Fill(reco_CosAnglep1p2CM);
		 reco_angle_p1p2_CCCoh_PID_300_CM_btb_zoom->Fill(reco_CosAnglep1p2CM);
	       }
	       else if(*nu_mode== 2) {
		 reco_angle_p1p2_CCDIS_PID_300_CM_btb->Fill(reco_CosAnglep1p2CM);
		 reco_angle_p1p2_CCDIS_PID_300_CM_btb_zoom->Fill(reco_CosAnglep1p2CM);
	       }
	       else if(*nu_mode== 10) {
		 reco_angle_p1p2_CCMEC_PID_300_CM_btb->Fill(reco_CosAnglep1p2CM);
		 reco_angle_p1p2_CCMEC_PID_300_CM_btb_zoom->Fill(reco_CosAnglep1p2CM);
	       }
   
	       else if(abs(fhg4parpdg[IDTmuon])==11){/// ? hacerlo de otra manera...
		 reco_angle_p1p2_CCNue_PID_300_CM_btb->Fill(reco_CosAnglep1p2CM);
		 reco_angle_p1p2_CCNue_PID_300_CM_btb_zoom->Fill(reco_CosAnglep1p2CM);
	       }  
	     } ///CC interaction
	     else{
	       reco_angle_p1p2_NC_PID_300_CM_btb->Fill(reco_CosAnglep1p2CM);
	       reco_angle_p1p2_NC_PID_300_CM_btb_zoom->Fill(reco_CosAnglep1p2CM);
	     }
	   }/// trackfromneutrino
	 }
       }///mom>300 MeV

       
     //////// **************** /////////////
     //// same histos amd PID_300 per particle type    
     ///////// **************** /////////////

     /// muon candidate /////
       if(pfp_pdg[muind] ==13){
	 selmuon_lenght_muon_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_muon_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_muon_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_muon_PID_300->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_muon_PID_300->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_muon_PID_300->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_muon_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_muon_PID_300->Fill(track_pfp_chi2_proton[muind]); 
	 }
       }
       else if(pfp_pdg[muind] ==2212){
	 selmuon_lenght_proton_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_proton_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_proton_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_proton_PID_300->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_proton_PID_300->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_proton_PID_300->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_proton_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_proton_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
       } 
       else if(pfp_pdg[muind] ==211){
	 selmuon_lenght_pion_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_pion_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pion_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pion_PID_300->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pion_PID_300->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_pion_PID_300->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pion_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pion_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
       }
       else if(pfp_pdg[muind] ==11){
	 selmuon_lenght_electron_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_electron_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_electron_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_electron_PID_300->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_electron_PID_300->Fill(track_pfp_chi2_proton[muind]);
       
	 ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_electron_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_electron_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
       }  

       else{
	 selmuon_lenght_pother_PID_300->Fill(track_pfp_length[muind]);
	 selmuon_mom_pother_PID_300->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pother_PID_300->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pother_PID_300->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pother_PID_300->Fill(track_pfp_chi2_proton[muind]);
                   
	 //////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pother_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pother_PID_300->Fill(track_pfp_chi2_proton[muind]);
	 }
       }           

       if(pfp_pdg[p1ind] ==13){
	 selproton1_lenght_muon_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_muon_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_muon_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_muon_PID_300->Fill(track_pfp_chi2_proton[p1ind]);
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_muon_PID_300->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==2212){
	 selproton1_lenght_proton_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_proton_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_proton_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_proton_PID_300->Fill(track_pfp_chi2_proton[p1ind]);

	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_proton_PID_300->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==211){
	 selproton1_lenght_pion_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pion_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pion_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pion_PID_300->Fill(track_pfp_chi2_proton[p1ind]);
       
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_pion_PID_300->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }
       else if(pfp_pdg[p1ind] ==11){
	 selproton1_lenght_electron_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_electron_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_electron_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_electron_PID_300->Fill(track_pfp_chi2_proton[p1ind]);
       }//electrons

       else{
	 selproton1_lenght_pother_PID_300->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pother_PID_300->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pother_PID_300->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pother_PID_300->Fill(track_pfp_chi2_proton[p1ind]);
       }//other
       if(pfp_pdg[p2ind] ==13){
	 selproton2_lenght_muon_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_muon_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_muon_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_muon_PID_300->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_muon_PID_300->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==2212){
	 selproton2_lenght_proton_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_proton_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_proton_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_proton_PID_300->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_proton_PID_300->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==211){
	 selproton2_lenght_pion_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pion_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pion_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pion_PID_300->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_pion_PID_300->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }
       else if(pfp_pdg[p2ind] ==11){
	 selproton2_lenght_electron_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_electron_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_electron_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_electron_PID_300->Fill(track_pfp_chi2_proton[p2ind]);
       }//electrons

       else{
	 selproton2_lenght_pother_PID_300->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pother_PID_300->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pother_PID_300->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pother_PID_300->Fill(track_pfp_chi2_proton[p2ind]);
       }//other
       }
       }/// minimum number collection hits (5)
     }/// mu, p1, p2, muon in FV
   }///PID requirement

   return kTRUE;
}

void hanalysis_fMC_PID_300::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_fMC_PID_300::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  cout<<"total number of event processed"<<totentries<<endl;
  cout << "Output file written" << endl;

  fanalysis_PID_300->cd();
  fanalysis_PID_300->Write();

  std::cout << "root Output file written" << std::endl;
  std::cout << "start writing histos" << std::endl;
  outfileMC_PID_300<<"total entries: "<<totentries<<std::endl;
  double topo1fr = topo1/totentries;
  outfileMC_PID_300<<"CC0Pion0Proton: "<<topo1<<" purity "<<topo1fr<<std::endl;
  outfileMC_PID_300<<"CC0Pion1Proton: "<<topo2<<" purity "<<(topo2/totentries)<<std::endl;
  outfileMC_PID_300<<"CC0Pion2Proton: "<<topo3<<" purity "<<double ((topo3/totentries))<<std::endl;
  outfileMC_PID_300<<"CC0PionNProton: "<<topo4<<" purity "<<(topo4/totentries)*100.<<std::endl;
  outfileMC_PID_300<<"CC1PionNProton: "<<topo5<<" purity "<<(topo5/totentries)*100.<<std::endl;
  outfileMC_PID_300<<"CCNPionNProton: "<<topo6<<" purity "<<(topo6/totentries)*100.<<std::endl;
  outfileMC_PID_300<<"CCnue: "<<topo7<<" purity "<<(topo7/totentries)*100.<<std::endl;
  outfileMC_PID_300<<"NC: "<<topo8<<" purity "<<(topo8/totentries)*100.<<std::endl;
  outfileMC_PID_300<<"OOFV: "<<topo9<<" purity "<<(topo9/totentries)*100.<<std::endl;
  outfileMC_PID_300<<"cosmic: "<<topo10<<" purity "<<(topo10/totentries)*100.<<std::endl;
  outfileMC_PID_300<<"other: "<<topo11<<" purity "<<(topo11/totentries)*100.<<std::endl;

  outfileMC_PID_300<< "........................." << std::endl;
  outfileMC_PID_300<< "........................." << std::endl;
  outfileMC_PID_300<< "Number of events with p1p2>300 "<<num300 << std::endl;
  

  gStyle->SetOptStat(0000);
  gStyle->SetOptFit(1111);
  gStyle->SetOptTitle(0);
  gStyle->SetPadColor(kWhite);
  gStyle->SetStatY(0.90);
  gStyle->SetStatX(0.90);
  gStyle->SetStatW(0.15);
  gStyle->SetStatH(0.2);
  gStyle->SetLabelSize(0.04,"X");
  gStyle->SetLabelFont(62,"X");
  gStyle->SetTitleSize(0.04,"X");
  gStyle->SetTitleFont(62,"X");
  gStyle->SetTitleOffset(0.85,"X");

  //  gStyle->SetLabelOffset(0.015,"Y");
  gStyle->SetLabelSize(0.03,"Y");
  gStyle->SetLabelFont(62,"Y");
  gStyle->SetTitleSize(0.04,"Y");
  gStyle->SetTitleFont(62,"Y");
  gStyle->SetTitleOffset(1.3,"Y");
  gStyle->SetTitleX(0.22);
  gStyle->SetTitleY(0.98);
  gStyle->SetTitleSize(0.04,"t");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderSize(0);

  double normLF = angle_p1p2_CCQE_PID_300_LF->GetEntries()+ angle_p1p2_CCRes_PID_300_LF->GetEntries()+angle_p1p2_CCCoh_PID_300_LF->GetEntries()+angle_p1p2_CCDIS_PID_300_LF->GetEntries()+angle_p1p2_CCMEC_PID_300_LF->GetEntries();

  double normCM = angle_p1p2_CCQE_PID_300_CM->GetEntries()+ angle_p1p2_CCRes_PID_300_CM->GetEntries()+angle_p1p2_CCCoh_PID_300_CM->GetEntries()+angle_p1p2_CCDIS_PID_300_CM->GetEntries()+angle_p1p2_CCMEC_PID_300_CM->GetEntries();

  double normNP = NP_CCQE_PID_300->GetEntries()+ NP_CCRes_PID_300->GetEntries()+NP_CCCoh_PID_300->GetEntries()+NP_CCDIS_PID_300->GetEntries()+NP_CCMEC_PID_300->GetEntries();

  angle_p1p2_CCQE_PID_300_LF->Scale(1/normLF);
  angle_p1p2_CCRes_PID_300_LF-> Scale(1/normLF);
  angle_p1p2_CCCoh_PID_300_LF-> Scale(1/normLF);
  angle_p1p2_CCDIS_PID_300_LF-> Scale(1/normLF);
  angle_p1p2_CCMEC_PID_300_LF-> Scale(1/normLF);

  angle_p1p2_CCQE_PID_300_CM->Scale(1/normCM);
  angle_p1p2_CCRes_PID_300_CM-> Scale(1/normCM);
  angle_p1p2_CCCoh_PID_300_CM-> Scale(1/normCM);
  angle_p1p2_CCDIS_PID_300_CM-> Scale(1/normCM);
  angle_p1p2_CCMEC_PID_300_CM-> Scale(1/normCM);
  
  NP_CCQE_PID_300->Scale(1/normNP);
  NP_CCRes_PID_300-> Scale(1/normNP);
  NP_CCCoh_PID_300-> Scale(1/normNP);
  NP_CCDIS_PID_300-> Scale(1/normNP);
  NP_CCMEC_PID_300-> Scale(1/normNP);
  
  angle_p1p2_CCQE_PID_300_LF->Rebin(2);
  angle_p1p2_CCRes_PID_300_LF-> Rebin(2);
  angle_p1p2_CCCoh_PID_300_LF->Rebin(2);
  angle_p1p2_CCDIS_PID_300_LF-> Rebin(2);
  angle_p1p2_CCMEC_PID_300_LF-> Rebin(2);

  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
  
  angle_p1p2_CCQE_PID_300_LF-> SetFillColor(kRed);
  angle_p1p2_CCRes_PID_300_LF-> SetFillColor(kGreen);
  angle_p1p2_CCCoh_PID_300_LF-> SetFillColor(kYellow);
  angle_p1p2_CCDIS_PID_300_LF-> SetFillColor(kBlue);
  angle_p1p2_CCMEC_PID_300_LF-> SetFillColor(kMagenta);
 
  THStack *angle_p1p2_PID_300_LF = new THStack("angle_p1p2_PID_300_LF","");
  angle_p1p2_PID_300_LF-> Add(angle_p1p2_CCQE_PID_300_LF);
  angle_p1p2_PID_300_LF-> Add(angle_p1p2_CCRes_PID_300_LF);
  angle_p1p2_PID_300_LF-> Add(angle_p1p2_CCCoh_PID_300_LF);
  angle_p1p2_PID_300_LF-> Add(angle_p1p2_CCDIS_PID_300_LF);
  angle_p1p2_PID_300_LF-> Add(angle_p1p2_CCMEC_PID_300_LF); 
  //angle_p1p2_PID_300_LF-> SetMaximum(300);  
  angle_p1p2_PID_300_LF-> Draw();
  angle_p1p2_PID_300_LF->GetXaxis()->SetTitle("cos #theta_{p1p2} lab frame");
  angle_p1p2_PID_300_LF->GetYaxis()->SetTitle("fraction of events");

  TLegend *l1 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l1 -> AddEntry(angle_p1p2_CCQE_PID_300_LF, "CCQE", "f");
  l1 -> AddEntry(angle_p1p2_CCRes_PID_300_LF, "CCRES", "f");
  l1 -> AddEntry(angle_p1p2_CCCoh_PID_300_LF, "CC-Coh", "f");
  l1 -> AddEntry(angle_p1p2_CCDIS_PID_300_LF, "CCDIS", "f");
  l1 -> AddEntry(angle_p1p2_CCMEC_PID_300_LF, "CCMEC", "f");
  l1 -> Draw();

  c1->Update();
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID/costheta_LF.pdf");
  
  TCanvas *c2 = new TCanvas("c2", "c2", 900, 900);
  
  angle_p1p2_CCQE_PID_300_CM-> SetFillColor(kRed);
  angle_p1p2_CCRes_PID_300_CM-> SetFillColor(kGreen);
  angle_p1p2_CCCoh_PID_300_CM-> SetFillColor(kYellow);
  angle_p1p2_CCDIS_PID_300_CM-> SetFillColor(kBlue);
  angle_p1p2_CCMEC_PID_300_CM-> SetFillColor(kMagenta);
 
  THStack *angle_p1p2_PID_300_CM = new THStack("angle_p1p2_PID_300_CM","");
  angle_p1p2_PID_300_CM-> Add(angle_p1p2_CCQE_PID_300_CM);
  angle_p1p2_PID_300_CM-> Add(angle_p1p2_CCRes_PID_300_CM);
  angle_p1p2_PID_300_CM-> Add(angle_p1p2_CCCoh_PID_300_CM);
  angle_p1p2_PID_300_CM-> Add(angle_p1p2_CCDIS_PID_300_CM);
  angle_p1p2_PID_300_CM-> Add(angle_p1p2_CCMEC_PID_300_CM);  
  angle_p1p2_PID_300_CM-> Draw();
  angle_p1p2_PID_300_CM->GetXaxis()->SetTitle("cos #theta_{pnp2} CM frame");
  angle_p1p2_PID_300_CM->GetYaxis()->SetTitle("fraction of events");

  TLegend *l2 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l2 -> AddEntry(angle_p1p2_CCQE_PID_300_CM, "CCQE", "f");
  l2 -> AddEntry(angle_p1p2_CCRes_PID_300_CM, "CCRES", "f");
  l2 -> AddEntry(angle_p1p2_CCCoh_PID_300_CM, "CC-Coh", "f");
  l2 -> AddEntry(angle_p1p2_CCDIS_PID_300_CM, "CCDIS", "f");
  l2 -> AddEntry(angle_p1p2_CCMEC_PID_300_CM, "CCMEC", "f");
  l2 -> Draw();

  c2->Update();
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID/costheta_CM.pdf");
    

  TCanvas *c3 = new TCanvas("c3", "c3", 900, 900);
  
  NP_CCQE_PID_300-> SetFillColor(kRed);
  NP_CCRes_PID_300-> SetFillColor(kGreen);
  NP_CCCoh_PID_300-> SetFillColor(kYellow);
  NP_CCDIS_PID_300-> SetFillColor(kBlue);
  NP_CCMEC_PID_300-> SetFillColor(kMagenta);
 
  THStack *NP_PID_300 = new THStack("NP_PID_300","");
  NP_PID_300-> Add(NP_CCQE_PID_300);
  NP_PID_300-> Add(NP_CCRes_PID_300);
  NP_PID_300-> Add(NP_CCCoh_PID_300);
  NP_PID_300-> Add(NP_CCDIS_PID_300);
  NP_PID_300-> Add(NP_CCMEC_PID_300); 
  // NP_PID_300-> SetMaximum(300);  
  NP_PID_300-> Draw();
  NP_PID_300->GetXaxis()->SetTitle("Number of protons momentum > 300 MeV/c");
  NP_PID_300->GetYaxis()->SetTitle("fraction of events");

  TLegend *l3 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l3 -> AddEntry(NP_CCQE_PID_300, "CCQE", "f");
  l3 -> AddEntry(NP_CCRes_PID_300, "CCRES", "f");
  l3 -> AddEntry(NP_CCCoh_PID_300, "CC-Coh", "f");
  l3 -> AddEntry(NP_CCDIS_PID_300, "CCDIS", "f");
  l3 -> AddEntry(NP_CCMEC_PID_300, "CCMEC", "f");
  l3 -> Draw();

  c3->Update();
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID/NP_PID_300.pdf");
     
}
