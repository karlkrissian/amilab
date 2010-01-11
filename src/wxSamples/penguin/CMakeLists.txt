# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/wxSamples/penguin
  ${GLEXT_INCLUDE_DIR}
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(penguin_SRCS
  penguin.cpp
  dxfrenderer.cpp
  trackball.c
)

SET(penguin_HDRS
	dxfrenderer.h
	penguin.h
	trackball.h
)

SET(penguin_SRCS
     ${penguin_SRCS}
     ${penguin_HDRS}
)

my_add_library ( penguin)
