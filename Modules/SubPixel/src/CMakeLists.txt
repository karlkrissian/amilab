#==============================================================================
# SubPixel
#
# Description: SubPixel module
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================


SET(KIT SubPixel)

SET(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/../../../CMAKE  ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules   )

MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

INCLUDE(${wxWidgets_USE_FILE})

SET( ${KIT}_ENABLE_WRAPPING      OFF )

#FIND_PACKAGE(AMILab)


#INCLUDE(${AMILAB_BINARY_DIR}/AMILabConfig.cmake)
#MESSAGE("Boost_USE_STATIC_LIBS has been set to ${Boost_USE_STATIC_LIBS}")

#INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amilab_macros.cmake)

set(  wxParams_INCLUDE_DIRS
    ${AMILAB_SOURCE_DIR}/../wxParams/src)

SET(${KIT}_AMILab_PATHS
    ${AMILAB_SOURCE_DIR}/LanguageBase
    ${AMILAB_SOURCE_DIR}/Language
    ${AMILAB_SOURCE_DIR}/Common/include
    ${AMILAB_SOURCE_DIR}/CommonBase
    ${AMILAB_SOURCE_DIR}/Wrapping/include
    ${AMILAB_SOURCE_DIR}
    ${AMILAB_BINARY_DIR}
)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Wrapping
    ${CMAKE_CURRENT_SOURCE_DIR}/Wrapping/Generated
    ${${KIT}_AMILab_PATHS}
    ${AMILAB_SOURCE_DIR}/Algorithms/include
    ${AMILAB_SOURCE_DIR}/Graphic/include
    ${Boost_INCLUDE_DIR}
 )


MESSAGE("${KIT}_ENABLE_WRAPPING=${${KIT}_ENABLE_WRAPPING}")
IF(${KIT}_ENABLE_WRAPPING)
  #
  IF(${KIT}_NEED_VTK_WRAPPING)
    # allow use of vtk classes  wrapped within AMILab
    FILE(READ "${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated/ancestors.txt" vtk_ancestors_txt)
    STRING(REGEX REPLACE "[\r\n]" ";" vtk_ancestors_list ${vtk_ancestors_txt} )
    SET(AVAILABLE_EXTERNAL_CLASSES ${vtk_ancestors_list})
    MESSAGE("AVAILABLE_EXTERNAL_CLASSES=${AVAILABLE_EXTERNAL_CLASSES}")
  ENDIF(${KIT}_NEED_VTK_WRAPPING)
  #
  INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../CMAKE/PluginWrapping.cmake)
  #
ENDIF(${KIT}_ENABLE_WRAPPING)

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

# # ---------- Setup output Directories -------------------------
# SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
#   ${CMAKE_CURRENT_SOURCE_DIR}/bin
#   CACHE PATH
#   "Single Directory for all Libraries"
# )
# 
# # --------- Setup the Executable output Directory -------------
# SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
#   ${CMAKE_CURRENT_SOURCE_DIR}/bin
#   CACHE PATH
#   "Single Directory for all static libraries."
# )
# 
# # --------- Setup the Executable output Directory -------------
# SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
#   ${CMAKE_CURRENT_SOURCE_DIR}/bin
#   CACHE PATH
#   "Single Directory for all Executables."
# )

SET( ${KIT}_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/bin)

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

SET_TARGET_PROPERTIES( ${KIT}
  PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${${KIT}_LIBRARY_OUTPUT_DIRECTORY}
)
  
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


MESSAGE("TARGET: ${KIT}")
