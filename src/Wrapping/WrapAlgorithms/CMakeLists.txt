# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Generated
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated
  ${wxParams_INCLUDE_DIRS}
)

INCLUDE( ${VTK_USE_FILE} )
INCLUDE( ${wxWidgets_USE_FILE})


# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING)
  # Generate XML file
  MESSAGE("Generate XML file for Algorithms")

  IF   (VTK_FOUND)
    IF   (VTK_INCLUDE_DIRS)
      FOREACH( inc ${VTK_INCLUDE_DIRS})
        SET( VTK_INCLUDES  -I${inc}  ${VTK_INCLUDES} )
      ENDFOREACH(inc ${VTK_INCLUDE_DIRS})
    ENDIF(VTK_INCLUDE_DIRS)
     IF   (VTK_REQUIRED_CXX_FLAGS)
       FOREACH( def ${VTK_REQUIRED_CXX_FLAGS})
         SET( VTK_DEFS  ${def}  ${WX_DEFS} )
       ENDFOREACH(def ${VTK_REQUIRED_CXX_FLAGS})
       MESSAGE("VTK_DEFS=${VTK_DEFS}")
     ENDIF(VTK_REQUIRED_CXX_FLAGS)
  ENDIF ( VTK_FOUND)

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
  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  SET(WrapAlgorithms_OUTDIR ${CMAKE_CURRENT_SOURCE_DIR}/Generated)
  CreateDirectory( ${WrapAlgorithms_OUTDIR})
  IF(GENERATE_HTML_HELP)
    SET(CLASSES_URL_LIST "http://serdis.dis.ulpgc.es/~krissian/HomePage/Software/AMILab/Release-3.0.0/html/")
    SET(HTML_DIR "${WrapAlgorithms_OUTDIR}/html")
    CreateDirectory( ${HTML_DIR} )
  ENDIF(GENERATE_HTML_HELP)


MESSAGE("wxParams_INCLUDE_DIRS ${wxParams_INCLUDE_DIRS} ")
  SET(XML_OUTPUT "${WrapAlgorithms_OUTDIR}/algorithms_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/algorithms_includes.h")
  SET( GCCXML_result 0)
#   add_custom_command(OUTPUT ${XML_OUTPUT}
#     COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES}  ${VTK_DEFS}  ${XML_INPUT}
#     DEPENDS ${XML_INPUT}
#   )
  MESSAGE("${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include -I${AMILAB_SOURCE_DIR}/Graphic/include -I${wxParams_INCLUDE_DIRS} -I${AMILAB_SOURCE_DIR}/Language  -I${AMILAB_SOURCE_DIR}/Algorithms/include  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES}  ${WX_INCLUDES}  ${WX_DEFS}  ${XML_INPUT}")
  execute_process(
    COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include -I${AMILAB_SOURCE_DIR}/Graphic/include -I${wxParams_INCLUDE_DIRS} -I${AMILAB_SOURCE_DIR}/Language -I${AMILAB_SOURCE_DIR}/Algorithms/include -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES} ${WX_INCLUDES}  ${WX_DEFS} ${XML_INPUT}
  )
   
  # Generate the classes list

  # Read list of classes to wrap
  FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt" classes_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

  # Read vtk ancestors list
  SET( VTK_OUTDIR ${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/${AMI_VTK_VERSION}/Generated)

  FILE(READ "${VTK_OUTDIR}/ancestors.txt" vtk_ancestors_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" vtk_ancestors_list ${vtk_ancestors_txt} )


  SET(ANCESTORS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Generated/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  IF(GENERATE_HTML_HELP)
    MESSAGE("command is: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"  -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} --generate-html --url ${CLASSES_URL_LIST} --outputhtmldir ${HTML_DIR} --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"  -q
      OUTPUT_VARIABLE ancestors_result
      ERROR_VARIABLE ancestors_error
    )
  ELSE(GENERATE_HTML_HELP)
    MESSAGE("command is: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} -q")
    EXECUTE_PROCESS(
      COMMAND  ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} -q
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
    # Check that the class is not already wrapped with VTK wrapping
    IF ((NOT EXISTS ${VTK_OUTDIR}/wrap_${class}.h))
      SET(compilation_list ${compilation_list} ${class})
      IF ( (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp) OR
            (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.h))
        SET(OUTPUT_LIST ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp ${OUTPUT_LIST})
        SET(OUTPUT_LIST ${WrapAlgorithms_OUTDIR}/wrap_${class}.h ${OUTPUT_LIST})
        SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
      ENDIF( (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp) OR
          (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.h))
#    ELSE((NOT EXISTS ${VTK_OUTDIR}/wrap_${class}.h))
    ENDIF((NOT EXISTS ${VTK_OUTDIR}/wrap_${class}.h))
  ENDFOREACH( class ${ancestors_list}) 

  LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)

  #MESSAGE("Processing classes ${ancestors_list} and addwrap")
  IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.h) OR
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.cpp))
    # Go for python wrapping
    IF(GENERATE_HTML_HELP)
      ADD_CUSTOM_COMMAND(
        OUTPUT  ${OUTPUT_LIST} ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.h ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.cpp
        COMMAND
          ${PYTHON_EXECUTABLE}
            ${AMI_WRAPPER} ${XML_OUTPUT}
  #          --filter "*"
            --libname algorithms
            --classes ${MISSING_CLASSES}
            --available_classes ${ancestors_list} ${vtk_ancestors_list}
            --outputdir "${WrapAlgorithms_OUTDIR}"
            --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
            --addwrap
            --profile
            --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
            --generate-html             #flag to generate html help
            --url ${CLASSES_URL_LIST}   #base URL html help
            --outputhtmldir ${HTML_DIR} #HTML directory
            -q
          #DEPENDS
          #  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/classes.txt
          VERBATIM
      )
    ELSEIF(GENERATE_HTML_HELP)
      ADD_CUSTOM_COMMAND(
        OUTPUT  ${OUTPUT_LIST} ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.h ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.cpp
        COMMAND
          ${PYTHON_EXECUTABLE}
            ${AMI_WRAPPER} ${XML_OUTPUT}
  #          --filter "*"
            --libname algorithms
            --classes ${MISSING_CLASSES}
            --available_classes ${ancestors_list} ${vtk_ancestors_list}
            --outputdir "${WrapAlgorithms_OUTDIR}"
            --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
            --addwrap
            --profile
            -q
  #         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/classes.txt
          VERBATIM
        )
    ENDIF(GENERATE_HTML_HELP)
  ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.h) OR
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.cpp))

ENDIF(AMI_ENABLE_WRAPPING)

FOREACH( class ${compilation_list}  ) 
  SET( WrapAlgorithms_HDRS ${WrapAlgorithms_OUTDIR}/wrap_${class}.h ${WrapAlgorithms_HDRS})
  SET( WrapAlgorithms_SRCS ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp ${WrapAlgorithms_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( WrapAlgorithms_HDRS ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.h   ${WrapAlgorithms_HDRS})
SET( WrapAlgorithms_SRCS ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.cpp ${WrapAlgorithms_SRCS})

# file(GLOB algorithms_HDRS  "*.h"  )
# file(GLOB algorithms_SRCS  "*.cpp")

MESSAGE("Wrapping Algorithms ...")


SET(WrapAlgorithms_SRCS
     ${WrapAlgorithms_SRCS}
     ${WrapAlgorithms_HDRS}
)

#MESSAGE("WrapAlgorithms_SRCS =  ${WrapAlgorithms_SRCS}")

my_add_library ( WrapAlgorithms)
add_dependencies ( WrapAlgorithms WrapWxWidgets WrapVTK)
