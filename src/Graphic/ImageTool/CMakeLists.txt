# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/wxCode/wxTreeListCtrl
  ${wxParams_INCLUDE_DIRS}
  )

INCLUDE(${wxWidgets_USE_FILE})

SET(ImageTool_SRCS
)

SET(ImageTool_HDRS
)

SET(ImageTool_SRCS
     ${ImageTool_SRCS}
     ${ImageTool_HDRS}
)

my_add_library (ImageTool)
