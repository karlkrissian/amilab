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

set(CMAKE_XCODE_ATTRIBUTE_GCC_VERSION "4.2")

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
#FIND_PACKAGE( VTK )

#MESSAGE("VTK_USE_FILE=${VTK_USE_FILE}")
#INCLUDE(${VTK_USE_FILE})
#MESSAGE("VTK_LIBRARY_DIRS=${VTK_LIBRARY_DIRS}")

OPTION(ENABLE_WRAPPING    "ENABLE MODULE WRAPPING"  ON )
OPTION(NEED_VTK_WRAPPING  "NEED VTK WRAPPING"       OFF )
OPTION(GENERATE_HTML_HELP "Generate HTML file help" OFF)




#FIND_PACKAGE( wxWidgets COMPONENTS adv html aui  gl core base stc net richtext)

OPTION(NEED_WX_WRAPPING "NEED WXWIDGETS WRAPPING" OFF)

SET(AMI_WXWIDGETS_VERSION "AMI_WXWIDGETS_VERSION-NOTFOUND" )
#-------------------------------------------------------------------------------
#  Get the wxWidgets version.
#-------------------------------------------------------------------------------


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
 )

OPTION(Boost_USE_STATIC_LIBS "Use Boost static libraries" ON)
SET(Boost_USE_MULTITHREAD OFF)
SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")
FIND_PACKAGE( Boost ${BOOST_RELEASE} COMPONENTS date_time filesystem  system iostreams  regex)
FIND_PACKAGE( ZLIB)
FIND_PACKAGE( BZip2)



IF(ENABLE_WRAPPING)

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
  #AnalyticFunctionBase.h
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
  Wrapping/wrap_ComputePartialVolume.h
  Wrapping/wrap_SubVoxel3D.h
  Wrapping/wrap_SubPixel2D.h
  ${KIT}Plugin.h
)

SET(${KIT}_SRCS
  ${${KIT}_SRCS}
  AnalyticCircle.cpp
  AnalyticCube.cpp
  AnalyticCylinder.cpp
  #AnalyticFunctionBase.cpp
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
  Wrapping/wrap_ComputePartialVolume.cpp
  Wrapping/wrap_SubVoxel3D.cpp
  Wrapping/wrap_SubPixel2D.cpp
  ${KIT}Plugin.cpp
)

SET(${KIT}_scripts
  ../scripts/SyntheticPVEImages/SyntheticPVEImagesClass.amil
  ../scripts/2D/subpixel2DClass.amil
)

IF(WIN32)
  set_source_files_properties(${${KIT}_SRCS} PROPERTIES COMPILE_FLAGS "-D${KIT}_EXPORTS")
ENDIF(WIN32)

SET(${KIT}_SRCS
    ${${KIT}_SRCS}
    ${${KIT}_HDRS}
    ${${KIT}_scripts}
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
  ${Algorithms}
)



ADD_LIBRARY(${KIT} MODULE ${${KIT}_SRCS} )

  
IF(WIN32 OR APPLE)
  # conflict between freetype and vtkfreetype
  TARGET_LINK_LIBRARIES( ${KIT}
    ${amilab_ownlibs}
    ${wxWidgets_LIBRARIES}
    ${Boost_LIBRARIES}
    )
  TARGET_LINK_LIBRARIES( ${KIT}
    ITKIO
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
