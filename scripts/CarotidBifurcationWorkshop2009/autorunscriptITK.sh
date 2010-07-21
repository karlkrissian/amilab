#!/bin/bash

center=$1
shift


for n in $*
do
  /home/sara/Pruebas\ Workshop/build/amilab/amilab_2.1.0_release autorunITK.amil $center $n
  /home/sara/Pruebas\ Workshop/build/amilab/amilab_2.1.0_release autorunANT.amil $center $n
done
