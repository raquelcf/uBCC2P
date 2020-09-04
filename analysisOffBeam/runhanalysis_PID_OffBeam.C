#include "TROOT.h"
#include "TChain.h"
#include "TSystem.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <TFile.h>
#include <TH1.h>
#include <TLine.h>
#include <TTree.h>

void runhanalysis_PID_OffBeam() {
  
  TChain chain("SimpleAna/cc1unptree");
  
  FILE *input;
  char filename[300];
  chain.Add("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/PlotsPID/files/merged_output_Aug092018_2135_v4/ubxsec_output_data_extbnb_merged.root");

  std::cout<<"start processing the analysis"<<std::endl;

  chain.Process("hanalysis_fOffBeam_PID.C");
  std::cout<<"end analysis"<<std::endl;
}
  
