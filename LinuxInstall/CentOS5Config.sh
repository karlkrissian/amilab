
INSTALLCMD="yum install"

INSTALLER_PACKAGES=""

COMPILATION_PACKAGES="gcc gcc-c++ binutils make subversion wget tar gawk"

CMAKE_PACKAGES="TOCOMPILE"

VTKDEV_PRECOMP="libXt-devel"
VTKDEV_PACKAGES="TOCOMPILE"

# packages needed for compilation
WXWIDGETSDEV_PRECOMP="gtk2-devel freeglut-devel"
WXWIDGETSDEV_PACKAGES="TOCOMPILE"


BOOSTDEV_PRECOMP="git"
BOOSTDEV_PACKAGES="TOCOMPILE"

IMDEV_PACKAGES="libpng-devel libtiff-devel libjpeg-devel"

OTHERDEV_PACKAGES="expat-devel"

COMPRESSDEV_PACKAGES="zlib-devel bzip2-devel"

BISONFLEX_PACKAGES="bison flex"

ITKDEV_PACKAGES="TOCOMPILE"

# AMILab cmake configuration flags
AMILAB_CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF -DwxWidgets_CONFIG_EXECUTABLE=/usr/local/bin/wx-config -DBOOST_ROOT=/usr/local/include/boost-1.41.0 -DBOOST_LIBRARY_DIR=/usr/local/lib/boost-1.41.0"
