# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


INCLUDE( ${VTK_USE_FILE} )

# Make sure the compiler can find include files from our Hello library.
include_directories (
		    ${AMILAB_SOURCE_DIR}/Common
		    ${AMILAB_SOURCE_DIR}/Images
        ${AMILAB_SOURCE_DIR}/AMImage
        ${AMILAB_SOURCE_DIR}/Language
        ${AMILAB_SOURCE_DIR}/Wrapping/WrapITK
        ${Boost_INCLUDE_DIR}
		    )

SET(Images_SRCS
      inrimage.cpp
      ImageLinearInterpolator.cpp
#      inrimage_base.cpp
#      inrimage_compressee.cpp
#      inrimage_all.cpp
)

SET(Images_HDRS
	imageextent.h
	inrimage.hpp
  ImageLinearInterpolator.h
  ImagePositionsBase.h
  ImagePositions.h
  ImagePositions.tpp
  InrImageIteratorBase.h
  InrImageIterator.h
  InrImageIterator.tpp
  InrImageConstIterator.h
  InrImageConstIterator.tpp
)

SET(Images_SRCS
     ${Images_SRCS}
     ${Images_HDRS}
)

my_add_library (Images)
