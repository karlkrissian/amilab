
import config

def SetConfig():
  config.PYSVN_PACKAGES         ="pysvn"
  # not sure what package creates the need for libxml2-devel 
  config.OTHERDEV_PACKAGES      += " libxml2-devel"
