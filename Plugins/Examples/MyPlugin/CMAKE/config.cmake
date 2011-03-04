#==============================================================================
# Plugin
#
# Description: Specifies the path where AMILab header files.
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

SET(AMILAB_SOURCE_DIR
    /Users/administrador/Desktop/Daniel/src
    CACHE STRING "AMILab source path"
)

SET(AMILAB_BINARY_DIR
    /Users/administrador/Desktop/Daniel/build/Release
    CACHE STRING "AMILab binary path"
)

SET(AMILab_Header
    ${AMILAB_SOURCE_DIR}/Language
    ${AMILAB_SOURCE_DIR}/Common/include/
    ${AMILAB_SOURCE_DIR}/Wrapping/include/
    ${AMILAB_BINARY_DIR}
)
