# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

INCLUDE( ${VTK_USE_FILE} )

# Make sure the compiler can find include files from our Hello library.

include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Algorithms
  ${Boost_INCLUDE_DIR}
  )


SET(Contours_SRCS
)

SET(Contours_HDRS
)

SET(Contours_SRCS
     ${Contours_SRCS}
     ${Contours_HDRS}
)

my_add_library (Contours)
