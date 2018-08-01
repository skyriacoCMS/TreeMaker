import os
import sys

jonum  = sys.argv[1]

fileinp = open("InpOut.txt","r")
outp     = fileinp.readline() 
inpp =""
for x in range(0,int(jonum)):
    inpp = fileinp.readline()

cmnd = "cmsRun ConfFile_cfg.py "+inpp.strip("\n")+" output_"+jonum+".root"
print cmnd
os.system(cmnd)
print "xrdcp output_"+jonum+".root "+outp.strip("\n")+jonum+"_tree.root"
os.system("xrdcp output_"+jonum+".root "+outp+jonum+"_tree.root")

print "rm output_"+jonum+".root "
os.system("rm output_"+jonum+".root ")
