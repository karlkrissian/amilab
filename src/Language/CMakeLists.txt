# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.



# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated
  ${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/libamiFluid
  ${AMILAB_SOURCE_DIR}/libamiFluid/opticflow/
  ${AMILAB_SOURCE_DIR}/JavierHornSchunck
  ${AMILAB_SOURCE_DIR}/
  ${wxParams_INCLUDE_DIRS}
  ${FLEX_INCLUDE_DIR}
  )

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${ITK_USE_FILE} )
INCLUDE(${wxWidgets_USE_FILE})


SET(Language_SRCS
    ImageStack.cpp
    driver.cc
    language_global_export.cpp
)

SET(Language_HDRS
    LanguageConfigure.h
    language_global_import.h
    driver.h
    MatrixStack.h  
    scanner.h
    GLTransformStack.h
    ImageStack.h
    VariableStack.h
#    SurfStack.h
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
#BISON_${Name}_COMPILE_FLAGS

  BISON_TARGET(improcessbison
    ${AMILAB_SOURCE_DIR}/Language/improcess_bison.ypp
    ${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_bison.tab.cpp
    COMPILE_FLAGS ${bison_options}
 )
 
  FLEX_TARGET(improcessflex
  ${AMILAB_SOURCE_DIR}/Language/improcess_flex.lpp
  ${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_flex.cpp)

  ADD_FLEX_BISON_DEPENDENCY(improcessflex improcessbison)

  
  #MESSAGE("******************** Language_SRCS = ${Language_SRCS} *****************************")
  IF(WIN32)
    set_source_files_properties(${Language_SRCS} PROPERTIES COMPILE_FLAGS "-DLanguage_EXPORTS")
    set_source_files_properties(${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_flex.cpp PROPERTIES COMPILE_FLAGS "-DLanguage_EXPORTS")
    set_source_files_properties(${AMILAB_SOURCE_DIR}/Language/GeneratedFlexBison/improcess_bison.tab.cpp PROPERTIES COMPILE_FLAGS "-DLanguage_EXPORTS")
  ENDIF(WIN32)

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
  )
  
  IF(WIN32)
    set_source_files_properties(${Language_SRCS} PROPERTIES COMPILE_FLAGS "-DLanguage_EXPORTS")
  ENDIF(WIN32)

   SET(Language_SRCS
     ${Language_SRCS}
     ${Language_HDRS}
   )
 

ENDIF(AMI_USE_FLEXBISON)


#ADD_PCH_RULE( ${AMILAB_SOURCE_DIR}/Language/Variable.hpp Language_SRCS)
#ADD_PCH_RULE( ${AMILAB_SOURCE_DIR}/Common/include/amilab_messages.h Language_SRCS)
#ADD_PCH_RULE( ${AMILAB_SOURCE_DIR}/Common/include/DefineClass.hpp Language_SRCS)

my_add_library ( Language)

target_link_libraries(Language 
  AMILab
  Common
  Graphic
  vtkIO 
  vtkImaging
  wxStcFrame
  myVTK4
  WrapVTK
  ${wxWidgets_LIBRARIES}
  ${Boost_LIBRARIES}
)


add_dependencies ( Language 
  WrapWxWidgets 
)
