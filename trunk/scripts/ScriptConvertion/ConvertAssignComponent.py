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
  amilfile=re.compile('\S*amil$')

  for root,dirs,files in os.walk("."):
    for f in files:
      m=amilfile.match(f)
      if (m != None):
        scripts.append(root+"/"+f)

  for inputscript in scripts:
    print "*** Pre-Processing file ",inputscript
    list_arrays = []
    for line in fileinput.input(inputscript):
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
      # 1. search for id = Surface[expr] or id = Image[expr]
      res = re.search(r"\s*([:a-zA-Z0-9_]+)\s*=\s*Surface\[",line)
      if (res!=None):
        list_arrays.append(res.group(1))
        print "found variable "+res.group(1)
      res = re.search(r"\s*([:a-zA-Z0-9_]+)\s*<<=\s*Surface\[",line)
      if (res!=None):
        list_arrays.append(res.group(1))
        print "found variable "+res.group(1)
      res = re.search(r"\s*([:a-zA-Z0-9_]+)\s*=\s*Image\[",line)
      if (res!=None):
        list_arrays.append(res.group(1))
        print "found variable "+res.group(1)
      res = re.search(r"\s*([:a-zA-Z0-9_]+)\s*<<=\s*Image\[",line)
      if (res!=None):
        list_arrays.append(res.group(1))
        print "found variable "+res.group(1)
    
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
      # 2. convert 
      res = re.search(r"\s*([:a-zA-Z0-9_]+)\s*\[(.+)\]\s*=\s*(.+)",line)
      if (res!=None):
        if list_arrays.count(res.group(1))==0:
          print "found "+res.group(1)+ " in "+line
          res = re.subn(r"\s*([:a-zA-Z0-9_])\s*\[(.+)\]\s*=\s*(.+)",r"\1.SetComponent( \2, \3)",line)
          line = res[0]
          num_subs = num_subs+1
        else:
          print "line "+line+"not replaced since variable seems to be an array ..."
        #sys.stdout.write("("+cmd1+","+cmd2+") -> "+line)
      f.write(line)
      if comments!="":
        f.write(comments+"\n")
    f.close()
    if (num_subs!=0):
      print "Number of lines changed =", num_subs, " for file "+inputscript
    else:
      os.remove(inputscript+".converted")


