#!/bin/bash

#
# this script is designed to run within the install_linux.sh script
# but could run as standalone if all the necessary commands are available
#

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

wget http://www.vtk.org/files/release/5.6/vtk-5.6.1.tar.gz
tar zxf vtk-5.6.1.tar.gz
cd VTK
mkdir build_release
cd build_release
cmake  -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release ..
make -j ${numthreads} install
cd ../..
