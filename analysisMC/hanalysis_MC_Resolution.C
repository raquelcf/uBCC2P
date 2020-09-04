#define hanalysis_MC_Resolution_cxx
// The class definition in hanalysis_MC_Resolution.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("hanalysis_MC_Resolution.C")
// root> T->Process("hanalysis_MC_Resolution.C","some options")
// root> T->Process("hanalysis_MC_Resolution.C+")
//

#include "hanalysis_MC_Resolution.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TMath.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfile_MCResolution;
TFile *fanalysis_Resolution;
TTree *err = new TTree("err","error vector");

const int nmax = 10000;

/// para escribir en los Trees// (x,y) // (truth, reco) // truth CC2Protons
TH2D *truth_reco_p1_nocuts;
TH2D *truth_reco_p2_nocuts;
TH2D *truth_reco_pn_nocuts;
TH2D *truth_reco_cosp1p2LF;
TH2D *truth_reco_pT_nocuts;
TH2D *truth_reco_Enu_nocuts;
TH2D *truth_reco_q2_nocuts;
TH2D *truth_reco_cospnp2CM_nocuts;

TH2D *Truth_reco_Enu_nocuts;

TH2D *truth_reco_cospnp2CM_nobtb;

TH2D *Truth_reco_Enu_nobtb;

TH2D *truth_reco_p1_nobtblowPT;
TH2D *truth_reco_p2_nobtblowPT;
TH2D *truth_reco_pn_nobtblowPT;
TH2D *truth_reco_Enu_nobtblowPT;
TH2D *truth_reco_q2_nobtblowPT;
TH2D *truth_reco_cospnp2CM_nobtblowPT;

TH2D *Truth_reco_Enu_nobtblowPT;

TH2D *truth_reco_p1_nobtblowPTSRC;
TH2D *truth_reco_p2_nobtblowPTSRC;
TH2D *truth_reco_pn_nobtblowPTSRC;
TH2D *truth_reco_Enu_nobtblowPTSRC;
TH2D *truth_reco_q2_nobtblowPTSRC;
TH2D *truth_reco_cospnp2CM_nobtblowPTSRC;

TH2D *Truth_reco_Enu_nobtblowPTSRC;

/////

Int_t n1 = 0, n2=0;/// selected lowPT, no hammer

std::vector<double> Enureco_n1;
std::vector<double> Enutruth_n1;

std::vector<double>  truth_p1_nobtblowPT;
std::vector<double>  reco_p1_nobtblowPT;
std::vector<double>  truth_p2_nobtblowPT;
std::vector<double>  reco_p2_nobtblowPT;
std::vector<double>  truth_pn_nobtblowPT;
std::vector<double>  reco_pn_nobtblowPT;
std::vector<double>  truth_cosp1p2LF_nobtblowPT;
std::vector<double>  reco_cosp1p2LF_nobtblowPT;
std::vector<double>  truth_pT_nobtblowPT;
std::vector<double>  reco_pT_nobtblowPT;
std::vector<double>  EnuTruthreco_nobtblowPT;
std::vector<double>  truth_q2_nobtblowPT;
std::vector<double>  reco_q2_nobtblowPT;
std::vector<double>  truth_cospnp2CM_nobtblowPT;
std::vector<double>  reco_cospnp2CM_nobtblowPT;

const int nbinscLF = 13;
const double binscLF[nbinscLF+1] = { -1.,-0.95,-0.9,-0.8,-0.7,-0.6,-0.4,-0.2,0.,0.2,0.4,0.6,0.8,1.};
const int nbinscCM = 7;
const double binscCM[nbinscCM+1] = { -1.,-0.95,-0.9,-0.85,-0.8,-0.4,0.,1.};
const int nbinsEnu = 6;
const double binsEnu[nbinsEnu+1] = {0.,0.4,0.6,0.8,1.,1.4,2.};
const int nbinsp = 7;
const double binsp[nbinsp+1] = {0.,0.3,0.4,0.5,0.6,0.7,0.8,2};
const int nbinspT = 10;
const double binspT[nbinspT+1] = {0.,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.5,0.6,2.};
const int nbinsq2 = 5;
const double binsq2[nbinsq2+1] = {0.,0.1,0.2,0.3,0.8,2.};

///////////////////////////// binning for error profiles

//const int nbinscLFerr = 12;
//const double binscLFerr[nbinscLFerr+1] = { -1.,-0.95,-0.9,-0.8,-0.7,-0.6,-0.4,-0.2,0.,0.2,0.4,0.6,1.};

const int nbinscLFerr = 20;
const double binscLFerr[nbinscLFerr+1] = { -1.,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0.,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.};

//const int nbinscLFerr = 18;
//const double binscLFerr[nbinscLFerr+1] = { -1.,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,-0.1,0.,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.};

//const int nbinscLFerr = 17;
//const double binscLFerr[nbinscLFerr+1] = { -1.,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,0.,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.};

//const int nbinscLFerr = 16;
//const double binscLFerr[nbinscLFerr+1] = { -1.,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,0.,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.};

//const int nbinscLFerr = 18;
//const double binscLFerr[nbinscLFerr+1] = { -1.,-0.9,-0.8,-0.7,-0.6,-0.5,-0.4,-0.3,-0.2,0.,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.};

//const int nbinscCMerr = 5;
//const double binscCMerr[nbinscCMerr+1] = { -1.,-0.95,-0.9,-0.8,-0.4,1.};
const int nbinsEnuerr = 4;
const double binsEnuerr[nbinsEnuerr+1] = {0.,0.6,0.8,1.,2.};
const int nbinsperr = 6;
const double binsperr[nbinsperr+1] = {0.,0.3,0.4,0.5,0.6,0.7,2};
const int nbinspTerr = 10;
const double binspTerr[nbinspTerr+1] = {0.,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.5,0.6,2.};

//const int nbinscCMerr = 4;
//const double binscCMerr[nbinscCMerr+1] = { -1.,-0.95,-0.9,-0.8,1.};

//const int nbinscCMerr = 4; // default
//const double binscCMerr[nbinscCMerr+1] = { -1.,-0.9,-0.8,-0.6,1.};

//const int nbinscCMerr = 5; // prueba 1
//const double binscCMerr[nbinscCMerr+1] = { -1.,-0.9,-0.8,-0.6,0.,1.};

//const int nbinscCMerr = 6; // prueba 2
//const double binscCMerr[nbinscCMerr+1] = { -1.,-0.9,-0.8,-0.6,0.,0.4,1.};

const int nbinscCMerr = 9; // prueba 2
const double binscCMerr[nbinscCMerr+1] = { -1.,-0.9,-0.8,-0.6,-0.4,-0.2,0.,0.2,0.5,1.};

float err2cosCM[nbinscCMerr+1];
float err2cosgamma[nbinscCMerr+1];
float nentries[nmax];
float err2CM =0.;
float errorcCMreco=0.;
int nerr =0;

float err2cosgammanocut[nbinscCMerr+1];
int nerrnocut =0;
float nentriesnocuts[nmax];

float err2cosgammanocutLF[nbinscCMerr+1];
float nentriesnocutsLF[nmax];
///////////////////////

TProfile *hprof_p1_nobtblowPT;
TProfile *hprof_p2_nobtblowPT;
TProfile *hprof_pn_nobtblowPT;
TProfile *hprof_cosp1p2LF_nobtblowPT;
TProfile *hprof_pT_nobtblowPT;
TProfile *hprof_TruthEnu_nobtblowPT;////// reco vis - true vis
TProfile *hprof_q2_nobtblowPT;
TProfile *hprof_cospnp2CM_nobtblowPT;
TProfile *hprof_Enu_nobtblowPT;
TProfile *hprof_TruthEnucaloTrueGENIE_nobtblowPT;////// true vis - true GENIE
TProfile *hprof_Truthcospnp2CM_nobtblowPT;// usando truth Enu (GENIE) en q3

TProfile *hprof_pmux_nobtblowPT;
TProfile *hprof_p1x_nobtblowPT;
TProfile *hprof_p2x_nobtblowPT;

TProfile *hprof_pmuy_nobtblowPT;
TProfile *hprof_p1y_nobtblowPT;
TProfile *hprof_p2y_nobtblowPT;

TProfile *hprof_pmuz_nobtblowPT;
TProfile *hprof_p1z_nobtblowPT;
TProfile *hprof_p2z_nobtblowPT;

//Int_t n2 = 0;/// selected lowPT, no hammer, deltap<100MeV
std::vector<double> Enureco_n2;
std::vector<double> Enutruth_n2;
TProfile *hprof_Enu_nobtblowPTSRC;
///

Int_t n3 = 0;/// selected CC2P no cuts
std::vector<double> Enureco_n3;
std::vector<double> Enutruth_n3;

std::vector<double>  truth_p1_nocuts;
std::vector<double>  reco_p1_nocuts;
std::vector<double>  truth_p2_nocuts;
std::vector<double>  reco_p2_nocuts;
std::vector<double>  truth_pn_nocuts;
std::vector<double>  reco_pn_nocuts;
std::vector<double>  truth_cosp1p2LF_nocuts;
std::vector<double>  reco_cosp1p2LF_nocuts;
std::vector<double>  truth_pT_nocuts;
std::vector<double>  reco_pT_nocuts;
std::vector<double>  EnuTruthreco_nocuts;
std::vector<double>  truth_q2_nocuts;
std::vector<double>  reco_q2_nocuts;
std::vector<double>  truth_cospnp2CM_nocuts;
std::vector<double>  reco_cospnp2CM_nocuts;

TProfile *hprof_p1_nocuts;
TProfile *hprof_p2_nocuts;
TProfile *hprof_pn_nocuts;
TProfile *hprof_cosp1p2LF_nocuts;
TProfile *hprof_pT_nocuts;
TProfile *hprof_TruthEnu_nocuts;/// reco vis - true vis
TProfile *hprof_q2_nocuts;
TProfile *hprof_cospnp2CM_nocuts;
TProfile *hprof_Truthcospnp2CM_nocuts;// usando truth Enu (GENIE) en q3

TProfile *hprof_pmux_nocuts;
TProfile *hprof_p1x_nocuts;
TProfile *hprof_p2x_nocuts;

TProfile *hprof_pmuy_nocuts;
TProfile *hprof_p1y_nocuts;
TProfile *hprof_p2y_nocuts;

TProfile *hprof_pmuz_nocuts;
TProfile *hprof_p1z_nocuts;
TProfile *hprof_p2z_nocuts;

TProfile *hprof_Enu_nocuts;
TProfile *hprof_TruthEnucaloTrueGENIE_nocuts;////// true vis - true GENIE

///// resoluciones vs reco variables para TTree de errores por bin

TProfile *hprof_cosp1p2LF_vs_reco_nocuts;
TProfile *hprof_pT_vs_reco_nocuts;
TProfile *hprof_p1_vs_reco_nocuts;
TProfile *hprof_p2_vs_reco_nocuts;
TProfile *hprof_pn_vs_reco_nocuts;
TProfile *hprof_Enu_vs_reco_nocuts;
TProfile *hprof_Truthcospnp2CM_vs_reco_nocuts;// usando truth Enu (GENIE) en q3

/// despues de los cortes
TProfile *hprof_cosp1p2CM_vs_reco_nobtblowPT;
TProfile *hprof_p1_vs_reco_nobtblowPT;
TProfile *hprof_p2_vs_reco_nobtblowPT;
TProfile *hprof_pn_vs_reco_nobtblowPT;
TProfile *hprof_Enu_vs_reco_nobtblowPT;
TProfile *hprof_Truthcospnp2CM_vs_reco_nobtblowPT;// usando truth Enu (GENIE) en q3

////errores para cosCM (usando errores de p2 y pn)
//// TArray !!!


/////////////////////////
int numpairs=0;
int totentries =0;
int topo1 =0;
int topo2 =0;
int topo3 =0;
int topo4 =0;
int topo5 =0;
int topo6 =0;
int topo7 =0;
int topo8 =0;
int topo9 =0;
int topo10 =0;
int topo11 =0;

int topo1_300 =0;/// 300MeV proton threshold
int topo2_300 =0;
int topo3_300 =0;
int topo4_300 =0;
int topo5_300 =0;
int topo6_300 =0;
int topo7_300 =0;
int topo8_300=0;
int topo9_300=0;
int topo10_300=0;
int topo11_300=0;

int topo1_btb =0;/// with p1~p2
int topo2_btb =0;
int topo3_btb =0;
int topo4_btb =0;
int topo5_btb =0;
int topo6_btb =0;
int topo7_btb =0;
int topo8_btb =0;
int topo9_btb=0;
int topo10_btb=0;
int topo11_btb=0;

int topo1_btblowPT =0;/// nobtb, lowPT
int topo2_btblowPT =0;
int topo3_btblowPT =0;
int topo4_btblowPT =0;
int topo5_btblowPT =0;
int topo6_btblowPT =0;
int topo7_btblowPT =0;
int topo8_btblowPT =0;
int topo9_btblowPT =0;
int topo10_btblowPT =0;
int topo11_btblowPT =0;

float FVx = 256.35;
float FVy = 233;
float FVz = 1036.8;
float borderx = 12.;
float bordery = 35.;
float borderz = 25.;

int num300 =0;

//This function returns if a 3D point is within the fiducial volume
bool inFV(float x, float y, float z) {
    if(x < (FVx - borderx) && (x > borderx) && (y < (FVy/2. - bordery)) && (y > (-FVy/2. + bordery)) && (z < (FVz - 85)) && (z > borderz)) return true;
    else return false;
}

double Ecalomiss(double Esum, double PTmiss, int np) {
  Esum *= 1000; //convert to MeV
  PTmiss *= 1000; //convert to MeV
  double Eexcit = 30.4; //in MeV
  double Mass = 0; // in MeV
  if(np == 0) Mass = 37.2050e3; //Ar40
  else if(np == 1) Mass = 36.2758e3; //Ar39
  else if(np == 2) Mass = 35.3669e3; //Cl38
  else if(np == 3) Mass = 34.4201e3; //S37
  else if(np == 4) Mass = 33.4957e3; //P36
  else if(np == 5) Mass = 32.5706e3; //Si35
  else if(np == 6) Mass = 31.6539e3; //Al34
  else if(np == 7) Mass = 30.7279e3; //Mg33
  else if(np == 8) Mass = 29.8111e3; //Na32
  else if(np == 9) Mass = 28.8918e3; //Ne31
  else if(np >= 10) Mass = 27.9789e3; //F30

  double Ekinrecoil = sqrt(PTmiss*PTmiss + Mass*Mass) - Mass;
  return Esum + Eexcit + Ekinrecoil; // return result in MeV
}

int Topology(int nmuons, int nelectrons, int npions, int npi0, int nprotons, bool cosmicflag, int OOFVflag) {
  //// This function return the true topology of the event, numu & anti-numu                                                        
  ////1. CC0Pion0Proton                                                                                                            
  ////2. CC0Pion1Proton                                  
  ////3. CC0Pion2Proton                                                                                                            
  ////4. CC0PionNProton                                                                                                            
  ////5. CC1PionNProton (1 Pion= 1 charged pion || 1 neutral pion)
  ////6. CCNPionNProton    
  ////7. CCnue-antinue   
  ////8. NC                                                                                            
  ////9. OOFV (nu event out of FV)                                                                                                 
  ////10. Cosmic                                                                                                       
  ////11. Other (just in case, let's check!)                                                                     
  /// e.g. numu CC inclusive= Topology >0 && Topology < 7

  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons ==0 ) return 1;
  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons ==1 ) return 2;
  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons ==2 ) return 3;
  if (nmuons >0 && (nelectrons + npions + npi0 ) == 0 && nprotons >2 ) return 4;
  if (nmuons >0 && (nelectrons ) == 0 && (npions + npi0) == 1 ) return 5;
  if (nmuons >0 && (nelectrons ) == 0 && (npions + npi0) > 1 ) return 6;
  if (nmuons == 0 && nelectrons > 0 ) return 7;
  if (nmuons==0  && nelectrons ==0) return 8;
//  if (OOFVflag) return 9;
//  if (cosmicflag) return 10;  //check with colton how to select cosmic event

  else return 11;

}

double GetQ2lep(double Enu, double pmu, double cosmu) {
  double muonmass = 0.105658;
  double Q2 = (2.*Enu*(sqrt(muonmass*muonmass+pmu*pmu) - (pmu*cosmu))) - (muonmass*muonmass);
  //std::cout<<"Q2lep "<<Q2<<std::endl;
  return Q2;// return result in GeV2
}

double errcosgamma(double absp2, double p2x, double p2y, double p2z, double abspn, double pnx, double pny, double pnz, double errabsp2, double errp2x, double errp2y, double errp2z, double errabspn, double errpnx, double errpny, double errpnz, double cosgamma){ /// error cos gammaCM **2

  double errcCM2 = 0;
  //double A = (1./(absp2*abspn))*(1./(absp2*abspn));
  //double B = (pnx*errp2x*pnx*errp2x) + (p2x*errpnx)*(p2x*errpnx) + (pny*errp2y)*(pny*errp2y) + (p2y*errpny)*(p2y*errpny) + (p2z*errpnz)*(p2z*errpnz) + (pnz*errp2z)*(pnz*errp2z);
  //double C = - ((cosgamma)/(absp2*abspn))*((cosgamma)/(absp2*abspn));
  //double D = (abspn*errabsp2 + absp2*errabspn)*(abspn*errabsp2 + absp2*errabspn);

  double A = (1./(absp2*absp2*abspn*abspn));
  double B = (pnx*errp2x*pnx*errp2x) + (p2x*errpnx*p2x*errpnx) + (pny*errp2y*pny*errp2y) + (p2y*errpny*p2y*errpny) + (p2z*errpnz*p2z*errpnz) + (pnz*errp2z*pnz*errp2z);
  double C = (cosgamma*cosgamma);
  double D = (1./(absp2*absp2)) + (1./(abspn*abspn)); 
  
  errcCM2 = A*B + C*D;
  //  if (errcCM2>4) return absp2;
  //else return 0.;
  // if(abs(errcCM2)>cosgamma) std::cout<<"valor del error mas grande q el valor del angulo "<<std::endl;
  return errcCM2;
}

double errX(double Xreco, double Xtrue){

  double Xerr = TMath::Abs((Xreco-Xtrue)/(Xtrue));
  //double Xerr = TMath::Abs((Xreco-Xtrue));

  //std::cout<<"resolution "<<Xerr<<std::endl;
  return Xerr;
}

void hanalysis_MC_Resolution::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   fanalysis_Resolution= new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/resolutions_BNBMC.root","RECREATE");
   outfile_MCResolution.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_resolution_MC.txt");


   err->Branch("err2cosCM",err2cosCM,"err2cosCM[nbinscCMer+1]/F");
   err->Branch("nentries",nentries,"nentries[nmax]/I");
   
   truth_reco_p1_nocuts = new TH2D("truth_reco_p1_nocuts", "truth_reco_p1_nocuts", 50,0,2.,50, 0, 2.);
   truth_reco_p2_nocuts = new TH2D("truth_reco_p2_nocuts", "truth_reco_p2_nocuts", 50,0,2.,50, 0, 2.);
   truth_reco_pn_nocuts = new TH2D("truth_reco_pn_nocuts", "truth_reco_pn_nocuts", 50,0,2.,50, 0, 2.);
   truth_reco_cosp1p2LF = new TH2D("truth_reco_cosp1p2LF", "truth_reco_cosp1p2LF", 50,-1.,1.,50, -1., 1.);
   truth_reco_pT_nocuts = new TH2D("truth_reco_pT_nocuts", "truth_reco_pT_nocuts", 50,0,2.,50, 0, 2.);
   truth_reco_Enu_nocuts = new TH2D("truth_reco_Enu_nocuts", "truth_reco_Enu_nocuts", 50,0,2.,50, 0, 2.);
   truth_reco_q2_nocuts = new TH2D("truth_reco_q2_nocuts", "truth_reco_q2_nocuts", 50,0,2.,50, 0, 2.);
   truth_reco_cospnp2CM_nocuts = new TH2D("truth_reco_cospnp2CM_nocuts", "truth_reco_cospnp2CM_nocuts", 50,-1.,1.,50, -1., 1.);
   truth_reco_cospnp2CM_nobtb = new TH2D("truth_reco_cospnp2CM_nobtb", "truth_reco_cospnp2CM_nobtb", 50,-1.,1.,50, -1., 1.);


   truth_reco_p1_nobtblowPT = new TH2D("truth_reco_p1_nobtblowPT", "truth_reco_p1_nobtblowPT", 50,0,2.,50, 0, 2.);
   truth_reco_p2_nobtblowPT = new TH2D("truth_reco_p2_nobtblowPT", "truth_reco_p2_nobtblowPT", 50,0,2.,50, 0, 2.);
   truth_reco_pn_nobtblowPT = new TH2D("truth_reco_pn_nobtblowPT", "truth_reco_pn_nobtblowPT", 50,0,2.,50, 0, 2.);
   truth_reco_Enu_nobtblowPT = new TH2D("truth_reco_Enu_nobtblowPT", "truth_reco_Enu_nobtblowPT", 50,0,2.,50, 0, 2.);
   truth_reco_q2_nobtblowPT = new TH2D("truth_reco_q2_nobtblowPT", "truth_reco_q2_nobtblowPT", 50,0,2.,50, 0, 2.);
   truth_reco_cospnp2CM_nobtblowPT = new TH2D("truth_reco_cospnp2CM_nobtblowPT", "truth_reco_cospnp2CM_nobtblowPT", 50,-1.,1.,50, -1., 1.);

   truth_reco_p1_nobtblowPTSRC = new TH2D("truth_reco_p1_nobtblowPTSRC", "truth_reco_p1_nobtblowPTSRC", 50,0,2.,50, 0, 2.);
   truth_reco_p2_nobtblowPTSRC = new TH2D("truth_reco_p2_nobtblowPTSRC", "truth_reco_p2_nobtblowPTSRC", 50,0,2.,50, 0, 2.);
   truth_reco_pn_nobtblowPTSRC = new TH2D("truth_reco_pn_nobtblowPTSRC", "truth_reco_pn_nobtblowPTSRC", 50,0,2.,50, 0, 2.);
   truth_reco_Enu_nobtblowPTSRC = new TH2D("truth_reco_Enu_nobtblowPTSRC", "truth_reco_Enu_nobtblowPTSRC", 50,0,2.,50, 0, 2.);
   truth_reco_q2_nobtblowPTSRC = new TH2D("truth_reco_q2_nobtblowPTSRC", "truth_reco_q2_nobtblowPTSRC", 50,0,2.,50, 0, 2.);
   truth_reco_cospnp2CM_nobtblowPTSRC = new TH2D("truth_reco_cospnp2CM_nobtblowPTSRC", "truth_reco_cospnp2CM_nobtblowPTSRC", 50,-1.,1.,50, -1., 1.);


   Truth_reco_Enu_nocuts = new TH2D("Truth_reco_Enu_nocuts", "Truth_reco_Enu_nocuts", 50,0,2.,50, 0, 2.);
   Truth_reco_Enu_nobtb = new TH2D("Truth_reco_Enu_nobtb", "Truth_reco_Enu_nobtb", 50,0,2.,50, 0, 2.);
   Truth_reco_Enu_nobtblowPT = new TH2D("Truth_reco_Enu_nobtblowPT", "Truth_reco_Enu_nobtblowPT", 50,0,2.,50, 0, 2.);
   Truth_reco_Enu_nobtblowPTSRC = new TH2D("Truth_reco_Enu_nobtblowPTSRC", "Truth_reco_Enu_nobtblowPTSRC", 50,0,2.,50, 0, 2.);

   //   hprof_Enu_nocuts = new TProfile("hprof_Enu_nocuts", "",10,0,5,-2.,2.);
   //   hprof_Enu_nobtblowPT = new TProfile("hprof_Enu_nobtblowPT", "",10,0,5,-2.,2.);
   //   hprof_Enu_nobtblowPTSRC = new TProfile("hprof_Enu_nobtblowPTSRC", "",10,0,2,-2.,2.);

   hprof_Enu_nocuts = new TProfile("hprof_Enu_nocuts", "",nbinsEnu, binsEnu);
   hprof_Enu_nobtblowPT = new TProfile("hprof_Enu_nobtblowPT", "",nbinsEnu, binsEnu);
   hprof_Enu_nobtblowPTSRC = new TProfile("hprof_Enu_nobtblowPTSRC", "",nbinsEnu, binsEnu);

   hprof_p1_nocuts = new TProfile("hprof_p1_nocuts", "",nbinsp,binsp);
   hprof_p2_nocuts = new TProfile("hprof_p2_nocuts", "",nbinsp,binsp);
   hprof_pn_nocuts = new TProfile("hprof_pn_nocuts", "",nbinsp,binsp);
   hprof_cosp1p2LF_nocuts = new TProfile("hprof_cosp1p2LF_nocuts", "",nbinscLF,binscLF);
   hprof_pT_nocuts = new TProfile("hprof_pT_nocuts", "",nbinspT,binspT);
   hprof_TruthEnu_nocuts = new TProfile("hprof_TruthEnu_nocuts", "",nbinsEnu, binsEnu);
   hprof_q2_nocuts = new TProfile("hprof_q2_nocuts", "",nbinsq2, binsq2);
   hprof_cospnp2CM_nocuts = new TProfile("hprof_cospnp2CM_nocuts", "",nbinscCM,binscCM);
   hprof_TruthEnucaloTrueGENIE_nocuts = new TProfile("hprof_TruthEnucaloTrueGENIE_nocuts", "",nbinsEnu, binsEnu);
   hprof_Truthcospnp2CM_nocuts = new TProfile("hprof_Truthcospnp2CM_nocuts", "",nbinscCM,binscCM);

   hprof_pmux_nocuts = new TProfile("hprof_pmux_nocuts", "",nbinsp,binsp);
   hprof_p1x_nocuts = new TProfile("hprof_p1x_nocuts", "",nbinsp,binsp);
   hprof_p2x_nocuts = new TProfile("hprof_p2x_nocuts", "",nbinsp,binsp);
   hprof_pmuy_nocuts = new TProfile("hprof_pmuy_nocuts", "",nbinsp,binsp);
   hprof_p1y_nocuts = new TProfile("hprof_p1y_nocuts", "",nbinsp,binsp);
   hprof_p2y_nocuts = new TProfile("hprof_p2y_nocuts", "",nbinsp,binsp);
   hprof_pmuz_nocuts = new TProfile("hprof_pmuz_nocuts", "",nbinsp,binsp);
   hprof_p1z_nocuts = new TProfile("hprof_p1z_nocuts", "",nbinsp,binsp);
   hprof_p2z_nocuts = new TProfile("hprof_p2z_nocuts", "",nbinsp,binsp);

   hprof_p1_nobtblowPT = new TProfile("hprof_p1_nocuts", "",nbinsp,binsp);
   hprof_p2_nobtblowPT = new TProfile("hprof_p2_nocuts", "",nbinsp,binsp);
   hprof_pn_nobtblowPT = new TProfile("hprof_pn_nocuts", "",nbinsp,binsp);
   hprof_cosp1p2LF_nobtblowPT = new TProfile("hprof_cosp1p2LF_nobtblowPT", "",nbinscLF,binscLF);
   hprof_pT_nobtblowPT = new TProfile("hprof_pT_nobtblowPT", "",nbinspT,binspT);
   hprof_TruthEnu_nobtblowPT = new TProfile("hprof_TruthEnu_nobtblowPT", "",nbinsEnu, binsEnu);
   hprof_q2_nobtblowPT = new TProfile("hprof_q2_nobtblowPT", "",nbinsq2, binsq2);
   hprof_cospnp2CM_nobtblowPT = new TProfile("hprof_cospnp2CM_nobtblowPT", "",nbinscCM,binscCM);
   hprof_TruthEnucaloTrueGENIE_nobtblowPT = new TProfile("hprof_TruthEnucaloTrueGENIE_nobtblowPT", "",nbinsEnu, binsEnu);
   hprof_Truthcospnp2CM_nobtblowPT = new TProfile("hprof_Truthcospnp2CM_nobtblowPT", "",nbinscCM,binscCM);

   hprof_pmux_nobtblowPT = new TProfile("hprof_pmux_nobtblowPT", "",nbinsp,binsp);
   hprof_p1x_nobtblowPT = new TProfile("hprof_p1x_nobtblowPT", "",nbinsp,binsp);
   hprof_p2x_nobtblowPT = new TProfile("hprof_p2x_nobtblowPT", "",nbinsp,binsp);
   hprof_pmuy_nobtblowPT = new TProfile("hprof_pmuy_nobtblowPT", "",nbinsp,binsp);
   hprof_p1y_nobtblowPT = new TProfile("hprof_p1y_nobtblowPT", "",nbinsp,binsp);
   hprof_p2y_nobtblowPT = new TProfile("hprof_p2y_nobtblowPT", "",nbinsp,binsp);
   hprof_pmuz_nobtblowPT = new TProfile("hprof_pmuz_nobtblowPT", "",nbinsp,binsp);
   hprof_p1z_nobtblowPT = new TProfile("hprof_p1z_nobtblowPT", "",nbinsp,binsp);
   hprof_p2z_nobtblowPT = new TProfile("hprof_p2z_nobtblowPT", "",nbinsp,binsp);

   ///// profiles para errores (vs reco variables)
   hprof_cosp1p2LF_vs_reco_nocuts = new TProfile("hprof_cosp1p2LF_vs_reco_nocuts", "",nbinscLFerr,binscLFerr);
   //hprof_cosp1p2LF_vs_reco_nocuts = new TProfile("hprof_cosp1p2LF_vs_reco_nocuts", "",20,-1.,1.);
   hprof_pT_vs_reco_nocuts = new TProfile("hprof_pT_vs_reco_nocuts", "",nbinsperr,binsperr);
   hprof_p1_vs_reco_nocuts = new TProfile("hprof_p1_vs_reco_nocuts", "",nbinsperr,binsperr);
   hprof_p2_vs_reco_nocuts = new TProfile("hprof_p2_vs_reco_nocuts", "",nbinsperr,binsperr);
   hprof_pn_vs_reco_nocuts = new TProfile("hprof_pn_vs_reco_nocuts", "",nbinsperr,binsperr);
   hprof_Enu_vs_reco_nocuts = new TProfile("hprof_Enu_vs_reco_nocuts", "",nbinsEnuerr, binsEnuerr);
   hprof_Truthcospnp2CM_vs_reco_nocuts = new TProfile("hprof_Truthcospnp2CM_vs_reco_nocuts", "",nbinscCMerr,binscCMerr);

   hprof_cosp1p2CM_vs_reco_nobtblowPT = new TProfile("hprof_cosp1p2CM_vs_reco_nobtblowPT", "",nbinscCMerr,binscCMerr);
   hprof_p1_vs_reco_nobtblowPT = new TProfile("hprof_p1_vs_reco_nobtblowPT", "",nbinsperr,binsperr);
   hprof_p2_vs_reco_nobtblowPT = new TProfile("hprof_p2_vs_reco_nobtblowPT", "",nbinsperr,binsperr);
   hprof_pn_vs_reco_nobtblowPT = new TProfile("hprof_pn_vs_reco_nobtblowPT", "",nbinsperr,binsperr);
   hprof_Enu_vs_reco_nobtblowPT = new TProfile("hprof_Enu_vs_reco_nobtblowPT", "",nbinsEnuerr, binsEnuerr);
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT = new TProfile("hprof_Truthcospnp2CM_vs_reco_nobtblowPT", "",nbinscCMerr,binscCMerr);
   
   std::cout<<"declaring TFile"<<endl;

}

void hanalysis_MC_Resolution::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t hanalysis_MC_Resolution::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);

   int IDTmuon= -1;
   int IDTproton1= -1;
   int IDTproton2= -1;
   bool CC2P =false;
   bool Thadrons =true;
   int num2P =0;
   double tempmomp =-999.;
   double tempmomp2 =-999.;

   ///
   int IDTmuonT= -1;
   int IDTproton1T= -1;
   int IDTproton2T= -1;
   bool ThadronsT =true;
   int num2Ptot =0;

   if(*nu_energy >0.){
   
     if(fhg4parpdg.GetSize()>2){// at least 3 particles from the neutrino, we don't care about neutrons or photons
       for(int nT=0; nT<fhg4parpdg.GetSize(); nT++){
	 if(abs(fhg4parpdg[nT])==211 || abs(fhg4parpdg[nT])==111) Thadrons=false;
	 else if(abs(fhg4parpdg[nT])==13) IDTmuon=nT;
	 else if(fhg4parpdg[nT]==2212){
	   if(fhg4parp[nT]>0.3){
	     num2P++;
	     if(tempmomp<fhg4parp[nT]){
	       IDTproton1=nT;
	       tempmomp=fhg4parp[nT];
	     }
	     if(IDTproton2==-1 || fhg4parp[nT] <tempmomp){
	       IDTproton2=nT;
	       tempmomp2=fhg4parp[nT];
	     }
	   }/// proton momenta>0.3
	 }//protons
       }/// loop on geant4 particle
     }//at least 2 particles

     /////// at least 1 particle
     if(fhg4parpdg.GetSize()>0){// at least 3 particles from the neutrino, we don't care about neutrons or photons
       for(int nT=0; nT<fhg4parpdg.GetSize(); nT++){
	 if(abs(fhg4parpdg[nT])==211 || abs(fhg4parpdg[nT])==111) ThadronsT=false;
	 else if(abs(fhg4parpdg[nT])==13) IDTmuonT=nT;
	 else if(fhg4parpdg[nT]==2212){
	   if(fhg4parp[nT]>0.3){
	     num2Ptot++;
	   }/// proton momenta>0.3
	 }//protons
       }/// loop on geant4 particle
     }//at least 2 particles
   }//enu>0

   if(num2P==2 && Thadrons && IDTmuon!=-1  && IDTproton1!=-1 && IDTproton2!=-1 && *nu_ccnc==0){
     
     double deltax= fhg4parpx[IDTmuon]+fhg4parpx[IDTproton1]+fhg4parpx[IDTproton2];
     double deltay= fhg4parpy[IDTmuon]+fhg4parpy[IDTproton1]+fhg4parpy[IDTproton2];
     double PTmiss = sqrt(deltax*deltax+deltay*deltay);
     // muon energy
     double  Emuon = sqrt(pow(105.6/1000.,2) + pow(fhg4parp[IDTmuon],2));  ///

   // protons energy
     double Eprotons = sqrt(pow(938.272/1000.,2) + pow(fhg4parp[IDTproton1],2)) + sqrt(pow(938.272/1000.,2) + pow(fhg4parp[IDTproton2],2));
     double Eproton1 = pow(fhg4parp[IDTproton1],2)/(2*938.272/1000.);
     double Eproton2 = pow(fhg4parp[IDTproton2],2)/(2*938.272/1000.);
     
     //double Esum= Emuon + Eprotons;
     double Esum= Emuon + pow(fhg4parp[IDTproton1],2)/(2*938.272/1000.) + pow(fhg4parp[IDTproton2],2)/(2*938.272/1000.);
     double Enuvis = Ecalomiss(Esum, PTmiss, 2)/1000.;
     
     /// opening angles in Lab frame
     TVector3 P1dirT;
     P1dirT[0] = fhg4parpx[IDTproton1];
     P1dirT[1] = fhg4parpy[IDTproton1];
     P1dirT[2] = fhg4parpz[IDTproton1];

     TVector3 P2dirT;
     P2dirT[0] = fhg4parpx[IDTproton2];
     P2dirT[1] = fhg4parpy[IDTproton2];
     P2dirT[2] = fhg4parpz[IDTproton2];

     TVector3 udirT;
     udirT[0] = fhg4parpx[IDTmuon];
     udirT[1] = fhg4parpy[IDTmuon];
     udirT[2] = fhg4parpz[IDTmuon];

     double norm_P1dirT = sqrt(pow(P1dirT[0],2) + pow(P1dirT[1],2)+ pow(P1dirT[2],2));
     double norm_P2dirT = sqrt(pow(P2dirT[0],2) + pow(P2dirT[1],2)+ pow(P2dirT[2],2));
     double norm_udirT = sqrt(pow(udirT[0],2) + pow(udirT[1],2)+ pow(udirT[2],2));

     float TPlep=fhg4parp[IDTmuon];
     float TPhad1=fhg4parp[IDTproton1];
     float TPhad2=fhg4parp[IDTproton2];

     double TCosAnglep1p2; // scalar product
     if(Enuvis>0) TCosAnglep1p2 = P1dirT.Dot(P2dirT);
     TCosAnglep1p2 =  TCosAnglep1p2/(norm_P1dirT*norm_P2dirT);

     double TCosAnglep1p2CM_Tune3 =-999.;
     TVector3 NeuDir;
     NeuDir.SetXYZ(0,0,1);

     double Q3[3];/// this is just Q_3 
     for( int i = 0; i < 3; i++ ) Q3[i] = Enuvis*NeuDir[i] - udirT[i];

     TVector3 Pn;
     for( int i = 0; i < 3; i++ ) Pn[i] = P1dirT[i] - Q3[i]; 

     if(Enuvis>0) TCosAnglep1p2CM_Tune3 = P2dirT.Dot(Pn);
     double norm_pndirT = sqrt(pow(Pn[0],2) + pow(Pn[1],2)+ pow(Pn[2],2));

     TCosAnglep1p2CM_Tune3 =  TCosAnglep1p2CM_Tune3/(norm_P2dirT*norm_pndirT);

     for(int ipi = 0; ipi < 3 ;ipi++ ) P1dirT[ipi] = P1dirT[ipi]/norm_P1dirT;
     for(int ipi = 0; ipi < 3 ;ipi++ ) P2dirT[ipi] = P2dirT[ipi]/norm_P2dirT;
     for(int ipi = 0; ipi < 3 ;ipi++ ) udirT[ipi] = udirT[ipi]/norm_udirT;

     //std::cout<<"truth cos theta CM: "<<TCosAnglep1p2CM_Tune3<<"   Truth Lab frame "<< TCosAnglep1p2<<std::endl;

   }// truth CC2P
   /// seleccion ////////
   if(track_pfp_Id.GetSize()<1) std::cout<<"Oooops, there are less than 1 tracks"<<std::endl;

   ///specific cuts////
   if(track_pfp_Id.GetSize()==3){/// 3 trks requirement

     double trklength_temp=0;
     double trklength_temp2=0;
     double trklength_temp3=0;
     int muind=-1;
     int p1ind=-1;
     int p2ind=-1;
     bool muoninFV = true;

     bool trackfromneutrino=true;// by default from neutrino interation
     for(int ncand=0; ncand<pfp_origin.GetSize(); ncand++){
       if(pfp_origin[ncand] !=1) trackfromneutrino=false;
     }/// check if all pfp true associated particles are from neutrino, otherwise is a cosmic

     for(int allp=0; allp< track_pfp_Id.GetSize(); ++allp){
       if(track_pfp_length[allp]>trklength_temp){
	 muind=allp;
	 trklength_temp=track_pfp_length[allp];
       }
     }
     bool tempflag=true;
     bool minColl = true;

     if(muind>-1 && !inFV(*_nuvtxx_reco, *_nuvtxy_reco,*_nuvtxx_reco)) muoninFV=false;
     ///loop over all the proton candidates
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       if (!*pfp_upinFVflag) tempflag=false;
       if(tempflag==false) continue;
       if(track_pfp_length[np]>trklength_temp2) {
	 p1ind=np;
	 trklength_temp2=track_pfp_length[np];
       }
     }

     /////loop over all the proton candidates
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       if(p1ind==np) continue;
       if(tempflag==false) continue;
       if(track_pfp_length[np]>trklength_temp3) {
	 p2ind=np;
	 trklength_temp3=track_pfp_length[np];
       }
     } //end of loop over proton candidates //second proton selected   

     /// check topology (look at true particles associated and proton momenta)
     int numMuon =0;
     int numPion =0;
     int numPi0 = 0;
     int numEle = 0;
     int numProton = 0;
     int cosmicflag= 0;   

     if(pfp_parId.GetSize()>0){
       for(int nt =0; nt<pfp_parId.GetSize(); nt++){
	 if(pfp_status[nt]!=1) continue;
	 if(*nu_ccnc!=0)continue;
	 if(abs(pfp_pdg[nt])==13) numMuon++;
	 if(abs(pfp_pdg[nt])==211) numPion++;
	 if(abs(pfp_pdg[nt])==111) numPi0++;
	 if(abs(pfp_pdg[nt])==11) numPi0++;
	 if(abs(pfp_pdg[nt])==2212 &&  pfp_mom[nt]>0.3) numProton++;
       }
     }
     else cosmicflag= 1;
     if(!trackfromneutrino) cosmicflag= 1;
     Int_t TopFlag=Topology(numMuon, numEle , numPion, numPi0, numProton, cosmicflag, *OOFVflag);

     if(muind !=-1 &&p1ind !=-1 && p2ind !=-1 && tempflag){/// requirements
       if(track_pfp_dEdx[muind].size()<5 ||track_pfp_dEdx[p1ind].size()<5 ||track_pfp_dEdx[p2ind].size()<5) minColl=false;/// min coll hits
       if(minColl){
	 if(track_pfp_chi2_proton[muind]>88. && track_pfp_chi2_proton[p1ind]<88. &&track_pfp_chi2_proton[p2ind]<88.){

	   totentries++;

	   /// opening angles
	   float fPlep=*track_pfp_mom_mucand;
	   float fPhad1=track_pfp_Mom_p[p1ind];
	   float fPhad2=track_pfp_Mom_p[p2ind];
	   float fThetaLep=track_pfp_theta[muind];
	   float fThetaHad1=track_pfp_theta[p1ind];
	   float fThetaHad2=track_pfp_theta[p2ind];
	   float fPhiLep=track_pfp_phi[muind];
	   float fPhiHad1=track_pfp_phi[p1ind];
	   float fPhiHad2=track_pfp_phi[p2ind];
	   TVector3 muonP(fPlep*(TMath::Sin(fThetaLep))*(TMath::Cos(fPhiLep)), fPlep*(TMath::Sin(fThetaLep))*(TMath::Sin(fPhiLep)), fPlep*(TMath::Cos(fThetaLep)));
	   TVector3 protonP1(fPhad1*(TMath::Sin(fThetaHad1))*(TMath::Cos(fPhiHad1)), fPhad1*(TMath::Sin(fThetaHad1))*(TMath::Sin(fPhiHad1)), fPhad1*(TMath::Cos(fThetaHad1)));
	   TVector3 protonP2(fPhad2*(TMath::Sin(fThetaHad2))*(TMath::Cos(fPhiHad2)), fPhad2*(TMath::Sin(fThetaHad2))*(TMath::Sin(fPhiHad2)), fPhad2*(TMath::Cos(fThetaHad2)));

	   TVector3 trackpdir_mu;
	   TVector3 trackpdir_p1;
	   TVector3 trackpdir_p2;
   
	   trackpdir_mu.SetXYZ(TMath::Sin(track_pfp_theta[muind])*TMath::Cos(track_pfp_phi[muind]),TMath::Sin(track_pfp_phi[muind])*TMath::Sin(track_pfp_theta[muind]),track_pfp_costheta[muind]);
	   trackpdir_p1.SetXYZ(TMath::Sin(track_pfp_theta[p1ind])*TMath::Cos(track_pfp_phi[p1ind]),TMath::Sin(track_pfp_phi[p1ind])*TMath::Sin(track_pfp_theta[p1ind]),track_pfp_costheta[p1ind]);
	   trackpdir_p2.SetXYZ(TMath::Sin(track_pfp_theta[p2ind])*TMath::Cos(track_pfp_phi[p2ind]),TMath::Sin(track_pfp_phi[p2ind])*TMath::Sin(track_pfp_theta[p2ind]),track_pfp_costheta[p2ind]);
   
	   Double_t m1 = trackpdir_p1.Mag();
	   Double_t m2 = trackpdir_p2.Mag();
	   Double_t mu = trackpdir_mu.Mag();

	   double CosAnglep1p2 = trackpdir_p1.Dot(trackpdir_p2);   // scalar product
	   CosAnglep1p2 =  CosAnglep1p2/(m1*m2);

	   double CosAnglemup1 = trackpdir_mu.Dot(trackpdir_p1);  // scalar product
	   CosAnglemup1 =  CosAnglemup1/(mu*m1);

	   double CosAnglemup2 = trackpdir_mu.Dot(trackpdir_p2);  // scalar product
	   CosAnglemup2 =  CosAnglemup2/(mu*m2);

	   double anglemup1=CosAnglemup1;
	   double anglemup2=CosAnglemup2;
	   double anglep1p2=CosAnglep1p2;/// LF angle

	   //// reco Enu & PT
	   double reco_deltax= muonP.X()+protonP1.X()+protonP2.X();
	   double reco_deltay= muonP.Y()+protonP1.Y()+protonP2.Y();
	   double reco_PTmiss = sqrt(reco_deltax*reco_deltax + reco_deltay*reco_deltay);
	   // muon energy
	   double  reco_Emuon = sqrt(pow(105.6/1000.,2) + pow(fPlep,2));

	   // protons energy
	   double reco_Eprotons = sqrt(pow(938.272/1000.,2) + pow(fPhad1,2)) + sqrt(pow(938.272/1000.,2) + pow(fPhad2,2));
	   double reco_Eproton1 = pow(fPhad1,2)/(2*938.272/1000.);
	   double reco_Eproton2 = pow(fPhad2,2)/(2*938.272/1000.);
     
	   //double Esum= Emuon + Eprotons;
	   double reco_Esum= reco_Emuon + pow(fPhad1,2)/(2*938.272/1000.) + pow(fPhad2,2)/(2*938.272/1000.);
	   double reco_Enuvis = Ecalomiss(reco_Esum, reco_PTmiss, 2)/1000.;

	   double reco_CosAnglep1p2CM =-999.;
	   TVector3 reco_NeuDir;
	   reco_NeuDir.SetXYZ(0,0,1);

	   double reco_Q3[3];/// this is Q_3 
	   for( int i = 0; i < 3; i++ ) reco_Q3[i] = reco_Enuvis*reco_NeuDir[i] - muonP[i];

	   TVector3 reco_Pn;
	   for( int i = 0; i < 3; i++) reco_Pn[i] = protonP1[i] - reco_Q3[i];

	   if(reco_Enuvis>0) reco_CosAnglep1p2CM = protonP2.Dot(reco_Pn);
	   double norm_recopndirT = sqrt(pow(reco_Pn[0],2) + pow(reco_Pn[1],2)+ pow(reco_Pn[2],2));
	   double norm_recop2dirT = sqrt(pow(protonP2[0],2) + pow(protonP2[1],2)+ pow(protonP2[2],2));
	   reco_CosAnglep1p2CM =  reco_CosAnglep1p2CM/(norm_recop2dirT*norm_recopndirT);

	   double reco_Q2lep = GetQ2lep(reco_Enuvis, fPlep, track_pfp_costheta[muind]);
	   //////////// truth (not reconstructed) associated to reco track ID //////////////
	   ////////////////////////////////////////////////////////////////////////////////

	   /// truth requirements para CC2P /// eficiencias

	   if(TopFlag ==3 && trackfromneutrino && abs(pfp_pdg[muind])==13 && abs(pfp_pdg[p1ind])==2212 && abs(pfp_pdg[p2ind])==2212){

	     float TruePlep=pfp_mom[muind];
	     float TruePhad1=pfp_mom[p1ind];
	     float TruePhad2=pfp_mom[p2ind];
	     float TrueThetaLep=pfp_theta[muind];
	     float TrueThetaHad1=pfp_theta[p1ind];
	     float TrueThetaHad2=pfp_theta[p2ind];
	     float TruePhiLep=pfp_phi[muind];
	     float TruePhiHad1=pfp_phi[p1ind];
	     float TruePhiHad2=pfp_phi[p2ind];
	     TVector3 TruemuonP(TruePlep*(TMath::Sin(TrueThetaLep))*(TMath::Cos(TruePhiLep)), TruePlep*(TMath::Sin(TrueThetaLep))*(TMath::Sin(TruePhiLep)), TruePlep*(TMath::Cos(TrueThetaLep)));
	     TVector3 TrueprotonP1(TruePhad1*(TMath::Sin(TrueThetaHad1))*(TMath::Cos(TruePhiHad1)), TruePhad1*(TMath::Sin(TrueThetaHad1))*(TMath::Sin(TruePhiHad1)), TruePhad1*(TMath::Cos(TrueThetaHad1)));
	     TVector3 TrueprotonP2(TruePhad2*(TMath::Sin(TrueThetaHad2))*(TMath::Cos(TruePhiHad2)), TruePhad2*(TMath::Sin(TrueThetaHad2))*(TMath::Sin(TruePhiHad2)), TruePhad2*(TMath::Cos(TrueThetaHad2)));

	     TVector3 Truetrackpdir_mu;
	     TVector3 Truetrackpdir_p1;
	     TVector3 Truetrackpdir_p2;
  
	     Truetrackpdir_mu.SetXYZ(TMath::Sin(pfp_theta[muind])*TMath::Cos(pfp_phi[muind]),TMath::Sin(pfp_phi[muind])*TMath::Sin(pfp_theta[muind]),pfp_costheta[muind]);
	     Truetrackpdir_p1.SetXYZ(TMath::Sin(pfp_theta[p1ind])*TMath::Cos(pfp_phi[p1ind]),TMath::Sin(pfp_phi[p1ind])*TMath::Sin(pfp_theta[p1ind]),pfp_costheta[p1ind]);
	     Truetrackpdir_p2.SetXYZ(TMath::Sin(pfp_theta[p2ind])*TMath::Cos(pfp_phi[p2ind]),TMath::Sin(pfp_phi[p2ind])*TMath::Sin(pfp_theta[p2ind]),pfp_costheta[p2ind]);
   
	     Double_t Truem1 = Truetrackpdir_p1.Mag();
	     Double_t Truem2 = Truetrackpdir_p2.Mag();
	     Double_t Truemu = Truetrackpdir_mu.Mag();

	     double TrueCosAnglep1p2 = Truetrackpdir_p1.Dot(Truetrackpdir_p2);   // scalar product
	     TrueCosAnglep1p2 =  TrueCosAnglep1p2/(Truem1*Truem2);

	     double TrueCosAnglemup1 = Truetrackpdir_mu.Dot(Truetrackpdir_p1);  // scalar product
	     TrueCosAnglemup1 =  TrueCosAnglemup1/(Truemu*Truem1);

	     double TrueCosAnglemup2 = Truetrackpdir_mu.Dot(Truetrackpdir_p2);  // scalar product
	     TrueCosAnglemup2 = TrueCosAnglemup2/(Truemu*Truem2);

	     double Trueanglemup1=TrueCosAnglemup1;
	     double Trueanglemup2=TrueCosAnglemup2;
	     double Trueanglep1p2=TrueCosAnglep1p2;/// LF angle

	     ///// reco Enu & PT
	     double True_deltax= TruemuonP.X()+TrueprotonP1.X()+TrueprotonP2.X();
	     double True_deltay= TruemuonP.Y()+TrueprotonP1.Y()+TrueprotonP2.Y();
	     double True_PTmiss = sqrt(True_deltax*True_deltax + True_deltay*True_deltay);
	     // muon energy
	     double  True_Emuon = sqrt(pow(105.6/1000.,2) + pow(TruePlep,2));

	     // protons energy
	     double True_Eprotons = sqrt(pow(938.272/1000.,2) + pow(TruePhad1,2)) + sqrt(pow(938.272/1000.,2) + pow(TruePhad2,2));
	     double True_Eproton1 = pow(TruePhad1,2)/(2*938.272/1000.);
	     double True_Eproton2 = pow(TruePhad2,2)/(2*938.272/1000.);
     
	     //double Esum= Emuon + Eprotons;
	     double True_Esum= True_Emuon + pow(TruePhad1,2)/(2*938.272/1000.) + pow(TruePhad2,2)/(2*938.272/1000.);
	     double True_Enuvis = Ecalomiss(True_Esum, True_PTmiss, 2)/1000.;

	     double True_CosAnglep1p2CM =-999.;
	     double True_Cospnp2CM =-999.;
	     TVector3 True_NeuDir;
	     True_NeuDir.SetXYZ(0,0,1);

	     double True_Q3[3];/// this is Q_3 
	     for( int i = 0; i < 3; i++ ) True_Q3[i] = True_Enuvis*True_NeuDir[i] - TruemuonP[i];

	     double True_Q3GENIE[3];/// this is Q_3 
	     for( int i = 0; i < 3; i++ ) True_Q3GENIE[i] = (*nu_energy)*True_NeuDir[i] - TruemuonP[i];

	     TVector3 True_Pn;
	     for( int i = 0; i < 3; i++) True_Pn[i] = TrueprotonP1[i] - True_Q3[i];

	     TVector3 Trueboost_Pn;
	     for( int i = 0; i < 3; i++) Trueboost_Pn[i] = TrueprotonP1[i] - True_Q3GENIE[i];

	     if(True_Enuvis>0) True_CosAnglep1p2CM = TrueprotonP2.Dot(True_Pn);
	     if((*nu_energy)>0) True_Cospnp2CM = TrueprotonP2.Dot(Trueboost_Pn);
	     double norm_TruepndirT = sqrt(pow(True_Pn[0],2) + pow(True_Pn[1],2)+ pow(True_Pn[2],2));
	     double norm_Truep2dirT = sqrt(pow(TrueprotonP2[0],2) + pow(TrueprotonP2[1],2)+ pow(TrueprotonP2[2],2));
	     double norm_TruepndirTboost = sqrt(pow(Trueboost_Pn[0],2) + pow(Trueboost_Pn[1],2)+ pow(Trueboost_Pn[2],2));
	     True_CosAnglep1p2CM =  True_CosAnglep1p2CM/(norm_Truep2dirT*norm_TruepndirT);
	     True_Cospnp2CM =  True_Cospnp2CM/(norm_Truep2dirT*norm_TruepndirTboost);

	     double TrueQ2lep = GetQ2lep(True_Enuvis, TruePlep, pfp_costheta[muind]);


	     if(track_pfp_Mom_p[p1ind]>0.3 && track_pfp_Mom_p[p2ind]>0.3){ /// require proton momenta>300 MeV
	     
	     //	     std::cout<<"despues de info en truth"<<std::endl;
	     /////////////////////////////////////////////////
	     //////////////////////////////////////////////////

	     /// para escribir en los Trees// (x,y) // (truth, reco) // truth CC2Protons
	     // std::cout<<" topo "<<TopFlag<<std::endl;
	     //// no cuts /////
	     truth_reco_p1_nocuts->Fill(pfp_mom[p1ind],track_pfp_Mom_p[p1ind]);
	     truth_reco_p2_nocuts->Fill(pfp_mom[p2ind],track_pfp_Mom_p[p2ind]);
	     truth_reco_pn_nocuts->Fill(norm_TruepndirT,norm_recopndirT);
	     truth_reco_cosp1p2LF->Fill(TrueCosAnglep1p2,anglep1p2);
	     truth_reco_pT_nocuts->Fill(True_PTmiss,reco_PTmiss);
	     truth_reco_Enu_nocuts->Fill(True_Enuvis,reco_Enuvis);
	     truth_reco_q2_nocuts->Fill(TrueQ2lep,reco_Q2lep);
	     truth_reco_cospnp2CM_nocuts->Fill(True_CosAnglep1p2CM,reco_CosAnglep1p2CM);
	     Truth_reco_Enu_nocuts->Fill(*nu_energy,reco_Enuvis);
	     n3++;
	     Enureco_n3.push_back(reco_Enuvis);
	     Enutruth_n3.push_back(*nu_energy);
	     hprof_Enu_nocuts->Fill(*nu_energy,reco_Enuvis-*nu_energy,1);

	     hprof_p1_nocuts->Fill(pfp_mom[p1ind],(track_pfp_Mom_p[p1ind]-pfp_mom[p1ind]),1);
	     hprof_p2_nocuts->Fill(pfp_mom[p2ind],(track_pfp_Mom_p[p2ind]-pfp_mom[p2ind]),1);
	     hprof_pn_nocuts->Fill(norm_TruepndirT,(norm_recopndirT-norm_TruepndirT),1);
	     hprof_cosp1p2LF_nocuts->Fill(TrueCosAnglep1p2,(anglep1p2-TrueCosAnglep1p2),1);
	     hprof_pT_nocuts->Fill(True_PTmiss,(reco_PTmiss-True_PTmiss),1);
	     hprof_TruthEnu_nocuts->Fill(True_Enuvis,(reco_Enuvis-True_Enuvis),1);
	     hprof_q2_nocuts->Fill(TrueQ2lep,(reco_Q2lep-TrueQ2lep),1);
	     hprof_cospnp2CM_nocuts->Fill(True_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_CosAnglep1p2CM),1);
	     hprof_TruthEnucaloTrueGENIE_nocuts->Fill(*nu_energy,(True_Enuvis-*nu_energy),1);
	     hprof_Truthcospnp2CM_nocuts->Fill(True_Cospnp2CM,(reco_CosAnglep1p2CM-True_Cospnp2CM),1);

	     /// projections x,y,z
	     hprof_pmux_nocuts->Fill(TruemuonP.X(),(muonP.X()-TruemuonP.X()),1);
	     hprof_p1x_nocuts->Fill(TrueprotonP1.X(),(protonP1.X()-TrueprotonP1.X()),1);
	     hprof_p2x_nocuts->Fill(TrueprotonP2.X(),(protonP2.X()-TrueprotonP2.X()),1);

	     hprof_pmuy_nocuts->Fill(TruemuonP.Y(),(muonP.Y()-TruemuonP.Y()),1);
	     hprof_p1y_nocuts->Fill(TrueprotonP1.Y(),(protonP1.Y()-TrueprotonP1.Y()),1);
	     hprof_p2y_nocuts->Fill(TrueprotonP2.Y(),(protonP2.Y()-TrueprotonP2.Y()),1);

	     hprof_pmuz_nocuts->Fill(TruemuonP.Z(),(muonP.Z()-TruemuonP.Z()),1);
	     hprof_p1z_nocuts->Fill(TrueprotonP1.Z(),(protonP1.Z()-TrueprotonP1.Z()),1);
	     hprof_p2z_nocuts->Fill(TrueprotonP2.Z(),(protonP2.Z()-TrueprotonP2.Z()),1);

	     ////TProfile para errores (vs reco)

	     hprof_cosp1p2LF_vs_reco_nocuts->Fill(anglep1p2,(anglep1p2-TrueCosAnglep1p2),1);
	     hprof_pT_vs_reco_nocuts->Fill(reco_PTmiss,(reco_PTmiss-True_PTmiss),1);
	     hprof_p1_vs_reco_nocuts->Fill(track_pfp_Mom_p[p1ind],(track_pfp_Mom_p[p1ind]-pfp_mom[p1ind]),1);
	     hprof_p2_vs_reco_nocuts->Fill(track_pfp_Mom_p[p2ind],(track_pfp_Mom_p[p2ind]-pfp_mom[p2ind]),1);
	     hprof_pn_vs_reco_nocuts->Fill(norm_recopndirT,(norm_recopndirT-norm_TruepndirTboost),1);
	     hprof_Enu_vs_reco_nocuts->Fill(reco_Enuvis,(reco_Enuvis-*nu_energy),1);
	     hprof_Truthcospnp2CM_vs_reco_nocuts->Fill(reco_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_Cospnp2CM),1);
	   
	     nerrnocut++;
	     ///errores sin cortes
	     for(int i= 0; i<nbinscCMerr+1; i++){
	       
	       if (i != nbinscCMerr && reco_CosAnglep1p2CM >=  binscCMerr[i] && reco_CosAnglep1p2CM <  binscCMerr[i+1] ){
		 //if(errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)>4) continue;
		 //err2cosgammanocut[i] = err2cosgammanocut[i] + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM); // RMS
		 //err2cosgammanocut[i] = err2cosgammanocut[i] + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM);
		 err2cosgammanocut[i] = err2cosgammanocut[i] + (errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM));
		 nentriesnocuts[i]++;
		 
		 if(errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)>10) outfile_MCResolution<<" error "<<errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)<<std::endl;
	       }
	       else if(i == nbinscCMerr && reco_CosAnglep1p2CM >  binscCMerr[i-1]) {
		 err2cosgammanocut[i] = err2cosgammanocut[i] + (errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM));
		 nentriesnocuts[i]++;
	       }
	     }

	     for(int i= 0; i<nbinscLFerr+1; i++){/// errores cos LF // hacser las resoluciones con 20 bins

	       if(abs(anglep1p2)==0.) continue;
	       if (i != nbinscLFerr && anglep1p2 >=  binscLFerr[i] && anglep1p2 <  binscLFerr[i+1] ){

		 if(abs(anglep1p2) <0.2 && abs(anglep1p2)< abs(TrueCosAnglep1p2)) err2cosgammanocutLF[i] = err2cosgammanocutLF[i] + (errX(TrueCosAnglep1p2,anglep1p2)*errX(TrueCosAnglep1p2,anglep1p2));
		 else err2cosgammanocutLF[i] = err2cosgammanocutLF[i] + (errX(anglep1p2, TrueCosAnglep1p2)*errX(anglep1p2, TrueCosAnglep1p2));
		 nentriesnocutsLF[i]++;
		 
		 //if(errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)>10) outfile_MCResolution<<" error "<<errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)<<std::endl;
	       }
	     }

	 
	   
	     /*  
	     //
	     if(reco_Enuvis-*nu_energy>0){
	       std::cout<<"truth enu "<<*nu_energy<<" truth p1 mom "<<pfp_mom[p1ind]<<" truth p2 mom "<<pfp_mom[p2ind]<<" truth muon mom "<<pfp_mom[muind]<<std::endl;
	       std::cout<<"reco enu "<<reco_Enuvis<<" reco p1 mom "<<track_pfp_Mom_p[p1ind]<<" reco p2 mom "<<track_pfp_Mom_p[p2ind]<< " reco muon mom "<<*track_pfp_mom_mucand<<std::endl;
	     }

	     //// no hammer /////
	     if(anglep1p2>-0.8){
	       truth_reco_cospnp2CM_nobtb->Fill(True_CosAnglep1p2CM,reco_CosAnglep1p2CM);
	       Truth_reco_Enu_nobtb->Fill(*nu_energy,reco_Enuvis);
	       /// no hammer & low PT
	       if(reco_PTmiss<0.3){
		 truth_reco_p1_nobtblowPT->Fill(pfp_mom[p1ind],track_pfp_Mom_p[p1ind]);
		 truth_reco_p2_nobtblowPT->Fill(pfp_mom[p2ind],track_pfp_Mom_p[p2ind]);
		 truth_reco_pn_nobtblowPT->Fill(norm_TruepndirT,norm_recopndirT);
		 truth_reco_Enu_nobtblowPT->Fill(True_Enuvis,reco_Enuvis);
		 truth_reco_q2_nobtblowPT->Fill(TrueQ2lep,reco_Q2lep);
		 truth_reco_cospnp2CM_nobtblowPT->Fill(True_CosAnglep1p2CM,reco_CosAnglep1p2CM);
		 Truth_reco_Enu_nobtblowPT->Fill(*nu_energy,reco_Enuvis);
		 n2++;
		 Enureco_n2.push_back(reco_Enuvis);
		 Enutruth_n2.push_back(*nu_energy);
		 hprof_Enu_nobtblowPT->Fill(*nu_energy,(reco_Enuvis-*nu_energy),1);

		 hprof_p1_nobtblowPT->Fill(pfp_mom[p1ind],(track_pfp_Mom_p[p1ind]-pfp_mom[p1ind]),1);
		 hprof_p2_nobtblowPT->Fill(pfp_mom[p2ind],(track_pfp_Mom_p[p2ind]-pfp_mom[p2ind]),1);
		 hprof_pn_nobtblowPT->Fill(norm_TruepndirT,(norm_recopndirT-norm_TruepndirT),1);
		 hprof_cosp1p2LF_nobtblowPT->Fill(TrueCosAnglep1p2,(anglep1p2-TrueCosAnglep1p2),1);
		 hprof_pT_nobtblowPT->Fill(True_PTmiss,(reco_PTmiss-True_PTmiss),1);
		 hprof_TruthEnu_nobtblowPT->Fill(True_Enuvis,(reco_Enuvis-True_Enuvis),1);
		 hprof_q2_nobtblowPT->Fill(TrueQ2lep,(reco_Q2lep-TrueQ2lep),1);
		 hprof_cospnp2CM_nobtblowPT->Fill(True_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_CosAnglep1p2CM),1);
		 hprof_TruthEnucaloTrueGENIE_nobtblowPT->Fill(*nu_energy,(True_Enuvis-*nu_energy),1);
		 hprof_Truthcospnp2CM_nobtblowPT->Fill(True_Cospnp2CM,(reco_CosAnglep1p2CM-True_Cospnp2CM),1);

		 //// projections x,y,z
		 hprof_pmux_nobtblowPT->Fill(TruemuonP.X(),(muonP.X()-TruemuonP.X()),1);
		 hprof_p1x_nobtblowPT->Fill(TrueprotonP1.X(),(protonP1.X()-TrueprotonP1.X()),1);
		 hprof_p2x_nobtblowPT->Fill(TrueprotonP2.X(),(protonP2.X()-TrueprotonP2.X()),1);

		 hprof_pmuy_nobtblowPT->Fill(TruemuonP.Y(),(muonP.Y()-TruemuonP.Y()),1);
		 hprof_p1y_nobtblowPT->Fill(TrueprotonP1.Y(),(protonP1.Y()-TrueprotonP1.Y()),1);
		 hprof_p2y_nobtblowPT->Fill(TrueprotonP2.Y(),(protonP2.Y()-TrueprotonP2.Y()),1);

		 hprof_pmuz_nobtblowPT->Fill(TruemuonP.Z(),(muonP.Z()-TruemuonP.Z()),1);
		 hprof_p1z_nobtblowPT->Fill(TrueprotonP1.Z(),(protonP1.Z()-TrueprotonP1.Z()),1);
		 hprof_p2z_nobtblowPT->Fill(TrueprotonP2.Z(),(protonP2.Z()-TrueprotonP2.Z()),1);

		 //// error (resolution vs reco)
		 hprof_Truthcospnp2CM_vs_reco_nobtblowPT->Fill(reco_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_Cospnp2CM),1);
		 hprof_cosp1p2CM_vs_reco_nobtblowPT->Fill(reco_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_CosAnglep1p2CM),1);		 
		 hprof_p1_vs_reco_nobtblowPT->Fill(track_pfp_Mom_p[p1ind],(track_pfp_Mom_p[p1ind]-pfp_mom[p1ind]),1);		 
		 hprof_p2_vs_reco_nobtblowPT->Fill(track_pfp_Mom_p[p2ind],(track_pfp_Mom_p[p2ind]-pfp_mom[p2ind]),1);		 
		 hprof_pn_vs_reco_nobtblowPT->Fill(norm_recopndirT,(norm_recopndirT-norm_TruepndirTboost),1);
		 hprof_Enu_vs_reco_nobtblowPT->Fill(reco_Enuvis,(reco_Enuvis-*nu_energy),1);

		 //// filling the error array

		 double errorp2 = errX(track_pfp_Mom_p[p2ind], pfp_mom[p2ind]);
		 double errorpn = errX(norm_recopndirT, norm_TruepndirTboost);
		 double errorp2x = errX(protonP2.X(), TrueprotonP2.X());
		 double errorp2y = errX(protonP2.Y(), TrueprotonP2.Y());
		 double errorp2z = errX(protonP2.Z(), TrueprotonP2.Z());
		 double errorpnx = errX(reco_Pn[0], Trueboost_Pn[0]);
		 double errorpny = errX(reco_Pn[1], Trueboost_Pn[1]);
		 double errorpnz = errX(reco_Pn[2], Trueboost_Pn[2]);

		 err2CM = err2CM + errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM);
		 
		 for(int i= 0; i<nbinscCMerr+1; i++){
		   //std::cout<<"bin i "<<i<<"  valor bin  "<<binscCMerr[i]<<"  cosine CM  "<<reco_CosAnglep1p2CM <<std::endl;
		   if(reco_CosAnglep1p2CM <  binscCMerr[i+1] && reco_CosAnglep1p2CM >=  binscCMerr[i]){
		     err2cosCM[i] = err2cosCM[i] + errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM); /// error cos gammaCM **2
		     ////outfile_MCResolution<<" error "<<errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)<<std::endl;
	       }
	       else if(i == nbinscCMerr && reco_CosAnglep1p2CM >  binscCMerr[i-1]) err2cosgammanocut[i] = err2cosgammanocut[i] + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM);
	   
		 }
	       
*/	     
	     //
	     //if(reco_Enuvis-*nu_energy>0){
	       //std::cout<<"truth enu "<<*nu_energy<<" truth p1 mom "<<pfp_mom[p1ind]<<" truth p2 mom "<<pfp_mom[p2ind]<<" truth muon mom "<<pfp_mom[muind]<<std::endl;
	       //std::cout<<"reco enu "<<reco_Enuvis<<" reco p1 mom "<<track_pfp_Mom_p[p1ind]<<" reco p2 mom "<<track_pfp_Mom_p[p2ind]<< " reco muon mom "<<*track_pfp_mom_mucand<<std::endl;
	     //}
	       
	     //// no hammer /////
	     //if(anglep1p2>-0.8){
	       truth_reco_cospnp2CM_nobtb->Fill(True_CosAnglep1p2CM,reco_CosAnglep1p2CM);
	       Truth_reco_Enu_nobtb->Fill(*nu_energy,reco_Enuvis);
	       /// no hammer & low PT
	       if(reco_PTmiss<0.3){
		 truth_reco_p1_nobtblowPT->Fill(pfp_mom[p1ind],track_pfp_Mom_p[p1ind]);
		 truth_reco_p2_nobtblowPT->Fill(pfp_mom[p2ind],track_pfp_Mom_p[p2ind]);
		 truth_reco_pn_nobtblowPT->Fill(norm_TruepndirT,norm_recopndirT);
		 truth_reco_Enu_nobtblowPT->Fill(True_Enuvis,reco_Enuvis);
		 truth_reco_q2_nobtblowPT->Fill(TrueQ2lep,reco_Q2lep);
		 truth_reco_cospnp2CM_nobtblowPT->Fill(True_CosAnglep1p2CM,reco_CosAnglep1p2CM);
		 Truth_reco_Enu_nobtblowPT->Fill(*nu_energy,reco_Enuvis);
		 n2++;
		 Enureco_n2.push_back(reco_Enuvis);
		 Enutruth_n2.push_back(*nu_energy);
		 hprof_Enu_nobtblowPT->Fill(*nu_energy,(reco_Enuvis-*nu_energy),1);

		 hprof_p1_nobtblowPT->Fill(pfp_mom[p1ind],(track_pfp_Mom_p[p1ind]-pfp_mom[p1ind]),1);
		 hprof_p2_nobtblowPT->Fill(pfp_mom[p2ind],(track_pfp_Mom_p[p2ind]-pfp_mom[p2ind]),1);
		 hprof_pn_nobtblowPT->Fill(norm_TruepndirT,(norm_recopndirT-norm_TruepndirT),1);
		 hprof_cosp1p2LF_nobtblowPT->Fill(TrueCosAnglep1p2,(anglep1p2-TrueCosAnglep1p2),1);
		 hprof_pT_nobtblowPT->Fill(True_PTmiss,(reco_PTmiss-True_PTmiss),1);
		 hprof_TruthEnu_nobtblowPT->Fill(True_Enuvis,(reco_Enuvis-True_Enuvis),1);
		 hprof_q2_nobtblowPT->Fill(TrueQ2lep,(reco_Q2lep-TrueQ2lep),1);
		 hprof_cospnp2CM_nobtblowPT->Fill(True_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_CosAnglep1p2CM),1);
		 hprof_TruthEnucaloTrueGENIE_nobtblowPT->Fill(*nu_energy,(True_Enuvis-*nu_energy),1);
		 hprof_Truthcospnp2CM_nobtblowPT->Fill(True_Cospnp2CM,(reco_CosAnglep1p2CM-True_Cospnp2CM),1);

		 //// projections x,y,z
		 hprof_pmux_nobtblowPT->Fill(TruemuonP.X(),(muonP.X()-TruemuonP.X()),1);
		 hprof_p1x_nobtblowPT->Fill(TrueprotonP1.X(),(protonP1.X()-TrueprotonP1.X()),1);
		 hprof_p2x_nobtblowPT->Fill(TrueprotonP2.X(),(protonP2.X()-TrueprotonP2.X()),1);

		 hprof_pmuy_nobtblowPT->Fill(TruemuonP.Y(),(muonP.Y()-TruemuonP.Y()),1);
		 hprof_p1y_nobtblowPT->Fill(TrueprotonP1.Y(),(protonP1.Y()-TrueprotonP1.Y()),1);
		 hprof_p2y_nobtblowPT->Fill(TrueprotonP2.Y(),(protonP2.Y()-TrueprotonP2.Y()),1);

		 hprof_pmuz_nobtblowPT->Fill(TruemuonP.Z(),(muonP.Z()-TruemuonP.Z()),1);
		 hprof_p1z_nobtblowPT->Fill(TrueprotonP1.Z(),(protonP1.Z()-TrueprotonP1.Z()),1);
		 hprof_p2z_nobtblowPT->Fill(TrueprotonP2.Z(),(protonP2.Z()-TrueprotonP2.Z()),1);

		 //// error (resolution vs reco)
		 hprof_Truthcospnp2CM_vs_reco_nobtblowPT->Fill(reco_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_Cospnp2CM),1);
		 hprof_cosp1p2CM_vs_reco_nobtblowPT->Fill(reco_CosAnglep1p2CM,(reco_CosAnglep1p2CM-True_CosAnglep1p2CM),1);		 
		 hprof_p1_vs_reco_nobtblowPT->Fill(track_pfp_Mom_p[p1ind],(track_pfp_Mom_p[p1ind]-pfp_mom[p1ind]),1);		 
		 hprof_p2_vs_reco_nobtblowPT->Fill(track_pfp_Mom_p[p2ind],(track_pfp_Mom_p[p2ind]-pfp_mom[p2ind]),1);		 
		 hprof_pn_vs_reco_nobtblowPT->Fill(norm_recopndirT,(norm_recopndirT-norm_TruepndirTboost),1);
		 hprof_Enu_vs_reco_nobtblowPT->Fill(reco_Enuvis,(reco_Enuvis-*nu_energy),1);

		 //// filling the error array

		 double errorp2 = errX(track_pfp_Mom_p[p2ind], pfp_mom[p2ind]);
		 double errorpn = errX(norm_recopndirT, norm_TruepndirTboost);
		 double errorp2x = errX(protonP2.X(), TrueprotonP2.X());
		 double errorp2y = errX(protonP2.Y(), TrueprotonP2.Y());
		 double errorp2z = errX(protonP2.Z(), TrueprotonP2.Z());
		 double errorpnx = errX(reco_Pn[0], Trueboost_Pn[0]);
		 double errorpny = errX(reco_Pn[1], Trueboost_Pn[1]);
		 double errorpnz = errX(reco_Pn[2], Trueboost_Pn[2]);

		 err2CM = err2CM + errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM);
		 
		 for(int i= 0; i<nbinscCMerr+1; i++){
		   //if(norm_recopndirT<0.3 || errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM)>20) continue;
		   //if(errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM)>25) continue;
		   //std::cout<<"bin i "<<i<<"  valor bin  "<<binscCMerr[i]<<"  cosine CM  "<<reco_CosAnglep1p2CM <<std::endl;
		   if(reco_CosAnglep1p2CM <  binscCMerr[i+1] && reco_CosAnglep1p2CM >=  binscCMerr[i]){
		     err2cosCM[i] = err2cosCM[i] + errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM); /// error cos gammaCM **2


		     if(errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM)>20.) std::cout<<" error local **2 "<<errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM)<<" p2 "<<track_pfp_Mom_p[p2ind]<< " pn "<<norm_recopndirT<<std::endl;
		       
		     //		     err2cosCM[i] = err2cosCM[i] + errcosgamma(track_pfp_Mom_p[p2ind], protonP2.X(), protonP2.Y(), protonP2.Z(), norm_recopndirT, reco_Pn[0], reco_Pn[1], reco_Pn[2], errorp2, errorp2x, errorp2y, errorp2z, errorpn, errorpnx, errorpny, errorpnz, reco_CosAnglep1p2CM); /// error cos gammaCM **2 /// RMS
		     ////outfile_MCResolution<<"error at bin "<<err2cosCM[i]<<std::endl;
		     ///number of entries per component
		     nentries[i]++;
		     //std::cout<<"writing content to actual bin  "<<std::endl;
		   }
		 }

		 if(errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)<2.){
		   //outfile_MCResolution<<"resolution error cosine "<<errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)<<std::endl;
		   //errorcCMreco = errorcCMreco + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM); // RMS
		   errorcCMreco = errorcCMreco + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM);
		   nerr++;
		 }

		 for(int i= 0; i<nbinscCMerr+1; i++){
		   if(reco_CosAnglep1p2CM <  binscCMerr[i+1] && reco_CosAnglep1p2CM >=  binscCMerr[i]){
		     //if (i != nbinscCMerr && reco_CosAnglep1p2CM >=  binscCMerr[i] && reco_CosAnglep1p2CM <  binscCMerr[i+1] ){
		     //err2cosgamma[i] = err2cosgamma[i] + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM); /// RMS
		     //err2cosgamma[i] = err2cosgamma[i] + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM);
		     err2cosgamma[i] = err2cosgamma[i] + (errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM));
		   }
		   //else if(i == nbinscCMerr && reco_CosAnglep1p2CM >  binscCMerr[i-1]) err2cosgamma[i] = err2cosgamma[i] + errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM)*errX(reco_CosAnglep1p2CM, True_CosAnglep1p2CM);
	   
		 }
	       
		     
		 //// no hammer & low PT & pn-p2
		 if(abs(norm_recopndirT-track_pfp_Mom_p[p2ind])<0.1){
		   truth_reco_p1_nobtblowPTSRC->Fill(pfp_mom[p1ind],track_pfp_Mom_p[p1ind]);
		   truth_reco_p2_nobtblowPTSRC->Fill(pfp_mom[p2ind],track_pfp_Mom_p[p2ind]);
		   truth_reco_pn_nobtblowPTSRC->Fill(norm_TruepndirT,norm_recopndirT);
		   truth_reco_Enu_nobtblowPTSRC->Fill(True_Enuvis,reco_Enuvis);
		   truth_reco_q2_nobtblowPTSRC->Fill(TrueQ2lep,reco_Q2lep);
		   truth_reco_cospnp2CM_nobtblowPTSRC->Fill(True_CosAnglep1p2CM,reco_CosAnglep1p2CM);
		   Truth_reco_Enu_nobtblowPTSRC->Fill(*nu_energy,reco_Enuvis);
		   n1++;
		   Enureco_n1.push_back(reco_Enuvis);
		   Enutruth_n1.push_back(*nu_energy);
		   hprof_Enu_nobtblowPTSRC->Fill(*nu_energy,reco_Enuvis-*nu_energy,1);
		 }///// no hammer & low PT & pn~p2
	       }/// no hammer & low PT
	       //}//// no hammer
	     }/// momenta>300 MeV
	     /// end resolution studies

	   }/// CC2P from nu
	 }/// PID requirement
       }/// min coll hits
     }/// reco ID 3 trks
   }//3 trks

    err->Fill();
   return kTRUE;
}

void hanalysis_MC_Resolution::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_MC_Resolution::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  cout<<"total number of event processed"<<totentries<<"  events passing all cuts, nobtb, lowPT "<<n2<<endl;
  cout << "Output file written" << endl;
  
  err->Write();
  
  fanalysis_Resolution->cd();
  fanalysis_Resolution->Write();

  std::cout << "root Output file written" << std::endl;
  std::cout << "start writing histos" << std::endl;
  outfile_MCResolution<<"total entries: "<<totentries<<"  events passing all cuts, nobtb, lowPT "<<n2<<std::endl;

  outfile_MCResolution<<"bin ranges ...................................................."<<std::endl;
  for(int i= 0; i<nbinscCMerr+1; i++){
    outfile_MCResolution<<"bin  "<<binscCMerr[i]<<"  error2=  "<<  err2cosCM[i] <<" number of entries at bin= "<<nentries[i]<<std::endl;
    outfile_MCResolution<<"mean per entry  "<<  sqrt(err2cosCM[i])/nentries[i] <<" RMS at bin = "<<TMath::Sqrt(err2cosCM[i]/nentries[i])<<std::endl;
  }
  outfile_MCResolution<<"total error: "<<err2CM<<" sqrt(err/n) = "<<TMath::Sqrt(err2CM/n2) <<std::endl;
  //outfile_MCResolution<<"Error from cosine resolution: "<<errorcCMreco<<" sqrt(err/n) = "<<TMath::Sqrt(errorcCMreco/n2) <<std::endl;
  outfile_MCResolution<<"Error from cosine resolution mean: "<<errorcCMreco<<" sqrt(err/n) = "<<TMath::Sqrt(errorcCMreco/nerr) <<std::endl;

  outfile_MCResolution<<"desde eficiencies ........"<<std::endl;
  for(int i= 0; i<nbinscCMerr+1; i++){
    outfile_MCResolution<<"bin  "<<binscCMerr[i]<<" number of entries at bin= "<<nentries[i]<<"   mean  "<<  err2cosgamma[i]/nentries[i] <<" RMS at bin = "<<TMath::Sqrt(err2cosgamma[i]/nentries[i])<<std::endl;
  }
  outfile_MCResolution<<"...................................................."<<std::endl;
  outfile_MCResolution<<"sample sin cortes ........"<<std::endl;
  for(int i= 0; i<nbinscCMerr+1; i++){
    outfile_MCResolution<<"bin  "<<binscCMerr[i]<<" number of entries at bin= "<<nentriesnocuts[i]<<"   error2tot  "<<  err2cosgammanocut[i]<<"   mean  "<<  err2cosgammanocut[i]/nentriesnocuts[i] <<" RMS at bin = "<<TMath::Sqrt(err2cosgammanocut[i]/nentriesnocuts[i])<<std::endl;
  }


  outfile_MCResolution<<".............Errors at Lab Frame......................................."<<std::endl;
  outfile_MCResolution<<"sample sin cortes ........"<<std::endl;
  for(int i= 0; i<nbinscLFerr+1; i++){
    outfile_MCResolution<<"bin  "<<binscLFerr[i]<<" number of entries at bin= "<<nentriesnocutsLF[i]<<"   error2tot  "<<  err2cosgammanocutLF[i]<<"   mean  "<<  err2cosgammanocutLF[i]/nentriesnocutsLF[i] <<" RMS at bin = "<<TMath::Sqrt(err2cosgammanocutLF[i]/nentriesnocutsLF[i])<<std::endl;
  }


  
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
  gStyle->SetTitleOffset(1.2,"Y");
  gStyle->SetTitleX(0.22);
  gStyle->SetTitleY(0.98);
  gStyle->SetTitleSize(0.04,"t");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderSize(0);
  //gStyle->SetPadRightMargin(0.15);

  gStyle->SetTitleSize(0.045,"xyz");
  gStyle->SetTitleFont(22,"xyz");
  gStyle->SetLabelFont(22,"xyz");
  gStyle->SetTitleOffset(2.,"y");
  gStyle->SetTitleOffset(1.,"x");

  std::cout<<"antes de los plots"<<std::endl;  
 

  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_p1_nocuts->GetXaxis()->SetTitle("truth momentum p_{1} [GeV]");
  truth_reco_p1_nocuts->GetYaxis()->SetTitle("reconstructed momentum p_{1}");
  truth_reco_p1_nocuts->Draw("colz");

  c1->Update();
  c1-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p1_nocuts_resolution.pdf");
  c1-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p1_nocuts_resolution.eps");
  
  TCanvas *c2 = new TCanvas("c2", "c2", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_p2_nocuts->GetXaxis()->SetTitle("truth momentum p_{2} [GeV]");
  truth_reco_p2_nocuts->GetYaxis()->SetTitle("reconstructed momentum p_{2}");
  truth_reco_p2_nocuts->Draw("colz");

  c2->Update();
  c2-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p2_nocuts_resolution.pdf");
  c2-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p2_nocuts_resolution.eps");

  TCanvas *c3 = new TCanvas("c3", "c3", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_pn_nocuts->GetXaxis()->SetTitle("truth momentum p_{n} [GeV]");
  truth_reco_pn_nocuts->GetYaxis()->SetTitle("reconstructed momentum p_{n}");
  truth_reco_pn_nocuts->Draw("colz");

  c3->Update();
  c3-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pn_nocuts_resolution.pdf");
  c3-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pn_nocuts_resolution.eps");
  
  TCanvas *c4 = new TCanvas("c4", "c4", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_cosp1p2LF->GetXaxis()->SetTitle("truth cos_{p1p2} Lab Frame");
  truth_reco_cosp1p2LF->GetYaxis()->SetTitle("reconstructed cos_{p1p2} Lab Frame");
  truth_reco_cosp1p2LF->Draw("colz");

  c4->Update();
  c4-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cosp1p2LF_nocuts_resolution.pdf");
  c4-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cosp1p2LF_nocuts_resolution.eps");
  
  TCanvas *c5 = new TCanvas("c5", "c5", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_pT_nocuts->GetXaxis()->SetTitle("truth missing p_{T} [GeV]");
  truth_reco_pT_nocuts->GetYaxis()->SetTitle("reconstructed missing p_{T}");
  truth_reco_pT_nocuts->Draw("colz");

  c5->Update();
  c5-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pT_nocuts_resolution.pdf");
  c5-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pT_nocuts_resolution.eps");

  TCanvas *c6 = new TCanvas("c6", "c6", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_Enu_nocuts->GetXaxis()->SetTitle("truth E_{#nu} [GeV]");
  truth_reco_Enu_nocuts->GetYaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  truth_reco_Enu_nocuts->Draw("colz");

  c6->Update();
  c6-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_Enu_nocuts_resolution.pdf");
  c6-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_Enu_nocuts_resolution.eps");

  TCanvas *c7 = new TCanvas("c7", "c7", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_q2_nocuts->GetXaxis()->SetTitle("truth Q^{2} [GeV]");
  truth_reco_q2_nocuts->GetYaxis()->SetTitle("reconstructed Q^{2} [GeV]");
  truth_reco_q2_nocuts->Draw("colz");

  c7->Update();
  c7-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_q2_nocuts_resolution.pdf");
  c7-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_q2_nocuts_resolution.eps");
  
  TCanvas *c8 = new TCanvas("c8", "c8", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_cospnp2CM_nocuts->GetXaxis()->SetTitle("truth cos #gamma_{CM}");
  truth_reco_cospnp2CM_nocuts->GetYaxis()->SetTitle("reconstructed cos #gamma_{CM}");
  truth_reco_cospnp2CM_nocuts->Draw("colz");

  c8->Update();
  c8-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nocuts_resolution.pdf");
  c8-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nocuts_resolution.eps");

  TCanvas *c9 = new TCanvas("c9", "c9", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_cospnp2CM_nobtb->GetXaxis()->SetTitle("truth cos #gamma_{CM}");
  truth_reco_cospnp2CM_nobtb->GetYaxis()->SetTitle("reconstructed cos #gamma_{CM}");
  truth_reco_cospnp2CM_nobtb->Draw("colz");

  c9->Update();
  c9-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nobtb_resolution.pdf");
  c9-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nobtb_resolution.eps");

  TCanvas *c10 = new TCanvas("c10", "c10", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_p1_nobtblowPT->GetXaxis()->SetTitle("truth momentum p_{1} [GeV]");
  truth_reco_p1_nobtblowPT->GetYaxis()->SetTitle("reconstructed momentum p_{1}");
  truth_reco_p1_nobtblowPT->Draw("colz");

  c10->Update();
  c10-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p1_nobtblowPT_resolution.pdf");
  c10-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p1_nobtblowPT_resolution.eps");

  TCanvas *c11 = new TCanvas("c11", "c11", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_p2_nobtblowPT->GetXaxis()->SetTitle("truth momentum p_{2} [GeV]");
  truth_reco_p2_nobtblowPT->GetYaxis()->SetTitle("reconstructed momentum p_{2}");
  truth_reco_p2_nobtblowPT->Draw("colz");

  c11->Update();
  c11-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p2_nobtblowPT_resolution.pdf");
  c11-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p2_nobtblowPT_resolution.eps");

  TCanvas *c12 = new TCanvas("c12", "c12", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_pn_nobtblowPT->GetXaxis()->SetTitle("truth momentum p_{n} [GeV]");
  truth_reco_pn_nobtblowPT->GetYaxis()->SetTitle("reconstructed momentum p_{n}");
  truth_reco_pn_nobtblowPT->Draw("colz");

  c12->Update();
  c12-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pn_nobtblowPT_resolution.pdf");
  c12-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pn_nobtblowPT_resolution.eps");

  TCanvas *c13 = new TCanvas("c13", "c13", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_Enu_nobtblowPT->GetXaxis()->SetTitle("truth E_{#nu} [GeV]");
  truth_reco_Enu_nobtblowPT->GetYaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  truth_reco_Enu_nobtblowPT->Draw("colz");

  c13->Update();
  c13-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_Enu_nobtblowP_resolution.pdf");
  c13-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_Enu_nobtblowP_resolution.eps");

  TCanvas *c14 = new TCanvas("c14", "c14", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_q2_nobtblowPT->GetXaxis()->SetTitle("truth Q^{2} [GeV]");
  truth_reco_q2_nobtblowPT->GetYaxis()->SetTitle("reconstructed Q^{2} [GeV]");
  truth_reco_q2_nobtblowPT->Draw("colz");

  c14->Update();
  c14-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_q2_nobtblowP_resolution.pdf");
  c14-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_q2_nobtblowP_resolution.eps");

  TCanvas *c15 = new TCanvas("c15", "c15", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_cospnp2CM_nobtblowPT->GetXaxis()->SetTitle("truth ccos #gamma_{CM}");
  truth_reco_cospnp2CM_nobtblowPT->GetYaxis()->SetTitle("reconstructed cos #gamma_{CM}");
  truth_reco_cospnp2CM_nobtblowPT->Draw("colz");

  c15->Update();
  c15-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nobtblowPT_resolution.pdf");
  c15-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nobtblowPT_resolution.eps");

  TCanvas *c16 = new TCanvas("c16", "c16", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_p1_nobtblowPTSRC->GetXaxis()->SetTitle("truth momentum p_{1} [GeV]");
  truth_reco_p1_nobtblowPTSRC->GetYaxis()->SetTitle("reconstructed momentum p_{1}");
  truth_reco_p1_nobtblowPTSRC->Draw("colz");

  c16->Update();
  c16-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p1_nobtblowPTSRC_resolution.pdf");
  c16-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p1_nobtblowPTSRC_resolution.eps");

  TCanvas *c17 = new TCanvas("c17", "c17", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_p2_nobtblowPTSRC->GetXaxis()->SetTitle("truth momentum p_{2} [GeV]");
  truth_reco_p2_nobtblowPTSRC->GetYaxis()->SetTitle("reconstructed momentum p_{2}");
  truth_reco_p2_nobtblowPTSRC->Draw("colz");

  c17->Update();
  c17-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p2_nobtblowPTSRC_resolution.pdf");
  c17-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_p2_nobtblowPTSRC_resolution.eps");

  TCanvas *c18 = new TCanvas("c18", "c18", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_pn_nobtblowPTSRC->GetXaxis()->SetTitle("truth momentum p_{n} [GeV]");
  truth_reco_pn_nobtblowPTSRC->GetYaxis()->SetTitle("reconstructed momentum p_{n}");
  truth_reco_pn_nobtblowPTSRC->Draw("colz");

  c18->Update();
  c18-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pn_nobtblowPTSRC_resolution.pdf");
  c18-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_pn_nobtblowPTSRC_resolution.eps");

  TCanvas *c19 = new TCanvas("c19", "c19", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_Enu_nobtblowPTSRC->GetXaxis()->SetTitle("truth E_{#nu} [GeV]");
  truth_reco_Enu_nobtblowPTSRC->GetYaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  truth_reco_Enu_nobtblowPTSRC->Draw("colz");

  c19->Update();
  c19-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_Enu_nobtblowPTSRC_resolution.pdf");
  c19-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_Enu_nobtblowPTSRC_resolution.eps");

  TCanvas *c20 = new TCanvas("c20", "c20", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_q2_nobtblowPTSRC->GetXaxis()->SetTitle("truth Q^{2} [GeV]");
  truth_reco_q2_nobtblowPTSRC->GetYaxis()->SetTitle("reconstructed Q^{2} [GeV]");
  truth_reco_q2_nobtblowPTSRC->Draw("colz");

  c20->Update();
  c20-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_q2_nobtblowPSRC_resolution.pdf");
  c20-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_q2_nobtblowPSRC_resolution.eps");

  TCanvas *c21 = new TCanvas("c21", "c21", 900, 900);
  gStyle->SetOptStat(kFALSE);

  truth_reco_cospnp2CM_nobtblowPTSRC->GetXaxis()->SetTitle("truth cos #gamma_{CM}");
  truth_reco_cospnp2CM_nobtblowPTSRC->GetYaxis()->SetTitle("reconstructed cos #gamma_{CM}");
  truth_reco_cospnp2CM_nobtblowPTSRC->Draw("colz");

  c21->Update();
  c21-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nobtblowPTSRC_resolution.pdf");
  c21-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/truth_reco_cospnp2CM_nobtblowPTSRC_resolution.eps");

  TCanvas *c22 = new TCanvas("c22", "c22", 900, 900);
  gStyle->SetOptStat(kFALSE);

  Truth_reco_Enu_nocuts->GetXaxis()->SetTitle("truth E_{#nu} [GeV]");
  Truth_reco_Enu_nocuts->GetYaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  Truth_reco_Enu_nocuts->Draw("colz");

  c22->Update();
  c22-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nocuts_resolution.pdf");
  c22-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nocuts_resolution.eps");

  TCanvas *c23 = new TCanvas("c23", "c23", 900, 900);
  gStyle->SetOptStat(kFALSE);

  Truth_reco_Enu_nobtb->GetXaxis()->SetTitle("truth E_{#nu} [GeV]");
  Truth_reco_Enu_nobtb->GetYaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  Truth_reco_Enu_nobtb->Draw("colz");

  c23->Update();
  c23-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nobtb_resolution.pdf");
  c23-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nobtb_resolution.eps");

  TCanvas *c24 = new TCanvas("c24", "c24", 900, 900);
  gStyle->SetOptStat(kFALSE);

  Truth_reco_Enu_nobtblowPT->GetXaxis()->SetTitle("truth E_{#nu} [GeV]");
  Truth_reco_Enu_nobtblowPT->GetYaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  Truth_reco_Enu_nobtblowPT->Draw("colz");

  c24->Update();
  c24-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nobtblowPT_resolution.pdf");
  c24-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nobtblowPT_resolution.eps");

  TCanvas *c25 = new TCanvas("c25", "c25", 900, 900);
  gStyle->SetOptStat(kFALSE);

  Truth_reco_Enu_nobtblowPTSRC->GetXaxis()->SetTitle("truth E_{#nu} [GeV]");
  Truth_reco_Enu_nobtblowPTSRC->GetYaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
  Truth_reco_Enu_nobtblowPTSRC->Draw("colz");

  c25->Update();
  c25-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nobtblowPTSRC_resolution.pdf");
  c25-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TruthGENIE_reco_Enu_nobtblowPTSRC_resolution.eps");

  //// TGraph resolucion en energia ////

  Double_t GRes_n1[n1], GEnutruth_n1[n1], GRes_n2[n2], GEnutruth_n2[n2], GRes_n3[n3], GEnutruth_n3[n3];

  for (Int_t i=0;i<n1;i++) {
    GRes_n1[i] = Enureco_n1[i] - Enutruth_n1[i];
    GEnutruth_n1[i] = Enutruth_n1[i];
  }

  for (Int_t i=0;i<n2;i++) {
    GRes_n2[i] = Enureco_n2[i]-Enutruth_n2[i];
    GEnutruth_n2[i] = Enutruth_n2[i];
  }

  for (Int_t i=0;i<n3;i++) {
    GRes_n3[i] = Enureco_n3[i]-Enutruth_n3[i];
    GEnutruth_n3[i] = Enutruth_n3[i];
  }

   TGraph *gr26  = new TGraph(n1,GEnutruth_n1,GRes_n1);
   TCanvas *c26 = new TCanvas("c26","",900, 900);

   c26->SetGrid();
   gr26->SetTitle("");
   gr26->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   gr26->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   gr26->SetMarkerColor(kRed);
   gr26->Draw("A*");

   c26->Update();
   c26-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TGResol_CC2PlowPTnobtb_vs_truth.pdf");
   c26-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TGResol_CC2PlowPTnobtb_vs_truth.eps");

   TGraph *gr27  = new TGraph(n2,GEnutruth_n2,GRes_n2);
   TCanvas *c27 = new TCanvas("c27","",900, 900);

   c27->SetGrid();
   gr27->SetTitle("");
   gr27->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   gr27->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   gr27->SetMarkerColor(kRed);
   gr27->Draw("A*");

   c27->Update();
   c27-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TGResol_CC2PlowPTnobtbSRC_vs_truth.pdf");
   c27-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TGResol_CC2PlowPTnobtbSRC_vs_truth.eps");

   TGraph *gr28  = new TGraph(n3,GEnutruth_n3,GRes_n3);
   TCanvas *c28 = new TCanvas("c28","",900, 900);

   c28->SetGrid();
   gr28->SetTitle("");
   gr28->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   gr28->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   gr28->SetMarkerColor(kRed);
   gr28->Draw("A*");

   c28->Update();
   c28-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TGResol_CC2_vs_truth.pdf");
   c28-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TGResol_CC2_vs_truth.eps");

   TCanvas *c29 = new TCanvas("c29","",900, 900);

   c29->SetGrid();
   hprof_Enu_nocuts->SetTitle("");
   hprof_Enu_nocuts->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   hprof_Enu_nocuts->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   hprof_Enu_nocuts->SetLineColor(kRed);
   hprof_Enu_nocuts->SetLineWidth(2);
   hprof_Enu_nocuts->SetMarkerColor(kRed);
   hprof_Enu_nocuts->SetMarkerStyle(20);
   hprof_Enu_nocuts->Draw();

   c29->Update();
   c29-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Enu_nocuts.pdf");
   c29-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Enu_nocuts.eps");

   TCanvas *c30 = new TCanvas("c30","",900, 900);

   c30->SetGrid();
   hprof_Enu_nobtblowPT->SetTitle("");
   hprof_Enu_nobtblowPT->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   hprof_Enu_nobtblowPT->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   hprof_Enu_nobtblowPT->SetLineColor(kRed);
   hprof_Enu_nobtblowPT->SetLineWidth(2);
   hprof_Enu_nobtblowPT->SetMarkerColor(kRed);
   hprof_Enu_nobtblowPT->SetMarkerStyle(20);
   hprof_Enu_nobtblowPT->Draw();

   c30->Update();
   c30-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Enu_nobtblowPT.pdf");
   c30-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Enu_nobtblowPT.eps");

   TCanvas *c31 = new TCanvas("c31","",900, 900);

   c31->SetGrid();
   hprof_Enu_nobtblowPTSRC->SetTitle("");
   hprof_Enu_nobtblowPTSRC->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   hprof_Enu_nobtblowPTSRC->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   hprof_Enu_nobtblowPTSRC->SetLineColor(kRed);
   hprof_Enu_nobtblowPTSRC->SetLineWidth(2);
   hprof_Enu_nobtblowPTSRC->SetMarkerColor(kRed);
   hprof_Enu_nobtblowPTSRC->SetMarkerStyle(20);
   hprof_Enu_nobtblowPTSRC->Draw();

   c31->Update();
   c31-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Enu_nobtblowPTSRC.pdf");
   c31-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Enu_nobtblowPTSRC.eps");

   ////////////////
   TCanvas *c32 = new TCanvas("c32","",900, 900);

   c32->SetGrid();
   hprof_p1_nocuts->SetTitle("");
   hprof_p1_nocuts->GetXaxis()->SetTitle("p_{1 truth}[GeV]");
   hprof_p1_nocuts->GetYaxis()->SetTitle("(p_{1 reco}- p_{1 truth})[GeV]");
   hprof_p1_nocuts->SetLineColor(kRed);
   hprof_p1_nocuts->SetLineWidth(2);
   hprof_p1_nocuts->SetMarkerColor(kRed);
   hprof_p1_nocuts->SetMarkerStyle(20);
   hprof_p1_nocuts->Draw();

   c32->Update();
   c32-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1_nocuts.pdf");
   c32-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1_nocuts.eps");

   TCanvas *c33 = new TCanvas("c33","",900, 900);

   c33->SetGrid();
   hprof_p2_nocuts->SetTitle("");
   hprof_p2_nocuts->GetXaxis()->SetTitle("p_{2 truth}[GeV]");
   hprof_p2_nocuts->GetYaxis()->SetTitle("(p_{2 reco}- p_{2 truth})[GeV]");
   hprof_p2_nocuts->SetLineColor(kRed);
   hprof_p2_nocuts->SetLineWidth(2);
   hprof_p2_nocuts->SetMarkerColor(kRed);
   hprof_p2_nocuts->SetMarkerStyle(20);
   hprof_p2_nocuts->Draw();

   c33->Update();
   c33-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2_nocuts.pdf");
   c33-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2_nocuts.eps");

   TCanvas *c34 = new TCanvas("c34","",900, 900);

   c34->SetGrid();
   hprof_pn_nocuts->SetTitle("");
   hprof_pn_nocuts->GetXaxis()->SetTitle("p_{n truth}[GeV]");
   hprof_pn_nocuts->GetYaxis()->SetTitle("(p_{n reco}- p_{n truth})[GeV]");
   hprof_pn_nocuts->SetLineColor(kRed);
   hprof_pn_nocuts->SetLineWidth(2);
   hprof_pn_nocuts->SetMarkerColor(kRed);
   hprof_pn_nocuts->SetMarkerStyle(20);
   hprof_pn_nocuts->Draw();

   c34->Update();
   c34-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pn_nocuts.pdf");
   c34-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pn_nocuts.eps");

   TCanvas *c35 = new TCanvas("c35","",900, 900);

   c35->SetGrid();
   hprof_cosp1p2LF_nocuts->SetTitle("");
   hprof_cosp1p2LF_nocuts->GetXaxis()->SetTitle("truth cos #theta_{p1p2} LF");
   hprof_cosp1p2LF_nocuts->GetYaxis()->SetTitle("(reco - truth) cos #theta_{p1p2} LF");
   hprof_cosp1p2LF_nocuts->SetLineColor(kRed);
   hprof_cosp1p2LF_nocuts->SetLineWidth(2);
   hprof_cosp1p2LF_nocuts->SetMarkerColor(kRed);
   hprof_cosp1p2LF_nocuts->SetMarkerStyle(20);
   hprof_cosp1p2LF_nocuts->Draw();

   c35->Update();
   c35-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosLF_nocuts.pdf");
   c35-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosLF_nocuts.eps");

   TCanvas *c36 = new TCanvas("c36","",900, 900);

   c36->SetGrid();
   hprof_pT_nocuts->SetTitle("");
   hprof_pT_nocuts->GetXaxis()->SetTitle("p_{T truth}[GeV]");
   hprof_pT_nocuts->GetYaxis()->SetTitle("(p_{T reco}- p_{T truth})[GeV]");
   hprof_pT_nocuts->SetLineColor(kRed);
   hprof_pT_nocuts->SetLineWidth(2);
   hprof_pT_nocuts->SetMarkerColor(kRed);
   hprof_pT_nocuts->SetMarkerStyle(20);
   hprof_pT_nocuts->Draw();

   c36->Update();
   c36-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pT_nocuts.pdf");
   c36-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pT_nocuts.eps");

   TCanvas *c37 = new TCanvas("c37","",900, 900);

   c37->SetGrid();
   hprof_TruthEnu_nocuts->SetTitle("");
   hprof_TruthEnu_nocuts->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   hprof_TruthEnu_nocuts->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   hprof_TruthEnu_nocuts->SetLineColor(kRed);
   hprof_TruthEnu_nocuts->SetLineWidth(2);
   hprof_TruthEnu_nocuts->SetMarkerColor(kRed);
   hprof_TruthEnu_nocuts->SetMarkerStyle(20);
   hprof_TruthEnu_nocuts->Draw();

   c37->Update();
   c37-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_EnuvistrutTOreco_nocuts.pdf");
   c37-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_EnuvistrutTOreco_nocuts.eps");

   TCanvas *c38 = new TCanvas("c38","",900, 900);

   c38->SetGrid();
   hprof_q2_nocuts->SetTitle("");
   hprof_q2_nocuts->GetXaxis()->SetTitle("Q^{2 truth}[GeV^2]");
   hprof_q2_nocuts->GetYaxis()->SetTitle("(Q^{2 reco}- Q^{2 truth})[GeV^2]");
   hprof_q2_nocuts->SetLineColor(kRed);
   hprof_q2_nocuts->SetLineWidth(2);
   hprof_q2_nocuts->SetMarkerColor(kRed);
   hprof_q2_nocuts->SetMarkerStyle(20);
   hprof_q2_nocuts->Draw();

   c38->Update();
   c38-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Q2_nocuts.pdf");
   c38-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Q2_nocuts.eps");

   TCanvas *c39 = new TCanvas("c39","",900, 900);

   c39->SetGrid();
   hprof_cospnp2CM_nocuts->SetTitle("");
   hprof_cospnp2CM_nocuts->GetXaxis()->SetTitle("truth cos #gamma_{CM}");
   hprof_cospnp2CM_nocuts->GetYaxis()->SetTitle("(reco - truth) cos #gamma_{CM}");
   hprof_cospnp2CM_nocuts->SetLineColor(kRed);
   hprof_cospnp2CM_nocuts->SetLineWidth(2);
   hprof_cospnp2CM_nocuts->SetMarkerColor(kRed);
   hprof_cospnp2CM_nocuts->SetMarkerStyle(20);
   hprof_cospnp2CM_nocuts->Draw();

   c39->Update();
   c39-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosCM_nocuts.pdf");
   c39-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosCM_nocuts.eps");

   //////////////////////////

   TCanvas *c40 = new TCanvas("c40","",900, 900);

   c40->SetGrid();
   hprof_p1_nobtblowPT->SetTitle("");
   hprof_p1_nobtblowPT->GetXaxis()->SetTitle("p_{1 truth}[GeV]");
   hprof_p1_nobtblowPT->GetYaxis()->SetTitle("(p_{1 reco}- p_{1 truth})[GeV]");
   hprof_p1_nobtblowPT->SetLineColor(kRed);
   hprof_p1_nobtblowPT->SetLineWidth(2);
   hprof_p1_nobtblowPT->SetMarkerColor(kRed);
   hprof_p1_nobtblowPT->SetMarkerStyle(20);
   hprof_p1_nobtblowPT->Draw();

   c40->Update();
   c40-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1_nobtblowPT.pdf");
   c40-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1_nobtblowPT.eps");

   TCanvas *c41 = new TCanvas("c41","",900, 900);

   c41->SetGrid();
   hprof_p2_nobtblowPT->SetTitle("");
   hprof_p2_nobtblowPT->GetXaxis()->SetTitle("p_{2 truth}[GeV]");
   hprof_p2_nobtblowPT->GetYaxis()->SetTitle("(p_{2 reco}- p_{2 truth})[GeV]");
   hprof_p2_nobtblowPT->SetLineColor(kRed);
   hprof_p2_nobtblowPT->SetLineWidth(2);
   hprof_p2_nobtblowPT->SetMarkerColor(kRed);
   hprof_p2_nobtblowPT->SetMarkerStyle(20);
   hprof_p2_nobtblowPT->Draw();

   c41->Update();
   c41-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2_nobtblowPT.pdf");
   c41-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2_nobtblowPT.eps");

   TCanvas *c42 = new TCanvas("c42","",900, 900);

   c42->SetGrid();
   hprof_pn_nobtblowPT->SetTitle("");
   hprof_pn_nobtblowPT->GetXaxis()->SetTitle("p_{n truth}[GeV]");
   hprof_pn_nobtblowPT->GetYaxis()->SetTitle("(p_{n reco}- p_{n truth})[GeV]");
   hprof_pn_nobtblowPT->SetLineColor(kRed);
   hprof_pn_nobtblowPT->SetLineWidth(2);
   hprof_pn_nobtblowPT->SetMarkerColor(kRed);
   hprof_pn_nobtblowPT->SetMarkerStyle(20);
   hprof_pn_nobtblowPT->Draw();

   c42->Update();
   c42-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pn_nobtblowPT.pdf");
   c42-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pn_nobtblowPT.eps");

   TCanvas *c43 = new TCanvas("c43","",900, 900);

   c43->SetGrid();
   hprof_cosp1p2LF_nobtblowPT->SetTitle("");
   hprof_cosp1p2LF_nobtblowPT->GetXaxis()->SetTitle("truth cos #theta_{p1p2} LF");
   hprof_cosp1p2LF_nobtblowPT->GetYaxis()->SetTitle("(reco - truth) cos #theta_{p1p2} LF");
   hprof_cosp1p2LF_nobtblowPT->SetLineColor(kRed);
   hprof_cosp1p2LF_nobtblowPT->SetLineWidth(2);
   hprof_cosp1p2LF_nobtblowPT->SetMarkerColor(kRed);
   hprof_cosp1p2LF_nobtblowPT->SetMarkerStyle(20);
   hprof_cosp1p2LF_nobtblowPT->Draw();

   c43->Update();
   c43-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosLF_nobtblowPT.pdf");
   c43-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosLF_nobtblowPT.eps");

   TCanvas *c44 = new TCanvas("c44","",900, 900);

   c44->SetGrid();
   hprof_pT_nobtblowPT->SetTitle("");
   hprof_pT_nobtblowPT->GetXaxis()->SetTitle("p_{T truth}[GeV]");
   hprof_pT_nobtblowPT->GetYaxis()->SetTitle("(p_{T reco}- p_{T truth})[GeV]");
   hprof_pT_nobtblowPT->SetLineColor(kRed);
   hprof_pT_nobtblowPT->SetLineWidth(2);
   hprof_pT_nobtblowPT->SetMarkerColor(kRed);
   hprof_pT_nobtblowPT->SetMarkerStyle(20);
   hprof_pT_nobtblowPT->Draw();

   c44->Update();
   c44-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pT_nobtblowPT.pdf");
   c44-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pT_nobtblowPT.eps");

   TCanvas *c45 = new TCanvas("c45","",900, 900);

   c45->SetGrid();
   hprof_TruthEnu_nobtblowPT->SetTitle("");
   hprof_TruthEnu_nobtblowPT->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   hprof_TruthEnu_nobtblowPT->GetYaxis()->SetTitle("(E_{#nu reco}- E_{#nu truth})[GeV]");
   hprof_TruthEnu_nobtblowPT->SetLineColor(kRed);
   hprof_TruthEnu_nobtblowPT->SetLineWidth(2);
   hprof_TruthEnu_nobtblowPT->SetMarkerColor(kRed);
   hprof_TruthEnu_nobtblowPT->SetMarkerStyle(20);
   hprof_TruthEnu_nobtblowPT->Draw();

   c45->Update();
   c45-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_EnuvistrutTOreco_nobtblowPT.pdf");
   c45-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_EnuvistrutTOreco_nobtblowPT.eps");

   TCanvas *c46 = new TCanvas("c46","",900, 900);

   c46->SetGrid();
   hprof_q2_nobtblowPT->SetTitle("");
   hprof_q2_nobtblowPT->GetXaxis()->SetTitle("Q^{2 truth}[GeV^2]");
   hprof_q2_nobtblowPT->GetYaxis()->SetTitle("(Q^{2 reco}- Q^{2 truth})[GeV^2]");
   hprof_q2_nobtblowPT->SetLineColor(kRed);
   hprof_q2_nobtblowPT->SetLineWidth(2);
   hprof_q2_nobtblowPT->SetMarkerColor(kRed);
   hprof_q2_nobtblowPT->SetMarkerStyle(20);
   hprof_q2_nobtblowPT->Draw();

   c46->Update();
   c46-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Q2_nobtblowPT.pdf");
   c46-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_Q2_nobtblowPT.eps");

   TCanvas *c47 = new TCanvas("c47","",900, 900);

   c47->SetGrid();
   hprof_cospnp2CM_nobtblowPT->SetTitle("");
   hprof_cospnp2CM_nobtblowPT->GetXaxis()->SetTitle("truth cos #gamma_{CM}");
   hprof_cospnp2CM_nobtblowPT->GetYaxis()->SetTitle("(reco - truth) cos #gamma_{CM}");
   hprof_cospnp2CM_nobtblowPT->SetLineColor(kRed);
   hprof_cospnp2CM_nobtblowPT->SetLineWidth(2);
   hprof_cospnp2CM_nobtblowPT->SetMarkerColor(kRed);
   hprof_cospnp2CM_nobtblowPT->SetMarkerStyle(20);
   hprof_cospnp2CM_nobtblowPT->Draw();

   c47->Update();
   c47-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosCM_nobtblowPT.pdf");
   c47-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_cosCM_nobtblowPT.eps");

   TCanvas *c48 = new TCanvas("c48","",900, 900);

   c48->SetGrid();
   hprof_TruthEnucaloTrueGENIE_nocuts->SetTitle("");
   hprof_TruthEnucaloTrueGENIE_nocuts->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   hprof_TruthEnucaloTrueGENIE_nocuts->GetYaxis()->SetTitle("(E_{#nu truth calo}- E_{#nu truth})[GeV]");
   hprof_TruthEnucaloTrueGENIE_nocuts->SetLineColor(kRed);
   hprof_TruthEnucaloTrueGENIE_nocuts->SetLineWidth(2);
   hprof_TruthEnucaloTrueGENIE_nocuts->SetMarkerColor(kRed);
   hprof_TruthEnucaloTrueGENIE_nocuts->SetMarkerStyle(20);
   hprof_TruthEnucaloTrueGENIE_nocuts->Draw();

   c48->Update();
   c48-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthEnucaloTrueGENIE_nocuts.pdf");
   c48-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthEnucaloTrueGENIE_nocuts.eps");
   
   TCanvas *c49 = new TCanvas("c49","",900, 900);

   c49->SetGrid();
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->SetTitle("");
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->GetXaxis()->SetTitle("E_{#nu truth}[GeV]");
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->GetYaxis()->SetTitle("(E_{#nu truth calo}- E_{#nu truth})[GeV]");
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->SetLineColor(kRed);
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->SetLineWidth(2);
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->SetMarkerColor(kRed);
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->SetMarkerStyle(20);
   hprof_TruthEnucaloTrueGENIE_nobtblowPT->Draw();

   c49->Update();
   c49-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthEnucaloTrueGENIE__nobtblowPT.pdf");
   c49-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthEnucaloTrueGENIE__nobtblowPT.eps");

   TCanvas *c50 = new TCanvas("c50","",900, 900);

   c50->SetGrid();
   hprof_pmux_nocuts->SetTitle("");
   hprof_pmux_nocuts->GetXaxis()->SetTitle("p_{#mu x truth}[GeV]");
   hprof_pmux_nocuts->GetYaxis()->SetTitle("(p_{#mu x truth}- p_{#mu x reco})[GeV]");
   hprof_pmux_nocuts->SetLineColor(kRed);
   hprof_pmux_nocuts->SetLineWidth(2);
   hprof_pmux_nocuts->SetMarkerColor(kRed);
   hprof_pmux_nocuts->SetMarkerStyle(20);
   hprof_pmux_nocuts->Draw();

   c50->Update();
   c50-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmux_nocuts.pdf");
   c50-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmux_nocuts.eps");

   TCanvas *c51 = new TCanvas("c51","",900, 900);

   c51->SetGrid();
   hprof_p1x_nocuts->SetTitle("");
   hprof_p1x_nocuts->GetXaxis()->SetTitle("p_{1x truth}[GeV]");
   hprof_p1x_nocuts->GetYaxis()->SetTitle("(p_{1x truth}- p_{1x reco})[GeV]");
   hprof_p1x_nocuts->SetLineColor(kRed);
   hprof_p1x_nocuts->SetLineWidth(2);
   hprof_p1x_nocuts->SetMarkerColor(kRed);
   hprof_p1x_nocuts->SetMarkerStyle(20);
   hprof_p1x_nocuts->Draw();

   c51->Update();
   c51-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1x_nocuts.pdf");
   c51-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1x_nocuts.eps");

   TCanvas *c52 = new TCanvas("c52","",900, 900);

   c52->SetGrid();
   hprof_p2x_nocuts->SetTitle("");
   hprof_p2x_nocuts->GetXaxis()->SetTitle("p_{2x truth}[GeV]");
   hprof_p2x_nocuts->GetYaxis()->SetTitle("(p_{2x truth}- p_{2x reco})[GeV]");
   hprof_p2x_nocuts->SetLineColor(kRed);
   hprof_p2x_nocuts->SetLineWidth(2);
   hprof_p2x_nocuts->SetMarkerColor(kRed);
   hprof_p2x_nocuts->SetMarkerStyle(20);
   hprof_p2x_nocuts->Draw();

   c52->Update();
   c52-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2x_nocuts.pdf");
   c52-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2x_nocuts.eps");

   TCanvas *c53 = new TCanvas("c53","",900, 900);

   c53->SetGrid();
   hprof_pmuy_nocuts->SetTitle("");
   hprof_pmuy_nocuts->GetXaxis()->SetTitle("p_{#mu y truth}[GeV]");
   hprof_pmuy_nocuts->GetYaxis()->SetTitle("(p_{#mu y truth}- p_{#mu y reco})[GeV]");
   hprof_pmuy_nocuts->SetLineColor(kRed);
   hprof_pmuy_nocuts->SetLineWidth(2);
   hprof_pmuy_nocuts->SetMarkerColor(kRed);
   hprof_pmuy_nocuts->SetMarkerStyle(20);
   hprof_pmuy_nocuts->Draw();

   c53->Update();
   c53-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuy_nocuts.pdf");
   c53-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuy_nocuts.eps");

   TCanvas *c54 = new TCanvas("c54","",900, 900);

   c54->SetGrid();
   hprof_p1y_nocuts->SetTitle("");
   hprof_p1y_nocuts->GetXaxis()->SetTitle("p_{1y truth}[GeV]");
   hprof_p1y_nocuts->GetYaxis()->SetTitle("(p_{1y truth}- p_{1y reco})[GeV]");
   hprof_p1y_nocuts->SetLineColor(kRed);
   hprof_p1y_nocuts->SetLineWidth(2);
   hprof_p1y_nocuts->SetMarkerColor(kRed);
   hprof_p1y_nocuts->SetMarkerStyle(20);
   hprof_p1y_nocuts->Draw();

   c54->Update();
   c54-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1y_nocuts.pdf");
   c54-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1y_nocuts.eps");

   TCanvas *c55 = new TCanvas("c55","",900, 900);

   c55->SetGrid();
   hprof_p2y_nocuts->SetTitle("");
   hprof_p2y_nocuts->GetXaxis()->SetTitle("p_{2y truth}[GeV]");
   hprof_p2y_nocuts->GetYaxis()->SetTitle("(p_{2y truth}- p_{2y reco})[GeV]");
   hprof_p2y_nocuts->SetLineColor(kRed);
   hprof_p2y_nocuts->SetLineWidth(2);
   hprof_p2y_nocuts->SetMarkerColor(kRed);
   hprof_p2y_nocuts->SetMarkerStyle(20);
   hprof_p2y_nocuts->Draw();

   c55->Update();
   c55-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2y_nocuts.pdf");
   c55-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2y_nocuts.eps");

   TCanvas *c56 = new TCanvas("c56","",900, 900);

   c56->SetGrid();
   hprof_pmuz_nocuts->SetTitle("");
   hprof_pmuz_nocuts->GetXaxis()->SetTitle("p_{#mu z truth}[GeV]");
   hprof_pmuz_nocuts->GetYaxis()->SetTitle("(p_{#mu z truth}- p_{#mu z reco})[GeV]");
   hprof_pmuz_nocuts->SetLineColor(kRed);
   hprof_pmuz_nocuts->SetLineWidth(2);
   hprof_pmuz_nocuts->SetMarkerColor(kRed);
   hprof_pmuz_nocuts->SetMarkerStyle(20);
   hprof_pmuz_nocuts->Draw();

   c56->Update();
   c56-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuz_nocuts.pdf");
   c56-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuz_nocuts.eps");

   TCanvas *c57 = new TCanvas("c57","",900, 900);

   c57->SetGrid();
   hprof_p1z_nocuts->SetTitle("");
   hprof_p1z_nocuts->GetXaxis()->SetTitle("p_{1z truth}[GeV]");
   hprof_p1z_nocuts->GetYaxis()->SetTitle("(p_{1z truth}- p_{1z reco})[GeV]");
   hprof_p1z_nocuts->SetLineColor(kRed);
   hprof_p1z_nocuts->SetLineWidth(2);
   hprof_p1z_nocuts->SetMarkerColor(kRed);
   hprof_p1z_nocuts->SetMarkerStyle(20);
   hprof_p1z_nocuts->Draw();

   c57->Update();
   c57-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1z_nocuts.pdf");
   c57-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1z_nocuts.eps");

   TCanvas *c58 = new TCanvas("c58","",900, 900);

   c58->SetGrid();
   hprof_p2z_nocuts->SetTitle("");
   hprof_p2z_nocuts->GetXaxis()->SetTitle("p_{2z truth}[GeV]");
   hprof_p2z_nocuts->GetYaxis()->SetTitle("(p_{2z truth}- p_{2z reco})[GeV]");
   hprof_p2z_nocuts->SetLineColor(kRed);
   hprof_p2z_nocuts->SetLineWidth(2);
   hprof_p2z_nocuts->SetMarkerColor(kRed);
   hprof_p2z_nocuts->SetMarkerStyle(20);
   hprof_p2z_nocuts->Draw();

   c58->Update();
   c58-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2z_nocuts.pdf");
   c58-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2z_nocuts.eps");

   TCanvas *c59 = new TCanvas("c59","",900, 900);

   c59->SetGrid();
   hprof_pmux_nobtblowPT->SetTitle("");
   hprof_pmux_nobtblowPT->GetXaxis()->SetTitle("p_{#mu x truth}[GeV]");
   hprof_pmux_nobtblowPT->GetYaxis()->SetTitle("(p_{#mu x truth}- p_{#mu x reco})[GeV]");
   hprof_pmux_nobtblowPT->SetLineColor(kRed);
   hprof_pmux_nobtblowPT->SetLineWidth(2);
   hprof_pmux_nobtblowPT->SetMarkerColor(kRed);
   hprof_pmux_nobtblowPT->SetMarkerStyle(20);
   hprof_pmux_nobtblowPT->Draw();

   c59->Update();
   c59-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmux_nobtblowPT.pdf");
   c59-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmux_nobtblowPT.eps");

   TCanvas *c60 = new TCanvas("c60","",900, 900);

   c60->SetGrid();
   hprof_p1x_nobtblowPT->SetTitle("");
   hprof_p1x_nobtblowPT->GetXaxis()->SetTitle("p_{1x truth}[GeV]");
   hprof_p1x_nobtblowPT->GetYaxis()->SetTitle("(p_{1x truth}- p_{1x reco})[GeV]");
   hprof_p1x_nobtblowPT->SetLineColor(kRed);
   hprof_p1x_nobtblowPT->SetLineWidth(2);
   hprof_p1x_nobtblowPT->SetMarkerColor(kRed);
   hprof_p1x_nobtblowPT->SetMarkerStyle(20);
   hprof_p1x_nobtblowPT->Draw();

   c60->Update();
   c60-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1x_nobtblowPT.pdf");
   c60-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1x_nobtblowPT.eps");

   TCanvas *c61 = new TCanvas("c61","",900, 900);

   c61->SetGrid();
   hprof_p2x_nobtblowPT->SetTitle("");
   hprof_p2x_nobtblowPT->GetXaxis()->SetTitle("p_{2x truth}[GeV]");
   hprof_p2x_nobtblowPT->GetYaxis()->SetTitle("(p_{2x truth}- p_{2x reco})[GeV]");
   hprof_p2x_nobtblowPT->SetLineColor(kRed);
   hprof_p2x_nobtblowPT->SetLineWidth(2);
   hprof_p2x_nobtblowPT->SetMarkerColor(kRed);
   hprof_p2x_nobtblowPT->SetMarkerStyle(20);
   hprof_p2x_nobtblowPT->Draw();

   c61->Update();
   c61-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2x_nobtblowPT.pdf");
   c61-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2x_nobtblowPT.eps");

   TCanvas *c62 = new TCanvas("c62","",900, 900);

   c62->SetGrid();
   hprof_pmuy_nobtblowPT->SetTitle("");
   hprof_pmuy_nobtblowPT->GetXaxis()->SetTitle("p_{#mu y truth}[GeV]");
   hprof_pmuy_nobtblowPT->GetYaxis()->SetTitle("(p_{#mu y truth}- p_{#mu y reco})[GeV]");
   hprof_pmuy_nobtblowPT->SetLineColor(kRed);
   hprof_pmuy_nobtblowPT->SetLineWidth(2);
   hprof_pmuy_nobtblowPT->SetMarkerColor(kRed);
   hprof_pmuy_nobtblowPT->SetMarkerStyle(20);
   hprof_pmuy_nobtblowPT->Draw();

   c62->Update();
   c62-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuy_nobtblowPT.pdf");
   c62-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuy_nobtblowPT.eps");

   TCanvas *c63 = new TCanvas("c63","",900, 900);

   c63->SetGrid();
   hprof_p1y_nobtblowPT->SetTitle("");
   hprof_p1y_nobtblowPT->GetXaxis()->SetTitle("p_{1y truth}[GeV]");
   hprof_p1y_nobtblowPT->GetYaxis()->SetTitle("(p_{1y truth}- p_{1y reco})[GeV]");
   hprof_p1y_nobtblowPT->SetLineColor(kRed);
   hprof_p1y_nobtblowPT->SetLineWidth(2);
   hprof_p1y_nobtblowPT->SetMarkerColor(kRed);
   hprof_p1y_nobtblowPT->SetMarkerStyle(20);
   hprof_p1y_nobtblowPT->Draw();

   c63->Update();
   c63-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1y_nobtblowPT.pdf");
   c63-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1y_nobtblowPT.eps");

   TCanvas *c64 = new TCanvas("c64","",900, 900);

   c64->SetGrid();
   hprof_p2y_nobtblowPT->SetTitle("");
   hprof_p2y_nobtblowPT->GetXaxis()->SetTitle("p_{2y truth}[GeV]");
   hprof_p2y_nobtblowPT->GetYaxis()->SetTitle("(p_{2y truth}- p_{2y reco})[GeV]");
   hprof_p2y_nobtblowPT->SetLineColor(kRed);
   hprof_p2y_nobtblowPT->SetLineWidth(2);
   hprof_p2y_nobtblowPT->SetMarkerColor(kRed);
   hprof_p2y_nobtblowPT->SetMarkerStyle(20);
   hprof_p2y_nobtblowPT->Draw();

   c64->Update();
   c64-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2y_nobtblowPT.pdf");
   c64-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2y_nobtblowPT.eps");

   TCanvas *c65 = new TCanvas("c65","",900, 900);

   c65->SetGrid();
   hprof_pmuz_nobtblowPT->SetTitle("");
   hprof_pmuz_nobtblowPT->GetXaxis()->SetTitle("p_{#mu z truth}[GeV]");
   hprof_pmuz_nobtblowPT->GetYaxis()->SetTitle("(p_{#mu z truth}- p_{#mu z reco})[GeV]");
   hprof_pmuz_nobtblowPT->SetLineColor(kRed);
   hprof_pmuz_nobtblowPT->SetLineWidth(2);
   hprof_pmuz_nobtblowPT->SetMarkerColor(kRed);
   hprof_pmuz_nobtblowPT->SetMarkerStyle(20);
   hprof_pmuz_nobtblowPT->Draw();

   c65->Update();
   c65-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuz_nobtblowPT.pdf");
   c65-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_pmuz_nobtblowPT.eps");

   TCanvas *c66 = new TCanvas("c66","",900, 900);

   c66->SetGrid();
   hprof_p1z_nobtblowPT->SetTitle("");
   hprof_p1z_nobtblowPT->GetXaxis()->SetTitle("p_{1z truth}[GeV]");
   hprof_p1z_nobtblowPT->GetYaxis()->SetTitle("(p_{1z truth}- p_{1z reco})[GeV]");
   hprof_p1z_nobtblowPT->SetLineColor(kRed);
   hprof_p1z_nobtblowPT->SetLineWidth(2);
   hprof_p1z_nobtblowPT->SetMarkerColor(kRed);
   hprof_p1z_nobtblowPT->SetMarkerStyle(20);
   hprof_p1z_nobtblowPT->Draw();

   c66->Update();
   c66-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1z_nobtblowPT.pdf");
   c66-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p1z_nobtblowPT.eps");

   TCanvas *c67 = new TCanvas("c67","",900, 900);

   c67->SetGrid();
   hprof_p2z_nobtblowPT->SetTitle("");
   hprof_p2z_nobtblowPT->GetXaxis()->SetTitle("p_{2z truth}[GeV]");
   hprof_p2z_nobtblowPT->GetYaxis()->SetTitle("(p_{2z truth}- p_{2z reco})[GeV]");
   hprof_p2z_nobtblowPT->SetLineColor(kRed);
   hprof_p2z_nobtblowPT->SetLineWidth(2);
   hprof_p2z_nobtblowPT->SetMarkerColor(kRed);
   hprof_p2z_nobtblowPT->SetMarkerStyle(20);
   hprof_p2z_nobtblowPT->Draw();

   c67->Update();
   c67-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2z_nobtblowPT.pdf");
   c67-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_p2z_nobtblowPT.eps");

   TCanvas *c68 = new TCanvas("c68","",900, 900);

   c68->SetGrid();
   hprof_Truthcospnp2CM_nocuts->SetTitle("");
   hprof_Truthcospnp2CM_nocuts->GetXaxis()->SetTitle("truth cos #gamma_{CM}");
   hprof_Truthcospnp2CM_nocuts->GetYaxis()->SetTitle("(reco - truth) cos #gamma_{CM}");
   hprof_Truthcospnp2CM_nocuts->SetLineColor(kRed);
   hprof_Truthcospnp2CM_nocuts->SetLineWidth(2);
   hprof_Truthcospnp2CM_nocuts->SetMarkerColor(kRed);
   hprof_Truthcospnp2CM_nocuts->SetMarkerStyle(20);
   hprof_Truthcospnp2CM_nocuts->Draw();

   c68->Update();
   c68-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthcCM_nocuts.pdf");
   c68-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthcCM_nocuts.eps");

   TCanvas *c69 = new TCanvas("c69","",900, 900);

   c69->SetGrid();
   hprof_Truthcospnp2CM_nobtblowPT->SetTitle("");
   hprof_Truthcospnp2CM_nobtblowPT->GetXaxis()->SetTitle("truth cos #gamma_{CM}");
   hprof_Truthcospnp2CM_nobtblowPT->GetYaxis()->SetTitle("(reco - truth) cos #gamma_{CM}");
   hprof_Truthcospnp2CM_nobtblowPT->SetLineColor(kRed);
   hprof_Truthcospnp2CM_nobtblowPT->SetLineWidth(2);
   hprof_Truthcospnp2CM_nobtblowPT->SetMarkerColor(kRed);
   hprof_Truthcospnp2CM_nobtblowPT->SetMarkerStyle(20);
   hprof_Truthcospnp2CM_nobtblowPT->Draw();

   c69->Update();
   c69-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthcCM_nobtblowPT.pdf");
   c69-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/TProfResol_TruthcCM_nobtblowPT.eps");

   ////// errores

   TCanvas *c70 = new TCanvas("c70","",900, 900);

   c70->SetGrid();
   hprof_cosp1p2LF_vs_reco_nocuts->SetTitle("");
   hprof_cosp1p2LF_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed cos #theta_{p1p2} lab frame");
   hprof_cosp1p2LF_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) cos #theta_{p1p2} lab frame");
   hprof_cosp1p2LF_vs_reco_nocuts->SetLineColor(kRed);
   hprof_cosp1p2LF_vs_reco_nocuts->SetLineWidth(2);
   hprof_cosp1p2LF_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_cosp1p2LF_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_cosp1p2LF_vs_reco_nocuts->Draw();

   c70->Update();
   c70-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cosp1p2LF_nocuts.pdf");
   c70-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cosp1p2LF_nocuts.eps");

   TCanvas *c71 = new TCanvas("c71","",900, 900);

   c71->SetGrid();
   hprof_pT_vs_reco_nocuts->SetTitle("");
   hprof_pT_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed p^{T}_missing [GeV]");
   hprof_pT_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) p^{T}_missing [GeV]");
   hprof_pT_vs_reco_nocuts->SetLineColor(kRed);
   hprof_pT_vs_reco_nocuts->SetLineWidth(2);
   hprof_pT_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_pT_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_pT_vs_reco_nocuts->Draw();

   c71->Update();
   c71-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_pT_nocuts.pdf");
   c71-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_pT_nocuts.eps");

   TCanvas *c72 = new TCanvas("c72","",900, 900);

   c72->SetGrid();
   hprof_p1_vs_reco_nocuts->SetTitle("");
   hprof_p1_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed p_1 [GeV]");
   hprof_p1_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) p_1 [GeV]");
   hprof_p1_vs_reco_nocuts->SetLineColor(kRed);
   hprof_p1_vs_reco_nocuts->SetLineWidth(2);
   hprof_p1_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_p1_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_p1_vs_reco_nocuts->Draw();

   c72->Update();
   c72-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_p1_nocuts.pdf");
   c72-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_p1_nocuts.eps");

   TCanvas *c73 = new TCanvas("c73","",900, 900);

   c73->SetGrid();
   hprof_p2_vs_reco_nocuts->SetTitle("");
   hprof_p2_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed p_2 [GeV]");
   hprof_p2_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) p_2 [GeV]");
   hprof_p2_vs_reco_nocuts->SetLineColor(kRed);
   hprof_p2_vs_reco_nocuts->SetLineWidth(2);
   hprof_p2_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_p2_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_p2_vs_reco_nocuts->Draw();

   c73->Update();
   c73-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_p2_nocuts.pdf");
   c73-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_p2_nocuts.eps");

   TCanvas *c74 = new TCanvas("c74","",900, 900);

   c74->SetGrid();
   hprof_pn_vs_reco_nocuts->SetTitle("");
   hprof_pn_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed p_n [GeV]");
   hprof_pn_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) p_n [GeV]");
   hprof_pn_vs_reco_nocuts->SetLineColor(kRed);
   hprof_pn_vs_reco_nocuts->SetLineWidth(2);
   hprof_pn_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_pn_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_pn_vs_reco_nocuts->Draw();

   c74->Update();
   c74-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_pn_nocuts.pdf");
   c74-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_pn_nocuts.eps");

   TCanvas *c75 = new TCanvas("c75","",900, 900);

   c75->SetGrid();
   hprof_Enu_vs_reco_nocuts->SetTitle("");
   hprof_Enu_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
   hprof_Enu_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) E_{#nu} [GeV]");
   hprof_Enu_vs_reco_nocuts->SetLineColor(kRed);
   hprof_Enu_vs_reco_nocuts->SetLineWidth(2);
   hprof_Enu_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_Enu_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_Enu_vs_reco_nocuts->Draw();

   c75->Update();
   c75-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_Enu_nocuts.pdf");
   c75-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_Enu_nocuts.eps");

   TCanvas *c76 = new TCanvas("c76","",900, 900);

   c76->SetGrid();
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetTitle("");
   hprof_Truthcospnp2CM_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed cos #gamma_{CM}");
   hprof_Truthcospnp2CM_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth (E_{#nu} GENIE) cos #gamma_{CM}");
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetLineColor(kRed);
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetLineWidth(2);
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_Truthcospnp2CM_vs_reco_nocuts->Draw();

   c76->Update();
   c76-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nocuts_EnuGENIE.pdf");
   c76-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nocuts_EnuGENIE.eps");

   TCanvas *c77 = new TCanvas("c77","",900, 900);

   c77->SetGrid();
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->SetTitle("");
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->GetXaxis()->SetTitle("reconstructed cos #gamma_{CM}");
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->GetYaxis()->SetTitle("(reco - truth) cos #gamma_{CM}");
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->SetLineColor(kRed);
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->SetLineWidth(2);
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->SetMarkerColor(kRed);
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->SetMarkerStyle(20);
   hprof_Truthcospnp2CM_vs_reco_nobtblowPT->Draw();

   c77->Update();
   c77-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nobtblowPT_EnuGENIE.pdf");
   c77-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nobtblowPT_EnuGENIE.eps");

   //// con todos los cortes
   

   TCanvas *c78 = new TCanvas("c78","",900, 900);

   c78->SetGrid();
   hprof_p2_vs_reco_nobtblowPT->SetTitle("");
   hprof_p2_vs_reco_nobtblowPT->GetXaxis()->SetTitle("reconstructed p_2 [GeV]");
   hprof_p2_vs_reco_nobtblowPT->GetYaxis()->SetTitle("(reco - truth) p_2 [GeV]");
   hprof_p2_vs_reco_nobtblowPT->SetLineColor(kRed);
   hprof_p2_vs_reco_nobtblowPT->SetLineWidth(2);
   hprof_p2_vs_reco_nobtblowPT->SetMarkerColor(kRed);
   hprof_p2_vs_reco_nobtblowPT->SetMarkerStyle(20);
   hprof_p2_vs_reco_nobtblowPT->Draw();

   c78->Update();
   c78-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_p2_nobtblowPT.pdf");
   c78-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_p2_nobtblowPT.eps");

   TCanvas *c79 = new TCanvas("c79","",900, 900);

   c79->SetGrid();
   hprof_pn_vs_reco_nobtblowPT->SetTitle("");
   hprof_pn_vs_reco_nobtblowPT->GetXaxis()->SetTitle("reconstructed p_n [GeV]");
   hprof_pn_vs_reco_nobtblowPT->GetYaxis()->SetTitle("(reco - truth) p_n [GeV]");
   hprof_pn_vs_reco_nobtblowPT->SetLineColor(kRed);
   hprof_pn_vs_reco_nobtblowPT->SetLineWidth(2);
   hprof_pn_vs_reco_nobtblowPT->SetMarkerColor(kRed);
   hprof_pn_vs_reco_nobtblowPT->SetMarkerStyle(20);
   hprof_pn_vs_reco_nobtblowPT->Draw();

   c79->Update();
   c79-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_pn_nobtblowPT.pdf");
   c79-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_pn_nobtblowPT.eps");

   TCanvas *c80 = new TCanvas("c80","",900, 900);

   c80->SetGrid();
   hprof_Enu_vs_reco_nocuts->SetTitle("");
   hprof_Enu_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed E_{#nu} [GeV]");
   hprof_Enu_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth) E_{#nu} [GeV]");
   hprof_Enu_vs_reco_nocuts->SetLineColor(kRed);
   hprof_Enu_vs_reco_nocuts->SetLineWidth(2);
   hprof_Enu_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_Enu_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_Enu_vs_reco_nocuts->Draw();

   c80->Update();
   c80-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_Enu_nobtblowPT.pdf");
   c80-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_Enu_nobtblowPT.eps");

   TCanvas *c81 = new TCanvas("c81","",900, 900);

   c81->SetGrid();
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetTitle("");
   hprof_Truthcospnp2CM_vs_reco_nocuts->GetXaxis()->SetTitle("reconstructed cos #gamma_{CM}");
   hprof_Truthcospnp2CM_vs_reco_nocuts->GetYaxis()->SetTitle("(reco - truth (E_{#nu} GENIE) cos #gamma_{CM}");
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetLineColor(kRed);
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetLineWidth(2);
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetMarkerColor(kRed);
   hprof_Truthcospnp2CM_vs_reco_nocuts->SetMarkerStyle(20);
   hprof_Truthcospnp2CM_vs_reco_nocuts->Draw();

   c81->Update();
   c81-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nobtblowPT_EnuGENIE.pdf");
   c81-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nobtblowPT_EnuGENIE.eps");

   TCanvas *c82 = new TCanvas("c82","",900, 900);

   c82->SetGrid();
   hprof_cosp1p2CM_vs_reco_nobtblowPT->SetTitle("");
   hprof_cosp1p2CM_vs_reco_nobtblowPT->GetXaxis()->SetTitle("reconstructed cos #gamma_{CM}");
   hprof_cosp1p2CM_vs_reco_nobtblowPT->GetYaxis()->SetTitle("(reco - truth) cos #gamma_{CM}");
   hprof_cosp1p2CM_vs_reco_nobtblowPT->SetLineColor(kRed);
   hprof_cosp1p2CM_vs_reco_nobtblowPT->SetLineWidth(2);
   hprof_cosp1p2CM_vs_reco_nobtblowPT->SetMarkerColor(kRed);
   hprof_cosp1p2CM_vs_reco_nobtblowPT->SetMarkerStyle(20);
   hprof_cosp1p2CM_vs_reco_nobtblowPT->Draw();

   c82->Update();
   c82-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nobtblowPT.pdf");
   c82-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/errors/Error_cCM_nobtblowPT.eps");
}
