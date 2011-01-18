#==============================================================================
# WrapExamples
#
# Description: Wrapping of template example
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Language
  ${AMILAB_SOURCE_DIR}/../Pixmaps
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapExamples
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapExamples/Generated
)

SET(WrapExamplessDir "${AMILAB_SOURCE_DIR}/Wrapping/WrapExamples")

# if automatic wrapping, generate source files
IF(AMI_WRAP_EXAMPLES)
  MESSAGE("\nBegin wrap examples:")
  # Generate XML file
  MESSAGE("Try to generate file xml...")
  SET(WRAPEXAMPLES_OUTDIR "${WrapExamplessDir}/Generated")
  CreateDirectory( ${WRAPEXAMPLES_OUTDIR})

  SET(XML_OUTPUT "${WRAPEXAMPLES_OUTDIR}/template_includes.xml")
  SET(XML_INPUT  "${WrapExamplessDir}/template_includes.h")
  SET(GCCXML_result 0)

  SET(MYCOMMAND ${GCCXML}    "-fxml=${XML_OUTPUT}")                     #Command
  SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Wrapping/include") #Includes
  SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Common/include")
  SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Language")
  SET(MYCOMMAND ${MYCOMMAND} "-I${CMAKE_BINARY_DIR}" "-I${Boost_INCLUDE_DIR}")
  #SET(MYCOMMAND ${MYCOMMAND} ${WX_INCLUDES})
  #SET(MYCOMMAND ${MYCOMMAND} ${WX_DEFS})                                #Flags
  SET(MYCOMMAND ${MYCOMMAND} ${XML_INPUT})                              #Input

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
    FILE(READ "${WrapExamplessDir}/classes.txt" classes_txt)
    STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_txt} )

    FOREACH( class ${classes_list})
      STRING(REGEX REPLACE "<" "__LT__" class ${class} )
      STRING(REGEX REPLACE ">" "__GT__" class ${class} )
      STRING(REGEX REPLACE "," "__COMMA__" class ${class} )
      SET(OUTPUT_LIST
        ${WRAPEXAMPLES_OUTDIR}/wrap_${class}.cpp
        ${WRAPEXAMPLES_OUTDIR}/wrap_${class}.h
        ${OUTPUT_LIST}
      )
    ENDFOREACH( class ${classes_list})
    

    SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")
    SET(TEMPLATE_WRAPPER_DIR "${AMILAB_SOURCE_DIR}/../PythonWrap/")
    IF(${GCCXML_result} EQUAL 0)
      SET(MYCOMMAND_3 ${PYTHON_EXECUTABLE})                                        #Command
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${AMI_WRAPPER})                               #Wrapper
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${XML_OUTPUT})                                #Input
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--libname" "wx")                             #Name of the library to wrap
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--classes" "\"TestTemplateClass<int>\"") #\"${classes_list}\")                   #Name of the class(es) to wrap
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--templates")                                #template wrapping
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--outputdir" ${WRAPEXAMPLES_OUTDIR})               #Output directory
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--profile")                                  #Displays the processing time
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--templatefile_dir" ${TEMPLATE_WRAPPER_DIR}) #Directory containing the template files
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "-q")

      MESSAGE("COMMAND: ${MYCOMMAND_3}")
      ADD_CUSTOM_COMMAND(
        OUTPUT
          ${OUTPUT_LIST}
        COMMAND
          ${MYCOMMAND_3}
        DEPENDS
          ${WrapExamplessDir}/classes.txt
      )
    ENDIF(${GCCXML_result} EQUAL 0)

#     SET( wrapExamples_HDRS
#         ${WRAPEXAMPLES_OUTDIR}/wrap_TemplateClass__int_.cpp
#     )
# 
#     SET( wrapExamples_SRCS
#         ${WRAPEXAMPLES_OUTDIR}/wrap_TemplateClass_int_.h
#     )

    SET(WrapExamples_SRCS
      ${OUTPUT_LIST}
#       ${wrapExamples_HDRS}
#       ${wrapExamples_SRCS}
    )

#    MESSAGE( "output list '${OUTPUT_LIST}', wrapExamples_SRCS= '${wrapExamples_SRCS}'")

    MESSAGE("Source: ${WrapExamples_SRCS}")
    my_add_library ( WrapExamples )

  ENDIF(MYCOMMAND_RESULT)
  MESSAGE("End wrap examples")
ENDIF(AMI_WRAP_EXAMPLES)
