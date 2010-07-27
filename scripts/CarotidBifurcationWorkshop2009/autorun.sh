#!/bin/bash

config=$1
shift
center=$1
shift

for n in $*
do
  amilab AutoRun.amil $config $center $n
done
