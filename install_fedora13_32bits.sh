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
yum install yum-plugin-fastestmirror
yum install gcc gcc-c++ binutils make subversion
yum install cmake cmake-gui

# if you have problems with missing packages, try to change the repository
# for example http://ubuntu.media.mit.edu/ubuntu worked
yum install vtk-devel
yum install  wxGTK-devel boost-devel zlib-devel bzip2-devel libpng-devel libtiff-devel expat-devel libjpeg-devel
yum install bison flex


# get number of threads
yum install gawk
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

# compilation of ITK
yum install wget tar
wget http://voxel.dl.sourceforge.net/sourceforge/itk/InsightToolkit-3.20.0.tar.gz
tar zxf InsightToolkit-3.20.0.tar.gz
cd InsightToolkit-3.20.0
mkdir build_release
cd build_release
cmake  -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release ..
make -j ${numthreads} install
cd ../..

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
yum install rpm-build
cpack -G RPM
rpm -ivh AMILab-3.0.0-Linux.i686.rpm
