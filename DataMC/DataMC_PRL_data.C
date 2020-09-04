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

void DataMC_PRL_data(){ 
  
  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_Tune1_BNBMC_PRL.root","READ");
  TFile* OnBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OnBeam_PRL.root","READ");
  TFile* OffBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OffBeam_PRL.root","READ");
  
  TFile* BNBMCTune3 = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_Tune3_BNBMC_PRL.root","READ");
  
  std::cout<<"antes de Tfile"<<std::endl;
 
  outfileDataMC_PID_300.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/chi2_2P_Data.txt");
  outfileChi2.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/Chi2Data.txt");
  
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
 TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1= (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1");
 TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2= (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2");
 TH1D* reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3= (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3");
 TH1D* reco_angle_p1p2_OnBeam_PID_CM_rebin = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_rebin");
 TH1D* reco_angle_p1p2_OnBeam_PID_CM_rebin1 = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_rebin1");
 TH1D* reco_angle_p1p2_OnBeam_PID_CM_rebin2 = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_rebin2");
 TH1D* reco_angle_p1p2_OnBeam_PID_CM_rebin3 = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PID_CM_rebin3");

 TH1D* reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3 = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3");
 TH1D* reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3 = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3");

 TH1D* reco_PT_OnBeam_lowPT_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_lowPT_PID");
 TH1D* reco_PT_OnBeam_1binCM_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_1binCM_PID");
 TH1D* reco_PT_OnBeam_1binCM_lowPT_PID = (TH1D*) OnBeam->Get("reco_PT_OnBeam_1binCM_lowPT_PID");

 TH1D* reco_projprel_OnBeam_lowPT = (TH1D*) OnBeam->Get("reco_projprel_OnBeam_lowPT");
 TH1D* reco_projprel_OnBeam_lowPT_1binCM = (TH1D*) OnBeam->Get("reco_projprel_OnBeam_lowPT_1binCM");
 TH1D* reco_projprel_OnBeam = (TH1D*) OnBeam->Get("reco_projprel_OnBeam");
 TH1D* reco_projprel_OnBeam_1binCM = (TH1D*) OnBeam->Get("reco_projprel_OnBeam_1binCM");

 TH1D* reco_pn_OnBeam_PID_all = (TH1D*) OnBeam->Get("reco_pn_OnBeam_PID_all");
 TH1D* reco_pn_OnBeam_PID_lowPT = (TH1D*) OnBeam->Get("reco_pn_OnBeam_PID_lowPT");
 TH1D* reco_pn_OnBeam_PID_lowPT_1stbin = (TH1D*) OnBeam->Get("reco_pn_OnBeam_PID_lowPT_1stbin");

 TH1D* reco_angle_p1p2_OnBeam_PT_CM_rebin3 = (TH1D*) OnBeam->Get("reco_angle_p1p2_OnBeam_PT_CM_rebin3");
 
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

  gStyle->SetTitleSize(0.03,"xyz");
  gStyle->SetTitleFont(22,"xyz");
  gStyle->SetLabelFont(22,"xyz");
  gStyle->SetTitleOffset(1.,"y");
  gStyle->SetTitleOffset(1.,"x");

  std::cout<<"antes de los plots"<<std::endl;  

  double chi2test =0.0;
  int canvas=0;

  //////////////////// ratio plot
   
  int nbins=reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetNbinsX();
  int nbins1=reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetNbinsX();
  int nbins2=reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetNbinsX();
  int nbins3=reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->GetNbinsX();

  std::cout<<"num bins "<<nbins<<" num bins1 "<<nbins1<<" num bins2 "<<nbins2<<std::endl;

  //  double syst[4] ={0.200444, 0.340512, 0.461152,1.30709};/// con cortes, RMS
  //  double syst1[5] ={0.200444, 0.340512, 0.461152, 0.786026, 2.12438};/// bininng q toca// este mejor
  //  double syst2[6] ={0.200444, 0.340512, 0.461152, 0.786026, 3.03245, 1.00046};/// bininng q toca// entradas de 6 y 8// anaydir mismo sin cortes
  //  double syst3[9] ={0.200444, 0.340512, 0.461152,0.620509, 0.818293, 1.21831, 3.54788, 1.30607, 1.04982};/// bininng q toca// entradas de 6 y 8// anaydir mismo sin cortes

  // propagacion de errores
  double syst[4] ={1.61234, 0.562667, 1.27406, 3.70919};/// mean
  double syst1[5] ={1.61234, 0.562667, 1.27406, 4.56736, 3.19052};
  double syst2[6] ={1.61234, 0.562667, 1.27406, 4.56736, 3.82141, 4.56095};/// entradas de 6 y 8
  double syst3[9] ={1.61234, 0.562667, 1.27406, 7.39805, 6.11268, 2.58804, 5.19513, 2.62334, 5.6789};

  double syst11[9] ={1.33216, 0.474963, 1.08995, 14.6365, 4.41064, 2.33561, 3.52674, 2.62334, 5.6789};//PRL, low PT
  
  double err[4];
  double stats[4];
  double statsnocuts[4];

  double err1[5];
  double stats1[5];
  double statsnocuts1[5];

  double err2[6];
  double stats2[6];
  double statsnocuts2[6];  

  double err3[9];
  double stats3[9];
  double statsnocuts3[9];

  double err11[9];
  double stats11[9];
  double statsnocuts11[9];   

  for(int ii=0; ii<nbins-1; ii++){
    stats[ii] = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinError(ii+1);
    statsnocuts[ii] = reco_angle_p1p2_OnBeam_PID_CM_rebin->GetBinError(ii+1);
  }

  for(int ii=0; ii<nbins1-1; ii++){
    stats1[ii] = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetBinError(ii+1);
    statsnocuts1[ii] = reco_angle_p1p2_OnBeam_PID_CM_rebin1->GetBinError(ii+1);
  }

  for(int ii=0; ii<nbins2-1; ii++){
    stats2[ii] = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetBinError(ii+1);
    statsnocuts2[ii] = reco_angle_p1p2_OnBeam_PID_CM_rebin2->GetBinError(ii+1);
  }

  for(int ii=0; ii<nbins3-1; ii++){
    stats3[ii] = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->GetBinError(ii+1);
    statsnocuts3[ii] = reco_angle_p1p2_OnBeam_PID_CM_rebin3->GetBinError(ii+1);
  }

  for(int ii=0; ii<nbins3-1; ii++){
    stats11[ii] = reco_angle_p1p2_OnBeam_PT_CM_rebin3->GetBinError(ii+1);
    statsnocuts11[ii] = reco_angle_p1p2_OnBeam_PT_CM_rebin3->GetBinError(ii+1);
  }   
  
  //  std::cout<<"entries MC tune 1  "<< MCOffBeamCM<<"  entries MC tune 3  "<< MCOffBeamCMTune3<<"  entries on-beam "<< OnBeamCM<<std::endl;
  
  /*
  for(int ii=0; ii<nbins1-1; ii++){
    reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->SetBinError(ii+1,sqrt(stats1[ii]*stats1[ii] +syst1[ii]*syst1[ii]));
    reco_angle_p1p2_OnBeam_PID_CM_rebin1->SetBinError(ii+1,sqrt(stats1[ii]*stats1[ii] +syst1[ii]*syst1[ii]));
    err1[ii] = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetBinError(ii+1);
  }

  for(int ii=0; ii<nbins2-1; ii++){
    reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->SetBinError(ii+1,sqrt(stats2[ii]*stats2[ii] +syst2[ii]*syst2[ii]));
    reco_angle_p1p2_OnBeam_PID_CM_rebin2->SetBinError(ii+1,sqrt(stats2[ii]*stats2[ii] +syst2[ii]*syst2[ii]));
    err2[ii] = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetBinError(ii+1);
  }  
  


  std::cout<<"...................................................."<<std::endl;
  std::cout<<"metiendo errores 1........"<<std::endl;
  for(int ii=0; ii<nbins1; ii++){
    std::cout<<"bin "<< ii<<std::endl;
    std::cout<<" bin content "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetBinContent(ii+1)<<" stats "<< stats1[ii]<<" syst "<<syst1[ii] <<std::endl;
    std::cout<<"error  "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetBinError(ii+1)<<std::endl;
  }

  std::cout<<"...................................................."<<std::endl;
  std::cout<<"metiendo errores 2........"<<std::endl;
  for(int ii=0; ii<nbins2; ii++){
    std::cout<<"bin "<< ii<<std::endl;
    std::cout<<" bin content "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetBinContent(ii+1)<<" stats "<< stats2[ii]<<" syst "<<syst2[ii] <<std::endl;
    std::cout<<"error  "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetBinError(ii+1)<<std::endl;
  }    
  */
 
  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
  TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
  pad1->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad1->Draw();             // Draw the upper pad: pad1
  pad1->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetTitle("");
  //reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->SetMaximum(1.);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Draw("e1p");
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetYaxis()->SetTitle("No. of Entries");
  // reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetYaxis()->SetLabelSize(27);

  TH1F *hrebin = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Clone("hrebin");
  
  for(int ii=0; ii<nbins-1; ii++){
    hrebin->SetBinError(ii+1,sqrt(stats[ii]*stats[ii] +syst[ii]*syst[ii]));
    //reco_angle_p1p2_OnBeam_PID_CM_rebin->SetBinError(ii+1,sqrt(stats[ii]*stats[ii] +syst[ii]*syst[ii]));
    err[ii] = hrebin->GetBinError(ii+1);
  }

  hrebin->Draw("e1 same");
  
  TLegend *l1 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l1 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin, "MicroBooNE on-beam data", "lep");
  l1 -> Draw();

  TText *t1 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t1->Draw();
  
  c1->cd();
  TPad *pad1_2 = new TPad("pad1_2", "pad1_2", 0, 0.05, 1, 0.3);
  pad1_2->SetTopMargin(0.01);
  pad1_2->SetBottomMargin(0.3);
  pad1_2->SetGridx();
  pad1_2->SetGridy();
  pad1_2->Draw();
  pad1_2->cd();
  // Define the ratio plot

  TH1F *h1 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->Clone("h1");
  TH1F *hbefore1 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_rebin->Clone("hbefore1");

  h1->SetLineColor(kRed);
  h1->SetStats(0);      // No statistics on lower plot
  h1->Divide(hbefore1);
  h1->SetMarkerStyle(20);
  h1->SetMarkerColor(kRed);
  h1->SetTitle("");
  //h22->Draw("ep");       // Draw the ratio plot
  h1->Draw("histo p");      // Draw the ratio plot

  h1->GetYaxis()->SetTitle("after/before");
  h1->GetYaxis()->SetNdivisions(505);
  h1->GetYaxis()->SetTitleSize(20);
  h1->GetYaxis()->SetTitleFont(43);
  h1->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h1->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h1->GetXaxis()->SetTitleSize(25);
  h1->GetXaxis()->SetTitleFont(43);
  h1->GetXaxis()->SetTitleOffset(4.);
  h1->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h1->GetXaxis()->SetLabelSize(27);

  c1->Update();
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data.pdf");  
  c1->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data.eps");  

  //////////

  TCanvas *c2 = new TCanvas("c2", "c2", 900, 900);
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.3, 1, 1.0);
  pad2->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad2->Draw();             // Draw the upper pad: pad1
  pad2->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->SetTitle("");
  //reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->SetMaximum(1.);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->Draw("e1p");
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetYaxis()->SetTitle("No. of Entries");

  TH1F *hrebin1 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->Clone("hrebin1");
  
  for(int ii=0; ii<nbins1-1; ii++){
    hrebin1->SetBinError(ii+1,sqrt(stats1[ii]*stats1[ii] +syst1[ii]*syst1[ii]));
    //reco_angle_p1p2_OnBeam_PID_CM_rebin1->SetBinError(ii+1,sqrt(stats1[ii]*stats1[ii] +syst1[ii]*syst1[ii]));
    err1[ii] = hrebin1->GetBinError(ii+1);
  }

  hrebin1->Draw("e1 same");
  
  TLegend *l2 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l2 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1, "MicroBooNE on-beam data", "lep");
  l2 -> Draw();

  TText *t2 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t2->Draw();
  
  c2->cd();
  TPad *pad2_2 = new TPad("pad2_2", "pad2_2", 0, 0.05, 1, 0.3);
  pad2_2->SetTopMargin(0.01);
  pad2_2->SetBottomMargin(0.3);
  pad2_2->SetGridx();
  pad2_2->SetGridy();
  pad2_2->Draw();
  pad2_2->cd();
  // Define the ratio plot

  TH1F *h2 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->Clone("h2");
  TH1F *hbefore2 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_rebin1->Clone("hbefore2");

  h2->SetLineColor(kRed);
  h2->SetMarkerColor(kRed);
  h2->SetStats(0);      // No statistics on lower plot
  h2->Divide(hbefore2);
  h2->SetMarkerStyle(20);
  h2->SetTitle("");
  //h22->Draw("ep");       // Draw the ratio plot
  h2->Draw("histo p");      // Draw the ratio plot

  h2->GetYaxis()->SetTitle("after/before");
  h2->GetYaxis()->SetNdivisions(505);
  h2->GetYaxis()->SetTitleSize(20);
  h2->GetYaxis()->SetTitleFont(43);
  h2->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h2->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h2->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h2->GetXaxis()->SetTitleSize(25);
  h2->GetXaxis()->SetTitleFont(43);
  h2->GetXaxis()->SetTitleOffset(4.);
  h2->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h2->GetXaxis()->SetLabelSize(27);

  c2->Update();
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data1.pdf");  
  c2->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data1.eps");  

  /////

  TCanvas *c3 = new TCanvas("c3", "c3", 900, 900);
  TPad *pad3 = new TPad("pad3", "pad3", 0, 0.3, 1, 1.0);
  pad3->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad3->Draw();             // Draw the upper pad: pad1
  pad3->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->SetTitle("");
  //reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->SetMaximum(1.);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->Draw("e1p");
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetYaxis()->SetTitle("No. of Entries");

  TH1F *hrebin2 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->Clone("hrebin2");
  
  for(int ii=0; ii<nbins2-1; ii++){
    hrebin2->SetBinError(ii+1,sqrt(stats2[ii]*stats2[ii] +syst2[ii]*syst2[ii]));
    //reco_angle_p1p2_OnBeam_PID_CM_rebin2->SetBinError(ii+1,sqrt(stats2[ii]*stats2[ii] +syst2[ii]*syst2[ii]));
    err2[ii] = hrebin2->GetBinError(ii+1);
  }

  hrebin2->Draw("e1 same");
  
  TLegend *l3 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l3 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2, "MicroBooNE on-beam data", "lep");
  l3 -> Draw();

  TText *t3 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t3->Draw();
  
  c3->cd();
  TPad *pad3_2 = new TPad("pad3_2", "pad3_2", 0, 0.05, 1, 0.3);
  pad3_2->SetTopMargin(0.01);
  pad3_2->SetBottomMargin(0.3);
  pad3_2->SetGridx();
  pad3_2->SetGridy();
  pad3_2->Draw();
  pad3_2->cd();
  // Define the ratio plot

  TH1F *h3 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->Clone("h3");
  TH1F *hbefore3 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_rebin2->Clone("hbefore3");

  h3->SetLineColor(kRed);
  h3->SetMarkerColor(kRed);
  h3->SetStats(0);      // No statistics on lower plot
  h3->Divide(hbefore3);
  h3->SetMarkerStyle(20);
  h3->SetTitle("");
  //h22->Draw("ep");       // Draw the ratio plot
  h3->Draw("histo p");      // Draw the ratio plot

  h3->GetYaxis()->SetTitle("after/before");
  h3->GetYaxis()->SetNdivisions(505);
  h3->GetYaxis()->SetTitleSize(20);
  h3->GetYaxis()->SetTitleFont(43);
  h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h3->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h3->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h3->GetXaxis()->SetTitleSize(25);
  h3->GetXaxis()->SetTitleFont(43);
  h3->GetXaxis()->SetTitleOffset(4.);
  h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h3->GetXaxis()->SetLabelSize(27);

  c3->Update();
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data2.pdf");  
  c3->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data2.eps");  

  ////  

  TCanvas *c4 = new TCanvas("c4", "c4", 900, 900);
  TPad *pad4 = new TPad("pad4", "pad4", 0, 0.3, 1, 1.0);
  pad4->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad4->Draw();             // Draw the upper pad: pad1
  pad4->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetTitle("");
  //reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMaximum(1.);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->Draw("e1p");
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->GetYaxis()->SetTitle("No. of Entries");

  TH1F *hrebin3 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->Clone("hrebin3");
  
  for(int ii=0; ii<nbins3-1; ii++){
    hrebin3->SetBinError(ii+1,sqrt(stats3[ii]*stats3[ii] +syst3[ii]*syst3[ii]));
    //reco_angle_p1p2_OnBeam_PID_CM_rebin3->SetBinError(ii+1,sqrt(stats3[ii]*stats3[ii] +syst3[ii]*syst3[ii]));
    err3[ii] = hrebin3->GetBinError(ii+1);
  }

  hrebin3->SetFillStyle(3002);
  hrebin3->SetFillColor(kAzure-6);
  //hrebin3->SetLineColor(kBlack);
  hrebin3->Draw("e1 same");
  
  TLegend *l4 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l4 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3, "MicroBooNE on-beam data", "flep");
  l4 -> Draw();

  TText *t4 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t4->Draw();
  
  c4->cd();
  TPad *pad4_2 = new TPad("pad4_2", "pad4_2", 0, 0.05, 1, 0.3);
  pad4_2->SetTopMargin(0.01);
  pad4_2->SetBottomMargin(0.3);
  pad4_2->SetGridx();
  pad4_2->SetGridy();
  pad4_2->Draw();
  pad4_2->cd();
  // Define the ratio plot

  TH1F *h4 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->Clone("h4");
  TH1F *hbefore4 = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_rebin3->Clone("hbefore4");

  h4->SetLineColor(kBlack);
  h4->SetMarkerColor(kRed);
  h4->SetStats(0);      // No statistics on lower plot
  h4->Divide(hbefore4);
  h4->SetMarkerStyle(20);
  h4->SetTitle("");
  //h22->Draw("ep");       // Draw the ratio plot
  h4->Draw("histo p");      // Draw the ratio plot

  h4->GetYaxis()->SetTitle("after/before");
  h4->GetYaxis()->SetNdivisions(505);
  h4->GetYaxis()->SetTitleSize(20);
  h4->GetYaxis()->SetTitleFont(43);
  h4->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h4->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h4->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h4->GetXaxis()->SetTitleSize(25);
  h4->GetXaxis()->SetTitleFont(43);
  h4->GetXaxis()->SetTitleOffset(4.);
  h4->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h4->GetXaxis()->SetLabelSize(27);

  c4->Update();
  c4->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data3.pdf");  
  c4->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data3.eps");  
  
  
  std::cout<<"...................................................."<<std::endl;
  std::cout<<"metiendo errores default........"<<std::endl;
  for(int ii=0; ii<nbins; ii++){
    std::cout<<"bin "<< ii<<std::endl;
    std::cout<<" bin content "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetBinContent(ii+1)<<" stats "<< stats[ii]<<" syst "<<syst[ii] <<std::endl;
    Double_t xcenter = reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin->GetXaxis()->GetBinCenter(ii+1);
    std::cout<<" bin content * syst "<<xcenter * syst[ii] <<std::endl;
    std::cout<<"error  "<<hrebin->GetBinError(ii+1)<<std::endl;
  }

  std::cout<<"...................................................."<<std::endl;
  std::cout<<"metiendo errores rebin1........"<<std::endl;
  for(int ii=0; ii<nbins1; ii++){
    std::cout<<"bin "<< ii<<std::endl;
    std::cout<<" bin content "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetBinContent(ii+1)<<" stats "<< stats1[ii]<<" syst "<<syst1[ii] <<std::endl;
    std::cout<<" bin content * syst "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin1->GetBinContent(ii+1) * syst1[ii] <<std::endl;
    std::cout<<"error  "<<hrebin1->GetBinError(ii+1)<<std::endl;
  }

  std::cout<<"...................................................."<<std::endl;
  std::cout<<"metiendo errores rebin2........"<<std::endl;
  for(int ii=0; ii<nbins2; ii++){
    std::cout<<"bin "<< ii<<std::endl;
    std::cout<<" bin content "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetBinContent(ii+1)<<" stats "<< stats2[ii]<<" syst "<<syst2[ii] <<std::endl;
    std::cout<<" bin content * syst "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin2->GetBinContent(ii+1) * syst2[ii] <<std::endl;
    std::cout<<"error  "<<hrebin2->GetBinError(ii+1)<<std::endl;
  }

  std::cout<<"...................................................."<<std::endl;
  std::cout<<"metiendo errores rebin3........"<<std::endl;
  for(int ii=0; ii<nbins3; ii++){
    std::cout<<"bin "<< ii<<std::endl;
    std::cout<<" bin content "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->GetBinContent(ii+1)<<" stats "<< stats3[ii]<<" syst "<<syst3[ii] <<std::endl;
    std::cout<<" bin content * syst "<<reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->GetBinContent(ii+1) * syst3[ii] <<std::endl;
    std::cout<<"error  "<<hrebin3->GetBinError(ii+1)<<std::endl;
  }     

  
  //////

  TCanvas *c5 = new TCanvas("c5", "c5", 900, 900);
  TPad *pad5 = new TPad("pad5", "pad5", 0, 0.3, 1, 1.0);
  pad5->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad5->Draw();             // Draw the upper pad: pad1
  pad5->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetLineColor(kAzure+4);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetMarkerStyle(21);// squaer, 22 para triangulo
  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetMarkerColor(kAzure+4);
  //reco_angle_p1p2_OnBeam_PID_CM_zoom->SetMaximum(1.);
  reco_angle_p1p2_OnBeam_PID_CM_zoom->SetTitle("");
  reco_angle_p1p2_OnBeam_PID_CM_zoom-> Draw("ep");
  reco_angle_p1p2_OnBeam_PID_CM_zoom->GetYaxis()->SetTitle("No. of Entries");

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Draw("ep same");
  
  TLegend *l5 = new TLegend(0.45, 0.65, 0.9, 0.9);
  //l2 -> SetNColumns(2);
  l5 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom, "#nu_{#mu} CC2Proton after cuts", "lep");
  l5 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM_zoom, "#nu_{#mu} CC2Proton before cuts", "lep");
  l5 -> Draw();

  TText *t5 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
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

  TH1F *h5_2 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Clone("h5_2");
  TH1F *h5_before = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_zoom->Clone("h5_before");

  h5_2->SetLineColor(kBlack);
  //  h5_2->SetStats(0);      // No statistics on lower plot
  h5_2->Sumw2();
  h5_2->Sumw2();
  h5_2->Divide(h5_before);
  h5_2->SetMarkerStyle(21);
  h5_2->SetMaximum(1.);
  h5_2->SetTitle("");
  h5_2->Draw("ep");       // Draw the ratio plot
  //h5_2->Draw("histo p");      // Draw the ratio plot

  h5_2->GetYaxis()->SetTitle("after/before");
  h5_2->GetYaxis()->SetNdivisions(505);
  h5_2->GetYaxis()->SetTitleSize(20);
  h5_2->GetYaxis()->SetTitleFont(43);
  h5_2->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h5_2->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  h5_2->GetXaxis()->SetTitle("cos #gamma_{CM}");
  h5_2->GetXaxis()->SetTitleSize(20);
  h5_2->GetXaxis()->SetTitleFont(43);
  h5_2->GetXaxis()->SetTitleOffset(3.);
  h5_2->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  h5_2->GetXaxis()->SetLabelSize(15);

  c5->Update();
  c5->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data_defaultbinning.pdf");  
  c5->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data_defaultbinning.eps");  

  //////////

  TCanvas *c6 = new TCanvas("c6", "c6", 900, 900);
  //TPad *pad6 = new TPad("pad6", "pad6", 0, 0.3, 1, 1.0);
  //pad6->SetBottomMargin(0.01); // Upper and lower plot are joined
  //pad6->Draw();             // Draw the upper pad: pad1
  //pad6->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMarkerSize(1.5);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetTitle("");
  //reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMaximum(1.);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->Draw("e1p");
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->GetYaxis()->SetTitle("No. of Entries");
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->GetXaxis()->SetTitle("cos #gamma_{CM}");

  TH1F *hrebin6 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->Clone("hrebin6");
  
  for(int ii=0; ii<nbins3-1; ii++){
    hrebin6->SetBinError(ii+1,sqrt(stats3[ii]*stats3[ii] +syst3[ii]*syst3[ii]));
    //reco_angle_p1p2_OnBeam_PID_CM_rebin3->SetBinError(ii+1,sqrt(stats3[ii]*stats3[ii] +syst3[ii]*syst3[ii]));
    err3[ii] = hrebin6->GetBinError(ii+1);
  }

  hrebin6->SetFillStyle(3002);
  hrebin6->SetFillColor(kViolet-5);
  //hrebin6->SetLineColor(kBlack);
  hrebin6->Draw("e2 same");
  
  TLegend *l6 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l6 -> AddEntry(hrebin6, "on-beam data (stats+syst)", "flep");
  l6 -> Draw();

  TText *t6 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t6->Draw();
  
  c6->Update();
  c6->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data3_noratio.pdf");  
  c6->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_nobtblowPT_data3_noratio.eps");  


  /////

  TCanvas *c7 = new TCanvas("c7", "c7", 900, 900);
  //  TPad *pad7 = new TPad("pad7", "pad7", 0, 0.3, 1, 1.0);
  //pad7->SetBottomMargin(0.01); // Upper and lower plot are joined
  //pad7->Draw();             // Draw the upper pad: pad1
  //pad7->cd();              // pad1 becomes the current pad

  reco_angle_p1p2_OnBeam_PID_CM_rebin3->SetLineColor(kAzure+4);
  reco_angle_p1p2_OnBeam_PID_CM_rebin3->SetMarkerStyle(21);// squaer, 22 para triangulo
  reco_angle_p1p2_OnBeam_PID_CM_rebin3->SetMarkerColor(kAzure+4);
  //reco_angle_p1p2_OnBeam_PID_CM_rebin3->SetMaximum(1.);
  reco_angle_p1p2_OnBeam_PID_CM_rebin3->SetTitle("");
  reco_angle_p1p2_OnBeam_PID_CM_rebin3-> Draw("ep");
  reco_angle_p1p2_OnBeam_PID_CM_rebin3->GetYaxis()->SetTitle("No. of Entries");
  reco_angle_p1p2_OnBeam_PID_CM_rebin3->GetXaxis()->SetTitle("cos #gamma_{CM}");

  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3->Draw("ep same");

  reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3->SetLineColor(kRed);
  reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3->SetMarkerColor(kRed);
  reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3->Draw("ep same");

  reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->SetLineColor(kGreen);
  reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->SetMarkerColor(kGreen);
  reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->Draw("ep same");
  
  TLegend *l7 = new TLegend(0.45, 0.65, 0.9, 0.9);
  //l7 -> SetNColumns(2);
  l7 -> AddEntry(reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_rebin3, "All cuts", "lep");
  l7 -> AddEntry(reco_angle_p1p2_OnBeam_PID_CM_rebin, "No cuts", "lep");
  l7 -> AddEntry(reco_angle_p1p2_OnBeam_PT_PID_CM_rebin3, "Low PT", "lep");
  l7 -> AddEntry(reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3, "No Hammer", "lep");
  l7 -> Draw();

  TText *t7 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t7->Draw();
  
  //c7->cd();
  //TPad *pad7_2 = new TPad("pad7_2", "pad7_2", 0, 0.05, 1, 0.3);
  //pad7_2->SetTopMargin(0.01);
  //pad7_2->SetBottomMargin(0.2);
  //pad7_2->SetGridx();
  //pad7_2->SetGridy();
  //pad7_2->Draw();
  //pad7_2->cd();
  // Define the ratio plot

  //TH1F *h7_2 = (TH1F*)reco_angle_p1p2_OnBeam_nobtbLF_PT_PID_CM_zoom->Clone("h7_2");
  //TH1F *h7_before = (TH1F*)reco_angle_p1p2_OnBeam_PID_CM_zoom->Clone("h7_before");

  //h7_2->SetLineColor(kBlack);
  //h7_2->Sumw2();
  //h7_2->Sumw2();
  //h7_2->Divide(h5_before);
  //h7_2->SetMarkerStyle(21);
  //h7_2->SetMaximum(1.);
  //h7_2->SetTitle("");
  //h7_2->Draw("ep");       // Draw the ratio plot

  //h7_2->GetYaxis()->SetTitle("after/before");
  //h7_2->GetYaxis()->SetNdivisions(505);
  //h7_2->GetYaxis()->SetTitleSize(20);
  //h7_2->GetYaxis()->SetTitleFont(43);
  //h7_2->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h7_2->GetYaxis()->SetLabelSize(15);

  // X axis ratio plot settings
  //h7_2->GetXaxis()->SetTitle("cos #gamma_{CM}");
  //h7_2->GetXaxis()->SetTitleSize(20);
  //h7_2->GetXaxis()->SetTitleFont(43);
  //h7_2->GetXaxis()->SetTitleOffset(3.);
  //h7_2->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
  //h7_2->GetXaxis()->SetLabelSize(15);

  c7->Update();
  c7->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_bycut_data.pdf");  
  c7->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_bycut_data.eps");  
  ////

  TCanvas *c8 = new TCanvas("c8", "c8", 900, 900);

  reco_PT_OnBeam_PID->SetLineColor(kAzure+4);
  reco_PT_OnBeam_PID->SetMarkerStyle(21);// square, 22 para triangulo
  reco_PT_OnBeam_PID->SetMarkerColor(kAzure+4);
  reco_PT_OnBeam_PID->SetTitle("");
  reco_PT_OnBeam_PID-> Draw("ep");
  reco_PT_OnBeam_PID->GetYaxis()->SetTitle("No. of Entries");
  reco_PT_OnBeam_PID->GetXaxis()->SetTitle("p^{T}_{miss} [GeV/c]");

  reco_PT_OnBeam_1binCM_PID->SetLineColor(kBlack);
  reco_PT_OnBeam_1binCM_PID->SetMarkerColor(kBlack);
  reco_PT_OnBeam_1binCM_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_1binCM_PID->Draw("ep same");

  reco_PT_OnBeam_1binCM_lowPT_PID->SetLineColor(kRed);
  reco_PT_OnBeam_1binCM_lowPT_PID->SetMarkerColor(kRed);
  reco_PT_OnBeam_1binCM_lowPT_PID->SetMarkerStyle(20);
  reco_PT_OnBeam_1binCM_lowPT_PID->Draw("ep same");

  //reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->SetLineColor(kGreen);
  //reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->SetMarkerColor(kGreen);
  //reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->SetMarkerStyle(20);
  //reco_angle_p1p2_OnBeam_btb_PID_CM_rebin3->Draw("ep same");
  
  TLegend *l8 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l8 -> AddEntry(reco_PT_OnBeam_PID, "No cuts", "lep");
  l8 -> AddEntry(reco_PT_OnBeam_1binCM_PID, "No cuts, cos#gamma_{CM}<-0.9", "lep");
  l8 -> AddEntry(reco_PT_OnBeam_1binCM_lowPT_PID, "p^{T}_{miss}<300, cos#gamma_{CM}<-0.9", "lep");
  l8 -> Draw();

  TText *t8 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t8->Draw();

  c8->Update();
  c8->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/pT_bycut_data.pdf");  
  c8->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/pT_bycut_data.eps");

  TCanvas *c9 = new TCanvas("c9", "c9", 900, 900);

  reco_projprel_OnBeam->SetLineColor(kAzure+4);
  reco_projprel_OnBeam->SetMarkerStyle(21);// square, 22 para triangulo
  reco_projprel_OnBeam->SetMarkerColor(kAzure+4);
  reco_projprel_OnBeam->SetTitle("");
  reco_projprel_OnBeam-> Draw("ep");
  reco_projprel_OnBeam->GetYaxis()->SetTitle("No. of Entries");
  reco_projprel_OnBeam->GetXaxis()->SetTitle("p^{#perp}_{p1-p2} [GeV/c]");

  reco_projprel_OnBeam_1binCM->SetLineColor(kBlack);
  reco_projprel_OnBeam_1binCM->SetMarkerColor(kBlack);
  reco_projprel_OnBeam_1binCM->SetMarkerStyle(20);
  reco_projprel_OnBeam_1binCM->Draw("ep same");

  reco_projprel_OnBeam_lowPT->SetLineColor(kRed);
  reco_projprel_OnBeam_lowPT->SetMarkerColor(kRed);
  reco_projprel_OnBeam_lowPT->SetMarkerStyle(20);
  reco_projprel_OnBeam_lowPT->Draw("ep same");

  reco_projprel_OnBeam_lowPT_1binCM->SetLineColor(kGreen);
  reco_projprel_OnBeam_lowPT_1binCM->SetMarkerColor(kGreen);
  reco_projprel_OnBeam_lowPT_1binCM->SetMarkerStyle(20);
  reco_projprel_OnBeam_lowPT_1binCM->Draw("ep same");
  
  TLegend *l9 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l9 -> AddEntry(reco_projprel_OnBeam, "No cuts", "lep");
  l9 -> AddEntry(reco_projprel_OnBeam_1binCM, "No cuts, cos#gamma_{CM}<-0.9", "lep");
  l9 -> AddEntry(reco_projprel_OnBeam_lowPT, "p^{T}_{miss}<300", "lep");
  l9 -> AddEntry(reco_projprel_OnBeam_lowPT_1binCM, "p^{T}_{miss}<300, cos#gamma_{CM}<-0.9", "lep");
  l9 -> Draw();

  TText *t9 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t9->Draw();

  c9->Update();
  c9->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prel_bycut_data.pdf");  
  c9->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/prel_bycut_data.eps");  
  
  TCanvas *c10 = new TCanvas("c10", "c10", 900, 900);

  reco_pn_OnBeam_PID_all->SetLineColor(kAzure+4);
  reco_pn_OnBeam_PID_all->SetMarkerStyle(21);// square, 22 para triangulo
  reco_pn_OnBeam_PID_all->SetMarkerColor(kAzure+4);
  reco_pn_OnBeam_PID_all->SetTitle("");
  reco_pn_OnBeam_PID_all-> Draw("ep");
  reco_pn_OnBeam_PID_all->GetYaxis()->SetTitle("No. of Entries");
  reco_pn_OnBeam_PID_all->GetXaxis()->SetTitle("p_{n} [GeV/c]");

  reco_pn_OnBeam_PID_lowPT->SetLineColor(kRed);
  reco_pn_OnBeam_PID_lowPT->SetMarkerColor(kRed);
  reco_pn_OnBeam_PID_lowPT->SetMarkerStyle(20);
  reco_pn_OnBeam_PID_lowPT->Draw("ep same");

  reco_pn_OnBeam_PID_lowPT_1stbin->SetLineColor(kGreen);
  reco_pn_OnBeam_PID_lowPT_1stbin->SetMarkerColor(kGreen);
  reco_pn_OnBeam_PID_lowPT_1stbin->SetMarkerStyle(20);
  reco_pn_OnBeam_PID_lowPT_1stbin->Draw("ep same");
  
  TLegend *l10 = new TLegend(0.45, 0.65, 0.9, 0.9);
  l10 -> AddEntry(reco_pn_OnBeam_PID_all, "No cuts", "lep");
  l10 -> AddEntry(reco_pn_OnBeam_PID_lowPT, "p^{T}_{miss}<300", "lep");
  l10 -> AddEntry(reco_pn_OnBeam_PID_lowPT_1stbin, "p^{T}_{miss}<300, cos#gamma_{CM}<-0.9", "lep");
  l10 -> Draw();

  TText *t10 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t10->Draw();

  c10->Update();
  c10->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/pn_bycut_data.pdf");  
  c10->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/pn_bycut_data.eps");  
  
  ///////// final

  //gStyle->SetTitleOffset(2,"y");
  TCanvas *c11 = new TCanvas("c11", "c11", 900, 900);

  reco_angle_p1p2_OnBeam_PT_CM_rebin3->SetLineColor(kBlack);
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->SetMarkerColor(kBlack);
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->SetMarkerStyle(20);
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->SetMarkerSize(1.5);
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->SetTitle("");
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->Draw("e1p");
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->GetYaxis()->SetTitle("No. of Entries");
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->GetYaxis()->SetTitleOffset(1.4);
  reco_angle_p1p2_OnBeam_PT_CM_rebin3->GetXaxis()->SetTitle("cos #gamma_{CM}");

  TH1F *hrebin11 = (TH1F*)reco_angle_p1p2_OnBeam_PT_CM_rebin3->Clone("hrebin11");
  
  for(int ii=0; ii<nbins3-1; ii++){
    hrebin11->SetBinError(ii+1,sqrt(stats11[ii]*stats11[ii] +syst11[ii]*syst11[ii]));
    err11[ii] = hrebin11->GetBinError(ii+1);
  }

  hrebin11->SetFillStyle(3002);
  hrebin11->SetFillColor(kViolet-5);
  //hrebin1->SetLineColor(kBlack);
  hrebin11->Draw("e2 same");
  
  TLegend *l11 = new TLegend(0.5, 0.7, 0.9, 0.9);
  l11 -> AddEntry(hrebin11, "on-beam data (stats+syst)", "flep");
  l11 -> Draw();

  TText *t11 = drawPrelim(0.1, 0.91, 0.052, "MicroBooNE data. 1.592e20 POT");
  t11->Draw();

  //  TLine *fcandidate=new TLine(-0.9,0.,-0.9,103.);
  // fcandidate->SetLineColor(kGreen+3);
  // fcandidate->SetLineWidth(3);
  // fcandidate->Draw("same");

  c11->Update();
  c11->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_lowPT_data_noratio.pdf");  
  c11->Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/techNote/cosCM_lowPT_data_noratio.eps");  
  
  
  }
