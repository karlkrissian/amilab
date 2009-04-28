#!/bin/bash

# Creating source files for the 3 different libraries

# amilab
svnrelease=`svnversion -n`

if [[ $# == 1 ]]
then
  release=$1
else
  release=${svnrelease}
fi

curdir=AMILab_sources_${release}

sources=`more src/source_list.txt`
echo "0.1"
files=`find src/. -name "ReadMe.txt" -o -name "Copyright.txt"  `
echo "0.2"
pixmaps=`find Pixmaps/. -name "*.xpm"`
echo "0.3"
installfiles=`find . \( -name "Find*.cmake" -o -name "INSTALL.txt" \
 -o -name "LesserGPL_license.txt" -o -name "amilab_macros.cmake" \) \! -path "./libAMI*"` 

echo "1"
tar zcf sources.tgz $sources $files $pixmaps $installfiles

mkdir ${curdir}
echo "2"
tar zxf sources.tgz -C ${curdir}/
echo "$svnrelease" > ${curdir}/svn_release_number

rm sources.tgz
echo "3"
tar zcf ${curdir}_src.tgz $curdir
rm -Rf ${curdir}

# libamifluid

# libOpticFlow
