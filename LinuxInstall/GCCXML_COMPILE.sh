#!/bin/bash

#
# this script is designed to run within the install_linux.sh script
# but could run as standalone if all the necessary commands are available
#

#echo "PATH = ${PATH}"

${INSTALLCMD} ${GCCXML_PRECOMP}

# get number of threads
numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

echo "Enter empty password ..."
cvs -d :pserver:anoncvs@www.gccxml.org:/cvsroot/GCC_XML login
cvs -d :pserver:anoncvs@www.gccxml.org:/cvsroot/GCC_XML co gccxml

cd gccxml
mkdir build_release
cd build_release
cmake  -DCMAKE_BUILD_TYPE=Release ..
make -j ${numthreads} install
cd ../..
