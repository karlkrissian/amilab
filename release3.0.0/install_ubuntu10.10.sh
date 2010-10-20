#!/bin/sh

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
apt-get install cmake cmake-curses-gui cmake-qt-gui

# if you have problems with missing packages, try to change the repository
# for example http://ubuntu.media.mit.edu/ubuntu worked
apt-get install libvtk5-dev 
apt-get install libinsighttoolkit3-dev libwxgtk2.8-dev libboost-all-dev zlib1g-dev libbz2-dev libpng12-dev libtiff4-dev libexpat1-dev  uuid-dev

apt-get install bison flex

apt-get install libgdcm2-dev

svn co  https://amilab.svn.sourceforge.net/svnroot/amilab/trunk amilab_trunk

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

cd amilab_trunk
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
cmake -D CMAKE_BUILD_TYPE=Release  -D AMI_USE_STATIC_LIBS=OFF ../..
make -j ${numthreads} 

# Compile documentation, but missing improcess_html 
cd ${maindir}/doc
./generate_html.py all

# create and install ubuntu package ?
cd ${maindir}/src/build/release
cpack -G DEB
dpkg -i AMILab-3.0.0-Linux.`uname -p`.deb
