# The name of our project is "HELLO".  CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
project (AMILab)


MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

cmake_minimum_required(VERSION 2.6)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

SET(CMAKE_MODULE_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/../CMAKE ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules   )


#-----------------------------------------------------
# VERSION information
#-----------------------------------------------------

SET(AMILAB_VERSION_MAJOR "2")
SET(AMILAB_VERSION_MINOR "1")
SET(AMILAB_VERSION_PATCH "0")
SET(AMILAB_VERSION "${AMILAB_VERSION_MAJOR}.${AMILAB_VERSION_MINOR}.${AMILAB_VERSION_PATCH}")


#-----------------------------------------------------
# set packaging information
#-----------------------------------------------------
INCLUDE(InstallRequiredSystemLibraries)


#
# Common package configuration
#
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "AMILab image processing and visualization software")
SET(CPACK_PACKAGE_VENDOR "Karl Krissian, University of Las Palmas of Gran Canaria")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/Copyright.txt")
SET(CPACK_PACKAGE_VERSION ${AMILAB_VERSION})
SET(CPACK_PACKAGE_VERSION_MAJOR ${AMILAB_VERSION_MAJOR} )
SET(CPACK_PACKAGE_VERSION_MINOR ${AMILAB_VERSION_MINOR} )
SET(CPACK_PACKAGE_VERSION_PATCH ${AMILAB_VERSION_PATCH} )
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "AMILab is a software for 2D/3D image processing, including its own scripting language with wrapping possibilities")

SET(CPACK_SYSTEM_NAME "${CMAKE_SYSTEM_NAME}.${CMAKE_SYSTEM_PROCESSOR}")
SET(CPACK_TOPLEVEL_TAG ${CPACK_SYSTEM_NAME})

SET(CPACK_INSTALL_PREFIX "${CPACK_INSTALL_PREFIX}")
SET(CPACK_PACKAGE_RELOCATABLE "true")
#SET(CPACK_SET_DESTDIR "ON")
SET(CPACK_SET_DESTDIR "OFF")

#
# RPM configuration
#
SET(CPACK_RPM_PACKAGE_SUMMARY "AMILab image processing and visualization software")
SET(CPACK_RPM_PACKAGE_NAME "amilab")
SET(CPACK_RPM_PACKAGE_VERSION ${AMILAB_VERSION})
SET(CPACK_RPM_PACKAGE_RELEASE "fc11")
SET(CPACK_RPM_PACKAGE_LICENSE "LGPL")
SET(CPACK_RPM_PACKAGE_GROUP "Applications/Engineering")
SET(CPACK_RPM_PACKAGE_VENDOR "Karl Krissian, ULPGC")
SET(CPACK_RPM_PACKAGE_DESCRIPTION "Amilab is designed as a tool for research and prototyping, with its own scripting language.")
SET(CPACK_RPM_PACKAGE_REQUIRES "glibc wxGTK wxGTK-gl")
SET(CPACK_RPM_PACKAGE_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})

# this will make the package relocatable !!cd
SET(CPACK_RPM_SPEC_MORE_DEFINE "Prefix: /usr")

#
# DEB configuration
#


IF(UNIX)
  #
  # DEB configuration
  #
  # no i386 in debian, should use dpkg --print-architecture ??
  SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386" )
  SET(CPACK_DEBIAN_PACKAGE_MAINTAINER   "krissian@dis.ulpgc.es")
  
  # creating dependencies ...
  MESSAGE(" ${AMILAB_BIN}")
  if (EXISTS "${AMILAB_BIN}")
      EXECUTE_PROCESS( 
        COMMAND ${CMAKE_SOURCE_DIR}/../Releases/Debian/list_dependencies.sh  ${AMILAB_BIN} 
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        RESULT_VARIABLE amilab_dep_result 
        OUTPUT_VARIABLE amilab_dep_output
        ERROR_VARIABLE amilab_dep_error
      )
    
      MESSAGE ("Dependencies = [${amilab_dep_result}], [${amilab_dep_output}] , [${amilab_dep_error}]")
      SET(CPACK_DEBIAN_PACKAGE_DEPENDS "${amilab_dep_output}")
#      SET(CPACK_DEBIAN_PACKAGE_DEPENDS "lib64expat1, libbz2-1.0, libc6, libc6-amd64, libc6-i686, libexpat1, libgcc1, libgl1-mesa-glx, libglu1-mesa, libice6, libjpeg62, libpng12-0, libsm6, libstdc++6, libtiff4, libuuid1, libvtk5.2, libwxbase2.8-0, libwxgtk2.8-0, libx11-6, libxext6, zlib1g")
#    endif(objdump_prog)
  
  ENDIF(EXISTS "${AMILAB_BIN}")
ENDIF(UNIX)

#
# NSIS: not used at the moment
#
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
  #SET(CPACK_PACKAGE_INSTALL_DIRECTORY "/usr/local")
  SET(CPACK_SOURCE_STRIP_FILES "")
ENDIF(WIN32 AND NOT UNIX)
#SET(CPACK_PACKAGE_EXECUTABLES "MyExecutable" "My Executable")
#MESSAGE("CMake:Debug:  CPACK_PACKAGE_INSTALL_DIRECTORY         = ${CPACK_PACKAGE_INSTALL_DIRECTORY}")

#
# MacOS
#
# Bundle Configuration (still needs work ...),
# now compiling MacOS Package with "sudo cpack -G PackageMaker ."
#
#SET( CPACK_PACKAGE_FILE_NAME      )
SET( CPACK_PACKAGE_ICON            "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_logo_new_48x48_alpha.xpm")
SET( CPACK_BUNDLE_NAME             "AMLab-${AMILAB_VERSION}-Bundle")
SET( CPACK_BUNDLE_ICON             "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_logo_new_48x48_alpha.xpm")
SET( CPACK_BUNDLE_PLIST            "${CMAKE_CURRENT_SOURCE_DIR}/../Releases/MacOS/Info_${AMILAB_VERSION}.plist")
#SET( CPACK_BUNDLE_STARTUP_COMMAND )

#SET( CPACK_COMPONENTS_ALL applications scripts doc )

SET(CPACK_GENERATOR "RPM")
#SET(CPACK_GENERATOR "RPM;STGZ;DEB")
#SET(CPACK_SOURCE_GENERATOR "TGZ")
INCLUDE(CPack)

OPTION(AMI_USE_STATIC_LIBS "Look for static libraries" ON)

#MESSAGE( "CMAKE_SYSTEM = ${CMAKE_SYSTEM} ")

IF( AMI_USE_STATIC_LIBS )
   SET( _ami_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
   IF(WIN32)
     SET(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
   ELSE(WIN32)
     SET(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
   ENDIF(WIN32)
ENDIF( AMI_USE_STATIC_LIBS )


OPTION(AMI_CHECK_BRANCH "Look for the name of the SVN branch" ON)

IF(AMI_CHECK_BRANCH)
  FIND_PACKAGE(Subversion)

  IF(Subversion_FOUND)
    Subversion_WC_INFO(${CMAKE_SOURCE_DIR} SRCDIR)
    MESSAGE( " *** SUBVERSION INFO ***")
    MESSAGE( "SRCDIR_WC_URL = ${SRCDIR_WC_URL}")
    #MESSAGE( "SRCDIR_WC_ROOT = ${SRCDIR_WC_ROOT}")
    #MESSAGE( "SRCDIR_WC_REVISION = ${SRCDIR_WC_REVISION}")
  ENDIF(Subversion_FOUND)

  # Get the root dir through info XML
  EXECUTE_PROCESS(COMMAND ${Subversion_SVN_EXECUTABLE} info --xml ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE SRCDIR_WC_XML_INFO
    ERROR_VARIABLE Subversion_svn_info_error
    RESULT_VARIABLE Subversion_svn_info_result
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  IF(NOT ${Subversion_svn_info_result} EQUAL 0)
    MESSAGE(SEND_ERROR "Command \"${Subversion_SVN_EXECUTABLE} info --xml ${CMAKE_SOURCE_DIR}\" failed with output:\n${Subversion_svn_info_error}")
  ELSE(NOT ${Subversion_svn_info_result} EQUAL 0)

    STRING(REGEX REPLACE ".*<root>(.*)</root>.*"
      "\\1" SRCDIR_WC_XML_ROOT "${SRCDIR_WC_XML_INFO}")
    MESSAGE( "SRCDIR_WC_XML_ROOT = ${SRCDIR_WC_XML_ROOT}")
  ENDIF(NOT ${Subversion_svn_info_result} EQUAL 0)

  
  STRING(REGEX MATCH "^(.*\n)?${SRCDIR_WC_XML_ROOT}/trunk/src/.*"
    SRCDIR_WC_TRUNK  "${SRCDIR_WC_URL}")

  IF(NOT SRCDIR_WC_TRUNK)
    IF(SRCDIR_WC_XML_ROOT AND SRCDIR_WC_URL)
      SET(PATTERN "^(.*\n)?${SRCDIR_WC_XML_ROOT}([^\n]+).*")
      MESSAGE("PATTERN = ${PATTERN}")
      STRING(REGEX REPLACE "^(.*\n)?${SRCDIR_WC_XML_ROOT}/branches/(.+)/src.*"
        "\\2" SRCDIR_WC_BRANCH "${SRCDIR_WC_URL}")
      MESSAGE( "SRCDIR_WC_BRANCH = ${SRCDIR_WC_BRANCH} ")
    ENDIF(SRCDIR_WC_XML_ROOT AND SRCDIR_WC_URL)
  ENDIF(NOT SRCDIR_WC_TRUNK)
  
ENDIF(AMI_CHECK_BRANCH)


OPTION(AMI_USE_VTK "Use VTK: recommended" ON)

IF(AMI_USE_VTK)
  FIND_PACKAGE ( VTK )
ENDIF(AMI_USE_VTK)

OPTION(AMI_USE_ITK "Use ITK: recommended" ON)

IF(AMI_USE_ITK)
  FIND_PACKAGE ( ITK )
ENDIF(AMI_USE_ITK)

FIND_PACKAGE ( AMIFluid )
#FIND_PACKAGE ( wxParams )
FIND_PACKAGE ( OpticFlow )
#FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net xml qa xrc richtext media)
FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc )

# put OpenGL before VTK to find the correct library of the system
FIND_PACKAGE ( OpenGL )
FIND_PATH(GLEXT_INCLUDE_DIR GL/glext.h )

OPTION(Boost_USE_STATIC_LIBS "Use Boost static libraries" OFF)

SET(Boost_USE_MULTITHREAD OFF)
#MESSAGE(  CMAKE_HOST_SYSTEM_NAME=${CMAKE_HOST_SYSTEM_NAME} )
#MESSAGE(  CMAKE_HOST_SYSTEM=${CMAKE_HOST_SYSTEM} )

SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")


FIND_PACKAGE( Boost ${BOOST_RELEASE} COMPONENTS date_time filesystem  system iostreams  regex)
#SET(Boost_USE_STATIC_LIBS ON)

OPTION(AMI_USE_ZLIB "Use zlib" ON)

IF(AMI_USE_ZLIB)
  FIND_PACKAGE( ZLIB)
ENDIF(AMI_USE_ZLIB)

OPTION(AMI_USE_BZIP2 "Use BZip2" ON)

IF(AMI_USE_BZIP2)
  FIND_PACKAGE( BZip2)
ENDIF(AMI_USE_BZIP2)

IF(AMI_USE_OPENMP)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
ENDIF(AMI_USE_OPENMP)

FIND_PACKAGE( Pthreads)

OPTION(AMI_USE_FLEXBISON "Compile language using Flex and Bison" ON)
IF(AMI_USE_FLEXBISON)
  OPTION(AMI_BISON_DEBUG "Outputs debugging information of the parser" OFF)
ENDIF(AMI_USE_FLEXBISON)

IF(AMI_USE_OPENMP)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
ENDIF(AMI_USE_OPENMP)


IF(AMI_USE_FLEXBISON)
  FIND_PACKAGE(BISON)
  FIND_PACKAGE(FLEX)
ENDIF(AMI_USE_FLEXBISON)

OPTION(AMI_USE_FASTNLMEANS "Use Fast NLmeans implementation" OFF)

IF(AMI_USE_FASTNLMEANS)
  FIND_PACKAGE(NewNLMeans)
  MESSAGE("NewNLMeans_LIBRARY=${NewNLMeans_LIBRARY}")
ENDIF(AMI_USE_FASTNLMEANS)

OPTION(AMI_USE_OPENMP "Use OpenMP for multithreading and timing" OFF)

IF(AMI_USE_OPENMP)
  FIND_PACKAGE( OpenMP)
ENDIF(AMI_USE_OPENMP)

OPTION(AMI_USE_SSE "Use SSE CPU instructions set" OFF)

IF(AMI_USE_SSE)
  # add flag for mingw
    MESSAGE("${CMAKE_CXX_COMPILER}")
  IF(${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/i686-pc-mingw32-g++")
    MESSAGE("adding -msse for compiler")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse")
  ENDIF(${CMAKE_CXX_COMPILER} STREQUAL "/usr/bin/i686-pc-mingw32-g++")
ENDIF(AMI_USE_SSE)


 IF( AMI_USE_STATIC_LIBS )
   SET(CMAKE_FIND_LIBRARY_SUFFIXES ${_ami_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES})
 ENDIF( AMI_USE_STATIC_LIBS )



INCLUDE (CheckIncludeFiles)
# usage: CHECK_INCLUDE_FILES (<header> <RESULT_VARIABLE> )
CHECK_INCLUDE_FILES (malloc.h HAVE_MALLOC_H)


include_directories (
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
)


#SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMAKE)

SET(AMI_BUILD_TYPE ${CMAKE_BUILD_TYPE})

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/AMILabConfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/AMILabConfig.h)


include(amilab_macros)
InitPrintSources()

set(  wxParams_INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/../wxParams/src)

#MESSAGE(wxParams_INCLUDE_DIRS=${wxParams_INCLUDE_DIRS})
MESSAGE(FLEX_INCLUDE_DIR=${FLEX_INCLUDE_DIR})

include_directories (
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${wxParams_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${FLEX_INCLUDE_DIR}
)

#INCLUDE(${wxWidgets_USE_FILE})

# for compatibility with previous name
SET( AMILAB_SOURCE_DIR ${AMILab_SOURCE_DIR} )

add_subdirectory (Common)
add_subdirectory (Math)
#add_subdirectory (Zinrimage)
add_subdirectory (AMImage)
add_subdirectory (DistTransf)
add_subdirectory (Images)
add_subdirectory (Coordonnees)
add_subdirectory (Contours)
add_subdirectory (Vaisseaux)
add_subdirectory (Filtering)
add_subdirectory (Crest)
add_subdirectory (ImageTool)
add_subdirectory (Graphic)
add_subdirectory (../wxParams/src binary_dir )
add_subdirectory (OpenGL)
add_subdirectory (wxSamples/penguin)
add_subdirectory (wxStcFrame)
add_subdirectory (Voxels)
add_subdirectory (AMILab)

IF(AMI_USE_VTK)
  add_subdirectory (myVTK4)
ENDIF(AMI_USE_VTK)

add_subdirectory (Line)
add_subdirectory (SplineThevenaz)
#add_subdirectory (libamiFluid)
add_subdirectory (Graph)

#add_subdirectory (WrapITK)
add_subdirectory (Wrapping)

add_subdirectory (Language)

#IF(AMI_USE_FASTNLMEANS)
add_subdirectory (Algorithms)
#ENDIF(AMI_USE_FASTNLMEANS)

include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
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
  ${AMILAB_SOURCE_DIR}/Filtering
  ${AMILAB_SOURCE_DIR}/Line
  ${AMILAB_SOURCE_DIR}/SplineThevenaz
  ${AMILAB_SOURCE_DIR}/Contours
  ${AMILAB_SOURCE_DIR}/DistTransf
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapITK
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapImports
  ${AMILAB_SOURCE_DIR}/wxStcFrame
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILAB_BINARY_DIR}
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${OPTICFLOW_INCLUDE_DIR}
  ${AMILAB_SOURCE_DIR}/../wxParams/src
#  ${wxParams_INCLUDE_DIRS}
  )

IF(AMI_USE_VTK)
  include_directories (
    ${AMILAB_SOURCE_DIR}/myVTK4
  )
  INCLUDE( ${USE_VTK_FILE} )
ENDIF(AMI_USE_VTK)

INCLUDE(${wxWidgets_USE_FILE})
INCLUDE( ${USE_ITK_FILE} )
MESSAGE( "*** USE_ITK_FILE = ${USE_ITK_FILE}")



SET(amilab_bin_SRCS
  amilab.cpp
  myTreeCtrl.cpp
  MainFrame.cpp
)

SET(amilab_bin_HDRS
  guicon.h
  MainFrame.h
  myTreeCtrl.h
)

SET(amilab_bin_SRCS
     ${amilab_bin_SRCS}
     ${amilab_bin_HDRS}
)

if (WIN32)
SET(amilab_bin_SRCS
  ${amilab_bin_SRCS}
  guicon.cpp
)
endif (WIN32)

IF(CMAKE_BUILD_TYPE)
  string(TOLOWER amilab_${CPACK_PACKAGE_VERSION}_${CMAKE_BUILD_TYPE} AMILAB_BIN )
ELSE(CMAKE_BUILD_TYPE)
  string(TOLOWER amilab_${CPACK_PACKAGE_VERSION} AMILAB_BIN )
ENDIF(CMAKE_BUILD_TYPE)

include_directories (
  ${AMILAB_SOURCE_DIR}/Language
)

add_executable (${AMILAB_BIN} WIN32
  #MACOSX_BUNDLE
  ${amilab_bin_SRCS}
)


SET(amilab_ownlibs
  Language
  WrapImports
  WrapVTK
  WrapmyVTK
  WrapFilters
  WrapSystem
  WrapITK
  WrapAMIFluid
  WrapWII
  WrapInterface
  WrapBasicTypes
  WrapCommon
  WrapWxWidgets
  WrapIO
  AMILab
  AMImage
  Contours
  Coordinates
  Crest
#  DistTransf
  Algorithms
  Filtering
  ImageTool
  Images
  Line
  Math
  OpenGL
  Graphic
  wxParams
  SplineThevenaz
  Graph
  Vessels
  Common
  Voxels
# wrapped wxwidgets samples
  penguin
  wxStcFrame
)


IF(AMI_USE_VTK)
  SET(amilab_ownlibs
      ${amilab_ownlibs}
      myVTK4
  )
  SET(LINK_VTK
    vtkGraphics
    vtkImaging
    vtkIO
    vtkFiltering
    vtkCommon
    vtkNetCDF
  )
ELSE(AMI_USE_VTK)
  SET(LINK_VTK
  )
ENDIF(AMI_USE_VTK)


MESSAGE( "Boost_LIBRARIES=${Boost_LIBRARIES}" )

# conflict between freetype and vtkfreetype
TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
  ${amilab_ownlibs}
  ${LINK_VTK}
  ITKIO
  ITKAlgorithms
  itkvnl
  itkvnl_algo
  ${AMIFLUID_LIBRARIES}
#  ${wxParams_LIBRARIES}
  wxParams
  ${OPENGL_LIBRARIES}
  ${OPENGL_glu_LIBRARY}
  ${PTHREADS_LIBRARY}
  ${wxWidgets_LIBRARIES}
# should be included in wxWdigets_LIBRARIES already ...
#  ${WX_gl}
  ${Boost_LIBRARIES}
)

# is it needed or already included by boost?
IF(AMI_USE_ZLIB)
  # need it to compile on MacOS
  TARGET_LINK_LIBRARIES( ${AMILAB_BIN} ${ZLIB_LIBRARIES})
ENDIF(AMI_USE_ZLIB)

IF(AMI_USE_BZIP2)
  TARGET_LINK_LIBRARIES( ${AMILAB_BIN} ${BZIP2_LIBRARIES})
ENDIF(AMI_USE_BZIP2)

if (WIN32)
TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
  ole32
  oleaut32
  uuid
  winmm
)
endif (WIN32)


IF(MSVC)
  # NEED TO SPECIFY FOR EACH POSSIBLE CONFIGURATION
  set_target_properties( ${AMILAB_BIN} 
  PROPERTIES LINK_FLAGS_RELEASE "/NODEFAULTLIB:LIBCMT")
  set_target_properties( ${AMILAB_BIN} 
  PROPERTIES LINK_FLAGS_DEBUG "/NODEFAULTLIB:LIBCMTD")
ENDIF(MSVC)

IF(AMI_USE_FASTNLMEANS)
  TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
    ${NewNLMeans_LIBRARIES}
  )
ENDIF(AMI_USE_FASTNLMEANS)

IF(UNIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/")
ENDIF(UNIX)

#IF(APPLE)
#    MESSAGE("APPLE ...")
#  SET(CMAKE_INSTALL_PREFIX "/Applications/AMILab.app/")
#ENDIF(APPLE)

IF (APPLE)
  SET_TARGET_PROPERTIES( ${AMILAB_BIN}
      PROPERTIES
      MACOSX_BUNDLE_BUNDLE_NAME AMILab
      MACOSX_BUNDLE_ICON_FILE "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_logo_new_64x64_alpha.icns"
  )
ENDIF(APPLE)


INSTALL(TARGETS ${AMILAB_BIN}
  RUNTIME DESTINATION bin
#  COMPONENT applications
  BUNDLE DESTINATION /Applications
)



# Install the scripts
install(DIRECTORY ${AMILAB_SOURCE_DIR}/../scripts
        DESTINATION share/amilab-${AMILAB_VERSION}
#        COMPONENT scripts
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
        DESTINATION share/amilab-${AMILAB_VERSION}
#        COMPONENT doc
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

if (UNIX)
  # Install the documentation
  install(DIRECTORY ${AMILAB_SOURCE_DIR}/../Releases/Linux/share
          DESTINATION .
          FILES_MATCHING
            PATTERN "*.*"
          PATTERN ".svn" EXCLUDE
          PATTERN "*~" EXCLUDE
          PERMISSIONS OWNER_READ GROUP_READ
          )
endif(UNIX)



#Test for amilab.
INCLUDE(${PROJECT_SOURCE_DIR}/../CTEST/amilab_tests.cmake)

PrintSources(${AMILAB_BIN})
