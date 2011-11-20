#!/usr/bin/python2.7

# first, try to know the system: Linux, MacOS, Windows ...
# get some options about the branch to download etc ...

import platform
import sys
import os
import config

initdir=os.getcwd()


conf_platform = 'config_{0}'.format(platform.system())
conf_platform = conf_platform.replace('.','_')
conf_platform = conf_platform.strip()

system_name=platform.system().strip()

# Create the system configuration filename

# ---Linux Systems---
if conf_platform =='config_Linux':
  linuxdist= platform.linux_distribution()
  conf_dist     = 'config_{0}_{1}'.format(system_name,linuxdist[0].strip())
  conf_distnum  = 'config_{0}_{1}_{2}'.format(system_name,linuxdist[0].strip(),linuxdist[1].strip())
  #from gi.repository import PackageKitGlib as packagekit
  import packagekit_wrapper
  import dbus

#---Windows Systems---
if conf_platform =='config_Windows':
  winver = platform.win32_ver()
  conf_dist     = 'config_{0}_{1}'.format(system_name,winver[0])
  conf_distnum  = 'config_{0}_{1}_{2}'.format(system_name,winver[0],winver[1])
  # set 32 or 64bits info?
 
#---Darwin Systems---
 
conf_dist     = conf_dist    .replace('.','_')
conf_dist     = conf_dist.strip()
conf_distnum  = conf_distnum .replace('.','_')
conf_distnum  = conf_distnum.strip()
print "Configuration filenames are {0}, {1}, {2} ".format(conf_platform, conf_dist, conf_distnum)


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
        

#------------------------------------------------------------------------
def installer_install_Linux_openSUSE(packages):
  for pkg in packages.split():
    os.system('sudo zypper -n install {0}'.format(pkg))

def installer_install_Linux_debian(packages):
  pkg_list = ''
  for pkg in packages.split():
    pkg_list += ' '+pkg
  os.system('su -c "apt-get -y install {0}"'.format(pkg_list))

def installer_install_Linux(packages):
  # packagekit not working in opensuse: getting stuck ...
  print "'{0}'".format(conf_dist)
  if conf_dist=='config_Linux_openSUSE':
    installer_install_Linux_openSUSE(packages)
  else:
    if  conf_dist    == 'config_Linux_debian' and \
        conf_distnum != 'config_Linux_debian_wheezy/sid':
      installer_install_Linux_debian(packages)
    else:
      pk = packagekit_wrapper.PackageKitClient()
      for pkg in packages.split():
        print "  '{0}'".format(pkg)
        res = pk.Resolve('none',[pkg])
        print "  resolved"
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
      pk.SuggestDaemonQuit()


#------------------------------------------------------------------------
def installer_install_Windows(packages):
  for pkg in packages.split():
    installer=os.getcwd()+"/{0}_WININSTALL.py".format(pkg)
    if os.access(installer, os.R_OK):
      #print os.getcwd()
      print "running python "+installer
      #os.system("python "+installer)
      execfile(installer)
    else:
      print "ERROR: No Windows installer for {0}".format(pkg)

#------------------------------------------------------------------------
def installer_install_Darwin(packages):
  for pkg in packages.split():
    installer=os.getcwd()+"/{0}_MACINSTALL.py".format(pkg)
    if os.access(installer, os.R_OK):
      #print os.getcwd()
      print "running python "+installer
      #os.system("python "+installer)
      execfile(installer)
    else:
      print "ERROR: No Windows installer for {0}".format(pkg)

#------------------------------------------------------------------------
def installer_install(packages):
  if conf_platform=='config_Linux':
    installer_install_Linux(packages)
  if conf_platform=='config_Windows':
    installer_install_Windows(packages)
  if conf_platform=='config_Darwin':
    installer_install_Darwin(packages)
    

#------------------------------------------------------------------------
def install_packages(pkgname):
  print "-------------------------"
  print "  Installation of {0}    ".format(pkgname)
  print "-------------------------"

  try:
    exec('packages=config.{0}_PACKAGES'.format(pkgname))
  except:
    print "ERROR: {0}_PACKAGES not defined".format(pkgname)
    return
  print "  packages are '{0}'".format(packages)

  if packages == "TOCOMPILE":
    print "Compiling {0} from source".format(pkgname)
    exec("import {0}_COMPILE".format(pkgname))
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
  
#----------------------------------------------------------------------
# main
#----------------------------------------------------------------------
if __name__ == '__main__':
  #
  # source different files
  if os.path.isfile(conf_platform+'.py'):
    print "importing {0}".format(conf_platform)
    exec("import {0}".format(conf_platform))
    exec("{0}.SetConfig()".format(conf_platform))
    #config.libmodule = wx_lib.config
    #print "reading {0}".format(conf_platform)
    #execfile(conf_platform)
    
  if os.path.isfile(conf_dist+'.py'):
    print "importing {0}".format(conf_dist)
    exec("import {0}".format(conf_dist))
    exec("{0}.SetConfig()".format(conf_dist))
    try:
      exec("{0}.PreInstall()".format(conf_dist))
    except:
      print "no pre-installation required for {0}".format(conf_dist)
    #print "reading {0}".format(conf_dist)
    #execfile(conf_dist)
    
  if os.path.isfile(conf_distnum+'.py'):
    print "importing {0}".format(conf_distnum)
    exec("import {0}".format(conf_distnum))
    exec("{0}.SetConfig()".format(conf_distnum))
    # try pre-installation commands
    try:
      exec("{0}.PreInstall()".format(conf_distnum))
    except:
      print "no pre-installation required for {0}".format(conf_distnum)
    #print "reading {0}".format(conf_distnum)
    #execfile(conf_distnum)

  #print config.INSTALLER_PACKAGES
  print "config.VTK_VERSION = ", config.VTK_VERSION


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

  #print config.INSTALLER_PACKAGES

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

  amilabpath='amilab_release_3.2.0'
  svn_co('https://amilab.svn.sourceforge.net/svnroot/amilab/branches/Release-3.2.0',amilabpath)

  import os
  import shutil

  #os.getcwd()
  installpath=os.environ['HOME']+'/usr/local'
  os.chdir(amilabpath)
  maindir=os.getcwd()

  cmake_module_path=''
  # fix FindBISON pb in spanish
  if os.access('/usr/share/cmake/Modules',os.R_OK):
    cmake_module_path='/usr/share/cmake/Modules'
  else:
    if os.access('/usr/share/cmake-2.8/Modules',os.R_OK):
      cmake_module_path='/usr/share/cmake-2.8/Modules'

  if cmake_module_path!='':
    print "***************"
    print " Fixing possible problem in FindBISON.cmake"
    cmd  = "sed 's/GNU Bison/GNU [bB]ison/g' {0}/FindBISON.cmake > /tmp/FindBISON.cmake".format(cmake_module_path)
    os.system(cmd)
    cmd = "sudo mv /tmp/FindBISON.cmake {0}".format(cmake_module_path)
    os.system(cmd)
    print "**************"


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

  # check for ITK_DIR
  print "looking for "+initdir+'/ITK_DIR'
  if os.access(initdir+'/ITK_DIR', os.R_OK):
    f = open(initdir+'/ITK_DIR')
    ITK_DIR=f.readline()
    f.close()
    config.AMILAB_CMAKE_FLAGS += ' -DITK_DIR="{0}"'.format(ITK_DIR)

  # check for VTK_DIR
  print "looking for "+initdir+'/VTK_DIR'
  if os.access(initdir+'/VTK_DIR', os.R_OK):
    f = open(initdir+'/VTK_DIR')
    VTK_DIR=f.readline()
    f.close()
    config.AMILAB_CMAKE_FLAGS += ' -DVTK_DIR="{0}"'.format(VTK_DIR)

  cmake_cmd = 'cmake ../.. {0} -DCMAKE_INSTALL_PREFIX="{1}"'.format(config.AMILAB_CMAKE_FLAGS,installpath)
  print "CMAKE CMD="+cmake_cmd
  cmake_return = os.system(cmake_cmd)
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
  
  os.chdir(initdir)

