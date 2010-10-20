#!/bin/bash

# check for proper number of command line arguments
ERROR_PAR=65

if [ $# -ne 1 ]
   then
      echo
      echo " Usage: "
      echo " $0 amilabtag"
      echo " where amilabtag is the name of the amilab subversion repository tab to download (for example release-3.0.0)"
      echo
      exit $ERROR_PAR
fi

#
# need to specify the release tag as argument
#
releasetag=$1

#
# Script for installing amilab from source on Ubuntu, tested on Ubuntu 10.10 32 bits
#
# the whole process may take more than 30 minutes depending on your computer
# need to be run as root precause of the packages to install

#
# selecting fastest mirror on ubuntu, check:
# http://www.ubuntugeek.com/how-to-select-fastest-mirror-in-ubuntu.html
#
apt-get install build-essential subversion
apt-get install cmake
# cmake-curses-gui cmake-qt-gui

# if you have problems with missing packages, try to change the repository
# for example http://ubuntu.media.mit.edu/ubuntu worked
apt-get install libvtk5-dev 
apt-get install libinsighttoolkit3-dev 
apt-get install libwxgtk2.8-dev libboost1.35-dev zlib1g-dev libbz2-dev libpng12-dev libtiff4-dev libexpat1-dev  uuid-dev

apt-get install bison flex

#apt-get install libgdcm2-dev

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

#install recent wxwidgets
apt-get install libgtk2.0-dev
if [ \! -f wxGTK-2.8.10.tar.gz ];
then
  apt-get install wget
  wget http://www.cmake.org/files/v2.8/cmake-2.8.2-Linux-i386.tar.gz
  tar zxf wxGTK-2.8.10.tar.gz
  cd wxGTK-2.8.10
  mkdir build_linux
  cd build_linux
  ../configure --with-opengl --enable-intl --enable-threads --enable-xpm
  make -j ${numthreads} install
  cd contrib/src/stc
  make -j ${numthreads} install
  cd ../../../../..
fi

# install recent cmake
if [ \! -f cmake-2.8.2-Linux-i386.tar.gz ];
then
  apt-get install wget
  wget http://www.cmake.org/files/v2.8/cmake-2.8.2-Linux-i386.tar.gz
  tar zxf cmake-2.8.2-Linux-i386.tar.gz
fi

cmake_bin=`pwd`/cmake-2.8.2-Linux-i386/bin/cmake
cpack_bin=`pwd`/cmake-2.8.2-Linux-i386/bin/cpack

svn co  https://amilab.svn.sourceforge.net/svnroot/amilab/tags/${releasetag} amilab_stable
cd amilab_stable
maindir=`pwd`

# Compile and install libAMIFluid
echo "Compiling and installing libAMIFluid"
cd ${maindir}/libAMIFluid/src
mkdir build; cd build; mkdir release; cd release
${cmake_bin} ../..
make -j ${numthreads} install

# Copy libAMIOpticalFlow
echo "Copying libAMIOpticalFlow"
cd ${maindir}
cp -R libAMIOpticalFlow/include/OpticalFlow /usr/local/include/

# Compile amilab
echo "Compiling amilab"
cd ${maindir}/src
mkdir build; mkdir build/release; cd build/release
${cmake_bin} -DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF -DwxWidgets_CONFIG_EXECUTABLE=/usr/local/bin/wx-config ../..
make -j ${numthreads} 

# Compile documentation, but missing improcess_html 
cd ${maindir}/doc
./generate_html.py all

# create and install ubuntu package ?
cd ${maindir}/src/build/release
${cpack_bin} -G DEB .
# does not work ...
#dpkg -i AMILab-3.0.0-Linux.`uname -m`.deb
make install

