# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Line
  ${AMILAB_SOURCE_DIR}/Images
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Math
  ${AMILAB_SOURCE_DIR}/Zinrimage 
  ${AMILAB_SOURCE_DIR}/AMImage
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Coordonnees
  ${AMILAB_SOURCE_DIR}/ImageTool 
  ${AMILAB_SOURCE_DIR}/Crest 
  ${AMILAB_SOURCE_DIR}/Filtrage
  ${Boost_INCLUDE_DIR}
  )

SET(Line_SRCS
  reponse_cercle.cpp
)

my_add_library ( Line)
