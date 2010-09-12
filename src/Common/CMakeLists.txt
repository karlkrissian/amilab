# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (${AMILAB_SOURCE_DIR}/Common)

INCLUDE( ${wxWidgets_USE_FILE})

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
)

SET (Common_SRCS
     ${Common_SRCS}
     ${Common_HDRS}
)

# own macro to add the library and print the source files
# using xxx_SRCS variable
my_add_library (Common)
