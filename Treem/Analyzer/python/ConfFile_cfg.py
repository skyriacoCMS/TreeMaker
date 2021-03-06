import FWCore.ParameterSet.Config as cms
import os
import sys


INPUT  = sys.argv[2]
OUTPUT = sys.argv[3]

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(INPUT)
    # replace 'myfile.root' with the source file you want to use
    #fileNames = cms.untracked.vstring('file:./b2gedmntuple.root')
)

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string(OUTPUT)
                                   )


process.demo = cms.EDAnalyzer('Analyzer',
                              #rhotag = cms.InputTag("fixedGridRhoFastjetAll::RECO"),
                              rhotag = cms.InputTag("fixedGridRhoFastjetAll::HLT"),
                              nvtxtag = cms.InputTag("vertexInfo:npv:b2gEDMNtuples"),   


                              genparticlestag = cms.InputTag("filteredPrunedGenParticles::b2gEDMNtuples"),

                              
                              ak8etaCtag = cms.InputTag("jetsAK8CHS:jetAK8CHSEta:b2gEDMNtuples"),
                              ak8phiCtag = cms.InputTag("jetsAK8CHS:jetAK8CHSPhi:b2gEDMNtuples"),
                              ak8eneCtag = cms.InputTag("jetsAK8CHS:jetAK8CHSE:b2gEDMNtuples"),
                              ak8ptCtag = cms.InputTag("jetsAK8CHS:jetAK8CHSPt:b2gEDMNtuples"),
                              ak8t1Ctag = cms.InputTag("jetsAK8CHS:jetAK8CHStau1CHS:b2gEDMNtuples"),
                              ak8t2Ctag = cms.InputTag("jetsAK8CHS:jetAK8CHStau2CHS:b2gEDMNtuples"),
                              ak8t3Ctag = cms.InputTag("jetsAK8CHS:jetAK8CHStau3CHS:b2gEDMNtuples"),
                              ak8sfmassCtag = cms.InputTag("jetsAK8CHS:jetAK8CHSsoftDropMassCHS:b2gEDMNtuples"),
                              ak8prmassCtag = cms.InputTag("jetsAK8CHS:jetAK8CHSprunedMassCHS:b2gEDMNtuples"),


                              ak8Cceftag = cms.InputTag("jetsAK8CHS:jetAK8CHSchargedEmEnergyFrac:b2gEDMNtuples"),
                              ak8Cchftag = cms.InputTag("jetsAK8CHS:jetAK8CHSchargedHadronEnergyFrac:b2gEDMNtuples"),
                              ak8Cchmtag = cms.InputTag("jetsAK8CHS:jetAK8CHSchargedMultiplicity:b2gEDMNtuples"),
                              ak8Cnmtag  = cms.InputTag("jetsAK8CHS:jetAK8CHSneutralMultiplicity:b2gEDMNtuples"),
                              ak8Cchemftag = cms.InputTag("jetsAK8CHS:jetAK8CHSchargedMultiplicity:b2gEDMNtuples"),
                              ak8Careatag = cms.InputTag("jetsAK8CHS:jetAK8CHSjetArea:b2gEDMNtuples"),
                              ak8Cnemftag = cms.InputTag("jetsAK8CHS:jetAK8CHSneutralEmEnergyFrac:b2gEDMNtuples"),
                              ak8Cnhftag = cms.InputTag("jetsAK8CHS:jetAK8CHSneutralHadronEnergyFrac:b2gEDMNtuples"),
                              ak8Cnnptag = cms.InputTag("jetsAK8CHS:jetAK8CHSneutralMultiplicity:b2gEDMNtuples"),
                              ak8phoindxCtag     =  cms.InputTag("jetsAK8CHS:jetAK8CHSPhotonIndex:b2gEDMNtuples"), 
                              ak8phosubjfCtag    =  cms.InputTag("jetsAK8CHS:jetAK8CHSPhotonSubjetFrac:b2gEDMNtuples"),
                              ak8subindxCtag     =  cms.InputTag("jetsAK8CHS:jetAK8CHSSubwGammatIndex:b2gEDMNtuples"),                           
# jec and jer 
                              ak8Cjecf0tag = cms.InputTag("jetsAK8CHS:jetAK8CHSjecFactor0:b2gEDMNtuples"),
                              ak8CjecL3abstag = cms.InputTag("jetsAK8CHS:jetAK8CHSjecFactorL3Absolute:b2gEDMNtuples"),
                              ak8CjecUncerttag = cms.InputTag("jetsAK8CHS:jetAK8CHSjecUncertainty:b2gEDMNtuples"),
                           
                              ak8Cjersftag     = cms.InputTag("jetsAK8CHS:jetAK8CHSJERSF:b2gEDMNtuples"),
                              ak8Cjersfdowntag = cms.InputTag("jetsAK8CHS:jetAK8CHSJERSFDown:b2gEDMNtuples"),
                              ak8Cjersfuptag   = cms.InputTag("jetsAK8CHS:jetAK8CHSJERSFUp:b2gEDMNtuples"),
                              ak8Cptsmearedtag  = cms.InputTag("jetsAK8CHS:jetAK8CHSSmearedPt:b2gEDMNtuples"),
                              

                              ak4ptCtag  = cms.InputTag("jetsAK4CHS:jetAK4CHSPt:b2gEDMNtuples"),
                              ak4etaCtag = cms.InputTag("jetsAK4CHS:jetAK4CHSEta:b2gEDMNtuples"),
                              ak4phiCtag = cms.InputTag("jetsAK4CHS:jetAK4CHSPhi:b2gEDMNtuples"),
                              ak4eneCtag = cms.InputTag("jetsAK4CHS:jetAK4CHSE:b2gEDMNtuples"),
                              ak4CSVv2Ctag = cms.InputTag("jetsAK4CHS:jetAK4CHSCSVv2:b2gEDMNtuples"),

                              ak4Cceftag = cms.InputTag("jetsAK4CHS:jetAK4CHSchargedEmEnergyFrac:b2gEDMNtuples"),
                              ak4Cchftag = cms.InputTag("jetsAK4CHS:jetAK4CHSchargedHadronEnergyFrac:b2gEDMNtuples"),
                              ak4Cchmtag = cms.InputTag("jetsAK4CHS:jetAK4CHSchargedMultiplicity:b2gEDMNtuples"),
                              ak4Cnmtag  = cms.InputTag("jetsAK4CHS:jetAK4CHSneutralMultiplicity:b2gEDMNtuples"),
                              ak4Cchemftag = cms.InputTag("jetsAK4CHS:jetAK4CHSchargedMultiplicity:b2gEDMNtuples"),
                              
                              ak4Careatag = cms.InputTag("jetsAK4CHS:jetAK4CHSjetArea:b2gEDMNtuples"),
                              ak4Cnemftag = cms.InputTag("jetsAK4CHS:jetAK4CHSneutralEmEnergyFrac:b2gEDMNtuples"),
                              ak4Cnhftag = cms.InputTag("jetsAK4CHS:jetAK4CHSneutralHadronEnergyFrac:b2gEDMNtuples"),
                              ak4Cnnptag = cms.InputTag("jetsAK4CHS:jetAK4CHSneutralMultiplicity:b2gEDMNtuples"),                                       


# jec and jer 
                              ak4Cjecf0tag = cms.InputTag("jetsAK4CHS:jetAK4CHSjecFactor0:b2gEDMNtuples"),
                              ak4CjecL3abstag = cms.InputTag("jetsAK4CHS:jetAK4CHSjecFactorL3Absolute:b2gEDMNtuples"),
                              ak4CjecUncerttag = cms.InputTag("jetsAK4CHS:jetAK4CHSjecUncertainty:b2gEDMNtuples"),
                              ak4Cjersftag  = cms.InputTag("jetsAK4CHS:jetAK4CHSJERSF:b2gEDMNtuples"),
                              ak4Cjersfdowntag = cms.InputTag("jetsAK4CHS:jetAK4CHSJERSFDown:b2gEDMNtuples"),
                              ak4Cjersfuptag   = cms.InputTag("jetsAK4CHS:jetAK4CHSJERSFUp:b2gEDMNtuples"),
                              ak4Cptsmearedtag  = cms.InputTag("jetsAK4CHS:jetAK4CHSSmearedPt:b2gEDMNtuples"),


        
                              ak8subeta1tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetEta0:b2gEDMNtuples"), 
                              ak8subphi1tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetPhi0:b2gEDMNtuples"), 
                              ak8subpt1tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetPt0:b2gEDMNtuples"), 

                              ak8subeta2tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetEta1:b2gEDMNtuples"), 
                              ak8subphi2tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetPhi1:b2gEDMNtuples"), 
                              ak8subpt2tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetPt1:b2gEDMNtuples"), 

                              ak8subeta3tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetEta2:b2gEDMNtuples"), 
                              ak8subphi3tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetPhi2:b2gEDMNtuples"), 
                              ak8subpt3tag = cms.InputTag("jetsAK8CHS:jetAK8CHSSubjetPt2:b2gEDMNtuples"), 

                              
                              phopttag  =  cms.InputTag("photons:phoPt:b2gEDMNtuples"), 
                              phoEtag   =  cms.InputTag("photons:phoE:b2gEDMNtuples"), 
                              phoetatag =  cms.InputTag("photons:phoEta:b2gEDMNtuples"), 
                              phophitag =  cms.InputTag("photons:phoPhi:b2gEDMNtuples"), 
                              phohoetag =  cms.InputTag("photons:phoHoverE:b2gEDMNtuples"), 
                              phosieietag =  cms.InputTag("photons:phoSigmaIEtaIEta:b2gEDMNtuples"), 
                              phohaspixelseedtag =  cms.InputTag("photons:phoHasPixelSeed:b2gEDMNtuples"), 
                              photonIDLoosetag   = cms.InputTag("photons:phoPassLooseID:b2gEDMNtuples"),
                              photonIDMediumtag  = cms.InputTag("photons:phoPassMediumID:b2gEDMNtuples"),
                              photonIDTighttag   = cms.InputTag("photons:phoPassTightID:b2gEDMNtuples"),



                              mupttag = cms.InputTag("muons:muPt:b2gEDMNtuples"),
                              muetatag = cms.InputTag("muons:muEta:b2gEDMNtuples"),
                              muphitag = cms.InputTag("muons:muPhi:b2gEDMNtuples"),
                              muetag = cms.InputTag("muons:muE:b2gEDMNtuples"),
                              muisGlobaltag = cms.InputTag("muons:muIsGlobalMuon:b2gEDMNtuples"),
                              muisPFtag = cms.InputTag("muons:muIsPFMuon:b2gEDMNtuples"),
                              muisTighttag = cms.InputTag("muons:muIsTightMuon:b2gEDMNtuples"),
                              muIso04tag = cms.InputTag("muons:muIso04:b2gEDMNtuples"),

                              metfullphitag = cms.InputTag("metFull:metFullPhi:b2gEDMNtuples"),
                              metfullpttag  = cms.InputTag("metFull:metFullPt:b2gEDMNtuples"),

                              metpuppiphitag = cms.InputTag("puppimetFull:puppimetFullPhi:b2gEDMNtuples"),
                              metpuppipttag  = cms.InputTag("puppimetFull:puppimetFullPt:b2gEDMNtuples"),
                              triggerBit        = cms.InputTag("TriggerUserData:triggerBitTree:b2gEDMNtuples"),
                              triggerPrescale     = cms.InputTag("TriggerUserData:triggerPrescaleTree:b2gEDMNtuples"),
                              triggerName         = cms.InputTag("TriggerUserData:triggerNameTree:b2gEDMNtuples"),


                              
)


process.p = cms.Path(process.demo)
