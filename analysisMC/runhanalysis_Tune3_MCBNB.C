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

void runhanalysis_Tune3_MCBNB() {
  
  TChain chain("SimpleAna/cc1unptree");
  
  FILE *input;
  char filename[300];
  chain.Add("/pnfs/uboone/persistent/users/rcastill/CC0Pion2P/MCC8_Tune1_CCNProton/resultMCtune3_3.root");

  std::cout<<"start processing the analysis"<<std::endl;

  chain.Process("hanalysis_fMC_Tune3.C");
  std::cout<<"end analysis"<<std::endl;
}
  
