#!/bin/bash

#
# Script for installing amilab from source on OpenSuse, tested on OpenSuse 11.3 32 bits
#
# the whole process may take more than 30 minutes depending on your computer
# need to be run as root precause of the packages to install

#
#
zypper install gcc gcc-c++ binutils make subversion
zypper install cmake cmake-gui

# if you have problems with missing packages, try to change the repository
# for example http://ubuntu.media.mit.edu/ubuntu worked

# no vtk here ...
#zypper install vtk-devel

zypper install  wxGTK-devel boost-devel zlib-devel libpng-devel libtiff-devel libexpat-devel libjpeg-devel libbz2-devel freeglut-devel
zypper install bison flex


# get number of threads
zypper install gawk
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

zypper install wget tar

# compilation of VTK
if [ \! -f vtk-5.4.2.tar.gz ];
then
  wget http://www.vtk.org/files/release/5.4/vtk-5.4.2.tar.gz
  tar zxf vtk-5.4.2.tar.gz
  cd VTK
  mkdir build_release
  cd build_release
  cmake  -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release -DAMI_USE_BZIP2=OFF ..
  make -j ${numthreads} install
  cd ../..
fi

# compilation of ITK
if [ \! -f InsightToolkit-3.20.0.tar.gz ];
then
  wget http://voxel.dl.sourceforge.net/sourceforge/itk/InsightToolkit-3.20.0.tar.gz
  tar zxf InsightToolkit-3.20.0.tar.gz
  cd InsightToolkit-3.20.0
  mkdir build_release
  cd build_release
  cmake  -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release ..
  make -j ${numthreads} install
  cd ../..
fi

svn co  https://amilab.svn.sourceforge.net/svnroot/amilab/trunk amilab_trunk


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
cmake -DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF ../..
make -j ${numthreads} 

# Compile documentation, but missing improcess_html 
cd ${maindir}/doc
./generate_html.py all

# create and install ubuntu package ?
cd ${maindir}/src/build/release
zypper install rpm-build
cpack -G RPM
mv AMILab-3.0.0-Linux.i686.rpm AMILab-3.0.0-opensuse11.3.i686.rpm
rpm -ivh AMILab-3.0.0-opensuse11.3.i686.rpm
