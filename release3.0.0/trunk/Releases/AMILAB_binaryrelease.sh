#!/bin/bash

echo "Creating directory"

release=`svnversion -n`
system=`uname -s`
kernel=`uname -r`
machine=`uname -m`

# Create the binary
curdir=AMILab_${release}_${system}_${kernel}_${machine}
echo $curdir
mkdir ${curdir}

cd ${curdir}/
mkdir bin


cp ../builds/optimized/amilab_bin bin/
cp ../amilab_init.sh .

echo "Creating libs"
mkdir libs

#exit

echo "Check vtk libs"
#--- copy vtk and itk libraries
for l in `ldd bin/amilab_bin | grep vtk | gawk '{print $3}'`
do
  if [ -f $l ]
  then
    cp -L $l libs
  fi 
done

for l in `ldd bin/amilab_bin | grep VTK | gawk '{print $3}'`
do
  if [ -f $l ]
  then
    cp -L $l libs
  fi 
done

echo "Check ITK libs"
for l in `ldd bin/amilab_bin | grep itk | gawk '{print $3}'`
do
  if [ -f $l ]
  then
    cp -L $l libs
  fi 
done

for l in `ldd bin/amilab_bin | grep ITK | gawk '{print $3}'`
do
  if [ -f $l ]
  then
    cp $l libs
  fi 
done

echo "Check wxWidgets libs"
#--- copy wxwidgets libraries
for l in `ldd bin/amilab_bin | grep wx | gawk '{print $3}'`
do
  if [ -f $l ]
  then
    echo "cp -L $l libs"
    cp -L $l libs
  fi 
done


echo "Check tiff,png,libXm libs"

res=`ldd bin/amilab_bin | grep tiff  | gawk '{print $3}'`
if [[ $res != "" ]]
then
  cp  -L $res libs
fi

res=`ldd bin/amilab_bin | grep png  | gawk '{print $3}'`
if [[ $res != "" ]]
then
  cp  -L $res libs
fi

#cp  `ldd bin/amilab_bin | grep dps   | gawk '{print $3}'` libs






echo "Creating archive"
#--- save tar file
cd ..

#tarfile="amilab-${system}-${kernel}-${machine}-r${release}.tgz"
#tarfile=${curdir}.tgz

tar zcf ${curdir}.tgz ${curdir}

echo "Removing temporal dir"
rm -Rf  ${curdir}



