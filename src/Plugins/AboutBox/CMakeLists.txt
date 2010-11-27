#==============================================================================
# AboutBox
#
# Description: A plugin that display the About dialog box.
#
# Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

#source code:
INCLUDE_DIRECTORIES (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/../Pixmaps
)

SET(AboutBoxPlugin_SRCS
  AboutBox.cpp
)

SET(AboutBoxPlugin_HDRCS
  AboutBox.h
#  include/PluginInterface.h
)

SET(Plugin_SRCS
  ${AboutBoxPlugin_HDRCS}
  ${AboutBoxPlugin_SRCS}
)

#include wxWidgets:
INCLUDE(${wxWidgets_USE_FILE})

#compile the plugin:
#my_add_library (AboutBoxPluginExample)
ADD_LIBRARY(AboutBoxPluginExample SHARED ${Plugin_SRCS})
TARGET_LINK_LIBRARIES(AboutBoxPluginExample ${wxWidgets_LIBRARIES})
