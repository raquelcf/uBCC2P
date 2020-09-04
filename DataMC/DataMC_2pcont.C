#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"
#include "THStack.h"
#include "TH1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TPad.h"
#include "TGaxis.h"
#include "TLegend.h"
#include "TLine.h"
#include "TROOT.h"
#include "TStyle.h"  

#include <TH2.h>
#include <TStyle.h>
#include <TH1D.h>

#include <cstring>
//using namespace std;

void DataMC_2pcont(){ 
  
  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_2pcont_BNBMC.root","READ");
  TFile* OnBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_2pcont_OnBeam.root","READ");
  TFile* OffBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_2pcont_OffBeam.root","READ");

  std::cout<<"antes de Tfile"<<std::endl;
  
  ////// BNB MC

  TH1D* selmuon_lenght_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_CC0Pion0Proton_2pcont");
  TH1D* selmuon_lenght_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_CC0Pion1Proton_2pcont");
  TH1D* selmuon_lenght_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_CC0Pion2Proton_2pcont");
  TH1D* selmuon_lenght_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_CC0PionNProton_2pcont");
  TH1D* selmuon_lenght_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_CC1PionNProton_2pcont");
  TH1D* selmuon_lenght_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_CCNPionNProton_2pcont");
  TH1D* selmuon_lenght_CCNue_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_CCNue_2pcont");
  TH1D* selmuon_lenght_NC_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_NC_2pcont");
  TH1D* selmuon_lenght_OOFV_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_OOFV_2pcont");
  TH1D* selmuon_lenght_EXT_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_EXT_2pcont");
  TH1D* selmuon_lenght_other_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_other_2pcont");

  TH1D* selmuon_mom_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_CC0Pion0Proton_2pcont");
  TH1D* selmuon_mom_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_CC0Pion1Proton_2pcont");
  TH1D* selmuon_mom_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_CC0Pion2Proton_2pcont");
  TH1D* selmuon_mom_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_CC0PionNProton_2pcont");
  TH1D* selmuon_mom_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_CC1PionNProton_2pcont");
  TH1D* selmuon_mom_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_CCNPionNProton_2pcont");
  TH1D* selmuon_mom_CCNue_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_CCNue_2pcont");
  TH1D* selmuon_mom_NC_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_NC_2pcont");
  TH1D* selmuon_mom_OOFV_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_OOFV_2pcont");
  TH1D* selmuon_mom_EXT_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_EXT_2pcont");
  TH1D* selmuon_mom_other_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_other_2pcont");

  TH1D* selmuon_costheta_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_CC0Pion0Proton_2pcont");
  TH1D* selmuon_costheta_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_CC0Pion1Proton_2pcont");
  TH1D* selmuon_costheta_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_CC0Pion2Proton_2pcont");
  TH1D* selmuon_costheta_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_CC0PionNProton_2pcont");
  TH1D* selmuon_costheta_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_CC1PionNProton_2pcont");
  TH1D* selmuon_costheta_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_CCNPionNProton_2pcont");
  TH1D* selmuon_costheta_CCNue_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_CCNue_2pcont");
  TH1D* selmuon_costheta_NC_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_NC_2pcont");
  TH1D* selmuon_costheta_OOFV_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_OOFV_2pcont");
  TH1D* selmuon_costheta_EXT_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_EXT_2pcont");
  TH1D* selmuon_costheta_other_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_other_2pcont");

  TH1D* selmuon_phi_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_CC0Pion0Proton_2pcont");
  TH1D* selmuon_phi_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_CC0Pion1Proton_2pcont");
  TH1D* selmuon_phi_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_CC0Pion2Proton_2pcont");
  TH1D* selmuon_phi_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_CC0PionNProton_2pcont");
  TH1D* selmuon_phi_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_CC1PionNProton_2pcont");
  TH1D* selmuon_phi_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_CCNPionNProton_2pcont");
  TH1D* selmuon_phi_CCNue_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_CCNue_2pcont");
  TH1D* selmuon_phi_NC_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_NC_2pcont");
  TH1D* selmuon_phi_OOFV_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_OOFV_2pcont");
  TH1D* selmuon_phi_EXT_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_EXT_2pcont");
  TH1D* selmuon_phi_other_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_other_2pcont");

  TH1D* selmuon_lenght_muon_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_muon_2pcont");
  TH1D* selmuon_lenght_proton_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_proton_2pcont");
  TH1D* selmuon_lenght_pion_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_pion_2pcont");
  TH1D* selmuon_lenght_electron_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_electron_2pcont");
  TH1D* selmuon_lenght_pother_2pcont = (TH1D*) BNBMC->Get("selmuon_lenght_pother_2pcont");

  TH1D* selmuon_mom_muon_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_muon_2pcont");
  TH1D* selmuon_mom_proton_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_proton_2pcont");
  TH1D* selmuon_mom_pion_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_pion_2pcont");
  TH1D* selmuon_mom_electron_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_electron_2pcont");
  TH1D* selmuon_mom_pother_2pcont = (TH1D*) BNBMC->Get("selmuon_mom_pother_2pcont");

  TH1D* selmuon_costheta_muon_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_muon_2pcont");
  TH1D* selmuon_costheta_proton_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_proton_2pcont");
  TH1D* selmuon_costheta_pion_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_pion_2pcont");
  TH1D* selmuon_costheta_electron_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_electron_2pcont");
  TH1D* selmuon_costheta_pother_2pcont = (TH1D*) BNBMC->Get("selmuon_costheta_pother_2pcont");

  TH1D* selmuon_phi_muon_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_muon_2pcont");
  TH1D* selmuon_phi_proton_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_proton_2pcont");
  TH1D* selmuon_phi_pion_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_pion_2pcont");
  TH1D* selmuon_phi_electron_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_electron_2pcont");
  TH1D* selmuon_phi_pother_2pcont = (TH1D*) BNBMC->Get("selmuon_phi_pother_2pcont");

  TH1D* selmuon_chi2proton_muon_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_muon_2pcont");
  TH1D* selmuon_chi2proton_proton_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_proton_2pcont");
  TH1D* selmuon_chi2proton_pion_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_pion_2pcont");
  TH1D* selmuon_chi2proton_electron_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_electron_2pcont");
  TH1D* selmuon_chi2proton_pother_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_pother_2pcont");

  TH1D* selmuon_chi2proton_cont_muon_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_muon_2pcont");
  TH1D* selmuon_chi2proton_cont_proton_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_proton_2pcont");
  TH1D* selmuon_chi2proton_cont_pion_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_pion_2pcont");
  TH1D* selmuon_chi2proton_cont_electron_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_electron_2pcont");
  TH1D* selmuon_chi2proton_cont_pother_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_pother_2pcont");

  TH1D* selmuon_chi2proton_uncont_muon_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_muon_2pcont");
  TH1D* selmuon_chi2proton_uncont_proton_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_proton_2pcont");
  TH1D* selmuon_chi2proton_uncont_pion_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_pion_2pcont");
  TH1D* selmuon_chi2proton_uncont_electron_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_electron_2pcont");
  TH1D* selmuon_chi2proton_uncont_pother_2pcont = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_pother_2pcont");

  TH2D* selmuon_dEdx_vs_resrange_muon_2pcont = (TH2D*) BNBMC->Get("selmuon_dEdx_vs_resrange_muon_2pcont");
  TH2D* selmuon_dEdx_vs_resrange_proton_2pcont = (TH2D*) BNBMC->Get("selmuon_dEdx_vs_resrange_proton_2pcont");
  TH2D* selmuon_dEdx_vs_resrange_pion_2pcont = (TH2D*) BNBMC->Get("selmuon_dEdx_vs_resrange_pion_2pcont");

  /// proton 1

  TH1D* selproton1_lenght_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_CC0Pion0Proton_2pcont");
  TH1D* selproton1_lenght_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_CC0Pion1Proton_2pcont");
  TH1D* selproton1_lenght_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_CC0Pion2Proton_2pcont");
  TH1D* selproton1_lenght_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_CC0PionNProton_2pcont");
  TH1D* selproton1_lenght_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_CC1PionNProton_2pcont");
  TH1D* selproton1_lenght_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_CCNPionNProton_2pcont");
  TH1D* selproton1_lenght_CCNue_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_CCNue_2pcont");
  TH1D* selproton1_lenght_NC_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_NC_2pcont");
  TH1D* selproton1_lenght_OOFV_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_OOFV_2pcont");
  TH1D* selproton1_lenght_EXT_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_EXT_2pcont");
  TH1D* selproton1_lenght_other_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_other_2pcont");

  TH1D* selproton1_costheta_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_CC0Pion0Proton_2pcont");
  TH1D* selproton1_costheta_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_CC0Pion1Proton_2pcont");
  TH1D* selproton1_costheta_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_CC0Pion2Proton_2pcont");
  TH1D* selproton1_costheta_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_CC0PionNProton_2pcont");
  TH1D* selproton1_costheta_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_CC1PionNProton_2pcont");
  TH1D* selproton1_costheta_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_CCNPionNProton_2pcont");
  TH1D* selproton1_costheta_CCNue_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_CCNue_2pcont");
  TH1D* selproton1_costheta_NC_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_NC_2pcont");
  TH1D* selproton1_costheta_OOFV_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_OOFV_2pcont");
  TH1D* selproton1_costheta_EXT_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_EXT_2pcont");
  TH1D* selproton1_costheta_other_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_other_2pcont");

  TH1D* selproton1_phi_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_CC0Pion0Proton_2pcont");
  TH1D* selproton1_phi_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_CC0Pion1Proton_2pcont");
  TH1D* selproton1_phi_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_CC0Pion2Proton_2pcont");
  TH1D* selproton1_phi_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_CC0PionNProton_2pcont");
  TH1D* selproton1_phi_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_CC1PionNProton_2pcont");
  TH1D* selproton1_phi_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_CCNPionNProton_2pcont");
  TH1D* selproton1_phi_CCNue_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_CCNue_2pcont");
  TH1D* selproton1_phi_NC_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_NC_2pcont");
  TH1D* selproton1_phi_OOFV_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_OOFV_2pcont");
  TH1D* selproton1_phi_EXT_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_EXT_2pcont");
  TH1D* selproton1_phi_other_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_other_2pcont");

  TH1D* selproton1_lenght_muon_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_muon_2pcont");
  TH1D* selproton1_lenght_proton_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_proton_2pcont");
  TH1D* selproton1_lenght_pion_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_pion_2pcont");
  TH1D* selproton1_lenght_electron_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_electron_2pcont");
  TH1D* selproton1_lenght_pother_2pcont = (TH1D*) BNBMC->Get("selproton1_lenght_pother_2pcont");

  TH1D* selproton1_costheta_muon_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_muon_2pcont");
  TH1D* selproton1_costheta_proton_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_proton_2pcont");
  TH1D* selproton1_costheta_pion_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_pion_2pcont");
  TH1D* selproton1_costheta_electron_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_electron_2pcont");
  TH1D* selproton1_costheta_pother_2pcont = (TH1D*) BNBMC->Get("selproton1_costheta_pother_2pcont");

  TH1D* selproton1_phi_muon_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_muon_2pcont");
  TH1D* selproton1_phi_proton_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_proton_2pcont");
  TH1D* selproton1_phi_pion_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_pion_2pcont");
  TH1D* selproton1_phi_electron_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_electron_2pcont");
  TH1D* selproton1_phi_pother_2pcont = (TH1D*) BNBMC->Get("selproton1_phi_pother_2pcont");

  TH1D* selproton1_chi2proton_muon_2pcont = (TH1D*) BNBMC->Get("selproton1_chi2proton_muon_2pcont");
  TH1D* selproton1_chi2proton_proton_2pcont = (TH1D*) BNBMC->Get("selproton1_chi2proton_proton_2pcont");
  TH1D* selproton1_chi2proton_pion_2pcont = (TH1D*) BNBMC->Get("selproton1_chi2proton_pion_2pcont");
  TH1D* selproton1_chi2proton_electron_2pcont = (TH1D*) BNBMC->Get("selproton1_chi2proton_electron_2pcont");
  TH1D* selproton1_chi2proton_pother_2pcont = (TH1D*) BNBMC->Get("selproton1_chi2proton_pother_2pcont");

  TH2D* selproton1_dEdx_vs_resrange_muon_2pcont = (TH2D*) BNBMC->Get("selproton1_dEdx_vs_resrange_muon_2pcont");
  TH2D* selproton1_dEdx_vs_resrange_proton_2pcont = (TH2D*) BNBMC->Get("selproton1_dEdx_vs_resrange_proton_2pcont");
  TH2D* selproton1_dEdx_vs_resrange_pion_2pcont = (TH2D*) BNBMC->Get("selproton1_dEdx_vs_resrange_pion_2pcont");

  /// proton 2
  TH1D* selproton2_lenght_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_CC0Pion0Proton_2pcont");
  TH1D* selproton2_lenght_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_CC0Pion1Proton_2pcont");
  TH1D* selproton2_lenght_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_CC0Pion2Proton_2pcont");
  TH1D* selproton2_lenght_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_CC0PionNProton_2pcont");
  TH1D* selproton2_lenght_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_CC1PionNProton_2pcont");
  TH1D* selproton2_lenght_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_CCNPionNProton_2pcont");
  TH1D* selproton2_lenght_CCNue_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_CCNue_2pcont");
  TH1D* selproton2_lenght_NC_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_NC_2pcont");
  TH1D* selproton2_lenght_OOFV_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_OOFV_2pcont");
  TH1D* selproton2_lenght_EXT_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_EXT_2pcont");
  TH1D* selproton2_lenght_other_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_other_2pcont");

  TH1D* selproton2_costheta_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_CC0Pion0Proton_2pcont");
  TH1D* selproton2_costheta_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_CC0Pion1Proton_2pcont");
  TH1D* selproton2_costheta_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_CC0Pion2Proton_2pcont");
  TH1D* selproton2_costheta_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_CC0PionNProton_2pcont");
  TH1D* selproton2_costheta_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_CC1PionNProton_2pcont");
  TH1D* selproton2_costheta_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_CCNPionNProton_2pcont");
  TH1D* selproton2_costheta_CCNue_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_CCNue_2pcont");
  TH1D* selproton2_costheta_NC_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_NC_2pcont");
  TH1D* selproton2_costheta_OOFV_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_OOFV_2pcont");
  TH1D* selproton2_costheta_EXT_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_EXT_2pcont");
  TH1D* selproton2_costheta_other_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_other_2pcont");

  TH1D* selproton2_phi_CC0Pion0Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_CC0Pion0Proton_2pcont");
  TH1D* selproton2_phi_CC0Pion1Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_CC0Pion1Proton_2pcont");
  TH1D* selproton2_phi_CC0Pion2Proton_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_CC0Pion2Proton_2pcont");
  TH1D* selproton2_phi_CC0PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_CC0PionNProton_2pcont");
  TH1D* selproton2_phi_CC1PionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_CC1PionNProton_2pcont");
  TH1D* selproton2_phi_CCNPionNProton_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_CCNPionNProton_2pcont");
  TH1D* selproton2_phi_CCNue_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_CCNue_2pcont");
  TH1D* selproton2_phi_NC_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_NC_2pcont");
  TH1D* selproton2_phi_OOFV_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_OOFV_2pcont");
  TH1D* selproton2_phi_EXT_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_EXT_2pcont");
  TH1D* selproton2_phi_other_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_other_2pcont");

  TH1D* selproton2_lenght_muon_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_muon_2pcont");
  TH1D* selproton2_lenght_proton_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_proton_2pcont");
  TH1D* selproton2_lenght_pion_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_pion_2pcont");
  TH1D* selproton2_lenght_electron_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_electron_2pcont");
  TH1D* selproton2_lenght_pother_2pcont = (TH1D*) BNBMC->Get("selproton2_lenght_pother_2pcont");

  TH1D* selproton2_costheta_muon_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_muon_2pcont");
  TH1D* selproton2_costheta_proton_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_proton_2pcont");
  TH1D* selproton2_costheta_pion_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_pion_2pcont");
  TH1D* selproton2_costheta_electron_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_electron_2pcont");
  TH1D* selproton2_costheta_pother_2pcont = (TH1D*) BNBMC->Get("selproton2_costheta_pother_2pcont");

  TH1D* selproton2_phi_muon_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_muon_2pcont");
  TH1D* selproton2_phi_proton_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_proton_2pcont");
  TH1D* selproton2_phi_pion_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_pion_2pcont");
  TH1D* selproton2_phi_electron_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_electron_2pcont");
  TH1D* selproton2_phi_pother_2pcont = (TH1D*) BNBMC->Get("selproton2_phi_pother_2pcont");

  TH1D* selproton2_chi2proton_muon_2pcont = (TH1D*) BNBMC->Get("selproton2_chi2proton_muon_2pcont");
  TH1D* selproton2_chi2proton_proton_2pcont = (TH1D*) BNBMC->Get("selproton2_chi2proton_proton_2pcont");
  TH1D* selproton2_chi2proton_pion_2pcont = (TH1D*) BNBMC->Get("selproton2_chi2proton_pion_2pcont");
  TH1D* selproton2_chi2proton_electron_2pcont = (TH1D*) BNBMC->Get("selproton2_chi2proton_electron_2pcont");
  TH1D* selproton2_chi2proton_pother_2pcont = (TH1D*) BNBMC->Get("selproton2_chi2proton_pother_2pcont");

  TH2D* selproton2_dEdx_vs_resrange_muon_2pcont = (TH2D*) BNBMC->Get("selproton2_dEdx_vs_resrange_muon_2pcont");
  TH2D* selproton2_dEdx_vs_resrange_proton_2pcont = (TH2D*) BNBMC->Get("selproton2_dEdx_vs_resrange_proton_2pcont");
  TH2D* selproton2_dEdx_vs_resrange_pion_2pcont = (TH2D*) BNBMC->Get("selproton2_dEdx_vs_resrange_pion_2pcont");


  //// On-Beam data

  /// muon candidate properties
  TH1D* selmuon_lenght_OnBeam_2pcont = (TH1D*) OnBeam->Get("selmuon_lenght_OnBeam_2pcont");
  TH1D* selmuon_mom_OnBeam_2pcont = (TH1D*) OnBeam->Get("selmuon_mom_OnBeam_2pcont");
  TH1D* selmuon_costheta_OnBeam_2pcont = (TH1D*) OnBeam->Get("selmuon_costheta_OnBeam_2pcont");
  TH1D* selmuon_phi_OnBeam_2pcont = (TH1D*) OnBeam->Get("selmuon_phi_OnBeam_2pcont");

  TH1D* selmuon_chi2proton_OnBeam_2pcont = (TH1D*) OnBeam->Get("selmuon_chi2proton_OnBeam_2pcont");

  TH1D* selmuon_chi2proton_cont_OnBeam_2pcont = (TH1D*) OnBeam->Get("selmuon_chi2proton_cont_OnBeam_2pcont");
  TH1D* selmuon_chi2proton_uncont_OnBeam_2pcont = (TH1D*) OnBeam->Get("selmuon_chi2proton_uncont_OnBeam_2pcont");

  TH2D* selmuon_dEdx_vs_resrange_OnBeam_2pcont = (TH2D*) OnBeam->Get("selmuon_dEdx_vs_resrange_OnBeam_2pcont");

  ////proton 1

  TH1D* selproton1_lenght_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton1_lenght_OnBeam_2pcont");
  TH1D* selproton1_costheta_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton1_costheta_OnBeam_2pcont");
  TH1D* selproton1_phi_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton1_phi_OnBeam_2pcont");

  TH1D* selproton1_chi2proton_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton1_chi2proton_OnBeam_2pcont");

  TH2D* selproton1_dEdx_vs_resrange_OnBeam_2pcont = (TH2D*) OnBeam->Get("selproton1_dEdx_vs_resrange_OnBeam_2pcont");

  //////////////// proton 2
  TH1D* selproton2_lenght_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton2_lenght_OnBeam_2pcont");
  TH1D* selproton2_costheta_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton2_costheta_OnBeam_2pcont");
  TH1D* selproton2_phi_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton2_phi_OnBeam_2pcont");

  TH1D* selproton2_chi2proton_OnBeam_2pcont = (TH1D*) OnBeam->Get("selproton2_chi2proton_OnBeam_2pcont");

  TH2D* selproton2_dEdx_vs_resrange_OnBeam_2pcont = (TH2D*) OnBeam->Get("selproton2_dEdx_vs_resrange_OnBeam_2pcont");

  //// Off-Beam data

  /// muon candidate properties
  TH1D* selmuon_lenght_OffBeam_2pcont = (TH1D*) OffBeam->Get("selmuon_lenght_OffBeam_2pcont");
  TH1D* selmuon_mom_OffBeam_2pcont = (TH1D*) OffBeam->Get("selmuon_mom_OffBeam_2pcont");
  TH1D* selmuon_costheta_OffBeam_2pcont = (TH1D*) OffBeam->Get("selmuon_costheta_OffBeam_2pcont");
  TH1D* selmuon_phi_OffBeam_2pcont = (TH1D*) OffBeam->Get("selmuon_phi_OffBeam_2pcont");

  TH1D* selmuon_chi2proton_OffBeam_2pcont = (TH1D*) OffBeam->Get("selmuon_chi2proton_OffBeam_2pcont");
  TH1D* selmuon_chi2proton_cont_OffBeam_2pcont = (TH1D*) OffBeam->Get("selmuon_chi2proton_cont_OffBeam_2pcont");
  TH1D* selmuon_chi2proton_uncont_OffBeam_2pcont = (TH1D*) OffBeam->Get("selmuon_chi2proton_uncont_OffBeam_2pcont");

  TH2D* selmuon_dEdx_vs_resrange_OffBeam_2pcont = (TH2D*) OffBeam->Get("selmuon_dEdx_vs_resrange_OffBeam_2pcont");

  ////proton 1

  TH1D* selproton1_lenght_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton1_lenght_OffBeam_2pcont");
  TH1D* selproton1_costheta_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton1_costheta_OffBeam_2pcont");
  TH1D* selproton1_phi_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton1_phi_OffBeam_2pcont");

  TH1D* selproton1_chi2proton_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton1_chi2proton_OffBeam_2pcont");

  TH2D* selproton1_dEdx_vs_resrange_OffBeam_2pcont = (TH2D*) OffBeam->Get("selproton1_dEdx_vs_resrange_OffBeam_2pcont");

  //////////////// proton 2
  TH1D* selproton2_lenght_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton2_lenght_OffBeam_2pcont");
  TH1D* selproton2_costheta_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton2_costheta_OffBeam_2pcont");
  TH1D* selproton2_phi_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton2_phi_OffBeam_2pcont");

  TH1D* selproton2_chi2proton_OffBeam_2pcont = (TH1D*) OffBeam->Get("selproton2_chi2proton_OffBeam_2pcont");

  TH2D* selproton2_dEdx_vs_resrange_OffBeam_2pcont = (TH2D*) OffBeam->Get("selproton2_dEdx_vs_resrange_OffBeam_2pcont");

 
  /// valores de las normalizaciones
  // Double_t normOffBeam = (36177265) / (33320382);// 10848971./36811051.; //11278529./ 41189266.; 
  Double_t normMCBNB =  (4.411e+19)/(2.010e+20);//(4.874e+19)/(1.566e+20);
  Double_t normOffBeam = 9775610./73710197.;  //0.1464;//(33320382.)/(36177265.);
  //Double_t normMCBNB =  0.2568; //(2.002e+20)/(4.896e+19);//(4.874e+19)/(1.566e+20);
  //Double_t normOffBeam = 1.085739803343191;//(33320382.)/(36177265.);

  //h->Scale(1/norm);

  /// normalizing MC
  std::cout<<"antes del scale"<<std::endl;
  std::cout<<"normMCBNB : "<<normMCBNB<<std::endl;
  std::cout<<"normOffBeam : "<<normOffBeam<<std::endl;
  
  selmuon_lenght_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  std::cout<<"hola 1"<<std::endl;
  selmuon_lenght_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selmuon_lenght_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selmuon_lenght_CC0PionNProton_2pcont->Scale(normMCBNB);
  selmuon_lenght_CC1PionNProton_2pcont->Scale(normMCBNB);
  selmuon_lenght_CCNPionNProton_2pcont->Scale(normMCBNB);
  selmuon_lenght_CCNue_2pcont->Scale(normMCBNB);;
  selmuon_lenght_NC_2pcont->Scale(normMCBNB);
  selmuon_lenght_OOFV_2pcont->Scale(normMCBNB);
  selmuon_lenght_EXT_2pcont->Scale(normMCBNB);
  selmuon_lenght_other_2pcont->Scale(normMCBNB);
 
  selmuon_mom_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selmuon_mom_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selmuon_mom_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selmuon_mom_CC0PionNProton_2pcont->Scale(normMCBNB);
  selmuon_mom_CC1PionNProton_2pcont->Scale(normMCBNB);
  selmuon_mom_CCNPionNProton_2pcont->Scale(normMCBNB);
  selmuon_mom_CCNue_2pcont->Scale(normMCBNB);
  selmuon_mom_NC_2pcont->Scale(normMCBNB);
  selmuon_mom_OOFV_2pcont->Scale(normMCBNB);
  selmuon_mom_EXT_2pcont->Scale(normMCBNB);
  selmuon_mom_other_2pcont->Scale(normMCBNB);
  
  selmuon_costheta_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selmuon_costheta_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selmuon_costheta_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selmuon_costheta_CC0PionNProton_2pcont->Scale(normMCBNB);
  selmuon_costheta_CC1PionNProton_2pcont->Scale(normMCBNB);
  selmuon_costheta_CCNPionNProton_2pcont->Scale(normMCBNB);
  selmuon_costheta_CCNue_2pcont->Scale(normMCBNB);
  selmuon_costheta_NC_2pcont->Scale(normMCBNB);
  selmuon_costheta_OOFV_2pcont->Scale(normMCBNB);
  selmuon_costheta_EXT_2pcont->Scale(normMCBNB);
  selmuon_costheta_other_2pcont->Scale(normMCBNB);
  
  selmuon_phi_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selmuon_phi_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selmuon_phi_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selmuon_phi_CC0PionNProton_2pcont->Scale(normMCBNB);
  selmuon_phi_CC1PionNProton_2pcont->Scale(normMCBNB);
  selmuon_phi_CCNPionNProton_2pcont->Scale(normMCBNB);
  selmuon_phi_CCNue_2pcont->Scale(normMCBNB);
  selmuon_phi_NC_2pcont->Scale(normMCBNB);
  selmuon_phi_OOFV_2pcont->Scale(normMCBNB);
  selmuon_phi_EXT_2pcont->Scale(normMCBNB);
  selmuon_phi_other_2pcont->Scale(normMCBNB);
  
  selmuon_lenght_muon_2pcont->Scale(normMCBNB);
  selmuon_lenght_proton_2pcont->Scale(normMCBNB);
  selmuon_lenght_pion_2pcont->Scale(normMCBNB);
  selmuon_lenght_electron_2pcont->Scale(normMCBNB);
  selmuon_lenght_pother_2pcont->Scale(normMCBNB);
  
  selmuon_mom_muon_2pcont->Scale(normMCBNB);
  selmuon_mom_proton_2pcont->Scale(normMCBNB);
  selmuon_mom_pion_2pcont->Scale(normMCBNB);
  selmuon_mom_electron_2pcont->Scale(normMCBNB);
  selmuon_mom_pother_2pcont->Scale(normMCBNB);
  
  selmuon_costheta_muon_2pcont->Scale(normMCBNB);
  selmuon_costheta_proton_2pcont->Scale(normMCBNB);
  selmuon_costheta_pion_2pcont->Scale(normMCBNB);
  selmuon_costheta_electron_2pcont->Scale(normMCBNB);
  selmuon_costheta_pother_2pcont->Scale(normMCBNB);
  
  selmuon_phi_muon_2pcont->Scale(normMCBNB);
  selmuon_phi_proton_2pcont->Scale(normMCBNB);
  selmuon_phi_pion_2pcont->Scale(normMCBNB);
  selmuon_phi_electron_2pcont->Scale(normMCBNB);
  selmuon_phi_pother_2pcont->Scale(normMCBNB);
      
  ///
  selmuon_chi2proton_muon_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_proton_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_pion_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_electron_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_pother_2pcont->Scale(normMCBNB);
  
  selmuon_chi2proton_cont_muon_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_cont_proton_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_cont_pion_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_cont_electron_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_cont_pother_2pcont->Scale(normMCBNB);
  
  selmuon_chi2proton_uncont_muon_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_uncont_proton_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_uncont_pion_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_uncont_electron_2pcont->Scale(normMCBNB);
  selmuon_chi2proton_uncont_pother_2pcont->Scale(normMCBNB);
    
  /// proton 1

  selproton1_lenght_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selproton1_lenght_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selproton1_lenght_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selproton1_lenght_CC0PionNProton_2pcont->Scale(normMCBNB);
  selproton1_lenght_CC1PionNProton_2pcont->Scale(normMCBNB);
  selproton1_lenght_CCNPionNProton_2pcont->Scale(normMCBNB);
  selproton1_lenght_CCNue_2pcont->Scale(normMCBNB);
  selproton1_lenght_NC_2pcont->Scale(normMCBNB);
  selproton1_lenght_OOFV_2pcont->Scale(normMCBNB);
  selproton1_lenght_EXT_2pcont->Scale(normMCBNB);
  selproton1_lenght_other_2pcont->Scale(normMCBNB);
  
  selproton1_costheta_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selproton1_costheta_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selproton1_costheta_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selproton1_costheta_CC0PionNProton_2pcont->Scale(normMCBNB);
  selproton1_costheta_CC1PionNProton_2pcont->Scale(normMCBNB);
  selproton1_costheta_CCNPionNProton_2pcont->Scale(normMCBNB);
  selproton1_costheta_CCNue_2pcont->Scale(normMCBNB);
  selproton1_costheta_NC_2pcont->Scale(normMCBNB);
  selproton1_costheta_OOFV_2pcont->Scale(normMCBNB);
  selproton1_costheta_EXT_2pcont->Scale(normMCBNB);
  selproton1_costheta_other_2pcont->Scale(normMCBNB);
  
  selproton1_phi_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selproton1_phi_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selproton1_phi_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selproton1_phi_CC0PionNProton_2pcont->Scale(normMCBNB);
  selproton1_phi_CC1PionNProton_2pcont->Scale(normMCBNB);
  selproton1_phi_CCNPionNProton_2pcont->Scale(normMCBNB);
  selproton1_phi_CCNue_2pcont->Scale(normMCBNB);
  selproton1_phi_NC_2pcont->Scale(normMCBNB);
  selproton1_phi_OOFV_2pcont->Scale(normMCBNB);
  selproton1_phi_EXT_2pcont->Scale(normMCBNB);
  selproton1_phi_other_2pcont->Scale(normMCBNB);
  
  selproton1_lenght_muon_2pcont->Scale(normMCBNB);
  selproton1_lenght_proton_2pcont->Scale(normMCBNB);
  selproton1_lenght_pion_2pcont->Scale(normMCBNB);
  selproton1_lenght_electron_2pcont->Scale(normMCBNB);
  selproton1_lenght_pother_2pcont->Scale(normMCBNB);
  
  selproton1_costheta_muon_2pcont->Scale(normMCBNB);
  selproton1_costheta_proton_2pcont->Scale(normMCBNB);
  selproton1_costheta_pion_2pcont->Scale(normMCBNB);
  selproton1_costheta_electron_2pcont->Scale(normMCBNB);
  selproton1_costheta_pother_2pcont->Scale(normMCBNB);
  
  selproton1_phi_muon_2pcont->Scale(normMCBNB);
  selproton1_phi_proton_2pcont->Scale(normMCBNB);
  selproton1_phi_pion_2pcont->Scale(normMCBNB);
  selproton1_phi_electron_2pcont->Scale(normMCBNB);
  selproton1_phi_pother_2pcont->Scale(normMCBNB);
    
  selproton1_chi2proton_muon_2pcont->Scale(normMCBNB);
  selproton1_chi2proton_proton_2pcont->Scale(normMCBNB);
  selproton1_chi2proton_pion_2pcont->Scale(normMCBNB);
  selproton1_chi2proton_electron_2pcont->Scale(normMCBNB);
  selproton1_chi2proton_pother_2pcont->Scale(normMCBNB);

  /// proton 2
  selproton2_lenght_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selproton2_lenght_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selproton2_lenght_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selproton2_lenght_CC0PionNProton_2pcont->Scale(normMCBNB);
  selproton2_lenght_CC1PionNProton_2pcont->Scale(normMCBNB);
  selproton2_lenght_CCNPionNProton_2pcont->Scale(normMCBNB);
  selproton2_lenght_CCNue_2pcont->Scale(normMCBNB);
  selproton2_lenght_NC_2pcont->Scale(normMCBNB);
  selproton2_lenght_OOFV_2pcont->Scale(normMCBNB);
  selproton2_lenght_EXT_2pcont->Scale(normMCBNB);
  selproton2_lenght_other_2pcont->Scale(normMCBNB);

  selproton2_costheta_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selproton2_costheta_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selproton2_costheta_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selproton2_costheta_CC0PionNProton_2pcont->Scale(normMCBNB);
  selproton2_costheta_CC1PionNProton_2pcont->Scale(normMCBNB);
  selproton2_costheta_CCNPionNProton_2pcont->Scale(normMCBNB);
  selproton2_costheta_CCNue_2pcont->Scale(normMCBNB);
  selproton2_costheta_NC_2pcont->Scale(normMCBNB);
  selproton2_costheta_OOFV_2pcont->Scale(normMCBNB);
  selproton2_costheta_EXT_2pcont->Scale(normMCBNB);
  selproton2_costheta_other_2pcont->Scale(normMCBNB);

  selproton2_phi_CC0Pion0Proton_2pcont->Scale(normMCBNB);
  selproton2_phi_CC0Pion1Proton_2pcont->Scale(normMCBNB);
  selproton2_phi_CC0Pion2Proton_2pcont->Scale(normMCBNB);
  selproton2_phi_CC0PionNProton_2pcont->Scale(normMCBNB);
  selproton2_phi_CC1PionNProton_2pcont->Scale(normMCBNB);
  selproton2_phi_CCNPionNProton_2pcont->Scale(normMCBNB);
  selproton2_phi_CCNue_2pcont->Scale(normMCBNB);
  selproton2_phi_NC_2pcont->Scale(normMCBNB);
  selproton2_phi_OOFV_2pcont->Scale(normMCBNB);
  selproton2_phi_EXT_2pcont->Scale(normMCBNB);
  selproton2_phi_other_2pcont->Scale(normMCBNB);

  selproton2_lenght_muon_2pcont->Scale(normMCBNB);
  selproton2_lenght_proton_2pcont->Scale(normMCBNB);
  selproton2_lenght_pion_2pcont->Scale(normMCBNB);
  selproton2_lenght_electron_2pcont->Scale(normMCBNB);
  selproton2_lenght_pother_2pcont->Scale(normMCBNB);

  selproton2_costheta_muon_2pcont->Scale(normMCBNB);
  selproton2_costheta_proton_2pcont->Scale(normMCBNB);
  selproton2_costheta_pion_2pcont->Scale(normMCBNB);
  selproton2_costheta_electron_2pcont->Scale(normMCBNB);
  selproton2_costheta_pother_2pcont->Scale(normMCBNB);

  selproton2_phi_muon_2pcont->Scale(normMCBNB);
  selproton2_phi_proton_2pcont->Scale(normMCBNB);
  selproton2_phi_pion_2pcont->Scale(normMCBNB);
  selproton2_phi_electron_2pcont->Scale(normMCBNB);
  selproton2_phi_pother_2pcont->Scale(normMCBNB);

  selproton2_chi2proton_muon_2pcont->Scale(normMCBNB);
  selproton2_chi2proton_proton_2pcont->Scale(normMCBNB);
  selproton2_chi2proton_pion_2pcont->Scale(normMCBNB);
  selproton2_chi2proton_electron_2pcont->Scale(normMCBNB);
  selproton2_chi2proton_pother_2pcont->Scale(normMCBNB);

  /// Off beam data normalization
 
  /// muon candidate properties
  selmuon_lenght_OffBeam_2pcont->Scale(normOffBeam);
  selmuon_mom_OffBeam_2pcont->Scale(normOffBeam);
  selmuon_costheta_OffBeam_2pcont->Scale(normOffBeam);
  selmuon_phi_OffBeam_2pcont->Scale(normOffBeam);
  
  selmuon_chi2proton_OffBeam_2pcont->Scale(normOffBeam);
  selmuon_chi2proton_cont_OffBeam_2pcont->Scale(normOffBeam);
  selmuon_chi2proton_uncont_OffBeam_2pcont->Scale(normOffBeam);

  selmuon_dEdx_vs_resrange_OffBeam_2pcont->Scale(normOffBeam);

  ////proton 1

  selproton1_lenght_OffBeam_2pcont->Scale(normOffBeam);
  selproton1_costheta_OffBeam_2pcont->Scale(normOffBeam);
  selproton1_phi_OffBeam_2pcont->Scale(normOffBeam);

  selproton1_chi2proton_OffBeam_2pcont->Scale(normOffBeam);
  selproton1_dEdx_vs_resrange_OffBeam_2pcont->Scale(normOffBeam);

  //////////////// proton 2
  selproton2_lenght_OffBeam_2pcont->Scale(normOffBeam);
  selproton2_costheta_OffBeam_2pcont->Scale(normOffBeam);
  selproton2_phi_OffBeam_2pcont->Scale(normOffBeam);

  selproton2_chi2proton_OffBeam_2pcont->Scale(normOffBeam);

  selproton2_dEdx_vs_resrange_OffBeam_2pcont->Scale(normOffBeam);  

  //  gStyle->SetOptFit(0);
  //gStyle->SetOptStat(00000);
 
  std::cout<<"antes de los plots"<<std::endl;  

  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);

  selmuon_lenght_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selmuon_lenght_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selmuon_lenght_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_lenght_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selmuon_lenght_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selmuon_lenght_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selmuon_lenght_CCNue_2pcont-> SetFillColor(31);
  selmuon_lenght_NC_2pcont-> SetFillColor(kOrange+6);
  selmuon_lenght_OOFV_2pcont-> SetFillColor(kYellow+2);
  selmuon_lenght_EXT_2pcont-> SetFillColor(kBlack);
  selmuon_lenght_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selmuon_lenght_2pcont = new THStack("selmuon_lenght_2pcont","length [cm]");
  selmuon_lenght_2pcont-> Add(selmuon_lenght_CC0Pion0Proton_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_CC0Pion1Proton_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_CC0Pion2Proton_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_CC0PionNProton_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_CC1PionNProton_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_CCNPionNProton_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_CCNue_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_NC_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_OOFV_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_EXT_2pcont);
  //selmuon_lenght_2pcont-> Add(selmuon_lenght_other_2pcont);
  selmuon_lenght_2pcont-> Add(selmuon_lenght_OffBeam_2pcont);
  //selmuon_lenght_2pcont->SetMaximum(600.);
  selmuon_lenght_2pcont-> Draw();
  selmuon_lenght_2pcont->GetXaxis()->SetTitle("muon candidate, length [cm]");

  selmuon_lenght_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_lenght_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_lenght_OnBeam_2pcont->Draw("e1same");

  TLegend *l1 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l1 -> SetNColumns(2);
  l1 -> AddEntry(selmuon_lenght_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CCNue_2pcont, "CC#nu_{e}", "f");
  l1 -> AddEntry(selmuon_lenght_NC_2pcont, "NC", "f");
  l1 -> AddEntry(selmuon_lenght_OOFV_2pcont, "OOFV", "f");
  l1 -> AddEntry(selmuon_lenght_EXT_2pcont, "cosmic", "f");
  //l1 -> AddEntry(selmuon_lenght_other_2pcont, "other", "f");
  l1 -> AddEntry(selmuon_lenght_OffBeam_2pcont, "off-beam data", "f");
  l1 -> AddEntry(selmuon_lenght_OnBeam_2pcont, "on-beam data", "lep");
  l1 -> Draw();  
  
  c1->Update();
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_lenght_topo_2pcont.pdf");

  TCanvas *c2 = new TCanvas("c2", "c2", 900, 900);

  selmuon_mom_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selmuon_mom_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selmuon_mom_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_mom_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selmuon_mom_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selmuon_mom_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selmuon_mom_CCNue_2pcont-> SetFillColor(31);
  selmuon_mom_NC_2pcont-> SetFillColor(kOrange+6);
  selmuon_mom_OOFV_2pcont-> SetFillColor(kYellow+2);
  selmuon_mom_EXT_2pcont-> SetFillColor(kBlack);
  selmuon_mom_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selmuon_mom_2pcont = new THStack("selmuon_mom_2pcont","momemtum");
  selmuon_mom_2pcont-> Add(selmuon_mom_CC0Pion0Proton_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_CC0Pion1Proton_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_CC0Pion2Proton_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_CC0PionNProton_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_CC1PionNProton_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_CCNPionNProton_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_CCNue_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_NC_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_OOFV_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_EXT_2pcont);
  //selmuon_mom_2pcont-> Add(selmuon_mom_other_2pcont);
  selmuon_mom_2pcont-> Add(selmuon_mom_OffBeam_2pcont);
  //selmuon_mom_2pcont->SetMaximum(600.);
  selmuon_mom_2pcont-> Draw();
  selmuon_mom_2pcont->GetXaxis()->SetTitle("muon candidate, momemtum [GeV]");

  selmuon_mom_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_mom_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_mom_OnBeam_2pcont->Draw("e1same");

  TLegend *l2 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l2 -> SetNColumns(2);
  l2 -> AddEntry(selmuon_mom_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l2 -> AddEntry(selmuon_mom_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l2 -> AddEntry(selmuon_mom_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l2 -> AddEntry(selmuon_mom_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l2 -> AddEntry(selmuon_mom_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l2 -> AddEntry(selmuon_mom_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l2 -> AddEntry(selmuon_mom_CCNue_2pcont, "CC#nu_{e}", "f");
  l2 -> AddEntry(selmuon_mom_NC_2pcont, "NC", "f");
  l2 -> AddEntry(selmuon_mom_OOFV_2pcont, "OOFV", "f");
  l2 -> AddEntry(selmuon_mom_EXT_2pcont, "cosmic", "f");
  //l2 -> AddEntry(selmuon_mom_other_2pcont, "other", "f");
  l2 -> AddEntry(selmuon_mom_OffBeam_2pcont, "off-beam data", "f");
  l2 -> AddEntry(selmuon_mom_OnBeam_2pcont, "on-beam data", "lep");
  l2 -> Draw();  
  
  c2->Update();
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_mom_topo_2pcont.pdf");

  TCanvas *c3 = new TCanvas("c3", "c3", 900, 900);

  selmuon_costheta_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selmuon_costheta_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selmuon_costheta_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_costheta_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selmuon_costheta_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selmuon_costheta_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selmuon_costheta_CCNue_2pcont-> SetFillColor(31);
  selmuon_costheta_NC_2pcont-> SetFillColor(kOrange+6);
  selmuon_costheta_OOFV_2pcont-> SetFillColor(kYellow+2);
  selmuon_costheta_EXT_2pcont-> SetFillColor(kBlack);
  selmuon_costheta_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selmuon_costheta_2pcont = new THStack("selmuon_costheta_2pcont","cos #theta");
  selmuon_costheta_2pcont-> Add(selmuon_costheta_CC0Pion0Proton_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_CC0Pion1Proton_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_CC0Pion2Proton_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_CC0PionNProton_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_CC1PionNProton_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_CCNPionNProton_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_CCNue_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_NC_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_OOFV_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_EXT_2pcont);
  //selmuon_costheta_2pcont-> Add(selmuon_costheta_other_2pcont);
  selmuon_costheta_2pcont-> Add(selmuon_costheta_OffBeam_2pcont);
  selmuon_costheta_2pcont->SetMaximum(200.);
  selmuon_costheta_2pcont-> Draw();
  selmuon_costheta_2pcont->GetXaxis()->SetTitle("muon candidate, cos #theta");

  selmuon_costheta_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_costheta_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_costheta_OnBeam_2pcont->Draw("e1same");

  TLegend *l3 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l3 -> SetNColumns(2);
  l3 -> AddEntry(selmuon_costheta_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l3 -> AddEntry(selmuon_costheta_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l3 -> AddEntry(selmuon_costheta_CCNue_2pcont, "CC#nu_{e}", "f");
  l3 -> AddEntry(selmuon_costheta_NC_2pcont, "NC", "f");
  l3 -> AddEntry(selmuon_costheta_OOFV_2pcont, "OOFV", "f");
  l3 -> AddEntry(selmuon_costheta_EXT_2pcont, "cosmic", "f");
  //l3 -> AddEntry(selmuon_costheta_other_2pcont, "other", "f");
  l3 -> AddEntry(selmuon_costheta_OffBeam_2pcont, "off-beam data", "f");
  l3 -> AddEntry(selmuon_costheta_OnBeam_2pcont, "on-beam data", "lep");
  l3 -> Draw();  
  
  c3->Update();
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_costheta_topo_2pcont.pdf");

  TCanvas *c4 = new TCanvas("c4", "c4", 900, 900);

  selmuon_phi_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selmuon_phi_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selmuon_phi_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_phi_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selmuon_phi_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selmuon_phi_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selmuon_phi_CCNue_2pcont-> SetFillColor(31);
  selmuon_phi_NC_2pcont-> SetFillColor(kOrange+6);
  selmuon_phi_OOFV_2pcont-> SetFillColor(kYellow+2);
  selmuon_phi_EXT_2pcont-> SetFillColor(kBlack);
  selmuon_phi_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selmuon_phi_2pcont = new THStack("selmuon_phi_2pcont","#phi");
  selmuon_phi_2pcont-> Add(selmuon_phi_CC0Pion0Proton_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_CC0Pion1Proton_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_CC0Pion2Proton_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_CC0PionNProton_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_CC1PionNProton_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_CCNPionNProton_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_CCNue_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_NC_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_OOFV_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_EXT_2pcont);
  //selmuon_phi_2pcont-> Add(selmuon_phi_other_2pcont);
  selmuon_phi_2pcont-> Add(selmuon_phi_OffBeam_2pcont);
  selmuon_phi_2pcont->SetMaximum(40.);
  selmuon_phi_2pcont-> Draw();
  selmuon_phi_2pcont->GetXaxis()->SetTitle("muon candidate, #phi");

  selmuon_phi_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_phi_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_phi_OnBeam_2pcont->Draw("e1same");

  TLegend *l4 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l4 -> SetNColumns(2);
  l4 -> AddEntry(selmuon_phi_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l4 -> AddEntry(selmuon_phi_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l4 -> AddEntry(selmuon_phi_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l4 -> AddEntry(selmuon_phi_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l4 -> AddEntry(selmuon_phi_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l4 -> AddEntry(selmuon_phi_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l4 -> AddEntry(selmuon_phi_CCNue_2pcont, "CC#nu_{e}", "f");
  l4 -> AddEntry(selmuon_phi_NC_2pcont, "NC", "f");
  l4 -> AddEntry(selmuon_phi_OOFV_2pcont, "OOFV", "f");
  l4 -> AddEntry(selmuon_phi_EXT_2pcont, "cosmic", "f");
  //l4 -> AddEntry(selmuon_phi_other_2pcont, "other", "f");
  l4 -> AddEntry(selmuon_phi_OffBeam_2pcont, "off-beam data", "f");
  l4 -> AddEntry(selmuon_phi_OnBeam_2pcont, "on-beam data", "lep");
  l4 -> Draw();  
  
  c4->Update();
  c4->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_phi_topo_2pcont.pdf");

  TCanvas *c5 = new TCanvas("c5", "c5", 900, 900);

  selmuon_lenght_muon_2pcont-> SetFillColor(kRed +1);
  selmuon_lenght_proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_lenght_pion_2pcont-> SetFillColor(kOrange);
  selmuon_lenght_electron_2pcont-> SetFillColor(kRed-9);
  selmuon_lenght_pother_2pcont-> SetFillColor(kGreen-8);
  selmuon_lenght_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selmuon_lenghtpdg_2pcont = new THStack("selmuon_lenghtpdg_2pcont","length");
  selmuon_lenghtpdg_2pcont-> Add(selmuon_lenght_muon_2pcont);
  selmuon_lenghtpdg_2pcont-> Add(selmuon_lenght_proton_2pcont);
  selmuon_lenghtpdg_2pcont-> Add(selmuon_lenght_pion_2pcont);
  selmuon_lenghtpdg_2pcont-> Add(selmuon_lenght_electron_2pcont);
  selmuon_lenghtpdg_2pcont-> Add(selmuon_lenght_pother_2pcont);
  selmuon_lenghtpdg_2pcont-> Add(selmuon_lenght_OffBeam_2pcont);
  //selmuon_phi_2pcont->SetMaximum(600.);
  selmuon_lenghtpdg_2pcont-> Draw();
  selmuon_lenghtpdg_2pcont->GetXaxis()->SetTitle("muon candidate, length [cm]");

  selmuon_lenght_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_lenght_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_lenght_OnBeam_2pcont->Draw("e1same");

  TLegend *l5 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l5 -> SetNColumns(2);
  l5 -> AddEntry(selmuon_lenght_muon_2pcont, "#mu", "f");
  l5 -> AddEntry(selmuon_lenght_proton_2pcont, "proton", "f");
  l5 -> AddEntry(selmuon_lenght_pion_2pcont, "#pi", "f");
  l5 -> AddEntry(selmuon_lenght_electron_2pcont, "e^{+/-}", "f");
  l5 -> AddEntry(selmuon_lenght_pother_2pcont, "other", "f");
  l5 -> AddEntry(selmuon_lenght_OffBeam_2pcont, "off-beam data", "f");
  l5 -> AddEntry(selmuon_lenght_OnBeam_2pcont, "on-beam data", "lep");
  l5 -> Draw();  
  
  c5->Update();
  c5->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_lenght_pdg_2pcont.pdf");

  TCanvas *c6 = new TCanvas("c6", "c6", 900, 900);

  selmuon_mom_muon_2pcont-> SetFillColor(kRed +1);
  selmuon_mom_proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_mom_pion_2pcont-> SetFillColor(kOrange);
  selmuon_mom_electron_2pcont-> SetFillColor(kRed-9);
  selmuon_mom_pother_2pcont-> SetFillColor(kGreen-8);
  selmuon_mom_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selmuon_mompdg_2pcont = new THStack("selmuon_mompdg_2pcont","momemtum");
  selmuon_mompdg_2pcont-> Add(selmuon_mom_muon_2pcont);
  selmuon_mompdg_2pcont-> Add(selmuon_mom_proton_2pcont);
  selmuon_mompdg_2pcont-> Add(selmuon_mom_pion_2pcont);
  selmuon_mompdg_2pcont-> Add(selmuon_mom_electron_2pcont);
  selmuon_mompdg_2pcont-> Add(selmuon_mom_pother_2pcont);
  selmuon_mompdg_2pcont-> Add(selmuon_mom_OffBeam_2pcont);
  //selmuon_phi_2pcont->SetMaximum(600.);
  selmuon_mompdg_2pcont-> Draw();
  selmuon_mompdg_2pcont->GetXaxis()->SetTitle("muon candidate, momemtum [GeV]");

  selmuon_mom_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_mom_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_mom_OnBeam_2pcont->Draw("e1same");

  TLegend *l6 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l6 -> SetNColumns(2);
  l6 -> AddEntry(selmuon_mom_muon_2pcont, "#mu", "f");
  l6 -> AddEntry(selmuon_mom_proton_2pcont, "proton", "f");
  l6 -> AddEntry(selmuon_mom_pion_2pcont, "#pi", "f");
  l6 -> AddEntry(selmuon_mom_electron_2pcont, "e^{+/-}", "f");
  l6 -> AddEntry(selmuon_mom_pother_2pcont, "other", "f");
  l6 -> AddEntry(selmuon_mom_OffBeam_2pcont, "off-beam data", "f");
  l6 -> AddEntry(selmuon_mom_OnBeam_2pcont, "on-beam data", "lep");
  l6 -> Draw();  
  
  c6->Update();
  c6->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_mom_pdg_2pcont.pdf");

  TCanvas *c7 = new TCanvas("c7", "c7", 900, 900);

  selmuon_costheta_muon_2pcont-> SetFillColor(kRed +1);
  selmuon_costheta_proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_costheta_pion_2pcont-> SetFillColor(kOrange);
  selmuon_costheta_electron_2pcont-> SetFillColor(kRed-9);
  selmuon_costheta_pother_2pcont-> SetFillColor(kGreen-8);
  selmuon_costheta_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selmuon_costhetapdg_2pcont = new THStack("selmuon_costhetapdg_2pcont","cos #theta");
  selmuon_costhetapdg_2pcont-> Add(selmuon_costheta_muon_2pcont);
  selmuon_costhetapdg_2pcont-> Add(selmuon_costheta_proton_2pcont);
  selmuon_costhetapdg_2pcont-> Add(selmuon_costheta_pion_2pcont);
  selmuon_costhetapdg_2pcont-> Add(selmuon_costheta_electron_2pcont);
  selmuon_costhetapdg_2pcont-> Add(selmuon_costheta_pother_2pcont);
  selmuon_costhetapdg_2pcont-> Add(selmuon_costheta_OffBeam_2pcont);
  selmuon_costhetapdg_2pcont->SetMaximum(200.);
  selmuon_costhetapdg_2pcont-> Draw();
  selmuon_costhetapdg_2pcont->GetXaxis()->SetTitle("muon candidate, cos #theta");

  selmuon_costheta_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_costheta_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_costheta_OnBeam_2pcont->Draw("e1same");

  TLegend *l7 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l7 -> SetNColumns(2);
  l7 -> AddEntry(selmuon_costheta_muon_2pcont, "#mu", "f");
  l7 -> AddEntry(selmuon_costheta_proton_2pcont, "proton", "f");
  l7 -> AddEntry(selmuon_costheta_pion_2pcont, "#pi", "f");
  l7 -> AddEntry(selmuon_costheta_electron_2pcont, "e^{+/-}", "f");
  l7 -> AddEntry(selmuon_costheta_pother_2pcont, "other", "f");
  l7 -> AddEntry(selmuon_costheta_OffBeam_2pcont, "off-beam data", "f");
  l7 -> AddEntry(selmuon_costheta_OnBeam_2pcont, "on-beam data", "lep");
  l7 -> Draw();  
  
  c7->Update();
  c7->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_costheta_pdg_2pcont.pdf");

  TCanvas *c8 = new TCanvas("c8", "c8", 900, 900);

  selmuon_phi_muon_2pcont-> SetFillColor(kRed +1);
  selmuon_phi_proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_phi_pion_2pcont-> SetFillColor(kOrange);
  selmuon_phi_electron_2pcont-> SetFillColor(kRed-9);
  selmuon_phi_pother_2pcont-> SetFillColor(kGreen-8);
  selmuon_phi_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selmuon_phipdg_2pcont = new THStack("selmuon_phipdg_2pcont","#phi");
  selmuon_phipdg_2pcont-> Add(selmuon_phi_muon_2pcont);
  selmuon_phipdg_2pcont-> Add(selmuon_phi_proton_2pcont);
  selmuon_phipdg_2pcont-> Add(selmuon_phi_pion_2pcont);
  selmuon_phipdg_2pcont-> Add(selmuon_phi_electron_2pcont);
  selmuon_phipdg_2pcont-> Add(selmuon_phi_pother_2pcont);
  selmuon_phipdg_2pcont-> Add(selmuon_phi_OffBeam_2pcont);
  selmuon_phipdg_2pcont->SetMaximum(40.);
  selmuon_phipdg_2pcont-> Draw();
  selmuon_phipdg_2pcont->GetXaxis()->SetTitle("muon candidate, #phi");

  selmuon_phi_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_phi_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_phi_OnBeam_2pcont->Draw("e1same");

  TLegend *l8 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l8 -> SetNColumns(2);
  l8 -> AddEntry(selmuon_phi_muon_2pcont, "#mu", "f");
  l8 -> AddEntry(selmuon_phi_proton_2pcont, "proton", "f");
  l8 -> AddEntry(selmuon_phi_pion_2pcont, "#pi", "f");
  l8 -> AddEntry(selmuon_phi_electron_2pcont, "e^{+/-}", "f");
  l8 -> AddEntry(selmuon_phi_pother_2pcont, "other", "f");
  l8 -> AddEntry(selmuon_phi_OffBeam_2pcont, "off-beam data", "f");
  l8 -> AddEntry(selmuon_phi_OnBeam_2pcont, "on-beam data", "lep");
  l8 -> Draw();  
  
  c8->Update();
  c8->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_phi_pdg_2pcont.pdf");

  TCanvas *c10 = new TCanvas("c10", "c10", 900, 900);

  selmuon_chi2proton_muon_2pcont-> SetFillColor(kRed +1);
  selmuon_chi2proton_proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_chi2proton_pion_2pcont-> SetFillColor(kOrange);
  selmuon_chi2proton_electron_2pcont-> SetFillColor(kRed-9);
  selmuon_chi2proton_pother_2pcont-> SetFillColor(kGreen-8);
  selmuon_chi2proton_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selmuon_chi2protonpdg_2pcont = new THStack("selmuon_chi2protonpdg_2pcont","#chi^{2} proton hypothesis");
  selmuon_chi2protonpdg_2pcont-> Add(selmuon_chi2proton_muon_2pcont);
  selmuon_chi2protonpdg_2pcont-> Add(selmuon_chi2proton_proton_2pcont);
  selmuon_chi2protonpdg_2pcont-> Add(selmuon_chi2proton_pion_2pcont);
  selmuon_chi2protonpdg_2pcont-> Add(selmuon_chi2proton_electron_2pcont);
  selmuon_chi2protonpdg_2pcont-> Add(selmuon_chi2proton_pother_2pcont);
  selmuon_chi2protonpdg_2pcont-> Add(selmuon_chi2proton_OffBeam_2pcont);
  //selmuon_chi2protonpdg_2pcont->SetMaximum(120.);
  selmuon_chi2protonpdg_2pcont-> Draw();
  selmuon_chi2protonpdg_2pcont->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");

  selmuon_chi2proton_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_chi2proton_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_chi2proton_OnBeam_2pcont->Draw("e1same");

  TLegend *l10 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l10 -> SetNColumns(2);
  l10 -> AddEntry(selmuon_chi2proton_muon_2pcont, "#mu", "f");
  l10 -> AddEntry(selmuon_chi2proton_proton_2pcont, "proton", "f");
  l10 -> AddEntry(selmuon_chi2proton_pion_2pcont, "#pi", "f");
  l10 -> AddEntry(selmuon_chi2proton_electron_2pcont, "e^{+/-}", "f");
  l10 -> AddEntry(selmuon_chi2proton_pother_2pcont, "other", "f");
  l10 -> AddEntry(selmuon_chi2proton_OffBeam_2pcont, "off-beam data", "f");
  l10 -> AddEntry(selmuon_chi2proton_OnBeam_2pcont, "on-beam data", "lep");
  l10 -> Draw();  
  
  c10->Update();
  c10->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_chi2proton_pdg_2pcont.pdf");

  TCanvas *c11 = new TCanvas("c11", "c11", 900, 900);

  selproton1_lenght_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selproton1_lenght_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selproton1_lenght_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selproton1_lenght_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selproton1_lenght_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selproton1_lenght_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selproton1_lenght_CCNue_2pcont-> SetFillColor(31);
  selproton1_lenght_NC_2pcont-> SetFillColor(kOrange+6);
  selproton1_lenght_OOFV_2pcont-> SetFillColor(kYellow+2);
  selproton1_lenght_EXT_2pcont-> SetFillColor(kBlack);
  selproton1_lenght_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selproton1_lenght_2pcont = new THStack("selproton1_lenght_2pcont","length");
  selproton1_lenght_2pcont-> Add(selproton1_lenght_CC0Pion0Proton_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_CC0Pion1Proton_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_CC0Pion2Proton_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_CC0PionNProton_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_CC1PionNProton_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_CCNPionNProton_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_CCNue_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_NC_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_OOFV_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_EXT_2pcont);
  //selproton1_lenght_2pcont-> Add(selproton1_lenght_other_2pcont);
  selproton1_lenght_2pcont-> Add(selproton1_lenght_OffBeam_2pcont);
  //selproton1_lenght_2pcont->SetMaximum(600.);
  selproton1_lenght_2pcont-> Draw();
  selproton1_lenght_2pcont->GetXaxis()->SetTitle("proton 1 candidate, length [cm]");

  selproton1_lenght_OnBeam_2pcont->SetLineColor(kBlack);
  selproton1_lenght_OnBeam_2pcont->SetMarkerStyle(20);
  selproton1_lenght_OnBeam_2pcont->Draw("e1same");

  TLegend *l11 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l11 -> SetNColumns(2);
  l11 -> AddEntry(selproton1_lenght_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l11 -> AddEntry(selproton1_lenght_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l11 -> AddEntry(selproton1_lenght_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l11 -> AddEntry(selproton1_lenght_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l11 -> AddEntry(selproton1_lenght_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l11 -> AddEntry(selproton1_lenght_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l11 -> AddEntry(selproton1_lenght_CCNue_2pcont, "CC#nu_{e}", "f");
  l11 -> AddEntry(selproton1_lenght_NC_2pcont, "NC", "f");
  l11 -> AddEntry(selproton1_lenght_OOFV_2pcont, "OOFV", "f");
  l11 -> AddEntry(selproton1_lenght_EXT_2pcont, "cosmic", "f");
  //l11 -> AddEntry(selproton1_lenght_other_2pcont, "other", "f");
  l11 -> AddEntry(selproton1_lenght_OffBeam_2pcont, "off-beam data", "f");
  l11 -> AddEntry(selproton1_lenght_OnBeam_2pcont, "on-beam data", "lep");
  l11 -> Draw();  
  
  c11->Update();
  c11->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_lenght_topo_2pcont.pdf");

  TCanvas *c12 = new TCanvas("c12", "c12", 900, 900);

  selproton1_costheta_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selproton1_costheta_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selproton1_costheta_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selproton1_costheta_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selproton1_costheta_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selproton1_costheta_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selproton1_costheta_CCNue_2pcont-> SetFillColor(31);
  selproton1_costheta_NC_2pcont-> SetFillColor(kOrange+6);
  selproton1_costheta_OOFV_2pcont-> SetFillColor(kYellow+2);
  selproton1_costheta_EXT_2pcont-> SetFillColor(kBlack);
  selproton1_costheta_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selproton1_costheta_2pcont = new THStack("selproton1_costheta_2pcont","cos #theta");
  selproton1_costheta_2pcont-> Add(selproton1_costheta_CC0Pion0Proton_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_CC0Pion1Proton_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_CC0Pion2Proton_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_CC0PionNProton_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_CC1PionNProton_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_CCNPionNProton_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_CCNue_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_NC_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_OOFV_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_EXT_2pcont);
  //selproton1_costheta_2pcont-> Add(selproton1_costheta_other_2pcont);
  selproton1_costheta_2pcont-> Add(selproton1_costheta_OffBeam_2pcont);
  selproton1_costheta_2pcont->SetMaximum(150.);
  selproton1_costheta_2pcont-> Draw();
  selproton1_costheta_2pcont->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");

  selproton1_costheta_OnBeam_2pcont->SetLineColor(kBlack);
  selproton1_costheta_OnBeam_2pcont->SetMarkerStyle(20);
  selproton1_costheta_OnBeam_2pcont->Draw("e1same");

  TLegend *l12 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l12 -> SetNColumns(2);
  l12 -> AddEntry(selproton1_costheta_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l12 -> AddEntry(selproton1_costheta_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l12 -> AddEntry(selproton1_costheta_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l12 -> AddEntry(selproton1_costheta_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l12 -> AddEntry(selproton1_costheta_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l12 -> AddEntry(selproton1_costheta_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l12 -> AddEntry(selproton1_costheta_CCNue_2pcont, "CC#nu_{e}", "f");
  l12 -> AddEntry(selproton1_costheta_NC_2pcont, "NC", "f");
  l12 -> AddEntry(selproton1_costheta_OOFV_2pcont, "OOFV", "f");
  l12 -> AddEntry(selproton1_costheta_EXT_2pcont, "cosmic", "f");
  //l12 -> AddEntry(selproton1_costheta_other_2pcont, "other", "f");
  l12 -> AddEntry(selproton1_costheta_OffBeam_2pcont, "off-beam data", "f");
  l12 -> AddEntry(selproton1_costheta_OnBeam_2pcont, "on-beam data", "lep");
  l12 -> Draw();  
  
  c12->Update();
  c12->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_costheta_topo_2pcont.pdf");

  TCanvas *c13 = new TCanvas("c13", "c13", 900, 900);

  selproton1_phi_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selproton1_phi_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selproton1_phi_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selproton1_phi_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selproton1_phi_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selproton1_phi_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selproton1_phi_CCNue_2pcont-> SetFillColor(31);
  selproton1_phi_NC_2pcont-> SetFillColor(kOrange+6);
  selproton1_phi_OOFV_2pcont-> SetFillColor(kYellow+2);
  selproton1_phi_EXT_2pcont-> SetFillColor(kBlack);
  selproton1_phi_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selproton1_phi_2pcont = new THStack("selproton1_phi_2pcont","#phi");
  selproton1_phi_2pcont-> Add(selproton1_phi_CC0Pion0Proton_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_CC0Pion1Proton_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_CC0Pion2Proton_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_CC0PionNProton_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_CC1PionNProton_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_CCNPionNProton_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_CCNue_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_NC_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_OOFV_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_EXT_2pcont);
  //selproton1_phi_2pcont-> Add(selproton1_phi_other_2pcont);
  selproton1_phi_2pcont-> Add(selproton1_phi_OffBeam_2pcont);
  selproton1_phi_2pcont->SetMaximum(40.);
  selproton1_phi_2pcont-> Draw();
  selproton1_phi_2pcont->GetXaxis()->SetTitle("proton 1 candidate, #phi");

  selproton1_phi_OnBeam_2pcont->SetLineColor(kBlack);
  selproton1_phi_OnBeam_2pcont->SetMarkerStyle(20);
  selproton1_phi_OnBeam_2pcont->Draw("e1same");

  TLegend *l13 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l13 -> SetNColumns(2);
  l13 -> AddEntry(selproton1_phi_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l13 -> AddEntry(selproton1_phi_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l13 -> AddEntry(selproton1_phi_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l13 -> AddEntry(selproton1_phi_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l13 -> AddEntry(selproton1_phi_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l13 -> AddEntry(selproton1_phi_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l13 -> AddEntry(selproton1_phi_CCNue_2pcont, "CC#nu_{e}", "f");
  l13 -> AddEntry(selproton1_phi_NC_2pcont, "NC", "f");
  l13 -> AddEntry(selproton1_phi_OOFV_2pcont, "OOFV", "f");
  l13 -> AddEntry(selproton1_phi_EXT_2pcont, "cosmic", "f");
  //l13 -> AddEntry(selproton1_phi_other_2pcont, "other", "f");
  l13 -> AddEntry(selproton1_phi_OffBeam_2pcont, "off-beam data", "f");
  l13 -> AddEntry(selproton1_phi_OnBeam_2pcont, "on-beam data", "lep");
  l13 -> Draw();  
  
  c13->Update();
  c13->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_phi_topo_2pcont.pdf");

  TCanvas *c14 = new TCanvas("c14", "c14", 900, 900);

  selproton1_lenght_muon_2pcont-> SetFillColor(kRed +1);
  selproton1_lenght_proton_2pcont-> SetFillColor(kAzure+4);
  selproton1_lenght_pion_2pcont-> SetFillColor(kOrange);
  selproton1_lenght_electron_2pcont-> SetFillColor(kRed-9);
  selproton1_lenght_pother_2pcont-> SetFillColor(kGreen-8);
  selproton1_lenght_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton1_lenghtpdg_2pcont = new THStack("selproton1_lenghtpdg_2pcont","length");
  selproton1_lenghtpdg_2pcont-> Add(selproton1_lenght_muon_2pcont);
  selproton1_lenghtpdg_2pcont-> Add(selproton1_lenght_proton_2pcont);
  selproton1_lenghtpdg_2pcont-> Add(selproton1_lenght_pion_2pcont);
  selproton1_lenghtpdg_2pcont-> Add(selproton1_lenght_electron_2pcont);
  selproton1_lenghtpdg_2pcont-> Add(selproton1_lenght_pother_2pcont);
  selproton1_lenghtpdg_2pcont-> Add(selproton1_lenght_OffBeam_2pcont);
  //selmuon_chi2kaonpdg_2pcont->SetMaximum(50.);
  selproton1_lenghtpdg_2pcont-> Draw();
  selproton1_lenghtpdg_2pcont->GetXaxis()->SetTitle("proton 1 candidate, length [cm]");

  selproton1_lenght_OnBeam_2pcont->SetLineColor(kBlack);
  selproton1_lenght_OnBeam_2pcont->SetMarkerStyle(20);
  selproton1_lenght_OnBeam_2pcont->Draw("e1same");

  TLegend *l14 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l14 -> SetNColumns(2);
  l14 -> AddEntry(selproton1_lenght_muon_2pcont, "#mu", "f");
  l14 -> AddEntry(selproton1_lenght_proton_2pcont, "proton", "f");
  l14 -> AddEntry(selproton1_lenght_pion_2pcont, "#pi", "f");
  l14 -> AddEntry(selproton1_lenght_electron_2pcont, "e^{+/-}", "f");
  l14 -> AddEntry(selproton1_lenght_pother_2pcont, "other", "f");
  l14 -> AddEntry(selproton1_lenght_OffBeam_2pcont, "off-beam data", "f");
  l14 -> AddEntry(selproton1_lenght_OnBeam_2pcont, "on-beam data", "lep");
  l14 -> Draw();  
  
  c14->Update();
  c14->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_lenght_pdg_2pcont.pdf");

  TCanvas *c15 = new TCanvas("c15", "c15", 900, 900);

  selproton1_costheta_muon_2pcont-> SetFillColor(kRed +1);
  selproton1_costheta_proton_2pcont-> SetFillColor(kAzure+4);
  selproton1_costheta_pion_2pcont-> SetFillColor(kOrange);
  selproton1_costheta_electron_2pcont-> SetFillColor(kRed-9);
  selproton1_costheta_pother_2pcont-> SetFillColor(kGreen-8);
  selproton1_costheta_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton1_costhetapdg_2pcont = new THStack("selproton1_costhetapdg_2pcont","cos #theta");
  selproton1_costhetapdg_2pcont-> Add(selproton1_costheta_muon_2pcont);
  selproton1_costhetapdg_2pcont-> Add(selproton1_costheta_proton_2pcont);
  selproton1_costhetapdg_2pcont-> Add(selproton1_costheta_pion_2pcont);
  selproton1_costhetapdg_2pcont-> Add(selproton1_costheta_electron_2pcont);
  selproton1_costhetapdg_2pcont-> Add(selproton1_costheta_pother_2pcont);
  selproton1_costhetapdg_2pcont-> Add(selproton1_costheta_OffBeam_2pcont);
  selproton1_costhetapdg_2pcont->SetMaximum(150);
  selproton1_costhetapdg_2pcont-> Draw();
  selproton1_costhetapdg_2pcont->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");

  selproton1_costheta_OnBeam_2pcont->SetLineColor(kBlack);
  selproton1_costheta_OnBeam_2pcont->SetMarkerStyle(20);
  selproton1_costheta_OnBeam_2pcont->Draw("e1same");

  TLegend *l15 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l15 -> SetNColumns(2);
  l15 -> AddEntry(selproton1_costheta_muon_2pcont, "#mu", "f");
  l15 -> AddEntry(selproton1_costheta_proton_2pcont, "proton", "f");
  l15 -> AddEntry(selproton1_costheta_pion_2pcont, "#pi", "f");
  l15 -> AddEntry(selproton1_costheta_electron_2pcont, "e^{+/-}", "f");
  l15 -> AddEntry(selproton1_costheta_pother_2pcont, "other", "f");
  l15 -> AddEntry(selproton1_costheta_OffBeam_2pcont, "off-beam data", "f");
  l15 -> AddEntry(selproton1_costheta_OnBeam_2pcont, "on-beam data", "lep");
  l15 -> Draw();  
  
  c15->Update();
  c15->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_costheta_pdg_2pcont.pdf");

  TCanvas *c16 = new TCanvas("c16", "c16", 900, 900);

  selproton1_phi_muon_2pcont-> SetFillColor(kRed +1);
  selproton1_phi_proton_2pcont-> SetFillColor(kAzure+4);
  selproton1_phi_pion_2pcont-> SetFillColor(kOrange);
  selproton1_phi_electron_2pcont-> SetFillColor(kRed-9);
  selproton1_phi_pother_2pcont-> SetFillColor(kGreen-8);
  selproton1_phi_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton1_phipdg_2pcont = new THStack("selproton1_phipdg_2pcont","#phi");
  selproton1_phipdg_2pcont-> Add(selproton1_phi_muon_2pcont);
  selproton1_phipdg_2pcont-> Add(selproton1_phi_proton_2pcont);
  selproton1_phipdg_2pcont-> Add(selproton1_phi_pion_2pcont);
  selproton1_phipdg_2pcont-> Add(selproton1_phi_electron_2pcont);
  selproton1_phipdg_2pcont-> Add(selproton1_phi_pother_2pcont);
  selproton1_phipdg_2pcont-> Add(selproton1_phi_OffBeam_2pcont);
  selproton1_phipdg_2pcont->SetMaximum(40.);
  selproton1_phipdg_2pcont-> Draw();
  selproton1_phipdg_2pcont->GetXaxis()->SetTitle("proton 1 candidate, #phi");

  selproton1_phi_OnBeam_2pcont->SetLineColor(kBlack);
  selproton1_phi_OnBeam_2pcont->SetMarkerStyle(20);
  selproton1_phi_OnBeam_2pcont->Draw("e1same");

  TLegend *l16 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l16 -> SetNColumns(2);
  l16 -> AddEntry(selproton1_phi_muon_2pcont, "#mu", "f");
  l16 -> AddEntry(selproton1_phi_proton_2pcont, "proton", "f");
  l16 -> AddEntry(selproton1_phi_pion_2pcont, "#pi", "f");
  l16 -> AddEntry(selproton1_phi_electron_2pcont, "e^{+/-}", "f");
  l16 -> AddEntry(selproton1_phi_pother_2pcont, "other", "f");
  l16 -> AddEntry(selproton1_phi_OffBeam_2pcont, "off-beam data", "f");
  l16 -> AddEntry(selproton1_phi_OnBeam_2pcont, "on-beam data", "lep");
  l16 -> Draw();  
  
  c16->Update();
  c16->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_phi_pdg_2pcont.pdf");

  TCanvas *c18 = new TCanvas("c18", "c18", 900, 900);

  selproton1_chi2proton_muon_2pcont-> SetFillColor(kRed +1);
  selproton1_chi2proton_proton_2pcont-> SetFillColor(kAzure+4);
  selproton1_chi2proton_pion_2pcont-> SetFillColor(kOrange);
  selproton1_chi2proton_electron_2pcont-> SetFillColor(kRed-9);
  selproton1_chi2proton_pother_2pcont-> SetFillColor(kGreen-8);
  selproton1_chi2proton_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton1_chi2protonpdg_2pcont = new THStack("selproton1_chi2protonpdg_2pcont","#chi^{2} proton hypothesis");
  selproton1_chi2protonpdg_2pcont-> Add(selproton1_chi2proton_muon_2pcont);
  selproton1_chi2protonpdg_2pcont-> Add(selproton1_chi2proton_proton_2pcont);
  selproton1_chi2protonpdg_2pcont-> Add(selproton1_chi2proton_pion_2pcont);
  selproton1_chi2protonpdg_2pcont-> Add(selproton1_chi2proton_electron_2pcont);
  selproton1_chi2protonpdg_2pcont-> Add(selproton1_chi2proton_pother_2pcont);
  selproton1_chi2protonpdg_2pcont-> Add(selproton1_chi2proton_OffBeam_2pcont);
  //selproton1_chi2protonpdg_2pcont->SetMaximum(25.);
  selproton1_chi2protonpdg_2pcont-> Draw();
  selproton1_chi2protonpdg_2pcont->GetXaxis()->SetTitle("proton 1 candidate, #chi^{2}/dof proton hypothesis");

  selproton1_chi2proton_OnBeam_2pcont->SetLineColor(kBlack);
  selproton1_chi2proton_OnBeam_2pcont->SetMarkerStyle(20);
  selproton1_chi2proton_OnBeam_2pcont->Draw("e1same");

  TLegend *l18 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l18 -> SetNColumns(2);
  l18 -> AddEntry(selproton1_chi2proton_muon_2pcont, "#mu", "f");
  l18 -> AddEntry(selproton1_chi2proton_proton_2pcont, "proton", "f");
  l18 -> AddEntry(selproton1_chi2proton_pion_2pcont, "#pi", "f");
  l18 -> AddEntry(selproton1_chi2proton_electron_2pcont, "e^{+/-}", "f");
  l18 -> AddEntry(selproton1_chi2proton_pother_2pcont, "other", "f");
  l18 -> AddEntry(selproton1_chi2proton_OffBeam_2pcont, "off-beam data", "f");
  l18 -> AddEntry(selproton1_chi2proton_OnBeam_2pcont, "on-beam data", "lep");
  l18 -> Draw();  
  
  c18->Update();
  c18->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_chi2proton_pdg_2pcont.pdf");

  TCanvas *c19 = new TCanvas("c19", "c19", 900, 900);

  selproton2_lenght_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selproton2_lenght_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selproton2_lenght_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selproton2_lenght_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selproton2_lenght_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selproton2_lenght_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selproton2_lenght_CCNue_2pcont-> SetFillColor(31);
  selproton2_lenght_NC_2pcont-> SetFillColor(kOrange+6);
  selproton2_lenght_OOFV_2pcont-> SetFillColor(kYellow+2);
  selproton2_lenght_EXT_2pcont-> SetFillColor(kBlack);
  selproton2_lenght_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selproton2_lenght_2pcont = new THStack("selproton2_lenght_2pcont","length");
  selproton2_lenght_2pcont-> Add(selproton2_lenght_CC0Pion0Proton_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_CC0Pion1Proton_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_CC0Pion2Proton_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_CC0PionNProton_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_CC1PionNProton_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_CCNPionNProton_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_CCNue_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_NC_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_OOFV_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_EXT_2pcont);
  //selproton2_lenght_2pcont-> Add(selproton2_lenght_other_2pcont);
  selproton2_lenght_2pcont-> Add(selproton2_lenght_OffBeam_2pcont);
  //selproton2_lenght_2pcont->SetMaximum(600.);
  selproton2_lenght_2pcont-> Draw();
  selproton2_lenght_2pcont->GetXaxis()->SetTitle("proton 2 candidate, length [cm]");

  selproton2_lenght_OnBeam_2pcont->SetLineColor(kBlack);
  selproton2_lenght_OnBeam_2pcont->SetMarkerStyle(20);
  selproton2_lenght_OnBeam_2pcont->Draw("e1same");

  TLegend *l19 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l19 -> SetNColumns(2);
  l19 -> AddEntry(selproton2_lenght_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l19 -> AddEntry(selproton2_lenght_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l19 -> AddEntry(selproton2_lenght_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l19 -> AddEntry(selproton2_lenght_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l19 -> AddEntry(selproton2_lenght_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l19 -> AddEntry(selproton2_lenght_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l19 -> AddEntry(selproton2_lenght_CCNue_2pcont, "CC#nu_{e}", "f");
  l19 -> AddEntry(selproton2_lenght_NC_2pcont, "NC", "f");
  l19 -> AddEntry(selproton2_lenght_OOFV_2pcont, "OOFV", "f");
  l19 -> AddEntry(selproton2_lenght_EXT_2pcont, "cosmic", "f");
  //l19 -> AddEntry(selproton2_lenght_other_2pcont, "other", "f");
  l19 -> AddEntry(selproton2_lenght_OffBeam_2pcont, "off-beam data", "f");
  l19 -> AddEntry(selproton2_lenght_OnBeam_2pcont, "on-beam data", "lep");
  l19 -> Draw();  
  
  c19->Update();
  c19->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_lenght_topo_2pcont.pdf");

  TCanvas *c20 = new TCanvas("c20", "c20", 900, 900);

  selproton2_costheta_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selproton2_costheta_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selproton2_costheta_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selproton2_costheta_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selproton2_costheta_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selproton2_costheta_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selproton2_costheta_CCNue_2pcont-> SetFillColor(31);
  selproton2_costheta_NC_2pcont-> SetFillColor(kOrange+6);
  selproton2_costheta_OOFV_2pcont-> SetFillColor(kYellow+2);
  selproton2_costheta_EXT_2pcont-> SetFillColor(kBlack);
  selproton2_costheta_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selproton2_costheta_2pcont = new THStack("selproton2_costheta_2pcont","cos #theta");
  selproton2_costheta_2pcont-> Add(selproton2_costheta_CC0Pion0Proton_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_CC0Pion1Proton_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_CC0Pion2Proton_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_CC0PionNProton_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_CC1PionNProton_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_CCNPionNProton_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_CCNue_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_NC_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_OOFV_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_EXT_2pcont);
  //selproton2_costheta_2pcont-> Add(selproton2_costheta_other_2pcont);
  selproton2_costheta_2pcont-> Add(selproton2_costheta_OffBeam_2pcont);
  selproton2_costheta_2pcont->SetMaximum(150.);
  selproton2_costheta_2pcont-> Draw();
  selproton2_costheta_2pcont->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");

  selproton2_costheta_OnBeam_2pcont->SetLineColor(kBlack);
  selproton2_costheta_OnBeam_2pcont->SetMarkerStyle(20);
  selproton2_costheta_OnBeam_2pcont->Draw("e1same");

  TLegend *l20 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l20 -> SetNColumns(2);
  l20 -> AddEntry(selproton2_costheta_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l20 -> AddEntry(selproton2_costheta_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l20 -> AddEntry(selproton2_costheta_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l20 -> AddEntry(selproton2_costheta_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l20 -> AddEntry(selproton2_costheta_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l20 -> AddEntry(selproton2_costheta_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l20 -> AddEntry(selproton2_costheta_CCNue_2pcont, "CC#nu_{e}", "f");
  l20 -> AddEntry(selproton2_costheta_NC_2pcont, "NC", "f");
  l20 -> AddEntry(selproton2_costheta_OOFV_2pcont, "OOFV", "f");
  l20 -> AddEntry(selproton2_costheta_EXT_2pcont, "cosmic", "f");
  //l20 -> AddEntry(selproton2_costheta_other_2pcont, "other", "f");
  l20 -> AddEntry(selproton2_costheta_OffBeam_2pcont, "off-beam data", "f");
  l20 -> AddEntry(selproton2_costheta_OnBeam_2pcont, "on-beam data", "lep");
  l20 -> Draw();  
  
  c20->Update();
  c20->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_costheta_topo_2pcont.pdf");

  TCanvas *c21 = new TCanvas("c21", "c21", 900, 900);

  selproton2_phi_CC0Pion0Proton_2pcont-> SetFillColor(kRed -10);
  selproton2_phi_CC0Pion1Proton_2pcont-> SetFillColor(kGreen-8);
  selproton2_phi_CC0Pion2Proton_2pcont-> SetFillColor(kAzure+4);
  selproton2_phi_CC0PionNProton_2pcont-> SetFillColor(kRed-9);
  selproton2_phi_CC1PionNProton_2pcont-> SetFillColor(kOrange);
  selproton2_phi_CCNPionNProton_2pcont-> SetFillColor(kCyan-8);
  selproton2_phi_CCNue_2pcont-> SetFillColor(31);
  selproton2_phi_NC_2pcont-> SetFillColor(kOrange+6);
  selproton2_phi_OOFV_2pcont-> SetFillColor(kYellow+2);
  selproton2_phi_EXT_2pcont-> SetFillColor(kBlack);
  selproton2_phi_OffBeam_2pcont-> SetFillColor(kGray);
  //DistFlstrk_other_2pcont-> SetFillColor(kRed);

  THStack *selproton2_phi_2pcont = new THStack("selproton2_phi_2pcont","#phi");
  selproton2_phi_2pcont-> Add(selproton2_phi_CC0Pion0Proton_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_CC0Pion1Proton_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_CC0Pion2Proton_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_CC0PionNProton_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_CC1PionNProton_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_CCNPionNProton_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_CCNue_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_NC_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_OOFV_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_EXT_2pcont);
  //selproton2_phi_2pcont-> Add(selproton2_phi_other_2pcont);
  selproton2_phi_2pcont-> Add(selproton2_phi_OffBeam_2pcont);
  selproton2_phi_2pcont->SetMaximum(40.);
  selproton2_phi_2pcont-> Draw();
  selproton2_phi_2pcont->GetXaxis()->SetTitle("proton 2 candidate, #phi");

  selproton2_phi_OnBeam_2pcont->SetLineColor(kBlack);
  selproton2_phi_OnBeam_2pcont->SetMarkerStyle(20);
  selproton2_phi_OnBeam_2pcont->Draw("e1same");

  TLegend *l21 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l21 -> SetNColumns(2);
  l21 -> AddEntry(selproton2_phi_CC0Pion0Proton_2pcont, "CC0P0#pi", "f");
  l21 -> AddEntry(selproton2_phi_CC0Pion1Proton_2pcont, "CC1P0#pi", "f");
  l21 -> AddEntry(selproton2_phi_CC0Pion2Proton_2pcont, "CC2P0#pi", "f");
  l21 -> AddEntry(selproton2_phi_CC0PionNProton_2pcont, "CCNP0#pi", "f");
  l21 -> AddEntry(selproton2_phi_CC1PionNProton_2pcont, "CCNP1#pi", "f");
  l21 -> AddEntry(selproton2_phi_CCNPionNProton_2pcont, "CCNPN#pi", "f");
  l21 -> AddEntry(selproton2_phi_CCNue_2pcont, "CC#nu_{e}", "f");
  l21 -> AddEntry(selproton2_phi_NC_2pcont, "NC", "f");
  l21 -> AddEntry(selproton2_phi_OOFV_2pcont, "OOFV", "f");
  l21 -> AddEntry(selproton2_phi_EXT_2pcont, "cosmic", "f");
  //l21 -> AddEntry(selproton2_phi_other_2pcont, "other", "f");
  l21 -> AddEntry(selproton2_phi_OffBeam_2pcont, "off-beam data", "f");
  l21 -> AddEntry(selproton2_phi_OnBeam_2pcont, "on-beam data", "lep");
  l21 -> Draw();  
  
  c21->Update();
  c21->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_phi_topo_2pcont.pdf");

  TCanvas *c22 = new TCanvas("c22", "c22", 900, 900);

  selproton2_lenght_muon_2pcont-> SetFillColor(kRed +1);
  selproton2_lenght_proton_2pcont-> SetFillColor(kAzure+4);
  selproton2_lenght_pion_2pcont-> SetFillColor(kOrange);
  selproton2_lenght_electron_2pcont-> SetFillColor(kRed-9);
  selproton2_lenght_pother_2pcont-> SetFillColor(kGreen-8);
  selproton2_lenght_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton2_lenghtpdg_2pcont = new THStack("selproton2_lenghtpdg_2pcont","length");
  selproton2_lenghtpdg_2pcont-> Add(selproton2_lenght_muon_2pcont);
  selproton2_lenghtpdg_2pcont-> Add(selproton2_lenght_proton_2pcont);
  selproton2_lenghtpdg_2pcont-> Add(selproton2_lenght_pion_2pcont);
  selproton2_lenghtpdg_2pcont-> Add(selproton2_lenght_electron_2pcont);
  selproton2_lenghtpdg_2pcont-> Add(selproton2_lenght_pother_2pcont);
  selproton2_lenghtpdg_2pcont-> Add(selproton2_lenght_OffBeam_2pcont);
  //selmuon_chi2kaonpdg_2pcont->SetMaximum(50.);
  selproton2_lenghtpdg_2pcont-> Draw();
  selproton2_lenghtpdg_2pcont->GetXaxis()->SetTitle("proton 2 candidate, length [cm]");

  selproton2_lenght_OnBeam_2pcont->SetLineColor(kBlack);
  selproton2_lenght_OnBeam_2pcont->SetMarkerStyle(20);
  selproton2_lenght_OnBeam_2pcont->Draw("e1same");

  TLegend *l22 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l22 -> SetNColumns(2);
  l22 -> AddEntry(selproton2_lenght_muon_2pcont, "#mu", "f");
  l22 -> AddEntry(selproton2_lenght_proton_2pcont, "proton", "f");
  l22 -> AddEntry(selproton2_lenght_pion_2pcont, "#pi", "f");
  l22 -> AddEntry(selproton2_lenght_electron_2pcont, "e^{+/-}", "f");
  l22 -> AddEntry(selproton2_lenght_pother_2pcont, "other", "f");
  l22 -> AddEntry(selproton2_lenght_OffBeam_2pcont, "off-beam data", "f");
  l22 -> AddEntry(selproton2_lenght_OnBeam_2pcont, "on-beam data", "lep");
  l22 -> Draw();  
  
  c22->Update();
  c22->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_lenght_pdg_2pcont.pdf");

  TCanvas *c23 = new TCanvas("c23", "c23", 900, 900);

  selproton2_costheta_muon_2pcont-> SetFillColor(kRed +1);
  selproton2_costheta_proton_2pcont-> SetFillColor(kAzure+4);
  selproton2_costheta_pion_2pcont-> SetFillColor(kOrange);
  selproton2_costheta_electron_2pcont-> SetFillColor(kRed-9);
  selproton2_costheta_pother_2pcont-> SetFillColor(kGreen-8);
  selproton2_costheta_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton2_costhetapdg_2pcont = new THStack("selproton2_costhetapdg_2pcont","cos #theta");
  selproton2_costhetapdg_2pcont-> Add(selproton2_costheta_muon_2pcont);
  selproton2_costhetapdg_2pcont-> Add(selproton2_costheta_proton_2pcont);
  selproton2_costhetapdg_2pcont-> Add(selproton2_costheta_pion_2pcont);
  selproton2_costhetapdg_2pcont-> Add(selproton2_costheta_electron_2pcont);
  selproton2_costhetapdg_2pcont-> Add(selproton2_costheta_pother_2pcont);
  selproton2_costhetapdg_2pcont-> Add(selproton2_costheta_OffBeam_2pcont);
  selproton2_costhetapdg_2pcont->SetMaximum(150.);
  selproton2_costhetapdg_2pcont-> Draw();
  selproton2_costhetapdg_2pcont->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");

  selproton2_costheta_OnBeam_2pcont->SetLineColor(kBlack);
  selproton2_costheta_OnBeam_2pcont->SetMarkerStyle(20);
  selproton2_costheta_OnBeam_2pcont->Draw("e1same");

  TLegend *l23 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l23 -> SetNColumns(2);
  l23 -> AddEntry(selproton2_costheta_muon_2pcont, "#mu", "f");
  l23 -> AddEntry(selproton2_costheta_proton_2pcont, "proton", "f");
  l23 -> AddEntry(selproton2_costheta_pion_2pcont, "#pi", "f");
  l23 -> AddEntry(selproton2_costheta_electron_2pcont, "e^{+/-}", "f");
  l23 -> AddEntry(selproton2_costheta_pother_2pcont, "other", "f");
  l23 -> AddEntry(selproton2_costheta_OffBeam_2pcont, "off-beam data", "f");
  l23 -> AddEntry(selproton2_costheta_OnBeam_2pcont, "on-beam data", "lep");
  l23 -> Draw();  
  
  c23->Update();
  c23->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_costheta_pdg_2pcont.pdf");

  TCanvas *c24 = new TCanvas("c24", "c24", 900, 900);

  selproton2_phi_muon_2pcont-> SetFillColor(kRed +1);
  selproton2_phi_proton_2pcont-> SetFillColor(kAzure+4);
  selproton2_phi_pion_2pcont-> SetFillColor(kOrange);
  selproton2_phi_electron_2pcont-> SetFillColor(kRed-9);
  selproton2_phi_pother_2pcont-> SetFillColor(kGreen-8);
  selproton2_phi_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton2_phipdg_2pcont = new THStack("selproton2_phipdg_2pcont","#phi");
  selproton2_phipdg_2pcont-> Add(selproton2_phi_muon_2pcont);
  selproton2_phipdg_2pcont-> Add(selproton2_phi_proton_2pcont);
  selproton2_phipdg_2pcont-> Add(selproton2_phi_pion_2pcont);
  selproton2_phipdg_2pcont-> Add(selproton2_phi_electron_2pcont);
  selproton2_phipdg_2pcont-> Add(selproton2_phi_pother_2pcont);
  selproton2_phipdg_2pcont-> Add(selproton2_phi_OffBeam_2pcont);
  selproton2_phipdg_2pcont->SetMaximum(40.);
  selproton2_phipdg_2pcont-> Draw();
  selproton2_phipdg_2pcont->GetXaxis()->SetTitle("proton 2 candidate, #phi");

  selproton2_phi_OnBeam_2pcont->SetLineColor(kBlack);
  selproton2_phi_OnBeam_2pcont->SetMarkerStyle(20);
  selproton2_phi_OnBeam_2pcont->Draw("e1same");

  TLegend *l24 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l24 -> SetNColumns(2);
  l24 -> AddEntry(selproton2_phi_muon_2pcont, "#mu", "f");
  l24 -> AddEntry(selproton2_phi_proton_2pcont, "proton", "f");
  l24 -> AddEntry(selproton2_phi_pion_2pcont, "#pi", "f");
  l24 -> AddEntry(selproton2_phi_electron_2pcont, "e^{+/-}", "f");
  l24 -> AddEntry(selproton2_phi_pother_2pcont, "other", "f");
  l24 -> AddEntry(selproton2_phi_OffBeam_2pcont, "off-beam data", "f");
  l24 -> AddEntry(selproton2_phi_OnBeam_2pcont, "on-beam data", "lep");
  l24 -> Draw();  
  
  c24->Update();
  c24->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_phi_pdg_2pcont.pdf");

  TCanvas *c26 = new TCanvas("c26", "c26", 900, 900);

  selproton2_chi2proton_muon_2pcont-> SetFillColor(kRed +1);
  selproton2_chi2proton_proton_2pcont-> SetFillColor(kAzure+4);
  selproton2_chi2proton_pion_2pcont-> SetFillColor(kOrange);
  selproton2_chi2proton_electron_2pcont-> SetFillColor(kRed-9);
  selproton2_chi2proton_pother_2pcont-> SetFillColor(kGreen-8);
  selproton2_chi2proton_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selproton2_chi2protonpdg_2pcont = new THStack("selproton2_chi2protonpdg_2pcont","#chi^{2} proton hypothesis");
  selproton2_chi2protonpdg_2pcont-> Add(selproton2_chi2proton_muon_2pcont);
  selproton2_chi2protonpdg_2pcont-> Add(selproton2_chi2proton_proton_2pcont);
  selproton2_chi2protonpdg_2pcont-> Add(selproton2_chi2proton_pion_2pcont);
  selproton2_chi2protonpdg_2pcont-> Add(selproton2_chi2proton_electron_2pcont);
  selproton2_chi2protonpdg_2pcont-> Add(selproton2_chi2proton_pother_2pcont);
  selproton2_chi2protonpdg_2pcont-> Add(selproton2_chi2proton_OffBeam_2pcont);
  //selproton2_chi2protonpdg_2pcont->SetMaximum(25.);
  selproton2_chi2protonpdg_2pcont-> Draw();
  selproton2_chi2protonpdg_2pcont->GetXaxis()->SetTitle("proton 2 candidate, #chi^{2}/dof proton hypothesis");

  selproton2_chi2proton_OnBeam_2pcont->SetLineColor(kBlack);
  selproton2_chi2proton_OnBeam_2pcont->SetMarkerStyle(20);
  selproton2_chi2proton_OnBeam_2pcont->Draw("e1same");

  TLegend *l26 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l26 -> SetNColumns(2);
  l26 -> AddEntry(selproton2_chi2proton_muon_2pcont, "#mu", "f");
  l26 -> AddEntry(selproton2_chi2proton_proton_2pcont, "proton", "f");
  l26 -> AddEntry(selproton2_chi2proton_pion_2pcont, "#pi", "f");
  l26 -> AddEntry(selproton2_chi2proton_electron_2pcont, "e^{+/-}", "f");
  l26 -> AddEntry(selproton2_chi2proton_pother_2pcont, "other", "f");
  l26 -> AddEntry(selproton2_chi2proton_OffBeam_2pcont, "off-beam data", "f");
  l26 -> AddEntry(selproton2_chi2proton_OnBeam_2pcont, "on-beam data", "lep");
  l26 -> Draw();  
  
  c26->Update();
  c26->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_chi2proton_pdg_2pcont.pdf");

  TCanvas *c27 = new TCanvas("c27", "c27", 900, 900);

  selmuon_chi2proton_cont_muon_2pcont-> SetFillColor(kRed +1);
  selmuon_chi2proton_cont_proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_chi2proton_cont_pion_2pcont-> SetFillColor(kOrange);
  selmuon_chi2proton_cont_electron_2pcont-> SetFillColor(kRed-9);
  selmuon_chi2proton_cont_pother_2pcont-> SetFillColor(kGreen-8);
  selmuon_chi2proton_cont_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selmuon_chi2proton_contpdg_2pcont = new THStack("selmuon_chi2proton_contpdg_2pcont","#chi^{2} proton hypothesis");
  selmuon_chi2proton_contpdg_2pcont-> Add(selmuon_chi2proton_cont_muon_2pcont);
  selmuon_chi2proton_contpdg_2pcont-> Add(selmuon_chi2proton_cont_proton_2pcont);
  selmuon_chi2proton_contpdg_2pcont-> Add(selmuon_chi2proton_cont_pion_2pcont);
  selmuon_chi2proton_contpdg_2pcont-> Add(selmuon_chi2proton_cont_electron_2pcont);
  selmuon_chi2proton_contpdg_2pcont-> Add(selmuon_chi2proton_cont_pother_2pcont);
  selmuon_chi2proton_contpdg_2pcont-> Add(selmuon_chi2proton_cont_OffBeam_2pcont);
  //selmuon_chi2proton_contpdg_2pcont->SetMaximum(120.);
  selmuon_chi2proton_contpdg_2pcont-> Draw();
  selmuon_chi2proton_contpdg_2pcont->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");

  selmuon_chi2proton_cont_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_chi2proton_cont_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_chi2proton_cont_OnBeam_2pcont->Draw("e1same");

  TLegend *l27 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l27 -> SetNColumns(2);
  l27 -> AddEntry(selmuon_chi2proton_cont_muon_2pcont, "#mu", "f");
  l27 -> AddEntry(selmuon_chi2proton_cont_proton_2pcont, "proton", "f");
  l27 -> AddEntry(selmuon_chi2proton_cont_pion_2pcont, "#pi", "f");
  l27 -> AddEntry(selmuon_chi2proton_cont_electron_2pcont, "e^{+/-}", "f");
  l27 -> AddEntry(selmuon_chi2proton_cont_pother_2pcont, "other", "f");
  l27 -> AddEntry(selmuon_chi2proton_cont_OffBeam_2pcont, "off-beam data", "f");
  l27 -> AddEntry(selmuon_chi2proton_cont_OnBeam_2pcont, "on-beam data", "lep");
  l27 -> Draw();  
  
  c27->Update();
  c27->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_chi2proton_cont_pdg_2pcont.pdf");

  TCanvas *c28 = new TCanvas("c28", "c28", 900, 900);

  selmuon_chi2proton_uncont_muon_2pcont-> SetFillColor(kRed +1);
  selmuon_chi2proton_uncont_proton_2pcont-> SetFillColor(kAzure+4);
  selmuon_chi2proton_uncont_pion_2pcont-> SetFillColor(kOrange);
  selmuon_chi2proton_uncont_electron_2pcont-> SetFillColor(kRed-9);
  selmuon_chi2proton_uncont_pother_2pcont-> SetFillColor(kGreen-8);
  selmuon_chi2proton_uncont_OffBeam_2pcont-> SetFillColor(kGray);

  THStack *selmuon_chi2proton_uncontpdg_2pcont = new THStack("selmuon_chi2proton_uncontpdg_2pcont","#chi^{2} proton hypothesis");
  selmuon_chi2proton_uncontpdg_2pcont-> Add(selmuon_chi2proton_uncont_muon_2pcont);
  selmuon_chi2proton_uncontpdg_2pcont-> Add(selmuon_chi2proton_uncont_proton_2pcont);
  selmuon_chi2proton_uncontpdg_2pcont-> Add(selmuon_chi2proton_uncont_pion_2pcont);
  selmuon_chi2proton_uncontpdg_2pcont-> Add(selmuon_chi2proton_uncont_electron_2pcont);
  selmuon_chi2proton_uncontpdg_2pcont-> Add(selmuon_chi2proton_uncont_pother_2pcont);
  selmuon_chi2proton_uncontpdg_2pcont-> Add(selmuon_chi2proton_uncont_OffBeam_2pcont);
  //selmuon_chi2proton_uncontpdg_2pcont->SetMaximum(120.);
  selmuon_chi2proton_uncontpdg_2pcont-> Draw();
  selmuon_chi2proton_uncontpdg_2pcont->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");

  selmuon_chi2proton_uncont_OnBeam_2pcont->SetLineColor(kBlack);
  selmuon_chi2proton_uncont_OnBeam_2pcont->SetMarkerStyle(20);
  selmuon_chi2proton_uncont_OnBeam_2pcont->Draw("e1same");

  TLegend *l28 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l28 -> SetNColumns(2);
  l28 -> AddEntry(selmuon_chi2proton_uncont_muon_2pcont, "#mu", "f");
  l28 -> AddEntry(selmuon_chi2proton_uncont_proton_2pcont, "proton", "f");
  l28 -> AddEntry(selmuon_chi2proton_uncont_pion_2pcont, "#pi", "f");
  l28 -> AddEntry(selmuon_chi2proton_uncont_electron_2pcont, "e^{+/-}", "f");
  l28 -> AddEntry(selmuon_chi2proton_uncont_pother_2pcont, "other", "f");
  l28 -> AddEntry(selmuon_chi2proton_uncont_OffBeam_2pcont, "off-beam data", "f");
  l28 -> AddEntry(selmuon_chi2proton_uncont_OnBeam_2pcont, "on-beam data", "lep");
  l28 -> Draw();  
  
  c28->Update();
  c28->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selmuon_chi2proton_uncont_pdg_2pcont.pdf");



  TCanvas *c74 = new TCanvas("c74", "c74", 900, 900);
  gStyle->SetOptStat(kFALSE);

  selproton1_dEdx_vs_resrange_OnBeam_2pcont->GetXaxis()->SetTitle("residual range");
  selproton1_dEdx_vs_resrange_OnBeam_2pcont->GetYaxis()->SetTitle("dE/dx");
  //selproton2_dEdx_vs_resrange_OffBeam_2pcont->SetMaximum(400.);
  selproton1_dEdx_vs_resrange_OnBeam_2pcont->Draw("colz");

  c74->Update();
  c74-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton1_dEdx_vs_resrange_OnBeam_2pcont.pdf");

  TCanvas *c75 = new TCanvas("c75", "c75", 900, 900);
  gStyle->SetOptStat(kFALSE);

  selproton2_dEdx_vs_resrange_OnBeam_2pcont->GetXaxis()->SetTitle("residual range");
  selproton2_dEdx_vs_resrange_OnBeam_2pcont->GetYaxis()->SetTitle("dE/dx");
  //selproton2_dEdx_vs_resrange_OffBeam_2pcont->SetMaximum(400.);
  selproton2_dEdx_vs_resrange_OnBeam_2pcont->Draw("colz");

  c75->Update();
  c75-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/selproton2_dEdx_vs_resrange_OnBeam_2pcont.pdf");

  TCanvas *c76 = new TCanvas("c76", "c76", 900, 900);
  gStyle->SetOptStat(kFALSE);

  selmuon_dEdx_vs_resrange_OnBeam_2pcont->GetXaxis()->SetTitle("residual range");
  selmuon_dEdx_vs_resrange_OnBeam_2pcont->GetYaxis()->SetTitle("dE/dx");
  //selproton2_dEdx_vs_resrange_OffBeam_2pcont->SetMaximum(400.);
  selmuon_dEdx_vs_resrange_OnBeam_2pcont->Draw("colz");

  c76->Update();
  c76-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/2pcont/muon_dEdx_vs_resrange_OnBeam_2pcont.pdf");


}
