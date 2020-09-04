#define hanalysis_fOnBeam_minColl_cxx
// The class definition in hanalysis_fOnBeam_minColl.h has been generated automatically
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
// root> T->Process("hanalysis_fOnBeam_minColl.C")
// root> T->Process("hanalysis_fOnBeam_minColl.C","some options")
// root> T->Process("hanalysis_fOnBeam_minColl.C+")
//


#include "hanalysis_fOnBeam_minColl.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfileOnBeam_minColl;
TFile *fanalysis_OnBeam_minColl;

TH1D *selmuon_lenght_OnBeam_minColl;
TH1D *selmuon_mom_OnBeam_minColl;
TH1D *selmuon_contained_mom_OnBeam_minColl;
TH1D *selmuon_uncontained_mom_OnBeam_minColl;
TH1D *selmuon_costheta_OnBeam_minColl;
TH1D *selmuon_phi_OnBeam_minColl;
TH1D *selmuon_chi2proton_OnBeam_minColl;
TH1D *selmuon_chi2proton_cont_OnBeam_minColl;
TH2D *selmuon_dEdx_vs_resrange_OnBeam_minColl;
TH1D *selmuon_chi2proton_uncont_OnBeam_minColl;

TH1D *selproton1_lenght_OnBeam_minColl;
TH1D *selproton1_mom_OnBeam_minColl;
TH1D *selproton1_costheta_OnBeam_minColl;
TH1D *selproton1_phi_OnBeam_minColl;
TH1D *selproton1_chi2proton_OnBeam_minColl;
TH2D *selproton1_dEdx_vs_resrange_OnBeam_minColl;

TH1D *selproton2_lenght_OnBeam_minColl;
TH1D *selproton2_mom_OnBeam_minColl;
TH1D *selproton2_costheta_OnBeam_minColl;
TH1D *selproton2_phi_OnBeam_minColl;
TH1D *selproton2_chi2proton_OnBeam_minColl;
TH2D *selproton2_dEdx_vs_resrange_OnBeam_minColl;

int totentries =0;
int protons =0;

float FVx = 256.35;
float FVy = 233;
float FVz = 1036.8;
float borderx = 12.;
float bordery = 35.;
float borderz = 25.;

//This function returns if a 3D point is within the fiducial volume
bool inFV(float x, float y, float z) {
    if(x < (FVx - borderx) && (x > borderx) && (y < (FVy/2. - bordery)) && (y > (-FVy/2. + bordery)) && (z < (FVz - 85)) && (z > borderz)) return true;
    else return false;
}

void hanalysis_fOnBeam_minColl::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   fanalysis_OnBeam_minColl= new TFile("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/analysis_minColl_OnBeam.root","RECREATE");
   outfileOnBeam_minColl.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_minColl_OnBeam.txt");

   std::cout<<"declaring histos"<<endl;

   selmuon_lenght_OnBeam_minColl= new TH1D("selmuon_lenght_OnBeam_minColl", "selmuon_lenght_OnBeam_minColl", 10, 0, 500);   
   selmuon_mom_OnBeam_minColl= new TH1D("selmuon_mom_OnBeam_minColl", "selmuon_mom_OnBeam_minColl", 10, 0, 3);
   selmuon_contained_mom_OnBeam_minColl= new TH1D("selmuon_contained_mom_OnBeam_minColl", "selmuon_contained_mom_OnBeam_minColl", 10, 0, 3);   
   selmuon_uncontained_mom_OnBeam_minColl= new TH1D("selmuon_uncontained_mom_OnBeam_minColl", "selmuon_uncontained_mom_OnBeam_minColl", 10, 0, 3);
   selmuon_costheta_OnBeam_minColl= new TH1D("selmuon_costheta_OnBeam_minColl", "selmuon_costheta_OnBeam_minColl", 10, -1, 1); 
   selmuon_phi_OnBeam_minColl= new TH1D("selmuon_phi_OnBeam_minColl", "selmuon_phi_OnBeam_minColl", 10, -3.14, 3.14);
   selmuon_chi2proton_OnBeam_minColl= new TH1D("selmuon_chi2proton_OnBeam_minColl", "selmuon_chi2proton_OnBeam_minColl", 30, 0, 300);
   selmuon_chi2proton_cont_OnBeam_minColl= new TH1D("selmuon_chi2proton_cont_OnBeam_minColl", "selmuon_chi2proton_cont_OnBeam_minColl", 30, 0, 300);
   selmuon_chi2proton_uncont_OnBeam_minColl= new TH1D("selmuon_chi2proton_uncont_OnBeam_minColl", "selmuon_chi2proton_uncont_OnBeam_minColl", 30, 0, 300);
   selmuon_dEdx_vs_resrange_OnBeam_minColl = new TH2D("selmuon_dEdx_vs_resrange_OnBeam_minColl", "selmuon_dEdx_vs_resrange_OnBeam_minColl", 50,0,50,20, 0, 20);

   selproton1_lenght_OnBeam_minColl= new TH1D("selproton1_lenght_OnBeam_minColl", "selproton1_lenght_OnBeam_minColl", 10, 0, 100);   
   selproton1_mom_OnBeam_minColl= new TH1D("selproton1_mom_OnBeam_minColl", "selproton1_mom_OnBeam_minColl", 10, 0, 3);
   selproton1_costheta_OnBeam_minColl= new TH1D("selproton1_costheta_OnBeam_minColl", "selproton1_costheta_OnBeam_minColl", 10, -1, 1); 
   selproton1_phi_OnBeam_minColl= new TH1D("selproton1_phi_OnBeam_minColl", "selproton1_phi_OnBeam_minColl", 10, -3.14, 3.14);
   selproton1_chi2proton_OnBeam_minColl= new TH1D("selproton1_chi2proton_OnBeam_minColl", "selproton1_chi2proton_OnBeam_minColl", 10, 0, 300);
   selproton1_dEdx_vs_resrange_OnBeam_minColl = new TH2D("selproton1_dEdx_vs_resrange_OnBeam_minColl", "selproton1_dEdx_vs_resrange_OnBeam_minColl", 50,0,50,20, 0, 20);

   selproton2_lenght_OnBeam_minColl= new TH1D("selproton2_lenght_OnBeam_minColl", "selproton2_lenght_OnBeam_minColl", 10, 0, 100);   
   selproton2_mom_OnBeam_minColl= new TH1D("selproton2_mom_OnBeam_minColl", "selproton2_mom_OnBeam_minColl", 10, 0, 3);
   selproton2_costheta_OnBeam_minColl= new TH1D("selproton2_costheta_OnBeam_minColl", "selproton2_costheta_OnBeam_minColl", 10, -1, 1); 
   selproton2_phi_OnBeam_minColl= new TH1D("selproton2_phi_OnBeam_minColl", "selproton2_phi_OnBeam_minColl", 10, -3.14, 3.14);
   selproton2_chi2proton_OnBeam_minColl= new TH1D("selproton2_chi2proton_OnBeam_minColl", "selproton2_chi2proton_OnBeam_minColl", 10, 0, 300);
   selproton2_dEdx_vs_resrange_OnBeam_minColl = new TH2D("selproton2_dEdx_vs_resrange_OnBeam_minColl", "selproton2_dEdx_vs_resrange_OnBeam_minColl", 50,0,50,20, 0, 20);

}

void hanalysis_fOnBeam_minColl::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t hanalysis_fOnBeam_minColl::Process(Long64_t entry)
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
     ///loop over all the proton candidates
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       //if(!inFV(track_pfp_startx[np], track_pfp_starty[np], track_pfp_startz[np]) || !inFV(track_pfp_endx[np], track_pfp_endy[np], track_pfp_endz[np])) {tempflag=false;};
       if (!*pfp_upinFVflag) tempflag=false;
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

     if(muind !=-1 && p1ind !=-1 && p2ind !=-1 && tempflag){/// requirements
       if(track_pfp_dEdx[muind].size()<5 ||track_pfp_dEdx[p1ind].size()<5 ||track_pfp_dEdx[p2ind].size()<5) minColl=false;

       if(minColl){

       totentries++;

       selmuon_lenght_OnBeam_minColl->Fill(track_pfp_length[muind]);
       selmuon_mom_OnBeam_minColl->Fill(*track_pfp_mom_mucand);
       selmuon_costheta_OnBeam_minColl->Fill(track_pfp_costheta[muind]);
       selmuon_phi_OnBeam_minColl->Fill(track_pfp_phi[muind]);
       selmuon_chi2proton_OnBeam_minColl->Fill(track_pfp_chi2_proton[muind]);
       
       for(int i =0; i< track_pfp_dEdx[muind].size(); ++i){
	 selmuon_dEdx_vs_resrange_OnBeam_minColl->Fill(track_pfp_RR[muind][i],track_pfp_dEdx[muind][i]);
       }
             
       ////contained
       if(inFV(track_pfp_startx[muind], track_pfp_starty[muind], track_pfp_startz[muind]) && inFV(track_pfp_endx[muind], track_pfp_endy[muind], track_pfp_endz[muind])){
	 selmuon_chi2proton_cont_OnBeam_minColl->Fill(track_pfp_chi2_proton[muind]);
       }
       else{ //uncontained
	 selmuon_chi2proton_uncont_OnBeam_minColl->Fill(track_pfp_chi2_proton[muind]);
       }

       selproton1_lenght_OnBeam_minColl->Fill(track_pfp_length[p1ind]);
       selproton2_lenght_OnBeam_minColl->Fill(track_pfp_length[p2ind]);
       selproton1_costheta_OnBeam_minColl->Fill(track_pfp_costheta[p1ind]);
       selproton2_costheta_OnBeam_minColl->Fill(track_pfp_costheta[p2ind]);
       selproton1_phi_OnBeam_minColl->Fill(track_pfp_phi[p1ind]);
       selproton2_phi_OnBeam_minColl->Fill(track_pfp_phi[p2ind]);
       selproton1_chi2proton_OnBeam_minColl->Fill(track_pfp_chi2_proton[p1ind]);
       selproton2_chi2proton_OnBeam_minColl->Fill(track_pfp_chi2_proton[p2ind]);
       
       for(int i =0; i< track_pfp_dEdx[p1ind].size(); ++i){
	 selproton1_dEdx_vs_resrange_OnBeam_minColl->Fill(track_pfp_RR[p1ind][i],track_pfp_dEdx[p1ind][i]);
       }
       for(int i =0; i< track_pfp_dEdx[p2ind].size(); ++i){
	 selproton2_dEdx_vs_resrange_OnBeam_minColl->Fill(track_pfp_RR[p2ind][i],track_pfp_dEdx[p2ind][i]);
       }
       }
     }/// muon, p1, p2
   }// 3 trks

   return kTRUE;
}

void hanalysis_fOnBeam_minColl::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_fOnBeam_minColl::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   outfileOnBeam_minColl<<"total number of event processed"<<totentries<<endl;
   cout << "Output file written" << endl;

   fanalysis_OnBeam_minColl->cd();
   fanalysis_OnBeam_minColl->Write(); 

}
