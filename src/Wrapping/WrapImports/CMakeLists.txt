# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Algorithms/Others
  ${AMILAB_SOURCE_DIR}/Algorithms/Segmentation
  ${AMILAB_SOURCE_DIR}
  ${PTHREADS_INCLUDE_DIR}
  ${wxParams_INCLUDE_DIRS}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapImports_SRCS
  wrap_imports.cpp
)

SET(WrapImports_HDRS
	../include/wrap_imports.h
)

SET(WrapImports_SRCS
     ${WrapImports_SRCS}
     ${WrapImports_HDRS}
)

my_add_library ( WrapImports)
