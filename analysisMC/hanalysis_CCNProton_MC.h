//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 22 16:53:14 2018 by ROOT version 6.06/08
// from TTree cc1unptree/
// found on file: /uboone/app/users/rcastill/ubooneprefilterv06_26_01_13XSEC/work/PlotsPID/files/merged_output_Aug092018_2135_v4/ubxsec_output_mc_bnbcosmic_merged.root
//////////////////////////////////////////////////////////

#ifndef hanalysis_CCNProton_MC_h
#define hanalysis_CCNProton_MC_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include "TLorentzVector.h"

#include <vector>

#include <string>



class hanalysis_CCNProton_MC : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> run = {fReader, "run"};
   TTreeReaderValue<Int_t> subrun = {fReader, "subrun"};
   TTreeReaderValue<Int_t> event = {fReader, "event"};
   TTreeReaderValue<Double_t> bnb_correction = {fReader, "bnb_correction"};
   TTreeReaderValue<Bool_t> status_ccincl = {fReader, "status_ccincl"};
   TTreeReaderValue<Bool_t> status_ccpi0 = {fReader, "status_ccpi0"};
   TTreeReaderValue<Double_t> nu_energy = {fReader, "nu_energy"};
   TTreeReaderValue<Int_t> nu_ccnc = {fReader, "nu_ccnc"};
   TTreeReaderValue<Int_t> nu_pdg = {fReader, "nu_pdg"};
   TTreeReaderValue<Int_t> nu_mode = {fReader, "nu_mode"};
   TTreeReaderValue<Double_t> _lep_mom = {fReader, "_lep_mom"};
   TTreeReaderValue<Double_t> _lep_costheta = {fReader, "_lep_costheta"};
   TTreeReaderValue<Double_t> _lep_phi = {fReader, "_lep_phi"};
   //TTreeReaderValue<TLorentzVector> fHitNucP4 = {fReader, "fHitNucP4"};
   TTreeReaderValue<Float_t> _fTruenuvrtxx = {fReader, "_fTruenuvrtxx"};
   TTreeReaderValue<Float_t> _fTruenuvrtxy = {fReader, "_fTruenuvrtxy"};
   TTreeReaderValue<Float_t> _fTruenuvrtxz = {fReader, "_fTruenuvrtxz"};
   TTreeReaderArray<double> trueProtonsTrueMomentum = {fReader, "trueProtonsTrueMomentum"};
   TTreeReaderArray<double> trueProtonsTrueTheta = {fReader, "trueProtonsTrueTheta"};
   TTreeReaderArray<double> trueProtonsTruePhi = {fReader, "trueProtonsTruePhi"};
   TTreeReaderArray<double> trueProtonsEndMomentum = {fReader, "trueProtonsEndMomentum"};
   TTreeReaderArray<string> trueProtonsEndProcess = {fReader, "trueProtonsEndProcess"};
   TTreeReaderArray<int> fhg4parpdg = {fReader, "fhg4parpdg"};
   TTreeReaderArray<int> fhg4parstatus = {fReader, "fhg4parstatus"};
   TTreeReaderArray<float> fhg4parpx = {fReader, "fhg4parpx"};
   TTreeReaderArray<float> fhg4parpy = {fReader, "fhg4parpy"};
   TTreeReaderArray<float> fhg4parpz = {fReader, "fhg4parpz"};
   TTreeReaderArray<float> fhg4partheta = {fReader, "fhg4partheta"};
   TTreeReaderArray<float> fhg4parphi = {fReader, "fhg4parphi"};
   TTreeReaderArray<float> fhg4parp = {fReader, "fhg4parp"};
   TTreeReaderValue<Bool_t> OOFVflag = {fReader, "OOFVflag"};
   TTreeReaderValue<Bool_t> ccinclflag = {fReader, "ccinclflag"};
   TTreeReaderValue<Bool_t> ntrk2flag = {fReader, "ntrk2flag"};
   TTreeReaderValue<Bool_t> noextrkflag = {fReader, "noextrkflag"};
   TTreeReaderValue<Bool_t> upinFVflag = {fReader, "upinFVflag"};
   TTreeReaderValue<Bool_t> pdqdxflag = {fReader, "pdqdxflag"};
   TTreeReaderValue<Bool_t> pfp_ntrk2flag = {fReader, "pfp_ntrk2flag"};
   TTreeReaderValue<Bool_t> pfp_upinFVflag = {fReader, "pfp_upinFVflag"};
   TTreeReaderValue<Bool_t> pfp_pdqdxflag = {fReader, "pfp_pdqdxflag"};
   TTreeReaderValue<Int_t> npfps = {fReader, "npfps"};
   TTreeReaderValue<Int_t> npfp_tracks = {fReader, "npfp_tracks"};
   TTreeReaderValue<Int_t> npfp_showers = {fReader, "npfp_showers"};
   TTreeReaderValue<vector<bool>> pfp_isTrack = {fReader, "pfp_isTrack"};
   TTreeReaderValue<vector<bool>> pfp_isShower = {fReader, "pfp_isShower"};
   TTreeReaderValue<vector<bool>> pfp_isPrimary = {fReader, "pfp_isPrimary"};
   TTreeReaderArray<int> pfp_ndaughters = {fReader, "pfp_ndaughters"};
   TTreeReaderArray<int> pfp_pdg = {fReader, "pfp_pdg"};
   TTreeReaderArray<int> pfp_origin = {fReader, "pfp_origin"};
   TTreeReaderArray<int> pfp_parId = {fReader, "pfp_parId"};
   TTreeReaderArray<int> pfp_status = {fReader, "pfp_status"};
   TTreeReaderArray<float> pfp_theta = {fReader, "pfp_theta"};
   TTreeReaderArray<float> pfp_costheta = {fReader, "pfp_costheta"};
   TTreeReaderArray<float> pfp_phi = {fReader, "pfp_phi"};
   TTreeReaderArray<float> pfp_mom = {fReader, "pfp_mom"};
   TTreeReaderArray<float> pfp_startx = {fReader, "pfp_startx"};
   TTreeReaderArray<float> pfp_starty = {fReader, "pfp_starty"};
   TTreeReaderArray<float> pfp_startz = {fReader, "pfp_startz"};
   TTreeReaderArray<float> pfp_endx = {fReader, "pfp_endx"};
   TTreeReaderArray<float> pfp_endy = {fReader, "pfp_endy"};
   TTreeReaderArray<float> pfp_endz = {fReader, "pfp_endz"};
   TTreeReaderArray<float> pfp_endE = {fReader, "pfp_endE"};
   TTreeReaderArray<float> pfp_KE = {fReader, "pfp_KE"};
   TTreeReaderArray<float> pfp_Mass = {fReader, "pfp_Mass"};
   TTreeReaderValue<vector<bool>> track_pfp_upflag = {fReader, "track_pfp_upflag"};
   TTreeReaderArray<int> track_pfp_Id = {fReader, "track_pfp_Id"};
   TTreeReaderArray<float> track_pfp_length = {fReader, "track_pfp_length"};
   TTreeReaderArray<float> track_pfp_theta = {fReader, "track_pfp_theta"};
   TTreeReaderArray<float> track_pfp_costheta = {fReader, "track_pfp_costheta"};
   TTreeReaderArray<float> track_pfp_phi = {fReader, "track_pfp_phi"};
   TTreeReaderArray<float> track_pfp_startx = {fReader, "track_pfp_startx"};
   TTreeReaderArray<float> track_pfp_starty = {fReader, "track_pfp_starty"};
   TTreeReaderArray<float> track_pfp_startz = {fReader, "track_pfp_startz"};
   TTreeReaderArray<float> track_pfp_endx = {fReader, "track_pfp_endx"};
   TTreeReaderArray<float> track_pfp_endy = {fReader, "track_pfp_endy"};
   TTreeReaderArray<float> track_pfp_endz = {fReader, "track_pfp_endz"};
   TTreeReaderArray<float> track_pfp_Mom = {fReader, "track_pfp_Mom"};
   TTreeReaderArray<float> track_pfp_Mom_p = {fReader, "track_pfp_Mom_p"};
   TTreeReaderArray<float> track_pfp_Mom_MCS = {fReader, "track_pfp_Mom_MCS"};
   TTreeReaderArray<float> track_pfp_trunmeandqdx = {fReader, "track_pfp_trunmeandqdx"};
   TTreeReaderArray<float> track_pfp_trunmeandqdx_U = {fReader, "track_pfp_trunmeandqdx_U"};
   TTreeReaderArray<float> track_pfp_trunmeandqdx_V = {fReader, "track_pfp_trunmeandqdx_V"};
   TTreeReaderArray<float> track_pfp_pida = {fReader, "track_pfp_pida"};
   TTreeReaderArray<float> track_pfp_newpid_pida = {fReader, "track_pfp_newpid_pida"};
   TTreeReaderArray<float> track_pfp_chi2_proton = {fReader, "track_pfp_chi2_proton"};
   TTreeReaderArray<float> track_pfp_bragg_ratio = {fReader, "track_pfp_bragg_ratio"};
   TTreeReaderArray<float> track_pfp_bragg_proton = {fReader, "track_pfp_bragg_proton"};
   TTreeReaderArray<float> track_pfp_bragg_fwd_proton = {fReader, "track_pfp_bragg_fwd_proton"};
   TTreeReaderArray<float> track_pfp_bragg_bwd_proton = {fReader, "track_pfp_bragg_bwd_proton"};
   TTreeReaderArray<float> track_pfp_bragg_fwd_mip = {fReader, "track_pfp_bragg_fwd_mip"};
   TTreeReaderArray<int> track_pfp_nhits = {fReader, "track_pfp_nhits"};
   TTreeReaderArray<vector<double>> track_pfp_dEdx = {fReader, "track_pfp_dEdx"};
   TTreeReaderArray<vector<double>> track_pfp_dQdx = {fReader, "track_pfp_dQdx"};
   TTreeReaderArray<vector<double>> track_pfp_RR = {fReader, "track_pfp_RR"};
   TTreeReaderValue<Float_t> track_pfp_mom_mucand = {fReader, "track_pfp_mom_mucand"};
   TTreeReaderArray<float> track_pfp_mom_pcand = {fReader, "track_pfp_mom_pcand"};
   TTreeReaderValue<Int_t> ntrks = {fReader, "ntrks"};
   TTreeReaderValue<Float_t> _nuvtxx_reco = {fReader, "_nuvtxx_reco"};
   TTreeReaderValue<Float_t> _nuvtxy_reco = {fReader, "_nuvtxy_reco"};
   TTreeReaderValue<Float_t> _nuvtxz_reco = {fReader, "_nuvtxz_reco"};
   TTreeReaderArray<int> upflag = {fReader, "upflag"};
   TTreeReaderArray<int> trackId = {fReader, "trackId"};
   TTreeReaderArray<float> tracklength = {fReader, "tracklength"};
   TTreeReaderArray<float> trackmom = {fReader, "trackmom"};
   TTreeReaderArray<float> trackcostheta = {fReader, "trackcostheta"};
   TTreeReaderArray<float> trackphi = {fReader, "trackphi"};
   TTreeReaderArray<double> trackstartx = {fReader, "trackstartx"};
   TTreeReaderArray<double> trackstarty = {fReader, "trackstarty"};
   TTreeReaderArray<double> trackstartz = {fReader, "trackstartz"};
   TTreeReaderArray<double> trackendx = {fReader, "trackendx"};
   TTreeReaderArray<double> trackendy = {fReader, "trackendy"};
   TTreeReaderArray<double> trackendz = {fReader, "trackendz"};
   TTreeReaderArray<float> tracktrunmeandqdx = {fReader, "tracktrunmeandqdx"};
   TTreeReaderArray<float> tracktrunmeandqdx_U = {fReader, "tracktrunmeandqdx_U"};
   TTreeReaderArray<float> tracktrunmeandqdx_V = {fReader, "tracktrunmeandqdx_V"};
   TTreeReaderArray<vector<double>> trackdEdx = {fReader, "trackdEdx"};
   TTreeReaderArray<vector<double>> trackRR = {fReader, "trackRR"};
   TTreeReaderArray<int> tracknhits = {fReader, "tracknhits"};
   TTreeReaderArray<int> trackcand_origin = {fReader, "trackcand_origin"};
   TTreeReaderArray<int> trackcand_nuset = {fReader, "trackcand_nuset"};
   TTreeReaderArray<int> trackcand_parPDG = {fReader, "trackcand_parPDG"};
   TTreeReaderArray<int> trackcand_parStatusCode = {fReader, "trackcand_parStatusCode"};
   TTreeReaderArray<float> trackcand_parTheta = {fReader, "trackcand_parTheta"};
   TTreeReaderArray<float> trackcand_parCosTheta = {fReader, "trackcand_parCosTheta"};
   TTreeReaderArray<float> trackcand_parSinTheta = {fReader, "trackcand_parSinTheta"};
   TTreeReaderArray<float> trackcand_parE = {fReader, "trackcand_parE"};
   TTreeReaderArray<float> trackcand_parMass = {fReader, "trackcand_parMass"};
   TTreeReaderArray<float> trackcand_parKE = {fReader, "trackcand_parKE"};
   TTreeReaderArray<float> trackcand_parEndE = {fReader, "trackcand_parEndE"};
   TTreeReaderArray<float> trackcand_parPx = {fReader, "trackcand_parPx"};
   TTreeReaderArray<float> trackcand_parPy = {fReader, "trackcand_parPy"};
   TTreeReaderArray<float> trackcand_parPz = {fReader, "trackcand_parPz"};
   TTreeReaderArray<float> trackcand_parCosPhi = {fReader, "trackcand_parCosPhi"};
   TTreeReaderArray<float> trackcand_parSinPhi = {fReader, "trackcand_parSinPhi"};
   TTreeReaderValue<Float_t> trackmom_mucand = {fReader, "trackmom_mucand"};
   TTreeReaderArray<float> trackmom_pcand = {fReader, "trackmom_pcand"};
   TTreeReaderValue<Int_t> truthtop = {fReader, "truthtop"};
   TTreeReaderValue<Int_t> truthtop_200thresh = {fReader, "truthtop_200thresh"};
   TTreeReaderValue<Int_t> truthtop_300thresh = {fReader, "truthtop_300thresh"};
   TTreeReaderValue<Int_t> truthtop_400thresh = {fReader, "truthtop_400thresh"};
   TTreeReaderValue<Int_t> truthtop_genie = {fReader, "truthtop_genie"};
   TTreeReaderValue<Int_t> truthtop_genie_200thresh = {fReader, "truthtop_genie_200thresh"};
   TTreeReaderValue<Int_t> truthtop_genie_300thresh = {fReader, "truthtop_genie_300thresh"};
   TTreeReaderValue<Int_t> truthtop_genie_400thresh = {fReader, "truthtop_genie_400thresh"};


   hanalysis_CCNProton_MC(TTree * /*tree*/ =0) { }
   virtual ~hanalysis_CCNProton_MC() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(hanalysis_CCNProton_MC,0);

};

#endif

#ifdef hanalysis_CCNProton_MC_cxx
void hanalysis_CCNProton_MC::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t hanalysis_CCNProton_MC::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef hanalysis_CCNProton_MC_cxx
