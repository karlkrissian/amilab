#!/bin/bash

#
# this script is designed to run within the install_linux.sh script
# but could run as standalone if all the necessary commands are available
#

#echo "PATH = ${PATH}"

${INSTALLCMD} ${BOOSTDEV_PRECOMP}

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`


git clone http://git.gitorious.org/boost/cmake.git
cd cmake
git co cmake-1.41.0

mkdir build_release
cd build_release
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j ${numthreads} install
cd ../..
