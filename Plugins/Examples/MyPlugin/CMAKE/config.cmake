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

SET(AMILab_Header
    ${AMILAB_SOURCE_DIR}/Language
    ${AMILAB_SOURCE_DIR}/Common/include
    ${AMILAB_SOURCE_DIR}/Wrapping/include
    ${AMILAB_SOURCE_DIR}/Graphic/include
    ${AMILAB_SOURCE_DIR}/Algorithms/include
    ${AMILAB_SOURCE_DIR}/wxParams
    ${AMILAB_SOURCE_DIR}/../wxParams/src
    ${AMILAB_SOURCE_DIR}/AMILab
    ${AMILAB_SOURCE_DIR}

    ${AMILAB_BINARY_DIR}
)
