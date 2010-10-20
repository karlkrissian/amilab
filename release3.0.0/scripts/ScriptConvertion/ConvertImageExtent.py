#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#  Class for generating HTML pages
#

#
# convert previous rule   [expr:expr,expr:expr,expr:expr]
# to image_extent = [primary_var:primary_var,primary_var:primary_var,primary_var:primary_var]
#
# if operators are used within extent, we need now to put parenthesis around ...
# otherwise we need to set : as an operator and to create a 'Range' object ...


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
      
      # -  convert [a:b,c:d,e:f]
      res = re.search(r"\s*\[([^:]*):([^:]*),([^:]*):([^:]*),([^:]*):([^:]*)\]",line)
      if (res!=None):
        # check for each group if we need to add parenthesis around
        modified=0
        displ=0
        for n in range(1,7):
          if not( re.match(r"^\s*[0-9_a-zA-Z]*\s*$",res.group(n)) or 
                  re.match(r"^\s*\([^\)]*\)\s*$",   res.group(n))):
            # add parenthesis
            #print "initial line: ",line
            #print line[:res.start(n)+displ]
            #print line[res.end(n)+displ:]
            line = line[:res.start(n)+displ]+"("+res.group(n)+")"+line[res.end(n)+displ:]
            displ=displ+2
            #print "newline: ", line
            modified=1
        if modified:
          num_subs = num_subs+1
      
      # -  convert [a:b,c:d]
      res = re.search(r"\s*\[([^:]*):([^:]*),([^:]*):([^:]*)\]",line)
      if (res!=None):
        # check for each group if we need to add parenthesis around
        modified=0
        displ=0
        for n in range(1,5):
          if not( re.match(r"^\s*[0-9_a-zA-Z]*\s*$",res.group(n)) or 
                  re.match(r"^\s*\([^\)]*\)\s*$",   res.group(n))):
            # add parenthesis
            #print "initial line: ",line
            #print line[:res.start(n)+displ]
            #print line[res.end(n)+displ:]
            line = line[:res.start(n)+displ]+"("+res.group(n)+")"+line[res.end(n)+displ:]
            displ=displ+2
            #print "newline: ", line
            modified=1
        if modified:
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


