# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/penguin
  ${GLEXT_INCLUDE_DIR}
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(penguin_SRCS
  penguin.cpp
  dxfrenderer.cpp
  trackball.c
)

my_add_library ( penguin)
