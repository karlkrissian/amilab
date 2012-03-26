# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/Generated
)


INCLUDE( ${wxWidgets_USE_FILE})


# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING)
  # Generate XML file
  MESSAGE("*******************************")
  MESSAGE("Generate XML file for Language")
  MESSAGE("*******************************")

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

  SET(GCCXML_FLAGS "")
  IF(WIN32)
    SET(GCCXML_FLAGS ${GCCXML_FLAGS} -D_WIN32 -DWIN32 -D_MSC_VER -D__GCCXML__)
  ENDIF(WIN32)
  MESSAGE("GCCXML_FLAGS='${GCCXML_FLAGS}'")

  #
  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  SET(WrapLanguage_OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/Generated)
  CreateDirectory( ${WrapLanguage_OUTDIR})
  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://www.ctm.ulpgc.es/amilab_doxygen/${AMILAB_VERSION}/html/")
    SET(HTML_DIR "${WrapLanguage_OUTDIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)


  SET(XML_OUTPUT "${WrapLanguage_OUTDIR}/language_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/language_includes.h")
  SET( GCCXML_result 0)
#   add_custom_command(OUTPUT ${XML_OUTPUT}
#     COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES}  ${VTK_DEFS}  ${XML_INPUT}
#     DEPENDS ${XML_INPUT}
#   )
  MESSAGE("${GCCXML}  -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include -I${wxParams_INCLUDE_DIRS} -I${AMILAB_SOURCE_DIR}/LanguageBase -I${AMILAB_SOURCE_DIR}/Language   -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${WX_INCLUDES}   ${WX_DEFS} ${GCCXML_FLAGS} ${XML_INPUT}")
  execute_process(
    COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include -I${AMILAB_SOURCE_DIR}/CommonBase -I${AMILAB_SOURCE_DIR}/Common/include -I${AMILAB_SOURCE_DIR}/Graphic/include -I${wxParams_INCLUDE_DIRS} -I${AMILAB_SOURCE_DIR}/LanguageBase -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES} ${WX_INCLUDES} ${WX_DEFS} ${GCCXML_FLAGS} ${XML_INPUT}
    OUTPUT_VARIABLE gccxml_result
    ERROR_VARIABLE gccxml_error
  )
  MESSAGE(" gccxml_result = ${gccxml_result} ")
  MESSAGE(" gccxml_error = ${gccxml_error} ")
   
  # Generate the classes list

  # Read list of classes to wrap
  FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt" classes_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

  # Read wx ancestors list
  SET( WX_OUTDIR ${AMILab_BINARY_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}/Generated)

  FILE(READ "${WX_OUTDIR}/ancestors.txt" wx_ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" wx_ancestors_list ${wx_ancestors_txt} )


  SET(ANCESTORS_FILE "${CMAKE_CURRENT_BINARY_DIR}/Generated/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  IF(GENERATE_HTML_HELP)
    MESSAGE("command is: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"  -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"  -q
      OUTPUT_VARIABLE ancestors_result
      ERROR_VARIABLE ancestors_error
    )
  ELSE(GENERATE_HTML_HELP)
    MESSAGE("command is: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --templates --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/" --ancestors-file ${ANCESTORS_FILE} -q
      OUTPUT_VARIABLE ancestors_result
      ERROR_VARIABLE ancestors_error
    )
  ENDIF(GENERATE_HTML_HELP)
  MESSAGE(" ancestors_result = ${ancestors_result} ")
  MESSAGE(" ancestors_error = ${ancestors_error} ")

  FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

  # Read list of method pointers to wrap
  #FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/methodpointers.txt" methodpointers_txt)
  #STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )


  # Wrap all classes at once since it is now fast
  FOREACH( class ${ancestors_list})

    ClassUsedName( class m_class )

    # Check that the class is not already wrapped with wxWidgets wrapping
    IF ((NOT EXISTS ${WX_OUTDIR}/wrap_${m_class}.h))
      SET(compilation_list ${compilation_list} ${m_class})
      IF ( (NOT EXISTS ${WrapLanguage_OUTDIR}/wrap_${m_class}.cpp) OR
            (NOT EXISTS ${WrapLanguage_OUTDIR}/wrap_${m_class}.h))
        SET(OUTPUT_LIST ${WrapLanguage_OUTDIR}/wrap_${m_class}.cpp ${OUTPUT_LIST})
        SET(OUTPUT_LIST ${WrapLanguage_OUTDIR}/wrap_${m_class}.h ${OUTPUT_LIST})
        SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
      ENDIF( (NOT EXISTS ${WrapLanguage_OUTDIR}/wrap_${m_class}.cpp) OR
          (NOT EXISTS ${WrapLanguage_OUTDIR}/wrap_${m_class}.h))
#    ELSE((NOT EXISTS ${VTK_OUTDIR}/wrap_${class}.h))
    ENDIF((NOT EXISTS ${WX_OUTDIR}/wrap_${m_class}.h))
  ENDFOREACH( class ${ancestors_list}) 

  LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)

  MESSAGE("Processing classes ${ancestors_list} and addwrap")
  MESSAGE(" NB_MISSING_CLASSES=${NB_MISSING_CLASSES}")
  MESSAGE(" WrapLanguage_OUTDIR = ${WrapLanguage_OUTDIR} ")
  MESSAGE(" GENERATE_HTML_HELP = ${GENERATE_HTML_HELP}")
  IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WrapLanguage_OUTDIR}/addwrap_language.h) OR
      (NOT EXISTS ${WrapLanguage_OUTDIR}/addwrap_language.cpp))
    # Go for python wrapping
    IF(GENERATE_HTML_HELP)
      ADD_CUSTOM_COMMAND(
        OUTPUT  ${OUTPUT_LIST} ${WrapLanguage_OUTDIR}/addwrap_language.h ${WrapLanguage_OUTDIR}/addwrap_language.cpp
        COMMAND
          ${PYTHON_EXECUTABLE}
            ${AMI_WRAPPER} ${XML_OUTPUT}
  #          --filter "*"
            --libname language
            --classes ${MISSING_CLASSES}
            --available_classes ${ancestors_list} 
            --available_external_classes ${wx_ancestors_list}
            --outputdir "${WrapLanguage_OUTDIR}"
            --templates
            --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
            --addwrap
            --profile
            --generate-html             #flag to generate html help
            --url ${CLASSES_URL_LIST}   #base URL html help
            --outputhtmldir ${HTML_DIR} #HTML directory
            -q
          #DEPENDS
          #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
          VERBATIM
      )
    ELSE(GENERATE_HTML_HELP)
      ADD_CUSTOM_COMMAND(
        OUTPUT  ${OUTPUT_LIST} ${WrapLanguage_OUTDIR}/addwrap_language.h ${WrapLanguage_OUTDIR}/addwrap_language.cpp
        COMMAND
          ${PYTHON_EXECUTABLE}
            ${AMI_WRAPPER} ${XML_OUTPUT}
  #          --filter "*"
            --libname language
            --classes ${MISSING_CLASSES}
            --available_classes ${ancestors_list} 
            --available_external_classes ${wx_ancestors_list}
            --outputdir "${WrapLanguage_OUTDIR}"
            --templates
            --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
            --addwrap
            --profile
            -q
  #         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/classes.txt
          VERBATIM
        )
    ENDIF(GENERATE_HTML_HELP)
  ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WrapLanguage_OUTDIR}/addwrap_language.h) OR
      (NOT EXISTS ${WrapLanguage_OUTDIR}/addwrap_language.cpp))

ENDIF(AMI_ENABLE_WRAPPING)

FOREACH( class ${compilation_list}  ) 
  ClassUsedName( class m_class )
  SET( WrapLanguage_HDRS ${WrapLanguage_OUTDIR}/wrap_${m_class}.h ${WrapLanguage_HDRS})
  SET( WrapLanguage_SRCS ${WrapLanguage_OUTDIR}/wrap_${m_class}.cpp ${WrapLanguage_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( WrapLanguage_HDRS ${WrapLanguage_OUTDIR}/addwrap_language.h   ${WrapLanguage_HDRS})
SET( WrapLanguage_SRCS ${WrapLanguage_OUTDIR}/addwrap_language.cpp ${WrapLanguage_SRCS})

# file(GLOB language_HDRS  "*.h"  )
# file(GLOB language_SRCS  "*.cpp")

MESSAGE("---------------------")
MESSAGE("Wrapping Language ...")
MESSAGE("---------------------")


SET(WrapLanguage_SRCS
     ${WrapLanguage_SRCS}
     ${WrapLanguage_HDRS}
)

#MESSAGE("WrapLanguage_SRCS =  ${WrapLanguage_SRCS}")

my_add_library ( WrapLanguage)

add_dependencies ( WrapLanguage WrapWxWidgets)

