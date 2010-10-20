# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILAB_SOURCE_DIR}/Language
  ${GLEXT_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

SET(OpenGL_SRCS
)

SET(OpenGL_HDRS
)

SET(OpenGL_SRCS
     ${OpenGL_SRCS}
     ${OpenGL_HDRS}
)

my_add_library ( OpenGL)
