#!/bin/sh

# check for proper number of command line arguments
ERROR_PAR=65

if [ $# -ne 0 ]
   then
      echo
      echo " Usage: "
      echo " $0 "
      echo
      exit $ERROR_PAR
fi


#
# Script for installing amilab from source on Ubuntu, tested on Ubuntu 10.10 32 bits
#
# the whole process may take more than 30 minutes depending on your computer
# need to be run as root precause of the packages to install

#
# selecting fastest mirror on ubuntu, check:
# http://www.ubuntugeek.com/how-to-select-fastest-mirror-in-ubuntu.html
#
sudo apt-get install -y build-essential subversion
sudo apt-get install -y cmake cmake-curses-gui cmake-qt-gui

# if you have problems with missing packages, try to change the repository
# for example http://ubuntu.media.mit.edu/ubuntu worked
sudo apt-get install -y libvtk7-dev 
sudo apt-get install -y libinsighttoolkit5-dev libwxgtk3.0-gtk3-dev libwxgtk-media3.0-gtk3-dev libwxgtk-webview3.0-gtk3-dev libboost-all-dev zlib1g-dev libbz2-dev libpng-dev libtiff-dev libexpat1-dev  uuid-dev

sudo apt-get install -y bison flex
sudo apt-get install -y libgdcm-dev
sudo apt-get install -y castxml
sudo apt-get install -y libomp-dev
sudo apt-get install -y python2

git clone  https://github.com/karlkrissian/amilab.git
cd amilab
maindir=`pwd`

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

# Compile and install libAMIFluid
echo "Compiling and installing libAMIFluid"
cd ${maindir}/libAMIFluid/src
mkdir build; cd build; mkdir release; cd release
cmake ../.. 
sudo make -j ${numthreads} install

# Copy libAMIOpticalFlow
echo "Copying libAMIOpticalFlow"
cd ${maindir}
sudo cp -R libAMIOpticalFlow/include/OpticalFlow /usr/local/include/

# Compile amilab
echo "Compiling amilab"
cd ${maindir}/src
mkdir build; mkdir build/release; cd build/release
cmake -D CMAKE_BUILD_TYPE=Release  -D AMI_USE_STATIC_LIBS=OFF -DAMI_CHECK_BRANCH=0 ../..
make -j ${numthreads} 

# Compile documentation, but missing improcess_html 
cd ${maindir}/doc
./generate_html.py all

# create and install ubuntu package ?
cd ${maindir}/src/build/release
cpack -G DEB
dpkg -i AMILab-3.0.0-Linux.`uname -p`.deb
