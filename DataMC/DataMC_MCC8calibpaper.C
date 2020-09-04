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

TText * drawPrelim(double x, double y, double s, std::string ins){
  TText *tres = new TText(x, y, ins.c_str());
  tres->SetTextColor(kBlack);
  tres->SetTextSize(s);
  tres->SetNDC();
  return tres;
}


double Chi2Calc(TH1 *histo_MC, TH1D *histo_bnb, TH1D *histo_extbnb, double scale_offbeam, double norm_MC){
  int nbins=histo_MC->GetNbinsX();
  int nbinsdata=0;
  int N_MC[nbins], N_BNB[nbins], N_EXTBNB[nbins];
  double Chi2=0.0;
  /// area normalized
  double intMC = (histo_MC->GetEntries())*norm_MC;
  double intOffBeam = (histo_extbnb->GetEntries())*scale_offbeam;
  double intOnBeam = histo_bnb->GetEntries();

  Double_t global = 0.547177;
  intMC =  intMC*global;
  intOffBeam = intOffBeam*global; 

  //std::cout<<"entries MC "<< intMC<<" entries off beam "<<intOffBeam<<std::endl;
  for(int ii=0; ii<nbins-1; ii++){
     N_MC[ii]=histo_MC->GetBinContent(ii+1);
     N_BNB[ii]=histo_bnb->GetBinContent(ii+1);
     N_EXTBNB[ii]=histo_extbnb->GetBinContent(ii+1);
     if(N_BNB[ii]>0 && N_MC[ii]>0){
       Chi2 +=pow((N_MC[ii]*norm_MC+N_EXTBNB[ii]*scale_offbeam-N_BNB[ii]),2)/(N_MC[ii]*norm_MC +N_EXTBNB[ii]*scale_offbeam);
       nbinsdata++;
     }
  }
  std::cout<<"  chi2test : "<<Chi2<<" ndof: "<<nbinsdata<<" chi2/ndof: "<<Chi2/nbinsdata<<std::endl;

  return Chi2/nbinsdata;
}

void DataMC_MCC8calibpaper(){ 
  
  //  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_BNBMC.root","READ");
  TFile* BNBMC = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_300_BNBMC.root","READ");
  TFile* OnBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OnBeam.root","READ");
  TFile* OffBeam = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OffBeam.root","READ");

  std::cout<<"antes de Tfile"<<std::endl;
  
  ofstream outfileDataMC_PID;
  outfileDataMC_PID.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/chi2_2P_DataMCcaliMCC8_paper.txt");

  ////// BNB MC

  TH1D* selproton_dEdx_PID_MC = (TH1D*) BNBMC->Get("selproton_dEdx_PID_MC");

  //// On-Beam data

  TH1D* selproton_dEdx_OnBeam_PID = (TH1D*) OnBeam->Get("selproton_dEdx_OnBeam_PID");
  TH1D* selmuon_dEdx_OnBeam_PID = (TH1D*) OnBeam->Get("selmuon_dEdx_OnBeam_PID");
  TH1D* selprotonold_dEdx_OnBeam_PID = (TH1D*) OnBeam->Get("selprotonold_dEdx_OnBeam_PID");
  TH1D* selprotonnew_dEdx_OnBeam_PID = (TH1D*) OnBeam->Get("selprotonnew_dEdx_OnBeam_PID");

  /// valores de las normalizaciones

  //Double_t normMCBNB =  (4.411e+19)/(4.0878e+20);//tune 3
  Double_t normMCBNB =  (4.411e+19)/(2.010e+20);//(4.874e+19)/(1.566e+20);
  Double_t normOffBeam = 9775610./73710197.;  //0.1464;//(33320382.)/(36177265.);

  Double_t global = 0.547177;
  normMCBNB =  normMCBNB*global;
  normOffBeam = normOffBeam*global; 

  //Double_t normOffBeam = 9775610./35789730.;  //0.1464;//(33320382.)/(36177265.);
  //h->Scale(1/norm);

  /// normalizing MC
  std::cout<<"antes del scale"<<std::endl;
  std::cout<<"normMCBNB : "<<normMCBNB<<std::endl;
  std::cout<<"normOffBeam : "<<normOffBeam<<std::endl;

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


  //// calib paper

  selmuon_dEdx_OnBeam_PID->Scale(1/20.);

  TCanvas *c44 = new TCanvas("c44", "c44", 900, 900);

  selmuon_dEdx_OnBeam_PID->SetMarkerColor(kRed+2);
  selmuon_dEdx_OnBeam_PID->SetLineColor(kRed+2);
  selmuon_dEdx_OnBeam_PID->SetMarkerStyle(20);
  selmuon_dEdx_OnBeam_PID->SetMarkerSize(1);
  selmuon_dEdx_OnBeam_PID->GetYaxis()->SetTitle("No. of Entries");
  selmuon_dEdx_OnBeam_PID->GetXaxis()->SetTitle("dE/dx (MeV/cm)");
  selmuon_dEdx_OnBeam_PID->Draw("e1");
  //selmuon_dEdx_OnBeam_PID->Draw("L");
  selmuon_dEdx_OnBeam_PID->GetYaxis()->SetTitleOffset(1.6);

  selproton_dEdx_OnBeam_PID->SetMarkerColor(kAzure+2);
  selproton_dEdx_OnBeam_PID->SetLineColor(kAzure+2);
  selproton_dEdx_OnBeam_PID->SetMarkerStyle(20);
  selproton_dEdx_OnBeam_PID->SetMarkerSize(1);
  //selproton_dEdx_OnBeam_PID->Draw("same L e1");
  selproton_dEdx_OnBeam_PID->Draw("same e1");

  TLegend *l44 = new TLegend(0.35, 0.75, 0.9, 0.9); 
  l44 -> AddEntry(selmuon_dEdx_OnBeam_PID, "muon MicroBooNE data", "lep");
  l44 -> AddEntry(selproton_dEdx_OnBeam_PID, "proton MicroBooNE data", "lep");
  l44 -> Draw();  
  
  TText *t44 = drawPrelim(0.1, 0.91, 0.039, "MicroBooNE");
  t44->Draw();

  c44->Update();
  c44->Print("/pnfs/uboone/persistent/users/rcastill/CC0Pion2P/Plots/BNBCosmicMC/recombinationPaper/dEdx_OnBeam_MCC8paper.pdf");  


  selproton_dEdx_PID_MC->Scale(0.46);

  TCanvas *c45 = new TCanvas("c45", "c45", 900, 900);

  selproton_dEdx_PID_MC->SetMarkerColor(kBlack);
  selproton_dEdx_PID_MC->SetLineColor(kBlack);
  selproton_dEdx_PID_MC->SetMarkerStyle(20);
  selproton_dEdx_PID_MC->SetLineWidth(2);
  selproton_dEdx_PID_MC->GetYaxis()->SetTitle("No. of Entries");
  selproton_dEdx_PID_MC->GetXaxis()->SetTitle("dE/dx (MeV/cm)");
  selproton_dEdx_PID_MC->Draw("histo e");
  //  selproton_dEdx_PID_MC->Draw("L e1");
  selproton_dEdx_PID_MC->GetYaxis()->SetTitleOffset(1.6);

  selproton_dEdx_OnBeam_PID->SetMarkerColor(kAzure+2);
  selproton_dEdx_OnBeam_PID->SetLineColor(kAzure+2);
  selproton_dEdx_OnBeam_PID->SetMarkerStyle(20);
  selproton_dEdx_OnBeam_PID->SetMarkerSize(1);
  //selproton_dEdx_OnBeam_PID->Draw("same L e1");
  selproton_dEdx_OnBeam_PID->Draw("same e1");

  TLegend *l45 = new TLegend(0.35, 0.75, 0.9, 0.9); 
  l45 -> AddEntry(selproton_dEdx_PID_MC, "proton simulation", "lep");
  l45 -> AddEntry(selproton_dEdx_OnBeam_PID, "proton MicroBooNE data", "lep");
  l45 -> Draw();  
  
  TText *t45 = drawPrelim(0.1, 0.91, 0.039, "MicroBooNE");
  t45->Draw();

  c45->Update();
  c45->Print("/pnfs/uboone/persistent/users/rcastill/CC0Pion2P/Plots/BNBCosmicMC/recombinationPaper/dEdx_protondataMC_MCC8paper.pdf");  
  ////////////////

  TCanvas *c46 = new TCanvas("c46", "c46", 900, 900);

  selproton_dEdx_PID_MC->SetMarkerColor(kBlack);
  selproton_dEdx_PID_MC->SetLineColor(kBlack);
  selproton_dEdx_PID_MC->SetMarkerStyle(20);
  selproton_dEdx_PID_MC->SetLineWidth(2);
  selproton_dEdx_PID_MC->GetYaxis()->SetTitle("No. of Entries");
  selproton_dEdx_PID_MC->GetXaxis()->SetTitle("dE/dx (MeV/cm)");
  selproton_dEdx_PID_MC->Draw("histo e");
  selproton_dEdx_PID_MC->GetYaxis()->SetTitleOffset(1.6);

  selprotonold_dEdx_OnBeam_PID->SetMarkerColor(kAzure+2);
  selprotonold_dEdx_OnBeam_PID->SetLineColor(kAzure+2);
  selprotonold_dEdx_OnBeam_PID->SetMarkerStyle(20);
  selprotonold_dEdx_OnBeam_PID->SetMarkerSize(1);
  selprotonold_dEdx_OnBeam_PID->Draw("same e1");

  TLegend *l46 = new TLegend(0.35, 0.75, 0.9, 0.9); 
  l46 -> AddEntry(selproton_dEdx_PID_MC, "proton simulation", "lep");
  l46 -> AddEntry(selprotonold_dEdx_OnBeam_PID, "proton MicroBooNE data", "lep");
  l46 -> Draw();  
  
  TText *t46 = drawPrelim(0.1, 0.91, 0.039, "MicroBooNE");
  t46->Draw();

  c46->Update();
  c46->Print("/pnfs/uboone/persistent/users/rcastill/CC0Pion2P/Plots/BNBCosmicMC/recombinationPaper/dEdxold_protondataMC_MCC8paper.pdf");  

  TCanvas *c47 = new TCanvas("c47", "c47", 900, 900);

  selproton_dEdx_PID_MC->SetMarkerColor(kBlack);
  selproton_dEdx_PID_MC->SetLineColor(kBlack);
  selproton_dEdx_PID_MC->SetMarkerStyle(20);
  selproton_dEdx_PID_MC->SetLineWidth(2);
  selproton_dEdx_PID_MC->GetYaxis()->SetTitle("No. of Entries");
  selproton_dEdx_PID_MC->GetXaxis()->SetTitle("dE/dx (MeV/cm)");
  selproton_dEdx_PID_MC->Draw("histo e");
  selproton_dEdx_PID_MC->GetYaxis()->SetTitleOffset(1.6);

  selprotonnew_dEdx_OnBeam_PID->SetMarkerColor(kAzure+2);
  selprotonnew_dEdx_OnBeam_PID->SetLineColor(kAzure+2);
  selprotonnew_dEdx_OnBeam_PID->SetMarkerStyle(20);
  selprotonnew_dEdx_OnBeam_PID->SetMarkerSize(1);
  selprotonnew_dEdx_OnBeam_PID->Draw("same e1");

  TLegend *l47 = new TLegend(0.35, 0.75, 0.9, 0.9); 
  l47 -> AddEntry(selproton_dEdx_PID_MC, "proton simulation", "lep");
  l47 -> AddEntry(selprotonnew_dEdx_OnBeam_PID, "proton MicroBooNE data", "lep");
  l47 -> Draw();  
  
  TText *t47 = drawPrelim(0.1, 0.91, 0.039, "MicroBooNE");
  t47->Draw();

  c47->Update();
  c47->Print("/pnfs/uboone/persistent/users/rcastill/CC0Pion2P/Plots/BNBCosmicMC/recombinationPaper/dEdxne_protondataMC_MCC8paper.pdf");  


}
