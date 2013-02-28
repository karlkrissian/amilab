#==============================================================================
# vtkAmiVolRen
#
# Description: vtkAmiVolRen module
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================


SET(KIT vtkAmiVolRen)

SET(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/../../../CMAKE  ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules   )

MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

INCLUDE(${wxWidgets_USE_FILE})
INCLUDE(${ITK_USE_FILE})
INCLUDE(${VTK_USE_FILE})

SET( ${KIT}_ENABLE_WRAPPING      ON )

#FIND_PACKAGE(AMILab)


#INCLUDE(${AMILab_BINARY_DIR}/AMILabConfig.cmake)
#MESSAGE("Boost_USE_STATIC_LIBS has been set to ${Boost_USE_STATIC_LIBS}")

#INCLUDE(${AMILab_SOURCE_DIR}/../CMAKE/amilab_macros.cmake)


SET(${KIT}_INCLUDE_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/Wrapping
    ${${KIT}_BINARY_DIR}/Wrapping/Generated
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${AMILab_PATHS}
)


INCLUDE_DIRECTORIES(
    ${${KIT}_INCLUDE_PATHS}
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

  IF(${KIT}_NEED_WX_WRAPPING)
    # allow use of vtk classes  wrapped within AMILab
    FILE(READ "${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated/ancestors.txt" wx_ancestors_txt)
    STRING(REGEX REPLACE "[\r\n]" ";" wx_ancestors_list ${wx_ancestors_txt} )
    SET(AVAILABLE_EXTERNAL_CLASSES ${AVAILABLE_EXTERNAL_CLASSES} ${wx_ancestors_list})
    MESSAGE("AVAILABLE_EXTERNAL_CLASSES=${AVAILABLE_EXTERNAL_CLASSES}")
  ENDIF(${KIT}_NEED_WX_WRAPPING)

  #
  INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../CMAKE/PluginWrapping.cmake)
  #
ENDIF(${KIT}_ENABLE_WRAPPING)

SET(${KIT}_HDRS
  ${${KIT}_HDRS}
  vtkGPUMultiVolumeRayCastMapper.h
  vtkOpenGLGPUMultiVolumeRayCastMapper.h
  ${KIT}Plugin.h
)

SET(${KIT}_SRCS
  ${${KIT}_SRCS}
  vtkGPUMultiVolumeRayCastMapper.cxx
  vtkOpenGLGPUMultiVolumeRayCastMapper.cxx
  ${KIT}Plugin.cpp
)

SET(${KIT}_scriptsdir
  ../scripts
)

IF(WIN32)
  set_source_files_properties(${${KIT}_SRCS} PROPERTIES COMPILE_FLAGS "-D${KIT}_EXPORTS")
  # add this definition to allow original VTK macros to work
  set_source_files_properties(${${KIT}_SRCS} PROPERTIES COMPILE_FLAGS "-DvtkVolumeRendering_EXPORTS")
ENDIF(WIN32)

SET(${KIT}_SRCS
    ${${KIT}_SRCS}
    ${${KIT}_HDRS}
    ${${KIT}_scriptsdir}
)

# Deal with GLSL files like in VTK

# -----------------------------------------------------------------------------
# Set of GLSL source files
# -----------------------------------------------------------------------------
set(KIT_GLSL_SRCS
  vtkGPUMultiVolumeRayCastMapper_CompositeFS
#   vtkGPUVolumeRayCastMapper_AdditiveFS
#   vtkGPUVolumeRayCastMapper_AdditiveCroppingFS
#   vtkGPUVolumeRayCastMapper_AdditiveNoCroppingFS
#   vtkGPUVolumeRayCastMapper_CompositeFS
#   vtkGPUVolumeRayCastMapper_CompositeMaskFS
#   vtkGPUVolumeRayCastMapper_CompositeBinaryMaskFS
#   vtkGPUVolumeRayCastMapper_CompositeCroppingFS
#   vtkGPUVolumeRayCastMapper_CompositeNoCroppingFS
#   vtkGPUVolumeRayCastMapper_HeaderFS
#   vtkGPUVolumeRayCastMapper_MIPCroppingFS
#   vtkGPUVolumeRayCastMapper_MIPFS
#   vtkGPUVolumeRayCastMapper_MIPBinaryMaskFS
#   vtkGPUVolumeRayCastMapper_MIPFourDependentFS
#   vtkGPUVolumeRayCastMapper_MIPFourDependentCroppingFS
#   vtkGPUVolumeRayCastMapper_MIPFourDependentNoCroppingFS
#   vtkGPUVolumeRayCastMapper_MIPNoCroppingFS
#   vtkGPUVolumeRayCastMapper_MinIPCroppingFS
#   vtkGPUVolumeRayCastMapper_MinIPFS
#   vtkGPUVolumeRayCastMapper_MinIPBinaryMaskFS
#   vtkGPUVolumeRayCastMapper_MinIPFourDependentFS
#   vtkGPUVolumeRayCastMapper_MinIPFourDependentCroppingFS
#   vtkGPUVolumeRayCastMapper_MinIPFourDependentNoCroppingFS
#   vtkGPUVolumeRayCastMapper_MinIPNoCroppingFS
#   vtkGPUVolumeRayCastMapper_ParallelProjectionFS
#   vtkGPUVolumeRayCastMapper_PerspectiveProjectionFS
#   vtkGPUVolumeRayCastMapper_ScaleBiasFS
   vtkGPUMultiVolumeRayCastMapper_OneComponentFS
   vtkGPUMultiVolumeRayCastMapper_FourComponentsFS
   vtkGPUMultiVolumeRayCastMapper_NoShadeFS
   vtkGPUMultiVolumeRayCastMapper_ShadeFS
#   vtkProjectedAAHexahedraMapper_VS
#   vtkProjectedAAHexahedraMapper_GS
#   vtkProjectedAAHexahedraMapper_FS
  )

# -----------------------------------------------------------------------------
# Create custom commands to encode each glsl file into a C string literal
# in a header file
# -----------------------------------------------------------------------------

# Needs vtkEncodeString, VTK_ENCODESTRING_EXE 
# should work ...  
# VTK_VOLUMERENDERING_EXPORT is the flag associated to the library, should be adapted
MESSAGE("PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")
foreach(file ${KIT_GLSL_SRCS})
  ## TODO
  set(src  ${PROJECT_SOURCE_DIR}/src/GLSL/${file}.glsl)
#   set(res  ${PROJECT_BINARY_DIR}/GLSL/${file}.cxx)
#   set(resh ${PROJECT_BINARY_DIR}/GLSL/${file}.h)
  set(res  ${CMAKE_CURRENT_BINARY_DIR}/${file}.cxx)
  set(resh ${CMAKE_CURRENT_BINARY_DIR}/${file}.h)
  add_custom_command(
    OUTPUT ${res} ${resh}
    DEPENDS ${src} vtkEncodeString
    COMMAND ${VTK_ENCODESTRING_EXE}
    ARGS ${res} ${src} ${file} --build-header VTK_VOLUMERENDERING_EXPORT vtkSystemIncludes.h
    )
  set(Kit_EXTRA_SRCS ${Kit_EXTRA_SRCS} ${res})
endforeach(file)

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

# CONFIGURE_FILE(
#     ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil.in 
#     ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil
#     )



ADD_LIBRARY(${KIT} MODULE ${${KIT}_SRCS}  ${Kit_EXTRA_SRCS})

SET_TARGET_PROPERTIES( ${KIT}
  PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${${KIT}_LIBRARY_OUTPUT_DIRECTORY}
)
  
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

SET(amilab_ownlibs
  ${LanguageBase}
  ${Common}
  ${CommonBase}
  ${WrapCommon}
  ${WrapVTK}
  #${Algorithms}
)

IF(WIN32 OR APPLE)

  # conflict between freetype and vtkfreetype
  TARGET_LINK_LIBRARIES( ${KIT}
    ${amilab_ownlibs}
    ${wxWidgets_LIBRARIES}
    ${Boost_LIBRARIES}
    ${LINK_VTK}
    ${OPENGL_LIBRARIES}
    ${OPENGL_glu_LIBRARY}
    )
  TARGET_LINK_LIBRARIES( ${KIT}
    #ITKIO
  )
  TARGET_LINK_LIBRARIES( ${KIT} ${ZLIB_LIBRARIES})
  TARGET_LINK_LIBRARIES( ${KIT} ${BZIP2_LIBRARIES})
ELSE(WIN32 OR APPLE)
  TARGET_LINK_LIBRARIES( ${KIT}
    ${LINK_VTK}
  )
  
  ADD_DEPENDENCIES ( ${KIT} ${amilab_ownlibs})
ENDIF(WIN32 OR APPLE)

# Install library 
INSTALL(TARGETS vtkAmiVolRen
      RUNTIME DESTINATION bin
      ARCHIVE DESTINATION lib/amilab-${AMILAB_VERSION}/plugin/
      LIBRARY DESTINATION lib/amilab-${AMILAB_VERSION}/plugin/
)

#get_target_property(Subpixel_location vtkAmiVolRen LOCATION target)
#MESSAGE("Subpixel_location=${Subpixel_location}")

# Install the scripts
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../vtkAmiVolRen
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
          PATTERN "build"          EXCLUDE
          PATTERN "Generated"      EXCLUDE
          PATTERN "CMakeFiles"     EXCLUDE
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
