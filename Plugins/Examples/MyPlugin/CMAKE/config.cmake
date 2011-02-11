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
    /home/proyectos/amilab/trunk-amilab/src
)

SET(AMILAB_BINARY_DIR
    /home/proyectos/amilab/trunk-amilab/build/release/
)

SET(AMILab_Header
    ${AMILAB_SOURCE_DIR}/Language
    ${AMILAB_SOURCE_DIR}/Common/include/
    ${AMILAB_SOURCE_DIR}/Wrapping/include/
    ${AMILAB_BINARY_DIR}
)
