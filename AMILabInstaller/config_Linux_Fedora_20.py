
import config

def SetConfig():
  config.PYSVN_PACKAGES         ="pysvn"
  # not sure what package creates the need for libxml2-devel 
  # python-devel probably needed due to system VTK libs
  config.OTHERDEV_PACKAGES      += " libxml2-devel python-devel"
  config.WXWIDGETSDEV_PACKAGES  = "wxGTK3-devel wxGTK3-gl gtk3-devel"


