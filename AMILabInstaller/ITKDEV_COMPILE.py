
#
# this script is designed to run within the install_linux.py script
# but could run as standalone if all the necessary commands are available
#

# get number of threads
import cpuinfo
import os

numthreads=len(cpuinfo.cpu.info)
initdir=os.getcwd()


#itksourcefile='InsightToolkit-3.20.1.tar.gz'
#itkurl='http://sourceforge.net/projects/itk/files/itk/3.20/{0}/download'.format(itksourcefile)
itksourcefile='InsightToolkit-4.0.0.tar.gz'
itkurl='http://sourceforge.net/projects/itk/files/itk/4.0/{0}/download'.format(itksourcefile)
if not(os.access(itksourcefile, os.R_OK)):
  import urllib2, urllib
  urllib.urlretrieve(itkurl, itksourcefile)

if not(os.access("InsightToolkit-4.0.0", os.R_OK)):
  print " Extracting the tar.gz file"
  import tarfile
  tar = tarfile.open("InsightToolkit-4.0.0.tar.gz")
  tar.extractall()
  tar.close()

import os
os.chdir("InsightToolkit-4.0.0")
compile_ITK=True
if os.access("build_release", os.R_OK):
  ans = raw_input("ITK seems to have been already compiled, recompile it? (Y for Yes): ")
  compile_ITK=(ans=='Y')
else:
  os.mkdir("build_release")
  
if compile_ITK:
  os.chdir("build_release")
  installpath=os.environ['HOME']+'/usr/local'
  cmake_return = os.system('cmake .. -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release')
  #-DCMAKE_INSTALL_PREFIX="{0}"'.format(installpath))
  os.system('make -j {0} '.format(numthreads))  
  # no need for make install if we use the build directory to compile amilab
  #print "-------------------------------"
  #print " Installing as root: enter the sudo password"
  #print "-------------------------------"
  #os.system("sudo make install")
  # Write the installation dir in a files
  f = open(initdir+'/ITK_DIR', 'w')
  f.write('{0}'.format(os.getcwd()))
  f.close()

os.chdir(initdir)

