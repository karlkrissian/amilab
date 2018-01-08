# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

INCLUDE( ${wxWidgets_USE_FILE})
INCLUDE( ${ITK_USE_FILE} )

include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}
  ${CMAKE_CURRENT_BINARY_DIR}/${AMI_WXWIDGETS_VERSION}/Generated
)

# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING AND AMI_WRAP_WXWIDGETS)
  #------------------------------------------------------------
  # Initialization
  #------------------------------------------------------------

  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)
  #SET(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/Generated")
  SET(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/${AMI_WXWIDGETS_VERSION}/Generated")
  CreateDirectory( ${GENERATED_DIR})
  SET(LIBNAME "wx")
  WRAP_INIT(" WxWidgets ${AMI_WXWIDGETS_VERSION}")

  #------------------------------------------------------------
  # Creating XML file
  #------------------------------------------------------------
  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapWxWidgets.cmake)
  GCCXML_USE_WXWIDGETS()

  SET(XML_OUTPUT "${GENERATED_DIR}/wx_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h")

  # Adding needed includes for wrapping ???
  SET(GCCXML_INCLUDES "-I${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}" ${GCCXML_INCLUDES} )
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Wrapping/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Common/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/CommonBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/LanguageBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Language")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/AMILab")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_BINARY_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${PROJECT_SOURCE_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${Boost_INCLUDE_DIR}")

  RUN_GCCXML( ${XML_INPUT} ${XML_OUTPUT})

  #------------------------------------------------------------
  # Setting up the Documentation information
  #------------------------------------------------------------

  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://docs.wxwidgets.org/stable/")
    SET(HTML_DIR "${GENERATED_DIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  #------------------------------------------------------------
  # Generating the classes, functions, etc...  lists
  #------------------------------------------------------------

  SET(WRAPPING_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION})

  # Read list of classes to wrap
  READ_CLASSES2(
    "${CMAKE_CURRENT_SOURCE_DIR}/classes_common.txt"
    "${WRAPPING_DIR}/classes.txt"
  ) 
  #READ_CLASSES(  "${WRAPPING_DIR}/classes.txt")
  # Read list of functions to wrap
  READ_FUNCTIONS("${WRAPPING_DIR}/functions.txt")

  # Read list of method pointers to wrap
  FILE(READ "${WRAPPING_DIR}/methodpointers.txt" methodpointers_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )

  #------------------------------------------------------------
  # Generating and reading ancestors
  #------------------------------------------------------------

  CREATE_ANCESTORS()

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  #------------------------------------------------------------
  # Checking for existing and missing files
  #------------------------------------------------------------

  # Wrap all missing classes at once since it is now fast
  #CHECK_WRAPPED_FILES( "${ancestors_list}"       "MISSING_CLASSES")
  #CHECK_WRAPPED_FILES( "${functions_list}"       "MISSING_FUNCTIONS")
  #CHECK_WRAPPED_FILES( "${methodpointers_list}"  "MISSING_METHODS")
  UPDATE_OUTPUT_LIST( "${ancestors_list}"     )
  UPDATE_OUTPUT_LIST( "${functions_list}"     )
  UPDATE_OUTPUT_LIST( "${methodpointers_list}")

  FOREACH( MP ${methodpointers_list})
    SET( methodpointers_files ${methodpointers_files} ${GENERATED_DIR}/wrap_${MP}.h ${GENERATED_DIR}/wrap_${MP}.cpp )
  ENDFOREACH( MP ${methodpointers_list})
  
  #------------------------------------------------------------
  # Create the rule that wraps the code
  #------------------------------------------------------------

  SET(LIBFILTER "wx*")
  SET(NO_METHOD_HELP true)

  WRAP_CODE()

ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_WXWIDGETS)

FOREACH( class ${ancestors_list} ${methodpointers_list} ${functions_list})
  ClassUsedName( class m_class )
  SET( wx_HDRS ${GENERATED_DIR}/wrap_${m_class}.h ${wx_HDRS})
  SET( wx_SRCS ${GENERATED_DIR}/wrap_${m_class}.cpp ${wx_SRCS})
ENDFOREACH( class ${ancestors_list} ${methodpointers_list} ) 
SET( wx_HDRS ${GENERATED_DIR}/addwrap_wx.h   ${wx_HDRS})
SET( wx_SRCS ${GENERATED_DIR}/addwrap_wx.cpp ${wx_SRCS})

# MESSAGE("${wx_HDRS}")

WRAP_MESSAGE("----------------------")
WRAP_MESSAGE("Wrapping wxWidgets... ")
WRAP_MESSAGE("----------------------")

WRAP_MESSAGE( "AMI_USE_PRECOMP_HEADERS = ${AMI_USE_PRECOMP_HEADERS} ")

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
  wxAmiEventHandler.h
  ${AMI_WXWIDGETS_VERSION}/wx_includes.h
  ${wx_HDRS}
)


SET(WrapWxWidgets_SRCS
     ${WrapWxWidgets_SRCS}
     ${WrapWxWidgets_HDRS}
)

#MESSAGE("WrapWxWidgets_SRCS = ${WrapWxWidgets_SRCS}")

IF (AMI_USE_PRECOMP_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Wrapping/include/wrap_prec.hpp WrapVTK_SRCS)
    #ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Common/include/DefineClass.hpp WrapVTK_SRCS)
    #ADD_PCH_RULE(${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOMP_HEADERS)

# Give the option to compile as shared, but need to write dependencies for 
# Windows and MacOS ...
# however speeds up the linking ...
OPTION(WrapWxWidgets_SHARED     "Compile WrapWxWidgets library as shared" OFF)

CONFIGURE_FILE(
    ${AMILab_SOURCE_DIR}/Wrapping/include/WrapWxWidgetsConfigure.h.in
    ${AMILab_BINARY_DIR}/WrapWxWidgetsConfigure.h)


IF(WrapWxWidgets_SHARED)
  my_add_shared_library ( WrapWxWidgets)
ELSE(WrapWxWidgets_SHARED)
  my_add_library ( WrapWxWidgets)
ENDIF(WrapWxWidgets_SHARED)

SET(amilab_ownlibs
  LanguageBase
  CommonBase
  WrapCommon
)

target_link_libraries( WrapWxWidgets
  ${amilab_ownlibs}
  ${wxWidgets_LIBRARIES}
  ${Boost_LIBRARIES}
)

IF(MSVC)
  # SET INCREMENTAL LINKING: much faster ...
  set_target_properties( WrapWxWidgets 
    PROPERTIES LINK_FLAGS_RELEASE "/INCREMENTAL:YES")
ENDIF(MSVC)
