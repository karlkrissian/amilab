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
    cp $l libs
  fi 
done

for l in `ldd bin/amilab_bin | grep VTK | gawk '{print $3}'`
do
  if [ -f $l ]
  then
    cp $l libs
  fi 
done

echo "Check ITK libs"
for l in `ldd bin/amilab_bin | grep itk | gawk '{print $3}'`
do
  if [ -f $l ]
  then
    cp $l libs
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
    cp $l libs
  fi 
done


echo "Check tiff,png,libXm libs"

res=`ldd bin/amilab_bin | grep tiff  | gawk '{print $3}'`
if [[ $res != "" ]]
then
  cp  $res libs
fi

res=`ldd bin/amilab_bin | grep png  | gawk '{print $3}'`
if [[ $res != "" ]]
then
  cp  $res libs
fi

#cp  `ldd bin/amilab_bin | grep dps   | gawk '{print $3}'` libs

res=`ldd bin/amilab_bin | grep libXm  | gawk '{print $3}'`
if [[ $res != "" ]]
then
  cp  $res libs
fi



#----------------------------------
# Create the scripts
#----------------------------------

echo "Creating scripts dir"
# find the scripts
script_files=`find ../scripts/. -name "*.amil" -o -name  "*.sh" -o -name "*.html"`

# create a directory to because of the relative .. in ../scripts
mkdir anydir
# copy preserving the parents, the links, and the properties
cp --parents -d -p  `echo ${script_files}` anydir
rmdir anydir

#----------------------------------
# Create the documentation
#----------------------------------

echo "Creating doc dir"

# find the doc files
doc_files=`find ../doc/. -name "*.htm*" -o -name "*.amih" \
                      -o -name "*.gif" \
                      -o -name ".css" \
                      -o -name "*.txt"`

# create a directory to because of the relative .. in ../scripts
mkdir anydir
# copy preserving the parents, the links, and the properties
cp --parents -d -p  `echo ${doc_files}` anydir
rmdir anydir


echo "Creating archive"
#--- save tar file
cd ..

#tarfile="amilab-${system}-${kernel}-${machine}-r${release}.tgz"
#tarfile=${curdir}.tgz

tar zcf ${curdir}.tgz ${curdir}

echo "Removing temporal dir"
rm -Rf  ${curdir}



