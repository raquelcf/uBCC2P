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

double Chi2Calc(TH1 *histo_MC, TH1D *histo_bnb, TH1D *histo_extbnb, double scale_offbeam, double norm_MC){

  int nbins=histo_MC->GetNbinsX();
  int nbinsdata=0;
  double N_MC[nbins], N_BNB[nbins], N_EXTBNB[nbins];
  double Chi2=0.0;
  /// area normalized
  double intOffBeam = (histo_extbnb->GetEntries());
  double intMC = (histo_MC->GetEntries());
  double intOnBeam = histo_bnb->GetEntries();
 
  for(int ii=0; ii<nbins-1; ii++){
     N_MC[ii]=histo_MC->GetBinContent(ii+1);
     N_BNB[ii]=histo_bnb->GetBinContent(ii+1);
     N_EXTBNB[ii]=histo_extbnb->GetBinContent(ii+1);
     if(N_BNB[ii]>0 && N_MC[ii]>0){
       Chi2 +=pow((N_MC[ii]+N_EXTBNB[ii]-N_BNB[ii]),2)/(N_MC[ii] +N_EXTBNB[ii]);
       nbinsdata++;
     }
  }
  std::cout<<"  chi2test : "<<Chi2<<" ndof: "<<nbinsdata<<" chi2/ndof: "<<Chi2/nbinsdata<<std::endl;

  return Chi2/nbinsdata;
}

std::vector<double> Error(TProfile *hprof){

  int nbins=hprof->GetNbinsX();
  double N_Prof[nbins];
  double err=0.0;
 
  for(int ii=0; ii<nbins-1; ii++){
    N_Prof[ii]=hprof->GetBinContent(ii+1);
     if(N_Prof[ii]>0){
       err =pow((N_MC[ii]+N_EXTBNB[ii]-N_BNB[ii]),2)/(N_MC[ii] +N_EXTBNB[ii]);
       nbinsdata++;
     }
  }
  std::cout<<"  chi2test : "<<Chi2<<" ndof: "<<nbinsdata<<" chi2/ndof: "<<Chi2/nbinsdata<<std::endl;

  return Chi2/nbinsdata;
}


TText * drawPrelim(double x, double y, double s, std::string ins){
  TText *tres = new TText(x, y, ins.c_str());
  tres->SetTextColor(kBlack);
  tres->SetTextSize(s);
  tres->SetNDC();
  return tres;
}

void DataMC_errors(){ 
  
  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/resolutions_BNBMC.root","READ");

  std::cout<<"antes de Tfile"<<std::endl;
  
  ofstream outfileDataMC_Errors;
  outfileDataMC_Errors.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/Errors.txt");
  ////// BNB MC

  /// errors

  TProfile* hprof_cosp1p2LF_vs_reco_nocuts = (TProfile*) BNBMC->Get("hprof_cosp1p2LF_vs_reco_nocuts");
  TProfile* hprof_pT_vs_reco_nocuts = (TProfile*) BNBMC->Get("hprof_pT_vs_reco_nocuts");
  TProfile* hprof_p1_vs_reco_nocuts = (TProfile*) BNBMC->Get("hprof_p1_vs_reco_nocuts");
  TProfile* hprof_p2_vs_reco_nocuts = (TProfile*) BNBMC->Get("hprof_p2_vs_reco_nocuts");
  TProfile* hprof_pn_vs_reco_nocuts = (TProfile*) BNBMC->Get("hprof_pn_vs_reco_nocuts");
  TProfile* hprof_Enu_vs_reco_nocuts = (TProfile*) BNBMC->Get("hprof_Enu_vs_reco_nocuts");
  TProfile* hprof_Truthcospnp2CM_vs_reco_nocuts = (TProfile*) BNBMC->Get("hprof_Truthcospnp2CM_vs_reco_nocuts");
  TProfile* hprof_Truthcospnp2CM_vs_reco_nobtblowPT = (TProfile*) BNBMC->Get("hprof_Truthcospnp2CM_vs_reco_nobtblowPT");
  
  /// biases

  TProfile* hprof_p1_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p1_nobtblowPT");
  TProfile* hprof_p2_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p2_nobtblowPT");
  TProfile* hprof_pn_nobtblowPT = (TProfile*) BNBMC->Get("hprof_pn_nobtblowPT");
  TProfile* hprof_cosp1p2LF_nobtblowPT = (TProfile*) BNBMC->Get("hprof_cosp1p2LF_nobtblowPT");
  TProfile* hprof_pT_nobtblowPT = (TProfile*) BNBMC->Get("hprof_pT_nobtblowPT");
  TProfile* hprof_TruthEnu_nobtblowPT = (TProfile*) BNBMC->Get("hprof_TruthEnu_nobtblowPT");
  TProfile* hprof_q2_nobtblowPT = (TProfile*) BNBMC->Get("hprof_q2_nobtblowPT");
  TProfile* hprof_cospnp2CM_nobtblowPT = (TProfile*) BNBMC->Get("hprof_cospnp2CM_nobtblowPT");
  TProfile* hprof_Enu_nobtblowPT = (TProfile*) BNBMC->Get("hprof_Enu_nobtblowPT");
  TProfile* hprof_TruthEnucaloTrueGENIE_nobtblowPT = (TProfile*) BNBMC->Get("hprof_TruthEnucaloTrueGENIE_nobtblowPT");
  TProfile* hprof_Truthcospnp2CM_nobtblowPT = (TProfile*) BNBMC->Get("hprof_Truthcospnp2CM_nobtblowPT");
  TProfile* hprof_pmux_nobtblowPT = (TProfile*) BNBMC->Get("hprof_pmux_nobtblowPT");
  TProfile* hprof_p1x_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p1x_nobtblowPT");
  TProfile* hprof_p2x_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p2x_nobtblowPT");
  TProfile* hprof_pmuy_nobtblowPT = (TProfile*) BNBMC->Get("hprof_pmuy_nobtblowPT");
  TProfile* hprof_p1y_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p1y_nobtblowPT");
  TProfile* hprof_p2y_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p2y_nobtblowPT");
  TProfile* hprof_pmuz_nobtblowPT = (TProfile*) BNBMC->Get("hprof_pmuz_nobtblowPT");
  TProfile* hprof_p1z_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p1z_nobtblowPT");
  TProfile* hprof_p2z_nobtblowPT = (TProfile*) BNBMC->Get("hprof_p2z_nobtblowPT");
  TProfile* hprof_p1_nocuts = (TProfile*) BNBMC->Get("hprof_p1_nocuts");
  TProfile* hprof_p2_nocuts = (TProfile*) BNBMC->Get("hprof_p2_nocuts");
  TProfile* hprof_pn_nocuts = (TProfile*) BNBMC->Get("hprof_pn_nocuts");
  TProfile* hprof_cosp1p2LF_nocuts = (TProfile*) BNBMC->Get("hprof_cosp1p2LF_nocuts");
  TProfile* hprof_pT_nocuts = (TProfile*) BNBMC->Get("hprof_pT_nocuts");
  TProfile* hprof_TruthEnu_nocuts = (TProfile*) BNBMC->Get("hprof_TruthEnu_nocuts");
  TProfile* hprof_cospnp2CM_nocuts = (TProfile*) BNBMC->Get("hprof_cospnp2CM_nocuts");
  TProfile* hprof_Truthcospnp2CM_nocuts = (TProfile*) BNBMC->Get("hprof_Truthcospnp2CM_nocuts");
  TProfile* hprof_pmux_nocuts = (TProfile*) BNBMC->Get("hprof_pmux_nocuts");
  TProfile* hprof_p1x_nocuts = (TProfile*) BNBMC->Get("hprof_p1x_nocuts");
  TProfile* hprof_p2x_nocuts = (TProfile*) BNBMC->Get("hprof_p2x_nocuts");
  TProfile* hprof_pmuy_nocuts = (TProfile*) BNBMC->Get("hprof_pmuy_nocuts");
  TProfile* hprof_p1y_nocuts = (TProfile*) BNBMC->Get("hprof_p1y_nocuts");
  TProfile* hprof_p2y_nocuts = (TProfile*) BNBMC->Get("hprof_p2y_nocuts");
  TProfile* hprof_pmuz_nocuts = (TProfile*) BNBMC->Get("hprof_pmuz_nocuts");
  TProfile* hprof_p1z_nocuts = (TProfile*) BNBMC->Get("hprof_p1z_nocuts");
  TProfile* hprof_p2z_nocuts = (TProfile*) BNBMC->Get("hprof_p2z_nocuts");
  TProfile* hprof_Enu_nocuts = (TProfile*) BNBMC->Get("hprof_Enu_nocuts");
  TProfile* hprof_TruthEnucaloTrueGENIE_nocuts = (TProfile*) BNBMC->Get("hprof_TruthEnucaloTrueGENIE_nocuts");

  //// On-Beam data
  /*
  TH1D* reco_Enu_OnBeam_PID = (TH1D*) OnBeam->Get("reco_Enu_OnBeam_PID");
  TH1D* reco_PT_OnBeam_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_PID");
  TH1D* reco_p1p2_OnBeam_PID = (TH1D*) OnBeam->Get("reco_p1p2_OnBeam_PID");
  TH1D* reco_dp1p2_OnBeam_PID = (TH1D*) OnBeam->Get("reco_dp1p2_OnBeam_PID");
  TH1D* reco_kp1p2_OnBeam_PID = (TH1D*) OnBeam->Get("reco_kp1p2_OnBeam_PID");
  TH1D* reco_kp1p2_OnBeam_PID_btb = (TH1D*) OnBeam->Get("reco_kp1p2_OnBeam_PID_btb");
  TH1D* reco_PT_OnBeam_1binCM_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_1binCM_PID");
  TH1D* reco_pn_OnBeam_PID = (TH1D*) OnBeam->Get("reco_pn_OnBeam_PID");
  TH2D* p1p2_OnBeam_PID = (TH2D*) OnBeam->Get("p1p2_OnBeam_PID");
  TH2D* reco_angle_p1p2_p2_OnBeam_PID_LF = (TH2D*) OnBeam->Get("reco_angle_p1p2_p2_OnBeam_PID_LF");
  TH2D* reco_angle_p1p2_OnBeam_PID_LF_CM = (TH2D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_LF_CM");
  TH1D* reco_angle_p1p2_OnBeam_PID_LF = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_LF");
  TH1D* reco_angle_p1p2_OnBeam_PID_CM = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM");
  TH1D* reco_angle_p1p2_OnBeam_PID_LF_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_LF_zoom");
  TH1D* reco_angle_p1p2_OnBeam_PID_CM_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_zoom");
  TH1D* reco_angle_SRCrest_p1p2_OnBeam_PID_CM = (TH1D*) OnBeam->Get("reco_angle_SRCrest_p1p2_OnBeam_PID_CM");

  TH2D* reco_angle_p1p2_p2_OnBeam_PID_LF_btb = (TH2D*) OnBeam->Get("reco_angle_p1p2_p2_OnBeam_PID_LF_btb");
  TH1D* reco_angle_p1p2_OnBeam_PID_LF_btb = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_LF_btb");
  TH1D* reco_angle_p1p2_OnBeam_PID_CM_btb = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_btb");
  TH1D* reco_angle_p1p2_OnBeam_PID_LF_btb_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_LF_btb_zoom");
  TH1D* reco_angle_p1p2_OnBeam_PID_CM_btb_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_btb_zoom");

  TH1D* reco_PT_OnBeam_nobtbLF_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_nobtbLF_PID");
  TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom");
  TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM = (TH1D*) OnBeam->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM");

  /// opening angles
  TH1D* angle_p1p2_OnBeam_PID = (TH1D*) OnBeam->Get("angle_p1p2_OnBeam_PID");
  */
  //// Off-Beam data
  /*
  TH1D* reco_Enu_OffBeam_PID = (TH1D*) OffBeam->Get("reco_Enu_OffBeam_PID");
  TH1D* reco_PT_OffBeam_PID = (TH1D*) OffBeam->Get("reco_PT_OffBeam_PID");
  TH1D* reco_p1p2_OffBeam_PID = (TH1D*) OffBeam->Get("reco_p1p2_OffBeam_PID");
  TH1D* reco_dp1p2_OffBeam_PID = (TH1D*) OffBeam->Get("reco_dp1p2_OffBeam_PID");
  TH1D* reco_kp1p2_OffBeam_PID = (TH1D*) OffBeam->Get("reco_kp1p2_OffBeam_PID");
  TH1D* reco_kp1p2_OffBeam_PID_btb = (TH1D*) OffBeam->Get("reco_kp1p2_OffBeam_PID_btb");
  TH1D* reco_PT_OffBeam_1binCM_PID = (TH1D*) OffBeam->Get("reco_PT_OffBeam_1binCM_PID");
  TH1D* reco_pn_OffBeam_PID = (TH1D*) OffBeam->Get("reco_pn_OffBeam_PID");
  TH2D* p1p2_OffBeam_PID = (TH2D*) OffBeam->Get("p1p2_OffBeam_PID");
  TH2D* reco_angle_p1p2_p2_OffBeam_PID_LF = (TH2D*) OffBeam->Get("reco_angle_p1p2_p2_OffBeam_PID_LF");
  TH2D* reco_angle_p1p2_OffBeam_PID_LF_CM = (TH2D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_LF_CM");
  TH1D* reco_angle_p1p2_OffBeam_PID_LF = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_LF");
  TH1D* reco_angle_p1p2_OffBeam_PID_CM = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_CM");
  TH1D* reco_angle_SRCrest_p1p2_OffBeam_PID_CM = (TH1D*) OffBeam->Get("reco_angle_SRCrest_p1p2_OffBeam_PID_CM");
  TH1D* reco_angle_p1p2_OffBeam_PID_LF_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_LF_zoom");
  TH1D* reco_angle_p1p2_OffBeam_PID_CM_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_CM_zoom");

  TH2D* reco_angle_p1p2_p2_OffBeam_PID_LF_btb = (TH2D*) OffBeam->Get("reco_angle_p1p2_p2_OffBeam_PID_LF_btb");
  TH1D* reco_angle_p1p2_OffBeam_PID_LF_btb = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_LF_btb");
  TH1D* reco_angle_p1p2_OffBeam_PID_CM_btb = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_CM_btb");
  TH1D* reco_angle_p1p2_OffBeam_PID_LF_btb_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_LF_btb_zoom");
  TH1D* reco_angle_p1p2_OffBeam_PID_CM_btb_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_CM_btb_zoom");

  TH1D* reco_PT_OffBeam_nobtbLF_PID = (TH1D*) OffBeam->Get("reco_PT_OffBeam_nobtbLF_PID");
  TH1D* reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom");
  TH1D* reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_OffBeam_PID_CM = (TH1D*) OffBeam->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_OffBeam_PID_CM");

  /// opening angles
 
  TH1D* angle_p1p2_OffBeam_PID = (TH1D*) OffBeam->Get("angle_p1p2_OffBeam_PID");
  */
  /// valores de las normalizaciones

  //Double_t normMCBNB =  (4.411e+19)/(4.0878e+20);//tune 3
  //Double_t normMCBNB =  (4.411e+19)/(2.010e+20);//(4.874e+19)/(1.566e+20);/// public note
  Double_t normMCBNB =  (1.562e+20)/(4.0878e+20); //(4.874e+19)/(1.566e+20);/// paper
  ///Double_t normOffBeam = 9775610./73710197.;  //0.1464;//(33320382.)/(36177265.);// public note
  Double_t normOffBeam = 35388924./73710197.;  //0.1464;//(33320382.)/(36177265.);//paper

  //Double_t normOffBeam = 9775610./35789730.;  //0.1464;//(33320382.)/(36177265.);
  //h->Scale(1/norm);

  //  Double_t global = 0.547177;
  // normMCBNB =  normMCBNB*global;
  //normOffBeam = normOffBeam*global; 
  //  normMCBNB =  0.11947;

  /// normalizing MC
  std::cout<<"antes del scale"<<std::endl;
  std::cout<<"normMCBNB : "<<normMCBNB<<std::endl;
  std::cout<<"normOffBeam : "<<normOffBeam<<std::endl;

  //normalizar solo 1D
  

  /// proton 1
  /*
  selproton1_costheta_CC0Pion0Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_CC0Pion1Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_CC0Pion2Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_CC0PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_CC1PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_CCNPionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_CCNue_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_NC_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_OOFV_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_EXT_PID_Tune3->Scale(normMCBNB);
  selproton1_costheta_other_PID_Tune3->Scale(normMCBNB);

  */

  /// Off beam data normalization
 
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
  gStyle->SetTitleSize(0.05,"X");
  gStyle->SetTitleFont(62,"X");
  gStyle->SetTitleOffset(0.85,"X");
  gStyle->SetLabelSize(0.04,"Y");
  gStyle->SetLabelFont(62,"Y");
  gStyle->SetTitleSize(0.06,"Y");
  gStyle->SetTitleFont(62,"Y");
  gStyle->SetTitleOffset(0.8,"Y");
  gStyle->SetTitleX(0.22);
  gStyle->SetTitleY(0.98);
  gStyle->SetTitleSize(0.04,"t");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderSize(0);
  //gStyle->SetPadGridY(kTRUE);

  std::cout<<"antes de los plots"<<std::endl;  

  double chi2test =0.0;
  int canvas=0;



  TCanvas *c1 = new TCanvas("c1","",900, 900);

   c1->SetGrid();
   hprof_cosp1p2LF_vs_reco_nocuts->SetTitle("");
   hprof_cosp1p2LF_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed cos #theta_{p1p2} lab frame");
   hprof_cosp1p2LF_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) cos #theta_{p1p2} lab frame");
   hprof_cosp1p2LF_vs_reco_nocuts->SetLineColor(kRed);
   hprof_cosp1p2LF_vs_reco_nocuts->SetLineWidth(2);
   hprof_cosp1p2LF_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_cosp1p2LF_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_cosp1p2LF_vs_reco_nocuts->Draw();

   c1->Update();
   c1-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_300/Error_cosp1p2LF_nocuts.pdf");


  /*
  TCanvas *c36 = new TCanvas("c36", "c36", 900, 900);
  TPad *pad36 = new TPad("pad36", "pad36", 0, 0.3, 1, 1.0);
  pad36->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad36->Draw();             // Draw the upper pad: pad1
  pad36->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(31);
  reco_angle_p1p2_other_nobtbLF_PT_PID_Tune3_CM_zoom-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom-> SetFillColor(kGray);

  THStack *reco_angle_LFbtbPT_p1p2_PID_Tune3 = new THStack("reco_angle_LFbtbPT_p1p2_PID_Tune3","");
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCQE_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCRes_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCCoh_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCDIS_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCMEC_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCNue_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_NC_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_other_nobtbLF_PT_PID_Tune3_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Add(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom);
  reco_angle_LFbtbPT_p1p2_PID_Tune3->SetMaximum(100.);
  reco_angle_LFbtbPT_p1p2_PID_Tune3-> Draw();
  reco_angle_LFbtbPT_p1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Draw("e1same");

  TLegend *l36 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l36 -> SetNColumns(2);
  l36 -> AddEntry(reco_angle_p1p2_CCQE_nobtbLF_PT_PID_Tune3_CM_zoom, "CCQE", "f");
  l36 -> AddEntry(reco_angle_p1p2_CCRes_nobtbLF_PT_PID_Tune3_CM_zoom, "CCRes", "f");
  l36 -> AddEntry(reco_angle_p1p2_CCCoh_nobtbLF_PT_PID_Tune3_CM_zoom, "CCCoh", "f");
  l36 -> AddEntry(reco_angle_p1p2_CCDIS_nobtbLF_PT_PID_Tune3_CM_zoom, "DIS", "f");
  l36 -> AddEntry(reco_angle_p1p2_CCMEC_nobtbLF_PT_PID_Tune3_CM_zoom, "CCMEC", "f");
  l36 -> AddEntry(reco_angle_p1p2_CCNue_nobtbLF_PT_PID_Tune3_CM_zoom, "CC#nu_{e}", "f");
  l36 -> AddEntry(reco_angle_p1p2_NC_nobtbLF_PT_PID_Tune3_CM_zoom, "NC", "f");
  l36 -> AddEntry(reco_angle_p1p2_other_nobtbLF_PT_PID_Tune3_CM_zoom, "other", "f");

  l36 -> AddEntry(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom, "off-beam data", "f");
  l36 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom, "on-beam data", "lep");
  l36 -> Draw();  
  
  TText *t36 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t36->Draw();

  c36->cd();
  TPad *pad36_2 = new TPad("pad36_2", "pad36_2", 0, 0.05, 1, 0.3);
  pad36_2->SetTopMargin(0.01);
  pad36_2->SetBottomMargin(0.2);
  pad36_2->SetGridx();
  pad36_2->SetGridy();
  pad36_2->Draw();
  pad36_2->cd();
  // Define the ratio plot
  TH1F *h36 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Clone("h36");
  TH1 *last36 = (TH1*)reco_angle_LFbtbPT_p1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last36,reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom, reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cos thetaCM (p1= p2) chi2test : "<<chi2test<<std::endl;

  h36->SetLineColor(kBlack);
  h36->Sumw2();
  h36->SetStats(0);      // No statistics on lower plot
  h36->Divide(last36);
  h36->SetMarkerStyle(21);
  h36->SetTitle("");
  h36->Draw("ep");       // Draw the ratio plot

  h36->GetYaxis()->SetTitle("Data/MC");
  h36->GetYaxis()->SetNdivisions(505);
  h36->GetYaxis()->SetTitleSize(20);
  h36->GetYaxis()->SetTitleFont(43);
  h36->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h36->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h36->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h36->GetXaxis()->SetTitleSize(20);
  h36->GetXaxis()->SetTitleFont(43);
  h36->GetXaxis()->SetTitleOffset(3.);
  h36->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h36->GetXaxis()->SetLabelSize(15);

  c36->Update();
  c36->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/costhetaCM_LFbtbPT_PID_Tune3.pdf"); 
  */
}
