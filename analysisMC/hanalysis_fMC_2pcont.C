#define hanalysis_fMC_2pcont_cxx
// The class definition in hanalysis_fMC_2pcont.h has been generated automatically
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
// root> T->Process("hanalysis_fMC_2pcont.C")
// root> T->Process("hanalysis_fMC_2pcont.C","some options")
// root> T->Process("hanalysis_fMC_2pcont.C+")
//


#include "hanalysis_fMC_2pcont.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TMath.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfileMC_2pcont;
TFile *fanalysis_2pcont;

/// muon candidate properties
TH1D *selmuon_lenght_CC0Pion0Proton_2pcont;
TH1D *selmuon_lenght_CC0Pion1Proton_2pcont;
TH1D *selmuon_lenght_CC0Pion2Proton_2pcont;
TH1D *selmuon_lenght_CC0PionNProton_2pcont;
TH1D *selmuon_lenght_CC1PionNProton_2pcont;
TH1D *selmuon_lenght_CCNPionNProton_2pcont;
TH1D *selmuon_lenght_CCNue_2pcont;
TH1D *selmuon_lenght_NC_2pcont;
TH1D *selmuon_lenght_OOFV_2pcont;
TH1D *selmuon_lenght_EXT_2pcont;
TH1D *selmuon_lenght_other_2pcont;

TH1D *selmuon_mom_CC0Pion0Proton_2pcont;
TH1D *selmuon_mom_CC0Pion1Proton_2pcont;
TH1D *selmuon_mom_CC0Pion2Proton_2pcont;
TH1D *selmuon_mom_CC0PionNProton_2pcont;
TH1D *selmuon_mom_CC1PionNProton_2pcont;
TH1D *selmuon_mom_CCNPionNProton_2pcont;
TH1D *selmuon_mom_CCNue_2pcont;
TH1D *selmuon_mom_NC_2pcont;
TH1D *selmuon_mom_OOFV_2pcont;
TH1D *selmuon_mom_EXT_2pcont;
TH1D *selmuon_mom_other_2pcont;

TH1D *selmuon_contained_mom_CC0Pion0Proton_2pcont;
TH1D *selmuon_contained_mom_CC0Pion1Proton_2pcont;
TH1D *selmuon_contained_mom_CC0Pion2Proton_2pcont;
TH1D *selmuon_contained_mom_CC0PionNProton_2pcont;
TH1D *selmuon_contained_mom_CC1PionNProton_2pcont;
TH1D *selmuon_contained_mom_CCNPionNProton_2pcont;
TH1D *selmuon_contained_mom_CCNue_2pcont;
TH1D *selmuon_contained_mom_NC_2pcont;
TH1D *selmuon_contained_mom_OOFV_2pcont;
TH1D *selmuon_contained_mom_EXT_2pcont;
TH1D *selmuon_contained_mom_other_2pcont;

TH1D *selmuon_uncontained_mom_CC0Pion0Proton_2pcont;
TH1D *selmuon_uncontained_mom_CC0Pion1Proton_2pcont;
TH1D *selmuon_uncontained_mom_CC0Pion2Proton_2pcont;
TH1D *selmuon_uncontained_mom_CC0PionNProton_2pcont;
TH1D *selmuon_uncontained_mom_CC1PionNProton_2pcont;
TH1D *selmuon_uncontained_mom_CCNPionNProton_2pcont;
TH1D *selmuon_uncontained_mom_CCNue_2pcont;
TH1D *selmuon_uncontained_mom_NC_2pcont;
TH1D *selmuon_uncontained_mom_OOFV_2pcont;
TH1D *selmuon_uncontained_mom_EXT_2pcont;
TH1D *selmuon_uncontained_mom_other_2pcont;

TH1D *selmuon_costheta_CC0Pion0Proton_2pcont;
TH1D *selmuon_costheta_CC0Pion1Proton_2pcont;
TH1D *selmuon_costheta_CC0Pion2Proton_2pcont;
TH1D *selmuon_costheta_CC0PionNProton_2pcont;
TH1D *selmuon_costheta_CC1PionNProton_2pcont;
TH1D *selmuon_costheta_CCNPionNProton_2pcont;
TH1D *selmuon_costheta_CCNue_2pcont;
TH1D *selmuon_costheta_NC_2pcont;
TH1D *selmuon_costheta_OOFV_2pcont;
TH1D *selmuon_costheta_EXT_2pcont;
TH1D *selmuon_costheta_other_2pcont;

TH1D *selmuon_phi_CC0Pion0Proton_2pcont;
TH1D *selmuon_phi_CC0Pion1Proton_2pcont;
TH1D *selmuon_phi_CC0Pion2Proton_2pcont;
TH1D *selmuon_phi_CC0PionNProton_2pcont;
TH1D *selmuon_phi_CC1PionNProton_2pcont;
TH1D *selmuon_phi_CCNPionNProton_2pcont;
TH1D *selmuon_phi_CCNue_2pcont;
TH1D *selmuon_phi_NC_2pcont;
TH1D *selmuon_phi_OOFV_2pcont;
TH1D *selmuon_phi_EXT_2pcont;
TH1D *selmuon_phi_other_2pcont;

TH1D *selmuon_lenght_muon_2pcont;
TH1D *selmuon_lenght_proton_2pcont;
TH1D *selmuon_lenght_pion_2pcont;
TH1D *selmuon_lenght_electron_2pcont;
TH1D *selmuon_lenght_pother_2pcont;

TH1D *selmuon_mom_muon_2pcont;
TH1D *selmuon_mom_proton_2pcont;
TH1D *selmuon_mom_pion_2pcont;
TH1D *selmuon_mom_electron_2pcont;
TH1D *selmuon_mom_pother_2pcont;

TH1D *selmuon_contained_mom_muon_2pcont;
TH1D *selmuon_contained_mom_proton_2pcont;
TH1D *selmuon_contained_mom_pion_2pcont;
TH1D *selmuon_contained_mom_electron_2pcont;
TH1D *selmuon_contained_mom_pother_2pcont;

TH1D *selmuon_uncontained_mom_muon_2pcont;
TH1D *selmuon_uncontained_mom_proton_2pcont;
TH1D *selmuon_uncontained_mom_pion_2pcont;
TH1D *selmuon_uncontained_mom_electron_2pcont;
TH1D *selmuon_uncontained_mom_pother_2pcont;

TH1D *selmuon_costheta_muon_2pcont;
TH1D *selmuon_costheta_proton_2pcont;
TH1D *selmuon_costheta_pion_2pcont;
TH1D *selmuon_costheta_electron_2pcont;
TH1D *selmuon_costheta_pother_2pcont;

TH1D *selmuon_phi_muon_2pcont;
TH1D *selmuon_phi_proton_2pcont;
TH1D *selmuon_phi_pion_2pcont;
TH1D *selmuon_phi_electron_2pcont;
TH1D *selmuon_phi_pother_2pcont;

TH1D *selmuon_chi2proton_muon_2pcont;
TH1D *selmuon_chi2proton_proton_2pcont;
TH1D *selmuon_chi2proton_pion_2pcont;
TH1D *selmuon_chi2proton_electron_2pcont;
TH1D *selmuon_chi2proton_pother_2pcont;

TH1D *selmuon_chi2proton_cont_muon_2pcont;
TH1D *selmuon_chi2proton_cont_proton_2pcont;
TH1D *selmuon_chi2proton_cont_pion_2pcont;
TH1D *selmuon_chi2proton_cont_electron_2pcont;
TH1D *selmuon_chi2proton_cont_pother_2pcont;

TH2D *selmuon_dEdx_vs_resrange_muon_2pcont;
TH2D *selmuon_dEdx_vs_resrange_proton_2pcont;
TH2D *selmuon_dEdx_vs_resrange_pion_2pcont;

TH1D *selmuon_chi2proton_uncont_muon_2pcont;
TH1D *selmuon_chi2proton_uncont_proton_2pcont;
TH1D *selmuon_chi2proton_uncont_pion_2pcont;
TH1D *selmuon_chi2proton_uncont_electron_2pcont;
TH1D *selmuon_chi2proton_uncont_pother_2pcont;

///proton properties

TH1D *selproton1_lenght_CC0Pion0Proton_2pcont;
TH1D *selproton1_lenght_CC0Pion1Proton_2pcont;
TH1D *selproton1_lenght_CC0Pion2Proton_2pcont;
TH1D *selproton1_lenght_CC0PionNProton_2pcont;
TH1D *selproton1_lenght_CC1PionNProton_2pcont;
TH1D *selproton1_lenght_CCNPionNProton_2pcont;
TH1D *selproton1_lenght_CCNue_2pcont;
TH1D *selproton1_lenght_NC_2pcont;
TH1D *selproton1_lenght_OOFV_2pcont;
TH1D *selproton1_lenght_EXT_2pcont;
TH1D *selproton1_lenght_other_2pcont;

TH1D *selproton1_costheta_CC0Pion0Proton_2pcont;
TH1D *selproton1_costheta_CC0Pion1Proton_2pcont;
TH1D *selproton1_costheta_CC0Pion2Proton_2pcont;
TH1D *selproton1_costheta_CC0PionNProton_2pcont;
TH1D *selproton1_costheta_CC1PionNProton_2pcont;
TH1D *selproton1_costheta_CCNPionNProton_2pcont;
TH1D *selproton1_costheta_CCNue_2pcont;
TH1D *selproton1_costheta_NC_2pcont;
TH1D *selproton1_costheta_OOFV_2pcont;
TH1D *selproton1_costheta_EXT_2pcont;
TH1D *selproton1_costheta_other_2pcont;

TH1D *selproton1_phi_CC0Pion0Proton_2pcont;
TH1D *selproton1_phi_CC0Pion1Proton_2pcont;
TH1D *selproton1_phi_CC0Pion2Proton_2pcont;
TH1D *selproton1_phi_CC0PionNProton_2pcont;
TH1D *selproton1_phi_CC1PionNProton_2pcont;
TH1D *selproton1_phi_CCNPionNProton_2pcont;
TH1D *selproton1_phi_CCNue_2pcont;
TH1D *selproton1_phi_NC_2pcont;
TH1D *selproton1_phi_OOFV_2pcont;
TH1D *selproton1_phi_EXT_2pcont;
TH1D *selproton1_phi_other_2pcont;

TH1D *selproton1_lenght_muon_2pcont;
TH1D *selproton1_lenght_proton_2pcont;
TH1D *selproton1_lenght_pion_2pcont;
TH1D *selproton1_lenght_electron_2pcont;
TH1D *selproton1_lenght_pother_2pcont;

TH1D *selproton1_costheta_muon_2pcont;
TH1D *selproton1_costheta_proton_2pcont;
TH1D *selproton1_costheta_pion_2pcont;
TH1D *selproton1_costheta_electron_2pcont;
TH1D *selproton1_costheta_pother_2pcont;

TH1D *selproton1_phi_muon_2pcont;
TH1D *selproton1_phi_proton_2pcont;
TH1D *selproton1_phi_pion_2pcont;
TH1D *selproton1_phi_electron_2pcont;
TH1D *selproton1_phi_pother_2pcont;

TH1D *selproton1_chi2proton_muon_2pcont;
TH1D *selproton1_chi2proton_proton_2pcont;
TH1D *selproton1_chi2proton_pion_2pcont;
TH1D *selproton1_chi2proton_electron_2pcont;
TH1D *selproton1_chi2proton_pother_2pcont;

TH2D *selproton1_dEdx_vs_resrange_muon_2pcont;
TH2D *selproton1_dEdx_vs_resrange_proton_2pcont;
TH2D *selproton1_dEdx_vs_resrange_pion_2pcont;

/////////////////////////////////////////////

TH1D *selproton2_lenght_CC0Pion0Proton_2pcont;
TH1D *selproton2_lenght_CC0Pion1Proton_2pcont;
TH1D *selproton2_lenght_CC0Pion2Proton_2pcont;
TH1D *selproton2_lenght_CC0PionNProton_2pcont;
TH1D *selproton2_lenght_CC1PionNProton_2pcont;
TH1D *selproton2_lenght_CCNPionNProton_2pcont;
TH1D *selproton2_lenght_CCNue_2pcont;
TH1D *selproton2_lenght_NC_2pcont;
TH1D *selproton2_lenght_OOFV_2pcont;
TH1D *selproton2_lenght_EXT_2pcont;
TH1D *selproton2_lenght_other_2pcont;

TH1D *selproton2_costheta_CC0Pion0Proton_2pcont;
TH1D *selproton2_costheta_CC0Pion1Proton_2pcont;
TH1D *selproton2_costheta_CC0Pion2Proton_2pcont;
TH1D *selproton2_costheta_CC0PionNProton_2pcont;
TH1D *selproton2_costheta_CC1PionNProton_2pcont;
TH1D *selproton2_costheta_CCNPionNProton_2pcont;
TH1D *selproton2_costheta_CCNue_2pcont;
TH1D *selproton2_costheta_NC_2pcont;
TH1D *selproton2_costheta_OOFV_2pcont;
TH1D *selproton2_costheta_EXT_2pcont;
TH1D *selproton2_costheta_other_2pcont;

TH1D *selproton2_phi_CC0Pion0Proton_2pcont;
TH1D *selproton2_phi_CC0Pion1Proton_2pcont;
TH1D *selproton2_phi_CC0Pion2Proton_2pcont;
TH1D *selproton2_phi_CC0PionNProton_2pcont;
TH1D *selproton2_phi_CC1PionNProton_2pcont;
TH1D *selproton2_phi_CCNPionNProton_2pcont;
TH1D *selproton2_phi_CCNue_2pcont;
TH1D *selproton2_phi_NC_2pcont;
TH1D *selproton2_phi_OOFV_2pcont;
TH1D *selproton2_phi_EXT_2pcont;
TH1D *selproton2_phi_other_2pcont;

TH1D *selproton2_lenght_muon_2pcont;
TH1D *selproton2_lenght_proton_2pcont;
TH1D *selproton2_lenght_pion_2pcont;
TH1D *selproton2_lenght_electron_2pcont;
TH1D *selproton2_lenght_pother_2pcont;

TH1D *selproton2_costheta_muon_2pcont;
TH1D *selproton2_costheta_proton_2pcont;
TH1D *selproton2_costheta_pion_2pcont;
TH1D *selproton2_costheta_electron_2pcont;
TH1D *selproton2_costheta_pother_2pcont;

TH1D *selproton2_phi_muon_2pcont;
TH1D *selproton2_phi_proton_2pcont;
TH1D *selproton2_phi_pion_2pcont;
TH1D *selproton2_phi_electron_2pcont;
TH1D *selproton2_phi_pother_2pcont;

TH1D *selproton2_PIDA_muon_2pcont;
TH1D *selproton2_PIDA_proton_2pcont;
TH1D *selproton2_PIDA_pion_2pcont;
TH1D *selproton2_PIDA_electron_2pcont;
TH1D *selproton2_PIDA_pother_2pcont;

TH1D *selproton2_chi2proton_muon_2pcont;
TH1D *selproton2_chi2proton_proton_2pcont;
TH1D *selproton2_chi2proton_pion_2pcont;
TH1D *selproton2_chi2proton_electron_2pcont;
TH1D *selproton2_chi2proton_pother_2pcont;

TH2D *selproton2_dEdx_vs_resrange_muon_2pcont;
TH2D *selproton2_dEdx_vs_resrange_proton_2pcont;
TH2D *selproton2_dEdx_vs_resrange_pion_2pcont;

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

void hanalysis_fMC_2pcont::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   fanalysis_2pcont= new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_2pcont_BNBMC.root","RECREATE");
   outfileMC_2pcont.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_2pcont_MC.txt");

   std::cout<<"declaring histos"<<endl;
/////////////////// muon candidate properties

   selmuon_lenght_CC0Pion0Proton_2pcont= new TH1D("selmuon_lenght_CC0Pion0Proton_2pcont", "selmuon_lenght_CC0Pion0Proton_2pcont", 20, 0, 500);
   selmuon_lenght_CC0Pion1Proton_2pcont= new TH1D("selmuon_lenght_CC0Pion1Proton_2pcont", "selmuon_lenght_CC0Pion1Proton_2pcont", 20, 0, 500);
   selmuon_lenght_CC0Pion2Proton_2pcont= new TH1D("selmuon_lenght_CC0Pion2Proton_2pcont", "selmuon_lenght_CC0Pion2Proton_2pcont", 20, 0, 500);
   selmuon_lenght_CC0PionNProton_2pcont= new TH1D("selmuon_lenght_CC0PionNProton_2pcont", "selmuon_lenght_CC0PionNProton_2pcont", 20, 0, 500);
   selmuon_lenght_CC1PionNProton_2pcont= new TH1D("selmuon_lenght_CC1PionNProton_2pcont", "selmuon_lenght_CC1PionNProton_2pcont", 20, 0, 500);
   selmuon_lenght_CCNPionNProton_2pcont= new TH1D("selmuon_lenght_CCNPionNProton_2pcont", "selmuon_lenght_CCNPionNProton_2pcont", 20, 0, 500);
   selmuon_lenght_CCNue_2pcont= new TH1D("selmuon_lenght_CCNue_2pcont", "selmuon_lenght_CCNue_2pcont", 20, 0, 500);   
   selmuon_lenght_NC_2pcont= new TH1D("selmuon_lenght_NC_2pcont", "selmuon_lenght_NC_2pcont", 20, 0, 500);
   selmuon_lenght_OOFV_2pcont= new TH1D("selmuon_lenght_OOFV_2pcont", "selmuon_lenght_OOFV_2pcont", 20, 0, 500);
   selmuon_lenght_EXT_2pcont= new TH1D("selmuon_lenght_EXT_2pcont", "selmuon_lenght_EXT_2pcont", 20, 0, 500);
   selmuon_lenght_other_2pcont= new TH1D("selmuon_lenght_other_2pcont", "selmuon_lenght_other_2pcont", 20, 0, 500);   
   ////
   selmuon_mom_CC0Pion0Proton_2pcont= new TH1D("selmuon_mom_CC0Pion0Proton_2pcont", "selmuon_mom_CC0Pion0Proton_2pcont", 20, 0, 3);
   selmuon_mom_CC0Pion1Proton_2pcont= new TH1D("selmuon_mom_CC0Pion1Proton_2pcont", "selmuon_mom_CC0Pion1Proton_2pcont", 20, 0, 3);
   selmuon_mom_CC0Pion2Proton_2pcont= new TH1D("selmuon_mom_CC0Pion2Proton_2pcont", "selmuon_mom_CC0Pion2Proton_2pcont", 20, 0, 3);
   selmuon_mom_CC0PionNProton_2pcont= new TH1D("selmuon_mom_CC0PionNProton_2pcont", "selmuon_mom_CC0PionNProton_2pcont", 20, 0, 3);
   selmuon_mom_CC1PionNProton_2pcont= new TH1D("selmuon_mom_CC1PionNProton_2pcont", "selmuon_mom_CC1PionNProton_2pcont", 20, 0, 3);
   selmuon_mom_CCNPionNProton_2pcont= new TH1D("selmuon_mom_CCNPionNProton_2pcont", "selmuon_mom_CCNPionNProton_2pcont", 20, 0, 3);
   selmuon_mom_CCNue_2pcont= new TH1D("selmuon_mom_CCNue_2pcont", "selmuon_mom_CCNue_2pcont", 20, 0, 3);   
   selmuon_mom_NC_2pcont= new TH1D("selmuon_mom_NC_2pcont", "selmuon_mom_NC_2pcont", 20, 0, 3);
   selmuon_mom_OOFV_2pcont= new TH1D("selmuon_mom_OOFV_2pcont", "selmuon_mom_OOFV_2pcont", 20, 0, 3);
   selmuon_mom_EXT_2pcont= new TH1D("selmuon_mom_EXT_2pcont", "selmuon_mom_EXT_2pcont", 20, 0, 3);
   selmuon_mom_other_2pcont= new TH1D("selmuon_mom_other_2pcont", "selmuon_mom_other_2pcont", 20, 0, 3);   
   ///
   
   selmuon_contained_mom_CC0Pion0Proton_2pcont= new TH1D("selmuon_contained_mom_CC0Pion0Proton_2pcont", "selmuon_contained_mom_CC0Pion0Proton_2pcont", 20, 0, 3);
   selmuon_contained_mom_CC0Pion1Proton_2pcont= new TH1D("selmuon_contained_mom_CC0Pion1Proton_2pcont", "selmuon_contained_mom_CC0Pion1Proton_2pcont", 20, 0, 3);
   selmuon_contained_mom_CC0Pion2Proton_2pcont= new TH1D("selmuon_contained_mom_CC0Pion2Proton_2pcont", "selmuon_contained_mom_CC0Pion2Proton_2pcont", 20, 0, 3);
   selmuon_contained_mom_CC0PionNProton_2pcont= new TH1D("selmuon_contained_mom_CC0PionNProton_2pcont", "selmuon_contained_mom_CC0PionNProton_2pcont", 20, 0, 3);
   selmuon_contained_mom_CC1PionNProton_2pcont= new TH1D("selmuon_contained_mom_CC1PionNProton_2pcont", "selmuon_contained_mom_CC1PionNProton_2pcont", 20, 0, 3);
   selmuon_contained_mom_CCNPionNProton_2pcont= new TH1D("selmuon_contained_mom_CCNPionNProton_2pcont", "selmuon_contained_mom_CCNPionNProton_2pcont", 20, 0, 3);
   selmuon_contained_mom_CCNue_2pcont= new TH1D("selmuon_contained_mom_CCNue_2pcont", "selmuon_contained_mom_CCNue_2pcont", 20, 0, 3);   
   selmuon_contained_mom_NC_2pcont= new TH1D("selmuon_contained_mom_NC_2pcont", "selmuon_contained_mom_NC_2pcont", 20, 0, 3);
   selmuon_contained_mom_OOFV_2pcont= new TH1D("selmuon_contained_mom_OOFV_2pcont", "selmuon_contained_mom_OOFV_2pcont", 20, 0, 3);
   selmuon_contained_mom_EXT_2pcont= new TH1D("selmuon_contained_mom_EXT_2pcont", "selmuon_contained_mom_EXT_2pcont", 20, 0, 3);
   selmuon_contained_mom_other_2pcont= new TH1D("selmuon_contained_mom_other_2pcont", "selmuon_contained_mom_other_2pcont", 20, 0, 3);   
   ////

   selmuon_uncontained_mom_CC0Pion0Proton_2pcont= new TH1D("selmuon_uncontained_mom_CC0Pion0Proton_2pcont", "selmuon_uncontained_mom_CC0Pion0Proton_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_CC0Pion1Proton_2pcont= new TH1D("selmuon_uncontained_mom_CC0Pion1Proton_2pcont", "selmuon_uncontained_mom_CC0Pion1Proton_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_CC0Pion2Proton_2pcont= new TH1D("selmuon_uncontained_mom_CC0Pion2Proton_2pcont", "selmuon_uncontained_mom_CC0Pion2Proton_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_CC0PionNProton_2pcont= new TH1D("selmuon_uncontained_mom_CC0PionNProton_2pcont", "selmuon_uncontained_mom_CC0PionNProton_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_CC1PionNProton_2pcont= new TH1D("selmuon_uncontained_mom_CC1PionNProton_2pcont", "selmuon_uncontained_mom_CC1PionNProton_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_CCNPionNProton_2pcont= new TH1D("selmuon_uncontained_mom_CCNPionNProton_2pcont", "selmuon_uncontained_mom_CCNPionNProton_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_CCNue_2pcont= new TH1D("selmuon_uncontained_mom_CCNue_2pcont", "selmuon_uncontained_mom_CCNue_2pcont", 20, 0, 3);   
   selmuon_uncontained_mom_NC_2pcont= new TH1D("selmuon_uncontained_mom_NC_2pcont", "selmuon_uncontained_mom_NC_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_OOFV_2pcont= new TH1D("selmuon_uncontained_mom_OOFV_2pcont", "selmuon_uncontained_mom_OOFV_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_EXT_2pcont= new TH1D("selmuon_uncontained_mom_EXT_2pcont", "selmuon_uncontained_mom_EXT_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_other_2pcont= new TH1D("selmuon_uncontained_mom_other_2pcont", "selmuon_uncontained_mom_other_2pcont", 20, 0, 3);   
   ////
   selmuon_costheta_CC0Pion0Proton_2pcont= new TH1D("selmuon_costheta_CC0Pion0Proton_2pcont", "selmuon_costheta_CC0Pion0Proton_2pcont", 20, -1, 1);
   selmuon_costheta_CC0Pion1Proton_2pcont= new TH1D("selmuon_costheta_CC0Pion1Proton_2pcont", "selmuon_costheta_CC0Pion1Proton_2pcont", 20, -1, 1);
   selmuon_costheta_CC0Pion2Proton_2pcont= new TH1D("selmuon_costheta_CC0Pion2Proton_2pcont", "selmuon_costheta_CC0Pion2Proton_2pcont", 20, -1, 1);
   selmuon_costheta_CC0PionNProton_2pcont= new TH1D("selmuon_costheta_CC0PionNProton_2pcont", "selmuon_costheta_CC0PionNProton_2pcont", 20, -1, 1);
   selmuon_costheta_CC1PionNProton_2pcont= new TH1D("selmuon_costheta_CC1PionNProton_2pcont", "selmuon_costheta_CC1PionNProton_2pcont", 20, -1, 1);
   selmuon_costheta_CCNPionNProton_2pcont= new TH1D("selmuon_costheta_CCNPionNProton_2pcont", "selmuon_costheta_CCNPionNProton_2pcont", 20, -1, 1);
   selmuon_costheta_CCNue_2pcont= new TH1D("selmuon_costheta_CCNue_2pcont", "selmuon_costheta_CCNue_2pcont", 20, -1, 1);   
   selmuon_costheta_NC_2pcont= new TH1D("selmuon_costheta_NC_2pcont", "selmuon_costheta_NC_2pcont", 20, -1, 1);
   selmuon_costheta_OOFV_2pcont= new TH1D("selmuon_costheta_OOFV_2pcont", "selmuon_costheta_OOFV_2pcont", 20, -1, 1);
   selmuon_costheta_EXT_2pcont= new TH1D("selmuon_costheta_EXT_2pcont", "selmuon_costheta_EXT_2pcont", 20, -1, 1);
   selmuon_costheta_other_2pcont= new TH1D("selmuon_costheta_other_2pcont", "selmuon_costheta_other_2pcont", 20, -1, 1); 
   /////
   selmuon_phi_CC0Pion0Proton_2pcont= new TH1D("selmuon_phi_CC0Pion0Proton_2pcont", "selmuon_phi_CC0Pion0Proton_2pcont", 20, -3.14, 3.14);
   selmuon_phi_CC0Pion1Proton_2pcont= new TH1D("selmuon_phi_CC0Pion1Proton_2pcont", "selmuon_phi_CC0Pion1Proton_2pcont", 20, -3.14, 3.14);
   selmuon_phi_CC0Pion2Proton_2pcont= new TH1D("selmuon_phi_CC0Pion2Proton_2pcont", "selmuon_phi_CC0Pion2Proton_2pcont", 20, -3.14, 3.14);
   selmuon_phi_CC0PionNProton_2pcont= new TH1D("selmuon_phi_CC0PionNProton_2pcont", "selmuon_phi_CC0PionNProton_2pcont", 20, -3.14, 3.14);
   selmuon_phi_CC1PionNProton_2pcont= new TH1D("selmuon_phi_CC1PionNProton_2pcont", "selmuon_phi_CC1PionNProton_2pcont", 20, -3.14, 3.14);
   selmuon_phi_CCNPionNProton_2pcont= new TH1D("selmuon_phi_CCNPionNProton_2pcont", "selmuon_phi_CCNPionNProton_2pcont", 20, -3.14, 3.14);
   selmuon_phi_CCNue_2pcont= new TH1D("selmuon_phi_CCNue_2pcont", "selmuon_phi_CCNue_2pcont", 20, -3.14, 3.14);   
   selmuon_phi_NC_2pcont= new TH1D("selmuon_phi_NC_2pcont", "selmuon_phi_NC_2pcont", 20, -3.14, 3.14);
   selmuon_phi_OOFV_2pcont= new TH1D("selmuon_phi_OOFV_2pcont", "selmuon_phi_OOFV_2pcont", 20, -3.14, 3.14);
   selmuon_phi_EXT_2pcont= new TH1D("selmuon_phi_EXT_2pcont", "selmuon_phi_EXT_2pcont", 20, -3.14, 3.14);
   selmuon_phi_other_2pcont= new TH1D("selmuon_phi_other_2pcont", "selmuon_phi_other_2pcont", 20, -3.14, 3.14); 
   /////

   selmuon_lenght_muon_2pcont= new TH1D("selmuon_lenght_muon_2pcont", "selmuon_lenght_muon_2pcont", 20, 0, 500);
   selmuon_lenght_proton_2pcont= new TH1D("selmuon_lenght_proton_2pcont", "selmuon_lenght_proton_2pcont", 20, 0, 500);
   selmuon_lenght_pion_2pcont= new TH1D("selmuon_lenght_pion_2pcont", "selmuon_lenght_pion_2pcont", 20, 0, 500);
   selmuon_lenght_electron_2pcont= new TH1D("selmuon_lenght_electron_2pcont", "selmuon_lenght_electron_2pcont", 20, 0, 500);
   selmuon_lenght_pother_2pcont= new TH1D("selmuon_lenght_pother_2pcont", "selmuon_lenght_pother_2pcont", 20, 0, 500);
   ////   
   selmuon_mom_muon_2pcont= new TH1D("selmuon_mom_muon_2pcont", "selmuon_mom_muon_2pcont", 20, 0, 3);
   selmuon_mom_proton_2pcont= new TH1D("selmuon_mom_proton_2pcont", "selmuon_mom_proton_2pcont", 20, 0, 3);
   selmuon_mom_pion_2pcont= new TH1D("selmuon_mom_pion_2pcont", "selmuon_mom_pion_2pcont", 20, 0, 3);
   selmuon_mom_electron_2pcont= new TH1D("selmuon_mom_electron_2pcont", "selmuon_mom_electron_2pcont", 20, 0, 3);
   selmuon_mom_pother_2pcont= new TH1D("selmuon_mom_pother_2pcont", "selmuon_mom_pother_2pcont", 20, 0, 3);
   ///
   selmuon_contained_mom_muon_2pcont= new TH1D("selmuon_contained_mom_muon_2pcont", "selmuon_contained_mom_muon_2pcont", 20, 0, 3);
   selmuon_contained_mom_proton_2pcont= new TH1D("selmuon_contained_mom_proton_2pcont", "selmuon_contained_mom_proton_2pcont", 20, 0, 3);
   selmuon_contained_mom_pion_2pcont= new TH1D("selmuon_contained_mom_pion_2pcont", "selmuon_contained_mom_pion_2pcont", 20, 0, 3);
   selmuon_contained_mom_electron_2pcont= new TH1D("selmuon_contained_mom_electron_2pcont", "selmuon_contained_mom_electron_2pcont", 20, 0, 3);
   selmuon_contained_mom_pother_2pcont= new TH1D("selmuon_contained_mom_pother_2pcont", "selmuon_contained_mom_pother_2pcont", 20, 0, 3);
   ///
   selmuon_uncontained_mom_muon_2pcont= new TH1D("selmuon_uncontained_mom_muon_2pcont", "selmuon_uncontained_mom_muon_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_proton_2pcont= new TH1D("selmuon_uncontained_mom_proton_2pcont", "selmuon_uncontained_mom_proton_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_pion_2pcont= new TH1D("selmuon_uncontained_mom_pion_2pcont", "selmuon_uncontained_mom_pion_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_electron_2pcont= new TH1D("selmuon_uncontained_mom_electron_2pcont", "selmuon_uncontained_mom_electron_2pcont", 20, 0, 3);
   selmuon_uncontained_mom_pother_2pcont= new TH1D("selmuon_uncontained_mom_pother_2pcont", "selmuon_uncontained_mom_pother_2pcont", 20, 0, 3);

   ///
   selmuon_costheta_muon_2pcont= new TH1D("selmuon_costheta_muon_2pcont", "selmuon_costheta_muon_2pcont", 20, -1, 1);
   selmuon_costheta_proton_2pcont= new TH1D("selmuon_costheta_proton_2pcont", "selmuon_costheta_proton_2pcont", 20, -1, 1);
   selmuon_costheta_pion_2pcont= new TH1D("selmuon_costheta_pion_2pcont", "selmuon_costheta_pion_2pcont", 20, -1, 1);
   selmuon_costheta_electron_2pcont= new TH1D("selmuon_costheta_electron_2pcont", "selmuon_costheta_electron_2pcont", 20, -1, 1);
   selmuon_costheta_pother_2pcont= new TH1D("selmuon_costheta_pother_2pcont", "selmuon_costheta_pother_2pcont", 20, -1, 1);
   ///
   selmuon_phi_muon_2pcont= new TH1D("selmuon_phi_muon_2pcont", "selmuon_phi_muon_2pcont", 20, -3.14, 3.14);
   selmuon_phi_proton_2pcont= new TH1D("selmuon_phi_proton_2pcont", "selmuon_phi_proton_2pcont", 20, -3.14, 3.14);
   selmuon_phi_pion_2pcont= new TH1D("selmuon_phi_pion_2pcont", "selmuon_phi_pion_2pcont", 20, -3.14, 3.14);
   selmuon_phi_electron_2pcont= new TH1D("selmuon_phi_electron_2pcont", "selmuon_phi_electron_2pcont", 20, -3.14, 3.14);
   selmuon_phi_pother_2pcont= new TH1D("selmuon_phi_pother_2pcont", "selmuon_phi_pother_2pcont", 20, -3.14, 3.14);

   selmuon_chi2proton_muon_2pcont= new TH1D("selmuon_chi2proton_muon_2pcont", "selmuon_chi2proton_muon_2pcont", 30, 0, 300);
   selmuon_chi2proton_proton_2pcont= new TH1D("selmuon_chi2proton_proton_2pcont", "selmuon_chi2proton_proton_2pcont", 30, 0, 300);
   selmuon_chi2proton_pion_2pcont= new TH1D("selmuon_chi2proton_pion_2pcont", "selmuon_chi2proton_pion_2pcont", 30, 0, 300);
   selmuon_chi2proton_electron_2pcont= new TH1D("selmuon_chi2proton_electron_2pcont", "selmuon_chi2proton_electron_2pcont", 30, 0, 300);
   selmuon_chi2proton_pother_2pcont= new TH1D("selmuon_chi2proton_pother_2pcont", "selmuon_chi2proton_pother_2pcont", 30, 0, 300);

   selmuon_chi2proton_cont_muon_2pcont= new TH1D("selmuon_chi2proton_cont_muon_2pcont", "selmuon_chi2proton_cont_muon_2pcont", 30, 0, 300);
   selmuon_chi2proton_cont_proton_2pcont= new TH1D("selmuon_chi2proton_cont_proton_2pcont", "selmuon_chi2proton_cont_proton_2pcont", 30, 0, 300);
   selmuon_chi2proton_cont_pion_2pcont= new TH1D("selmuon_chi2proton_cont_pion_2pcont", "selmuon_chi2proton_cont_pion_2pcont", 30, 0, 300);
   selmuon_chi2proton_cont_electron_2pcont= new TH1D("selmuon_chi2proton_cont_electron_2pcont", "selmuon_chi2proton_cont_electron_2pcont", 30, 0, 300);
   selmuon_chi2proton_cont_pother_2pcont= new TH1D("selmuon_chi2proton_cont_pother_2pcont", "selmuon_chi2proton_cont_pother_2pcont", 30, 0, 300);

   selmuon_chi2proton_uncont_muon_2pcont= new TH1D("selmuon_chi2proton_uncont_muon_2pcont", "selmuon_chi2proton_uncont_muon_2pcont", 30, 0, 300);
   selmuon_chi2proton_uncont_proton_2pcont= new TH1D("selmuon_chi2proton_uncont_proton_2pcont", "selmuon_chi2proton_uncont_proton_2pcont", 30, 0, 300);
   selmuon_chi2proton_uncont_pion_2pcont= new TH1D("selmuon_chi2proton_uncont_pion_2pcont", "selmuon_chi2proton_uncont_pion_2pcont", 30, 0, 300);
   selmuon_chi2proton_uncont_electron_2pcont= new TH1D("selmuon_chi2proton_uncont_electron_2pcont", "selmuon_chi2proton_uncont_electron_2pcont", 30, 0, 300);
   selmuon_chi2proton_uncont_pother_2pcont= new TH1D("selmuon_chi2proton_uncont_pother_2pcont", "selmuon_chi2proton_uncont_pother_2pcont", 30, 0, 300);
   
   selmuon_dEdx_vs_resrange_muon_2pcont = new TH2D("selmuon_dEdx_vs_resrange_muon_2pcont", "selmuon_dEdx_vs_resrange_muon_2pcont", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_proton_2pcont = new TH2D("selmuon_dEdx_vs_resrange_proton_2pcont", "selmuon_dEdx_vs_resrange_proton_2pcont", 50,0,50,20, 0, 20);
   selmuon_dEdx_vs_resrange_pion_2pcont = new TH2D("selmuon_dEdx_vs_resrange_pion_2pcont", "selmuon_dEdx_vs_resrange_pion_2pcont", 50,0,50,20, 0, 20);

///proton properties
   selproton1_lenght_CC0Pion0Proton_2pcont= new TH1D("selproton1_lenght_CC0Pion0Proton_2pcont", "selproton1_lenght_CC0Pion0Proton_2pcont", 20, 0, 100);
   selproton1_lenght_CC0Pion1Proton_2pcont= new TH1D("selproton1_lenght_CC0Pion1Proton_2pcont", "selproton1_lenght_CC0Pion1Proton_2pcont", 20, 0, 100);
   selproton1_lenght_CC0Pion2Proton_2pcont= new TH1D("selproton1_lenght_CC0Pion2Proton_2pcont", "selproton1_lenght_CC0Pion2Proton_2pcont", 20, 0, 100);
   selproton1_lenght_CC0PionNProton_2pcont= new TH1D("selproton1_lenght_CC0PionNProton_2pcont", "selproton1_lenght_CC0PionNProton_2pcont", 20, 0, 100);
   selproton1_lenght_CC1PionNProton_2pcont= new TH1D("selproton1_lenght_CC1PionNProton_2pcont", "selproton1_lenght_CC1PionNProton_2pcont", 20, 0, 100);
   selproton1_lenght_CCNPionNProton_2pcont= new TH1D("selproton1_lenght_CCNPionNProton_2pcont", "selproton1_lenght_CCNPionNProton_2pcont", 20, 0, 100);
   selproton1_lenght_CCNue_2pcont= new TH1D("selproton1_lenght_CCNue_2pcont", "selproton1_lenght_CCNue_2pcont", 20, 0, 100);   
   selproton1_lenght_NC_2pcont= new TH1D("selproton1_lenght_NC_2pcont", "selproton1_lenght_NC_2pcont", 20, 0, 100);
   selproton1_lenght_OOFV_2pcont= new TH1D("selproton1_lenght_OOFV_2pcont", "selproton1_lenght_OOFV_2pcont", 20, 0, 100);
   selproton1_lenght_EXT_2pcont= new TH1D("selproton1_lenght_EXT_2pcont", "selproton1_lenght_EXT_2pcont", 20, 0, 100);
   selproton1_lenght_other_2pcont= new TH1D("selproton1_lenght_other_2pcont", "selproton1_lenght_other_2pcont", 20, 0, 100);
   
   //////////////////////
   selproton1_costheta_CC0Pion0Proton_2pcont= new TH1D("selproton1_costheta_CC0Pion0Proton_2pcont", "selproton1_costheta_CC0Pion0Proton_2pcont", 20, -1, 1);
   selproton1_costheta_CC0Pion1Proton_2pcont= new TH1D("selproton1_costheta_CC0Pion1Proton_2pcont", "selproton1_costheta_CC0Pion1Proton_2pcont", 20, -1, 1);
   selproton1_costheta_CC0Pion2Proton_2pcont= new TH1D("selproton1_costheta_CC0Pion2Proton_2pcont", "selproton1_costheta_CC0Pion2Proton_2pcont", 20, -1, 1);
   selproton1_costheta_CC0PionNProton_2pcont= new TH1D("selproton1_costheta_CC0PionNProton_2pcont", "selproton1_costheta_CC0PionNProton_2pcont", 20, -1, 1);
   selproton1_costheta_CC1PionNProton_2pcont= new TH1D("selproton1_costheta_CC1PionNProton_2pcont", "selproton1_costheta_CC1PionNProton_2pcont", 20, -1, 1);
   selproton1_costheta_CCNPionNProton_2pcont= new TH1D("selproton1_costheta_CCNPionNProton_2pcont", "selproton1_costheta_CCNPionNProton_2pcont", 20, -1, 1);
   selproton1_costheta_CCNue_2pcont= new TH1D("selproton1_costheta_CCNue_2pcont", "selproton1_costheta_CCNue_2pcont", 20, -1, 1);   
   selproton1_costheta_NC_2pcont= new TH1D("selproton1_costheta_NC_2pcont", "selproton1_costheta_NC_2pcont", 20, -1, 1);
   selproton1_costheta_OOFV_2pcont= new TH1D("selproton1_costheta_OOFV_2pcont", "selproton1_costheta_OOFV_2pcont", 20, -1, 1);
   selproton1_costheta_EXT_2pcont= new TH1D("selproton1_costheta_EXT_2pcont", "selproton1_costheta_EXT_2pcont", 20, -1, 1);
   selproton1_costheta_other_2pcont= new TH1D("selproton1_costheta_other_2pcont", "selproton1_costheta_other_2pcont", 20, -1, 1); 
   /////
   selproton1_phi_CC0Pion0Proton_2pcont= new TH1D("selproton1_phi_CC0Pion0Proton_2pcont", "selproton1_phi_CC0Pion0Proton_2pcont", 20, -3.14, 3.14);
   selproton1_phi_CC0Pion1Proton_2pcont= new TH1D("selproton1_phi_CC0Pion1Proton_2pcont", "selproton1_phi_CC0Pion1Proton_2pcont", 20, -3.14, 3.14);
   selproton1_phi_CC0Pion2Proton_2pcont= new TH1D("selproton1_phi_CC0Pion2Proton_2pcont", "selproton1_phi_CC0Pion2Proton_2pcont", 20, -3.14, 3.14);
   selproton1_phi_CC0PionNProton_2pcont= new TH1D("selproton1_phi_CC0PionNProton_2pcont", "selproton1_phi_CC0PionNProton_2pcont", 20, -3.14, 3.14);
   selproton1_phi_CC1PionNProton_2pcont= new TH1D("selproton1_phi_CC1PionNProton_2pcont", "selproton1_phi_CC1PionNProton_2pcont", 20, -3.14, 3.14);
   selproton1_phi_CCNPionNProton_2pcont= new TH1D("selproton1_phi_CCNPionNProton_2pcont", "selproton1_phi_CCNPionNProton_2pcont", 20, -3.14, 3.14);
   selproton1_phi_CCNue_2pcont= new TH1D("selproton1_phi_CCNue_2pcont", "selproton1_phi_CCNue_2pcont", 20, -3.14, 3.14);   
   selproton1_phi_NC_2pcont= new TH1D("selproton1_phi_NC_2pcont", "selproton1_phi_NC_2pcont", 20, -3.14, 3.14);
   selproton1_phi_OOFV_2pcont= new TH1D("selproton1_phi_OOFV_2pcont", "selproton1_phi_OOFV_2pcont", 20, -3.14, 3.14);
   selproton1_phi_EXT_2pcont= new TH1D("selproton1_phi_EXT_2pcont", "selproton1_phi_EXT_2pcont", 20, -3.14, 3.14);
   selproton1_phi_other_2pcont= new TH1D("selproton1_phi_other_2pcont", "selproton1_phi_other_2pcont", 20, -3.14, 3.14); 
   /////

   selproton1_lenght_muon_2pcont= new TH1D("selproton1_lenght_muon_2pcont", "selproton1_lenght_muon_2pcont", 20, 0, 100);
   selproton1_lenght_proton_2pcont= new TH1D("selproton1_lenght_proton_2pcont", "selproton1_lenght_proton_2pcont", 20, 0, 100);
   selproton1_lenght_pion_2pcont= new TH1D("selproton1_lenght_pion_2pcont", "selproton1_lenght_pion_2pcont", 20, 0, 100);
   selproton1_lenght_electron_2pcont= new TH1D("selproton1_lenght_electron_2pcont", "selproton1_lenght_electron_2pcont", 20, 0, 100);
   selproton1_lenght_pother_2pcont= new TH1D("selproton1_lenght_pother_2pcont", "selproton1_lenght_pother_2pcont", 20, 0, 100);
   ////
   selproton1_costheta_muon_2pcont= new TH1D("selproton1_costheta_muon_2pcont", "selproton1_costheta_muon_2pcont", 20, -1, 1);
   selproton1_costheta_proton_2pcont= new TH1D("selproton1_costheta_proton_2pcont", "selproton1_costheta_proton_2pcont", 20, -1, 1);
   selproton1_costheta_pion_2pcont= new TH1D("selproton1_costheta_pion_2pcont", "selproton1_costheta_pion_2pcont", 20, -1, 1);
   selproton1_costheta_electron_2pcont= new TH1D("selproton1_costheta_electron_2pcont", "selproton1_costheta_electron_2pcont", 20, -1, 1);
   selproton1_costheta_pother_2pcont= new TH1D("selproton1_costheta_pother_2pcont", "selproton1_costheta_pother_2pcont", 20, -1, 1);
   ///
   selproton1_phi_muon_2pcont= new TH1D("selproton1_phi_muon_2pcont", "selproton1_phi_muon_2pcont", 20, -3.14, 3.14);
   selproton1_phi_proton_2pcont= new TH1D("selproton1_phi_proton_2pcont", "selproton1_phi_proton_2pcont", 20, -3.14, 3.14);
   selproton1_phi_pion_2pcont= new TH1D("selproton1_phi_pion_2pcont", "selproton1_phi_pion_2pcont", 20, -3.14, 3.14);
   selproton1_phi_electron_2pcont= new TH1D("selproton1_phi_electron_2pcont", "selproton1_phi_electron_2pcont", 20, -3.14, 3.14);
   selproton1_phi_pother_2pcont= new TH1D("selproton1_phi_pother_2pcont", "selproton1_phi_pother_2pcont", 20, -3.14, 3.14);

   selproton1_chi2proton_muon_2pcont= new TH1D("selproton1_chi2proton_muon_2pcont", "selproton1_chi2proton_muon_2pcont", 30, 0, 300);
   selproton1_chi2proton_proton_2pcont= new TH1D("selproton1_chi2proton_proton_2pcont", "selproton1_chi2proton_proton_2pcont", 30, 0, 300);
   selproton1_chi2proton_pion_2pcont= new TH1D("selproton1_chi2proton_pion_2pcont", "selproton1_chi2proton_pion_2pcont", 30, 0, 300);
   selproton1_chi2proton_electron_2pcont= new TH1D("selproton1_chi2proton_electron_2pcont", "selproton1_chi2proton_electron_2pcont", 30, 0, 300);
   selproton1_chi2proton_pother_2pcont= new TH1D("selproton1_chi2proton_pother_2pcont", "selproton1_chi2proton_pother_2pcont", 30, 0, 300);

   selproton1_dEdx_vs_resrange_muon_2pcont = new TH2D("selproton1_dEdx_vs_resrange_muon_2pcont", "selproton1_dEdx_vs_resrange_muon_2pcont", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_proton_2pcont = new TH2D("selproton1_dEdx_vs_resrange_proton_2pcont", "selproton1_dEdx_vs_resrange_proton_2pcont", 50,0,50,20, 0, 20);
   selproton1_dEdx_vs_resrange_pion_2pcont = new TH2D("selproton1_dEdx_vs_resrange_pion_2pcont", "selproton1_dEdx_vs_resrange_pion_2pcont", 50,0,50,20, 0, 20);

   //////////////////////////////// proton 2///////////////
   
   selproton2_lenght_CC0Pion0Proton_2pcont= new TH1D("selproton2_lenght_CC0Pion0Proton_2pcont", "selproton2_lenght_CC0Pion0Proton_2pcont", 20, 0, 100);
   selproton2_lenght_CC0Pion1Proton_2pcont= new TH1D("selproton2_lenght_CC0Pion1Proton_2pcont", "selproton2_lenght_CC0Pion1Proton_2pcont", 20, 0, 100);
   selproton2_lenght_CC0Pion2Proton_2pcont= new TH1D("selproton2_lenght_CC0Pion2Proton_2pcont", "selproton2_lenght_CC0Pion2Proton_2pcont", 20, 0, 100);
   selproton2_lenght_CC0PionNProton_2pcont= new TH1D("selproton2_lenght_CC0PionNProton_2pcont", "selproton2_lenght_CC0PionNProton_2pcont", 20, 0, 100);
   selproton2_lenght_CC1PionNProton_2pcont= new TH1D("selproton2_lenght_CC1PionNProton_2pcont", "selproton2_lenght_CC1PionNProton_2pcont", 20, 0, 100);
   selproton2_lenght_CCNPionNProton_2pcont= new TH1D("selproton2_lenght_CCNPionNProton_2pcont", "selproton2_lenght_CCNPionNProton_2pcont", 20, 0, 100);
   selproton2_lenght_CCNue_2pcont= new TH1D("selproton2_lenght_CCNue_2pcont", "selproton2_lenght_CCNue_2pcont", 20, 0, 100);
   selproton2_lenght_NC_2pcont= new TH1D("selproton2_lenght_NC_2pcont", "selproton2_lenght_NC_2pcont", 20, 0, 100);
   selproton2_lenght_OOFV_2pcont= new TH1D("selproton2_lenght_OOFV_2pcont", "selproton2_lenght_OOFV_2pcont", 20, 0, 100);
   selproton2_lenght_EXT_2pcont= new TH1D("selproton2_lenght_EXT_2pcont", "selproton2_lenght_EXT_2pcont", 20, 0, 100);
   selproton2_lenght_other_2pcont= new TH1D("selproton2_lenght_other_2pcont", "selproton2_lenght_other_2pcont", 20, 0, 100);

   selproton2_costheta_CC0Pion0Proton_2pcont= new TH1D("selproton2_costheta_CC0Pion0Proton_2pcont", "selproton2_costheta_CC0Pion0Proton_2pcont", 20, -1, 1);
   selproton2_costheta_CC0Pion1Proton_2pcont= new TH1D("selproton2_costheta_CC0Pion1Proton_2pcont", "selproton2_costheta_CC0Pion1Proton_2pcont", 20, -1, 1);
   selproton2_costheta_CC0Pion2Proton_2pcont= new TH1D("selproton2_costheta_CC0Pion2Proton_2pcont", "selproton2_costheta_CC0Pion2Proton_2pcont", 20, -1, 1);
   selproton2_costheta_CC0PionNProton_2pcont= new TH1D("selproton2_costheta_CC0PionNProton_2pcont", "selproton2_costheta_CC0PionNProton_2pcont", 20, -1, 1);
   selproton2_costheta_CC1PionNProton_2pcont= new TH1D("selproton2_costheta_CC1PionNProton_2pcont", "selproton2_costheta_CC1PionNProton_2pcont", 20, -1, 1);
   selproton2_costheta_CCNPionNProton_2pcont= new TH1D("selproton2_costheta_CCNPionNProton_2pcont", "selproton2_costheta_CCNPionNProton_2pcont", 20, -1, 1);
   selproton2_costheta_CCNue_2pcont= new TH1D("selproton2_costheta_CCNue_2pcont", "selproton2_costheta_CCNue_2pcont", 20, -1, 1);   
   selproton2_costheta_NC_2pcont= new TH1D("selproton2_costheta_NC_2pcont", "selproton2_costheta_NC_2pcont", 20, -1, 1);
   selproton2_costheta_OOFV_2pcont= new TH1D("selproton2_costheta_OOFV_2pcont", "selproton2_costheta_OOFV_2pcont", 20, -1, 1);
   selproton2_costheta_EXT_2pcont= new TH1D("selproton2_costheta_EXT_2pcont", "selproton2_costheta_EXT_2pcont", 20, -1, 1);
   selproton2_costheta_other_2pcont= new TH1D("selproton2_costheta_other_2pcont", "selproton2_costheta_other_2pcont", 20, -1, 1); 
   /////
   selproton2_phi_CC0Pion0Proton_2pcont= new TH1D("selproton2_phi_CC0Pion0Proton_2pcont", "selproton2_phi_CC0Pion0Proton_2pcont", 20, -3.14, 3.14);
   selproton2_phi_CC0Pion1Proton_2pcont= new TH1D("selproton2_phi_CC0Pion1Proton_2pcont", "selproton2_phi_CC0Pion1Proton_2pcont", 20, -3.14, 3.14);
   selproton2_phi_CC0Pion2Proton_2pcont= new TH1D("selproton2_phi_CC0Pion2Proton_2pcont", "selproton2_phi_CC0Pion2Proton_2pcont", 20, -3.14, 3.14);
   selproton2_phi_CC0PionNProton_2pcont= new TH1D("selproton2_phi_CC0PionNProton_2pcont", "selproton2_phi_CC0PionNProton_2pcont", 20, -3.14, 3.14);
   selproton2_phi_CC1PionNProton_2pcont= new TH1D("selproton2_phi_CC1PionNProton_2pcont", "selproton2_phi_CC1PionNProton_2pcont", 20, -3.14, 3.14);
   selproton2_phi_CCNPionNProton_2pcont= new TH1D("selproton2_phi_CCNPionNProton_2pcont", "selproton2_phi_CCNPionNProton_2pcont", 20, -3.14, 3.14);
   selproton2_phi_CCNue_2pcont= new TH1D("selproton2_phi_CCNue_2pcont", "selproton2_phi_CCNue_2pcont", 20, -3.14, 3.14);   
   selproton2_phi_NC_2pcont= new TH1D("selproton2_phi_NC_2pcont", "selproton2_phi_NC_2pcont", 20, -3.14, 3.14);
   selproton2_phi_OOFV_2pcont= new TH1D("selproton2_phi_OOFV_2pcont", "selproton2_phi_OOFV_2pcont", 20, -3.14, 3.14);
   selproton2_phi_EXT_2pcont= new TH1D("selproton2_phi_EXT_2pcont", "selproton2_phi_EXT_2pcont", 20, -3.14, 3.14);
   selproton2_phi_other_2pcont= new TH1D("selproton2_phi_other_2pcont", "selproton2_phi_other_2pcont", 20, -3.14, 3.14); 
   /////

   selproton2_lenght_muon_2pcont= new TH1D("selproton2_lenght_muon_2pcont", "selproton2_lenght_muon_2pcont", 20, 0, 100);
   selproton2_lenght_proton_2pcont= new TH1D("selproton2_lenght_proton_2pcont", "selproton2_lenght_proton_2pcont", 20, 0, 100);
   selproton2_lenght_pion_2pcont= new TH1D("selproton2_lenght_pion_2pcont", "selproton2_lenght_pion_2pcont", 20, 0, 100);
   selproton2_lenght_electron_2pcont= new TH1D("selproton2_lenght_electron_2pcont", "selproton2_lenght_electron_2pcont", 20, 0, 100);
   selproton2_lenght_pother_2pcont= new TH1D("selproton2_lenght_pother_2pcont", "selproton2_lenght_pother_2pcont", 20, 0, 100);
   ////
   selproton2_costheta_muon_2pcont= new TH1D("selproton2_costheta_muon_2pcont", "selproton2_costheta_muon_2pcont", 20, -1, 1);
   selproton2_costheta_proton_2pcont= new TH1D("selproton2_costheta_proton_2pcont", "selproton2_costheta_proton_2pcont", 20, -1, 1);
   selproton2_costheta_pion_2pcont= new TH1D("selproton2_costheta_pion_2pcont", "selproton2_costheta_pion_2pcont", 20, -1, 1);
   selproton2_costheta_electron_2pcont= new TH1D("selproton2_costheta_electron_2pcont", "selproton2_costheta_electron_2pcont", 20, -1, 1);
   selproton2_costheta_pother_2pcont= new TH1D("selproton2_costheta_pother_2pcont", "selproton2_costheta_pother_2pcont", 20, -1, 1);
   ///
   selproton2_phi_muon_2pcont= new TH1D("selproton2_phi_muon_2pcont", "selproton2_phi_muon_2pcont", 20, -3.14, 3.14);
   selproton2_phi_proton_2pcont= new TH1D("selproton2_phi_proton_2pcont", "selproton2_phi_proton_2pcont", 20, -3.14, 3.14);
   selproton2_phi_pion_2pcont= new TH1D("selproton2_phi_pion_2pcont", "selproton2_phi_pion_2pcont", 20, -3.14, 3.14);
   selproton2_phi_electron_2pcont= new TH1D("selproton2_phi_electron_2pcont", "selproton2_phi_electron_2pcont", 20, -3.14, 3.14);
   selproton2_phi_pother_2pcont= new TH1D("selproton2_phi_pother_2pcont", "selproton2_phi_pother_2pcont", 20, -3.14, 3.14);

   selproton2_chi2proton_muon_2pcont= new TH1D("selproton2_chi2proton_muon_2pcont", "selproton2_chi2proton_muon_2pcont", 30, 0, 300);
   selproton2_chi2proton_proton_2pcont= new TH1D("selproton2_chi2proton_proton_2pcont", "selproton2_chi2proton_proton_2pcont", 30, 0, 300);
   selproton2_chi2proton_pion_2pcont= new TH1D("selproton2_chi2proton_pion_2pcont", "selproton2_chi2proton_pion_2pcont", 30, 0, 300);
   selproton2_chi2proton_electron_2pcont= new TH1D("selproton2_chi2proton_electron_2pcont", "selproton2_chi2proton_electron_2pcont", 30, 0, 300);
   selproton2_chi2proton_pother_2pcont= new TH1D("selproton2_chi2proton_pother_2pcont", "selproton2_chi2proton_pother_2pcont", 30, 0, 300);

   selproton2_dEdx_vs_resrange_muon_2pcont = new TH2D("selproton2_dEdx_vs_resrange_muon_2pcont", "selproton2_dEdx_vs_resrange_muon_2pcont", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_proton_2pcont = new TH2D("selproton2_dEdx_vs_resrange_proton_2pcont", "selproton2_dEdx_vs_resrange_proton_2pcont", 50,0,50,20, 0, 20);
   selproton2_dEdx_vs_resrange_pion_2pcont = new TH2D("selproton2_dEdx_vs_resrange_pion_2pcont", "selproton2_dEdx_vs_resrange_pion_2pcont", 50,0,50,20, 0, 20);

   std::cout<<"histos declared"<<endl;
}

void hanalysis_fMC_2pcont::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t hanalysis_fMC_2pcont::Process(Long64_t entry)
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
   if(track_pfp_Id.GetSize()==3){/// 2pcont requirement
   
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

     if(muind !=-1 &&p1ind !=-1 && p2ind !=-1 && tempflag){/// requirements
       totentries++;
       if(*truthtop ==1 && trackfromneutrino){
	 topo1++;
	 selmuon_lenght_CC0Pion0Proton_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion0Proton_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion0Proton_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion0Proton_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion0Proton_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion0Proton_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion0Proton_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion0Proton_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion0Proton_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion0Proton_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo1

       else if(*truthtop ==2 && trackfromneutrino){
	 topo2++;
	 selmuon_lenght_CC0Pion1Proton_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion1Proton_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion1Proton_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion1Proton_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion1Proton_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion1Proton_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion1Proton_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion1Proton_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion1Proton_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion1Proton_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo2

       else if(*truthtop ==3 && trackfromneutrino){
	 topo3++;
	 selmuon_lenght_CC0Pion2Proton_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0Pion2Proton_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0Pion2Proton_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0Pion2Proton_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0Pion2Proton_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0Pion2Proton_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0Pion2Proton_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0Pion2Proton_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0Pion2Proton_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0Pion2Proton_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo3

       else if(*truthtop ==4 && trackfromneutrino){
	 topo4++;
	 selmuon_lenght_CC0PionNProton_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC0PionNProton_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC0PionNProton_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC0PionNProton_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC0PionNProton_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC0PionNProton_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC0PionNProton_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC0PionNProton_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC0PionNProton_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC0PionNProton_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo4

       else if(*truthtop ==5 && trackfromneutrino){
	 topo5++;
	 selmuon_lenght_CC1PionNProton_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_CC1PionNProton_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CC1PionNProton_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CC1PionNProton_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CC1PionNProton_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CC1PionNProton_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CC1PionNProton_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CC1PionNProton_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CC1PionNProton_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CC1PionNProton_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo5

       else if(*truthtop ==6 && trackfromneutrino){
	 topo6++;
	 selmuon_lenght_CCNPionNProton_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNPionNProton_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNPionNProton_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNPionNProton_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNPionNProton_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNPionNProton_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNPionNProton_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNPionNProton_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNPionNProton_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNPionNProton_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo6

       else if(*truthtop ==7 && trackfromneutrino){
	 topo7++;
	 selmuon_lenght_CCNue_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_CCNue_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_CCNue_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_CCNue_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_CCNue_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_CCNue_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_CCNue_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_CCNue_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_CCNue_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_CCNue_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo7

       else if(*truthtop ==8 && trackfromneutrino){
	 topo8++;
	 selmuon_lenght_NC_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_NC_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_NC_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_NC_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_NC_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_NC_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_NC_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_NC_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_NC_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_NC_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo8
       else if(trackfromneutrino==1 && *OOFVflag==1){
	 topo9++;
	 selmuon_lenght_OOFV_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_OOFV_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_OOFV_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_OOFV_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_OOFV_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_OOFV_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_OOFV_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_OOFV_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_OOFV_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_OOFV_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo9

       else if(!trackfromneutrino){
	 topo10++;
	 selmuon_lenght_EXT_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_EXT_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_EXT_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_EXT_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_EXT_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_EXT_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_EXT_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_EXT_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_EXT_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_EXT_2pcont->Fill(track_pfp_phi[p2ind]);
       }// topo9

       else{
	 topo11++;
	 selmuon_lenght_other_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_other_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_other_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_other_2pcont->Fill(track_pfp_phi[muind]);
	 selproton1_lenght_other_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton2_lenght_other_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton1_costheta_other_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton2_costheta_other_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton1_phi_other_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton2_phi_other_2pcont->Fill(track_pfp_phi[p2ind]);
       }//else

     //////// **************** /////////////
     //// same histos amd PID per particle type    
     ///////// **************** /////////////

     /// muon candidate /////
       if(pfp_pdg[muind] ==13){
	 selmuon_lenght_muon_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_muon_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_muon_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_muon_2pcont->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_muon_2pcont->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_muon_2pcont->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_muon_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_muon_2pcont->Fill(track_pfp_chi2_proton[muind]); 
	 }
       }
       else if(pfp_pdg[muind] ==2212){
	 selmuon_lenght_proton_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_proton_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_proton_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_proton_2pcont->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_proton_2pcont->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_proton_2pcont->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_proton_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_proton_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
       } 
       else if(pfp_pdg[muind] ==211){
	 selmuon_lenght_pion_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_pion_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pion_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pion_2pcont->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pion_2pcont->Fill(track_pfp_chi2_proton[muind]);
       
	 for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	   selmuon_dEdx_vs_resrange_pion_2pcont->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
	 }
             
       ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pion_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pion_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
       }
       else if(pfp_pdg[muind] ==11){
	 selmuon_lenght_electron_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_electron_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_electron_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_electron_2pcont->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_electron_2pcont->Fill(track_pfp_chi2_proton[muind]);
       
	 ////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_electron_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_electron_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
       }  

       else{
	 selmuon_lenght_pother_2pcont->Fill(track_pfp_length[muind]);
	 selmuon_mom_pother_2pcont->Fill(*track_pfp_mom_mucand);
	 selmuon_costheta_pother_2pcont->Fill(track_pfp_costheta[muind]);
	 selmuon_phi_pother_2pcont->Fill(track_pfp_phi[muind]);
	 selmuon_chi2proton_pother_2pcont->Fill(track_pfp_chi2_proton[muind]);
                   
	 //////contained
	 if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	   selmuon_chi2proton_cont_pother_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
	 else{ //uncontained
	   selmuon_chi2proton_uncont_pother_2pcont->Fill(track_pfp_chi2_proton[muind]);
	 }
       }           

       if(pfp_pdg[p1ind] ==13){
	 selproton1_lenght_muon_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_muon_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_muon_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_muon_2pcont->Fill(track_pfp_chi2_proton[p1ind]);
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_muon_2pcont->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==2212){
	 selproton1_lenght_proton_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_proton_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_proton_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_proton_2pcont->Fill(track_pfp_chi2_proton[p1ind]);

	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_proton_2pcont->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }

       else if(pfp_pdg[p1ind] ==211){
	 selproton1_lenght_pion_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pion_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pion_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pion_2pcont->Fill(track_pfp_chi2_proton[p1ind]);
       
	 for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	   selproton1_dEdx_vs_resrange_pion_2pcont->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
	 }
       }
       else if(pfp_pdg[p1ind] ==11){
	 selproton1_lenght_electron_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_electron_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_electron_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_electron_2pcont->Fill(track_pfp_chi2_proton[p1ind]);
       }//electrons

       else{
	 selproton1_lenght_pother_2pcont->Fill(track_pfp_length[p1ind]);
	 selproton1_costheta_pother_2pcont->Fill(track_pfp_costheta[p1ind]);
	 selproton1_phi_pother_2pcont->Fill(track_pfp_phi[p1ind]);
	 selproton1_chi2proton_pother_2pcont->Fill(track_pfp_chi2_proton[p1ind]);
       }//other
       if(pfp_pdg[p2ind] ==13){
	 selproton2_lenght_muon_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_muon_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_muon_2pcont->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_muon_2pcont->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_muon_2pcont->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==2212){
	 selproton2_lenght_proton_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_proton_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_proton_2pcont->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_proton_2pcont->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_proton_2pcont->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }

       else if(pfp_pdg[p2ind] ==211){
	 selproton2_lenght_pion_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pion_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pion_2pcont->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pion_2pcont->Fill(track_pfp_chi2_proton[p2ind]);
	 for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	   selproton2_dEdx_vs_resrange_pion_2pcont->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
	 }
       }
       else if(pfp_pdg[p2ind] ==11){
	 selproton2_lenght_electron_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_electron_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_electron_2pcont->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_electron_2pcont->Fill(track_pfp_chi2_proton[p2ind]);
       }//electrons

       else{
	 selproton2_lenght_pother_2pcont->Fill(track_pfp_length[p2ind]);
	 selproton2_costheta_pother_2pcont->Fill(track_pfp_costheta[p2ind]);
	 selproton2_phi_pother_2pcont->Fill(track_pfp_phi[p2ind]);
	 selproton2_chi2proton_pother_2pcont->Fill(track_pfp_chi2_proton[p2ind]);
       }//other

     }/// mu, p1, p2, muon in FV
   }///2pcont requirement

   return kTRUE;
}

void hanalysis_fMC_2pcont::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_fMC_2pcont::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  cout<<"total number of event processed"<<totentries<<endl;
  cout << "Output file written" << endl;

  fanalysis_2pcont->cd();
  fanalysis_2pcont->Write();

  std::cout << "root Output file written" << std::endl;
  std::cout << "start writing histos" << std::endl;
  outfileMC_2pcont<<"total entries: "<<totentries<<std::endl;
  double topo1fr = topo1/totentries;
  outfileMC_2pcont<<"CC0Pion0Proton: "<<topo1<<" purity "<<topo1fr<<std::endl;
  outfileMC_2pcont<<"CC0Pion1Proton: "<<topo2<<" purity "<<(topo2/totentries)<<std::endl;
  outfileMC_2pcont<<"CC0Pion2Proton: "<<topo3<<" purity "<<double ((topo3/totentries))<<std::endl;
  outfileMC_2pcont<<"CC0PionNProton: "<<topo4<<" purity "<<(topo4/totentries)*100.<<std::endl;
  outfileMC_2pcont<<"CC1PionNProton: "<<topo5<<" purity "<<(topo5/totentries)*100.<<std::endl;
  outfileMC_2pcont<<"CCNPionNProton: "<<topo6<<" purity "<<(topo6/totentries)*100.<<std::endl;
  outfileMC_2pcont<<"CCnue: "<<topo7<<" purity "<<(topo7/totentries)*100.<<std::endl;
  outfileMC_2pcont<<"NC: "<<topo8<<" purity "<<(topo8/totentries)*100.<<std::endl;
  outfileMC_2pcont<<"OOFV: "<<topo9<<" purity "<<(topo9/totentries)*100.<<std::endl;
  outfileMC_2pcont<<"cosmic: "<<topo10<<" purity "<<(topo10/totentries)*100.<<std::endl;
  outfileMC_2pcont<<"other: "<<topo11<<" purity "<<(topo11/totentries)*100.<<std::endl;

}
