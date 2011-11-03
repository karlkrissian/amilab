
#
# this script is designed to run within the install_linux.py script
# but could run as standalone if all the necessary commands are available
#

# get number of threads
import cpuinfo
import os

numthreads=len(cpuinfo.cpu.info)
initdir=os.getcwd()


vtksourcefile='vtk-5.6.1.tar.gz'
vtkurl='http://www.vtk.org/files/release/5.6/{0}'.format(vtksourcefile)
if not(os.access(vtksourcefile, os.R_OK)):
  import urllib2, urllib
  urllib.urlretrieve(vtkurl, vtksourcefile)

if not(os.access("VTK", os.R_OK)):
  print " Extracting the tar.gz file"
  import tarfile
  tar = tarfile.open("vtk-5.6.1.tar.gz")
  tar.extractall()
  tar.close()

import os
os.chdir("VTK")
compile_VTK=True
if os.access("build_release", os.R_OK):
  ans = raw_input("VTK seems to have been already compiled, recompile it? (Y for Yes): ")
  compile_VTK=(ans=='Y')
else:
  os.mkdir("build_release")
  
if compile_VTK:
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
  f = open(initdir+'/VTK_DIR', 'w')
  f.write('{0}'.format(os.getcwd()))
  f.close()

os.chdir(initdir)

