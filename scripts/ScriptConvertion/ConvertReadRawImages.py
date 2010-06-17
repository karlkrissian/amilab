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

  scripts=[]
  changedfiles = []
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
      typeval = r"(CHAR|UCHAR|SHORT|USHORT|INT|UINT|LONG|FLOAT|DOUBLE|RGB|FLOAT_VECTOR)"
      res = re.subn(r"ReadRawImages\(([^,]+),([^,]+),\s*"+typeval+"(\.val|)\s*,([^,]+),([^,]+),([^,]+),([^\)]+)\)",r"IO.ReadRawImages2D( \1, \2, \3.val, \5, \6, \7, \8 )",line)
      if (res[1]>0):
        line = res[0]
        num_subs = num_subs+1
      res = re.subn(r"ReadRawImages\(([^,]+),([^,]+),([^,]+),\s*"+typeval+"(.val|)\s*,([^,]+),([^,]+)\)",r"IO.ReadRawImage3D(\1,\2,\3,\4.val,\6,\7)",line)
      if (res[1]>0):
        line = res[0]
        num_subs = num_subs+1
      res = re.subn(r"ReadRawImages\(([^,]+),([^,]+),([^,]+),\s*"+typeval+"(.val|)\s*,([^,]+),([^,]+),([^,]+)\)",r"IO.ReadRawVectImage3D(\1,\2,\3,\4.val,\6,\7,\8)",line)
      if (res[1]>0):
        line = res[0]
        num_subs = num_subs+1
        
      
      f.write(line)
      if comments!="":
        f.write(comments+"\n")
    
    f.close()
    if (num_subs!=0):
      print "Number of lines changed =", num_subs, " for file "+inputscript
      changedfiles.append(inputscript)
    else:
      os.remove(inputscript+".converted")
  print "\nFiles changed:\n"
  print changedfiles

