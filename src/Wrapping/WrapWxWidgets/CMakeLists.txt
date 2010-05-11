# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Voxels
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/wxSamples/penguin
  ${AMILAB_SOURCE_DIR}/wxSamples/stctest
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapWxWidgets_SRCS
  wrap_wxsamples.cpp
  wrap_wxfunctions.cpp
  wrap_wxWindow.cpp
  wrap_wxHtmlWindow.cpp
  wrap_wxSizerItem.cpp
  wrap_wxSize.cpp
  wrap_wxColour.cpp
)

SET(WrapWxWidgets_HDRS
  wrap_wxsamples.h
  wrap_wxfunctions.h
  wrap_wxWindow.h
  wrap_wxHtmlWindow.h
  wrap_wxSizerItem.h
  wrap_wxSize.h
  wrap_wxColour.h
)

SET(WrapWxWidgets_SRCS
     ${WrapWxWidgets_SRCS}
     ${WrapWxWidgets_HDRS}
)

my_add_library ( WrapWxWidgets)
