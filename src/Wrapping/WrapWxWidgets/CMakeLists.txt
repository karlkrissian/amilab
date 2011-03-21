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
  MESSAGE("\nWrapping wxWidgets...")

  # Generate XML file
  MESSAGE("Generate XML file")
  #
  IF   (wxWidgets_FOUND)
    IF   (wxWidgets_INCLUDE_DIRS)
      FOREACH( inc ${wxWidgets_INCLUDE_DIRS})
        SET( WX_INCLUDES  -I${inc}  ${WX_INCLUDES} )
      ENDFOREACH(inc ${wxWidgets_INCLUDE_DIRS})
    ENDIF(wxWidgets_INCLUDE_DIRS)
    MESSAGE("WX_INCLUDES=${WX_INCLUDES}")

    IF   (wxWidgets_DEFINITIONS)
      FOREACH( def ${wxWidgets_DEFINITIONS})
        SET( WX_DEFS  -D${def}  ${WX_DEFS} )
      ENDFOREACH(def ${wxWidgets_DEFINITIONS})
      MESSAGE("wxWidgets_DEFINITIONS=${wxWidgets_DEFINITIONS}")
    ENDIF(wxWidgets_DEFINITIONS)

    IF   (wxWidgets_DEFINITIONS_DEBUG)
      FOREACH( def ${wxWidgets_DEFINITIONS_DEBUG})
        SET( WX_DEFS  -D${def} ${WX_DEFS} )
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
  SET(WRAPWX_OUTDIR ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/Generated)
  CreateDirectory( ${WRAPWX_OUTDIR})

  SET(XML_OUTPUT "${WRAPWX_OUTDIR}/wx_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/wx_includes.h")
  SET( GCCXML_result 0)
#   add_custom_command(OUTPUT ${XML_OUTPUT}
#     COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${WX_INCLUDES}  ${WX_DEFS}  ${XML_INPUT}
#     DEPENDS ${XML_INPUT}
#   )
  MESSAGE("COMMAND: ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${WX_INCLUDES}  ${WX_DEFS}  ${XML_INPUT}")
  EXECUTE_PROCESS(
    COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${WX_INCLUDES}  ${WX_DEFS}  ${XML_INPUT}
  )

  # Generate the classes list

  # Read list of classes to wrap
  FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt" classes_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )
  STRING(REGEX REPLACE "[\r\n]" " " classes_string ${classes_txt} )

  SET(ANCESTORS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/Generated/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  MESSAGE("COMMAND: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} -q")
  EXECUTE_PROCESS(
    COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} -q
    OUTPUT_VARIABLE ancestors_result
    ERROR_VARIABLE ancestors_error
  )
  MESSAGE(" ancestors_result = ${ancestors_result} ")
  MESSAGE(" ancestors_error = ${ancestors_error} ")

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  # Read list of method pointers to wrap
  FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/methodpointers.txt" methodpointers_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )

  # Wrap all missing classes at once since it is now fast
  
  FOREACH( class ${ancestors_list})

    ClassUsedName( class m_class )
    IF( (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${m_class}.cpp) OR
        (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${m_class}.h))
      SET(OUTPUT_LIST ${WRAPWX_OUTDIR}/wrap_${m_class}.cpp ${OUTPUT_LIST})
      SET(OUTPUT_LIST ${WRAPWX_OUTDIR}/wrap_${m_class}.h ${OUTPUT_LIST})
      SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
    ENDIF( (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${m_class}.cpp) OR
        (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${m_class}.h))
  ENDFOREACH( class ${ancestors_list}) 

  FOREACH( method ${methodpointers_list})
    IF( (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${method}.cpp) OR
        (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${method}.h))
      SET(OUTPUT_LIST ${WRAPWX_OUTDIR}/wrap_${method}.cpp ${OUTPUT_LIST})
      SET(OUTPUT_LIST ${WRAPWX_OUTDIR}/wrap_${method}.h ${OUTPUT_LIST})
      SET(MISSING_METHODS ${method} ${MISSING_METHODS})
    ENDIF( (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${method}.cpp) OR
        (NOT EXISTS ${WRAPWX_OUTDIR}/wrap_${method}.h))
  ENDFOREACH( method ${methodpointers_list}) 

  FOREACH( MP ${methodpointers_list})
    SET( methodpointers_files ${methodpointers_files} ${WRAPWX_OUTDIR}/wrap_${MP}.h ${WRAPWX_OUTDIR}/wrap_${MP}.cpp )
  ENDFOREACH( MP ${methodpointers_list})

  LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)
  LIST(LENGTH MISSING_METHODS NB_MISSING_METHODS)

  #MESSAGE("Processing class ${class}")
  IF ((${NB_MISSING_CLASSES} GREATER 0) OR
      (${NB_MISSING_METHODS} GREATER 0) OR
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_wx.h) OR
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_wx.cpp))
#     FOREACH( class ${MISSING_CLASSES})
#       SET(MISSING_CLASSES_STRINGLIST ${MISSING_CLASSES_STRINGLIST} \"${class}\")
#     ENDFOREACH( class ${MISSING_CLASSES})
#     FOREACH( class ${ancestors_list})
#       SET(ANCESTORS_STRINGLIST ${ANCESTORS_STRINGLIST} \"${class}\")
#     ENDFOREACH( class ${ancestors_list})
    # Go for python wrapping
    ADD_CUSTOM_COMMAND(
        OUTPUT ${OUTPUT_LIST}  ${WRAPWX_OUTDIR}/addwrap_wx.h ${WRAPWX_OUTDIR}/addwrap_wx.cpp
        COMMAND
          ${PYTHON_EXECUTABLE}
            ${AMI_WRAPPER} ${XML_OUTPUT}
            --libname wx
            --filter "wx*"
            --classes ${MISSING_CLASSES}
            --methodpointers ${MISSING_METHODS}
            --available_classes ${ancestors_list} ${methodpointers_list}
            --outputdir "${WRAPWX_OUTDIR}"
            --addwrap
            --profile
            --templates
            --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
            -q
        #DEPENDS
        #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
        VERBATIM
    )
  ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR
        (${NB_MISSING_METHODS} GREATER 0) OR
        (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_wx.h) OR
        (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_wx.cpp))


ENDIF(AMI_ENABLE_WRAPPING AND AMI_WRAP_WXWIDGETS)

FOREACH( class ${ancestors_list} ${methodpointers_list} )
  ClassUsedName( class m_class )
  SET( wx_HDRS ${WRAPWX_OUTDIR}/wrap_${m_class}.h ${wx_HDRS})
  SET( wx_SRCS ${WRAPWX_OUTDIR}/wrap_${m_class}.cpp ${wx_SRCS})
ENDFOREACH( class ${ancestors_list} ${methodpointers_list} ) 
SET( wx_HDRS ${WRAPWX_OUTDIR}/addwrap_wx.h   ${wx_HDRS})
SET( wx_SRCS ${WRAPWX_OUTDIR}/addwrap_wx.cpp ${wx_SRCS})

# MESSAGE("${wx_HDRS}")

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
