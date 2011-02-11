
INSTALLCMD="yum install"

INSTALLER_PACKAGES=""

COMPILATION_PACKAGES="gcc gcc-c++ binutils make subversion wget tar gawk"

CMAKE_PACKAGES="TOCOMPILE"

VTKDEV_PACKAGES="TOCOMPILE"

# packages needed for compilation
WXWIDGETSDEV_PRECOMP="gtk2-devel"
WXWIDGETSDEV_PACKAGES="TOCOMPILE"

BOOSTDEV_PACKAGES="boost-devel"

IMDEV_PACKAGES="libpng-devel libtiff-devel libjpeg-devel"

OTHERDEV_PACKAGES="expat-devel"

COMPRESSDEV_PACKAGES="zlib-devel bzip2-devel"

BISONFLEX_PACKAGES="bison flex"

ITKDEV_PACKAGES="TOCOMPILE"

# AMILab cmake configuration flags
AMILAB_CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF -DwxWidgets_CONFIG_EXECUTABLE=/usr/local/bin/wx-config"
