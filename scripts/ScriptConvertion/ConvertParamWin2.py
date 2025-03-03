#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Class for generating HTML pages
#

import string
import os
import sys
import shutil


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

  commands_with_par=[
      (r"\.\s*BeginBox\s*\(",         ".BeginBoxPanel("),
      
      # convert old style without label
      (r"\.\s*AddFloat\s*\(\s*([:a-zA-Z0-9_]+)\s*,([^,)]+,[^,)]+\))",
        r'.AddFloat( &\1,  "\1", \2'),
      
      (r"\.\s*AddFloat\s*\(\s*([:a-zA-Z0-9_]+)",         
        r".AddFloat( &\1"),
      
      
      # convert old style without label
      (r"\.\s*AddInt\s*\(\s*([:a-zA-Z0-9_]+)\s*,([^,)]+,[^,)]+\))",
        r'.AddInt( &\1,  "\1", \2'),
      
      (r"\.\s*AddInt\s*\(\s*([:a-zA-Z0-9_]+)",         
        r".AddInt( &\1"),
        
      (r"\.\s*AddEnum\s*\(\s*([:a-zA-Z0-9_]+)",         
        r".AddEnum( &\1"),
     
      
      (r"\.\s*AddFilename\s*\(\s*([:a-zA-Z0-9_]+)",         
        r".AddFilename( &\1"),
      
      (r"\.\s*AddString\s*\(\s*([:a-zA-Z0-9_]+)",         
        r".AddString( &\1"),
      
      (r"\.\s*AddBoolean\s*\(\s*([:a-zA-Z0-9_]+)",       r".AddBoolean( &\1"),
      
      (r"\.\s*SetCallback\s*\(\s*([:a-zA-Z0-9_]+)",
        r".SetCallback( &\1"),
      
      (r"\.\s*SetDragCallback\s*\(",
        ".SetDragCallback("),
      
      (r"\.\s*AddImageChoice\s*\(\s*([:a-zA-Z0-9\_]+)",
      r".AddImageChoice( &\1"),
      
      ]

  commands_with_or_without_par=[
            ]
  
  commands_force_par=[
            ("EndBox",           "EndBoxPanel()"),
            ("CreateWin",        "Update()"),
            ("Hide",             "HidePanel()"),
            ("update",           "Update(-1)"),
            ("BeginBook",        "BeginBook()"),
            ]
            
  commands_addpar =[
    "EndBoxPanel", "Update", "HidePanel", "BeginBook", "EndBook", "Display", "BeginHorizontal", "EndHorizontal"
  ]
  
  scripts=[]
  amilfile=re.compile('\S*amil$')

  for root,dirs,files in os.walk("."):
    for f in files:
      m=amilfile.match(f)
      if (m != None):
        scripts.append(root+"/"+f)

  for inputscript in scripts:
    #print "*** Processing file ",inputscript
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
      creationline = "(\s*)([:a-zA-Z_]+)\s*=\s*ParamWin\s*\("
      res = re.subn(r""+creationline,r"\1import = &global::ami_import;\n\1\2 = import->ParamPanel(",line)
      if (res[1]>0):
        line = res[0]
        num_subs = num_subs+1
      for cmd1,cmd2 in commands_with_par:
        res = re.subn(cmd1,cmd2,line)
        if (res[1]>0)and res[0]!=line:
          line = res[0]
          num_subs = num_subs+1
          #sys.stdout.write("("+cmd1+","+cmd2+") -> "+line)
      for cmd1,cmd2 in commands_with_or_without_par:
        res = re.subn(r"\.(\s*)"+cmd1+r"([^a-zA-Z_])",r"."+cmd2+r"\2",line)
        if (res[1]>0)and res[0]!=line:
          line = res[0]
          num_subs = num_subs+1
          #sys.stdout.write("("+cmd1+","+cmd2+") -> "+line)
      for cmd1,cmd2 in commands_force_par:
        # $ matches the end of the string and avoids adding () where there are already present
        res = re.subn(r"\.(\s*)"+cmd1+r"(\s*$)",r"."+cmd2+r"\2",line)
        if (res[1]>0) and res[0]!=line:
          line = res[0]
          num_subs = num_subs+1
          #sys.stdout.write("("+cmd1+","+cmd2+") -> "+line)
          
      for cmd in commands_addpar:
        res = re.subn(r"\.(\s*)"+cmd+r"(\s+[^\(]|;|$)",r"."+cmd+r"()\2",line)
        if (res[1]>0):
          if (res[0]!=line):
            line = res[0]
            num_subs = num_subs+1
          
      f.write(line)
      if comments!="":
        f.write(comments+"\n")
    f.close()
    if (num_subs!=0):
      print "Number of lines changed =", num_subs, " for file "+inputscript
      cmd = 'diff '+inputscript+ " " +inputscript+".converted"
      os.system(cmd)
      applychanges=raw_input('Apply the changed ? (Y/N):')
      if applychanges=="Y":
        shutil.move(inputscript,inputscript+".bak")
        shutil.move(inputscript+".converted",inputscript)
    else:
      os.remove(inputscript+".converted")


