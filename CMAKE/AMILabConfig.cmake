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

IF (NEED_VTK_WRAPPING)
  IF(VTK_FOUND)
    SET(AMI_VTK_VERSION "${VTK_MAJOR_VERSION}.${VTK_MINOR_VERSION}")
  ENDIF(VTK_FOUND)
  SET(AMILab_PATHS
    ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated
    ${AMILab_PATHS}
    )
  MESSAGE(" VTK wrapping path is ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated")
ENDIF(NEED_VTK_WRAPPING)

FIND_LIBRARY(CommonBase CommonBase
    DOC "AMILab CommonBase library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES CommonBase CommonBase/Debug CommonBase/Release)

FIND_LIBRARY(Common Common
    DOC "AMILab Common library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES Common Common/Debug Common/Release)

FIND_LIBRARY(LanguageBase LanguageBase
    DOC "AMILab LanguageBase library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES LanguageBase LanguageBase/Debug LanguageBase/Release)

FIND_LIBRARY(WrapCommon WrapCommon
    DOC "AMILab WrapCommon library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES Wrapping/WrapCommon 
                  Wrapping/WrapCommon/Debug 
                  Wrapping/WrapCommon/Release)

FIND_LIBRARY(WrapLanguage WrapLanguage
    DOC "AMILab WrapLanguage library"
    PATHS ${AMILAB_BINARY_DIR}
    PATH_SUFFIXES Wrapping/WrapLanguage 
                  Wrapping/WrapLanguage/Debug 
                  Wrapping/WrapLanguage/Release)
