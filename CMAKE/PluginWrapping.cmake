#==============================================================================
# Plugin
#
# Description: Specifies since it is wrapped of the class Example.
#
# Author: xXx <xXX>, (C) 2010
#
# Copyright: See COPYING file that comes with this distribution
#==============================================================================

#MESSAGE("Find GCCXML...")

FIND_PACKAGE( GCCXML REQUIRED)

#MESSAGE("GCCXML found")
#MESSAGE("Begin wrapping...")

INCLUDE(${AMILab_SOURCE_DIR}/../CMAKE/amiWrapping.cmake)

IF(EXISTS ${PROJECT_SOURCE_DIR}/Wrapping)
  SET(WRAP_DIR ${PROJECT_SOURCE_DIR}/Wrapping)
ENDIF(EXISTS ${PROJECT_SOURCE_DIR}/Wrapping)

IF(EXISTS ${PROJECT_SOURCE_DIR}/src/Wrapping)
  SET(WRAP_DIR ${PROJECT_SOURCE_DIR}/src/Wrapping)
ENDIF(EXISTS ${PROJECT_SOURCE_DIR}/src/Wrapping)

SET(GENERATED_DIR ${WRAP_DIR}/Generated)
IF( NOT EXISTS ${GENERATED_DIR})
  FILE(MAKE_DIRECTORY ${GENERATED_DIR})
ENDIF( NOT EXISTS ${GENERATED_DIR})

WRAP_INIT("Wrapping ${KIT}")

SET(XML_OUTPUT "${GENERATED_DIR}/${CMAKE_PROJECT_NAME}_includes.xml")
SET(XML_INPUT  "${WRAP_DIR}/${CMAKE_PROJECT_NAME}_includes.h")
SET(GCCXML_result 0)

WRAP_MESSAGE("Try to generate XML file...")

IF(${KIT}_NEED_VTK_WRAPPING)
  INCLUDE(${AMILab_SOURCE_DIR}/../CMAKE/amiWrapVTK.cmake)
  GCCXML_USE_VTK()
ENDIF(${KIT}_NEED_VTK_WRAPPING)

IF(${KIT}_NEED_WX_WRAPPING)
  INCLUDE(${AMILab_SOURCE_DIR}/../CMAKE/amiWrapWxWidgets.cmake)
  GCCXML_USE_WXWIDGETS()
ENDIF(${KIT}_NEED_WX_WRAPPING)

# Adding KIT includes
IF(KIT)
  IF(${KIT}_INCLUDE_PATHS)
    WRAP_MESSAGE("************** ${KIT}_INCLUDE_PATHS = ${${KIT}_INCLUDE_PATHS}")
    foreach(path ${${KIT}_INCLUDE_PATHS})
      SET(GCCXML_INCLUDES ${GCCXML_INCLUDES} "-I${path}")
    endforeach(p ${${KIT}_INCLUDE_PATHS})
  ENDIF(${KIT}_INCLUDE_PATHS)
ENDIF(KIT)

SET(GCCXML_CMD ${GCCXML}    "-fxml=${XML_OUTPUT}")
SET(GCCXML_CMD ${GCCXML_CMD} "-I${AMILab_SOURCE_DIR}/Wrapping/include")
SET(GCCXML_CMD ${GCCXML_CMD} "-I${AMILab_SOURCE_DIR}/Common/include")
SET(GCCXML_CMD ${GCCXML_CMD} "-I${AMILab_SOURCE_DIR}/CommonBase")
SET(GCCXML_CMD ${GCCXML_CMD} "-I${AMILab_SOURCE_DIR}/LanguageBase")
SET(GCCXML_CMD ${GCCXML_CMD} "-I${AMILab_BINARY_DIR}")
SET(GCCXML_CMD ${GCCXML_CMD} "-I${PROJECT_SOURCE_DIR}")
SET(GCCXML_CMD ${GCCXML_CMD} "-I${Boost_INCLUDE_DIR}")
SET(GCCXML_CMD ${GCCXML_CMD} "${GCCXML_INCLUDES}")
SET(GCCXML_CMD ${GCCXML_CMD} "${GCCXML_DEFS}")
SET(GCCXML_CMD ${GCCXML_CMD} ${XML_INPUT})


WRAP_MESSAGE("COMMAND: ${GCCXML_CMD}")
EXECUTE_PROCESS(
  COMMAND ${GCCXML_CMD}
  RESULT_VARIABLE GCCXML_CMD_RESULT
  ERROR_VARIABLE  GCCXML_CMD_ERROR
)

IF(GCCXML_CMD_RESULT)

    WRAP_MESSAGE("Failed the generation of XML: ${GCCXML_CMD_ERROR} - ${GCCXML_CMD_RESULT}")

ELSE(GCCXML_CMD_RESULT)

  WRAP_MESSAGE("Generated XML file")
  WRAP_MESSAGE("Find PYTHON...")
  FIND_PACKAGE( PythonInterp REQUIRED)
  WRAP_MESSAGE("PYTHON found")
  WRAP_MESSAGE("Try to generate ANCESTORS file...")

  # Read list of classes to wrap
  READ_CLASSES(  "${WRAP_DIR}/classes.txt")
  # Read list of functions to wrap
  READ_FUNCTIONS("${WRAP_DIR}/functions.txt")

  SET(LIBNAME "${CMAKE_PROJECT_NAME}")
  CREATE_ANCESTORS()

#   IF(MYCOMMAND_2_RESULT)
#     WRAP_MESSAGE(SEND_ERROR "Failed the generation of ANCESTORS file: ${MYCOMMAND_2_ERROR} - ${MYCOMMAND_2_RESULT}")
#   ELSE(MYCOMMAND_2_RESULT)
    #WRAP_
    MESSAGE("Generated ANCESTORS file: ancestors_result = ${ancestors_result}")

    IF(EXISTS ${ANCESTORS_FILE})
      FILE(READ "${ANCESTORS_FILE}" ancestors_txt)
      STRING(REGEX REPLACE "[\r\n]" ";" ancestors_list ${ancestors_txt} )
    ELSE(EXISTS ${ANCESTORS_FILE})
      SET(ancestors_list "")
    ENDIF(EXISTS ${ANCESTORS_FILE})

    CHECK_WRAPPED_FILES( "${ancestors_list}"       "MISSING_CLASSES")
    CHECK_WRAPPED_FILES( "${functions_list}"       "MISSING_FUNCTIONS")

    WRAP_MESSAGE("MISSING_CLASSES   = ${MISSING_CLASSES}")
    WRAP_MESSAGE("MISSING_FUNCTIONS = ${MISSING_FUNCTIONS}")

    LIST(LENGTH MISSING_CLASSES NB_MISSING_CLASSES)
    WRAP_MESSAGE(" NB_MISSING_CLASSES=${NB_MISSING_CLASSES}")

    LIST(LENGTH MISSING_FUNCTIONS NB_MISSING_FUNCTIONS)
    WRAP_MESSAGE(" NB_MISSING_FUNCTIONS=${NB_MISSING_FUNCTIONS}")


    #IF( (${GCCXML_result} EQUAL 0) AND
    #    (DEFINED OUTPUT_LIST ) )
    IF ((${NB_MISSING_CLASSES}   GREATER 0) OR 
        (${NB_MISSING_FUNCTIONS} GREATER 0) OR
        (NOT EXISTS ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.h) OR
        (NOT EXISTS ${GENERATED_DIR}/addwrap_${CMAKE_PROJECT_NAME}.cpp))

      WRAP_MESSAGE("Try to generate wrapping...")

      SET(MYCOMMAND_3 ${PYTHON_EXECUTABLE})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${AMI_WRAPPER})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} ${XML_OUTPUT})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--libname" "${CMAKE_PROJECT_NAME}")
      #SET(MYCOMMAND_3 ${MYCOMMAND_3} "--filter" "\"wx*\"")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--classes" ${MISSING_CLASSES})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--available_classes" ${ancestors_list})
      IF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
        WRAP_MESSAGE("***** available external classes *****")
        SET(MYCOMMAND_3 ${MYCOMMAND_3} "--available_external_classes" ${AVAILABLE_EXTERNAL_CLASSES})
      ENDIF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
      IF(DEFINED HAS_FUNCTIONS)
        SET(MYCOMMAND_3 ${MYCOMMAND_3} "--functions" ${MISSING_FUNCTIONS})
        SET(MYCOMMAND_3 ${MYCOMMAND_3} "--available_functions" ${functions_list})
      ENDIF(DEFINED HAS_FUNCTIONS)
      IF(EXISTS ${WRAP_DIR}/classes_includes.py)
        SET(MYCOMMAND_3 ${MYCOMMAND_3} "--classes_includes" ${WRAP_DIR}/classes_includes.py)
      ENDIF(EXISTS ${WRAP_DIR}/classes_includes.py)
      #SET(MYCOMMAND_3 ${MYCOMMAND_3} "--wrap_includes" ${WrapWxWidgetsDir})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--outputdir" ${GENERATED_DIR})
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--profile")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--templates")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--templatefile_dir" ${AMILab_SOURCE_DIR}/../PythonWrap/)
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "--addwrap")
      SET(MYCOMMAND_3 ${MYCOMMAND_3} "-q")

      WRAP_MESSAGE("COMMAND 3: ${MYCOMMAND_3}")
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


#   ENDIF(MYCOMMAND_2_RESULT)

  WRAP_MESSAGE("End wrapping")
ENDIF(GCCXML_CMD_RESULT)
