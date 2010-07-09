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
  # the third parameter: a boolean, is True if we need to ask confirmation from the user ...
  commands_force_par=[
            ("close",       "close",        True ),
            ("print",       "print",        True ),
            ("printn",      "printn",       True ),
            ("read_float",  "read_float",   True ),
            ("read_string", "read_string",  True ),
            ("rewind",      "rewind",       True ),
            ("scan_float",  "scan_float",   True ),
            ]

  # close pattern: *file.close,  *file*.close, *.close 
  # open pattern(Deprecated):  *= open(*
  # print pattern: *_File*.print* , file.print*
  # read_float pattern: No check
  # read_string pattern: No check
  # rewind pattern: No check
  # scan_float pattern: No check

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

      for cmd1,cmd2,ask in commands_force_par:
        # $ matches the end of the string and avoids adding () where there are already present
        # if no parenthesis, add it
        res = re.subn(r"_draw\s*\.(\s*)"+cmd1+r"(\s*[^\(]|\s*$)",r"_draw."+cmd2+r"()\2",line)
        if (res[1]>0):
          if ask:
            message = " Conversion of File methods from: \n"
            message = message + "'"+line[:-1]  +"' to:"
            message = message + "'"+res[0][:-1]+"' accept? (Y/N)"
            applychanges=raw_input(message)
            if applychanges=="Y":
              line = res[0]
              num_subs = num_subs+1
          else:
            if (res[0]!=line):
              line = res[0]
              num_subs = num_subs+1
        # if parenthesis, just replace name
        res = re.subn(r"_draw\s*\.(\s*)"+cmd1+r"(\s*[\(]|\s*$)",r"_draw."+cmd2+r"\2",line)
        if (res[1]>0):
          if ask:
            message = " Conversion of File methods from: \n"
            message = message + "'"+line[:-1]  +"' to: "
            message = message + "'"+res[0][:-1]+"' accept? (Y/N)"
            applychanges=raw_input(message)
            if applychanges=="Y":
              line = res[0]
              num_subs = num_subs+1
          else:
            if (res[0]!=line):
              line = res[0]
              num_subs = num_subs+1
          #sys.stdout.write("("+cmd1+","+cmd2+") -> "+line)

        # convert FILE to OBJECT in parameter declaration
        res = re.subn(r"(,|\()\s*FILE(\s+|,|\))",r"\1 OBJECT\2",line)
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


