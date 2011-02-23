#==============================================================================
# Plugin
#
# Description: Specifies since it is wrapped of the class Example.
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

MESSAGE("Find GCCXML...")

FIND_PACKAGE( GCCXML REQUIRED)

MESSAGE("GCCXML found")

MESSAGE("Begin wrapping...")

SET(WRAP_DIR ${PROJECT_SOURCE_DIR}/Wrapping)
SET(GENERATED_DIR ${WRAP_DIR}/Generated)
IF( NOT EXISTS ${GENERATED_DIR})
  FILE(MAKE_DIRECTORY ${GENERATED_DIR})
ENDIF( NOT EXISTS ${GENERATED_DIR})

SET(XML_OUTPUT "${GENERATED_DIR}/examples_includes.xml")
SET(XML_INPUT  "${WRAP_DIR}/example_includes.h")
SET(GCCXML_result 0)

MESSAGE("Try to generate XML file...")

SET(MYCOMMAND ${GCCXML}    "-fxml=${XML_OUTPUT}")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Wrapping/include")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Common/include")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Language")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_BINARY_DIR}")
SET(MYCOMMAND ${MYCOMMAND} "-I${PROJECT_SOURCE_DIR}")
SET(MYCOMMAND ${MYCOMMAND} ${XML_INPUT})

MESSAGE("COMMAND: ${MYCOMMAND}")
EXECUTE_PROCESS(
  COMMAND ${MYCOMMAND}
  RESULT_VARIABLE MYCOMMAND_RESULT
  ERROR_VARIABLE  MYCOMMAND_ERROR
)

IF(MYCOMMAND_RESULT)
  MESSAGE(SEND_ERROR "Failed the generation of XML: ${MYCOMMAND_ERROR} - ${MYCOMMAND_RESULT}")
ELSE(MYCOMMAND_RESULT)
  MESSAGE("Generated XML file")

  MESSAGE("Find PYTHON...")

  FIND_PACKAGE( PythonInterp REQUIRED)

  MESSAGE("PYTHON found")

  MESSAGE("Try to generate ANCESTORS file...")

  FILE(READ "${WRAP_DIR}/classes.txt" classes_txt)
  STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

  SET(ANCESTORS_FILE "${GENERATED_DIR}/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  SET(MYCOMMAND_2 ${PYTHON_EXECUTABLE})                          #Command
  SET(MYCOMMAND_2 ${MYCOMMAND_2} ${AMI_WRAPPER})                 #Wrapper
  SET(MYCOMMAND_2 ${MYCOMMAND_2} ${XML_OUTPUT})                  #Input
  SET(MYCOMMAND_2 ${MYCOMMAND_2} "--ancestors" ${classes_list})  #Options
  SET(MYCOMMAND_2 ${MYCOMMAND_2} "--ancestors-file" ${ANCESTORS_FILE} "-q")
  MESSAGE("COMMAND: ${MYCOMMAND_2}")

  EXECUTE_PROCESS(
    COMMAND ${MYCOMMAND_2}
    RESULT_VARIABLE MYCOMMAND_2_RESULT
    ERROR_VARIABLE  MYCOMMAND_2_ERROR
    OUTPUT_VARIABLE ancestors_result
  )

  IF(MYCOMMAND_2_RESULT)
    MESSAGE(SEND_ERROR "Failed the generation of ANCESTORS file: ${MYCOMMAND_2_ERROR} - ${MYCOMMAND_2_RESULT}")
  ELSE(MYCOMMAND_2_RESULT)
    MESSAGE("Generated ANCESTORS file: ancestors_result = ${ancestors_result}")

    FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
    STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )

    FOREACH( class ${ancestors_list})
      SET(OUTPUT_LIST
        ${GENERATED_DIR}/wrap_${class}.cpp ${GENERATED_DIR}/wrap_${class}.h
        ${OUTPUT_LIST}
    )
    ENDFOREACH( class ${ancestors_list})

    IF(${GCCXML_result} EQUAL 0)
      MESSAGE("Try to generate wrapping...")

      SET(MYCOMMAND_3 ${PYTHON_EXECUTABLE})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${AMI_WRAPPER})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${XML_OUTPUT})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--libname" "wx")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--filter" "\"wx*\"")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--classes" ${ancestors_list})
      #SET(MYCOMMAND_3 ${MYCOMMAND_3} "--wrap_includes" ${WrapWxWidgetsDir})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--outputdir" ${GENERATED_DIR})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--profile")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--templatefile_dir" ${AMILAB_SOURCE_DIR}/../PythonWrap/)
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "-q")

      MESSAGE("COMMAND: ${MYCOMMAND_3}")
      ADD_CUSTOM_COMMAND(
        OUTPUT
          ${OUTPUT_LIST} ${methodpointers_list}
        COMMAND
          ${MYCOMMAND_3}
        DEPENDS
          ${WRAP_DIR}/classes.txt
      )
    ENDIF(${GCCXML_result} EQUAL 0)

    FOREACH( class ${ancestors_list} )
      SET( Example_HDRS ${GENERATED_DIR}/wrap_${class}.h ${Example_HDRS})
      SET( Example_SRCS ${GENERATED_DIR}/wrap_${class}.cpp ${Example_SRCS})
    ENDFOREACH( class ${ancestors_list} )

  ENDIF(MYCOMMAND_2_RESULT)

  MESSAGE("End wrapping")
ENDIF(MYCOMMAND_RESULT)
