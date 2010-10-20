#!/bin/bash

#
# replace the release number and build type to generate specific windows installation script
#
# parameters:
# 1. release number
# 2. buildtype
#

s="s/\${version}/$1/g"
echo $s
sed $s   < amilab_wininstall_generic.iss > amilab_wininstall_$1.iss
s="s/\${buildtype}/$2/g"
echo $s
sed $s < amilab_wininstall_$1.iss > amilab_wininstall_$1_$2.iss 
rm  amilab_wininstall_$1.iss
