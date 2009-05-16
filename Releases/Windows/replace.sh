#!/bin/bash

s="s/\${version}/$1/"
echo $s
sed $s   < amilab_wininstall_generic.iss > amilab_wininstall_$1.iss
s="s/\${buildtype}/$2/"
echo $s
sed $s < amilab_wininstall_$1.iss > amilab_wininstall_$1_$2.iss 
rm  amilab_wininstall_$1.iss
