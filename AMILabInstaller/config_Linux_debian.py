import config
import os

def PreInstall():
  print "--------------------------------------"
  print " Installing packagekit"
  print "--------------------------------------"
  print " Enter root password:"
  #os.system('su -c "apt-get install packagekit"')
  print " Looking for the fastest mirror"
  os.system('su -c "apt-get install netselect-apt"')

def SetConfig():
  config.PYSVN_PACKAGES       = "pysvn"
  config.INSTALLCMD           = "apt-get install"
  config.INSTALLER_PACKAGES   = "" 
  config.COMPILATION_PACKAGES = " build-essential subversion wget tar gawk"
  config.CMAKE_PACKAGES       = "cmake cmake-curses-gui cmake-qt-gui"
  config.VTKDEV_PACKAGES      = "libvtk5-dev"
  # installing libgtk2.0-dev because of wxVTK class
  config.WXWIDGETSDEV_PACKAGES= "libwxgtk2.8-dev libgtk2.0-dev"
  config.BOOSTDEV_PACKAGES    = "libboost-all-dev"
  config.IMDEV_PACKAGES       = "libpng12-dev libtiff4-dev"
  config.OTHERDEV_PACKAGES    = "libexpat1-dev  uuid-dev libgdcm2-dev"
  config.COMPRESSDEV_PACKAGES = "zlib1g-dev libbz2-dev"
  config.BISONFLEX_PACKAGES   = "bison flex"
  config.ITKDEV_PACKAGES      = "TOCOMPILE"
  #config.ITKDEV_PACKAGES      = "libinsighttoolkit3-dev"
  # AMILab cmake configuration flags
  config.AMILAB_CMAKE_FLAGS   = "-DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF"
  config.PYSVN_PACKAGES       = "python-svn"
