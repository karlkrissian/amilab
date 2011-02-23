
INSTALLCMD="apt-get install"

INSTALLER_PACKAGES=""

COMPILATION_PACKAGES="build-essential subversion wget tar gawk"

CMAKE_PACKAGES="cmake cmake-curses-gui cmake-qt-gui"

VTKDEV_PACKAGES="libvtk5-dev"

WXWIDGETSDEV_PACKAGES="libwxgtk2.8-dev"

BOOSTDEV_PACKAGES="libboost-all-dev"

IMDEV_PACKAGES="libpng12-dev libtiff4-dev"

OTHERDEV_PACKAGES="libexpat1-dev  uuid-dev libgdcm2-dev"

COMPRESSDEV_PACKAGES="zlib1g-dev libbz2-dev"

BISONFLEX_PACKAGES="bison flex"

ITKDEV_PACKAGES="libinsighttoolkit3-dev"

# AMILab cmake configuration flags
AMILAB_CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF"
