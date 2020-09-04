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

void runhanalysis_Tune3_PID() {
  
  TChain chain("SimpleAna/cc1unptree");
  
  FILE *input;
  char filename[300];
  chain.Add("/uboone/app/users/rcastill/cc1muNp_git_integration/work/files/resultMCtune3_3.root");

  std::cout<<"start processing the analysis"<<std::endl;

  chain.Process("hanalysis_Tune3_PID.C");
  std::cout<<"end analysis"<<std::endl;
}
  
