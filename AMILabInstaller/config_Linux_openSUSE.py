import config
import os

def PreInstall():
  print "--------------------------------------"
  print " Installing packagekit"
  print "--------------------------------------"
  os.system("sudo zypper install packagekit")
  os.system("sudo zypper install python-gobject-devel")
  os.system("sudo zypper install python-gobject2")

def SetConfig():
  config.PYSVN_PACKAGES       = "python-pysvn"
  # not sure what package creates the need for libxml2-devel 
  config.OTHERDEV_PACKAGES      += " libxml2-devel"
  config.INSTALLCMD           = "zypper install"
  config.INSTALLER_PACKAGES   = "" 
  config.COMPILATION_PACKAGES  = "gcc gcc-c++ binutils make subversion wget tar gawk Mesa-devel"
  config.VTKDEV_PACKAGES        = "TOCOMPILE"
  config.GCCXML_PACKAGES        = "TOCOMPILE"
  config.COMPRESSDEV_PACKAGES   = "zlib-devel libbz2-devel"