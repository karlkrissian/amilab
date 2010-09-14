# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/Wrapping/include
)

INCLUDE( ${wxWidgets_USE_FILE})

INCLUDE( ${VTK_USE_FILE} )

SET(Common_SRCS
  chaine.cpp 
  Timing.cpp 
  Erreurs.cpp 
  ficparam.cpp  
  StringUtils.cpp
  message_dialog.cpp

  # coming from previous Math dir
  CurvaturasPrincipales.cpp
  Eigen.cpp
  FloatMatrix.cpp
  math1.cpp

  # from AMImage
  amimage.cpp

  # from Coordonnees
  coord_image.cpp  
  Point3D.cpp

  # from Crest
  Crest/CreeCrest.cpp
  Crest/Crest.cpp
  Crest/MultiCrest2.cpp
  Crest/MultiCrest.cpp

  # from Images
  Images/inrimage.cpp
  Images/ImageLinearInterpolator.cpp
  #      inrimage_base.cpp
  #      inrimage_compressee.cpp
  #      inrimage_all.cpp
)

SET(Common_HDRS
	amilab_messages.h
	std_common.h
	vtk_common.h
	chaine.hpp
	DefineClass.hpp
	ensemble.hpp
	Erreurs.hpp
	Erreurs.Main.hpp
	ficparam.hpp
	MinHeap.hpp
	Pile.hpp
	StringUtils.hpp
	style.hpp
	TableauDyn.hpp
	Timing.hpp
	Voisins27.hpp
  amilab_boost.h

  # coming from previous Math dir
  complex.hpp
  Coordonnees.hpp
  CurvaturasPrincipales.hpp
  Eigen.hpp
  FloatMatrix.hpp
  math1.hpp

  # from AMImage
  amimage.hpp

  # from Coordonnees
  coord_image.hpp
  coord_op.hpp
  Point3D.hpp

  # from Crest
  CreeCrest.hpp
  Crest.hpp
  MultiCrest.hpp
  MultiCrest2.hpp

  # from Images
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

SET (Common_SRCS
     ${Common_SRCS}
     ${Common_HDRS}
)



# own macro to add the library and print the source files
# using xxx_SRCS variable
my_add_library (Common)
