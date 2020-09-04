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
       // if(N_BNB[ii]<5 || N_MC[ii]<5 || N_EXTBNB[ii]) 
       //std::cout<<"N_BNB[ii] "<<N_BNB[ii]<<" N_MC[ii] "<<N_MC[ii]*norm_MC<<" N_EXTBNB[ii] "<<N_EXTBNB[ii]*scale_offbeam<<std::endl;
       //std::cout<<"N_BNB[ii] "<<N_BNB[ii]<<" N_MC[ii] "<<N_MC[ii]<<" N_EXTBNB[ii] "<<N_EXTBNB[ii]<<std::endl;
//Chi2 +=pow((N_MC[ii]*norm_MC+N_EXTBNB[ii]*scale_offbeam-N_BNB[ii]),2)/(N_MC[ii]*norm_MC +N_EXTBNB[ii]*scale_offbeam);
       Chi2 +=pow((N_MC[ii]+N_EXTBNB[ii]-N_BNB[ii]),2)/(N_MC[ii] +N_EXTBNB[ii]);
 //std::cout<<"  chi2test : "<<Chi2<<std::endl;
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

void DataMC_PID_angles_Tune3(){ 
  
  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_Tune3_BNBMC.root","READ");
  TFile* OnBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OnBeam.root","READ");
  TFile* OffBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OffBeam.root","READ");

  std::cout<<"antes de Tfile"<<std::endl;
  
  ofstream outfileDataMC_PID_Tune3;
  // outfileDataMC_PID_300.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/chi2_2P_DataMC_300.txt");
  outfileDataMC_PID_Tune3.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/chi2_2P_DataMC_angles_Tune3.txt");
  ////// BNB MC

  TH1D* reco_Enu_CCQE_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_CCQE_PID_Tune3");
  TH1D* reco_Enu_CCRes_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_CCRes_PID_Tune3");
  TH1D* reco_Enu_CCCoh_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_CCCoh_PID_Tune3");
  TH1D* reco_Enu_CCDIS_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_CCDIS_PID_Tune3");
  TH1D* reco_Enu_CCMEC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_CCMEC_PID_Tune3");
  TH1D* reco_Enu_CCNue_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_CCNue_PID_Tune3");
  TH1D* reco_Enu_NC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_NC_PID_Tune3");
  TH1D* reco_Enu_other_PID_Tune3 = (TH1D*) BNBMC->Get("reco_Enu_other_PID_Tune3");

  TH1D* reco_PT_CCQE_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCQE_PID_Tune3");
  TH1D* reco_PT_CCRes_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCRes_PID_Tune3");
  TH1D* reco_PT_CCCoh_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCCoh_PID_Tune3");
  TH1D* reco_PT_CCDIS_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCDIS_PID_Tune3");
  TH1D* reco_PT_CCMEC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCMEC_PID_Tune3");
  TH1D* reco_PT_CCNue_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCNue_PID_Tune3");
  TH1D* reco_PT_NC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_NC_PID_Tune3");
  TH1D* reco_PT_other_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_other_PID_Tune3");

  TH1D* reco_p1p2_CCQE_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_CCQE_PID_Tune3");
  TH1D* reco_p1p2_CCRes_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_CCRes_PID_Tune3");
  TH1D* reco_p1p2_CCCoh_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_CCCoh_PID_Tune3");
  TH1D* reco_p1p2_CCDIS_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_CCDIS_PID_Tune3");
  TH1D* reco_p1p2_CCMEC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_CCMEC_PID_Tune3");
  TH1D* reco_p1p2_CCNue_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_CCNue_PID_Tune3");
  TH1D* reco_p1p2_NC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_NC_PID_Tune3");
  TH1D* reco_p1p2_other_PID_Tune3 = (TH1D*) BNBMC->Get("reco_p1p2_other_PID_Tune3");

  TH1D* reco_dp1p2_CCQE_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_CCQE_PID_Tune3");
  TH1D* reco_dp1p2_CCRes_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_CCRes_PID_Tune3");
  TH1D* reco_dp1p2_CCCoh_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_CCCoh_PID_Tune3");
  TH1D* reco_dp1p2_CCDIS_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_CCDIS_PID_Tune3");
  TH1D* reco_dp1p2_CCMEC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_CCMEC_PID_Tune3");
  TH1D* reco_dp1p2_CCNue_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_CCNue_PID_Tune3");
  TH1D* reco_dp1p2_NC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_NC_PID_Tune3");
  TH1D* reco_dp1p2_other_PID_Tune3 = (TH1D*) BNBMC->Get("reco_dp1p2_other_PID_Tune3");

  TH1D* reco_kp1p2_CCQE_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_CCQE_PID_Tune3");
  TH1D* reco_kp1p2_CCRes_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_CCRes_PID_Tune3");
  TH1D* reco_kp1p2_CCCoh_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_CCCoh_PID_Tune3");
  TH1D* reco_kp1p2_CCDIS_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_CCDIS_PID_Tune3");
  TH1D* reco_kp1p2_CCMEC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_CCMEC_PID_Tune3");
  TH1D* reco_kp1p2_CCNue_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_CCNue_PID_Tune3");
  TH1D* reco_kp1p2_NC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_NC_PID_Tune3");
  TH1D* reco_kp1p2_other_PID_Tune3 = (TH1D*) BNBMC->Get("reco_kp1p2_other_PID_Tune3");

  TH1D* reco_kp1p2_CCQE_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_CCQE_PID_Tune3_btb");
  TH1D* reco_kp1p2_CCRes_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_CCRes_PID_Tune3_btb");
  TH1D* reco_kp1p2_CCCoh_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_CCCoh_PID_Tune3_btb");
  TH1D* reco_kp1p2_CCDIS_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_CCDIS_PID_Tune3_btb");
  TH1D* reco_kp1p2_CCMEC_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_CCMEC_PID_Tune3_btb");
  TH1D* reco_kp1p2_CCNue_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_CCNue_PID_Tune3_btb");
  TH1D* reco_kp1p2_NC_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_NC_PID_Tune3_btb");
  TH1D* reco_kp1p2_other_PID_Tune3_btb = (TH1D*) BNBMC->Get("reco_kp1p2_other_PID_Tune3_btb");

  TH1D* reco_PT_CCQE_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCQE_1binCM_PID_Tune3");
  TH1D* reco_PT_CCRes_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCRes_1binCM_PID_Tune3");
  TH1D* reco_PT_CCCoh_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCCoh_1binCM_PID_Tune3");
  TH1D* reco_PT_CCDIS_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCDIS_1binCM_PID_Tune3");
  TH1D* reco_PT_CCMEC_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCMEC_1binCM_PID_Tune3");
  TH1D* reco_PT_CCNue_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCNue_1binCM_PID_Tune3");
  TH1D* reco_PT_NC_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_NC_1binCM_PID_Tune3");
  TH1D* reco_PT_other_1binCM_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_other_1binCM_PID_Tune3");
  
  TH1D* reco_pn_CCQE_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_CCQE_PID_Tune3");
  TH1D* reco_pn_CCRes_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_CCRes_PID_Tune3");
  TH1D* reco_pn_CCCoh_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_CCCoh_PID_Tune3");
  TH1D* reco_pn_CCDIS_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_CCDIS_PID_Tune3");
  TH1D* reco_pn_CCMEC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_CCMEC_PID_Tune3");
  TH1D* reco_pn_CCNue_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_CCNue_PID_Tune3");
  TH1D* reco_pn_NC_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_NC_PID_Tune3");
  TH1D* reco_pn_other_PID_Tune3 = (TH1D*) BNBMC->Get("reco_pn_other_PID_Tune3");

  TH2D* p1p2_PID_Tune3 = (TH2D*) BNBMC->Get("p1p2_PID_Tune3");
  TH2D* reco_angle_p1p2_p2_PID_Tune3_LF = (TH2D*) BNBMC->Get("reco_angle_p1p2_p2_PID_Tune3_LF");
  TH2D* reco_angle_p1p2_PID_Tune3_LF_CM = (TH2D*) BNBMC->Get("reco_angle_p1p2_PID_Tune3_LF_CM");

  TH2D* reco_angle_p1p2_p2_PID_Tune3_LF_btb = (TH2D*) BNBMC->Get("reco_angle_p1p2_p2_PID_Tune3_LF_btb");

  /// opening angle lab frame

  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_LF");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_LF");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_LF");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_LF");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_LF");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_LF");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_LF");
  TH1D* reco_angle_p1p2_other_PID_Tune3_LF = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_LF");

  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_LF_btb");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_LF_btb");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_LF_btb");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_LF_btb");
  TH1D* reco_angle_p1p2_other_PID_Tune3_LF_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_LF_btb");
  
  ///
  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_LF_zoom");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_LF_zoom");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_LF_zoom");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_LF_zoom");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_LF_zoom");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_LF_zoom");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_LF_zoom");
  TH1D* reco_angle_p1p2_other_PID_Tune3_LF_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_LF_zoom");

  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_LF_btb_zoom");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_LF_btb_zoom");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb_zoom");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb_zoom");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb_zoom");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_LF_btb_zoom");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_LF_btb_zoom");
  TH1D* reco_angle_p1p2_other_PID_Tune3_LF_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_LF_btb_zoom");
  

  //// Opening angles in CM/// pn= p_p1 -q_3 (vector), q from Evis and muon kinematics--opeing angle between nucleon reco and recoil proton in the np initial pair, p>Tune3

  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_CM_btb");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_CM_btb");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_CM_btb");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_CM_btb");
  TH1D* reco_angle_p1p2_other_PID_Tune3_CM_btb = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_CM_btb");

  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_CM");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_CM");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_CM");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_CM");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_CM");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_CM");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_CM");
  TH1D* reco_angle_p1p2_other_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_CM");
  /////////

  TH1D* reco_angle_SRCrest_p1p2_CCQE_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_CCQE_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_p1p2_CCRes_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_CCRes_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_p1p2_CCCoh_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_CCCoh_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_p1p2_CCDIS_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_CCDIS_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_p1p2_CCMEC_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_CCMEC_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_p1p2_CCNue_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_CCNue_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_p1p2_NC_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_NC_PID_Tune3_CM");
  //TH1D* reco_angle_SRCrest_p1p2_other_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_p1p2_other_PID_Tune3_CM");

  ///
  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_CM_btb_zoom");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_CM_btb_zoom");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb_zoom");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb_zoom");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb_zoom");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_CM_btb_zoom");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_CM_btb_zoom");
  TH1D* reco_angle_p1p2_other_PID_Tune3_CM_btb_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_CM_btb_zoom");

  TH1D* reco_angle_p1p2_CCQE_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCRes_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCCoh_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCDIS_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCMEC_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCNue_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_NC_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_other_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_PID_Tune3_CM_zoom");
  
  ///// opening angles

  TH1D* angle_p1p2_CC0Pion0Proton_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_CC0Pion0Proton_PID_Tune3");
  TH1D* angle_p1p2_CC0Pion1Proton_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_CC0Pion1Proton_PID_Tune3");
  TH1D* angle_p1p2_CC0Pion2Proton_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_CC0Pion2Proton_PID_Tune3");
  TH1D* angle_p1p2_CC0PionNProton_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_CC0PionNProton_PID_Tune3");
  TH1D* angle_p1p2_CC1PionNProton_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_CC1PionNProton_PID_Tune3");
  TH1D* angle_p1p2_CCNPionNProton_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_CCNPionNProton_PID_Tune3");
  TH1D* angle_p1p2_CCNue_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_CCNue_PID_Tune3");
  TH1D* angle_p1p2_NC_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_NC_PID_Tune3");
  TH1D* angle_p1p2_OOFV_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_OOFV_PID_Tune3");
  TH1D* angle_p1p2_EXT_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_EXT_PID_Tune3");
  TH1D* angle_p1p2_other_PID_Tune3 = (TH1D*) BNBMC->Get("angle_p1p2_other_PID_Tune3");


  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_CCQE_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_CCQE_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_CCRes_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_CCRes_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_CCCoh_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_CCCoh_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_CCDIS_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_CCDIS_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_CCMEC_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_CCMEC_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_CCNue_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_CCNue_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_NC_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_NC_PID_Tune3_CM");
  TH1D* reco_angle_SRCrest_PT_LFbtb_p1p2_other_PID_Tune3_CM = (TH1D*) BNBMC->Get("reco_angle_SRCrest_PT_LFbtb_p1p2_other_PID_Tune3_CM");

  TH1D* reco_PT_CCQE_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCQE_nobtbLF_PID_Tune3");
  TH1D* reco_PT_CCRes_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCRes_nobtbLF_PID_Tune3");
  TH1D* reco_PT_CCCoh_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCCoh_nobtbLF_PID_Tune3");
  TH1D* reco_PT_CCDIS_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCDIS_nobtbLF_PID_Tune3");
  TH1D* reco_PT_CCMEC_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCMEC_nobtbLF_PID_Tune3");
  TH1D* reco_PT_CCNue_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_CCNue_nobtbLF_PID_Tune3");
  TH1D* reco_PT_NC_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_NC_nobtbLF_PID_Tune3");
  TH1D* reco_PT_other_nobtbLF_PID_Tune3 = (TH1D*) BNBMC->Get("reco_PT_other_nobtbLF_PID_Tune3");

  TH1D* reco_angle_p1p2_CCQE_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_nobtbLF_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCRes_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_nobtbLF_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCCoh_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_nobtbLF_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCDIS_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_nobtbLF_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCMEC_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_nobtbLF_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCNue_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_nobtbLF_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_NC_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_nobtbLF_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_other_nobtbLF_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_nobtbLF_PID_Tune3_CM_zoom");

  TH1D* reco_angle_p1p2_CCQE_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCQE_nobtbLF_PT_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCRes_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCRes_nobtbLF_PT_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCCoh_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCCoh_nobtbLF_PT_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCDIS_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCDIS_nobtbLF_PT_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCMEC_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCMEC_nobtbLF_PT_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_CCNue_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_CCNue_nobtbLF_PT_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_NC_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_NC_nobtbLF_PT_PID_Tune3_CM_zoom");
  TH1D* reco_angle_p1p2_other_nobtbLF_PT_PID_Tune3_CM_zoom = (TH1D*) BNBMC->Get("reco_angle_p1p2_other_nobtbLF_PT_PID_Tune3_CM_zoom");

  ///// resolutions (MC)
  TH2D* res_Enu_PID_Tune3 = (TH2D*) BNBMC->Get("res_Enu_PID_Tune3");
  
  //// On-Beam data

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

  //// Off-Beam data

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
  
  selproton1_phi_CC0Pion0Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_CC0Pion1Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_CC0Pion2Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_CC0PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_CC1PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_CCNPionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_CCNue_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_NC_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_OOFV_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_EXT_PID_Tune3->Scale(normMCBNB);
  selproton1_phi_other_PID_Tune3->Scale(normMCBNB);

  selproton1_mom_CC0Pion0Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_CC0Pion1Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_CC0Pion2Proton_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_CC0PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_CC1PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_CCNPionNProton_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_CCNue_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_NC_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_OOFV_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_EXT_PID_Tune3->Scale(normMCBNB);
  selproton1_mom_other_PID_Tune3->Scale(normMCBNB);
  */
  /// proton 2
  /*
  selproton2_costheta_CC0Pion0Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_CC0Pion1Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_CC0Pion2Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_CC0PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_CC1PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_CCNPionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_CCNue_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_NC_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_OOFV_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_EXT_PID_Tune3->Scale(normMCBNB);
  selproton2_costheta_other_PID_Tune3->Scale(normMCBNB);

  selproton2_phi_CC0Pion0Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_CC0Pion1Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_CC0Pion2Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_CC0PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_CC1PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_CCNPionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_CCNue_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_NC_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_OOFV_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_EXT_PID_Tune3->Scale(normMCBNB);
  selproton2_phi_other_PID_Tune3->Scale(normMCBNB);

  selproton2_mom_CC0Pion0Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_CC0Pion1Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_CC0Pion2Proton_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_CC0PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_CC1PionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_CCNPionNProton_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_CCNue_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_NC_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_OOFV_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_EXT_PID_Tune3->Scale(normMCBNB);
  selproton2_mom_other_PID_Tune3->Scale(normMCBNB);
  */

  //std::cout<<"hola 1"<<std::endl;
  angle_p1p2_CC0Pion0Proton_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_CC0Pion1Proton_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_CC0Pion2Proton_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_CC0PionNProton_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_CC1PionNProton_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_CCNPionNProton_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_CCNue_PID_Tune3->Scale(normMCBNB);;
  angle_p1p2_NC_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_OOFV_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_EXT_PID_Tune3->Scale(normMCBNB);
  angle_p1p2_other_PID_Tune3->Scale(normMCBNB);

  /// *** nuevos histos

  reco_Enu_CCQE_PID_Tune3->Scale(normMCBNB);
  reco_Enu_CCRes_PID_Tune3->Scale(normMCBNB);
  reco_Enu_CCCoh_PID_Tune3->Scale(normMCBNB);
  reco_Enu_CCDIS_PID_Tune3->Scale(normMCBNB);
  reco_Enu_CCMEC_PID_Tune3->Scale(normMCBNB);
  reco_Enu_CCNue_PID_Tune3->Scale(normMCBNB);
  reco_Enu_NC_PID_Tune3->Scale(normMCBNB);
  reco_Enu_other_PID_Tune3->Scale(normMCBNB);

  reco_PT_CCQE_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCRes_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCCoh_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCDIS_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCMEC_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCNue_PID_Tune3->Scale(normMCBNB);
  reco_PT_NC_PID_Tune3->Scale(normMCBNB);
  reco_PT_other_PID_Tune3->Scale(normMCBNB);

  reco_PT_CCQE_1binCM_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCRes_1binCM_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCCoh_1binCM_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCDIS_1binCM_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCMEC_1binCM_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCNue_1binCM_PID_Tune3->Scale(normMCBNB);
  reco_PT_NC_1binCM_PID_Tune3->Scale(normMCBNB);
  reco_PT_other_1binCM_PID_Tune3->Scale(normMCBNB);

  reco_pn_CCQE_PID_Tune3->Scale(normMCBNB);
  reco_pn_CCRes_PID_Tune3->Scale(normMCBNB);
  reco_pn_CCCoh_PID_Tune3->Scale(normMCBNB);
  reco_pn_CCDIS_PID_Tune3->Scale(normMCBNB);
  reco_pn_CCMEC_PID_Tune3->Scale(normMCBNB);
  reco_pn_CCNue_PID_Tune3->Scale(normMCBNB);
  reco_pn_NC_PID_Tune3->Scale(normMCBNB);
  reco_pn_other_PID_Tune3->Scale(normMCBNB);

  reco_p1p2_CCQE_PID_Tune3->Scale(normMCBNB);
  reco_p1p2_CCRes_PID_Tune3->Scale(normMCBNB);
  reco_p1p2_CCCoh_PID_Tune3->Scale(normMCBNB);
  reco_p1p2_CCDIS_PID_Tune3->Scale(normMCBNB);
  reco_p1p2_CCMEC_PID_Tune3->Scale(normMCBNB);
  reco_p1p2_CCNue_PID_Tune3->Scale(normMCBNB);
  reco_p1p2_NC_PID_Tune3->Scale(normMCBNB);
  reco_p1p2_other_PID_Tune3->Scale(normMCBNB);

  reco_dp1p2_CCQE_PID_Tune3->Scale(normMCBNB);
  reco_dp1p2_CCRes_PID_Tune3->Scale(normMCBNB);
  reco_dp1p2_CCCoh_PID_Tune3->Scale(normMCBNB);
  reco_dp1p2_CCDIS_PID_Tune3->Scale(normMCBNB);
  reco_dp1p2_CCMEC_PID_Tune3->Scale(normMCBNB);
  reco_dp1p2_CCNue_PID_Tune3->Scale(normMCBNB);
  reco_dp1p2_NC_PID_Tune3->Scale(normMCBNB);
  reco_dp1p2_other_PID_Tune3->Scale(normMCBNB);

  reco_kp1p2_CCQE_PID_Tune3->Scale(normMCBNB);
  reco_kp1p2_CCRes_PID_Tune3->Scale(normMCBNB);
  reco_kp1p2_CCCoh_PID_Tune3->Scale(normMCBNB);
  reco_kp1p2_CCDIS_PID_Tune3->Scale(normMCBNB);
  reco_kp1p2_CCMEC_PID_Tune3->Scale(normMCBNB);
  reco_kp1p2_CCNue_PID_Tune3->Scale(normMCBNB);
  reco_kp1p2_NC_PID_Tune3->Scale(normMCBNB);
  reco_kp1p2_other_PID_Tune3->Scale(normMCBNB);

  reco_kp1p2_CCQE_PID_Tune3_btb->Scale(normMCBNB);
  reco_kp1p2_CCRes_PID_Tune3_btb->Scale(normMCBNB);
  reco_kp1p2_CCCoh_PID_Tune3_btb->Scale(normMCBNB);
  reco_kp1p2_CCDIS_PID_Tune3_btb->Scale(normMCBNB);
  reco_kp1p2_CCMEC_PID_Tune3_btb->Scale(normMCBNB);
  reco_kp1p2_CCNue_PID_Tune3_btb->Scale(normMCBNB);
  reco_kp1p2_NC_PID_Tune3_btb->Scale(normMCBNB);
  reco_kp1p2_other_PID_Tune3_btb->Scale(normMCBNB);

  reco_angle_p1p2_CCQE_PID_Tune3_LF->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_LF->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_LF->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_LF->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_LF->Scale(normMCBNB);

  reco_angle_p1p2_CCQE_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_CM->Scale(normMCBNB);

  reco_angle_SRCrest_p1p2_CCQE_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_p1p2_CCRes_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_p1p2_CCCoh_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_p1p2_CCDIS_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_p1p2_CCMEC_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_p1p2_CCNue_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_p1p2_NC_PID_Tune3_CM->Scale(normMCBNB);
  //reco_angle_SRCrest_p1p2_other_PID_Tune3_CM->Scale(normMCBNB);
  //
 
  reco_angle_p1p2_CCQE_PID_Tune3_LF_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_LF_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_LF_zoom->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_LF_zoom->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_LF_zoom->Scale(normMCBNB);

  reco_angle_p1p2_CCQE_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_CM_zoom->Scale(normMCBNB);
  //
  reco_angle_p1p2_CCQE_PID_Tune3_LF_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_LF_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_LF_btb->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_LF_btb->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_LF_btb->Scale(normMCBNB);

  reco_angle_p1p2_CCQE_PID_Tune3_CM_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_CM_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_CM_btb->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_CM_btb->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_CM_btb->Scale(normMCBNB);
  ////
  reco_angle_p1p2_CCQE_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_LF_btb_zoom->Scale(normMCBNB);

  reco_angle_p1p2_CCQE_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_NC_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);
  reco_angle_p1p2_other_PID_Tune3_CM_btb_zoom->Scale(normMCBNB);


  reco_angle_SRCrest_PT_LFbtb_p1p2_CCQE_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCRes_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCCoh_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCDIS_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCMEC_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCNue_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_PT_LFbtb_p1p2_NC_PID_Tune3_CM->Scale(normMCBNB);
  reco_angle_SRCrest_PT_LFbtb_p1p2_other_PID_Tune3_CM->Scale(normMCBNB);

  reco_PT_CCQE_nobtbLF_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCRes_nobtbLF_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCCoh_nobtbLF_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCDIS_nobtbLF_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCMEC_nobtbLF_PID_Tune3->Scale(normMCBNB);
  reco_PT_CCNue_nobtbLF_PID_Tune3->Scale(normMCBNB);
  reco_PT_NC_nobtbLF_PID_Tune3->Scale(normMCBNB);
  reco_PT_other_nobtbLF_PID_Tune3->Scale(normMCBNB);

  reco_angle_p1p2_CCQE_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCRes_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_NC_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_other_nobtbLF_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCQE_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);

  reco_angle_p1p2_CCRes_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCCoh_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCDIS_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCMEC_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_CCNue_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_NC_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);
  reco_angle_p1p2_other_nobtbLF_PT_PID_Tune3_CM_zoom->Scale(normMCBNB);

  /// Off beam data normalization
 
  ////proton 1
  /*
  selproton1_costheta_OffBeam_PID->Scale(normOffBeam);
  selproton1_phi_OffBeam_PID->Scale(normOffBeam);
  selproton1_mom_OffBeam_PID->Scale(normOffBeam);

  //////////////// proton 2

  selproton2_costheta_OffBeam_PID->Scale(normOffBeam);
  selproton2_phi_OffBeam_PID->Scale(normOffBeam);
  selproton2_mom_OffBeam_PID->Scale(normOffBeam);
  */
  angle_p1p2_OffBeam_PID->Scale(normOffBeam);

  reco_Enu_OffBeam_PID->Scale(normOffBeam);
  reco_PT_OffBeam_PID->Scale(normOffBeam);
  reco_PT_OffBeam_1binCM_PID->Scale(normOffBeam);
  reco_pn_OffBeam_PID->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_PID_LF->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_PID_CM->Scale(normOffBeam);
  reco_angle_SRCrest_p1p2_OffBeam_PID_CM->Scale(normOffBeam);
  std::cout<<"despues de escalar MC"<<std::endl;
  reco_p1p2_OffBeam_PID->Scale(normOffBeam);
  reco_dp1p2_OffBeam_PID->Scale(normOffBeam);
  reco_kp1p2_OffBeam_PID->Scale(normOffBeam);
  reco_kp1p2_OffBeam_PID_btb->Scale(normOffBeam);

  reco_angle_p1p2_OffBeam_PID_LF_btb->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_PID_CM_btb->Scale(normOffBeam);

  reco_angle_p1p2_OffBeam_PID_LF_zoom->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_PID_CM_zoom->Scale(normOffBeam);

  reco_angle_p1p2_OffBeam_PID_LF_btb_zoom->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_PID_CM_btb_zoom->Scale(normOffBeam);

  reco_PT_OffBeam_nobtbLF_PID->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom->Scale(normOffBeam);
  reco_angle_SRCrest_PT_LFbtb_p1p2_OffBeam_PID_CM->Scale(normOffBeam);
  
 std::cout<<"hola 1"<<std::endl;

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
  /*
  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();              // pad1 becomes the current pad

  selproton1_costheta_CC0Pion0Proton_PID_Tune3-> SetFillColor(kRed -10);
  selproton1_costheta_CC0Pion1Proton_PID_Tune3-> SetFillColor(kGreen-8);
  selproton1_costheta_CC0Pion2Proton_PID_Tune3-> SetFillColor(kAzure+4);
  selproton1_costheta_CC0PionNProton_PID_Tune3-> SetFillColor(kRed-9);
  selproton1_costheta_CC1PionNProton_PID_Tune3-> SetFillColor(kOrange);
  selproton1_costheta_CCNPionNProton_PID_Tune3-> SetFillColor(kCyan-8);
  selproton1_costheta_CCNue_PID_Tune3-> SetFillColor(31);
  selproton1_costheta_NC_PID_Tune3-> SetFillColor(kOrange+6);
  selproton1_costheta_OOFV_PID_Tune3-> SetFillColor(kYellow+2);
  selproton1_costheta_EXT_PID_Tune3-> SetFillColor(kBlack);
  selproton1_costheta_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_Tune3-> SetFillColor(kRed);

  THStack *selproton1_costheta_PID_Tune3 = new THStack("selproton1_costheta_PID_Tune3","");
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_CC0Pion0Proton_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_CC0Pion1Proton_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_CC0Pion2Proton_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_CC0PionNProton_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_CC1PionNProton_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_CCNPionNProton_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_CCNue_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_NC_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_OOFV_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_EXT_PID_Tune3);
  //selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_other_PID_Tune3);
  selproton1_costheta_PID_Tune3-> Add(selproton1_costheta_OffBeam_PID);
  selproton1_costheta_PID_Tune3->SetMaximum(80.);
  selproton1_costheta_PID_Tune3-> Draw();
  //selproton1_costheta_PID_Tune3->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");
  selproton1_costheta_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  selproton1_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton1_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton1_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l1 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l1 -> SetNColumns(2);
  l1 -> AddEntry(selproton1_costheta_CC0Pion0Proton_PID_Tune3, "CC0P0#pi", "f");
  l1 -> AddEntry(selproton1_costheta_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l1 -> AddEntry(selproton1_costheta_CC0Pion1Proton_PID_Tune3, "CC1P0#pi", "f");
  l1 -> AddEntry(selproton1_costheta_NC_PID_Tune3, "NC", "f");
  l1 -> AddEntry(selproton1_costheta_CC0Pion2Proton_PID_Tune3, "CC2P0#pi", "f");
  l1 -> AddEntry(selproton1_costheta_OOFV_PID_Tune3, "OOFV", "f");
  l1 -> AddEntry(selproton1_costheta_CC0PionNProton_PID_Tune3, "CCNP0#pi", "f");
  l1 -> AddEntry(selproton1_costheta_EXT_PID_Tune3, "cosmic", "f");
  l1 -> AddEntry(selproton1_costheta_CC1PionNProton_PID_Tune3, "CCNP1#pi", "f");
  l1 -> AddEntry(selproton1_costheta_OffBeam_PID, "off-beam data", "f");
  l1 -> AddEntry(selproton1_costheta_CCNPionNProton_PID_Tune3, "CCNPN#pi", "f");
  l1 -> AddEntry(selproton1_costheta_OnBeam_PID, "on-beam data", "lep");
  l1 -> Draw();  

  TText *t1 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t1->Draw();
  
  c1->cd();
  TPad *pad1_2 = new TPad("pad1_2", "pad1_2", 0, 0.05, 1, 0.3);
  pad1_2->SetTopMargin(0.01);
  pad1_2->SetBottomMargin(0.2);
  pad1_2->SetGridx();
  pad1_2->SetGridy();
  pad1_2->Draw();
  pad1_2->cd();
  // Define the ratio plot
  TH1F *h1 = (TH1F*)selproton1_costheta_OnBeam_PID->Clone("h1");
  TH1 *last1 = (TH1*)selproton1_costheta_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last1, selproton1_costheta_OnBeam_PID, selproton1_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h1->SetLineColor(kBlack);
  h1->Sumw2();
  h1->SetStats(0);      // No statistics on lower plot
  h1->Divide(last1);
  h1->SetMarkerStyle(21);
  h1->SetTitle("");
  h1->Draw("ep");       // Draw the ratio plot

  h1->GetYaxis()->SetTitle("Data/MC");
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetTitleSize(20);
  h1->GetYaxis()->SetTitleFont(43);
  h1->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h1->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");
  h1->GetXaxis()->SetTitleSize(20);
  h1->GetXaxis()->SetTitleFont(43);
  h1->GetXaxis()->SetTitleOffset(3.);
  h1->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetXaxis()->SetLabelSize(15);

  c1->Update();
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/selproton1_costheta_topo_PID_Tune3.pdf");

  TCanvas *c2 = new TCanvas("c2", "c2", 900, 900);
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.3, 1, 1.0);
  pad2->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad2->Draw();             // Draw the upper pad: pad1
  pad2->cd();              // pad1 becomes the current pad

  selproton1_phi_CC0Pion0Proton_PID_Tune3-> SetFillColor(kRed -10);
  selproton1_phi_CC0Pion1Proton_PID_Tune3-> SetFillColor(kGreen-8);
  selproton1_phi_CC0Pion2Proton_PID_Tune3-> SetFillColor(kAzure+4);
  selproton1_phi_CC0PionNProton_PID_Tune3-> SetFillColor(kRed-9);
  selproton1_phi_CC1PionNProton_PID_Tune3-> SetFillColor(kOrange);
  selproton1_phi_CCNPionNProton_PID_Tune3-> SetFillColor(kCyan-8);
  selproton1_phi_CCNue_PID_Tune3-> SetFillColor(31);
  selproton1_phi_NC_PID_Tune3-> SetFillColor(kOrange+6);
  selproton1_phi_OOFV_PID_Tune3-> SetFillColor(kYellow+2);
  selproton1_phi_EXT_PID_Tune3-> SetFillColor(kBlack);
  selproton1_phi_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_Tune3-> SetFillColor(kRed);

  THStack *selproton1_phi_PID_Tune3 = new THStack("selproton1_phi_PID_Tune3","");
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_CC0Pion0Proton_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_CC0Pion1Proton_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_CC0Pion2Proton_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_CC0PionNProton_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_CC1PionNProton_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_CCNPionNProton_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_CCNue_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_NC_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_OOFV_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_EXT_PID_Tune3);
  //selproton1_phi_PID_Tune3-> Add(selproton1_phi_other_PID_Tune3);
  selproton1_phi_PID_Tune3-> Add(selproton1_phi_OffBeam_PID);
  selproton1_phi_PID_Tune3->SetMaximum(40.);
  selproton1_phi_PID_Tune3-> Draw();
  //  selproton1_phi_PID_Tune3->GetXaxis()->SetTitle("proton 1 candidate, #phi");
  selproton1_phi_PID_Tune3->GetYaxis()->SetTitle("No. of Entries");

  selproton1_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton1_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton1_phi_OnBeam_PID->Draw("e1same");

  TLegend *l2 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l2 -> SetNColumns(2);
  l2 -> AddEntry(selproton1_phi_CC0Pion0Proton_PID_Tune3, "CC0P0#pi", "f");
  l2 -> AddEntry(selproton1_phi_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l2 -> AddEntry(selproton1_phi_CC0Pion1Proton_PID_Tune3, "CC1P0#pi", "f");
  l2 -> AddEntry(selproton1_phi_NC_PID_Tune3, "NC", "f");
  l2 -> AddEntry(selproton1_phi_CC0Pion2Proton_PID_Tune3, "CC2P0#pi", "f");
  l2 -> AddEntry(selproton1_phi_OOFV_PID_Tune3, "OOFV", "f");
  l2 -> AddEntry(selproton1_phi_CC0PionNProton_PID_Tune3, "CCNP0#pi", "f");
  l2 -> AddEntry(selproton1_phi_EXT_PID_Tune3, "cosmic", "f");
  l2 -> AddEntry(selproton1_phi_CC1PionNProton_PID_Tune3, "CCNP1#pi", "f");
  l2 -> AddEntry(selproton1_phi_OffBeam_PID, "off-beam data", "f");
  l2 -> AddEntry(selproton1_phi_CCNPionNProton_PID_Tune3, "CCNPN#pi", "f");
  l2 -> AddEntry(selproton1_phi_OnBeam_PID, "on-beam data", "lep");
  l2 -> Draw();  
  
  TText *t2 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t2->Draw();

  c2->cd();
  TPad *pad2_2 = new TPad("pad2_2", "pad2_2", 0, 0.05, 1, 0.3);
  pad2_2->SetTopMargin(0.01);
  pad2_2->SetBottomMargin(0.2);
  pad2_2->SetGridx();
  pad2_2->SetGridy();
  pad2_2->Draw();
  pad2_2->cd();
  // Define the ratio plot
  TH1F *h2 = (TH1F*)selproton1_phi_OnBeam_PID->Clone("h2");
  TH1 *last2 = (TH1*)selproton1_phi_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last2, selproton1_phi_OnBeam_PID, selproton1_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h2->SetLineColor(kBlack);
  h2->Sumw2();
  h2->SetStats(0);      // No statistics on lower plot
  h2->Divide(last2);
  h2->SetMarkerStyle(21);
  h2->SetTitle("");
  h2->Draw("ep");       // Draw the ratio plot

  h2->GetYaxis()->SetTitle("Data/MC");
  h2->GetYaxis()->SetNdivisions(505);
  h2->GetYaxis()->SetTitleSize(20);
  h2->GetYaxis()->SetTitleFont(43);
  h2->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h2->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h2->GetXaxis()->SetTitle("proton 1 candidate, #phi");
  h2->GetXaxis()->SetTitleSize(20);
  h2->GetXaxis()->SetTitleFont(43);
  h2->GetXaxis()->SetTitleOffset(3.);
  h2->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h2->GetXaxis()->SetLabelSize(15);

  c2->Update();
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/selproton1_phi_topo_PID_Tune3.pdf");

  TCanvas *c3 = new TCanvas("c3", "c3", 900, 900);
  TPad *pad3 = new TPad("pad3", "pad3", 0, 0.3, 1, 1.0);
  pad3->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad3->Draw();             // Draw the upper pad: pad1
  pad3->cd();              // pad1 becomes the current pad

  selproton1_mom_CC0Pion0Proton_PID_Tune3-> SetFillColor(kRed -10);
  selproton1_mom_CC0Pion1Proton_PID_Tune3-> SetFillColor(kGreen-8);
  selproton1_mom_CC0Pion2Proton_PID_Tune3-> SetFillColor(kAzure+4);
  selproton1_mom_CC0PionNProton_PID_Tune3-> SetFillColor(kRed-9);
  selproton1_mom_CC1PionNProton_PID_Tune3-> SetFillColor(kOrange);
  selproton1_mom_CCNPionNProton_PID_Tune3-> SetFillColor(kCyan-8);
  selproton1_mom_CCNue_PID_Tune3-> SetFillColor(31);
  selproton1_mom_NC_PID_Tune3-> SetFillColor(kOrange+6);
  selproton1_mom_OOFV_PID_Tune3-> SetFillColor(kYellow+2);
  selproton1_mom_EXT_PID_Tune3-> SetFillColor(kBlack);
  selproton1_mom_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_Tune3-> SetFillColor(kRed);

  THStack *selproton1_mom_PID_Tune3 = new THStack("selproton1_mom_PID_Tune3","");
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_CC0Pion0Proton_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_CC0Pion1Proton_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_CC0Pion2Proton_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_CC0PionNProton_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_CC1PionNProton_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_CCNPionNProton_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_CCNue_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_NC_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_OOFV_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_EXT_PID_Tune3);
  //selproton1_mom_PID_Tune3-> Add(selproton1_mom_other_PID_Tune3);
  selproton1_mom_PID_Tune3-> Add(selproton1_mom_OffBeam_PID);
  selproton1_mom_PID_Tune3->SetMaximum(60.);
  selproton1_mom_PID_Tune3-> Draw();
  //selproton1_mom_PID_Tune3->GetXaxis()->SetTitle("proton 1 candidate, momentum [GeV/c]");
  selproton1_mom_PID_Tune3->GetYaxis()->SetTitle("No. of Entries");

  selproton1_mom_OnBeam_PID->SetLineColor(kBlack);
  selproton1_mom_OnBeam_PID->SetMarkerStyle(20);
  selproton1_mom_OnBeam_PID->Draw("e1same");

  TLegend *l3 = new TLegend(0.5, 0.65, 1.1, 0.9);
  l3 -> SetNColumns(2);
  l3 -> AddEntry(selproton1_mom_CC0Pion0Proton_PID_Tune3, "CC0P0#pi", "f");
  l3 -> AddEntry(selproton1_mom_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l3 -> AddEntry(selproton1_mom_CC0Pion1Proton_PID_Tune3, "CC1P0#pi", "f");
  l3 -> AddEntry(selproton1_mom_NC_PID_Tune3, "NC", "f");
  l3 -> AddEntry(selproton1_mom_CC0Pion2Proton_PID_Tune3, "CC2P0#pi", "f");
  l3 -> AddEntry(selproton1_mom_OOFV_PID_Tune3, "OOFV", "f");
  l3 -> AddEntry(selproton1_mom_CC0PionNProton_PID_Tune3, "CCNP0#pi", "f");
  l3 -> AddEntry(selproton1_mom_EXT_PID_Tune3, "cosmic", "f");
  l3 -> AddEntry(selproton1_mom_CC1PionNProton_PID_Tune3, "CCNP1#pi", "f");
  l3 -> AddEntry(selproton1_mom_OffBeam_PID, "off-beam data", "f");
  l3 -> AddEntry(selproton1_mom_CCNPionNProton_PID_Tune3, "CCNPN#pi", "f");
  l3 -> AddEntry(selproton1_mom_OnBeam_PID, "on-beam data", "lep");
  l3 -> Draw();  

  TText *t3 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t3->Draw();
  
  c3->cd();
  TPad *pad3_2 = new TPad("pad3_2", "pad3_2", 0, 0.05, 1, 0.3);
  pad3_2->SetTopMargin(0.01);
  pad3_2->SetBottomMargin(0.2);
  pad3_2->SetGridx();
  pad3_2->SetGridy();
  pad3_2->Draw();
  pad3_2->cd();
  // Define the ratio plot
  TH1F *h3 = (TH1F*)selproton1_mom_OnBeam_PID->Clone("h3");
  TH1 *last3 = (TH1*)selproton1_mom_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last3, selproton1_mom_OnBeam_PID, selproton1_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h3->SetLineColor(kBlack);
  h3->Sumw2();
  h3->SetStats(0);      // No statistics on lower plot
  h3->Divide(last3);
  h3->SetMarkerStyle(21);
  h3->SetTitle("");
  h3->Draw("ep");       // Draw the ratio plot

  h3->GetYaxis()->SetTitle("Data/MC");
  h3->GetYaxis()->SetNdivisions(505);
  h3->GetYaxis()->SetTitleSize(20);
  h3->GetYaxis()->SetTitleFont(43);
  h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h3->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h3->GetXaxis()->SetTitle("proton 1 candidate, momentum [GeV/c]");
  h3->GetXaxis()->SetTitleSize(20);
  h3->GetXaxis()->SetTitleFont(43);
  h3->GetXaxis()->SetTitleOffset(3.);
  h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h3->GetXaxis()->SetLabelSize(15);

  c3->Update();
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/selproton1_mom_topo_PID_Tune3.pdf");

  TCanvas *c4 = new TCanvas("c4", "c4", 900, 900);
  TPad *pad4 = new TPad("pad4", "pad4", 0, 0.3, 1, 1.0);
  pad4->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad4->Draw();             // Draw the upper pad: pad1
  pad4->cd();              // pad1 becomes the current pad

  selproton2_costheta_CC0Pion0Proton_PID_Tune3-> SetFillColor(kRed -10);
  selproton2_costheta_CC0Pion1Proton_PID_Tune3-> SetFillColor(kGreen-8);
  selproton2_costheta_CC0Pion2Proton_PID_Tune3-> SetFillColor(kAzure+4);
  selproton2_costheta_CC0PionNProton_PID_Tune3-> SetFillColor(kRed-9);
  selproton2_costheta_CC1PionNProton_PID_Tune3-> SetFillColor(kOrange);
  selproton2_costheta_CCNPionNProton_PID_Tune3-> SetFillColor(kCyan-8);
  selproton2_costheta_CCNue_PID_Tune3-> SetFillColor(31);
  selproton2_costheta_NC_PID_Tune3-> SetFillColor(kOrange+6);
  selproton2_costheta_OOFV_PID_Tune3-> SetFillColor(kYellow+2);
  selproton2_costheta_EXT_PID_Tune3-> SetFillColor(kBlack);
  selproton2_costheta_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_Tune3-> SetFillColor(kRed);

  THStack *selproton2_costheta_PID_Tune3 = new THStack("selproton2_costheta_PID_Tune3","");
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_CC0Pion0Proton_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_CC0Pion1Proton_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_CC0Pion2Proton_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_CC0PionNProton_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_CC1PionNProton_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_CCNPionNProton_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_CCNue_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_NC_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_OOFV_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_EXT_PID_Tune3);
  //selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_other_PID_Tune3);
  selproton2_costheta_PID_Tune3-> Add(selproton2_costheta_OffBeam_PID);
  selproton2_costheta_PID_Tune3->SetMaximum(50.);
  selproton2_costheta_PID_Tune3-> Draw();
  //  selproton2_costheta_PID_Tune3->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");
  selproton2_costheta_PID_Tune3->GetYaxis()->SetTitle("No. of Entries");

  selproton2_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton2_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton2_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l4 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l4 -> SetNColumns(2);
  l4 -> AddEntry(selproton2_costheta_CC0Pion0Proton_PID_Tune3, "CC0P0#pi", "f");
  l4 -> AddEntry(selproton2_costheta_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l4 -> AddEntry(selproton2_costheta_CC0Pion1Proton_PID_Tune3, "CC1P0#pi", "f");
  l4 -> AddEntry(selproton2_costheta_NC_PID_Tune3, "NC", "f");
  l4 -> AddEntry(selproton2_costheta_CC0Pion2Proton_PID_Tune3, "CC2P0#pi", "f");
  l4 -> AddEntry(selproton2_costheta_OOFV_PID_Tune3, "OOFV", "f");
  l4 -> AddEntry(selproton2_costheta_CC0PionNProton_PID_Tune3, "CCNP0#pi", "f");
  l4 -> AddEntry(selproton2_costheta_EXT_PID_Tune3, "cosmic", "f");
  l4 -> AddEntry(selproton2_costheta_CC1PionNProton_PID_Tune3, "CCNP1#pi", "f");
  l4 -> AddEntry(selproton2_costheta_OffBeam_PID, "off-beam data", "f");
  l4 -> AddEntry(selproton2_costheta_CCNPionNProton_PID_Tune3, "CCNPN#pi", "f");
  l4 -> AddEntry(selproton2_costheta_OnBeam_PID, "on-beam data", "lep");
  l4 -> Draw();  
  
  TText *t4 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t4->Draw();

  c4->cd();
  TPad *pad4_2 = new TPad("pad4_2", "pad4_2", 0, 0.05, 1, 0.3);
  pad4_2->SetTopMargin(0.01);
  pad4_2->SetBottomMargin(0.2);
  pad4_2->SetGridx();
  pad4_2->SetGridy();
  pad4_2->Draw();
  pad4_2->cd();
  // Define the ratio plot
  TH1F *h4 = (TH1F*)selproton2_costheta_OnBeam_PID->Clone("h4");
  TH1 *last4 = (TH1*)selproton2_costheta_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last4,selproton2_costheta_OnBeam_PID, selproton2_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h4->SetLineColor(kBlack);
  h4->Sumw2();
  h4->SetStats(0);      // No statistics on lower plot
  h4->Divide(last4);
  h4->SetMarkerStyle(21);
  h4->SetTitle("");
  h4->Draw("ep");       // Draw the ratio plot

  h4->GetYaxis()->SetTitle("Data/MC");
  h4->GetYaxis()->SetNdivisions(505);
  h4->GetYaxis()->SetTitleSize(20);
  h4->GetYaxis()->SetTitleFont(43);
  h4->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h4->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h4->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");
  h4->GetXaxis()->SetTitleSize(20);
  h4->GetXaxis()->SetTitleFont(43);
  h4->GetXaxis()->SetTitleOffset(3.);
  h4->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h4->GetXaxis()->SetLabelSize(15);

  c4->Update();
  c4->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/selproton2_costheta_topo_PID_Tune3.pdf");

  TCanvas *c5 = new TCanvas("c5", "c5", 900, 900);
  TPad *pad5 = new TPad("pad5", "pad5", 0, 0.3, 1, 1.0);
  pad5->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad5->Draw();             // Draw the upper pad: pad1
  pad5->cd();              // pad1 becomes the current pad

  selproton2_phi_CC0Pion0Proton_PID_Tune3-> SetFillColor(kRed -10);
  selproton2_phi_CC0Pion1Proton_PID_Tune3-> SetFillColor(kGreen-8);
  selproton2_phi_CC0Pion2Proton_PID_Tune3-> SetFillColor(kAzure+4);
  selproton2_phi_CC0PionNProton_PID_Tune3-> SetFillColor(kRed-9);
  selproton2_phi_CC1PionNProton_PID_Tune3-> SetFillColor(kOrange);
  selproton2_phi_CCNPionNProton_PID_Tune3-> SetFillColor(kCyan-8);
  selproton2_phi_CCNue_PID_Tune3-> SetFillColor(31);
  selproton2_phi_NC_PID_Tune3-> SetFillColor(kOrange+6);
  selproton2_phi_OOFV_PID_Tune3-> SetFillColor(kYellow+2);
  selproton2_phi_EXT_PID_Tune3-> SetFillColor(kBlack);
  selproton2_phi_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_Tune3-> SetFillColor(kRed);

  THStack *selproton2_phi_PID_Tune3 = new THStack("selproton2_phi_PID_Tune3","");
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_CC0Pion0Proton_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_CC0Pion1Proton_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_CC0Pion2Proton_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_CC0PionNProton_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_CC1PionNProton_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_CCNPionNProton_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_CCNue_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_NC_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_OOFV_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_EXT_PID_Tune3);
  //selproton2_phi_PID_Tune3-> Add(selproton2_phi_other_PID_Tune3);
  selproton2_phi_PID_Tune3-> Add(selproton2_phi_OffBeam_PID);
  selproton2_phi_PID_Tune3->SetMaximum(40.);
  selproton2_phi_PID_Tune3-> Draw();
  //selproton2_phi_PID_Tune3->GetXaxis()->SetTitle("proton 2 candidate, #phi");
  selproton2_phi_PID_Tune3->GetYaxis()->SetTitle("No. of Entries");

  selproton2_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton2_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton2_phi_OnBeam_PID->Draw("e1same");

  TLegend *l5 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l5 -> SetNColumns(2);
  l5 -> AddEntry(selproton2_phi_CC0Pion0Proton_PID_Tune3, "CC0P0#pi", "f");
  l5 -> AddEntry(selproton2_phi_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l5 -> AddEntry(selproton2_phi_CC0Pion1Proton_PID_Tune3, "CC1P0#pi", "f");
  l5 -> AddEntry(selproton2_phi_NC_PID_Tune3, "NC", "f");
  l5 -> AddEntry(selproton2_phi_CC0Pion2Proton_PID_Tune3, "CC2P0#pi", "f");
  l5 -> AddEntry(selproton2_phi_OOFV_PID_Tune3, "OOFV", "f");
  l5 -> AddEntry(selproton2_phi_CC0PionNProton_PID_Tune3, "CCNP0#pi", "f");
  l5 -> AddEntry(selproton2_phi_EXT_PID_Tune3, "cosmic", "f");
  l5 -> AddEntry(selproton2_phi_CC1PionNProton_PID_Tune3, "CCNP1#pi", "f");
  l5 -> AddEntry(selproton2_phi_OffBeam_PID, "off-beam data", "f");
  l5 -> AddEntry(selproton2_phi_CCNPionNProton_PID_Tune3, "CCNPN#pi", "f");
  l5 -> AddEntry(selproton2_phi_OnBeam_PID, "on-beam data", "lep");
  l5 -> Draw();  

  TText *t5 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t5->Draw();
  
  c5->cd();
  TPad *pad5_2 = new TPad("pad5_2", "pad5_2", 0, 0.05, 1, 0.3);
  pad5_2->SetTopMargin(0.01);
  pad5_2->SetBottomMargin(0.2);
  pad5_2->SetGridx();
  pad5_2->SetGridy();
  pad5_2->Draw();
  pad5_2->cd();
  // Define the ratio plot
  TH1F *h5 = (TH1F*)selproton2_phi_OnBeam_PID->Clone("h5");
  TH1 *last5 = (TH1*)selproton2_phi_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last5,selproton2_phi_OnBeam_PID, selproton2_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h5->SetLineColor(kBlack);
  h5->Sumw2();
  h5->SetStats(0);      // No statistics on lower plot
  h5->Divide(last5);
  h5->SetMarkerStyle(21);
  h5->SetTitle("");
  h5->Draw("ep");       // Draw the ratio plot

  h5->GetYaxis()->SetTitle("Data/MC");
  h5->GetYaxis()->SetNdivisions(505);
  h5->GetYaxis()->SetTitleSize(20);
  h5->GetYaxis()->SetTitleFont(43);
  h5->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h5->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h5->GetXaxis()->SetTitle("proton 2 candidate, #phi");
  h5->GetXaxis()->SetTitleSize(20);
  h5->GetXaxis()->SetTitleFont(43);
  h5->GetXaxis()->SetTitleOffset(3.);
  h5->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h5->GetXaxis()->SetLabelSize(15);

  c5->Update();
  c5->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/selproton2_phi_topo_PID_Tune3.pdf");

  TCanvas *c6 = new TCanvas("c6", "c6", 900, 900);
  TPad *pad6 = new TPad("pad6", "pad6", 0, 0.3, 1, 1.0);
  pad6->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad6->Draw();             // Draw the upper pad: pad1
  pad6->cd();              // pad1 becomes the current pad

  selproton2_mom_CC0Pion0Proton_PID_Tune3-> SetFillColor(kRed -10);
  selproton2_mom_CC0Pion1Proton_PID_Tune3-> SetFillColor(kGreen-8);
  selproton2_mom_CC0Pion2Proton_PID_Tune3-> SetFillColor(kAzure+4);
  selproton2_mom_CC0PionNProton_PID_Tune3-> SetFillColor(kRed-9);
  selproton2_mom_CC1PionNProton_PID_Tune3-> SetFillColor(kOrange);
  selproton2_mom_CCNPionNProton_PID_Tune3-> SetFillColor(kCyan-8);
  selproton2_mom_CCNue_PID_Tune3-> SetFillColor(31);
  selproton2_mom_NC_PID_Tune3-> SetFillColor(kOrange+6);
  selproton2_mom_OOFV_PID_Tune3-> SetFillColor(kYellow+2);
  selproton2_mom_EXT_PID_Tune3-> SetFillColor(kBlack);
  selproton2_mom_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_Tune3-> SetFillColor(kRed);

  THStack *selproton2_mom_PID_Tune3 = new THStack("selproton2_mom_PID_Tune3","");
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_CC0Pion0Proton_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_CC0Pion1Proton_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_CC0Pion2Proton_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_CC0PionNProton_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_CC1PionNProton_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_CCNPionNProton_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_CCNue_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_NC_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_OOFV_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_EXT_PID_Tune3);
  //selproton2_mom_PID_Tune3-> Add(selproton2_mom_other_PID_Tune3);
  selproton2_mom_PID_Tune3-> Add(selproton2_mom_OffBeam_PID);
  selproton2_mom_PID_Tune3->SetMaximum(60.);
  selproton2_mom_PID_Tune3-> Draw();
  //  selproton2_mom_PID_Tune3->GetXaxis()->SetTitle("proton 2 candidate, momentum [GeV/c]");
  selproton2_mom_PID_Tune3->GetYaxis()->SetTitle("No. of Entries");

  selproton2_mom_OnBeam_PID->SetLineColor(kBlack);
  selproton2_mom_OnBeam_PID->SetMarkerStyle(20);
  selproton2_mom_OnBeam_PID->Draw("e1same");

  TLegend *l6 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l6 -> SetNColumns(2);
  l6 -> AddEntry(selproton2_mom_CC0Pion0Proton_PID_Tune3, "CC0P0#pi", "f");
  l6 -> AddEntry(selproton2_mom_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l6 -> AddEntry(selproton2_mom_CC0Pion1Proton_PID_Tune3, "CC1P0#pi", "f");
  l6 -> AddEntry(selproton2_mom_NC_PID_Tune3, "NC", "f");
  l6 -> AddEntry(selproton2_mom_CC0Pion2Proton_PID_Tune3, "CC2P0#pi", "f");
  l6 -> AddEntry(selproton2_mom_OOFV_PID_Tune3, "OOFV", "f");
  l6 -> AddEntry(selproton2_mom_CC0PionNProton_PID_Tune3, "CCNP0#pi", "f");
  l6 -> AddEntry(selproton2_mom_EXT_PID_Tune3, "cosmic", "f");
  l6 -> AddEntry(selproton2_mom_CC1PionNProton_PID_Tune3, "CCNP1#pi", "f");
  l6 -> AddEntry(selproton2_mom_OffBeam_PID, "off-beam data", "f");
  l6 -> AddEntry(selproton2_mom_CCNPionNProton_PID_Tune3, "CCNPN#pi", "f");
  l6 -> AddEntry(selproton2_mom_OnBeam_PID, "on-beam data", "lep");
  l6 -> Draw();  
 
  TText *t6 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t6->Draw();
 
  c6->cd();
  TPad *pad6_2 = new TPad("pad6_2", "pad6_2", 0, 0.05, 1, 0.3);
  pad6_2->SetTopMargin(0.01);
  pad6_2->SetBottomMargin(0.2);
  pad6_2->SetGridx();
  pad6_2->SetGridy();
  pad6_2->Draw();
  pad6_2->cd();
  // Define the ratio plot
  TH1F *h6 = (TH1F*)selproton2_mom_OnBeam_PID->Clone("h6");
  TH1 *last6 = (TH1*)selproton2_mom_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last6,selproton2_mom_OnBeam_PID, selproton2_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h6->SetLineColor(kBlack);
  h6->Sumw2();
  h6->SetStats(0);      // No statistics on lower plot
  h6->Divide(last6);
  h6->SetMarkerStyle(21);
  h6->SetTitle("");
  h6->Draw("ep");       // Draw the ratio plot

  h6->GetYaxis()->SetTitle("Data/MC");
  h6->GetYaxis()->SetNdivisions(505);
  h6->GetYaxis()->SetTitleSize(20);
  h6->GetYaxis()->SetTitleFont(43);
  h6->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h6->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h6->GetXaxis()->SetTitle("proton 2 candidate, momentum [GeV/c]");
  h6->GetXaxis()->SetTitleSize(20);
  h6->GetXaxis()->SetTitleFont(43);
  h6->GetXaxis()->SetTitleOffset(3.);
  h6->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h6->GetXaxis()->SetLabelSize(15);

  c6->Update();
  c6->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/selproton2_mom_topo_PID_Tune3.pdf");
  
  TCanvas *c7 = new TCanvas("c7", "c7", 900, 900);
  TPad *pad7 = new TPad("pad7", "pad7", 0, 0.3, 1, 1.0);
  pad7->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad7->Draw();             // Draw the upper pad: pad1
  pad7->cd();              // pad1 becomes the current pad

  angle_p1p2_CC0Pion0Proton_PID_Tune3-> SetFillColor(kRed -10);
  angle_p1p2_CC0Pion1Proton_PID_Tune3-> SetFillColor(kGreen-8);
  angle_p1p2_CC0Pion2Proton_PID_Tune3-> SetFillColor(kAzure+4);
  angle_p1p2_CC0PionNProton_PID_Tune3-> SetFillColor(kRed-9);
  angle_p1p2_CC1PionNProton_PID_Tune3-> SetFillColor(kOrange);
  angle_p1p2_CCNPionNProton_PID_Tune3-> SetFillColor(kCyan-8);
  angle_p1p2_CCNue_PID_Tune3-> SetFillColor(31);
  angle_p1p2_NC_PID_Tune3-> SetFillColor(kOrange+6);
  angle_p1p2_OOFV_PID_Tune3-> SetFillColor(kYellow+2);
  angle_p1p2_EXT_PID_Tune3-> SetFillColor(kBlack);
  angle_p1p2_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_Tune3-> SetFillColor(kRed);

  THStack *cangle_p1p2_PID_Tune3 = new THStack("angle_p1p2_PID_Tune3","");
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_CC0Pion0Proton_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_CC0Pion1Proton_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_CC0Pion2Proton_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_CC0PionNProton_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_CC1PionNProton_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_CCNPionNProton_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_CCNue_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_NC_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_OOFV_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_EXT_PID_Tune3);
  //angle_p1p2_PID_Tune3-> Add(angle_p1p2_other_PID_Tune3);
  angle_p1p2_PID_Tune3-> Add(angle_p1p2_OffBeam_PID);
  angle_p1p2_PID_Tune3->SetMaximum(50.);
  angle_p1p2_PID_Tune3-> Draw();
  //  angle_p1p2_PID_Tune3->GetXaxis()->SetTitle("cos#theta_{p_{1} -p_{2}} [rad]");
  angle_p1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  angle_p1p2_OnBeam_PID->SetLineColor(kBlack);
  angle_p1p2_OnBeam_PID->SetMarkerStyle(20);
  angle_p1p2_OnBeam_PID->Draw("e1same");

  TLegend *l7 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l7 -> SetNColumns(2);
  l7 -> AddEntry(angle_p1p2_CC0Pion0Proton_PID_Tune3, "CC0P0#pi", "f");
  l7 -> AddEntry(angle_p1p2_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l7 -> AddEntry(angle_p1p2_CC0Pion1Proton_PID_Tune3, "CC1P0#pi", "f");
  l7 -> AddEntry(angle_p1p2_NC_PID_Tune3, "NC", "f");
  l7 -> AddEntry(angle_p1p2_CC0Pion2Proton_PID_Tune3, "CC2P0#pi", "f");
  l7 -> AddEntry(angle_p1p2_OOFV_PID_Tune3, "OOFV", "f");
  l7 -> AddEntry(angle_p1p2_CC0PionNProton_PID_Tune3, "CCNP0#pi", "f");
  l7 -> AddEntry(angle_p1p2_EXT_PID_Tune3, "cosmic", "f");
  l7 -> AddEntry(angle_p1p2_CC1PionNProton_PID_Tune3, "CCNP1#pi", "f");
  l7 -> AddEntry(angle_p1p2_OffBeam_PID, "off-beam data", "f");
  l7 -> AddEntry(angle_p1p2_CCNPionNProton_PID_Tune3, "CCNPN#pi", "f");
  l7 -> AddEntry(angle_p1p2_OnBeam_PID, "on-beam data", "lep");
  l7 -> Draw();  
  
  TText *t7 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t7->Draw();

  c7->cd();
  TPad *pad7_2 = new TPad("pad7_2", "pad7_2", 0, 0.05, 1, 0.3);
  pad7_2->SetTopMargin(0.01);
  pad7_2->SetBottomMargin(0.2);
  pad7_2->SetGridx();
  pad7_2->SetGridy();
  pad7_2->Draw();
  pad7_2->cd();
  // Define the ratio plot
  TH1F *h7 = (TH1F*)angle_p1p2_OnBeam_PID->Clone("h7");
  TH1 *last7 = (TH1*)angle_p1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last7,angle_p1p2_OnBeam_PID, angle_p1p2_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h7->SetLineColor(kBlack);
  h7->Sumw2();
  h7->SetStats(0);      // No statistics on lower plot
  h7->Divide(last7);
  h7->SetMarkerStyle(21);
  h7->SetTitle("");
  h7->Draw("ep");       // Draw the ratio plot

  h7->GetYaxis()->SetTitle("Data/MC");
  h7->GetYaxis()->SetNdivisions(505);
  h7->GetYaxis()->SetTitleSize(20);
  h7->GetYaxis()->SetTitleFont(43);
  h7->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h7->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h7->GetXaxis()->SetTitle("cos#theta_{p_{1} -p_{2}}");
  h7->GetXaxis()->SetTitleSize(20);
  h7->GetXaxis()->SetTitleFont(43);
  h7->GetXaxis()->SetTitleOffset(3.);
  h7->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h7->GetXaxis()->SetLabelSize(15);

  c7->Update();
  c7->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosangle_p1p2_topo_PID_Tune3.pdf");
  */
  //////////////// *** nuevos histos

 
  TCanvas *c8 = new TCanvas("c8", "c8", 900, 900);
  TPad *pad8 = new TPad("pad8", "pad8", 0, 0.3, 1, 1.0);
  pad8->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad8->Draw();             // Draw the upper pad: pad1
  pad8->cd();              // pad1 becomes the current pad

  reco_Enu_CCQE_PID_Tune3-> SetFillColor(kRed -10);
  reco_Enu_CCRes_PID_Tune3-> SetFillColor(kGreen-8);
  reco_Enu_CCCoh_PID_Tune3-> SetFillColor(kAzure+4);
  reco_Enu_CCDIS_PID_Tune3-> SetFillColor(kRed-9);
  reco_Enu_CCMEC_PID_Tune3-> SetFillColor(kOrange);
  reco_Enu_CCNue_PID_Tune3-> SetFillColor(kCyan-8);
  reco_Enu_NC_PID_Tune3-> SetFillColor(31);
  reco_Enu_other_PID_Tune3-> SetFillColor(kOrange+6);
  reco_Enu_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_Enu_PID_Tune3 = new THStack("reco_Enu_PID_Tune3","");
  reco_Enu_PID_Tune3-> Add(reco_Enu_CCQE_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_CCRes_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_CCCoh_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_CCDIS_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_CCMEC_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_CCNue_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_NC_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_other_PID_Tune3);
  reco_Enu_PID_Tune3-> Add(reco_Enu_OffBeam_PID);
  reco_Enu_PID_Tune3->SetMaximum(250.);
  reco_Enu_PID_Tune3-> Draw();
  reco_Enu_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_Enu_OnBeam_PID->SetLineColor(kBlack);
  reco_Enu_OnBeam_PID->SetMarkerStyle(20);
  reco_Enu_OnBeam_PID->Draw("e1same");

  TLegend *l8 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l8 -> SetNColumns(2);
  l8 -> AddEntry(reco_Enu_CCQE_PID_Tune3, "CCQE", "f");
  l8 -> AddEntry(reco_Enu_CCRes_PID_Tune3, "CCRes", "f");
  l8 -> AddEntry(reco_Enu_CCCoh_PID_Tune3, "CCCoh", "f");
  l8 -> AddEntry(reco_Enu_CCDIS_PID_Tune3, "DIS", "f");
  l8 -> AddEntry(reco_Enu_CCMEC_PID_Tune3, "CCMEC", "f");
  l8 -> AddEntry(reco_Enu_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l8 -> AddEntry(reco_Enu_NC_PID_Tune3, "NC", "f");
  l8 -> AddEntry(reco_Enu_other_PID_Tune3, "other", "f");

  l8 -> AddEntry(reco_Enu_OffBeam_PID, "off-beam data", "f");
  l8 -> AddEntry(reco_Enu_OnBeam_PID, "on-beam data", "lep");
  l8 -> Draw();  
  
  TText *t8 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t8->Draw();

  c8->cd();
  TPad *pad8_2 = new TPad("pad8_2", "pad8_2", 0, 0.05, 1, 0.3);
  pad8_2->SetTopMargin(0.01);
  pad8_2->SetBottomMargin(0.2);
  pad8_2->SetGridx();
  pad8_2->SetGridy();
  pad8_2->Draw();
  pad8_2->cd();
  // Define the ratio plot
  TH1F *h8 = (TH1F*)reco_Enu_OnBeam_PID->Clone("h8");
  TH1 *last8 = (TH1*)reco_Enu_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last8,reco_Enu_OnBeam_PID, reco_Enu_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  Enu reco chi2test : "<<chi2test<<std::endl;

  h8->SetLineColor(kBlack);
  h8->Sumw2();
  h8->SetStats(0);      // No statistics on lower plot
  h8->Divide(last8);
  h8->SetMarkerStyle(21);
  h8->SetTitle("");
  h8->Draw("ep");       // Draw the ratio plot

  h8->GetYaxis()->SetTitle("Data/MC");
  h8->GetYaxis()->SetNdivisions(505);
  h8->GetYaxis()->SetTitleSize(20);
  h8->GetYaxis()->SetTitleFont(43);
  h8->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h8->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h8->GetXaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  h8->GetXaxis()->SetTitleSize(20);
  h8->GetXaxis()->SetTitleFont(43);
  h8->GetXaxis()->SetTitleOffset(3.);
  h8->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h8->GetXaxis()->SetLabelSize(15);

  c8->Update();
  c8->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/EnuReco_topo_PID_Tune3.pdf");
    
  TCanvas *c9 = new TCanvas("c9", "c9", 900, 900);
  TPad *pad9 = new TPad("pad9", "pad9", 0, 0.3, 1, 1.0);
  pad9->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad9->Draw();             // Draw the upper pad: pad1
  pad9->cd();              // pad1 becomes the current pad

  reco_PT_CCQE_PID_Tune3-> SetFillColor(kRed -10);
  reco_PT_CCRes_PID_Tune3-> SetFillColor(kGreen-8);
  reco_PT_CCCoh_PID_Tune3-> SetFillColor(kAzure+4);
  reco_PT_CCDIS_PID_Tune3-> SetFillColor(kRed-9);
  reco_PT_CCMEC_PID_Tune3-> SetFillColor(kOrange);
  reco_PT_CCNue_PID_Tune3-> SetFillColor(kCyan-8);
  reco_PT_NC_PID_Tune3-> SetFillColor(31);
  reco_PT_other_PID_Tune3-> SetFillColor(kOrange+6);
  reco_PT_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_PT_PID_Tune3 = new THStack("reco_PT_PID_Tune3","");
  reco_PT_PID_Tune3-> Add(reco_PT_CCQE_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_CCRes_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_CCCoh_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_CCDIS_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_CCMEC_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_CCNue_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_NC_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_other_PID_Tune3);
  reco_PT_PID_Tune3-> Add(reco_PT_OffBeam_PID);
  //reco_PT_PID_Tune3->SetMaximum(50.);
  reco_PT_PID_Tune3-> Draw();
  reco_PT_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_PT_OnBeam_PID->SetLineColor(kBlack);
  reco_PT_OnBeam_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_PID->Draw("e1same");

  TLegend *l9 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l9 -> SetNColumns(2);
  l9 -> AddEntry(reco_PT_CCQE_PID_Tune3, "CCQE", "f");
  l9 -> AddEntry(reco_PT_CCRes_PID_Tune3, "CCRes", "f");
  l9 -> AddEntry(reco_PT_CCCoh_PID_Tune3, "CCCoh", "f");
  l9 -> AddEntry(reco_PT_CCDIS_PID_Tune3, "DIS", "f");
  l9 -> AddEntry(reco_PT_CCMEC_PID_Tune3, "CCMEC", "f");
  l9 -> AddEntry(reco_PT_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l9 -> AddEntry(reco_PT_NC_PID_Tune3, "NC", "f");
  l9 -> AddEntry(reco_PT_other_PID_Tune3, "other", "f");

  l9 -> AddEntry(reco_PT_OffBeam_PID, "off-beam data", "f");
  l9 -> AddEntry(reco_PT_OnBeam_PID, "on-beam data", "lep");
  l9 -> Draw();  
  
  TText *t9 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t9->Draw();

  c9->cd();
  TPad *pad9_2 = new TPad("pad9_2", "pad9_2", 0, 0.05, 1, 0.3);
  pad9_2->SetTopMargin(0.01);
  pad9_2->SetBottomMargin(0.2);
  pad9_2->SetGridx();
  pad9_2->SetGridy();
  pad9_2->Draw();
  pad9_2->cd();
  // Define the ratio plot
  TH1F *h9 = (TH1F*)reco_PT_OnBeam_PID->Clone("h9");
  TH1 *last9 = (TH1*)reco_PT_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last9,reco_PT_OnBeam_PID, reco_PT_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  PT reco chi2test : "<<chi2test<<std::endl;

  h9->SetLineColor(kBlack);
  h9->Sumw2();
  h9->SetStats(0);      // No statistics on lower plot
  h9->Divide(last9);
  h9->SetMarkerStyle(21);
  h9->SetTitle("");
  h9->Draw("ep");       // Draw the ratio plot

  h9->GetYaxis()->SetTitle("Data/MC");
  h9->GetYaxis()->SetNdivisions(505);
  h9->GetYaxis()->SetTitleSize(20);
  h9->GetYaxis()->SetTitleFont(43);
  h9->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h9->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h9->GetXaxis()->SetTitle("reconstructed missing P_{T} [GeV]");
  h9->GetXaxis()->SetTitleSize(20);
  h9->GetXaxis()->SetTitleFont(43);
  h9->GetXaxis()->SetTitleOffset(3.);
  h9->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h9->GetXaxis()->SetLabelSize(15);

  c9->Update();
  c9->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/PTReco_topo_PID_Tune3.pdf");
  
  TCanvas *c10 = new TCanvas("c10", "c10", 900, 900);
  TPad *pad10 = new TPad("pad10", "pad10", 0, 0.3, 1, 1.0);
  pad10->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad10->Draw();             // Draw the upper pad: pad1
  pad10->cd();              // pad1 becomes the current pad

  reco_pn_CCQE_PID_Tune3-> SetFillColor(kRed -10);
  reco_pn_CCRes_PID_Tune3-> SetFillColor(kGreen-8);
  reco_pn_CCCoh_PID_Tune3-> SetFillColor(kAzure+4);
  reco_pn_CCDIS_PID_Tune3-> SetFillColor(kRed-9);
  reco_pn_CCMEC_PID_Tune3-> SetFillColor(kOrange);
  reco_pn_CCNue_PID_Tune3-> SetFillColor(kCyan-8);
  reco_pn_NC_PID_Tune3-> SetFillColor(31);
  reco_pn_other_PID_Tune3-> SetFillColor(kOrange+6);
  reco_pn_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_pn_PID_Tune3 = new THStack("reco_pn_PID_Tune3","");
  reco_pn_PID_Tune3-> Add(reco_pn_CCQE_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_CCRes_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_CCCoh_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_CCDIS_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_CCMEC_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_CCNue_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_NC_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_other_PID_Tune3);
  reco_pn_PID_Tune3-> Add(reco_pn_OffBeam_PID);
  reco_pn_PID_Tune3->SetMaximum(250.);
  reco_pn_PID_Tune3-> Draw();
  reco_pn_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_pn_OnBeam_PID->SetLineColor(kBlack);
  reco_pn_OnBeam_PID->SetMarkerStyle(20);
  reco_pn_OnBeam_PID->Draw("e1same");

  TLegend *l10 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l10 -> SetNColumns(2);
  l10 -> AddEntry(reco_pn_CCQE_PID_Tune3, "CCQE", "f");
  l10 -> AddEntry(reco_pn_CCRes_PID_Tune3, "CCRes", "f");
  l10 -> AddEntry(reco_pn_CCCoh_PID_Tune3, "CCCoh", "f");
  l10 -> AddEntry(reco_pn_CCDIS_PID_Tune3, "DIS", "f");
  l10 -> AddEntry(reco_pn_CCMEC_PID_Tune3, "CCMEC", "f");
  l10 -> AddEntry(reco_pn_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l10 -> AddEntry(reco_pn_NC_PID_Tune3, "NC", "f");
  l10 -> AddEntry(reco_pn_other_PID_Tune3, "other", "f");

  l10 -> AddEntry(reco_pn_OffBeam_PID, "off-beam data", "f");
  l10 -> AddEntry(reco_pn_OnBeam_PID, "on-beam data", "lep");
  l10 -> Draw();  
  
  TText *t10 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t10->Draw();

  c10->cd();
  TPad *pad10_2 = new TPad("pad10_2", "pad10_2", 0, 0.05, 1, 0.3);
  pad10_2->SetTopMargin(0.01);
  pad10_2->SetBottomMargin(0.2);
  pad10_2->SetGridx();
  pad10_2->SetGridy();
  pad10_2->Draw();
  pad10_2->cd();
  // Define the ratio plot
  TH1F *h10 = (TH1F*)reco_pn_OnBeam_PID->Clone("h10");
  TH1 *last10 = (TH1*)reco_pn_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last10,reco_pn_OnBeam_PID, reco_pn_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  pn reco chi2test : "<<chi2test<<std::endl;

  h10->SetLineColor(kBlack);
  h10->Sumw2();
  h10->SetStats(0);      // No statistics on lower plot
  h10->Divide(last10);
  h10->SetMarkerStyle(21);
  h10->SetTitle("");
  h10->Draw("ep");       // Draw the ratio plot

  h10->GetYaxis()->SetTitle("Data/MC");
  h10->GetYaxis()->SetNdivisions(505);
  h10->GetYaxis()->SetTitleSize(20);
  h10->GetYaxis()->SetTitleFont(43);
  h10->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h10->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h10->GetXaxis()->SetTitle("reconstructed momentum struck nucleon [GeV]");
  h10->GetXaxis()->SetTitleSize(20);
  h10->GetXaxis()->SetTitleFont(43);
  h10->GetXaxis()->SetTitleOffset(3.);
  h10->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h10->GetXaxis()->SetLabelSize(15);

  c10->Update();
  c10->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/pnReco_topo_PID_Tune3.pdf");
  
  TCanvas *c11 = new TCanvas("c11", "c11", 900, 900);
  TPad *pad11 = new TPad("pad11", "pad11", 0, 0.3, 1, 1.0);
  pad11->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad11->Draw();             // Draw the upper pad: pad1
  pad11->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_LF-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_LF-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_LF-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_LF-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_LF-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_LF-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_LF = new THStack("reco_angle_p1p2_PID_Tune3_LF","");
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_CCQE_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_CCRes_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_CCNue_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_NC_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_other_PID_Tune3_LF);
  reco_angle_p1p2_PID_Tune3_LF-> Add(reco_angle_p1p2_OffBeam_PID_LF);
  reco_angle_p1p2_PID_Tune3_LF->SetMaximum(150.);
  reco_angle_p1p2_PID_Tune3_LF-> Draw();
  reco_angle_p1p2_PID_Tune3_LF->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_LF->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_LF->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_LF->Draw("e1same");

  TLegend *l11 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l11 -> SetNColumns(2);
  l11 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_LF, "CCQE", "f");
  l11 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_LF, "CCRes", "f");
  l11 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_LF, "CCCoh", "f");
  l11 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_LF, "DIS", "f");
  l11 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_LF, "CCMEC", "f");
  l11 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_LF, "CC#nu_{e}", "f");
  l11 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_LF, "NC", "f");
  l11 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_LF, "other", "f");
  
  l11 -> AddEntry(reco_angle_p1p2_OffBeam_PID_LF, "off-beam data", "f");
  l11 -> AddEntry(reco_angle_p1p2_OnBeam_PID_LF, "on-beam data", "lep");
  l11 -> Draw();  
  
  TText *t11 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t11->Draw();

  c11->cd();
  TPad *pad11_2 = new TPad("pad11_2", "pad11_2", 0, 0.05, 1, 0.3);
  pad11_2->SetTopMargin(0.01);
  pad11_2->SetBottomMargin(0.2);
  pad11_2->SetGridx();
  pad11_2->SetGridy();
  pad11_2->Draw();
  pad11_2->cd();
  // Define the ratio plot
  TH1F *h11 = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF->Clone("h11");
  TH1 *last11 = (TH1*)reco_angle_p1p2_PID_Tune3_LF->GetStack()->Last();

  chi2test = Chi2Calc(last11,reco_angle_p1p2_OnBeam_PID_LF, reco_angle_p1p2_OffBeam_PID_LF, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle LF reco chi2test : "<<chi2test<<std::endl;

  h11->SetLineColor(kBlack);
  h11->Sumw2();
  h11->SetStats(0);      // No statistics on lower plot
  h11->Divide(last11);
  h11->SetMarkerStyle(21);
  h11->SetTitle("");
  h11->Draw("ep");       // Draw the ratio plot

  h11->GetYaxis()->SetTitle("Data/MC");
  h11->GetYaxis()->SetNdivisions(505);
  h11->GetYaxis()->SetTitleSize(20);
  h11->GetYaxis()->SetTitleFont(43);
  h11->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h11->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h11->GetXaxis()->SetTitle("reconstructed cos#theta_{p_{1} vs p_{2}} in lab frame");
  h11->GetXaxis()->SetTitleSize(20);
  h11->GetXaxis()->SetTitleFont(43);
  h11->GetXaxis()->SetTitleOffset(3.);
  h11->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h11->GetXaxis()->SetLabelSize(15);

  c11->Update();
  c11->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoLF_topo_PID_Tune3.pdf");
    

  TCanvas *c12 = new TCanvas("c12", "c12", 900, 900);
  TPad *pad12 = new TPad("pad12", "pad12", 0, 0.3, 1, 1.0);
  pad12->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad12->Draw();             // Draw the upper pad: pad1
  pad12->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_CM-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_CM-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_CM-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_CM-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_CM-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_CM-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_CM = new THStack("reco_angle_p1p2_PID_Tune3_CM","");
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_CCQE_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_CCRes_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_CCNue_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_NC_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_other_PID_Tune3_CM);
  reco_angle_p1p2_PID_Tune3_CM-> Add(reco_angle_p1p2_OffBeam_PID_CM);
  //reco_angle_p1p2_PID_Tune3_CM->SetMaximum(50.);
  reco_angle_p1p2_PID_Tune3_CM-> Draw();
  reco_angle_p1p2_PID_Tune3_CM->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_CM->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_CM->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_CM->Draw("e1same");

  TLegend *l12 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l12 -> SetNColumns(2);
  l12 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_CM, "CCQE", "f");
  l12 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_CM, "CCRes", "f");
  l12 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_CM, "CCCoh", "f");
  l12 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_CM, "DIS", "f");
  l12 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_CM, "CCMEC", "f");
  l12 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_CM, "CC#nu_{e}", "f");
  l12 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_CM, "NC", "f");
  l12 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_CM, "other", "f");
  
  l12 -> AddEntry(reco_angle_p1p2_OffBeam_PID_CM, "off-beam data", "f");
  l12 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM, "on-beam data", "lep");
  l12 -> Draw();  
  
  TText *t12 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t12->Draw();

  c12->cd();
  TPad *pad12_2 = new TPad("pad12_2", "pad12_2", 0, 0.05, 1, 0.3);
  pad12_2->SetTopMargin(0.01);
  pad12_2->SetBottomMargin(0.2);
  pad12_2->SetGridx();
  pad12_2->SetGridy();
  pad12_2->Draw();
  pad12_2->cd();
  // Define the ratio plot
  TH1F *h12 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM->Clone("h12");
  TH1 *last12 = (TH1*)reco_angle_p1p2_PID_Tune3_CM->GetStack()->Last();

  chi2test = Chi2Calc(last12,reco_angle_p1p2_OnBeam_PID_CM, reco_angle_p1p2_OffBeam_PID_CM, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle CM reco chi2test : "<<chi2test<<std::endl;

  h12->SetLineColor(kBlack);
  h12->Sumw2();
  h12->SetStats(0);      // No statistics on lower plot
  h12->Divide(last12);
  h12->SetMarkerStyle(21);
  h12->SetTitle("");
  h12->Draw("ep");       // Draw the ratio plot

  h12->GetYaxis()->SetTitle("Data/MC");
  h12->GetYaxis()->SetNdivisions(505);
  h12->GetYaxis()->SetTitleSize(20);
  h12->GetYaxis()->SetTitleFont(43);
  h12->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h12->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h12->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h12->GetXaxis()->SetTitleSize(20);
  h12->GetXaxis()->SetTitleFont(43);
  h12->GetXaxis()->SetTitleOffset(3.);
  h12->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h12->GetXaxis()->SetLabelSize(15);

  c12->Update();
  c12->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoCM_topo_PID_Tune3.pdf");

  ///

  TCanvas *c13 = new TCanvas("c13", "c13", 900, 900);
  gStyle->SetOptStat(kFALSE);

  reco_angle_p1p2_p2_OnBeam_PID_LF->GetXaxis()->SetTitle("momentum least energetic proton [GeV]");
  reco_angle_p1p2_p2_OnBeam_PID_LF->GetYaxis()->SetTitle("cos#gamma");
  //reco_angle_p1p2_p2_OnBeam_PID_LF->SetMaximum(400.);
  reco_angle_p1p2_p2_OnBeam_PID_LF->Draw("colz");

  c13->Update();
  c13-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/reco_angle_p1p2_p2_OnBeam_PID_LF.pdf");

  TCanvas *c14 = new TCanvas("c14", "c14", 900, 900);
  gStyle->SetOptStat(kFALSE);

  reco_angle_p1p2_OnBeam_PID_LF_CM->GetXaxis()->SetTitle("cos#gamma");
  reco_angle_p1p2_OnBeam_PID_LF_CM->GetYaxis()->SetTitle("cos#gamma{'}");
  //reco_angle_p1p2_OnBeam_PID_LF_CM->SetMaximum(400.);
  reco_angle_p1p2_OnBeam_PID_LF_CM->Draw("colz");

  c14->Update();
  c14-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/reco_angle_p1p2_OnBeam_PID_LF_CM.pdf");

  TCanvas *c15 = new TCanvas("c15", "c15", 900, 900);
  gStyle->SetOptStat(kFALSE);

  p1p2_OnBeam_PID->GetXaxis()->SetTitle("reconstructed momentum p_{1} [GeV]");
  p1p2_OnBeam_PID->GetYaxis()->SetTitle("reconstructed momentum p_{2} [GeV]");
  //p1p2_OnBeam_PID->SetMaximum(400.);
  p1p2_OnBeam_PID->Draw("colz");

  c15->Update();
  c15-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/p1p2_OnBeam_PID.pdf");

  TCanvas *c16 = new TCanvas("c16", "c16", 900, 900);
  gStyle->SetOptStat(kFALSE);

  res_Enu_PID_Tune3->GetXaxis()->SetTitle("Truth E_{#nu} [GeV]");
  res_Enu_PID_Tune3->GetYaxis()->SetTitle("(Truth-Reco) E_{#nu} [GeV]");
  //res_Enu_PID_Tune3->SetMaximum(400.);
  res_Enu_PID_Tune3->Draw("colz");

  c16->Update();
  c16-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/res_Enu_PID_Tune3.pdf");
  /////////////////

  TCanvas *c17 = new TCanvas("c17", "c17", 900, 900);
  TPad *pad17 = new TPad("pad17", "pad17", 0, 0.3, 1, 1.0);
  pad17->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad17->Draw();             // Draw the upper pad: pad1
  pad17->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_LF_btb-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_LF_btb-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_LF_btb-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_LF_btb-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_LF_btb-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_LF_btb-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_LF_btb = new THStack("reco_angle_p1p2_PID_Tune3_LF_btb","");
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_CCQE_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_CCRes_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_CCNue_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_NC_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_other_PID_Tune3_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Add(reco_angle_p1p2_OffBeam_PID_LF_btb);
  reco_angle_p1p2_PID_Tune3_LF_btb->SetMaximum(30.);
  reco_angle_p1p2_PID_Tune3_LF_btb-> Draw();
  reco_angle_p1p2_PID_Tune3_LF_btb->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_LF_btb->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_LF_btb->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_LF_btb->Draw("e1same");

  TLegend *l17 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l17 -> SetNColumns(2);
  l17 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_LF_btb, "CCQE", "f");
  l17 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_LF_btb, "CCRes", "f");
  l17 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb, "CCCoh", "f");
  l17 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb, "DIS", "f");
  l17 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb, "CCMEC", "f");
  l17 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_LF_btb, "CC#nu_{e}", "f");
  l17 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_LF_btb, "NC", "f");
  l17 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_LF_btb, "other", "f");
  
  l17 -> AddEntry(reco_angle_p1p2_OffBeam_PID_LF_btb, "off-beam data", "f");
  l17 -> AddEntry(reco_angle_p1p2_OnBeam_PID_LF_btb, "on-beam data", "lep");
  l17 -> Draw();  
  
  TText *t17 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t17->Draw();

  c17->cd();
  TPad *pad17_2 = new TPad("pad17_2", "pad17_2", 0, 0.05, 1, 0.3);
  pad17_2->SetTopMargin(0.01);
  pad17_2->SetBottomMargin(0.2);
  pad17_2->SetGridx();
  pad17_2->SetGridy();
  pad17_2->Draw();
  pad17_2->cd();
  // Define the ratio plot
  TH1F *h17 = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF_btb->Clone("h17");
  TH1 *last17 = (TH1*)reco_angle_p1p2_PID_Tune3_LF_btb->GetStack()->Last();

  chi2test = Chi2Calc(last17,reco_angle_p1p2_OnBeam_PID_LF_btb, reco_angle_p1p2_OffBeam_PID_LF_btb, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle LF reco chi2test btb : "<<chi2test<<std::endl;

  h17->SetLineColor(kBlack);
  h17->Sumw2();
  h17->SetStats(0);      // No statistics on lower plot
  h17->Divide(last17);
  h17->SetMarkerStyle(21);
  h17->SetTitle("");
  h17->Draw("ep");       // Draw the ratio plot

  h17->GetYaxis()->SetTitle("Data/MC");
  h17->GetYaxis()->SetNdivisions(505);
  h17->GetYaxis()->SetTitleSize(20);
  h17->GetYaxis()->SetTitleFont(43);
  h17->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h17->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h17->GetXaxis()->SetTitle("reconstructed cos#theta_{p_{1} vs p_{2}} in lab frame");
  h17->GetXaxis()->SetTitleSize(20);
  h17->GetXaxis()->SetTitleFont(43);
  h17->GetXaxis()->SetTitleOffset(3.);
  h17->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h17->GetXaxis()->SetLabelSize(15);

  c17->Update();
  c17->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoLF_topo_PID_Tune3_btb.pdf");
    
  TCanvas *c18 = new TCanvas("c18", "c18", 900, 900);
  TPad *pad18 = new TPad("pad18", "pad18", 0, 0.3, 1, 1.0);
  pad18->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad18->Draw();             // Draw the upper pad: pad1
  pad18->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_CM_btb-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_CM_btb-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_CM_btb-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_CM_btb-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_CM_btb-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_CM_btb-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_CM_btb = new THStack("reco_angle_p1p2_PID_Tune3_CM_btb","");
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_CCQE_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_CCRes_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_CCNue_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_NC_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_other_PID_Tune3_CM_btb);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Add(reco_angle_p1p2_OffBeam_PID_CM_btb);
  //reco_angle_p1p2_PID_Tune3_CM_btb->SetMaximum(50.);
  reco_angle_p1p2_PID_Tune3_CM_btb-> Draw();
  reco_angle_p1p2_PID_Tune3_CM_btb->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_CM_btb->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_CM_btb->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_CM_btb->Draw("e1same");

  TLegend *l18 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l18 -> SetNColumns(2);
  l18 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_CM_btb, "CCQE", "f");
  l18 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_CM_btb, "CCRes", "f");
  l18 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb, "CCCoh", "f");
  l18 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb, "DIS", "f");
  l18 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb, "CCMEC", "f");
  l18 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_CM_btb, "CC#nu_{e}", "f");
  l18 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_CM_btb, "NC", "f");
  l18 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_CM_btb, "other", "f");
  
  l18 -> AddEntry(reco_angle_p1p2_OffBeam_PID_CM_btb, "off-beam data", "f");
  l18 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM_btb, "on-beam data", "lep");
  l18 -> Draw();  
  
  TText *t18 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t18->Draw();

  c18->cd();
  TPad *pad18_2 = new TPad("pad18_2", "pad18_2", 0, 0.05, 1, 0.3);
  pad18_2->SetTopMargin(0.01);
  pad18_2->SetBottomMargin(0.2);
  pad18_2->SetGridx();
  pad18_2->SetGridy();
  pad18_2->Draw();
  pad18_2->cd();
  // Define the ratio plot
  TH1F *h18 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_btb->Clone("h18");
  TH1 *last18 = (TH1*)reco_angle_p1p2_PID_Tune3_CM_btb->GetStack()->Last();

  chi2test = Chi2Calc(last18,reco_angle_p1p2_OnBeam_PID_CM_btb, reco_angle_p1p2_OffBeam_PID_CM_btb, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle CM reco chi2test btb : "<<chi2test<<std::endl;

  h18->SetLineColor(kBlack);
  h18->Sumw2();
  h18->SetStats(0);      // No statistics on lower plot
  h18->Divide(last18);
  h18->SetMarkerStyle(21);
  h18->SetTitle("");
  h18->Draw("ep");       // Draw the ratio plot

  h18->GetYaxis()->SetTitle("Data/MC");
  h18->GetYaxis()->SetNdivisions(505);
  h18->GetYaxis()->SetTitleSize(20);
  h18->GetYaxis()->SetTitleFont(43);
  h18->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h18->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h18->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h18->GetXaxis()->SetTitleSize(20);
  h18->GetXaxis()->SetTitleFont(43);
  h18->GetXaxis()->SetTitleOffset(3.);
  h18->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h18->GetXaxis()->SetLabelSize(15);

  c18->Update();
  c18->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoCM_topo_PID_Tune3_btb.pdf");

  ///

  TCanvas *c19 = new TCanvas("c19", "c19", 900, 900);
  gStyle->SetOptStat(kFALSE);

  reco_angle_p1p2_p2_OnBeam_PID_LF_btb->GetXaxis()->SetTitle("momentum least energetic proton [GeV]");
  reco_angle_p1p2_p2_OnBeam_PID_LF_btb->GetYaxis()->SetTitle("cos#gamma");
  //reco_angle_p1p2_p2_OnBeam_PID_LF_btb->SetMaximum(400.);
  reco_angle_p1p2_p2_OnBeam_PID_LF_btb->Draw("colz");

  c19->Update();
  c19-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/reco_angle_p1p2_p2_OnBeam_PID_LF_btb.pdf");

  /////////

  TCanvas *c20 = new TCanvas("c20", "c20", 900, 900);
  TPad *pad20 = new TPad("pad20", "pad20", 0, 0.3, 1, 1.0);
  pad20->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad20->Draw();             // Draw the upper pad: pad1
  pad20->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_LF_zoom-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_LF_zoom-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF_zoom-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF_zoom-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF_zoom-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_LF_zoom-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_LF_zoom-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_LF_zoom-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_LF_zoom-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_LF_zoom = new THStack("reco_angle_p1p2_PID_Tune3_LF_zoom","");
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_CCQE_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_CCRes_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_CCNue_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_NC_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_other_PID_Tune3_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Add(reco_angle_p1p2_OffBeam_PID_LF_zoom);
  reco_angle_p1p2_PID_Tune3_LF_zoom->SetMaximum(60.);
  reco_angle_p1p2_PID_Tune3_LF_zoom-> Draw();
  reco_angle_p1p2_PID_Tune3_LF_zoom->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->Draw("e1same");

  TLegend *l20 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l20 -> SetNColumns(2);
  l20 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_LF_zoom, "CCQE", "f");
  l20 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_LF_zoom, "CCRes", "f");
  l20 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_LF_zoom, "CCCoh", "f");
  l20 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_LF_zoom, "DIS", "f");
  l20 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_LF_zoom, "CCMEC", "f");
  l20 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_LF_zoom, "CC#nu_{e}", "f");
  l20 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_LF_zoom, "NC", "f");
  l20 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_LF_zoom, "other", "f");
  
  l20 -> AddEntry(reco_angle_p1p2_OffBeam_PID_LF_zoom, "off-beam data", "f");
  l20 -> AddEntry(reco_angle_p1p2_OnBeam_PID_LF_zoom, "on-beam data", "lep");
  l20 -> Draw();  
  
  TText *t20 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t20->Draw();

  c20->cd();
  TPad *pad20_2 = new TPad("pad20_2", "pad20_2", 0, 0.05, 1, 0.3);
  pad20_2->SetTopMargin(0.01);
  pad20_2->SetBottomMargin(0.2);
  pad20_2->SetGridx();
  pad20_2->SetGridy();
  pad20_2->Draw();
  pad20_2->cd();
  // Define the ratio plot
  TH1F *h20 = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF_zoom->Clone("h20");
  TH1 *last20 = (TH1*)reco_angle_p1p2_PID_Tune3_LF_zoom->GetStack()->Last();

  chi2test = Chi2Calc(last20,reco_angle_p1p2_OnBeam_PID_LF_zoom, reco_angle_p1p2_OffBeam_PID_LF_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle LF reco chi2test zoom : "<<chi2test<<std::endl;

  h20->SetLineColor(kBlack);
  h20->Sumw2();
  h20->SetStats(0);      // No statistics on lower plot
  h20->Divide(last20);
  h20->SetMarkerStyle(21);
  h20->SetTitle("");
  h20->Draw("ep");       // Draw the ratio plot

  h20->GetYaxis()->SetTitle("Data/MC");
  h20->GetYaxis()->SetNdivisions(505);
  h20->GetYaxis()->SetTitleSize(20);
  h20->GetYaxis()->SetTitleFont(43);
  h20->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h20->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h20->GetXaxis()->SetTitle("reconstructed cos#theta_{p_{1} vs p_{2}} in lab frame");
  h20->GetXaxis()->SetTitleSize(20);
  h20->GetXaxis()->SetTitleFont(43);
  h20->GetXaxis()->SetTitleOffset(3.);
  h20->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h20->GetXaxis()->SetLabelSize(15);

  c20->Update();
  c20->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoLF_topo_PID_Tune3_zoom.pdf");
    
  TCanvas *c21 = new TCanvas("c21", "c21", 900, 900);
  TPad *pad21 = new TPad("pad21", "pad21", 0, 0.3, 1, 1.0);
  pad21->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad21->Draw();             // Draw the upper pad: pad1
  pad21->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_CM_zoom-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_CM_zoom-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM_zoom-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM_zoom-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM_zoom-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_CM_zoom-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_CM_zoom-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_CM_zoom-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_CM_zoom-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_CM_zoom = new THStack("reco_angle_p1p2_PID_Tune3_CM_zoom","");
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_CCQE_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_CCRes_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_CCNue_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_NC_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_other_PID_Tune3_CM_zoom);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Add(reco_angle_p1p2_OffBeam_PID_CM_zoom);
  //reco_angle_p1p2_PID_Tune3_CM_zoom->SetMaximum(50.);
  reco_angle_p1p2_PID_Tune3_CM_zoom-> Draw();
  reco_angle_p1p2_PID_Tune3_CM_zoom->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->Draw("e1same");

  TLegend *l21 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l21 -> SetNColumns(2);
  l21 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_CM_zoom, "CCQE", "f");
  l21 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_CM_zoom, "CCRes", "f");
  l21 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_CM_zoom, "CCCoh", "f");
  l21 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_CM_zoom, "DIS", "f");
  l21 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_CM_zoom, "CCMEC", "f");
  l21 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_CM_zoom, "CC#nu_{e}", "f");
  l21 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_CM_zoom, "NC", "f");
  l21 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_CM_zoom, "other", "f");
  
  l21 -> AddEntry(reco_angle_p1p2_OffBeam_PID_CM_zoom, "off-beam data", "f");
  l21 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM_zoom, "on-beam data", "lep");
  l21 -> Draw();  
  
  TText *t21 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t21->Draw();

  c21->cd();
  TPad *pad21_2 = new TPad("pad21_2", "pad21_2", 0, 0.05, 1, 0.3);
  pad21_2->SetTopMargin(0.01);
  pad21_2->SetBottomMargin(0.2);
  pad21_2->SetGridx();
  pad21_2->SetGridy();
  pad21_2->Draw();
  pad21_2->cd();
  // Define the ratio plot
  TH1F *h21 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_zoom->Clone("h21");
  TH1 *last21 = (TH1*)reco_angle_p1p2_PID_Tune3_CM_zoom->GetStack()->Last();

  chi2test = Chi2Calc(last21,reco_angle_p1p2_OnBeam_PID_CM_zoom, reco_angle_p1p2_OffBeam_PID_CM_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle CM reco chi2test : "<<chi2test<<std::endl;

  h21->SetLineColor(kBlack);
  h21->Sumw2();
  h21->SetStats(0);      // No statistics on lower plot
  h21->Divide(last21);
  h21->SetMarkerStyle(21);
  h21->SetTitle("");
  h21->Draw("ep");       // Draw the ratio plot

  h21->GetYaxis()->SetTitle("Data/MC");
  h21->GetYaxis()->SetNdivisions(505);
  h21->GetYaxis()->SetTitleSize(20);
  h21->GetYaxis()->SetTitleFont(43);
  h21->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h21->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h21->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h21->GetXaxis()->SetTitleSize(20);
  h21->GetXaxis()->SetTitleFont(43);
  h21->GetXaxis()->SetTitleOffset(3.);
  h21->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h21->GetXaxis()->SetLabelSize(15);

  c21->Update();
  c21->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoCM_topo_PID_Tune3_zoom.pdf");

  TCanvas *c22 = new TCanvas("c22", "c22", 900, 900);
  TPad *pad22 = new TPad("pad22", "pad22", 0, 0.3, 1, 1.0);
  pad22->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad22->Draw();             // Draw the upper pad: pad1
  pad22->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_LF_btb_zoom-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_LF_btb_zoom-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb_zoom-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb_zoom-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb_zoom-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_LF_btb_zoom-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_LF_btb_zoom-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_LF_btb_zoom-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_LF_btb_zoom-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_LF_btb_zoom = new THStack("reco_angle_p1p2_PID_Tune3_LF_btb_zoom","");
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_CCQE_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_CCRes_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_CCNue_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_NC_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_other_PID_Tune3_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Add(reco_angle_p1p2_OffBeam_PID_LF_btb_zoom);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom->SetMaximum(20.);
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom-> Draw();
  reco_angle_p1p2_PID_Tune3_LF_btb_zoom->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_LF_btb_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_LF_btb_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_LF_btb_zoom->Draw("e1same");

  TLegend *l22 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l22 -> SetNColumns(2);
  l22 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_LF_btb_zoom, "CCQE", "f");
  l22 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_LF_btb_zoom, "CCRes", "f");
  l22 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_LF_btb_zoom, "CCCoh", "f");
  l22 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_LF_btb_zoom, "DIS", "f");
  l22 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_LF_btb_zoom, "CCMEC", "f");
  l22 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_LF_btb_zoom, "CC#nu_{e}", "f");
  l22 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_LF_btb_zoom, "NC", "f");
  l22 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_LF_btb_zoom, "other", "f");
  
  l22 -> AddEntry(reco_angle_p1p2_OffBeam_PID_LF_btb_zoom, "off-beam data", "f");
  l22 -> AddEntry(reco_angle_p1p2_OnBeam_PID_LF_btb_zoom, "on-beam data", "lep");
  l22 -> Draw();  
  
  TText *t22 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t22->Draw();

  c22->cd();
  TPad *pad22_2 = new TPad("pad22_2", "pad22_2", 0, 0.05, 1, 0.3);
  pad22_2->SetTopMargin(0.01);
  pad22_2->SetBottomMargin(0.2);
  pad22_2->SetGridx();
  pad22_2->SetGridy();
  pad22_2->Draw();
  pad22_2->cd();
  // Define the ratio plot
  TH1F *h22 = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF_btb_zoom->Clone("h22");
  TH1 *last22 = (TH1*)reco_angle_p1p2_PID_Tune3_LF_btb_zoom->GetStack()->Last();

  chi2test = Chi2Calc(last22,reco_angle_p1p2_OnBeam_PID_LF_btb_zoom, reco_angle_p1p2_OffBeam_PID_LF_btb_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle LF reco chi2test btb : "<<chi2test<<std::endl;

  h22->SetLineColor(kBlack);
  h22->Sumw2();
  h22->SetStats(0);      // No statistics on lower plot
  h22->Divide(last22);
  h22->SetMarkerStyle(21);
  h22->SetTitle("");
  h22->Draw("ep");       // Draw the ratio plot

  h22->GetYaxis()->SetTitle("Data/MC");
  h22->GetYaxis()->SetNdivisions(505);
  h22->GetYaxis()->SetTitleSize(20);
  h22->GetYaxis()->SetTitleFont(43);
  h22->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h22->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h22->GetXaxis()->SetTitle("reconstructed cos#theta_{p_{1} vs p_{2}} in lab frame");
  h22->GetXaxis()->SetTitleSize(20);
  h22->GetXaxis()->SetTitleFont(43);
  h22->GetXaxis()->SetTitleOffset(3.);
  h22->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h22->GetXaxis()->SetLabelSize(15);

  c22->Update();
  c22->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoLF_topo_PID_Tune3_btb_zoom.pdf");
    
  TCanvas *c23 = new TCanvas("c23", "c23", 900, 900);
  TPad *pad23 = new TPad("pad23", "pad23", 0, 0.3, 1, 1.0);
  pad23->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad23->Draw();             // Draw the upper pad: pad1
  pad23->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_PID_Tune3_CM_btb_zoom-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_PID_Tune3_CM_btb_zoom-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb_zoom-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb_zoom-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb_zoom-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_PID_Tune3_CM_btb_zoom-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_PID_Tune3_CM_btb_zoom-> SetFillColor(31);
  reco_angle_p1p2_other_PID_Tune3_CM_btb_zoom-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_PID_CM_btb_zoom-> SetFillColor(kGray);

  THStack *reco_angle_p1p2_PID_Tune3_CM_btb_zoom = new THStack("reco_angle_p1p2_PID_Tune3_CM_btb_zoom","");
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_CCQE_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_CCRes_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_CCNue_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_NC_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_other_PID_Tune3_CM_btb_zoom);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Add(reco_angle_p1p2_OffBeam_PID_CM_btb_zoom);
  //reco_angle_p1p2_PID_Tune3_CM_btb_zoom->SetMaximum(50.);
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom-> Draw();
  reco_angle_p1p2_PID_Tune3_CM_btb_zoom->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_PID_CM_btb_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_CM_btb_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_CM_btb_zoom->Draw("e1same");

  TLegend *l23 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l23 -> SetNColumns(2);
  l23 -> AddEntry(reco_angle_p1p2_CCQE_PID_Tune3_CM_btb_zoom, "CCQE", "f");
  l23 -> AddEntry(reco_angle_p1p2_CCRes_PID_Tune3_CM_btb_zoom, "CCRes", "f");
  l23 -> AddEntry(reco_angle_p1p2_CCCoh_PID_Tune3_CM_btb_zoom, "CCCoh", "f");
  l23 -> AddEntry(reco_angle_p1p2_CCDIS_PID_Tune3_CM_btb_zoom, "DIS", "f");
  l23 -> AddEntry(reco_angle_p1p2_CCMEC_PID_Tune3_CM_btb_zoom, "CCMEC", "f");
  l23 -> AddEntry(reco_angle_p1p2_CCNue_PID_Tune3_CM_btb_zoom, "CC#nu_{e}", "f");
  l23 -> AddEntry(reco_angle_p1p2_NC_PID_Tune3_CM_btb_zoom, "NC", "f");
  l23 -> AddEntry(reco_angle_p1p2_other_PID_Tune3_CM_btb_zoom, "other", "f");
  
  l23 -> AddEntry(reco_angle_p1p2_OffBeam_PID_CM_btb_zoom, "off-beam data", "f");
  l23 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM_btb_zoom, "on-beam data", "lep");
  l23 -> Draw();  
  
  TText *t23 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t23->Draw();

  c23->cd();
  TPad *pad23_2 = new TPad("pad23_2", "pad23_2", 0, 0.05, 1, 0.3);
  pad23_2->SetTopMargin(0.01);
  pad23_2->SetBottomMargin(0.2);
  pad23_2->SetGridx();
  pad23_2->SetGridy();
  pad23_2->Draw();
  pad23_2->cd();
  // Define the ratio plot
  TH1F *h23 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_btb_zoom->Clone("h23");
  TH1 *last23 = (TH1*)reco_angle_p1p2_PID_Tune3_CM_btb_zoom->GetStack()->Last();

  chi2test = Chi2Calc(last23,reco_angle_p1p2_OnBeam_PID_CM_btb_zoom, reco_angle_p1p2_OffBeam_PID_CM_btb_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cosangle CM reco chi2test btb : "<<chi2test<<std::endl;

  h23->SetLineColor(kBlack);
  h23->Sumw2();
  h23->SetStats(0);      // No statistics on lower plot
  h23->Divide(last23);
  h23->SetMarkerStyle(21);
  h23->SetTitle("");
  h23->Draw("ep");       // Draw the ratio plot

  h23->GetYaxis()->SetTitle("Data/MC");
  h23->GetYaxis()->SetNdivisions(505);
  h23->GetYaxis()->SetTitleSize(20);
  h23->GetYaxis()->SetTitleFont(43);
  h23->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h23->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h23->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h23->GetXaxis()->SetTitleSize(20);
  h23->GetXaxis()->SetTitleFont(43);
  h23->GetXaxis()->SetTitleOffset(3.);
  h23->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h23->GetXaxis()->SetLabelSize(15);

  c23->Update();
  c23->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/cosanglep1p2RecoCM_topo_PID_Tune3_btb_zoom.pdf");

  TCanvas *c24 = new TCanvas("c24", "c24", 900, 900);
  TPad *pad24 = new TPad("pad24", "pad24", 0, 0.3, 1, 1.0);
  pad24->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad24->Draw();             // Draw the upper pad: pad1
  pad24->cd();              // pad1 becomes the current pad

  reco_PT_CCQE_1binCM_PID_Tune3-> SetFillColor(kRed -10);
  reco_PT_CCRes_1binCM_PID_Tune3-> SetFillColor(kGreen-8);
  reco_PT_CCCoh_1binCM_PID_Tune3-> SetFillColor(kAzure+4);
  reco_PT_CCDIS_1binCM_PID_Tune3-> SetFillColor(kRed-9);
  reco_PT_CCMEC_1binCM_PID_Tune3-> SetFillColor(kOrange);
  reco_PT_CCNue_1binCM_PID_Tune3-> SetFillColor(kCyan-8);
  reco_PT_NC_1binCM_PID_Tune3-> SetFillColor(31);
  reco_PT_other_1binCM_PID_Tune3-> SetFillColor(kOrange+6);
  reco_PT_OffBeam_1binCM_PID-> SetFillColor(kGray);

  THStack *reco_PT_1binCM_PID_Tune3 = new THStack("reco_PT_1binCM_PID_Tune3","");
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_CCQE_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_CCRes_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_CCCoh_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_CCDIS_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_CCMEC_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_CCNue_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_NC_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_other_1binCM_PID_Tune3);
  reco_PT_1binCM_PID_Tune3-> Add(reco_PT_OffBeam_1binCM_PID);
  //reco_PT_1binCM_PID_Tune3->SetMaximum(50.);
  reco_PT_1binCM_PID_Tune3-> Draw();
  reco_PT_1binCM_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_PT_OnBeam_1binCM_PID->SetLineColor(kBlack);
  reco_PT_OnBeam_1binCM_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_1binCM_PID->Draw("e1same");

  TLegend *l24 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l24 -> SetNColumns(2);
  l24 -> AddEntry(reco_PT_CCQE_1binCM_PID_Tune3, "CCQE", "f");
  l24 -> AddEntry(reco_PT_CCRes_1binCM_PID_Tune3, "CCRes", "f");
  l24 -> AddEntry(reco_PT_CCCoh_1binCM_PID_Tune3, "CCCoh", "f");
  l24 -> AddEntry(reco_PT_CCDIS_1binCM_PID_Tune3, "DIS", "f");
  l24 -> AddEntry(reco_PT_CCMEC_1binCM_PID_Tune3, "CCMEC", "f");
  l24 -> AddEntry(reco_PT_CCNue_1binCM_PID_Tune3, "CC#nu_{e}", "f");
  l24 -> AddEntry(reco_PT_NC_1binCM_PID_Tune3, "NC", "f");
  l24 -> AddEntry(reco_PT_other_1binCM_PID_Tune3, "other", "f");

  l24 -> AddEntry(reco_PT_OffBeam_1binCM_PID, "off-beam data", "f");
  l24 -> AddEntry(reco_PT_OnBeam_1binCM_PID, "on-beam data", "lep");
  l24 -> Draw();  
  
  TText *t24 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t24->Draw();

  c24->cd();
  TPad *pad24_2 = new TPad("pad24_2", "pad24_2", 0, 0.05, 1, 0.3);
  pad24_2->SetTopMargin(0.01);
  pad24_2->SetBottomMargin(0.2);
  pad24_2->SetGridx();
  pad24_2->SetGridy();
  pad24_2->Draw();
  pad24_2->cd();
  // Define the ratio plot
  TH1F *h24 = (TH1F*)reco_PT_OnBeam_1binCM_PID->Clone("h24");
  TH1 *last24 = (TH1*)reco_PT_1binCM_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last24,reco_PT_OnBeam_1binCM_PID, reco_PT_OffBeam_1binCM_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  PT reco 1binCM chi2test : "<<chi2test<<std::endl;

  h24->SetLineColor(kBlack);
  h24->Sumw2();
  h24->SetStats(0);      // No statistics on lower plot
  h24->Divide(last24);
  h24->SetMarkerStyle(21);
  h24->SetTitle("");
  h24->Draw("ep");       // Draw the ratio plot

  h24->GetYaxis()->SetTitle("Data/MC");
  h24->GetYaxis()->SetNdivisions(505);
  h24->GetYaxis()->SetTitleSize(20);
  h24->GetYaxis()->SetTitleFont(43);
  h24->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h24->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h24->GetXaxis()->SetTitle("reconstructed missing P_{T} [GeV]");
  h24->GetXaxis()->SetTitleSize(20);
  h24->GetXaxis()->SetTitleFont(43);
  h24->GetXaxis()->SetTitleOffset(3.);
  h24->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h24->GetXaxis()->SetLabelSize(15);

  c24->Update();
  c24->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/PTReco_topo_1bibCM_PID_Tune3.pdf");

  TCanvas *c25 = new TCanvas("c25", "c25", 900, 900);
  TPad *pad25 = new TPad("pad25", "pad25", 0, 0.3, 1, 1.0);
  pad25->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad25->Draw();             // Draw the upper pad: pad1
  pad25->cd();              // pad1 becomes the current pad

  reco_p1p2_CCQE_PID_Tune3-> SetFillColor(kRed -10);
  reco_p1p2_CCRes_PID_Tune3-> SetFillColor(kGreen-8);
  reco_p1p2_CCCoh_PID_Tune3-> SetFillColor(kAzure+4);
  reco_p1p2_CCDIS_PID_Tune3-> SetFillColor(kRed-9);
  reco_p1p2_CCMEC_PID_Tune3-> SetFillColor(kOrange);
  reco_p1p2_CCNue_PID_Tune3-> SetFillColor(kCyan-8);
  reco_p1p2_NC_PID_Tune3-> SetFillColor(31);
  reco_p1p2_other_PID_Tune3-> SetFillColor(kOrange+6);
  reco_p1p2_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_p1p2_PID_Tune3 = new THStack("reco_p1p2_PID_Tune3","");
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_CCQE_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_CCRes_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_CCCoh_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_CCDIS_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_CCMEC_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_CCNue_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_NC_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_other_PID_Tune3);
  reco_p1p2_PID_Tune3-> Add(reco_p1p2_OffBeam_PID);
  //reco_p1p2_PID_Tune3->SetMaximum(50.);
  reco_p1p2_PID_Tune3-> Draw();
  reco_p1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_p1p2_OnBeam_PID->SetLineColor(kBlack);
  reco_p1p2_OnBeam_PID->SetMarkerStyle(20);
  reco_p1p2_OnBeam_PID->Draw("e1same");

  TLegend *l25 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l25 -> SetNColumns(2);
  l25 -> AddEntry(reco_p1p2_CCQE_PID_Tune3, "CCQE", "f");
  l25 -> AddEntry(reco_p1p2_CCRes_PID_Tune3, "CCRes", "f");
  l25 -> AddEntry(reco_p1p2_CCCoh_PID_Tune3, "CCCoh", "f");
  l25 -> AddEntry(reco_p1p2_CCDIS_PID_Tune3, "DIS", "f");
  l25 -> AddEntry(reco_p1p2_CCMEC_PID_Tune3, "CCMEC", "f");
  l25 -> AddEntry(reco_p1p2_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l25 -> AddEntry(reco_p1p2_NC_PID_Tune3, "NC", "f");
  l25 -> AddEntry(reco_p1p2_other_PID_Tune3, "other", "f");

  l25 -> AddEntry(reco_p1p2_OffBeam_PID, "off-beam data", "f");
  l25 -> AddEntry(reco_p1p2_OnBeam_PID, "on-beam data", "lep");
  l25 -> Draw();  
  
  TText *t25 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t25->Draw();

  c25->cd();
  TPad *pad25_2 = new TPad("pad25_2", "pad25_2", 0, 0.05, 1, 0.3);
  pad25_2->SetTopMargin(0.01);
  pad25_2->SetBottomMargin(0.2);
  pad25_2->SetGridx();
  pad25_2->SetGridy();
  pad25_2->Draw();
  pad25_2->cd();
  // Define the ratio plot
  TH1F *h25 = (TH1F*)reco_p1p2_OnBeam_PID->Clone("h25");
  TH1 *last25 = (TH1*)reco_p1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last25,reco_p1p2_OnBeam_PID, reco_p1p2_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  p1+ p2 reco chi2test : "<<chi2test<<std::endl;

  h25->SetLineColor(kBlack);
  h25->Sumw2();
  h25->SetStats(0);      // No statistics on lower plot
  h25->Divide(last25);
  h25->SetMarkerStyle(21);
  h25->SetTitle("");
  h25->Draw("ep");       // Draw the ratio plot

  h25->GetYaxis()->SetTitle("Data/MC");
  h25->GetYaxis()->SetNdivisions(505);
  h25->GetYaxis()->SetTitleSize(20);
  h25->GetYaxis()->SetTitleFont(43);
  h25->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h25->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h25->GetXaxis()->SetTitle("reconstructed p_{1} + p_{2} [GeV]");
  h25->GetXaxis()->SetTitleSize(20);
  h25->GetXaxis()->SetTitleFont(43);
  h25->GetXaxis()->SetTitleOffset(3.);
  h25->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h25->GetXaxis()->SetLabelSize(15);

  c25->Update();
  c25->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/p1p2Reco_topo_PID_Tune3.pdf"); 

  TCanvas *c26 = new TCanvas("c26", "c26", 900, 900);
  TPad *pad26 = new TPad("pad26", "pad26", 0, 0.3, 1, 1.0);
  pad26->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad26->Draw();             // Draw the upper pad: pad1
  pad26->cd();              // pad1 becomes the current pad

  reco_dp1p2_CCQE_PID_Tune3-> SetFillColor(kRed -10);
  reco_dp1p2_CCRes_PID_Tune3-> SetFillColor(kGreen-8);
  reco_dp1p2_CCCoh_PID_Tune3-> SetFillColor(kAzure+4);
  reco_dp1p2_CCDIS_PID_Tune3-> SetFillColor(kRed-9);
  reco_dp1p2_CCMEC_PID_Tune3-> SetFillColor(kOrange);
  reco_dp1p2_CCNue_PID_Tune3-> SetFillColor(kCyan-8);
  reco_dp1p2_NC_PID_Tune3-> SetFillColor(31);
  reco_dp1p2_other_PID_Tune3-> SetFillColor(kOrange+6);
  reco_dp1p2_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_dp1p2_PID_Tune3 = new THStack("reco_dp1p2_PID_Tune3","");
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_CCQE_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_CCRes_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_CCCoh_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_CCDIS_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_CCMEC_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_CCNue_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_NC_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_other_PID_Tune3);
  reco_dp1p2_PID_Tune3-> Add(reco_dp1p2_OffBeam_PID);
  //reco_dp1p2_PID_Tune3->SetMaximum(50.);
  reco_dp1p2_PID_Tune3-> Draw();
  reco_dp1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_dp1p2_OnBeam_PID->SetLineColor(kBlack);
  reco_dp1p2_OnBeam_PID->SetMarkerStyle(20);
  reco_dp1p2_OnBeam_PID->Draw("e1same");

  TLegend *l26 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l26 -> SetNColumns(2);
  l26 -> AddEntry(reco_dp1p2_CCQE_PID_Tune3, "CCQE", "f");
  l26 -> AddEntry(reco_dp1p2_CCRes_PID_Tune3, "CCRes", "f");
  l26 -> AddEntry(reco_dp1p2_CCCoh_PID_Tune3, "CCCoh", "f");
  l26 -> AddEntry(reco_dp1p2_CCDIS_PID_Tune3, "DIS", "f");
  l26 -> AddEntry(reco_dp1p2_CCMEC_PID_Tune3, "CCMEC", "f");
  l26 -> AddEntry(reco_dp1p2_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l26 -> AddEntry(reco_dp1p2_NC_PID_Tune3, "NC", "f");
  l26 -> AddEntry(reco_dp1p2_other_PID_Tune3, "other", "f");

  l26 -> AddEntry(reco_dp1p2_OffBeam_PID, "off-beam data", "f");
  l26 -> AddEntry(reco_dp1p2_OnBeam_PID, "on-beam data", "lep");
  l26 -> Draw();  
  
  TText *t26 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t26->Draw();

  c26->cd();
  TPad *pad26_2 = new TPad("pad26_2", "pad26_2", 0, 0.05, 1, 0.3);
  pad26_2->SetTopMargin(0.01);
  pad26_2->SetBottomMargin(0.2);
  pad26_2->SetGridx();
  pad26_2->SetGridy();
  pad26_2->Draw();
  pad26_2->cd();
  // Define the ratio plot
  TH1F *h26 = (TH1F*)reco_dp1p2_OnBeam_PID->Clone("h26");
  TH1 *last26 = (TH1*)reco_dp1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last26,reco_dp1p2_OnBeam_PID, reco_dp1p2_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  p1- p2 reco chi2test : "<<chi2test<<std::endl;

  h26->SetLineColor(kBlack);
  h26->Sumw2();
  h26->SetStats(0);      // No statistics on lower plot
  h26->Divide(last26);
  h26->SetMarkerStyle(21);
  h26->SetTitle("");
  h26->Draw("ep");       // Draw the ratio plot

  h26->GetYaxis()->SetTitle("Data/MC");
  h26->GetYaxis()->SetNdivisions(505);
  h26->GetYaxis()->SetTitleSize(20);
  h26->GetYaxis()->SetTitleFont(43);
  h26->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h26->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h26->GetXaxis()->SetTitle("reconstructed p_{1} - p_{2} [GeV]");
  h26->GetXaxis()->SetTitleSize(20);
  h26->GetXaxis()->SetTitleFont(43);
  h26->GetXaxis()->SetTitleOffset(3.);
  h26->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h26->GetXaxis()->SetLabelSize(15);

  c26->Update();
  c26->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/dp1p2Reco_topo_PID_Tune3.pdf"); 

  TCanvas *c27 = new TCanvas("c27", "c27", 900, 900);
  TPad *pad27 = new TPad("pad27", "pad27", 0, 0.3, 1, 1.0);
  pad27->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad27->Draw();             // Draw the upper pad: pad1
  pad27->cd();              // pad1 becomes the current pad

  reco_kp1p2_CCQE_PID_Tune3-> SetFillColor(kRed -10);
  reco_kp1p2_CCRes_PID_Tune3-> SetFillColor(kGreen-8);
  reco_kp1p2_CCCoh_PID_Tune3-> SetFillColor(kAzure+4);
  reco_kp1p2_CCDIS_PID_Tune3-> SetFillColor(kRed-9);
  reco_kp1p2_CCMEC_PID_Tune3-> SetFillColor(kOrange);
  reco_kp1p2_CCNue_PID_Tune3-> SetFillColor(kCyan-8);
  reco_kp1p2_NC_PID_Tune3-> SetFillColor(31);
  reco_kp1p2_other_PID_Tune3-> SetFillColor(kOrange+6);
  reco_kp1p2_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_kp1p2_PID_Tune3 = new THStack("reco_kp1p2_PID_Tune3","");
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_CCQE_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_CCRes_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_CCCoh_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_CCDIS_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_CCMEC_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_CCNue_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_NC_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_other_PID_Tune3);
  reco_kp1p2_PID_Tune3-> Add(reco_kp1p2_OffBeam_PID);
  //reco_kp1p2_PID_Tune3->SetMaximum(50.);
  reco_kp1p2_PID_Tune3-> Draw();
  reco_kp1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_kp1p2_OnBeam_PID->SetLineColor(kBlack);
  reco_kp1p2_OnBeam_PID->SetMarkerStyle(20);
  reco_kp1p2_OnBeam_PID->Draw("e1same");

  TLegend *l27 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l27 -> SetNColumns(2);
  l27 -> AddEntry(reco_kp1p2_CCQE_PID_Tune3, "CCQE", "f");
  l27 -> AddEntry(reco_kp1p2_CCRes_PID_Tune3, "CCRes", "f");
  l27 -> AddEntry(reco_kp1p2_CCCoh_PID_Tune3, "CCCoh", "f");
  l27 -> AddEntry(reco_kp1p2_CCDIS_PID_Tune3, "DIS", "f");
  l27 -> AddEntry(reco_kp1p2_CCMEC_PID_Tune3, "CCMEC", "f");
  l27 -> AddEntry(reco_kp1p2_CCNue_PID_Tune3, "CC#nu_{e}", "f");
  l27 -> AddEntry(reco_kp1p2_NC_PID_Tune3, "NC", "f");
  l27 -> AddEntry(reco_kp1p2_other_PID_Tune3, "other", "f");

  l27 -> AddEntry(reco_kp1p2_OffBeam_PID, "off-beam data", "f");
  l27 -> AddEntry(reco_kp1p2_OnBeam_PID, "on-beam data", "lep");
  l27 -> Draw();  
  
  TText *t27 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t27->Draw();

  c27->cd();
  TPad *pad27_2 = new TPad("pad27_2", "pad27_2", 0, 0.05, 1, 0.3);
  pad27_2->SetTopMargin(0.01);
  pad27_2->SetBottomMargin(0.2);
  pad27_2->SetGridx();
  pad27_2->SetGridy();
  pad27_2->Draw();
  pad27_2->cd();
  // Define the ratio plot
  TH1F *h27 = (TH1F*)reco_kp1p2_OnBeam_PID->Clone("h27");
  TH1 *last27 = (TH1*)reco_kp1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last27,reco_kp1p2_OnBeam_PID, reco_kp1p2_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  k (p1+ p2) reco chi2test : "<<chi2test<<std::endl;

  h27->SetLineColor(kBlack);
  h27->Sumw2();
  h27->SetStats(0);      // No statistics on lower plot
  h27->Divide(last27);
  h27->SetMarkerStyle(21);
  h27->SetTitle("");
  h27->Draw("ep");       // Draw the ratio plot

  h27->GetYaxis()->SetTitle("Data/MC");
  h27->GetYaxis()->SetNdivisions(505);
  h27->GetYaxis()->SetTitleSize(20);
  h27->GetYaxis()->SetTitleFont(43);
  h27->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h27->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h27->GetXaxis()->SetTitle("reconstructed KE_{p_{1}} + KE_{p_{2}} [GeV]");
  h27->GetXaxis()->SetTitleSize(20);
  h27->GetXaxis()->SetTitleFont(43);
  h27->GetXaxis()->SetTitleOffset(3.);
  h27->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h27->GetXaxis()->SetLabelSize(15);

  c27->Update();
  c27->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/kp1p2Reco_topo_PID_Tune3.pdf"); 

  
  TCanvas *c28 = new TCanvas("c28", "c28", 900, 900);
  TPad *pad28 = new TPad("pad28", "pad28", 0, 0.3, 1, 1.0);
  pad28->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad28->Draw();             // Draw the upper pad: pad1
  pad28->cd();              // pad1 becomes the current pad

  reco_kp1p2_CCQE_PID_Tune3_btb-> SetFillColor(kRed -10);
  reco_kp1p2_CCRes_PID_Tune3_btb-> SetFillColor(kGreen-8);
  reco_kp1p2_CCCoh_PID_Tune3_btb-> SetFillColor(kAzure+4);
  reco_kp1p2_CCDIS_PID_Tune3_btb-> SetFillColor(kRed-9);
  reco_kp1p2_CCMEC_PID_Tune3_btb-> SetFillColor(kOrange);
  reco_kp1p2_CCNue_PID_Tune3_btb-> SetFillColor(kCyan-8);
  reco_kp1p2_NC_PID_Tune3_btb-> SetFillColor(31);
  reco_kp1p2_other_PID_Tune3_btb-> SetFillColor(kOrange+6);
  reco_kp1p2_OffBeam_PID_btb-> SetFillColor(kGray);

  THStack *reco_kp1p2_PID_Tune3_btb = new THStack("reco_kp1p2_PID_Tune3_btb","");
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_CCQE_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_CCRes_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_CCCoh_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_CCDIS_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_CCMEC_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_CCNue_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_NC_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_other_PID_Tune3_btb);
  reco_kp1p2_PID_Tune3_btb-> Add(reco_kp1p2_OffBeam_PID_btb);
  reco_kp1p2_PID_Tune3_btb->SetMaximum(25.);
  reco_kp1p2_PID_Tune3_btb-> Draw();
  reco_kp1p2_PID_Tune3_btb->GetXaxis()->SetTitle("No. of Entries");

  reco_kp1p2_OnBeam_PID_btb->SetLineColor(kBlack);
  reco_kp1p2_OnBeam_PID_btb->SetMarkerStyle(20);
  reco_kp1p2_OnBeam_PID_btb->Draw("e1same");

  TLegend *l28 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l28 -> SetNColumns(2);
  l28 -> AddEntry(reco_kp1p2_CCQE_PID_Tune3_btb, "CCQE", "f");
  l28 -> AddEntry(reco_kp1p2_CCRes_PID_Tune3_btb, "CCRes", "f");
  l28 -> AddEntry(reco_kp1p2_CCCoh_PID_Tune3_btb, "CCCoh", "f");
  l28 -> AddEntry(reco_kp1p2_CCDIS_PID_Tune3_btb, "DIS", "f");
  l28 -> AddEntry(reco_kp1p2_CCMEC_PID_Tune3_btb, "CCMEC", "f");
  l28 -> AddEntry(reco_kp1p2_CCNue_PID_Tune3_btb, "CC#nu_{e}", "f");
  l28 -> AddEntry(reco_kp1p2_NC_PID_Tune3_btb, "NC", "f");
  l28 -> AddEntry(reco_kp1p2_other_PID_Tune3_btb, "other", "f");

  l28 -> AddEntry(reco_kp1p2_OffBeam_PID_btb, "off-beam data", "f");
  l28 -> AddEntry(reco_kp1p2_OnBeam_PID_btb, "on-beam data", "lep");
  l28 -> Draw();  
  
  TText *t28 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t28->Draw();

  c28->cd();
  TPad *pad28_2 = new TPad("pad28_2", "pad28_2", 0, 0.05, 1, 0.3);
  pad28_2->SetTopMargin(0.01);
  pad28_2->SetBottomMargin(0.2);
  pad28_2->SetGridx();
  pad28_2->SetGridy();
  pad28_2->Draw();
  pad28_2->cd();
  // Define the ratio plot
  TH1F *h28 = (TH1F*)reco_kp1p2_OnBeam_PID_btb->Clone("h28");
  TH1 *last28 = (TH1*)reco_kp1p2_PID_Tune3_btb->GetStack()->Last();

  chi2test = Chi2Calc(last28,reco_kp1p2_OnBeam_PID_btb, reco_kp1p2_OffBeam_PID_btb, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  k (p1+ p2) btb reco chi2test : "<<chi2test<<std::endl;

  h28->SetLineColor(kBlack);
  h28->Sumw2();
  h28->SetStats(0);      // No statistics on lower plot
  h28->Divide(last28);
  h28->SetMarkerStyle(21);
  h28->SetTitle("");
  h28->Draw("ep");       // Draw the ratio plot

  h28->GetYaxis()->SetTitle("Data/MC");
  h28->GetYaxis()->SetNdivisions(505);
  h28->GetYaxis()->SetTitleSize(20);
  h28->GetYaxis()->SetTitleFont(43);
  h28->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h28->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h28->GetXaxis()->SetTitle("reconstructed KE_{p_{1}} + KE_{p_{2}} [GeV]");
  h28->GetXaxis()->SetTitleSize(20);
  h28->GetXaxis()->SetTitleFont(43);
  h28->GetXaxis()->SetTitleOffset(3.);
  h28->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h28->GetXaxis()->SetLabelSize(15);

  c28->Update();
  c28->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/kp1p2Reco_topo_PID_Tune3_btb.pdf"); 

  //std::cout<<"antes del plot"<<std::endl;
  ///
  TCanvas *c29 = new TCanvas("c29", "c29", 900, 900);
  TPad *pad29 = new TPad("pad29", "pad29", 0, 0.3, 1, 1.0);
  pad29->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad29->Draw();             // Draw the upper pad: pad1
  pad29->cd();              // pad1 becomes the current pad

  reco_angle_SRCrest_p1p2_CCQE_PID_Tune3_CM-> SetFillColor(kRed -10);
  reco_angle_SRCrest_p1p2_CCRes_PID_Tune3_CM-> SetFillColor(kGreen-8);
  reco_angle_SRCrest_p1p2_CCCoh_PID_Tune3_CM-> SetFillColor(kAzure+4);
  reco_angle_SRCrest_p1p2_CCDIS_PID_Tune3_CM-> SetFillColor(kRed-9);
  reco_angle_SRCrest_p1p2_CCMEC_PID_Tune3_CM-> SetFillColor(kOrange);
  reco_angle_SRCrest_p1p2_CCNue_PID_Tune3_CM-> SetFillColor(kCyan-8);
  reco_angle_SRCrest_p1p2_NC_PID_Tune3_CM-> SetFillColor(31);
  //reco_angle_SRCrest_p1p2_other_PID_Tune3_CM-> SetFillColor(kOrange+6);
  reco_angle_SRCrest_p1p2_OffBeam_PID_CM-> SetFillColor(kGray);

  THStack *reco_angle_SRCrest_p1p2_PID_Tune3 = new THStack("reco_angle_SRCrest_p1p2_PID_Tune3","");
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_CCQE_PID_Tune3_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_CCRes_PID_Tune3_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_CCCoh_PID_Tune3_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_CCDIS_PID_Tune3_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_CCMEC_PID_Tune3_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_CCNue_PID_Tune3_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_NC_PID_Tune3_CM);
  //reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_other_PID_Tune3_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_p1p2_OffBeam_PID_CM);
  reco_angle_SRCrest_p1p2_PID_Tune3->SetMaximum(30.);
  reco_angle_SRCrest_p1p2_PID_Tune3-> Draw();
  reco_angle_SRCrest_p1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_SRCrest_p1p2_OnBeam_PID_CM->SetLineColor(kBlack);
  reco_angle_SRCrest_p1p2_OnBeam_PID_CM->SetMarkerStyle(20);
  reco_angle_SRCrest_p1p2_OnBeam_PID_CM->Draw("e1same");

  TLegend *l29 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l29 -> SetNColumns(2);
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_CCQE_PID_Tune3_CM, "CCQE", "f");
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_CCRes_PID_Tune3_CM, "CCRes", "f");
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_CCCoh_PID_Tune3_CM, "CCCoh", "f");
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_CCDIS_PID_Tune3_CM, "DIS", "f");
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_CCMEC_PID_Tune3_CM, "CCMEC", "f");
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_CCNue_PID_Tune3_CM, "CC#nu_{e}", "f");
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_NC_PID_Tune3_CM, "NC", "f");
  //l29 -> AddEntry(reco_angle_SRCrest_p1p2_other_PID_Tune3_CM, "other", "f");

  l29 -> AddEntry(reco_angle_SRCrest_p1p2_OffBeam_PID_CM, "off-beam data", "f");
  l29 -> AddEntry(reco_angle_SRCrest_p1p2_OnBeam_PID_CM, "on-beam data", "lep");
  l29 -> Draw();  
  
  TText *t29 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t29->Draw();

  c29->cd();
  TPad *pad29_2 = new TPad("pad29_2", "pad29_2", 0, 0.05, 1, 0.3);
  pad29_2->SetTopMargin(0.01);
  pad29_2->SetBottomMargin(0.2);
  pad29_2->SetGridx();
  pad29_2->SetGridy();
  pad29_2->Draw();
  pad29_2->cd();
  // Define the ratio plot
  TH1F *h29 = (TH1F*)reco_angle_SRCrest_p1p2_OnBeam_PID_CM->Clone("h29");
  TH1 *last29 = (TH1*)reco_angle_SRCrest_p1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last29,reco_angle_SRCrest_p1p2_OnBeam_PID_CM, reco_angle_SRCrest_p1p2_OffBeam_PID_CM, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cos thetaCM (p1= p2) chi2test : "<<chi2test<<std::endl;

  h29->SetLineColor(kBlack);
  h29->Sumw2();
  h29->SetStats(0);      // No statistics on lower plot
  h29->Divide(last29);
  h29->SetMarkerStyle(21);
  h29->SetTitle("");
  h29->Draw("ep");       // Draw the ratio plot

  h29->GetYaxis()->SetTitle("Data/MC");
  h29->GetYaxis()->SetNdivisions(505);
  h29->GetYaxis()->SetTitleSize(20);
  h29->GetYaxis()->SetTitleFont(43);
  h29->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h29->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h29->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h29->GetXaxis()->SetTitleSize(20);
  h29->GetXaxis()->SetTitleFont(43);
  h29->GetXaxis()->SetTitleOffset(3.);
  h29->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h29->GetXaxis()->SetLabelSize(15);

  c29->Update();
  c29->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/costhetaCM_SRCrest_PID_Tune3.pdf"); 

  /// data only

  TCanvas *c30 = new TCanvas("c30", "c30", 900, 900);

  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->GetXaxis()->SetTitle("No. of Entries");
  reco_angle_p1p2_OnBeam_PID_CM_zoom->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  reco_angle_p1p2_OnBeam_PID_CM_zoom->Draw("e1");

  TLegend *l30 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l30 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM_zoom, "on-beam data", "lep");
  l30 -> Draw();  
  
  TText *t30 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t30->Draw();

  c30->Update();
  c30->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/data_cosanglep1p2RecoCM_topo_PID_Tune3_zoom.pdf");

  TCanvas *c32 = new TCanvas("c32", "c32", 900, 900);

  reco_PT_OnBeam_1binCM_PID->SetLineColor(kBlack);
  reco_PT_OnBeam_1binCM_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_1binCM_PID->GetXaxis()->SetTitle("No. of Entries");
  reco_PT_OnBeam_1binCM_PID->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  reco_PT_OnBeam_1binCM_PID->Draw("e1");

  TLegend *l32 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l32 -> AddEntry(reco_PT_OnBeam_1binCM_PID, "on-beam data", "lep");
  l32 -> Draw();  
  
  TText *t32 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t32->Draw();

  c32->Update();
  c32->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/data_PTReco_topo_1bibCM_PID_Tune3.pdf");

  ///////// more requirements

  TCanvas *c33 = new TCanvas("c33", "c33", 900, 900);
  TPad *pad33 = new TPad("pad33", "pad33", 0, 0.3, 1, 1.0);
  pad33->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad33->Draw();             // Draw the upper pad: pad1
  pad33->cd();              // pad1 becomes the current pad

  reco_angle_SRCrest_PT_LFbtb_p1p2_CCQE_PID_Tune3_CM-> SetFillColor(kRed -10);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCRes_PID_Tune3_CM-> SetFillColor(kGreen-8);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCCoh_PID_Tune3_CM-> SetFillColor(kAzure+4);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCDIS_PID_Tune3_CM-> SetFillColor(kRed-9);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCMEC_PID_Tune3_CM-> SetFillColor(kOrange);
  reco_angle_SRCrest_PT_LFbtb_p1p2_CCNue_PID_Tune3_CM-> SetFillColor(kCyan-8);
  reco_angle_SRCrest_PT_LFbtb_p1p2_NC_PID_Tune3_CM-> SetFillColor(31);
  reco_angle_SRCrest_PT_LFbtb_p1p2_other_PID_Tune3_CM-> SetFillColor(kOrange+6);
  reco_angle_SRCrest_PT_LFbtb_p1p2_OffBeam_PID_CM-> SetFillColor(kGray);

  THStack *reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3 = new THStack("reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3","");
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_CCQE_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_CCRes_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_CCCoh_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_CCDIS_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_CCMEC_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_CCNue_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_NC_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_other_PID_Tune3_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_SRCrest_PT_LFbtb_p1p2_OffBeam_PID_CM);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3->SetMaximum(40.);
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3-> Draw();
  reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM->SetLineColor(kBlack);
  reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM->SetMarkerStyle(20);
  reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM->Draw("e1same");

  TLegend *l33 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l33 -> SetNColumns(2);
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_CCQE_PID_Tune3_CM, "CCQE", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_CCRes_PID_Tune3_CM, "CCRes", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_CCCoh_PID_Tune3_CM, "CCCoh", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_CCDIS_PID_Tune3_CM, "DIS", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_CCMEC_PID_Tune3_CM, "CCMEC", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_CCNue_PID_Tune3_CM, "CC#nu_{e}", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_NC_PID_Tune3_CM, "NC", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_other_PID_Tune3_CM, "other", "f");

  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_OffBeam_PID_CM, "off-beam data", "f");
  l33 -> AddEntry(reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM, "on-beam data", "lep");
  l33 -> Draw();  
  
  TText *t33 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t33->Draw();

  c33->cd();
  TPad *pad33_2 = new TPad("pad33_2", "pad33_2", 0, 0.05, 1, 0.3);
  pad33_2->SetTopMargin(0.01);
  pad33_2->SetBottomMargin(0.2);
  pad33_2->SetGridx();
  pad33_2->SetGridy();
  pad33_2->Draw();
  pad33_2->cd();
  // Define the ratio plot
  TH1F *h33 = (TH1F*)reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM->Clone("h33");
  TH1 *last33 = (TH1*)reco_angle_SRCrest_PT_LFbtb_p1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last33,reco_angle_SRCrest_PT_LFbtb_p1p2_OnBeam_PID_CM, reco_angle_SRCrest_PT_LFbtb_p1p2_OffBeam_PID_CM, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cos thetaCM (p1= p2) chi2test : "<<chi2test<<std::endl;

  h33->SetLineColor(kBlack);
  h33->Sumw2();
  h33->SetStats(0);      // No statistics on lower plot
  h33->Divide(last33);
  h33->SetMarkerStyle(21);
  h33->SetTitle("");
  h33->Draw("ep");       // Draw the ratio plot

  h33->GetYaxis()->SetTitle("Data/MC");
  h33->GetYaxis()->SetNdivisions(505);
  h33->GetYaxis()->SetTitleSize(20);
  h33->GetYaxis()->SetTitleFont(43);
  h33->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h33->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h33->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h33->GetXaxis()->SetTitleSize(20);
  h33->GetXaxis()->SetTitleFont(43);
  h33->GetXaxis()->SetTitleOffset(3.);
  h33->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h33->GetXaxis()->SetLabelSize(15);

  c33->Update();
  c33->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/costhetaCM_SRCrest_PT_LFbtb_PID_Tune3.pdf"); 

  TCanvas *c34 = new TCanvas("c34", "c34", 900, 900);
  TPad *pad34 = new TPad("pad34", "pad34", 0, 0.3, 1, 1.0);
  pad34->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad34->Draw();             // Draw the upper pad: pad1
  pad34->cd();              // pad1 becomes the current pad

  reco_PT_CCQE_nobtbLF_PID_Tune3-> SetFillColor(kRed -10);
  reco_PT_CCRes_nobtbLF_PID_Tune3-> SetFillColor(kGreen-8);
  reco_PT_CCCoh_nobtbLF_PID_Tune3-> SetFillColor(kAzure+4);
  reco_PT_CCDIS_nobtbLF_PID_Tune3-> SetFillColor(kRed-9);
  reco_PT_CCMEC_nobtbLF_PID_Tune3-> SetFillColor(kOrange);
  reco_PT_CCNue_nobtbLF_PID_Tune3-> SetFillColor(kCyan-8);
  reco_PT_NC_nobtbLF_PID_Tune3-> SetFillColor(31);
  reco_PT_other_nobtbLF_PID_Tune3-> SetFillColor(kOrange+6);
  reco_PT_OffBeam_nobtbLF_PID-> SetFillColor(kGray);

  THStack *reco_PT_nobtbLF = new THStack("reco_PT_nobtbLF","");
  reco_PT_nobtbLF-> Add(reco_PT_CCQE_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_CCRes_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_CCCoh_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_CCDIS_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_CCMEC_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_CCNue_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_NC_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_other_nobtbLF_PID_Tune3);
  reco_PT_nobtbLF-> Add(reco_PT_OffBeam_nobtbLF_PID);
  //reco_PT_nobtbLF->SetMaximum(50.);
  reco_PT_nobtbLF-> Draw();
  reco_PT_nobtbLF->GetXaxis()->SetTitle("No. of Entries");

  reco_PT_OnBeam_nobtbLF_PID->SetLineColor(kBlack);
  reco_PT_OnBeam_nobtbLF_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_nobtbLF_PID->Draw("e1same");

  TLegend *l34 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l34 -> SetNColumns(2);
  l34 -> AddEntry(reco_PT_CCQE_nobtbLF_PID_Tune3, "CCQE", "f");
  l34 -> AddEntry(reco_PT_CCRes_nobtbLF_PID_Tune3, "CCRes", "f");
  l34 -> AddEntry(reco_PT_CCCoh_nobtbLF_PID_Tune3, "CCCoh", "f");
  l34 -> AddEntry(reco_PT_CCDIS_nobtbLF_PID_Tune3, "DIS", "f");
  l34 -> AddEntry(reco_PT_CCMEC_nobtbLF_PID_Tune3, "CCMEC", "f");
  l34 -> AddEntry(reco_PT_CCNue_nobtbLF_PID_Tune3, "CC#nu_{e}", "f");
  l34 -> AddEntry(reco_PT_NC_nobtbLF_PID_Tune3, "NC", "f");
  l34 -> AddEntry(reco_PT_other_nobtbLF_PID_Tune3, "other", "f");

  l34 -> AddEntry(reco_PT_OffBeam_nobtbLF_PID, "off-beam data", "f");
  l34 -> AddEntry(reco_PT_OnBeam_nobtbLF_PID, "on-beam data", "lep");
  l34 -> Draw();  
  
  TText *t34 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t34->Draw();

  c34->cd();
  TPad *pad34_2 = new TPad("pad34_2", "pad34_2", 0, 0.05, 1, 0.3);
  pad34_2->SetTopMargin(0.01);
  pad34_2->SetBottomMargin(0.2);
  pad34_2->SetGridx();
  pad34_2->SetGridy();
  pad34_2->Draw();
  pad34_2->cd();
  // Define the ratio plot
  TH1F *h34 = (TH1F*)reco_PT_OnBeam_nobtbLF_PID->Clone("h34");
  TH1 *last34 = (TH1*)reco_PT_nobtbLF->GetStack()->Last();

  chi2test = Chi2Calc(last34,reco_PT_OnBeam_nobtbLF_PID, reco_PT_OnBeam_nobtbLF_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cos thetaCM (p1= p2) chi2test : "<<chi2test<<std::endl;

  h34->SetLineColor(kBlack);
  h34->Sumw2();
  h34->SetStats(0);      // No statistics on lower plot
  h34->Divide(last34);
  h34->SetMarkerStyle(21);
  h34->SetTitle("");
  h34->Draw("ep");       // Draw the ratio plot

  h34->GetYaxis()->SetTitle("Data/MC");
  h34->GetYaxis()->SetNdivisions(505);
  h34->GetYaxis()->SetTitleSize(20);
  h34->GetYaxis()->SetTitleFont(43);
  h34->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h34->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h34->GetXaxis()->SetTitle("reconstructed missing P_{T}");
  h34->GetXaxis()->SetTitleSize(20);
  h34->GetXaxis()->SetTitleFont(43);
  h34->GetXaxis()->SetTitleOffset(3.);
  h34->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h34->GetXaxis()->SetLabelSize(15);

  c34->Update();
  c34->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/reco_PT_nobtbLF_PID_Tune3.pdf"); 

  TCanvas *c35 = new TCanvas("c35", "c35", 900, 900);
  TPad *pad35 = new TPad("pad35", "pad35", 0, 0.3, 1, 1.0);
  pad35->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad35->Draw();             // Draw the upper pad: pad1
  pad35->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_CCQE_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(kRed -10);
  reco_angle_p1p2_CCRes_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(kGreen-8);
  reco_angle_p1p2_CCCoh_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(kAzure+4);
  reco_angle_p1p2_CCDIS_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(kRed-9);
  reco_angle_p1p2_CCMEC_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(kOrange);
  reco_angle_p1p2_CCNue_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(kCyan-8);
  reco_angle_p1p2_NC_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(31);
  reco_angle_p1p2_other_nobtbLF_PID_Tune3_CM_zoom-> SetFillColor(kOrange+6);
  reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom-> SetFillColor(kGray);

  THStack *reco_angle_LFbtb_p1p2_PID_Tune3 = new THStack("reco_angle_LFbtb_p1p2_PID_Tune3","");
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCQE_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCRes_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCCoh_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCDIS_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCMEC_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_CCNue_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_NC_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_other_nobtbLF_PID_Tune3_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Add(reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom);
  reco_angle_LFbtb_p1p2_PID_Tune3->SetMaximum(150.);
  reco_angle_LFbtb_p1p2_PID_Tune3-> Draw();
  reco_angle_LFbtb_p1p2_PID_Tune3->GetXaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->Draw("e1same");

  TLegend *l35 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l35 -> SetNColumns(2);
  l35 -> AddEntry(reco_angle_p1p2_CCQE_nobtbLF_PID_Tune3_CM_zoom, "CCQE", "f");
  l35 -> AddEntry(reco_angle_p1p2_CCRes_nobtbLF_PID_Tune3_CM_zoom, "CCRes", "f");
  l35 -> AddEntry(reco_angle_p1p2_CCCoh_nobtbLF_PID_Tune3_CM_zoom, "CCCoh", "f");
  l35 -> AddEntry(reco_angle_p1p2_CCDIS_nobtbLF_PID_Tune3_CM_zoom, "DIS", "f");
  l35 -> AddEntry(reco_angle_p1p2_CCMEC_nobtbLF_PID_Tune3_CM_zoom, "CCMEC", "f");
  l35 -> AddEntry(reco_angle_p1p2_CCNue_nobtbLF_PID_Tune3_CM_zoom, "CC#nu_{e}", "f");
  l35 -> AddEntry(reco_angle_p1p2_NC_nobtbLF_PID_Tune3_CM_zoom, "NC", "f");
  l35 -> AddEntry(reco_angle_p1p2_other_nobtbLF_PID_Tune3_CM_zoom, "other", "f");

  l35 -> AddEntry(reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom, "off-beam data", "f");
  l35 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom, "on-beam data", "lep");
  l35 -> Draw();  
  
  TText *t35 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE. 1.592e20 POT, stats only");
  t35->Draw();

  c35->cd();
  TPad *pad35_2 = new TPad("pad35_2", "pad35_2", 0, 0.05, 1, 0.3);
  pad35_2->SetTopMargin(0.01);
  pad35_2->SetBottomMargin(0.2);
  pad35_2->SetGridx();
  pad35_2->SetGridy();
  pad35_2->Draw();
  pad35_2->cd();
  // Define the ratio plot
  TH1F *h35 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->Clone("h35");
  TH1 *last35 = (TH1*)reco_angle_LFbtb_p1p2_PID_Tune3->GetStack()->Last();

  chi2test = Chi2Calc(last35,reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom, reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_Tune3<<"canvas: "<<canvas<<"  cos thetaCM (p1= p2) chi2test : "<<chi2test<<std::endl;

  h35->SetLineColor(kBlack);
  h35->Sumw2();
  h35->SetStats(0);      // No statistics on lower plot
  h35->Divide(last35);
  h35->SetMarkerStyle(21);
  h35->SetTitle("");
  h35->Draw("ep");       // Draw the ratio plot

  h35->GetYaxis()->SetTitle("Data/MC");
  h35->GetYaxis()->SetNdivisions(505);
  h35->GetYaxis()->SetTitleSize(20);
  h35->GetYaxis()->SetTitleFont(43);
  h35->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h35->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h35->GetXaxis()->SetTitle("reconstructed cos#gamma^{'} in CM");
  h35->GetXaxis()->SetTitleSize(20);
  h35->GetXaxis()->SetTitleFont(43);
  h35->GetXaxis()->SetTitleOffset(3.);
  h35->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h35->GetXaxis()->SetLabelSize(15);

  c35->Update();
  c35->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/angles_Tune3/costhetaCM_LFbtb_PID_Tune3.pdf"); 

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


}
