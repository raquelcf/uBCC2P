	   /// opening angles
	   float TPlep=pfp_mom[muind];
	   float TPhad1=pfp_mom[p1ind];
	   float TPhad2=pfp_mom[p2ind];
	   float TThetaLep=pfp_theta[muind];
	   float TThetaHad1=pfp_theta[p1ind];
	   float TThetaHad2=pfp_theta[p2ind];
	   float TPhiLep=pfp_phi[muind];
	   float TPhiHad1=pfp_phi[p1ind];
	   float TPhiHad2=pfp_phi[p2ind];
	   TVector3 TmuonP(TPlep*(TMath::Sin(TThetaLep))*(TMath::Cos(TPhiLep)), TPlep*(TMath::Sin(TThetaLep))*(TMath::Sin(TPhiLep)), TPlep*(TMath::Cos(TThetaLep)));
	   TVector3 TprotonP1(TPhad1*(TMath::Sin(TThetaHad1))*(TMath::Cos(TPhiHad1)), TPhad1*(TMath::Sin(TThetaHad1))*(TMath::Sin(TPhiHad1)), TPhad1*(TMath::Cos(TThetaHad1)));
	   TVector3 TprotonP2(TPhad2*(TMath::Sin(TThetaHad2))*(TMath::Cos(TPhiHad2)), TPhad2*(TMath::Sin(TThetaHad2))*(TMath::Sin(TPhiHad2)), TPhad2*(TMath::Cos(TThetaHad2)));

	   TVector3 Ttrackpdir_mu;
	   TVector3 Ttrackpdir_p1;
	   TVector3 Ttrackpdir_p2;
  
	   Ttrackpdir_mu.SetXYZ(TMath::Sin(pfp_theta[muind])*TMath::Cos(pfp_phi[muind]),TMath::Sin(pfp_phi[muind])*TMath::Sin(pfp_theta[muind]),pfp_costheta[muind]);
	   Ttrackpdir_p1.SetXYZ(TMath::Sin(pfp_theta[p1ind])*TMath::Cos(pfp_phi[p1ind]),TMath::Sin(pfp_phi[p1ind])*TMath::Sin(pfp_theta[p1ind]),pfp_costheta[p1ind]);
	   Ttrackpdir_p2.SetXYZ(TMath::Sin(pfp_theta[p2ind])*TMath::Cos(pfp_phi[p2ind]),TMath::Sin(pfp_phi[p2ind])*TMath::Sin(pfp_theta[p2ind]),pfp_costheta[p2ind]);
   
	   Double_t Tm1 = Ttrackpdir_p1.Mag();
	   Double_t Tm2 = Ttrackpdir_p2.Mag();
	   Double_t Tmu = Ttrackpdir_mu.Mag();

	   double TCosAnglep1p2 = Ttrackpdir_p1.Dot(Ttrackpdir_p2);   // scalar product
	   TCosAnglep1p2 =  TCosAnglep1p2/(Tm1*Tm2);

	   double TCosAnglemup1 = Ttrackpdir_mu.Dot(Ttrackpdir_p1);  // scalar product
	   TCosAnglemup1 =  TCosAnglemup1/(Tmu*Tm1);

	   double TCosAnglemup2 = Ttrackpdir_mu.Dot(Ttrackpdir_p2);  // scalar product
	   TCosAnglemup2 = TCosAnglemup2/(Tmu*Tm2);

	   double Tanglemup1=TCosAnglemup1;
	   double Tanglemup2=TCosAnglemup2;
	   double Tanglep1p2=TCosAnglep1p2;/// LF angle

	   //// reco Enu & PT
	   double T_deltax= TmuonP.X()+TprotonP1.X()+TprotonP2.X();
	   double T_deltay= TmuonP.Y()+TprotonP1.Y()+TprotonP2.Y();
	   double T_PTmiss = sqrt(T_deltax*T_deltax + T_deltay*T_deltay);
	   // muon energy
	   double  T_Emuon = sqrt(pow(105.6/1000.,2) + pow(TPlep,2));

	   // protons energy
	   double T_Eprotons = sqrt(pow(938.272/1000.,2) + pow(TPhad1,2)) + sqrt(pow(938.272/1000.,2) + pow(TPhad2,2));
	   double T_Eproton1 = pow(TPhad1,2)/(2*938.272/1000.);
	   double T_Eproton2 = pow(TPhad2,2)/(2*938.272/1000.);
     
	   //double Esum= Emuon + Eprotons;
	   double T_Esum= T_Emuon + pow(TPhad1,2)/(2*938.272/1000.) + pow(TPhad2,2)/(2*938.272/1000.);
	   double T_Enuvis = Ecalomiss(T_Esum, T_PTmiss, 2)/1000.;

	   double T_CosAnglep1p2CM =-999.;
	   TVector3 T_NeuDir;
	   T_NeuDir.SetXYZ(0,0,1);

	   double T_Q3[3];/// this is Q_3 
	   for( int i = 0; i < 3; i++ ) T_Q3[i] = T_Enuvis*T_NeuDir[i] - TmuonP[i];

	   TVector3 T_Pn;
	   for( int i = 0; i < 3; i++) T_Pn[i] = TprotonP1[i] - T_Q3[i];

	   if(T_Enuvis>0) T_CosAnglep1p2CM = TprotonP2.Dot(T_Pn);
	   double norm_pndirT = sqrt(pow(T_Pn[0],2) + pow(T_Pn[1],2)+ pow(T_Pn[2],2));
	   double norm_p2dirT = sqrt(pow(TprotonP2[0],2) + pow(TprotonP2[1],2)+ pow(TprotonP2[2],2));
	   T_CosAnglep1p2CM =  T_CosAnglep1p2CM/(norm_p2dirT*norm_pndirT);

