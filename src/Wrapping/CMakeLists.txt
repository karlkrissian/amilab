# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/wxParams
  ${Boost_INCLUDE_DIR}
  )

INCLUDE( ${wxWidgets_USE_FILE})

add_subdirectory ( WrapITK )
add_subdirectory ( WrapVTK )
add_subdirectory ( WrapFilters )
