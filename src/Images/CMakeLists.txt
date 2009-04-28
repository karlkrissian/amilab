# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


INCLUDE( ${VTK_USE_FILE} )

# Make sure the compiler can find include files from our Hello library.
include_directories (
		    ${AMILAB_SOURCE_DIR}/Common
		    ${AMILAB_SOURCE_DIR}/Zinrimage
		    ${AMILAB_SOURCE_DIR}/Images
		    ${AMILAB_SOURCE_DIR}/Math
		    ${AMILAB_SOURCE_DIR}/AMImage
        ${Boost_INCLUDE_DIR}
		    )

SET(Images_SRCS
      inrimage_base.cpp
      inrimage.cpp
      inrimage_compressee.cpp
      inrimage_all.cpp
)

my_add_library (Images)
