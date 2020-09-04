#define hanalysis_fMC_minColl_cxx
// The class definition in hanalysis_fMC_minColl.h has been generated automatically
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
// root> T->Process("hanalysis_fMC_minColl.C")
// root> T->Process("hanalysis_fMC_minColl.C","some options")
// root> T->Process("hanalysis_fMC_minColl.C+")
//


#include "hanalysis_fMC_minColl.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TMath.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfileMC_minColl;
TFile *fanalysis_minColl;

/// muon candidate properties
TH1D *selmuon_lenght_CC0Pion0Proton_minColl;
TH1D *selmuon_lenght_CC0Pion1Proton_minColl;
TH1D *selmuon_lenght_CC0Pion2Proton_minColl;
TH1D *selmuon_lenght_CC0PionNProton_minColl;
TH1D *selmuon_lenght_CC1PionNProton_minColl;
TH1D *selmuon_lenght_CCNPionNProton_minColl;
TH1D *selmuon_lenght_CCNue_minColl;
TH1D *selmuon_lenght_NC_minColl;
TH1D *selmuon_lenght_OOFV_minColl;
TH1D *selmuon_lenght_EXT_minColl;
TH1D *selmuon_lenght_other_minColl;

TH1D *selmuon_mom_CC0Pion0Proton_minColl;
TH1D *selmuon_mom_CC0Pion1Proton_minColl;
TH1D *selmuon_mom_CC0Pion2Proton_minColl;
TH1D *selmuon_mom_CC0PionNProton_minColl;
TH1D *selmuon_mom_CC1PionNProton_minColl;
TH1D *selmuon_mom_CCNPionNProton_minColl;
TH1D *selmuon_mom_CCNue_minColl;
TH1D *selmuon_mom_NC_minColl;
TH1D *selmuon_mom_OOFV_minColl;
TH1D *selmuon_mom_EXT_minColl;
TH1D *selmuon_mom_other_minColl;

TH1D *selmuon_contained_mom_CC0Pion0Proton_minColl;
TH1D *selmuon_contained_mom_CC0Pion1Proton_minColl;
TH1D *selmuon_contained_mom_CC0Pion2Proton_minColl;
TH1D *selmuon_contained_mom_CC0PionNProton_minColl;
TH1D *selmuon_contained_mom_CC1PionNProton_minColl;
TH1D *selmuon_contained_mom_CCNPionNProton_minColl;
TH1D *selmuon_contained_mom_CCNue_minColl;
TH1D *selmuon_contained_mom_NC_minColl;
TH1D *selmuon_contained_mom_OOFV_minColl;
TH1D *selmuon_contained_mom_EXT_minColl;
TH1D *selmuon_contained_mom_other_minColl;

TH1D *selmuon_uncontained_mom_CC0Pion0Proton_minColl;
TH1D *selmuon_uncontained_mom_CC0Pion1Proton_minColl;
TH1D *selmuon_uncontained_mom_CC0Pion2Proton_minColl;
TH1D *selmuon_uncontained_mom_CC0PionNProton_minColl;
TH1D *selmuon_uncontained_mom_CC1PionNProton_minColl;
TH1D *selmuon_uncontained_mom_CCNPionNProton_minColl;
TH1D *selmuon_uncontained_mom_CCNue_minColl;
TH1D *selmuon_uncontained_mom_NC_minColl;
TH1D *selmuon_uncontained_mom_OOFV_minColl;
TH1D *selmuon_uncontained_mom_EXT_minColl;
TH1D *selmuon_uncontained_mom_other_minColl;

TH1D *selmuon_costheta_CC0Pion0Proton_minColl;
TH1D *selmuon_costheta_CC0Pion1Proton_minColl;
TH1D *selmuon_costheta_CC0Pion2Proton_minColl;
TH1D *selmuon_costheta_CC0PionNProton_minColl;
TH1D *selmuon_costheta_CC1PionNProton_minColl;
TH1D *selmuon_costheta_CCNPionNProton_minColl;
TH1D *selmuon_costheta_CCNue_minColl;
TH1D *selmuon_costheta_NC_minColl;
TH1D *selmuon_costheta_OOFV_minColl;
TH1D *selmuon_costheta_EXT_minColl;
TH1D *selmuon_costheta_other_minColl;

TH1D *selmuon_phi_CC0Pion0Proton_minColl;
TH1D *selmuon_phi_CC0Pion1Proton_minColl;
TH1D *selmuon_phi_CC0Pion2Proton_minColl;
TH1D *selmuon_phi_CC0PionNProton_minColl;
TH1D *selmuon_phi_CC1PionNProton_minColl;
TH1D *selmuon_phi_CCNPionNProton_minColl;
TH1D *selmuon_phi_CCNue_minColl;
TH1D *selmuon_phi_NC_minColl;
TH1D *selmuon_phi_OOFV_minColl;
TH1D *selmuon_phi_EXT_minColl;
TH1D *selmuon_phi_other_minColl;

TH1D *selmuon_lenght_muon_minColl;
TH1D *selmuon_lenght_proton_minColl;
TH1D *selmuon_lenght_pion_minColl;
TH1D *selmuon_lenght_electron_minColl;
TH1D *selmuon_lenght_pother_minColl;

TH1D *selmuon_mom_muon_minColl;
TH1D *selmuon_mom_proton_minColl;
TH1D *selmuon_mom_pion_minColl;
TH1D *selmuon_mom_electron_minColl;
TH1D *selmuon_mom_pother_minColl;

TH1D *selmuon_contained_mom_muon_minColl;
TH1D *selmuon_contained_mom_proton_minColl;
TH1D *selmuon_contained_mom_pion_minColl;
TH1D *selmuon_contained_mom_electron_minColl;
TH1D *selmuon_contained_mom_pother_minColl;

TH1D *selmuon_uncontained_mom_muon_minColl;
TH1D *selmuon_uncontained_mom_proton_minColl;
TH1D *selmuon_uncontained_mom_pion_minColl;
TH1D *selmuon_uncontained_mom_electron_minColl;
TH1D *selmuon_uncontained_mom_pother_minColl;

TH1D *selmuon_costheta_muon_minColl;
TH1D *selmuon_costheta_proton_minColl;
TH1D *selmuon_costheta_pion_minColl;
TH1D *selmuon_costheta_electron_minColl;
TH1D *selmuon_costheta_pother_minColl;

TH1D *selmuon_phi_muon_minColl;
TH1D *selmuon_phi_proton_minColl;
TH1D *selmuon_phi_pion_minColl;
TH1D *selmuon_phi_electron_minColl;
TH1D *selmuon_phi_pother_minColl;

TH1D *selmuon_chi2proton_muon_minColl;
TH1D *selmuon_chi2proton_proton_minColl;
TH1D *selmuon_chi2proton_pion_minColl;
TH1D *selmuon_chi2proton_electron_minColl;
TH1D *selmuon_chi2proton_pother_minColl;

TH1D *selmuon_chi2proton_cont_muon_minColl;
TH1D *selmuon_chi2proton_cont_proton_minColl;
TH1D *selmuon_chi2proton_cont_pion_minColl;
TH1D *selmuon_chi2proton_cont_electron_minColl;
TH1D *selmuon_chi2proton_cont_pother_minColl;

TH2D *selmuon_dEdx_vs_resrange_muon_minColl;
TH2D *selmuon_dEdx_vs_resrange_proton_minColl;
TH2D *selmuon_dEdx_vs_resrange_pion_minColl;

TH1D *selmuon_chi2proton_uncont_muon_minColl;
TH1D *selmuon_chi2proton_uncont_proton_minColl;
TH1D *selmuon_chi2proton_uncont_pion_minColl;
TH1D *selmuon_chi2proton_uncont_electron_minColl;
TH1D *selmuon_chi2proton_uncont_pother_minColl;

///proton properties

TH1D *selproton1_lenght_CC0Pion0Proton_minColl;
TH1D *selproton1_lenght_CC0Pion1Proton_minColl;
TH1D *selproton1_lenght_CC0Pion2Proton_minColl;
TH1D *selproton1_lenght_CC0PionNProton_minColl;
TH1D *selproton1_lenght_CC1PionNProton_minColl;
TH1D *selproton1_lenght_CCNPionNProton_minColl;
TH1D *selproton1_lenght_CCNue_minColl;
TH1D *selproton1_lenght_NC_minColl;
TH1D *selproton1_lenght_OOFV_minColl;
TH1D *selproton1_lenght_EXT_minColl;
TH1D *selproton1_lenght_other_minColl;

TH1D *selproton1_costheta_CC0Pion0Proton_minColl;
TH1D *selproton1_costheta_CC0Pion1Proton_minColl;
TH1D *selproton1_costheta_CC0Pion2Proton_minColl;
TH1D *selproton1_costheta_CC0PionNProton_minColl;
TH1D *selproton1_costheta_CC1PionNProton_minColl;
TH1D *selproton1_costheta_CCNPionNProton_minColl;
TH1D *selproton1_costheta_CCNue_minColl;
TH1D *selproton1_costheta_NC_minColl;
TH1D *selproton1_costheta_OOFV_minColl;
TH1D *selproton1_costheta_EXT_minColl;
TH1D *selproton1_costheta_other_minColl;

TH1D *selproton1_phi_CC0Pion0Proton_minColl;
TH1D *selproton1_phi_CC0Pion1Proton_minColl;
TH1D *selproton1_phi_CC0Pion2Proton_minColl;
TH1D *selproton1_phi_CC0PionNProton_minColl;
TH1D *selproton1_phi_CC1PionNProton_minColl;
TH1D *selproton1_phi_CCNPionNProton_minColl;
TH1D *selproton1_phi_CCNue_minColl;
TH1D *selproton1_phi_NC_minColl;
TH1D *selproton1_phi_OOFV_minColl;
TH1D *selproton1_phi_EXT_minColl;
TH1D *selproton1_phi_other_minColl;

TH1D *selproton1_lenght_muon_minColl;
TH1D *selproton1_lenght_proton_minColl;
TH1D *selproton1_lenght_pion_minColl;
TH1D *selproton1_lenght_electron_minColl;
TH1D *selproton1_lenght_pother_minColl;

TH1D *selproton1_costheta_muon_minColl;
TH1D *selproton1_costheta_proton_minColl;
TH1D *selproton1_costheta_pion_minColl;
TH1D *selproton1_costheta_electron_minColl;
TH1D *selproton1_costheta_pother_minColl;

TH1D *selproton1_phi_muon_minColl;
TH1D *selproton1_phi_proton_minColl;
TH1D *selproton1_phi_pion_minColl;
TH1D *selproton1_phi_electron_minColl;
TH1D *selproton1_phi_pother_minColl;

TH1D *selproton1_chi2proton_muon_minColl;
TH1D *selproton1_chi2proton_proton_minColl;
TH1D *selproton1_chi2proton_pion_minColl;
TH1D *selproton1_chi2proton_electron_minColl;
TH1D *selproton1_chi2proton_pother_minColl;

TH2D *selproton1_dEdx_vs_resrange_muon_minColl;
TH2D *selproton1_dEdx_vs_resrange_proton_minColl;
TH2D *selproton1_dEdx_vs_resrange_pion_minColl;

/////////////////////////////////////////////

TH1D *selproton2_lenght_CC0Pion0Proton_minColl;
TH1D *selproton2_lenght_CC0Pion1Proton_minColl;
TH1D *selproton2_lenght_CC0Pion2Proton_minColl;
TH1D *selproton2_lenght_CC0PionNProton_minColl;
TH1D *selproton2_lenght_CC1PionNProton_minColl;
TH1D *selproton2_lenght_CCNPionNProton_minColl;
TH1D *selproton2_lenght_CCNue_minColl;
TH1D *selproton2_lenght_NC_minColl;
TH1D *selproton2_lenght_OOFV_minColl;
TH1D *selproton2_lenght_EXT_minColl;
TH1D *selproton2_lenght_other_minColl;

TH1D *selproton2_costheta_CC0Pion0Proton_minColl;
TH1D *selproton2_costheta_CC0Pion1Proton_minColl;
TH1D *selproton2_costheta_CC0Pion2Proton_minColl;
TH1D *selproton2_costheta_CC0PionNProton_minColl;
TH1D *selproton2_costheta_CC1PionNProton_minColl;
TH1D *selproton2_costheta_CCNPionNProton_minColl;
TH1D *selproton2_costheta_CCNue_minColl;
TH1D *selproton2_costheta_NC_minColl;
TH1D *selproton2_costheta_OOFV_minColl;
TH1D *selproton2_costheta_EXT_minColl;
TH1D *selproton2_costheta_other_minColl;

TH1D *selproton2_phi_CC0Pion0Proton_minColl;
TH1D *selproton2_phi_CC0Pion1Proton_minColl;
TH1D *selproton2_phi_CC0Pion2Proton_minColl;
TH1D *selproton2_phi_CC0PionNProton_minColl;
TH1D *selproton2_phi_CC1PionNProton_minColl;
TH1D *selproton2_phi_CCNPionNProton_minColl;
TH1D *selproton2_phi_CCNue_minColl;
TH1D *selproton2_phi_NC_minColl;
TH1D *selproton2_phi_OOFV_minColl;
TH1D *selproton2_phi_EXT_minColl;
TH1D *selproton2_phi_other_minColl;

TH1D *selproton2_lenght_muon_minColl;
TH1D *selproton2_lenght_proton_minColl;
TH1D *selproton2_lenght_pion_minColl;
TH1D *selproton2_lenght_electron_minColl;
TH1D *selproton2_lenght_pother_minColl;

TH1D *selproton2_costheta_muon_minColl;
TH1D *selproton2_costheta_proton_minColl;
TH1D *selproton2_costheta_pion_minColl;
TH1D *selproton2_costheta_electron_minColl;
TH1D *selproton2_costheta_pother_minColl;

TH1D *selproton2_phi_muon_minColl;
TH1D *selproton2_phi_proton_minColl;
TH1D *selproton2_phi_pion_minColl;
TH1D *selproton2_phi_electron_minColl;
TH1D *selproton2_phi_pother_minColl;

TH1D *selproton2_PIDA_muon_minColl;
TH1D *selproton2_PIDA_proton_minColl;
TH1D *selproton2_PIDA_pion_minColl;
TH1D *selproton2_PIDA_electron_minColl;
TH1D *selproton2_PIDA_pother_minColl;

TH1D *selproton2_chi2proton_muon_minColl;
TH1D *selproton2_chi2proton_proton_minColl;
TH1D *selproton2_chi2proton_pion_minColl;
TH1D *selproton2_chi2proton_electron_minColl;
TH1D *selproton2_chi2proton_pother_minColl;

TH2D *selproton2_dEdx_vs_resrange_muon_minColl;
TH2D *selproton2_dEdx_vs_resrange_proton_minColl;
TH2D *selproton2_dEdx_vs_resrange_pion_minColl;

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


void hanalysis_fMC_minColl::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   fanalysis_minColl= new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_minColl_BNBMC.root","RECREATE");
   outfileMC_minColl.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_minColl_MC.txt");

   std::cout<<"declaring histos"<<endl;
/////////////////// muon candidate properties

   selmuon_lenght_CC0Pion0Proton_minColl= new TH1D("selmuon_lenght_CC0Pion0Proton_minColl", "selmuon_lenght_CC0Pion0Proton_minColl", 10, 0, 500);
   selmuon_lenght_CC0Pion1Proton_minColl= new TH1D("selmuon_lenght_CC0Pion1Proton_minColl", "selmuon_lenght_CC0Pion1Proton_minColl", 10, 0, 500);
   selmuon_lenght_CC0Pion2Proton_minColl= new TH1D("selmuon_lenght_CC0Pion2Proton_minColl", "selmuon_lenght_CC0Pion2Proton_minColl", 10, 0, 500);
   selmuon_lenght_CC0PionNProton_minColl= new TH1D("selmuon_lenght_CC0PionNProton_minColl", "selmuon_lenght_CC0PionNProton_minColl", 10, 0, 500);
   selmuon_lenght_CC1PionNProton_minColl= new TH1D("selmuon_lenght_CC1PionNProton_minColl", "selmuon_lenght_CC1PionNProton_minColl", 10, 0, 500);
   selmuon_lenght_CCNPionNProton_minColl= new TH1D("selmuon_lenght_CCNPionNProton_minColl", "selmuon_lenght_CCNPionNProton_minColl", 10, 0, 500);
   selmuon_lenght_CCNue_minColl= new TH1D("selmuon_lenght_CCNue_minColl", "selmuon_lenght_CCNue_minColl", 10, 0, 500);   
   selmuon_lenght_NC_minColl= new TH1D("selmuon_lenght_NC_minColl", "selmuon_lenght_NC_minColl", 10, 0, 500);
   selmuon_lenght_OOFV_minColl= new TH1D("selmuon_lenght_OOFV_minColl", "selmuon_lenght_OOFV_minColl", 10, 0, 500);
   selmuon_lenght_EXT_minColl= new TH1D("selmuon_lenght_EXT_minColl", "selmuon_lenght_EXT_minColl", 10, 0, 500);
   selmuon_lenght_other_minColl= new TH1D("selmuon_lenght_other_minColl", "selmuon_lenght_other_minColl", 10, 0, 500);   
   ////
   selmuon_mom_CC0Pion0Proton_minColl= new TH1D("selmuon_mom_CC0Pion0Proton_minColl", "selmuon_mom_CC0Pion0Proton_minColl", 10, 0, 3);
   selmuon_mom_CC0Pion1Proton_minColl= new TH1D("selmuon_mom_CC0Pion1Proton_minColl", "selmuon_mom_CC0Pion1Proton_minColl", 10, 0, 3);
   selmuon_mom_CC0Pion2Proton_minColl= new TH1D("selmuon_mom_CC0Pion2Proton_minColl", "selmuon_mom_CC0Pion2Proton_minColl", 10, 0, 3);
   selmuon_mom_CC0PionNProton_minColl= new TH1D("selmuon_mom_CC0PionNProton_minColl", "selmuon_mom_CC0PionNProton_minColl", 10, 0, 3);
   selmuon_mom_CC1PionNProton_minColl= new TH1D("selmuon_mom_CC1PionNProton_minColl", "selmuon_mom_CC1PionNProton_minColl", 10, 0, 3);
   selmuon_mom_CCNPionNProton_minColl= new TH1D("selmuon_mom_CCNPionNProton_minColl", "selmuon_mom_CCNPionNProton_minColl", 10, 0, 3);
   selmuon_mom_CCNue_minColl= new TH1D("selmuon_mom_CCNue_minColl", "selmuon_mom_CCNue_minColl", 10, 0, 3);   
   selmuon_mom_NC_minColl= new TH1D("selmuon_mom_NC_minColl", "selmuon_mom_NC_minColl", 10, 0, 3);
   selmuon_mom_OOFV_minColl= new TH1D("selmuon_mom_OOFV_minColl", "selmuon_mom_OOFV_minColl", 10, 0, 3);
   selmuon_mom_EXT_minColl= new TH1D("selmuon_mom_EXT_minColl", "selmuon_mom_EXT_minColl", 10, 0, 3);
   selmuon_mom_other_minColl= new TH1D("selmuon_mom_other_minColl", "selmuon_mom_other_minColl", 10, 0, 3);   
   ///
   
   selmuon_contained_mom_CC0Pion0Proton_minColl= new TH1D("selmuon_contained_mom_CC0Pion0Proton_minColl", "selmuon_contained_mom_CC0Pion0Proton_minColl", 10, 0, 3);
   selmuon_contained_mom_CC0Pion1Proton_minColl= new TH1D("selmuon_contained_mom_CC0Pion1Proton_minColl", "selmuon_contained_mom_CC0Pion1Proton_minColl", 10, 0, 3);
   selmuon_contained_mom_CC0Pion2Proton_minColl= new TH1D("selmuon_contained_mom_CC0Pion2Proton_minColl", "selmuon_contained_mom_CC0Pion2Proton_minColl", 10, 0, 3);
   selmuon_contained_mom_CC0PionNProton_minColl= new TH1D("selmuon_contained_mom_CC0PionNProton_minColl", "selmuon_contained_mom_CC0PionNProton_minColl", 10, 0, 3);
   selmuon_contained_mom_CC1PionNProton_minColl= new TH1D("selmuon_contained_mom_CC1PionNProton_minColl", "selmuon_contained_mom_CC1PionNProton_minColl", 10, 0, 3);
   selmuon_contained_mom_CCNPionNProton_minColl= new TH1D("selmuon_contained_mom_CCNPionNProton_minColl", "selmuon_contained_mom_CCNPionNProton_minColl", 10, 0, 3);
   selmuon_contained_mom_CCNue_minColl= new TH1D("selmuon_contained_mom_CCNue_minColl", "selmuon_contained_mom_CCNue_minColl", 10, 0, 3);   
   selmuon_contained_mom_NC_minColl= new TH1D("selmuon_contained_mom_NC_minColl", "selmuon_contained_mom_NC_minColl", 10, 0, 3);
   selmuon_contained_mom_OOFV_minColl= new TH1D("selmuon_contained_mom_OOFV_minColl", "selmuon_contained_mom_OOFV_minColl", 10, 0, 3);
   selmuon_contained_mom_EXT_minColl= new TH1D("selmuon_contained_mom_EXT_minColl", "selmuon_contained_mom_EXT_minColl", 10, 0, 3);
   selmuon_contained_mom_other_minColl= new TH1D("selmuon_contained_mom_other_minColl", "selmuon_contained_mom_other_minColl", 10, 0, 3);   
   ////

   selmuon_uncontained_mom_CC0Pion0Proton_minColl= new TH1D("selmuon_uncontained_mom_CC0Pion0Proton_minColl", "selmuon_uncontained_mom_CC0Pion0Proton_minColl", 10, 0, 3);
   selmuon_uncontained_mom_CC0Pion1Proton_minColl= new TH1D("selmuon_uncontained_mom_CC0Pion1Proton_minColl", "selmuon_uncontained_mom_CC0Pion1Proton_minColl", 10, 0, 3);
   selmuon_uncontained_mom_CC0Pion2Proton_minColl= new TH1D("selmuon_uncontained_mom_CC0Pion2Proton_minColl", "selmuon_uncontained_mom_CC0Pion2Proton_minColl", 10, 0, 3);
   selmuon_uncontained_mom_CC0PionNProton_minColl= new TH1D("selmuon_uncontained_mom_CC0PionNProton_minColl", "selmuon_uncontained_mom_CC0PionNProton_minColl", 10, 0, 3);
   selmuon_uncontained_mom_CC1PionNProton_minColl= new TH1D("selmuon_uncontained_mom_CC1PionNProton_minColl", "selmuon_uncontained_mom_CC1PionNProton_minColl", 10, 0, 3);
   selmuon_uncontained_mom_CCNPionNProton_minColl= new TH1D("selmuon_uncontained_mom_CCNPionNProton_minColl", "selmuon_uncontained_mom_CCNPionNProton_minColl", 10, 0, 3);
   selmuon_uncontained_mom_CCNue_minColl= new TH1D("selmuon_uncontained_mom_CCNue_minColl", "selmuon_uncontained_mom_CCNue_minColl", 10, 0, 3);   
   selmuon_uncontained_mom_NC_minColl= new TH1D("selmuon_uncontained_mom_NC_minColl", "selmuon_uncontained_mom_NC_minColl", 10, 0, 3);
   selmuon_uncontained_mom_OOFV_minColl= new TH1D("selmuon_uncontained_mom_OOFV_minColl", "selmuon_uncontained_mom_OOFV_minColl", 10, 0, 3);
   selmuon_uncontained_mom_EXT_minColl= new TH1D("selmuon_uncontained_mom_EXT_minColl", "selmuon_uncontained_mom_EXT_minColl", 10, 0, 3);
   selmuon_uncontained_mom_other_minColl= new TH1D("selmuon_uncontained_mom_other_minColl", "selmuon_uncontained_mom_other_minColl", 10, 0, 3);   
   ////
   selmuon_costheta_CC0Pion0Proton_minColl= new TH1D("selmuon_costheta_CC0Pion0Proton_minColl", "selmuon_costheta_CC0Pion0Proton_minColl", 10, -1, 1);
   selmuon_costheta_CC0Pion1Proton_minColl= new TH1D("selmuon_costheta_CC0Pion1Proton_minColl", "selmuon_costheta_CC0Pion1Proton_minColl", 10, -1, 1);
   selmuon_costheta_CC0Pion2Proton_minColl= new TH1D("selmuon_costheta_CC0Pion2Proton_minColl", "selmuon_costheta_CC0Pion2Proton_minColl", 10, -1, 1);
   selmuon_costheta_CC0PionNProton_minColl= new TH1D("selmuon_costheta_CC0PionNProton_minColl", "selmuon_costheta_CC0PionNProton_minColl", 10, -1, 1);
   selmuon_costheta_CC1PionNProton_minColl= new TH1D("selmuon_costheta_CC1PionNProton_minColl", "selmuon_costheta_CC1PionNProton_minColl", 10, -1, 1);
   selmuon_costheta_CCNPionNProton_minColl= new TH1D("selmuon_costheta_CCNPionNProton_minColl", "selmuon_costheta_CCNPionNProton_minColl", 10, -1, 1);
   selmuon_costheta_CCNue_minColl= new TH1D("selmuon_costheta_CCNue_minColl", "selmuon_costheta_CCNue_minColl", 10, -1, 1);   
   selmuon_costheta_NC_minColl= new TH1D("selmuon_costheta_NC_minColl", "selmuon_costheta_NC_minColl", 10, -1, 1);
   selmuon_costheta_OOFV_minColl= new TH1D("selmuon_costheta_OOFV_minColl", "selmuon_costheta_OOFV_minColl", 10, -1, 1);
   selmuon_costheta_EXT_minColl= new TH1D("selmuon_costheta_EXT_minColl", "selmuon_costheta_EXT_minColl", 10, -1, 1);
   selmuon_costheta_other_minColl= new TH1D("selmuon_costheta_other_minColl", "selmuon_costheta_other_minColl", 10, -1, 1); 
   /////
   selmuon_phi_CC0Pion0Proton_minColl= new TH1D("selmuon_phi_CC0Pion0Proton_minColl", "selmuon_phi_CC0Pion0Proton_minColl", 10, -3.14, 3.14);
   selmuon_phi_CC0Pion1Proton_minColl= new TH1D("selmuon_phi_CC0Pion1Proton_minColl", "selmuon_phi_CC0Pion1Proton_minColl", 10, -3.14, 3.14);
   selmuon_phi_CC0Pion2Proton_minColl= new TH1D("selmuon_phi_CC0Pion2Proton_minColl", "selmuon_phi_CC0Pion2Proton_minColl", 10, -3.14, 3.14);
   selmuon_phi_CC0PionNProton_minColl= new TH1D("selmuon_phi_CC0PionNProton_minColl", "selmuon_phi_CC0PionNProton_minColl", 10, -3.14, 3.14);
   selmuon_phi_CC1PionNProton_minColl= new TH1D("selmuon_phi_CC1PionNProton_minColl", "selmuon_phi_CC1PionNProton_minColl", 10, -3.14, 3.14);
   selmuon_phi_CCNPionNProton_minColl= new TH1D("selmuon_phi_CCNPionNProton_minColl", "selmuon_phi_CCNPionNProton_minColl", 10, -3.14, 3.14);
   selmuon_phi_CCNue_minColl= new TH1D("selmuon_phi_CCNue_minColl", "selmuon_phi_CCNue_minColl", 10, -3.14, 3.14);   
   selmuon_phi_NC_minColl= new TH1D("selmuon_phi_NC_minColl", "selmuon_phi_NC_minColl", 10, -3.14, 3.14);
   selmuon_phi_OOFV_minColl= new TH1D("selmuon_phi_OOFV_minColl", "selmuon_phi_OOFV_minColl", 10, -3.14, 3.14);
   selmuon_phi_EXT_minColl= new TH1D("selmuon_phi_EXT_minColl", "selmuon_phi_EXT_minColl", 10, -3.14, 3.14);
   selmuon_phi_other_minColl= new TH1D("selmuon_phi_other_minColl", "selmuon_phi_other_minColl", 10, -3.14, 3.14); 
   /////

   selmuon_lenght_muon_minColl= new TH1D("selmuon_lenght_muon_minColl", "selmuon_lenght_muon_minColl", 10, 0, 500);
   selmuon_lenght_proton_minColl= new TH1D("selmuon_lenght_proton_minColl", "selmuon_lenght_proton_minColl", 10, 0, 500);
   selmuon_lenght_pion_minColl= new TH1D("selmuon_lenght_pion_minColl", "selmuon_lenght_pion_minColl", 10, 0, 500);
   selmuon_lenght_electron_minColl= new TH1D("selmuon_lenght_electron_minColl", "selmuon_lenght_electron_minColl", 10, 0, 500);
   selmuon_lenght_pother_minColl= new TH1D("selmuon_lenght_pother_minColl", "selmuon_lenght_pother_minColl", 10, 0, 500);
   ////   
   selmuon_mom_muon_minColl= new TH1D("selmuon_mom_muon_minColl", "selmuon_mom_muon_minColl", 10, 0, 3);
   selmuon_mom_proton_minColl= new TH1D("selmuon_mom_proton_minColl", "selmuon_mom_proton_minColl", 10, 0, 3);
   selmuon_mom_pion_minColl= new TH1D("selmuon_mom_pion_minColl", "selmuon_mom_pion_minColl", 10, 0, 3);
   selmuon_mom_electron_minColl= new TH1D("selmuon_mom_electron_minColl", "selmuon_mom_electron_minColl", 10, 0, 3);
   selmuon_mom_pother_minColl= new TH1D("selmuon_mom_pother_minColl", "selmuon_mom_pother_minColl", 10, 0, 3);
   ///
   selmuon_contained_mom_muon_minColl= new TH1D("selmuon_contained_mom_muon_minColl", "selmuon_contained_mom_muon_minColl", 10, 0, 3);
   selmuon_contained_mom_proton_minColl= new TH1D("selmuon_contained_mom_proton_minColl", "selmuon_contained_mom_proton_minColl", 10, 0, 3);
   selmuon_contained_mom_pion_minColl= new TH1D("selmuon_contained_mom_pion_minColl", "selmuon_contained_mom_pion_minColl", 10, 0, 3);
   selmuon_contained_mom_electron_minColl= new TH1D("selmuon_contained_mom_electron_minColl", "selmuon_contained_mom_electron_minColl", 10, 0, 3);
   selmuon_contained_mom_pother_minColl= new TH1D("selmuon_contained_mom_pother_minColl", "selmuon_contained_mom_pother_minColl", 10, 0, 3);
   ///
   selmuon_uncontained_mom_muon_minColl= new TH1D("selmuon_uncontained_mom_muon_minColl", "selmuon_uncontained_mom_muon_minColl", 10, 0, 3);
   selmuon_uncontained_mom_proton_minColl= new TH1D("selmuon_uncontained_mom_proton_minColl", "selmuon_uncontained_mom_proton_minColl", 10, 0, 3);
   selmuon_uncontained_mom_pion_minColl= new TH1D("selmuon_uncontained_mom_pion_minColl", "selmuon_uncontained_mom_pion_minColl", 10, 0, 3);
   selmuon_uncontained_mom_electron_minColl= new TH1D("selmuon_uncontained_mom_electron_minColl", "selmuon_uncontained_mom_electron_minColl", 10, 0, 3);
   selmuon_uncontained_mom_pother_minColl= new TH1D("selmuon_uncontained_mom_pother_minColl", "selmuon_uncontained_mom_pother_minColl", 10, 0, 3);

   ///
   selmuon_costheta_muon_minColl= new TH1D("selmuon_costheta_muon_minColl", "selmuon_costheta_muon_minColl", 10, -1, 1);
   selmuon_costheta_proton_minColl= new TH1D("selmuon_costheta_proton_minColl", "selmuon_costheta_proton_minColl", 10, -1, 1);
   selmuon_costheta_pion_minColl= new TH1D("selmuon_costheta_pion_minColl", "selmuon_costheta_pion_minColl", 10, -1, 1);
   selmuon_costheta_electron_minColl= new TH1D("selmuon_costheta_electron_minColl", "selmuon_costheta_electron_minColl", 10, -1, 1);
   selmuon_costheta_pother_minColl= new TH1D("selmuon_costheta_pother_minColl", "selmuon_costheta_pother_minColl", 10, -1, 1);
   ///
   selmuon_phi_muon_minColl= new TH1D("selmuon_phi_muon_minColl", "selmuon_phi_muon_minColl", 10, -3.14, 3.14);
   selmuon_phi_proton_minColl= new TH1D("selmuon_phi_proton_minColl", "selmuon_phi_proton_minColl", 10, -3.14, 3.14);
   selmuon_phi_pion_minColl= new TH1D("selmuon_phi_pion_minColl", "selmuon_phi_pion_minColl", 10, -3.14, 3.14);
   selmuon_phi_electron_minColl= new TH1D("selmuon_phi_electron_minColl", "selmuon_phi_electron_minColl", 10, -3.14, 3.14);
   selmuon_phi_pother_minColl= new TH1D("selmuon_phi_pother_minColl", "selmuon_phi_pother_minColl", 10, -3.14, 3.14);

   selmuon_chi2proton_muon_minColl= new TH1D("selmuon_chi2proton_muon_minColl", "selmuon_chi2proton_muon_minColl", 30, 0, 300);
   selmuon_chi2proton_proton_minColl= new TH1D("selmuon_chi2proton_proton_minColl", "selmuon_chi2proton_proton_minColl", 30, 0, 300);
   selmuon_chi2proton_pion_minColl= new TH1D("selmuon_chi2proton_pion_minColl", "selmuon_chi2proton_pion_minColl", 30, 0, 300);
   selmuon_chi2proton_electron_minColl= new TH1D("selmuon_chi2proton_electron_minColl", "selmuon_chi2proton_electron_minColl", 30, 0, 300);
   selmuon_chi2proton_pother_minColl= new TH1D("selmuon_chi2proton_pother_minColl", "selmuon_chi2proton_pother_minColl", 30, 0, 300);

   selmuon_chi2proton_cont_muon_minColl= new TH1D("selmuon_chi2proton_cont_muon_minColl", "selmuon_chi2proton_cont_muon_minColl", 30, 0, 300);
   selmuon_chi2proton_cont_proton_minColl= new TH1D("selmuon_chi2proton_cont_proton_minColl", "selmuon_chi2proton_cont_proton_minColl", 30, 0, 300);
   selmuon_chi2proton_cont_pion_minColl= new TH1D("selmuon_chi2proton_cont_pion_minColl", "selmuon_chi2proton_cont_pion_minColl", 30, 0, 300);
   selmuon_chi2proton_cont_electron_minColl= new TH1D("selmuon_chi2proton_cont_electron_minColl", "selmuon_chi2proton_cont_electron_minColl", 30, 0, 300);
   selmuon_chi2proton_cont_pother_minColl= new TH1D("selmuon_chi2proton_cont_pother_minColl", "selmuon_chi2proton_cont_pother_minColl", 30, 0, 300);

   selmuon_chi2proton_uncont_muon_minColl= new TH1D("selmuon_chi2proton_uncont_muon_minColl", "selmuon_chi2proton_uncont_muon_minColl", 30, 0, 300);
   selmuon_chi2proton_uncont_proton_minColl= new TH1D("selmuon_chi2proton_uncont_proton_minColl", "selmuon_chi2proton_uncont_proton_minColl", 30, 0, 300);
   selmuon_chi2proton_uncont_pion_minColl= new TH1D("selmuon_chi2proton_uncont_pion_minColl", "selmuon_chi2proton_uncont_pion_minColl", 30, 0, 300);
   selmuon_chi2proton_uncont_electron_minColl= new TH1D("selmuon_chi2proton_uncont_electron_minColl", "selmuon_chi2proton_uncont_electron_minColl", 30, 0, 300);
   selmuon_chi2proton_uncont_pother_minColl= new TH1D("selmuon_chi2proton_uncont_pother_minColl", "selmuon_chi2proton_uncont_pother_minColl", 30, 0, 300);
   
   selmuon_dEdx_vs_resrange_muon_minColl = new TH2D("selmuon_dEdx_vs_resrange_muon_minColl", "selmuon_dEdx_vs_resrange_muon_minColl", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_proton_minColl = new TH2D("selmuon_dEdx_vs_resrange_proton_minColl", "selmuon_dEdx_vs_resrange_proton_minColl", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_pion_minColl = new TH2D("selmuon_dEdx_vs_resrange_pion_minColl", "selmuon_dEdx_vs_resrange_pion_minColl", 50,0,50,20, 0, 20);

///proton properties
   selproton1_lenght_CC0Pion0Proton_minColl= new TH1D("selproton1_lenght_CC0Pion0Proton_minColl", "selproton1_lenght_CC0Pion0Proton_minColl", 10, 0, 100);
   selproton1_lenght_CC0Pion1Proton_minColl= new TH1D("selproton1_lenght_CC0Pion1Proton_minColl", "selproton1_lenght_CC0Pion1Proton_minColl", 10, 0, 100);
   selproton1_lenght_CC0Pion2Proton_minColl= new TH1D("selproton1_lenght_CC0Pion2Proton_minColl", "selproton1_lenght_CC0Pion2Proton_minColl", 10, 0, 100);
   selproton1_lenght_CC0PionNProton_minColl= new TH1D("selproton1_lenght_CC0PionNProton_minColl", "selproton1_lenght_CC0PionNProton_minColl", 10, 0, 100);
   selproton1_lenght_CC1PionNProton_minColl= new TH1D("selproton1_lenght_CC1PionNProton_minColl", "selproton1_lenght_CC1PionNProton_minColl", 10, 0, 100);
   selproton1_lenght_CCNPionNProton_minColl= new TH1D("selproton1_lenght_CCNPionNProton_minColl", "selproton1_lenght_CCNPionNProton_minColl", 10, 0, 100);
   selproton1_lenght_CCNue_minColl= new TH1D("selproton1_lenght_CCNue_minColl", "selproton1_lenght_CCNue_minColl", 10, 0, 100);   
   selproton1_lenght_NC_minColl= new TH1D("selproton1_lenght_NC_minColl", "selproton1_lenght_NC_minColl", 10, 0, 100);
   selproton1_lenght_OOFV_minColl= new TH1D("selproton1_lenght_OOFV_minColl", "selproton1_lenght_OOFV_minColl", 10, 0, 100);
   selproton1_lenght_EXT_minColl= new TH1D("selproton1_lenght_EXT_minColl", "selproton1_lenght_EXT_minColl", 10, 0, 100);
   selproton1_lenght_other_minColl= new TH1D("selproton1_lenght_other_minColl", "selproton1_lenght_other_minColl", 10, 0, 100);
   
   //////////////////////
   selproton1_costheta_CC0Pion0Proton_minColl= new TH1D("selproton1_costheta_CC0Pion0Proton_minColl", "selproton1_costheta_CC0Pion0Proton_minColl", 10, -1, 1);
   selproton1_costheta_CC0Pion1Proton_minColl= new TH1D("selproton1_costheta_CC0Pion1Proton_minColl", "selproton1_costheta_CC0Pion1Proton_minColl", 10, -1, 1);
   selproton1_costheta_CC0Pion2Proton_minColl= new TH1D("selproton1_costheta_CC0Pion2Proton_minColl", "selproton1_costheta_CC0Pion2Proton_minColl", 10, -1, 1);
   selproton1_costheta_CC0PionNProton_minColl= new TH1D("selproton1_costheta_CC0PionNProton_minColl", "selproton1_costheta_CC0PionNProton_minColl", 10, -1, 1);
   selproton1_costheta_CC1PionNProton_minColl= new TH1D("selproton1_costheta_CC1PionNProton_minColl", "selproton1_costheta_CC1PionNProton_minColl", 10, -1, 1);
   selproton1_costheta_CCNPionNProton_minColl= new TH1D("selproton1_costheta_CCNPionNProton_minColl", "selproton1_costheta_CCNPionNProton_minColl", 10, -1, 1);
   selproton1_costheta_CCNue_minColl= new TH1D("selproton1_costheta_CCNue_minColl", "selproton1_costheta_CCNue_minColl", 10, -1, 1);   
   selproton1_costheta_NC_minColl= new TH1D("selproton1_costheta_NC_minColl", "selproton1_costheta_NC_minColl", 10, -1, 1);
   selproton1_costheta_OOFV_minColl= new TH1D("selproton1_costheta_OOFV_minColl", "selproton1_costheta_OOFV_minColl", 10, -1, 1);
   selproton1_costheta_EXT_minColl= new TH1D("selproton1_costheta_EXT_minColl", "selproton1_costheta_EXT_minColl", 10, -1, 1);
   selproton1_costheta_other_minColl= new TH1D("selproton1_costheta_other_minColl", "selproton1_costheta_other_minColl", 10, -1, 1); 
   /////
   selproton1_phi_CC0Pion0Proton_minColl= new TH1D("selproton1_phi_CC0Pion0Proton_minColl", "selproton1_phi_CC0Pion0Proton_minColl", 10, -3.14, 3.14);
   selproton1_phi_CC0Pion1Proton_minColl= new TH1D("selproton1_phi_CC0Pion1Proton_minColl", "selproton1_phi_CC0Pion1Proton_minColl", 10, -3.14, 3.14);
   selproton1_phi_CC0Pion2Proton_minColl= new TH1D("selproton1_phi_CC0Pion2Proton_minColl", "selproton1_phi_CC0Pion2Proton_minColl", 10, -3.14, 3.14);
   selproton1_phi_CC0PionNProton_minColl= new TH1D("selproton1_phi_CC0PionNProton_minColl", "selproton1_phi_CC0PionNProton_minColl", 10, -3.14, 3.14);
   selproton1_phi_CC1PionNProton_minColl= new TH1D("selproton1_phi_CC1PionNProton_minColl", "selproton1_phi_CC1PionNProton_minColl", 10, -3.14, 3.14);
   selproton1_phi_CCNPionNProton_minColl= new TH1D("selproton1_phi_CCNPionNProton_minColl", "selproton1_phi_CCNPionNProton_minColl", 10, -3.14, 3.14);
   selproton1_phi_CCNue_minColl= new TH1D("selproton1_phi_CCNue_minColl", "selproton1_phi_CCNue_minColl", 10, -3.14, 3.14);   
   selproton1_phi_NC_minColl= new TH1D("selproton1_phi_NC_minColl", "selproton1_phi_NC_minColl", 10, -3.14, 3.14);
   selproton1_phi_OOFV_minColl= new TH1D("selproton1_phi_OOFV_minColl", "selproton1_phi_OOFV_minColl", 10, -3.14, 3.14);
   selproton1_phi_EXT_minColl= new TH1D("selproton1_phi_EXT_minColl", "selproton1_phi_EXT_minColl", 10, -3.14, 3.14);
   selproton1_phi_other_minColl= new TH1D("selproton1_phi_other_minColl", "selproton1_phi_other_minColl", 10, -3.14, 3.14); 
   /////

   selproton1_lenght_muon_minColl= new TH1D("selproton1_lenght_muon_minColl", "selproton1_lenght_muon_minColl", 10, 0, 100);
   selproton1_lenght_proton_minColl= new TH1D("selproton1_lenght_proton_minColl", "selproton1_lenght_proton_minColl", 10, 0, 100);
   selproton1_lenght_pion_minColl= new TH1D("selproton1_lenght_pion_minColl", "selproton1_lenght_pion_minColl", 10, 0, 100);
   selproton1_lenght_electron_minColl= new TH1D("selproton1_lenght_electron_minColl", "selproton1_lenght_electron_minColl", 10, 0, 100);
   selproton1_lenght_pother_minColl= new TH1D("selproton1_lenght_pother_minColl", "selproton1_lenght_pother_minColl", 10, 0, 100);
   ////
   selproton1_costheta_muon_minColl= new TH1D("selproton1_costheta_muon_minColl", "selproton1_costheta_muon_minColl", 10, -1, 1);
   selproton1_costheta_proton_minColl= new TH1D("selproton1_costheta_proton_minColl", "selproton1_costheta_proton_minColl", 10, -1, 1);
   selproton1_costheta_pion_minColl= new TH1D("selproton1_costheta_pion_minColl", "selproton1_costheta_pion_minColl", 10, -1, 1);
   selproton1_costheta_electron_minColl= new TH1D("selproton1_costheta_electron_minColl", "selproton1_costheta_electron_minColl", 10, -1, 1);
   selproton1_costheta_pother_minColl= new TH1D("selproton1_costheta_pother_minColl", "selproton1_costheta_pother_minColl", 10, -1, 1);
   ///
   selproton1_phi_muon_minColl= new TH1D("selproton1_phi_muon_minColl", "selproton1_phi_muon_minColl", 10, -3.14, 3.14);
   selproton1_phi_proton_minColl= new TH1D("selproton1_phi_proton_minColl", "selproton1_phi_proton_minColl", 10, -3.14, 3.14);
   selproton1_phi_pion_minColl= new TH1D("selproton1_phi_pion_minColl", "selproton1_phi_pion_minColl", 10, -3.14, 3.14);
   selproton1_phi_electron_minColl= new TH1D("selproton1_phi_electron_minColl", "selproton1_phi_electron_minColl", 10, -3.14, 3.14);
   selproton1_phi_pother_minColl= new TH1D("selproton1_phi_pother_minColl", "selproton1_phi_pother_minColl", 10, -3.14, 3.14);

   selproton1_chi2proton_muon_minColl= new TH1D("selproton1_chi2proton_muon_minColl", "selproton1_chi2proton_muon_minColl", 10, 0, 300);
   selproton1_chi2proton_proton_minColl= new TH1D("selproton1_chi2proton_proton_minColl", "selproton1_chi2proton_proton_minColl", 10, 0, 300);
   selproton1_chi2proton_pion_minColl= new TH1D("selproton1_chi2proton_pion_minColl", "selproton1_chi2proton_pion_minColl", 10, 0, 300);
   selproton1_chi2proton_electron_minColl= new TH1D("selproton1_chi2proton_electron_minColl", "selproton1_chi2proton_electron_minColl", 10, 0, 300);
   selproton1_chi2proton_pother_minColl= new TH1D("selproton1_chi2proton_pother_minColl", "selproton1_chi2proton_pother_minColl", 10, 0, 300);

   selproton1_dEdx_vs_resrange_muon_minColl = new TH2D("selproton1_dEdx_vs_resrange_muon_minColl", "selproton1_dEdx_vs_resrange_muon_minColl", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_proton_minColl = new TH2D("selproton1_dEdx_vs_resrange_proton_minColl", "selproton1_dEdx_vs_resrange_proton_minColl", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_pion_minColl = new TH2D("selproton1_dEdx_vs_resrange_pion_minColl", "selproton1_dEdx_vs_resrange_pion_minColl", 50,0,50,20, 0, 20);

   //////////////////////////////// proton 2///////////////
   
   selproton2_lenght_CC0Pion0Proton_minColl= new TH1D("selproton2_lenght_CC0Pion0Proton_minColl", "selproton2_lenght_CC0Pion0Proton_minColl", 10, 0, 100);
   selproton2_lenght_CC0Pion1Proton_minColl= new TH1D("selproton2_lenght_CC0Pion1Proton_minColl", "selproton2_lenght_CC0Pion1Proton_minColl", 10, 0, 100);
   selproton2_lenght_CC0Pion2Proton_minColl= new TH1D("selproton2_lenght_CC0Pion2Proton_minColl", "selproton2_lenght_CC0Pion2Proton_minColl", 10, 0, 100);
   selproton2_lenght_CC0PionNProton_minColl= new TH1D("selproton2_lenght_CC0PionNProton_minColl", "selproton2_lenght_CC0PionNProton_minColl", 10, 0, 100);
   selproton2_lenght_CC1PionNProton_minColl= new TH1D("selproton2_lenght_CC1PionNProton_minColl", "selproton2_lenght_CC1PionNProton_minColl", 10, 0, 100);
   selproton2_lenght_CCNPionNProton_minColl= new TH1D("selproton2_lenght_CCNPionNProton_minColl", "selproton2_lenght_CCNPionNProton_minColl", 10, 0, 100);
   selproton2_lenght_CCNue_minColl= new TH1D("selproton2_lenght_CCNue_minColl", "selproton2_lenght_CCNue_minColl", 10, 0, 100);
   selproton2_lenght_NC_minColl= new TH1D("selproton2_lenght_NC_minColl", "selproton2_lenght_NC_minColl", 10, 0, 100);
   selproton2_lenght_OOFV_minColl= new TH1D("selproton2_lenght_OOFV_minColl", "selproton2_lenght_OOFV_minColl", 10, 0, 100);
   selproton2_lenght_EXT_minColl= new TH1D("selproton2_lenght_EXT_minColl", "selproton2_lenght_EXT_minColl", 10, 0, 100);
   selproton2_lenght_other_minColl= new TH1D("selproton2_lenght_other_minColl", "selproton2_lenght_other_minColl", 10, 0, 100);

   selproton2_costheta_CC0Pion0Proton_minColl= new TH1D("selproton2_costheta_CC0Pion0Proton_minColl", "selproton2_costheta_CC0Pion0Proton_minColl", 10, -1, 1);
   selproton2_costheta_CC0Pion1Proton_minColl= new TH1D("selproton2_costheta_CC0Pion1Proton_minColl", "selproton2_costheta_CC0Pion1Proton_minColl", 10, -1, 1);
   selproton2_costheta_CC0Pion2Proton_minColl= new TH1D("selproton2_costheta_CC0Pion2Proton_minColl", "selproton2_costheta_CC0Pion2Proton_minColl", 10, -1, 1);
   selproton2_costheta_CC0PionNProton_minColl= new TH1D("selproton2_costheta_CC0PionNProton_minColl", "selproton2_costheta_CC0PionNProton_minColl", 10, -1, 1);
   selproton2_costheta_CC1PionNProton_minColl= new TH1D("selproton2_costheta_CC1PionNProton_minColl", "selproton2_costheta_CC1PionNProton_minColl", 10, -1, 1);
   selproton2_costheta_CCNPionNProton_minColl= new TH1D("selproton2_costheta_CCNPionNProton_minColl", "selproton2_costheta_CCNPionNProton_minColl", 10, -1, 1);
   selproton2_costheta_CCNue_minColl= new TH1D("selproton2_costheta_CCNue_minColl", "selproton2_costheta_CCNue_minColl", 10, -1, 1);   
   selproton2_costheta_NC_minColl= new TH1D("selproton2_costheta_NC_minColl", "selproton2_costheta_NC_minColl", 10, -1, 1);
   selproton2_costheta_OOFV_minColl= new TH1D("selproton2_costheta_OOFV_minColl", "selproton2_costheta_OOFV_minColl", 10, -1, 1);
   selproton2_costheta_EXT_minColl= new TH1D("selproton2_costheta_EXT_minColl", "selproton2_costheta_EXT_minColl", 10, -1, 1);
   selproton2_costheta_other_minColl= new TH1D("selproton2_costheta_other_minColl", "selproton2_costheta_other_minColl", 10, -1, 1); 
   /////
   selproton2_phi_CC0Pion0Proton_minColl= new TH1D("selproton2_phi_CC0Pion0Proton_minColl", "selproton2_phi_CC0Pion0Proton_minColl", 10, -3.14, 3.14);
   selproton2_phi_CC0Pion1Proton_minColl= new TH1D("selproton2_phi_CC0Pion1Proton_minColl", "selproton2_phi_CC0Pion1Proton_minColl", 10, -3.14, 3.14);
   selproton2_phi_CC0Pion2Proton_minColl= new TH1D("selproton2_phi_CC0Pion2Proton_minColl", "selproton2_phi_CC0Pion2Proton_minColl", 10, -3.14, 3.14);
   selproton2_phi_CC0PionNProton_minColl= new TH1D("selproton2_phi_CC0PionNProton_minColl", "selproton2_phi_CC0PionNProton_minColl", 10, -3.14, 3.14);
   selproton2_phi_CC1PionNProton_minColl= new TH1D("selproton2_phi_CC1PionNProton_minColl", "selproton2_phi_CC1PionNProton_minColl", 10, -3.14, 3.14);
   selproton2_phi_CCNPionNProton_minColl= new TH1D("selproton2_phi_CCNPionNProton_minColl", "selproton2_phi_CCNPionNProton_minColl", 10, -3.14, 3.14);
   selproton2_phi_CCNue_minColl= new TH1D("selproton2_phi_CCNue_minColl", "selproton2_phi_CCNue_minColl", 10, -3.14, 3.14);   
   selproton2_phi_NC_minColl= new TH1D("selproton2_phi_NC_minColl", "selproton2_phi_NC_minColl", 10, -3.14, 3.14);
   selproton2_phi_OOFV_minColl= new TH1D("selproton2_phi_OOFV_minColl", "selproton2_phi_OOFV_minColl", 10, -3.14, 3.14);
   selproton2_phi_EXT_minColl= new TH1D("selproton2_phi_EXT_minColl", "selproton2_phi_EXT_minColl", 10, -3.14, 3.14);
   selproton2_phi_other_minColl= new TH1D("selproton2_phi_other_minColl", "selproton2_phi_other_minColl", 10, -3.14, 3.14); 
   /////

   selproton2_lenght_muon_minColl= new TH1D("selproton2_lenght_muon_minColl", "selproton2_lenght_muon_minColl", 10, 0, 100);
   selproton2_lenght_proton_minColl= new TH1D("selproton2_lenght_proton_minColl", "selproton2_lenght_proton_minColl", 10, 0, 100);
   selproton2_lenght_pion_minColl= new TH1D("selproton2_lenght_pion_minColl", "selproton2_lenght_pion_minColl", 10, 0, 100);
   selproton2_lenght_electron_minColl= new TH1D("selproton2_lenght_electron_minColl", "selproton2_lenght_electron_minColl", 10, 0, 100);
   selproton2_lenght_pother_minColl= new TH1D("selproton2_lenght_pother_minColl", "selproton2_lenght_pother_minColl", 10, 0, 100);
   ////
   selproton2_costheta_muon_minColl= new TH1D("selproton2_costheta_muon_minColl", "selproton2_costheta_muon_minColl", 10, -1, 1);
   selproton2_costheta_proton_minColl= new TH1D("selproton2_costheta_proton_minColl", "selproton2_costheta_proton_minColl", 10, -1, 1);
   selproton2_costheta_pion_minColl= new TH1D("selproton2_costheta_pion_minColl", "selproton2_costheta_pion_minColl", 10, -1, 1);
   selproton2_costheta_electron_minColl= new TH1D("selproton2_costheta_electron_minColl", "selproton2_costheta_electron_minColl", 10, -1, 1);
   selproton2_costheta_pother_minColl= new TH1D("selproton2_costheta_pother_minColl", "selproton2_costheta_pother_minColl", 10, -1, 1);
   ///
   selproton2_phi_muon_minColl= new TH1D("selproton2_phi_muon_minColl", "selproton2_phi_muon_minColl", 10, -3.14, 3.14);
   selproton2_phi_proton_minColl= new TH1D("selproton2_phi_proton_minColl", "selproton2_phi_proton_minColl", 10, -3.14, 3.14);
   selproton2_phi_pion_minColl= new TH1D("selproton2_phi_pion_minColl", "selproton2_phi_pion_minColl", 10, -3.14, 3.14);
   selproton2_phi_electron_minColl= new TH1D("selproton2_phi_electron_minColl", "selproton2_phi_electron_minColl", 10, -3.14, 3.14);
   selproton2_phi_pother_minColl= new TH1D("selproton2_phi_pother_minColl", "selproton2_phi_pother_minColl", 10, -3.14, 3.14);

   selproton2_chi2proton_muon_minColl= new TH1D("selproton2_chi2proton_muon_minColl", "selproton2_chi2proton_muon_minColl", 10, 0, 300);
   selproton2_chi2proton_proton_minColl= new TH1D("selproton2_chi2proton_proton_minColl", "selproton2_chi2proton_proton_minColl", 10, 0, 300);
   selproton2_chi2proton_pion_minColl= new TH1D("selproton2_chi2proton_pion_minColl", "selproton2_chi2proton_pion_minColl", 10, 0, 300);
   selproton2_chi2proton_electron_minColl= new TH1D("selproton2_chi2proton_electron_minColl", "selproton2_chi2proton_electron_minColl", 10, 0, 300);
   selproton2_chi2proton_pother_minColl= new TH1D("selproton2_chi2proton_pother_minColl", "selproton2_chi2proton_pother_minColl", 10, 0, 300);

   selproton2_dEdx_vs_resrange_muon_minColl = new TH2D("selproton2_dEdx_vs_resrange_muon_minColl", "selproton2_dEdx_vs_resrange_muon_minColl", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_proton_minColl = new TH2D("selproton2_dEdx_vs_resrange_proton_minColl", "selproton2_dEdx_vs_resrange_proton_minColl", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_pion_minColl = new TH2D("selproton2_dEdx_vs_resrange_pion_minColl", "selproton2_dEdx_vs_resrange_pion_minColl", 50,0,50,20, 0, 20);

   std::cout<<"histos declared"<<endl;
}

void hanalysis_fMC_minColl::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t hanalysis_fMC_minColl::Process(Long64_t entry)
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
   if(track_pfp_Id.GetSize()==3){/// minColl requirement
   
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
       //if(!inFV(track_pfp_startx[np], track_pfp_starty[np], track_pfp_startz[np]) || !inFV(track_pfp_endx[np], track_pfp_endy[np], track_pfp_endz[np])) {tempflag=false;};
       if (!*pfp_upinFVflag) tempflag=false;
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

       if(track_pfp_dEdx[muind].size()<5 ||track_pfp_dEdx[p1ind].size()<5 ||track_pfp_dEdx[p2ind].size()<5) minColl=false;

       if(minColl){

       totentries++;
       if(*truthtop ==1 && trackfromneutrino){
	 topo1++;
	 selmuon_lenght_CC0Pion0Proton_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion0Proton_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion0Proton_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion0Proton_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion0Proton_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion0Proton_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion0Proton_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion0Proton_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion0Proton_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion0Proton_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo1

       else if(*truthtop ==2 && trackfromneutrino){
	 topo2++;
	 selmuon_lenght_CC0Pion1Proton_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion1Proton_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion1Proton_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion1Proton_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion1Proton_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion1Proton_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion1Proton_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion1Proton_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion1Proton_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion1Proton_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo2

       else if(*truthtop ==3 && trackfromneutrino){
	 topo3++;
	 selmuon_lenght_CC0Pion2Proton_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion2Proton_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion2Proton_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion2Proton_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion2Proton_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion2Proton_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion2Proton_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion2Proton_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion2Proton_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion2Proton_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo3

       else if(*truthtop ==4 && trackfromneutrino){
	 topo4++;
	 selmuon_lenght_CC0PionNProton_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0PionNProton_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0PionNProton_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0PionNProton_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0PionNProton_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0PionNProton_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0PionNProton_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0PionNProton_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0PionNProton_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0PionNProton_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo4

       else if(*truthtop ==5 && trackfromneutrino){
	 topo5++;
	 selmuon_lenght_CC1PionNProton_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC1PionNProton_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC1PionNProton_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC1PionNProton_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC1PionNProton_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC1PionNProton_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC1PionNProton_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC1PionNProton_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC1PionNProton_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC1PionNProton_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo5

       else if(*truthtop ==6 && trackfromneutrino){
	 topo6++;
	 selmuon_lenght_CCNPionNProton_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNPionNProton_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNPionNProton_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNPionNProton_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNPionNProton_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNPionNProton_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNPionNProton_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNPionNProton_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNPionNProton_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNPionNProton_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo6

       else if(*truthtop ==7 && trackfromneutrino){
	 topo7++;
	 selmuon_lenght_CCNue_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNue_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNue_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNue_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNue_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNue_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNue_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNue_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNue_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNue_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo7

       else if(*truthtop ==8 && trackfromneutrino){
	 topo8++;
	 selmuon_lenght_NC_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_NC_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_NC_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_NC_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_NC_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_NC_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_NC_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_NC_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_NC_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_NC_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo8
       else if(trackfromneutrino==1 && *OOFVflag==1){
	 topo9++;
	 selmuon_lenght_OOFV_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_OOFV_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_OOFV_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_OOFV_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_OOFV_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_OOFV_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_OOFV_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_OOFV_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_OOFV_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_OOFV_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo9

       else if(!trackfromneutrino){
	 topo10++;
	 selmuon_lenght_EXT_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_EXT_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_EXT_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_EXT_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_EXT_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_EXT_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_EXT_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_EXT_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_EXT_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_EXT_minColl->Fill(track_pfp_phi[p2ind]);
       }// topo9

       else{
	 topo11++;
	 selmuon_lenght_other_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_other_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_other_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_other_minColl->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_other_minColl->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_other_minColl->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_other_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_other_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_other_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_other_minColl->Fill(track_pfp_phi[p2ind]);
       }//else

     //////// **************** /////////////
     //// same histos amd PID per particle type    
     ///////// **************** /////////////

     /// muon candidate /////
       if(pfp_pdg[muind] ==13){
	 selmuon_lenght_muon_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_muon_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_muon_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_muon_minColl->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_muon_minColl->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_muon_minColl->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_muon_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_muon_minColl->Fill(track_pfp_chi2_proton[muind]); 
	 }
       }
       else if(pfp_pdg[muind] ==2212){
	 selmuon_lenght_proton_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_proton_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_proton_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_proton_minColl->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_proton_minColl->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_proton_minColl->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_proton_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_proton_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
       } 
       else if(pfp_pdg[muind] ==211){
	 selmuon_lenght_pion_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_pion_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pion_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pion_minColl->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pion_minColl->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_pion_minColl->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pion_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pion_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
       }
       else if(pfp_pdg[muind] ==11){
	 selmuon_lenght_electron_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_electron_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_electron_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_electron_minColl->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_electron_minColl->Fill(track_pfp_chi2_proton[muind]);
       
	 ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_electron_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_electron_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
       }  

       else{
	 selmuon_lenght_pother_minColl->Fill(track_pfp_length[muind]);
	 selmuon_mom_pother_minColl->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pother_minColl->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pother_minColl->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pother_minColl->Fill(track_pfp_chi2_proton[muind]);
                   
	 //////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pother_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pother_minColl->Fill(track_pfp_chi2_proton[muind]);
	 }
       }           

       if(pfp_pdg[p1ind] ==13){
	 selproton1_lenght_muon_minColl->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_muon_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_muon_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_muon_minColl->Fill(track_pfp_chi2_proton[p1ind]);
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_muon_minColl->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==2212){
	 selproton1_lenght_proton_minColl->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_proton_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_proton_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_proton_minColl->Fill(track_pfp_chi2_proton[p1ind]);

	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_proton_minColl->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==211){
	 selproton1_lenght_pion_minColl->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pion_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pion_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pion_minColl->Fill(track_pfp_chi2_proton[p1ind]);
       
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_pion_minColl->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }
       else if(pfp_pdg[p1ind] ==11){
	 selproton1_lenght_electron_minColl->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_electron_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_electron_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_electron_minColl->Fill(track_pfp_chi2_proton[p1ind]);
       }//electrons

       else{
	 selproton1_lenght_pother_minColl->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pother_minColl->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pother_minColl->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pother_minColl->Fill(track_pfp_chi2_proton[p1ind]);
       }//other
       if(pfp_pdg[p2ind] ==13){
	 selproton2_lenght_muon_minColl->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_muon_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_muon_minColl->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_muon_minColl->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_muon_minColl->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==2212){
	 selproton2_lenght_proton_minColl->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_proton_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_proton_minColl->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_proton_minColl->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_proton_minColl->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==211){
	 selproton2_lenght_pion_minColl->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pion_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pion_minColl->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pion_minColl->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_pion_minColl->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }
       else if(pfp_pdg[p2ind] ==11){
	 selproton2_lenght_electron_minColl->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_electron_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_electron_minColl->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_electron_minColl->Fill(track_pfp_chi2_proton[p2ind]);
       }//electrons

       else{
	 selproton2_lenght_pother_minColl->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pother_minColl->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pother_minColl->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pother_minColl->Fill(track_pfp_chi2_proton[p2ind]);
       }//other
       }/// minimum number collection hits (5)
     }/// mu, p1, p2, muon in FV
   }///minColl requirement

   return kTRUE;
}

void hanalysis_fMC_minColl::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_fMC_minColl::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  cout<<"total number of event processed"<<totentries<<endl;
  cout << "Output file written" << endl;

  fanalysis_minColl->cd();
  fanalysis_minColl->Write();

  std::cout << "root Output file written" << std::endl;
  std::cout << "start writing histos" << std::endl;
  outfileMC_minColl<<"total entries: "<<totentries<<std::endl;
  double topo1fr = topo1/totentries;
  outfileMC_minColl<<"CC0Pion0Proton: "<<topo1<<" purity "<<topo1fr<<std::endl;
  outfileMC_minColl<<"CC0Pion1Proton: "<<topo2<<" purity "<<(topo2/totentries)<<std::endl;
  outfileMC_minColl<<"CC0Pion2Proton: "<<topo3<<" purity "<<double ((topo3/totentries))<<std::endl;
  outfileMC_minColl<<"CC0PionNProton: "<<topo4<<" purity "<<(topo4/totentries)*100.<<std::endl;
  outfileMC_minColl<<"CC1PionNProton: "<<topo5<<" purity "<<(topo5/totentries)*100.<<std::endl;
  outfileMC_minColl<<"CCNPionNProton: "<<topo6<<" purity "<<(topo6/totentries)*100.<<std::endl;
  outfileMC_minColl<<"CCnue: "<<topo7<<" purity "<<(topo7/totentries)*100.<<std::endl;
  outfileMC_minColl<<"NC: "<<topo8<<" purity "<<(topo8/totentries)*100.<<std::endl;
  outfileMC_minColl<<"OOFV: "<<topo9<<" purity "<<(topo9/totentries)*100.<<std::endl;
  outfileMC_minColl<<"cosmic: "<<topo10<<" purity "<<(topo10/totentries)*100.<<std::endl;
  outfileMC_minColl<<"other: "<<topo11<<" purity "<<(topo11/totentries)*100.<<std::endl;

}
