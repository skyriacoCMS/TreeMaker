import sys 
import os

#path="/eos/uscms/store/user/skyria/QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1_B2GAna_QCD/171216_173900/Trees"

#path="/eos/uscms/store/user/skyria/QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2_B2GAna_QCDext/171216_174143/Trees"



path="/eos/uscms/store/user/skyria/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1_B2GAna_TT/171218_194019/Trees/"

cmnd = "ls -al "+path+"  > files.txt "

os.system(cmnd )
os.system("awk '$5 <1300 {print $9}' files.txt > failled.txt")

with open("failled.txt","r") as ifile:
    line = ifile.readline()
    line = ifile.readline()
    line = ifile.readline()
    for line in ifile:
        cmnd = "rm "+path+"/"+line
        os.system(cmnd)

#

#line = filel.readline()
#line = filel.readline()
 



