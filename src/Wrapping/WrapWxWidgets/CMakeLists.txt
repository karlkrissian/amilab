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
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/Generated
)

# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING AND AMI_WRAP_WXWIDGETS)
  MESSAGE("\n*********************")
  MESSAGE("Creating wxWidgets wrapping...")
  MESSAGE("*********************\n")

  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)
  INCLUDE(${AMILAB_SOURCE_DIR}/../CMAKE/amiWrapWxWidgets.cmake)
  GCCXML_USE_WXWIDGETS()

  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  SET(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/Generated")
  CreateDirectory( ${GENERATED_DIR})
  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://docs.wxwidgets.org/stable/")
    SET(HTML_DIR "${GENERATED_DIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)

  SET(XML_OUTPUT "${GENERATED_DIR}/wx_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h")

  # Adding needed includes for wrapping ???
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Wrapping/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Common/include")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/CommonBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/LanguageBase")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${AMILAB_SOURCE_DIR}/Language")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${CMAKE_BINARY_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${PROJECT_SOURCE_DIR}")
  SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${Boost_INCLUDE_DIR}")

  RUN_GCCXML( ${XML_INPUT} ${XML_OUTPUT})

  # Generate the classes list

  # Read list of classes to wrap
  READ_CLASSES(  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt")
  # Read list of functions to wrap
  READ_FUNCTIONS("${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/functions.txt")

  SET(LIBNAME "wx")
  CREATE_ANCESTORS()

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  # Read list of method pointers to wrap
  FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/methodpointers.txt" methodpointers_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )

  # Wrap all missing classes at once since it is now fast
  
  CHECK_WRAPPED_FILES( "${ancestors_list}"       "MISSING_CLASSES")
  CHECK_WRAPPED_FILES( "${functions_list}"       "MISSING_FUNCTIONS")
  CHECK_WRAPPED_FILES( "${methodpointers_list}"  "MISSING_METHODS")

  MESSAGE("MISSING_CLASSES   = ${MISSING_CLASSES}")
  MESSAGE("MISSING_FUNCTIONS = ${MISSING_FUNCTIONS}")
  MESSAGE("MISSING_METHODS   = ${MISSING_METHODS}")

  FOREACH( MP ${methodpointers_list})
    SET( methodpointers_files ${methodpointers_files} ${GENERATED_DIR}/wrap_${MP}.h ${GENERATED_DIR}/wrap_${MP}.cpp )
  ENDFOREACH( MP ${methodpointers_list})

  LIST(LENGTH MISSING_CLASSES   NB_MISSING_CLASSES)
  LIST(LENGTH MISSING_METHODS   NB_MISSING_METHODS)
  LIST(LENGTH MISSING_FUNCTIONS NB_MISSING_FUNCTIONS)
  
  SET(LIBFILTER "wx*")
  WRAP_CODE()

# #MESSAGE("Processing class ${class}")
#   IF ((${NB_MISSING_CLASSES} GREATER 0) OR
#       (${NB_MISSING_METHODS} GREATER 0) OR
#       (${NB_MISSING_FUNCTIONS} GREATER 0) OR
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_wx.h) OR
#       (NOT EXISTS ${GENERATED_DIR}/addwrap_wx.cpp))
# #     FOREACH( class ${MISSING_CLASSES})
# #       SET(MISSING_CLASSES_STRINGLIST ${MISSING_CLASSES_STRINGLIST} \"${class}\")
# #     ENDFOREACH( class ${MISSING_CLASSES})
# #     FOREACH( class ${ancestors_list})
# #       SET(ANCESTORS_STRINGLIST ${ANCESTORS_STRINGLIST} \"${class}\")
# #     ENDFOREACH( class ${ancestors_list})
#     # Go for python wrapping
#     IF(GENERATE_HTML_HELP)
#       ADD_CUSTOM_COMMAND(
#           OUTPUT ${OUTPUT_LIST}  ${GENERATED_DIR}/addwrap_wx.h ${GENERATED_DIR}/addwrap_wx.cpp
#           COMMAND
#             ${PYTHON_EXECUTABLE}
#               ${AMI_WRAPPER} ${XML_OUTPUT}
#               --libname wx
#                --filter "${LIBFILTER}"
#               --classes ${MISSING_CLASSES}
#               --methodpointers ${MISSING_METHODS}
#               --available_classes ${ancestors_list} ${methodpointers_list}
#               --functions ${MISSING_FUNCTIONS}
#               --available_functions ${functions_list}
#               --outputdir "${GENERATED_DIR}"
#               --addwrap
#               --profile
#               --templates
#               --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
#               --generate-html             #flag to generate html help
#               --url ${CLASSES_URL_LIST}   #base URL html help
#               --outputhtmldir ${HTML_DIR} #HTML directory
#               -q
#           #DEPENDS
#           #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
#           VERBATIM
#       )
#     ELSE(GENERATE_HTML_HELP)
#       ADD_CUSTOM_COMMAND(
#           OUTPUT ${OUTPUT_LIST}  ${GENERATED_DIR}/addwrap_wx.h ${GENERATED_DIR}/addwrap_wx.cpp
#           COMMAND
#             ${PYTHON_EXECUTABLE}
#               ${AMI_WRAPPER} ${XML_OUTPUT}
#               --libname wx
#               --filter "wx*"
#               --classes ${MISSING_CLASSES}
#               --methodpointers ${MISSING_METHODS}
#               --available_classes ${ancestors_list} ${methodpointers_list}
#               --functions ${MISSING_FUNCTIONS}
#               --available_functions ${functions_list}
#               --outputdir "${GENERATED_DIR}"
#               --addwrap
#               --profile
#               --templates
#               --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
#               -q
#           #DEPENDS
#           #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
#           VERBATIM
#       )
#     ENDIF(GENERATE_HTML_HELP)
#   ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR
#         (${NB_MISSING_METHODS} GREATER 0) OR
#         (${NB_MISSING_FUNCTIONS} GREATER 0) OR
#         (NOT EXISTS ${GENERATED_DIR}/addwrap_wx.h) OR
#         (NOT EXISTS ${GENERATED_DIR}/addwrap_wx.cpp))


ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_WXWIDGETS)

FOREACH( class ${ancestors_list} ${methodpointers_list} ${functions_list})
  ClassUsedName( class m_class )
  SET( wx_HDRS ${GENERATED_DIR}/wrap_${m_class}.h ${wx_HDRS})
  SET( wx_SRCS ${GENERATED_DIR}/wrap_${m_class}.cpp ${wx_SRCS})
ENDFOREACH( class ${ancestors_list} ${methodpointers_list} ) 
SET( wx_HDRS ${GENERATED_DIR}/addwrap_wx.h   ${wx_HDRS})
SET( wx_SRCS ${GENERATED_DIR}/addwrap_wx.cpp ${wx_SRCS})

# MESSAGE("${wx_HDRS}")

MESSAGE("----------------------")
MESSAGE("Wrapping wxWidgets... ")
MESSAGE("----------------------")

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
  ${AMI_WXWIDGETS_VERSION}/wxAmiEventHandler.h
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
    ADD_PCH_RULE(${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOMP_HEADERS)


my_add_library ( WrapWxWidgets)
