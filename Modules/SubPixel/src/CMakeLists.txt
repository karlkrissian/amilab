#==============================================================================
# SubPixel
#
# Description: SubPixel module
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

project (SubPixel)

SET(KIT ${CMAKE_PROJECT_NAME})

IF(POLICY CMP0017) 
  CMAKE_POLICY(SET CMP0017 NEW)
ENDIF(POLICY CMP0017)

SET(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/../../../CMAKE  ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules   )

MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4)

# should get everything from amilab configuration but ok for the moment
FIND_PACKAGE( ITK )
MESSAGE( "ITK_FOUND=${ITK_FOUND}")
IF(ITK_FOUND)
  MESSAGE("ITK_USE_FILE=${ITK_USE_FILE}")
  INCLUDE(${ITK_USE_FILE})
ENDIF(ITK_FOUND)

# need to find VTK first ...
FIND_PACKAGE( VTK )


OPTION(ENABLE_WRAPPING    "ENABLE MODULE WRAPPING"  ON )
OPTION(NEED_VTK_WRAPPING  "NEED VTK WRAPPING"       ON )
OPTION(GENERATE_HTML_HELP "Generate HTML file help" OFF)




FIND_PACKAGE( wxWidgets COMPONENTS adv html aui  gl core base stc net richtext)

OPTION(NEED_WX_WRAPPING "NEED WXWIDGETS WRAPPING" ON)

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


FIND_PACKAGE(AMILab)

INCLUDE(${AMILAB_BINARY_DIR}/AMILabConfig.cmake)
INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amilab_macros.cmake)

set(  wxParams_INCLUDE_DIRS
    ${AMILAB_SOURCE_DIR}/../wxParams/src)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}
                    ${PROJECT_SOURCE_DIR}/Wrapping
                    ${PROJECT_SOURCE_DIR}/Wrapping/Generated
                    ${AMILab_PATHS}
                    ${AMILAB_SOURCE_DIR}/Algorithms/include
                    ${AMILAB_SOURCE_DIR}/Graphic/include
                    ${wxParams_INCLUDE_DIRS}
 )

OPTION(Boost_USE_STATIC_LIBS "Use Boost static libraries" ON)
SET(Boost_USE_MULTITHREAD OFF)
SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")
FIND_PACKAGE( Boost ${BOOST_RELEASE} COMPONENTS date_time filesystem  system iostreams  regex)
FIND_PACKAGE( ZLIB)
FIND_PACKAGE( BZip2)



IF(ENABLE_WRAPPING)
  IF(VTK_FOUND)
    SET(AMI_VTK_VERSION "${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}")
  ENDIF(VTK_FOUND)

  # allow use of vtk classes  wrapped within AMILab
  FILE(READ "${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated/ancestors.txt" vtk_ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" vtk_ancestors_list ${vtk_ancestors_txt} )
  SET(AVAILABLE_EXTERNAL_CLASSES ${vtk_ancestors_list})
  MESSAGE("AVAILABLE_EXTERNAL_CLASSES=${AVAILABLE_EXTERNAL_CLASSES}")
  #          --available_external_classes ${vtk_ancestors_list}
  # plus find wrapvtk library and link with it ...

  INCLUDE(${PROJECT_SOURCE_DIR}/../../../CMAKE/PluginWrapping.cmake)
ENDIF(ENABLE_WRAPPING)

SET(${KIT}_HDRS
  ${${KIT}_HDRS}
  AnalyticCircle.h
  AnalyticCube.h
  AnalyticCylinder.h
  AnalyticFunctionBase.h
  AnalyticLine.h
  AnalyticPlane.h
  AnalyticRing2D.h
  AnalyticSphere.h
  AnalyticStraightVessel2D.h
  AnalyticTorus.h
  SubPixel2D.h
  SubVoxel3D.h
  Wrapping/wrap_AnalyticCircle.h
  Wrapping/wrap_AnalyticCube.h
  Wrapping/wrap_AnalyticCylinder.h
  Wrapping/wrap_AnalyticFunctionBase.h
  Wrapping/wrap_AnalyticLine.h
  Wrapping/wrap_AnalyticPlane.h
  Wrapping/wrap_AnalyticRing2D.h
  Wrapping/wrap_AnalyticSphere.h
  Wrapping/wrap_AnalyticStraightVessel2D.h
  Wrapping/wrap_AnalyticTorus.h
  Wrapping/wrap_SubVoxel3D.h
  Wrapping/wrap_SubPixel2D.h
  ${KIT}Plugin.h
)

SET(${KIT}_SRCS
  ${${KIT}_SRCS}
  AnalyticCircle.cpp
  AnalyticCube.cpp
  AnalyticCylinder.cpp
  AnalyticFunctionBase.cpp
  AnalyticLine.cpp
  AnalyticPlane.cpp
  AnalyticRing2D.cpp
  AnalyticSphere.cpp
  AnalyticStraightVessel2D.cpp
  AnalyticTorus.cpp
  SubPixel2D.cpp
  SubVoxel3D.cpp
  Wrapping/wrap_AnalyticCircle.cpp
  Wrapping/wrap_AnalyticCube.cpp
  Wrapping/wrap_AnalyticCylinder.cpp
  Wrapping/wrap_AnalyticFunctionBase.cpp
  Wrapping/wrap_AnalyticLine.cpp
  Wrapping/wrap_AnalyticPlane.cpp
  Wrapping/wrap_AnalyticRing2D.cpp
  Wrapping/wrap_AnalyticSphere.cpp
  Wrapping/wrap_AnalyticStraightVessel2D.cpp
  Wrapping/wrap_AnalyticTorus.cpp
  Wrapping/wrap_SubVoxel3D.cpp
  Wrapping/wrap_SubPixel2D.cpp
  ${KIT}Plugin.cpp
)

SET(${KIT}_scripts
  ../scripts/SyntheticPVEImages/SyntheticPVEImagesClass.amil
)

IF(WIN32)
  set_source_files_properties(${${KIT}_SRCS} PROPERTIES COMPILE_FLAGS "-D${KIT}_EXPORTS")
ENDIF(WIN32)

SET(${KIT}_SRCS
    ${${KIT}_SRCS}
    ${${KIT}_HDRS}
)

# Deal with GLSL files like in VTK



FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net  REQUIRED)
INCLUDE(${wxWidgets_USE_FILE})

include_directories (
  ${Boost_INCLUDE_DIR}
)

# ---------- Setup output Directories -------------------------
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${PROJECT_SOURCE_DIR}/bin
  CACHE PATH
  "Single Directory for all Libraries"
)

# --------- Setup the Executable output Directory -------------
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${PROJECT_SOURCE_DIR}/bin
  CACHE PATH
  "Single Directory for all static libraries."
)

# --------- Setup the Executable output Directory -------------
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${PROJECT_SOURCE_DIR}/bin
  CACHE PATH
  "Single Directory for all Executables."
)


CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil
    )


SET(amilab_ownlibs
  ${LanguageBase}
  ${Common}
  ${CommonBase}
  ${WrapCommon}
  ${WrapLanguage}
  ${Algorithms}
  ${Graphic}
  ${wxParams}
)

MESSAGE("VTK_USE_FILE=${VTK_USE_FILE}")
INCLUDE(${VTK_USE_FILE})
MESSAGE("VTK_LIBRARY_DIRS=${VTK_LIBRARY_DIRS}")

LINK_DIRECTORIES( ${LINK_DIRECTORIES} ${VTK_LIBRARY_DIRS} )

SET(LINK_VTK
  vtkGraphics
  vtkImaging
  vtkIO
  vtkFiltering
  vtkCommon
  vtkNetCDF
  vtkRendering 
  vtkVolumeRendering 
  vtkWidgets
  vtkViews
  vtkCharts
)

ADD_LIBRARY(${KIT} MODULE ${${KIT}_SRCS} )

  
IF(WIN32 OR APPLE)
  # conflict between freetype and vtkfreetype
  TARGET_LINK_LIBRARIES( ${KIT}
    ${amilab_ownlibs}
    ${LINK_VTK}
    ${wxWidgets_LIBRARIES}
    ${Boost_LIBRARIES}
    )
  TARGET_LINK_LIBRARIES( ${KIT}
    ITKIO
    #ITKAlgorithms
    #itkvnl
    #itkvnl_algo
  )
  TARGET_LINK_LIBRARIES( ${KIT} ${ZLIB_LIBRARIES})
  TARGET_LINK_LIBRARIES( ${KIT} ${BZIP2_LIBRARIES})
ELSE(WIN32 OR APPLE)
  TARGET_LINK_LIBRARIES( ${KIT}
    ${LINK_VTK}
  )
ENDIF(WIN32 OR APPLE)

IF(GENERATE_HTML_HELP)
  # check if doxygen is even installed
  FIND_PACKAGE(Doxygen)
  IF (DOXYGEN_FOUND STREQUAL "NO")
    MESSAGE(FATAL_ERROR "Doxygen not found. Please get a copy http://www.doxygen.org")
  ENDIF (DOXYGEN_FOUND STREQUAL "NO")

  # prepare doxygen configuration file
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/../../../Doxygen/doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

  # add doxygen as target
  ADD_CUSTOM_TARGET(doxygen ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

  # cleanup $build/api-doc on "make clean"
  SET_PROPERTY(DIRECTORY APPEND PROPERTY
       ADDITIONAL_MAKE_CLEAN_FILES api-doc)

  # add doxygen as dependency to doc-target
  GET_TARGET_PROPERTY(DOC_TARGET doc TYPE)
  IF(NOT DOC_TARGET)
    ADD_CUSTOM_TARGET(doc)
  ENDIF(NOT DOC_TARGET)
  ADD_DEPENDENCIES(doc doxygen)

  # install HTML API documentation and manual pages
  SET(DOC_PATH "share/amilab-${AMILAB_VERSION}/${CMAKE_PROJECT_NAME}")

  INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/html
           DESTINATION ${DOC_PATH}
         )

  # install man pages into packages, scope is now project root..
  INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/man/man3
         DESTINATION share/man/man3/
       )
ENDIF(GENERATE_HTML_HELP)


MESSAGE("TARGET: ${KIT}")
