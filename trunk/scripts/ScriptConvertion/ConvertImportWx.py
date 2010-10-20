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

  wxclasses = [ "wxWindow","wxSize","wxColour","wxImage", "wxBitmap", "wxHtmlWindow" ]
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

      for cl in wxclasses:
        
        res = re.subn(r"([a-zA-Z_]*)\s*->\s*"+cl+r"\(",r"wx."+cl+r"(",line)
        if (res[1]>0):
          line = res[0]
          num_subs = num_subs+1
          
        res = re.search(r"([a-zA-Z_]*)\s*\.\s*"+cl+r"\(",line)
        if ((res!=None) and (res.group(1)!="wx")):
          res = re.subn(r"([a-zA-Z_]*)\s*\.\s*"+cl+r"\(",r"wx."+cl+r"(",line)
          if (res[1]>0):
            line = res[0]
            num_subs = num_subs+1
      f.write(line)
      if comments!="":
        f.write(comments+"\n")
    f.close()
    if (num_subs!=0):
      print "Number of lines changed =", num_subs, " for file "+inputscript
    else:
      os.remove(inputscript+".converted")


