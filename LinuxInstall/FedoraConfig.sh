
INSTALLCMD="yum install"

INSTALLER_PACKAGES="yum-plugin-fastestmirror"

COMPILATION_PACKAGES="gcc gcc-c++ binutils make subversion wget tar gawk"

CMAKE_PACKAGES="cmake cmake-gui"

VTKDEV_PACKAGES="vtk-devel"

WXWIDGETSDEV_PACKAGES="wxGTK-devel"

BOOSTDEV_PACKAGES="boost-devel"

IMDEV_PACKAGES="libpng-devel libtiff-devel libjpeg-devel"

OTHERDEV_PACKAGES="expat-devel"

COMPRESSDEV_PACKAGES="zlib-devel bzip2-devel"

BISONFLEX_PACKAGES="bison flex"

ITKDEV_PACKAGES="TOCOMPILE"

# AMILab cmake configuration flags
AMILAB_CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Release  -DAMI_USE_STATIC_LIBS=OFF"
