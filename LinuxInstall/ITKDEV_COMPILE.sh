#!/bin/bash

#
# this script is designed to run within the install_linux.sh script
# but could run as standalone if all the necessary commands are available
#

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

wget http://voxel.dl.sourceforge.net/sourceforge/itk/InsightToolkit-3.20.0.tar.gz
tar zxf InsightToolkit-3.20.0.tar.gz
cd InsightToolkit-3.20.0
mkdir build_release
cd build_release
cmake  -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release ..
make -j ${numthreads} install
cd ../..
