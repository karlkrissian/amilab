#==============================================================================
# Ultrasonix
#
# Description: Ultrasonix module
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================


SET(KIT Ultrasonix)

#FIND_PATH( MT_DIR MTC.h PATHS "$ENV{ProgramFiles}/Claron Technology/Ultrasonix/Dist")

SET(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/../../../CMAKE  ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules   )

MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

#MESSAGE("wxWidgets_USE_FILE = ${wxWidgets_USE_FILE}")
INCLUDE(${wxWidgets_USE_FILE})
INCLUDE(${ITK_USE_FILE})
#MESSAGE("${ITK_USE_FILE}")
INCLUDE(${VTK_USE_FILE})
#MESSAGE("${VTK_USE_FILE}")


SET( ${KIT}_ENABLE_WRAPPING      ON )

#FIND_PACKAGE(AMILab)


#INCLUDE(${AMILab_BINARY_DIR}/AMILabConfig.cmake)
#MESSAGE("Boost_USE_STATIC_LIBS has been set to ${Boost_USE_STATIC_LIBS}")

#INCLUDE(${AMILab_SOURCE_DIR}/../CMAKE/amilab_macros.cmake)

set(  wxParams_INCLUDE_DIRS
    ${AMILab_SOURCE_DIR}/../wxParams/src)

SET(${KIT}_AMILab_PATHS
    ${AMILab_SOURCE_DIR}/LanguageBase
    ${AMILab_SOURCE_DIR}/Language
    ${AMILab_SOURCE_DIR}/Common/include
    ${AMILab_SOURCE_DIR}/CommonBase
    ${AMILab_SOURCE_DIR}/Wrapping/include
    ${AMILab_SOURCE_DIR}
    ${AMILab_BINARY_DIR}
    ${AMILab_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
    ${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
)

SET(${KIT}_INCLUDE_PATHS
    ${ULTRASOUND_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/Wrapping
    ${CMAKE_CURRENT_BINARY_DIR}/Wrapping/Generated
    ${${KIT}_AMILab_PATHS}
    ${${KIT}_INCLUDE_PATHS}
    ${Boost_INCLUDE_DIR}
 )

add_definitions(-DMBCS -D_MBCS)
GET_PROPERTY( US_DEF DIRECTORY PROPERTY COMPILE_DEFINITIONS)
MESSAGE("US_DEF = ${US_DEF}")
ADD_DEFINITIONS(-D_AFXDLL)
ADD_DEFINITIONS(-D_DLL )
SET(CMAKE_MFC_FLAG 2)

SET(GCCXML_DEFS "")
FOREACH( usdef ${US_DEF})
  SET( GCCXML_DEFS -D${usdef}  ${GCCXML_DEFS} )
ENDFOREACH( usdef ${US_DEF} )

IF(WIN32)
  SET(GCCXML_DEFS ${GCCXML_DEFS} -D_WIN32 -DWIN32 -D_MSC_VER -D_WINDOWS)
ENDIF(WIN32)

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

  MESSAGE("*****")
  #
  INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/../../../CMAKE/PluginWrapping.cmake)
  #
ENDIF(${KIT}_ENABLE_WRAPPING)

SET(${KIT}_HDRS
  ${${KIT}_HDRS}
  ${KIT}Plugin.h
  InterfaceUS.h
)

SET(${KIT}_SRCS
  ${${KIT}_SRCS}
  ${KIT}Plugin.cpp
  InterfaceUS.cpp
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

# CONFIGURE_FILE(
#     ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil.in 
#     ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/dllpath.amil
#     )


SET(amilab_ownlibs
  ${LanguageBase}
  ${Common}
  ${CommonBase}
  ${WrapCommon}
  ${WrapVTK}
  ${WrapWxWidgets}
  #Algorithms
)



ADD_LIBRARY(${KIT} MODULE ${${KIT}_SRCS} )

SET_TARGET_PROPERTIES( ${KIT}
  PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${${KIT}_LIBRARY_OUTPUT_DIRECTORY}
)

IF(MSVC) 
 	set_target_properties( ${KIT}
	PROPERTIES LINK_FLAGS "/NODEFAULTLIB:msvcrtd.lib")
ENDIF(MSVC)
 
TARGET_LINK_LIBRARIES( ${KIT}
    ${ULTRASOUND_LIB}
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


TARGET_LINK_LIBRARIES( ${KIT}
    ${LINK_VTK}
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
  
  ADD_DEPENDENCIES ( ${KIT} ${amilab_ownlibs})
ENDIF(WIN32 OR APPLE)

# Install library 
INSTALL(TARGETS Ultrasonix
      RUNTIME DESTINATION bin
      ARCHIVE DESTINATION lib/amilab-${AMILAB_VERSION}/plugin/
      LIBRARY DESTINATION lib/amilab-${AMILAB_VERSION}/plugin/
)

#get_target_property(Subpixel_location Ultrasonix LOCATION target)
#MESSAGE("Subpixel_location=${Subpixel_location}")

# Install the scripts
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../Ultrasonix
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
