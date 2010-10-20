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

# to change SetParam, LevelSetsCURV, iterate, end, GetOutput
  commands_to_change=[
            ("LevelSetsCURV\s*\.",     "::levelset."),
            (r"::levelset.init\(([^\)]*)\)",        r"::levelset.InitWithImage(\1) # could also be InitWithThreshold"),
            ("::levelset.end",         "::levelset.End()"),
            (r"::levelset.GetOutput[\s,;]*$",   "::levelset.GetOutputImage()\n"),
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
      
      #print "line=",line
      # parse line
      creationline = "(\s*)LevelSetsCURV\s*\.SetParam\s*\("
      res = re.subn(r""+creationline,r"\1import = &global::ami_import\n\1if (exists(::levelset)) { del ::levelset; }\n\1::levelset = import->vtkLevelSet()\n\1::levelset.SetParam(",line)
      if (res[1]>0):
        line = res[0]
        num_subs = num_subs+1
      for cmd1,cmd2 in commands_to_change:
        res = re.subn(cmd1,cmd2,line)
        if (res[1]>0):
          line = res[0]
          num_subs = num_subs+1
          #sys.stdout.write("("+cmd1+","+cmd2+") -> "+line)
      f.write(line)
      if comments!="":
        f.write(comments+"\n")
    f.close()
    if (num_subs!=0):
      print "Number of lines changed =", num_subs, " for file "+inputscript
    else:
      os.remove(inputscript+".converted")


