# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.



# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  )

# Difficult to avoid wxwidgets: used in Variables.cpp
INCLUDE(${wxWidgets_USE_FILE})
INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${USE_ITK_FILE} )

SET(LanguageBase_SRCS
    ami_object.cpp
	BasicVariable.cpp
    CallBackAMIFunction.cpp
    DriverBase.cpp
    languagebase_global_export.cpp
    paramlist.cpp
    VarArray.cpp
    VarContexts.cpp
    Variable.cpp
    Variable_AMIObject.cpp
    Variable_bool.cpp
    Variable_double.cpp
    Variable_float.cpp
    Variable_FloatMatrix.cpp
    Variable_InrImage.cpp
    Variable_int.cpp
    Variable_long.cpp
    Variable_string.cpp
    Variable_uchar.cpp
    Variables.cpp

#    VarContexts.cpp
#    ImageStack.cpp
#    VarArray.cpp
#    driver.cc
#    language_global_export.cpp
)

SET(LanguageBase_HDRS
  ami_class.h
  ami_function.h
  ami_object.h
  AmiInstructionBlock.h
  BasicVariable.h
  CallBackAMIFunction.h
  DriverBase.h
  IdentifierInfo.h
  languagebase_global_import.h
  LanguageBaseConfigure.h
  paramlist.h
  VarArray.h
  VarContexts.hpp
  VarContexts.tpp
  Variable.hpp
  Variable.tpp
  Variable_AMIObject.h
  Variable_bool.h
  Variable_double.h
  Variable_float.h
  Variable_FloatMatrix.h
  Variable_InrImage.h
  Variable_int.h
  Variable_long.h
  Variable_string.h
  Variable_uchar.h
  Variables.hpp
  vartype.h
#    language_global_import.h
#    driver.h
#    IdentifierInfo.h
#    MatrixStack.h  
#    scanner.h
#    GLTransformStack.h
#    ImageStack.h
#    VariableStack.h
##    SurfStack.h
#    VarContexts.hpp
#    VarContexts.tpp
#    VarArray.h
)


 
IF(WIN32)
  set_source_files_properties(${Language_SRCS} PROPERTIES COMPILE_FLAGS "-DLanguageBase_EXPORTS")
ENDIF(WIN32)

SET(LanguageBase_SRCS
 ${LanguageBase_SRCS}
 ${LanguageBase_HDRS}
)
 
IF(WIN32)
  OPTION(LanguageBase_SHARED     "Compile LanguageBase library as shared" ON)
ELSE(WIN32)
  OPTION(LanguageBase_SHARED     "Compile LanguageBase library as shared" OFF)
ENDIF(WIN32)

IF (LanguageBase_SHARED)
  my_add_shared_library ( LanguageBase)
  INSTALL(TARGETS LanguageBase
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    #  COMPONENT applications
    #  BUNDLE DESTINATION 
    #${CMAKE_INSTALL_DESTINATION_ARGS}
  )
ELSE(LanguageBase_SHARED)
  my_add_library ( LanguageBase)
ENDIF(LanguageBase_SHARED)

target_link_libraries(LanguageBase 
  CommonBase
  Common
  WrapCommon
  ${wxWidgets_LIBRARIES}
  ${Boost_LIBRARIES}
)


#add_dependencies ( LanguageBase
#  WrapWxWidgets 
#)
