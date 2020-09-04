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

double Chi2Calc(TH1 *histo_MC, TH1D *histo_bnb, TH1D *histo_extbnb, double scale_offbeam, double norm_MC){

  int nbins=histo_MC->GetNbinsX();
  int nbinsdata=0;
  double N_MC[nbins], N_BNB[nbins], N_EXTBNB[nbins];
  double Chi2=0.0;
  /// area normalized
  double intOffBeam = (histo_extbnb->GetEntries());
  //double intOffBeam = (histo_extbnb->GetEntries());
  //std::cout<<"off beam entries "<<std::endl;
  double intMC = (histo_MC->GetEntries());
  //std::cout<<"MC entries "<<intMC<<std::endl;

  double intOnBeam = histo_bnb->GetEntries();
 
  //std::cout<<"norm MC "<< norm_MC<<" norm off beam "<<scale_offbeam<<std::endl;
  //std::cout<<"entries MC "<< intMC<<" entries off beam "<<intOffBeam<<" entries on beam "<<intOnBeam<<std::endl;
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

void DataMC_PID_300(){ 
  
  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_300_BNBMC.root","READ");
  TFile* OnBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OnBeam.root","READ");
  TFile* OffBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OffBeam.root","READ");

  std::cout<<"antes de Tfile"<<std::endl;
  
  ofstream outfileDataMC_PID_300;
  outfileDataMC_PID_300.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/chi2_2P_DataMC_300.txt");

  ////// BNB MC

  TH1D* selmuon_lenght_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_CC0Pion0Proton_PID_300");
  TH1D* selmuon_lenght_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_CC0Pion1Proton_PID_300");
  TH1D* selmuon_lenght_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_CC0Pion2Proton_PID_300");
  TH1D* selmuon_lenght_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_CC0PionNProton_PID_300");
  TH1D* selmuon_lenght_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_CC1PionNProton_PID_300");
  TH1D* selmuon_lenght_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_CCNPionNProton_PID_300");
  TH1D* selmuon_lenght_CCNue_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_CCNue_PID_300");
  TH1D* selmuon_lenght_NC_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_NC_PID_300");
  TH1D* selmuon_lenght_OOFV_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_OOFV_PID_300");
  TH1D* selmuon_lenght_EXT_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_EXT_PID_300");
  TH1D* selmuon_lenght_other_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_other_PID_300");

  TH1D* selmuon_mom_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_CC0Pion0Proton_PID_300");
  TH1D* selmuon_mom_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_CC0Pion1Proton_PID_300");
  TH1D* selmuon_mom_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_CC0Pion2Proton_PID_300");
  TH1D* selmuon_mom_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_CC0PionNProton_PID_300");
  TH1D* selmuon_mom_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_CC1PionNProton_PID_300");
  TH1D* selmuon_mom_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_CCNPionNProton_PID_300");
  TH1D* selmuon_mom_CCNue_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_CCNue_PID_300");
  TH1D* selmuon_mom_NC_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_NC_PID_300");
  TH1D* selmuon_mom_OOFV_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_OOFV_PID_300");
  TH1D* selmuon_mom_EXT_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_EXT_PID_300");
  TH1D* selmuon_mom_other_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_other_PID_300");

  TH1D* selmuon_costheta_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_CC0Pion0Proton_PID_300");
  TH1D* selmuon_costheta_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_CC0Pion1Proton_PID_300");
  TH1D* selmuon_costheta_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_CC0Pion2Proton_PID_300");
  TH1D* selmuon_costheta_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_CC0PionNProton_PID_300");
  TH1D* selmuon_costheta_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_CC1PionNProton_PID_300");
  TH1D* selmuon_costheta_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_CCNPionNProton_PID_300");
  TH1D* selmuon_costheta_CCNue_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_CCNue_PID_300");
  TH1D* selmuon_costheta_NC_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_NC_PID_300");
  TH1D* selmuon_costheta_OOFV_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_OOFV_PID_300");
  TH1D* selmuon_costheta_EXT_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_EXT_PID_300");
  TH1D* selmuon_costheta_other_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_other_PID_300");

  TH1D* selmuon_phi_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_CC0Pion0Proton_PID_300");
  TH1D* selmuon_phi_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_CC0Pion1Proton_PID_300");
  TH1D* selmuon_phi_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_CC0Pion2Proton_PID_300");
  TH1D* selmuon_phi_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_CC0PionNProton_PID_300");
  TH1D* selmuon_phi_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_CC1PionNProton_PID_300");
  TH1D* selmuon_phi_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_CCNPionNProton_PID_300");
  TH1D* selmuon_phi_CCNue_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_CCNue_PID_300");
  TH1D* selmuon_phi_NC_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_NC_PID_300");
  TH1D* selmuon_phi_OOFV_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_OOFV_PID_300");
  TH1D* selmuon_phi_EXT_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_EXT_PID_300");
  TH1D* selmuon_phi_other_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_other_PID_300");

  TH1D* selmuon_lenght_muon_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_muon_PID_300");
  TH1D* selmuon_lenght_proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_proton_PID_300");
  TH1D* selmuon_lenght_pion_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_pion_PID_300");
  TH1D* selmuon_lenght_electron_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_electron_PID_300");
  TH1D* selmuon_lenght_pother_PID_300 = (TH1D*) BNBMC->Get("selmuon_lenght_pother_PID_300");

  TH1D* selmuon_mom_muon_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_muon_PID_300");
  TH1D* selmuon_mom_proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_proton_PID_300");
  TH1D* selmuon_mom_pion_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_pion_PID_300");
  TH1D* selmuon_mom_electron_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_electron_PID_300");
  TH1D* selmuon_mom_pother_PID_300 = (TH1D*) BNBMC->Get("selmuon_mom_pother_PID_300");

  TH1D* selmuon_costheta_muon_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_muon_PID_300");
  TH1D* selmuon_costheta_proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_proton_PID_300");
  TH1D* selmuon_costheta_pion_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_pion_PID_300");
  TH1D* selmuon_costheta_electron_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_electron_PID_300");
  TH1D* selmuon_costheta_pother_PID_300 = (TH1D*) BNBMC->Get("selmuon_costheta_pother_PID_300");

  TH1D* selmuon_phi_muon_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_muon_PID_300");
  TH1D* selmuon_phi_proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_proton_PID_300");
  TH1D* selmuon_phi_pion_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_pion_PID_300");
  TH1D* selmuon_phi_electron_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_electron_PID_300");
  TH1D* selmuon_phi_pother_PID_300 = (TH1D*) BNBMC->Get("selmuon_phi_pother_PID_300");

  TH1D* selmuon_chi2proton_muon_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_muon_PID_300");
  TH1D* selmuon_chi2proton_proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_proton_PID_300");
  TH1D* selmuon_chi2proton_pion_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_pion_PID_300");
  TH1D* selmuon_chi2proton_electron_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_electron_PID_300");
  TH1D* selmuon_chi2proton_pother_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_pother_PID_300");

  TH1D* selmuon_chi2proton_cont_muon_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_muon_PID_300");
  TH1D* selmuon_chi2proton_cont_proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_proton_PID_300");
  TH1D* selmuon_chi2proton_cont_pion_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_pion_PID_300");
  TH1D* selmuon_chi2proton_cont_electron_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_electron_PID_300");
  TH1D* selmuon_chi2proton_cont_pother_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_cont_pother_PID_300");

  TH1D* selmuon_chi2proton_uncont_muon_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_muon_PID_300");
  TH1D* selmuon_chi2proton_uncont_proton_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_proton_PID_300");
  TH1D* selmuon_chi2proton_uncont_pion_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_pion_PID_300");
  TH1D* selmuon_chi2proton_uncont_electron_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_electron_PID_300");
  TH1D* selmuon_chi2proton_uncont_pother_PID_300 = (TH1D*) BNBMC->Get("selmuon_chi2proton_uncont_pother_PID_300");

  TH2D* selmuon_dEdx_vs_resrange_muon_PID_300 = (TH2D*) BNBMC->Get("selmuon_dEdx_vs_resrange_muon_PID_300");
  TH2D* selmuon_dEdx_vs_resrange_proton_PID_300 = (TH2D*) BNBMC->Get("selmuon_dEdx_vs_resrange_proton_PID_300");
  TH2D* selmuon_dEdx_vs_resrange_pion_PID_300 = (TH2D*) BNBMC->Get("selmuon_dEdx_vs_resrange_pion_PID_300");

  /// proton 1

  TH1D* selproton1_lenght_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_CC0Pion0Proton_PID_300");
  TH1D* selproton1_lenght_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_CC0Pion1Proton_PID_300");
  TH1D* selproton1_lenght_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_CC0Pion2Proton_PID_300");
  TH1D* selproton1_lenght_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_CC0PionNProton_PID_300");
  TH1D* selproton1_lenght_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_CC1PionNProton_PID_300");
  TH1D* selproton1_lenght_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_CCNPionNProton_PID_300");
  TH1D* selproton1_lenght_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_CCNue_PID_300");
  TH1D* selproton1_lenght_NC_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_NC_PID_300");
  TH1D* selproton1_lenght_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_OOFV_PID_300");
  TH1D* selproton1_lenght_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_EXT_PID_300");
  TH1D* selproton1_lenght_other_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_other_PID_300");

  TH1D* selproton1_mom_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_CC0Pion0Proton_PID_300");
  TH1D* selproton1_mom_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_CC0Pion1Proton_PID_300");
  TH1D* selproton1_mom_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_CC0Pion2Proton_PID_300");
  TH1D* selproton1_mom_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_CC0PionNProton_PID_300");
  TH1D* selproton1_mom_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_CC1PionNProton_PID_300");
  TH1D* selproton1_mom_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_CCNPionNProton_PID_300");
  TH1D* selproton1_mom_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_CCNue_PID_300");
  TH1D* selproton1_mom_NC_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_NC_PID_300");
  TH1D* selproton1_mom_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_OOFV_PID_300");
  TH1D* selproton1_mom_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_EXT_PID_300");
  TH1D* selproton1_mom_other_PID_300 = (TH1D*) BNBMC->Get("selproton1_mom_other_PID_300");

  TH1D* selproton1_costheta_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_CC0Pion0Proton_PID_300");
  TH1D* selproton1_costheta_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_CC0Pion1Proton_PID_300");
  TH1D* selproton1_costheta_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_CC0Pion2Proton_PID_300");
  TH1D* selproton1_costheta_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_CC0PionNProton_PID_300");
  TH1D* selproton1_costheta_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_CC1PionNProton_PID_300");
  TH1D* selproton1_costheta_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_CCNPionNProton_PID_300");
  TH1D* selproton1_costheta_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_CCNue_PID_300");
  TH1D* selproton1_costheta_NC_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_NC_PID_300");
  TH1D* selproton1_costheta_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_OOFV_PID_300");
  TH1D* selproton1_costheta_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_EXT_PID_300");
  TH1D* selproton1_costheta_other_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_other_PID_300");

  TH1D* selproton1_phi_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_CC0Pion0Proton_PID_300");
  TH1D* selproton1_phi_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_CC0Pion1Proton_PID_300");
  TH1D* selproton1_phi_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_CC0Pion2Proton_PID_300");
  TH1D* selproton1_phi_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_CC0PionNProton_PID_300");
  TH1D* selproton1_phi_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_CC1PionNProton_PID_300");
  TH1D* selproton1_phi_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_CCNPionNProton_PID_300");
  TH1D* selproton1_phi_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_CCNue_PID_300");
  TH1D* selproton1_phi_NC_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_NC_PID_300");
  TH1D* selproton1_phi_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_OOFV_PID_300");
  TH1D* selproton1_phi_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_EXT_PID_300");
  TH1D* selproton1_phi_other_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_other_PID_300");

  TH1D* selproton1_lenght_muon_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_muon_PID_300");
  TH1D* selproton1_lenght_proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_proton_PID_300");
  TH1D* selproton1_lenght_pion_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_pion_PID_300");
  TH1D* selproton1_lenght_electron_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_electron_PID_300");
  TH1D* selproton1_lenght_pother_PID_300 = (TH1D*) BNBMC->Get("selproton1_lenght_pother_PID_300");

  TH1D* selproton1_costheta_muon_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_muon_PID_300");
  TH1D* selproton1_costheta_proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_proton_PID_300");
  TH1D* selproton1_costheta_pion_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_pion_PID_300");
  TH1D* selproton1_costheta_electron_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_electron_PID_300");
  TH1D* selproton1_costheta_pother_PID_300 = (TH1D*) BNBMC->Get("selproton1_costheta_pother_PID_300");

  TH1D* selproton1_phi_muon_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_muon_PID_300");
  TH1D* selproton1_phi_proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_proton_PID_300");
  TH1D* selproton1_phi_pion_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_pion_PID_300");
  TH1D* selproton1_phi_electron_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_electron_PID_300");
  TH1D* selproton1_phi_pother_PID_300 = (TH1D*) BNBMC->Get("selproton1_phi_pother_PID_300");

  TH1D* selproton1_chi2proton_muon_PID_300 = (TH1D*) BNBMC->Get("selproton1_chi2proton_muon_PID_300");
  TH1D* selproton1_chi2proton_proton_PID_300 = (TH1D*) BNBMC->Get("selproton1_chi2proton_proton_PID_300");
  TH1D* selproton1_chi2proton_pion_PID_300 = (TH1D*) BNBMC->Get("selproton1_chi2proton_pion_PID_300");
  TH1D* selproton1_chi2proton_electron_PID_300 = (TH1D*) BNBMC->Get("selproton1_chi2proton_electron_PID_300");
  TH1D* selproton1_chi2proton_pother_PID_300 = (TH1D*) BNBMC->Get("selproton1_chi2proton_pother_PID_300");

  TH2D* selproton1_dEdx_vs_resrange_muon_PID_300 = (TH2D*) BNBMC->Get("selproton1_dEdx_vs_resrange_muon_PID_300");
  TH2D* selproton1_dEdx_vs_resrange_proton_PID_300 = (TH2D*) BNBMC->Get("selproton1_dEdx_vs_resrange_proton_PID_300");
  TH2D* selproton1_dEdx_vs_resrange_pion_PID_300 = (TH2D*) BNBMC->Get("selproton1_dEdx_vs_resrange_pion_PID_300");

  /// proton 2
  TH1D* selproton2_lenght_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_CC0Pion0Proton_PID_300");
  TH1D* selproton2_lenght_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_CC0Pion1Proton_PID_300");
  TH1D* selproton2_lenght_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_CC0Pion2Proton_PID_300");
  TH1D* selproton2_lenght_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_CC0PionNProton_PID_300");
  TH1D* selproton2_lenght_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_CC1PionNProton_PID_300");
  TH1D* selproton2_lenght_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_CCNPionNProton_PID_300");
  TH1D* selproton2_lenght_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_CCNue_PID_300");
  TH1D* selproton2_lenght_NC_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_NC_PID_300");
  TH1D* selproton2_lenght_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_OOFV_PID_300");
  TH1D* selproton2_lenght_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_EXT_PID_300");
  TH1D* selproton2_lenght_other_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_other_PID_300");

  TH1D* selproton2_mom_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_CC0Pion0Proton_PID_300");
  TH1D* selproton2_mom_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_CC0Pion1Proton_PID_300");
  TH1D* selproton2_mom_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_CC0Pion2Proton_PID_300");
  TH1D* selproton2_mom_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_CC0PionNProton_PID_300");
  TH1D* selproton2_mom_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_CC1PionNProton_PID_300");
  TH1D* selproton2_mom_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_CCNPionNProton_PID_300");
  TH1D* selproton2_mom_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_CCNue_PID_300");
  TH1D* selproton2_mom_NC_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_NC_PID_300");
  TH1D* selproton2_mom_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_OOFV_PID_300");
  TH1D* selproton2_mom_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_EXT_PID_300");
  TH1D* selproton2_mom_other_PID_300 = (TH1D*) BNBMC->Get("selproton2_mom_other_PID_300");

  TH1D* selproton2_costheta_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_CC0Pion0Proton_PID_300");
  TH1D* selproton2_costheta_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_CC0Pion1Proton_PID_300");
  TH1D* selproton2_costheta_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_CC0Pion2Proton_PID_300");
  TH1D* selproton2_costheta_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_CC0PionNProton_PID_300");
  TH1D* selproton2_costheta_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_CC1PionNProton_PID_300");
  TH1D* selproton2_costheta_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_CCNPionNProton_PID_300");
  TH1D* selproton2_costheta_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_CCNue_PID_300");
  TH1D* selproton2_costheta_NC_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_NC_PID_300");
  TH1D* selproton2_costheta_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_OOFV_PID_300");
  TH1D* selproton2_costheta_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_EXT_PID_300");
  TH1D* selproton2_costheta_other_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_other_PID_300");

  TH1D* selproton2_phi_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_CC0Pion0Proton_PID_300");
  TH1D* selproton2_phi_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_CC0Pion1Proton_PID_300");
  TH1D* selproton2_phi_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_CC0Pion2Proton_PID_300");
  TH1D* selproton2_phi_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_CC0PionNProton_PID_300");
  TH1D* selproton2_phi_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_CC1PionNProton_PID_300");
  TH1D* selproton2_phi_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_CCNPionNProton_PID_300");
  TH1D* selproton2_phi_CCNue_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_CCNue_PID_300");
  TH1D* selproton2_phi_NC_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_NC_PID_300");
  TH1D* selproton2_phi_OOFV_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_OOFV_PID_300");
  TH1D* selproton2_phi_EXT_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_EXT_PID_300");
  TH1D* selproton2_phi_other_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_other_PID_300");

  TH1D* selproton2_lenght_muon_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_muon_PID_300");
  TH1D* selproton2_lenght_proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_proton_PID_300");
  TH1D* selproton2_lenght_pion_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_pion_PID_300");
  TH1D* selproton2_lenght_electron_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_electron_PID_300");
  TH1D* selproton2_lenght_pother_PID_300 = (TH1D*) BNBMC->Get("selproton2_lenght_pother_PID_300");

  TH1D* selproton2_costheta_muon_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_muon_PID_300");
  TH1D* selproton2_costheta_proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_proton_PID_300");
  TH1D* selproton2_costheta_pion_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_pion_PID_300");
  TH1D* selproton2_costheta_electron_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_electron_PID_300");
  TH1D* selproton2_costheta_pother_PID_300 = (TH1D*) BNBMC->Get("selproton2_costheta_pother_PID_300");

  TH1D* selproton2_phi_muon_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_muon_PID_300");
  TH1D* selproton2_phi_proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_proton_PID_300");
  TH1D* selproton2_phi_pion_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_pion_PID_300");
  TH1D* selproton2_phi_electron_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_electron_PID_300");
  TH1D* selproton2_phi_pother_PID_300 = (TH1D*) BNBMC->Get("selproton2_phi_pother_PID_300");

  TH1D* selproton2_chi2proton_muon_PID_300 = (TH1D*) BNBMC->Get("selproton2_chi2proton_muon_PID_300");
  TH1D* selproton2_chi2proton_proton_PID_300 = (TH1D*) BNBMC->Get("selproton2_chi2proton_proton_PID_300");
  TH1D* selproton2_chi2proton_pion_PID_300 = (TH1D*) BNBMC->Get("selproton2_chi2proton_pion_PID_300");
  TH1D* selproton2_chi2proton_electron_PID_300 = (TH1D*) BNBMC->Get("selproton2_chi2proton_electron_PID_300");
  TH1D* selproton2_chi2proton_pother_PID_300 = (TH1D*) BNBMC->Get("selproton2_chi2proton_pother_PID_300");

  TH2D* selproton2_dEdx_vs_resrange_muon_PID_300 = (TH2D*) BNBMC->Get("selproton2_dEdx_vs_resrange_muon_PID_300");
  TH2D* selproton2_dEdx_vs_resrange_proton_PID_300 = (TH2D*) BNBMC->Get("selproton2_dEdx_vs_resrange_proton_PID_300");
  TH2D* selproton2_dEdx_vs_resrange_pion_PID_300 = (TH2D*) BNBMC->Get("selproton2_dEdx_vs_resrange_pion_PID_300");
  ///// opening angles

  TH1D* angle_mup1_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_CC0Pion0Proton_PID_300");
  TH1D* angle_mup1_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_CC0Pion1Proton_PID_300");
  TH1D* angle_mup1_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_CC0Pion2Proton_PID_300");
  TH1D* angle_mup1_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_CC0PionNProton_PID_300");
  TH1D* angle_mup1_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_CC1PionNProton_PID_300");
  TH1D* angle_mup1_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_CCNPionNProton_PID_300");
  TH1D* angle_mup1_CCNue_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_CCNue_PID_300");
  TH1D* angle_mup1_NC_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_NC_PID_300");
  TH1D* angle_mup1_OOFV_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_OOFV_PID_300");
  TH1D* angle_mup1_EXT_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_EXT_PID_300");
  TH1D* angle_mup1_other_PID_300 = (TH1D*) BNBMC->Get("angle_mup1_other_PID_300");

  TH1D* angle_mup2_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_CC0Pion0Proton_PID_300");
  TH1D* angle_mup2_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_CC0Pion1Proton_PID_300");
  TH1D* angle_mup2_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_CC0Pion2Proton_PID_300");
  TH1D* angle_mup2_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_CC0PionNProton_PID_300");
  TH1D* angle_mup2_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_CC1PionNProton_PID_300");
  TH1D* angle_mup2_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_CCNPionNProton_PID_300");
  TH1D* angle_mup2_CCNue_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_CCNue_PID_300");
  TH1D* angle_mup2_NC_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_NC_PID_300");
  TH1D* angle_mup2_OOFV_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_OOFV_PID_300");
  TH1D* angle_mup2_EXT_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_EXT_PID_300");
  TH1D* angle_mup2_other_PID_300 = (TH1D*) BNBMC->Get("angle_mup2_other_PID_300");

  TH1D* angle_p1p2_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_CC0Pion0Proton_PID_300");
  TH1D* angle_p1p2_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_CC0Pion1Proton_PID_300");
  TH1D* angle_p1p2_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_CC0Pion2Proton_PID_300");
  TH1D* angle_p1p2_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_CC0PionNProton_PID_300");
  TH1D* angle_p1p2_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_CC1PionNProton_PID_300");
  TH1D* angle_p1p2_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_CCNPionNProton_PID_300");
  TH1D* angle_p1p2_CCNue_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_CCNue_PID_300");
  TH1D* angle_p1p2_NC_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_NC_PID_300");
  TH1D* angle_p1p2_OOFV_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_OOFV_PID_300");
  TH1D* angle_p1p2_EXT_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_EXT_PID_300");
  TH1D* angle_p1p2_other_PID_300 = (TH1D*) BNBMC->Get("angle_p1p2_other_PID_300");

  TH1D* cosangle_p1p2_CC0Pion0Proton_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_CC0Pion0Proton_PID_300");
  TH1D* cosangle_p1p2_CC0Pion1Proton_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_CC0Pion1Proton_PID_300");
  TH1D* cosangle_p1p2_CC0Pion2Proton_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_CC0Pion2Proton_PID_300");
  TH1D* cosangle_p1p2_CC0PionNProton_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_CC0PionNProton_PID_300");
  TH1D* cosangle_p1p2_CC1PionNProton_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_CC1PionNProton_PID_300");
  TH1D* cosangle_p1p2_CCNPionNProton_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_CCNPionNProton_PID_300");
  TH1D* cosangle_p1p2_CCNue_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_CCNue_PID_300");
  TH1D* cosangle_p1p2_NC_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_NC_PID_300");
  TH1D* cosangle_p1p2_OOFV_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_OOFV_PID_300");
  TH1D* cosangle_p1p2_EXT_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_EXT_PID_300");
  TH1D* cosangle_p1p2_other_PID_300 = (TH1D*) BNBMC->Get("cosangle_p1p2_other_PID_300");

  ///// resolutions (MC)
  TH2D* selmuon_mom_res_PID_300 = (TH2D*) BNBMC->Get("selmuon_mom_res_PID_300");
  TH2D* selmuon_costheta_res_PID_300 = (TH2D*) BNBMC->Get("selmuon_costheta_res_PID_300");
  TH2D* selmuon_phi_res_PID_300 = (TH2D*) BNBMC->Get("selmuon_phi_res_PID_300");

  TH2D* selproton1_mom_res_PID_300 = (TH2D*) BNBMC->Get("selproton1_mom_res_PID_300");
  TH2D* selproton1_costheta_res_PID_300 = (TH2D*) BNBMC->Get("selproton1_costheta_res_PID_300");
  TH2D* selproton1_phi_res_PID_300 = (TH2D*) BNBMC->Get("selproton1_phi_res_PID_300");

  TH2D* selproton2_mom_res_PID_300 = (TH2D*) BNBMC->Get("selproton2_mom_res_PID_300");
  TH2D* selproton2_costheta_res_PID_300 = (TH2D*) BNBMC->Get("selproton2_costheta_res_PID_300");
  TH2D* selproton2_phi_res_PID_300 = (TH2D*) BNBMC->Get("selproton2_phi_res_PID_300");

  //// On-Beam data

  /// muon candidate properties
  TH1D* selmuon_lenght_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_lenght_OnBeam_PID");
  TH1D* selmuon_mom_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_mom_OnBeam_PID");
  TH1D* selmuon_costheta_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_costheta_OnBeam_PID");
  TH1D* selmuon_phi_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_phi_OnBeam_PID");

  TH1D* selmuon_chi2proton_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_chi2proton_OnBeam_PID");

  TH1D* selmuon_chi2proton_cont_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_chi2proton_cont_OnBeam_PID");
  TH1D* selmuon_chi2proton_uncont_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_chi2proton_uncont_OnBeam_PID");

  TH2D* selmuon_dEdx_vs_resrange_OnBeam_PID = (TH2D*) OnBeam->Get("selmuon_dEdx_vs_resrange_OnBeam_PID");

  ////proton 1

  TH1D* selproton1_lenght_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_lenght_OnBeam_PID");
  TH1D* selproton1_costheta_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_costheta_OnBeam_PID");
  TH1D* selproton1_phi_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_phi_OnBeam_PID");
  TH1D* selproton1_mom_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_mom_OnBeam_PID");

  TH1D* selproton1_chi2proton_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_chi2proton_OnBeam_PID");

  TH2D* selproton1_dEdx_vs_resrange_OnBeam_PID = (TH2D*) OnBeam->Get("selproton1_dEdx_vs_resrange_OnBeam_PID");

  //////////////// proton 2
  TH1D* selproton2_lenght_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_lenght_OnBeam_PID");
  TH1D* selproton2_costheta_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_costheta_OnBeam_PID");
  TH1D* selproton2_phi_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_phi_OnBeam_PID");
  TH1D* selproton2_mom_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_mom_OnBeam_PID");
  TH1D* selproton2_chi2proton_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_chi2proton_OnBeam_PID");

  TH2D* selproton2_dEdx_vs_resrange_OnBeam_PID = (TH2D*) OnBeam->Get("selproton2_dEdx_vs_resrange_OnBeam_PID");

  /// opening angles
  TH1D* angle_mup1_OnBeam_PID = (TH1D*) OnBeam->Get("angle_mup1_OnBeam_PID");
  TH1D* angle_mup2_OnBeam_PID = (TH1D*) OnBeam->Get("angle_mup2_OnBeam_PID");
  TH1D* angle_p1p2_OnBeam_PID = (TH1D*) OnBeam->Get("angle_p1p2_OnBeam_PID");
  TH1D* cosangle_p1p2_OnBeam_PID = (TH1D*) OnBeam->Get("cosangle_p1p2_OnBeam_PID");

  //// Off-Beam data

  /// muon candidate properties
  TH1D* selmuon_lenght_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_lenght_OffBeam_PID");
  TH1D* selmuon_mom_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_mom_OffBeam_PID");
  TH1D* selmuon_costheta_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_costheta_OffBeam_PID");
  TH1D* selmuon_phi_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_phi_OffBeam_PID");

  TH1D* selmuon_chi2proton_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_chi2proton_OffBeam_PID");
  TH1D* selmuon_chi2proton_cont_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_chi2proton_cont_OffBeam_PID");
  TH1D* selmuon_chi2proton_uncont_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_chi2proton_uncont_OffBeam_PID");

  TH2D* selmuon_dEdx_vs_resrange_OffBeam_PID = (TH2D*) OffBeam->Get("selmuon_dEdx_vs_resrange_OffBeam_PID");

  ////proton 1

  TH1D* selproton1_lenght_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_lenght_OffBeam_PID");
  TH1D* selproton1_costheta_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_costheta_OffBeam_PID");
  TH1D* selproton1_phi_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_phi_OffBeam_PID");
  TH1D* selproton1_mom_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_mom_OffBeam_PID");

  TH1D* selproton1_chi2proton_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_chi2proton_OffBeam_PID");

  TH2D* selproton1_dEdx_vs_resrange_OffBeam_PID = (TH2D*) OffBeam->Get("selproton1_dEdx_vs_resrange_OffBeam_PID");

  //////////////// proton 2
  TH1D* selproton2_lenght_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_lenght_OffBeam_PID");
  TH1D* selproton2_costheta_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_costheta_OffBeam_PID");
  TH1D* selproton2_phi_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_phi_OffBeam_PID");
  TH1D* selproton2_mom_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_mom_OffBeam_PID");

  TH1D* selproton2_chi2proton_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_chi2proton_OffBeam_PID");

  TH2D* selproton2_dEdx_vs_resrange_OffBeam_PID = (TH2D*) OffBeam->Get("selproton2_dEdx_vs_resrange_OffBeam_PID");

  /// opening angles
 
  /// opening angles
  TH1D* angle_mup1_OffBeam_PID = (TH1D*) OffBeam->Get("angle_mup1_OffBeam_PID");
  TH1D* angle_mup2_OffBeam_PID = (TH1D*) OffBeam->Get("angle_mup2_OffBeam_PID");
  TH1D* angle_p1p2_OffBeam_PID = (TH1D*) OffBeam->Get("angle_p1p2_OffBeam_PID");
  TH1D* cosangle_p1p2_OffBeam_PID = (TH1D*) OffBeam->Get("cosangle_p1p2_OffBeam_PID");

  /// valores de las normalizaciones

  //Double_t normMCBNB =  (4.411e+19)/(4.0878e+20);//tune 3
   Double_t normMCBNB =  (4.411e+19)/(2.010e+20);//(4.874e+19)/(1.566e+20);
  Double_t normOffBeam = 9775610./73710197.;  //0.1464;//(33320382.)/(36177265.);

  //Double_t normOffBeam = 9775610./35789730.;  //0.1464;//(33320382.)/(36177265.);
  //h->Scale(1/norm);

  //  Double_t global = 0.547177;
  // normMCBNB =  normMCBNB*global;
  //normOffBeam = normOffBeam*global; 
  normMCBNB =  0.11947;

  /// normalizing MC
  std::cout<<"antes del scale"<<std::endl;
  std::cout<<"normMCBNB : "<<normMCBNB<<std::endl;
  std::cout<<"normOffBeam : "<<normOffBeam<<std::endl;
  
  selmuon_lenght_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selmuon_lenght_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selmuon_lenght_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selmuon_lenght_CC0PionNProton_PID_300->Scale(normMCBNB);
  selmuon_lenght_CC1PionNProton_PID_300->Scale(normMCBNB);
  selmuon_lenght_CCNPionNProton_PID_300->Scale(normMCBNB);
  selmuon_lenght_CCNue_PID_300->Scale(normMCBNB);;
  selmuon_lenght_NC_PID_300->Scale(normMCBNB);
  selmuon_lenght_OOFV_PID_300->Scale(normMCBNB);
  selmuon_lenght_EXT_PID_300->Scale(normMCBNB);
  selmuon_lenght_other_PID_300->Scale(normMCBNB);
 
  selmuon_mom_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selmuon_mom_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selmuon_mom_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selmuon_mom_CC0PionNProton_PID_300->Scale(normMCBNB);
  selmuon_mom_CC1PionNProton_PID_300->Scale(normMCBNB);
  selmuon_mom_CCNPionNProton_PID_300->Scale(normMCBNB);
  selmuon_mom_CCNue_PID_300->Scale(normMCBNB);
  selmuon_mom_NC_PID_300->Scale(normMCBNB);
  selmuon_mom_OOFV_PID_300->Scale(normMCBNB);
  selmuon_mom_EXT_PID_300->Scale(normMCBNB);
  selmuon_mom_other_PID_300->Scale(normMCBNB);
  
  selmuon_costheta_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selmuon_costheta_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selmuon_costheta_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selmuon_costheta_CC0PionNProton_PID_300->Scale(normMCBNB);
  selmuon_costheta_CC1PionNProton_PID_300->Scale(normMCBNB);
  selmuon_costheta_CCNPionNProton_PID_300->Scale(normMCBNB);
  selmuon_costheta_CCNue_PID_300->Scale(normMCBNB);
  selmuon_costheta_NC_PID_300->Scale(normMCBNB);
  selmuon_costheta_OOFV_PID_300->Scale(normMCBNB);
  selmuon_costheta_EXT_PID_300->Scale(normMCBNB);
  selmuon_costheta_other_PID_300->Scale(normMCBNB);
  
  selmuon_phi_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selmuon_phi_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selmuon_phi_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selmuon_phi_CC0PionNProton_PID_300->Scale(normMCBNB);
  selmuon_phi_CC1PionNProton_PID_300->Scale(normMCBNB);
  selmuon_phi_CCNPionNProton_PID_300->Scale(normMCBNB);
  selmuon_phi_CCNue_PID_300->Scale(normMCBNB);
  selmuon_phi_NC_PID_300->Scale(normMCBNB);
  selmuon_phi_OOFV_PID_300->Scale(normMCBNB);
  selmuon_phi_EXT_PID_300->Scale(normMCBNB);
  selmuon_phi_other_PID_300->Scale(normMCBNB);
  
  selmuon_lenght_muon_PID_300->Scale(normMCBNB);
  selmuon_lenght_proton_PID_300->Scale(normMCBNB);
  selmuon_lenght_pion_PID_300->Scale(normMCBNB);
  selmuon_lenght_electron_PID_300->Scale(normMCBNB);
  selmuon_lenght_pother_PID_300->Scale(normMCBNB);
  
  selmuon_mom_muon_PID_300->Scale(normMCBNB);
  selmuon_mom_proton_PID_300->Scale(normMCBNB);
  selmuon_mom_pion_PID_300->Scale(normMCBNB);
  selmuon_mom_electron_PID_300->Scale(normMCBNB);
  selmuon_mom_pother_PID_300->Scale(normMCBNB);
  
  selmuon_costheta_muon_PID_300->Scale(normMCBNB);
  selmuon_costheta_proton_PID_300->Scale(normMCBNB);
  selmuon_costheta_pion_PID_300->Scale(normMCBNB);
  selmuon_costheta_electron_PID_300->Scale(normMCBNB);
  selmuon_costheta_pother_PID_300->Scale(normMCBNB);
  
  selmuon_phi_muon_PID_300->Scale(normMCBNB);
  selmuon_phi_proton_PID_300->Scale(normMCBNB);
  selmuon_phi_pion_PID_300->Scale(normMCBNB);
  selmuon_phi_electron_PID_300->Scale(normMCBNB);
  selmuon_phi_pother_PID_300->Scale(normMCBNB);
      
  ///
  selmuon_chi2proton_muon_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_proton_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_pion_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_electron_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_pother_PID_300->Scale(normMCBNB);
  
  selmuon_chi2proton_cont_muon_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_cont_proton_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_cont_pion_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_cont_electron_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_cont_pother_PID_300->Scale(normMCBNB);
  
  selmuon_chi2proton_uncont_muon_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_uncont_proton_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_uncont_pion_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_uncont_electron_PID_300->Scale(normMCBNB);
  selmuon_chi2proton_uncont_pother_PID_300->Scale(normMCBNB);
    
  /// proton 1

  selproton1_lenght_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton1_lenght_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton1_lenght_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton1_lenght_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton1_lenght_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton1_lenght_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton1_lenght_CCNue_PID_300->Scale(normMCBNB);
  selproton1_lenght_NC_PID_300->Scale(normMCBNB);
  selproton1_lenght_OOFV_PID_300->Scale(normMCBNB);
  selproton1_lenght_EXT_PID_300->Scale(normMCBNB);
  selproton1_lenght_other_PID_300->Scale(normMCBNB);
  
  selproton1_costheta_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton1_costheta_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton1_costheta_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton1_costheta_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton1_costheta_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton1_costheta_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton1_costheta_CCNue_PID_300->Scale(normMCBNB);
  selproton1_costheta_NC_PID_300->Scale(normMCBNB);
  selproton1_costheta_OOFV_PID_300->Scale(normMCBNB);
  selproton1_costheta_EXT_PID_300->Scale(normMCBNB);
  selproton1_costheta_other_PID_300->Scale(normMCBNB);
  
  selproton1_phi_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton1_phi_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton1_phi_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton1_phi_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton1_phi_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton1_phi_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton1_phi_CCNue_PID_300->Scale(normMCBNB);
  selproton1_phi_NC_PID_300->Scale(normMCBNB);
  selproton1_phi_OOFV_PID_300->Scale(normMCBNB);
  selproton1_phi_EXT_PID_300->Scale(normMCBNB);
  selproton1_phi_other_PID_300->Scale(normMCBNB);

  selproton1_mom_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton1_mom_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton1_mom_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton1_mom_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton1_mom_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton1_mom_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton1_mom_CCNue_PID_300->Scale(normMCBNB);
  selproton1_mom_NC_PID_300->Scale(normMCBNB);
  selproton1_mom_OOFV_PID_300->Scale(normMCBNB);
  selproton1_mom_EXT_PID_300->Scale(normMCBNB);
  selproton1_mom_other_PID_300->Scale(normMCBNB);
  
  selproton1_lenght_muon_PID_300->Scale(normMCBNB);
  selproton1_lenght_proton_PID_300->Scale(normMCBNB);
  selproton1_lenght_pion_PID_300->Scale(normMCBNB);
  selproton1_lenght_electron_PID_300->Scale(normMCBNB);
  selproton1_lenght_pother_PID_300->Scale(normMCBNB);
  
  selproton1_costheta_muon_PID_300->Scale(normMCBNB);
  selproton1_costheta_proton_PID_300->Scale(normMCBNB);
  selproton1_costheta_pion_PID_300->Scale(normMCBNB);
  selproton1_costheta_electron_PID_300->Scale(normMCBNB);
  selproton1_costheta_pother_PID_300->Scale(normMCBNB);
  
  selproton1_phi_muon_PID_300->Scale(normMCBNB);
  selproton1_phi_proton_PID_300->Scale(normMCBNB);
  selproton1_phi_pion_PID_300->Scale(normMCBNB);
  selproton1_phi_electron_PID_300->Scale(normMCBNB);
  selproton1_phi_pother_PID_300->Scale(normMCBNB);
    
  selproton1_chi2proton_muon_PID_300->Scale(normMCBNB);
  selproton1_chi2proton_proton_PID_300->Scale(normMCBNB);
  selproton1_chi2proton_pion_PID_300->Scale(normMCBNB);
  selproton1_chi2proton_electron_PID_300->Scale(normMCBNB);
  selproton1_chi2proton_pother_PID_300->Scale(normMCBNB);

  /// proton 2
  selproton2_lenght_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton2_lenght_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton2_lenght_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton2_lenght_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton2_lenght_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton2_lenght_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton2_lenght_CCNue_PID_300->Scale(normMCBNB);
  selproton2_lenght_NC_PID_300->Scale(normMCBNB);
  selproton2_lenght_OOFV_PID_300->Scale(normMCBNB);
  selproton2_lenght_EXT_PID_300->Scale(normMCBNB);
  selproton2_lenght_other_PID_300->Scale(normMCBNB);

  selproton2_costheta_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton2_costheta_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton2_costheta_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton2_costheta_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton2_costheta_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton2_costheta_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton2_costheta_CCNue_PID_300->Scale(normMCBNB);
  selproton2_costheta_NC_PID_300->Scale(normMCBNB);
  selproton2_costheta_OOFV_PID_300->Scale(normMCBNB);
  selproton2_costheta_EXT_PID_300->Scale(normMCBNB);
  selproton2_costheta_other_PID_300->Scale(normMCBNB);

  selproton2_phi_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton2_phi_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton2_phi_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton2_phi_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton2_phi_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton2_phi_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton2_phi_CCNue_PID_300->Scale(normMCBNB);
  selproton2_phi_NC_PID_300->Scale(normMCBNB);
  selproton2_phi_OOFV_PID_300->Scale(normMCBNB);
  selproton2_phi_EXT_PID_300->Scale(normMCBNB);
  selproton2_phi_other_PID_300->Scale(normMCBNB);

  selproton2_mom_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  selproton2_mom_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  selproton2_mom_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  selproton2_mom_CC0PionNProton_PID_300->Scale(normMCBNB);
  selproton2_mom_CC1PionNProton_PID_300->Scale(normMCBNB);
  selproton2_mom_CCNPionNProton_PID_300->Scale(normMCBNB);
  selproton2_mom_CCNue_PID_300->Scale(normMCBNB);
  selproton2_mom_NC_PID_300->Scale(normMCBNB);
  selproton2_mom_OOFV_PID_300->Scale(normMCBNB);
  selproton2_mom_EXT_PID_300->Scale(normMCBNB);
  selproton2_mom_other_PID_300->Scale(normMCBNB);

  selproton2_lenght_muon_PID_300->Scale(normMCBNB);
  selproton2_lenght_proton_PID_300->Scale(normMCBNB);
  selproton2_lenght_pion_PID_300->Scale(normMCBNB);
  selproton2_lenght_electron_PID_300->Scale(normMCBNB);
  selproton2_lenght_pother_PID_300->Scale(normMCBNB);

  selproton2_costheta_muon_PID_300->Scale(normMCBNB);
  selproton2_costheta_proton_PID_300->Scale(normMCBNB);
  selproton2_costheta_pion_PID_300->Scale(normMCBNB);
  selproton2_costheta_electron_PID_300->Scale(normMCBNB);
  selproton2_costheta_pother_PID_300->Scale(normMCBNB);

  selproton2_phi_muon_PID_300->Scale(normMCBNB);
  selproton2_phi_proton_PID_300->Scale(normMCBNB);
  selproton2_phi_pion_PID_300->Scale(normMCBNB);
  selproton2_phi_electron_PID_300->Scale(normMCBNB);
  selproton2_phi_pother_PID_300->Scale(normMCBNB);

  selproton2_chi2proton_muon_PID_300->Scale(normMCBNB);
  selproton2_chi2proton_proton_PID_300->Scale(normMCBNB);
  selproton2_chi2proton_pion_PID_300->Scale(normMCBNB);
  selproton2_chi2proton_electron_PID_300->Scale(normMCBNB);
  selproton2_chi2proton_pother_PID_300->Scale(normMCBNB);

  angle_mup1_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  angle_mup1_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  angle_mup1_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  angle_mup1_CC0PionNProton_PID_300->Scale(normMCBNB);
  angle_mup1_CC1PionNProton_PID_300->Scale(normMCBNB);
  angle_mup1_CCNPionNProton_PID_300->Scale(normMCBNB);
  angle_mup1_CCNue_PID_300->Scale(normMCBNB);;
  angle_mup1_NC_PID_300->Scale(normMCBNB);
  angle_mup1_OOFV_PID_300->Scale(normMCBNB);
  angle_mup1_EXT_PID_300->Scale(normMCBNB);
  angle_mup1_other_PID_300->Scale(normMCBNB);

  angle_mup2_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  angle_mup2_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  angle_mup2_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  angle_mup2_CC0PionNProton_PID_300->Scale(normMCBNB);
  angle_mup2_CC1PionNProton_PID_300->Scale(normMCBNB);
  angle_mup2_CCNPionNProton_PID_300->Scale(normMCBNB);
  angle_mup2_CCNue_PID_300->Scale(normMCBNB);;
  angle_mup2_NC_PID_300->Scale(normMCBNB);
  angle_mup2_OOFV_PID_300->Scale(normMCBNB);
  angle_mup2_EXT_PID_300->Scale(normMCBNB);
  angle_mup2_other_PID_300->Scale(normMCBNB);

  angle_p1p2_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  angle_p1p2_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  angle_p1p2_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  angle_p1p2_CC0PionNProton_PID_300->Scale(normMCBNB);
  angle_p1p2_CC1PionNProton_PID_300->Scale(normMCBNB);
  angle_p1p2_CCNPionNProton_PID_300->Scale(normMCBNB);
  angle_p1p2_CCNue_PID_300->Scale(normMCBNB);;
  angle_p1p2_NC_PID_300->Scale(normMCBNB);
  angle_p1p2_OOFV_PID_300->Scale(normMCBNB);
  angle_p1p2_EXT_PID_300->Scale(normMCBNB);
  angle_p1p2_other_PID_300->Scale(normMCBNB);

  cosangle_p1p2_CC0Pion0Proton_PID_300->Scale(normMCBNB);
  cosangle_p1p2_CC0Pion1Proton_PID_300->Scale(normMCBNB);
  cosangle_p1p2_CC0Pion2Proton_PID_300->Scale(normMCBNB);
  cosangle_p1p2_CC0PionNProton_PID_300->Scale(normMCBNB);
  cosangle_p1p2_CC1PionNProton_PID_300->Scale(normMCBNB);
  cosangle_p1p2_CCNPionNProton_PID_300->Scale(normMCBNB);
  cosangle_p1p2_CCNue_PID_300->Scale(normMCBNB);;
  cosangle_p1p2_NC_PID_300->Scale(normMCBNB);
  cosangle_p1p2_OOFV_PID_300->Scale(normMCBNB);
  cosangle_p1p2_EXT_PID_300->Scale(normMCBNB);
  cosangle_p1p2_other_PID_300->Scale(normMCBNB);

  /// Off beam data normalization
 
  /// muon candidate properties
  selmuon_lenght_OffBeam_PID->Scale(normOffBeam);
  selmuon_mom_OffBeam_PID->Scale(normOffBeam);
  selmuon_costheta_OffBeam_PID->Scale(normOffBeam);
  selmuon_phi_OffBeam_PID->Scale(normOffBeam);
  
  selmuon_chi2proton_OffBeam_PID->Scale(normOffBeam);
  selmuon_chi2proton_cont_OffBeam_PID->Scale(normOffBeam);
  selmuon_chi2proton_uncont_OffBeam_PID->Scale(normOffBeam);

  selmuon_dEdx_vs_resrange_OffBeam_PID->Scale(normOffBeam);

  ////proton 1

  selproton1_lenght_OffBeam_PID->Scale(normOffBeam);
  selproton1_costheta_OffBeam_PID->Scale(normOffBeam);
  selproton1_phi_OffBeam_PID->Scale(normOffBeam);
  selproton1_mom_OffBeam_PID->Scale(normOffBeam);

  selproton1_chi2proton_OffBeam_PID->Scale(normOffBeam);
  selproton1_dEdx_vs_resrange_OffBeam_PID->Scale(normOffBeam);

  //////////////// proton 2
  selproton2_lenght_OffBeam_PID->Scale(normOffBeam);
  selproton2_costheta_OffBeam_PID->Scale(normOffBeam);
  selproton2_phi_OffBeam_PID->Scale(normOffBeam);
  selproton2_mom_OffBeam_PID->Scale(normOffBeam);

  selproton2_chi2proton_OffBeam_PID->Scale(normOffBeam);

  selproton2_dEdx_vs_resrange_OffBeam_PID->Scale(normOffBeam);  

  angle_mup1_OffBeam_PID->Scale(normOffBeam);
  angle_mup2_OffBeam_PID->Scale(normOffBeam);
  angle_p1p2_OffBeam_PID->Scale(normOffBeam);
  cosangle_p1p2_OffBeam_PID->Scale(normOffBeam);
 
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

  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();              // pad1 becomes the current pad

  selmuon_lenght_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selmuon_lenght_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selmuon_lenght_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_lenght_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selmuon_lenght_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selmuon_lenght_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selmuon_lenght_CCNue_PID_300-> SetFillColor(31);
  selmuon_lenght_NC_PID_300-> SetFillColor(kOrange+6);
  selmuon_lenght_OOFV_PID_300-> SetFillColor(kYellow+2);
  selmuon_lenght_EXT_PID_300-> SetFillColor(kBlack);
  selmuon_lenght_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selmuon_lenght_PID_300 = new THStack("selmuon_lenght_PID_300","");
  selmuon_lenght_PID_300-> Add(selmuon_lenght_CC0Pion0Proton_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_CC0Pion1Proton_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_CC0Pion2Proton_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_CC0PionNProton_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_CC1PionNProton_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_CCNPionNProton_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_CCNue_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_NC_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_OOFV_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_EXT_PID_300);
  //selmuon_lenght_PID_300-> Add(selmuon_lenght_other_PID_300);
  selmuon_lenght_PID_300-> Add(selmuon_lenght_OffBeam_PID);
  //selmuon_lenght_PID_300->SetMaximum(600.);
  selmuon_lenght_PID_300-> Draw();
  //selmuon_lenght_PID_300->GetXaxis()->SetTitle("muon candidate, length [cm]");
  selmuon_lenght_PID_300->GetYaxis()->SetTitle("No. of Entries");
  selmuon_lenght_OnBeam_PID->SetLineColor(kBlack);
  selmuon_lenght_OnBeam_PID->SetMarkerStyle(20);
  selmuon_lenght_OnBeam_PID->Draw("e1same");

  TLegend *l1 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l1 -> SetNColumns(2);
  /*
  l1 -> AddEntry(selmuon_lenght_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CCNue_PID_300, "CC#nu_{e}", "f");
  l1 -> AddEntry(selmuon_lenght_NC_PID_300, "NC", "f");
  l1 -> AddEntry(selmuon_lenght_OOFV_PID_300, "OOFV", "f");
  l1 -> AddEntry(selmuon_lenght_EXT_PID_300, "cosmic", "f");
  //l1 -> AddEntry(selmuon_lenght_other_PID_300, "other", "f");
  l1 -> AddEntry(selmuon_lenght_OffBeam_PID, "off-beam data", "f");
  l1 -> AddEntry(selmuon_lenght_OnBeam_PID, "on-beam data", "lep");
  */
  l1 -> AddEntry(selmuon_lenght_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_CCNue_PID_300, "CC#nu_{e}", "f");
  l1 -> AddEntry(selmuon_lenght_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_NC_PID_300, "NC", "f");
  l1 -> AddEntry(selmuon_lenght_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_OOFV_PID_300, "OOFV", "f");
  l1 -> AddEntry(selmuon_lenght_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l1 -> AddEntry(selmuon_lenght_EXT_PID_300, "cosmic", "f");
  l1 -> AddEntry(selmuon_lenght_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l1 -> AddEntry(selmuon_lenght_OffBeam_PID, "off-beam data", "f");
  l1 -> AddEntry(selmuon_lenght_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l1 -> AddEntry(selmuon_lenght_OnBeam_PID, "on-beam data", "lep");
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
  TH1F *h1 = (TH1F*)selmuon_lenght_OnBeam_PID->Clone("h1");
  TH1 *last1 = (TH1*)selmuon_lenght_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last1, selmuon_lenght_OnBeam_PID, selmuon_lenght_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;
  
  h1->SetLineColor(kBlack);
   //h1->SetMinimum(0.8);  // Define Y ..
   //h1->SetMaximum(1.35); // .. range
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
  //h1->GetYaxis()->SetTitleOffset(1.55);
  h1->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h1->GetXaxis()->SetTitle("muon candidate, length [cm]");
  h1->GetXaxis()->SetTitleSize(20);
  h1->GetXaxis()->SetTitleFont(43);
  h1->GetXaxis()->SetTitleOffset(3.);
  h1->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetXaxis()->SetLabelSize(15);

  c1->Update();
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_lenght_topo_PID_300.pdf");

  TCanvas *c2 = new TCanvas("c2", "c2", 900, 900);
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.3, 1, 1.0);
  pad2->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad2->Draw();             // Draw the upper pad: pad1
  pad2->cd();              // pad1 becomes the current pad

  selmuon_mom_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selmuon_mom_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selmuon_mom_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_mom_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selmuon_mom_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selmuon_mom_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selmuon_mom_CCNue_PID_300-> SetFillColor(31);
  selmuon_mom_NC_PID_300-> SetFillColor(kOrange+6);
  selmuon_mom_OOFV_PID_300-> SetFillColor(kYellow+2);
  selmuon_mom_EXT_PID_300-> SetFillColor(kBlack);
  selmuon_mom_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selmuon_mom_PID_300 = new THStack("selmuon_mom_PID_300","");
  selmuon_mom_PID_300-> Add(selmuon_mom_CC0Pion0Proton_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_CC0Pion1Proton_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_CC0Pion2Proton_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_CC0PionNProton_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_CC1PionNProton_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_CCNPionNProton_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_CCNue_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_NC_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_OOFV_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_EXT_PID_300);
  //selmuon_mom_PID_300-> Add(selmuon_mom_other_PID_300);
  selmuon_mom_PID_300-> Add(selmuon_mom_OffBeam_PID);
  selmuon_mom_PID_300->SetMaximum(60.);
  selmuon_mom_PID_300-> Draw();
  //selmuon_mom_PID_300->GetXaxis()->SetTitle("muon candidate, momemtum [GeV/c]");
  selmuon_mom_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_mom_OnBeam_PID->SetLineColor(kBlack);
  selmuon_mom_OnBeam_PID->SetMarkerStyle(20);
  selmuon_mom_OnBeam_PID->Draw("e1same");

  TLegend *l2 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l2 -> SetNColumns(2);
  l2 -> AddEntry(selmuon_mom_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l2 -> AddEntry(selmuon_mom_CCNue_PID_300, "CC#nu_{e}", "f");
  l2 -> AddEntry(selmuon_mom_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l2 -> AddEntry(selmuon_mom_NC_PID_300, "NC", "f");
  l2 -> AddEntry(selmuon_mom_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l2 -> AddEntry(selmuon_mom_OOFV_PID_300, "OOFV", "f");
  l2 -> AddEntry(selmuon_mom_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l2 -> AddEntry(selmuon_mom_EXT_PID_300, "cosmic", "f");
  l2 -> AddEntry(selmuon_mom_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l2 -> AddEntry(selmuon_mom_OffBeam_PID, "off-beam data", "f");
  l2 -> AddEntry(selmuon_mom_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l2 -> AddEntry(selmuon_mom_OnBeam_PID, "on-beam data", "lep");

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
  TH1F *h2 = (TH1F*)selmuon_mom_OnBeam_PID->Clone("h2");
  TH1 *last2 = (TH1*)selmuon_mom_PID_300->GetStack()->Last();
  chi2test = Chi2Calc(last2, selmuon_mom_OnBeam_PID, selmuon_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h2->GetXaxis()->SetTitle("muon candidate, momemtum [GeV/c]");
  h2->GetXaxis()->SetTitleSize(20);
  h2->GetXaxis()->SetTitleFont(43);
  h2->GetXaxis()->SetTitleOffset(3.);
  h2->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h2->GetXaxis()->SetLabelSize(15);

  c2->Update();
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_mom_topo_PID_300.pdf");

  TCanvas *c3 = new TCanvas("c3", "c3", 900, 900);
  TPad *pad3 = new TPad("pad3", "pad3", 0, 0.3, 1, 1.0);
  pad3->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad3->Draw();             // Draw the upper pad: pad1
  pad3->cd();              // pad1 becomes the current pad

  selmuon_costheta_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selmuon_costheta_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selmuon_costheta_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_costheta_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selmuon_costheta_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selmuon_costheta_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selmuon_costheta_CCNue_PID_300-> SetFillColor(31);
  selmuon_costheta_NC_PID_300-> SetFillColor(kOrange+6);
  selmuon_costheta_OOFV_PID_300-> SetFillColor(kYellow+2);
  selmuon_costheta_EXT_PID_300-> SetFillColor(kBlack);
  selmuon_costheta_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selmuon_costheta_PID_300 = new THStack("selmuon_costheta_PID_300","");
  selmuon_costheta_PID_300-> Add(selmuon_costheta_CC0Pion0Proton_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_CC0Pion1Proton_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_CC0Pion2Proton_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_CC0PionNProton_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_CC1PionNProton_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_CCNPionNProton_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_CCNue_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_NC_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_OOFV_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_EXT_PID_300);
  //selmuon_costheta_PID_300-> Add(selmuon_costheta_other_PID_300);
  selmuon_costheta_PID_300-> Add(selmuon_costheta_OffBeam_PID);
  selmuon_costheta_PID_300->SetMaximum(120.);
  selmuon_costheta_PID_300-> Draw();
  //selmuon_costheta_PID_300->GetXaxis()->SetTitle("muon candidate, cos #theta");
  selmuon_costheta_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_costheta_OnBeam_PID->SetLineColor(kBlack);
  selmuon_costheta_OnBeam_PID->SetMarkerStyle(20);
  selmuon_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l3 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l3 -> SetNColumns(2);

  l3 -> AddEntry(selmuon_costheta_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_CCNue_PID_300, "CC#nu_{e}", "f");
  l3 -> AddEntry(selmuon_costheta_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_NC_PID_300, "NC", "f");
  l3 -> AddEntry(selmuon_costheta_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_OOFV_PID_300, "OOFV", "f");
  l3 -> AddEntry(selmuon_costheta_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l3 -> AddEntry(selmuon_costheta_EXT_PID_300, "cosmic", "f");
  l3 -> AddEntry(selmuon_costheta_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l3 -> AddEntry(selmuon_costheta_OffBeam_PID, "off-beam data", "f");
  l3 -> AddEntry(selmuon_costheta_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l3 -> AddEntry(selmuon_costheta_OnBeam_PID, "on-beam data", "lep");
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
  TH1F *h3 = (TH1F*)selmuon_costheta_OnBeam_PID->Clone("h3");
  TH1 *last3 = (TH1*)selmuon_costheta_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last3, selmuon_costheta_OnBeam_PID, selmuon_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h3->GetXaxis()->SetTitle("muon candidate, cos #theta");
  h3->GetXaxis()->SetTitleSize(20);
  h3->GetXaxis()->SetTitleFont(43);
  h3->GetXaxis()->SetTitleOffset(3.);
  h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h3->GetXaxis()->SetLabelSize(15);
  
  c3->Update();
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_costheta_topo_PID_300.pdf");

  TCanvas *c4 = new TCanvas("c4", "c4", 900, 900);
  TPad *pad4 = new TPad("pad4", "pad4", 0, 0.3, 1, 1.0);
  pad4->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad4->Draw();             // Draw the upper pad: pad1
  pad4->cd();              // pad1 becomes the current pad

  selmuon_phi_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selmuon_phi_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selmuon_phi_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_phi_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selmuon_phi_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selmuon_phi_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selmuon_phi_CCNue_PID_300-> SetFillColor(31);
  selmuon_phi_NC_PID_300-> SetFillColor(kOrange+6);
  selmuon_phi_OOFV_PID_300-> SetFillColor(kYellow+2);
  selmuon_phi_EXT_PID_300-> SetFillColor(kBlack);
  selmuon_phi_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selmuon_phi_PID_300 = new THStack("selmuon_phi_PID_300","");
  selmuon_phi_PID_300-> Add(selmuon_phi_CC0Pion0Proton_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_CC0Pion1Proton_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_CC0Pion2Proton_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_CC0PionNProton_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_CC1PionNProton_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_CCNPionNProton_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_CCNue_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_NC_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_OOFV_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_EXT_PID_300);
  //selmuon_phi_PID_300-> Add(selmuon_phi_other_PID_300);
  selmuon_phi_PID_300-> Add(selmuon_phi_OffBeam_PID);
  selmuon_phi_PID_300->SetMaximum(40.);
  selmuon_phi_PID_300-> Draw();
  //selmuon_phi_PID_300->GetXaxis()->SetTitle("muon candidate, #phi");
  selmuon_phi_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_phi_OnBeam_PID->SetLineColor(kBlack);
  selmuon_phi_OnBeam_PID->SetMarkerStyle(20);
  selmuon_phi_OnBeam_PID->Draw("e1same");

  TLegend *l4 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l4 -> SetNColumns(2);
  l4 -> AddEntry(selmuon_phi_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l4 -> AddEntry(selmuon_phi_CCNue_PID_300, "CC#nu_{e}", "f");
  l4 -> AddEntry(selmuon_phi_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l4 -> AddEntry(selmuon_phi_NC_PID_300, "NC", "f");
  l4 -> AddEntry(selmuon_phi_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l4 -> AddEntry(selmuon_phi_OOFV_PID_300, "OOFV", "f");
  l4 -> AddEntry(selmuon_phi_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l4 -> AddEntry(selmuon_phi_EXT_PID_300, "cosmic", "f");
  l4 -> AddEntry(selmuon_phi_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l4 -> AddEntry(selmuon_phi_OffBeam_PID, "off-beam data", "f");
  l4 -> AddEntry(selmuon_phi_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l4 -> AddEntry(selmuon_phi_OnBeam_PID, "on-beam data", "lep");
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
  TH1F *h4 = (TH1F*)selmuon_phi_OnBeam_PID->Clone("h4");
  TH1 *last4 = (TH1*)selmuon_phi_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last4, selmuon_phi_OnBeam_PID, selmuon_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h4->GetXaxis()->SetTitle("muon candidate, #phi");
  h4->GetXaxis()->SetTitleSize(20);
  h4->GetXaxis()->SetTitleFont(43);
  h4->GetXaxis()->SetTitleOffset(3.);
  h4->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h4->GetXaxis()->SetLabelSize(15);

  c4->Update();
  c4->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_phi_topo_PID_300.pdf");

  TCanvas *c5 = new TCanvas("c5", "c5", 900, 900);
  TPad *pad5 = new TPad("pad5", "pad5", 0, 0.3, 1, 1.0);
  pad5->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad5->Draw();             // Draw the upper pad: pad1
  pad5->cd();              // pad1 becomes the current pad

  selmuon_lenght_muon_PID_300-> SetFillColor(kRed +1);
  selmuon_lenght_proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_lenght_pion_PID_300-> SetFillColor(kOrange);
  selmuon_lenght_electron_PID_300-> SetFillColor(kRed-9);
  selmuon_lenght_pother_PID_300-> SetFillColor(kGreen-8);
  selmuon_lenght_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_lenghtpdg_PID_300 = new THStack("selmuon_lenghtpdg_PID_300","");
  selmuon_lenghtpdg_PID_300-> Add(selmuon_lenght_muon_PID_300);
  selmuon_lenghtpdg_PID_300-> Add(selmuon_lenght_proton_PID_300);
  selmuon_lenghtpdg_PID_300-> Add(selmuon_lenght_pion_PID_300);
  selmuon_lenghtpdg_PID_300-> Add(selmuon_lenght_electron_PID_300);
  selmuon_lenghtpdg_PID_300-> Add(selmuon_lenght_pother_PID_300);
  selmuon_lenghtpdg_PID_300-> Add(selmuon_lenght_OffBeam_PID);
  //selmuon_phi_PID_300->SetMaximum(600.);
  selmuon_lenghtpdg_PID_300-> Draw();
  //selmuon_lenghtpdg_PID_300->GetXaxis()->SetTitle("muon candidate, length [cm]");
  selmuon_lenghtpdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_lenght_OnBeam_PID->SetLineColor(kBlack);
  selmuon_lenght_OnBeam_PID->SetMarkerStyle(20);
  selmuon_lenght_OnBeam_PID->Draw("e1same");

  TLegend *l5 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l5 -> SetNColumns(2);
  l5 -> AddEntry(selmuon_lenght_muon_PID_300, "#mu", "f");
  l5 -> AddEntry(selmuon_lenght_proton_PID_300, "proton", "f");
  l5 -> AddEntry(selmuon_lenght_pion_PID_300, "#pi", "f");
  l5 -> AddEntry(selmuon_lenght_electron_PID_300, "e^{+/-}", "f");
  l5 -> AddEntry(selmuon_lenght_pother_PID_300, "other", "f");
  l5 -> AddEntry(selmuon_lenght_OffBeam_PID, "off-beam data", "f");
  l5 -> AddEntry(selmuon_lenght_OnBeam_PID, "on-beam data", "lep");
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
  TH1F *h5 = (TH1F*)selmuon_lenght_OnBeam_PID->Clone("h5");
  TH1 *last5 = (TH1*)selmuon_lenghtpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last5, selmuon_lenght_OnBeam_PID, selmuon_lenght_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h5->GetXaxis()->SetTitle("No. of Entries");
  h5->GetXaxis()->SetTitleSize(20);
  h5->GetXaxis()->SetTitleFont(43);
  h5->GetXaxis()->SetTitleOffset(3.);
  h5->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h5->GetXaxis()->SetLabelSize(15);

  c5->Update();
  c5->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_lenght_pdg_PID_300.pdf");

  TCanvas *c6 = new TCanvas("c6", "c6", 900, 900);
  TPad *pad6 = new TPad("pad6", "pad6", 0, 0.3, 1, 1.0);
  pad6->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad6->Draw();             // Draw the upper pad: pad1
  pad6->cd();              // pad1 becomes the current pad

  selmuon_mom_muon_PID_300-> SetFillColor(kRed +1);
  selmuon_mom_proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_mom_pion_PID_300-> SetFillColor(kOrange);
  selmuon_mom_electron_PID_300-> SetFillColor(kRed-9);
  selmuon_mom_pother_PID_300-> SetFillColor(kGreen-8);
  selmuon_mom_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_mompdg_PID_300 = new THStack("selmuon_mompdg_PID_300","");
  selmuon_mompdg_PID_300-> Add(selmuon_mom_muon_PID_300);
  selmuon_mompdg_PID_300-> Add(selmuon_mom_proton_PID_300);
  selmuon_mompdg_PID_300-> Add(selmuon_mom_pion_PID_300);
  selmuon_mompdg_PID_300-> Add(selmuon_mom_electron_PID_300);
  selmuon_mompdg_PID_300-> Add(selmuon_mom_pother_PID_300);
  selmuon_mompdg_PID_300-> Add(selmuon_mom_OffBeam_PID);
  //selmuon_phi_PID_300->SetMaximum(600.);
  selmuon_mompdg_PID_300-> Draw();
  //selmuon_mompdg_PID_300->GetXaxis()->SetTitle("muon candidate, momemtum [GeV/c]");
  selmuon_mompdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_mom_OnBeam_PID->SetLineColor(kBlack);
  selmuon_mom_OnBeam_PID->SetMarkerStyle(20);
  selmuon_mom_OnBeam_PID->Draw("e1same");

  TLegend *l6 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l6 -> SetNColumns(2);
  l6 -> AddEntry(selmuon_mom_muon_PID_300, "#mu", "f");
  l6 -> AddEntry(selmuon_mom_proton_PID_300, "proton", "f");
  l6 -> AddEntry(selmuon_mom_pion_PID_300, "#pi", "f");
  l6 -> AddEntry(selmuon_mom_electron_PID_300, "e^{+/-}", "f");
  l6 -> AddEntry(selmuon_mom_pother_PID_300, "other", "f");
  l6 -> AddEntry(selmuon_mom_OffBeam_PID, "off-beam data", "f");
  l6 -> AddEntry(selmuon_mom_OnBeam_PID, "on-beam data", "lep");
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
  TH1F *h6 = (TH1F*)selmuon_mom_OnBeam_PID->Clone("h6");
  TH1 *last6 = (TH1*)selmuon_mompdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last6, selmuon_mom_OnBeam_PID, selmuon_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h6->GetXaxis()->SetTitle("muon candidate, momemtum [GeV/c]");
  h6->GetXaxis()->SetTitleSize(20);
  h6->GetXaxis()->SetTitleFont(43);
  h6->GetXaxis()->SetTitleOffset(3.);
  h6->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h6->GetXaxis()->SetLabelSize(15);

  c6->Update();
  c6->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_mom_pdg_PID_300.pdf");

  TCanvas *c7 = new TCanvas("c7", "c7", 900, 900);

  TPad *pad7 = new TPad("pad7", "pad7", 0, 0.3, 1, 1.0);
  pad7->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad7->Draw();             // Draw the upper pad: pad1
  pad7->cd();              // pad1 becomes the current pad

  selmuon_costheta_muon_PID_300-> SetFillColor(kRed +1);
  selmuon_costheta_proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_costheta_pion_PID_300-> SetFillColor(kOrange);
  selmuon_costheta_electron_PID_300-> SetFillColor(kRed-9);
  selmuon_costheta_pother_PID_300-> SetFillColor(kGreen-8);
  selmuon_costheta_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_costhetapdg_PID_300 = new THStack("selmuon_costhetapdg_PID_300","");
  selmuon_costhetapdg_PID_300-> Add(selmuon_costheta_muon_PID_300);
  selmuon_costhetapdg_PID_300-> Add(selmuon_costheta_proton_PID_300);
  selmuon_costhetapdg_PID_300-> Add(selmuon_costheta_pion_PID_300);
  selmuon_costhetapdg_PID_300-> Add(selmuon_costheta_electron_PID_300);
  selmuon_costhetapdg_PID_300-> Add(selmuon_costheta_pother_PID_300);
  selmuon_costhetapdg_PID_300-> Add(selmuon_costheta_OffBeam_PID);
  selmuon_costhetapdg_PID_300->SetMaximum(120.);
  selmuon_costhetapdg_PID_300-> Draw();
  //selmuon_costhetapdg_PID_300->GetXaxis()->SetTitle("muon candidate, cos #theta");
  selmuon_costhetapdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_costheta_OnBeam_PID->SetLineColor(kBlack);
  selmuon_costheta_OnBeam_PID->SetMarkerStyle(20);
  selmuon_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l7 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l7 -> SetNColumns(2);
  l7 -> AddEntry(selmuon_costheta_muon_PID_300, "#mu", "f");
  l7 -> AddEntry(selmuon_costheta_proton_PID_300, "proton", "f");
  l7 -> AddEntry(selmuon_costheta_pion_PID_300, "#pi", "f");
  l7 -> AddEntry(selmuon_costheta_electron_PID_300, "e^{+/-}", "f");
  l7 -> AddEntry(selmuon_costheta_pother_PID_300, "other", "f");
  l7 -> AddEntry(selmuon_costheta_OffBeam_PID, "off-beam data", "f");
  l7 -> AddEntry(selmuon_costheta_OnBeam_PID, "on-beam data", "lep");
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
  TH1F *h7 = (TH1F*)selmuon_costheta_OnBeam_PID->Clone("h7");
  TH1 *last7 = (TH1*)selmuon_costhetapdg_PID_300->GetStack()->Last();
  chi2test = Chi2Calc(last7, selmuon_costheta_OnBeam_PID, selmuon_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h7->GetXaxis()->SetTitle("muon candidate, cos #theta");
  h7->GetXaxis()->SetTitleSize(20);
  h7->GetXaxis()->SetTitleFont(43);
  h7->GetXaxis()->SetTitleOffset(3.);
  h7->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h7->GetXaxis()->SetLabelSize(15);

  c7->Update();
  c7->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_costheta_pdg_PID_300.pdf");

  TCanvas *c8 = new TCanvas("c8", "c8", 900, 900);
  TPad *pad8 = new TPad("pad8", "pad8", 0, 0.3, 1, 1.0);
  pad8->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad8->Draw();             // Draw the upper pad: pad1
  pad8->cd();              // pad1 becomes the current pad

  selmuon_phi_muon_PID_300-> SetFillColor(kRed +1);
  selmuon_phi_proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_phi_pion_PID_300-> SetFillColor(kOrange);
  selmuon_phi_electron_PID_300-> SetFillColor(kRed-9);
  selmuon_phi_pother_PID_300-> SetFillColor(kGreen-8);
  selmuon_phi_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_phipdg_PID_300 = new THStack("selmuon_phipdg_PID_300","");
  selmuon_phipdg_PID_300-> Add(selmuon_phi_muon_PID_300);
  selmuon_phipdg_PID_300-> Add(selmuon_phi_proton_PID_300);
  selmuon_phipdg_PID_300-> Add(selmuon_phi_pion_PID_300);
  selmuon_phipdg_PID_300-> Add(selmuon_phi_electron_PID_300);
  selmuon_phipdg_PID_300-> Add(selmuon_phi_pother_PID_300);
  selmuon_phipdg_PID_300-> Add(selmuon_phi_OffBeam_PID);
  selmuon_phipdg_PID_300->SetMaximum(50.);
  selmuon_phipdg_PID_300-> Draw();
  //selmuon_phipdg_PID_300->GetXaxis()->SetTitle("muon candidate, #phi");
  selmuon_phipdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_phi_OnBeam_PID->SetLineColor(kBlack);
  selmuon_phi_OnBeam_PID->SetMarkerStyle(20);
  selmuon_phi_OnBeam_PID->Draw("e1same");

  TLegend *l8 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l8 -> SetNColumns(2);
  l8 -> AddEntry(selmuon_phi_muon_PID_300, "#mu", "f");
  l8 -> AddEntry(selmuon_phi_proton_PID_300, "proton", "f");
  l8 -> AddEntry(selmuon_phi_pion_PID_300, "#pi", "f");
  l8 -> AddEntry(selmuon_phi_electron_PID_300, "e^{+/-}", "f");
  l8 -> AddEntry(selmuon_phi_pother_PID_300, "other", "f");
  l8 -> AddEntry(selmuon_phi_OffBeam_PID, "off-beam data", "f");
  l8 -> AddEntry(selmuon_phi_OnBeam_PID, "on-beam data", "lep");
  l8 -> Draw();  
  
  TText *t8 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h8 = (TH1F*)selmuon_phi_OnBeam_PID->Clone("h8");
  TH1 *last8 = (TH1*)selmuon_phipdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last8, selmuon_phi_OnBeam_PID, selmuon_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h8->GetXaxis()->SetTitle("muon candidate, #phi");
  h8->GetXaxis()->SetTitleSize(20);
  h8->GetXaxis()->SetTitleFont(43);
  h8->GetXaxis()->SetTitleOffset(3.);
  h8->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h8->GetXaxis()->SetLabelSize(15);

  c8->Update();
  c8->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_phi_pdg_PID_300.pdf");

  TCanvas *c9 = new TCanvas("c9", "c9", 900, 900);
  TPad *pad9 = new TPad("pad9", "pad9", 0, 0.3, 1, 1.0);
  pad9->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad9->Draw();             // Draw the upper pad: pad1
  pad9->cd();              // pad1 becomes the current pad

  selmuon_chi2proton_muon_PID_300-> SetFillColor(kRed +1);
  selmuon_chi2proton_proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_chi2proton_pion_PID_300-> SetFillColor(kOrange);
  selmuon_chi2proton_electron_PID_300-> SetFillColor(kRed-9);
  selmuon_chi2proton_pother_PID_300-> SetFillColor(kGreen-8);
  selmuon_chi2proton_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_chi2protonpdg_PID_300 = new THStack("selmuon_chi2protonpdg_PID_300","");
  selmuon_chi2protonpdg_PID_300-> Add(selmuon_chi2proton_muon_PID_300);
  selmuon_chi2protonpdg_PID_300-> Add(selmuon_chi2proton_proton_PID_300);
  selmuon_chi2protonpdg_PID_300-> Add(selmuon_chi2proton_pion_PID_300);
  selmuon_chi2protonpdg_PID_300-> Add(selmuon_chi2proton_electron_PID_300);
  selmuon_chi2protonpdg_PID_300-> Add(selmuon_chi2proton_pother_PID_300);
  selmuon_chi2protonpdg_PID_300-> Add(selmuon_chi2proton_OffBeam_PID);
  //selmuon_chi2protonpdg_PID_300->SetMaximum(120.);
  selmuon_chi2protonpdg_PID_300-> Draw();
  // selmuon_chi2protonpdg_PID_300->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");
  selmuon_chi2protonpdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_chi2proton_OnBeam_PID->SetLineColor(kBlack);
  selmuon_chi2proton_OnBeam_PID->SetMarkerStyle(20);
  selmuon_chi2proton_OnBeam_PID->Draw("e1same");

  TLegend *l9 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l9 -> SetNColumns(2);
  l9 -> AddEntry(selmuon_chi2proton_muon_PID_300, "#mu", "f");
  l9 -> AddEntry(selmuon_chi2proton_proton_PID_300, "proton", "f");
  l9 -> AddEntry(selmuon_chi2proton_pion_PID_300, "#pi", "f");
  l9 -> AddEntry(selmuon_chi2proton_electron_PID_300, "e^{+/-}", "f");
  l9 -> AddEntry(selmuon_chi2proton_pother_PID_300, "other", "f");
  l9 -> AddEntry(selmuon_chi2proton_OffBeam_PID, "off-beam data", "f");
  l9 -> AddEntry(selmuon_chi2proton_OnBeam_PID, "on-beam data", "lep");
  l9 -> Draw();  
  
  TText *t9 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h9 = (TH1F*)selmuon_chi2proton_OnBeam_PID->Clone("h9");
  TH1 *last9 = (TH1*)selmuon_chi2protonpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last9, selmuon_chi2proton_OnBeam_PID, selmuon_chi2proton_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h9->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");
  h9->GetXaxis()->SetTitleSize(20);
  h9->GetXaxis()->SetTitleFont(43);
  h9->GetXaxis()->SetTitleOffset(3.);
  h9->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h9->GetXaxis()->SetLabelSize(15);

  c9->Update();
  c9->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_chi2proton_pdg_PID_300.pdf");

  TCanvas *c10 = new TCanvas("c10", "c10", 900, 900);
  TPad *pad10 = new TPad("pad10", "pad10", 0, 0.3, 1, 1.0);
  pad10->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad10->Draw();             // Draw the upper pad: pad1
  pad10->cd();              // pad1 becomes the current pad

  selproton1_lenght_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton1_lenght_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton1_lenght_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_lenght_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton1_lenght_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton1_lenght_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton1_lenght_CCNue_PID_300-> SetFillColor(31);
  selproton1_lenght_NC_PID_300-> SetFillColor(kOrange+6);
  selproton1_lenght_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton1_lenght_EXT_PID_300-> SetFillColor(kBlack);
  selproton1_lenght_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton1_lenght_PID_300 = new THStack("selproton1_lenght_PID_300","");
  selproton1_lenght_PID_300-> Add(selproton1_lenght_CC0Pion0Proton_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_CC0Pion1Proton_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_CC0Pion2Proton_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_CC0PionNProton_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_CC1PionNProton_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_CCNPionNProton_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_CCNue_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_NC_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_OOFV_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_EXT_PID_300);
  //selproton1_lenght_PID_300-> Add(selproton1_lenght_other_PID_300);
  selproton1_lenght_PID_300-> Add(selproton1_lenght_OffBeam_PID);
  //selproton1_lenght_PID_300->SetMaximum(600.);
  selproton1_lenght_PID_300-> Draw();
  //selproton1_lenght_PID_300->GetXaxis()->SetTitle("proton 1 candidate, length [cm]");
  selproton1_lenght_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton1_lenght_OnBeam_PID->SetLineColor(kBlack);
  selproton1_lenght_OnBeam_PID->SetMarkerStyle(20);
  selproton1_lenght_OnBeam_PID->Draw("e1same");

  TLegend *l10 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l10 -> SetNColumns(2);
  l10 -> AddEntry(selproton1_lenght_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l10 -> AddEntry(selproton1_lenght_CCNue_PID_300, "CC#nu_{e}", "f");
  l10 -> AddEntry(selproton1_lenght_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l10 -> AddEntry(selproton1_lenght_NC_PID_300, "NC", "f");
  l10 -> AddEntry(selproton1_lenght_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l10 -> AddEntry(selproton1_lenght_OOFV_PID_300, "OOFV", "f");
  l10 -> AddEntry(selproton1_lenght_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l10 -> AddEntry(selproton1_lenght_EXT_PID_300, "cosmic", "f");
  l10 -> AddEntry(selproton1_lenght_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l10 -> AddEntry(selproton1_lenght_OffBeam_PID, "off-beam data", "f");
  l10 -> AddEntry(selproton1_lenght_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l10 -> AddEntry(selproton1_lenght_OnBeam_PID, "on-beam data", "lep");
  l10 -> Draw();  
 
  TText *t10 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h10 = (TH1F*)selproton1_lenght_OnBeam_PID->Clone("h10");
  TH1 *last10 = (TH1*)selproton1_lenght_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last10, selproton1_lenght_OnBeam_PID, selproton1_lenght_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h10->GetXaxis()->SetTitle("proton 1 candidate, length [cm]");
  h10->GetXaxis()->SetTitleSize(20);
  h10->GetXaxis()->SetTitleFont(43);
  h10->GetXaxis()->SetTitleOffset(3.);
  h10->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h10->GetXaxis()->SetLabelSize(15);

  c10->Update();
  c10->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_lenght_topo_PID_300.pdf");

  TCanvas *c11 = new TCanvas("c11", "c11", 900, 900);
  TPad *pad11 = new TPad("pad11", "pad11", 0, 0.3, 1, 1.0);
  pad11->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad11->Draw();             // Draw the upper pad: pad1
  pad11->cd();              // pad1 becomes the current pad

  selproton1_costheta_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton1_costheta_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton1_costheta_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_costheta_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton1_costheta_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton1_costheta_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton1_costheta_CCNue_PID_300-> SetFillColor(31);
  selproton1_costheta_NC_PID_300-> SetFillColor(kOrange+6);
  selproton1_costheta_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton1_costheta_EXT_PID_300-> SetFillColor(kBlack);
  selproton1_costheta_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton1_costheta_PID_300 = new THStack("selproton1_costheta_PID_300","");
  selproton1_costheta_PID_300-> Add(selproton1_costheta_CC0Pion0Proton_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_CC0Pion1Proton_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_CC0Pion2Proton_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_CC0PionNProton_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_CC1PionNProton_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_CCNPionNProton_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_CCNue_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_NC_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_OOFV_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_EXT_PID_300);
  //selproton1_costheta_PID_300-> Add(selproton1_costheta_other_PID_300);
  selproton1_costheta_PID_300-> Add(selproton1_costheta_OffBeam_PID);
  selproton1_costheta_PID_300->SetMaximum(80.);
  selproton1_costheta_PID_300-> Draw();
  //selproton1_costheta_PID_300->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");
  selproton1_costheta_PID_300->GetXaxis()->SetTitle("No. of Entries");

  selproton1_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton1_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton1_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l11 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l11 -> SetNColumns(2);
  l11 -> AddEntry(selproton1_costheta_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l11 -> AddEntry(selproton1_costheta_CCNue_PID_300, "CC#nu_{e}", "f");
  l11 -> AddEntry(selproton1_costheta_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l11 -> AddEntry(selproton1_costheta_NC_PID_300, "NC", "f");
  l11 -> AddEntry(selproton1_costheta_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l11 -> AddEntry(selproton1_costheta_OOFV_PID_300, "OOFV", "f");
  l11 -> AddEntry(selproton1_costheta_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l11 -> AddEntry(selproton1_costheta_EXT_PID_300, "cosmic", "f");
  l11 -> AddEntry(selproton1_costheta_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l11 -> AddEntry(selproton1_costheta_OffBeam_PID, "off-beam data", "f");
  l11 -> AddEntry(selproton1_costheta_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l11 -> AddEntry(selproton1_costheta_OnBeam_PID, "on-beam data", "lep");
  l11 -> Draw();  

  TText *t11 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h11 = (TH1F*)selproton1_costheta_OnBeam_PID->Clone("h11");
  TH1 *last11 = (TH1*)selproton1_costheta_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last11, selproton1_costheta_OnBeam_PID, selproton1_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h11->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");
  h11->GetXaxis()->SetTitleSize(20);
  h11->GetXaxis()->SetTitleFont(43);
  h11->GetXaxis()->SetTitleOffset(3.);
  h11->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h11->GetXaxis()->SetLabelSize(15);

  c11->Update();
  c11->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_costheta_topo_PID_300.pdf");

  TCanvas *c12 = new TCanvas("c12", "c12", 900, 900);
  TPad *pad12 = new TPad("pad12", "pad12", 0, 0.3, 1, 1.0);
  pad12->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad12->Draw();             // Draw the upper pad: pad1
  pad12->cd();              // pad1 becomes the current pad

  selproton1_phi_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton1_phi_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton1_phi_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_phi_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton1_phi_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton1_phi_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton1_phi_CCNue_PID_300-> SetFillColor(31);
  selproton1_phi_NC_PID_300-> SetFillColor(kOrange+6);
  selproton1_phi_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton1_phi_EXT_PID_300-> SetFillColor(kBlack);
  selproton1_phi_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton1_phi_PID_300 = new THStack("selproton1_phi_PID_300","");
  selproton1_phi_PID_300-> Add(selproton1_phi_CC0Pion0Proton_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_CC0Pion1Proton_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_CC0Pion2Proton_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_CC0PionNProton_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_CC1PionNProton_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_CCNPionNProton_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_CCNue_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_NC_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_OOFV_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_EXT_PID_300);
  //selproton1_phi_PID_300-> Add(selproton1_phi_other_PID_300);
  selproton1_phi_PID_300-> Add(selproton1_phi_OffBeam_PID);
  selproton1_phi_PID_300->SetMaximum(40.);
  selproton1_phi_PID_300-> Draw();
  //  selproton1_phi_PID_300->GetXaxis()->SetTitle("proton 1 candidate, #phi");
  selproton1_phi_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton1_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton1_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton1_phi_OnBeam_PID->Draw("e1same");

  TLegend *l12 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l12 -> SetNColumns(2);
  l12 -> AddEntry(selproton1_phi_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l12 -> AddEntry(selproton1_phi_CCNue_PID_300, "CC#nu_{e}", "f");
  l12 -> AddEntry(selproton1_phi_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l12 -> AddEntry(selproton1_phi_NC_PID_300, "NC", "f");
  l12 -> AddEntry(selproton1_phi_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l12 -> AddEntry(selproton1_phi_OOFV_PID_300, "OOFV", "f");
  l12 -> AddEntry(selproton1_phi_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l12 -> AddEntry(selproton1_phi_EXT_PID_300, "cosmic", "f");
  l12 -> AddEntry(selproton1_phi_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l12 -> AddEntry(selproton1_phi_OffBeam_PID, "off-beam data", "f");
  l12 -> AddEntry(selproton1_phi_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l12 -> AddEntry(selproton1_phi_OnBeam_PID, "on-beam data", "lep");
  l12 -> Draw();  
  
  TText *t12 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h12 = (TH1F*)selproton1_phi_OnBeam_PID->Clone("h12");
  TH1 *last12 = (TH1*)selproton1_phi_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last12, selproton1_phi_OnBeam_PID, selproton1_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h12->GetXaxis()->SetTitle("proton 1 candidate, #phi");
  h12->GetXaxis()->SetTitleSize(20);
  h12->GetXaxis()->SetTitleFont(43);
  h12->GetXaxis()->SetTitleOffset(3.);
  h12->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h12->GetXaxis()->SetLabelSize(15);

  c12->Update();
  c12->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_phi_topo_PID_300.pdf");

  TCanvas *c13 = new TCanvas("c13", "c13", 900, 900);
  TPad *pad13 = new TPad("pad13", "pad13", 0, 0.3, 1, 1.0);
  pad13->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad13->Draw();             // Draw the upper pad: pad1
  pad13->cd();              // pad1 becomes the current pad

  selproton1_mom_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton1_mom_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton1_mom_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_mom_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton1_mom_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton1_mom_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton1_mom_CCNue_PID_300-> SetFillColor(31);
  selproton1_mom_NC_PID_300-> SetFillColor(kOrange+6);
  selproton1_mom_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton1_mom_EXT_PID_300-> SetFillColor(kBlack);
  selproton1_mom_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton1_mom_PID_300 = new THStack("selproton1_mom_PID_300","");
  selproton1_mom_PID_300-> Add(selproton1_mom_CC0Pion0Proton_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_CC0Pion1Proton_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_CC0Pion2Proton_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_CC0PionNProton_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_CC1PionNProton_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_CCNPionNProton_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_CCNue_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_NC_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_OOFV_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_EXT_PID_300);
  //selproton1_mom_PID_300-> Add(selproton1_mom_other_PID_300);
  selproton1_mom_PID_300-> Add(selproton1_mom_OffBeam_PID);
  selproton1_mom_PID_300->SetMaximum(60.);
  selproton1_mom_PID_300-> Draw();
  //selproton1_mom_PID_300->GetXaxis()->SetTitle("proton 1 candidate, momentum [GeV/c]");
  selproton1_mom_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton1_mom_OnBeam_PID->SetLineColor(kBlack);
  selproton1_mom_OnBeam_PID->SetMarkerStyle(20);
  selproton1_mom_OnBeam_PID->Draw("e1same");

  TLegend *l13 = new TLegend(0.5, 0.65, 1.1, 0.9);
  l13 -> SetNColumns(2);
  l13 -> AddEntry(selproton1_mom_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l13 -> AddEntry(selproton1_mom_CCNue_PID_300, "CC#nu_{e}", "f");
  l13 -> AddEntry(selproton1_mom_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l13 -> AddEntry(selproton1_mom_NC_PID_300, "NC", "f");
  l13 -> AddEntry(selproton1_mom_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l13 -> AddEntry(selproton1_mom_OOFV_PID_300, "OOFV", "f");
  l13 -> AddEntry(selproton1_mom_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l13 -> AddEntry(selproton1_mom_EXT_PID_300, "cosmic", "f");
  l13 -> AddEntry(selproton1_mom_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l13 -> AddEntry(selproton1_mom_OffBeam_PID, "off-beam data", "f");
  l13 -> AddEntry(selproton1_mom_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l13 -> AddEntry(selproton1_mom_OnBeam_PID, "on-beam data", "lep");
  l13 -> Draw();  

  TText *t13 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t13->Draw();
  
  c13->cd();
  TPad *pad13_2 = new TPad("pad13_2", "pad13_2", 0, 0.05, 1, 0.3);
  pad13_2->SetTopMargin(0.01);
  pad13_2->SetBottomMargin(0.2);
  pad13_2->SetGridx();
  pad13_2->SetGridy();
  pad13_2->Draw();
  pad13_2->cd();
  // Define the ratio plot
  TH1F *h13 = (TH1F*)selproton1_mom_OnBeam_PID->Clone("h13");
  TH1 *last13 = (TH1*)selproton1_mom_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last13, selproton1_mom_OnBeam_PID, selproton1_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h13->SetLineColor(kBlack);
  h13->Sumw2();
  h13->SetStats(0);      // No statistics on lower plot
  h13->Divide(last13);
  h13->SetMarkerStyle(21);
  h13->SetTitle("");
  h13->Draw("ep");       // Draw the ratio plot

  h13->GetYaxis()->SetTitle("Data/MC");
  h13->GetYaxis()->SetNdivisions(505);
  h13->GetYaxis()->SetTitleSize(20);
  h13->GetYaxis()->SetTitleFont(43);
  h13->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h13->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h13->GetXaxis()->SetTitle("proton 1 candidate, momentum [GeV/c]");
  h13->GetXaxis()->SetTitleSize(20);
  h13->GetXaxis()->SetTitleFont(43);
  h13->GetXaxis()->SetTitleOffset(3.);
  h13->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h13->GetXaxis()->SetLabelSize(15);

  c13->Update();
  c13->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_mom_topo_PID_300.pdf");

  TCanvas *c14 = new TCanvas("c14", "c14", 900, 900);
  TPad *pad14 = new TPad("pad14", "pad14", 0, 0.3, 1, 1.0);
  pad14->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad14->Draw();             // Draw the upper pad: pad1
  pad14->cd();              // pad1 becomes the current pad

  selproton1_lenght_muon_PID_300-> SetFillColor(kRed +1);
  selproton1_lenght_proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_lenght_pion_PID_300-> SetFillColor(kOrange);
  selproton1_lenght_electron_PID_300-> SetFillColor(kRed-9);
  selproton1_lenght_pother_PID_300-> SetFillColor(kGreen-8);
  selproton1_lenght_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton1_lenghtpdg_PID_300 = new THStack("selproton1_lenghtpdg_PID_300","");
  selproton1_lenghtpdg_PID_300-> Add(selproton1_lenght_muon_PID_300);
  selproton1_lenghtpdg_PID_300-> Add(selproton1_lenght_proton_PID_300);
  selproton1_lenghtpdg_PID_300-> Add(selproton1_lenght_pion_PID_300);
  selproton1_lenghtpdg_PID_300-> Add(selproton1_lenght_electron_PID_300);
  selproton1_lenghtpdg_PID_300-> Add(selproton1_lenght_pother_PID_300);
  selproton1_lenghtpdg_PID_300-> Add(selproton1_lenght_OffBeam_PID);
  //selmuon_chi2kaonpdg_PID_300->SetMaximum(50.);
  selproton1_lenghtpdg_PID_300-> Draw();
  //selproton1_lenghtpdg_PID_300->GetXaxis()->SetTitle("proton 1 candidate, length [cm]");
  selproton1_lenghtpdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton1_lenght_OnBeam_PID->SetLineColor(kBlack);
  selproton1_lenght_OnBeam_PID->SetMarkerStyle(20);
  selproton1_lenght_OnBeam_PID->Draw("e1same");

  TLegend *l14 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l14 -> SetNColumns(2);
  l14 -> AddEntry(selproton1_lenght_muon_PID_300, "#mu", "f");
  l14 -> AddEntry(selproton1_lenght_proton_PID_300, "proton", "f");
  l14 -> AddEntry(selproton1_lenght_pion_PID_300, "#pi", "f");
  l14 -> AddEntry(selproton1_lenght_electron_PID_300, "e^{+/-}", "f");
  l14 -> AddEntry(selproton1_lenght_pother_PID_300, "other", "f");
  l14 -> AddEntry(selproton1_lenght_OffBeam_PID, "off-beam data", "f");
  l14 -> AddEntry(selproton1_lenght_OnBeam_PID, "on-beam data", "lep");
  l14 -> Draw();  
  
  TText *t14 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t14->Draw();

  c14->cd();
  TPad *pad14_2 = new TPad("pad14_2", "pad14_2", 0, 0.05, 1, 0.3);
  pad14_2->SetTopMargin(0.01);
  pad14_2->SetBottomMargin(0.2);
  pad14_2->SetGridx();
  pad14_2->SetGridy();
  pad14_2->Draw();
  pad14_2->cd();
  // Define the ratio plot
  TH1F *h14 = (TH1F*)selproton1_lenght_OnBeam_PID->Clone("h14");
  TH1 *last14 = (TH1*)selproton1_lenghtpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last14, selproton1_lenght_OnBeam_PID, selproton1_lenght_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h14->SetLineColor(kBlack);
  h14->Sumw2();
  h14->SetStats(0);      // No statistics on lower plot
  h14->Divide(last14);
  h14->SetMarkerStyle(21);
  h14->SetTitle("");
  h14->Draw("ep");       // Draw the ratio plot

  h14->GetYaxis()->SetTitle("Data/MC");
  h14->GetYaxis()->SetNdivisions(505);
  h14->GetYaxis()->SetTitleSize(20);
  h14->GetYaxis()->SetTitleFont(43);
  h14->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h14->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h14->GetXaxis()->SetTitle("proton 1 candidate, length [cm]");
  h14->GetXaxis()->SetTitleSize(20);
  h14->GetXaxis()->SetTitleFont(43);
  h14->GetXaxis()->SetTitleOffset(3.);
  h14->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h14->GetXaxis()->SetLabelSize(15);

  c14->Update();
  c14->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_lenght_pdg_PID_300.pdf");

  TCanvas *c15 = new TCanvas("c15", "c15", 900, 900);
  TPad *pad15 = new TPad("pad15", "pad15", 0, 0.3, 1, 1.0);
  pad15->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad15->Draw();             // Draw the upper pad: pad1
  pad15->cd();              // pad1 becomes the current pad

  selproton1_costheta_muon_PID_300-> SetFillColor(kRed +1);
  selproton1_costheta_proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_costheta_pion_PID_300-> SetFillColor(kOrange);
  selproton1_costheta_electron_PID_300-> SetFillColor(kRed-9);
  selproton1_costheta_pother_PID_300-> SetFillColor(kGreen-8);
  selproton1_costheta_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton1_costhetapdg_PID_300 = new THStack("selproton1_costhetapdg_PID_300","");
  selproton1_costhetapdg_PID_300-> Add(selproton1_costheta_muon_PID_300);
  selproton1_costhetapdg_PID_300-> Add(selproton1_costheta_proton_PID_300);
  selproton1_costhetapdg_PID_300-> Add(selproton1_costheta_pion_PID_300);
  selproton1_costhetapdg_PID_300-> Add(selproton1_costheta_electron_PID_300);
  selproton1_costhetapdg_PID_300-> Add(selproton1_costheta_pother_PID_300);
  selproton1_costhetapdg_PID_300-> Add(selproton1_costheta_OffBeam_PID);
  selproton1_costhetapdg_PID_300->SetMaximum(80);
  selproton1_costhetapdg_PID_300-> Draw();
  //selproton1_costhetapdg_PID_300->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");
  selproton1_costhetapdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton1_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton1_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton1_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l15 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l15 -> SetNColumns(2);
  l15 -> AddEntry(selproton1_costheta_muon_PID_300, "#mu", "f");
  l15 -> AddEntry(selproton1_costheta_proton_PID_300, "proton", "f");
  l15 -> AddEntry(selproton1_costheta_pion_PID_300, "#pi", "f");
  l15 -> AddEntry(selproton1_costheta_electron_PID_300, "e^{+/-}", "f");
  l15 -> AddEntry(selproton1_costheta_pother_PID_300, "other", "f");
  l15 -> AddEntry(selproton1_costheta_OffBeam_PID, "off-beam data", "f");
  l15 -> AddEntry(selproton1_costheta_OnBeam_PID, "on-beam data", "lep");
  l15 -> Draw();  

  TText *t15 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t15->Draw();

  c15->cd();
  TPad *pad15_2 = new TPad("pad15_2", "pad15_2", 0, 0.05, 1, 0.3);
  pad15_2->SetTopMargin(0.01);
  pad15_2->SetBottomMargin(0.2);
  pad15_2->SetGridx();
  pad15_2->SetGridy();
  pad15_2->Draw();
  pad15_2->cd();
  // Define the ratio plot
  TH1F *h15 = (TH1F*)selproton1_costheta_OnBeam_PID->Clone("h15");
  TH1 *last15 = (TH1*)selproton1_costhetapdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last15, selproton1_costheta_OnBeam_PID, selproton1_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h15->SetLineColor(kBlack);
  h15->Sumw2();
  h15->SetStats(0);      // No statistics on lower plot
  h15->Divide(last15);
  h15->SetMarkerStyle(21);
  h15->SetTitle("");
  h15->Draw("ep");       // Draw the ratio plot

  h15->GetYaxis()->SetTitle("Data/MC");
  h15->GetYaxis()->SetNdivisions(505);
  h15->GetYaxis()->SetTitleSize(20);
  h15->GetYaxis()->SetTitleFont(43);
  h15->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h15->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h15->GetXaxis()->SetTitle("proton 1 candidate, cos #theta");
  h15->GetXaxis()->SetTitleSize(20);
  h15->GetXaxis()->SetTitleFont(43);
  h15->GetXaxis()->SetTitleOffset(3.);
  h15->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h15->GetXaxis()->SetLabelSize(15);
  
  c15->Update();
  c15->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_costheta_pdg_PID_300.pdf");

  TCanvas *c16 = new TCanvas("c16", "c16", 900, 900);
  TPad *pad16 = new TPad("pad16", "pad16", 0, 0.3, 1, 1.0);
  pad16->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad16->Draw();             // Draw the upper pad: pad1
  pad16->cd();              // pad1 becomes the current pad

  selproton1_phi_muon_PID_300-> SetFillColor(kRed +1);
  selproton1_phi_proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_phi_pion_PID_300-> SetFillColor(kOrange);
  selproton1_phi_electron_PID_300-> SetFillColor(kRed-9);
  selproton1_phi_pother_PID_300-> SetFillColor(kGreen-8);
  selproton1_phi_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton1_phipdg_PID_300 = new THStack("selproton1_phipdg_PID_300","");
  selproton1_phipdg_PID_300-> Add(selproton1_phi_muon_PID_300);
  selproton1_phipdg_PID_300-> Add(selproton1_phi_proton_PID_300);
  selproton1_phipdg_PID_300-> Add(selproton1_phi_pion_PID_300);
  selproton1_phipdg_PID_300-> Add(selproton1_phi_electron_PID_300);
  selproton1_phipdg_PID_300-> Add(selproton1_phi_pother_PID_300);
  selproton1_phipdg_PID_300-> Add(selproton1_phi_OffBeam_PID);
  selproton1_phipdg_PID_300->SetMaximum(40.);
  selproton1_phipdg_PID_300-> Draw();
  //selproton1_phipdg_PID_300->GetXaxis()->SetTitle("proton 1 candidate, #phi");
  selproton1_phipdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton1_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton1_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton1_phi_OnBeam_PID->Draw("e1same");

  TLegend *l16 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l16 -> SetNColumns(2);
  l16 -> AddEntry(selproton1_phi_muon_PID_300, "#mu", "f");
  l16 -> AddEntry(selproton1_phi_proton_PID_300, "proton", "f");
  l16 -> AddEntry(selproton1_phi_pion_PID_300, "#pi", "f");
  l16 -> AddEntry(selproton1_phi_electron_PID_300, "e^{+/-}", "f");
  l16 -> AddEntry(selproton1_phi_pother_PID_300, "other", "f");
  l16 -> AddEntry(selproton1_phi_OffBeam_PID, "off-beam data", "f");
  l16 -> AddEntry(selproton1_phi_OnBeam_PID, "on-beam data", "lep");
  l16 -> Draw();  

  TText *t16 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t16->Draw();

  c16->cd();
  TPad *pad16_2 = new TPad("pad16_2", "pad16_2", 0, 0.05, 1, 0.3);
  pad16_2->SetTopMargin(0.01);
  pad16_2->SetBottomMargin(0.2);
  pad16_2->SetGridx();
  pad16_2->SetGridy();
  pad16_2->Draw();
  pad16_2->cd();
  // Define the ratio plot
  TH1F *h16 = (TH1F*)selproton1_phi_OnBeam_PID->Clone("h16");
  TH1 *last16 = (TH1*)selproton1_phipdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last16, selproton1_phi_OnBeam_PID, selproton1_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h16->SetLineColor(kBlack);
  h16->Sumw2();
  h16->SetStats(0);      // No statistics on lower plot
  h16->Divide(last16);
  h16->SetMarkerStyle(21);
  h16->SetTitle("");
  h16->Draw("ep");       // Draw the ratio plot

  h16->GetYaxis()->SetTitle("Data/MC");
  h16->GetYaxis()->SetNdivisions(505);
  h16->GetYaxis()->SetTitleSize(20);
  h16->GetYaxis()->SetTitleFont(43);
  h16->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h16->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h16->GetXaxis()->SetTitle("proton 1 candidate, #phi");
  h16->GetXaxis()->SetTitleSize(20);
  h16->GetXaxis()->SetTitleFont(43);
  h16->GetXaxis()->SetTitleOffset(3.);
  h16->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h16->GetXaxis()->SetLabelSize(15);
  
  c16->Update();
  c16->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_phi_pdg_PID_300.pdf");

  TCanvas *c17 = new TCanvas("c17", "c17", 900, 900);
  TPad *pad17 = new TPad("pad17", "pad17", 0, 0.3, 1, 1.0);
  pad17->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad17->Draw();             // Draw the upper pad: pad1
  pad17->cd();              // pad1 becomes the current pad

  selproton1_chi2proton_muon_PID_300-> SetFillColor(kRed +1);
  selproton1_chi2proton_proton_PID_300-> SetFillColor(kAzure+4);
  selproton1_chi2proton_pion_PID_300-> SetFillColor(kOrange);
  selproton1_chi2proton_electron_PID_300-> SetFillColor(kRed-9);
  selproton1_chi2proton_pother_PID_300-> SetFillColor(kGreen-8);
  selproton1_chi2proton_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton1_chi2protonpdg_PID_300 = new THStack("selproton1_chi2protonpdg_PID_300","");
  selproton1_chi2protonpdg_PID_300-> Add(selproton1_chi2proton_muon_PID_300);
  selproton1_chi2protonpdg_PID_300-> Add(selproton1_chi2proton_proton_PID_300);
  selproton1_chi2protonpdg_PID_300-> Add(selproton1_chi2proton_pion_PID_300);
  selproton1_chi2protonpdg_PID_300-> Add(selproton1_chi2proton_electron_PID_300);
  selproton1_chi2protonpdg_PID_300-> Add(selproton1_chi2proton_pother_PID_300);
  selproton1_chi2protonpdg_PID_300-> Add(selproton1_chi2proton_OffBeam_PID);
  //selproton1_chi2protonpdg_PID_300->SetMaximum(25.);
  selproton1_chi2protonpdg_PID_300-> Draw();
  //  selproton1_chi2protonpdg_PID_300->GetXaxis()->SetTitle("proton 1 candidate, #chi^{2}/dof proton hypothesis");
  selproton1_chi2protonpdg_PID_300->GetXaxis()->SetTitle("No. of Entries");

  selproton1_chi2proton_OnBeam_PID->SetLineColor(kBlack);
  selproton1_chi2proton_OnBeam_PID->SetMarkerStyle(20);
  selproton1_chi2proton_OnBeam_PID->Draw("e1same");

  TLegend *l17 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l17 -> SetNColumns(2);
  l17 -> AddEntry(selproton1_chi2proton_muon_PID_300, "#mu", "f");
  l17 -> AddEntry(selproton1_chi2proton_proton_PID_300, "proton", "f");
  l17 -> AddEntry(selproton1_chi2proton_pion_PID_300, "#pi", "f");
  l17 -> AddEntry(selproton1_chi2proton_electron_PID_300, "e^{+/-}", "f");
  l17 -> AddEntry(selproton1_chi2proton_pother_PID_300, "other", "f");
  l17 -> AddEntry(selproton1_chi2proton_OffBeam_PID, "off-beam data", "f");
  l17 -> AddEntry(selproton1_chi2proton_OnBeam_PID, "on-beam data", "lep");
  l17 -> Draw();  
  
  TText *t17 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h17 = (TH1F*)selproton1_chi2proton_OnBeam_PID->Clone("h17");
  TH1 *last17 = (TH1*)selproton1_chi2protonpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last17, selproton1_chi2proton_OnBeam_PID, selproton1_chi2proton_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h17->GetXaxis()->SetTitle("proton 1 candidate, #chi^{2}/dof proton hypothesis");
  h17->GetXaxis()->SetTitleSize(20);
  h17->GetXaxis()->SetTitleFont(43);
  h17->GetXaxis()->SetTitleOffset(3.);
  h17->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h17->GetXaxis()->SetLabelSize(15);

  c17->Update();
  c17->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_chi2proton_pdg_PID_300.pdf");

  TCanvas *c18 = new TCanvas("c18", "c18", 900, 900);
  TPad *pad18 = new TPad("pad18", "pad18", 0, 0.3, 1, 1.0);
  pad18->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad18->Draw();             // Draw the upper pad: pad1
  pad18->cd();              // pad1 becomes the current pad

  selproton2_lenght_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton2_lenght_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton2_lenght_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_lenght_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton2_lenght_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton2_lenght_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton2_lenght_CCNue_PID_300-> SetFillColor(31);
  selproton2_lenght_NC_PID_300-> SetFillColor(kOrange+6);
  selproton2_lenght_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton2_lenght_EXT_PID_300-> SetFillColor(kBlack);
  selproton2_lenght_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton2_lenght_PID_300 = new THStack("selproton2_lenght_PID_300","");
  selproton2_lenght_PID_300-> Add(selproton2_lenght_CC0Pion0Proton_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_CC0Pion1Proton_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_CC0Pion2Proton_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_CC0PionNProton_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_CC1PionNProton_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_CCNPionNProton_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_CCNue_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_NC_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_OOFV_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_EXT_PID_300);
  //selproton2_lenght_PID_300-> Add(selproton2_lenght_other_PID_300);
  selproton2_lenght_PID_300-> Add(selproton2_lenght_OffBeam_PID);
  //selproton2_lenght_PID_300->SetMaximum(600.);
  selproton2_lenght_PID_300-> Draw();
  //  selproton2_lenght_PID_300->GetXaxis()->SetTitle("proton 2 candidate, length [cm]");
  selproton2_lenght_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_lenght_OnBeam_PID->SetLineColor(kBlack);
  selproton2_lenght_OnBeam_PID->SetMarkerStyle(20);
  selproton2_lenght_OnBeam_PID->Draw("e1same");

  TLegend *l18 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l18 -> SetNColumns(2);
  l18 -> AddEntry(selproton2_lenght_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l18 -> AddEntry(selproton2_lenght_CCNue_PID_300, "CC#nu_{e}", "f");
  l18 -> AddEntry(selproton2_lenght_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l18 -> AddEntry(selproton2_lenght_NC_PID_300, "NC", "f");
  l18 -> AddEntry(selproton2_lenght_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l18 -> AddEntry(selproton2_lenght_OOFV_PID_300, "OOFV", "f");
  l18 -> AddEntry(selproton2_lenght_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l18 -> AddEntry(selproton2_lenght_EXT_PID_300, "cosmic", "f");
  l18 -> AddEntry(selproton2_lenght_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l18 -> AddEntry(selproton2_lenght_OffBeam_PID, "off-beam data", "f");
  l18 -> AddEntry(selproton2_lenght_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l18 -> AddEntry(selproton2_lenght_OnBeam_PID, "on-beam data", "lep");
  l18 -> Draw();  

  TText *t18 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h18 = (TH1F*)selproton2_lenght_OnBeam_PID->Clone("h18");
  TH1 *last18 = (TH1*)selproton2_lenght_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last18,selproton2_lenght_OnBeam_PID, selproton2_lenght_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h18->GetXaxis()->SetTitle("proton 2 candidate, length [cm]");
  h18->GetXaxis()->SetTitleSize(20);
  h18->GetXaxis()->SetTitleFont(43);
  h18->GetXaxis()->SetTitleOffset(3.);
  h18->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h18->GetXaxis()->SetLabelSize(15);

  c18->Update();
  c18->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_lenght_topo_PID_300.pdf");

  TCanvas *c19 = new TCanvas("c19", "c19", 900, 900);
  TPad *pad19 = new TPad("pad19", "pad19", 0, 0.3, 1, 1.0);
  pad19->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad19->Draw();             // Draw the upper pad: pad1
  pad19->cd();              // pad1 becomes the current pad

  selproton2_costheta_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton2_costheta_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton2_costheta_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_costheta_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton2_costheta_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton2_costheta_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton2_costheta_CCNue_PID_300-> SetFillColor(31);
  selproton2_costheta_NC_PID_300-> SetFillColor(kOrange+6);
  selproton2_costheta_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton2_costheta_EXT_PID_300-> SetFillColor(kBlack);
  selproton2_costheta_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton2_costheta_PID_300 = new THStack("selproton2_costheta_PID_300","");
  selproton2_costheta_PID_300-> Add(selproton2_costheta_CC0Pion0Proton_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_CC0Pion1Proton_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_CC0Pion2Proton_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_CC0PionNProton_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_CC1PionNProton_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_CCNPionNProton_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_CCNue_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_NC_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_OOFV_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_EXT_PID_300);
  //selproton2_costheta_PID_300-> Add(selproton2_costheta_other_PID_300);
  selproton2_costheta_PID_300-> Add(selproton2_costheta_OffBeam_PID);
  selproton2_costheta_PID_300->SetMaximum(50.);
  selproton2_costheta_PID_300-> Draw();
  //  selproton2_costheta_PID_300->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");
  selproton2_costheta_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton2_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton2_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l19 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l19 -> SetNColumns(2);
  l19 -> AddEntry(selproton2_costheta_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l19 -> AddEntry(selproton2_costheta_CCNue_PID_300, "CC#nu_{e}", "f");
  l19 -> AddEntry(selproton2_costheta_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l19 -> AddEntry(selproton2_costheta_NC_PID_300, "NC", "f");
  l19 -> AddEntry(selproton2_costheta_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l19 -> AddEntry(selproton2_costheta_OOFV_PID_300, "OOFV", "f");
  l19 -> AddEntry(selproton2_costheta_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l19 -> AddEntry(selproton2_costheta_EXT_PID_300, "cosmic", "f");
  l19 -> AddEntry(selproton2_costheta_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l19 -> AddEntry(selproton2_costheta_OffBeam_PID, "off-beam data", "f");
  l19 -> AddEntry(selproton2_costheta_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l19 -> AddEntry(selproton2_costheta_OnBeam_PID, "on-beam data", "lep");
  l19 -> Draw();  
  
  TText *t19 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t19->Draw();

  c19->cd();
  TPad *pad19_2 = new TPad("pad19_2", "pad19_2", 0, 0.05, 1, 0.3);
  pad19_2->SetTopMargin(0.01);
  pad19_2->SetBottomMargin(0.2);
  pad19_2->SetGridx();
  pad19_2->SetGridy();
  pad19_2->Draw();
  pad19_2->cd();
  // Define the ratio plot
  TH1F *h19 = (TH1F*)selproton2_costheta_OnBeam_PID->Clone("h19");
  TH1 *last19 = (TH1*)selproton2_costheta_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last19,selproton2_costheta_OnBeam_PID, selproton2_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h19->SetLineColor(kBlack);
  h19->Sumw2();
  h19->SetStats(0);      // No statistics on lower plot
  h19->Divide(last19);
  h19->SetMarkerStyle(21);
  h19->SetTitle("");
  h19->Draw("ep");       // Draw the ratio plot

  h19->GetYaxis()->SetTitle("Data/MC");
  h19->GetYaxis()->SetNdivisions(505);
  h19->GetYaxis()->SetTitleSize(20);
  h19->GetYaxis()->SetTitleFont(43);
  h19->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h19->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h19->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");
  h19->GetXaxis()->SetTitleSize(20);
  h19->GetXaxis()->SetTitleFont(43);
  h19->GetXaxis()->SetTitleOffset(3.);
  h19->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h19->GetXaxis()->SetLabelSize(15);

  c19->Update();
  c19->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_costheta_topo_PID_300.pdf");

  TCanvas *c20 = new TCanvas("c20", "c20", 900, 900);
  TPad *pad20 = new TPad("pad20", "pad20", 0, 0.3, 1, 1.0);
  pad20->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad20->Draw();             // Draw the upper pad: pad1
  pad20->cd();              // pad1 becomes the current pad

  selproton2_phi_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton2_phi_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton2_phi_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_phi_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton2_phi_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton2_phi_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton2_phi_CCNue_PID_300-> SetFillColor(31);
  selproton2_phi_NC_PID_300-> SetFillColor(kOrange+6);
  selproton2_phi_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton2_phi_EXT_PID_300-> SetFillColor(kBlack);
  selproton2_phi_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton2_phi_PID_300 = new THStack("selproton2_phi_PID_300","");
  selproton2_phi_PID_300-> Add(selproton2_phi_CC0Pion0Proton_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_CC0Pion1Proton_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_CC0Pion2Proton_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_CC0PionNProton_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_CC1PionNProton_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_CCNPionNProton_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_CCNue_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_NC_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_OOFV_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_EXT_PID_300);
  //selproton2_phi_PID_300-> Add(selproton2_phi_other_PID_300);
  selproton2_phi_PID_300-> Add(selproton2_phi_OffBeam_PID);
  selproton2_phi_PID_300->SetMaximum(40.);
  selproton2_phi_PID_300-> Draw();
  //selproton2_phi_PID_300->GetXaxis()->SetTitle("proton 2 candidate, #phi");
  selproton2_phi_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton2_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton2_phi_OnBeam_PID->Draw("e1same");

  TLegend *l20 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l20 -> SetNColumns(2);
  l20 -> AddEntry(selproton2_phi_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l20 -> AddEntry(selproton2_phi_CCNue_PID_300, "CC#nu_{e}", "f");
  l20 -> AddEntry(selproton2_phi_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l20 -> AddEntry(selproton2_phi_NC_PID_300, "NC", "f");
  l20 -> AddEntry(selproton2_phi_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l20 -> AddEntry(selproton2_phi_OOFV_PID_300, "OOFV", "f");
  l20 -> AddEntry(selproton2_phi_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l20 -> AddEntry(selproton2_phi_EXT_PID_300, "cosmic", "f");
  l20 -> AddEntry(selproton2_phi_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l20 -> AddEntry(selproton2_phi_OffBeam_PID, "off-beam data", "f");
  l20 -> AddEntry(selproton2_phi_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l20 -> AddEntry(selproton2_phi_OnBeam_PID, "on-beam data", "lep");
  l20 -> Draw();  

  TText *t20 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h20 = (TH1F*)selproton2_phi_OnBeam_PID->Clone("h20");
  TH1 *last20 = (TH1*)selproton2_phi_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last20,selproton2_phi_OnBeam_PID, selproton2_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h20->GetXaxis()->SetTitle("proton 2 candidate, #phi");
  h20->GetXaxis()->SetTitleSize(20);
  h20->GetXaxis()->SetTitleFont(43);
  h20->GetXaxis()->SetTitleOffset(3.);
  h20->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h20->GetXaxis()->SetLabelSize(15);

  c20->Update();
  c20->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_phi_topo_PID_300.pdf");

  TCanvas *c21 = new TCanvas("c21", "c21", 900, 900);
  TPad *pad21 = new TPad("pad21", "pad21", 0, 0.3, 1, 1.0);
  pad21->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad21->Draw();             // Draw the upper pad: pad1
  pad21->cd();              // pad1 becomes the current pad

  selproton2_mom_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  selproton2_mom_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  selproton2_mom_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_mom_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  selproton2_mom_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  selproton2_mom_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  selproton2_mom_CCNue_PID_300-> SetFillColor(31);
  selproton2_mom_NC_PID_300-> SetFillColor(kOrange+6);
  selproton2_mom_OOFV_PID_300-> SetFillColor(kYellow+2);
  selproton2_mom_EXT_PID_300-> SetFillColor(kBlack);
  selproton2_mom_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *selproton2_mom_PID_300 = new THStack("selproton2_mom_PID_300","");
  selproton2_mom_PID_300-> Add(selproton2_mom_CC0Pion0Proton_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_CC0Pion1Proton_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_CC0Pion2Proton_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_CC0PionNProton_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_CC1PionNProton_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_CCNPionNProton_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_CCNue_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_NC_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_OOFV_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_EXT_PID_300);
  //selproton2_mom_PID_300-> Add(selproton2_mom_other_PID_300);
  selproton2_mom_PID_300-> Add(selproton2_mom_OffBeam_PID);
  selproton2_mom_PID_300->SetMaximum(60.);
  selproton2_mom_PID_300-> Draw();
  //  selproton2_mom_PID_300->GetXaxis()->SetTitle("proton 2 candidate, momentum [GeV/c]");
  selproton2_mom_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_mom_OnBeam_PID->SetLineColor(kBlack);
  selproton2_mom_OnBeam_PID->SetMarkerStyle(20);
  selproton2_mom_OnBeam_PID->Draw("e1same");

  TLegend *l21 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l21 -> SetNColumns(2);
  l21 -> AddEntry(selproton2_mom_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l21 -> AddEntry(selproton2_mom_CCNue_PID_300, "CC#nu_{e}", "f");
  l21 -> AddEntry(selproton2_mom_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l21 -> AddEntry(selproton2_mom_NC_PID_300, "NC", "f");
  l21 -> AddEntry(selproton2_mom_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l21 -> AddEntry(selproton2_mom_OOFV_PID_300, "OOFV", "f");
  l21 -> AddEntry(selproton2_mom_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l21 -> AddEntry(selproton2_mom_EXT_PID_300, "cosmic", "f");
  l21 -> AddEntry(selproton2_mom_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l21 -> AddEntry(selproton2_mom_OffBeam_PID, "off-beam data", "f");
  l21 -> AddEntry(selproton2_mom_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l21 -> AddEntry(selproton2_mom_OnBeam_PID, "on-beam data", "lep");
  l21 -> Draw();  
 
  TText *t21 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h21 = (TH1F*)selproton2_mom_OnBeam_PID->Clone("h21");
  TH1 *last21 = (TH1*)selproton2_mom_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last21,selproton2_mom_OnBeam_PID, selproton2_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h21->GetXaxis()->SetTitle("proton 2 candidate, momentum [GeV/c]");
  h21->GetXaxis()->SetTitleSize(20);
  h21->GetXaxis()->SetTitleFont(43);
  h21->GetXaxis()->SetTitleOffset(3.);
  h21->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h21->GetXaxis()->SetLabelSize(15);

  c21->Update();
  c21->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_mom_topo_PID_300.pdf");

  TCanvas *c22 = new TCanvas("c22", "c22", 900, 900);
  TPad *pad22 = new TPad("pad22", "pad22", 0, 0.3, 1, 1.0);
  pad22->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad22->Draw();             // Draw the upper pad: pad1
  pad22->cd();              // pad1 becomes the current pad

  selproton2_lenght_muon_PID_300-> SetFillColor(kRed +1);
  selproton2_lenght_proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_lenght_pion_PID_300-> SetFillColor(kOrange);
  selproton2_lenght_electron_PID_300-> SetFillColor(kRed-9);
  selproton2_lenght_pother_PID_300-> SetFillColor(kGreen-8);
  selproton2_lenght_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton2_lenghtpdg_PID_300 = new THStack("selproton2_lenghtpdg_PID_300","");
  selproton2_lenghtpdg_PID_300-> Add(selproton2_lenght_muon_PID_300);
  selproton2_lenghtpdg_PID_300-> Add(selproton2_lenght_proton_PID_300);
  selproton2_lenghtpdg_PID_300-> Add(selproton2_lenght_pion_PID_300);
  selproton2_lenghtpdg_PID_300-> Add(selproton2_lenght_electron_PID_300);
  selproton2_lenghtpdg_PID_300-> Add(selproton2_lenght_pother_PID_300);
  selproton2_lenghtpdg_PID_300-> Add(selproton2_lenght_OffBeam_PID);
  //selmuon_chi2kaonpdg_PID_300->SetMaximum(50.);
  selproton2_lenghtpdg_PID_300-> Draw();
  //selproton2_lenghtpdg_PID_300->GetXaxis()->SetTitle("proton 2 candidate, length [cm]");
  selproton2_lenghtpdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_lenght_OnBeam_PID->SetLineColor(kBlack);
  selproton2_lenght_OnBeam_PID->SetMarkerStyle(20);
  selproton2_lenght_OnBeam_PID->Draw("e1same");

  TLegend *l22 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l22 -> SetNColumns(2);
  l22 -> AddEntry(selproton2_lenght_muon_PID_300, "#mu", "f");
  l22 -> AddEntry(selproton2_lenght_proton_PID_300, "proton", "f");
  l22 -> AddEntry(selproton2_lenght_pion_PID_300, "#pi", "f");
  l22 -> AddEntry(selproton2_lenght_electron_PID_300, "e^{+/-}", "f");
  l22 -> AddEntry(selproton2_lenght_pother_PID_300, "other", "f");
  l22 -> AddEntry(selproton2_lenght_OffBeam_PID, "off-beam data", "f");
  l22 -> AddEntry(selproton2_lenght_OnBeam_PID, "on-beam data", "lep");
  l22 -> Draw();  

  TText *t22 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h22 = (TH1F*)selproton2_lenght_OnBeam_PID->Clone("h22");
  TH1 *last22 = (TH1*)selproton2_lenghtpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last22,selproton2_lenght_OnBeam_PID, selproton2_lenght_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h22->GetXaxis()->SetTitle("proton 2 candidate, length [cm]");
  h22->GetXaxis()->SetTitleSize(20);
  h22->GetXaxis()->SetTitleFont(43);
  h22->GetXaxis()->SetTitleOffset(3.);
  h22->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h22->GetXaxis()->SetLabelSize(15);

  c22->Update();
  c22->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_lenght_pdg_PID_300.pdf");

  TCanvas *c23 = new TCanvas("c23", "c23", 900, 900);
  TPad *pad23 = new TPad("pad23", "pad23", 0, 0.3, 1, 1.0);
  pad23->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad23->Draw();             // Draw the upper pad: pad1
  pad23->cd();              // pad1 becomes the current pad

  selproton2_costheta_muon_PID_300-> SetFillColor(kRed +1);
  selproton2_costheta_proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_costheta_pion_PID_300-> SetFillColor(kOrange);
  selproton2_costheta_electron_PID_300-> SetFillColor(kRed-9);
  selproton2_costheta_pother_PID_300-> SetFillColor(kGreen-8);
  selproton2_costheta_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton2_costhetapdg_PID_300 = new THStack("selproton2_costhetapdg_PID_300","");
  selproton2_costhetapdg_PID_300-> Add(selproton2_costheta_muon_PID_300);
  selproton2_costhetapdg_PID_300-> Add(selproton2_costheta_proton_PID_300);
  selproton2_costhetapdg_PID_300-> Add(selproton2_costheta_pion_PID_300);
  selproton2_costhetapdg_PID_300-> Add(selproton2_costheta_electron_PID_300);
  selproton2_costhetapdg_PID_300-> Add(selproton2_costheta_pother_PID_300);
  selproton2_costhetapdg_PID_300-> Add(selproton2_costheta_OffBeam_PID);
  selproton2_costhetapdg_PID_300->SetMaximum(60.);
  selproton2_costhetapdg_PID_300-> Draw();
  //selproton2_costhetapdg_PID_300->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");
  selproton2_costhetapdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton2_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton2_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l23 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l23 -> SetNColumns(2);
  l23 -> AddEntry(selproton2_costheta_muon_PID_300, "#mu", "f");
  l23 -> AddEntry(selproton2_costheta_proton_PID_300, "proton", "f");
  l23 -> AddEntry(selproton2_costheta_pion_PID_300, "#pi", "f");
  l23 -> AddEntry(selproton2_costheta_electron_PID_300, "e^{+/-}", "f");
  l23 -> AddEntry(selproton2_costheta_pother_PID_300, "other", "f");
  l23 -> AddEntry(selproton2_costheta_OffBeam_PID, "off-beam data", "f");
  l23 -> AddEntry(selproton2_costheta_OnBeam_PID, "on-beam data", "lep");
  l23 -> Draw();  
  
  TText *t23 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h23 = (TH1F*)selproton2_costheta_OnBeam_PID->Clone("h23");
  TH1 *last23 = (TH1*)selproton2_costhetapdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last23,selproton2_costheta_OnBeam_PID, selproton2_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h23->GetXaxis()->SetTitle("proton 2 candidate, cos #theta");
  h23->GetXaxis()->SetTitleSize(20);
  h23->GetXaxis()->SetTitleFont(43);
  h23->GetXaxis()->SetTitleOffset(3.);
  h23->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h23->GetXaxis()->SetLabelSize(15);

  c23->Update();
  c23->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_costheta_pdg_PID_300.pdf");

  TCanvas *c24 = new TCanvas("c24", "c24", 900, 900);

  TPad *pad24 = new TPad("pad24", "pad24", 0, 0.3, 1, 1.0);
  pad24->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad24->Draw();             // Draw the upper pad: pad1
  pad24->cd();              // pad1 becomes the current pad

  selproton2_phi_muon_PID_300-> SetFillColor(kRed +1);
  selproton2_phi_proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_phi_pion_PID_300-> SetFillColor(kOrange);
  selproton2_phi_electron_PID_300-> SetFillColor(kRed-9);
  selproton2_phi_pother_PID_300-> SetFillColor(kGreen-8);
  selproton2_phi_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton2_phipdg_PID_300 = new THStack("selproton2_phipdg_PID_300","");
  selproton2_phipdg_PID_300-> Add(selproton2_phi_muon_PID_300);
  selproton2_phipdg_PID_300-> Add(selproton2_phi_proton_PID_300);
  selproton2_phipdg_PID_300-> Add(selproton2_phi_pion_PID_300);
  selproton2_phipdg_PID_300-> Add(selproton2_phi_electron_PID_300);
  selproton2_phipdg_PID_300-> Add(selproton2_phi_pother_PID_300);
  selproton2_phipdg_PID_300-> Add(selproton2_phi_OffBeam_PID);
  selproton2_phipdg_PID_300->SetMaximum(40.);
  selproton2_phipdg_PID_300-> Draw();
  //  selproton2_phipdg_PID_300->GetXaxis()->SetTitle("proton 2 candidate, #phi");
  selproton2_phipdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton2_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton2_phi_OnBeam_PID->Draw("e1same");

  TLegend *l24 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l24 -> SetNColumns(2);
  l24 -> AddEntry(selproton2_phi_muon_PID_300, "#mu", "f");
  l24 -> AddEntry(selproton2_phi_proton_PID_300, "proton", "f");
  l24 -> AddEntry(selproton2_phi_pion_PID_300, "#pi", "f");
  l24 -> AddEntry(selproton2_phi_electron_PID_300, "e^{+/-}", "f");
  l24 -> AddEntry(selproton2_phi_pother_PID_300, "other", "f");
  l24 -> AddEntry(selproton2_phi_OffBeam_PID, "off-beam data", "f");
  l24 -> AddEntry(selproton2_phi_OnBeam_PID, "on-beam data", "lep");
  l24 -> Draw();  
 
  TText *t24 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h24 = (TH1F*)selproton2_phi_OnBeam_PID->Clone("h24");
  TH1 *last24 = (TH1*)selproton2_phipdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last24,selproton2_phi_OnBeam_PID, selproton2_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h24->GetXaxis()->SetTitle("proton 2 candidate, #phi");
  h24->GetXaxis()->SetTitleSize(20);
  h24->GetXaxis()->SetTitleFont(43);
  h24->GetXaxis()->SetTitleOffset(3.);
  h24->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h24->GetXaxis()->SetLabelSize(15);

  c24->Update();
  c24->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_phi_pdg_PID_300.pdf");

  TCanvas *c25 = new TCanvas("c25", "c25", 900, 900);
  TPad *pad25 = new TPad("pad25", "pad25", 0, 0.3, 1, 1.0);
  pad25->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad25->Draw();             // Draw the upper pad: pad1
  pad25->cd();              // pad1 becomes the current pad

  selproton2_chi2proton_muon_PID_300-> SetFillColor(kRed +1);
  selproton2_chi2proton_proton_PID_300-> SetFillColor(kAzure+4);
  selproton2_chi2proton_pion_PID_300-> SetFillColor(kOrange);
  selproton2_chi2proton_electron_PID_300-> SetFillColor(kRed-9);
  selproton2_chi2proton_pother_PID_300-> SetFillColor(kGreen-8);
  selproton2_chi2proton_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton2_chi2protonpdg_PID_300 = new THStack("selproton2_chi2protonpdg_PID_300","");
  selproton2_chi2protonpdg_PID_300-> Add(selproton2_chi2proton_muon_PID_300);
  selproton2_chi2protonpdg_PID_300-> Add(selproton2_chi2proton_proton_PID_300);
  selproton2_chi2protonpdg_PID_300-> Add(selproton2_chi2proton_pion_PID_300);
  selproton2_chi2protonpdg_PID_300-> Add(selproton2_chi2proton_electron_PID_300);
  selproton2_chi2protonpdg_PID_300-> Add(selproton2_chi2proton_pother_PID_300);
  selproton2_chi2protonpdg_PID_300-> Add(selproton2_chi2proton_OffBeam_PID);
  //selproton2_chi2protonpdg_PID_300->SetMaximum(25.);
  selproton2_chi2protonpdg_PID_300-> Draw();
  //selproton2_chi2protonpdg_PID_300->GetXaxis()->SetTitle("proton 2 candidate, #chi^{2}/dof proton hypothesis");
  selproton2_chi2protonpdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selproton2_chi2proton_OnBeam_PID->SetLineColor(kBlack);
  selproton2_chi2proton_OnBeam_PID->SetMarkerStyle(20);
  selproton2_chi2proton_OnBeam_PID->Draw("e1same");

  TLegend *l25 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l25 -> SetNColumns(2);
  l25 -> AddEntry(selproton2_chi2proton_muon_PID_300, "#mu", "f");
  l25 -> AddEntry(selproton2_chi2proton_proton_PID_300, "proton", "f");
  l25 -> AddEntry(selproton2_chi2proton_pion_PID_300, "#pi", "f");
  l25 -> AddEntry(selproton2_chi2proton_electron_PID_300, "e^{+/-}", "f");
  l25 -> AddEntry(selproton2_chi2proton_pother_PID_300, "other", "f");
  l25 -> AddEntry(selproton2_chi2proton_OffBeam_PID, "off-beam data", "f");
  l25 -> AddEntry(selproton2_chi2proton_OnBeam_PID, "on-beam data", "lep");
  l25 -> Draw();  
 
  TText *t25 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h25 = (TH1F*)selproton2_chi2proton_OnBeam_PID->Clone("h25");
  TH1 *last25 = (TH1*)selproton2_chi2protonpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last25,selproton2_chi2proton_OnBeam_PID, selproton2_chi2proton_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h25->GetXaxis()->SetTitle("proton 2 candidate, #chi^{2}/dof proton hypothesis");
  h25->GetXaxis()->SetTitleSize(20);
  h25->GetXaxis()->SetTitleFont(43);
  h25->GetXaxis()->SetTitleOffset(3.);
  h25->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h25->GetXaxis()->SetLabelSize(15);

  c25->Update();
  c25->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_chi2proton_pdg_PID_300.pdf");

  TCanvas *c26 = new TCanvas("c26", "c26", 900, 900);
  TPad *pad26 = new TPad("pad26", "pad26", 0, 0.3, 1, 1.0);
  pad26->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad26->Draw();             // Draw the upper pad: pad1
  pad26->cd();              // pad1 becomes the current pad

  selmuon_chi2proton_cont_muon_PID_300-> SetFillColor(kRed +1);
  selmuon_chi2proton_cont_proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_chi2proton_cont_pion_PID_300-> SetFillColor(kOrange);
  selmuon_chi2proton_cont_electron_PID_300-> SetFillColor(kRed-9);
  selmuon_chi2proton_cont_pother_PID_300-> SetFillColor(kGreen-8);
  selmuon_chi2proton_cont_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_chi2proton_contpdg_PID_300 = new THStack("selmuon_chi2proton_contpdg_PID_300","");
  selmuon_chi2proton_contpdg_PID_300-> Add(selmuon_chi2proton_cont_muon_PID_300);
  selmuon_chi2proton_contpdg_PID_300-> Add(selmuon_chi2proton_cont_proton_PID_300);
  selmuon_chi2proton_contpdg_PID_300-> Add(selmuon_chi2proton_cont_pion_PID_300);
  selmuon_chi2proton_contpdg_PID_300-> Add(selmuon_chi2proton_cont_electron_PID_300);
  selmuon_chi2proton_contpdg_PID_300-> Add(selmuon_chi2proton_cont_pother_PID_300);
  selmuon_chi2proton_contpdg_PID_300-> Add(selmuon_chi2proton_cont_OffBeam_PID);
  //selmuon_chi2proton_contpdg_PID_300->SetMaximum(120.);
  selmuon_chi2proton_contpdg_PID_300-> Draw();
  //  selmuon_chi2proton_contpdg_PID_300->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");
  selmuon_chi2proton_contpdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_chi2proton_cont_OnBeam_PID->SetLineColor(kBlack);
  selmuon_chi2proton_cont_OnBeam_PID->SetMarkerStyle(20);
  selmuon_chi2proton_cont_OnBeam_PID->Draw("e1same");

  TLegend *l26 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l26 -> SetNColumns(2);
  l26 -> AddEntry(selmuon_chi2proton_cont_muon_PID_300, "#mu", "f");
  l26 -> AddEntry(selmuon_chi2proton_cont_proton_PID_300, "proton", "f");
  l26 -> AddEntry(selmuon_chi2proton_cont_pion_PID_300, "#pi", "f");
  l26 -> AddEntry(selmuon_chi2proton_cont_electron_PID_300, "e^{+/-}", "f");
  l26 -> AddEntry(selmuon_chi2proton_cont_pother_PID_300, "other", "f");
  l26 -> AddEntry(selmuon_chi2proton_cont_OffBeam_PID, "off-beam data", "f");
  l26 -> AddEntry(selmuon_chi2proton_cont_OnBeam_PID, "on-beam data", "lep");
  l26 -> Draw();  
  
  TText *t26 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h26 = (TH1F*)selmuon_chi2proton_cont_OnBeam_PID->Clone("h26");
  TH1 *last26 = (TH1*)selmuon_chi2proton_contpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last26,selmuon_chi2proton_cont_OnBeam_PID, selmuon_chi2proton_cont_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h26->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");
  h26->GetXaxis()->SetTitleSize(20);
  h26->GetXaxis()->SetTitleFont(43);
  h26->GetXaxis()->SetTitleOffset(3.);
  h26->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h26->GetXaxis()->SetLabelSize(15);

  c26->Update();
  c26->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_chi2proton_cont_pdg_PID_300.pdf");

  TCanvas *c27 = new TCanvas("c27", "c27", 900, 900);
  TPad *pad27 = new TPad("pad27", "pad27", 0, 0.3, 1, 1.0);
  pad27->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad27->Draw();             // Draw the upper pad: pad1
  pad27->cd();              // pad1 becomes the current pad

  selmuon_chi2proton_uncont_muon_PID_300-> SetFillColor(kRed +1);
  selmuon_chi2proton_uncont_proton_PID_300-> SetFillColor(kAzure+4);
  selmuon_chi2proton_uncont_pion_PID_300-> SetFillColor(kOrange);
  selmuon_chi2proton_uncont_electron_PID_300-> SetFillColor(kRed-9);
  selmuon_chi2proton_uncont_pother_PID_300-> SetFillColor(kGreen-8);
  selmuon_chi2proton_uncont_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_chi2proton_uncontpdg_PID_300 = new THStack("selmuon_chi2proton_uncontpdg_PID_300","");
  selmuon_chi2proton_uncontpdg_PID_300-> Add(selmuon_chi2proton_uncont_muon_PID_300);
  selmuon_chi2proton_uncontpdg_PID_300-> Add(selmuon_chi2proton_uncont_proton_PID_300);
  selmuon_chi2proton_uncontpdg_PID_300-> Add(selmuon_chi2proton_uncont_pion_PID_300);
  selmuon_chi2proton_uncontpdg_PID_300-> Add(selmuon_chi2proton_uncont_electron_PID_300);
  selmuon_chi2proton_uncontpdg_PID_300-> Add(selmuon_chi2proton_uncont_pother_PID_300);
  selmuon_chi2proton_uncontpdg_PID_300-> Add(selmuon_chi2proton_uncont_OffBeam_PID);
  //selmuon_chi2proton_uncontpdg_PID_300->SetMaximum(120.);
  selmuon_chi2proton_uncontpdg_PID_300-> Draw();
  //  selmuon_chi2proton_uncontpdg_PID_300->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");
  selmuon_chi2proton_uncontpdg_PID_300->GetYaxis()->SetTitle("No. of Entries");

  selmuon_chi2proton_uncont_OnBeam_PID->SetLineColor(kBlack);
  selmuon_chi2proton_uncont_OnBeam_PID->SetMarkerStyle(20);
  selmuon_chi2proton_uncont_OnBeam_PID->Draw("e1same");

  TLegend *l27 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l27 -> SetNColumns(2);
  l27 -> AddEntry(selmuon_chi2proton_uncont_muon_PID_300, "#mu", "f");
  l27 -> AddEntry(selmuon_chi2proton_uncont_proton_PID_300, "proton", "f");
  l27 -> AddEntry(selmuon_chi2proton_uncont_pion_PID_300, "#pi", "f");
  l27 -> AddEntry(selmuon_chi2proton_uncont_electron_PID_300, "e^{+/-}", "f");
  l27 -> AddEntry(selmuon_chi2proton_uncont_pother_PID_300, "other", "f");
  l27 -> AddEntry(selmuon_chi2proton_uncont_OffBeam_PID, "off-beam data", "f");
  l27 -> AddEntry(selmuon_chi2proton_uncont_OnBeam_PID, "on-beam data", "lep");
  l27 -> Draw();  

  TText *t27 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h27 = (TH1F*)selmuon_chi2proton_uncont_OnBeam_PID->Clone("h27");
  TH1 *last27 = (TH1*)selmuon_chi2proton_uncontpdg_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last27,selmuon_chi2proton_uncont_OnBeam_PID, selmuon_chi2proton_uncont_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h27->GetXaxis()->SetTitle("muon candidate, #chi^{2}/dof proton hypothesis");
  h27->GetXaxis()->SetTitleSize(20);
  h27->GetXaxis()->SetTitleFont(43);
  h27->GetXaxis()->SetTitleOffset(3.);
  h27->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h27->GetXaxis()->SetLabelSize(15);
  
  c27->Update();
  c27->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_chi2proton_uncont_pdg_PID_300.pdf");

  TCanvas *c28 = new TCanvas("c28", "c28", 900, 900);
  gStyle->SetOptStat(kFALSE);

  selproton1_dEdx_vs_resrange_OnBeam_PID->GetXaxis()->SetTitle("residual range [cm]");
  selproton1_dEdx_vs_resrange_OnBeam_PID->GetYaxis()->SetTitle("dE/dx [MeV/cm]");
  //selproton2_dEdx_vs_resrange_OffBeam_PID->SetMaximum(400.);
  selproton1_dEdx_vs_resrange_OnBeam_PID->Draw("colz");

  c28->Update();
  c28-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_dEdx_vs_resrange_OnBeam_PID.pdf");

  TCanvas *c29 = new TCanvas("c29", "c29", 900, 900);
  gStyle->SetOptStat(kFALSE);

  selproton2_dEdx_vs_resrange_OnBeam_PID->GetXaxis()->SetTitle("residual range [cm]");
  selproton2_dEdx_vs_resrange_OnBeam_PID->GetYaxis()->SetTitle("dE/dx [MeV/cm]");
  //selproton2_dEdx_vs_resrange_OffBeam_PID->SetMaximum(400.);
  selproton2_dEdx_vs_resrange_OnBeam_PID->Draw("colz");

  c29->Update();
  c29-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_dEdx_vs_resrange_OnBeam_PID.pdf");

  TCanvas *c30 = new TCanvas("c30", "c30", 900, 900);
  gStyle->SetOptStat(kFALSE);

  selmuon_dEdx_vs_resrange_OnBeam_PID->GetXaxis()->SetTitle("residual range [cm]");
  selmuon_dEdx_vs_resrange_OnBeam_PID->GetYaxis()->SetTitle("dE/dx [MeV/cm]");
  //selproton2_dEdx_vs_resrange_OffBeam_PID->SetMaximum(400.);
  selmuon_dEdx_vs_resrange_OnBeam_PID->Draw("colz");

  c30->Update();
  c30-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/muon_dEdx_vs_resrange_OnBeam_PID.pdf");

  TCanvas *c31 = new TCanvas("c31", "c31", 900, 900);
  TPad *pad31 = new TPad("pad31", "pad31", 0, 0.3, 1, 1.0);
  pad31->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad31->Draw();             // Draw the upper pad: pad1
  pad31->cd();              // pad1 becomes the current pad

  angle_mup1_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  angle_mup1_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  angle_mup1_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  angle_mup1_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  angle_mup1_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  angle_mup1_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  angle_mup1_CCNue_PID_300-> SetFillColor(31);
  angle_mup1_NC_PID_300-> SetFillColor(kOrange+6);
  angle_mup1_OOFV_PID_300-> SetFillColor(kYellow+2);
  angle_mup1_EXT_PID_300-> SetFillColor(kBlack);
  angle_mup1_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *angle_mup1_PID_300 = new THStack("angle_mup1_PID_300","");
  angle_mup1_PID_300-> Add(angle_mup1_CC0Pion0Proton_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_CC0Pion1Proton_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_CC0Pion2Proton_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_CC0PionNProton_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_CC1PionNProton_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_CCNPionNProton_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_CCNue_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_NC_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_OOFV_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_EXT_PID_300);
  //angle_mup1_PID_300-> Add(angle_mup1_other_PID_300);
  angle_mup1_PID_300-> Add(angle_mup1_OffBeam_PID);
  angle_mup1_PID_300->SetMaximum(50.);
  angle_mup1_PID_300-> Draw();
  //  angle_mup1_PID_300->GetXaxis()->SetTitle("cos #theta_{#mu -p_{1}} [rad]");
  angle_mup1_PID_300->GetYaxis()->SetTitle("No. of Entries");

  angle_mup1_OnBeam_PID->SetLineColor(kBlack);
  angle_mup1_OnBeam_PID->SetMarkerStyle(20);
  angle_mup1_OnBeam_PID->Draw("e1same");

  TLegend *l31 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l31 -> SetNColumns(2);
  l31 -> AddEntry(angle_mup1_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l31 -> AddEntry(angle_mup1_CCNue_PID_300, "CC#nu_{e}", "f");
  l31 -> AddEntry(angle_mup1_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l31 -> AddEntry(angle_mup1_NC_PID_300, "NC", "f");
  l31 -> AddEntry(angle_mup1_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l31 -> AddEntry(angle_mup1_OOFV_PID_300, "OOFV", "f");
  l31 -> AddEntry(angle_mup1_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l31 -> AddEntry(angle_mup1_EXT_PID_300, "cosmic", "f");
  l31 -> AddEntry(angle_mup1_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l31 -> AddEntry(angle_mup1_OffBeam_PID, "off-beam data", "f");
  l31 -> AddEntry(angle_mup1_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l31 -> AddEntry(angle_mup1_OnBeam_PID, "on-beam data", "lep");
  l31 -> Draw();  

  TText *t31 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t31->Draw();

  c31->cd();
  TPad *pad31_2 = new TPad("pad31_2", "pad31_2", 0, 0.05, 1, 0.3);
  pad31_2->SetTopMargin(0.01);
  pad31_2->SetBottomMargin(0.2);
  pad31_2->SetGridx();
  pad31_2->SetGridy();
  pad31_2->Draw();
  pad31_2->cd();
  // Define the ratio plot
  TH1F *h31 = (TH1F*)angle_mup1_OnBeam_PID->Clone("h31");
  TH1 *last31 = (TH1*)angle_mup1_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last31,angle_mup1_OnBeam_PID, angle_mup1_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h31->SetLineColor(kBlack);
  h31->Sumw2();
  h31->SetStats(0);      // No statistics on lower plot
  h31->Divide(last31);
  h31->SetMarkerStyle(21);
  h31->SetTitle("");
  h31->Draw("ep");       // Draw the ratio plot

  h31->GetYaxis()->SetTitle("Data/MC");
  h31->GetYaxis()->SetNdivisions(505);
  h31->GetYaxis()->SetTitleSize(20);
  h31->GetYaxis()->SetTitleFont(43);
  h31->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h31->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h31->GetXaxis()->SetTitle("cos #theta_{#mu -p_{1}}");
  h31->GetXaxis()->SetTitleSize(20);
  h31->GetXaxis()->SetTitleFont(43);
  h31->GetXaxis()->SetTitleOffset(3.);
  h31->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h31->GetXaxis()->SetLabelSize(15);
  
  c31->Update();
  c31->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/angle_mup1_topo_PID_300.pdf");

  TCanvas *c32 = new TCanvas("c32", "c32", 900, 900);
  TPad *pad32 = new TPad("pad32", "pad32", 0, 0.3, 1, 1.0);
  pad32->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad32->Draw();             // Draw the upper pad: pad1
  pad32->cd();              // pad1 becomes the current pad

  angle_mup2_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  angle_mup2_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  angle_mup2_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  angle_mup2_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  angle_mup2_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  angle_mup2_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  angle_mup2_CCNue_PID_300-> SetFillColor(31);
  angle_mup2_NC_PID_300-> SetFillColor(kOrange+6);
  angle_mup2_OOFV_PID_300-> SetFillColor(kYellow+2);
  angle_mup2_EXT_PID_300-> SetFillColor(kBlack);
  angle_mup2_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *angle_mup2_PID_300 = new THStack("angle_mup2_PID_300","");
  angle_mup2_PID_300-> Add(angle_mup2_CC0Pion0Proton_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_CC0Pion1Proton_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_CC0Pion2Proton_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_CC0PionNProton_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_CC1PionNProton_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_CCNPionNProton_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_CCNue_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_NC_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_OOFV_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_EXT_PID_300);
  //angle_mup2_PID_300-> Add(angle_mup2_other_PID_300);
  angle_mup2_PID_300-> Add(angle_mup2_OffBeam_PID);
  angle_mup2_PID_300->SetMaximum(50.);
  angle_mup2_PID_300-> Draw();
  // angle_mup2_PID_300->GetXaxis()->SetTitle("cos #theta_{#mu -p_{2}} [rad]");
  angle_mup2_PID_300->GetYaxis()->SetTitle("No. of Entries");

  angle_mup2_OnBeam_PID->SetLineColor(kBlack);
  angle_mup2_OnBeam_PID->SetMarkerStyle(20);
  angle_mup2_OnBeam_PID->Draw("e1same");

  TLegend *l32 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l32 -> SetNColumns(2);
  l32 -> AddEntry(angle_mup2_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l32 -> AddEntry(angle_mup2_CCNue_PID_300, "CC#nu_{e}", "f");
  l32 -> AddEntry(angle_mup2_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l32 -> AddEntry(angle_mup2_NC_PID_300, "NC", "f");
  l32 -> AddEntry(angle_mup2_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l32 -> AddEntry(angle_mup2_OOFV_PID_300, "OOFV", "f");
  l32 -> AddEntry(angle_mup2_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l32 -> AddEntry(angle_mup2_EXT_PID_300, "cosmic", "f");
  l32 -> AddEntry(angle_mup2_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l32 -> AddEntry(angle_mup2_OffBeam_PID, "off-beam data", "f");
  l32 -> AddEntry(angle_mup2_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l32 -> AddEntry(angle_mup2_OnBeam_PID, "on-beam data", "lep");
  l32 -> Draw();  
 
  TText *t32 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t32->Draw();
 
  c32->cd();
  TPad *pad32_2 = new TPad("pad32_2", "pad32_2", 0, 0.05, 1, 0.3);
  pad32_2->SetTopMargin(0.01);
  pad32_2->SetBottomMargin(0.2);
  pad32_2->SetGridx();
  pad32_2->SetGridy();
  pad32_2->Draw();
  pad32_2->cd();
  // Define the ratio plot
  TH1F *h32 = (TH1F*)angle_mup2_OnBeam_PID->Clone("h32");
  TH1 *last32 = (TH1*)angle_mup2_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last32,angle_mup2_OnBeam_PID, angle_mup2_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h32->SetLineColor(kBlack);
  h32->Sumw2();
  h32->SetStats(0);      // No statistics on lower plot
  h32->Divide(last32);
  h32->SetMarkerStyle(21);
  h32->SetTitle("");
  h32->Draw("ep");       // Draw the ratio plot

  h32->GetYaxis()->SetTitle("Data/MC");
  h32->GetYaxis()->SetNdivisions(505);
  h32->GetYaxis()->SetTitleSize(20);
  h32->GetYaxis()->SetTitleFont(43);
  h32->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h32->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h32->GetXaxis()->SetTitle("cos #theta_{#mu -p_{2}}");
  h32->GetXaxis()->SetTitleSize(20);
  h32->GetXaxis()->SetTitleFont(43);
  h32->GetXaxis()->SetTitleOffset(3.);
  h32->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h32->GetXaxis()->SetLabelSize(15);

  c32->Update();
  c32->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/angle_mup2_topo_PID_300.pdf");

  TCanvas *c33 = new TCanvas("c33", "c33", 900, 900);
  TPad *pad33 = new TPad("pad33", "pad33", 0, 0.3, 1, 1.0);
  pad33->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad33->Draw();             // Draw the upper pad: pad1
  pad33->cd();              // pad1 becomes the current pad

  angle_p1p2_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  angle_p1p2_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  angle_p1p2_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  angle_p1p2_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  angle_p1p2_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  angle_p1p2_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  angle_p1p2_CCNue_PID_300-> SetFillColor(31);
  angle_p1p2_NC_PID_300-> SetFillColor(kOrange+6);
  angle_p1p2_OOFV_PID_300-> SetFillColor(kYellow+2);
  angle_p1p2_EXT_PID_300-> SetFillColor(kBlack);
  angle_p1p2_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *angle_p1p2_PID_300 = new THStack("angle_p1p2_PID_300","");
  angle_p1p2_PID_300-> Add(angle_p1p2_CC0Pion0Proton_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_CC0Pion1Proton_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_CC0Pion2Proton_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_CC0PionNProton_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_CC1PionNProton_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_CCNPionNProton_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_CCNue_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_NC_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_OOFV_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_EXT_PID_300);
  //angle_p1p2_PID_300-> Add(angle_p1p2_other_PID_300);
  angle_p1p2_PID_300-> Add(angle_p1p2_OffBeam_PID);
  angle_p1p2_PID_300->SetMaximum(40.);
  angle_p1p2_PID_300-> Draw();
  //  angle_p1p2_PID_300->GetXaxis()->SetTitle("cos #theta_{p_{1} -p_{2}} [rad]");
  angle_p1p2_PID_300->GetYaxis()->SetTitle("No. of Entries");

  angle_p1p2_OnBeam_PID->SetLineColor(kBlack);
  angle_p1p2_OnBeam_PID->SetMarkerStyle(20);
  angle_p1p2_OnBeam_PID->Draw("e1same");

  TLegend *l33 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l33 -> SetNColumns(2);

  l33 -> AddEntry(angle_p1p2_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l33 -> AddEntry(angle_p1p2_CCNue_PID_300, "CC#nu_{e}", "f");
  l33 -> AddEntry(angle_p1p2_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l33 -> AddEntry(angle_p1p2_NC_PID_300, "NC", "f");
  l33 -> AddEntry(angle_p1p2_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l33 -> AddEntry(angle_p1p2_OOFV_PID_300, "OOFV", "f");
  l33 -> AddEntry(angle_p1p2_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l33 -> AddEntry(angle_p1p2_EXT_PID_300, "cosmic", "f");
  l33 -> AddEntry(angle_p1p2_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l33 -> AddEntry(angle_p1p2_OffBeam_PID, "off-beam data", "f");
  l33 -> AddEntry(angle_p1p2_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l33 -> AddEntry(angle_p1p2_OnBeam_PID, "on-beam data", "lep");
  l33 -> Draw();  
  
  TText *t33 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
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
  TH1F *h33 = (TH1F*)angle_p1p2_OnBeam_PID->Clone("h33");
  TH1 *last33 = (TH1*)angle_p1p2_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last33,angle_p1p2_OnBeam_PID, angle_p1p2_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h33->GetXaxis()->SetTitle("cos #theta_{p_{1} -p_{2}} ");
  h33->GetXaxis()->SetTitleSize(20);
  h33->GetXaxis()->SetTitleFont(43);
  h33->GetXaxis()->SetTitleOffset(3.);
  h33->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h33->GetXaxis()->SetLabelSize(15);

  c33->Update();
  c33->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/angle_p1p2_topo_PID_300.pdf");

  TCanvas *c34 = new TCanvas("c34", "c34", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selmuon_mom_res_PID_300->SetTitle("");

  selmuon_mom_res_PID_300->GetXaxis()->SetTitle("muon candidate truth momentum [GeV/c]");
  selmuon_mom_res_PID_300->GetYaxis()->SetTitle("muon candidate reconstructed momenta [GeV/c]");
  selmuon_mom_res_PID_300->Draw("colz");

  c34->Update();
  c34-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_mom_res_PID_300.pdf");

  TCanvas *c35 = new TCanvas("c35", "c35", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selmuon_costheta_res_PID_300->SetTitle("");

  selmuon_costheta_res_PID_300->GetXaxis()->SetTitle("muon candidate truth cos #theta");
  selmuon_costheta_res_PID_300->GetYaxis()->SetTitle("muon candidate reconstructed cos #theta");
  selmuon_costheta_res_PID_300->Draw("colz");

  c35->Update();
  c35-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_costheta_res_PID_300.pdf");

  TCanvas *c36 = new TCanvas("c36", "c36", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selmuon_phi_res_PID_300->SetTitle("");

  selmuon_phi_res_PID_300->GetXaxis()->SetTitle("muon candidate truth #phi");
  selmuon_phi_res_PID_300->GetYaxis()->SetTitle("muon candidate reconstructed #phi");
  selmuon_phi_res_PID_300->Draw("colz");

  c36->Update();
  c36-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selmuon_phi_res_PID_300.pdf");

  TCanvas *c37 = new TCanvas("c37", "c37", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selproton1_mom_res_PID_300->SetTitle("");

  selproton1_mom_res_PID_300->GetXaxis()->SetTitle("proton 1 candidate truth momentum [GeV/c]");
  selproton1_mom_res_PID_300->GetYaxis()->SetTitle("proton 1 candidate reconstructed momenta [GeV/c]");
  selproton1_mom_res_PID_300->Draw("colz");

  c37->Update();
  c37-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_mom_res_PID_300.pdf");

  TCanvas *c38 = new TCanvas("c38", "c38", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selproton1_costheta_res_PID_300->SetTitle("");

  selproton1_costheta_res_PID_300->GetXaxis()->SetTitle("proton 1 candidate truth cos #theta");
  selproton1_costheta_res_PID_300->GetYaxis()->SetTitle("proton 1 candidate reconstructed cos #theta");
  selproton1_costheta_res_PID_300->Draw("colz");

  c38->Update();
  c38-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_costheta_res_PID_300.pdf");

  TCanvas *c39 = new TCanvas("c39", "c39", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selproton1_phi_res_PID_300->SetTitle("");

  selproton1_phi_res_PID_300->GetXaxis()->SetTitle("proton 1 candidate truth #phi");
  selproton1_phi_res_PID_300->GetYaxis()->SetTitle("proton 1 candidate reconstructed #phi");
  selproton1_phi_res_PID_300->Draw("colz");

  c39->Update();
  c39-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton1_phi_res_PID_300.pdf");

  TCanvas *c40 = new TCanvas("c40", "c40", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selproton2_mom_res_PID_300->SetTitle("");

  selproton2_mom_res_PID_300->GetXaxis()->SetTitle("proton 2 candidate truth momentum [GeV/c]");
  selproton2_mom_res_PID_300->GetYaxis()->SetTitle("proton 2 candidate reconstructed momenta [GeV/c]");
  selproton2_mom_res_PID_300->Draw("colz");

  c40->Update();
  c40-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_mom_res_PID_300.pdf");

  TCanvas *c41 = new TCanvas("c41", "c41", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selproton2_costheta_res_PID_300->SetTitle("");

  selproton2_costheta_res_PID_300->GetXaxis()->SetTitle("proton 2 candidate truth cos #theta");
  selproton2_costheta_res_PID_300->GetYaxis()->SetTitle("proton 2 candidate reconstructed cos #theta");
  selproton2_costheta_res_PID_300->Draw("colz");

  c41->Update();
  c41-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_costheta_res_PID_300.pdf");

  TCanvas *c42 = new TCanvas("c42", "c42", 900, 900);
  gStyle->SetOptStat(kFALSE);
  selproton2_phi_res_PID_300->SetTitle("");

  selproton2_phi_res_PID_300->GetXaxis()->SetTitle("proton 2 candidate truth #phi");
  selproton2_phi_res_PID_300->GetYaxis()->SetTitle("proton 2 candidate reconstructed #phi");
  selproton2_phi_res_PID_300->Draw("colz");

  c42->Update();
  c42-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/selproton2_phi_res_PID_300.pdf");

  TCanvas *c43 = new TCanvas("c43", "c43", 900, 900);
  TPad *pad43 = new TPad("pad43", "pad43", 0, 0.3, 1, 1.0);
  pad43->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad43->Draw();             // Draw the upper pad: pad1
  pad43->cd();              // pad1 becomes the current pad

  cosangle_p1p2_CC0Pion0Proton_PID_300-> SetFillColor(kRed -10);
  cosangle_p1p2_CC0Pion1Proton_PID_300-> SetFillColor(kGreen-8);
  cosangle_p1p2_CC0Pion2Proton_PID_300-> SetFillColor(kAzure+4);
  cosangle_p1p2_CC0PionNProton_PID_300-> SetFillColor(kRed-9);
  cosangle_p1p2_CC1PionNProton_PID_300-> SetFillColor(kOrange);
  cosangle_p1p2_CCNPionNProton_PID_300-> SetFillColor(kCyan-8);
  cosangle_p1p2_CCNue_PID_300-> SetFillColor(31);
  cosangle_p1p2_NC_PID_300-> SetFillColor(kOrange+6);
  cosangle_p1p2_OOFV_PID_300-> SetFillColor(kYellow+2);
  cosangle_p1p2_EXT_PID_300-> SetFillColor(kBlack);
  cosangle_p1p2_OffBeam_PID-> SetFillColor(kGray);
  //DistFlstrk_other_PID_300-> SetFillColor(kRed);

  THStack *cosangle_p1p2_PID_300 = new THStack("cosangle_p1p2_PID_300","");
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_CC0Pion0Proton_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_CC0Pion1Proton_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_CC0Pion2Proton_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_CC0PionNProton_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_CC1PionNProton_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_CCNPionNProton_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_CCNue_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_NC_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_OOFV_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_EXT_PID_300);
  //cosangle_p1p2_PID_300-> Add(cosangle_p1p2_other_PID_300);
  cosangle_p1p2_PID_300-> Add(cosangle_p1p2_OffBeam_PID);
  cosangle_p1p2_PID_300->SetMaximum(50.);
  cosangle_p1p2_PID_300-> Draw();
  //  cosangle_p1p2_PID_300->GetXaxis()->SetTitle("cos#theta_{p_{1} -p_{2}} [rad]");
  cosangle_p1p2_PID_300->GetXaxis()->SetTitle("No. of Entries");

  cosangle_p1p2_OnBeam_PID->SetLineColor(kBlack);
  cosangle_p1p2_OnBeam_PID->SetMarkerStyle(20);
  cosangle_p1p2_OnBeam_PID->Draw("e1same");

  TLegend *l43 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l43 -> SetNColumns(2);
  l43 -> AddEntry(cosangle_p1p2_CC0Pion0Proton_PID_300, "CC0P0#pi", "f");
  l43 -> AddEntry(cosangle_p1p2_CCNue_PID_300, "CC#nu_{e}", "f");
  l43 -> AddEntry(cosangle_p1p2_CC0Pion1Proton_PID_300, "CC1P0#pi", "f");
  l43 -> AddEntry(cosangle_p1p2_NC_PID_300, "NC", "f");
  l43 -> AddEntry(cosangle_p1p2_CC0Pion2Proton_PID_300, "CC2P0#pi", "f");
  l43 -> AddEntry(cosangle_p1p2_OOFV_PID_300, "OOFV", "f");
  l43 -> AddEntry(cosangle_p1p2_CC0PionNProton_PID_300, "CCNP0#pi", "f");
  l43 -> AddEntry(cosangle_p1p2_EXT_PID_300, "cosmic", "f");
  l43 -> AddEntry(cosangle_p1p2_CC1PionNProton_PID_300, "CCNP1#pi", "f");
  l43 -> AddEntry(cosangle_p1p2_OffBeam_PID, "off-beam data", "f");
  l43 -> AddEntry(cosangle_p1p2_CCNPionNProton_PID_300, "CCNPN#pi", "f");
  l43 -> AddEntry(cosangle_p1p2_OnBeam_PID, "on-beam data", "lep");
  l43 -> Draw();  
  
  TText *t43 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE preliminary. 4.411e19 POT, stats only");
  t43->Draw();

  c43->cd();
  TPad *pad43_2 = new TPad("pad43_2", "pad43_2", 0, 0.05, 1, 0.3);
  pad43_2->SetTopMargin(0.01);
  pad43_2->SetBottomMargin(0.2);
  pad43_2->SetGridx();
  pad43_2->SetGridy();
  pad43_2->Draw();
  pad43_2->cd();
  // Define the ratio plot
  TH1F *h43 = (TH1F*)cosangle_p1p2_OnBeam_PID->Clone("h43");
  TH1 *last43 = (TH1*)cosangle_p1p2_PID_300->GetStack()->Last();

  chi2test = Chi2Calc(last43,cosangle_p1p2_OnBeam_PID, cosangle_p1p2_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileDataMC_PID_300<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h43->SetLineColor(kBlack);
  h43->Sumw2();
  h43->SetStats(0);      // No statistics on lower plot
  h43->Divide(last43);
  h43->SetMarkerStyle(21);
  h43->SetTitle("");
  h43->Draw("ep");       // Draw the ratio plot

  h43->GetYaxis()->SetTitle("Data/MC");
  h43->GetYaxis()->SetNdivisions(505);
  h43->GetYaxis()->SetTitleSize(20);
  h43->GetYaxis()->SetTitleFont(43);
  h43->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h43->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h43->GetXaxis()->SetTitle("cos#theta_{p_{1} -p_{2}}");
  h43->GetXaxis()->SetTitleSize(20);
  h43->GetXaxis()->SetTitleFont(43);
  h43->GetXaxis()->SetTitleOffset(3.);
  h43->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h43->GetXaxis()->SetLabelSize(15);

  c43->Update();
  c43->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300/cosangle_p1p2_topo_PID_300.pdf");

}
