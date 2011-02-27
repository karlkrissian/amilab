# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Generated
)


# if automatic wrapping, generate source files
IF(AMI_ENABLE_WRAPPING)
  # Generate XML file
  MESSAGE("Generate XML file for Algorithms")
  #
  #
  # TODO: run gccxml_vcconfig.bat to allow visual studio 9
  #
  SET(WrapAlgorithms_OUTDIR ${CMAKE_CURRENT_SOURCE_DIR}/Generated)
  CreateDirectory( ${WrapAlgorithms_OUTDIR})

  SET(XML_OUTPUT "${WrapAlgorithms_OUTDIR}/algorithms_includes.xml")
  SET(XML_INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/algorithms_includes.h")
  SET( GCCXML_result 0)
#   add_custom_command(OUTPUT ${XML_OUTPUT}
#     COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}  ${VTK_INCLUDES}  ${VTK_DEFS}  ${XML_INPUT}
#     DEPENDS ${XML_INPUT}
#   )
  MESSAGE("${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language  -I${AMILAB_SOURCE_DIR}/Algorithms/include  -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}     ${XML_INPUT}")
  execute_process(
    COMMAND ${GCCXML} -fxml=${XML_OUTPUT} -I${AMILAB_SOURCE_DIR}/Wrapping/include  -I${AMILAB_SOURCE_DIR}/Common/include  -I${AMILAB_SOURCE_DIR}/Language -I${AMILAB_SOURCE_DIR}/Algorithms/include -I${CMAKE_BINARY_DIR} -I${Boost_INCLUDE_DIR}   ${XML_INPUT}
  )
   
  # Generate the classes list

  # Read list of classes to wrap
  FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/classes.txt" classes_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

  SET(ANCESTORS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Generated/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  MESSAGE("command is: ${PYTHON_EXECUTABLE}  ${AMI_WRAPPER} ${XML_OUTPUT} --ancestors ${classes_list} --ancestors-file ${ANCESTORS_FILE} -q")
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
  #FILE(READ "${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}/methodpointers.txt" methodpointers_txt)
  #STRING(REGEX REPLACE "[\r\n]" ";" methodpointers_list ${methodpointers_txt} )

  # Wrap all classes at once since it is now fast
  FOREACH( class ${ancestors_list})
    IF( (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp) OR
        (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.h))
      SET(OUTPUT_LIST ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp ${OUTPUT_LIST})
      SET(OUTPUT_LIST ${WrapAlgorithms_OUTDIR}/wrap_${class}.h ${OUTPUT_LIST})
      SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
    ENDIF( (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp) OR
        (NOT EXISTS ${WrapAlgorithms_OUTDIR}/wrap_${class}.h))
  ENDFOREACH( class ${ancestors_list}) 

  LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)

  #MESSAGE("Processing classes ${ancestors_list} and addwrap")
  IF ((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.h) OR
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.cpp))
    # Go for python wrapping
    ADD_CUSTOM_COMMAND(
      OUTPUT  ${OUTPUT_LIST} ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.h ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.cpp
      COMMAND
        ${PYTHON_EXECUTABLE} 
          ${AMI_WRAPPER} ${XML_OUTPUT}
#          --filter "*"
          --libname algorithms
          --classes ${MISSING_CLASSES}
          --available_classes ${ancestors_list} 
          --outputdir "${WrapAlgorithms_OUTDIR}"
          --templatefile_dir "${AMILAB_SOURCE_DIR}/../PythonWrap/"
          --addwrap
          --profile
          -q
#         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/classes.txt
      )
  ENDIF((${NB_MISSING_CLASSES} GREATER 0) OR 
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.h) OR
      (NOT EXISTS ${WRAPWX_OUTDIR}/addwrap_algorithms.cpp))

ENDIF(AMI_ENABLE_WRAPPING)

FOREACH( class ${ancestors_list}  ) 
  SET( algorithms_HDRS ${WrapAlgorithms_OUTDIR}/wrap_${class}.h ${algorithms_HDRS})
  SET( algorithms_SRCS ${WrapAlgorithms_OUTDIR}/wrap_${class}.cpp ${algorithms_SRCS})
ENDFOREACH( class ${ancestors_list}  ) 
SET( algorithms_HDRS ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.h   ${algorithms_HDRS})
SET( algorithms_SRCS ${WrapAlgorithms_OUTDIR}/addwrap_algorithms.cpp ${algorithms_SRCS})

# file(GLOB algorithms_HDRS  "*.h"  )
# file(GLOB algorithms_SRCS  "*.cpp")

MESSAGE("Wrapping Algorithms ...")

IF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(new_vtk_source_code_list ${algorithms_SRCS})
ELSE(NUMBER_SOURCES_TO_PACKAGE EQUAL 1)
  SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapAlgorithms")
  GenerateSourcesWrapping (new_vtk_source_code_list source_path algorithms_SRCS)
ENDIF(NUMBER_SOURCES_TO_PACKAGE EQUAL 1) 

SET(  WrapAlgorithms_SRCS
)

SET(WrapAlgorithms_HDRS
)

SET(WrapAlgorithms_SRCS
     ${WrapAlgorithms_SRCS}
     ${WrapAlgorithms_HDRS}
     ${new_vtk_source_code_list}
     #${algorithms_SRCS}
     ${algorithms_HDRS}
)

#MESSAGE("WrapAlgorithms_SRCS =  ${WrapAlgorithms_SRCS}")

my_add_library ( WrapAlgorithms)
add_dependencies ( WrapAlgorithms WrapWxWidgets )