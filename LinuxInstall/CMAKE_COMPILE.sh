#!/bin/bash

#
# this script is designed to run within the install_linux.sh script
# but could run as standalone if all the needed commands are available
#

SITE="http://www.cmake.org/files/v2.8/"
FILE="cmake-2.8.2-Linux-i386.tar.gz"

if [ ! -z "$CMAKE_PRECOMP" ];
then
  $INSTALLCMD $CMAKE_PRECOMP
fi

# if not already downloaded, install it
if [ \! -f $FILE ];
then
  wget ${SITE}${FILE}
  tar zxf $FILE -C /usr/local/ --strip-components 1
  #tar zxf $FILE
  #cp cmake-2.8.2-Linux-i386/bin/cmake /usr/local/bin/
  #cp cmake-2.8.2-Linux-i386/bin/cpack /usr/local/bin/
  # for the rest of the script, we need to use /usr/local/bin for cmake ??
  # or is it automatic ?
fi
