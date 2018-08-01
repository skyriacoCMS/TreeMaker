// -*- C++ -*-
//
// Package:    Treem/Analyzer
// Class:      Analyzer
//
/**\class Analyzer Analyzer.cc Treem/Analyzer/plugins/Analyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  savvas kyriacou
//         Created:  Fri, 13 Jan 2017 10:37:16 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/Common/interface/Ref.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"


#include "TH1.h"
#include "TH2.h"
#include "TLorentzVector.h"
#include "cstdlib"
#include "iostream"
#include "TTree.h"
#include <memory>
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"


//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.


using namespace std;
using namespace edm;


class Analyzer : public EDAnalyzer  {
   public:
      explicit Analyzer(const edm::ParameterSet&);
      ~Analyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  virtual void beginRun(const Run&, const EventSetup&) override; 
  virtual void endRun(const edm::Run& , const edm::EventSetup& ) override;


  //void Analyzer::beginRun(const Run& iRun, const EventSetup& iSetup){
  bool JetIsLoose(float,int,int,float,float,float);
  bool JetIsTight(float,int,int,float,float,float,float);
  bool PassJetID( float,float,float,int,float,int,float,int);


  int PassTrig(string,vector<string>, Handle < vector <float> > , Handle < vector <int> >);



  edm::EDGetTokenT<double> rhoToken_;
  edm::EDGetTokenT<int>    nvtxToken_;

  edm::EDGetTokenT<reco::GenParticleCollection> genpartsToken_; //  (consumes<reco::GenParticleCollection>(edm::InputTag("prunedGenParticles")));


  edm::EDGetTokenT< vector<float> >  ak8etaCToken_;
  edm::EDGetTokenT< vector<float> >  ak8phiCToken_;
  edm::EDGetTokenT< vector<float> >  ak8eneCToken_;
  edm::EDGetTokenT< vector<float> >  ak8ptCToken_;
  edm::EDGetTokenT< vector<float> >  ak8t1CToken_;
  edm::EDGetTokenT< vector<float> >  ak8t2CToken_;
  edm::EDGetTokenT< vector<float> >  ak8t3CToken_;
  edm::EDGetTokenT< vector<float> >  ak8sfmassCToken_;
  edm::EDGetTokenT< vector<float> >  ak8prmassCToken_;

  edm::EDGetTokenT< vector<float> > ak8CcefToken_;
  edm::EDGetTokenT< vector<float> > ak8CchfToken_;
  edm::EDGetTokenT< vector<float> > ak8CchmToken_;
  edm::EDGetTokenT< vector<float> > ak8CnmToken_;
  edm::EDGetTokenT< vector<float> > ak8CchemfToken_;
  edm::EDGetTokenT< vector<float> > ak8CareaToken_;
  edm::EDGetTokenT< vector<float> > ak8CnemfToken_;
  edm::EDGetTokenT< vector<float> > ak8CnhfToken_;
  edm::EDGetTokenT< vector<float> > ak8CnnpToken_;

  edm::EDGetTokenT< vector<float> >   ak8phoindxCToken_;
  edm::EDGetTokenT< vector<float> > ak8phosubjfCToken_;
  edm::EDGetTokenT< vector<float> >   ak8subindxCToken_;

  edm::EDGetTokenT< vector<float> >   ak8phoindxPToken_;
  edm::EDGetTokenT< vector<float> >   ak8phosubjfPToken_;

  edm::EDGetTokenT< vector<float> >   ak8subeta1Token_;
  edm::EDGetTokenT< vector<float> >   ak8subphi1Token_;
  edm::EDGetTokenT< vector<float> >   ak8subpt1Token_;

  edm::EDGetTokenT< vector<float> >   ak8subeta2Token_;
  edm::EDGetTokenT< vector<float> >   ak8subphi2Token_;
  edm::EDGetTokenT< vector<float> >   ak8subpt2Token_;

  edm::EDGetTokenT< vector<float> >   ak8subeta3Token_;
  edm::EDGetTokenT< vector<float> >   ak8subphi3Token_;
  edm::EDGetTokenT< vector<float> >   ak8subpt3Token_;


  edm::EDGetTokenT< vector<float> > ak8Cjecf0Token_;
  edm::EDGetTokenT< vector<float> > ak8CjecL3absToken_;
  edm::EDGetTokenT< vector<float> > ak8CjecUncertToken_;

  edm::EDGetTokenT< vector<float> > ak8CjersfToken_;
  edm::EDGetTokenT< vector<float> > ak8CjersfdownToken_;
  edm::EDGetTokenT< vector<float> > ak8CjersfupToken_;

  edm::EDGetTokenT< vector<float> > ak8CptsmearedToken_;

  edm::EDGetTokenT< vector<float> >  ak4ptCToken_;
  edm::EDGetTokenT< vector<float> >  ak4etaCToken_;
  edm::EDGetTokenT< vector<float> >  ak4phiCToken_;
  edm::EDGetTokenT< vector<float> >  ak4eneCToken_;
  edm::EDGetTokenT< vector<float> >  ak4CSVv2CToken_;

  edm::EDGetTokenT< vector<float> > ak4CcefToken_;
  edm::EDGetTokenT< vector<float> > ak4CchfToken_;
  edm::EDGetTokenT< vector<float> > ak4CchmToken_;
  edm::EDGetTokenT< vector<float> > ak4CnmToken_;
  edm::EDGetTokenT< vector<float> > ak4CchemfToken_;
  edm::EDGetTokenT< vector<float> > ak4CareaToken_;
  edm::EDGetTokenT< vector<float> > ak4CnemfToken_;
  edm::EDGetTokenT< vector<float> > ak4CnhfToken_;
  edm::EDGetTokenT< vector<float> > ak4CnnpToken_;

  edm::EDGetTokenT< vector<float> > ak4Cjecf0Token_;
  edm::EDGetTokenT< vector<float> > ak4CjecL3absToken_;
  edm::EDGetTokenT< vector<float> > ak4CjecUncertToken_;

  edm::EDGetTokenT< vector<float> > ak4CjersfToken_;
  edm::EDGetTokenT< vector<float> > ak4CjersfdownToken_;
  edm::EDGetTokenT< vector<float> > ak4CjersfupToken_;



  edm::EDGetTokenT< vector<float> >  phoptToken_;
  edm::EDGetTokenT< vector<float> >  phoEToken_;
  edm::EDGetTokenT< vector<float> >  phoetaToken_;
  edm::EDGetTokenT< vector<float> >  phophiToken_;
  edm::EDGetTokenT< vector<float> >  phohoeToken_;
  edm::EDGetTokenT< vector<float> >  phosieieToken_;
  edm::EDGetTokenT< vector<float> >  phohaspixelseedToken_;
  edm::EDGetTokenT< vector<float> > photonIDLooseToken_;
  edm::EDGetTokenT< vector<float> > photonIDMediumToken_;
  edm::EDGetTokenT< vector<float> > photonIDTightToken_;
  //-----------------------------------------------------------

  edm::EDGetTokenT< vector<float>   > ak8spt1PToken_;
  edm::EDGetTokenT< vector<float>   > ak8spt2PToken_;
  edm::EDGetTokenT< vector<float>   > ak8spt3PToken_;

  //----------------------------------------------------------

  //--- muons -------

  edm::EDGetTokenT< vector<float> > muonptToken_;
  edm::EDGetTokenT< vector<float> > muonetaToken_;
  edm::EDGetTokenT< vector<float> > muonPhiToken_;
  edm::EDGetTokenT< vector<float> > muonEToken_;
  edm::EDGetTokenT< vector<float> > muonisGlobalToken_;
  edm::EDGetTokenT< vector<float> > muonIso04Token_;
  edm::EDGetTokenT< vector<float> > muonIsPFToken_;
  edm::EDGetTokenT< vector<float> > muonIsTightToken_;

  edm::EDGetTokenT< vector<float> > metfullptToken_;
  edm::EDGetTokenT< vector<float> > metfullphiToken_;

  edm::EDGetTokenT< vector<float> > metpuppiptToken_;
  edm::EDGetTokenT< vector<float> > metpuppiphiToken_;


  //  edm::EDGetTokenT< vector<vector <int> >  > electronkeysToken_;
  // edm::EDGetTokenT< vector<float> >          electronptToken_;

  edm::EDGetTokenT< vector<int>    > triggerPrescale_;
  edm::EDGetTokenT< vector<float>  > triggerBit_;
  edm::EDGetTokenT< vector<string> > triggerName_;



  TTree *event;
  //event info
  double rho   = -99;
  int nvtx     = 0; 
  float HTak4 = 0;
  int NJ = 0;
  int isdgam = 0;
  


  int bitHLT_Mu50 = 0;
  int bitHLT_Mu27 = 0;
  int bitHLT_TkMu20 = 0;
  int bitHLT_PFHT400 = 0; 
  int bitHLT_PFHT900 = 0; 
  int bitHLT_HT650 = 0; 
  int bitHLT_mu50 = 0; 
  int bitHLT_PFJet450 = 0; 
  int bitHLT_PFJet200 = 0; 





  float mcglumass = -1;
  float mcchimass = -1;

  //Jets
  vector<float> ak8etaC;
  vector<float> ak8phiC;
  vector<float> ak8ptC;
  vector<float> ak8eneC;
  vector<float> ak8sfMassC;
  vector<float> ak8prMassC;
  vector<float> ak8t3t1C;
  vector<float> ak8t3C;
  vector<float> ak8t2C;
  vector<float> ak8t1C;
  vector<float> ak8subjC;
  vector<float> ak8phoindxC;
  vector<float> ak8subindxC;




  vector<float> ak8seta1;
  vector<float> ak8seta2;
  vector<float> ak8seta3;
  vector<float> ak8sphi1;
  vector<float> ak8sphi2;
  vector<float> ak8sphi3;
  vector<float> ak8spt1;
  vector<float> ak8spt2;
  vector<float> ak8spt3;


  vector<float> ak8spt1P;
  vector<float> ak8spt2P;
  vector<float> ak8spt3P;
  
  vector<float>  ak8ptCjecU;
  vector<float>  ak8ptCjecD;
  vector<float>  ak8ptCjerU;
  vector<float>  ak8ptCjerD;

  vector<float>  ak8eneCjecU;
  vector<float>  ak8eneCjecD;
  vector<float>  ak8eneCjerU;
  vector<float>  ak8eneCjerD;


  vector<float>  ak4ptCjecU;
  vector<float>  ak4ptCjecD;
  vector<float>  ak4ptCjerU;
  vector<float>  ak4ptCjerD;

  vector<float>  ak4eneCjecU;
  vector<float>  ak4eneCjecD;
  vector<float>  ak4eneCjerU;
  vector<float>  ak4eneCjerD;






  vector<float> ak4ptC;
  vector<float> ak4etaC;
  vector<float> ak4phiC;
  vector<float> ak4eneC;
  vector<float> ak4CSVv2C;

  vector<float> mcphopt;
  vector<float> mcphophi;
  vector<float> mcphoeta;

  vector<float> mcchipt;
  vector<float> mcchiphi;
  vector<float> mcchieta;



  //Photons
  vector<float> phopt;
  vector<float> phoE;
  vector<float> phoeta;
  vector<float> phophi;
  vector<float> phohoe;
  vector<float> phosieie;
  vector<float> phohaspixelseed;
  vector<float> phoisLoose;
  vector<float> phoisMedium;
  vector<float> phoisTight;


  vector<float> muonpt;
  vector<float> muoneta;
  vector<float> muonphi;
  vector<float> muone;
  vector<float> muonisglobal;
  vector<float> muoniso04;
  vector<float> muonisPF;
  vector<float> muonisTight;

  vector<float> metpuppiphi;
  vector<float> metpuppipt;
  vector<float> metfullphi;
  vector<float> metfullpt;


  //GenInfo -has to be added -

  vector<string> triggerNamesList;





      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
Analyzer::Analyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  //   usesResource("TFileService");



  Service<TFileService> fs;

  event = fs->make<TTree>("event","");

  //consumes

  rhoToken_ = consumes<double>( iConfig.getParameter<InputTag>("rhotag"));

  genpartsToken_ = consumes< reco::GenParticleCollection >( iConfig.getParameter<InputTag>("genparticlestag"));

  nvtxToken_       = consumes< int >( iConfig.getParameter<InputTag>("nvtxtag"));
  ak8etaCToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8etaCtag"));
  ak8phiCToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8phiCtag"));
  ak8eneCToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8eneCtag"));
  ak8ptCToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8ptCtag"));
  ak8t1CToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8t1Ctag"));
  ak8t2CToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8t2Ctag"));
  ak8t3CToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8t3Ctag"));
  ak8sfmassCToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8sfmassCtag"));
  ak8prmassCToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8prmassCtag"));

  ak8CcefToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cceftag"));
  ak8CchfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cchftag"));
  ak8CchmToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cchmtag"));
  ak8CnmToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cnmtag"));
  ak8CchemfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cchemftag"));
  ak8CareaToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Careatag"));
  ak8CnemfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cnemftag"));
  ak8CnhfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cnhftag"));
  ak8CnnpToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cnnptag"));




  ak8phoindxCToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8phoindxCtag"));
  ak8phosubjfCToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8phosubjfCtag"));
  ak8subindxCToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8subindxCtag"));


  ak8subeta1Token_ = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subeta1tag"));
  ak8subphi1Token_ = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subphi1tag"));
  ak8subpt1Token_  = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subpt1tag"));

  ak8subeta2Token_ = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subeta2tag"));
  ak8subphi2Token_ = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subphi2tag"));
  ak8subpt2Token_  = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subpt2tag"));

  ak8subeta3Token_ = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subeta3tag"));
  ak8subphi3Token_ = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subphi3tag"));
  ak8subpt3Token_  = consumes< vector <float> >( iConfig.getParameter<InputTag>("ak8subpt3tag"));

  ak8Cjecf0Token_        = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cjecf0tag"));
  ak8CjecL3absToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8CjecL3abstag"));
  ak8CjecUncertToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8CjecUncerttag"));
  ak8CjersfToken_        = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cjersftag"));
  ak8CjersfdownToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cjersfdowntag"));
  ak8CjersfupToken_      = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cjersfuptag"));


  ak8CptsmearedToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak8Cptsmearedtag"));

  ak4ptCToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4ptCtag"));
  ak4etaCToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4etaCtag"));
  ak4phiCToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4phiCtag"));
  ak4eneCToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4eneCtag"));
  ak4CSVv2CToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4CSVv2Ctag"));





  ak4CcefToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cceftag"));
  ak4CchfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cchftag"));
  ak4CchmToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cchmtag"));
  ak4CnmToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cnmtag"));
  ak4CchemfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cchemftag"));
  ak4CareaToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Careatag"));
  ak4CnemfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cnemftag"));
  ak4CnhfToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cnhftag"));
  ak4CnnpToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cnnptag"));

  ak4Cjecf0Token_        = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cjecf0tag"));
  ak4CjecL3absToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4CjecL3abstag"));
  ak4CjecUncertToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4CjecUncerttag"));
  ak4CjersfToken_        = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cjersftag"));
  ak4CjersfdownToken_    = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cjersfdowntag"));
  ak4CjersfupToken_      = consumes< vector<float> >( iConfig.getParameter<InputTag>("ak4Cjersfuptag"));



  phoptToken_      = consumes< vector<float> >( iConfig.getParameter<InputTag>("phopttag"));
  phoEToken_       = consumes< vector<float> >( iConfig.getParameter<InputTag>("phoEtag"));
  phoetaToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("phoetatag"));
  phophiToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("phophitag"));
  phohoeToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("phohoetag"));
  phosieieToken_     = consumes< vector<float> >( iConfig.getParameter<InputTag>("phosieietag"));
  phohaspixelseedToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("phohaspixelseedtag"));

  photonIDLooseToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("photonIDLoosetag"));

  photonIDMediumToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("photonIDMediumtag"));

  photonIDTightToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("photonIDTighttag"));




  //  electronptToken_   = consumes<vector<float> >(iConfig.getParameter<InputTag>("electronpttag"));
  //electronkeysToken_ = consumes<vector<vector<int> >( iConfig.getParameter<InputTag>("electronkeystag"));

  muonptToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("mupttag"));

  muonetaToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("muetatag"));

  muonPhiToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("muphitag"));

  muonEToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("muetag"));
  muonisGlobalToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("muisGlobaltag"));
  muonIso04Token_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("muIso04tag"));
  muonIsPFToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("muisPFtag"));
  muonIsTightToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("muisTighttag"));
  metfullptToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("metfullpttag"));
  metfullphiToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("metfullphitag"));

  metpuppiptToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("metpuppipttag"));
  metpuppiphiToken_ = consumes< vector<float> >( iConfig.getParameter<InputTag>("metpuppiphitag"));


  triggerPrescale_ = consumes<vector<int>>(iConfig.getParameter<InputTag>("triggerPrescale"));
  triggerBit_ = consumes<vector<float>>(iConfig.getParameter<InputTag>("triggerBit"));
  triggerName_ = consumes<vector<string>,InRun>(iConfig.getParameter<InputTag>("triggerName"));




  //Tree branches
  event->Branch("rho",&rho,"rho/F");
  event->Branch("nvtx",&nvtx,"nvtx/I");
  event->Branch("HTak4",&HTak4,"HTak4/F");
  event->Branch("NJ",&NJ,"NJ/I");
  event->Branch("mcglumass",&mcglumass,"mcglumass/F");
  event->Branch("mcchimass",&mcchimass,"mcchimass/F");

  event->Branch("bitHLT_Mu50",&bitHLT_mu50,"bitHLT_Mu50/I");
  event->Branch("bitHLT_Mu27",&bitHLT_mu50,"bitHLT_Mu27/I");
  event->Branch("bitHLT_TkMu20",&bitHLT_mu50,"bitHLT_TkMu20/I");
  event->Branch("bitHLT_PFHT400",&bitHLT_mu50,"bitHLT_PFHT400/I");
  event->Branch("bitHLT_PFHT900",&bitHLT_mu50,"bitHLT_PFHT900/I");
  event->Branch("bitHLT_HT650",&bitHLT_mu50,"bitHLT_HT650/I");
  event->Branch("bitHLT_PFJet450",&bitHLT_mu50,"bitHLT_PFJet450/I");
  event->Branch("bitHLT_PFJet200",&bitHLT_mu50,"bitHLT_PFJet200/I");



  event->Branch("ak8etaC",&ak8etaC);
  event->Branch("ak8phiC",&ak8phiC);

  event->Branch("ak8ptC",&ak8ptC);
  event->Branch("ak8ptCjecU",&ak8ptCjecU);
  event->Branch("ak8ptCjecD",&ak8ptCjecD);

  event->Branch("ak8ptCjerU",&ak8ptCjerU);
  event->Branch("ak8ptCjerD",&ak8ptCjerD);

  event->Branch("ak8eneC",&ak8eneC);
  event->Branch("ak8eneCjecU",&ak8eneCjecU);
  event->Branch("ak8eneCjecD",&ak8eneCjecD);

  event->Branch("ak8eneCjerU",&ak8eneCjerU);
  event->Branch("ak8eneCjerD",&ak8eneCjerD);

  event->Branch("ak8sfMassC",&ak8sfMassC);
  event->Branch("ak8prMassC",&ak8prMassC);
  event->Branch("ak8t3t1C",&ak8t3t1C);

  event->Branch("ak8t3C",&ak8t3C);
  event->Branch("ak8t2C",&ak8t2C);
  event->Branch("ak8t1C",&ak8t1C);

  event->Branch("ak8subjC",&ak8subjC);
  event->Branch("ak8phoindxC",&ak8phoindxC);
  event->Branch("ak8subindxC",&ak8subindxC);


  // event->Branch("ak8isLooseC",&ak8isLooseC);
  // event->Branch("ak8isTightC",&ak8isTightC);
  
  event->Branch("ak8seta1",&ak8seta1);
  event->Branch("ak8seta2",&ak8seta2);
  event->Branch("ak8seta3",&ak8seta3);
  event->Branch("ak8sphi",&ak8sphi1);
  event->Branch("ak8sphi2",&ak8sphi2);
  event->Branch("ak8sphi3",&ak8sphi3);
  event->Branch("ak8spt1",&ak8spt1);
  event->Branch("ak8spt2",&ak8spt2);
  event->Branch("ak8spt3",&ak8spt3);


  event->Branch("ak4ptC",&ak4ptC);
  event->Branch("ak4etaC",&ak4etaC);
  event->Branch("ak4phiC",&ak4phiC);
  event->Branch("ak4eneC",&ak4eneC);
  event->Branch("ak4CSVv2C",&ak4CSVv2C);


  event->Branch("ak4ptCjecU",&ak4ptCjecU);
  event->Branch("ak4ptCjecD",&ak4ptCjecD);
  event->Branch("ak4ptCjerU",&ak4ptCjerU);
  event->Branch("ak4ptCjerD",&ak4ptCjerD);


  event->Branch("ak8ptCjecU",&ak8ptCjecU);
  event->Branch("ak8ptCjecD",&ak8ptCjecD);
  event->Branch("ak8ptCjerU",&ak8ptCjerU);
  event->Branch("ak8ptCjerD",&ak8ptCjerD);




  //MC photons

  event->Branch("mcphopt",&mcphopt);
  event->Branch("mcphophi",&mcphophi);
  event->Branch("mcphoeta",&mcphoeta);

  event->Branch("mcchipt",&mcchipt);
  event->Branch("mcchiphi",&mcchiphi);
  event->Branch("mcchieta",&mcchieta);



  //Photons
  event->Branch("phopt",&phopt);
  event->Branch("phoE",&phoE);
  event->Branch("phoeta",&phoeta);
  event->Branch("phophi",&phophi);
  event->Branch("phohoe",&phohoe);
  event->Branch("phosieie",&phosieie);
  event->Branch("phohaspixelseed",&phohaspixelseed);
  event->Branch("phoisLoose",&phoisLoose);
  event->Branch("phoisMedium",&phoisMedium);
  event->Branch("phoisTight",&phoisTight);

  event->Branch("muonpt",&muonpt);
  event->Branch("muoneta",&muoneta);
  event->Branch("muonphi",&muonphi);
  event->Branch("muone",&muone);
  event->Branch("muonisglobal",&muonisglobal);
  event->Branch("muoniso04",&muoniso04);
  event->Branch("muonisPF",&muonisPF);
  event->Branch("muonisTight",&muonisTight);

  event->Branch("metfullpt",&metfullpt);
  event->Branch("metfullphi",&metfullphi);
  event->Branch("metpuppipt",&metpuppipt);
  event->Branch("metpuppiphi",&metpuppiphi);




}


Analyzer::~Analyzer()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
Analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   InputTag rhotag;
   InputTag nvtxtag;
   InputTag genparticlestag;
   
   InputTag ak8etaCtag;
   InputTag ak8phiCtag;
   InputTag ak8eneCtag;
   InputTag ak8ptCtag;
   InputTag ak8t1Ctag;
   InputTag ak8t3Ctag;
   InputTag ak8sfmassCtag;
   InputTag ak8prmassCtag;


   InputTag  ak8Cceftag;
   InputTag  ak8Cchftag;
   InputTag  ak8Cchmtag;
   InputTag  ak8Cnmtag;
   InputTag  ak8Cchemftag;
   InputTag  ak8Careatag;
   InputTag  ak8Cnemftag;
   InputTag  ak8Cnhftag;
   InputTag  ak8Cnnptag;


  

   InputTag ak4Cjecf0tag;
   InputTag ak4CjecL3abstag;
   InputTag ak4CjecUncerttag;
   InputTag ak4Cjersftag;
   InputTag ak4Cjersfdowntag;
   InputTag ak4Cjersfuptag;

   InputTag ak8Cjecf0tag;
   InputTag ak8CjecL3abstag;
   InputTag ak8CjecUncerttag;
   InputTag ak8Cjersftag;
   InputTag ak8Cjersfdowntag;
   InputTag ak8Cjersfuptag;

   InputTag ak8Cptsmearedtag;
   InputTag ak4Cptsmearedtag;



   /*
   InputTag ak8etaPtag;
   InputTag ak8phiPtag;
   InputTag ak8enePtag;
   InputTag ak8ptPtag;
   InputTag ak8t1Ptag;
   InputTag ak8t3Ptag;
   InputTag ak8sfmassPtag;
   InputTag ak8prmassPtag;

   InputTag  ak8Pceftag;
   InputTag  ak8Pchftag;
   InputTag  ak8Pchmtag;
   InputTag  ak8Pnmtag;
   InputTag  ak8Pchemftag;
   InputTag  ak8Pjecf0tag;
   InputTag  ak8PjecL3abstag;
   InputTag  ak8PjecUncerttag;
   InputTag  ak8Pareatag;
   InputTag  ak8Pnemftag;
   InputTag  ak8Pnhftag;
   InputTag  ak8Pnnptag;
   */



   InputTag ak8phoindxCtag;
   InputTag ak8phosubjfCtag;
   InputTag ak8subindxCtag;

   //   InputTag ak8phoindxPtag;
   //InputTag ak8phosubjfPtag;

   InputTag ak8subeta1tag;
   InputTag ak8subphi1tag;
   InputTag ak8subpt1tag;

   InputTag ak8subeta2tag;
   InputTag ak8subphi2tag;
   InputTag ak8subpt2tag;

   InputTag ak8subeta3tag;
   InputTag ak8subphi3tag;
   InputTag ak8subpt3tag;

   InputTag ak4ptCtag;
   InputTag ak4etaCtag;
   InputTag ak4phiCtag;
   InputTag ak4eneCtag;
   InputTag ak4CSVv2Ctag;

   InputTag  ak4Cceftag;
   InputTag  ak4Cchftag;
   InputTag  ak4Cchmtag;
   InputTag  ak4Cnmtag;
   InputTag  ak4Cchemftag;

   InputTag  ak4Careatag;
   InputTag  ak4Cnemftag;
   InputTag  ak4Cnhftag;
   InputTag  ak4Cnnptag;

   InputTag phopttag;
   InputTag phoEtag;
   InputTag phoetatag;
   InputTag phophitag;
   InputTag phohoetag;
   InputTag phosieietag;
   InputTag phohaspixelseedtag;
 
   InputTag photonIDLoosetag;
   InputTag photonIDMediumtag;
   InputTag photonIDTighttag;


   InputTag mupttag;
   InputTag muetatag;
   InputTag muphitag;
   InputTag muetag;
   InputTag muisGlobaltag;
   InputTag muisPFtag;
   InputTag muIso04tag;
   InputTag muisTighttag;


   InputTag metfullpttag;
   InputTag metfullphitag;

   InputTag metpuppipttag;
   InputTag metpuppiphitag;

   /*
   InputTag ak8spt1Ptag;
   InputTag ak8spt2Ptag;
   InputTag ak8spt3Ptag;

   InputTag ak8subpt0exPtag;
   InputTag ak8subpt1exPtag;
   InputTag ak8subpt2exPtag;

   InputTag subindxexPtag;
   InputTag phoindxexPtag;
   InputTag subjfexPtag;
   */




   // InputTag electronpttag;
   // InputTag electronkeystag;




   edm::Handle<double> rhohandle;
   edm::Handle<int>    nvtxhandle;

   edm::Handle< reco::GenParticleCollection > genparticleshandle;

   edm::Handle< vector<float> >  ak8etaChandle;
   edm::Handle< vector<float> >  ak8phiChandle;
   edm::Handle< vector<float> > ak8eneChandle;
   edm::Handle< vector<float> > ak8ptChandle;
   edm::Handle< vector<float> > ak8t1Chandle;
   edm::Handle< vector<float> > ak8t2Chandle;
   edm::Handle< vector<float> > ak8t3Chandle;
   edm::Handle< vector<float> > ak8sfmassChandle;
   edm::Handle< vector<float> > ak8prmassChandle;

   edm::Handle< vector<float> >  ak8Ccefhandle;
   edm::Handle< vector<float> >  ak8Cchfhandle;
   edm::Handle< vector<float> >  ak8Cchmhandle;
   edm::Handle< vector<float> >  ak8Cnmhandle;
   edm::Handle< vector<float> >  ak8Cchemfhandle;
   edm::Handle< vector<float> >  ak8Careahandle;
   edm::Handle< vector<float> >  ak8Cnemfhandle;
   edm::Handle< vector<float> >  ak8Cnhfhandle;
   edm::Handle< vector<float> >  ak8Cnnphandle;


   edm::Handle< vector<float> > ak4Cjecf0handle;
    edm::Handle< vector<float> > ak4CjecL3abshandle;
   edm::Handle< vector<float> > ak4CjecUncerthandle;
   edm::Handle< vector<float> > ak4Cjersfhandle;
   edm::Handle< vector<float> > ak4Cjersfdownhandle;
   edm::Handle< vector<float> > ak4Cjersfuphandle;

   edm::Handle< vector<float> > ak8Cjecf0handle;
   edm::Handle< vector<float> > ak8CjecL3abshandle;
   edm::Handle< vector<float> > ak8CjecUncerthandle;
   edm::Handle< vector<float> > ak8Cjersfhandle;
   edm::Handle< vector<float> > ak8Cjersfdownhandle;
   edm::Handle< vector<float> > ak8Cjersfuphandle;


   edm::Handle< vector<float> >  ak8phoindxChandle;
   edm::Handle< vector<float> >  ak8phosubjfChandle;
   edm::Handle< vector<float> >  ak8subindxChandle;

   edm::Handle< vector<float> >  ak8phoindxPhandle;
   edm::Handle< vector<float> >  ak8phosubjfPhandle;


   edm::Handle< vector<float> > ak8Cptsmearedhandle;
   edm::Handle< vector<float> > ak8subeta1handle;
   edm::Handle< vector<float> > ak8subphi1handle;
   edm::Handle< vector<float> > ak8subpt1handle;

   edm::Handle< vector<float> > ak8subeta2handle;
   edm::Handle< vector<float> > ak8subphi2handle;
   edm::Handle< vector<float> > ak8subpt2handle;

   edm::Handle< vector<float> > ak8subeta3handle;
   edm::Handle< vector<float> > ak8subphi3handle;
   edm::Handle< vector<float> > ak8subpt3handle;




   edm::Handle< vector<float> > ak4ptChandle;
   edm::Handle< vector<float> > ak4etaChandle;
   edm::Handle< vector<float> > ak4phiChandle;
   edm::Handle< vector<float> > ak4eneChandle;
   edm::Handle< vector<float> > ak4CSVv2Chandle;


   //ak4 jet ID variables
   edm::Handle< vector<float> >  ak4Ccefhandle;
   edm::Handle< vector<float> >  ak4Cchfhandle;
   edm::Handle< vector<float> >  ak4Cchmhandle;
   edm::Handle< vector<float> >  ak4Cnmhandle;
   edm::Handle< vector<float> >  ak4Cchemfhandle;
   edm::Handle< vector<float> >  ak4Careahandle;
   edm::Handle< vector<float> >  ak4Cnemfhandle;
   edm::Handle< vector<float> >  ak4Cnhfhandle;
   edm::Handle< vector<float> >  ak4Cnnphandle;

   edm::Handle< vector<float> >  phopthandle;
   edm::Handle< vector<float> >  phoEhandle;
   edm::Handle< vector<float> >  phoetahandle;
   edm::Handle< vector<float> >  phophihandle;
   edm::Handle< vector<float> >  phohoehandle;
   edm::Handle< vector<float> >  phosieiehandle;
   edm::Handle< vector<float> >  phohaspixelseedhandle;
   edm::Handle< vector<float> >   photonIDLoosehandle;
   edm::Handle< vector<float> >   photonIDMediumhandle;
   edm::Handle< vector<float> >   photonIDTighthandle;


   edm::Handle< vector<float> > mupthandle;
   edm::Handle< vector<float> > muetahandle;
   edm::Handle< vector<float> > muphihandle;
   edm::Handle< vector<float> > muehandle;
   edm::Handle< vector<float> > muisGlobalhandle;
   edm::Handle< vector<float> > muisPFhandle;
   edm::Handle< vector<float> > muIso04handle;
   edm::Handle< vector<float> > muisTighthandle;

   edm::Handle< vector<float> > metfullpthandle;
   edm::Handle< vector<float> > metfullphihandle;

   edm::Handle< vector<float> > metpuppipthandle;
   edm::Handle< vector<float> > metpuppiphihandle;


   iEvent.getByToken(rhoToken_,rhohandle);
   iEvent.getByToken(nvtxToken_,nvtxhandle);

   iEvent.getByToken(genpartsToken_,genparticleshandle);

   
   iEvent.getByToken(ak8etaCToken_,ak8etaChandle);
   iEvent.getByToken(ak8phiCToken_,ak8phiChandle);
   iEvent.getByToken(ak8eneCToken_,ak8eneChandle);
   iEvent.getByToken(ak8ptCToken_,ak8ptChandle);
   iEvent.getByToken(ak8t1CToken_,ak8t1Chandle);
   iEvent.getByToken(ak8t2CToken_,ak8t2Chandle);
   iEvent.getByToken(ak8t3CToken_,ak8t3Chandle);
   iEvent.getByToken(ak8sfmassCToken_,ak8sfmassChandle);
   iEvent.getByToken(ak8prmassCToken_,ak8prmassChandle);

   iEvent.getByToken(ak8CcefToken_,ak8Ccefhandle);
   iEvent.getByToken(ak8CchfToken_,ak8Cchfhandle);
   iEvent.getByToken(ak8CchmToken_, ak8Cchmhandle);
   iEvent.getByToken(ak8CnmToken_, ak8Cnmhandle);
   iEvent.getByToken(ak8CchemfToken_,ak8Cchemfhandle);

   iEvent.getByToken(ak8CareaToken_,ak8Careahandle);
   iEvent.getByToken(ak8CnemfToken_,ak8Cnemfhandle);
   iEvent.getByToken(ak8CnhfToken_,ak8Cnhfhandle);
   iEvent.getByToken(ak8CnnpToken_,ak8Cnnphandle);

   iEvent.getByToken(ak8CptsmearedToken_,ak8Cptsmearedhandle);


   iEvent.getByToken( ak4Cjecf0Token_ , ak4Cjecf0handle);
   iEvent.getByToken( ak4CjecL3absToken_ , ak4CjecL3abshandle);
   iEvent.getByToken( ak4CjecUncertToken_ , ak4CjecUncerthandle);
   iEvent.getByToken( ak4CjersfToken_ , ak4Cjersfhandle);
   iEvent.getByToken( ak4CjersfdownToken_ , ak4Cjersfdownhandle);
   iEvent.getByToken( ak4CjersfupToken_ , ak4Cjersfuphandle);

   iEvent.getByToken( ak8Cjecf0Token_ , ak8Cjecf0handle);
   iEvent.getByToken( ak8CjecL3absToken_ , ak8CjecL3abshandle);
   iEvent.getByToken( ak8CjecUncertToken_ , ak8CjecUncerthandle);
   iEvent.getByToken( ak8CjersfToken_ , ak8Cjersfhandle);
   iEvent.getByToken( ak8CjersfdownToken_ , ak8Cjersfdownhandle);
   iEvent.getByToken( ak8CjersfupToken_ , ak8Cjersfuphandle);



   iEvent.getByToken(ak8phoindxCToken_,ak8phoindxChandle);
   iEvent.getByToken(ak8phosubjfCToken_,ak8phosubjfChandle);
   iEvent.getByToken(ak8subindxCToken_,ak8subindxChandle);

   iEvent.getByToken(ak8subeta1Token_,ak8subeta1handle);
   iEvent.getByToken(ak8subphi1Token_,ak8subphi1handle);
   iEvent.getByToken(ak8subpt1Token_,ak8subpt1handle);

   iEvent.getByToken(ak8subeta2Token_,ak8subeta2handle);
   iEvent.getByToken(ak8subphi2Token_,ak8subphi2handle);
   iEvent.getByToken(ak8subpt2Token_,ak8subpt2handle);

   iEvent.getByToken(ak8subeta3Token_,ak8subeta3handle);
   iEvent.getByToken(ak8subphi3Token_,ak8subphi3handle);
   iEvent.getByToken(ak8subpt3Token_,ak8subpt3handle);


   iEvent.getByToken(ak4ptCToken_,ak4ptChandle);
   iEvent.getByToken(ak4etaCToken_,ak4etaChandle);
   iEvent.getByToken(ak4phiCToken_,ak4phiChandle);
   iEvent.getByToken(ak4eneCToken_,ak4eneChandle);
   iEvent.getByToken(ak4CSVv2CToken_,ak4CSVv2Chandle);

   iEvent.getByToken(ak4CcefToken_,ak4Ccefhandle);
   iEvent.getByToken(ak4CchfToken_,ak4Cchfhandle);
   iEvent.getByToken(ak4CchmToken_, ak4Cchmhandle);
   iEvent.getByToken(ak4CnmToken_, ak4Cnmhandle);
   iEvent.getByToken(ak4CchemfToken_,ak4Cchemfhandle);
   iEvent.getByToken(ak4Cjecf0Token_,ak4Cjecf0handle);
   iEvent.getByToken(ak4CjecL3absToken_,ak4CjecL3abshandle);
   iEvent.getByToken(ak4CjecUncertToken_,ak4CjecUncerthandle);
   iEvent.getByToken(ak4CareaToken_,ak4Careahandle);
   iEvent.getByToken(ak4CnemfToken_,ak4Cnemfhandle);
   iEvent.getByToken(ak4CnhfToken_,ak4Cnhfhandle);
   iEvent.getByToken(ak4CnnpToken_,ak4Cnnphandle);

   iEvent.getByToken(phoptToken_,phopthandle);
   iEvent.getByToken(phoEToken_,phoEhandle);
   iEvent.getByToken(phoetaToken_,phoetahandle);
   iEvent.getByToken(phophiToken_,phophihandle);
   iEvent.getByToken(phohoeToken_,phohoehandle);
   iEvent.getByToken(phosieieToken_,phosieiehandle);
   iEvent.getByToken(phohaspixelseedToken_,phohaspixelseedhandle);
   iEvent.getByToken(photonIDLooseToken_,photonIDLoosehandle);
   iEvent.getByToken(photonIDMediumToken_,photonIDMediumhandle);
   iEvent.getByToken(photonIDTightToken_,photonIDTighthandle);



   iEvent.getByToken(muonptToken_,mupthandle);
   iEvent.getByToken(muonPhiToken_,muphihandle);
   iEvent.getByToken(muonetaToken_,muetahandle);
   iEvent.getByToken(muonEToken_,muehandle);
   iEvent.getByToken(muonisGlobalToken_,muisGlobalhandle);
   iEvent.getByToken(muonIso04Token_,muIso04handle);
   iEvent.getByToken(muonIsPFToken_,muisPFhandle);
   iEvent.getByToken(muonIsTightToken_,muisTighthandle);

   iEvent.getByToken(metfullptToken_,metfullpthandle);
   iEvent.getByToken(metfullphiToken_,metfullphihandle);
   iEvent.getByToken(metpuppiptToken_,metpuppipthandle);
   iEvent.getByToken(metpuppiphiToken_,metpuppiphihandle);

   Handle<vector<int> > triggerPrescale;
   iEvent.getByToken(triggerPrescale_, triggerPrescale);

   Handle<vector<float> > triggerBit;
   iEvent.getByToken(triggerBit_, triggerBit);




   //clean vectors


   ak8etaC.clear();
   ak8phiC.clear();
   ak8ptC.clear();
   ak8eneC.clear();
   ak8sfMassC.clear();
   ak8prMassC.clear();
   ak8t3t1C.clear();
   ak8t3C.clear();
   ak8t2C.clear();
   ak8t1C.clear();
   
   ak8subjC.clear();
   ak8phoindxC.clear();
   ak8subindxC.clear();

   ak8seta1.clear();
   ak8seta2.clear();
   ak8seta3.clear();
   ak8sphi1.clear();
   ak8sphi2.clear();
   ak8sphi3.clear();
   ak8spt1.clear();
   ak8spt2.clear();
   ak8spt3.clear();

  
   ak8ptCjecU.clear();
   ak8ptCjecD.clear();
   ak8ptCjerU.clear();
   ak8ptCjerD.clear();
   
   ak8eneCjecU.clear();
   ak8eneCjecD.clear();
   ak8eneCjerU.clear();
   ak8eneCjerD.clear();


   ak4ptCjecU.clear();
   ak4ptCjecD.clear();
   ak4ptCjerU.clear();
   ak4ptCjerD.clear();
   
   ak4eneCjecU.clear();
   ak4eneCjecD.clear();
   ak4eneCjerU.clear();
   ak4eneCjerD.clear();







   ak4ptC.clear();
   ak4etaC.clear();
   ak4phiC.clear();
   ak4eneC.clear();
   ak4CSVv2C.clear();



   ak8spt1P.clear();
   ak8spt2P.clear();
   ak8spt3P.clear();




   //MCphotons
   mcphopt.clear();
   mcphophi.clear();
   mcphoeta.clear();

   mcchipt.clear();
   mcchiphi.clear();
   mcchieta.clear();

   //Photons
   phopt.clear();
   phoE.clear();
   phoeta.clear();
   phophi.clear();
   phohoe.clear();
   phosieie.clear();
   phohaspixelseed.clear();
   phoisLoose.clear();
   phoisMedium.clear();
   phoisTight.clear();

   //Muons
   muonpt.clear();
   muoneta.clear();
   muonphi.clear();
   muone.clear();
   muonisglobal.clear();
   muoniso04.clear();
   muonisPF.clear();
   muonisTight.clear();


   metfullpt.clear();
   metfullphi.clear();
   metpuppipt.clear();
   metpuppiphi.clear();



   //Initialize event varibles
   NJ    = 0;
   HTak4 = 0;
   isdgam = 0;
    


   
   bitHLT_Mu50    = PassTrig("HLT_Mu50", triggerNamesList,triggerBit,triggerPrescale); 
   bitHLT_Mu27    = PassTrig("HLT_Mu27", triggerNamesList,triggerBit,triggerPrescale); 
   bitHLT_TkMu20  = PassTrig("HLT_TkMu20", triggerNamesList,triggerBit,triggerPrescale); 
   bitHLT_PFHT400 = PassTrig("HLT_PFHT400", triggerNamesList,triggerBit,triggerPrescale); 
   bitHLT_PFHT900 = PassTrig("HLT_PFHT900", triggerNamesList,triggerBit,triggerPrescale); 
   bitHLT_HT650    = PassTrig("HLT_HT650", triggerNamesList,triggerBit,triggerPrescale); 
   bitHLT_PFJet450    = PassTrig("HLT_PFJet450", triggerNamesList,triggerBit,triggerPrescale); 
   bitHLT_PFJet200    = PassTrig("HLT_PFJet200", triggerNamesList,triggerBit,triggerPrescale); 

   /*
   cout<<"bitHLT_Mu50 "<<bitHLT_Mu50<<endl;
   cout<<"bitHLT_Mu27 "<<bitHLT_Mu27<<endl;
   cout<<"bitHLT_TkMu20 "<<bitHLT_TkMu20<<endl;
   cout<<"bitHLT_PFHT400 "<<bitHLT_PFHT400<<endl;
   cout<<"bitHLT_PFHT900 "<<bitHLT_PFHT900<<endl;
   cout<<"bitHLT_HT650 "<<bitHLT_HT650<<endl;
   cout<<"bitHLT_PFJet450 "<<bitHLT_PFJet450<<endl;
   cout<<"bitHLT_PFJet200 "<<bitHLT_PFJet200<<endl;
   */

   

   rho = (*rhohandle.product());
   if( fabs(rho) >   1000 ) rho = -1;
   nvtx = (*nvtxhandle.product());
   cout<<nvtx<<endl;

   // loop over gen particles!!!
   int isneu = 0;
   int ischg = 0;
   int iphos = 0;
   // for(int iprr = 0; iprr < 10; iprr++) cout<<"   -------    new event!!!!"<<endl;

   for(size_t i = 0; i < genparticleshandle->size(); ++i){
     const reco::GenParticle& p = (*genparticleshandle)[i];

     int momId = p.numberOfMothers() ? p.mother()->pdgId() : 0;
     // std::cout<<i<<" id="<<p.pdgId()<<" ("<<p.status()<<") mom="<<momId<<", daughters=";
     //for(size_t j = 0, n=p.numberOfDaughters(); j<n; ++j) std::cout<<p.daughter(j)->pdgId()<<(j+1<n?", ":"\n");


     //cout<<" mass "<<p.mass()<<" id "<<p.pdgId()<<" "<<momId<<endl;


     if(p.pdgId() == 3000001 && (p.mass() > 101 || p.mass() < 99) ){
       cout<<" --------------------------"<<endl;
       cout<<"multiple masses singlino :"<<p.mass() <<" mom "<<momId<<" part  "<<p.pdgId()<<endl;

     }
     if(p.pdgId() == 3000002 && (p.mass() > 91 || p.mass() < 89) ) cout<<"multiple masses signlet: "<<p.mass()<<" mom "<<momId<<" part  "<<p.pdgId()<<endl;


     if(  p.pdgId() == 1000022 && momId == 1000021 ) mcchimass = p.mass();
     if(  p.pdgId() == 1000021 )                     mcglumass = p.mass();

     if( p.pdgId() == 1000022 && momId == 1000021  )       isneu++;
     if( fabs(p.pdgId()) == 1000024 && momId == 1000021  ) ischg++;


     if(p.pdgId() == 1000022 &&  momId == 1000021 ){
       float ppt = p.pt();
       float peta = p.eta();
       float pphi = p.phi();

       mcchipt.push_back(ppt);
       mcchiphi.push_back(pphi);
       mcchieta.push_back(peta);
     }

     if( p.pdgId() == 22 &&  momId == 1000022){
       iphos++;
       float ppt = p.pt();
       float peta = p.eta();
       float pphi = p.phi();
       
       mcphopt.push_back(ppt);
       mcphophi.push_back(pphi);
       mcphoeta.push_back(peta);
     }


   }


   if(iphos == 2) isdgam = 1;

   //if( igluis == 0 ) cout<<"!!!!!!!!!!!!!!!!!"<<endl;
   //  if(isneu > 0 && ischg ==  0 ) isdgam =1;


   //Construct the original ak8 jet pf the photon jets

   /*
   vector<float> phoJeta;
   vector<float> phoJphi;
   vector<float> phoJpt;

   phoJeta.push_back(0);
   phoJphi.push_back(0);
   phoJpt.push_back(0);
   phoJeta.clear();
   phoJphi.clear();
   phoJpt.clear();

   for(uint iphoj = 0; iphoj < (*ak8phojetindxhandle).size(); iphoj++){






     TVector3 sub1,sub2,sub3,phosub;
     sub1.SetPtEtaPhi(pt1,eta1,phi1);
     sub2.SetPtEtaPhi(pt2,eta2,phi2);
     sub3.SetPtEtaPhi(pt3,eta3,phi3);

     phosub = sub1 + sub2;
     phosub = phosub +sub3;

     float ptjp  = phosub.Perp();


     float etajp = 0;
     float phijp = 0;
     if(ptjp != 0){
       etajp = phosub.Eta();
       phijp = phosub.Phi();
     }


     (phoJpt).push_back(ptjp);
     (phoJeta).push_back(etajp);
     (phoJphi).push_back(phijp);


   }
   */


  


   //Loop over AK8jets
   for(uint iak8 = 0; iak8 < (*ak8ptChandle).size(); iak8++){
     float pt  = (*ak8ptChandle)[iak8];
     float eta = (*ak8etaChandle)[iak8];

     if( fabs(eta) > 2.5 || pt < 200 ) continue;
     
     

     float nhf  = (*ak8Cnhfhandle)[iak8];
     float nemf = (*ak8Cnemfhandle)[iak8];
     float chf = (*ak8Cchfhandle)[iak8];
     float chm = (*ak8Cchmhandle)[iak8];
     float nm  = (*ak8Cnmhandle)[iak8];
     float cef = (*ak8Ccefhandle)[iak8];
     int   nnp = (*ak8Cnhfhandle)[iak8];

     bool passjid = PassJetID(eta,nhf,nemf,nm,chf,chm,cef,nnp);
     if(passjid != 1) continue;
     NJ++;


     float phi = (*ak8phiChandle)[iak8];
     float ene = (*ak8eneChandle)[iak8];
     
     float jec0  = (*ak8Cjecf0handle)[iak8];
     float jersf = (*ak8Cjersfhandle)[iak8];
     float jersfd = (*ak8Cjersfdownhandle)[iak8];
     float jersfu = (*ak8Cjersfuphandle)[iak8];
     float jecUn  = (*ak8CjecUncerthandle)[iak8];

     TLorentzVector jp4, newjp4plus,newjp4down,jp4erup,jp4erd,jp4un; 
     jp4.SetPtEtaPhiE(pt,eta,phi,ene);
     
     float factorjecup = (jec0 + jecUn )/(jec0);
     float factorjecd  = (jec0 - jecUn )/(jec0);

     newjp4plus = jp4*factorjecup;
     newjp4down = jp4*factorjecd;
          
     float ptsmeared = (*ak8Cptsmearedhandle)[iak8]; 
     float ptjerup   = pt*(  (ptsmeared/pt - 1)*((jersfu -1)/(jersf - 1)) +1 );
     float ptjerdown = pt*(  (ptsmeared/pt - 1)*((jersfd -1)/(jersf - 1)) +1 );;
    




     float subjf   = (*ak8phosubjfChandle)[iak8];
     float   phoindx = (*ak8phoindxChandle)[iak8];

     //jet selection
     float sfmass = (*ak8sfmassChandle)[iak8];
     float prmass = (*ak8prmassChandle)[iak8];

     float t1     = (*ak8t1Chandle)[iak8];
     float t2     = (*ak8t2Chandle)[iak8];
     float t3     = (*ak8t3Chandle)[iak8];

     // Check for photonJets
 
     //Filling subjets
     float eta1 = (*ak8subeta1handle)[iak8];
     float eta2 = (*ak8subeta2handle)[iak8];
     float eta3 = (*ak8subeta3handle)[iak8];

     float phi1 = (*ak8subphi1handle)[iak8];
     float phi2 = (*ak8subphi2handle)[iak8];
     float phi3 = (*ak8subphi3handle)[iak8];

     float pt1 = (*ak8subpt1handle)[iak8];
     float pt2 = (*ak8subpt2handle)[iak8];
     float pt3 = (*ak8subpt3handle)[iak8];



     (ak8seta1).push_back(eta1);
     (ak8seta2).push_back(eta2);
     (ak8seta3).push_back(eta3);
     (ak8sphi1).push_back(phi1);
     (ak8sphi2).push_back(phi2);
     (ak8sphi3).push_back(phi3);
     (ak8spt1).push_back(pt1);
     (ak8spt2).push_back(pt2);
     (ak8spt3).push_back(pt3);

     float subindx = (*ak8subindxChandle)[iak8];



     ak8etaC.push_back(eta);
     ak8phiC.push_back(phi);
     ak8ptC.push_back(pt);
     ak8eneC.push_back(ene);
     ak8sfMassC.push_back(sfmass);
     ak8prMassC.push_back(prmass);
     ak8t3t1C.push_back(t3/t1);

     ak8t3t1C.push_back(t3/t1);
     ak8t3C.push_back(t3);
     ak8t2C.push_back(t2);
     ak8t1C.push_back(t1);

     ak8subjC.push_back(subjf);
     ak8phoindxC.push_back(phoindx);
     ak8subindxC.push_back(subindx);

     ak8ptCjecU.push_back(newjp4plus.Perp());
     ak8ptCjecD.push_back(newjp4down.Perp());
     
     ak8ptCjerU.push_back(ptjerup);
     ak8ptCjerD.push_back(ptjerdown);


   }



   //Loop over AK4 jets
   for(uint iak4 = 0; iak4 < (*ak4ptChandle).size(); iak4++){
     float pt  = (*ak4ptChandle)[iak4];
     float eta = (*ak4etaChandle)[iak4];

     if(pt < 20  ) continue;
     if(fabs(eta) > 2.5) continue;

     //jet id selections
     float nhf  = (*ak4Cnhfhandle)[iak4];
     float nemf = (*ak4Cnemfhandle)[iak4];
     float chf = (*ak4Cchfhandle)[iak4];
     float chm = (*ak4Cchmhandle)[iak4];
     float nm  = (*ak4Cnmhandle)[iak4];
     float cef = (*ak4Ccefhandle)[iak4];
     int   nnp = (*ak4Cnhfhandle)[iak4];

     bool passjid = PassJetID(eta,nhf,nemf,nm,chf,chm,cef,nnp);
     if(passjid != 1) continue;
     float ene = (*ak4eneChandle)[iak4];
     float csvv2 = (*ak4CSVv2Chandle)[iak4];
     float phi = (*ak4phiChandle)[iak4];
     HTak4 += pt;


     float jec0  = (*ak4Cjecf0handle)[iak4];
     float jersf = (*ak4Cjersfhandle)[iak4];
     float jersfd = (*ak4Cjersfdownhandle)[iak4];
     float jersfu = (*ak4Cjersfuphandle)[iak4];
     float jecUn  = (*ak4CjecUncerthandle)[iak4];

     TLorentzVector jp4, newjp4plus,newjp4down,jp4erup,jp4erd,jp4un; 
     jp4.SetPtEtaPhiE(pt,eta,phi,ene);
     
     float factorjecup = (jec0 + jecUn )/(jec0*jersf);
     float factorjecd  = (jec0 - jecUn )/(jec0*jersf);
     float und = 1./(jec0*jersf);

     newjp4plus = jp4*factorjecup;
     newjp4down = jp4*factorjecd;
          
     jp4un      = jp4*und; 
     jp4erup    = jp4un*jersfu; 
     jp4erd     = jp4un*jersfd; 


     ak4ptCjecU.push_back(newjp4plus.Perp());
     ak4ptCjecD.push_back(newjp4down.Perp());
     ak4ptCjerU.push_back(jp4erup.Perp());
     ak4ptCjerD.push_back(jp4erd.Perp());
     ak4ptC.push_back(pt);
     ak4etaC.push_back(eta);
     ak4phiC.push_back(phi);
     ak4eneC.push_back(ene);
     ak4CSVv2C.push_back(csvv2);

   }



   //Loop over photons
   for(uint iph = 0; iph < (*phopthandle).size();iph ++){
     float pt  = (*phopthandle)[iph];
     float eta = (*phoetahandle)[iph];

     if(pt < 15)         continue;
     if(fabs(eta) > 2.5) continue;

     float sieie = (*phosieiehandle)[iph];
     float phi   = (*phophihandle)[iph];
     float hoe   = (*phohoehandle)[iph];
     float ene   = (*phoEhandle)[iph];
     int   haspixelseed = (*phohaspixelseedhandle)[iph];
     float isLoose  = (*photonIDLoosehandle)[iph];
     float isMedium = (*photonIDMediumhandle)[iph];
     float isTight  = (*photonIDTighthandle)[iph];

     phopt.push_back(pt);
     phoE.push_back(ene);
     phoeta.push_back(eta);
     phophi.push_back(phi);
     phohoe.push_back(hoe);
     phosieie.push_back(sieie);
     phohaspixelseed.push_back(haspixelseed);

     phoisLoose.push_back(isLoose);
     phoisMedium.push_back(isMedium);
     phoisTight.push_back(isTight);



   }



   for(uint imu = 0; imu < (*mupthandle).size();imu ++){
     float pt  = (*mupthandle)[imu];
     float eta = (*muetahandle)[imu];
     float phi = (*muphihandle)[imu];
     float een = (*muehandle)[imu];

     float isglobal =  (*muisGlobalhandle)[imu];
     float ispf     = (*muisPFhandle)[imu];
     float iso04    = (*muIso04handle)[imu];
     float istight  = (*muisTighthandle)[imu];


     muonpt.push_back(pt);
     muoneta.push_back(eta);
     muonphi.push_back(phi);
     muone.push_back(een);
     muonisglobal.push_back(isglobal);
     muoniso04.push_back(iso04);
     muonisPF.push_back(ispf);
     muonisTight.push_back(istight);
  }



   for(uint imet= 0; imet < (*metfullpthandle).size(); imet++){
     float phi = (*metfullphihandle)[imet];
     float pt  = (*metfullpthandle)[imet];
     metfullpt.push_back(pt);
     metfullphi.push_back(phi);
   }

   for(uint imet= 0; imet < (*metpuppipthandle).size(); imet++){
     float phi = (*metpuppiphihandle)[imet];
     float pt  = (*metpuppipthandle)[imet];
     metpuppipt.push_back(pt);
     metpuppiphi.push_back(phi);
   }





   if(isdgam ){
     event->Fill();
   }

   //checking triggers
   
   
   /*  

   float triggerFired = 0;
   for (size_t t = 0; t < triggerNamesList.size(); t++) {
     //LogWarning("triggerbit") << triggerNames[t] << " " <<  (*triggerBits)[t] << " " << (*triggerPrescale)[t];
     if ( TString( triggerNamesList[t] ).Contains( HLTtrigger ) ) {
       if ( ((*triggerPrescale)[t] == 1) || baselineTrigger ) triggerFired = (*triggerBits)[t];
     }
   }
   */






}

void Analyzer::beginRun(const Run& iRun, const EventSetup& iSetup){


  //  cout<<"triggerrrrsss "<<endl;
  Handle<vector<string>> triggerName;
  iRun.getByToken(triggerName_,triggerName);
  LogWarning("TriggerNames") << "List of triggers found:";
  for (size_t q = 0; q < triggerName->size(); q++) {
    triggerNamesList.push_back( (*triggerName)[q] );
    //cout << (*triggerName)[q] << endl;
  }
  if ( triggerNamesList.size() == 0 ) LogError("TriggerNames") << "No triggers found.";
}



void Analyzer::endRun(const Run& iRun, const EventSetup& iSetup){
  triggerNamesList.clear();
}







// ------------ method called once each job just before starting event loop  ------------
void
Analyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
Analyzer::endJob()
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
Analyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

bool Analyzer::JetIsLoose(float t3t1 , int noseed, int haspho , float eta, float hoe, float sie){
  if(haspho == -99)return 0;
  if(t3t1 < 0.4 && haspho == 1 && noseed == 1 && hoe < 0.05 && ( ( fabs(eta) > 1.4789 && sie < 0.0274 )||( fabs(eta) < 1.4789 && sie < 0.0102 ) ) ){
   return 1;
  }else{
    return 0;
  }
}

bool Analyzer::JetIsTight(float t3t1 ,int noseed, int haspho ,float eta, float hoe, float sie, float subf){
  if(haspho == -99 ) return 0;
  if(t3t1 < 0.4 && haspho == 1  && subf > 0.9 && noseed == 1  && hoe < 0.05 && ( ( fabs(eta) > 1.4789 && sie < 0.0274 )||( fabs(eta) < 1.4789 && sie < 0.0102 ) ) ){
    return 1;
  }else{
    return 0;
  }
}


bool Analyzer::PassJetID( float eta, float nhf, float nemf,int nm, float chf, int chm, float cef, int nnp){

  //working points implemented are loose from this twiki:
  //https://twiki.cern.ch/twiki/bin/view/CMS/JetID13TeVRun2016

  int ncon = chm+nm;
  if( fabs(eta) < 2.7 ){
    if( nhf < 0.99 && nemf < 0.99 && ncon > 1){

      if(fabs(eta)  < 2.4){
	if( chf > 0 && chm > 0 && cef < 0.99 ){
	  return 1;

	}else{
	  return 0;
	}
      }else{
	return 1;
      }
      return 1;
    }else{
	return 0;
    }
  }
  if(fabs(eta) > 2.7 && fabs(eta) < 3.0){

    if( nemf > 0.01 && nhf < 0.98 && nnp > 2 ){
      return 1;
    }else{
      return 0;
    }
  }

  if(fabs(eta) > 3.0 ) {
    if(nhf < 0.90 && nnp > 10 ){
      return 1;
    }else {
      return 0;
    }
  }

  return 0;


}


int Analyzer::PassTrig(string triname,vector<string> triggerNames , Handle < vector <float> > triggerBits, Handle < vector <int> > triggerPrescale){
  
  int triggerFired = 0;
  int triggerfound = 0; 
  for (size_t t = 0; t < triggerNames.size(); t++) {
    if ( TString( triggerNames[t] ).Contains( triname ) ) {
      triggerfound = 1; 
      if ( ((*triggerPrescale)[t] == 1) ) triggerFired = (*triggerBits)[t];
    }
  }

  int res = -1; 
  if(triggerFired == 1  && triggerfound  == 1 ) res =  1; 
  if(triggerFired == 0  && triggerfound  == 1 ) res =  0; 
  if(triggerFired == 0  && triggerfound  == 0 ) res =  2; 
  
  return res; 

}














//define this as a plug-in
DEFINE_FWK_MODULE(Analyzer);
