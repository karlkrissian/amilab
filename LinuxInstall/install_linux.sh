#!/bin/bash

# check for proper number of command line arguments
ERROR_PAR=65

if [ $# -ne 2 ]
   then
      echo
      echo " Usage: "
      echo " $0 amilabtag configfile"
      echo " where amilabtag is the name of the amilab subversion repository tab to download (for example Release-3.0.0)"
      echo " configfile is a file defining the variables for your linux distribution"
      echo
      exit $ERROR_PAR
fi

#
# need to specify the release tag as argument
#
releasetag=$1

source $2

#
# Script for installing amilab from source on Ubuntu, tested on Ubuntu 10.10 32 bits
#
# the whole process may take more than 30 minutes depending on your computer
# need to be run as root precause of the packages to install

function install_packages {
  echo "-------------------------"
  echo "  Installation of $1     "
  echo "-------------------------"

  eval "packages=\$$1_PACKAGES"
  echo "  packages are $packages   "

  if [ $packages == "TOCOMPILE" ]
  then
    echo "Compiling $1 from source"
    eval "source $1_COMPILE.sh"
    if [ $? != 0 ]
    then
      echo "Installation of $1 failed"
      exit $?
    fi
  else
    if [ $packages != "" ]
    then
      ${INSTALLCMD} $packages
      if [ $? != 0 ]
      then
        echo "Installation of $1 failed"
        exit $?
      fi
    fi
  fi

}

#
# selecting fastest mirror on ubuntu, check:
# http://www.ubuntugeek.com/how-to-select-fastest-mirror-in-ubuntu.html
#
install_packages INSTALLER

# Compilation packages
install_packages  COMPILATION

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

# CMake installation
install_packages CMAKE

# VTK
install_packages VTKDEV

# WXWIDGETS
install_packages WXWIDGETSDEV

# Boost
install_packages BOOSTDEV

# Image IO packages
install_packages IMDEV

# Compression packages
install_packages COMPRESSDEV

# Other packages
install_packages OTHERDEV

# Bison-Flex packages
install_packages BISONFLEX

# ITK packages
install_packages ITKDEV

svn co  https://amilab.svn.sourceforge.net/svnroot/amilab/tags/${releasetag} amilab_stable
cd amilab_stable
maindir=`pwd`

# Compile and install libAMIFluid
echo "Compiling and installing libAMIFluid"
cd ${maindir}/libAMIFluid/src
mkdir build; cd build; mkdir release; cd release
cmake ../..
make -j ${numthreads} install

# Copy libAMIOpticalFlow
echo "Copying libAMIOpticalFlow"
cd ${maindir}
cp -R libAMIOpticalFlow/include/OpticalFlow /usr/local/include/

# Compile amilab
echo "Compiling amilab"
cd ${maindir}/src
mkdir build; mkdir build/release; cd build/release
eval "cmake ${AMILAB_CMAKE_FLAGS} ../.."

if [ $? != 0 ]
  echo "--- cmake command failed ---"
  exit $?
fi

make -j ${numthreads} 

# Compile documentation, but missing improcess_html 
cd ${maindir}/doc
./generate_html.py all

# create and install ubuntu package ?
cd ${maindir}/src/build/release
${INSTALLCMD} rpm-build
cpack -G RPM
rpm -ivh AMILab-3.0.0-Linux.`uname -p`.rpm
