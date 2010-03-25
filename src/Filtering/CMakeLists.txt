# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Zinrimage
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Filtering
  ${Boost_INCLUDE_DIR}
  )


SET(Filtering_SRCS
      bruit.cpp
      DeriveesLissees.cpp
      GaussianFilter.cpp
      filtrage_rec.cpp
      GeneralGaussianFilter.cpp
)

SET(Filtering_HDRS
  bruit.hpp
  DeriveesLissees.hpp
  GaussianFilter.h
  filtrage_rec.hpp
  GeneralGaussianFilter.h
  filtre_param.hpp
)

SET(Filtering_SRCS
     ${Filtering_SRCS}
     ${Filtering_HDRS}
)

my_add_library (Filtering)
