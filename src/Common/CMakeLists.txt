# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Common/include
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
  ami_format.cpp
  amilab_messages.cpp

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

  # from Plugin
  wxPluginManager.cpp
)

SET(Common_HDRS
  include/amilab_messages.h
	include/std_common.h
	include/vtk_common.h
	include/chaine.hpp
	include/DefineClass.hpp
	include/ensemble.hpp
	include/Erreurs.hpp
	include/Erreurs.Main.hpp
	include/ficparam.hpp
	include/MinHeap.hpp
	include/Pile.hpp
	include/StringUtils.hpp
	include/style.hpp
	include/TableauDyn.hpp
	include/Timing.hpp
	include/Voisins27.hpp
  include/amilab_boost.h
  include/ami_format.h

  # coming from previous Math dir
  include/complex.hpp
  include/Coordonnees.hpp
  include/CurvaturasPrincipales.hpp
  include/Eigen.hpp
  include/FloatMatrix.hpp
  include/math1.hpp

  # from AMImage
  include/amimage.hpp

  # from Coordonnees
  include/coord_image.hpp
  include/coord_op.hpp
  include/Point3D.hpp

  # from Crest
  include/CreeCrest.hpp
  include/Crest.hpp
  include/MultiCrest.hpp
  include/MultiCrest2.hpp

  # from Images
  include/imageextent.h
  include/inrimage.hpp
  include/ImageLinearInterpolator.h
  include/ImagePositionsBase.h
  include/ImagePositions.h
  include/ImagePositions.tpp
  include/InrImageIteratorBase.h
  include/InrImageIterator.h
  include/InrImageIterator.tpp
  include/InrImageConstIterator.h
  include/InrImageConstIterator.tpp

  # from Plugin
  include/wxPluginInterface.h
  include/wxPluginManager.h
  include/wxPluginBase.h
)

SET (Common_SRCS
     ${Common_SRCS}
     ${Common_HDRS}
)



# own macro to add the library and print the source files
# using xxx_SRCS variable
my_add_library (Common)
