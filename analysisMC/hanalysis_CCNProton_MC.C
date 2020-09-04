#define hanalysis_CCNProton_MC_cxx
// The class definition in hanalysis_CCNProton_MC.h has been generated automatically
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
// root> T->Process("hanalysis_CCNProton_MC.C")
// root> T->Process("hanalysis_CCNProton_MC.C","some options")
// root> T->Process("hanalysis_CCNProton_MC.C+")
//


#include "hanalysis_CCNProton_MC.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TMath.h"

#include <iostream>
#include <cstring>
using namespace std;

ofstream outfileMC_CCNProton;

int totentries =0;
int totNtracks =0;
int totPcont =0;
int totminColl =0;
int totPID =0;
int tot2P =0;

////PID purity & efficiency

int tottruemuon_selmuon =0;
int tottrueproton_selmuon =0;
int tottrueother_selmuon=0;

int tottruemuon_selproton1 =0;
int tottrueproton_selproton1 =0;
int tottrueother_selproton1 =0;

int tottruemuon_selproton2 =0;
int tottrueproton_selproton2 =0;
int tottrueother_selproton2 =0;

int passingtruemuon_selmuon =0;
int passingtrueproton_selmuon =0;
int passingtrueother_selmuon =0;

int passingtruemuon_selproton1 =0;
int passingtrueproton_selproton1 =0;
int passingtrueother_selproton1 =0;

int passingtruemuon_selproton2 =0;
int passingtrueproton_selproton2 =0;
int passingtrueother_selproton2 =0;

int numberRecoP=0;
int numberTruthP =0;

int T1R1 =0; 
int T1R2 =0;
int T1R3 =0;
int T1R4 =0;
int T1R5 =0;

int T2R1 =0;
int T2R2 =0;
int T2R3 =0;
int T2R4 =0;
int T2R5 =0;

int T3R1 =0;
int T3R2 =0;
int T3R3 =0;
int T3R4 =0;
int T3R5 =0;

int T4R1 =0;
int T4R2 =0;
int T4R3 =0;
int T4R4 =0;
int T4R5 =0;

int T5R1 =0;
int T5R2 =0;
int T5R3 =0;
int T5R4 =0;
int T5R5 =0;

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


void hanalysis_CCNProton_MC::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void hanalysis_CCNProton_MC::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   outfileMC_CCNProton.open("/uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/DataMC/MC/info_CCNProton_MC.txt");

}

Bool_t hanalysis_CCNProton_MC::Process(Long64_t entry)
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

   if(track_pfp_Id.GetSize()<1) std::cout<<"Oooops, there are less than 1 tracks: "<<track_pfp_Id.GetSize()<<std::endl;
   double trklength_temp=0;
   int muind=-1;
   if(track_pfp_Id.GetSize()>=1){/// get index muon candidate
     for(int allp=0; allp< track_pfp_Id.GetSize(); ++allp){
       if(track_pfp_length[allp]>trklength_temp){
	 muind=allp;
	 trklength_temp=track_pfp_length[allp];
       }
     }
   }

   bool trackfromneutrino=true;// by default from neutrino interation                                                                      
   //for(int ncand=0; ncand<pfp_origin.GetSize(); ncand++){
   //if(pfp_origin[ncand] !=1) trackfromneutrino=false;
   //}/// check if all pfp true associated particles are from neutrino, otherwise is a cosmic                                               
   if(muind>-1){
     if(pfp_origin[muind] !=1) trackfromneutrino=false;
     if(!trackfromneutrino) std::cout<<" cosmic "<<std::endl;
   }
   totentries++;

   bool muoninFV=true;
   bool Ntracks =false;
   bool Pcont =true;
   bool minColl =true;
   bool PID =true;
   bool N2P= false;

   bool momlead =false;
   numberRecoP=0;
   numberTruthP =0;

   if(muind>-1){
     if(*OOFVflag==1 && trackfromneutrino) topo9++;
     else if(*truthtop ==1 && trackfromneutrino) topo1++;
     else if(*truthtop ==2 && trackfromneutrino) topo2++;
     else if(*truthtop ==3 && trackfromneutrino) topo3++;
     else if(*truthtop ==4 && trackfromneutrino) topo4++;
     else if(*truthtop ==5 && trackfromneutrino) topo5++;
     else if(*truthtop ==6 && trackfromneutrino) topo6++;
     else if(*truthtop ==7 && trackfromneutrino) topo7++;
     else if(*truthtop ==8 && trackfromneutrino) topo8++;
     //else if(*OOFVflag==1 && trackfromneutrino) topo9++;
     else if(!trackfromneutrino) topo10++;
     //else if(*OOFVflag==1 ) topo9++;
     else topo11++;
   }

   if(muind>-1 && track_pfp_Id.GetSize()>1 && muoninFV) {
     Ntracks=true;
     totNtracks++;
   }


   if ( Ntracks && !*pfp_upinFVflag) Pcont=false;
   if(Ntracks && Pcont) {
     totPcont++;
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(track_pfp_dEdx[np].size()<5)  minColl=false;
     }
   }
   if(Ntracks && Pcont && minColl){
     totminColl++;

       if(abs(pfp_pdg[muind]) ==13) tottruemuon_selmuon++;
       else if(abs(pfp_pdg[muind] ) ==2212) tottrueproton_selmuon++;
       else tottrueother_selmuon++;

       if(track_pfp_Id.GetSize()>1) {// CCNP
	 for(int np=0; np<track_pfp_Id.GetSize(); ++np){
	   if(muind==np) continue;
	   if(abs(pfp_pdg[np]) ==13) tottruemuon_selproton1++;
	   else if(abs(pfp_pdg[np]) ==2212) tottrueproton_selproton1++;
	   else tottrueother_selproton1++;
	 }
       }

       if(track_pfp_chi2_proton[muind] >88){
	 if(abs(pfp_pdg[muind]) ==13) passingtruemuon_selmuon++;
	 else if(abs(pfp_pdg[muind]) ==2212) passingtrueproton_selmuon++;
	 else passingtrueother_selmuon++;
       }
       if(track_pfp_Id.GetSize()>1) {// CCNP
	 for(int np=0; np<track_pfp_Id.GetSize(); ++np){
	   if(muind==np) continue;

	   if(track_pfp_chi2_proton[np] <88){
	     if(abs(pfp_pdg[np]) ==13) passingtruemuon_selproton1++;
	     else if(abs(pfp_pdg[np]) ==2212) passingtrueproton_selproton1++;
	     else passingtrueother_selproton1++;
	   }
	 }
       }
   
     if (track_pfp_chi2_proton[muind]<88) PID = false;
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
       if(muind==np) continue;
       if (track_pfp_chi2_proton[np]>88) PID = false;
     }
   }
   if(Ntracks && Pcont && PID && minColl) {
     totPID++;
     for(int np=0; np<track_pfp_Id.GetSize(); ++np){
	 if(np == muind) continue;
	 if(track_pfp_Mom_p[np]>0.3 && track_pfp_chi2_proton[np]<88) numberRecoP++;
	 }
	 
     for(int it =0; it<fhg4parpdg.GetSize(); it++){
       // if(abs(fhg4parpdg[it])==2212 && fhg4parp[it]>0.3) numberTruthP++; 
       if(abs(fhg4parpdg[it])==2212 && fhg4parp[it]>0.3) momlead = true;
       if (momlead) numberTruthP++;
     }
     if(numberTruthP ==1){
       if(numberRecoP==1) T1R1++;
       if(numberRecoP==2) T1R2++;
       if(numberRecoP==3) T1R3++;
       if(numberRecoP==4) T1R4++;
       if(numberRecoP==5) T1R5++;
     }
     if(numberTruthP ==2){
       if(numberRecoP==1) T2R1++;
       if(numberRecoP==2) T2R2++;
       if(numberRecoP==3) T2R3++;
       if(numberRecoP==4) T2R4++;
       if(numberRecoP==5) T2R5++;
     }
     if(numberTruthP ==3){
       if(numberRecoP==1) T3R1++;
       if(numberRecoP==2) T3R2++;
       if(numberRecoP==3) T3R3++;
       if(numberRecoP==4) T3R4++;
       if(numberRecoP==5) T3R5++;
     }
     if(numberTruthP ==4){
       if(numberRecoP==1) T4R1++;
       if(numberRecoP==2) T4R2++;
       if(numberRecoP==3) T4R3++;
       if(numberRecoP==4) T4R4++;
       if(numberRecoP==5) T4R5++;
     }
     if(numberTruthP ==5){
       if(numberRecoP==1) T5R1++;
       if(numberRecoP==2) T5R2++;
       if(numberRecoP==3) T5R3++;
       if(numberRecoP==4) T5R4++;
       if(numberRecoP==5) T5R5++;
     }
   }

   if(Ntracks && Pcont && PID && minColl && track_pfp_Id.GetSize()==3) tot2P++;

   return kTRUE;
}

void hanalysis_CCNProton_MC::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void hanalysis_CCNProton_MC::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  outfileMC_CCNProton<<"total entries: "<<totentries<<std::endl;
  outfileMC_CCNProton<<"at least 2 tracks: "<<totNtracks<<std::endl;
  outfileMC_CCNProton<<"protons containement: "<<totPcont<<std::endl;
  outfileMC_CCNProton<<"minimum number of collection hits per track: "<<totminColl<<std::endl;
  outfileMC_CCNProton<<"PID cut (muons and protons candidates): "<<totPID<<std::endl;
  outfileMC_CCNProton<<"till here it was CCNProton "<<std::endl;
  outfileMC_CCNProton<<"CC2Proton: "<<tot2P<<std::endl;


  outfileMC_CCNProton<<"CC0Pion0Proton: "<<topo1<<" purity "<<topo1<<std::endl;
  outfileMC_CCNProton<<"CC0Pion1Proton: "<<topo2<<" purity "<<(topo2/totentries)<<std::endl;
  outfileMC_CCNProton<<"CC0Pion2Proton: "<<topo3<<" purity "<<double ((topo3/totentries))<<std::endl;
  outfileMC_CCNProton<<"CC0PionNProton: "<<topo4<<" purity "<<(topo4/totentries)*100.<<std::endl;
  outfileMC_CCNProton<<"CC1PionNProton: "<<topo5<<" purity "<<(topo5/totentries)*100.<<std::endl;
  outfileMC_CCNProton<<"CCNPionNProton: "<<topo6<<" purity "<<(topo6/totentries)*100.<<std::endl;
  outfileMC_CCNProton<<"CCnue: "<<topo7<<" purity "<<(topo7/totentries)*100.<<std::endl;
  outfileMC_CCNProton<<"NC: "<<topo8<<" purity "<<(topo8/totentries)*100.<<std::endl;
  outfileMC_CCNProton<<"OOFV: "<<topo9<<" purity "<<(topo9/totentries)*100.<<std::endl;
  outfileMC_CCNProton<<"cosmic: "<<topo10<<" purity "<<(topo10/totentries)*100.<<std::endl;
  outfileMC_CCNProton<<"other: "<<topo11<<" purity "<<(topo11/totentries)*100.<<std::endl;

  std::cout<<"......."<<std::endl;

  std::cout<<"tottruemuon_selmuon = "<<tottruemuon_selmuon<<std::endl;
  std::cout<<"tottrueproton_selmuon = "<<tottrueproton_selmuon<<std::endl;
  std::cout<<"tottrueother_selmuon = "<<tottrueother_selmuon<<std::endl;

  std::cout<<"passingtruemuon_selmuon = "<<passingtruemuon_selmuon<<std::endl;
  std::cout<<"passingtrueproton_selmuon = "<<passingtrueproton_selmuon<<std::endl;
  std::cout<<"passingtrueother_selmuon = "<<passingtrueother_selmuon<<std::endl;

  std::cout<<"......."<<std::endl;
  std::cout<<"tottruemuon_selproton1 = "<<tottruemuon_selproton1<<std::endl;
  std::cout<<"tottrueproton_selproton1 = "<<tottrueproton_selproton1<<std::endl;
  std::cout<<"tottrueother_selproton1 = "<<tottrueother_selproton1<<std::endl;


  std::cout<<"passingtruemuon_selproton1 = "<<passingtruemuon_selproton1<<std::endl;
  std::cout<<"passingtrueproton_selproton1 = "<<passingtrueproton_selproton1<<std::endl;
  std::cout<<"passingtrueother_selproton1 = "<<passingtrueother_selproton1<<std::endl;


  std::cout<<"**************************************************************** "<<std::endl;

  std::cout<<"    "<<"  reco =1 "<<"   reco =2 "<<"   reco =3 "<<"   reco =4 "<<"  reco =5 "<<std::endl;
  std::cout<<"true 1  "<<T1R1<<"  "<<T1R2<<" "<<T1R3<<"  "<<T1R4<<"  "<<T1R5<<std::endl;
  std::cout<<"true 2  "<<T2R1<<"  "<<T2R2<<" "<<T2R3<<"  "<<T2R4<<"  "<<T2R5<<std::endl;
  std::cout<<"true 3  "<<T3R1<<"  "<<T3R2<<" "<<T3R3<<"  "<<T3R4<<"  "<<T3R5<<std::endl;
  std::cout<<"true 4  "<<T4R1<<"  "<<T4R2<<" "<<T4R3<<"  "<<T4R4<<"  "<<T4R5<<std::endl;
  std::cout<<"true 5  "<<T5R1<<"  "<<T5R2<<" "<<T5R3<<"  "<<T5R4<<"  "<<T1R5<<std::endl;

}
