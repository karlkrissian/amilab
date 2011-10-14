#==============================================================================
# AMILab configuration
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================


# Assume not found.
SET(AMILab_FOUND 0)
# Construct consitent error messages for use below.
SET(AMILab_DIR_DESCRIPTION "directory containing AMILabConfig.cmake.  This is either the root of the build tree, or PREFIX/lib/AMILab for an installation.")
SET(AMILab_DIR_MESSAGE "AMILab not found.  Set the AMILab_DIR cmake cache entry to the ${AMILab_DIR_DESCRIPTION}")
FIND_PACKAGE(AMILab QUIET NO_MODULE)

MESSAGE("AMILab_FOUND=${AMILab_FOUND}")
IF(AMILab_FOUND)
  INCLUDE(${AMILab_DIR}/AMILabConfig.cmake)

  MESSAGE("AMILAB_SOURCE_DIR = ${AMILAB_SOURCE_DIR}")

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

  FIND_LIBRARY(Algorithms Algorithms
      DOC "AMILab Algorithms library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES Algorithms 
                    Algorithms/Debug 
                    Algorithms/Release)
