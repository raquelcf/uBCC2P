#define hanalysis_Tune3_PID_cxx
// The class definition in hanalysis_Tune3_PID.h has been generated automatically
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
// root> T->Process("hanalysis_Tune3_PID.C")
// root> T->Process("hanalysis_Tune3_PID.C","some options")
// root> T->Process("hanalysis_Tune3_PID.C+")
//


#include "hanalysis_Tune3_PID.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TMath.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfileMC_PID;
TFile *fanalysis_PID;

/// muon candidate properties
TH1D *selmuon_lenght_CC0Pion0Proton_PID;
TH1D *selmuon_lenght_CC0Pion1Proton_PID;
TH1D *selmuon_lenght_CC0Pion2Proton_PID;
TH1D *selmuon_lenght_CC0PionNProton_PID;
TH1D *selmuon_lenght_CC1PionNProton_PID;
TH1D *selmuon_lenght_CCNPionNProton_PID;
TH1D *selmuon_lenght_CCNue_PID;
TH1D *selmuon_lenght_NC_PID;
TH1D *selmuon_lenght_OOFV_PID;
TH1D *selmuon_lenght_EXT_PID;
TH1D *selmuon_lenght_other_PID;

TH1D *selmuon_mom_CC0Pion0Proton_PID;
TH1D *selmuon_mom_CC0Pion1Proton_PID;
TH1D *selmuon_mom_CC0Pion2Proton_PID;
TH1D *selmuon_mom_CC0PionNProton_PID;
TH1D *selmuon_mom_CC1PionNProton_PID;
TH1D *selmuon_mom_CCNPionNProton_PID;
TH1D *selmuon_mom_CCNue_PID;
TH1D *selmuon_mom_NC_PID;
TH1D *selmuon_mom_OOFV_PID;
TH1D *selmuon_mom_EXT_PID;
TH1D *selmuon_mom_other_PID;

TH1D *selmuon_contained_mom_CC0Pion0Proton_PID;
TH1D *selmuon_contained_mom_CC0Pion1Proton_PID;
TH1D *selmuon_contained_mom_CC0Pion2Proton_PID;
TH1D *selmuon_contained_mom_CC0PionNProton_PID;
TH1D *selmuon_contained_mom_CC1PionNProton_PID;
TH1D *selmuon_contained_mom_CCNPionNProton_PID;
TH1D *selmuon_contained_mom_CCNue_PID;
TH1D *selmuon_contained_mom_NC_PID;
TH1D *selmuon_contained_mom_OOFV_PID;
TH1D *selmuon_contained_mom_EXT_PID;
TH1D *selmuon_contained_mom_other_PID;

TH1D *selmuon_uncontained_mom_CC0Pion0Proton_PID;
TH1D *selmuon_uncontained_mom_CC0Pion1Proton_PID;
TH1D *selmuon_uncontained_mom_CC0Pion2Proton_PID;
TH1D *selmuon_uncontained_mom_CC0PionNProton_PID;
TH1D *selmuon_uncontained_mom_CC1PionNProton_PID;
TH1D *selmuon_uncontained_mom_CCNPionNProton_PID;
TH1D *selmuon_uncontained_mom_CCNue_PID;
TH1D *selmuon_uncontained_mom_NC_PID;
TH1D *selmuon_uncontained_mom_OOFV_PID;
TH1D *selmuon_uncontained_mom_EXT_PID;
TH1D *selmuon_uncontained_mom_other_PID;

TH1D *selmuon_costheta_CC0Pion0Proton_PID;
TH1D *selmuon_costheta_CC0Pion1Proton_PID;
TH1D *selmuon_costheta_CC0Pion2Proton_PID;
TH1D *selmuon_costheta_CC0PionNProton_PID;
TH1D *selmuon_costheta_CC1PionNProton_PID;
TH1D *selmuon_costheta_CCNPionNProton_PID;
TH1D *selmuon_costheta_CCNue_PID;
TH1D *selmuon_costheta_NC_PID;
TH1D *selmuon_costheta_OOFV_PID;
TH1D *selmuon_costheta_EXT_PID;
TH1D *selmuon_costheta_other_PID;

TH1D *selmuon_phi_CC0Pion0Proton_PID;
TH1D *selmuon_phi_CC0Pion1Proton_PID;
TH1D *selmuon_phi_CC0Pion2Proton_PID;
TH1D *selmuon_phi_CC0PionNProton_PID;
TH1D *selmuon_phi_CC1PionNProton_PID;
TH1D *selmuon_phi_CCNPionNProton_PID;
TH1D *selmuon_phi_CCNue_PID;
TH1D *selmuon_phi_NC_PID;
TH1D *selmuon_phi_OOFV_PID;
TH1D *selmuon_phi_EXT_PID;
TH1D *selmuon_phi_other_PID;

TH1D *selmuon_lenght_muon_PID;
TH1D *selmuon_lenght_proton_PID;
TH1D *selmuon_lenght_pion_PID;
TH1D *selmuon_lenght_electron_PID;
TH1D *selmuon_lenght_pother_PID;

TH1D *selmuon_mom_muon_PID;
TH1D *selmuon_mom_proton_PID;
TH1D *selmuon_mom_pion_PID;
TH1D *selmuon_mom_electron_PID;
TH1D *selmuon_mom_pother_PID;

TH1D *selmuon_contained_mom_muon_PID;
TH1D *selmuon_contained_mom_proton_PID;
TH1D *selmuon_contained_mom_pion_PID;
TH1D *selmuon_contained_mom_electron_PID;
TH1D *selmuon_contained_mom_pother_PID;

TH1D *selmuon_uncontained_mom_muon_PID;
TH1D *selmuon_uncontained_mom_proton_PID;
TH1D *selmuon_uncontained_mom_pion_PID;
TH1D *selmuon_uncontained_mom_electron_PID;
TH1D *selmuon_uncontained_mom_pother_PID;

TH1D *selmuon_costheta_muon_PID;
TH1D *selmuon_costheta_proton_PID;
TH1D *selmuon_costheta_pion_PID;
TH1D *selmuon_costheta_electron_PID;
TH1D *selmuon_costheta_pother_PID;

TH1D *selmuon_phi_muon_PID;
TH1D *selmuon_phi_proton_PID;
TH1D *selmuon_phi_pion_PID;
TH1D *selmuon_phi_electron_PID;
TH1D *selmuon_phi_pother_PID;

TH1D *selmuon_chi2proton_muon_PID;
TH1D *selmuon_chi2proton_proton_PID;
TH1D *selmuon_chi2proton_pion_PID;
TH1D *selmuon_chi2proton_electron_PID;
TH1D *selmuon_chi2proton_pother_PID;

TH1D *selmuon_chi2proton_cont_muon_PID;
TH1D *selmuon_chi2proton_cont_proton_PID;
TH1D *selmuon_chi2proton_cont_pion_PID;
TH1D *selmuon_chi2proton_cont_electron_PID;
TH1D *selmuon_chi2proton_cont_pother_PID;

TH2D *selmuon_dEdx_vs_resrange_muon_PID;
TH2D *selmuon_dEdx_vs_resrange_proton_PID;
TH2D *selmuon_dEdx_vs_resrange_pion_PID;

TH1D *selmuon_chi2proton_uncont_muon_PID;
TH1D *selmuon_chi2proton_uncont_proton_PID;
TH1D *selmuon_chi2proton_uncont_pion_PID;
TH1D *selmuon_chi2proton_uncont_electron_PID;
TH1D *selmuon_chi2proton_uncont_pother_PID;

///proton properties

TH1D *selproton1_lenght_CC0Pion0Proton_PID;
TH1D *selproton1_lenght_CC0Pion1Proton_PID;
TH1D *selproton1_lenght_CC0Pion2Proton_PID;
TH1D *selproton1_lenght_CC0PionNProton_PID;
TH1D *selproton1_lenght_CC1PionNProton_PID;
TH1D *selproton1_lenght_CCNPionNProton_PID;
TH1D *selproton1_lenght_CCNue_PID;
TH1D *selproton1_lenght_NC_PID;
TH1D *selproton1_lenght_OOFV_PID;
TH1D *selproton1_lenght_EXT_PID;
TH1D *selproton1_lenght_other_PID;

TH1D *selproton1_costheta_CC0Pion0Proton_PID;
TH1D *selproton1_costheta_CC0Pion1Proton_PID;
TH1D *selproton1_costheta_CC0Pion2Proton_PID;
TH1D *selproton1_costheta_CC0PionNProton_PID;
TH1D *selproton1_costheta_CC1PionNProton_PID;
TH1D *selproton1_costheta_CCNPionNProton_PID;
TH1D *selproton1_costheta_CCNue_PID;
TH1D *selproton1_costheta_NC_PID;
TH1D *selproton1_costheta_OOFV_PID;
TH1D *selproton1_costheta_EXT_PID;
TH1D *selproton1_costheta_other_PID;

TH1D *selproton1_phi_CC0Pion0Proton_PID;
TH1D *selproton1_phi_CC0Pion1Proton_PID;
TH1D *selproton1_phi_CC0Pion2Proton_PID;
TH1D *selproton1_phi_CC0PionNProton_PID;
TH1D *selproton1_phi_CC1PionNProton_PID;
TH1D *selproton1_phi_CCNPionNProton_PID;
TH1D *selproton1_phi_CCNue_PID;
TH1D *selproton1_phi_NC_PID;
TH1D *selproton1_phi_OOFV_PID;
TH1D *selproton1_phi_EXT_PID;
TH1D *selproton1_phi_other_PID;

TH1D *selproton1_mom_CC0Pion0Proton_PID;
TH1D *selproton1_mom_CC0Pion1Proton_PID;
TH1D *selproton1_mom_CC0Pion2Proton_PID;
TH1D *selproton1_mom_CC0PionNProton_PID;
TH1D *selproton1_mom_CC1PionNProton_PID;
TH1D *selproton1_mom_CCNPionNProton_PID;
TH1D *selproton1_mom_CCNue_PID;
TH1D *selproton1_mom_NC_PID;
TH1D *selproton1_mom_OOFV_PID;
TH1D *selproton1_mom_EXT_PID;
TH1D *selproton1_mom_other_PID;

TH1D *selproton1_lenght_muon_PID;
TH1D *selproton1_lenght_proton_PID;
TH1D *selproton1_lenght_pion_PID;
TH1D *selproton1_lenght_electron_PID;
TH1D *selproton1_lenght_pother_PID;

TH1D *selproton1_costheta_muon_PID;
TH1D *selproton1_costheta_proton_PID;
TH1D *selproton1_costheta_pion_PID;
TH1D *selproton1_costheta_electron_PID;
TH1D *selproton1_costheta_pother_PID;

TH1D *selproton1_phi_muon_PID;
TH1D *selproton1_phi_proton_PID;
TH1D *selproton1_phi_pion_PID;
TH1D *selproton1_phi_electron_PID;
TH1D *selproton1_phi_pother_PID;

TH1D *selproton1_chi2proton_muon_PID;
TH1D *selproton1_chi2proton_proton_PID;
TH1D *selproton1_chi2proton_pion_PID;
TH1D *selproton1_chi2proton_electron_PID;
TH1D *selproton1_chi2proton_pother_PID;

TH2D *selproton1_dEdx_vs_resrange_muon_PID;
TH2D *selproton1_dEdx_vs_resrange_proton_PID;
TH2D *selproton1_dEdx_vs_resrange_pion_PID;

/////////////////////////////////////////////

TH1D *selproton2_lenght_CC0Pion0Proton_PID;
TH1D *selproton2_lenght_CC0Pion1Proton_PID;
TH1D *selproton2_lenght_CC0Pion2Proton_PID;
TH1D *selproton2_lenght_CC0PionNProton_PID;
TH1D *selproton2_lenght_CC1PionNProton_PID;
TH1D *selproton2_lenght_CCNPionNProton_PID;
TH1D *selproton2_lenght_CCNue_PID;
TH1D *selproton2_lenght_NC_PID;
TH1D *selproton2_lenght_OOFV_PID;
TH1D *selproton2_lenght_EXT_PID;
TH1D *selproton2_lenght_other_PID;

TH1D *selproton2_costheta_CC0Pion0Proton_PID;
TH1D *selproton2_costheta_CC0Pion1Proton_PID;
TH1D *selproton2_costheta_CC0Pion2Proton_PID;
TH1D *selproton2_costheta_CC0PionNProton_PID;
TH1D *selproton2_costheta_CC1PionNProton_PID;
TH1D *selproton2_costheta_CCNPionNProton_PID;
TH1D *selproton2_costheta_CCNue_PID;
TH1D *selproton2_costheta_NC_PID;
TH1D *selproton2_costheta_OOFV_PID;
TH1D *selproton2_costheta_EXT_PID;
TH1D *selproton2_costheta_other_PID;

TH1D *selproton2_phi_CC0Pion0Proton_PID;
TH1D *selproton2_phi_CC0Pion1Proton_PID;
TH1D *selproton2_phi_CC0Pion2Proton_PID;
TH1D *selproton2_phi_CC0PionNProton_PID;
TH1D *selproton2_phi_CC1PionNProton_PID;
TH1D *selproton2_phi_CCNPionNProton_PID;
TH1D *selproton2_phi_CCNue_PID;
TH1D *selproton2_phi_NC_PID;
TH1D *selproton2_phi_OOFV_PID;
TH1D *selproton2_phi_EXT_PID;
TH1D *selproton2_phi_other_PID;

TH1D *selproton2_mom_CC0Pion0Proton_PID;
TH1D *selproton2_mom_CC0Pion1Proton_PID;
TH1D *selproton2_mom_CC0Pion2Proton_PID;
TH1D *selproton2_mom_CC0PionNProton_PID;
TH1D *selproton2_mom_CC1PionNProton_PID;
TH1D *selproton2_mom_CCNPionNProton_PID;
TH1D *selproton2_mom_CCNue_PID;
TH1D *selproton2_mom_NC_PID;
TH1D *selproton2_mom_OOFV_PID;
TH1D *selproton2_mom_EXT_PID;
TH1D *selproton2_mom_other_PID;

TH1D *selproton2_lenght_muon_PID;
TH1D *selproton2_lenght_proton_PID;
TH1D *selproton2_lenght_pion_PID;
TH1D *selproton2_lenght_electron_PID;
TH1D *selproton2_lenght_pother_PID;

TH1D *selproton2_costheta_muon_PID;
TH1D *selproton2_costheta_proton_PID;
TH1D *selproton2_costheta_pion_PID;
TH1D *selproton2_costheta_electron_PID;
TH1D *selproton2_costheta_pother_PID;

TH1D *selproton2_phi_muon_PID;
TH1D *selproton2_phi_proton_PID;
TH1D *selproton2_phi_pion_PID;
TH1D *selproton2_phi_electron_PID;
TH1D *selproton2_phi_pother_PID;

TH1D *selproton2_PIDA_muon_PID;
TH1D *selproton2_PIDA_proton_PID;
TH1D *selproton2_PIDA_pion_PID;
TH1D *selproton2_PIDA_electron_PID;
TH1D *selproton2_PIDA_pother_PID;

TH1D *selproton2_chi2proton_muon_PID;
TH1D *selproton2_chi2proton_proton_PID;
TH1D *selproton2_chi2proton_pion_PID;
TH1D *selproton2_chi2proton_electron_PID;
TH1D *selproton2_chi2proton_pother_PID;

TH2D *selproton2_dEdx_vs_resrange_muon_PID;
TH2D *selproton2_dEdx_vs_resrange_proton_PID;
TH2D *selproton2_dEdx_vs_resrange_pion_PID;

//// Opening angles
TH1D *angle_mup1_CC0Pion0Proton_PID;
TH1D *angle_mup1_CC0Pion1Proton_PID;
TH1D *angle_mup1_CC0Pion2Proton_PID;
TH1D *angle_mup1_CC0PionNProton_PID;
TH1D *angle_mup1_CC1PionNProton_PID;
TH1D *angle_mup1_CCNPionNProton_PID;
TH1D *angle_mup1_CCNue_PID;
TH1D *angle_mup1_NC_PID;
TH1D *angle_mup1_OOFV_PID;
TH1D *angle_mup1_EXT_PID;
TH1D *angle_mup1_other_PID;

TH1D *angle_mup2_CC0Pion0Proton_PID;
TH1D *angle_mup2_CC0Pion1Proton_PID;
TH1D *angle_mup2_CC0Pion2Proton_PID;
TH1D *angle_mup2_CC0PionNProton_PID;
TH1D *angle_mup2_CC1PionNProton_PID;
TH1D *angle_mup2_CCNPionNProton_PID;
TH1D *angle_mup2_CCNue_PID;
TH1D *angle_mup2_NC_PID;
TH1D *angle_mup2_OOFV_PID;
TH1D *angle_mup2_EXT_PID;
TH1D *angle_mup2_other_PID;

TH1D *angle_p1p2_CC0Pion0Proton_PID;
TH1D *angle_p1p2_CC0Pion1Proton_PID;
TH1D *angle_p1p2_CC0Pion2Proton_PID;
TH1D *angle_p1p2_CC0PionNProton_PID;
TH1D *angle_p1p2_CC1PionNProton_PID;
TH1D *angle_p1p2_CCNPionNProton_PID;
TH1D *angle_p1p2_CCNue_PID;
TH1D *angle_p1p2_NC_PID;
TH1D *angle_p1p2_OOFV_PID;
TH1D *angle_p1p2_EXT_PID;
TH1D *angle_p1p2_other_PID;

TH1D *cosangle_p1p2_CC0Pion0Proton_PID;
TH1D *cosangle_p1p2_CC0Pion1Proton_PID;
TH1D *cosangle_p1p2_CC0Pion2Proton_PID;
TH1D *cosangle_p1p2_CC0PionNProton_PID;
TH1D *cosangle_p1p2_CC1PionNProton_PID;
TH1D *cosangle_p1p2_CCNPionNProton_PID;
TH1D *cosangle_p1p2_CCNue_PID;
TH1D *cosangle_p1p2_NC_PID;
TH1D *cosangle_p1p2_OOFV_PID;
TH1D *cosangle_p1p2_EXT_PID;
TH1D *cosangle_p1p2_other_PID;

///// resolutions
TH2D *selmuon_mom_res_PID;
TH2D *selmuon_costheta_res_PID;
TH2D *selmuon_phi_res_PID;

TH2D *selproton1_mom_res_PID;
TH2D *selproton1_costheta_res_PID;
TH2D *selproton1_phi_res_PID;

TH2D *selproton2_mom_res_PID;
TH2D *selproton2_costheta_res_PID;
TH2D *selproton2_phi_res_PID;

//////////////////////

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

int QE=0;
int RES=0;
int DIS=0;
int COH=0;
int MEC=0;

float FVx = 256.35;
float FVy = 233;
float FVz = 1036.8;
float borderx = 12.;
float bordery = 35.;
float borderz = 25.;

//This function returns if a 3D point is within the fiducial volume
bool inFV(float x, float y, float z) {
    if(x < (FVx - borderx) && (x > borderx) && (y < (FVy/2. - bordery)) && (y > (-FVy/2. + bordery)) && (z < (FVz - 85)) && (z > borderz)) return true;
    else return false;
}

void hanalysis_Tune3_PID::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void hanalysis_Tune3_PID::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   fanalysis_PID= new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_BNBMCTune3.root","RECREATE");
   outfileMC_PID.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_PID_MCTune3.txt");

   std::cout<<"declaring histos"<<endl;
/////////////////// muon candidate properties

   selmuon_lenght_CC0Pion0Proton_PID= new TH1D("selmuon_lenght_CC0Pion0Proton_PID", "selmuon_lenght_CC0Pion0Proton_PID", 10, 0, 500);
   selmuon_lenght_CC0Pion1Proton_PID= new TH1D("selmuon_lenght_CC0Pion1Proton_PID", "selmuon_lenght_CC0Pion1Proton_PID", 10, 0, 500);
   selmuon_lenght_CC0Pion2Proton_PID= new TH1D("selmuon_lenght_CC0Pion2Proton_PID", "selmuon_lenght_CC0Pion2Proton_PID", 10, 0, 500);
   selmuon_lenght_CC0PionNProton_PID= new TH1D("selmuon_lenght_CC0PionNProton_PID", "selmuon_lenght_CC0PionNProton_PID", 10, 0, 500);
   selmuon_lenght_CC1PionNProton_PID= new TH1D("selmuon_lenght_CC1PionNProton_PID", "selmuon_lenght_CC1PionNProton_PID", 10, 0, 500);
   selmuon_lenght_CCNPionNProton_PID= new TH1D("selmuon_lenght_CCNPionNProton_PID", "selmuon_lenght_CCNPionNProton_PID", 10, 0, 500);
   selmuon_lenght_CCNue_PID= new TH1D("selmuon_lenght_CCNue_PID", "selmuon_lenght_CCNue_PID", 10, 0, 500);   
   selmuon_lenght_NC_PID= new TH1D("selmuon_lenght_NC_PID", "selmuon_lenght_NC_PID", 10, 0, 500);
   selmuon_lenght_OOFV_PID= new TH1D("selmuon_lenght_OOFV_PID", "selmuon_lenght_OOFV_PID", 10, 0, 500);
   selmuon_lenght_EXT_PID= new TH1D("selmuon_lenght_EXT_PID", "selmuon_lenght_EXT_PID", 10, 0, 500);
   selmuon_lenght_other_PID= new TH1D("selmuon_lenght_other_PID", "selmuon_lenght_other_PID", 10, 0, 500);   
   ////
   selmuon_mom_CC0Pion0Proton_PID= new TH1D("selmuon_mom_CC0Pion0Proton_PID", "selmuon_mom_CC0Pion0Proton_PID", 10, 0, 3);
   selmuon_mom_CC0Pion1Proton_PID= new TH1D("selmuon_mom_CC0Pion1Proton_PID", "selmuon_mom_CC0Pion1Proton_PID", 10, 0, 3);
   selmuon_mom_CC0Pion2Proton_PID= new TH1D("selmuon_mom_CC0Pion2Proton_PID", "selmuon_mom_CC0Pion2Proton_PID", 10, 0, 3);
   selmuon_mom_CC0PionNProton_PID= new TH1D("selmuon_mom_CC0PionNProton_PID", "selmuon_mom_CC0PionNProton_PID", 10, 0, 3);
   selmuon_mom_CC1PionNProton_PID= new TH1D("selmuon_mom_CC1PionNProton_PID", "selmuon_mom_CC1PionNProton_PID", 10, 0, 3);
   selmuon_mom_CCNPionNProton_PID= new TH1D("selmuon_mom_CCNPionNProton_PID", "selmuon_mom_CCNPionNProton_PID", 10, 0, 3);
   selmuon_mom_CCNue_PID= new TH1D("selmuon_mom_CCNue_PID", "selmuon_mom_CCNue_PID", 10, 0, 3);   
   selmuon_mom_NC_PID= new TH1D("selmuon_mom_NC_PID", "selmuon_mom_NC_PID", 10, 0, 3);
   selmuon_mom_OOFV_PID= new TH1D("selmuon_mom_OOFV_PID", "selmuon_mom_OOFV_PID", 10, 0, 3);
   selmuon_mom_EXT_PID= new TH1D("selmuon_mom_EXT_PID", "selmuon_mom_EXT_PID", 10, 0, 3);
   selmuon_mom_other_PID= new TH1D("selmuon_mom_other_PID", "selmuon_mom_other_PID", 10, 0, 3);   
   ///
   
   selmuon_contained_mom_CC0Pion0Proton_PID= new TH1D("selmuon_contained_mom_CC0Pion0Proton_PID", "selmuon_contained_mom_CC0Pion0Proton_PID", 10, 0, 3);
   selmuon_contained_mom_CC0Pion1Proton_PID= new TH1D("selmuon_contained_mom_CC0Pion1Proton_PID", "selmuon_contained_mom_CC0Pion1Proton_PID", 10, 0, 3);
   selmuon_contained_mom_CC0Pion2Proton_PID= new TH1D("selmuon_contained_mom_CC0Pion2Proton_PID", "selmuon_contained_mom_CC0Pion2Proton_PID", 10, 0, 3);
   selmuon_contained_mom_CC0PionNProton_PID= new TH1D("selmuon_contained_mom_CC0PionNProton_PID", "selmuon_contained_mom_CC0PionNProton_PID", 10, 0, 3);
   selmuon_contained_mom_CC1PionNProton_PID= new TH1D("selmuon_contained_mom_CC1PionNProton_PID", "selmuon_contained_mom_CC1PionNProton_PID", 10, 0, 3);
   selmuon_contained_mom_CCNPionNProton_PID= new TH1D("selmuon_contained_mom_CCNPionNProton_PID", "selmuon_contained_mom_CCNPionNProton_PID", 10, 0, 3);
   selmuon_contained_mom_CCNue_PID= new TH1D("selmuon_contained_mom_CCNue_PID", "selmuon_contained_mom_CCNue_PID", 10, 0, 3);   
   selmuon_contained_mom_NC_PID= new TH1D("selmuon_contained_mom_NC_PID", "selmuon_contained_mom_NC_PID", 10, 0, 3);
   selmuon_contained_mom_OOFV_PID= new TH1D("selmuon_contained_mom_OOFV_PID", "selmuon_contained_mom_OOFV_PID", 10, 0, 3);
   selmuon_contained_mom_EXT_PID= new TH1D("selmuon_contained_mom_EXT_PID", "selmuon_contained_mom_EXT_PID", 10, 0, 3);
   selmuon_contained_mom_other_PID= new TH1D("selmuon_contained_mom_other_PID", "selmuon_contained_mom_other_PID", 10, 0, 3);   
   ////

   selmuon_uncontained_mom_CC0Pion0Proton_PID= new TH1D("selmuon_uncontained_mom_CC0Pion0Proton_PID", "selmuon_uncontained_mom_CC0Pion0Proton_PID", 10, 0, 3);
   selmuon_uncontained_mom_CC0Pion1Proton_PID= new TH1D("selmuon_uncontained_mom_CC0Pion1Proton_PID", "selmuon_uncontained_mom_CC0Pion1Proton_PID", 10, 0, 3);
   selmuon_uncontained_mom_CC0Pion2Proton_PID= new TH1D("selmuon_uncontained_mom_CC0Pion2Proton_PID", "selmuon_uncontained_mom_CC0Pion2Proton_PID", 10, 0, 3);
   selmuon_uncontained_mom_CC0PionNProton_PID= new TH1D("selmuon_uncontained_mom_CC0PionNProton_PID", "selmuon_uncontained_mom_CC0PionNProton_PID", 10, 0, 3);
   selmuon_uncontained_mom_CC1PionNProton_PID= new TH1D("selmuon_uncontained_mom_CC1PionNProton_PID", "selmuon_uncontained_mom_CC1PionNProton_PID", 10, 0, 3);
   selmuon_uncontained_mom_CCNPionNProton_PID= new TH1D("selmuon_uncontained_mom_CCNPionNProton_PID", "selmuon_uncontained_mom_CCNPionNProton_PID", 10, 0, 3);
   selmuon_uncontained_mom_CCNue_PID= new TH1D("selmuon_uncontained_mom_CCNue_PID", "selmuon_uncontained_mom_CCNue_PID", 10, 0, 3);   
   selmuon_uncontained_mom_NC_PID= new TH1D("selmuon_uncontained_mom_NC_PID", "selmuon_uncontained_mom_NC_PID", 10, 0, 3);
   selmuon_uncontained_mom_OOFV_PID= new TH1D("selmuon_uncontained_mom_OOFV_PID", "selmuon_uncontained_mom_OOFV_PID", 10, 0, 3);
   selmuon_uncontained_mom_EXT_PID= new TH1D("selmuon_uncontained_mom_EXT_PID", "selmuon_uncontained_mom_EXT_PID", 10, 0, 3);
   selmuon_uncontained_mom_other_PID= new TH1D("selmuon_uncontained_mom_other_PID", "selmuon_uncontained_mom_other_PID", 10, 0, 3);   
   ////
   selmuon_costheta_CC0Pion0Proton_PID= new TH1D("selmuon_costheta_CC0Pion0Proton_PID", "selmuon_costheta_CC0Pion0Proton_PID", 10, -1, 1);
   selmuon_costheta_CC0Pion1Proton_PID= new TH1D("selmuon_costheta_CC0Pion1Proton_PID", "selmuon_costheta_CC0Pion1Proton_PID", 10, -1, 1);
   selmuon_costheta_CC0Pion2Proton_PID= new TH1D("selmuon_costheta_CC0Pion2Proton_PID", "selmuon_costheta_CC0Pion2Proton_PID", 10, -1, 1);
   selmuon_costheta_CC0PionNProton_PID= new TH1D("selmuon_costheta_CC0PionNProton_PID", "selmuon_costheta_CC0PionNProton_PID", 10, -1, 1);
   selmuon_costheta_CC1PionNProton_PID= new TH1D("selmuon_costheta_CC1PionNProton_PID", "selmuon_costheta_CC1PionNProton_PID", 10, -1, 1);
   selmuon_costheta_CCNPionNProton_PID= new TH1D("selmuon_costheta_CCNPionNProton_PID", "selmuon_costheta_CCNPionNProton_PID", 10, -1, 1);
   selmuon_costheta_CCNue_PID= new TH1D("selmuon_costheta_CCNue_PID", "selmuon_costheta_CCNue_PID", 10, -1, 1);   
   selmuon_costheta_NC_PID= new TH1D("selmuon_costheta_NC_PID", "selmuon_costheta_NC_PID", 10, -1, 1);
   selmuon_costheta_OOFV_PID= new TH1D("selmuon_costheta_OOFV_PID", "selmuon_costheta_OOFV_PID", 10, -1, 1);
   selmuon_costheta_EXT_PID= new TH1D("selmuon_costheta_EXT_PID", "selmuon_costheta_EXT_PID", 10, -1, 1);
   selmuon_costheta_other_PID= new TH1D("selmuon_costheta_other_PID", "selmuon_costheta_other_PID", 10, -1, 1); 
   /////
   selmuon_phi_CC0Pion0Proton_PID= new TH1D("selmuon_phi_CC0Pion0Proton_PID", "selmuon_phi_CC0Pion0Proton_PID", 10, -3.14, 3.14);
   selmuon_phi_CC0Pion1Proton_PID= new TH1D("selmuon_phi_CC0Pion1Proton_PID", "selmuon_phi_CC0Pion1Proton_PID", 10, -3.14, 3.14);
   selmuon_phi_CC0Pion2Proton_PID= new TH1D("selmuon_phi_CC0Pion2Proton_PID", "selmuon_phi_CC0Pion2Proton_PID", 10, -3.14, 3.14);
   selmuon_phi_CC0PionNProton_PID= new TH1D("selmuon_phi_CC0PionNProton_PID", "selmuon_phi_CC0PionNProton_PID", 10, -3.14, 3.14);
   selmuon_phi_CC1PionNProton_PID= new TH1D("selmuon_phi_CC1PionNProton_PID", "selmuon_phi_CC1PionNProton_PID", 10, -3.14, 3.14);
   selmuon_phi_CCNPionNProton_PID= new TH1D("selmuon_phi_CCNPionNProton_PID", "selmuon_phi_CCNPionNProton_PID", 10, -3.14, 3.14);
   selmuon_phi_CCNue_PID= new TH1D("selmuon_phi_CCNue_PID", "selmuon_phi_CCNue_PID", 10, -3.14, 3.14);   
   selmuon_phi_NC_PID= new TH1D("selmuon_phi_NC_PID", "selmuon_phi_NC_PID", 10, -3.14, 3.14);
   selmuon_phi_OOFV_PID= new TH1D("selmuon_phi_OOFV_PID", "selmuon_phi_OOFV_PID", 10, -3.14, 3.14);
   selmuon_phi_EXT_PID= new TH1D("selmuon_phi_EXT_PID", "selmuon_phi_EXT_PID", 10, -3.14, 3.14);
   selmuon_phi_other_PID= new TH1D("selmuon_phi_other_PID", "selmuon_phi_other_PID", 10, -3.14, 3.14); 
   /////

   selmuon_lenght_muon_PID= new TH1D("selmuon_lenght_muon_PID", "selmuon_lenght_muon_PID", 10, 0, 500);
   selmuon_lenght_proton_PID= new TH1D("selmuon_lenght_proton_PID", "selmuon_lenght_proton_PID", 10, 0, 500);
   selmuon_lenght_pion_PID= new TH1D("selmuon_lenght_pion_PID", "selmuon_lenght_pion_PID", 10, 0, 500);
   selmuon_lenght_electron_PID= new TH1D("selmuon_lenght_electron_PID", "selmuon_lenght_electron_PID", 10, 0, 500);
   selmuon_lenght_pother_PID= new TH1D("selmuon_lenght_pother_PID", "selmuon_lenght_pother_PID", 10, 0, 500);
   ////   
   selmuon_mom_muon_PID= new TH1D("selmuon_mom_muon_PID", "selmuon_mom_muon_PID", 10, 0, 3);
   selmuon_mom_proton_PID= new TH1D("selmuon_mom_proton_PID", "selmuon_mom_proton_PID", 10, 0, 3);
   selmuon_mom_pion_PID= new TH1D("selmuon_mom_pion_PID", "selmuon_mom_pion_PID", 10, 0, 3);
   selmuon_mom_electron_PID= new TH1D("selmuon_mom_electron_PID", "selmuon_mom_electron_PID", 10, 0, 3);
   selmuon_mom_pother_PID= new TH1D("selmuon_mom_pother_PID", "selmuon_mom_pother_PID", 10, 0, 3);
   ///
   selmuon_contained_mom_muon_PID= new TH1D("selmuon_contained_mom_muon_PID", "selmuon_contained_mom_muon_PID", 10, 0, 3);
   selmuon_contained_mom_proton_PID= new TH1D("selmuon_contained_mom_proton_PID", "selmuon_contained_mom_proton_PID", 10, 0, 3);
   selmuon_contained_mom_pion_PID= new TH1D("selmuon_contained_mom_pion_PID", "selmuon_contained_mom_pion_PID", 10, 0, 3);
   selmuon_contained_mom_electron_PID= new TH1D("selmuon_contained_mom_electron_PID", "selmuon_contained_mom_electron_PID", 10, 0, 3);
   selmuon_contained_mom_pother_PID= new TH1D("selmuon_contained_mom_pother_PID", "selmuon_contained_mom_pother_PID", 10, 0, 3);
   ///
   selmuon_uncontained_mom_muon_PID= new TH1D("selmuon_uncontained_mom_muon_PID", "selmuon_uncontained_mom_muon_PID", 10, 0, 3);
   selmuon_uncontained_mom_proton_PID= new TH1D("selmuon_uncontained_mom_proton_PID", "selmuon_uncontained_mom_proton_PID", 10, 0, 3);
   selmuon_uncontained_mom_pion_PID= new TH1D("selmuon_uncontained_mom_pion_PID", "selmuon_uncontained_mom_pion_PID", 10, 0, 3);
   selmuon_uncontained_mom_electron_PID= new TH1D("selmuon_uncontained_mom_electron_PID", "selmuon_uncontained_mom_electron_PID", 10, 0, 3);
   selmuon_uncontained_mom_pother_PID= new TH1D("selmuon_uncontained_mom_pother_PID", "selmuon_uncontained_mom_pother_PID", 10, 0, 3);

   ///
   selmuon_costheta_muon_PID= new TH1D("selmuon_costheta_muon_PID", "selmuon_costheta_muon_PID", 10, -1, 1);
   selmuon_costheta_proton_PID= new TH1D("selmuon_costheta_proton_PID", "selmuon_costheta_proton_PID", 10, -1, 1);
   selmuon_costheta_pion_PID= new TH1D("selmuon_costheta_pion_PID", "selmuon_costheta_pion_PID", 10, -1, 1);
   selmuon_costheta_electron_PID= new TH1D("selmuon_costheta_electron_PID", "selmuon_costheta_electron_PID", 10, -1, 1);
   selmuon_costheta_pother_PID= new TH1D("selmuon_costheta_pother_PID", "selmuon_costheta_pother_PID", 10, -1, 1);
   ///
   selmuon_phi_muon_PID= new TH1D("selmuon_phi_muon_PID", "selmuon_phi_muon_PID", 10, -3.14, 3.14);
   selmuon_phi_proton_PID= new TH1D("selmuon_phi_proton_PID", "selmuon_phi_proton_PID", 10, -3.14, 3.14);
   selmuon_phi_pion_PID= new TH1D("selmuon_phi_pion_PID", "selmuon_phi_pion_PID", 10, -3.14, 3.14);
   selmuon_phi_electron_PID= new TH1D("selmuon_phi_electron_PID", "selmuon_phi_electron_PID", 10, -3.14, 3.14);
   selmuon_phi_pother_PID= new TH1D("selmuon_phi_pother_PID", "selmuon_phi_pother_PID", 10, -3.14, 3.14);

   selmuon_chi2proton_muon_PID= new TH1D("selmuon_chi2proton_muon_PID", "selmuon_chi2proton_muon_PID", 30, 0, 300);
   selmuon_chi2proton_proton_PID= new TH1D("selmuon_chi2proton_proton_PID", "selmuon_chi2proton_proton_PID", 30, 0, 300);
   selmuon_chi2proton_pion_PID= new TH1D("selmuon_chi2proton_pion_PID", "selmuon_chi2proton_pion_PID", 30, 0, 300);
   selmuon_chi2proton_electron_PID= new TH1D("selmuon_chi2proton_electron_PID", "selmuon_chi2proton_electron_PID", 30, 0, 300);
   selmuon_chi2proton_pother_PID= new TH1D("selmuon_chi2proton_pother_PID", "selmuon_chi2proton_pother_PID", 30, 0, 300);

   selmuon_chi2proton_cont_muon_PID= new TH1D("selmuon_chi2proton_cont_muon_PID", "selmuon_chi2proton_cont_muon_PID", 30, 0, 300);
   selmuon_chi2proton_cont_proton_PID= new TH1D("selmuon_chi2proton_cont_proton_PID", "selmuon_chi2proton_cont_proton_PID", 30, 0, 300);
   selmuon_chi2proton_cont_pion_PID= new TH1D("selmuon_chi2proton_cont_pion_PID", "selmuon_chi2proton_cont_pion_PID", 30, 0, 300);
   selmuon_chi2proton_cont_electron_PID= new TH1D("selmuon_chi2proton_cont_electron_PID", "selmuon_chi2proton_cont_electron_PID", 30, 0, 300);
   selmuon_chi2proton_cont_pother_PID= new TH1D("selmuon_chi2proton_cont_pother_PID", "selmuon_chi2proton_cont_pother_PID", 30, 0, 300);

   selmuon_chi2proton_uncont_muon_PID= new TH1D("selmuon_chi2proton_uncont_muon_PID", "selmuon_chi2proton_uncont_muon_PID", 30, 0, 300);
   selmuon_chi2proton_uncont_proton_PID= new TH1D("selmuon_chi2proton_uncont_proton_PID", "selmuon_chi2proton_uncont_proton_PID", 30, 0, 300);
   selmuon_chi2proton_uncont_pion_PID= new TH1D("selmuon_chi2proton_uncont_pion_PID", "selmuon_chi2proton_uncont_pion_PID", 30, 0, 300);
   selmuon_chi2proton_uncont_electron_PID= new TH1D("selmuon_chi2proton_uncont_electron_PID", "selmuon_chi2proton_uncont_electron_PID", 30, 0, 300);
   selmuon_chi2proton_uncont_pother_PID= new TH1D("selmuon_chi2proton_uncont_pother_PID", "selmuon_chi2proton_uncont_pother_PID", 30, 0, 300);
   
   selmuon_dEdx_vs_resrange_muon_PID = new TH2D("selmuon_dEdx_vs_resrange_muon_PID", "selmuon_dEdx_vs_resrange_muon_PID", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_proton_PID = new TH2D("selmuon_dEdx_vs_resrange_proton_PID", "selmuon_dEdx_vs_resrange_proton_PID", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_pion_PID = new TH2D("selmuon_dEdx_vs_resrange_pion_PID", "selmuon_dEdx_vs_resrange_pion_PID", 50,0,50,20, 0, 20);

///proton properties
   selproton1_lenght_CC0Pion0Proton_PID= new TH1D("selproton1_lenght_CC0Pion0Proton_PID", "selproton1_lenght_CC0Pion0Proton_PID", 10, 0, 100);
   selproton1_lenght_CC0Pion1Proton_PID= new TH1D("selproton1_lenght_CC0Pion1Proton_PID", "selproton1_lenght_CC0Pion1Proton_PID", 10, 0, 100);
   selproton1_lenght_CC0Pion2Proton_PID= new TH1D("selproton1_lenght_CC0Pion2Proton_PID", "selproton1_lenght_CC0Pion2Proton_PID", 10, 0, 100);
   selproton1_lenght_CC0PionNProton_PID= new TH1D("selproton1_lenght_CC0PionNProton_PID", "selproton1_lenght_CC0PionNProton_PID", 10, 0, 100);
   selproton1_lenght_CC1PionNProton_PID= new TH1D("selproton1_lenght_CC1PionNProton_PID", "selproton1_lenght_CC1PionNProton_PID", 10, 0, 100);
   selproton1_lenght_CCNPionNProton_PID= new TH1D("selproton1_lenght_CCNPionNProton_PID", "selproton1_lenght_CCNPionNProton_PID", 10, 0, 100);
   selproton1_lenght_CCNue_PID= new TH1D("selproton1_lenght_CCNue_PID", "selproton1_lenght_CCNue_PID", 10, 0, 100);   
   selproton1_lenght_NC_PID= new TH1D("selproton1_lenght_NC_PID", "selproton1_lenght_NC_PID", 10, 0, 100);
   selproton1_lenght_OOFV_PID= new TH1D("selproton1_lenght_OOFV_PID", "selproton1_lenght_OOFV_PID", 10, 0, 100);
   selproton1_lenght_EXT_PID= new TH1D("selproton1_lenght_EXT_PID", "selproton1_lenght_EXT_PID", 10, 0, 100);
   selproton1_lenght_other_PID= new TH1D("selproton1_lenght_other_PID", "selproton1_lenght_other_PID", 10, 0, 100);
   
   //////////////////////
   selproton1_costheta_CC0Pion0Proton_PID= new TH1D("selproton1_costheta_CC0Pion0Proton_PID", "selproton1_costheta_CC0Pion0Proton_PID", 10, -1, 1);
   selproton1_costheta_CC0Pion1Proton_PID= new TH1D("selproton1_costheta_CC0Pion1Proton_PID", "selproton1_costheta_CC0Pion1Proton_PID", 10, -1, 1);
   selproton1_costheta_CC0Pion2Proton_PID= new TH1D("selproton1_costheta_CC0Pion2Proton_PID", "selproton1_costheta_CC0Pion2Proton_PID", 10, -1, 1);
   selproton1_costheta_CC0PionNProton_PID= new TH1D("selproton1_costheta_CC0PionNProton_PID", "selproton1_costheta_CC0PionNProton_PID", 10, -1, 1);
   selproton1_costheta_CC1PionNProton_PID= new TH1D("selproton1_costheta_CC1PionNProton_PID", "selproton1_costheta_CC1PionNProton_PID", 10, -1, 1);
   selproton1_costheta_CCNPionNProton_PID= new TH1D("selproton1_costheta_CCNPionNProton_PID", "selproton1_costheta_CCNPionNProton_PID", 10, -1, 1);
   selproton1_costheta_CCNue_PID= new TH1D("selproton1_costheta_CCNue_PID", "selproton1_costheta_CCNue_PID", 10, -1, 1);   
   selproton1_costheta_NC_PID= new TH1D("selproton1_costheta_NC_PID", "selproton1_costheta_NC_PID", 10, -1, 1);
   selproton1_costheta_OOFV_PID= new TH1D("selproton1_costheta_OOFV_PID", "selproton1_costheta_OOFV_PID", 10, -1, 1);
   selproton1_costheta_EXT_PID= new TH1D("selproton1_costheta_EXT_PID", "selproton1_costheta_EXT_PID", 10, -1, 1);
   selproton1_costheta_other_PID= new TH1D("selproton1_costheta_other_PID", "selproton1_costheta_other_PID", 10, -1, 1); 
   /////
   selproton1_phi_CC0Pion0Proton_PID= new TH1D("selproton1_phi_CC0Pion0Proton_PID", "selproton1_phi_CC0Pion0Proton_PID", 10, -3.14, 3.14);
   selproton1_phi_CC0Pion1Proton_PID= new TH1D("selproton1_phi_CC0Pion1Proton_PID", "selproton1_phi_CC0Pion1Proton_PID", 10, -3.14, 3.14);
   selproton1_phi_CC0Pion2Proton_PID= new TH1D("selproton1_phi_CC0Pion2Proton_PID", "selproton1_phi_CC0Pion2Proton_PID", 10, -3.14, 3.14);
   selproton1_phi_CC0PionNProton_PID= new TH1D("selproton1_phi_CC0PionNProton_PID", "selproton1_phi_CC0PionNProton_PID", 10, -3.14, 3.14);
   selproton1_phi_CC1PionNProton_PID= new TH1D("selproton1_phi_CC1PionNProton_PID", "selproton1_phi_CC1PionNProton_PID", 10, -3.14, 3.14);
   selproton1_phi_CCNPionNProton_PID= new TH1D("selproton1_phi_CCNPionNProton_PID", "selproton1_phi_CCNPionNProton_PID", 10, -3.14, 3.14);
   selproton1_phi_CCNue_PID= new TH1D("selproton1_phi_CCNue_PID", "selproton1_phi_CCNue_PID", 10, -3.14, 3.14);   
   selproton1_phi_NC_PID= new TH1D("selproton1_phi_NC_PID", "selproton1_phi_NC_PID", 10, -3.14, 3.14);
   selproton1_phi_OOFV_PID= new TH1D("selproton1_phi_OOFV_PID", "selproton1_phi_OOFV_PID", 10, -3.14, 3.14);
   selproton1_phi_EXT_PID= new TH1D("selproton1_phi_EXT_PID", "selproton1_phi_EXT_PID", 10, -3.14, 3.14);
   selproton1_phi_other_PID= new TH1D("selproton1_phi_other_PID", "selproton1_phi_other_PID", 10, -3.14, 3.14); 
 
   selproton1_mom_CC0Pion0Proton_PID= new TH1D("selproton1_mom_CC0Pion0Proton_PID", "selproton1_mom_CC0Pion0Proton_PID", 10, 0, 1.5);
   selproton1_mom_CC0Pion1Proton_PID= new TH1D("selproton1_mom_CC0Pion1Proton_PID", "selproton1_mom_CC0Pion1Proton_PID", 10, 0, 1.5);
   selproton1_mom_CC0Pion2Proton_PID= new TH1D("selproton1_mom_CC0Pion2Proton_PID", "selproton1_mom_CC0Pion2Proton_PID", 10, 0, 1.5);
   selproton1_mom_CC0PionNProton_PID= new TH1D("selproton1_mom_CC0PionNProton_PID", "selproton1_mom_CC0PionNProton_PID", 10, 0, 1.5);
   selproton1_mom_CC1PionNProton_PID= new TH1D("selproton1_mom_CC1PionNProton_PID", "selproton1_mom_CC1PionNProton_PID", 10, 0, 1.5);
   selproton1_mom_CCNPionNProton_PID= new TH1D("selproton1_mom_CCNPionNProton_PID", "selproton1_mom_CCNPionNProton_PID", 10, 0, 1.5);
   selproton1_mom_CCNue_PID= new TH1D("selproton1_mom_CCNue_PID", "selproton1_mom_CCNue_PID", 10, 0, 1.5);   
   selproton1_mom_NC_PID= new TH1D("selproton1_mom_NC_PID", "selproton1_mom_NC_PID", 10, 0, 1.5);
   selproton1_mom_OOFV_PID= new TH1D("selproton1_mom_OOFV_PID", "selproton1_mom_OOFV_PID", 10, 0, 1.5);
   selproton1_mom_EXT_PID= new TH1D("selproton1_mom_EXT_PID", "selproton1_mom_EXT_PID", 10, 0, 1.5);
   selproton1_mom_other_PID= new TH1D("selproton1_mom_other_PID", "selproton1_mom_other_PID", 10, 0, 1.5);

  //////

   selproton1_lenght_muon_PID= new TH1D("selproton1_lenght_muon_PID", "selproton1_lenght_muon_PID", 10, 0, 100);
   selproton1_lenght_proton_PID= new TH1D("selproton1_lenght_proton_PID", "selproton1_lenght_proton_PID", 10, 0, 100);
   selproton1_lenght_pion_PID= new TH1D("selproton1_lenght_pion_PID", "selproton1_lenght_pion_PID", 10, 0, 100);
   selproton1_lenght_electron_PID= new TH1D("selproton1_lenght_electron_PID", "selproton1_lenght_electron_PID", 10, 0, 100);
   selproton1_lenght_pother_PID= new TH1D("selproton1_lenght_pother_PID", "selproton1_lenght_pother_PID", 10, 0, 100);
   ////
   selproton1_costheta_muon_PID= new TH1D("selproton1_costheta_muon_PID", "selproton1_costheta_muon_PID", 10, -1, 1);
   selproton1_costheta_proton_PID= new TH1D("selproton1_costheta_proton_PID", "selproton1_costheta_proton_PID", 10, -1, 1);
   selproton1_costheta_pion_PID= new TH1D("selproton1_costheta_pion_PID", "selproton1_costheta_pion_PID", 10, -1, 1);
   selproton1_costheta_electron_PID= new TH1D("selproton1_costheta_electron_PID", "selproton1_costheta_electron_PID", 10, -1, 1);
   selproton1_costheta_pother_PID= new TH1D("selproton1_costheta_pother_PID", "selproton1_costheta_pother_PID", 10, -1, 1);
   ///
   selproton1_phi_muon_PID= new TH1D("selproton1_phi_muon_PID", "selproton1_phi_muon_PID", 10, -3.14, 3.14);
   selproton1_phi_proton_PID= new TH1D("selproton1_phi_proton_PID", "selproton1_phi_proton_PID", 10, -3.14, 3.14);
   selproton1_phi_pion_PID= new TH1D("selproton1_phi_pion_PID", "selproton1_phi_pion_PID", 10, -3.14, 3.14);
   selproton1_phi_electron_PID= new TH1D("selproton1_phi_electron_PID", "selproton1_phi_electron_PID", 10, -3.14, 3.14);
   selproton1_phi_pother_PID= new TH1D("selproton1_phi_pother_PID", "selproton1_phi_pother_PID", 10, -3.14, 3.14);

   selproton1_chi2proton_muon_PID= new TH1D("selproton1_chi2proton_muon_PID", "selproton1_chi2proton_muon_PID", 10, 0, 300);
   selproton1_chi2proton_proton_PID= new TH1D("selproton1_chi2proton_proton_PID", "selproton1_chi2proton_proton_PID", 10, 0, 300);
   selproton1_chi2proton_pion_PID= new TH1D("selproton1_chi2proton_pion_PID", "selproton1_chi2proton_pion_PID", 10, 0, 300);
   selproton1_chi2proton_electron_PID= new TH1D("selproton1_chi2proton_electron_PID", "selproton1_chi2proton_electron_PID", 10, 0, 300);
   selproton1_chi2proton_pother_PID= new TH1D("selproton1_chi2proton_pother_PID", "selproton1_chi2proton_pother_PID", 10, 0, 300);

   selproton1_dEdx_vs_resrange_muon_PID = new TH2D("selproton1_dEdx_vs_resrange_muon_PID", "selproton1_dEdx_vs_resrange_muon_PID", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_proton_PID = new TH2D("selproton1_dEdx_vs_resrange_proton_PID", "selproton1_dEdx_vs_resrange_proton_PID", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_pion_PID = new TH2D("selproton1_dEdx_vs_resrange_pion_PID", "selproton1_dEdx_vs_resrange_pion_PID", 50,0,50,20, 0, 20);

   //////////////////////////////// proton 2///////////////
   
   selproton2_lenght_CC0Pion0Proton_PID= new TH1D("selproton2_lenght_CC0Pion0Proton_PID", "selproton2_lenght_CC0Pion0Proton_PID", 10, 0, 40);
   selproton2_lenght_CC0Pion1Proton_PID= new TH1D("selproton2_lenght_CC0Pion1Proton_PID", "selproton2_lenght_CC0Pion1Proton_PID", 10, 0, 40);
   selproton2_lenght_CC0Pion2Proton_PID= new TH1D("selproton2_lenght_CC0Pion2Proton_PID", "selproton2_lenght_CC0Pion2Proton_PID", 10, 0, 40);
   selproton2_lenght_CC0PionNProton_PID= new TH1D("selproton2_lenght_CC0PionNProton_PID", "selproton2_lenght_CC0PionNProton_PID", 10, 0, 40);
   selproton2_lenght_CC1PionNProton_PID= new TH1D("selproton2_lenght_CC1PionNProton_PID", "selproton2_lenght_CC1PionNProton_PID", 10, 0, 40);
   selproton2_lenght_CCNPionNProton_PID= new TH1D("selproton2_lenght_CCNPionNProton_PID", "selproton2_lenght_CCNPionNProton_PID", 10, 0, 40);
   selproton2_lenght_CCNue_PID= new TH1D("selproton2_lenght_CCNue_PID", "selproton2_lenght_CCNue_PID", 10, 0, 40);
   selproton2_lenght_NC_PID= new TH1D("selproton2_lenght_NC_PID", "selproton2_lenght_NC_PID", 10, 0, 40);
   selproton2_lenght_OOFV_PID= new TH1D("selproton2_lenght_OOFV_PID", "selproton2_lenght_OOFV_PID", 10, 0, 40);
   selproton2_lenght_EXT_PID= new TH1D("selproton2_lenght_EXT_PID", "selproton2_lenght_EXT_PID", 10, 0, 40);
   selproton2_lenght_other_PID= new TH1D("selproton2_lenght_other_PID", "selproton2_lenght_other_PID", 10, 0, 40);

   selproton2_costheta_CC0Pion0Proton_PID= new TH1D("selproton2_costheta_CC0Pion0Proton_PID", "selproton2_costheta_CC0Pion0Proton_PID", 10, -1, 1);
   selproton2_costheta_CC0Pion1Proton_PID= new TH1D("selproton2_costheta_CC0Pion1Proton_PID", "selproton2_costheta_CC0Pion1Proton_PID", 10, -1, 1);
   selproton2_costheta_CC0Pion2Proton_PID= new TH1D("selproton2_costheta_CC0Pion2Proton_PID", "selproton2_costheta_CC0Pion2Proton_PID", 10, -1, 1);
   selproton2_costheta_CC0PionNProton_PID= new TH1D("selproton2_costheta_CC0PionNProton_PID", "selproton2_costheta_CC0PionNProton_PID", 10, -1, 1);
   selproton2_costheta_CC1PionNProton_PID= new TH1D("selproton2_costheta_CC1PionNProton_PID", "selproton2_costheta_CC1PionNProton_PID", 10, -1, 1);
   selproton2_costheta_CCNPionNProton_PID= new TH1D("selproton2_costheta_CCNPionNProton_PID", "selproton2_costheta_CCNPionNProton_PID", 10, -1, 1);
   selproton2_costheta_CCNue_PID= new TH1D("selproton2_costheta_CCNue_PID", "selproton2_costheta_CCNue_PID", 10, -1, 1);   
   selproton2_costheta_NC_PID= new TH1D("selproton2_costheta_NC_PID", "selproton2_costheta_NC_PID", 10, -1, 1);
   selproton2_costheta_OOFV_PID= new TH1D("selproton2_costheta_OOFV_PID", "selproton2_costheta_OOFV_PID", 10, -1, 1);
   selproton2_costheta_EXT_PID= new TH1D("selproton2_costheta_EXT_PID", "selproton2_costheta_EXT_PID", 10, -1, 1);
   selproton2_costheta_other_PID= new TH1D("selproton2_costheta_other_PID", "selproton2_costheta_other_PID", 10, -1, 1); 
   /////
   selproton2_phi_CC0Pion0Proton_PID= new TH1D("selproton2_phi_CC0Pion0Proton_PID", "selproton2_phi_CC0Pion0Proton_PID", 10, -3.14, 3.14);
   selproton2_phi_CC0Pion1Proton_PID= new TH1D("selproton2_phi_CC0Pion1Proton_PID", "selproton2_phi_CC0Pion1Proton_PID", 10, -3.14, 3.14);
   selproton2_phi_CC0Pion2Proton_PID= new TH1D("selproton2_phi_CC0Pion2Proton_PID", "selproton2_phi_CC0Pion2Proton_PID", 10, -3.14, 3.14);
   selproton2_phi_CC0PionNProton_PID= new TH1D("selproton2_phi_CC0PionNProton_PID", "selproton2_phi_CC0PionNProton_PID", 10, -3.14, 3.14);
   selproton2_phi_CC1PionNProton_PID= new TH1D("selproton2_phi_CC1PionNProton_PID", "selproton2_phi_CC1PionNProton_PID", 10, -3.14, 3.14);
   selproton2_phi_CCNPionNProton_PID= new TH1D("selproton2_phi_CCNPionNProton_PID", "selproton2_phi_CCNPionNProton_PID", 10, -3.14, 3.14);
   selproton2_phi_CCNue_PID= new TH1D("selproton2_phi_CCNue_PID", "selproton2_phi_CCNue_PID", 10, -3.14, 3.14);   
   selproton2_phi_NC_PID= new TH1D("selproton2_phi_NC_PID", "selproton2_phi_NC_PID", 10, -3.14, 3.14);
   selproton2_phi_OOFV_PID= new TH1D("selproton2_phi_OOFV_PID", "selproton2_phi_OOFV_PID", 10, -3.14, 3.14);
   selproton2_phi_EXT_PID= new TH1D("selproton2_phi_EXT_PID", "selproton2_phi_EXT_PID", 10, -3.14, 3.14);
   selproton2_phi_other_PID= new TH1D("selproton2_phi_other_PID", "selproton2_phi_other_PID", 10, -3.14, 3.14); 
   //////
   selproton2_mom_CC0Pion0Proton_PID= new TH1D("selproton2_mom_CC0Pion0Proton_PID", "selproton2_mom_CC0Pion0Proton_PID", 10, 0, 1.);
   selproton2_mom_CC0Pion1Proton_PID= new TH1D("selproton2_mom_CC0Pion1Proton_PID", "selproton2_mom_CC0Pion1Proton_PID", 10, 0, 1.);
   selproton2_mom_CC0Pion2Proton_PID= new TH1D("selproton2_mom_CC0Pion2Proton_PID", "selproton2_mom_CC0Pion2Proton_PID", 10, 0, 1.);
   selproton2_mom_CC0PionNProton_PID= new TH1D("selproton2_mom_CC0PionNProton_PID", "selproton2_mom_CC0PionNProton_PID", 10, 0, 1.);
   selproton2_mom_CC1PionNProton_PID= new TH1D("selproton2_mom_CC1PionNProton_PID", "selproton2_mom_CC1PionNProton_PID", 10, 0, 1.);
   selproton2_mom_CCNPionNProton_PID= new TH1D("selproton2_mom_CCNPionNProton_PID", "selproton2_mom_CCNPionNProton_PID", 10, 0, 1.);
   selproton2_mom_CCNue_PID= new TH1D("selproton2_mom_CCNue_PID", "selproton2_mom_CCNue_PID", 10, 0, 1.);   
   selproton2_mom_NC_PID= new TH1D("selproton2_mom_NC_PID", "selproton2_mom_NC_PID", 10, 0, 1.);
   selproton2_mom_OOFV_PID= new TH1D("selproton2_mom_OOFV_PID", "selproton2_mom_OOFV_PID", 10, 0, 1.);
   selproton2_mom_EXT_PID= new TH1D("selproton2_mom_EXT_PID", "selproton2_mom_EXT_PID", 10, 0, 1.);
   selproton2_mom_other_PID= new TH1D("selproton2_mom_other_PID", "selproton2_mom_other_PID", 10, 0, 1.);

   /////

   selproton2_lenght_muon_PID= new TH1D("selproton2_lenght_muon_PID", "selproton2_lenght_muon_PID", 10, 0, 40);
   selproton2_lenght_proton_PID= new TH1D("selproton2_lenght_proton_PID", "selproton2_lenght_proton_PID", 10, 0, 40);
   selproton2_lenght_pion_PID= new TH1D("selproton2_lenght_pion_PID", "selproton2_lenght_pion_PID", 10, 0, 40);
   selproton2_lenght_electron_PID= new TH1D("selproton2_lenght_electron_PID", "selproton2_lenght_electron_PID", 10, 0, 40);
   selproton2_lenght_pother_PID= new TH1D("selproton2_lenght_pother_PID", "selproton2_lenght_pother_PID", 10, 0, 40);
   ////
   selproton2_costheta_muon_PID= new TH1D("selproton2_costheta_muon_PID", "selproton2_costheta_muon_PID", 10, -1, 1);
   selproton2_costheta_proton_PID= new TH1D("selproton2_costheta_proton_PID", "selproton2_costheta_proton_PID", 10, -1, 1);
   selproton2_costheta_pion_PID= new TH1D("selproton2_costheta_pion_PID", "selproton2_costheta_pion_PID", 10, -1, 1);
   selproton2_costheta_electron_PID= new TH1D("selproton2_costheta_electron_PID", "selproton2_costheta_electron_PID", 10, -1, 1);
   selproton2_costheta_pother_PID= new TH1D("selproton2_costheta_pother_PID", "selproton2_costheta_pother_PID", 10, -1, 1);
   ///
   selproton2_phi_muon_PID= new TH1D("selproton2_phi_muon_PID", "selproton2_phi_muon_PID", 10, -3.14, 3.14);
   selproton2_phi_proton_PID= new TH1D("selproton2_phi_proton_PID", "selproton2_phi_proton_PID", 10, -3.14, 3.14);
   selproton2_phi_pion_PID= new TH1D("selproton2_phi_pion_PID", "selproton2_phi_pion_PID", 10, -3.14, 3.14);
   selproton2_phi_electron_PID= new TH1D("selproton2_phi_electron_PID", "selproton2_phi_electron_PID", 10, -3.14, 3.14);
   selproton2_phi_pother_PID= new TH1D("selproton2_phi_pother_PID", "selproton2_phi_pother_PID", 10, -3.14, 3.14);

   selproton2_chi2proton_muon_PID= new TH1D("selproton2_chi2proton_muon_PID", "selproton2_chi2proton_muon_PID", 10, 0, 300);
   selproton2_chi2proton_proton_PID= new TH1D("selproton2_chi2proton_proton_PID", "selproton2_chi2proton_proton_PID", 10, 0, 300);
   selproton2_chi2proton_pion_PID= new TH1D("selproton2_chi2proton_pion_PID", "selproton2_chi2proton_pion_PID", 10, 0, 300);
   selproton2_chi2proton_electron_PID= new TH1D("selproton2_chi2proton_electron_PID", "selproton2_chi2proton_electron_PID", 10, 0, 300);
   selproton2_chi2proton_pother_PID= new TH1D("selproton2_chi2proton_pother_PID", "selproton2_chi2proton_pother_PID", 10, 0, 300);

   selproton2_dEdx_vs_resrange_muon_PID = new TH2D("selproton2_dEdx_vs_resrange_muon_PID", "selproton2_dEdx_vs_resrange_muon_PID", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_proton_PID = new TH2D("selproton2_dEdx_vs_resrange_proton_PID", "selproton2_dEdx_vs_resrange_proton_PID", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_pion_PID = new TH2D("selproton2_dEdx_vs_resrange_pion_PID", "selproton2_dEdx_vs_resrange_pion_PID", 50,0,50,20, 0, 20);

   //// Opening angles
   angle_mup1_CC0Pion0Proton_PID= new TH1D("angle_mup1_CC0Pion0Proton_PID", "angle_mup1_CC0Pion0Proton_PID", 10, -1,1);
   angle_mup1_CC0Pion1Proton_PID= new TH1D("angle_mup1_CC0Pion1Proton_PID", "angle_mup1_CC0Pion1Proton_PID", 10, -1,1);
   angle_mup1_CC0Pion2Proton_PID= new TH1D("angle_mup1_CC0Pion2Proton_PID", "angle_mup1_CC0Pion2Proton_PID", 10, -1,1);
   angle_mup1_CC0PionNProton_PID= new TH1D("angle_mup1_CC0PionNProton_PID", "angle_mup1_CC0PionNProton_PID", 10, -1,1);
   angle_mup1_CC1PionNProton_PID= new TH1D("angle_mup1_CC1PionNProton_PID", "angle_mup1_CC1PionNProton_PID", 10, -1,1);
   angle_mup1_CCNPionNProton_PID= new TH1D("angle_mup1_CCNPionNProton_PID", "angle_mup1_CCNPionNProton_PID", 10, -1,1);
   angle_mup1_CCNue_PID= new TH1D("angle_mup1_CCNue_PID", "angle_mup1_CCNue_PID", 10, -1,1);
   angle_mup1_NC_PID= new TH1D("angle_mup1_NC_PID", "angle_mup1_NC_PID", 10, -1,1);
   angle_mup1_OOFV_PID= new TH1D("angle_mup1_OOFV_PID", "angle_mup1_OOFV_PID", 10, -1,1);
   angle_mup1_EXT_PID= new TH1D("angle_mup1_EXT_PID", "angle_mup1_EXT_PID", 10, -1,1);
   angle_mup1_other_PID= new TH1D("angle_mup1_other_PID", "angle_mup1_other_PID", 10, -1,1);   
 
   angle_mup2_CC0Pion0Proton_PID= new TH1D("angle_mup2_CC0Pion0Proton_PID", "angle_mup2_CC0Pion0Proton_PID", 10, -1,1);
   angle_mup2_CC0Pion1Proton_PID= new TH1D("angle_mup2_CC0Pion1Proton_PID", "angle_mup2_CC0Pion1Proton_PID", 10, -1,1);
   angle_mup2_CC0Pion2Proton_PID= new TH1D("angle_mup2_CC0Pion2Proton_PID", "angle_mup2_CC0Pion2Proton_PID", 10, -1,1);
   angle_mup2_CC0PionNProton_PID= new TH1D("angle_mup2_CC0PionNProton_PID", "angle_mup2_CC0PionNProton_PID", 10, -1,1);
   angle_mup2_CC1PionNProton_PID= new TH1D("angle_mup2_CC1PionNProton_PID", "angle_mup2_CC1PionNProton_PID", 10, -1,1);
   angle_mup2_CCNPionNProton_PID= new TH1D("angle_mup2_CCNPionNProton_PID", "angle_mup2_CCNPionNProton_PID", 10, -1,1);
   angle_mup2_CCNue_PID= new TH1D("angle_mup2_CCNue_PID", "angle_mup2_CCNue_PID", 10, -1,1);
   angle_mup2_NC_PID= new TH1D("angle_mup2_NC_PID", "angle_mup2_NC_PID", 10, -1,1);
   angle_mup2_OOFV_PID= new TH1D("angle_mup2_OOFV_PID", "angle_mup2_OOFV_PID", 10, -1,1);
   angle_mup2_EXT_PID= new TH1D("angle_mup2_EXT_PID", "angle_mup2_EXT_PID", 10, -1,1);
   angle_mup2_other_PID= new TH1D("angle_mup2_other_PID", "angle_mup2_other_PID", 10, -1,1);   
 
   angle_p1p2_CC0Pion0Proton_PID= new TH1D("angle_p1p2_CC0Pion0Proton_PID", "angle_p1p2_CC0Pion0Proton_PID", 10, -1,1);
   angle_p1p2_CC0Pion1Proton_PID= new TH1D("angle_p1p2_CC0Pion1Proton_PID", "angle_p1p2_CC0Pion1Proton_PID", 10, -1,1);
   angle_p1p2_CC0Pion2Proton_PID= new TH1D("angle_p1p2_CC0Pion2Proton_PID", "angle_p1p2_CC0Pion2Proton_PID", 10, -1,1);
   angle_p1p2_CC0PionNProton_PID= new TH1D("angle_p1p2_CC0PionNProton_PID", "angle_p1p2_CC0PionNProton_PID", 10, -1,1);
   angle_p1p2_CC1PionNProton_PID= new TH1D("angle_p1p2_CC1PionNProton_PID", "angle_p1p2_CC1PionNProton_PID", 10, -1,1);
   angle_p1p2_CCNPionNProton_PID= new TH1D("angle_p1p2_CCNPionNProton_PID", "angle_p1p2_CCNPionNProton_PID", 10, -1,1);
   angle_p1p2_CCNue_PID= new TH1D("angle_p1p2_CCNue_PID", "angle_p1p2_CCNue_PID", 10, -1,1);
   angle_p1p2_NC_PID= new TH1D("angle_p1p2_NC_PID", "angle_p1p2_NC_PID", 10, -1,1);
   angle_p1p2_OOFV_PID= new TH1D("angle_p1p2_OOFV_PID", "angle_p1p2_OOFV_PID", 10, -1,1);
   angle_p1p2_EXT_PID= new TH1D("angle_p1p2_EXT_PID", "angle_p1p2_EXT_PID", 10, -1,1);
   angle_p1p2_other_PID= new TH1D("angle_p1p2_other_PID", "angle_p1p2_other_PID", 10, -1,1);   
  
   cosangle_p1p2_CC0Pion0Proton_PID= new TH1D("cosangle_p1p2_CC0Pion0Proton_PID", "cosangle_p1p2_CC0Pion0Proton_PID", 10, -1,1);
   cosangle_p1p2_CC0Pion1Proton_PID= new TH1D("cosangle_p1p2_CC0Pion1Proton_PID", "cosangle_p1p2_CC0Pion1Proton_PID", 10, -1,1);
   cosangle_p1p2_CC0Pion2Proton_PID= new TH1D("cosangle_p1p2_CC0Pion2Proton_PID", "cosangle_p1p2_CC0Pion2Proton_PID", 10, -1,1);
   cosangle_p1p2_CC0PionNProton_PID= new TH1D("cosangle_p1p2_CC0PionNProton_PID", "cosangle_p1p2_CC0PionNProton_PID", 10, -1,1);
   cosangle_p1p2_CC1PionNProton_PID= new TH1D("cosangle_p1p2_CC1PionNProton_PID", "cosangle_p1p2_CC1PionNProton_PID", 10, -1,1);
   cosangle_p1p2_CCNPionNProton_PID= new TH1D("cosangle_p1p2_CCNPionNProton_PID", "cosangle_p1p2_CCNPionNProton_PID", 10, -1,1);
   cosangle_p1p2_CCNue_PID= new TH1D("cosangle_p1p2_CCNue_PID", "cosangle_p1p2_CCNue_PID", 10, -1,1);
   cosangle_p1p2_NC_PID= new TH1D("cosangle_p1p2_NC_PID", "cosangle_p1p2_NC_PID", 10, -1,1);
   cosangle_p1p2_OOFV_PID= new TH1D("cosangle_p1p2_OOFV_PID", "cosangle_p1p2_OOFV_PID", 10, -1,1);
   cosangle_p1p2_EXT_PID= new TH1D("cosangle_p1p2_EXT_PID", "cosangle_p1p2_EXT_PID", 10, -1, 1);
   cosangle_p1p2_other_PID= new TH1D("cosangle_p1p2_other_PID", "cosangle_p1p2_other_PID", 10, -1,1);   
  
   //// resolutions

   selmuon_mom_res_PID = new TH2D("selmuon_mom_res_PID", "selmuon_mom_res_PID",10, 0, 2, 10,-2,2);
   selmuon_costheta_res_PID = new TH2D("selmuon_costheta_res_PID", "selmuon_costheta_res_PID", 10, -1, 1,10,-2,2);
   selmuon_phi_res_PID = new TH2D("selmuon_phi_res_PID", "selmuon_phi_res_PID",10, -3.1415, 3.1415, 10,-6,6);

   selproton1_mom_res_PID = new TH2D("selproton1_mom_res_PID", "selproton1_mom_res_PID",10, 0, 2, 10,-2,2);
   selproton1_costheta_res_PID = new TH2D("selproton1_costheta_res_PID", "selproton1_costheta_res_PID",10, -1, 1, 10,-2,2);
   selproton1_phi_res_PID = new TH2D("selproton1_phi_res_PID", "selproton1_phi_res_PID",10, -3.1415, 3.1415, 10,-6,6);

   selproton2_mom_res_PID = new TH2D("selproton2_mom_res_PID", "selproton2_mom_res_PID",10, 0, 2, 10,-2,2);
   selproton2_costheta_res_PID = new TH2D("selproton2_costheta_res_PID", "selproton2_costheta_res_PID",10, -1, 1, 10,-2,2);
   selproton2_phi_res_PID = new TH2D("selproton2_phi_res_PID", "selproton2_phi_res_PID",10, -3.1415, 3.1415, 10,-6,6);

   std::cout<<"histos declared"<<endl;
}

Bool_t hanalysis_Tune3_PID::Process(Long64_t entry)
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
   std::cout<<"before process"<<endl;

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

     //if(muind !=-1 &&p1ind !=-1 && p2ind !=-1 && muoninFV && tempflag){/// requirements
     if(muind !=-1 &&p1ind !=-1 && p2ind !=-1 && tempflag){/// requirements
       if(track_pfp_dEdx[muind].size()<5 ||track_pfp_dEdx[p1ind].size()<5 ||track_pfp_dEdx[p2ind].size()<5)  minColl=false;/// min coll hits
       if(minColl){
       if(track_pfp_chi2_proton[muind]>88. && track_pfp_chi2_proton[p1ind]<88. &&track_pfp_chi2_proton[p2ind]<88.){

       totentries++;
       /// opening angles

       float fPlep=*track_pfp_mom_mucand;
       float fPhad1=track_pfp_Mom_p[p1ind];
       float fPhad2=track_pfp_Mom_p[p2ind];
       float fThetaLep=TMath::ACos(track_pfp_costheta[muind]);
       float fThetaHad1=TMath::ACos(track_pfp_costheta[p1ind]);
       float fThetaHad2=TMath::ACos(track_pfp_costheta[p2ind]);
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

       std::cout<<"norm p1: "<<m1<<" norm p2: "<<m2<<" norm mu: "<<mu<<std::endl;
 
       double CosAnglep1p2 = trackpdir_p1.Dot(trackpdir_p2);   // scalar product
       CosAnglep1p2 =  CosAnglep1p2/(m1*m2);

       double CosAnglemup1 = trackpdir_mu.Dot(trackpdir_p1);   // scalar product
       CosAnglemup1 =  CosAnglemup1/(mu*m1);

       double CosAnglemup2 = trackpdir_mu.Dot(trackpdir_p2);   // scalar product
       CosAnglemup2 =  CosAnglemup2/(mu*m2);

       double anglemup1=CosAnglemup1;
       double anglemup2=CosAnglemup2;
       double anglep1p2=CosAnglep1p2;
       /*
       double anglemup1=muonP.Angle(protonP1);
       double anglemup2=muonP.Angle(protonP2);
       double anglep1p2=protonP1.Angle(protonP2);
       */
       ///


       selmuon_mom_res_PID->Fill(pfp_mom[muind],pfp_mom[muind]-track_pfp_Mom_p[muind]);
       selmuon_costheta_res_PID->Fill( pfp_costheta[muind],pfp_costheta[muind]-track_pfp_costheta[muind]);
       selmuon_phi_res_PID->Fill(pfp_phi[muind],pfp_phi[muind]-track_pfp_phi[muind]);

       selproton1_mom_res_PID->Fill(pfp_mom[p1ind],pfp_mom[p1ind]-track_pfp_Mom_p[p1ind]);
       selproton1_costheta_res_PID->Fill(pfp_costheta[p1ind],pfp_costheta[p1ind]-track_pfp_costheta[p1ind]);
       selproton1_phi_res_PID->Fill(pfp_phi[p1ind],pfp_phi[p1ind]-track_pfp_phi[p1ind]);

       selproton2_mom_res_PID->Fill(pfp_mom[p2ind],pfp_mom[p2ind]-track_pfp_Mom_p[p2ind]);
       selproton2_costheta_res_PID->Fill(pfp_costheta[p2ind],pfp_costheta[p2ind]-track_pfp_costheta[p2ind]);
       selproton2_phi_res_PID->Fill(pfp_phi[p2ind],pfp_phi[p2ind]-track_pfp_phi[p2ind]);

       if(*nu_ccnc==0 &&trackfromneutrino){
	 if( *nu_mode== 0) QE++;
	 else if(*nu_mode== 1) RES++;
	 else if(*nu_mode== 2) DIS++;
	 else if(*nu_mode== 3) COH++;
	 else if(*nu_mode== 10) MEC++;
       }

       if(*truthtop ==1 && trackfromneutrino){
	 topo1++;
	 selmuon_lenght_CC0Pion0Proton_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion0Proton_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion0Proton_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion0Proton_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion0Proton_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion0Proton_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion0Proton_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion0Proton_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion0Proton_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion0Proton_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0Pion0Proton_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0Pion0Proton_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0Pion0Proton_PID->Fill(anglemup1);
	 angle_mup2_CC0Pion0Proton_PID->Fill(anglemup2);
	 angle_p1p2_CC0Pion0Proton_PID->Fill(anglep1p2);
	 cosangle_p1p2_CC0Pion0Proton_PID->Fill(TMath::Cos(anglep1p2));
       }// topo1

       else if(*truthtop ==2 && trackfromneutrino){
	 topo2++;
	 selmuon_lenght_CC0Pion1Proton_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion1Proton_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion1Proton_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion1Proton_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion1Proton_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion1Proton_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion1Proton_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion1Proton_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion1Proton_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion1Proton_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0Pion1Proton_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0Pion1Proton_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0Pion1Proton_PID->Fill(anglemup1);
	 angle_mup2_CC0Pion1Proton_PID->Fill(anglemup2);
	 angle_p1p2_CC0Pion1Proton_PID->Fill(anglep1p2);
	 cosangle_p1p2_CC0Pion1Proton_PID->Fill(TMath::Cos(anglep1p2));
       }// topo2

       else if(*truthtop ==3 && trackfromneutrino){
	 topo3++;
	 selmuon_lenght_CC0Pion2Proton_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion2Proton_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion2Proton_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion2Proton_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion2Proton_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion2Proton_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion2Proton_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion2Proton_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion2Proton_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion2Proton_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0Pion2Proton_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0Pion2Proton_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0Pion2Proton_PID->Fill(anglemup1);
	 angle_mup2_CC0Pion2Proton_PID->Fill(anglemup2);
	 angle_p1p2_CC0Pion2Proton_PID->Fill(anglep1p2);
	 cosangle_p1p2_CC0Pion2Proton_PID->Fill(TMath::Cos(anglep1p2));
       }// topo3

       else if(*truthtop ==4 && trackfromneutrino){
	 topo4++;
	 selmuon_lenght_CC0PionNProton_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0PionNProton_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0PionNProton_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0PionNProton_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0PionNProton_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0PionNProton_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0PionNProton_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0PionNProton_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0PionNProton_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0PionNProton_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC0PionNProton_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC0PionNProton_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC0PionNProton_PID->Fill(anglemup1);
	 angle_mup2_CC0PionNProton_PID->Fill(anglemup2);
	 angle_p1p2_CC0PionNProton_PID->Fill(anglep1p2);
	 cosangle_p1p2_CC0PionNProton_PID->Fill(TMath::Cos(anglep1p2));
       }// topo4

       else if(*truthtop ==5 && trackfromneutrino){
	 topo5++;
	 selmuon_lenght_CC1PionNProton_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC1PionNProton_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC1PionNProton_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC1PionNProton_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC1PionNProton_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC1PionNProton_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC1PionNProton_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC1PionNProton_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC1PionNProton_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC1PionNProton_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CC1PionNProton_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CC1PionNProton_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CC1PionNProton_PID->Fill(anglemup1);
	 angle_mup2_CC1PionNProton_PID->Fill(anglemup2);
	 angle_p1p2_CC1PionNProton_PID->Fill(anglep1p2);
	 cosangle_p1p2_CC1PionNProton_PID->Fill(TMath::Cos(anglep1p2));
       }// topo5

       else if(*truthtop ==6 && trackfromneutrino){
	 topo6++;
	 selmuon_lenght_CCNPionNProton_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNPionNProton_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNPionNProton_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNPionNProton_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNPionNProton_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNPionNProton_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNPionNProton_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNPionNProton_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNPionNProton_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNPionNProton_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CCNPionNProton_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CCNPionNProton_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CCNPionNProton_PID->Fill(anglemup1);
	 angle_mup2_CCNPionNProton_PID->Fill(anglemup2);
	 angle_p1p2_CCNPionNProton_PID->Fill(anglep1p2);
	 cosangle_p1p2_CCNPionNProton_PID->Fill(TMath::Cos(anglep1p2));
       }// topo6

       else if(*truthtop ==7 && trackfromneutrino){
	 topo7++;
	 selmuon_lenght_CCNue_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNue_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNue_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNue_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNue_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNue_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNue_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNue_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNue_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNue_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_CCNue_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_CCNue_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_CCNue_PID->Fill(anglemup1);
	 angle_mup2_CCNue_PID->Fill(anglemup2);
	 angle_p1p2_CCNue_PID->Fill(anglep1p2);
	 cosangle_p1p2_CCNue_PID->Fill(TMath::Cos(anglep1p2));
       }// topo7

       else if(*truthtop ==8 && trackfromneutrino){
	 topo8++;
	 selmuon_lenght_NC_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_NC_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_NC_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_NC_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_NC_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_NC_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_NC_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_NC_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_NC_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_NC_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_NC_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_NC_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_NC_PID->Fill(anglemup1);
	 angle_mup2_NC_PID->Fill(anglemup2);
	 angle_p1p2_NC_PID->Fill(anglep1p2);
	 cosangle_p1p2_NC_PID->Fill(TMath::Cos(anglep1p2));
       }// topo8

       else if(*OOFVflag==1){
	 topo9++;
	 selmuon_lenght_OOFV_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_OOFV_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_OOFV_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_OOFV_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_OOFV_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_OOFV_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_OOFV_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_OOFV_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_OOFV_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_OOFV_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_OOFV_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_OOFV_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_OOFV_PID->Fill(anglemup1);
	 angle_mup2_OOFV_PID->Fill(anglemup2);
	 angle_p1p2_OOFV_PID->Fill(anglep1p2);
	 cosangle_p1p2_OOFV_PID->Fill(TMath::Cos(anglep1p2));
       }// topo9

       else if(!trackfromneutrino){
	 topo10++;
	 selmuon_lenght_EXT_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_EXT_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_EXT_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_EXT_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_EXT_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_EXT_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_EXT_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_EXT_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_EXT_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_EXT_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_EXT_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_EXT_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_EXT_PID->Fill(anglemup1);
	 angle_mup2_EXT_PID->Fill(anglemup2);
	 angle_p1p2_EXT_PID->Fill(anglep1p2);
	 cosangle_p1p2_EXT_PID->Fill(TMath::Cos(anglep1p2));
       }// topo9

       else{
	 topo11++;
	 selmuon_lenght_other_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_other_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_other_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_other_PID->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_other_PID->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_other_PID->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_other_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_other_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_other_PID->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_other_PID->Fill(track_pfp_phi[p2ind]);
	 selproton1_mom_other_PID->Fill(track_pfp_Mom_p[p1ind]);
	 selproton2_mom_other_PID->Fill(track_pfp_Mom_p[p2ind]);

	 angle_mup1_other_PID->Fill(anglemup1);
	 angle_mup2_other_PID->Fill(anglemup2);
	 angle_p1p2_other_PID->Fill(anglep1p2);
	 cosangle_p1p2_other_PID->Fill(TMath::Cos(anglep1p2));
       }//else

     //////// **************** /////////////
     //// same histos amd PID per particle type    
     ///////// **************** /////////////

     /// muon candidate /////
       if(pfp_pdg[muind] ==13){
	 selmuon_lenght_muon_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_muon_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_muon_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_muon_PID->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_muon_PID->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_muon_PID->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_muon_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_muon_PID->Fill(track_pfp_chi2_proton[muind]); 
	 }
       }
       else if(pfp_pdg[muind] ==2212){
	 selmuon_lenght_proton_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_proton_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_proton_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_proton_PID->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_proton_PID->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_proton_PID->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_proton_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_proton_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
       } 
       else if(pfp_pdg[muind] ==211){
	 selmuon_lenght_pion_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_pion_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pion_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pion_PID->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pion_PID->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_pion_PID->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pion_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pion_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
       }
       else if(pfp_pdg[muind] ==11){
	 selmuon_lenght_electron_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_electron_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_electron_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_electron_PID->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_electron_PID->Fill(track_pfp_chi2_proton[muind]);
       
	 ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_electron_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_electron_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
       }  

       else{
	 selmuon_lenght_pother_PID->Fill(track_pfp_length[muind]);
	 selmuon_mom_pother_PID->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pother_PID->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pother_PID->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pother_PID->Fill(track_pfp_chi2_proton[muind]);
                   
	 //////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pother_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pother_PID->Fill(track_pfp_chi2_proton[muind]);
	 }
       }           

       if(pfp_pdg[p1ind] ==13){
	 selproton1_lenght_muon_PID->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_muon_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_muon_PID->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_muon_PID->Fill(track_pfp_chi2_proton[p1ind]);
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_muon_PID->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==2212){
	 selproton1_lenght_proton_PID->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_proton_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_proton_PID->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_proton_PID->Fill(track_pfp_chi2_proton[p1ind]);

	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_proton_PID->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==211){
	 selproton1_lenght_pion_PID->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pion_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pion_PID->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pion_PID->Fill(track_pfp_chi2_proton[p1ind]);
       
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_pion_PID->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }
       else if(pfp_pdg[p1ind] ==11){
	 selproton1_lenght_electron_PID->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_electron_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_electron_PID->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_electron_PID->Fill(track_pfp_chi2_proton[p1ind]);
       }//electrons

       else{
	 selproton1_lenght_pother_PID->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pother_PID->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pother_PID->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pother_PID->Fill(track_pfp_chi2_proton[p1ind]);
       }//other
       if(pfp_pdg[p2ind] ==13){
	 selproton2_lenght_muon_PID->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_muon_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_muon_PID->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_muon_PID->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_muon_PID->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==2212){
	 selproton2_lenght_proton_PID->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_proton_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_proton_PID->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_proton_PID->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_proton_PID->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==211){
	 selproton2_lenght_pion_PID->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pion_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pion_PID->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pion_PID->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_pion_PID->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }
       else if(pfp_pdg[p2ind] ==11){
	 selproton2_lenght_electron_PID->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_electron_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_electron_PID->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_electron_PID->Fill(track_pfp_chi2_proton[p2ind]);
       }//electrons

       else{
	 selproton2_lenght_pother_PID->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pother_PID->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pother_PID->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pother_PID->Fill(track_pfp_chi2_proton[p2ind]);
       }//other
       }
       }/// minimum number collection hits (5)
     }/// mu, p1, p2, muon in FV
   }///PID requirement

   return kTRUE;
}

void hanalysis_Tune3_PID::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_Tune3_PID::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  cout<<"total number of event processed"<<totentries<<endl;
  cout << "Output file written" << endl;

  fanalysis_PID->cd();
  fanalysis_PID->Write();

  std::cout << "root Output file written" << std::endl;
  std::cout << "start writing histos" << std::endl;
  outfileMC_PID<<"total entries: "<<totentries<<std::endl;
  double topo1fr = topo1/totentries;
  outfileMC_PID<<"CC0Pion0Proton: "<<topo1<<" purity "<<topo1fr<<std::endl;
  outfileMC_PID<<"CC0Pion1Proton: "<<topo2<<" purity "<<(topo2/totentries)<<std::endl;
  outfileMC_PID<<"CC0Pion2Proton: "<<topo3<<" purity "<<double ((topo3/totentries))<<std::endl;
  outfileMC_PID<<"CC0PionNProton: "<<topo4<<" purity "<<(topo4/totentries)*100.<<std::endl;
  outfileMC_PID<<"CC1PionNProton: "<<topo5<<" purity "<<(topo5/totentries)*100.<<std::endl;
  outfileMC_PID<<"CCNPionNProton: "<<topo6<<" purity "<<(topo6/totentries)*100.<<std::endl;
  outfileMC_PID<<"CCnue: "<<topo7<<" purity "<<(topo7/totentries)*100.<<std::endl;
  outfileMC_PID<<"NC: "<<topo8<<" purity "<<(topo8/totentries)*100.<<std::endl;
  outfileMC_PID<<"OOFV: "<<topo9<<" purity "<<(topo9/totentries)*100.<<std::endl;
  outfileMC_PID<<"cosmic: "<<topo10<<" purity "<<(topo10/totentries)*100.<<std::endl;
  outfileMC_PID<<"other: "<<topo11<<" purity "<<(topo11/totentries)*100.<<std::endl;

  outfileMC_PID<<"reactions..........."<<std::endl;
  outfileMC_PID<<"QE "<<QE<<std::endl;
  outfileMC_PID<<"RES "<<RES<<std::endl;
  outfileMC_PID<<"DIS "<<DIS<<std::endl;
  outfileMC_PID<<"COH "<<COH<<std::endl;
  outfileMC_PID<<"MEC "<<MEC<<std::endl;

}
