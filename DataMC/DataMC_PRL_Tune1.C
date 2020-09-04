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

ofstream outfileDataMC_PID_300;
ofstream outfileChi2;

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
       //Chi2 +=pow((N_MC[ii]*norm_MC+N_EXTBNB[ii]*scale_offbeam-N_BNB[ii]),2)/(N_MC[ii]*norm_MC +N_EXTBNB[ii]*scale_offbeam);
       Chi2 +=pow((N_MC[ii]+N_EXTBNB[ii]-N_BNB[ii]),2)/(N_MC[ii] +N_EXTBNB[ii]);
       //std::cout<<"  chi2test : "<<Chi2<<std::endl;
       nbinsdata++;
     }
  }
  outfileChi2<<"  chi2test : "<<Chi2<<" ndof: "<<nbinsdata<<" chi2/ndof: "<<Chi2/nbinsdata<<std::endl;

  return Chi2/nbinsdata;
}

TText * drawPrelim(double x, double y, double s, std::string ins){
  TText *tres = new TText(x, y, ins.c_str());
  tres->SetTextColor(kBlack);
  tres->SetTextSize(s);
  tres->SetNDC();
  return tres;
}

void DataMC_PRL_Tune1(){ 
  
  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_Tune1_BNBMC_PRL.root","READ");
  TFile* OnBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OnBeam_PRL.root","READ");
  TFile* OffBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OffBeam_PRL.root","READ");
  
  TFile* BNBMCTune3 = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_Tune3_BNBMC_PRL.root","READ");
  
  std::cout<<"antes de Tfile"<<std::endl;
 
  outfileDataMC_PID_300.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/chi2_2P_DataMC_angles.txt");
  outfileChi2.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/Chi2DataMC_Tune1.txt");
  
  ////// BNB MC

 ///////// no cuts

 TH1D* selmuon_mom_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCQE_nocuts_Tune1");
 TH1D* selmuon_mom_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCRes_nocuts_Tune1");
 TH1D* selmuon_mom_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCCoh_nocuts_Tune1");
 TH1D* selmuon_mom_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCDIS_nocuts_Tune1");
 TH1D* selmuon_mom_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCMEC_nocuts_Tune1");
 TH1D* selmuon_mom_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCNue_nocuts_Tune1");
 TH1D* selmuon_mom_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_NC_nocuts_Tune1");
 TH1D* selmuon_mom_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_OOFV_nocuts_Tune1");
 TH1D* selmuon_mom_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_EXT_nocuts_Tune1");
 TH1D* selmuon_mom_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_other_nocuts_Tune1");

 TH1D* selmuon_contained_mom_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_CCQE_nocuts_Tune1");
 TH1D* selmuon_contained_mom_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_CCRes_nocuts_Tune1");
 TH1D* selmuon_contained_mom_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_CCCoh_nocuts_Tune1");
 TH1D* selmuon_contained_mom_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_CCDIS_nocuts_Tune1");
 TH1D* selmuon_contained_mom_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_CCMEC_nocuts_Tune1");
 TH1D* selmuon_contained_mom_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_CCNue_nocuts_Tune1");
 TH1D* selmuon_contained_mom_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_NC_nocuts_Tune1");
 TH1D* selmuon_contained_mom_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_OOFV_nocuts_Tune1");
 TH1D* selmuon_contained_mom_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_EXT_nocuts_Tune1");
 TH1D* selmuon_contained_mom_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_other_nocuts_Tune1");

 TH1D* selmuon_uncontained_mom_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_CCQE_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_CCRes_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_CCCoh_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_CCDIS_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_CCMEC_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_CCNue_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_NC_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_OOFV_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_EXT_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_other_nocuts_Tune1");

 TH1D* selmuon_costheta_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCQE_nocuts_Tune1");
 TH1D* selmuon_costheta_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCRes_nocuts_Tune1");
 TH1D* selmuon_costheta_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCCoh_nocuts_Tune1");
 TH1D* selmuon_costheta_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCDIS_nocuts_Tune1");
 TH1D* selmuon_costheta_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCMEC_nocuts_Tune1");
 TH1D* selmuon_costheta_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCNue_nocuts_Tune1");
 TH1D* selmuon_costheta_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_NC_nocuts_Tune1");
 TH1D* selmuon_costheta_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_OOFV_nocuts_Tune1");
 TH1D* selmuon_costheta_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_EXT_nocuts_Tune1");
 TH1D* selmuon_costheta_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_other_nocuts_Tune1");

 TH1D* selmuon_phi_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCQE_nocuts_Tune1");
 TH1D* selmuon_phi_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCRes_nocuts_Tune1");
 TH1D* selmuon_phi_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCCoh_nocuts_Tune1");
 TH1D* selmuon_phi_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCDIS_nocuts_Tune1");
 TH1D* selmuon_phi_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCMEC_nocuts_Tune1");
 TH1D* selmuon_phi_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCNue_nocuts_Tune1");
 TH1D* selmuon_phi_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_NC_nocuts_Tune1");
 TH1D* selmuon_phi_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_OOFV_nocuts_Tune1");
 TH1D* selmuon_phi_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_EXT_nocuts_Tune1");
 TH1D* selmuon_phi_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_other_nocuts_Tune1");

 TH1D* selmuon_mom_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_muon_nocuts_Tune1");
 TH1D* selmuon_mom_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_proton_nocuts_Tune1");
 TH1D* selmuon_mom_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_pion_nocuts_Tune1");
 TH1D* selmuon_mom_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_electron_nocuts_Tune1");
 TH1D* selmuon_mom_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_pother_nocuts_Tune1");

 TH1D* selmuon_contained_mom_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_muon_nocuts_Tune1");
 TH1D* selmuon_contained_mom_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_proton_nocuts_Tune1");
 TH1D* selmuon_contained_mom_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_pion_nocuts_Tune1");
 TH1D* selmuon_contained_mom_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_electron_nocuts_Tune1");
 TH1D* selmuon_contained_mom_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_contained_mom_pother_nocuts_Tune1");

 TH1D* selmuon_uncontained_mom_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_muon_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_proton_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_pion_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_electron_nocuts_Tune1");
 TH1D* selmuon_uncontained_mom_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_uncontained_mom_pother_nocuts_Tune1");
 
 TH1D* selmuon_costheta_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_muon_nocuts_Tune1");
 TH1D* selmuon_costheta_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_proton_nocuts_Tune1");
 TH1D* selmuon_costheta_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_pion_nocuts_Tune1");
 TH1D* selmuon_costheta_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_electron_nocuts_Tune1");
 TH1D* selmuon_costheta_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_pother_nocuts_Tune1");

 TH1D* selmuon_phi_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_muon_nocuts_Tune1");
 TH1D* selmuon_phi_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_proton_nocuts_Tune1");
 TH1D* selmuon_phi_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_pion_nocuts_Tune1");
 TH1D* selmuon_phi_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_electron_nocuts_Tune1");
 TH1D* selmuon_phi_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_pother_nocuts_Tune1");

 TH1D* selproton1_mom_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCQE_nocuts_Tune1");
 TH1D* selproton1_mom_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCRes_nocuts_Tune1");
 TH1D* selproton1_mom_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCCoh_nocuts_Tune1");
 TH1D* selproton1_mom_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCDIS_nocuts_Tune1");
 TH1D* selproton1_mom_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCMEC_nocuts_Tune1");
 TH1D* selproton1_mom_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCNue_nocuts_Tune1");
 TH1D* selproton1_mom_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_NC_nocuts_Tune1");
 TH1D* selproton1_mom_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_OOFV_nocuts_Tune1");
 TH1D* selproton1_mom_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_EXT_nocuts_Tune1");
 TH1D* selproton1_mom_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_other_nocuts_Tune1");

 TH1D* selproton1_costheta_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCQE_nocuts_Tune1");
 TH1D* selproton1_costheta_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCRes_nocuts_Tune1");
 TH1D* selproton1_costheta_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCCoh_nocuts_Tune1");
 TH1D* selproton1_costheta_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCDIS_nocuts_Tune1");
 TH1D* selproton1_costheta_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCMEC_nocuts_Tune1");
 TH1D* selproton1_costheta_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCNue_nocuts_Tune1");
 TH1D* selproton1_costheta_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_NC_nocuts_Tune1");
 TH1D* selproton1_costheta_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_OOFV_nocuts_Tune1");
 TH1D* selproton1_costheta_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_EXT_nocuts_Tune1");
 TH1D* selproton1_costheta_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_other_nocuts_Tune1");

 TH1D* selproton1_phi_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCQE_nocuts_Tune1");
 TH1D* selproton1_phi_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCRes_nocuts_Tune1");
 TH1D* selproton1_phi_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCCoh_nocuts_Tune1");
 TH1D* selproton1_phi_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCDIS_nocuts_Tune1");
 TH1D* selproton1_phi_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCMEC_nocuts_Tune1");
 TH1D* selproton1_phi_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCNue_nocuts_Tune1");
 TH1D* selproton1_phi_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_NC_nocuts_Tune1");
 TH1D* selproton1_phi_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_OOFV_nocuts_Tune1");
 TH1D* selproton1_phi_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_EXT_nocuts_Tune1");
 TH1D* selproton1_phi_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_other_nocuts_Tune1");

 TH1D* selproton1_mom_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_muon_nocuts_Tune1");
 TH1D* selproton1_mom_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_proton_nocuts_Tune1");
 TH1D* selproton1_mom_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_pion_nocuts_Tune1");
 TH1D* selproton1_mom_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_electron_nocuts_Tune1");
 TH1D* selproton1_mom_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_pother_nocuts_Tune1");

 TH1D* selproton1_costheta_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_muon_nocuts_Tune1");
 TH1D* selproton1_costheta_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_proton_nocuts_Tune1");
 TH1D* selproton1_costheta_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_pion_nocuts_Tune1");
 TH1D* selproton1_costheta_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_electron_nocuts_Tune1");
 TH1D* selproton1_costheta_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_pother_nocuts_Tune1");

 TH1D* selproton1_phi_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_muon_nocuts_Tune1");
 TH1D* selproton1_phi_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_proton_nocuts_Tune1");
 TH1D* selproton1_phi_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_pion_nocuts_Tune1");
 TH1D* selproton1_phi_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_electron_nocuts_Tune1");
 TH1D* selproton1_phi_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_pother_nocuts_Tune1");

 TH1D* selproton2_mom_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCQE_nocuts_Tune1");
 TH1D* selproton2_mom_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCRes_nocuts_Tune1");
 TH1D* selproton2_mom_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCCoh_nocuts_Tune1");
 TH1D* selproton2_mom_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCDIS_nocuts_Tune1");
 TH1D* selproton2_mom_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCMEC_nocuts_Tune1");
 TH1D* selproton2_mom_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCNue_nocuts_Tune1");
 TH1D* selproton2_mom_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_NC_nocuts_Tune1");
 TH1D* selproton2_mom_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_OOFV_nocuts_Tune1");
 TH1D* selproton2_mom_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_EXT_nocuts_Tune1");
 TH1D* selproton2_mom_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_other_nocuts_Tune1");

 TH1D* selproton2_costheta_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCQE_nocuts_Tune1");
 TH1D* selproton2_costheta_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCRes_nocuts_Tune1");
 TH1D* selproton2_costheta_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCCoh_nocuts_Tune1");
 TH1D* selproton2_costheta_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCDIS_nocuts_Tune1");
 TH1D* selproton2_costheta_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCMEC_nocuts_Tune1");
 TH1D* selproton2_costheta_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCNue_nocuts_Tune1");
 TH1D* selproton2_costheta_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_NC_nocuts_Tune1");
 TH1D* selproton2_costheta_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_OOFV_nocuts_Tune1");
 TH1D* selproton2_costheta_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_EXT_nocuts_Tune1");
 TH1D* selproton2_costheta_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_other_nocuts_Tune1");

 TH1D* selproton2_phi_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCQE_nocuts_Tune1");
 TH1D* selproton2_phi_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCRes_nocuts_Tune1");
 TH1D* selproton2_phi_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCCoh_nocuts_Tune1");
 TH1D* selproton2_phi_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCDIS_nocuts_Tune1");
 TH1D* selproton2_phi_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCMEC_nocuts_Tune1");
 TH1D* selproton2_phi_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCNue_nocuts_Tune1");
 TH1D* selproton2_phi_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_NC_nocuts_Tune1");
 TH1D* selproton2_phi_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_OOFV_nocuts_Tune1");
 TH1D* selproton2_phi_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_EXT_nocuts_Tune1");
 TH1D* selproton2_phi_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_other_nocuts_Tune1");

 TH1D* selproton2_mom_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_muon_nocuts_Tune1");
 TH1D* selproton2_mom_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_proton_nocuts_Tune1");
 TH1D* selproton2_mom_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_pion_nocuts_Tune1");
 TH1D* selproton2_mom_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_electron_nocuts_Tune1");
 TH1D* selproton2_mom_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_pother_nocuts_Tune1");

 TH1D* selproton2_costheta_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_muon_nocuts_Tune1");
 TH1D* selproton2_costheta_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_proton_nocuts_Tune1");
 TH1D* selproton2_costheta_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_pion_nocuts_Tune1");
 TH1D* selproton2_costheta_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_electron_nocuts_Tune1");
 TH1D* selproton2_costheta_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_pother_nocuts_Tune1");

 TH1D* selproton2_phi_muon_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_muon_nocuts_Tune1");
 TH1D* selproton2_phi_proton_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_proton_nocuts_Tune1");
 TH1D* selproton2_phi_pion_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_pion_nocuts_Tune1");
 TH1D* selproton2_phi_electron_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_electron_nocuts_Tune1");
 TH1D* selproton2_phi_pother_nocuts_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_pother_nocuts_Tune1");

 TH1D* anglemup1_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_CCQE_nocuts_Tune1");
 TH1D* anglemup1_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_CCRes_nocuts_Tune1");
 TH1D* anglemup1_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_CCCoh_nocuts_Tune1");
 TH1D* anglemup1_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_CCDIS_nocuts_Tune1");
 TH1D* anglemup1_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_CCMEC_nocuts_Tune1");
 TH1D* anglemup1_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_CCNue_nocuts_Tune1");
 TH1D* anglemup1_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_NC_nocuts_Tune1");
 TH1D* anglemup1_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_OOFV_nocuts_Tune1");
 TH1D* anglemup1_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_EXT_nocuts_Tune1");
 TH1D* anglemup1_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup1_other_nocuts_Tune1");

 TH1D* anglemup2_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_CCQE_nocuts_Tune1");
 TH1D* anglemup2_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_CCRes_nocuts_Tune1");
 TH1D* anglemup2_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_CCCoh_nocuts_Tune1");
 TH1D* anglemup2_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_CCDIS_nocuts_Tune1");
 TH1D* anglemup2_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_CCMEC_nocuts_Tune1");
 TH1D* anglemup2_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_CCNue_nocuts_Tune1");
 TH1D* anglemup2_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_NC_nocuts_Tune1");
 TH1D* anglemup2_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_OOFV_nocuts_Tune1");
 TH1D* anglemup2_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_EXT_nocuts_Tune1");
 TH1D* anglemup2_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglemup2_other_nocuts_Tune1");

 TH1D* anglep1p2LF_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_CCQE_nocuts_Tune1");
 TH1D* anglep1p2LF_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_CCRes_nocuts_Tune1");
 TH1D* anglep1p2LF_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_CCCoh_nocuts_Tune1");
 TH1D* anglep1p2LF_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_CCDIS_nocuts_Tune1");
 TH1D* anglep1p2LF_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_CCMEC_nocuts_Tune1");
 TH1D* anglep1p2LF_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_CCNue_nocuts_Tune1");
 TH1D* anglep1p2LF_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_NC_nocuts_Tune1");
 TH1D* anglep1p2LF_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_OOFV_nocuts_Tune1");
 TH1D* anglep1p2LF_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_EXT_nocuts_Tune1");
 TH1D* anglep1p2LF_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2LF_other_nocuts_Tune1");

 TH1D* reco_Enu_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCQE_nocuts_Tune1");
 TH1D* reco_Enu_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCRes_nocuts_Tune1");
 TH1D* reco_Enu_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCCoh_nocuts_Tune1");
 TH1D* reco_Enu_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCDIS_nocuts_Tune1");
 TH1D* reco_Enu_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCMEC_nocuts_Tune1");
 TH1D* reco_Enu_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCNue_nocuts_Tune1");
 TH1D* reco_Enu_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_NC_nocuts_Tune1");
 TH1D* reco_Enu_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_OOFV_nocuts_Tune1");
 TH1D* reco_Enu_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_EXT_nocuts_Tune1");
 TH1D* reco_Enu_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_other_nocuts_Tune1");
 
 TH1D* reco_PT_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCQE_nocuts_Tune1");
 TH1D* reco_PT_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCRes_nocuts_Tune1");
 TH1D* reco_PT_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCCoh_nocuts_Tune1");
 TH1D* reco_PT_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCDIS_nocuts_Tune1");
 TH1D* reco_PT_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCMEC_nocuts_Tune1");
 TH1D* reco_PT_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCNue_nocuts_Tune1");
 TH1D* reco_PT_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_NC_nocuts_Tune1");
 TH1D* reco_PT_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_OOFV_nocuts_Tune1");
 TH1D* reco_PT_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_EXT_nocuts_Tune1");
 TH1D* reco_PT_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_PT_other_nocuts_Tune1");
 
 TH1D* reco_pn_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCQE_nocuts_Tune1");
 TH1D* reco_pn_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCRes_nocuts_Tune1");
 TH1D* reco_pn_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCCoh_nocuts_Tune1");
 TH1D* reco_pn_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCDIS_nocuts_Tune1");
 TH1D* reco_pn_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCMEC_nocuts_Tune1");
 TH1D* reco_pn_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCNue_nocuts_Tune1");
 TH1D* reco_pn_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_NC_nocuts_Tune1");
 TH1D* reco_pn_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_OOFV_nocuts_Tune1");
 TH1D* reco_pn_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_EXT_nocuts_Tune1");
 TH1D* reco_pn_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_pn_other_nocuts_Tune1");

 TH1D* reco_totpnp2_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCQE_nocuts_Tune1");
 TH1D* reco_totpnp2_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCRes_nocuts_Tune1");
 TH1D* reco_totpnp2_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCCoh_nocuts_Tune1");
 TH1D* reco_totpnp2_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCDIS_nocuts_Tune1");
 TH1D* reco_totpnp2_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCMEC_nocuts_Tune1");
 TH1D* reco_totpnp2_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCNue_nocuts_Tune1");
 TH1D* reco_totpnp2_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_NC_nocuts_Tune1");
 TH1D* reco_totpnp2_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_OOFV_nocuts_Tune1");
 TH1D* reco_totpnp2_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_EXT_nocuts_Tune1");
 TH1D* reco_totpnp2_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_other_nocuts_Tune1");

 TH1D* reco_relpnp2_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCQE_nocuts_Tune1");
 TH1D* reco_relpnp2_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCRes_nocuts_Tune1");
 TH1D* reco_relpnp2_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCCoh_nocuts_Tune1");
 TH1D* reco_relpnp2_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCDIS_nocuts_Tune1");
 TH1D* reco_relpnp2_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCMEC_nocuts_Tune1");
 TH1D* reco_relpnp2_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCNue_nocuts_Tune1");
 TH1D* reco_relpnp2_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_NC_nocuts_Tune1");
 TH1D* reco_relpnp2_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_OOFV_nocuts_Tune1");
 TH1D* reco_relpnp2_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_EXT_nocuts_Tune1");
 TH1D* reco_relpnp2_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_other_nocuts_Tune1");

 TH1D* anglep1p2CM_CCQE_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCQE_nocuts_Tune1");
 TH1D* anglep1p2CM_CCRes_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCRes_nocuts_Tune1");
 TH1D* anglep1p2CM_CCCoh_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCCoh_nocuts_Tune1");
 TH1D* anglep1p2CM_CCDIS_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCDIS_nocuts_Tune1");
 TH1D* anglep1p2CM_CCMEC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCMEC_nocuts_Tune1");
 TH1D* anglep1p2CM_CCNue_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCNue_nocuts_Tune1");
 TH1D* anglep1p2CM_NC_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_NC_nocuts_Tune1");
 TH1D* anglep1p2CM_OOFV_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_OOFV_nocuts_Tune1");
 TH1D* anglep1p2CM_EXT_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_EXT_nocuts_Tune1");
 TH1D* anglep1p2CM_other_nocuts_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_other_nocuts_Tune1");

 ////// no hammer///////////////////////

 TH1D* selmuon_mom_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCQE_nobtb_Tune1");
 TH1D* selmuon_mom_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCRes_nobtb_Tune1");
 TH1D* selmuon_mom_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCCoh_nobtb_Tune1");
 TH1D* selmuon_mom_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCDIS_nobtb_Tune1");
 TH1D* selmuon_mom_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCMEC_nobtb_Tune1");
 TH1D* selmuon_mom_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCNue_nobtb_Tune1");
 TH1D* selmuon_mom_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_NC_nobtb_Tune1");
 TH1D* selmuon_mom_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_OOFV_nobtb_Tune1");
 TH1D* selmuon_mom_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_EXT_nobtb_Tune1");
 TH1D* selmuon_mom_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_other_nobtb_Tune1");

 TH1D* selmuon_costheta_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCQE_nobtb_Tune1");
 TH1D* selmuon_costheta_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCRes_nobtb_Tune1");
 TH1D* selmuon_costheta_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCCoh_nobtb_Tune1");
 TH1D* selmuon_costheta_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCDIS_nobtb_Tune1");
 TH1D* selmuon_costheta_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCMEC_nobtb_Tune1");
 TH1D* selmuon_costheta_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCNue_nobtb_Tune1");
 TH1D* selmuon_costheta_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_NC_nobtb_Tune1");
 TH1D* selmuon_costheta_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_OOFV_nobtb_Tune1");
 TH1D* selmuon_costheta_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_EXT_nobtb_Tune1");
 TH1D* selmuon_costheta_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_other_nobtb_Tune1");

 TH1D* selmuon_phi_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCQE_nobtb_Tune1");
 TH1D* selmuon_phi_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCRes_nobtb_Tune1");
 TH1D* selmuon_phi_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCCoh_nobtb_Tune1");
 TH1D* selmuon_phi_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCDIS_nobtb_Tune1");
 TH1D* selmuon_phi_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCMEC_nobtb_Tune1");
 TH1D* selmuon_phi_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCNue_nobtb_Tune1");
 TH1D* selmuon_phi_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_NC_nobtb_Tune1");
 TH1D* selmuon_phi_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_OOFV_nobtb_Tune1");
 TH1D* selmuon_phi_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_EXT_nobtb_Tune1");
 TH1D* selmuon_phi_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_other_nobtb_Tune1");

 TH1D* selproton1_mom_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCQE_nobtb_Tune1");
 TH1D* selproton1_mom_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCRes_nobtb_Tune1");
 TH1D* selproton1_mom_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCCoh_nobtb_Tune1");
 TH1D* selproton1_mom_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCDIS_nobtb_Tune1");
 TH1D* selproton1_mom_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCMEC_nobtb_Tune1");
 TH1D* selproton1_mom_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCNue_nobtb_Tune1");
 TH1D* selproton1_mom_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_NC_nobtb_Tune1");
 TH1D* selproton1_mom_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_OOFV_nobtb_Tune1");
 TH1D* selproton1_mom_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_EXT_nobtb_Tune1");
 TH1D* selproton1_mom_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_other_nobtb_Tune1");

 TH1D* selproton1_costheta_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCQE_nobtb_Tune1");
 TH1D* selproton1_costheta_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCRes_nobtb_Tune1");
 TH1D* selproton1_costheta_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCCoh_nobtb_Tune1");
 TH1D* selproton1_costheta_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCDIS_nobtb_Tune1");
 TH1D* selproton1_costheta_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCMEC_nobtb_Tune1");
 TH1D* selproton1_costheta_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCNue_nobtb_Tune1");
 TH1D* selproton1_costheta_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_NC_nobtb_Tune1");
 TH1D* selproton1_costheta_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_OOFV_nobtb_Tune1");
 TH1D* selproton1_costheta_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_EXT_nobtb_Tune1");
 TH1D* selproton1_costheta_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_other_nobtb_Tune1");

 TH1D* selproton1_phi_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCQE_nobtb_Tune1");
 TH1D* selproton1_phi_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCRes_nobtb_Tune1");
 TH1D* selproton1_phi_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCCoh_nobtb_Tune1");
 TH1D* selproton1_phi_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCDIS_nobtb_Tune1");
 TH1D* selproton1_phi_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCMEC_nobtb_Tune1");
 TH1D* selproton1_phi_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCNue_nobtb_Tune1");
 TH1D* selproton1_phi_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_NC_nobtb_Tune1");
 TH1D* selproton1_phi_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_OOFV_nobtb_Tune1");
 TH1D* selproton1_phi_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_EXT_nobtb_Tune1");
 TH1D* selproton1_phi_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_other_nobtb_Tune1");

 TH1D* selproton2_mom_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCQE_nobtb_Tune1");
 TH1D* selproton2_mom_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCRes_nobtb_Tune1");
 TH1D* selproton2_mom_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCCoh_nobtb_Tune1");
 TH1D* selproton2_mom_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCDIS_nobtb_Tune1");
 TH1D* selproton2_mom_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCMEC_nobtb_Tune1");
 TH1D* selproton2_mom_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCNue_nobtb_Tune1");
 TH1D* selproton2_mom_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_NC_nobtb_Tune1");
 TH1D* selproton2_mom_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_OOFV_nobtb_Tune1");
 TH1D* selproton2_mom_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_EXT_nobtb_Tune1");
 TH1D* selproton2_mom_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_other_nobtb_Tune1");

 TH1D* selproton2_costheta_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCQE_nobtb_Tune1");
 TH1D* selproton2_costheta_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCRes_nobtb_Tune1");
 TH1D* selproton2_costheta_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCCoh_nobtb_Tune1");
 TH1D* selproton2_costheta_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCDIS_nobtb_Tune1");
 TH1D* selproton2_costheta_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCMEC_nobtb_Tune1");
 TH1D* selproton2_costheta_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCNue_nobtb_Tune1");
 TH1D* selproton2_costheta_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_NC_nobtb_Tune1");
 TH1D* selproton2_costheta_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_OOFV_nobtb_Tune1");
 TH1D* selproton2_costheta_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_EXT_nobtb_Tune1");
 TH1D* selproton2_costheta_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_other_nobtb_Tune1");

 TH1D* selproton2_phi_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCQE_nobtb_Tune1");
 TH1D* selproton2_phi_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCRes_nobtb_Tune1");
 TH1D* selproton2_phi_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCCoh_nobtb_Tune1");
 TH1D* selproton2_phi_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCDIS_nobtb_Tune1");
 TH1D* selproton2_phi_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCMEC_nobtb_Tune1");
 TH1D* selproton2_phi_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCNue_nobtb_Tune1");
 TH1D* selproton2_phi_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_NC_nobtb_Tune1");
 TH1D* selproton2_phi_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_OOFV_nobtb_Tune1");
 TH1D* selproton2_phi_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_EXT_nobtb_Tune1");
 TH1D* selproton2_phi_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_other_nobtb_Tune1");

 TH1D* reco_Enu_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCQE_nobtb_Tune1");
 TH1D* reco_Enu_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCRes_nobtb_Tune1");
 TH1D* reco_Enu_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCCoh_nobtb_Tune1");
 TH1D* reco_Enu_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCDIS_nobtb_Tune1");
 TH1D* reco_Enu_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCMEC_nobtb_Tune1");
 TH1D* reco_Enu_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCNue_nobtb_Tune1");
 TH1D* reco_Enu_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_NC_nobtb_Tune1");
 TH1D* reco_Enu_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_OOFV_nobtb_Tune1");
 TH1D* reco_Enu_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_EXT_nobtb_Tune1");
 TH1D* reco_Enu_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_other_nobtb_Tune1");
 
 TH1D* reco_PT_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCQE_nobtb_Tune1");
 TH1D* reco_PT_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCRes_nobtb_Tune1");
 TH1D* reco_PT_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCCoh_nobtb_Tune1");
 TH1D* reco_PT_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCDIS_nobtb_Tune1");
 TH1D* reco_PT_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCMEC_nobtb_Tune1");
 TH1D* reco_PT_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_CCNue_nobtb_Tune1");
 TH1D* reco_PT_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_NC_nobtb_Tune1");
 TH1D* reco_PT_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_OOFV_nobtb_Tune1");
 TH1D* reco_PT_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_EXT_nobtb_Tune1");
 TH1D* reco_PT_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_PT_other_nobtb_Tune1");
 
 TH1D* reco_pn_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCQE_nobtb_Tune1");
 TH1D* reco_pn_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCRes_nobtb_Tune1");
 TH1D* reco_pn_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCCoh_nobtb_Tune1");
 TH1D* reco_pn_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCDIS_nobtb_Tune1");
 TH1D* reco_pn_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCMEC_nobtb_Tune1");
 TH1D* reco_pn_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCNue_nobtb_Tune1");
 TH1D* reco_pn_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_NC_nobtb_Tune1");
 TH1D* reco_pn_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_OOFV_nobtb_Tune1");
 TH1D* reco_pn_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_EXT_nobtb_Tune1");
 TH1D* reco_pn_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_pn_other_nobtb_Tune1");

 TH1D* reco_totpnp2_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCQE_nobtb_Tune1");
 TH1D* reco_totpnp2_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCRes_nobtb_Tune1");
 TH1D* reco_totpnp2_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCCoh_nobtb_Tune1");
 TH1D* reco_totpnp2_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCDIS_nobtb_Tune1");
 TH1D* reco_totpnp2_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCMEC_nobtb_Tune1");
 TH1D* reco_totpnp2_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCNue_nobtb_Tune1");
 TH1D* reco_totpnp2_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_NC_nobtb_Tune1");
 TH1D* reco_totpnp2_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_OOFV_nobtb_Tune1");
 TH1D* reco_totpnp2_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_EXT_nobtb_Tune1");
 TH1D* reco_totpnp2_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_other_nobtb_Tune1");

 TH1D* reco_relpnp2_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCQE_nobtb_Tune1");
 TH1D* reco_relpnp2_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCRes_nobtb_Tune1");
 TH1D* reco_relpnp2_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCCoh_nobtb_Tune1");
 TH1D* reco_relpnp2_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCDIS_nobtb_Tune1");
 TH1D* reco_relpnp2_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCMEC_nobtb_Tune1");
 TH1D* reco_relpnp2_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCNue_nobtb_Tune1");
 TH1D* reco_relpnp2_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_NC_nobtb_Tune1");
 TH1D* reco_relpnp2_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_OOFV_nobtb_Tune1");
 TH1D* reco_relpnp2_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_EXT_nobtb_Tune1");
 TH1D* reco_relpnp2_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_other_nobtb_Tune1");

 TH1D* anglep1p2CM_CCQE_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCQE_nobtb_Tune1");
 TH1D* anglep1p2CM_CCRes_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCRes_nobtb_Tune1");
 TH1D* anglep1p2CM_CCCoh_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCCoh_nobtb_Tune1");
 TH1D* anglep1p2CM_CCDIS_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCDIS_nobtb_Tune1");
 TH1D* anglep1p2CM_CCMEC_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCMEC_nobtb_Tune1");
 TH1D* anglep1p2CM_CCNue_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCNue_nobtb_Tune1");
 TH1D* anglep1p2CM_NC_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_NC_nobtb_Tune1");
 TH1D* anglep1p2CM_OOFV_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_OOFV_nobtb_Tune1");
 TH1D* anglep1p2CM_EXT_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_EXT_nobtb_Tune1");
 TH1D* anglep1p2CM_other_nobtb_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_other_nobtb_Tune1");


 ///// no hammer, low PT

 TH1D* selmuon_mom_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCQE_nobtblowPT_Tune1");
 TH1D* selmuon_mom_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCRes_nobtblowPT_Tune1");
 TH1D* selmuon_mom_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCCoh_nobtblowPT_Tune1");
 TH1D* selmuon_mom_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCDIS_nobtblowPT_Tune1");
 TH1D* selmuon_mom_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCMEC_nobtblowPT_Tune1");
 TH1D* selmuon_mom_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_CCNue_nobtblowPT_Tune1");
 TH1D* selmuon_mom_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_NC_nobtblowPT_Tune1");
 TH1D* selmuon_mom_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_OOFV_nobtblowPT_Tune1");
 TH1D* selmuon_mom_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_EXT_nobtblowPT_Tune1");
 TH1D* selmuon_mom_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_mom_other_nobtblowPT_Tune1");

 TH1D* selmuon_costheta_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCQE_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCRes_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCCoh_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCDIS_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCMEC_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_CCNue_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_NC_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_OOFV_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_EXT_nobtblowPT_Tune1");
 TH1D* selmuon_costheta_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_costheta_other_nobtblowPT_Tune1");

 TH1D* selmuon_phi_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCQE_nobtblowPT_Tune1");
 TH1D* selmuon_phi_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCRes_nobtblowPT_Tune1");
 TH1D* selmuon_phi_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCCoh_nobtblowPT_Tune1");
 TH1D* selmuon_phi_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCDIS_nobtblowPT_Tune1");
 TH1D* selmuon_phi_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCMEC_nobtblowPT_Tune1");
 TH1D* selmuon_phi_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_CCNue_nobtblowPT_Tune1");
 TH1D* selmuon_phi_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_NC_nobtblowPT_Tune1");
 TH1D* selmuon_phi_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_OOFV_nobtblowPT_Tune1");
 TH1D* selmuon_phi_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_EXT_nobtblowPT_Tune1");
 TH1D* selmuon_phi_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selmuon_phi_other_nobtblowPT_Tune1");

 TH1D* selproton1_mom_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCQE_nobtblowPT_Tune1");
 TH1D* selproton1_mom_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCRes_nobtblowPT_Tune1");
 TH1D* selproton1_mom_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCCoh_nobtblowPT_Tune1");
 TH1D* selproton1_mom_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCDIS_nobtblowPT_Tune1");
 TH1D* selproton1_mom_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCMEC_nobtblowPT_Tune1");
 TH1D* selproton1_mom_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_CCNue_nobtblowPT_Tune1");
 TH1D* selproton1_mom_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_NC_nobtblowPT_Tune1");
 TH1D* selproton1_mom_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_OOFV_nobtblowPT_Tune1");
 TH1D* selproton1_mom_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_EXT_nobtblowPT_Tune1");
 TH1D* selproton1_mom_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_mom_other_nobtblowPT_Tune1");

 TH1D* selproton1_costheta_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCQE_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCRes_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCCoh_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCDIS_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCMEC_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_CCNue_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_NC_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_OOFV_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_EXT_nobtblowPT_Tune1");
 TH1D* selproton1_costheta_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_costheta_other_nobtblowPT_Tune1");

 TH1D* selproton1_phi_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCQE_nobtblowPT_Tune1");
 TH1D* selproton1_phi_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCRes_nobtblowPT_Tune1");
 TH1D* selproton1_phi_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCCoh_nobtblowPT_Tune1");
 TH1D* selproton1_phi_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCDIS_nobtblowPT_Tune1");
 TH1D* selproton1_phi_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCMEC_nobtblowPT_Tune1");
 TH1D* selproton1_phi_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_CCNue_nobtblowPT_Tune1");
 TH1D* selproton1_phi_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_NC_nobtblowPT_Tune1");
 TH1D* selproton1_phi_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_OOFV_nobtblowPT_Tune1");
 TH1D* selproton1_phi_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_EXT_nobtblowPT_Tune1");
 TH1D* selproton1_phi_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton1_phi_other_nobtblowPT_Tune1");

 TH1D* selproton2_mom_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCQE_nobtblowPT_Tune1");
 TH1D* selproton2_mom_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCRes_nobtblowPT_Tune1");
 TH1D* selproton2_mom_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCCoh_nobtblowPT_Tune1");
 TH1D* selproton2_mom_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCDIS_nobtblowPT_Tune1");
 TH1D* selproton2_mom_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCMEC_nobtblowPT_Tune1");
 TH1D* selproton2_mom_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_CCNue_nobtblowPT_Tune1");
 TH1D* selproton2_mom_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_NC_nobtblowPT_Tune1");
 TH1D* selproton2_mom_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_OOFV_nobtblowPT_Tune1");
 TH1D* selproton2_mom_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_EXT_nobtblowPT_Tune1");
 TH1D* selproton2_mom_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_mom_other_nobtblowPT_Tune1");

 TH1D* selproton2_costheta_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCQE_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCRes_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCCoh_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCDIS_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCMEC_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_CCNue_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_NC_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_OOFV_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_EXT_nobtblowPT_Tune1");
 TH1D* selproton2_costheta_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_costheta_other_nobtblowPT_Tune1");

 TH1D* selproton2_phi_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCQE_nobtblowPT_Tune1");
 TH1D* selproton2_phi_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCRes_nobtblowPT_Tune1");
 TH1D* selproton2_phi_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCCoh_nobtblowPT_Tune1");
 TH1D* selproton2_phi_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCDIS_nobtblowPT_Tune1");
 TH1D* selproton2_phi_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCMEC_nobtblowPT_Tune1");
 TH1D* selproton2_phi_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_CCNue_nobtblowPT_Tune1");
 TH1D* selproton2_phi_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_NC_nobtblowPT_Tune1");
 TH1D* selproton2_phi_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_OOFV_nobtblowPT_Tune1");
 TH1D* selproton2_phi_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_EXT_nobtblowPT_Tune1");
 TH1D* selproton2_phi_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("selproton2_phi_other_nobtblowPT_Tune1");

 TH1D* reco_Enu_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCQE_nobtblowPT_Tune1");
 TH1D* reco_Enu_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCRes_nobtblowPT_Tune1");
 TH1D* reco_Enu_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCCoh_nobtblowPT_Tune1");
 TH1D* reco_Enu_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCDIS_nobtblowPT_Tune1");
 TH1D* reco_Enu_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCMEC_nobtblowPT_Tune1");
 TH1D* reco_Enu_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_CCNue_nobtblowPT_Tune1");
 TH1D* reco_Enu_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_NC_nobtblowPT_Tune1");
 TH1D* reco_Enu_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_OOFV_nobtblowPT_Tune1");
 TH1D* reco_Enu_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_EXT_nobtblowPT_Tune1");
 TH1D* reco_Enu_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_Enu_other_nobtblowPT_Tune1");
  
 TH1D* reco_pn_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCQE_nobtblowPT_Tune1");
 TH1D* reco_pn_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCRes_nobtblowPT_Tune1");
 TH1D* reco_pn_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCCoh_nobtblowPT_Tune1");
 TH1D* reco_pn_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCDIS_nobtblowPT_Tune1");
 TH1D* reco_pn_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCMEC_nobtblowPT_Tune1");
 TH1D* reco_pn_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_CCNue_nobtblowPT_Tune1");
 TH1D* reco_pn_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_NC_nobtblowPT_Tune1");
 TH1D* reco_pn_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_OOFV_nobtblowPT_Tune1");
 TH1D* reco_pn_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_EXT_nobtblowPT_Tune1");
 TH1D* reco_pn_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_pn_other_nobtblowPT_Tune1");

 TH1D* reco_totpnp2_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCQE_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCRes_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCCoh_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCDIS_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCMEC_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_CCNue_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_NC_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_OOFV_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_EXT_nobtblowPT_Tune1");
 TH1D* reco_totpnp2_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_totpnp2_other_nobtblowPT_Tune1");

 TH1D* reco_relpnp2_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCQE_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCRes_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCCoh_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCDIS_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCMEC_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_CCNue_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_NC_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_OOFV_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_EXT_nobtblowPT_Tune1");
 TH1D* reco_relpnp2_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("reco_relpnp2_other_nobtblowPT_Tune1");

 TH1D* anglep1p2CM_CCQE_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCQE_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_CCRes_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCRes_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_CCCoh_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCCoh_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_CCDIS_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCDIS_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_CCMEC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCMEC_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_CCNue_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCNue_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_NC_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_NC_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_OOFV_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_OOFV_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_EXT_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_EXT_nobtblowPT_Tune1");
 TH1D* anglep1p2CM_other_nobtblowPT_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_other_nobtblowPT_Tune1");

 TH1D* anglep1p2CM_CCQE_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCQE_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_CCRes_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCRes_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_CCNue_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_CCNue_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_NC_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_NC_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_OOFV_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_OOFV_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_EXT_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_EXT_nobtblowPT_rebin_Tune1");
 TH1D* anglep1p2CM_other_nobtblowPT_rebin_Tune1 = (TH1D*) BNBMC->Get("anglep1p2CM_other_nobtblowPT_rebin_Tune1");

 TH2D* angleCM_PT_CCQE_Tune1 = (TH2D*) BNBMC->Get("angleCM_PT_CCQE_Tune1");
 TH2D* angleCM_PT_CCRes_Tune1 = (TH2D*) BNBMC->Get("angleCM_PT_CCRes_Tune1");
 TH2D* angleCM_PT_CCMEC_Tune1 = (TH2D*) BNBMC->Get("angleCM_PT_CCMEC_Tune1");
 TH2D* angleCM_PT_all_Tune1 = (TH2D*) BNBMC->Get("angleCM_PT_all_Tune1");

 TH1D* angleCM_CCQE_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_CCQE_lowPT_Tune1");
 TH1D* angleCM_CCRes_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_CCRes_lowPT_Tune1");
 TH1D* angleCM_CCCoh_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_CCCoh_lowPT_Tune1");
 TH1D* angleCM_CCDIS_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_CCDIS_lowPT_Tune1");
 TH1D* angleCM_CCMEC_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_CCMEC_lowPT_Tune1");
 TH1D* angleCM_CCNue_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_CCNue_lowPT_Tune1");
 TH1D* angleCM_NC_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_NC_lowPT_Tune1");
 TH1D* angleCM_OOFV_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_OOFV_lowPT_Tune1");
 TH1D* angleCM_EXT_lowPT_Tune1 = (TH1D*) BNBMC->Get("angleCM_EXT_lowPT_Tune1");

 TH2D* pn_prel_CCQE_lowPT_1stbin_Tune1 = (TH2D*) BNBMC->Get("pn_prel_CCQE_lowPT_1stbin_Tune1"); 
 TH2D* pn_prel_CCRes_lowPT_1stbin_Tune1 = (TH2D*) BNBMC->Get("pn_prel_CCRes_lowPT_1stbin_Tune1"); 
 TH2D* pn_prel_CCMEC_lowPT_1stbin_Tune1 = (TH2D*) BNBMC->Get("pn_prel_CCMEC_lowPT_1stbin_Tune1"); 
 TH2D* pn_prel_all_lowPT_1stbin_Tune1 = (TH2D*) BNBMC->Get("pn_prel_all_lowPT_1stbin_Tune1"); 
 
  ///////////////////// On-Beam data/////////////////////////////////////////////////////

 TH1D* selmuon_mom_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_mom_OnBeam_PID");
 TH1D* selproton1_mom_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_mom_OnBeam_PID");
 TH1D* selproton2_mom_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_mom_OnBeam_PID");
 TH1D* selmuon_costheta_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_costheta_OnBeam_PID");
 TH1D* selproton1_costheta_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_costheta_OnBeam_PID");
 TH1D* selproton2_costheta_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_costheta_OnBeam_PID");
 TH1D* selmuon_phi_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_phi_OnBeam_PID");
 TH1D* selproton1_phi_OnBeam_PID = (TH1D*) OnBeam->Get("selproton1_phi_OnBeam_PID");
 TH1D* selproton2_phi_OnBeam_PID = (TH1D*) OnBeam->Get("selproton2_phi_OnBeam_PID");
 TH1D* reco_angle_p1p2_OnBeam_PID_LF_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_LF_zoom");
 TH1D* reco_angle_p1p2_OnBeam_PID_CM_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_zoom");
 TH1D* reco_Enu_OnBeam_PID = (TH1D*) OnBeam->Get("reco_Enu_OnBeam_PID"); 
 TH1D* reco_PT_OnBeam_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_PID"); 
 TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom"); 
 TH1D* reco_PT_OnBeam_nobtbLF_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_nobtbLF_PID");
 TH1D* reco_pn_OnBeam_nobtbLF_PID= (TH1D*) OnBeam->Get("reco_pn_OnBeam_nobtbLF_PID");
 TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom= (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom");
 TH1D* reco_Enu_OnBeam_nobtbLF_PT_PID= (TH1D*) OnBeam->Get("reco_Enu_OnBeam_nobtbLF_PT_PID");
 TH1D* reco_pn_OnBeam_nobtbLF_PT_PID= (TH1D*) OnBeam->Get("reco_pn_OnBeam_nobtbLF_PT_PID");
 TH1D* reco_projptot_OnBeam_nobtb_lowPT= (TH1D*) OnBeam->Get("reco_projptot_OnBeam_nobtb_lowPT");
 TH1D* reco_projprel_OnBeam_nobtb_lowPT= (TH1D*) OnBeam->Get("reco_projprel_OnBeam_nobtb_lowPT");
 TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin= (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin");
 TH1D* reco_pn_OnBeam_PID= (TH1D*) OnBeam->Get("reco_pn_OnBeam_PID");

 TH1D* reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3= (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3");

 
 
 //////////////////// Off-Beam ///////////////////////////////////////////////////////////

 TH1D* selmuon_mom_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_mom_OffBeam_PID");
 TH1D* selproton1_mom_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_mom_OffBeam_PID");
 TH1D* selproton2_mom_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_mom_OffBeam_PID");
 TH1D* selmuon_costheta_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_costheta_OffBeam_PID");
 TH1D* selproton1_costheta_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_costheta_OffBeam_PID");
 TH1D* selproton2_costheta_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_costheta_OffBeam_PID");
 TH1D* selmuon_phi_OffBeam_PID = (TH1D*) OffBeam->Get("selmuon_phi_OffBeam_PID");
 TH1D* selproton1_phi_OffBeam_PID = (TH1D*) OffBeam->Get("selproton1_phi_OffBeam_PID");
 TH1D* selproton2_phi_OffBeam_PID = (TH1D*) OffBeam->Get("selproton2_phi_OffBeam_PID");
 TH1D* reco_angle_p1p2_OffBeam_PID_LF_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_LF_zoom");
 TH1D* reco_angle_p1p2_OffBeam_PID_CM_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_PID_CM_zoom");
 TH1D* reco_Enu_OffBeam_PID = (TH1D*) OffBeam->Get("reco_Enu_OffBeam_PID"); 
 TH1D* reco_PT_OffBeam_PID = (TH1D*) OffBeam->Get("reco_PT_OffBeam_PID"); 
 TH1D* reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom = (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom"); 
 TH1D* reco_PT_OffBeam_nobtbLF_PID = (TH1D*) OffBeam->Get("reco_PT_OffBeam_nobtbLF_PID");
 TH1D* reco_pn_OffBeam_nobtbLF_PID= (TH1D*) OffBeam->Get("reco_pn_OffBeam_nobtbLF_PID");
 TH1D* reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom= (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom");
 TH1D* reco_Enu_OffBeam_nobtbLF_PT_PID= (TH1D*) OffBeam->Get("reco_Enu_OffBeam_nobtbLF_PT_PID");
 TH1D* reco_pn_OffBeam_nobtbLF_PT_PID= (TH1D*) OffBeam->Get("reco_pn_OffBeam_nobtbLF_PT_PID");
 TH1D* reco_projptot_OffBeam_nobtb_lowPT= (TH1D*) OffBeam->Get("reco_projptot_OffBeam_nobtb_lowPT");
 TH1D* reco_projprel_OffBeam_nobtb_lowPT= (TH1D*) OffBeam->Get("reco_projprel_OffBeam_nobtb_lowPT");
 TH1D* reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin= (TH1D*) OffBeam->Get("reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin");
 TH1D* reco_pn_OffBeam_PID= (TH1D*) OffBeam->Get("reco_pn_OffBeam_PID");
 
 ///// Tune 3///
 
 TH1D* anglep1p2CM_CCQE_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCQE_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_CCRes_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCRes_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_CCCoh_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCCoh_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_CCDIS_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCDIS_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_CCMEC_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCMEC_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_CCNue_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCNue_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_NC_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_NC_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_OOFV_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_OOFV_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_EXT_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_EXT_nobtblowPT_Tune3");
 TH1D* anglep1p2CM_other_nobtblowPT_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_other_nobtblowPT_Tune3");

 TH1D* anglep1p2CM_CCQE_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCQE_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_CCRes_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCRes_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_CCNue_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_CCNue_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_NC_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_NC_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_OOFV_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_OOFV_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_EXT_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_EXT_nobtblowPT_rebin_Tune3");
 TH1D* anglep1p2CM_other_nobtblowPT_rebin_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2CM_other_nobtblowPT_rebin_Tune3");

 TH1D* anglep1p2LF_CCQE_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_CCQE_nocuts_Tune3");
 TH1D* anglep1p2LF_CCRes_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_CCRes_nocuts_Tune3");
 TH1D* anglep1p2LF_CCCoh_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_CCCoh_nocuts_Tune3");
 TH1D* anglep1p2LF_CCDIS_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_CCDIS_nocuts_Tune3");
 TH1D* anglep1p2LF_CCMEC_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_CCMEC_nocuts_Tune3");
 TH1D* anglep1p2LF_CCNue_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_CCNue_nocuts_Tune3");
 TH1D* anglep1p2LF_NC_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_NC_nocuts_Tune3");
 TH1D* anglep1p2LF_OOFV_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_OOFV_nocuts_Tune3");
 TH1D* anglep1p2LF_EXT_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_EXT_nocuts_Tune3");
 TH1D* anglep1p2LF_other_nocuts_Tune3 = (TH1D*) BNBMCTune3->Get("anglep1p2LF_other_nocuts_Tune3");
 
  /// valores de las normalizaciones

  //Double_t normMCBNB =  (4.411e+19)/(4.0878e+20);//tune 3
  //Double_t normMCBNB =  (4.411e+19)/(2.010e+20);//(4.874e+19)/(1.566e+20);/// public note
  Double_t normMCBNB =  (1.562e+20)/(2.010e+20); //(4.874e+19)/(1.566e+20);/// paper
  ///Double_t normOffBeam = 9775610./73710197.;  //0.1464;//(33320382.)/(36177265.);// public note
  Double_t normOffBeam = 35388924./73710197.;  //0.1464;//(33320382.)/(36177265.);//paper
  Double_t normMCBNBTune3 =  (1.562e+20)/(4.0878e+20);//tune 3


  /// normalizing MC
  std::cout<<"antes del scale"<<std::endl;
  std::cout<<"normMCBNB : "<<normMCBNB<<std::endl;
  std::cout<<"normMCBNB Tune3: "<<normMCBNBTune3<<std::endl;
  std::cout<<"normOffBeam : "<<normOffBeam<<std::endl;

  //// errores estadisticos
  
  int nbinsLF=reco_angle_p1p2_OnBeam_PID_LF_zoom->GetNbinsX();

  std::cout<<"num bins "<<nbinsLF<<std::endl;

  //  double systLF[21] ={0.213068, 0.0717653, 0.0100651, 0.00556159, 0.659479, 0.278703, 1.10987, 1.01436, 4.98589, 8.31293, 18.5596, 103.581, 1.683, 1.38248, 2.90295, 2.04023, 1.2954, 1.63008, 7.35112, 1.83456};/// RMS

  double systLF[21] ={0.213068, 0.0717653, 0.0100651, 0.00556159, 0.659479, 0.278703, 1.10987, 1.01436, 4.98589, 8.31293, 8.3129, 8.3129, 1.683, 1.38248, 2.90295, 2.04023, 1.2954, 1.63008, 7.35112, 1.83456};/// RMS

  double errLF[21];
  double statsLF[21];
  double statsnocutsLF[21];

  double statsLFtune1[21];
  double statsLFtune3[21];
  
  THStack *anglep1p2LF_nocuts_Tune1noScale = new THStack("anglep1p2LF_nocuts_Tune1noScale","");
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_CCQE_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_CCRes_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_CCMEC_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_CCCoh_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_CCDIS_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_CCNue_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_NC_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(anglep1p2LF_EXT_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1noScale-> Add(reco_angle_p1p2_OffBeam_PID_LF_zoom);
  
  THStack *anglep1p2LF_nocuts_Tune3 = new THStack("anglep1p2LF_nocuts_Tune3","");
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_CCQE_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_CCRes_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_CCMEC_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_CCCoh_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_CCDIS_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_CCNue_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_NC_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(anglep1p2LF_EXT_nocuts_Tune3);
  anglep1p2LF_nocuts_Tune3-> Add(reco_angle_p1p2_OffBeam_PID_LF_zoom);
  
  TH1F *h23 = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF_zoom->Clone("h23");
  TH1 *last23 = (TH1*)anglep1p2LF_nocuts_Tune1noScale->GetStack()->Last();

  TH1F *h23tune3 = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF_zoom->Clone("h23tune3");
  TH1 *last23tune3 = (TH1*)anglep1p2LF_nocuts_Tune3->GetStack()->Last();///

  last23->Sumw2();
  last23tune3->Sumw2();
  /*
  for(int ii=0; ii<nbinsLF-1; ii++){
    statsLF[ii] = reco_angle_p1p2_OnBeam_PID_LF_zoom->GetBinError(ii+1);
    statsLFtune1[ii] = last23->GetBinError(ii+1);
    statsLFtune3[ii] = last23tune3->GetBinError(ii+1);
  }
  */
  last23->Scale(normMCBNB);
  last23tune3->Scale(normMCBNBTune3);


  gStyle->SetOptStat(0000);
  gStyle->SetOptFit(1111);
  gStyle->SetLabelSize(0.035,"X");///004
  gStyle->SetLabelFont(22,"X");
  gStyle->SetTitleSize(0.05,"X");
  gStyle->SetTitleFont(62,"X");
  gStyle->SetTitleOffset(0.85,"X");
  gStyle->SetLabelSize(0.035,"Y");
  gStyle->SetLabelFont(22,"Y");
  gStyle->SetTitleSize(0.05,"Y");
  gStyle->SetTitleFont(62,"Y");
  gStyle->SetTitleOffset(1.0,"Y");
  gStyle->SetTitleX(0.22);
  gStyle->SetTitleY(0.98);
  gStyle->SetTitleSize(0.04,"t");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderSize(0);

  gStyle->SetTitleSize(0.045,"xyz");
  gStyle->SetTitleFont(22,"xyz");
  gStyle->SetLabelFont(22,"xyz");
  gStyle->SetTitleOffset(1.,"y");
  gStyle->SetTitleOffset(1.,"x");


  anglep1p2CM_CCQE_nobtblowPT_Tune1-> Rebin(2);
  anglep1p2CM_CCRes_nobtblowPT_Tune1-> Rebin(2);
  anglep1p2CM_CCMEC_nobtblowPT_Tune1-> Rebin(2);
  

  TCanvas *c33CCQE = new TCanvas("c33CCQE", "cc33CCQE", 900, 900);

  anglep1p2CM_CCQE_nobtblowPT_Tune1-> SetFillColor(kRed -10);
  //anglep1p2CM_CCRes_nobtblowPT_Tune1-> SetFillColor(kGreen-8);
  //anglep1p2CM_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  //anglep1p2CM_CCDIS_nobtblowPT_Tune1-> SetFillColor(kOrange);
  anglep1p2CM_CCQE_nobtblowPT_Tune1->SetTitle("");
  anglep1p2CM_CCQE_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  anglep1p2CM_CCQE_nobtblowPT_Tune1->GetXaxis()->SetTitle("cos #gamma_{CM}");
  anglep1p2CM_CCQE_nobtblowPT_Tune1-> Draw();
  
  TLegend *l33CCQE = new TLegend(0.45, 0.75, 0.9, 0.9);
  l33CCQE -> AddEntry(anglep1p2CM_CCQE_nobtblowPT_Tune1, "CC-QE", "f");
  //l33CCQE -> AddEntry(anglep1p2CM_CCRes_nobtblowPT_Tune1, "CC-Res", "f");
  //l33CCQE -> AddEntry(anglep1p2CM_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l33CCQE -> Draw();

  c33CCQE->Update();
  c33CCQE->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_lowPT_CCQE_Tune1.pdf");  
  c33CCQE->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_lowPT_CCQE_Tune1.eps");  

  TCanvas *c33CCRes = new TCanvas("c33CCRes", "cc33CCRes", 900, 900);
  
  anglep1p2CM_CCRes_nobtblowPT_Tune1-> SetFillColor(kGreen-8);
  //anglep1p2CM_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  //anglep1p2CM_CCDIS_nobtblowPT_Tune1-> SetFillColor(kOrange);
  anglep1p2CM_CCRes_nobtblowPT_Tune1->SetTitle("");
  anglep1p2CM_CCRes_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  anglep1p2CM_CCRes_nobtblowPT_Tune1->GetXaxis()->SetTitle("cos #gamma_{CM}");
  anglep1p2CM_CCRes_nobtblowPT_Tune1-> Draw();
  
  TLegend *l33CCRes = new TLegend(0.45, 0.75, 0.9, 0.9);
  l33CCRes -> AddEntry(anglep1p2CM_CCRes_nobtblowPT_Tune1, "CC-Res", "f");
  //l33CCQE -> AddEntry(anglep1p2CM_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l33CCRes -> Draw();

  c33CCRes->Update();
  c33CCRes->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_lowPT_CCRes_Tune1.pdf");  
  c33CCRes->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_lowPT_CCRes_Tune1.eps");  
   

  TCanvas *c33CCMEC = new TCanvas("c33CCMEC", "cc33CCMEC", 900, 900);
  
  anglep1p2CM_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  anglep1p2CM_CCMEC_nobtblowPT_Tune1->SetTitle("");
  anglep1p2CM_CCMEC_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  anglep1p2CM_CCMEC_nobtblowPT_Tune1->GetXaxis()->SetTitle("cos #gamma_{CM}");
  anglep1p2CM_CCMEC_nobtblowPT_Tune1-> Draw();
  
  TLegend *l33CCMEC = new TLegend(0.45, 0.75, 0.9, 0.9);
  l33CCMEC -> AddEntry(anglep1p2CM_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l33CCMEC -> Draw();

  c33CCMEC->Update();
  c33CCMEC->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_lowPT_CCMEC_Tune1.pdf");  
  c33CCMEC->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_lowPT_CCMEC_Tune1.eps");  
   
  

  
  //normalizar solo 1D
  
  selmuon_mom_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_NC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_EXT_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_other_nocuts_Tune1->Scale(normMCBNB);

  selmuon_contained_mom_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_NC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_EXT_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_other_nocuts_Tune1->Scale(normMCBNB);

  selmuon_uncontained_mom_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_NC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_EXT_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_other_nocuts_Tune1->Scale(normMCBNB);

  selmuon_costheta_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_NC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_EXT_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_other_nocuts_Tune1->Scale(normMCBNB);

  selmuon_phi_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_NC_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_EXT_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_other_nocuts_Tune1->Scale(normMCBNB);

  selmuon_mom_muon_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_proton_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_pion_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_electron_nocuts_Tune1->Scale(normMCBNB);
  selmuon_mom_pother_nocuts_Tune1->Scale(normMCBNB);

  selmuon_contained_mom_muon_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_proton_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_pion_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_electron_nocuts_Tune1->Scale(normMCBNB);
  selmuon_contained_mom_pother_nocuts_Tune1->Scale(normMCBNB);

  selmuon_uncontained_mom_muon_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_proton_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_pion_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_electron_nocuts_Tune1->Scale(normMCBNB);
  selmuon_uncontained_mom_pother_nocuts_Tune1->Scale(normMCBNB);

  selmuon_costheta_muon_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_proton_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_pion_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_electron_nocuts_Tune1->Scale(normMCBNB);
  selmuon_costheta_pother_nocuts_Tune1->Scale(normMCBNB);

  selmuon_phi_muon_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_proton_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_pion_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_electron_nocuts_Tune1->Scale(normMCBNB);
  selmuon_phi_pother_nocuts_Tune1->Scale(normMCBNB);

  selproton1_mom_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_NC_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_EXT_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_other_nocuts_Tune1->Scale(normMCBNB);

  selproton1_costheta_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_NC_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_EXT_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_other_nocuts_Tune1->Scale(normMCBNB);

  selproton1_phi_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_NC_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_EXT_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_other_nocuts_Tune1->Scale(normMCBNB);

  selproton1_mom_muon_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_proton_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_pion_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_electron_nocuts_Tune1->Scale(normMCBNB);
  selproton1_mom_pother_nocuts_Tune1->Scale(normMCBNB);

  selproton1_costheta_muon_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_proton_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_pion_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_electron_nocuts_Tune1->Scale(normMCBNB);
  selproton1_costheta_pother_nocuts_Tune1->Scale(normMCBNB);

  selproton1_phi_muon_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_proton_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_pion_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_electron_nocuts_Tune1->Scale(normMCBNB);
  selproton1_phi_pother_nocuts_Tune1->Scale(normMCBNB);

  selproton2_mom_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_NC_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_EXT_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_other_nocuts_Tune1->Scale(normMCBNB);

  selproton2_costheta_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_NC_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_EXT_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_other_nocuts_Tune1->Scale(normMCBNB);

  selproton2_phi_CCQE_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_CCRes_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_CCNue_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_NC_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_OOFV_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_EXT_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_other_nocuts_Tune1->Scale(normMCBNB);

  selproton2_mom_muon_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_proton_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_pion_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_electron_nocuts_Tune1->Scale(normMCBNB);
  selproton2_mom_pother_nocuts_Tune1->Scale(normMCBNB);

  selproton2_costheta_muon_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_proton_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_pion_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_electron_nocuts_Tune1->Scale(normMCBNB);
  selproton2_costheta_pother_nocuts_Tune1->Scale(normMCBNB);

  selproton2_phi_muon_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_proton_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_pion_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_electron_nocuts_Tune1->Scale(normMCBNB);
  selproton2_phi_pother_nocuts_Tune1->Scale(normMCBNB);

  anglemup1_CCQE_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_CCRes_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_CCNue_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_NC_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_OOFV_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_EXT_nocuts_Tune1->Scale(normMCBNB);
  anglemup1_other_nocuts_Tune1->Scale(normMCBNB);

  anglemup2_CCQE_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_CCRes_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_CCNue_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_NC_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_OOFV_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_EXT_nocuts_Tune1->Scale(normMCBNB);
  anglemup2_other_nocuts_Tune1->Scale(normMCBNB);

  anglep1p2LF_CCQE_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_CCRes_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_CCNue_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_NC_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_OOFV_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_EXT_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2LF_other_nocuts_Tune1->Scale(normMCBNB);

  reco_Enu_CCQE_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_CCRes_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_CCNue_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_NC_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_OOFV_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_EXT_nocuts_Tune1->Scale(normMCBNB);
  reco_Enu_other_nocuts_Tune1->Scale(normMCBNB);

  reco_PT_CCQE_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_CCRes_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_CCNue_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_NC_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_OOFV_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_EXT_nocuts_Tune1->Scale(normMCBNB);
  reco_PT_other_nocuts_Tune1->Scale(normMCBNB);

  reco_pn_CCQE_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_CCRes_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_CCNue_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_NC_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_OOFV_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_EXT_nocuts_Tune1->Scale(normMCBNB);
  reco_pn_other_nocuts_Tune1->Scale(normMCBNB);

  reco_totpnp2_CCQE_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCRes_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCNue_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_NC_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_OOFV_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_EXT_nocuts_Tune1->Scale(normMCBNB);
  reco_totpnp2_other_nocuts_Tune1->Scale(normMCBNB);

  reco_relpnp2_CCQE_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCRes_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCNue_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_NC_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_OOFV_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_EXT_nocuts_Tune1->Scale(normMCBNB);
  reco_relpnp2_other_nocuts_Tune1->Scale(normMCBNB);

  anglep1p2CM_CCQE_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCRes_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCCoh_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCDIS_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCMEC_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCNue_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_NC_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_OOFV_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_EXT_nocuts_Tune1->Scale(normMCBNB);
  anglep1p2CM_other_nocuts_Tune1->Scale(normMCBNB);

  angleCM_CCQE_lowPT_Tune1->Scale(normMCBNB);
  angleCM_CCRes_lowPT_Tune1->Scale(normMCBNB);
  angleCM_CCCoh_lowPT_Tune1->Scale(normMCBNB);
  angleCM_CCDIS_lowPT_Tune1->Scale(normMCBNB);
  angleCM_CCMEC_lowPT_Tune1->Scale(normMCBNB);
  angleCM_CCNue_lowPT_Tune1->Scale(normMCBNB);
  angleCM_NC_lowPT_Tune1->Scale(normMCBNB);
  angleCM_OOFV_lowPT_Tune1->Scale(normMCBNB);
  angleCM_EXT_lowPT_Tune1->Scale(normMCBNB);
  
////////////////////////////////////////////////// no hammer //////

  selmuon_mom_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_NC_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_EXT_nobtb_Tune1->Scale(normMCBNB);
  selmuon_mom_other_nobtb_Tune1->Scale(normMCBNB);

  selmuon_costheta_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_NC_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_EXT_nobtb_Tune1->Scale(normMCBNB);
  selmuon_costheta_other_nobtb_Tune1->Scale(normMCBNB);

  selmuon_phi_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_NC_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_EXT_nobtb_Tune1->Scale(normMCBNB);
  selmuon_phi_other_nobtb_Tune1->Scale(normMCBNB);

  selproton1_mom_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_NC_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_EXT_nobtb_Tune1->Scale(normMCBNB);
  selproton1_mom_other_nobtb_Tune1->Scale(normMCBNB);

  selproton1_costheta_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_NC_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_EXT_nobtb_Tune1->Scale(normMCBNB);
  selproton1_costheta_other_nobtb_Tune1->Scale(normMCBNB);

  selproton1_phi_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_NC_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_EXT_nobtb_Tune1->Scale(normMCBNB);
  selproton1_phi_other_nobtb_Tune1->Scale(normMCBNB);

  selproton2_mom_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_NC_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_EXT_nobtb_Tune1->Scale(normMCBNB);
  selproton2_mom_other_nobtb_Tune1->Scale(normMCBNB);

  selproton2_costheta_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_NC_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_EXT_nobtb_Tune1->Scale(normMCBNB);
  selproton2_costheta_other_nobtb_Tune1->Scale(normMCBNB);

  selproton2_phi_CCQE_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_CCRes_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_CCNue_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_NC_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_OOFV_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_EXT_nobtb_Tune1->Scale(normMCBNB);
  selproton2_phi_other_nobtb_Tune1->Scale(normMCBNB);

  reco_Enu_CCQE_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_CCRes_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_CCNue_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_NC_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_OOFV_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_EXT_nobtb_Tune1->Scale(normMCBNB);
  reco_Enu_other_nobtb_Tune1->Scale(normMCBNB);

  reco_PT_CCQE_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_CCRes_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_CCNue_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_NC_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_OOFV_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_EXT_nobtb_Tune1->Scale(normMCBNB);
  reco_PT_other_nobtb_Tune1->Scale(normMCBNB);

  reco_pn_CCQE_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_CCRes_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_CCNue_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_NC_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_OOFV_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_EXT_nobtb_Tune1->Scale(normMCBNB);
  reco_pn_other_nobtb_Tune1->Scale(normMCBNB);

  reco_totpnp2_CCQE_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCRes_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCNue_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_NC_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_OOFV_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_EXT_nobtb_Tune1->Scale(normMCBNB);
  reco_totpnp2_other_nobtb_Tune1->Scale(normMCBNB);

  reco_relpnp2_CCQE_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCRes_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCNue_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_NC_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_OOFV_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_EXT_nobtb_Tune1->Scale(normMCBNB);
  reco_relpnp2_other_nobtb_Tune1->Scale(normMCBNB);

  anglep1p2CM_CCQE_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCRes_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCCoh_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCDIS_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCMEC_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCNue_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_NC_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_OOFV_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_EXT_nobtb_Tune1->Scale(normMCBNB);
  anglep1p2CM_other_nobtb_Tune1->Scale(normMCBNB);
  
  //////////////////////////////////////////////////// no hammer, low PT

  selmuon_mom_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_mom_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selmuon_costheta_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_costheta_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selmuon_phi_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selmuon_phi_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selproton1_mom_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_mom_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selproton1_costheta_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_costheta_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selproton1_phi_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton1_phi_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selproton2_mom_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_mom_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selproton2_costheta_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_costheta_other_nobtblowPT_Tune1->Scale(normMCBNB);

  selproton2_phi_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  selproton2_phi_other_nobtblowPT_Tune1->Scale(normMCBNB);

  reco_Enu_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_Enu_other_nobtblowPT_Tune1->Scale(normMCBNB);
 
  reco_pn_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_pn_other_nobtblowPT_Tune1->Scale(normMCBNB);

  reco_totpnp2_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_totpnp2_other_nobtblowPT_Tune1->Scale(normMCBNB);

  reco_relpnp2_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  reco_relpnp2_other_nobtblowPT_Tune1->Scale(normMCBNB);

  anglep1p2CM_CCQE_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCRes_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCCoh_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCDIS_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCMEC_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCNue_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_NC_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_OOFV_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_EXT_nobtblowPT_Tune1->Scale(normMCBNB);
  anglep1p2CM_other_nobtblowPT_Tune1->Scale(normMCBNB);


  std::cout<<"anted de normalizar MC"<<std::endl;
  anglep1p2CM_CCQE_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCRes_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_CCNue_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_NC_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_OOFV_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_EXT_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  anglep1p2CM_other_nobtblowPT_rebin_Tune1->Scale(normMCBNB);
  ////////////////////////////////////////

  anglep1p2CM_CCQE_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCRes_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCCoh_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCDIS_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCMEC_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCNue_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_NC_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_OOFV_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_EXT_nobtblowPT_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_other_nobtblowPT_Tune3->Scale(normMCBNBTune3);

  anglep1p2CM_CCQE_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCRes_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_CCNue_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_NC_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_OOFV_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_EXT_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);
  anglep1p2CM_other_nobtblowPT_rebin_Tune3->Scale(normMCBNBTune3);

  anglep1p2LF_CCQE_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_CCRes_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_CCCoh_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_CCDIS_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_CCMEC_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_CCNue_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_NC_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_OOFV_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_EXT_nocuts_Tune3->Scale(normMCBNBTune3);
  anglep1p2LF_other_nocuts_Tune3->Scale(normMCBNBTune3);


  //////////////////////////////////////////////// Off beam data normalization

  selmuon_mom_OffBeam_PID->Scale(normOffBeam);
  selproton1_mom_OffBeam_PID->Scale(normOffBeam);
  selproton2_mom_OffBeam_PID->Scale(normOffBeam);
  selmuon_costheta_OffBeam_PID->Scale(normOffBeam);
  selproton1_costheta_OffBeam_PID->Scale(normOffBeam);
  selproton2_costheta_OffBeam_PID->Scale(normOffBeam);
  selmuon_phi_OffBeam_PID->Scale(normOffBeam);
  selproton1_phi_OffBeam_PID->Scale(normOffBeam);
  selproton2_phi_OffBeam_PID->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_PID_LF_zoom->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_PID_CM_zoom->Scale(normOffBeam);
  reco_Enu_OffBeam_PID->Scale(normOffBeam);
  reco_PT_OffBeam_PID->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom->Scale(normOffBeam);
  reco_PT_OffBeam_nobtbLF_PID->Scale(normOffBeam);
  reco_pn_OffBeam_nobtbLF_PID->Scale(normOffBeam);
  reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom->Scale(normOffBeam);
  reco_Enu_OffBeam_nobtbLF_PT_PID->Scale(normOffBeam);
  reco_pn_OffBeam_nobtbLF_PT_PID->Scale(normOffBeam);
  reco_projptot_OffBeam_nobtb_lowPT->Scale(normOffBeam);
  reco_projprel_OffBeam_nobtb_lowPT->Scale(normOffBeam);
  reco_pn_OffBeam_PID->Scale(normOffBeam);
  
  std::cout<<"anted de normalizar offbeam"<<std::endl;
  reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin->Scale(normOffBeam);
  
  std::cout<<"gStyle options "<<std::endl;

  gStyle->SetOptStat(0000);
  gStyle->SetOptFit(1111);
  gStyle->SetPadColor(kWhite);
  gStyle->SetStatY(0.90);
  gStyle->SetStatX(0.90);
  gStyle->SetStatW(0.15);
  gStyle->SetStatH(0.2);
  gStyle->SetLabelSize(0.035,"X");///004
  gStyle->SetLabelFont(22,"X");
  gStyle->SetTitleSize(0.05,"X");
  gStyle->SetTitleFont(62,"X");
  gStyle->SetTitleOffset(0.85,"X");
  gStyle->SetLabelSize(0.035,"Y");
  gStyle->SetLabelFont(22,"Y");
  gStyle->SetTitleSize(0.05,"Y");
  gStyle->SetTitleFont(62,"Y");
  gStyle->SetTitleOffset(1.0,"Y");
  gStyle->SetTitleX(0.22);
  gStyle->SetTitleY(0.98);
  gStyle->SetTitleSize(0.04,"t");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderSize(0);
  //gStyle->SetPadRightMargin(0.15);

  gStyle->SetTitleSize(0.045,"xyz");
  gStyle->SetTitleFont(22,"xyz");
  gStyle->SetLabelFont(22,"xyz");
  gStyle->SetTitleOffset(1.,"y");
  gStyle->SetTitleOffset(1.,"x");

  std::cout<<"antes de los plots"<<std::endl;  

  double chi2test =0.0;
  int canvas=0;

  ///////////////////////////////////////////////////////////////// plots with no cuts ////////////////////////////////////////////////
  
  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();              // pad1 becomes the current pad

  selmuon_mom_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selmuon_mom_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selmuon_mom_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selmuon_mom_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selmuon_mom_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selmuon_mom_CCNue_nocuts_Tune1-> SetFillColor(31);
  selmuon_mom_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selmuon_mom_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selmuon_mom_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_mom_nocuts_Tune1 = new THStack("selmuon_mom_nocuts_Tune1","");
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_CCQE_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_CCRes_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_CCMEC_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_CCCoh_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_CCDIS_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_CCNue_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_NC_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_EXT_nocuts_Tune1);
  selmuon_mom_nocuts_Tune1-> Add(selmuon_mom_OffBeam_PID);
  ////  selmuon_mom_nocuts_Tune1->SetMaximum(80.);
  selmuon_mom_nocuts_Tune1-> Draw();
  selmuon_mom_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");

  
  selmuon_mom_OnBeam_PID->SetLineColor(kBlack);
  selmuon_mom_OnBeam_PID->SetMarkerStyle(20);
  selmuon_mom_OnBeam_PID->Draw("e1same");

  TLegend *l1 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l1 -> SetNColumns(2);
  l1 -> AddEntry(selmuon_mom_CCQE_nocuts_Tune1, "CC-QE", "f");
  l1 -> AddEntry(selmuon_mom_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l1 -> AddEntry(selmuon_mom_CCRes_nocuts_Tune1, "CC-Res", "f");
  l1 -> AddEntry(selmuon_mom_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l1 -> AddEntry(selmuon_mom_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l1 -> AddEntry(selmuon_mom_NC_nocuts_Tune1, "NC", "f");
  l1 -> AddEntry(selmuon_mom_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l1 -> AddEntry(selmuon_mom_EXT_nocuts_Tune1, "other", "f");
  l1 -> AddEntry(selmuon_mom_OffBeam_PID, "off-beam data", "f");
  l1 -> AddEntry(selmuon_mom_OnBeam_PID, "on-beam data", "lep");
  l1 -> Draw();

  TText *t1 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h1 = (TH1F*)selmuon_mom_OnBeam_PID->Clone("h1");
  TH1 *last1 = (TH1*)selmuon_mom_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last1, selmuon_mom_OnBeam_PID, selmuon_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selmuon_mom_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h1->GetXaxis()->SetTitle("cos #theta_{#mu}");
  h1->GetXaxis()->SetTitleSize(20);
  h1->GetXaxis()->SetTitleFont(43);
  h1->GetXaxis()->SetTitleOffset(3.);
  h1->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetXaxis()->SetLabelSize(15);

  c1->Update();
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selmuon_mom_nocuts_Tune1.pdf");
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selmuon_mom_nocuts_Tune1.eps");

  TCanvas *c2 = new TCanvas("c2", "c2", 900, 900);
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.3, 1, 1.0);
  pad2->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad2->Draw();             // Draw the upper pad: pad1
  pad2->cd();              // pad1 becomes the current pad

  selproton1_mom_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selproton1_mom_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selproton1_mom_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selproton1_mom_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selproton1_mom_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selproton1_mom_CCNue_nocuts_Tune1-> SetFillColor(31);
  selproton1_mom_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selproton1_mom_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selproton1_mom_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton1_mom_nocuts_Tune1 = new THStack("selproton1_mom_nocuts_Tune1","");
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_CCQE_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_CCRes_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_CCMEC_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_CCCoh_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_CCDIS_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_CCNue_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_NC_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_EXT_nocuts_Tune1);
  selproton1_mom_nocuts_Tune1-> Add(selproton1_mom_OffBeam_PID);
  selproton1_mom_nocuts_Tune1->SetMaximum(400.);
  selproton1_mom_nocuts_Tune1-> Draw();
  selproton1_mom_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selproton1_mom_OnBeam_PID->SetLineColor(kBlack);
  selproton1_mom_OnBeam_PID->SetMarkerStyle(20);
  selproton1_mom_OnBeam_PID->Draw("e1same");

  TLegend *l2 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l2 -> SetNColumns(2);
  l2 -> AddEntry(selproton1_mom_CCQE_nocuts_Tune1, "CC-QE", "f");
  l2 -> AddEntry(selproton1_mom_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l2 -> AddEntry(selproton1_mom_CCRes_nocuts_Tune1, "CC-Res", "f");
  l2 -> AddEntry(selproton1_mom_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l2 -> AddEntry(selproton1_mom_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l2 -> AddEntry(selproton1_mom_NC_nocuts_Tune1, "NC", "f");
  l2 -> AddEntry(selproton1_mom_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l2 -> AddEntry(selproton1_mom_EXT_nocuts_Tune1, "other", "f");
  l2 -> AddEntry(selproton1_mom_OffBeam_PID, "off-beam data", "f");
  l2 -> AddEntry(selproton1_mom_OnBeam_PID, "on-beam data", "lep");
  l2 -> Draw();

  TText *t2 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h2 = (TH1F*)selproton1_mom_OnBeam_PID->Clone("h2");
  TH1 *last2 = (TH1*)selproton1_mom_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last2, selproton1_mom_OnBeam_PID, selproton1_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selproton1_mom_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h2->GetXaxis()->SetTitle("longest proton momentum [GeV/c]");
  h2->GetXaxis()->SetTitleSize(20);
  h2->GetXaxis()->SetTitleFont(43);
  h2->GetXaxis()->SetTitleOffset(3.);
  h2->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h2->GetXaxis()->SetLabelSize(15);

  c2->Update();
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton1_mom_nocuts_Tune1.pdf");
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton1_mom_nocuts_Tune1.eps");
  
  TCanvas *c3 = new TCanvas("c3", "c3", 900, 900);
  TPad *pad3 = new TPad("pad3", "pad3", 0, 0.3, 1, 1.0);
  pad3->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad3->Draw();             // Draw the upper pad: pad1
  pad3->cd();              // pad1 becomes the current pad

  selproton2_mom_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selproton2_mom_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selproton2_mom_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selproton2_mom_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selproton2_mom_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selproton2_mom_CCNue_nocuts_Tune1-> SetFillColor(31);
  selproton2_mom_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selproton2_mom_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selproton2_mom_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton2_mom_nocuts_Tune1 = new THStack("selproton2_mom_nocuts_Tune1","");
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_CCQE_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_CCRes_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_CCMEC_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_CCCoh_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_CCDIS_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_CCNue_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_NC_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_EXT_nocuts_Tune1);
  selproton2_mom_nocuts_Tune1-> Add(selproton2_mom_OffBeam_PID);
  selproton2_mom_nocuts_Tune1->SetMaximum(400.);
  selproton2_mom_nocuts_Tune1-> Draw();
  selproton2_mom_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selproton2_mom_OnBeam_PID->SetLineColor(kBlack);
  selproton2_mom_OnBeam_PID->SetMarkerStyle(20);
  selproton2_mom_OnBeam_PID->Draw("e1same");

  TLegend *l3 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l3 -> SetNColumns(2);
  l3 -> AddEntry(selproton2_mom_CCQE_nocuts_Tune1, "CC-QE", "f");
  l3 -> AddEntry(selproton2_mom_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l3 -> AddEntry(selproton2_mom_CCRes_nocuts_Tune1, "CC-Res", "f");
  l3 -> AddEntry(selproton2_mom_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l3 -> AddEntry(selproton2_mom_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l3 -> AddEntry(selproton2_mom_NC_nocuts_Tune1, "NC", "f");
  l3 -> AddEntry(selproton2_mom_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l3 -> AddEntry(selproton2_mom_EXT_nocuts_Tune1, "other", "f");
  l3 -> AddEntry(selproton2_mom_OffBeam_PID, "off-beam data", "f");
  l3 -> AddEntry(selproton2_mom_OnBeam_PID, "on-beam data", "lep");
  l3 -> Draw();

  TText *t3 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h3 = (TH1F*)selproton2_mom_OnBeam_PID->Clone("h3");
  TH1 *last3 = (TH1*)selproton2_mom_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last3, selproton2_mom_OnBeam_PID, selproton2_mom_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selproton2_mom_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h3->GetXaxis()->SetTitle("shortest proton momentum [GeV/c]");
  h3->GetXaxis()->SetTitleSize(20);
  h3->GetXaxis()->SetTitleFont(43);
  h3->GetXaxis()->SetTitleOffset(3.);
  h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h3->GetXaxis()->SetLabelSize(15);

  c3->Update();
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton2_mom_nocuts_Tune1.pdf");
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton2_mom_nocuts_Tune1.eps");
  
  TCanvas *c4 = new TCanvas("c4", "c4", 900, 900);
  TPad *pad4 = new TPad("pad4", "pad4", 0, 0.3, 1, 1.0);
  pad4->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad4->Draw();             // Draw the upper pad: pad1
  pad4->cd();              // pad1 becomes the current pad

  selmuon_costheta_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selmuon_costheta_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selmuon_costheta_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selmuon_costheta_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selmuon_costheta_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selmuon_costheta_CCNue_nocuts_Tune1-> SetFillColor(31);
  selmuon_costheta_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selmuon_costheta_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selmuon_costheta_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_costheta_nocuts_Tune1 = new THStack("selmuon_costheta_nocuts_Tune1","");
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_CCQE_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_CCRes_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_CCMEC_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_CCCoh_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_CCDIS_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_CCNue_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_NC_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_EXT_nocuts_Tune1);
  selmuon_costheta_nocuts_Tune1-> Add(selmuon_costheta_OffBeam_PID);
  ////  selmuon_costheta_nocuts_Tune1->SetMaximum(80.);
  selmuon_costheta_nocuts_Tune1-> Draw();
  selmuon_costheta_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selmuon_costheta_OnBeam_PID->SetLineColor(kBlack);
  selmuon_costheta_OnBeam_PID->SetMarkerStyle(20);
  selmuon_costheta_OnBeam_PID->Draw("e1same");

  //  TLegend *l4 = new TLegend(0.45, 0.65, 0.9, 0.9);
  TLegend *l4 = new TLegend(0.2, 0.65, 0.55, 0.9);
  l4 -> SetNColumns(2);
  l4 -> AddEntry(selmuon_costheta_CCQE_nocuts_Tune1, "CC-QE", "f");
  l4 -> AddEntry(selmuon_costheta_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l4 -> AddEntry(selmuon_costheta_CCRes_nocuts_Tune1, "CC-Res", "f");
  l4 -> AddEntry(selmuon_costheta_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l4 -> AddEntry(selmuon_costheta_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l4 -> AddEntry(selmuon_costheta_NC_nocuts_Tune1, "NC", "f");
  l4 -> AddEntry(selmuon_costheta_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l4 -> AddEntry(selmuon_costheta_EXT_nocuts_Tune1, "other", "f");
  l4 -> AddEntry(selmuon_costheta_OffBeam_PID, "off-beam data", "f");
  l4 -> AddEntry(selmuon_costheta_OnBeam_PID, "on-beam data", "lep");
  l4 -> Draw();

  TText *t4 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h4 = (TH1F*)selmuon_costheta_OnBeam_PID->Clone("h4");
  TH1 *last4 = (TH1*)selmuon_costheta_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last4, selmuon_costheta_OnBeam_PID, selmuon_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selmuon_costheta_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h4->GetXaxis()->SetTitle("cos #theta_{#mu}");
  h4->GetXaxis()->SetTitleSize(20);
  h4->GetXaxis()->SetTitleFont(43);
  h4->GetXaxis()->SetTitleOffset(3.);
  h4->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h4->GetXaxis()->SetLabelSize(15);

  c4->Update();
  c4->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selmuon_costheta_nocuts_Tune1.pdf");
  c4->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selmuon_costheta_nocuts_Tune1.eps");
  
  TCanvas *c5 = new TCanvas("c5", "c5", 900, 900);
  TPad *pad5 = new TPad("pad5", "pad5", 0, 0.3, 1, 1.0);
  pad5->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad5->Draw();             // Draw the upper pad: pad1
  pad5->cd();              // pad1 becomes the current pad

  selproton1_costheta_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selproton1_costheta_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selproton1_costheta_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selproton1_costheta_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selproton1_costheta_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selproton1_costheta_CCNue_nocuts_Tune1-> SetFillColor(31);
  selproton1_costheta_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selproton1_costheta_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selproton1_costheta_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton1_costheta_nocuts_Tune1 = new THStack("selproton1_costheta_nocuts_Tune1","");
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_CCQE_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_CCRes_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_CCMEC_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_CCCoh_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_CCDIS_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_CCNue_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_NC_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_EXT_nocuts_Tune1);
  selproton1_costheta_nocuts_Tune1-> Add(selproton1_costheta_OffBeam_PID);
  selproton1_costheta_nocuts_Tune1->SetMaximum(350.);
  selproton1_costheta_nocuts_Tune1-> Draw();
  selproton1_costheta_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selproton1_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton1_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton1_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l5 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l5 -> SetNColumns(2);
  l5 -> AddEntry(selproton1_costheta_CCQE_nocuts_Tune1, "CC-QE", "f");
  l5 -> AddEntry(selproton1_costheta_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l5 -> AddEntry(selproton1_costheta_CCRes_nocuts_Tune1, "CC-Res", "f");
  l5 -> AddEntry(selproton1_costheta_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l5 -> AddEntry(selproton1_costheta_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l5 -> AddEntry(selproton1_costheta_NC_nocuts_Tune1, "NC", "f");
  l5 -> AddEntry(selproton1_costheta_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l5 -> AddEntry(selproton1_costheta_EXT_nocuts_Tune1, "other", "f");
  l5 -> AddEntry(selproton1_costheta_OffBeam_PID, "off-beam data", "f");
  l5 -> AddEntry(selproton1_costheta_OnBeam_PID, "on-beam data", "lep");
  l5 -> Draw();

  TText *t5 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h5 = (TH1F*)selproton1_costheta_OnBeam_PID->Clone("h5");
  TH1 *last5 = (TH1*)selproton1_costheta_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last5, selproton1_costheta_OnBeam_PID, selproton1_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selproton1_costheta_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h5->GetXaxis()->SetTitle("cos #theta_{p1}");
  h5->GetXaxis()->SetTitleSize(20);
  h5->GetXaxis()->SetTitleFont(43);
  h5->GetXaxis()->SetTitleOffset(3.);
  h5->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h5->GetXaxis()->SetLabelSize(15);

  c5->Update();
  c5->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton1_costheta_nocuts_Tune1.pdf");
  c5->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton1_costheta_nocuts_Tune1.eps");
  
  TCanvas *c6 = new TCanvas("c6", "c6", 900, 900);
  TPad *pad6 = new TPad("pad6", "pad6", 0, 0.3, 1, 1.0);
  pad6->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad6->Draw();             // Draw the upper pad: pad1
  pad6->cd();              // pad1 becomes the current pad

  selproton2_costheta_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selproton2_costheta_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selproton2_costheta_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selproton2_costheta_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selproton2_costheta_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selproton2_costheta_CCNue_nocuts_Tune1-> SetFillColor(31);
  selproton2_costheta_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selproton2_costheta_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selproton2_costheta_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton2_costheta_nocuts_Tune1 = new THStack("selproton2_costheta_nocuts_Tune1","");
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_CCQE_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_CCRes_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_CCMEC_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_CCCoh_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_CCDIS_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_CCNue_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_NC_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_EXT_nocuts_Tune1);
  selproton2_costheta_nocuts_Tune1-> Add(selproton2_costheta_OffBeam_PID);
  selproton2_costheta_nocuts_Tune1->SetMaximum(200.);
  selproton2_costheta_nocuts_Tune1-> Draw();
  selproton2_costheta_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selproton2_costheta_OnBeam_PID->SetLineColor(kBlack);
  selproton2_costheta_OnBeam_PID->SetMarkerStyle(20);
  selproton2_costheta_OnBeam_PID->Draw("e1same");

  TLegend *l6 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l6 -> SetNColumns(2);
  l6 -> AddEntry(selproton2_costheta_CCQE_nocuts_Tune1, "CC-QE", "f");
  l6 -> AddEntry(selproton2_costheta_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l6 -> AddEntry(selproton2_costheta_CCRes_nocuts_Tune1, "CC-Res", "f");
  l6 -> AddEntry(selproton2_costheta_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l6 -> AddEntry(selproton2_costheta_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l6 -> AddEntry(selproton2_costheta_NC_nocuts_Tune1, "NC", "f");
  l6 -> AddEntry(selproton2_costheta_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l6 -> AddEntry(selproton2_costheta_EXT_nocuts_Tune1, "other", "f");
  l6 -> AddEntry(selproton2_costheta_OffBeam_PID, "off-beam data", "f");
  l6 -> AddEntry(selproton2_costheta_OnBeam_PID, "on-beam data", "lep");
  l6 -> Draw();

  TText *t6 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h6 = (TH1F*)selproton2_costheta_OnBeam_PID->Clone("h6");
  TH1 *last6 = (TH1*)selproton2_costheta_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last6, selproton2_costheta_OnBeam_PID, selproton2_costheta_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selproton2_costheta_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h5->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h6->GetXaxis()->SetTitle("cos #theta_{p2}");
  h6->GetXaxis()->SetTitleSize(20);
  h6->GetXaxis()->SetTitleFont(43);
  h6->GetXaxis()->SetTitleOffset(3.);
  h6->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h6->GetXaxis()->SetLabelSize(15);

  c6->Update();
  c6->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton2_costheta_nocuts_Tune1.pdf");
  c6->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton2_costheta_nocuts_Tune1.eps");
  
  TCanvas *c7 = new TCanvas("c7", "c7", 900, 900);
  TPad *pad7 = new TPad("pad7", "pad7", 0, 0.3, 1, 1.0);
  pad7->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad7->Draw();             // Draw the upper pad: pad1
  pad7->cd();              // pad1 becomes the current pad

  selmuon_phi_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selmuon_phi_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selmuon_phi_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selmuon_phi_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selmuon_phi_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selmuon_phi_CCNue_nocuts_Tune1-> SetFillColor(31);
  selmuon_phi_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selmuon_phi_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selmuon_phi_OffBeam_PID-> SetFillColor(kGray);

  THStack *selmuon_phi_nocuts_Tune1 = new THStack("selmuon_phi_nocuts_Tune1","");
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_CCQE_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_CCRes_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_CCMEC_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_CCCoh_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_CCDIS_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_CCNue_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_NC_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_EXT_nocuts_Tune1);
  selmuon_phi_nocuts_Tune1-> Add(selmuon_phi_OffBeam_PID);
  selmuon_phi_nocuts_Tune1->SetMaximum(130.);
  selmuon_phi_nocuts_Tune1-> Draw();
  selmuon_phi_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selmuon_phi_OnBeam_PID->SetLineColor(kBlack);
  selmuon_phi_OnBeam_PID->SetMarkerStyle(20);
  selmuon_phi_OnBeam_PID->Draw("e1same");

  TLegend *l7 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l7 -> SetNColumns(2);
  l7 -> AddEntry(selmuon_phi_CCQE_nocuts_Tune1, "CC-QE", "f");
  l7 -> AddEntry(selmuon_phi_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l7 -> AddEntry(selmuon_phi_CCRes_nocuts_Tune1, "CC-Res", "f");
  l7 -> AddEntry(selmuon_phi_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l7 -> AddEntry(selmuon_phi_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l7 -> AddEntry(selmuon_phi_NC_nocuts_Tune1, "NC", "f");
  l7 -> AddEntry(selmuon_phi_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l7 -> AddEntry(selmuon_phi_EXT_nocuts_Tune1, "other", "f");
  l7 -> AddEntry(selmuon_phi_OffBeam_PID, "off-beam data", "f");
  l7 -> AddEntry(selmuon_phi_OnBeam_PID, "on-beam data", "lep");
  l7 -> Draw();

  TText *t7 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h7 = (TH1F*)selmuon_phi_OnBeam_PID->Clone("h7");
  TH1 *last7 = (TH1*)selmuon_phi_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last7, selmuon_phi_OnBeam_PID, selmuon_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selmuon_phi_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h7->GetXaxis()->SetTitle("#phi_{#mu}");
  h7->GetXaxis()->SetTitleSize(20);
  h7->GetXaxis()->SetTitleFont(43);
  h7->GetXaxis()->SetTitleOffset(3.);
  h7->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h7->GetXaxis()->SetLabelSize(15);

  c7->Update();
  c7->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selmuon_phi_nocuts_Tune1.pdf");
  c7->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selmuon_phi_nocuts_Tune1.eps");
  
  TCanvas *c8 = new TCanvas("c8", "c8", 900, 900);
  TPad *pad8 = new TPad("pad8", "pad8", 0, 0.3, 1, 1.0);
  pad8->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad8->Draw();             // Draw the upper pad: pad1
  pad8->cd();              // pad1 becomes the current pad

  selproton1_phi_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selproton1_phi_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selproton1_phi_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selproton1_phi_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selproton1_phi_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selproton1_phi_CCNue_nocuts_Tune1-> SetFillColor(31);
  selproton1_phi_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selproton1_phi_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selproton1_phi_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton1_phi_nocuts_Tune1 = new THStack("selproton1_phi_nocuts_Tune1","");
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_CCQE_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_CCRes_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_CCMEC_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_CCCoh_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_CCDIS_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_CCNue_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_NC_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_EXT_nocuts_Tune1);
  selproton1_phi_nocuts_Tune1-> Add(selproton1_phi_OffBeam_PID);
  selproton1_phi_nocuts_Tune1->SetMaximum(130.);
  selproton1_phi_nocuts_Tune1-> Draw();
  selproton1_phi_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selproton1_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton1_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton1_phi_OnBeam_PID->Draw("e1same");

  TLegend *l8 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l8 -> SetNColumns(2);
  l8 -> AddEntry(selproton1_phi_CCQE_nocuts_Tune1, "CC-QE", "f");
  l8 -> AddEntry(selproton1_phi_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l8 -> AddEntry(selproton1_phi_CCRes_nocuts_Tune1, "CC-Res", "f");
  l8 -> AddEntry(selproton1_phi_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l8 -> AddEntry(selproton1_phi_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l8 -> AddEntry(selproton1_phi_NC_nocuts_Tune1, "NC", "f");
  l8 -> AddEntry(selproton1_phi_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l8 -> AddEntry(selproton1_phi_EXT_nocuts_Tune1, "other", "f");
  l8 -> AddEntry(selproton1_phi_OffBeam_PID, "off-beam data", "f");
  l8 -> AddEntry(selproton1_phi_OnBeam_PID, "on-beam data", "lep");
  l8 -> Draw();

  TText *t8 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h8 = (TH1F*)selproton1_phi_OnBeam_PID->Clone("h8");
  TH1 *last8 = (TH1*)selproton1_phi_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last8, selproton1_phi_OnBeam_PID, selproton1_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selproton1_phi_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h8->GetXaxis()->SetTitle("#phi_{p1}");
  h8->GetXaxis()->SetTitleSize(20);
  h8->GetXaxis()->SetTitleFont(43);
  h8->GetXaxis()->SetTitleOffset(3.);
  h8->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h8->GetXaxis()->SetLabelSize(15);

  c8->Update();
  c8->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton1_phi_nocuts_Tune1.pdf");  
  c8->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton1_phi_nocuts_Tune1.eps");  
  
  TCanvas *c9 = new TCanvas("c9", "c9", 900, 900);
  TPad *pad9 = new TPad("pad9", "pad9", 0, 0.3, 1, 1.0);
  pad9->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad9->Draw();             // Draw the upper pad: pad1
  pad9->cd();              // pad1 becomes the current pad

  selproton2_phi_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  selproton2_phi_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  selproton2_phi_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  selproton2_phi_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  selproton2_phi_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  selproton2_phi_CCNue_nocuts_Tune1-> SetFillColor(31);
  selproton2_phi_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  selproton2_phi_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  selproton2_phi_OffBeam_PID-> SetFillColor(kGray);

  THStack *selproton2_phi_nocuts_Tune1 = new THStack("selproton2_phi_nocuts_Tune1","");
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_CCQE_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_CCRes_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_CCMEC_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_CCCoh_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_CCDIS_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_CCNue_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_NC_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_EXT_nocuts_Tune1);
  selproton2_phi_nocuts_Tune1-> Add(selproton2_phi_OffBeam_PID);
  selproton2_phi_nocuts_Tune1->SetMaximum(130.);
  selproton2_phi_nocuts_Tune1-> Draw();
  selproton2_phi_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  selproton2_phi_OnBeam_PID->SetLineColor(kBlack);
  selproton2_phi_OnBeam_PID->SetMarkerStyle(20);
  selproton2_phi_OnBeam_PID->Draw("e1same");

  TLegend *l9 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l9 -> SetNColumns(2);
  l9 -> AddEntry(selproton2_phi_CCQE_nocuts_Tune1, "CC-QE", "f");
  l9 -> AddEntry(selproton2_phi_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l9 -> AddEntry(selproton2_phi_CCRes_nocuts_Tune1, "CC-Res", "f");
  l9 -> AddEntry(selproton2_phi_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l9 -> AddEntry(selproton2_phi_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l9 -> AddEntry(selproton2_phi_NC_nocuts_Tune1, "NC", "f");
  l9 -> AddEntry(selproton2_phi_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l9 -> AddEntry(selproton2_phi_EXT_nocuts_Tune1, "other", "f");
  l9 -> AddEntry(selproton2_phi_OffBeam_PID, "off-beam data", "f");
  l9 -> AddEntry(selproton2_phi_OnBeam_PID, "on-beam data", "lep");
  l9 -> Draw();

  TText *t9 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h9 = (TH1F*)selproton2_phi_OnBeam_PID->Clone("h9");
  TH1 *last9 = (TH1*)selproton2_phi_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last9, selproton2_phi_OnBeam_PID, selproton2_phi_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"selproton2_phi_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h9->GetXaxis()->SetTitle("#phi_{p1}");
  h9->GetXaxis()->SetTitleSize(20);
  h9->GetXaxis()->SetTitleFont(43);
  h9->GetXaxis()->SetTitleOffset(3.);
  h9->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h9->GetXaxis()->SetLabelSize(15);

  c9->Update();
  c9->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton2_phi_nocuts_Tune1.pdf");  
  c9->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/selproton2_phi_nocuts_Tune1.eps");  
  
  TCanvas *c10 = new TCanvas("c10", "c10", 900, 900);
  TPad *pad10 = new TPad("pad10", "pad10", 0, 0.3, 1, 1.0);
  pad10->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad10->Draw();             // Draw the upper pad: pad1
  pad10->cd();              // pad1 becomes the current pad

  anglep1p2LF_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  anglep1p2LF_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  anglep1p2LF_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  anglep1p2LF_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  anglep1p2LF_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  anglep1p2LF_CCNue_nocuts_Tune1-> SetFillColor(31);
  anglep1p2LF_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  anglep1p2LF_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_angle_p1p2_OffBeam_PID_LF_zoom-> SetFillColor(kGray);

  THStack *anglep1p2LF_nocuts_Tune1 = new THStack("anglep1p2LF_nocuts_Tune1","");
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_CCQE_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_CCRes_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_CCMEC_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_CCCoh_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_CCDIS_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_CCNue_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_NC_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(anglep1p2LF_EXT_nocuts_Tune1);
  anglep1p2LF_nocuts_Tune1-> Add(reco_angle_p1p2_OffBeam_PID_LF_zoom);
  ////  anglep1p2LF_nocuts_Tune1->SetMaximum(80.);
  anglep1p2LF_nocuts_Tune1-> Draw();
  anglep1p2LF_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->Draw("e1same");

  TLegend *l10 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l10 -> SetNColumns(2);
  l10 -> AddEntry(anglep1p2LF_CCQE_nocuts_Tune1, "CC-QE", "f");
  l10 -> AddEntry(anglep1p2LF_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l10 -> AddEntry(anglep1p2LF_CCRes_nocuts_Tune1, "CC-Res", "f");
  l10 -> AddEntry(anglep1p2LF_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l10 -> AddEntry(anglep1p2LF_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l10 -> AddEntry(anglep1p2LF_NC_nocuts_Tune1, "NC", "f");
  l10 -> AddEntry(anglep1p2LF_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l10 -> AddEntry(anglep1p2LF_EXT_nocuts_Tune1, "other", "f");
  l10 -> AddEntry(reco_angle_p1p2_OffBeam_PID_LF_zoom, "off-beam data", "f");
  l10 -> AddEntry(reco_angle_p1p2_OnBeam_PID_LF_zoom, "on-beam data", "lep");
  l10 -> Draw();

  TText *t10 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h10 = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF_zoom->Clone("h10");
  TH1 *last10 = (TH1*)anglep1p2LF_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last10, reco_angle_p1p2_OnBeam_PID_LF_zoom, reco_angle_p1p2_OffBeam_PID_LF_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"anglep1p2LF_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h10->GetXaxis()->SetTitle("cos #gamma_{LF}");
  h10->GetXaxis()->SetTitleSize(20);
  h10->GetXaxis()->SetTitleFont(43);
  h10->GetXaxis()->SetTitleOffset(3.);
  h10->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h10->GetXaxis()->SetLabelSize(15);

  c10->Update();
  c10->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2LF_nocuts_Tune1.pdf");  
  c10->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2LF_nocuts_Tune1.eps");  
  
  TCanvas *c11 = new TCanvas("c11", "c11", 900, 900);
  TPad *pad11 = new TPad("pad11", "pad11", 0, 0.3, 1, 1.0);
  pad11->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad11->Draw();             // Draw the upper pad: pad1
  pad11->cd();              // pad1 becomes the current pad

  anglep1p2CM_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  anglep1p2CM_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  anglep1p2CM_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  anglep1p2CM_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  anglep1p2CM_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  anglep1p2CM_CCNue_nocuts_Tune1-> SetFillColor(31);
  anglep1p2CM_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  anglep1p2CM_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_angle_p1p2_OffBeam_PID_CM_zoom-> SetFillColor(kGray);

  THStack *anglep1p2CM_nocuts_Tune1 = new THStack("anglep1p2CM_nocuts_Tune1","");
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_CCQE_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_CCRes_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_CCMEC_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_CCCoh_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_CCDIS_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_CCNue_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_NC_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(anglep1p2CM_EXT_nocuts_Tune1);
  anglep1p2CM_nocuts_Tune1-> Add(reco_angle_p1p2_OffBeam_PID_CM_zoom);
  ////  anglep1p2CM_nocuts_Tune1->SetMaximum(80.);
  anglep1p2CM_nocuts_Tune1-> Draw();
  anglep1p2CM_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->Draw("e1same");

  TLegend *l11 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l11 -> SetNColumns(2);
  l11 -> AddEntry(anglep1p2CM_CCQE_nocuts_Tune1, "CC-QE", "f");
  l11 -> AddEntry(anglep1p2CM_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l11 -> AddEntry(anglep1p2CM_CCRes_nocuts_Tune1, "CC-Res", "f");
  l11 -> AddEntry(anglep1p2CM_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l11 -> AddEntry(anglep1p2CM_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l11 -> AddEntry(anglep1p2CM_NC_nocuts_Tune1, "NC", "f");
  l11 -> AddEntry(anglep1p2CM_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l11 -> AddEntry(anglep1p2CM_EXT_nocuts_Tune1, "other", "f");
  l11 -> AddEntry(reco_angle_p1p2_OffBeam_PID_CM_zoom, "off-beam data", "f");
  l11 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM_zoom, "on-beam data", "lep");
  l11 -> Draw();

  TText *t11 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h11 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_zoom->Clone("h11");
  TH1 *last11 = (TH1*)anglep1p2CM_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last11, reco_angle_p1p2_OnBeam_PID_CM_zoom, reco_angle_p1p2_OffBeam_PID_CM_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"anglep1p2CM_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h11->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h11->GetXaxis()->SetTitleSize(20);
  h11->GetXaxis()->SetTitleFont(43);
  h11->GetXaxis()->SetTitleOffset(3.);
  h11->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h11->GetXaxis()->SetLabelSize(15);

  c11->Update();
  c11->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nocuts_Tune1.pdf");  
  c11->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nocuts_Tune1.eps");  
  
  TCanvas *c12 = new TCanvas("c12", "c12", 900, 900);
  TPad *pad12 = new TPad("pad12", "pad12", 0, 0.3, 1, 1.0);
  pad12->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad12->Draw();             // Draw the upper pad: pad1
  pad12->cd();              // pad1 becomes the current pad

  reco_Enu_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  reco_Enu_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  reco_Enu_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  reco_Enu_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  reco_Enu_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  reco_Enu_CCNue_nocuts_Tune1-> SetFillColor(31);
  reco_Enu_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  reco_Enu_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_Enu_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_Enu_nocuts_Tune1 = new THStack("reco_Enu_nocuts_Tune1","");
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_CCQE_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_CCRes_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_CCMEC_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_CCCoh_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_CCDIS_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_CCNue_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_NC_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_EXT_nocuts_Tune1);
  reco_Enu_nocuts_Tune1-> Add(reco_Enu_OffBeam_PID);
  ////  reco_Enu_nocuts_Tune1->SetMaximum(80.);
  reco_Enu_nocuts_Tune1-> Draw();
  reco_Enu_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_Enu_OnBeam_PID->SetLineColor(kBlack);
  reco_Enu_OnBeam_PID->SetMarkerStyle(20);
  reco_Enu_OnBeam_PID->Draw("e1same");

  TLegend *l12 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l12 -> SetNColumns(2);
  l12 -> AddEntry(reco_Enu_CCQE_nocuts_Tune1, "CC-QE", "f");
  l12 -> AddEntry(reco_Enu_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l12 -> AddEntry(reco_Enu_CCRes_nocuts_Tune1, "CC-Res", "f");
  l12 -> AddEntry(reco_Enu_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l12 -> AddEntry(reco_Enu_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l12 -> AddEntry(reco_Enu_NC_nocuts_Tune1, "NC", "f");
  l12 -> AddEntry(reco_Enu_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l12 -> AddEntry(reco_Enu_EXT_nocuts_Tune1, "other", "f");
  l12 -> AddEntry(reco_Enu_OffBeam_PID, "off-beam data", "f");
  l12 -> AddEntry(reco_Enu_OnBeam_PID, "on-beam data", "lep");
  l12 -> Draw();

  TText *t12 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h12 = (TH1F*)reco_Enu_OnBeam_PID->Clone("h12");
  TH1 *last12 = (TH1*)reco_Enu_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last12, reco_Enu_OnBeam_PID, reco_Enu_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_Enu_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h12->GetXaxis()->SetTitle("reconstructed #nu energy [GeV]");
  h12->GetXaxis()->SetTitleSize(20);
  h12->GetXaxis()->SetTitleFont(43);
  h12->GetXaxis()->SetTitleOffset(3.);
  h12->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h12->GetXaxis()->SetLabelSize(15);

  c12->Update();
  c12->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_Enu_nocuts_Tune1.pdf");  
  c12->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_Enu_nocuts_Tune1.eps");  
  
  TCanvas *c13 = new TCanvas("c13", "c13", 900, 900);
  TPad *pad13 = new TPad("pad13", "pad13", 0, 0.3, 1, 1.0);
  pad13->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad13->Draw();             // Draw the upper pad: pad1
  pad13->cd();              // pad1 becomes the current pad

  reco_PT_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  reco_PT_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  reco_PT_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  reco_PT_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  reco_PT_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  reco_PT_CCNue_nocuts_Tune1-> SetFillColor(31);
  reco_PT_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  reco_PT_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_PT_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_PT_nocuts_Tune1 = new THStack("reco_PT_nocuts_Tune1","");
  reco_PT_nocuts_Tune1-> Add(reco_PT_CCQE_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_CCRes_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_CCMEC_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_CCCoh_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_CCDIS_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_CCNue_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_NC_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_EXT_nocuts_Tune1);
  reco_PT_nocuts_Tune1-> Add(reco_PT_OffBeam_PID);
  ////  reco_PT_nocuts_Tune1->SetMaximum(80.);
  reco_PT_nocuts_Tune1-> Draw();
  reco_PT_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_PT_OnBeam_PID->SetLineColor(kBlack);
  reco_PT_OnBeam_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_PID->Draw("e1same");

  TLegend *l13 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l13 -> SetNColumns(2);
  l13 -> AddEntry(reco_PT_CCQE_nocuts_Tune1, "CC-QE", "f");
  l13 -> AddEntry(reco_PT_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l13 -> AddEntry(reco_PT_CCRes_nocuts_Tune1, "CC-Res", "f");
  l13 -> AddEntry(reco_PT_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l13 -> AddEntry(reco_PT_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l13 -> AddEntry(reco_PT_NC_nocuts_Tune1, "NC", "f");
  l13 -> AddEntry(reco_PT_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l13 -> AddEntry(reco_PT_EXT_nocuts_Tune1, "other", "f");
  l13 -> AddEntry(reco_PT_OffBeam_PID, "off-beam data", "f");
  l13 -> AddEntry(reco_PT_OnBeam_PID, "on-beam data", "lep");
  l13 -> Draw();

  TText *t13 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h13 = (TH1F*)reco_PT_OnBeam_PID->Clone("h13");
  TH1 *last13 = (TH1*)reco_PT_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last13, reco_PT_OnBeam_PID, reco_PT_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_PT_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h13->GetXaxis()->SetTitle("p^{T}_{miss} [GeV/c]");
  h13->GetXaxis()->SetTitleSize(20);
  h13->GetXaxis()->SetTitleFont(43);
  h13->GetXaxis()->SetTitleOffset(3.);
  h13->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h13->GetXaxis()->SetLabelSize(15);

  c13->Update();
  c13->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_PT_nocuts_Tune1.pdf");  
  c13->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_PT_nocuts_Tune1.eps");  
  
  ///// no hammer ////////////////////////////////////////

  TCanvas *c14 = new TCanvas("c14", "c14", 900, 900);
  TPad *pad14 = new TPad("pad14", "pad14", 0, 0.3, 1, 1.0);
  pad14->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad14->Draw();             // Draw the upper pad: pad1
  pad14->cd();              // pad1 becomes the current pad

  anglep1p2CM_CCQE_nobtb_Tune1-> SetFillColor(kRed -10);
  anglep1p2CM_CCRes_nobtb_Tune1-> SetFillColor(kGreen-8);
  anglep1p2CM_CCMEC_nobtb_Tune1-> SetFillColor(kAzure-4);
  anglep1p2CM_CCCoh_nobtb_Tune1-> SetFillColor(kYellow+2);
  anglep1p2CM_CCDIS_nobtb_Tune1-> SetFillColor(kOrange);
  anglep1p2CM_CCNue_nobtb_Tune1-> SetFillColor(31);
  anglep1p2CM_NC_nobtb_Tune1-> SetFillColor(kMagenta-8);
  anglep1p2CM_EXT_nobtb_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom-> SetFillColor(kGray);

  THStack *anglep1p2CM_nobtb_Tune1 = new THStack("anglep1p2CM_nobtb_Tune1","");
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_CCQE_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_CCRes_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_CCMEC_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_CCCoh_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_CCDIS_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_CCNue_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_NC_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(anglep1p2CM_EXT_nobtb_Tune1);
  anglep1p2CM_nobtb_Tune1-> Add(reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom);
  ////  anglep1p2CM_nobtb_Tune1->SetMaximum(80.);
  anglep1p2CM_nobtb_Tune1-> Draw();
  anglep1p2CM_nobtb_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->Draw("e1same");

  TLegend *l14 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l14 -> SetNColumns(2);
  l14 -> AddEntry(anglep1p2CM_CCQE_nobtb_Tune1, "CC-QE", "f");
  l14 -> AddEntry(anglep1p2CM_CCDIS_nobtb_Tune1, "CC-DIS", "f");
  l14 -> AddEntry(anglep1p2CM_CCRes_nobtb_Tune1, "CC-Res", "f");
  l14 -> AddEntry(anglep1p2CM_CCNue_nobtb_Tune1, "#nu_{e}-CC", "f");
  l14 -> AddEntry(anglep1p2CM_CCMEC_nobtb_Tune1, "CC-MEC", "f");
  l14 -> AddEntry(anglep1p2CM_NC_nobtb_Tune1, "NC", "f");
  l14 -> AddEntry(anglep1p2CM_CCCoh_nobtb_Tune1, "CC-Coh", "f");
  l14 -> AddEntry(anglep1p2CM_EXT_nobtb_Tune1, "other", "f");
  l14 -> AddEntry(reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom, "off-beam data", "f");
  l14 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom, "on-beam data", "lep");
  l14 -> Draw();

  TText *t14 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h14 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom->Clone("h14");
  TH1 *last14 = (TH1*)anglep1p2CM_nobtb_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last14, reco_angle_p1p2_OnBeam_nobtbLF_PID_CM_zoom, reco_angle_p1p2_OffBeam_nobtbLF_PID_CM_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"anglep1p2CM_nobtb_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h14->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h14->GetXaxis()->SetTitleSize(20);
  h14->GetXaxis()->SetTitleFont(43);
  h14->GetXaxis()->SetTitleOffset(3.);
  h14->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h14->GetXaxis()->SetLabelSize(15);

  c14->Update();
  c14->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtb_Tune1.pdf");  
  c14->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtb_Tune1.eps");  
  
  TCanvas *c15 = new TCanvas("c15", "c15", 900, 900);
  TPad *pad15 = new TPad("pad15", "pad15", 0, 0.3, 1, 1.0);
  pad15->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad15->Draw();             // Draw the upper pad: pad1
  pad15->cd();              // pad1 becomes the current pad

  reco_PT_CCQE_nobtb_Tune1-> SetFillColor(kRed -10);
  reco_PT_CCRes_nobtb_Tune1-> SetFillColor(kGreen-8);
  reco_PT_CCMEC_nobtb_Tune1-> SetFillColor(kAzure-4);
  reco_PT_CCCoh_nobtb_Tune1-> SetFillColor(kYellow+2);
  reco_PT_CCDIS_nobtb_Tune1-> SetFillColor(kOrange);
  reco_PT_CCNue_nobtb_Tune1-> SetFillColor(31);
  reco_PT_NC_nobtb_Tune1-> SetFillColor(kMagenta-8);
  reco_PT_EXT_nobtb_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_PT_OffBeam_nobtbLF_PID-> SetFillColor(kGray);

  THStack *reco_PT_nobtb_Tune1 = new THStack("reco_PT_nobtb_Tune1","");
  reco_PT_nobtb_Tune1-> Add(reco_PT_CCQE_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_CCRes_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_CCMEC_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_CCCoh_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_CCDIS_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_CCNue_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_NC_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_EXT_nobtb_Tune1);
  reco_PT_nobtb_Tune1-> Add(reco_PT_OffBeam_nobtbLF_PID);
  ////  reco_PT_nobtb_Tune1->SetMaximum(80.);
  reco_PT_nobtb_Tune1-> Draw();
  reco_PT_nobtb_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_PT_OnBeam_nobtbLF_PID->SetLineColor(kBlack);
  reco_PT_OnBeam_nobtbLF_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_nobtbLF_PID->Draw("e1same");

  TLegend *l15 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l15 -> SetNColumns(2);
  l15 -> AddEntry(reco_PT_CCQE_nobtb_Tune1, "CC-QE", "f");
  l15 -> AddEntry(reco_PT_CCDIS_nobtb_Tune1, "CC-DIS", "f");
  l15 -> AddEntry(reco_PT_CCRes_nobtb_Tune1, "CC-Res", "f");
  l15 -> AddEntry(reco_PT_CCNue_nobtb_Tune1, "#nu_{e}-CC", "f");
  l15 -> AddEntry(reco_PT_CCMEC_nobtb_Tune1, "CC-MEC", "f");
  l15 -> AddEntry(reco_PT_NC_nobtb_Tune1, "NC", "f");
  l15 -> AddEntry(reco_PT_CCCoh_nobtb_Tune1, "CC-Coh", "f");
  l15 -> AddEntry(reco_PT_EXT_nobtb_Tune1, "other", "f");
  l15 -> AddEntry(reco_PT_OffBeam_nobtbLF_PID, "off-beam data", "f");
  l15 -> AddEntry(reco_PT_OnBeam_nobtbLF_PID, "on-beam data", "lep");
  l15 -> Draw();

  TText *t15 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h15 = (TH1F*)reco_PT_OnBeam_nobtbLF_PID->Clone("h15");
  TH1 *last15 = (TH1*)reco_PT_nobtb_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last15, reco_PT_OnBeam_nobtbLF_PID, reco_PT_OffBeam_nobtbLF_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_PT_nobtb_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h15->GetXaxis()->SetTitle("p^{T}_{miss} [GeV/c]");
  h15->GetXaxis()->SetTitleSize(20);
  h15->GetXaxis()->SetTitleFont(43);
  h15->GetXaxis()->SetTitleOffset(3.);
  h15->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h15->GetXaxis()->SetLabelSize(15);

  c15->Update();
  c15->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_PT_nobtb_Tune1.pdf");
  c15->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_PT_nobtb_Tune1.eps");
  
  TCanvas *c16 = new TCanvas("c16", "c16", 900, 900);
  TPad *pad16 = new TPad("pad16", "pad16", 0, 0.3, 1, 1.0);
  pad16->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad16->Draw();             // Draw the upper pad: pad1
  pad16->cd();              // pad1 becomes the current pad

  reco_pn_CCQE_nobtb_Tune1-> SetFillColor(kRed -10);
  reco_pn_CCRes_nobtb_Tune1-> SetFillColor(kGreen-8);
  reco_pn_CCMEC_nobtb_Tune1-> SetFillColor(kAzure-4);
  reco_pn_CCCoh_nobtb_Tune1-> SetFillColor(kYellow+2);
  reco_pn_CCDIS_nobtb_Tune1-> SetFillColor(kOrange);
  reco_pn_CCNue_nobtb_Tune1-> SetFillColor(31);
  reco_pn_NC_nobtb_Tune1-> SetFillColor(kMagenta-8);
  reco_pn_EXT_nobtb_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_pn_OffBeam_nobtbLF_PID-> SetFillColor(kGray);

  THStack *reco_pn_nobtb_Tune1 = new THStack("reco_pn_nobtb_Tune1","");
  reco_pn_nobtb_Tune1-> Add(reco_pn_CCQE_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_CCRes_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_CCMEC_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_CCCoh_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_CCDIS_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_CCNue_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_NC_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_EXT_nobtb_Tune1);
  reco_pn_nobtb_Tune1-> Add(reco_pn_OffBeam_nobtbLF_PID);
  ////  reco_pn_nobtb_Tune1->SetMaximum(80.);
  reco_pn_nobtb_Tune1-> Draw();
  reco_pn_nobtb_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_pn_OnBeam_nobtbLF_PID->SetLineColor(kBlack);
  reco_pn_OnBeam_nobtbLF_PID->SetMarkerStyle(20);
  reco_pn_OnBeam_nobtbLF_PID->Draw("e1same");

  TLegend *l16 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l16 -> SetNColumns(2);
  l16 -> AddEntry(reco_pn_CCQE_nobtb_Tune1, "CC-QE", "f");
  l16 -> AddEntry(reco_pn_CCDIS_nobtb_Tune1, "CC-DIS", "f");
  l16 -> AddEntry(reco_pn_CCRes_nobtb_Tune1, "CC-Res", "f");
  l16 -> AddEntry(reco_pn_CCNue_nobtb_Tune1, "#nu_{e}-CC", "f");
  l16 -> AddEntry(reco_pn_CCMEC_nobtb_Tune1, "CC-MEC", "f");
  l16 -> AddEntry(reco_pn_NC_nobtb_Tune1, "NC", "f");
  l16 -> AddEntry(reco_pn_CCCoh_nobtb_Tune1, "CC-Coh", "f");
  l16 -> AddEntry(reco_pn_EXT_nobtb_Tune1, "other", "f");
  l16 -> AddEntry(reco_pn_OffBeam_nobtbLF_PID, "off-beam data", "f");
  l16 -> AddEntry(reco_pn_OnBeam_nobtbLF_PID, "on-beam data", "lep");
  l16 -> Draw();

  TText *t16 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h16 = (TH1F*)reco_pn_OnBeam_nobtbLF_PID->Clone("h16");
  TH1 *last16 = (TH1*)reco_pn_nobtb_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last16, reco_pn_OnBeam_nobtbLF_PID, reco_pn_OffBeam_nobtbLF_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_pn_nobtb_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h16->GetXaxis()->SetTitle("reconstructed initial struck nucleon p_{n} [GeV/c]");
  h16->GetXaxis()->SetTitleSize(20);
  h16->GetXaxis()->SetTitleFont(43);
  h16->GetXaxis()->SetTitleOffset(3.);
  h16->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h16->GetXaxis()->SetLabelSize(15);

  c16->Update();
  c16->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_pn_nobtb_Tune1.pdf");
  c16->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_pn_nobtb_Tune1.eps");
  
  ///////////////no hammer, low PT

  TCanvas *c17 = new TCanvas("c17", "c17", 900, 900);
  TPad *pad17 = new TPad("pad17", "pad17", 0, 0.3, 1, 1.0);
  pad17->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad17->Draw();             // Draw the upper pad: pad1
  pad17->cd();              // pad1 becomes the current pad

  anglep1p2CM_CCQE_nobtblowPT_Tune1-> SetFillColor(kRed -10);
  anglep1p2CM_CCRes_nobtblowPT_Tune1-> SetFillColor(kGreen-8);
  anglep1p2CM_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  anglep1p2CM_CCCoh_nobtblowPT_Tune1-> SetFillColor(kYellow+2);
  anglep1p2CM_CCDIS_nobtblowPT_Tune1-> SetFillColor(kOrange);
  anglep1p2CM_CCNue_nobtblowPT_Tune1-> SetFillColor(31);
  anglep1p2CM_NC_nobtblowPT_Tune1-> SetFillColor(kMagenta-8);
  anglep1p2CM_EXT_nobtblowPT_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom-> SetFillColor(kGray);

  THStack *anglep1p2CM_nobtblowPT_Tune1 = new THStack("anglep1p2CM_nobtblowPT_Tune1","");
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_CCQE_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_CCRes_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_CCMEC_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_CCCoh_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_CCDIS_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_CCNue_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_NC_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(anglep1p2CM_EXT_nobtblowPT_Tune1);
  anglep1p2CM_nobtblowPT_Tune1-> Add(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom);
  ////  anglep1p2CM_nobtblowPT_Tune1->SetMaximum(80.);
  anglep1p2CM_nobtblowPT_Tune1-> Draw();
  anglep1p2CM_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Draw("e1same");

  TLegend *l17 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l17 -> SetNColumns(2);
  l17 -> AddEntry(anglep1p2CM_CCQE_nobtblowPT_Tune1, "CC-QE", "f");
  l17 -> AddEntry(anglep1p2CM_CCDIS_nobtblowPT_Tune1, "CC-DIS", "f");
  l17 -> AddEntry(anglep1p2CM_CCRes_nobtblowPT_Tune1, "CC-Res", "f");
  l17 -> AddEntry(anglep1p2CM_CCNue_nobtblowPT_Tune1, "#nu_{e}-CC", "f");
  l17 -> AddEntry(anglep1p2CM_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l17 -> AddEntry(anglep1p2CM_NC_nobtblowPT_Tune1, "NC", "f");
  l17 -> AddEntry(anglep1p2CM_CCCoh_nobtblowPT_Tune1, "CC-Coh", "f");
  l17 -> AddEntry(anglep1p2CM_EXT_nobtblowPT_Tune1, "other", "f");
  l17 -> AddEntry(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom, "off-beam data", "f");
  l17 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom, "on-beam data", "lep");
  l17 -> Draw();

  TText *t17 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h17 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Clone("h17");
  TH1 *last17 = (TH1*)anglep1p2CM_nobtblowPT_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last17, reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom, reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_zoom, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"anglep1p2CM_nobtblowPT_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h17->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h17->GetXaxis()->SetTitleSize(20);
  h17->GetXaxis()->SetTitleFont(43);
  h17->GetXaxis()->SetTitleOffset(3.);
  h17->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h17->GetXaxis()->SetLabelSize(15);

  c17->Update();
  c17->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtblowPT_Tune1.pdf");  
  c17->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtblowPT_Tune1.eps");  
  
  TCanvas *c18 = new TCanvas("c18", "c18", 900, 900);
  TPad *pad18 = new TPad("pad18", "pad18", 0, 0.3, 1, 1.0);
  pad18->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad18->Draw();             // Draw the upper pad: pad1
  pad18->cd();              // pad1 becomes the current pad

  reco_Enu_CCQE_nobtblowPT_Tune1-> SetFillColor(kRed -10);
  reco_Enu_CCRes_nobtblowPT_Tune1-> SetFillColor(kGreen-8);
  reco_Enu_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  reco_Enu_CCCoh_nobtblowPT_Tune1-> SetFillColor(kYellow+2);
  reco_Enu_CCDIS_nobtblowPT_Tune1-> SetFillColor(kOrange);
  reco_Enu_CCNue_nobtblowPT_Tune1-> SetFillColor(31);
  reco_Enu_NC_nobtblowPT_Tune1-> SetFillColor(kMagenta-8);
  reco_Enu_EXT_nobtblowPT_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_Enu_OffBeam_nobtbLF_PT_PID-> SetFillColor(kGray);

  THStack *reco_Enu_nobtblowPT_Tune1 = new THStack("reco_Enu_nobtblowPT_Tune1","");
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_CCQE_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_CCRes_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_CCMEC_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_CCCoh_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_CCDIS_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_CCNue_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_NC_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_EXT_nobtblowPT_Tune1);
  reco_Enu_nobtblowPT_Tune1-> Add(reco_Enu_OffBeam_nobtbLF_PT_PID);
  ////  reco_Enu_nobtblowPT_Tune1->SetMaximum(80.);
  reco_Enu_nobtblowPT_Tune1-> Draw();
  reco_Enu_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_Enu_OnBeam_nobtbLF_PT_PID->SetLineColor(kBlack);
  reco_Enu_OnBeam_nobtbLF_PT_PID->SetMarkerStyle(20);
  reco_Enu_OnBeam_nobtbLF_PT_PID->Draw("e1same");

  TLegend *l18 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l18 -> SetNColumns(2);
  l18 -> AddEntry(reco_Enu_CCQE_nobtblowPT_Tune1, "CC-QE", "f");
  l18 -> AddEntry(reco_Enu_CCDIS_nobtblowPT_Tune1, "CC-DIS", "f");
  l18 -> AddEntry(reco_Enu_CCRes_nobtblowPT_Tune1, "CC-Res", "f");
  l18 -> AddEntry(reco_Enu_CCNue_nobtblowPT_Tune1, "#nu_{e}-CC", "f");
  l18 -> AddEntry(reco_Enu_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l18 -> AddEntry(reco_Enu_NC_nobtblowPT_Tune1, "NC", "f");
  l18 -> AddEntry(reco_Enu_CCCoh_nobtblowPT_Tune1, "CC-Coh", "f");
  l18 -> AddEntry(reco_Enu_EXT_nobtblowPT_Tune1, "other", "f");
  l18 -> AddEntry(reco_Enu_OffBeam_nobtbLF_PT_PID, "off-beam data", "f");
  l18 -> AddEntry(reco_Enu_OnBeam_nobtbLF_PT_PID, "on-beam data", "lep");
  l18 -> Draw();

  TText *t18 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h18 = (TH1F*)reco_Enu_OnBeam_nobtbLF_PT_PID->Clone("h18");
  TH1 *last18 = (TH1*)reco_Enu_nobtblowPT_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last18, reco_Enu_OnBeam_nobtbLF_PT_PID,reco_Enu_OffBeam_nobtbLF_PT_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_Enu_nobtblowPT_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h18->GetXaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  h18->GetXaxis()->SetTitleSize(20);
  h18->GetXaxis()->SetTitleFont(43);
  h18->GetXaxis()->SetTitleOffset(3.);
  h18->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h18->GetXaxis()->SetLabelSize(15);

  c18->Update();
  c18->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_Enu_nobtblowPT_Tune1.pdf");  
  c18->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_Enu_nobtblowPT_Tune1.eps");  
  
  TCanvas *c19 = new TCanvas("c19", "c19", 900, 900);
  TPad *pad19 = new TPad("pad19", "pad19", 0, 0.3, 1, 1.0);
  pad19->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad19->Draw();             // Draw the upper pad: pad1
  pad19->cd();              // pad1 becomes the current pad

  reco_pn_CCQE_nobtblowPT_Tune1-> SetFillColor(kRed -10);
  reco_pn_CCRes_nobtblowPT_Tune1-> SetFillColor(kGreen-8);
  reco_pn_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  reco_pn_CCCoh_nobtblowPT_Tune1-> SetFillColor(kYellow+2);
  reco_pn_CCDIS_nobtblowPT_Tune1-> SetFillColor(kOrange);
  reco_pn_CCNue_nobtblowPT_Tune1-> SetFillColor(31);
  reco_pn_NC_nobtblowPT_Tune1-> SetFillColor(kMagenta-8);
  reco_pn_EXT_nobtblowPT_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_pn_OffBeam_nobtbLF_PT_PID-> SetFillColor(kGray);

  THStack *reco_pn_nobtblowPT_Tune1 = new THStack("reco_pn_nobtblowPT_Tune1","");
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_CCQE_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_CCRes_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_CCMEC_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_CCCoh_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_CCDIS_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_CCNue_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_NC_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_EXT_nobtblowPT_Tune1);
  reco_pn_nobtblowPT_Tune1-> Add(reco_pn_OffBeam_nobtbLF_PT_PID);
  ////  reco_pn_nobtblowPT_Tune1->SetMaximum(80.);
  reco_pn_nobtblowPT_Tune1-> Draw();  
  reco_pn_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_pn_OnBeam_nobtbLF_PT_PID->SetLineColor(kBlack);
  reco_pn_OnBeam_nobtbLF_PT_PID->SetMarkerStyle(20);
  reco_pn_OnBeam_nobtbLF_PT_PID->Draw("e1same");

  TLegend *l19 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l19 -> SetNColumns(2);
  l19 -> AddEntry(reco_pn_CCQE_nobtblowPT_Tune1, "CC-QE", "f");
  l19 -> AddEntry(reco_pn_CCDIS_nobtblowPT_Tune1, "CC-DIS", "f");
  l19 -> AddEntry(reco_pn_CCRes_nobtblowPT_Tune1, "CC-Res", "f");
  l19 -> AddEntry(reco_pn_CCNue_nobtblowPT_Tune1, "#nu_{e}-CC", "f");
  l19 -> AddEntry(reco_pn_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l19 -> AddEntry(reco_pn_NC_nobtblowPT_Tune1, "NC", "f");
  l19 -> AddEntry(reco_pn_CCCoh_nobtblowPT_Tune1, "CC-Coh", "f");
  l19 -> AddEntry(reco_pn_EXT_nobtblowPT_Tune1, "other", "f");
  l19 -> AddEntry(reco_pn_OffBeam_nobtbLF_PT_PID, "off-beam data", "f");
  l19 -> AddEntry(reco_pn_OnBeam_nobtbLF_PT_PID, "on-beam data", "lep");
  l19 -> Draw();

  TText *t19 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h19 = (TH1F*)reco_pn_OnBeam_nobtbLF_PT_PID->Clone("h19");
  TH1 *last19 = (TH1*)reco_pn_nobtblowPT_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last19, reco_pn_OnBeam_nobtbLF_PT_PID,reco_pn_OffBeam_nobtbLF_PT_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_pn_nobtblowPT_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h19->GetXaxis()->SetTitle("initial struck nucleon p_{n} [GeV]");
  h19->GetXaxis()->SetTitleSize(20);
  h19->GetXaxis()->SetTitleFont(43);
  h19->GetXaxis()->SetTitleOffset(3.);
  h19->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h19->GetXaxis()->SetLabelSize(15);

  c19->Update();
  c19->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_pn_nobtblowPT_Tune1.pdf");  
  c19->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_pn_nobtblowPT_Tune1.eps");  
  
  TCanvas *c20 = new TCanvas("c20", "c20", 900, 900);
  TPad *pad20 = new TPad("pad20", "pad20", 0, 0.3, 1, 1.0);
  pad20->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad20->Draw();             // Draw the upper pad: pad1
  pad20->cd();              // pad1 becomes the current pad

  reco_totpnp2_CCQE_nobtblowPT_Tune1-> SetFillColor(kRed -10);
  reco_totpnp2_CCRes_nobtblowPT_Tune1-> SetFillColor(kGreen-8);
  reco_totpnp2_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  reco_totpnp2_CCCoh_nobtblowPT_Tune1-> SetFillColor(kYellow+2);
  reco_totpnp2_CCDIS_nobtblowPT_Tune1-> SetFillColor(kOrange);
  reco_totpnp2_CCNue_nobtblowPT_Tune1-> SetFillColor(31);
  reco_totpnp2_NC_nobtblowPT_Tune1-> SetFillColor(kMagenta-8);
  reco_totpnp2_EXT_nobtblowPT_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_projptot_OffBeam_nobtb_lowPT-> SetFillColor(kGray);

  THStack *reco_totpnp2_nobtblowPT_Tune1 = new THStack("reco_totpnp2_nobtblowPT_Tune1","");
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_CCQE_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_CCRes_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_CCMEC_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_CCCoh_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_CCDIS_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_CCNue_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_NC_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_totpnp2_EXT_nobtblowPT_Tune1);
  reco_totpnp2_nobtblowPT_Tune1-> Add(reco_projptot_OffBeam_nobtb_lowPT);
  ////  reco_totpnp2_nobtblowPT_Tune1->SetMaximum(80.);
  reco_totpnp2_nobtblowPT_Tune1-> Draw();
  reco_totpnp2_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_projptot_OnBeam_nobtb_lowPT->SetLineColor(kBlack);
  reco_projptot_OnBeam_nobtb_lowPT->SetMarkerStyle(20);
  reco_projptot_OnBeam_nobtb_lowPT->Draw("e1same");

  TLegend *l20 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l20 -> SetNColumns(2);
  l20 -> AddEntry(reco_totpnp2_CCQE_nobtblowPT_Tune1, "CC-QE", "f");
  l20 -> AddEntry(reco_totpnp2_CCDIS_nobtblowPT_Tune1, "CC-DIS", "f");
  l20 -> AddEntry(reco_totpnp2_CCRes_nobtblowPT_Tune1, "CC-Res", "f");
  l20 -> AddEntry(reco_totpnp2_CCNue_nobtblowPT_Tune1, "#nu_{e}-CC", "f");
  l20 -> AddEntry(reco_totpnp2_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l20 -> AddEntry(reco_totpnp2_NC_nobtblowPT_Tune1, "NC", "f");
  l20 -> AddEntry(reco_totpnp2_CCCoh_nobtblowPT_Tune1, "CC-Coh", "f");
  l20 -> AddEntry(reco_totpnp2_EXT_nobtblowPT_Tune1, "other", "f");
  l20 -> AddEntry(reco_projptot_OffBeam_nobtb_lowPT, "off-beam data", "f");
  l20 -> AddEntry(reco_projptot_OnBeam_nobtb_lowPT, "on-beam data", "lep");
  l20 -> Draw();

  TText *t20 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h20 = (TH1F*)reco_projptot_OnBeam_nobtb_lowPT->Clone("h20");
  TH1 *last20 = (TH1*)reco_totpnp2_nobtblowPT_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last20, reco_projptot_OnBeam_nobtb_lowPT, reco_projptot_OffBeam_nobtb_lowPT, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_totpnp2_nobtblowPT_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h20->GetXaxis()->SetTitle("initial struck nucleon p_{n} [GeV]");
  h20->GetXaxis()->SetTitleSize(20);
  h20->GetXaxis()->SetTitleFont(43);
  h20->GetXaxis()->SetTitleOffset(3.);
  h20->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h20->GetXaxis()->SetLabelSize(15);

  c20->Update();
  c20->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_totpnp2_nobtblowPT_Tune1.pdf");  
  c20->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_totpnp2_nobtblowPT_Tune1.eps");  
  
  TCanvas *c21 = new TCanvas("c21", "c21", 900, 900);
  TPad *pad21 = new TPad("pad21", "pad21", 0, 0.3, 1, 1.0);
  pad21->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad21->Draw();             // Draw the upper pad: pad1
  pad21->cd();              // pad1 becomes the current pad

  reco_relpnp2_CCQE_nobtblowPT_Tune1-> SetFillColor(kRed -10);
  reco_relpnp2_CCRes_nobtblowPT_Tune1-> SetFillColor(kGreen-8);
  reco_relpnp2_CCMEC_nobtblowPT_Tune1-> SetFillColor(kAzure-4);
  reco_relpnp2_CCCoh_nobtblowPT_Tune1-> SetFillColor(kYellow+2);
  reco_relpnp2_CCDIS_nobtblowPT_Tune1-> SetFillColor(kOrange);
  reco_relpnp2_CCNue_nobtblowPT_Tune1-> SetFillColor(31);
  reco_relpnp2_NC_nobtblowPT_Tune1-> SetFillColor(kMagenta-8);
  reco_relpnp2_EXT_nobtblowPT_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_projprel_OffBeam_nobtb_lowPT-> SetFillColor(kGray);

  THStack *reco_relpnp2_nobtblowPT_Tune1 = new THStack("reco_relpnp2_nobtblowPT_Tune1","");
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_CCQE_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_CCRes_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_CCMEC_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_CCCoh_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_CCDIS_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_CCNue_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_NC_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_relpnp2_EXT_nobtblowPT_Tune1);
  reco_relpnp2_nobtblowPT_Tune1-> Add(reco_projprel_OffBeam_nobtb_lowPT);
  ////  reco_relpnp2_nobtblowPT_Tune1->SetMaximum(80.);
  reco_relpnp2_nobtblowPT_Tune1-> Draw();
  reco_relpnp2_nobtblowPT_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_projprel_OnBeam_nobtb_lowPT->SetLineColor(kBlack);
  reco_projprel_OnBeam_nobtb_lowPT->SetMarkerStyle(20);
  reco_projprel_OnBeam_nobtb_lowPT->Draw("e1same");

  TLegend *l21 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l21 -> SetNColumns(2);
  l21 -> AddEntry(reco_relpnp2_CCQE_nobtblowPT_Tune1, "CC-QE", "f");
  l21 -> AddEntry(reco_relpnp2_CCDIS_nobtblowPT_Tune1, "CC-DIS", "f");
  l21 -> AddEntry(reco_relpnp2_CCRes_nobtblowPT_Tune1, "CC-Res", "f");
  l21 -> AddEntry(reco_relpnp2_CCNue_nobtblowPT_Tune1, "#nu_{e}-CC", "f");
  l21 -> AddEntry(reco_relpnp2_CCMEC_nobtblowPT_Tune1, "CC-MEC", "f");
  l21 -> AddEntry(reco_relpnp2_NC_nobtblowPT_Tune1, "NC", "f");
  l21 -> AddEntry(reco_relpnp2_CCCoh_nobtblowPT_Tune1, "CC-Coh", "f");
  l21 -> AddEntry(reco_relpnp2_EXT_nobtblowPT_Tune1, "other", "f");
  l21 -> AddEntry(reco_projprel_OffBeam_nobtb_lowPT, "off-beam data", "f");
  l21 -> AddEntry(reco_projprel_OnBeam_nobtb_lowPT, "on-beam data", "lep");
  l21 -> Draw();

  TText *t21 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h21 = (TH1F*)reco_projprel_OnBeam_nobtb_lowPT->Clone("h21");
  TH1 *last21 = (TH1*)reco_relpnp2_nobtblowPT_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last21, reco_projprel_OnBeam_nobtb_lowPT, reco_projprel_OffBeam_nobtb_lowPT, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_relpnp2_nobtblowPT_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h21->SetLineColor(kBlack);
  h21->Sumw2();
  h21->SetStats(0);      // No statistics on lower plot
  h21->Divide(last20);
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
  h21->GetXaxis()->SetTitle("initial struck nucleon p_{n} [GeV]");
  h21->GetXaxis()->SetTitleSize(20);
  h21->GetXaxis()->SetTitleFont(43);
  h21->GetXaxis()->SetTitleOffset(3.);
  h21->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h21->GetXaxis()->SetLabelSize(15);

  c21->Update();
  c21->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_relpnp2_nobtblowPT_Tune1.pdf");  
  c21->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_relpnp2_nobtblowPT_Tune1.eps");

  //////////////////// ratio plot
 
  TCanvas *ctest = new TCanvas("ctest", "ctest", 900, 900);
  TPad *padtest = new TPad("padtest", "padtest", 0, 0.3, 1, 1.0);
  padtest->SetBottomMargin(0.01); // Upper and lower plot are joined
  padtest->Draw();             // Draw the upper pad: pad1
  padtest->cd();              // pad1 becomes the current pad

  anglep1p2CM_CCQE_nobtblowPT_rebin_Tune1-> SetFillColor(kRed -10);
  anglep1p2CM_CCRes_nobtblowPT_rebin_Tune1-> SetFillColor(kGreen-8);
  anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune1-> SetFillColor(kAzure-4);
  anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune1-> SetFillColor(kYellow+2);
  anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune1-> SetFillColor(kOrange);
  anglep1p2CM_CCNue_nobtblowPT_rebin_Tune1-> SetFillColor(31);
  anglep1p2CM_NC_nobtblowPT_rebin_Tune1-> SetFillColor(kMagenta-8);
  anglep1p2CM_EXT_nobtblowPT_rebin_Tune1-> SetFillColor(kBlack);
  reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin-> SetFillColor(kGray);
  
  THStack *anglep1p2CM_nobtblowPT_Tune1test = new THStack("anglep1p2CM_nobtblowPT_Tune1test","");
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_CCQE_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_CCRes_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_CCNue_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_NC_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(anglep1p2CM_EXT_nobtblowPT_rebin_Tune1);
  anglep1p2CM_nobtblowPT_Tune1test-> Add(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin);
  ////  anglep1p2CM_nobtblowPT_Tune1->SetMaximum(80.);
  anglep1p2CM_nobtblowPT_Tune1test-> Draw();
  anglep1p2CM_nobtblowPT_Tune1test->GetYaxis()->SetTitle("No. of Entries");
 
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Draw("e1same");

  TLegend *ltest = new TLegend(0.45, 0.65, 0.9, 0.9);
  ltest -> SetNColumns(2);
  ltest -> AddEntry(anglep1p2CM_CCQE_nobtblowPT_rebin_Tune1, "CC-QE", "f");
  ltest -> AddEntry(anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune1, "CC-DIS", "f");
  ltest -> AddEntry(anglep1p2CM_CCRes_nobtblowPT_rebin_Tune1, "CC-Res", "f");
  ltest -> AddEntry(anglep1p2CM_CCNue_nobtblowPT_rebin_Tune1, "#nu_{e}-CC", "f");
  ltest -> AddEntry(anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune1, "CC-MEC", "f");
  ltest -> AddEntry(anglep1p2CM_NC_nobtblowPT_rebin_Tune1, "NC", "f");
  ltest -> AddEntry(anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune1, "CC-Coh", "f");
  ltest -> AddEntry(anglep1p2CM_EXT_nobtblowPT_rebin_Tune1, "other", "f");
  ltest -> AddEntry(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin, "off-beam data", "f");
  ltest -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin, "on-beam data", "lep");
  ltest -> Draw();
    
  TText *ttest = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
  ttest->Draw();
  
  ctest->cd();
  TPad *padtest_2 = new TPad("padtest_2", "padtest_2", 0, 0.05, 1, 0.3);
  padtest_2->SetTopMargin(0.01);
  padtest_2->SetBottomMargin(0.2);
  padtest_2->SetGridx();
  padtest_2->SetGridy();
  padtest_2->Draw();
  padtest_2->cd();
  // Define the ratio plot
  TH1F *htest = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Clone("htest");
  TH1 *lasttest = (TH1*)anglep1p2CM_nobtblowPT_Tune1test->GetStack()->Last();
   
  chi2test = Chi2Calc(lasttest, reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin, reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"anglep1p2CM_nobtblowPT_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;
  
  htest->SetLineColor(kBlack);
  htest->Sumw2();
  htest->SetStats(0);      // No statistics on lower plot
  htest->Divide(lasttest);
  htest->SetMarkerStyle(21);
  htest->SetTitle("");
  htest->Draw("ep");       // Draw the ratio plot

  htest->GetYaxis()->SetTitle("Data/MC");
  htest->GetYaxis()->SetNdivisions(505);
  htest->GetYaxis()->SetTitleSize(20);
  htest->GetYaxis()->SetTitleFont(43);
  htest->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  htest->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  htest->GetXaxis()->SetTitle("cos #gamma_{CM}");
  htest->GetXaxis()->SetTitleSize(20);
  htest->GetXaxis()->SetTitleFont(43);
  htest->GetXaxis()->SetTitleOffset(3.);
  htest->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  htest->GetXaxis()->SetLabelSize(15);

  ctest->Update();
  ctest->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtblowPT_Tune1_rebin.pdf");  
  ctest->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtblowPT_Tune1_rebin.eps");  

  /////////////////
  TCanvas *ctune = new TCanvas("ctune", "ctune", 900, 900);
  TPad *padtune = new TPad("padtune", "padtune", 0, 0.3, 1, 1.0);
  padtune->SetBottomMargin(0.01); // Upper and lower plot are joined
  padtune->Draw();             // Draw the upper pad: pad1
  padtune->cd();              // pad1 becomes the current pad

  anglep1p2CM_CCQE_nobtblowPT_rebin_Tune3-> SetFillColor(kRed -10);
  anglep1p2CM_CCRes_nobtblowPT_rebin_Tune3-> SetFillColor(kGreen-8);
  anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune3-> SetFillColor(kAzure-4);
  anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune3-> SetFillColor(kYellow+2);
  anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune3-> SetFillColor(kOrange);
  anglep1p2CM_CCNue_nobtblowPT_rebin_Tune3-> SetFillColor(31);
  anglep1p2CM_NC_nobtblowPT_rebin_Tune3-> SetFillColor(kMagenta-8);
  anglep1p2CM_EXT_nobtblowPT_rebin_Tune3-> SetFillColor(kBlack);
  reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin-> SetFillColor(kGray);
  
  THStack *anglep1p2CM_nobtblowPT_Tune3test = new THStack("anglep1p2CM_nobtblowPT_Tune3test","");
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_CCQE_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_CCRes_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_CCNue_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_NC_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(anglep1p2CM_EXT_nobtblowPT_rebin_Tune3);
  anglep1p2CM_nobtblowPT_Tune3test-> Add(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin);
  ////  anglep1p2CM_nobtblowPT_Tune3->SetMaximum(80.);
  anglep1p2CM_nobtblowPT_Tune3test-> Draw();
  anglep1p2CM_nobtblowPT_Tune3test->GetYaxis()->SetTitle("No. of Entries");
 
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Draw("e1same");

  TLegend *ltune = new TLegend(0.45, 0.65, 0.9, 0.9);
  ltune -> SetNColumns(2);
  ltune -> AddEntry(anglep1p2CM_CCQE_nobtblowPT_rebin_Tune3, "CC-QE", "f");
  ltune -> AddEntry(anglep1p2CM_CCDIS_nobtblowPT_rebin_Tune3, "CC-DIS", "f");
  ltune -> AddEntry(anglep1p2CM_CCRes_nobtblowPT_rebin_Tune3, "CC-Res", "f");
  ltune -> AddEntry(anglep1p2CM_CCNue_nobtblowPT_rebin_Tune3, "#nu_{e}-CC", "f");
  ltune -> AddEntry(anglep1p2CM_CCMEC_nobtblowPT_rebin_Tune3, "CC-MEC", "f");
  ltune -> AddEntry(anglep1p2CM_NC_nobtblowPT_rebin_Tune3, "NC", "f");
  ltune -> AddEntry(anglep1p2CM_CCCoh_nobtblowPT_rebin_Tune3, "CC-Coh", "f");
  ltune -> AddEntry(anglep1p2CM_EXT_nobtblowPT_rebin_Tune3, "other", "f");
  ltune -> AddEntry(reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin, "off-beam data", "f");
  ltune -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin, "on-beam data", "lep");
  ltune -> Draw();
    
  TText *ttune = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
  ttune->Draw();
  
  ctune->cd();
  TPad *padtune_2 = new TPad("padtune_2", "padtune_2", 0, 0.05, 1, 0.3);
  padtune_2->SetTopMargin(0.01);
  padtune_2->SetBottomMargin(0.2);
  padtune_2->SetGridx();
  padtune_2->SetGridy();
  padtune_2->Draw();
  padtune_2->cd();
  // Define the ratio plot
  TH1F *htune = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Clone("htune");
  TH1 *lasttune = (TH1*)anglep1p2CM_nobtblowPT_Tune3test->GetStack()->Last();
   
  chi2test = Chi2Calc(lasttune, reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin, reco_angle_p1p2_OffBeam_nobtbLF_PT_PID_CM_rebin, normOffBeam, normMCBNBTune3);
  canvas++;
  outfileChi2<<"anglep1p2CM_nobtblowPT_Tune3:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;
  
  htune->SetLineColor(kBlack);
  htune->Sumw2();
  htune->SetStats(0);      // No statistics on lower plot
  htune->Divide(lasttune);
  htune->SetMarkerStyle(21);
  htune->SetTitle("");
  htune->Draw("e p");       // Draw the ratio plot

  htune->GetYaxis()->SetTitle("Data/MC");
  htune->GetYaxis()->SetNdivisions(505);
  htune->GetYaxis()->SetTitleSize(20);
  htune->GetYaxis()->SetTitleFont(43);
  htune->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  htune->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  htune->GetXaxis()->SetTitle("cos #gamma_{CM}");
  htune->GetXaxis()->SetTitleSize(20);
  htune->GetXaxis()->SetTitleFont(43);
  htune->GetXaxis()->SetTitleOffset(3.);
  htune->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  htune->GetXaxis()->SetLabelSize(15);

  ctune->Update();
  ctune->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtblowPT_Tune3_rebin.pdf");  
  ctune->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/anglep1p2CM_nobtblowPT_Tune3_rebin.eps");  

  /////////////
  
  TH1F *h22 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Clone("h22");
  TH1 *last22 = (TH1*)anglep1p2CM_nobtblowPT_Tune1test->GetStack()->Last();///
  TH1 *lasttune3 = (TH1*)anglep1p2CM_nobtblowPT_Tune3test->GetStack()->Last();///
 
  double OnBeamCM = h22->GetEntries();
  double MCOffBeamCM = last22->GetEntries();
  double MCOffBeamCMTune3 = lasttune3->GetEntries();

  int nbins=reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetNbinsX();
  //double syst[5] ={0.0247713, 0.0762139, 0.115949,0.99173};
  double syst[5] ={0.0401779, 0.115949, 0.212662,1.70848};/// bininng q toca
  //double syst[20] ={0.0247713, 0.0247713, 0.115949,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735,0.991735};
  double err[5];
  double stats[5];
  double statsMC[5];
  double statsMCTune3[5];
  /*
  for(int ii=0; ii<nbins-1; ii++){
    if(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1) ==0) stats[ii] =0.;
    else stats[ii] = sqrt(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1))/OnBeamCM;
  }
  for(int ii=0; ii<nbins-1; ii++){
    if(last22->GetBinContent(ii+1) ==0) statsMC[ii]=0.;
    else statsMC[ii] = sqrt(last22->GetBinContent(ii+1))/MCOffBeamCM;
    }
  */
  for(int ii=0; ii<nbins-1; ii++){
    if(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1) ==0) stats[ii] =0.;
    else stats[ii] = sqrt((reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1))/(OnBeamCM*OnBeamCM) + (reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1)*reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1))/(OnBeamCM*OnBeamCM*OnBeamCM));
  }
  for(int ii=0; ii<nbins-1; ii++){
    if(last22->GetBinContent(ii+1) ==0) statsMC[ii]=0.;
        else statsMC[ii] = sqrt((last22->GetBinContent(ii+1))/(MCOffBeamCM*MCOffBeamCM) + (last22->GetBinContent(ii+1)*last22->GetBinContent(ii+1))/(MCOffBeamCM*MCOffBeamCM*MCOffBeamCM));
    }
  for(int ii=0; ii<nbins-1; ii++){
    if(lasttune3->GetBinContent(ii+1) ==0) statsMCTune3[ii]=0.;
        else statsMCTune3[ii] = sqrt((lasttune3->GetBinContent(ii+1))/(MCOffBeamCMTune3*MCOffBeamCMTune3) + (lasttune3->GetBinContent(ii+1)*lasttune3->GetBinContent(ii+1))/(MCOffBeamCMTune3*MCOffBeamCMTune3*MCOffBeamCMTune3));
    }
  
  std::cout<<"entries MC tune 1  "<< MCOffBeamCM<<"  entries MC tune 3  "<< MCOffBeamCMTune3<<"  entries on-beam "<< OnBeamCM<<std::endl;
  
  //reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Sumw2();
  //last22->Sumw2();
  
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Scale(1/OnBeamCM);
  last22->Scale(1/MCOffBeamCM);
  lasttune3->Scale(1/MCOffBeamCMTune3);
  /*
    for(int ii=0; ii<nbins-1; ii++){
    if(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->GetBinContent(ii+1) ==0) stats[ii] =0.;
    else stats[ii] = sqrt(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->GetBinContent(ii+1));
  }
  for(int ii=0; ii<nbins-1; ii++){
    if(last22->GetBinContent(ii+1) ==0) statsMC[ii]=0.;
    else statsMC[ii] = sqrt(last22->GetBinContent(ii+1));
  }
  */
  
  for(int ii=0; ii<nbins-1; ii++){
    reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetBinError(ii+1,sqrt(stats[ii]*stats[ii] +syst[ii]*syst[ii]));
    last22->SetBinError(ii+1,sqrt(statsMC[ii]*statsMC[ii]));
    lasttune3->SetBinError(ii+1,sqrt(statsMCTune3[ii]*statsMCTune3[ii]));
    //if(stats[ii]==0) reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_test->SetBinError(ii+1,0);
    //if(statsMC[ii]==0) last22->SetBinError(ii+1,0);
    err[ii] = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinError(ii+1);
  }

  std::cout<<"...................................................."<<std::endl;
  std::cout<<"metiendo errores ........"<<std::endl;
  for(int ii=0; ii<nbins; ii++){
    std::cout<<"bin "<< ii<<std::endl;
    std::cout<<" bin content "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1)<<" stats "<< stats[ii]<<" syst "<<syst[ii] <<std::endl;
    std::cout<<"error  "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinError(ii+1)<<std::endl;
  }
 
  TCanvas *c22 = new TCanvas("c22", "c22", 900, 900);
  TPad *pad22 = new TPad("pad22", "pad22", 0, 0.3, 1, 1.0);
  pad22->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad22->Draw();             // Draw the upper pad: pad1
  pad22->cd();              // pad1 becomes the current pad

  last22->SetLineColor(kAzure+4);
  last22->SetMarkerStyle(21);// squaer, 22 para triangulo
  last22->SetMarkerColor(kAzure+4);
  last22->SetMaximum(1.);
  last22->SetTitle("");
  last22-> Draw("ep");
  last22->GetYaxis()->SetTitle("production fraction");

  lasttune3->SetLineColor(kRed);
  lasttune3->SetMarkerColor(kRed);
  lasttune3->SetMarkerStyle(22);
  lasttune3->Draw("ep same");
  
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Draw("ep same");

  TLegend *l22 = new TLegend(0.45, 0.65, 0.9, 0.9);
  //l22 -> SetNColumns(2);
  l22 -> AddEntry(last22, "GENIE default", "lep");
  l22 -> AddEntry(lasttune3, "GENIE alternative", "lep");
  l22 -> AddEntry(h22, "on-beam data", "lep");
  l22 -> Draw();

  TText *t22 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
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

  //  chi2test = Chi2Calc(last17, h17, reco_projprel_OffBeam_nobtb_lowPT, normOffBeam, normMCBNB);
  //canvas++;
  //outfileChi2<<"reco_relpnp2_nobtblowPT_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

  h22->SetLineColor(kBlack);
  h22->SetStats(0);      // No statistics on lower plot
  h22->Divide(last22);
  h22->SetMarkerStyle(21);
  h22->SetTitle("");
  //h22->Draw("ep");       // Draw the ratio plot
  h22->Draw("histo p");      // Draw the ratio plot

  h22->GetYaxis()->SetTitle("Data/MC");
  h22->GetYaxis()->SetNdivisions(505);
  h22->GetYaxis()->SetTitleSize(20);
  h22->GetYaxis()->SetTitleFont(43);
  h22->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h22->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h22->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h22->GetXaxis()->SetTitleSize(20);
  h22->GetXaxis()->SetTitleFont(43);
  h22->GetXaxis()->SetTitleOffset(3.);
  h22->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h22->GetXaxis()->SetLabelSize(15);

  c22->Update();
  c22->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/production_cosCM_nobtblowPT_Tune1.pdf");  
  c22->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/production_cosCM_nobtblowPT_Tune1.eps");

  ///////////////////////////////////////////  opening angle LF //////////////////////////////////////////  

  double OnBeamLF = h23->GetEntries();
  double MCOffBeamLF = last23->GetEntries();
  double MCOffBeamLFTune3 = last23tune3->GetEntries();
 
  TCanvas *c23 = new TCanvas("c23", "c23", 900, 900);
  TPad *pad23 = new TPad("pad23", "pad23", 0, 0.3, 1, 1.0);
  pad23->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad23->Draw();             // Draw the upper pad: pad1
  pad23->cd();              // pad1 becomes the current pad

  last23->SetLineColor(kAzure-9);
  last23->SetFillColor(kAzure-9);
  last23->SetMarkerStyle(21);
  last23->SetMarkerColor(kAzure-3);
  last23->SetTitle("");
  last23-> Draw("E2P");
  //last23->SetMaximum(1.);
 
  last23->GetYaxis()->SetTitle("No. of Entries");

  last23tune3->SetLineColor(kRed-9);
  last23tune3->SetFillColor(kRed-9);
  last23tune3->SetMarkerColor(kRed+1);
  last23tune3->SetMarkerStyle(21);
  last23tune3->Draw("E2P same");

  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->SetMarkerSize(1.5);
  reco_angle_p1p2_OnBeam_PID_LF_zoom->Draw("e1p same");

  TH1F *htune1err = (TH1F*)last23->Clone("htune1err");
  TH1F *htune3err = (TH1F*)last23tune3->Clone("htune3err");

  for(int ii=0; ii<nbinsLF-1; ii++){
    statsLF[ii] = reco_angle_p1p2_OnBeam_PID_LF_zoom->GetBinError(ii+1);
    statsLFtune1[ii] = last23->GetBinError(ii+1);
    statsLFtune3[ii] = last23tune3->GetBinError(ii+1);
  }
  
  for(int ii=0; ii<nbinsLF-1; ii++){
    htune1err->SetBinError(ii+1,sqrt(statsLFtune1[ii]*statsLFtune1[ii] +systLF[ii]*systLF[ii]));
    htune3err->SetBinError(ii+1,sqrt(statsLFtune3[ii]*statsLFtune3[ii] +systLF[ii]*systLF[ii]));
    ///errLF[ii] = hdataerr->GetBinError(ii+1);
  }

  //TH1F *hdataerr = (TH1F*)reco_angle_p1p2_OnBeam_PID_LF_zoom->Clone("hdataerr");
  
  htune1err->SetFillStyle(3002);
  htune1err->SetFillColor(kAzure-6);
  htune1err->SetLineColor(kBlack);
  htune1err->Draw("E2P same");// probar E2 en el error syst

  htune3err->SetFillStyle(3013);
  htune3err->SetFillColor(kRed+2);
  htune3err->SetLineColor(kBlack);
  htune3err->Draw("E2P same");// probar E2 en el error syst


  //hdataerr->SetFillStyle(3013);
  //hdataerr->SetFillColor(kBlack);
  //hdataerr->SetLineColor(kBlack);
  //hdataerr->Draw("E2P same");// probar E2 en el error syst

  TLegend *l23 = new TLegend(0.45, 0.65, 0.9, 0.9);
  //l23 -> SetNColumns(2);
  l23 -> AddEntry(last23, "GENIE Default", "fp");
  l23 -> AddEntry(last23tune3, "GENIE Alternative", "fp");
  l23 -> AddEntry(reco_angle_p1p2_OnBeam_PID_LF_zoom, "on-beam data", "lep");
  l23 -> Draw();

  TText *t23 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
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

  h23->SetLineColor(kAzure-6);
  h23->SetMarkerColor(kAzure-6);
  h23->SetStats(0);      // No statistics on lower plot
  h23->Divide(last23);
  h23->SetMarkerStyle(21);
  h23->SetTitle("");
  //h23->Draw("ep");       // Draw the ratio plot
  h23->Draw("ep");      // Draw the ratio plot

  h23->GetYaxis()->SetTitle("Data/MC");
  h23->GetYaxis()->SetNdivisions(505);
  h23->GetYaxis()->SetTitleSize(20);
  h23->GetYaxis()->SetTitleFont(43);
  h23->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h23->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h23->GetXaxis()->SetTitle("cos #gamma_{LF}");
  h23->GetXaxis()->SetTitleSize(20);
  h23->GetXaxis()->SetTitleFont(43);
  h23->GetXaxis()->SetTitleOffset(3.);
  h23->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h23->GetXaxis()->SetLabelSize(15);


  h23tune3->SetMarkerColor(kRed-7);
  h23tune3->SetLineColor(kRed-7);
  h23tune3->Divide(last23tune3);
  h23tune3->SetMarkerStyle(20);
  h23tune3->Draw("ep same");       // Draw the ratio plot

  c23->Update();
  c23->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosLF_nocuts_Tune1Tune3.pdf");
  c23->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosLF_nocuts_Tune1Tune3.eps");;


  TCanvas *c24 = new TCanvas("c24", "c24", 900, 900);
  TPad *pad24 = new TPad("pad24", "pad24", 0, 0.3, 1, 1.0);
  pad24->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad24->Draw();             // Draw the upper pad: pad1
  pad24->cd();              // pad1 becomes the current pad

  reco_pn_CCQE_nocuts_Tune1-> SetFillColor(kRed -10);
  reco_pn_CCRes_nocuts_Tune1-> SetFillColor(kGreen-8);
  reco_pn_CCMEC_nocuts_Tune1-> SetFillColor(kAzure-4);
  reco_pn_CCCoh_nocuts_Tune1-> SetFillColor(kYellow+2);
  reco_pn_CCDIS_nocuts_Tune1-> SetFillColor(kOrange);
  reco_pn_CCNue_nocuts_Tune1-> SetFillColor(31);
  reco_pn_NC_nocuts_Tune1-> SetFillColor(kMagenta-8);
  reco_pn_EXT_nocuts_Tune1-> SetFillColor(kBlack);/// includes OOFV, other, EXT
  reco_pn_OffBeam_PID-> SetFillColor(kGray);

  THStack *reco_pn_nocuts_Tune1 = new THStack("reco_pn_nocuts_Tune1","");
  reco_pn_nocuts_Tune1-> Add(reco_pn_CCQE_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_CCRes_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_CCMEC_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_CCCoh_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_CCDIS_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_CCNue_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_NC_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_EXT_nocuts_Tune1);
  reco_pn_nocuts_Tune1-> Add(reco_pn_OffBeam_PID);
  ////  reco_pn_nocuts_Tune1->SetMaximum(80.);
  reco_pn_nocuts_Tune1-> Draw();  
  reco_pn_nocuts_Tune1->GetYaxis()->SetTitle("No. of Entries");
  
  reco_pn_OnBeam_PID->SetLineColor(kBlack);
  reco_pn_OnBeam_PID->SetMarkerStyle(20);
  reco_pn_OnBeam_PID->Draw("e1same");

  TLegend *l24 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l24 -> SetNColumns(2);
  l24 -> AddEntry(reco_pn_CCQE_nocuts_Tune1, "CC-QE", "f");
  l24 -> AddEntry(reco_pn_CCDIS_nocuts_Tune1, "CC-DIS", "f");
  l24 -> AddEntry(reco_pn_CCRes_nocuts_Tune1, "CC-Res", "f");
  l24 -> AddEntry(reco_pn_CCNue_nocuts_Tune1, "#nu_{e}-CC", "f");
  l24 -> AddEntry(reco_pn_CCMEC_nocuts_Tune1, "CC-MEC", "f");
  l24 -> AddEntry(reco_pn_NC_nocuts_Tune1, "NC", "f");
  l24 -> AddEntry(reco_pn_CCCoh_nocuts_Tune1, "CC-Coh", "f");
  l24 -> AddEntry(reco_pn_EXT_nocuts_Tune1, "other", "f");
  l24 -> AddEntry(reco_pn_OffBeam_PID, "off-beam data", "f");
  l24 -> AddEntry(reco_pn_OnBeam_PID, "on-beam data", "lep");
  l24 -> Draw();

  TText *t24 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT, stats only");
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
  TH1F *h24 = (TH1F*)reco_pn_OnBeam_PID->Clone("h24");
  TH1 *last24 = (TH1*)reco_pn_nocuts_Tune1->GetStack()->Last();

  chi2test = Chi2Calc(last24, reco_pn_OnBeam_PID,reco_pn_OffBeam_PID, normOffBeam, normMCBNB);
  canvas++;
  outfileChi2<<"reco_pn_nocuts_Tune1:  "<<"canvas: "<<canvas<<"  chi2test : "<<chi2test<<std::endl;

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
  h24->GetXaxis()->SetTitle("initial struck nucleon p_{n} [GeV]");
  h24->GetXaxis()->SetTitleSize(20);
  h24->GetXaxis()->SetTitleFont(43);
  h24->GetXaxis()->SetTitleOffset(3.);
  h24->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h24->GetXaxis()->SetLabelSize(15);

  c24->Update();
  c24->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_pn_nocuts_Tune1.pdf");  
  c24->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/reco_pn_nocuts_Tune1.eps");  
  
  TCanvas *c25 = new TCanvas("c25", "c25", 900, 900);
  angleCM_PT_CCQE_Tune1->SetTitle("");
  angleCM_PT_CCQE_Tune1->GetXaxis()->SetTitle("p^{T}_{miss} [GeV/c]");
  angleCM_PT_CCQE_Tune1->GetYaxis()->SetTitle("cos #gamma_{CM}");
  angleCM_PT_CCQE_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  angleCM_PT_CCQE_Tune1->GetXaxis()->SetLabelOffset(0.015);
  angleCM_PT_CCQE_Tune1->Draw("colz");

  c25->Update();
  c25-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/PID_300_tune3/cCM_PT_CCQE_nocut.pdf");
  c25-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cCM_PT_CCQE_nocut.eps");

  TCanvas *c26 = new TCanvas("c26", "c26", 900, 900);
  angleCM_PT_CCRes_Tune1->SetTitle("");
  angleCM_PT_CCRes_Tune1->GetXaxis()->SetTitle("p^{T}_{miss} [GeV/c]");
  angleCM_PT_CCRes_Tune1->GetYaxis()->SetTitle("cos #gamma_{CM}");
  angleCM_PT_CCRes_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  angleCM_PT_CCRes_Tune1->GetXaxis()->SetLabelOffset(0.015);
  angleCM_PT_CCRes_Tune1->Draw("colz");
 
  c26->Update();
  c26-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cCM_PT_CCRes_nocut.pdf");
  c26-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cCM_PT_CCRes_nocut.eps");

  TCanvas *c27 = new TCanvas("c27", "c27", 900, 900);
  angleCM_PT_CCMEC_Tune1->SetTitle("");
  angleCM_PT_CCMEC_Tune1->GetXaxis()->SetTitle("p^{T}_{miss} [GeV/c]");
  angleCM_PT_CCMEC_Tune1->GetYaxis()->SetTitle("cos #gamma_{CM}");
  angleCM_PT_CCMEC_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  angleCM_PT_CCMEC_Tune1->GetXaxis()->SetLabelOffset(0.015);
  angleCM_PT_CCMEC_Tune1->Draw("colz");

  c27->Update();
  c27-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cCM_PT_CCMEC_nocut.pdf.pdf");
  c27-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cCM_PT_CCMEC_nocut.eps");

  TCanvas *c28 = new TCanvas("c28", "c28", 900, 900);
  angleCM_PT_all_Tune1->SetTitle("");
  angleCM_PT_all_Tune1->GetXaxis()->SetTitle("p^{T}_{miss} [GeV/c]");
  angleCM_PT_all_Tune1->GetYaxis()->SetTitle("cos #gamma_{CM}");
  angleCM_PT_all_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  angleCM_PT_all_Tune1->GetXaxis()->SetLabelOffset(0.015);
  angleCM_PT_all_Tune1->Draw("colz");

  c28->Update();
  c28-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cCM_PT_all_nocut.pdf.pdf");
  c28-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cCM_PT_all_nocut.eps");

  TCanvas *c29 = new TCanvas("c29", "c29", 900, 900);
  pn_prel_CCQE_lowPT_1stbin_Tune1->SetTitle("");
  pn_prel_CCQE_lowPT_1stbin_Tune1->GetXaxis()->SetTitle("p^{#perp}_{pn-p2} [GeV/c]");
  pn_prel_CCQE_lowPT_1stbin_Tune1->GetYaxis()->SetTitle("p_{n} [GeV/c");
  pn_prel_CCQE_lowPT_1stbin_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  pn_prel_CCQE_lowPT_1stbin_Tune1->GetXaxis()->SetLabelOffset(0.015);
  pn_prel_CCQE_lowPT_1stbin_Tune1->Draw("colz");

  c29->Update();
  c29-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_CCQE_lowPT_1stbin.pdf.pdf");
  c29-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_CCQE_lowPT_1stbin.eps");

  TCanvas *c30 = new TCanvas("c30", "c30", 900, 900);
  pn_prel_CCRes_lowPT_1stbin_Tune1->SetTitle("");
  pn_prel_CCRes_lowPT_1stbin_Tune1->GetXaxis()->SetTitle("p^{#perp}_{pn-p2} [GeV/c]");
  pn_prel_CCRes_lowPT_1stbin_Tune1->GetYaxis()->SetTitle("p_{n} [GeV/c");
  pn_prel_CCRes_lowPT_1stbin_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  pn_prel_CCRes_lowPT_1stbin_Tune1->GetXaxis()->SetLabelOffset(0.015);
  pn_prel_CCRes_lowPT_1stbin_Tune1->Draw("colz");

  c30->Update();
  c30-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_CCRes_lowPT_1stbin.pdf.pdf");
  c30-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_CCRes_lowPT_1stbin.eps");

  TCanvas *c31 = new TCanvas("c31", "c31", 900, 900);
  pn_prel_CCMEC_lowPT_1stbin_Tune1->SetTitle("");
  pn_prel_CCMEC_lowPT_1stbin_Tune1->GetXaxis()->SetTitle("p^{#perp}_{pn-p2} [GeV/c]");
  pn_prel_CCMEC_lowPT_1stbin_Tune1->GetYaxis()->SetTitle("p_{n} [GeV/c");
  pn_prel_CCMEC_lowPT_1stbin_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  pn_prel_CCMEC_lowPT_1stbin_Tune1->GetXaxis()->SetLabelOffset(0.015);
  pn_prel_CCMEC_lowPT_1stbin_Tune1->Draw("colz");

  c31->Update();
  c31-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_CCMEC_lowPT_1stbin.pdf.pdf");
  c31-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_CCMEC_lowPT_1stbin.eps");

  TCanvas *c32 = new TCanvas("c32", "c32", 900, 900);
  pn_prel_all_lowPT_1stbin_Tune1->SetTitle("");
  pn_prel_all_lowPT_1stbin_Tune1->GetXaxis()->SetTitle("p^{#perp}_{pn-p2} [GeV/c]");
  pn_prel_all_lowPT_1stbin_Tune1->GetYaxis()->SetTitle("p_{n} [GeV/c");
  pn_prel_all_lowPT_1stbin_Tune1->GetYaxis()->SetTitleOffset(0.8); 
  pn_prel_all_lowPT_1stbin_Tune1->GetXaxis()->SetLabelOffset(0.015);
  pn_prel_all_lowPT_1stbin_Tune1->Draw("colz");

  c32->Update();
  c32-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_all_lowPT_1stbin.pdf.pdf");
  c32-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prelVSpn_all_lowPT_1stbin.eps");
  
  
  
  
  }
