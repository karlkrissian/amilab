# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Algorithms
  )

SET(  Vessels_SRCS
)

SET(Vessels_HDRS
)

SET(Vessels_SRCS
     ${Vessels_SRCS}
     ${Vessels_HDRS}
)

my_add_library (Vessels)
