#!/bin/bash

cd 2.8

n=0
n1=0
severalfile="Generated/wrap_${n1}.cpp"
echo "" > ${severalfile}

for f in wrap_wx*.cpp;  do  
  echo "#include \"$f\"" >> ${severalfile}
  n=`expr $n + 1`
  if [ $n -eq 10 ] 
  then
    n=0
    n1=`expr $n1 + 1`
    severalfile="Generated/wrap_${n1}.cpp"
    echo "" > ${severalfile}
    echo $n1
  fi
done

cd ..
