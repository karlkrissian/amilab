#!/bin/bash

scriptname=$1
shift
center=$1
shift
recompute=$1
shift
denoising=$1
shift

for n in $*
do
  amilab ${scriptname}.amil $center $n $recompute $denoising
done
