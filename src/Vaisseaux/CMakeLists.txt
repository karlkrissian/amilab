# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Algorithms
  )

SET(  Vessels_SRCS
  CalculBoules.cpp
  IntersectIsosurf.cpp
  IsoLigne.cpp
  Vaisseau.cpp
  CalculIsoLignes.cpp
  ImageVaisseaux.cpp
  IsoLigne2.cpp
  Voxel.cpp
)

SET(Vessels_HDRS
	CalculBoules.hpp
	CalculIsoLignes.hpp
	ImageVaisseaux.hpp
	InrViewIsoLignes.hpp
	IntersectIsosurf.hpp
	IsoLigne.hpp
	IsoLigne2.hpp
	Vaisseau.hpp
	Voxel.hpp
)

SET(Vessels_SRCS
     ${Vessels_SRCS}
     ${Vessels_HDRS}
)

my_add_library (Vessels)
