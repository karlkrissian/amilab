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

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}
                    ${PROJECT_SOURCE_DIR}/Wrapping/Generated
                    ${AMILab_Header} )

INCLUDE(${PROJECT_SOURCE_DIR}/../CMAKE/wrapping.cmake)

SET(ExamplePlugin_HDRS
    ${Example_HDRS}
    Plugin.h
    ExamplePlugin.h
)

SET(ExamplePlugin_SRCS
    ${Example_SRCS}
    Plugin.cpp
    ExamplePlugin.cpp
)

SET(ExamplePlugin_SRCS
    ${ExamplePlugin_SRCS}
    ${ExamplePlugin_HDRS}
)

SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")
FIND_PACKAGE( Boost ${BOOST_RELEASE} COMPONENTS date_time filesystem  system iostreams  regex)

FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net media REQUIRED)
INCLUDE(${wxWidgets_USE_FILE})

include_directories (
  ${Boost_INCLUDE_DIR}
)

ADD_LIBRARY(ExamplePlugin MODULE ${ExamplePlugin_SRCS})
TARGET_LINK_LIBRARIES(
  ExamplePlugin ${wxWidgets_LIBRARIES}  ${Boost_LIBRARIES}
)

MESSAGE("TARGET: ExamplePlugin")