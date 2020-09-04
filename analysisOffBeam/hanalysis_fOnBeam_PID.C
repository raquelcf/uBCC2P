#define hanalysis_fOnBeam_PID_cxx
// The class definition in hanalysis_fOnBeam_PID.h has been generated automatically
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
// root> T->Process("hanalysis_fOnBeam_PID.C")
// root> T->Process("hanalysis_fOnBeam_PID.C","some options")
// root> T->Process("hanalysis_fOnBeam_PID.C+")
//


#include "hanalysis_fOnBeam_PID.h"
#include <TH2.h>
#include <TStyle.h>

#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfileOnBeam_PID;
TFile *fanalysis_OnBeam_PID;

TFile* f0 = new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/TheoreticalPredictions_dedxresrange.root","READ");

void GetMuondEdxR(){
  //rr, dedx = array.array('f'), array.array('f')
  std::vector <float> rr, dedx;
  rr.push_back(0.9833);
  rr.push_back(1.786);
  rr.push_back(3.321);
  rr.push_back(6.598);
  rr.push_back(10.58);
  rr.push_back(30.84);
  rr.push_back(42.50);
  rr.push_back(67.50);
  rr.push_back(106.3);
  rr.push_back(172.5);
  rr.push_back(238.5);
  rr.push_back(493.4);
  rr.push_back(616.3);
  rr.push_back(855.2);
  rr.push_back(1202);
  rr.push_back(1758);
  rr.push_back(2297);
  dedx.push_back(5.687);
  dedx.push_back(4.461);
  dedx.push_back(3.502);
  dedx.push_back(2.731);
  dedx.push_back(2.340);
  dedx.push_back(1.771);
  dedx.push_back(1.670);
  dedx.push_back(1.570);
  dedx.push_back(1.519);
  dedx.push_back(1.510);
  dedx.push_back(1.526);
  dedx.push_back(1.610);
  dedx.push_back(1.645);
  dedx.push_back(1.700);
  dedx.push_back(1.761);
  dedx.push_back(1.829);
  dedx.push_back(1.877);
  for (int i=0; i< rr.size(); i++){
      rr[i]/=1.396;
      dedx[i]*=1.396;
   }
  Int_t n2=rr.size();
  float rr2[n2], dedx2[n2];
  for(int i2=0; i2<n2; i2++){
    rr2[i2]=rr[i2];
    dedx2[i2]=dedx[i2];
  }
  TGraph *gr = new TGraph(n2, rr2, dedx2);
  gr->SetLineWidth(2);
  gr->SetLineColor(3);
  gr->Draw("same");
}


TH1D *selmuon_lenght_OnBeam_PID;
TH1D *selmuon_mom_OnBeam_PID;
TH1D *selmuon_contained_mom_OnBeam_PID;
TH1D *selmuon_uncontained_mom_OnBeam_PID;
TH1D *selmuon_costheta_OnBeam_PID;
TH1D *selmuon_phi_OnBeam_PID;
TH1D *selmuon_chi2proton_OnBeam_PID;
TH1D *selmuon_chi2proton_cont_OnBeam_PID;
TH2D *selmuon_dEdx_vs_resrange_OnBeam_PID;
TH1D *selmuon_chi2proton_uncont_OnBeam_PID;

TH1D *selproton1_lenght_OnBeam_PID;
TH1D *selproton1_mom_OnBeam_PID;
TH1D *selproton1_costheta_OnBeam_PID;
TH1D *selproton1_phi_OnBeam_PID;
TH1D *selproton1_chi2proton_OnBeam_PID;
TH2D *selproton1_dEdx_vs_resrange_OnBeam_PID;

TH1D *selproton2_lenght_OnBeam_PID;
TH1D *selproton2_mom_OnBeam_PID;
TH1D *selproton2_costheta_OnBeam_PID;
TH1D *selproton2_phi_OnBeam_PID;
TH1D *selproton2_chi2proton_OnBeam_PID;
TH2D *selproton2_dEdx_vs_resrange_OnBeam_PID;


TH2D *selall_dEdx_vs_resrange_all_PID;
TProfile *hprof_all_MC;
TProfile *hprof_selprotons_MC;

/// Opening angles
TH1D *angle_mup1_OnBeam_PID;
TH1D *angle_mup2_OnBeam_PID;
TH1D *angle_p1p2_OnBeam_PID;
TH1D *cosangle_p1p2_OnBeam_PID;
/////

////////////////////////////////////////////////////////////////////////////////////
//// ArgoNeuT studies on opening angles -- reconstructed variables by reaction type/// cut on 300 MeV proton momenta
////////////////////////////////////////////////////////////////////////////////////

TH1D *reco_Enu_OnBeam_PID;
TH1D *reco_PT_OnBeam_PID;
TH1D *reco_pn_OnBeam_PID;
TH2D *p1p2_OnBeam_PID;
TH2D *reco_angle_p1p2_p2_OnBeam_PID_LF;
TH2D *reco_angle_p1p2_OnBeam_PID_LF_CM;
TH1D *reco_angle_p1p2_OnBeam_PID_LF;
TH1D *reco_angle_p1p2_OnBeam_PID_CM;
/////

int totentries =0;
int protons =0;

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

//********************************************************************
double PPCM_Tune3 (double dmumom, double dp1mom, double dp2mom, TVector3 NeuDir, TVector3 MuDir, TVector3 P1Dir, TVector3 P2Dir, double Enu, double Emuon, double Eproton1, double Eproton2) {
//********************************************************************

  if( Enu  < 0  || dmumom < 0 || dp1mom < 0 || dp2mom < 0) return -1000;

  double mumass = 105.658/1000.;
  double protonmass = 938.272/1000.;
  double bindE = 30.4/1000.;
  
  double Edelta = (protonmass-bindE) + Enu - Emuon;  // Assume target nucleon at rest. (q0)
  
  double delta[3];/// this is just Q_3 
  for( int i = 0; i < 3; i++ ) delta[i] = Enu*NeuDir[i] - dmumom*MuDir[i];////vector directors must be normalized

  double beta[3];/// proper of the boost to the Delta rest frame
  double b2 = 0.;
  
  for(int i = 0; i < 3; i++ ) {
    beta[i] = delta[i]/Edelta;
    b2 += beta[i]*beta[i]; 
  }

  double gamma = 1./TMath::Sqrt(1.-b2); 
  
  double b = TMath::Sqrt(b2);

  //std::cout<<" modulo de beta debe ser menor que 1 ----->    "<<b<<std::endl;
 
  TVector3 p1parallel;
  TVector3 p1perpend;
  TVector3 p1boost;
  double p1boostabs = 0.;

  TVector3 p2parallel;
  TVector3 p2perpend;
  TVector3 p2boost;
  double p2boostabs = 0.;
  
  TVector3 nuparallel;
  TVector3 nuperpend;
  TVector3 nuboost;
  double nuboostabs = 0.;

  TVector3 muparallel;
  TVector3 muperpend;
  TVector3 muboost;
  double muboostabs = 0.;
  
  TVector3 pnboost;
  double pnboostabs=0.;

  for(int i = 0; i < 3; i++ ) {   
    p1parallel[i] = beta[i]/b*(beta[0]/b*dp1mom*P1Dir[0]+beta[1]/b*dp1mom*P1Dir[1]+beta[2]/b*dp1mom*P1Dir[2]); // Pre boost 
    p1perpend[i] = dp1mom*P1Dir[i]-p1parallel[i];
    p1parallel[i] = gamma*(p1parallel[i]-beta[i]*Eproton1); // After boost
    p1boost[i] =  p1parallel[i]+p1perpend[i];
    p1boostabs += p1boost[i]*p1boost[i];

    p2parallel[i] = beta[i]/b*(beta[0]/b*dp2mom*P2Dir[0]+beta[1]/b*dp2mom*P2Dir[1]+beta[2]/b*dp2mom*P2Dir[2]); // Pre boost 
    p2perpend[i] = dp2mom*P2Dir[i]-p2parallel[i];
    p2parallel[i] = gamma*(p2parallel[i]-beta[i]*Eproton2); // After boost
    p2boost[i] =  p2parallel[i]+p2perpend[i];
    p2boostabs += p2boost[i]*p2boost[i];
    
    nuparallel[i] = beta[i]/b*(beta[0]/b*Enu*NeuDir[0]+beta[1]/b*Enu*NeuDir[1]+beta[2]/b*Enu*NeuDir[2]); // Pre boost
    nuperpend[i] = Enu*NeuDir[i]-nuparallel[i];
    nuparallel[i] = gamma*(nuparallel[i]-beta[i]*Enu); // After boost
    nuboost[i] =  nuparallel[i]+nuperpend[i];
    nuboostabs += nuboost[i]*nuboost[i];

    muparallel[i] = beta[i]/b*(beta[0]/b*dmumom*MuDir[0]+beta[1]/b*dmumom*MuDir[1]+beta[2]/b*dmumom*MuDir[2]); // Pre boost 
    muperpend[i] = dmumom*MuDir[i]-muparallel[i];
    muparallel[i] = gamma*(muparallel[i]-beta[i]*Emuon); // After boost
    muboost[i] =  muparallel[i]+muperpend[i];
    muboostabs += muboost[i]*muboost[i];

    pnboost[i]=p1boost[i] - delta[i];
    pnboostabs +=pnboost[i]*pnboost[i]; 
  }

  p1boostabs = TMath::Sqrt(p1boostabs);
  p2boostabs = TMath::Sqrt(p2boostabs);
  nuboostabs = TMath::Sqrt(nuboostabs);
  muboostabs = TMath::Sqrt(muboostabs);
  pnboostabs = TMath::Sqrt(pnboostabs);

  //  double p1p2CM_Tune3 = p1boost.Dot(p2boost);  // scalar product
  // p1p2CM_Tune3 =  p1p2CM_Tune3/((p1boost.Mag())*(p2boost.Mag()));

  double p1p2CM_Tune3 = p1boost.Dot(pnboost);  // scalar product
  p1p2CM_Tune3 =  p1p2CM_Tune3/(p1boostabs*pnboostabs);

  return p1p2CM_Tune3;

}/// fin del calculo de CM angle

void hanalysis_fOnBeam_PID::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   fanalysis_OnBeam_PID= new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_PID_OnBeam.root","RECREATE");
   outfileOnBeam_PID.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_PID_OnBeam.txt");

   std::cout<<"declaring histos"<<endl;

   selmuon_lenght_OnBeam_PID= new TH1D("selmuon_lenght_OnBeam_PID", "selmuon_lenght_OnBeam_PID", 10, 0, 500);   
   selmuon_mom_OnBeam_PID= new TH1D("selmuon_mom_OnBeam_PID", "selmuon_mom_OnBeam_PID", 10, 0, 3);
   selmuon_contained_mom_OnBeam_PID= new TH1D("selmuon_contained_mom_OnBeam_PID", "selmuon_contained_mom_OnBeam_PID", 10, 0, 3);   
   selmuon_uncontained_mom_OnBeam_PID= new TH1D("selmuon_uncontained_mom_OnBeam_PID", "selmuon_uncontained_mom_OnBeam_PID", 10, 0, 3);
   selmuon_costheta_OnBeam_PID= new TH1D("selmuon_costheta_OnBeam_PID", "selmuon_costheta_OnBeam_PID", 10, -1, 1); 
   selmuon_phi_OnBeam_PID= new TH1D("selmuon_phi_OnBeam_PID", "selmuon_phi_OnBeam_PID", 10, -3.14, 3.14);
   selmuon_chi2proton_OnBeam_PID= new TH1D("selmuon_chi2proton_OnBeam_PID", "selmuon_chi2proton_OnBeam_PID", 30, 0, 300);
   selmuon_chi2proton_cont_OnBeam_PID= new TH1D("selmuon_chi2proton_cont_OnBeam_PID", "selmuon_chi2proton_cont_OnBeam_PID", 30, 0, 300);
   selmuon_chi2proton_uncont_OnBeam_PID= new TH1D("selmuon_chi2proton_uncont_OnBeam_PID", "selmuon_chi2proton_uncont_OnBeam_PID", 30, 0, 300);
   selmuon_dEdx_vs_resrange_OnBeam_PID = new TH2D("selmuon_dEdx_vs_resrange_OnBeam_PID", "selmuon_dEdx_vs_resrange_OnBeam_PID", 50,0,50,20, 0, 20);

   selproton1_lenght_OnBeam_PID= new TH1D("selproton1_lenght_OnBeam_PID", "selproton1_lenght_OnBeam_PID", 10, 0, 100);   
   selproton1_costheta_OnBeam_PID= new TH1D("selproton1_costheta_OnBeam_PID", "selproton1_costheta_OnBeam_PID", 10, -1, 1); 
   selproton1_phi_OnBeam_PID= new TH1D("selproton1_phi_OnBeam_PID", "selproton1_phi_OnBeam_PID", 10, -3.14, 3.14);
   selproton1_mom_OnBeam_PID= new TH1D("selproton1_mom_OnBeam_PID", "selproton1_mom_OnBeam_PID", 10, 0, 1.5);
   selproton1_chi2proton_OnBeam_PID= new TH1D("selproton1_chi2proton_OnBeam_PID", "selproton1_chi2proton_OnBeam_PID", 10, 0, 300);
   selproton1_dEdx_vs_resrange_OnBeam_PID = new TH2D("selproton1_dEdx_vs_resrange_OnBeam_PID", "selproton1_dEdx_vs_resrange_OnBeam_PID", 50,0,50,20, 0, 20);

   selproton2_lenght_OnBeam_PID= new TH1D("selproton2_lenght_OnBeam_PID", "selproton2_lenght_OnBeam_PID", 10, 0, 40);   
   selproton2_costheta_OnBeam_PID= new TH1D("selproton2_costheta_OnBeam_PID", "selproton2_costheta_OnBeam_PID", 10, -1, 1); 
   selproton2_phi_OnBeam_PID= new TH1D("selproton2_phi_OnBeam_PID", "selproton2_phi_OnBeam_PID", 10, -3.14, 3.14);
   selproton2_mom_OnBeam_PID= new TH1D("selproton2_mom_OnBeam_PID", "selproton2_mom_OnBeam_PID", 10, 0, 1.);
   selproton2_chi2proton_OnBeam_PID= new TH1D("selproton2_chi2proton_OnBeam_PID", "selproton2_chi2proton_OnBeam_PID", 10, 0, 300);
   selproton2_dEdx_vs_resrange_OnBeam_PID = new TH2D("selproton2_dEdx_vs_resrange_OnBeam_PID", "selproton2_dEdx_vs_resrange_OnBeam_PID", 50,0,50,20, 0, 20);

   angle_mup1_OnBeam_PID= new TH1D("angle_mup1_OnBeam_PID", "angle_mup1_OnBeam_PID", 10,-1,1);
   angle_mup2_OnBeam_PID= new TH1D("angle_mup2_OnBeam_PID", "angle_mup2_OnBeam_PID", 10,-1,1);
   angle_p1p2_OnBeam_PID= new TH1D("angle_p1p2_OnBeam_PID", "angle_p1p2_OnBeam_PID", 10, -1,1);
   cosangle_p1p2_OnBeam_PID= new TH1D("cosangle_p1p2_OnBeam_PID", "cosangle_p1p2_OnBeam_PID", 10, -1,1);


   selall_dEdx_vs_resrange_all_PID = new TH2D("selall_dEdx_vs_resrange_all_PID", "selall_dEdx_vs_resrange_all_PID", 100,0,100,20, 0, 20);

   hprof_all_MC = new TProfile("hprof_all_MC", "",100,0,100,0,20);
   hprof_selprotons_MC = new TProfile("hprof_selprotons_MC", "",100,0,100,0,20);

   ///// reco ArgoNeuT studies///

   reco_Enu_OnBeam_PID= new TH1D("reco_Enu_OnBeam_PID", "reco_Enu_OnBeam_PID", 10, 0.,2.);
   reco_PT_OnBeam_PID= new TH1D("reco_PT_OnBeam_PID", "reco_PT_OnBeam_PID", 10, 0.,2.);
   reco_pn_OnBeam_PID= new TH1D("reco_pn_OnBeam_PID", "reco_pn_OnBeam_PID", 10, 0.,2.);
   p1p2_OnBeam_PID= new TH2D("p1p2_OnBeam_PID", "p1p2_OnBeam_PID", 10,0.,2., 10, 0.,2.);
   reco_angle_p1p2_p2_OnBeam_PID_LF= new TH2D("reco_angle_p1p2_p2_OnBeam_PID_LF", "reco_angle_p1p2_p2_OnBeam_PID_LF",10,0.,2., 10, 0.,2.);
   reco_angle_p1p2_OnBeam_PID_LF_CM= new TH2D("reco_angle_p1p2_OnBeam_PID_LF_CM", "reco_angle_p1p2_OnBeam_PID_LF_CM",10,-1.,1., 10, -1,1.);
   reco_angle_p1p2_OnBeam_PID_LF= new TH1D("reco_angle_p1p2_OnBeam_PID_LF", "reco_angle_p1p2_OnBeam_PID_LF",10, -1,1);
   reco_angle_p1p2_OnBeam_PID_CM= new TH1D("reco_angle_p1p2_OnBeam_PID_CM", "reco_angle_p1p2_OnBeam_PID_CM",10, -1,1);   
   
}

void hanalysis_fOnBeam_PID::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t hanalysis_fOnBeam_PID::Process(Long64_t entry)
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
   std::cout<<"before process"<<endl;

   if(track_pfp_Id.GetSize()<1) std::cout<<"Oooops, there are less than 1 tracks"<<std::endl;

   ///scpecific cuts////
   if(track_pfp_Id.GetSize()==3){/// minColl requirement
     double trklength_temp=0;
     double trklength_temp2=0;
     double trklength_temp3=0;
     int muind=-1;
     int p1ind=-1;
     int p2ind=-1;
     bool muoninFV = true;

     for(int allp=0; allp< track_pfp_Id.GetSize(); ++allp){
       if(track_pfp_length[allp]>trklength_temp){
	 muind=allp;
	 trklength_temp=track_pfp_length[allp];
       }
     }
     bool tempflag=true;
     bool minColl = true;
 
     if(muind>-1 && !inFV(*_nuvtxx_reco, *_nuvtxy_reco,*_nuvtxx_reco)) muoninFV=false;
     //if (*pfp_upinFVflag) tempflag=false;
     ///loop over all the proton candidates
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       if (!*pfp_upinFVflag) tempflag=false;
       //if(!inFV(track_pfp_startx[np], track_pfp_starty[np], track_pfp_startz[np]) || !inFV(track_pfp_endx[np], track_pfp_endy[np], track_pfp_endz[np])) {tempflag=false;};
       //if(tempflag==false) continue;
       if(track_pfp_length[np]>trklength_temp2) {
	 p1ind=np;
	 trklength_temp2=track_pfp_length[np];
       }
     }

     ////loop over all the proton candidates
   
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       if(p1ind==np) continue;
       //if(tempflag==false) continue;
       if(track_pfp_length[np]>trklength_temp3) {
	 p2ind=np;
	 trklength_temp3=track_pfp_length[np];
       }
     } //end of loop over proton candidates //second proton selected   


     if(muind !=-1 &&p1ind !=-1 && tempflag){
       
       for(int np=0; np<track_pfp_Id.GetSize(); ++np){
	 for(int i =0; i< track_pfp_dEdx[np].size(); ++i){
	   if(track_pfp_dEdx[np].size()<5) continue;
	   selall_dEdx_vs_resrange_all_PID->Fill(track_pfp_RR[np][i],track_pfp_dEdx[np][i]);
	   hprof_all_MC->Fill(track_pfp_RR[np][i],track_pfp_dEdx[np][i],1);
	  
	   if(muind==np) continue;
	   
	   if(track_pfp_chi2_proton[np]<88.) hprof_selprotons_MC->Fill(track_pfp_RR[np][i],track_pfp_dEdx[np][i],1);
	 }
       }
     }/// loop over all tracks CCNProton no PID cut

     if(muind !=-1 && p1ind !=-1 && p2ind !=-1 && tempflag){/// requirements
       if(track_pfp_dEdx[muind].size()<5 ||track_pfp_dEdx[p1ind].size()<5 ||track_pfp_dEdx[p2ind].size()<5) minColl=false;

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
       /*
       trackpdir_mu.SetXYZ(TMath::Cos(fPhiLep),TMath::Sqrt(1-pow(TMath::Cos(fPhiLep),2)- pow(TMath::Cos(fThetaLep),2)), TMath::Cos(fThetaLep));
       trackpdir_p1.SetXYZ(TMath::Cos(fPhiHad1),TMath::Sqrt(1-pow(TMath::Cos(fPhiHad1),2)- pow(TMath::Cos(fThetaHad1),2)), TMath::Cos(fThetaHad1));
       trackpdir_p2.SetXYZ(TMath::Cos(fPhiHad2),TMath::Sqrt(1-pow(TMath::Cos(fPhiHad2),2)- pow(TMath::Cos(fThetaHad2),2)), TMath::Cos(fThetaHad2));
       */

       trackpdir_mu.SetXYZ(TMath::Sin(track_pfp_theta[muind])*TMath::Cos(track_pfp_phi[muind]),TMath::Sin(track_pfp_phi[muind])*TMath::Sin(track_pfp_theta[muind]),track_pfp_costheta[muind]);
       trackpdir_p1.SetXYZ(TMath::Sin(track_pfp_theta[p1ind])*TMath::Cos(track_pfp_phi[p1ind]),TMath::Sin(track_pfp_phi[p1ind])*TMath::Sin(track_pfp_theta[p1ind]),track_pfp_costheta[p1ind]);
       trackpdir_p2.SetXYZ(TMath::Sin(track_pfp_theta[p2ind])*TMath::Cos(track_pfp_phi[p2ind]),TMath::Sin(track_pfp_phi[p2ind])*TMath::Sin(track_pfp_theta[p2ind]),track_pfp_costheta[p2ind]);

       Double_t m1 = trackpdir_p1.Mag();
       Double_t m2 = trackpdir_p2.Mag();
       Double_t mu = trackpdir_mu.Mag();

       std::cout<<"norm p1: "<<m1<<" norm p2: "<<m2<<" norm mu: "<<mu<<std::endl;
 
       double CosAnglep1p2 = trackpdir_p1.Dot(trackpdir_p2);   // scalar product
       CosAnglep1p2 =  CosAnglep1p2/(m1*m2);

       double CosAnglemup1 = trackpdir_mu.Dot(trackpdir_p1);   // scalar product
       CosAnglemup1 =  CosAnglemup1/(mu*m1);

       double CosAnglemup2 = trackpdir_mu.Dot(trackpdir_p2);   // scalar product
       CosAnglemup2 =  CosAnglemup2/(mu*m2);

       double anglemup1=CosAnglemup1;
       double anglemup2=CosAnglemup2;
       double anglep1p2=CosAnglep1p2;

       /*
       double anglemup1=muonP.Angle(protonP1);
       double anglemup2=muonP.Angle(protonP2);
       double anglep1p2=protonP1.Angle(protonP2);
       */
       //////////////

       ///// reco Enu & PT
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
     
       /////
       double reco_CosAnglep1p2CM =-999.;
       TVector3 reco_NeuDir;
       reco_NeuDir.SetXYZ(0,0,1);

       double reco_Q3[3];/// this is Q_3 
       for( int i = 0; i < 3; i++ ) reco_Q3[i] = reco_Enuvis*reco_NeuDir[i] - muonP[i];

       TVector3 reco_Pn;
       for( int i = 0; i < 3; i++) reco_Pn[i] = protonP1[i] - reco_Q3[i]; 

       if(reco_Enuvis>0) reco_CosAnglep1p2CM = protonP2.Dot(reco_Pn);
       double norm_recopndirT = sqrt(pow(reco_Pn[0],2) + pow(reco_Pn[1],2)+ pow(reco_Pn[2],2));

       reco_CosAnglep1p2CM =  reco_CosAnglep1p2CM/(m2*norm_recopndirT);
       //////

       
       selmuon_lenght_OnBeam_PID->Fill(track_pfp_length[muind]);
       selmuon_mom_OnBeam_PID->Fill(*track_pfp_mom_mucand);
       selmuon_costheta_OnBeam_PID->Fill(track_pfp_costheta[muind]);
       selmuon_phi_OnBeam_PID->Fill(track_pfp_phi[muind]);
       selmuon_chi2proton_OnBeam_PID->Fill(track_pfp_chi2_proton[muind]);
       
       for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	 selmuon_dEdx_vs_resrange_OnBeam_PID->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
       }
             
       ////contained
       if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	 selmuon_chi2proton_cont_OnBeam_PID->Fill(track_pfp_chi2_proton[muind]);
       }
       else{ //uncontained
	 selmuon_chi2proton_uncont_OnBeam_PID->Fill(track_pfp_chi2_proton[muind]);
       }

       selproton1_lenght_OnBeam_PID->Fill(track_pfp_length[p1ind]);
       selproton2_lenght_OnBeam_PID->Fill(track_pfp_length[p2ind]);
       selproton1_costheta_OnBeam_PID->Fill(track_pfp_costheta[p1ind]);
       selproton2_costheta_OnBeam_PID->Fill(track_pfp_costheta[p2ind]);
       selproton1_phi_OnBeam_PID->Fill(track_pfp_phi[p1ind]);
       selproton2_phi_OnBeam_PID->Fill(track_pfp_phi[p2ind]);
       selproton1_mom_OnBeam_PID->Fill(track_pfp_Mom_p[p1ind]);
       selproton2_mom_OnBeam_PID->Fill(track_pfp_Mom_p[p2ind]);
       selproton1_chi2proton_OnBeam_PID->Fill(track_pfp_chi2_proton[p1ind]);
       selproton2_chi2proton_OnBeam_PID->Fill(track_pfp_chi2_proton[p2ind]);
       
       for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	 selproton1_dEdx_vs_resrange_OnBeam_PID->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
       }
       for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	 selproton2_dEdx_vs_resrange_OnBeam_PID->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
       }

       angle_mup1_OnBeam_PID->Fill(anglemup1);
       angle_mup2_OnBeam_PID->Fill(anglemup2);
       angle_p1p2_OnBeam_PID->Fill(anglep1p2);
       cosangle_p1p2_OnBeam_PID->Fill(TMath::Cos(anglep1p2));

       //////
       if(track_pfp_Mom_p[p1ind]>0.3 && track_pfp_Mom_p[p2ind]>0.3){ /// require proton momenta>300 MeV
	 std::cout<<"pasa por el corte de 300 MeV en los dos protones"<<std::endl;
	 num300++;

	 p1p2_OnBeam_PID->Fill(track_pfp_Mom_p[p1ind],track_pfp_Mom_p[p2ind]);
	 reco_angle_p1p2_p2_OnBeam_PID_LF->Fill(track_pfp_Mom_p[p2ind],anglep1p2);
	 reco_angle_p1p2_OnBeam_PID_LF_CM->Fill(anglep1p2,reco_CosAnglep1p2CM);
	 reco_Enu_OnBeam_PID->Fill(reco_Enuvis);
	 reco_PT_OnBeam_PID->Fill(reco_PTmiss);
	 reco_pn_OnBeam_PID->Fill(norm_recopndirT);
	 reco_angle_p1p2_OnBeam_PID_LF->Fill(anglep1p2);
	 reco_angle_p1p2_OnBeam_PID_CM->Fill(reco_CosAnglep1p2CM);

       }///mom>300 MeV
       
	 }//PID
       }///min coll hits
     }/// muon, p1, p2
   }// 3 trks

   return kTRUE;
}

void hanalysis_fOnBeam_PID::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_fOnBeam_PID::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  outfileOnBeam_PID<<"total number of event processed "<<totentries<<std::endl;
  outfileOnBeam_PID<< "........................." << std::endl;
  outfileOnBeam_PID<< "........................." << std::endl;
  outfileOnBeam_PID<< "Number of events with p1p2>300 "<<num300 << std::endl;

   cout << "Output file written" << endl;

   fanalysis_OnBeam_PID->cd();
   fanalysis_OnBeam_PID->Write(); 


    gStyle->SetOptStat(0000);
    gStyle->SetOptFit(1111);
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
    gStyle->SetTitleSize(0.05,"Y");
    gStyle->SetTitleFont(62,"Y");
    gStyle->SetTitleOffset(1.0,"Y");
    gStyle->SetTitleX(0.22);
    gStyle->SetTitleY(0.98);
    gStyle->SetTitleSize(0.04,"t");
    gStyle->SetTitleBorderSize(0);
    gStyle->SetCanvasBorderSize(0);

    TGraph* graph=(TGraph*)f0->Get("proton");
    graph->SetLineColor(2);
    graph->SetLineWidth(2);
 
    TGraph* graphmu=(TGraph*)f0->Get("muon");
    graphmu->SetLineColor(3);
    graphmu->SetLineWidth(2);

    TF1 *f_dEdxVsRR = new TF1("f_dEdxVsRR","17 * x^(-0.42)",0,100);
    TF1 *f_dEdxVsRRmu = new TF1("f_dEdxVsRRmu","8 * x^(-0.37)",0,100);
    f_dEdxVsRRmu->SetLineColor(3);
    TF1 *f_dEdxVsRRMIP = new TF1("f_dEdxVsRRMIP","2.12",0,100);
    f_dEdxVsRRMIP->SetLineColor(6);

  TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
  selall_dEdx_vs_resrange_all_PID->SetTitle("");
  selall_dEdx_vs_resrange_all_PID->GetXaxis()->SetTitle("residual range [cm]");
  selall_dEdx_vs_resrange_all_PID->GetYaxis()->SetTitle("dE/dx [MeV/cm]");
  selall_dEdx_vs_resrange_all_PID->Draw("colz");

  //  hprof_all_MC->SetLineWidth(3);
  //hprof_all_MC->SetLineColor(kBlack);  
  //hprof_all_MC->Draw("same hist");

  TLegend* leg = new TLegend(0.65, 0.65, .9, .9);
  leg->AddEntry(graphmu, "Muon Expectation", "l");
  leg->AddEntry(graph, "Proton Expectation", "l");
  leg->AddEntry(f_dEdxVsRRMIP,"MIP expectation", "l");
  //leg -> AddEntry(hprof_all_MC, "<dE/dx> in residual range", "lep");
  f_dEdxVsRR->Draw("same");
  GetMuondEdxR();
  f_dEdxVsRRMIP->Draw("same");
  leg->Draw("same");

  c1->Update();
  c1-> Print("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/Plots/PID_300_tune3/selall_dEdx_vs_resrange_all_PID_OnBeam.pdf");

  TCanvas *c2 = new TCanvas("c2", "",900, 900);
  gStyle->SetOptStat(kFALSE);
  hprof_selprotons_MC->SetTitle("");
  hprof_selprotons_MC->GetXaxis()->SetTitle("residual range [cm]");
  hprof_selprotons_MC->GetYaxis()->SetTitle("dE/dx [MeV/cm]");
  hprof_selprotons_MC->SetLineColor(kBlack);
  hprof_selprotons_MC->Draw("E");

  TLegend* leg2 = new TLegend(0.5, 0.65, .9, .9);
  leg2->AddEntry(graphmu, "Muon Expectation", "l");
  leg2->AddEntry(graph, "Proton Expectation", "l");
  leg2->AddEntry(f_dEdxVsRRMIP,"MIP expectation", "l");
  leg2 -> AddEntry(hprof_selprotons_MC, "<dE/dx> per residual range in selected protons", "lep");
  f_dEdxVsRR->Draw("same");
  GetMuondEdxR();
  f_dEdxVsRRMIP->Draw("same");
  leg2->Draw("same");


  c2->Update();
  c2-> Print("/pnfs/uboone/persistent/users/rcastill/CC0Pion2P/Plots/BNBCosmicMC/cutsPID/hprof_protons_OnBeam.pdf");


}
