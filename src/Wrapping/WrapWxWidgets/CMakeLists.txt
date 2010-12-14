# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

INCLUDE( ${wxWidgets_USE_FILE})

include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}
)

# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING AND AMI_WRAP_WXWIDGETS)
  # Generate XML file
  MESSAGE("Generate XML file")
  #
  IF   (wxWidgets_FOUND)
    IF   (wxWidgets_INCLUDE_DIRS)
      FOREACH( inc ${wxWidgets_INCLUDE_DIRS})
        SET( WX_INCLUDES  "-I\"${inc}\" ${WX_INCLUDES}" )
      ENDFOREACH(inc ${wxWidgets_INCLUDE_DIRS})
    ENDIF(wxWidgets_INCLUDE_DIRS)
    MESSAGE("WX_INCLUDES=${WX_INCLUDES}")

    IF   (wxWidgets_DEFINITIONS)
      FOREACH( def ${wxWidgets_DEFINITIONS})
        SET( WX_DEFS  "-D${def} ${WX_DEFS}" )
      ENDFOREACH(def ${wxWidgets_DEFINITIONS})
      MESSAGE("wxWidgets_DEFINITIONS=${wxWidgets_DEFINITIONS}")
    ENDIF(wxWidgets_DEFINITIONS)

    IF   (wxWidgets_DEFINITIONS_DEBUG)
      FOREACH( def ${wxWidgets_DEFINITIONS_DEBUG})
        SET( WX_DEFS  "-D${def} ${WX_DEFS}" )
      ENDFOREACH(def ${wxWidgets_DEFINITIONS_DEBUG})
      MESSAGE("wxWidgets_DEFINITIONS_DEBUG=${wxWidgets_DEFINITIONS_DEBUG}")
    ENDIF(wxWidgets_DEFINITIONS_DEBUG)

    IF   (wxWidgets_CXX_FLAGS)
      SET(WX_FLAGS "${CMAKE_CXX_FLAGS} ${wxWidgets_CXX_FLAGS}")
      MESSAGE("WX_FLAGS=${WX_FLAGS}")
    ENDIF(wxWidgets_CXX_FLAGS)
  ENDIF (wxWidgets_FOUND)
  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  SET(XML_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/wx_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h")
  SET( GCCXML_result 0)
  add_custom_command(OUTPUT ${XML_OUTPUT}
    COMMAND
      EXECUTE_PROCESS(COMMAND ${GCCXML}  
        -fxml=${XML_OUTPUT} 
        --gccxml-compiler cl
        -I${AMILAB_SOURCE_DIR}/Wrapping/include
        -I${AMILAB_SOURCE_DIR}/Common/include
        -I${AMILAB_SOURCE_DIR}/Language
        -I${CMAKE_BINARY_DIR}
        -I${Boost_INCLUDE_DIR}
        -II:/AMILabCompilationWindows/wxWidgets/wxWidgets-2.8.11/include
        -II:/AMILabCompilationWindows/wxWidgets/wxWidgets-2.8.11/lib/vc_lib/mswu
        ${WX_INCLUDES}
        ${WX_DEFS}
        ${XML_INPUT}
        OUTPUT_VARIABLE GCCXML_INFO
        ERROR_VARIABLE GCCXML_error
        RESULT_VARIABLE GCCXML_result
        OUTPUT_STRIP_TRAILING_WHITESPACE)
    DEPENDS ${XML_INPUT}
  )
 
  MESSAGE( "wxWidgets: GCCXML output file is ${XML_OUTPUT} ")
  MESSAGE( "wxWidgets: GCCXML output = ${GCCXML_INFO}") 
  MESSAGE( "wxWidgets: GCCXML error  = ${GCCXML_error}") 
  MESSAGE( "wxWidgets: GCCXML result = ${GCCXML_result}") 
  IF (${GCCXML_result} EQUAL 0)
    # Go for python wrapping
    SET(AMI_WRAPPER "I:/AMILabCompilationWindows/swig_amilab2/PythonWrap/parse_xml/parse_xml2.py")
    EXECUTE_PROCESS(COMMAND ${PYTHON_EXECUTABLE} 
      ${AMI_WRAPPER}
      OUTPUT_VARIABLE WRAPPER_INFO
      ERROR_VARIABLE  WRAPPER_error
      RESULT_VARIABLE WRAPPER_result
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    MESSAGE( "wxWidgets: parse_xml2.py output = ${WRAPPER_INFO}") 
    MESSAGE( "wxWidgets: parse_xml2.py error  = ${WRAPPER_error}") 
    MESSAGE( "wxWidgets: parse_xml2.py result = ${WRAPPER_result}") 
  ENDIF(${GCCXML_result} EQUAL 0)
ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_WXWIDGETS)

file(GLOB wx_HDRS  "${AMI_WXWIDGETS_VERSION}/*.h"  )
file(GLOB wx_SRCS  "${AMI_WXWIDGETS_VERSION}/*.cpp")

MESSAGE("\nWrapping wxWidgets...\n")
MESSAGE( "AMI_USE_PRECOMP_HEADERS = ${AMI_USE_PRECOMP_HEADERS} ")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_wx_source_code_list ${wx_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets")
  GenerateSourcesWrapping (new_wx_source_code_list source_path wx_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 
#MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${new_source_code_list}\n")

IF (AMI_USE_PRECOMP_HEADERS)
  SET(  WrapWxWidgets_SRCS
    wrap_wxsamples.cpp
    wrap_wxfunctions.cpp
    #${wx_SRCS}
    ${new_wx_source_code_list}
  )
ELSE(AMI_USE_PRECOMP_HEADERS)
  SET(  WrapWxWidgets_SRCS
    wrap_wxsamples.cpp
    wrap_wxfunctions.cpp
    ${new_wx_source_code_list}
  )
ENDIF(AMI_USE_PRECOMP_HEADERS)


SET(WrapWxWidgets_HDRS
  ../include/wrap_wxsamples.h
  ../include/wrap_wxfunctions.h
  ${wx_HDRS}
)


SET(WrapWxWidgets_SRCS
     ${WrapWxWidgets_SRCS}
     ${WrapWxWidgets_HDRS}
)

#MESSAGE("WrapWxWidgets_SRCS = ${WrapWxWidgets_SRCS}")

IF (AMI_USE_PRECOMP_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOMP_HEADERS)


my_add_library ( WrapWxWidgets)
