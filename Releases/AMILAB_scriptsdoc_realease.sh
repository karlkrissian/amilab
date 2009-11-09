#!/bin/bash

if [[ $1 -eq "generate" ]]
then
  echo "Generating the documentation"
  cd doc
  ./generate_html.py 
  cd ..
fi

echo "Creating directory"
release=`svnversion -n`

# Create the binary
curdir=AMILab_${release}_scripts_doc
echo $curdir
mkdir ${curdir}

cd ${curdir}/


#----------------------------------
# Create the scripts
#----------------------------------

echo "Creating scripts dir"
# find the scripts
script_files=`find -L ../scripts/. -name "*.amil" -o -name  "*.sh" -o -name "*.html"`

# create a directory to because of the relative .. in ../scripts
mkdir anydir
# copy preserving the parents, and the properties
cp --parents  -p  `echo ${script_files}` anydir
rmdir anydir



#----------------------------------
# Create the documentation
#----------------------------------

echo "Creating doc dir"

# find the doc files
# get rid of files with special characters for windows installation ...
doc_files=`find -L ../doc/. -type f \
  \( -name "*.html" -o -name "*.amih" \
                      -o -name "*.gif" \
                      -o -name "*.css" \
                      -o -name "*.txt"   \) `

#              -o -name "-*"  -o -name "<*"  \) \

#       -! -name "-*" \
#       -! -name ">*" \
#       -! -name "=*" \
#       -! -name "<*" \
#       -! -name "%*" \
#       -! -name "&*" \
#       -! -name "|*" \
#       -! -name "!*" \
#       -! -name "^*" \
#       -! -name "\\*" \

echo $doc_files

# create a directory to because of the relative .. in ../scripts
mkdir anydir
# copy preserving the parents,  and the properties
for f in ${doc_files}
do
 echo "cp --parents  -p  $f anydir"
 cp --parents  -p  $f anydir
done
rmdir anydir


echo "Creating archive"
#--- save tar file
cd ..

#tarfile="amilab-${system}-${kernel}-${machine}-r${release}.tgz"
#tarfile=${curdir}.tgz

tar zcf ${curdir}.tgz ${curdir}

echo "Removing temporal dir"
rm -Rf  ${curdir}



