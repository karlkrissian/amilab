#!/bin/bash

#
# this script is designed to run within the install_linux.sh script
# but could run as standalone if all the necessary commands are available
#

SITE="http://prdownloads.sourceforge.net/wxwindows/"
FILE="wxGTK-2.8.11.tar.gz"
DIR="wxGTK-2.8.11"

${INSTALLCMD} ${WXWIDGETSDEV_PRECOMP}

# if not already downloaded, compile it
if [ \! -f $FILE ];
then
  wget ${SITE}${FILE}
  tar zxf $FILE
  cd $DIR
  mkdir build_linux
  cd build_linux
  ../configure --with-opengl --enable-intl --enable-threads --enable-xpm
  make -j ${numthreads} install
  cd contrib/src/stc
  make -j ${numthreads} install
  cd ../../../../..
fi
