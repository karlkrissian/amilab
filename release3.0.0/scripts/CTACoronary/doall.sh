#!/bin/bash

# parameter 1 : image0x

../scripts/mhd2ami.amil $1.mhd 
../scripts/read_vessels.amil $1.ami
sh ../scripts/combine_vessels.sh 
#sh ../scripts/recons.sh $1.ami 
../scripts/create_ROI.amil $1.ami 
../scripts/filter_nlm.amil 
