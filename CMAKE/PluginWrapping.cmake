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

SET(XML_OUTPUT "${GENERATED_DIR}/${CMAKE_PROJECT_NAME}_includes.xml")
SET(XML_INPUT  "${WRAP_DIR}/${CMAKE_PROJECT_NAME}_includes.h")
SET(GCCXML_result 0)

MESSAGE("Try to generate XML file...")

# VTK compilation flags
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


SET(MYCOMMAND ${GCCXML}    "-fxml=${XML_OUTPUT}")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Wrapping/include")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/Common/include")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/CommonBase")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_SOURCE_DIR}/LanguageBase")
SET(MYCOMMAND ${MYCOMMAND} "-I${AMILAB_BINARY_DIR}")
SET(MYCOMMAND ${MYCOMMAND} "-I${PROJECT_SOURCE_DIR}")
SET(MYCOMMAND ${MYCOMMAND} "-I${Boost_INCLUDE_DIR}")
SET(MYCOMMAND ${MYCOMMAND} "${VTK_INCLUDES}")
SET(MYCOMMAND ${MYCOMMAND} ${XML_INPUT})

IF(KIT)
  IF(${KIT}_INCLUDE_PATHS)
    MESSAGE("************** ${KIT}_INCLUDE_PATHS = ${${KIT}_INCLUDE_PATHS}")
    foreach(path ${${KIT}_INCLUDE_PATHS})
      SET(MYCOMMAND ${MYCOMMAND} "-I${path}")
    endforeach(p ${${KIT}_INCLUDE_PATHS})
  ENDIF(${KIT}_INCLUDE_PATHS)
ENDIF(KIT)

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

  # Read list of functions to wrap
  IF(EXISTS ${WRAP_DIR}/functions.txt)
    FILE(READ "${WRAP_DIR}/functions.txt" functions_txt)
    # skip comments
    STRING(REGEX REPLACE "#[^\n]*\n" "\n"  functions_list_cleaned ${functions_txt} )
    STRING(REGEX REPLACE "#[^\n]*$"  ""    functions_list_cleaned ${functions_list_cleaned} )
    #STRING(REGEX REPLACE "\n#[^\n]*\n" "\n" functions_list_cleaned ${functions_list_cleaned} )
    STRING(REGEX REPLACE "[\r\n]" ";" functions_list ${functions_list_cleaned} )
    MESSAGE("functions_list = ${functions_list}")
    SET(HAS_FUNCTIONS "1")
  ENDIF(EXISTS ${WRAP_DIR}/functions.txt)


#   IF(EXISTS ${WRAP_DIR}/functions.txt)
#     FILE(READ "${WRAP_DIR}/functions.txt" functions_txt)
#     STRING(REGEX REPLACE "[\r\n]" ";" functions_list ${functions_txt} )
#     SET(HAS_FUNCTIONS "1")
#   ENDIF(EXISTS ${WRAP_DIR}/functions.txt)



  SET(ANCESTORS_FILE "${GENERATED_DIR}/ancestors.txt")
  SET(AMI_WRAPPER "${AMILAB_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  SET(MYCOMMAND_2 ${PYTHON_EXECUTABLE})                          #Command
  SET(MYCOMMAND_2 ${MYCOMMAND_2} ${AMI_WRAPPER})                 #Wrapper
  SET(MYCOMMAND_2 ${MYCOMMAND_2} ${XML_OUTPUT})                  #Input
  SET(MYCOMMAND_2 ${MYCOMMAND_2} "--libname" "${CMAKE_PROJECT_NAME}")
  SET(MYCOMMAND_2 ${MYCOMMAND_2} "--ancestors" ${classes_list})  #Options
  SET(MYCOMMAND_2 ${MYCOMMAND_2} "--ancestors-file" ${ANCESTORS_FILE} "-q")
  IF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
    MESSAGE("***** available external classes *****")
    SET(MYCOMMAND_2 ${MYCOMMAND_2} "--available_external_classes" ${AVAILABLE_EXTERNAL_CLASSES})
  ENDIF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
  MESSAGE("COMMAND 2: ${MYCOMMAND_2}")

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

    IF(EXISTS ${ANCESTORS_FILE})
      FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
      STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )
    ELSE(EXISTS ${ANCESTORS_FILE})
      SET(ancestors_list "")
    ENDIF(EXISTS ${ANCESTORS_FILE})

    FOREACH( class ${ancestors_list})
      ClassUsedName( class m_class )
      SET(compilation_list ${compilation_list} ${m_class})
      IF( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.cpp) OR
          (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.h) )
        SET(OUTPUT_LIST
          ${GENERATED_DIR}/wrap_${m_class}.cpp ${GENERATED_DIR}/wrap_${m_class}.h
          ${OUTPUT_LIST}
        )
        SET(MISSING_CLASSES ${class} ${MISSING_CLASSES})
      ENDIF( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.cpp) OR
             (NOT EXISTS ${GENERATED_DIR}/wrap_${m_class}.h) )
      SET(CLASS_LIST ${CLASS_LIST} ${class})
    ENDFOREACH( class ${ancestors_list})

    LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)
    MESSAGE(" NB_MISSING_CLASSES=${NB_MISSING_CLASSES}")

    FOREACH( func ${functions_list})
      ClassUsedName( func m_func )
      SET(func_compilation_list ${compilation_list} ${m_func})
      IF( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_func}.cpp) OR
          (NOT EXISTS ${GENERATED_DIR}/wrap_${m_func}.h) )
        SET(OUTPUT_LIST
          ${GENERATED_DIR}/wrap_${m_func}.cpp ${GENERATED_DIR}/wrap_${m_func}.h
          ${OUTPUT_LIST}
        )
        SET(MISSING_FUNCTIONS ${func} ${MISSING_FUNCTIONS})
      ENDIF( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_func}.cpp) OR
             (NOT EXISTS ${GENERATED_DIR}/wrap_${m_func}.h) )
      SET(FUNC_LIST ${FUNC_LIST} ${func})
    ENDFOREACH( func ${functions_list})

    LIST(LENGTH MISSING_FUNCTIONS NB_MISSING_FUNCTIONS)
    MESSAGE(" NB_MISSING_FUNCTIONS=${NB_MISSING_FUNCTIONS}")

    #IF( (${GCCXML_result} EQUAL 0) AND
    #    (DEFINED OUTPUT_LIST ) )
    IF ((${NB_MISSING_CLASSES}   GREATER 0) OR 
        (${NB_MISSING_FUNCTIONS} GREATER 0) OR
        (NOT EXISTS ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.h) OR
        (NOT EXISTS ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.cpp))

      MESSAGE("Try to generate wrapping...")

      SET(MYCOMMAND_3 ${PYTHON_EXECUTABLE})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${AMI_WRAPPER})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${XML_OUTPUT})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--libname" "${CMAKE_PROJECT_NAME}")
      #SET(MYCOMMAND_3 ${MYCOMMAND_3} "--filter" "\"wx*\"")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--classes" ${MISSING_CLASSES})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--available_classes" ${ancestors_list})
      IF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
        MESSAGE("***** available external classes *****")
        SET(MYCOMMAND_3 ${MYCOMMAND_3} "--available_external_classes" ${AVAILABLE_EXTERNAL_CLASSES})
      ENDIF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
      IF(DEFINED HAS_FUNCTIONS)
        SET(MYCOMMAND_3 ${MYCOMMAND_3} "--functions" ${MISSING_FUNCTIONS})
        SET(MYCOMMAND_3 ${MYCOMMAND_3} "--available_functions" ${functions_list})
      ENDIF(DEFINED HAS_FUNCTIONS)
      #SET(MYCOMMAND_3 ${MYCOMMAND_3} "--wrap_includes" ${WrapWxWidgetsDir})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--outputdir" ${GENERATED_DIR})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--profile")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--templates")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--templatefile_dir" ${AMILAB_SOURCE_DIR}/../PythonWrap/)
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--addwrap")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "-q")

      MESSAGE("COMMAND 3: ${MYCOMMAND_3}")
      ADD_CUSTOM_COMMAND(
        OUTPUT
          ${OUTPUT_LIST} ${methodpointers_list} 
          ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.h
          ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.cpp
        COMMAND
          ${MYCOMMAND_3}
        DEPENDS
          ${WRAP_DIR}/classes.txt
        VERBATIM
      )
    ENDIF ((${NB_MISSING_CLASSES}   GREATER 0) OR 
        (${NB_MISSING_FUNCTIONS} GREATER 0) OR
        (NOT EXISTS ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.h) OR
        (NOT EXISTS ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.cpp))

    FOREACH( class ${ancestors_list} ${functions_list} )
      ClassUsedName( class m_class )
      SET( ${CMAKE_PROJECT_NAME}_HDRS 
            ${GENERATED_DIR}/wrap_${m_class}.h ${${CMAKE_PROJECT_NAME}_HDRS})
      SET( ${CMAKE_PROJECT_NAME}_SRCS 
            ${GENERATED_DIR}/wrap_${m_class}.cpp ${${CMAKE_PROJECT_NAME}_SRCS})
    ENDFOREACH( class ${ancestors_list} )

    SET( ${CMAKE_PROJECT_NAME}_HDRS 
        ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.h
        ${${CMAKE_PROJECT_NAME}_HDRS})

    SET( ${CMAKE_PROJECT_NAME}_SRCS 
        ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.cpp 
        ${${CMAKE_PROJECT_NAME}_SRCS})


  ENDIF(MYCOMMAND_2_RESULT)

  MESSAGE("End wrapping")
ENDIF(MYCOMMAND_RESULT)
