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
  ${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison
  ${AMILAB_SOURCE_DIR}/DistTransf
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapITK
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapFilters
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSystem
  ${AMILAB_SOURCE_DIR}/penguin
  ${AMILAB_SOURCE_DIR}/Algorithms/Basic
  ${AMILAB_SOURCE_DIR}/Algorithms/Graph
  ${AMILAB_SOURCE_DIR}/Algorithms/Denoising
  ${AMILAB_SOURCE_DIR}/
  )

INCLUDE( ${VTK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})

SET(Language_SRCS
    driver.cc
    VarContexts.cpp
    Variable.cpp
    Variables.cpp
    paramlist.cpp
    ImageStack.cpp
)

IF(AMI_USE_FLEXBISON)

  BISON_TARGET_option_extraopts("-t  -dv")

  BISON_TARGET(improcessbison
    ${AMILAB_SOURCE_DIR}/Language/improcess_bison.ypp
    ${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_bison.tab.cpp
  )

  FLEX_TARGET(improcessflex
  ${AMILAB_SOURCE_DIR}/Language/improcess_flex.lpp
  ${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_flex.cpp)

  ADD_FLEX_BISON_DEPENDENCY(improcessflex improcessbison)

  SET(Language_SRCS
    ${BISON_improcessbison_OUTPUTS}
    ${FLEX_improcessflex_OUTPUTS}
    ${Language_SRCS}
  )
  
ELSE(AMI_USE_FLEXBISON)
 
  # find FlexLexer.h
  include_directories(${AMILAB_SOURCE_DIR}/Language/FlexInclude)

   SET( FLEXBISON_OUTPUTS
		${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_bison.tab.cpp
		${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_flex.cpp
	)
 
   SET(Language_SRCS
     ${FLEXBISON_OUTPUTS}
     ${Language_SRCS}
   )
 

ENDIF(AMI_USE_FLEXBISON)

my_add_library ( Language)
