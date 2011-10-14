#==============================================================================
# Plugin
#
# Description: Tuning vtk GPU Raycast VolumeMapper.
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

project (vtkAmiVolRen)

MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4)

SET(CMAKE_MODULE_PATH  ${AMILAB_SOURCE_DIR}/../CMAKE ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules   )


# should get everything from amilab configuration but ok for the moment
FIND_PACKAGE( ITK )
MESSAGE( "ITK_FOUND=${ITK_FOUND}")
IF(ITK_FOUND)
  MESSAGE("ITK_USE_FILE=${ITK_USE_FILE}")
  INCLUDE(${ITK_USE_FILE})
ENDIF(ITK_FOUND)

# need to find VTK first ...
FIND_PACKAGE( VTK )


OPTION(ENABLE_WRAPPING   "ENABLE MODULE WRAPPING" ON)
OPTION(NEED_VTK_WRAPPING "NEED VTK WRAPPING" ON)

INCLUDE(${PROJECT_SOURCE_DIR}/../../../CMAKE/AMILabConfig.cmake)
INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amilab_macros.cmake)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}
                    ${PROJECT_SOURCE_DIR}/Wrapping
                    ${PROJECT_SOURCE_DIR}/Wrapping/Generated
                    ${AMILab_PATHS} )

OPTION(Boost_USE_STATIC_LIBS "Use Boost static libraries" ON)
SET(Boost_USE_MULTITHREAD OFF)
SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")
FIND_PACKAGE( Boost ${BOOST_RELEASE} COMPONENTS date_time filesystem  system iostreams  regex)
FIND_PACKAGE( ZLIB)
FIND_PACKAGE( BZip2)

FIND_PACKAGE( wxWidgets COMPONENTS adv html aui  gl core base stc net richtext)

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

SET(vtkAmiVolRen_HDRS
  ${vtkAmiVolRen_HDRS}
  vtkAMILabGPUMultiVolumeRayCastMapper.h
  vtkAMILabOpenGLGPUMultiVolumeRayCastMapper.h
  vtkAmiVolRenPlugin.h
)

SET(vtkAmiVolRen_SRCS
  ${vtkAmiVolRen_SRCS}
  vtkAMILabGPUMultiVolumeRayCastMapper.cxx
  vtkAMILabOpenGLGPUMultiVolumeRayCastMapper.cxx
  vtkAmiVolRenPlugin.cpp
)

IF(WIN32)
  set_source_files_properties(${vtkAmiVolRen_SRCS} PROPERTIES COMPILE_FLAGS "-DvtkAmiVolRen_EXPORTS")
ENDIF(WIN32)

SET(vtkAmiVolRen_SRCS
    ${vtkAmiVolRen_SRCS}
    ${vtkAmiVolRen_HDRS}
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
#   vtkGPUVolumeRayCastMapper_OneComponentFS
#   vtkGPUVolumeRayCastMapper_FourComponentsFS
#   vtkGPUVolumeRayCastMapper_NoShadeFS
#   vtkGPUVolumeRayCastMapper_ShadeFS
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
foreach(file ${KIT_GLSL_SRCS})
  ## TODO
  set(src  ${PROJECT_SOURCE_DIR}/GLSL/${file}.glsl)
#   set(res  ${PROJECT_BINARY_DIR}/GLSL/${file}.cxx)
#   set(resh ${PROJECT_BINARY_DIR}/GLSL/${file}.h)
  set(res  ${PROJECT_BINARY_DIR}/${file}.cxx)
  set(resh ${PROJECT_BINARY_DIR}/${file}.h)
  add_custom_command(
    OUTPUT ${res} ${resh}
    DEPENDS ${src} vtkEncodeString
    COMMAND ${VTK_ENCODESTRING_EXE}
    ARGS ${res} ${src} ${file} --build-header VTK_VOLUMERENDERING_EXPORT vtkSystemIncludes.h
    )
  set(Kit_EXTRA_SRCS ${Kit_EXTRA_SRCS} ${res})
endforeach(file)



FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net  REQUIRED)
INCLUDE(${wxWidgets_USE_FILE})

include_directories (
  ${Boost_INCLUDE_DIR}
)

ADD_LIBRARY(vtkAmiVolRen MODULE ${vtkAmiVolRen_SRCS} ${Kit_EXTRA_SRCS})


SET(amilab_ownlibs
  ${LanguageBase}
  ${Common}
  ${CommonBase}
  ${WrapCommon}
  ${WrapLanguage}
)

INCLUDE(${VTK_USE_FILE})

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


TARGET_LINK_LIBRARIES( vtkAmiVolRen
    ${LINK_VTK}
)
  
IF(WIN32)
  # conflict between freetype and vtkfreetype
  TARGET_LINK_LIBRARIES( vtkAmiVolRen
    ${amilab_ownlibs}
    ${LINK_VTK}
    ${wxWidgets_LIBRARIES}
    ${Boost_LIBRARIES}
    )
  TARGET_LINK_LIBRARIES( vtkAmiVolRen
    ITKIO
    ITKAlgorithms
    itkvnl
    itkvnl_algo
  )
  TARGET_LINK_LIBRARIES( vtkAmiVolRen ${ZLIB_LIBRARIES})
  TARGET_LINK_LIBRARIES( vtkAmiVolRen ${BZIP2_LIBRARIES})
ENDIF(WIN32)


MESSAGE("TARGET: vtkAmiVolRen")
