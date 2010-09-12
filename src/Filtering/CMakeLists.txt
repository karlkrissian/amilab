# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Algorithms
  ${Boost_INCLUDE_DIR}
  )


SET(Filtering_SRCS
)

SET(Filtering_HDRS
)

SET(Filtering_SRCS
     ${Filtering_SRCS}
     ${Filtering_HDRS}
)

my_add_library (Filtering)
