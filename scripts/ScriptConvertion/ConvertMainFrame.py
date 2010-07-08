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

  to_convert = [ "AddMenuScript" ]

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
      
      for cmd in to_convert:
        # $ matches the end of the string and avoids adding () where there are already present
        # if no parenthesis, add it
        res = re.subn(r"((^|\s*;)\s*)"+cmd+r"(\s*[\(])",r"\1ami.MainFrame."+cmd+r"\3",line)
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


