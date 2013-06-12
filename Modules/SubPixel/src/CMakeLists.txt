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

SET(${KIT}_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(${KIT}_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

INCLUDE(${wxWidgets_USE_FILE})
INCLUDE(${ITK_USE_FILE})
INCLUDE(${VTK_USE_FILE})

#INCLUDE(${wxWidgets_USE_FILE})
#INCLUDE( ${USE_ITK_FILE} )
#INCLUDE( ${USE_VTK_FILE} )

SET( ${KIT}_ENABLE_WRAPPING      ON )

#FIND_PACKAGE(AMILab)


#INCLUDE(${AMILab_BINARY_DIR}/AMILabConfig.cmake)
#MESSAGE("Boost_USE_STATIC_LIBS has been set to ${Boost_USE_STATIC_LIBS}")

#INCLUDE(${AMILab_SOURCE_DIR}/../CMAKE/amilab_macros.cmake)

# set(  wxParams_INCLUDE_DIRS
#     ${AMILab_SOURCE_DIR}/../wxParams/src)

SET(${KIT}_INCLUDE_PATHS
    ${AMILab_SOURCE_DIR}/LanguageBase
    ${AMILab_SOURCE_DIR}/Language
    ${AMILab_SOURCE_DIR}/Common/include
    ${AMILab_SOURCE_DIR}/Algorithms/include
    ${AMILab_SOURCE_DIR}/Algorithms/FastConvolution
    ${AMILab_SOURCE_DIR}/CommonBase
    ${AMILab_SOURCE_DIR}/Wrapping/include
    ${AMILab_SOURCE_DIR}
    ${AMILab_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Wrapping
)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_BINARY_DIR}/Wrapping/Generated
    ${${KIT}_INCLUDE_PATHS}
    ${AMILab_SOURCE_DIR}/Algorithms/include
    ${AMILab_SOURCE_DIR}/Graphic/include
    ${Boost_INCLUDE_DIR}
 )


MESSAGE("${KIT}_ENABLE_WRAPPING=${${KIT}_ENABLE_WRAPPING}")
IF(${KIT}_ENABLE_WRAPPING)
  #
  IF(${KIT}_NEED_VTK_WRAPPING)
    # allow use of vtk classes  wrapped within AMILab
    FILE(READ "${AMILab_BINARY_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated/ancestors.txt" vtk_ancestors_txt)
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
  AnalyticHelix.h
  SubPixel2D.h
  SubVoxel3D.h
  Wrapping/wrap_AnalyticCircle.h
  Wrapping/wrap_AnalyticCube.h
  #Wrapping/wrap_AnalyticCylinder.h
  #Wrapping/wrap_AnalyticFunctionBase.h
  Wrapping/wrap_AnalyticLine.h
  Wrapping/wrap_AnalyticPlane.h
  Wrapping/wrap_AnalyticRing2D.h
  Wrapping/wrap_AnalyticSphere.h
  Wrapping/wrap_AnalyticStraightVessel2D.h
  Wrapping/wrap_AnalyticTorus.h
  Wrapping/wrap_ComputePartialVolume.h
  Wrapping/wrap_SubVoxel3D.h
#  Wrapping/wrap_SubPixel2D.h
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
  AnalyticHelix.cpp
  SubPixel2D.cpp
  SubVoxel3D.cpp
  Wrapping/wrap_AnalyticCircle.cpp
  Wrapping/wrap_AnalyticCube.cpp
  #Wrapping/wrap_AnalyticCylinder.cpp
  #Wrapping/wrap_AnalyticFunctionBase.cpp
  Wrapping/wrap_AnalyticLine.cpp
  Wrapping/wrap_AnalyticPlane.cpp
  Wrapping/wrap_AnalyticRing2D.cpp
  Wrapping/wrap_AnalyticSphere.cpp
  Wrapping/wrap_AnalyticStraightVessel2D.cpp
  Wrapping/wrap_AnalyticTorus.cpp
  Wrapping/wrap_ComputePartialVolume.cpp
  Wrapping/wrap_SubVoxel3D.cpp
#  Wrapping/wrap_SubPixel2D.cpp
  ${KIT}Plugin.cpp
)

SET(${KIT}_scriptsdir
  ../scripts
)

IF(WIN32)
  set_source_files_properties(${${KIT}_SRCS} PROPERTIES COMPILE_FLAGS "-D${KIT}_EXPORTS")
ENDIF(WIN32)

SET(${KIT}_SRCS
    ${${KIT}_SRCS}
    ${${KIT}_HDRS}
    ${${KIT}_scriptsdir}
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

#SET( ${KIT}_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/bin)

SET( ${KIT}_LIBRARY_OUTPUT_DIRECTORY  ${AMILab_BINARY_DIR}/lib/amilab-${AMILAB_VERSION}/plugin/)

CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil
    )


SET(amilab_ownlibs
  LanguageBase
  Common
  CommonBase
  WrapCommon
  Algorithms
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
  #TARGET_LINK_LIBRARIES( ${KIT}
  #  ITKIO
  #)
  TARGET_LINK_LIBRARIES( ${KIT} ${ZLIB_LIBRARIES})
  TARGET_LINK_LIBRARIES( ${KIT} ${BZIP2_LIBRARIES})
ELSE(WIN32 OR APPLE)
  TARGET_LINK_LIBRARIES( ${KIT}
    ${LINK_VTK}
  )
  
  ADD_DEPENDENCIES ( ${KIT} ${amilab_ownlibs})
ENDIF(WIN32 OR APPLE)

# Install library 
INSTALL(TARGETS SubPixel
      RUNTIME DESTINATION bin
      ARCHIVE DESTINATION lib/amilab-${AMILAB_VERSION}/plugin/
      LIBRARY DESTINATION lib/amilab-${AMILAB_VERSION}/plugin/
)

#get_target_property(Subpixel_location SubPixel LOCATION target)
#MESSAGE("Subpixel_location=${Subpixel_location}")

# Install the scripts
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../SubPixel
        DESTINATION share/amilab-${AMILAB_VERSION}/Modules
        # COMPONENT scripts
        FILES_MATCHING 
          PATTERN "*.amil"
          PATTERN "*.sh"
          PATTERN "*.py"
          PATTERN "*.png"         
          PATTERN "*.txt"
          PATTERN "*.sh"
          PATTERN "*.html"
          # ----  Exclude
          PATTERN "CMakeLists.txt" EXCLUDE
          PATTERN "src"            EXCLUDE
          PATTERN ".svn"           EXCLUDE
          PATTERN "*.in"           EXCLUDE
        PERMISSIONS 
          OWNER_EXECUTE
          OWNER_WRITE
          OWNER_READ
          GROUP_EXECUTE
          GROUP_READ
        )

MESSAGE("TARGET: ${KIT}")
