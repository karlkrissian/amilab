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

FIND_PACKAGE(wxWidgets COMPONENTS adv html aui  gl core base stc net media REQUIRED)
INCLUDE(${wxWidgets_USE_FILE})
ADD_LIBRARY(ExamplePlugin SHARED ${ExamplePlugin_SRCS})
TARGET_LINK_LIBRARIES(ExamplePlugin ${wxWidgets_LIBRARIES})

MESSAGE("TARGET: ExamplePlugin")