
# first, try to know the system: Linux, MacOS, Windows ...
# get some options about the branch to download etc ...

import platform
import dbus
import sys
import os
from gi.repository import PackageKitGlib as packagekit

import packagekit_wrapper

# Create the system configuration filename
if platform.system()=='Linux':
  linuxdist= platform.linux_distribution()
  conf_platform = 'config_{0}.py'.format(platform.system())
  conf_dist     = 'config_{0}_{1}.py'.format(platform.system(),linuxdist[0])
  conf_distnum  = 'config_{0}_{1}_{2}.py'.format(platform.system(),linuxdist[0],linuxdist[1])
  print "Configuration filename is {0}".format(conf_distnum)

# source different files
if os.path.isfile(conf_platform):
  print "reading {0}".format(conf_platform)
  execfile(conf_platform)
if os.path.isfile(conf_dist):
  print "reading {0}".format(conf_dist)
  execfile(conf_dist)
if os.path.isfile(conf_distnum):
  print "reading {0}".format(conf_distnum)
  execfile(conf_distnum)

print INSTALLER_PACKAGES

def InstallPackageDbus(pname):
  try:
      bus = dbus.SessionBus()
  except dbus.DBusException, e:
      print 'Unable to connect to dbus: %s' % str(e)
      sys.exit()
  try:
      proxy = bus.get_object('org.freedesktop.PackageKit', '/org/freedesktop/PackageKit')
      iface = dbus.Interface(proxy, 'org.freedesktop.PackageKit.Modify')
      iface.InstallPackageNames(pname)
  except dbus.DBusException, e:
      print 'Unable to use PackageKit: %s' % str(e)
    
def cb(status, pc, spc, el, rem, c):
  print 'install pkg: %s, %i%%, cancel allowed: %s' % (status, pc, str(c))
  return True # return False to cancel
        
def installer_install(packages):
  pk = packagekit_wrapper.PackageKitClient()
  for pkg in packages.split():
    print pkg
    res = pk.Resolve('none',[pkg])
    if res==[]:
      print "ERROR: Package {0} not found ...".format(pkg)
    else:
      print res[0][1]
      print "Installing {0}".format(res[0][1])
      pk.InstallPackages([res[0][1]],cb)
    #res = pk.SearchNames('none',packages.split())
    #print res
    #for n in range(len(res)/2):
    #  pkgs = [res[n*2]]
    #  print "Installing {0}".format(res[n*2])
    #  pk.InstallPackages(pkgs,cb)

#------------------------------------------------------------------------
def install_packages(pkgname):
  print "-------------------------"
  print "  Installation of {0}    ".format(pkgname)
  print "-------------------------"

  try:
    exec('packages={0}_PACKAGES'.format(pkgname))
  except:
    print "ERROR: {0}_PACKAGES not defined".format(pkgname)
    return
  print "  packages are '{0}'".format(packages)

  if packages == "TOCOMPILE":
    print "Compiling {0} from source".format(pkgname)
    system("{0}_COMPILE.py".format(pkgname))
    #if [ $? != 0 ]
      #print "Installation of $1 failed"
      #exit $?
  else:
    if packages != '':
      installer_install(packages)
      #if [ $? != 0 ]
        #print "Installation of $1 failed"
        #exit $?
  #fi
  
#
# selecting fastest mirror on ubuntu, check:
# http://www.ubuntugeek.com/how-to-select-fastest-mirror-in-ubuntu.html
#
install_packages("INSTALLER")

# Compilation packages
install_packages("COMPILATION")

# get number of threads
#numthreads=`awk '/model name/  {ORS=""; count++;  }  END {  print  count "\n" }' /proc/cpuinfo`

# CMake installation
install_packages("CMAKE")

# VTK
install_packages("VTKDEV")

# WXWIDGETS
install_packages("WXWIDGETSDEV")

# Boost
install_packages("BOOSTDEV")

# Image IO packages
install_packages("IMDEV")

# Compression packages
install_packages("COMPRESSDEV")

# Other packages
install_packages("OTHERDEV")

# Bison-Flex packages
install_packages("BISONFLEX")

# ITK packages
install_packages("ITKDEV")

# GCCXML package
install_packages("GCCXML")

#---------------------------------------------
# installing repository
#---------------------------------------------
# try to use pysvn here ...
# pysvn for fedora python-svn for ubuntu ...
install_packages("PYSVN")

#import sys
#import svn.client
import pysvn

def notify( event_dict ):
    return "notify"

def svn_co(url, path):
  #svn.client.checkout(None, None, url, path, -1, 1, None, pool)
  client = pysvn.Client()
  client.callback_notify = notify
  #check out the current version of the pysvn project
  print "Checking out url:'{0}' to path:'{1}', be patient ...".format(url,path)
  client.checkout(url, path)
  print "Done. :)"

amilabpath='amilab_trunk'
svn_co('https://amilab.svn.sourceforge.net/svnroot/amilab/trunk',amilabpath)

import os
import shutil

#os.getcwd()
installpath=os.environ['HOME']+'/usr/local'
os.chdir(amilabpath)
maindir=os.getcwd()

## Compile and install libAMIFluid
print "-------------------------------------"
print "  Compiling and installing libAMIFluid"
print "-------------------------------------"
os.chdir("libAMIFluid/src")
if not(os.access("build", os.R_OK)):
  os.mkdir("build")
os.chdir("build")
if not(os.access("release", os.R_OK)):
  os.mkdir("release")
os.chdir("release")
os.system('cmake ../.. -DCMAKE_INSTALL_PREFIX="{0}"'.format(installpath))

import cpuinfo
numthreads=len(cpuinfo.cpu.info)

os.system('make -j {0} '.format(numthreads))
os.system("make install")

# Copy libAMIOpticalFlow
print "-------------------------------------"
print "  Copying libAMIOpticalFlow"
print "-------------------------------------"
os.chdir(maindir)
if not(os.access("{0}/include/OpticalFlow".format(installpath), os.R_OK)):
  shutil.copytree("libAMIOpticalFlow/include/OpticalFlow","{0}/include/OpticalFlow".format(installpath))

# Compile amilab
print "-------------------------------------"
print "  Compiling amilab"
print "-------------------------------------"
os.chdir("{0}/src".format(maindir))
if not(os.access("build", os.R_OK)):
  os.mkdir("build")
os.chdir("build")
if not(os.access("release", os.R_OK)):
  os.mkdir("release")
os.chdir("release")

cmake_return = os.system('cmake ../.. {0} -DCMAKE_INSTALL_PREFIX="{1}"'.format(AMILAB_CMAKE_FLAGS,installpath))
#eval "cmake ${AMILAB_CMAKE_FLAGS} ../.."

if cmake_return != 0:
  print ""
  print "ERROR: --- cmake command failed ---"
  print ""
  sys.exit()

os.system('make -j {0} '.format(numthreads))

# Compile documentation, but missing improcess_html 
#cd ${maindir}/doc
#./generate_html.py all

## create and install ubuntu package ?
#cd ${maindir}/src/build/release
#${INSTALLCMD} rpm-build
#cpack -G RPM
#rpm -ivh AMILab-3.0.0-Linux.`uname -p`.rpm

os.chdir(maindir)