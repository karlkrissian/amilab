import config
import os

def PreInstall():
  print "--------------------------------------"
  print " Installing packagekit"
  print "--------------------------------------"
  os.system("sudo zypper install packagekit")

def SetConfig():
  config.PYSVN_PACKAGES       = "pysvn"
  # not sure what package creates the need for libxml2-devel 
  config.OTHERDEV_PACKAGES      += " libxml2-devel"
  config.INSTALLCMD           = "zypper install"
  config.INSTALLER_PACKAGES   = "" 
