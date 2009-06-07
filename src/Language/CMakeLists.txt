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
  ${AMILAB_SOURCE_DIR}/Filtrage
  ${AMILAB_SOURCE_DIR}/Vaisseaux
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/ImageTool
  ${AMILAB_SOURCE_DIR}/OpenGL
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/Voxels
  ${AMILAB_SOURCE_DIR}/Crest
  ${AMILAB_SOURCE_DIR}/Graph
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Line
  ${AMILAB_SOURCE_DIR}/myVTK4
  ${AMILAB_SOURCE_DIR}/SplineThevenaz
  ${AMILAB_SOURCE_DIR}/Contours
  ${AMILAB_SOURCE_DIR}/libamiFluid
  ${AMILAB_SOURCE_DIR}/libamiFluid/opticflow/
  ${AMILAB_SOURCE_DIR}/JavierHornSchunck
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/DistTransf
  ${AMILAB_SOURCE_DIR}/WrapITK
  ${AMILAB_SOURCE_DIR}/penguin
  ${AMILAB_SOURCE_DIR}/Algorithms/Denoising
  ${AMILAB_SOURCE_DIR}/
  )

INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

BISON_TARGET_option_extraopts("-t  -dv")

BISON_TARGET(improcessbison
  ${AMILAB_SOURCE_DIR}/Language/improcess_bison.ypp
  ${AMILAB_SOURCE_DIR}/Language/improcess_bison.tab.cpp
  )

# IF (WIN32)
# 
#   SET(Language_SRCS
#     ${BISON_improcessbison_OUTPUTS}
#     driver.cc
#     improcess_flex.cpp
#     VarContexts.cpp
#     Variable.cpp
#     Variables.cpp
#   )
# 
# ELSE (WIN32)

  FLEX_TARGET(improcessflex
  ${AMILAB_SOURCE_DIR}/Language/improcess_flex.lpp
  ${AMILAB_SOURCE_DIR}/Language/improcess_flex.cpp)

  ADD_FLEX_BISON_DEPENDENCY(improcessflex improcessbison)

  SET(Language_SRCS
    ${BISON_improcessbison_OUTPUTS}
    ${FLEX_improcessflex_OUTPUTS}
    driver.cc
    VarContexts.cpp
    Variable.cpp
    Variables.cpp
    paramlist.cpp
  )

# ENDIF (WIN32)

my_add_library ( Language)
