#!/usr/bin/python
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

    amihfile=re.compile('\S*amih$')

    # 1. Create the table of contents from the main directories
    # 2. Propose also an alphabetical list

    commands=[]

    for root,dirs,files in os.walk("."):
        #print dirs
        #print files
        for f in files:
            m=amihfile.match(f)
            if (m != None):
                cmd=string.split(m.group(),".amih")[0]
                #print cmd
                commands.append((cmd,root))
                #print commands
    #print commands
    #

    for line in fileinput.input(sys.argv[1:]):
        lineno = 0
        # get rid of comments
        if (re.match(r'<.*>\s*#.*',line)==None) and (re.match(r'<.*>\s*//.*',line)==None):
            for cmd,root in commands:
                lineno = string.find(line, cmd)
                if lineno >0:
                    line=re.sub(r'\b'+cmd+r'\b',"<a href=\""+root+"/"+cmd+".amih\">"+cmd+"</a>",line)
        sys.stdout.write(line)





