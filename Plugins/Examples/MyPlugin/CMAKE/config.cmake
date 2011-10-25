#==============================================================================
# Plugin
#
# Description: Specifies the path where AMILab header files.
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

FIND_PATH(AMILAB_SOURCE_DIR
    amilab.cpp
    HINTS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../src
    DOC "AMILab source path"
)

FIND_PATH(AMILAB_BINARY_DIR
    AMILabConfig.h
    HINTS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../src/build
    DOC "AMILab binary path"
)

SET(AMILab_PATHS
    ${AMILAB_SOURCE_DIR}/LanguageBase
    ${AMILAB_SOURCE_DIR}/Language
    ${AMILAB_SOURCE_DIR}/Common/include
    ${AMILAB_SOURCE_DIR}/CommonBase
    ${AMILAB_SOURCE_DIR}/Wrapping/include
    ${AMILAB_SOURCE_DIR}
    ${AMILAB_BINARY_DIR}
)

FIND_LIBRARY(CommonBase CommonBase
    DOC "AMILab CommonBase library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES CommonBase/Debug CommonBase/Release)

FIND_LIBRARY(Common Common
    DOC "AMILab Common library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES Common/Debug Common/Release)

FIND_LIBRARY(LanguageBase LanguageBase
    DOC "AMILab LanguageBase library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES LanguageBase/Debug LanguageBase/Release)

FIND_LIBRARY(WrapCommon WrapCommon
    DOC "AMILab WrapCommon library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES Wrapping/WrapCommon/Debug Wrapping/WrapCommon/Release)

FIND_LIBRARY(WrapLanguage WrapLanguage
    DOC "AMILab WrapLanguage library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES Wrapping/WrapLanguage/Debug Wrapping/WrapLanguage/Release)
