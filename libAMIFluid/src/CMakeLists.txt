# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.
# Make sure the compiler can find include files from our Hello library.

cmake_minimum_required(VERSION 2.4)

project (libAMIFluid)

# CPack packaging configuration
INCLUDE(InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "AMIFluid library")
SET(CPACK_PACKAGE_VENDOR "AMI group, University of Las Palmas of Gran Canaria")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/Copyright.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "AMIFluid is a library for 2D/3D image processing created by the AMI Group, ULPGC, Spain")
# RPM configuration
SET(CPACK_RPM_PACKAGE_NAME "libAMIFluid")
SET(CPACK_RPM_PACKAGE_VENDOR "AMI group, ULPGC, Spain")
SET(CPACK_RPM_PACKAGE_GROUP "Development/Libraries")
SET(CPACK_RPM_PACKAGE_LICENSE "LGPL")
SET(CPACK_RPM_PACKAGE_REQUIRES "glibc-devel glibc-headers")

IF(WIN32 AND NOT UNIX)
  # There is a bug in NSI that does not handle full unix paths properly. Makec
  # sure there is at least one set of four (4) backlasshes.
  #SET(CPACK_PACKAGE_ICON "${CMake_SOURCE_DIR}/Utilities/Release\\\\InstallIcon.bmp")
  #SET(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\MyExecutable.exe")
  SET(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY} AMIFluid library")
  SET(CPACK_NSIS_HELP_LINK "http:\\\\\\\\http://ami.dis.ulpgc.es/")
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
SET(CPACK_GENERATOR "RPM;STGZ")
INCLUDE(CPack)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../../CMAKE)

FIND_PACKAGE( Pthreads)

INCLUDE (CheckIncludeFiles)
# usage: CHECK_INCLUDE_FILES (<header> <RESULT_VARIABLE> )

# check for malloc.h
CHECK_INCLUDE_FILES(malloc.h HAVE_MALLOC_H)
# create ami_config.h
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/ami_config.h.in ${CMAKE_CURRENT_BINARY_DIR}/ami_config.h)

include_directories (
  ${libAMIFluid_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  )

SET(libAMIFluid_SRCS
  ami.cpp
  ami_correlation2D.cpp
  ami_fft.cpp
  ami_lucas_kanade_2d_2o.cpp
  ami_utilities.cpp
  ami_chi2.cpp
  ami_image_file.cpp
  ami_optic_flow.cpp
  TIFF.cpp
  ami_utilities_3d.cpp
  ami_vorticity.cpp
  ami_optic_flow_pde_2d_t.cpp
  ami_optic_flow_pde_3d.cpp
  ami_3dflow_sphere.cpp
  ami_spline.cpp
  ami_correlation3D.cpp
)

add_library ( AMIFluid ${libAMIFluid_SRCS} )

FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
                "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
                ${CMAKE_CURRENT_BINARY_DIR}/ami_config.h)
INSTALL(FILES ${files} DESTINATION include/AMIFluid )


INSTALL(TARGETS AMIFluid
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

if(LIST_SOURCES)
  SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../../Karl/CMAKE)
  include(amilab_macros)

  InitPrintSources()
  PrintSources(libAMIFluid)
endif(LIST_SOURCES)

