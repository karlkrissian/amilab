
import config

def SetConfig():
  config.INSTALLCMD             = "yum install"
  config.INSTALLER_PACKAGES     = "yum-plugin-fastestmirror"
  config.COMPILATION_PACKAGES   = "gcc gcc-c++ binutils make subversion wget tar gawk"
  config.CMAKE_PACKAGES         = "cmake cmake-gui"
  config.VTKDEV_PACKAGES        = "vtk-devel"
  config.WXWIDGETSDEV_PACKAGES  = "wxGTK-devel"
  config.BOOSTDEV_PACKAGES      = "boost-devel"
  config.IMDEV_PACKAGES         = "libpng-devel libtiff-devel libjpeg-devel"
  config.OTHERDEV_PACKAGES      = "expat-devel"
  config.COMPRESSDEV_PACKAGES   = "zlib-devel bzip2-devel"
  config.BISONFLEX_PACKAGES     = "bison flex"
  config.ITKDEV_PACKAGES        = "TOCOMPILE"
  config.GCCXML_PACKAGES        = "gccxml"
  # AMILab cmake configuration flags
  config.AMILAB_CMAKE_FLAGS     = "-DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF"

