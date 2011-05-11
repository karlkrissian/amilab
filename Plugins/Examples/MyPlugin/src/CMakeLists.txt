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
                    ${PROJECT_SOURCE_DIR}/Wrapping/Generated
                    ${AMILab_Header} )

SET(BOOST_RELEASE "1.33" CACHE STRING "specify boost version")
FIND_PACKAGE( Boost ${BOOST_RELEASE} COMPONENTS date_time filesystem  system iostreams  regex)

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
TARGET_LINK_LIBRARIES(
  ExamplePlugin ${wxWidgets_LIBRARIES}  ${Boost_LIBRARIES}
)

MESSAGE("TARGET: ExamplePlugin")