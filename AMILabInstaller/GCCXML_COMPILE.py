
#
# this script is designed to run within the install_linux.py script
# but could run as standalone if all the necessary commands are available
#

# get number of threads
import cpuinfo
import os
import install_amilab

numthreads=len(cpuinfo.cpu.info)
initdir=os.getcwd()

# first install cvs
install_amilab.install_packages('CVS')


download_GCCXML=True
if os.access("gccxml", os.R_OK):
  ans = raw_input("GCCXML seems to have been already downloaded, re-download it? (Y for Yes): ")
  download_GCCXML=(ans=='Y')

if download_GCCXML:
  print "---------------------------------------------------"
  print " GCCXML development source will be installed       "
  print " press ENTER when asked for password               "
  print "---------------------------------------------------"
  # then download source code
  os.system("cvs -d :pserver:anoncvs@www.gccxml.org:/cvsroot/GCC_XML login")
  os.system("cvs -d :pserver:anoncvs@www.gccxml.org:/cvsroot/GCC_XML co gccxml")

os.chdir("gccxml")

compile_GCCXML=True
if os.access("build_release", os.R_OK):
  ans = raw_input("GCCXML seems to have been already compiled, recompile it? (Y for Yes): ")
  compile_GCCXML=(ans=='Y')
else:
  os.mkdir("build_release")
  
if compile_GCCXML:
  os.chdir("build_release")
  #installpath=os.environ['HOME']+'/usr/local'
  cmake_return = os.system('cmake .. -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE=Release')
  ##-DCMAKE_INSTALL_PREFIX="{0}"'.format(installpath))
  os.system('make -j {0} '.format(numthreads))  
  ## no need for make install if we use the build directory to compile amilab
  print "-------------------------------"
  print " Installing as root: enter the root password"
  print "-------------------------------"
  os.system("su -c 'make install'")
  #
  # Write the installation dir in a files
  #f = open(initdir+'/GCCXML_DIR', 'w')
  #f.write('{0}'.format(os.getcwd()))
  #f.close()

os.chdir(initdir)

