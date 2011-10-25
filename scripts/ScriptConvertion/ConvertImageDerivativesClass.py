#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Class for generating HTML pages
#

import string
import os
import sys


#
# Code to test this class
#

import re,fileinput


if __name__ == "__main__":

  #-------------------------------------------------
  # Links to commands 
  #-------------------------------------------------

  # read the input file

  amihfile=re.compile('\S*amil$')

  # 1. Create the table of contents from the main directories
  # 2. Propose also an alphabetical list

  # could also use language.WrapVariable(&\1).Name()-"_ref" as second parameter ...
  replacements=[
    # --------- StructTensor with 3 arguments -------------
    (r"StructTensor\(([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.StructTensor(&\1,"\1",\2,\3)')
    ,
    # --------- StructTensor with 4 arguments -------------
    (r"StructTensor\(([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.StructTensor(&\1,"\1",\2,\3,&\4)')
    ,
    # --------- StructTensorH with 3 arguments -------------
    (r"StructTensorH\(([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.StructTensorH(&\1,"\1",\2,\3,&\4)')
    ,
    # --------- StructTensorH with 4 arguments -------------
    (r"StructTensorH\(([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.StructTensorH(&\1,"\1",\2,\3,&\4)')
    ,
    # --------- StructTensorH with 5 arguments -------------
    (r"StructTensorH\(([^,]+),([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.StructTensorH(&\1,"\1",\2,\3,&\4,\5)')
    ,
    # --------- HessianMatrix with 2 arguments -------------
    (r"HessianMatrix\(([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.HessianMatrix(&\1,"\1",\2)')
    ,
    # --------- HessianMatrix with 4 arguments -------------
    (r"HessianMatrix\(([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.HessianMatrix(&\1,"\1",\2,\3,&\4)')
    ,
    # --------- HessianEval with 5 arguments -------------
    (r"HessianEval\(([^,]+),([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.HessianEval(&\1,"\1",\2,\3,&\4,\5)')
    ,
    # --------- Eigen3D with 8 arguments -------------
    (r"Eigen3D\(([^,]+),([^,]+),([^,]+),([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.Eigen3D(\1,&\2,&\3,&\4,&\5,&\6,&\7,&\8)')
    ,
    # --------- Eigen2D with 4 arguments -------------
    (r"Eigen2D\(([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.Eigen2D(\1,&\2,&\3,&\4,&\5)')
    ,
    # --------- discsecdergrad with 2 arguments -------------
    (r"discsecdergrad\(([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.discsecdergrad(\1,&\2)')
    ,
    # --------- discsecdergrad with 3 arguments -------------
    (r"discsecdergrad\(([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.discsecdergrad(\1,&\2,&\3)')
    ,
    # --------- normgrad with 2 arguments -------------
    (r"normgrad\(([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.normgrad(&\1,\2)')
    ,
    # --------- discnormgrad with 1 argument -------------
    (r"discnormgrad\(([^,\)]+)\)",
     r'ImageDerivativesClass.discnormgrad(&\1)')
    ,
    # --------- DiscMeanCurvature with 1 argument -------------
    (r"DiscMeanCurvature\(([^,\)]+)\)",
     r'ImageDerivativesClass.DiscMeanCurvature(&\1)')
    ,
    # --------- Laplacian with 1 argument -------------
    (r"Laplacian\(([^,\)]+)\)",
     r'ImageDerivativesClass.Laplacian(&\1)')
    ,
    # --------- secdergrad with 2 arguments -------------
    (r"secdergrad\(([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.secdergrad(&\1,\2)')
    ,
    # --------- secdergrad2 with 2 arguments -------------
    (r"secdergrad2\(([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.secdergrad2(&\1,\2)')
    ,
    # --------- gradient with 2 arguments -------------
    (r"gradient\(([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.gradient(&\1,\2)')
    ,
    # --------- filter with 5 arguments -------------
    (r"filter\(([^,]+),([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'ImageDerivativesClass.filter(&\1,\2,\3,\4,\5)')
    ,
    # --------- localmean with 2 arguments -------------
    (r"localmean\(([^,]+),([^,\)]+)\)",
     r'LocalStatsClass.localmean(&\1,\2)')
    ,
    # --------- localmean2 with 2 arguments -------------
    (r"localmean2\(([^,]+),([^,\)]+)\)",
     r'LocalStatsClass.localmean2(&\1,\2)')
    ,
    # --------- localSD with 3 arguments -------------
    (r"localSD\(([^,]+),([^,]+),([^,\)]+)\)",
     r'LocalStatsClass.localSD(&\1,&\2,\3)')
    ,
    # --------- localSD2 with 3 arguments -------------
    (r"localSD2\(([^,]+),([^,]+),([^,\)]+)\)",
     r'LocalStatsClass.localSD2(&\1,&\2,\3)')
    ,
    # --------- BorgeforsDT with 2 arguments -------------
    (r"BorgeforsDT\(([^,]+),([^,\)]+)\)",
     r'DistanceTransformClass.BorgeforsDT(&\1,\2)')
    ,
    # --------- BorgeforsSDT with 2 arguments -------------
    (r"BorgeforsSDT\(([^,]+),([^,\)]+)\)",
     r'DistanceTransformClass.BorgeforsDT(&\1,\2)')
    ,
    # --------- ChamferDT with 4 arguments -------------
    (r"ChamferDT\(([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'DistanceTransformClass.ChamferDT(&\1,\2,\3,\4)')
    ,
    # --------- Chamfer2DT with 4 arguments -------------
    (r"Chamfer2DT\(([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'DistanceTransformClass.Chamfer2DT(&\1,\2,\3,\4)')
    ,
    # --------- Chamfer2DT with 5 arguments -------------
    (r"Chamfer2DT\(([^,]+),([^,]+),([^,]+),([^,]+),([^,\)]+)\)",
     r'DistanceTransformClass.Chamfer2DT(&\1,\2,\3,\4,\5)')
    ,
    # --------- PropagationDist with 2 arguments -------------
    (r"PropagationDist\(([^,]+),([^,\)]+)\)",
     r'DistanceTransformClass.PropagationDist(&\1,\2)')
    ]
    
  scripts=[]
  amilfile=re.compile('\S*amil$')

  for root,dirs,files in os.walk("."):
    for f in files:
      m=amilfile.match(f)
      if (m != None):
        scripts.append(root+"/"+f)

  for inputscript in scripts:
    print "*** Processing file ",inputscript
    f = open(inputscript+".converted", 'w')
    num_subs = 0
    for line in fileinput.input(inputscript):
      lineno = 0
      # get rid of comments (here html comments, useless)
      # '#' style
      comments = ""
      splitcomments = re.match(r"([^\#]*)(\#.*)",line)
      if (splitcomments!=None):
        line    = splitcomments.group(1)
        comments = splitcomments.group(2)
      # '//' style
      splitcomments = re.match(r"([^/]*)(//.*)",line)
      if (splitcomments!=None):
        line    = splitcomments.group(1)
        comments = splitcomments.group(2)+comments
      
      for cmd1,cmd2 in replacements:
        #print "line=",line
        # parse line
        # 2. convert 
        res = re.search(cmd1,line)
        if (res!=None):
          res1 = re.subn(cmd1,cmd2,line)
          print "found "+res.group(0)+ " in "+line
          print "replacement is {0}".format(res1[0])
          apply = raw_input("Apply convertion ? ('y' for Yes)")
          if apply=="y":
            # TRICK: replace the first occurence of ',"::name"' to ',"name"', 
            # should use the variable name instead
            line = string.replace(res1[0],',"::',',"',1)
            print " --> " +line
            num_subs = num_subs+1
            break

      # --------- HessianMatrix with 3 arguments -------------
      if res==None:
        res = re.search(r"HessianMatrix\(([^,]+),([^,]+),([^,\)]+)\)",line)
        if (res!=None):
          res1 = re.subn(r"HessianMatrix\(([^,]+),([^,]+),([^,\)]+)\)",
                        r'ImageDerivativesClass.HessianMatrix(&\1,"\1",\2,\3)',\
                        line)
          res2 = re.subn(r"HessianMatrix\(([^,]+),([^,]+),([^,\)]+)\)",
                        r'ImageDerivativesClass.HessianMatrix(&\1,"\1",\2,0,&\3)',\
                        line)
          print "found "+res.group(0)+ " in "+line
          print "replacement is {0} or {1}".format(res1[0],res2[0])
          print "2 option of the last parameter: gamma or mask"
          apply = raw_input("Apply convertion ? (1 for gamma, 2 for mask)")
          if apply=="1":
            # TRICK: replace the first occurence of ',"::name"' to ',"name"', 
            # should use the variable name instead
            line = string.replace(res1[0],',"::',',"',1)
            print " --> " +line
            num_subs = num_subs+1
          if apply=="2":
            # TRICK: replace the first occurence of ',"::name"' to ',"name"', 
            # should use the variable name instead
            line = string.replace(res2[0],',"::',',"',1)
            print " --> " +line
            num_subs = num_subs+1
            
      f.write(line)
      if comments!="":
        f.write(comments+"\n")
    f.close()
    if (num_subs!=0):
      print "Number of lines changed =", num_subs, " for file "+inputscript
    else:
      os.remove(inputscript+".converted")


