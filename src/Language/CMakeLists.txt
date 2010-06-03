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
  ${AMILAB_SOURCE_DIR}/Filtering
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
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapCommon
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapITK
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapFilters
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapSystem
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapAMIFluid
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWII
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapInterface
  ${AMILAB_SOURCE_DIR}/wxSamples/penguin
  ${AMILAB_SOURCE_DIR}/wxStcFrame
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
    BasicVariable.cpp
    Variable.cpp
    Variable_long.cpp
    Variable_float.cpp
    Variable_double.cpp
    Variable_InrImage.cpp
    Variable_string.cpp
    Variable_FloatMatrix.cpp
    Variables.cpp
    paramlist.cpp
    ImageStack.cpp
    VarArray.cpp
)

SET(Language_HDRS
    ami_class.h
    AmiInstructionBlock.h
    driver.h
    IdentifierInfo.h
    MatrixStack.h  
    scanner.h
    vartype.h
    ami_function.h
    ami_object.h
    ami_cpp_object.h
    GLTransformStack.h
    ImageStack.h
    VariableStack.h
    paramlist.h
    SurfStack.h
    VarContexts.hpp
    VarContexts.tpp
    BasicVariable.h
    Variable.hpp
    Variable_long.h
    Variable_float.h
    Variable_double.h
    Variable_InrImage.h
    Variable_string.h
    Variable_FloatMatrix.h
    Variables.hpp
    VarArray.h
)

SET(Language_BISONFLEX_SRCS
  improcess_bison.ypp
  improcess_flex.lpp
)

IF(AMI_USE_FLEXBISON)


  SET(bison_options "-dv")
  IF(AMI_BISON_DEBUG)
    SET(bison_options "-t ${bison_options}")
  ENDIF(AMI_BISON_DEBUG)

  BISON_TARGET_option_extraopts(${bison_options})

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
    ${Language_BISONFLEX_SRCS}
    ${Language_HDRS}
  )

  IF(AMI_BISON_DEBUG)
    SET_SOURCE_FILES_PROPERTIES( ${Language_SRCS}
    PROPERTIES COMPILE_FLAGS -DYYDEBUG=1)
  ENDIF(AMI_BISON_DEBUG)
  
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
     ${Language_HDRS}
   )
 

ENDIF(AMI_USE_FLEXBISON)

my_add_library ( Language)
