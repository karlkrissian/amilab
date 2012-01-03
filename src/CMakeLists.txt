# The name of our project is "HELLO".  CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
project (AMILab)


MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

cmake_minimum_required(VERSION 2.6.4)

if(POLICY CMP0017) 
  cmake_policy(SET CMP0017 NEW)
endif(POLICY CMP0017)

SET(CMAKE_MODULE_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/../CMAKE ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules   )

#-------------------------------------------------------------
#  CONFIGURE OUTPUT DIRECTORIES FOR WINDOWS BECAUSE OF DLL
#-------------------------------------------------------------

IF (WIN32)
  # ---------- Setup output Directories -------------------------
  SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/Bin
    CACHE PATH
    "Single Directory for all Libraries"
  )

  # --------- Setup the Executable output Directory -------------
  SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/Bin
    CACHE PATH
    "Single Directory for all static libraries."
  )
ENDIF(WIN32)

# --------- Setup the Executable output Directory -------------
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${PROJECT_BINARY_DIR}
  CACHE PATH
  "Single Directory for all Executables."
)

#-----------------------------------------------------
# VERSION information
#-----------------------------------------------------

SET(AMILAB_VERSION_MAJOR "3")
SET(AMILAB_VERSION_MINOR "2")
SET(AMILAB_VERSION_PATCH "1")
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
SET(CPACK_RPM_PACKAGE_RELEASE "1")
SET(CPACK_RPM_PACKAGE_LICENSE "LGPL")
SET(CPACK_RPM_PACKAGE_GROUP "Applications/Engineering")
SET(CPACK_RPM_PACKAGE_VENDOR "Karl Krissian, ULPGC")
SET(CPACK_RPM_PACKAGE_DESCRIPTION "AMILab is a software for 2D/3D image processing, including its own scripting language with wrapping possibilities.")
SET(CPACK_RPM_PACKAGE_REQUIRES "glibc wxGTK wxGTK-gl")
SET(CPACK_RPM_PACKAGE_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})

# this will make the package relocatable !!cd
SET(CPACK_RPM_SPEC_MORE_DEFINE "Prefix: /usr")

# package architecture
# does this work??
MESSAGE("CMAKE_SYSTEM_PROCESSOR=${CMAKE_SYSTEM_PROCESSOR}")
IF(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
  SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE amd64)
  SET(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
ELSEIF(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "i686")
  SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE i386)
  SET(CPACK_RPM_PACKAGE_ARCHITECTURE "i386")
ENDIF(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")



# create AMILAB_BIN variable
# IF(CMAKE_BUILD_TYPE)
#   string(TOLOWER amilab_${CPACK_PACKAGE_VERSION}_${CMAKE_BUILD_TYPE} AMILAB_BIN )
# ELSE(CMAKE_BUILD_TYPE)
  string(TOLOWER amilab_${CPACK_PACKAGE_VERSION} AMILAB_BIN )
# ENDIF(CMAKE_BUILD_TYPE)
MESSAGE("AMILAB_BIN=${AMILAB_BIN}")


#
# DEB configuration
#


IF(UNIX)
  #
  # DEB configuration
  #
  # no i386 in debian, should use dpkg --print-architecture ??
#  SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386" )
  SET(CPACK_DEBIAN_PACKAGE_MAINTAINER   "krissian@dis.ulpgc.es")
  SET(CPACK_DEBIAN_PACKAGE_SECTION      "science")
  SET(CPACK_DEBIAN_PACKAGE_PRIORITY     "extra")
  # creating dependencies ...
  MESSAGE(" ${AMILAB_BIN}_release")
  if (EXISTS "${AMILAB_BIN}_release")
      EXECUTE_PROCESS( 
        COMMAND ${CMAKE_SOURCE_DIR}/../Releases/Debian/list_dependencies.sh  ${AMILAB_BIN}_release
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        RESULT_VARIABLE amilab_dep_result 
        OUTPUT_VARIABLE amilab_dep_output
        ERROR_VARIABLE amilab_dep_error
      )
    
      MESSAGE ("Dependencies = [${amilab_dep_result}], [${amilab_dep_output}] , [${amilab_dep_error}]")
      SET(CPACK_DEBIAN_PACKAGE_DEPENDS "${amilab_dep_output}")
#      SET(CPACK_DEBIAN_PACKAGE_DEPENDS "lib64expat1, libbz2-1.0, libc6, libc6-amd64, libc6-i686, libexpat1, libgcc1, libgl1-mesa-glx, libglu1-mesa, libice6, libjpeg62, libpng12-0, libsm6, libstdc++6, libtiff4, libuuid1, libvtk5.6, libwxbase2.8-0, libwxgtk2.8-0, libx11-6, libxext6, zlib1g")
#    endif(objdump_prog)
  
  ENDIF(EXISTS "${AMILAB_BIN}_release")
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
IF (APPLE)
  SET(CPACK_GENERATOR "Bundle")
  SET( CPACK_PACKAGE_FILE_NAME      )
#  SET( CPACK_PACKAGE_ICON            "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_logo_new_48x48_alpha.png")
#  SET( CPACK_BUNDLE_ICON             "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_logo_new_48x48_alpha.png")
#  SET( CPACK_BUNDLE_STARTUP_COMMAND )


  SET(CPACK_BUNDLE_ICON              "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_bundleicon.icns")
  SET( CPACK_BUNDLE_NAME             "AMILab_${AMILAB_VERSION}_release")
  SET( CPACK_BUNDLE_PLIST            "${CMAKE_SOURCE_DIR}/../Releases/MacOS/Info.plist")
  SET(CPACK_BUNDLE_STARTUP_COMMAND   "${CMAKE_SOURCE_DIR}/../Releases/MacOS/StartupCommand")
  SET(CPACK_PACKAGE_DESCRIPTIONG     "${CPACK_PACKAGE_DESCRIPTION_SUMMARY}")

  #Usamos el icono que hicimos para el disco
  SET(CPACK_PACKAGE_ICON    "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_volumeicon.icns")
  SET(CPACK_PACKAGE_NAME     "AMILabPackage")
  SET(CPACK_PACKAGE_VERSION  "1.0")

ENDIF(APPLE)


#IF(APPLE)
#  SET(CMAKE_BUNDLE_NAME "AMILab_${AMILAB_VERSION}")
#  SET(CMAKE_BUNDLE_LOCATION "${CMAKE_INSTALL_PREFIX}")
#  # make sure CMAKE_INSTALL_PREFIX ends in /
#  STRING(LENGTH "${CMAKE_INSTALL_PREFIX}" LEN)
#  MATH(EXPR LEN "${LEN} -1" )
#  STRING(SUBSTRING "${CMAKE_INSTALL_PREFIX}" ${LEN} 1 ENDCH)
#  IF(NOT "${ENDCH}" STREQUAL "/")
#  SET(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/")
#  ENDIF(NOT "${ENDCH}" STREQUAL "/")
#  SET(CMAKE_INSTALL_PREFIX  "${CMAKE_INSTALL_PREFIX}${CMAKE_BUNDLE_NAME}.app/Contents")
#ENDIF(APPLE)



#SET( CPACK_COMPONENTS_ALL applications scripts doc )

IF (UNIX AND NOT APPLE)
  SET(CPACK_GENERATOR "RPM")
  #SET(CPACK_GENERATOR "RPM;STGZ;DEB")
  #SET(CPACK_SOURCE_GENERATOR "TGZ")
ENDIF(UNIX AND NOT APPLE)

INCLUDE(CPack)


#-------------------------------------------------------------------------------
#  Configuration files
#-------------------------------------------------------------------------------

#
# Configuration of Linux Desktop
#
CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/Linux/share/applications/amilab.desktop.in
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/Linux/share/applications/amilab.desktop)

CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/Linux/share/menu/amilab.in
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/Linux/share/menu/amilab)

#
# Configuration for MacOS
#

CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/MacOS/Info.plist.in
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/MacOS/Info.plist)

CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/MacOS/StartupCommand.in
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/MacOS/StartupCommand)

#
# Configuration of Windows installation script (Inno)
#

CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/Windows/amilab_wininstall.iss.in
    ${CMAKE_CURRENT_SOURCE_DIR}/../Releases/Windows/amilab_wininstall.iss)

#
# Scripts dir configuration in the build directory
#

CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../Config/config.amil.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.amil)

#-------------------------------------------------------------------------------
#  End of Configuration files
#-------------------------------------------------------------------------------

OPTION(AMI_USE_STATIC_LIBS     "Look for static libraries" ON)
OPTION(AMI_USE_DOXYGEN         "Look for doxygen" OFF)
OPTION(AMI_USE_PRECOMP_HEADERS "Use precompiled headers when available" OFF)


set(CMAKE_XCODE_ATTRIBUTE_GCC_VERSION "4.2")

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

  
  STRING(REGEX MATCH "^(.*\n)?${SRCDIR_WC_XML_ROOT}/trunk/src.*"
    SRCDIR_WC_TRUNK  "${SRCDIR_WC_URL}")
  MESSAGE( "SRCDIR_WC_TRUNK = ${SRCDIR_WC_TRUNK}")

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

OPTION(AMI_ENABLE_WRAPPING "Enable Automatic Wrapping: need gccxml, python, ..." ON)

IF(AMI_ENABLE_WRAPPING)
  FIND_PACKAGE( GCCXML REQUIRED)
  FIND_PACKAGE( PythonInterp REQUIRED)
  OPTION(AMI_WRAP_WXWIDGETS "Enable Automatic Wrapping OF WXWIDGETS" ON)
  OPTION(AMI_WRAP_VTK       "Enable Automatic Wrapping OF VTK"       ON)
  OPTION(AMI_WRAP_ITK       "Enable Automatic Wrapping OF ITK"       ON)
  OPTION(AMI_WRAP_EXAMPLES  "Enable Automatic Wrapping OF EXAMPLES"  OFF)
  OPTION(AMI_WRAP_MICRONTRACKER "Enable Automatic Wrapping of MicronTracker library for stereo camera tracking" OFF)
  OPTION(AMI_WRAP_ULTRASOUND "Enable Automatic Wrapping of Ultrasound library for get ultrasound images" OFF)
ENDIF(AMI_ENABLE_WRAPPING)



OPTION(AMI_USE_VTK "Use VTK: recommended" ON)

IF(AMI_USE_VTK)
  FIND_PACKAGE ( VTK )

  IF(VTK_FOUND)
    SET(AMI_VTK_VERSION "${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}")
  ENDIF(VTK_FOUND)

  # Separe Mac generated files
  #IF (APPLE)
  #  SET(AMI_VTK_VERSION ${AMI_VTK_VERSION}/Mac)
  #ENDIF(APPLE)
  #MESSAGE("VTK version: ${AMI_VTK_VERSION}\n")

ENDIF(AMI_USE_VTK)


OPTION(AMI_USE_ITK "Use ITK: recommended" ON)

IF(AMI_USE_ITK)
  FIND_PACKAGE ( ITK )
  IF(ITK_FOUND)
    SET(AMI_ITK_VERSION "${ITK_VERSION_MAJOR}.${ITK_VERSION_MINOR}")
  ENDIF(ITK_FOUND)
ENDIF(AMI_USE_ITK)

FIND_PACKAGE ( AMIFluid )
#FIND_PACKAGE ( wxParams )
FIND_PACKAGE ( OpticFlow )
#FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net xml qa xrc richtext media)
FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net richtext)

OPTION(GENERATE_HTML_HELP "Generate HTML file help")

IF(NOT WIN32)
  SET(Need_Find_GTK FALSE)
  STRING(REGEX MATCH "__WXGTK__" FindGTKLib ${wxWidgets_DEFINITIONS})
  IF(FindGTKLib)
    SET(Need_Find_GTK TRUE)
  ENDIF(FindGTKLib)
ENDIF(NOT WIN32)

SET(AMI_WXWIDGETS_VERSION "AMI_WXWIDGETS_VERSION-NOTFOUND" )

#-------------------------------------------------------------------------------
#  Get the wxWidgets version.
#-------------------------------------------------------------------------------
IF(wxWidgets_FOUND)
  MESSAGE("\n*** wxWidgets VERSION ***")
  MESSAGE("wxWidgets include dirs: ${wxWidgets_INCLUDE_DIRS}")
  FIND_PATH(WX_VERSION_PATH NAMES wx/version.h
    PATHS
      ${wxWidgets_INCLUDE_DIRS}
    NO_DEFAULT_PATH
    DOC "path of file: wx/version.h")
  IF(WX_VERSION_PATH)
    MESSAGE("path of file \"wx/version.h\": ${WX_VERSION_PATH}")
    FILE(STRINGS "${WX_VERSION_PATH}/wx/version.h"
         FILE_WX_MAJOR_VERSION
         REGEX "^#define( +)wxM[AJ|IN].*OR_VERSION( +)[0-9]+")
    MESSAGE("File filtering: ${FILE_WX_MAJOR_VERSION}\n")
    LIST(GET FILE_WX_MAJOR_VERSION 0 MAJOR_VERSION)
    LIST(GET FILE_WX_MAJOR_VERSION -1 MINOR_VERSION)
    STRING(REGEX MATCH "[0-9]+" WX_MAJOR_VERSION ${MAJOR_VERSION})
    STRING(REGEX MATCH "[0-9]+" WX_MINOR_VERSION ${MINOR_VERSION})
    SET(AMI_WXWIDGETS_VERSION "${WX_MAJOR_VERSION}.${WX_MINOR_VERSION}")
    MESSAGE("wxWidgets version: ${AMI_WXWIDGETS_VERSION}\n")
  ELSE(WX_VERSION_PATH)
    MESSAGE("Error: \"wx/version.h\" file not found\n")
  ENDIF(WX_VERSION_PATH)
  SET(WX_VERSION_PATH "WX_VERSION_PATH-NOTFOUND" CACHE FILEPATH "Cleared." FORCE)
  MARK_AS_ADVANCED(WX_VERSION_PATH)
ENDIF(wxWidgets_FOUND)

# Separe Mac generated files
#IF(APPLE)
#  STRING(REGEX MATCH "WXMAC" ISMAC ${wxWidgets_CXX_FLAGS})
#  MESSAGE("\"${ISMAC}\"")
#  IF ( NOT ( ISMAC STREQUAL "" ) )
#    SET(AMI_WXWIDGETS_VERSION ${AMI_WXWIDGETS_VERSION}/Mac)
#  ENDIF( NOT ( ISMAC STREQUAL "" ) )
#  MESSAGE("AMI_WXWIDGETS_VERSION ${AMI_WXWIDGETS_VERSION}")
#ENDIF(APPLE)

# put OpenGL before VTK to find the correct library of the system
FIND_PACKAGE ( OpenGL )
FIND_PATH(GLEXT_INCLUDE_DIR GL/glext.h )

OPTION(Boost_USE_STATIC_LIBS "Use Boost static libraries" OFF)

SET(Boost_USE_MULTITHREAD OFF)
#MESSAGE(  CMAKE_HOST_SYSTEM_NAME=${CMAKE_HOST_SYSTEM_NAME} )
#MESSAGE(  CMAKE_HOST_SYSTEM=${CMAKE_HOST_SYSTEM} )

SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")
FIND_PACKAGE( Boost ${BOOST_RELEASE} REQUIRED COMPONENTS date_time filesystem  system iostreams  regex )
#graph)
#SET(Boost_USE_STATIC_LIBS ON)
MESSAGE( "Boost_LIBRARIES = ${Boost_LIBRARIES}")


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

OPTION(AMI_USE_PLUGINS "Use plugins implementations" OFF)

IF(AMI_USE_PLUGINS)
  OPTION(AMI_COMPILE_ABOUTPLUGIN "Compile plugin example" OFF)
  OPTION(AMI_COMPILE_WXMEDIACTRLPLUGIN "Compile wxMediaCtrl plugin" OFF)
ENDIF(AMI_USE_PLUGINS)

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




#SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMAKE)

SET(AMI_BUILD_TYPE ${CMAKE_BUILD_TYPE})

CONFIGURE_FILE( ${CMAKE_CURRENT_SOURCE_DIR}/AMILabConfig.h.in 
                ${CMAKE_CURRENT_BINARY_DIR}/AMILabConfig.h
              )

include(amilab_macros)

include(PCH_GCC4_v2)

InitPrintSources()

#-------------------------------------------------------------------------------
# Indepedent libraries and Plugins
set(  wxParams_INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/../wxParams/src)

# set(  SubPixel_INCLUDE_DIRS
#     ${PROJECT_SOURCE_DIR}/../Modules/SubPixel/src)

#-------------------------------------------------------------------------------

#MESSAGE(wxParams_INCLUDE_DIRS=${wxParams_INCLUDE_DIRS})
MESSAGE(FLEX_INCLUDE_DIR=${FLEX_INCLUDE_DIR})


include_directories (
  ${Boost_INCLUDE_DIR}
#  ${OPENGL_INCLUDE_DIR}
#  ${Boost_INCLUDE_DIR}
#  ${OPENGL_INCLUDE_DIR}
#  ${wxParams_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
#  ${FLEX_INCLUDE_DIR}
)

#INCLUDE(${wxWidgets_USE_FILE})

# for compatibility with previous name
SET( AMILAB_SOURCE_DIR ${AMILab_SOURCE_DIR} )

add_subdirectory (CommonBase)
add_subdirectory (Common)
#add_subdirectory (DistTransf)
add_subdirectory (Graphic)
add_subdirectory (../wxParams/src wxParams_build )
add_subdirectory (AMILab)

#for compile the plugins.
IF(AMI_USE_PLUGINS)
  IF(AMI_COMPILE_ABOUTPLUGIN)
    add_subdirectory (Plugins/AboutBox)
  ENDIF(AMI_COMPILE_ABOUTPLUGIN)

  IF(AMI_COMPILE_WXMEDIACTRLPLUGIN)
    add_subdirectory (Plugins/wxMediaCtrl)
  ENDIF(AMI_COMPILE_WXMEDIACTRLPLUGIN)
ENDIF(AMI_USE_PLUGINS)

#add_subdirectory (libamiFluid)

#add_subdirectory (WrapITK)
add_subdirectory (Wrapping)

add_subdirectory (LanguageBase)
add_subdirectory (Language)

#IF(AMI_USE_FASTNLMEANS)
add_subdirectory (Algorithms)
#ENDIF(AMI_USE_FASTNLMEANS)


#
# Automatically included plugins
#
add_subdirectory (../Modules/SubPixel/src SubPixel_build )


SET(AMILAB_INCLUDE_DIRS
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Plugins/
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILab_BINARY_DIR}
)


MESSAGE("AMILAB_INCLUDE_DIRS=${AMILAB_INCLUDE_DIRS}")
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/../CMAKE/AMILabConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/AMILabConfig.cmake)

include_directories (
  ${AMILAB_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${OPTICFLOW_INCLUDE_DIR}
  )

IF(AMI_USE_VTK)
  INCLUDE( ${USE_VTK_FILE} )
ENDIF(AMI_USE_VTK)

INCLUDE(${wxWidgets_USE_FILE})

INCLUDE( ${USE_ITK_FILE} )
MESSAGE( "*** USE_ITK_FILE = ${USE_ITK_FILE}")
# same 
#MESSAGE( "*** ITK_USE_FILE = ${ITK_USE_FILE}")

SET(amilab_bin_SRCS 
  myDataViewModels.cpp
  myDataViewCtrl.cpp
  amilab.cpp
  myTreeCtrl.cpp
  MainFrame.cpp
)

SET(amilab_bin_HDRS
  myDataViewNodes.h
  myDataViewModels.h
  myDataViewCtrl.h
  guicon.h
  MainFrame.h
  myTreeCtrl.h
)

SET(amilab_scripts_dir ../scripts/Common)

SET(amilab_bin_SRCS
  ${amilab_bin_SRCS}
  ${amilab_bin_HDRS}
  ${amilab_scripts_dir}
)

if (WIN32)
SET(amilab_bin_SRCS
  ${amilab_bin_SRCS}
  guicon.cpp
)
endif (WIN32)


include_directories (
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Language
)

#add_library( AMILab_lib ${amilab_bin_SRCS})
# target_link_libraries(AMILab_lib
#   Language
#   vtkIO 
#   vtkImaging
#   ITKIO
#   ${wxWidgets_LIBRARIES}
#   ${Boost_LIBRARIES}
# )


add_executable (${AMILAB_BIN} WIN32
  # MACOSX_BUNDLE
  ${amilab_bin_SRCS}
)


SET(amilab_ownlibs
  WrapImports
  WrapmyVTK
  WrapFilters
  WrapSystem
  WrapAMIFluid
#  WrapSurface
#  WrapDessinImage
#  WrapViewer3D
#  WrapGLTransfMatrix
  WrapInterface
  WrapWxWidgets
  WrapAlgorithms
  WrapLanguage
  WrapBasicTypes
  WrapCommon
  WrapIO
  WrapImage
  LanguageBase
  Language
  WrapVTK
  WrapWxVTK
  WrapWII
  WrapITK
  AMILab
  LanguageBase
  Language
  Algorithms
  Graphic
  wxParams
  Common
  CommonBase
# wrapped wxwidgets samples
  penguin
  wxStcFrame
  wxTreeListCtrl
  wxVTKSamples
  wxVTK
)

IF (AMI_WRAP_MICRONTRACKER)
  SET(amilab_ownlibs
    ${amilab_ownlibs}
    WrapMicronTracker
 )
ENDIF(AMI_WRAP_MICRONTRACKER)

IF (AMI_WRAP_ULTRASOUND)
  SET(amilab_ownlibs
    ${amilab_ownlibs}
    WrapUltrasound
 )
ENDIF(AMI_WRAP_ULTRASOUND)

# Test template class
IF(AMI_WRAP_EXAMPLES)
  SET(amilab_ownlibs WrapExamples ${amilab_ownlibs})
ENDIF(AMI_WRAP_EXAMPLES)

IF(AMI_USE_VTK)
  SET(amilab_ownlibs
      ${amilab_ownlibs}
      myVTK4
  )
  INCLUDE(${VTK_USE_FILE})

  SET(LINK_VTK
    vtkGraphics
    vtkImaging
    vtkIO
    vtkFiltering
    vtkCommon
    # additional libraries for volume rendering
    vtkRendering 
    vtkVolumeRendering 
    vtkWidgets
    vtkViews
    vtkCharts
  )

  # it seems that vtkNetCDF is not needed, at least on linux
  # TODO: check if we can really remove it
  IF(NOT UNIX)
    SET(LINK_VTK
      ${LINK_VTK}
      vtkNetCDF
    )
  ENDIF(NOT UNIX)
  MESSAGE("LINK_VTK=${LINK_VTK}")

ELSE(AMI_USE_VTK)
  SET(LINK_VTK
  )
ENDIF(AMI_USE_VTK)
#MESSAGE( " VTK_LIBRARY_DIRS = ${VTK_LIBRARY_DIRS}")

MESSAGE( "Boost_LIBRARIES=${Boost_LIBRARIES}" )

MESSAGE( "ITK_LIBRARIES=${ITK_LIBRARIES}")

IF( NOT DEFINED ITK_LIBRARIES )
  SET(ITK_LIBRARIES 
    ITKIO
    ITKAlgorithms
    itkvnl
    itkvnl_algo
  )
ENDIF( NOT DEFINED ITK_LIBRARIES )

MESSAGE( "ITK_LIBRARIES=${ITK_LIBRARIES}")

# conflict between freetype and vtkfreetype
TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
  ${amilab_ownlibs}
  ${LINK_VTK}
  ${AMIFLUID_LIBRARIES}
  ${ITK_LIBRARIES}
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

IF (AMI_WRAP_MICRONTRACKER)
  FIND_LIBRARY( MTC_LIB mtc PATHS "$ENV{ProgramFiles}/Claron Technology/MicronTracker/Dist")
  TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
    ${MTC_LIB}
  )
ENDIF(AMI_WRAP_MICRONTRACKER)

IF (AMI_WRAP_ULTRASOUND)
  FIND_LIBRARY( ULTRASOUND_LIB research PATHS "$ENV{ProgramFiles}/EcoResearch/Research_Package/lib")
  FIND_PATH( ULTRASOUND_DIR RPCore.h PATHS "$ENV{ProgramFiles}/EcoResearch/Research_Package/include")
 
  TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
    ${ULTRASOUND_LIB}
   # comctl32.lib
	 # wsock32.lib
	 # odbc32.lib
	 # odbccp32.lib 
  )
ENDIF(AMI_WRAP_ULTRASOUND)

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


SET(CMAKE_DEBUG_POSTFIX  _debug)
SET(CMAKE_RELEASE_POSTFIX _release)
SET(CMAKE_MINSIZEREL_POSTFIX _minsizerel)
SET(CMAKE_RELWITHDEBINFO_POSTFIX _relwithdebinfo)
  
SET_TARGET_PROPERTIES( ${AMILAB_BIN}
    PROPERTIES 
      DEBUG_POSTFIX           _debug
      RELEASE_POSTFIX         _release
      MINSIZEREL_POSTFIX      _minsizerel
      RELWITHDEBINFO_POSTFIX  _relwithdebinfo

      COMPILE_DEFINITIONS_DEBUG           "_CMAKEBUILDTYPE_DEBUG_"
      COMPILE_DEFINITIONS_RELEASE         "_CMAKEBUILDTYPE_RELEASE_"
      COMPILE_DEFINITIONS_MINSIZEREL      "_CMAKEBUILDTYPE_MINSIZEREL_"
      COMPILE_DEFINITIONS_RELWITHDEBINFO  "_CMAKEBUILDTYPE_RELWITHDEBINFO_"
)

IF(MSVC)
  # NEED TO SPECIFY FOR EACH POSSIBLE CONFIGURATION
  set_target_properties( ${AMILAB_BIN} 
    PROPERTIES LINK_FLAGS_RELEASE "/NODEFAULTLIB:LIBCMT /NODEFAULTLIB:LIBCMTD /NODEFAULTLIB:MSVCRTD /INCREMENTAL:NO")

  set_target_properties( ${AMILAB_BIN} 
    PROPERTIES LINK_FLAGS_DEBUG "/NODEFAULTLIB:LIBCMT /NODEFAULTLIB:LIBCMTD /INCREMENTAL:NO")

ENDIF(MSVC)

IF(AMI_USE_FASTNLMEANS)
  TARGET_LINK_LIBRARIES( ${AMILAB_BIN}
    ${NewNLMeans_LIBRARIES}
  )
ENDIF(AMI_USE_FASTNLMEANS)

#IF(UNIX)
#  SET(CMAKE_INSTALL_PREFIX "/usr/")
#ENDIF(UNIX)

#IF(APPLE)
#    MESSAGE("APPLE ...")
#  SET(CMAKE_INSTALL_PREFIX "/Applications/AMILab.app/")
#ENDIF(APPLE)


#IF(APPLE)
#   SET_TARGET_PROPERTIES(${AMILAB_BIN} PROPERTIES
#     OUTPUT_NAME ${CPACK_BUNDLE_NAME})
#ENDIF(APPLE)

#SET(CMAKE_INSTALL_DESTINATION_ARGS  BUNDLE DESTINATION "${CMAKE_BUNDLE_LOCATION}")


#IF (APPLE)
#   SET(amilab_bin_SRCS ${amilab_bin_SRCS} CMakeSetup.icns)
#   SET(MACOSX_BUNDLE_ICON_FILE "${CMAKE_SOURCE_DIR}/../Pixmaps/amilab_logo_new_64x64_alpha.icns")
#   SET_SOURCE_FILES_PROPERTIES(CMakeSetup.icns PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

#  SET_TARGET_PROPERTIES( ${AMILAB_BIN}
#      PROPERTIES
#      MACOSX_BUNDLE_BUNDLE_NAME AMILab
#      MACOSX_BUNDLE_ICON_FILE 
#  )
#ENDIF(APPLE)

# -------------------------------------
#   Find library in MacOS package
# -------------------------------------
IF(APPLE)
    SET(CMAKE_INSTALL_NAME_DIR @executable_path/../lib/amilab-${AMILAB_VERSION} CACHE STRING "Executable Path for MacOS X" FORCE)
    MARK_AS_ADVANCED(CMAKE_INSTALL_NAME_DIR)
ENDIF(APPLE)



INSTALL(TARGETS ${AMILAB_BIN}
  RUNTIME DESTINATION bin
  #  COMPONENT applications
  #  BUNDLE DESTINATION 
  #${CMAKE_INSTALL_DESTINATION_ARGS}
)


# Install the scripts
install(DIRECTORY ${AMILAB_SOURCE_DIR}/../scripts
        DESTINATION share/amilab-${AMILAB_VERSION}
#        COMPONENT scripts
        FILES_MATCHING 
          PATTERN "*.amil"
          PATTERN "*.sh"
          PATTERN "*.py"
          PATTERN "*.png"         
          PATTERN "*.txt"
          PATTERN "*.sh"
          PATTERN "*.html"
          # exclude
          PATTERN ".svn" EXCLUDE
          PATTERN "*.in"  EXCLUDE
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
                    WORLD_READ
        )

install(FILES ${AMILAB_SOURCE_DIR}/../Modules/Add2Menu.amil
        DESTINATION share/amilab-${AMILAB_VERSION}/Modules/
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
                    WORLD_READ
        )

# Install the Matlab utilities
install(DIRECTORY ${AMILAB_SOURCE_DIR}/../MatlabUtils
        DESTINATION share/amilab-${AMILAB_VERSION}
        FILES_MATCHING PATTERN "*.m" PATTERN "*.amil"
          PATTERN "*.sh"
          PATTERN "*.py"
          PATTERN "*.png"         
          PATTERN "*.txt"
          PATTERN "*.sh"
          PATTERN "*.html"
          # exclude
          PATTERN ".svn" EXCLUDE
          PATTERN "*.in"  EXCLUDE
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
                    WORLD_READ
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
          # exclude
          PATTERN ".svn" EXCLUDE
          PATTERN "*.in"  EXCLUDE
        PERMISSIONS 
          OWNER_WRITE 
          OWNER_READ
          GROUP_READ
          WORLD_READ
        )

if (UNIX)
  # Install the documentation
  install(DIRECTORY ${AMILAB_SOURCE_DIR}/../Releases/Linux/share
          DESTINATION .
          FILES_MATCHING
            PATTERN "*"
            # exclude
            PATTERN "*.in"  EXCLUDE
            PATTERN ".svn" EXCLUDE
            PATTERN "*~"   EXCLUDE
          PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
          )
endif(UNIX)



#Test for amilab.
INCLUDE(${PROJECT_SOURCE_DIR}/../CTEST/amilab_tests.cmake)


if (GENERATE_HTML_HELP)
  # check if doxygen is even installed
  find_package(Doxygen)
  if (DOXYGEN_FOUND STREQUAL "NO")
    message(FATAL_ERROR "Doxygen not found. Please get a copy http://www.doxygen.org")
  endif (DOXYGEN_FOUND STREQUAL "NO")

  # prepare doxygen configuration file
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../Doxygen/doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

  # add doxygen as target
  add_custom_target(doxygen ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

  # cleanup $build/api-doc on "make clean"
  set_property(DIRECTORY APPEND PROPERTY
       ADDITIONAL_MAKE_CLEAN_FILES api-doc)

  # add doxygen as dependency to doc-target
  get_target_property(DOC_TARGET doc TYPE)
  if(NOT DOC_TARGET)
    add_custom_target(doc)
  endif()
  add_dependencies(doc doxygen)

  # install HTML API documentation and manual pages
  set(DOC_PATH "share/amilab-${AMILAB_VERSION}")

  install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/html
           DESTINATION ${DOC_PATH}
         )

  # install man pages into packages, scope is now project root..
  install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/man/man3
         DESTINATION share/man/man3/
       )
endif (GENERATE_HTML_HELP)

PrintSources(${AMILAB_BIN})
