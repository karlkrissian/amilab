# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

INCLUDE( ${VTK_USE_FILE} )

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${Boost_INCLUDE_DIR}
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Zinrimage
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Filtrage
  )

SET(Crest_SRCS
    CreeCrest.cpp
    Crest.cpp
    MultiCrest2.cpp
    MultiCrest.cpp
)

SET(Crest_HDRS
	CreeCrest.hpp
	Crest.hpp
	MultiCrest.hpp
	MultiCrest2.hpp
)

SET(Crest_SRCS
     ${Crest_SRCS}
     ${Crest_HDRS}
)

my_add_library (Crest)
