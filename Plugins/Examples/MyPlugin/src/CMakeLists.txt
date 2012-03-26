#==============================================================================
# Plugin
#
# Description: A plugin example.
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

project (ExamplePlugin)

MESSAGE( "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME} ")

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4)

INCLUDE(${PROJECT_SOURCE_DIR}/../CMAKE/config.cmake)
INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amilab_macros.cmake)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}
                    ${PROJECT_BINARY_DIR}/Wrapping/Generated
                    ${AMILab_PATHS} )

OPTION(Boost_USE_STATIC_LIBS "Use Boost static libraries" ON)
SET(Boost_USE_MULTITHREAD OFF)
SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")
FIND_PACKAGE( Boost ${BOOST_RELEASE} COMPONENTS date_time filesystem  system iostreams  regex)
FIND_PACKAGE( ZLIB)
FIND_PACKAGE( BZip2)

# should get everything from amilab configuration but ok for the moment
FIND_PACKAGE( VTK )
FIND_PACKAGE( ITK )
MESSAGE( "ITK_FOUND=${ITK_FOUND}")
IF(ITK_FOUND)
  MESSAGE("ITK_USE_FILE=${ITK_USE_FILE}")
  INCLUDE(${ITK_USE_FILE})
ENDIF(ITK_FOUND)

FIND_PACKAGE( wxWidgets COMPONENTS adv html aui  gl core base stc net richtext)



INCLUDE(${PROJECT_SOURCE_DIR}/../CMAKE/wrapping.cmake)

SET(ExamplePlugin_HDRS
    Foo.h
    Plugin.h
    ExamplePlugin.h
    ${Example_HDRS}
)

SET(ExamplePlugin_SRCS
    Plugin.cpp
    ExamplePlugin.cpp
    ${Example_SRCS}
)

SET(ExamplePlugin_SRCS
    ${ExamplePlugin_SRCS}
    ${ExamplePlugin_HDRS}
)

FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net  REQUIRED)
INCLUDE(${wxWidgets_USE_FILE})

include_directories (
  ${Boost_INCLUDE_DIR}
)

ADD_LIBRARY(ExamplePlugin MODULE ${ExamplePlugin_SRCS})


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


# conflict between freetype and vtkfreetype
TARGET_LINK_LIBRARIES( ExamplePlugin
  ${amilab_ownlibs}
  ${LINK_VTK}
  ${wxWidgets_LIBRARIES}
  ${Boost_LIBRARIES}
  )
  
TARGET_LINK_LIBRARIES( ExamplePlugin
  ITKIO
  ITKAlgorithms
  itkvnl
  itkvnl_algo
)

TARGET_LINK_LIBRARIES( ExamplePlugin ${ZLIB_LIBRARIES})
TARGET_LINK_LIBRARIES( ExamplePlugin ${BZIP2_LIBRARIES})

MESSAGE("TARGET: ExamplePlugin")
