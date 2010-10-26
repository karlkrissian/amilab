
INSTALLCMD="apt-get install"

INSTALLER_PACKAGES=""

COMPILATION_PACKAGES="build-essential subversion wget tar gawk"

CMAKE_PACKAGES="TOCOMPILE"

VTKDEV_PACKAGES="libvtk5-dev"

# packages needed for compilation
WXWIDGETSDEV_PRECOMP="libgtk2.0-dev"
WXWIDGETSDEV_PACKAGES="TOCOMPILE"

BOOSTDEV_PACKAGES="libboost1.35-dev"

IMDEV_PACKAGES="libpng12-dev libtiff4-dev"

OTHERDEV_PACKAGES="libexpat1-dev  uuid-dev"

COMPRESSDEV_PACKAGES="zlib1g-dev libbz2-dev"

BISONFLEX_PACKAGES="bison flex"

ITKDEV_PACKAGES="libinsighttoolkit3-dev"

# AMILab cmake configuration flags
AMILAB_CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF -DwxWidgets_CONFIG_EXECUTABLE=/usr/local/bin/wx-config"
