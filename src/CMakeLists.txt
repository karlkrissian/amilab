# The name of our project is "HELLO".  CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
project (AMILab)

cmake_minimum_required(VERSION 2.6)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules  ${CMAKE_CURRENT_SOURCE_DIR}/../CMAKE )


MESSAGE( "CMAKE_SYSYEM           = ${CMAKE_SYSTEM}")
MESSAGE( "CMAKE_SYSYEM_NAME      = ${CMAKE_SYSTEM_NAME}")
MESSAGE(" CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")

# set packaging information
INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "AMILab image processing and visualization software")
SET(CPACK_PACKAGE_VENDOR "Karl Krissian, University of Las Palmas of Gran Canaria")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/Copyright.txt")
SET(CPACK_PACKAGE_VERSION "2.0.3")
SET(CPACK_PACKAGE_VERSION_MAJOR "2")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "3")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "AMILab is a software for 2D/3D image processing, including its own scripting language with wrapping possibilities")

SET(CPACK_SYSTEM_NAME "${CMAKE_SYSTEM_NAME}.${CMAKE_SYSTEM_PROCESSOR}")
SET(CPACK_TOPLEVEL_TAG ${CPACK_SYSTEM_NAME})

SET(CPACK_SET_DESTDIR "ON")

# RPM configuration
SET(CPACK_RPM_PACKAGE_SUMMARY "AMILab image processing and visualization software")
SET(CPACK_RPM_PACKAGE_NAME "amilab")
SET(CPACK_RPM_PACKAGE_VERSION "2.0.3")
SET(CPACK_RPM_PACKAGE_RELEASE "fc10")
SET(CPACK_RPM_PACKAGE_LICENSE "LGPL")
SET(CPACK_RPM_PACKAGE_GROUP "Applications/Engineering")
SET(CPACK_RPM_PACKAGE_VENDOR "Karl Krissian, ULPGC")
SET(CPACK_RPM_PACKAGE_DESCRIPTION "Amilab is designed as a tool for research and prototyping, with its own scripting language.")
SET(CPACK_RPM_PACKAGE_REQUIRES "glibc wxGTK wxGTK-gl")
SET(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")

# DEB configuration
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER   "krissian@dis.ulpgc.es")


IF(WIN32 AND NOT UNIX)
  # There is a bug in NSI that does not handle full unix paths properly. Makec
  # sure there is at least one set of four (4) backlasshes.
  #SET(CPACK_PACKAGE_ICON "${CMake_SOURCE_DIR}/Utilities/Release\\\\InstallIcon.bmp")
  #SET(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\MyExecutable.exe")
  SET(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY} AMIOpticalFlow library")
  SET(CPACK_NSIS_HELP_LINK "http:\\\\\\\\http://amilab.sourceforge.net")
  #SET(CPACK_NSIS_URL_INFO_ABOUT "http:\\\\\\\\www.my-personal-home-page.com")
  #SET(CPACK_NSIS_CONTACT "lalvarez@dis.ulpgc.es")
  SET(CPACK_NSIS_MODIFY_PATH ON)
ELSE(WIN32 AND NOT UNIX)
  #SET(CPACK_STRIP_FILES "bin/MyExecutable")
  SET(CPACK_PACKAGE_INSTALL_DIRECTORY "/usr/local")
  SET(CPACK_SOURCE_STRIP_FILES "")
ENDIF(WIN32 AND NOT UNIX)
#SET(CPACK_PACKAGE_EXECUTABLES "MyExecutable" "My Executable")
#MESSAGE("CMake:Debug:  CPACK_PACKAGE_INSTALL_DIRECTORY         = ${CPACK_PACKAGE_INSTALL_DIRECTORY}")

SET(CPACK_GENERATOR "RPM")
#SET(CPACK_GENERATOR "RPM;STGZ;DEB")
#SET(CPACK_SOURCE_GENERATOR "TGZ")
INCLUDE(CPack)



FIND_PACKAGE ( VTK )
FIND_PACKAGE ( ITK )
FIND_PACKAGE ( AMIFluid )
#FIND_PACKAGE ( wxParams )
FIND_PACKAGE ( OpticFlow )
FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base )

# put OpenGL before VTK to find the correct library of the system
FIND_PACKAGE ( OpenGL )
FIND_PATH(GLEXT_INCLUDE_DIR GL/glext.h )

SET(Boost_USE_STATIC_LIBS   ON)
SET(Boost_USE_MULTITHREAD OFF)
#MESSAGE(  CMAKE_HOST_SYSTEM_NAME=${CMAKE_HOST_SYSTEM_NAME} )
#MESSAGE(  CMAKE_HOST_SYSTEM=${CMAKE_HOST_SYSTEM} )
FIND_PACKAGE( Boost  1.38 COMPONENTS date_time filesystem  system iostreams  regex)
#SET(Boost_USE_STATIC_LIBS ON)

FIND_PACKAGE( ZLIB)
FIND_PACKAGE( BZip2)

FIND_PACKAGE( Pthreads)

# if (WIN32)
#   FIND_PACKAGE(BISON)
#   #FIND_PACKAGE(FLEXold)
# else (WIN32)
  FIND_PACKAGE(BISON)
  FIND_PACKAGE(FLEX)
# endif (WIN32)

INCLUDE (CheckIncludeFiles)
# usage: CHECK_INCLUDE_FILES (<header> <RESULT_VARIABLE> )
CHECK_INCLUDE_FILES (malloc.h HAVE_MALLOC_H)


include_directories (
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
)


#     # and for each of your dependant executable/library targets:
#     TARGET_LINK_LIBRARIES(<YourTarget> ${wxWidgets_LIBRARIES})

# Recurse into the "Hello" and "Demo" subdirectories.  This does not actually
# cause another cmake executable to run.  The same process will walk through
# the project's entire directory structure.
#add_subdirectory (Hello)
#add_subdirectory (Demo)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMAKE)
include(amilab_macros)
InitPrintSources()

set(  wxParams_INCLUDE_DIRS 
    ${PROJECT_SOURCE_DIR}/../wxParams/src)

include_directories (
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${wxParams_INCLUDE_DIRS}
)

add_subdirectory (Common)
add_subdirectory (Math)
add_subdirectory (Zinrimage)
add_subdirectory (AMImage)
add_subdirectory (DistTransf)
add_subdirectory (Images)
add_subdirectory (Coordonnees)
add_subdirectory (Contours)
add_subdirectory (Vaisseaux)
add_subdirectory (Filtrage)
add_subdirectory (Crest)
add_subdirectory (ImageTool)
add_subdirectory (Graphic)
add_subdirectory (../wxParams/src binary_dir )
add_subdirectory (OpenGL)
add_subdirectory (penguin)
add_subdirectory (Voxels)
add_subdirectory (AMILab)
add_subdirectory (myVTK4)
add_subdirectory (Line)
add_subdirectory (SplineThevenaz)
#add_subdirectory (libamiFluid)
add_subdirectory (Graph)
add_subdirectory (WrapITK)
add_subdirectory (Language)



include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Zinrimage
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Voxels
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Graph
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Filtrage
  ${AMILAB_SOURCE_DIR}/Line
  ${AMILAB_SOURCE_DIR}/myVTK4
  ${AMILAB_SOURCE_DIR}/SplineThevenaz
  ${AMILAB_SOURCE_DIR}/Contours
  ${AMILAB_SOURCE_DIR}/DistTransf
  ${AMILAB_SOURCE_DIR}/WrapITK
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILAB_BINARY_DIR}
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${OPTICFLOW_INCLUDE_DIR}
  ${AMILAB_SOURCE_DIR}/../wxParams/src
#  ${wxParams_INCLUDE_DIRS}
  )

INCLUDE( ${USE_VTK_FILE} )
INCLUDE(${wxWidgets_USE_FILE})
INCLUDE( ${USE_ITK_FILE} )



SET(amilab_bin_SRCS
  amilab.cpp 
  MainFrame.cpp
)

if (WIN32)
SET(amilab_bin_SRCS
  ${amilab_bin_SRCS}
  guicon.cpp
)
endif (WIN32)

string(TOLOWER amilab_${CPACK_PACKAGE_VERSION}_${CMAKE_BUILD_TYPE} AMILAB_BIN )

add_executable (${AMILAB_BIN} WIN32
  ${amilab_bin_SRCS}
)


SET(amilab_ownlibs
  Language
  AMILab
  WrapITK
  AMImage
  Contours
  Coordinates
  Crest
#  DistTransf
  Filtering
  ImageTool
  Images
  Line
  Math
  OpenGL
  penguin
  Graphic
  wxParams
  SplineThevenaz
  Graph
  Vessels
  Common
  Voxels
  Zinrimage
  myVTK4
)


# conflict between freetype and vtkfreetype
TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
  ${amilab_ownlibs}
  vtkRendering
  vtkGraphics
  vtkImaging
  vtkIO
  vtkFiltering
  vtkCommon
  vtkNetCDF
  ITKIO
  itkvnl
  itkvnl_algo
  ${AMIFLUID_LIBRARIES}
#  ${wxParams_LIBRARIES}
  wxParams
  ${OPENGL_LIBRARIES}
  ${OPENGL_glu_LIBRARY}
  ${PTHREADS_LIBRARY}
  ${wxWidgets_LIBRARIES}
  ${WX_gl}
  ${Boost_LIBRARIES}
  ${ZLIB_LIBRARIES}
  ${BZIP2_LIBRARIES}
)

if (WIN32)
TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
  ole32
  oleaut32
  uuid
  winmm
)
endif (WIN32)

IF(UNIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(UNIX)

INSTALL(TARGETS ${AMILAB_BIN}
  RUNTIME DESTINATION bin
)

# Install the scripts
install(DIRECTORY ${AMILAB_SOURCE_DIR}/../scripts 
        DESTINATION share/amilab-${CPACK_PACKAGE_VERSION}
        FILES_MATCHING PATTERN "*.amil"
         PATTERN "*.sh"
         PATTERN "*.html"
        PATTERN ".svn" EXCLUDE
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
#"*.amil" -o -name  "*.sh" -o -name "*.html"
        )

# Install the documentation
install(DIRECTORY ${AMILAB_SOURCE_DIR}/../doc
        DESTINATION share/amilab-${CPACK_PACKAGE_VERSION}
        FILES_MATCHING 
          PATTERN "*.html"
          PATTERN "*.amih"
          PATTERN "*.gif"
          PATTERN "*.css"
          PATTERN "*.txt"
        PATTERN ".svn" EXCLUDE
        PERMISSIONS OWNER_WRITE OWNER_READ
                    GROUP_READ
        )


PrintSources(${AMILAB_BIN})
