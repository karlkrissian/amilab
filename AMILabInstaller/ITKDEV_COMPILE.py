
#
# this script is designed to run within the install_linux.py script
# but could run as standalone if all the necessary commands are available
#

# get number of threads
import cpuinfo
numthreads=len(cpuinfo.cpu.info)

import urllib2, urllib
urllib.urlretrieve("http://sourceforge.net/projects/itk/files/itk/3.20/InsightToolkit-3.20.1.tar.gz/download")

import tarfile
tar = tarfile.open("InsightToolkit-3.20.1.tar.gz")
tar.extractall()
tar.close()

import os
os.chdir("InsightToolkit-3.20.1")
os.mkdir("build_release")
os.chdir("build_release")

installpath=os.environ['HOME']+'/usr/local'

cmake_return = os.system('cmake .. -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release  -DCMAKE_INSTALL_PREFIX="{0}"'.format(AMILAB_CMAKE_FLAGS,installpath))

os.system('make -j {0} '.format(numthreads))
os.system("make install")
os.chdir("../..")

