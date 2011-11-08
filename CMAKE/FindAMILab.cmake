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

  IF (NEED_WX_WRAPPING)
    SET(AMILab_PATHS
      ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
      ${AMILab_PATHS}
      )
    MESSAGE(" WxWidgets wrapping path is ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_WXWIDGETS_VERSION}/Generated")
  ENDIF(NEED_WX_WRAPPING)

  MESSAGE("AMILab_PATHS = ${AMILab_PATHS}")

  FIND_LIBRARY(CommonBase CommonBase
      DOC "AMILab CommonBase library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        CommonBase
        CommonBase/Debug
        CommonBase/Release
  )

  FIND_LIBRARY(Common Common
      DOC "AMILab Common library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Common Common/Debug 
        Common/Release)

  FIND_LIBRARY(LanguageBase LanguageBase
      DOC "AMILab LanguageBase library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        LanguageBase LanguageBase/Debug LanguageBase/Release)

  FIND_LIBRARY(Language Language
      DOC "AMILab Language library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Language Language/Debug Language/Release)

  FIND_LIBRARY(WrapCommon WrapCommon
      DOC "AMILab WrapCommon library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Wrapping/WrapCommon 
        Wrapping/WrapCommon/Debug 
        Wrapping/WrapCommon/Release)

  FIND_LIBRARY(WrapLanguage WrapLanguage
      DOC "AMILab WrapLanguage library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Wrapping/WrapLanguage 
        Wrapping/WrapLanguage/Debug 
        Wrapping/WrapLanguage/Release)

  FIND_LIBRARY(Algorithms Algorithms
      DOC "AMILab Algorithms library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Algorithms 
        Algorithms/Debug 
        Algorithms/Release)

  FIND_LIBRARY(Graphic Graphic
      DOC "AMILab Graphic library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Graphic 
        Graphic/Debug 
        Graphic/Release)

  FIND_LIBRARY(AMILab AMILab
      DOC "AMILab AMILab library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        AMILab 
        AMILab/Debug 
        AMILab/Release)

  FIND_LIBRARY(wxParams wxParams
      DOC "AMILab wxParams library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        binary_dir
        binary_dir/Debug
        binary_dir/Release
      )

  IF (NEED_WX_WRAPPING)
    FIND_LIBRARY(WrapWxWidgets WrapWxWidgets
        DOC "AMILab WrapWxWidgets library"
        PATHS ${AMILAB_BINARY_DIR}
        PATH_SUFFIXES 
          Bin/Debug
          Bin/Release
          Wrapping/WrapWxWidgets/
          Wrapping/WrapWxWidgets/Debug
          Wrapping/WrapWxWidgets/Release)
  ENDIF (NEED_WX_WRAPPING)

  IF (NEED_VTK_WRAPPING)
    FIND_LIBRARY(WrapVTK WrapVTK
        DOC "AMILab WrapVTK library"
        PATHS ${AMILAB_BINARY_DIR}
        PATH_SUFFIXES 
          Bin/Debug
          Bin/Release
          Wrapping/WrapVTK
          Wrapping/WrapVTK/Debug
          Wrapping/WrapVTK/Release)
  ENDIF (NEED_VTK_WRAPPING)

  FIND_LIBRARY(WrapInterface WrapInterface
      DOC "AMILab WrapInterface library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Wrapping/WrapInterface
        Wrapping/WrapInterface/Debug
        Wrapping/WrapInterface/Release)

  FIND_LIBRARY(WrapImports WrapImports
      DOC "AMILab WrapImports library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        Wrapping/WrapImports
        Wrapping/WrapImports/Debug
        Wrapping/WrapImports/Release)

  FIND_LIBRARY(myVTK4 myVTK4
      DOC "AMILab myVTK4 library"
      PATHS ${AMILAB_BINARY_DIR}
      PATH_SUFFIXES 
        Bin/Debug
        Bin/Release
        myVTK4
        myVTK4/Debug
        myVTK4/Release)

ENDIF(AMILab_FOUND)
