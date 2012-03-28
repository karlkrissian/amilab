

#-------------------------------------------------------------------------------
#
# needs 
#  GENERATED_DIR
#  LIBNAME
#
MACRO(WRAP_INIT mess)
  # reset log file
  IF(DEFINED GENERATED_DIR)
    FILE(WRITE ${GENERATED_DIR}/Wrapping.log "" )
  ENDIF(DEFINED GENERATED_DIR)
  WRAP_MESSAGE("***************************")
  WRAP_MESSAGE(" ${mess}")
  IF(DEFINED LIBNAME)
    WRAP_MESSAGE(" Configuring wrapping for library ${LIBNAME}")
  ENDIF(DEFINED LIBNAME)
  WRAP_MESSAGE("***************************")
  MESSAGE("Details in '${GENERATED_DIR}/Wrapping.log'")
ENDMACRO(WRAP_INIT)

#-------------------------------------------------------------------------------
#
# needs GENERATED_DIR
#
MACRO(WRAP_MESSAGE mess)
  SET(MAXLENGTH 50)
  STRING(LENGTH "${mess}" mess_length)
  IF (${mess_length} GREATER ${MAXLENGTH})
    # troncate message
    string(SUBSTRING "${mess}" 0 ${MAXLENGTH} mess_troncated)
    MESSAGE("${mess_troncated}[...]")
  ELSE (${mess_length} GREATER ${MAXLENGTH})
    MESSAGE("${mess}")
  ENDIF (${mess_length} GREATER ${MAXLENGTH})
  # APPEND TO LOG FILE
  IF(DEFINED GENERATED_DIR)
    FILE(APPEND ${GENERATED_DIR}/Wrapping.log ${mess} )
    FILE(APPEND ${GENERATED_DIR}/Wrapping.log "\n" )
  ENDIF(DEFINED GENERATED_DIR)
ENDMACRO(WRAP_MESSAGE mess)

#-------------------------------------------------------------------------------
#
# Running gccxml command for amilab wrapping
#
MACRO( RUN_GCCXML XML_INPUT XML_OUTPUT)

  WRAP_MESSAGE("Try to generate XML file ${XML_OUTPUT}")

  SET(GCCXML_CMD ${GCCXML}    "-fxml=${XML_OUTPUT}")

  # remove duplicates
  LIST(REMOVE_DUPLICATES GCCXML_INCLUDES)
  IF(GCCXML_DEFS)
    LIST(REMOVE_DUPLICATES GCCXML_DEFS)
  ENDIF(GCCXML_DEFS)


  # Adding the GCCXML includes and flags required
  SET(GCCXML_CMD ${GCCXML_CMD} "${GCCXML_INCLUDES}")
  IF(GCCXML_DEFS)
    SET(GCCXML_CMD ${GCCXML_CMD} "${GCCXML_DEFS}")
  ENDIF(GCCXML_DEFS)
  SET(GCCXML_CMD ${GCCXML_CMD} ${XML_INPUT})

  # Write the command to the standard output for information
  FOREACH( C ${GCCXML_CMD})
    SET( GCCXML_CMD_TXT "${GCCXML_CMD_TXT} ${C}")
  ENDFOREACH( C ${GCCXML_CMD})
  WRAP_MESSAGE("COMMAND: ${GCCXML_CMD_TXT}")

  # Execute the command
  EXECUTE_PROCESS(
    COMMAND ${GCCXML_CMD}
    RESULT_VARIABLE GCCXML_CMD_RESULT
    ERROR_VARIABLE  GCCXML_CMD_ERROR
  )

  IF(GCCXML_CMD_RESULT)
    MESSAGE(SEND_ERROR "Failed the generation of XML: ${GCCXML_CMD_ERROR} - ${GCCXML_CMD_RESULT}")
  ENDIF(GCCXML_CMD_RESULT)

ENDMACRO( RUN_GCCXML )

#-------------------------------------------------------------------------------
#
# Read the list of classes
#
# input:  filename containing the list of classes to wrap
# output: classes_txt classes_list HAS_CLASSES
#
MACRO( READ_CLASSES filename)
  #MESSAGE("READ_CLASSES *")
  # Read list of classes to wrap
  IF(EXISTS ${filename})
    #MESSAGE("READ_CLASSES *")
    FILE(READ "${filename}" classes_txt)
    # skip comments
    STRING(REGEX REPLACE "#[^\n]*\n" "\n"  classes_list_cleaned 
                          ${classes_txt} )
    STRING(REGEX REPLACE "#[^\n]*$"  ""    classes_list_cleaned 
                          ${classes_list_cleaned} )
    STRING(REGEX REPLACE "[\r\n]" ";" classes_list ${classes_list_cleaned} )
    SET(HAS_CLASSES "1")
  ENDIF(EXISTS ${filename})
ENDMACRO( READ_CLASSES )

#-------------------------------------------------------------------------------
#
# Read the list of classes including a common list for all versions of the 
# library
#
# input:  filename containing the list of classes to wrap
# output: classes_txt classes_list HAS_CLASSES
#
MACRO( READ_CLASSES2 filename_common filename)
  # Read list of classes to wrap
  IF(EXISTS ${filename_common})
    FILE(READ "${filename_common}" classes_common_txt)
    # skip comments
    STRING(REGEX REPLACE "#[^\n]*\n" "\n"  classes_common_list_cleaned 
                          ${classes_common_txt} )
    STRING(REGEX REPLACE "#[^\n]*$"  ""    classes_common_list_cleaned 
                          ${classes_common_list_cleaned} )
    STRING(REGEX REPLACE "[\r\n]" ";" classes_common_list 
                          ${classes_common_list_cleaned} )
    SET(HAS_CLASSES "1")
  ENDIF(EXISTS ${filename_common})
  READ_CLASSES(${filename})
  SET( classes_list ${classes_common_list} ${classes_list})
  MESSAGE("classes_list = ${classes_list}")
ENDMACRO( READ_CLASSES2 )

#-------------------------------------------------------------------------------
#
# Read the list of functions
#
# input:  filename containing the list of functions to wrap
# output: functions_txt functions_list HAS_FUNCTIONS
#
MACRO( READ_FUNCTIONS filename)
  # Read list of functions to wrap
  IF(EXISTS ${filename})
    FILE(READ "${filename}" functions_txt)
    # skip comments
    STRING(REGEX REPLACE "#[^\n]*\n" "\n"  functions_list_cleaned ${functions_txt} )
    STRING(REGEX REPLACE "#[^\n]*$"  ""    functions_list_cleaned ${functions_list_cleaned} )
    #STRING(REGEX REPLACE "\n#[^\n]*\n" "\n" functions_list_cleaned ${functions_list_cleaned} )
    STRING(REGEX REPLACE "[\r\n]" ";" functions_list ${functions_list_cleaned} )
    WRAP_MESSAGE("functions_list = ${functions_list}")
    SET(HAS_FUNCTIONS "1")
  ENDIF(EXISTS ${filename})
ENDMACRO( READ_FUNCTIONS )


#-------------------------------------------------------------------------------
#
# Create ancestors file
#
# needs:
#   GENERATED_DIR
#   AMILab_SOURCE_DIR
#   PYTHON_EXECUTABLE
#   XML_OUTPUT
#   LIBNAME
#   AVAILABLE_EXTERNAL_CLASSES (optional)
#   GENERATE_HTML_HELP
#   CLASSES_URL_LIST
#   HTML_DIR
#
# outputs:
#   ANCESTORS_CMD_RESULT
#   ANCESTORS_CMD_ERROR
#
MACRO( CREATE_ANCESTORS )
  SET(ANCESTORS_FILE "${GENERATED_DIR}/ancestors.txt")
  SET(AMI_WRAPPER "${AMILab_SOURCE_DIR}/../PythonWrap/parse_xml/parse_xml2.py")

  SET(ANCESTORS_CMD ${PYTHON_EXECUTABLE})                          #Command
  SET(ANCESTORS_CMD ${ANCESTORS_CMD} ${AMI_WRAPPER})                 #Wrapper
  SET(ANCESTORS_CMD ${ANCESTORS_CMD} ${XML_OUTPUT})                  #Input
  SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--libname" "${LIBNAME}")       
  SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--ancestors" ${classes_list})  #Options
  SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--ancestors-file" ${ANCESTORS_FILE} "-q")
  SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--templates" )
  SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--templatefile_dir" ${AMILab_SOURCE_DIR}/../PythonWrap/)

  IF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
    WRAP_MESSAGE("***** available external classes *****")
    SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--available_external_classes" ${AVAILABLE_EXTERNAL_CLASSES} )
    #FOREACH(C ${AVAILABLE_EXTERNAL_CLASSES})
    #  SET(ANCESTORS_CMD ${ANCESTORS_CMD} "\"${C}\"" )
    #ENDFOREACH(C ${AVAILABLE_EXTERNAL_CLASSES})
  ENDIF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
  
  IF(GENERATE_HTML_HELP AND CLASSES_URL_LIST AND HTML_DIR)
    # flag to generate html help
    SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--generate-html")
    # base URL html help
    SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--url" "${CLASSES_URL_LIST}")
    #HTML directory
    SET(ANCESTORS_CMD ${ANCESTORS_CMD} "--outputhtmldir" ${HTML_DIR})
  ENDIF(GENERATE_HTML_HELP AND CLASSES_URL_LIST AND HTML_DIR)

  SET( ANCESTORS_CMD_TXT "")
  FOREACH( C ${ANCESTORS_CMD})  
    SET( ANCESTORS_CMD_TXT "${ANCESTORS_CMD_TXT} ${C}")
  ENDFOREACH( C ${ANCESTORS_CMD})
  WRAP_MESSAGE("ANCESTORS_CMD: ${ANCESTORS_CMD_TXT}")

  EXECUTE_PROCESS(
    COMMAND ${ANCESTORS_CMD}
    RESULT_VARIABLE ANCESTORS_CMD_RESULT
    ERROR_VARIABLE  ANCESTORS_CMD_ERROR
    OUTPUT_VARIABLE ancestors_result
  )

  IF(ANCESTORS_CMD_RESULT)
    MESSAGE(SEND_ERROR "Failed the generation of ANCESTORS file: ${ANCESTORS_CMD_ERROR} - ${ANCESTORS_CMD_RESULT}")
  ENDIF(ANCESTORS_CMD_RESULT)

ENDMACRO( CREATE_ANCESTORS )

#
# Check existence of files to create
# if missing, add them to OUTPUT_LIST
# and to the list of missing elements
#
# needs:
#   GENERATED_DIR
#   ClassUsedName
#
MACRO( CHECK_WRAPPED_FILES ELTS_LIST MISSING_VAR)
  FOREACH( elt  ${ELTS_LIST})
    ClassUsedName( elt m_elt )
    IF( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_elt}.cpp) OR
        (NOT EXISTS ${GENERATED_DIR}/wrap_${m_elt}.h))
      SET(OUTPUT_LIST ${GENERATED_DIR}/wrap_${m_elt}.cpp ${OUTPUT_LIST})
      SET(OUTPUT_LIST ${GENERATED_DIR}/wrap_${m_elt}.h ${OUTPUT_LIST})
      SET(${MISSING_VAR} ${elt} ${${MISSING_VAR}})
    ENDIF( (NOT EXISTS ${GENERATED_DIR}/wrap_${m_elt}.cpp) OR
           (NOT EXISTS ${GENERATED_DIR}/wrap_${m_elt}.h))
  ENDFOREACH( elt ${ELTS_LIST}) 
ENDMACRO( CHECK_WRAPPED_FILES ELTS_LIST MISSING_VAR)


#-------------------------------------------------------------------------------
#
# Wrap the classes and functions
#
# needed:
#   NB_MISSING_CLASSES
#   NB_MISSING_FUNCTIONS
#   NB_MISSING_METHODS
#   MISSING_CLASSES
#   MISSING_FUNCTIONS
#   MISSING_METHODS (optional)
#   GENERATED_DIR
#   LIBNAME
#   LIBFILTER (optional)
#   LIBCONSTRUCTOR (optional)
#   PYTHON_EXECUTABLE
#   AMI_WRAPPER
#   ancestors_list
#   functions_list
#   OUTPUT_LIST
#   methodpointers_list (optional)
#   AVAILABLE_EXTERNAL_CLASSES (optional)
#   EXTERNAL_DLLNAME (optional)
#   GENERATE_HTML_HELP
#   CLASSES_URL_LIST (if GENERATE_HTML_HELP)
#   HTML_DIR (if GENERATE_HTML_HELP)
#
# output:
#  command to wrap all the classes, functions, etc ...
#
MACRO( WRAP_CODE )
  #
  #
  IF(NOT DEFINED NB_MISSING_CLASSES)
    SET(NB_MISSING_CLASSES 0)
  ENDIF(NOT DEFINED NB_MISSING_CLASSES)
  IF(NOT DEFINED NB_MISSING_FUNCTIONS)
    SET(NB_MISSING_FUNCTIONS 0)
  ENDIF(NOT DEFINED NB_MISSING_FUNCTIONS)
  IF(NOT DEFINED NB_MISSING_METHODS)
    SET(NB_MISSING_METHODS 0)
  ENDIF(NOT DEFINED NB_MISSING_METHODS)
  #
  #
  IF ((${NB_MISSING_CLASSES}   GREATER 0)                 OR 
      (${NB_MISSING_FUNCTIONS} GREATER 0)                 OR
      (${NB_MISSING_METHODS}   GREATER 0)                 OR
      (NOT EXISTS ${GENERATED_DIR}/addwrap_${LIBNAME}.h)  OR
      (NOT EXISTS ${GENERATED_DIR}/addwrap_${LIBNAME}.cpp))

    WRAP_MESSAGE("Try to generate wrapping...")
    WRAP_MESSAGE("PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
    # to avoid too long command, write available classes and functions to a file in disk
    #IF(DEFINED MISSING_METHODS)
    SET(available_classes_list ${ancestors_list} ${methodpointers_list})
    #ELSE(DEFINED MISSING_METHODS)
    #  SET(available_classes_list ${ancestors_list})
    #ENDIF(DEFINED MISSING_METHODS)

    IF(DEFINED available_classes_list)
      LIST(SORT               available_classes_list)
      LIST(REMOVE_DUPLICATES  available_classes_list)
      FILE(WRITE ${GENERATED_DIR}/available_classes.txt "${available_classes_list}")
    ENDIF(DEFINED available_classes_list)

    IF(DEFINED functions_list)
      LIST(SORT               functions_list)
      LIST(REMOVE_DUPLICATES  functions_list)
      FILE(WRITE ${GENERATED_DIR}/available_functions.txt "${functions_list}")
    ENDIF(DEFINED functions_list)


    SET(  WRAP_CMD ${PYTHON_EXECUTABLE})
    SET(  WRAP_CMD ${WRAP_CMD} ${AMI_WRAPPER})
    SET(  WRAP_CMD ${WRAP_CMD} ${XML_OUTPUT})
    SET(  WRAP_CMD ${WRAP_CMD} "--libname" "${LIBNAME}")
    IF(DEFINED LIBFILTER)
      SET(WRAP_CMD ${WRAP_CMD} "--filter" "\"${LIBFILTER}\"")
    ENDIF(DEFINED LIBFILTER)
    IF(DEFINED LIBCONSTRUCTOR)
      SET(WRAP_CMD ${WRAP_CMD} "--constructor" "\"${LIBCONSTRUCTOR}\"")
    ENDIF(DEFINED LIBCONSTRUCTOR)
    IF(DEFINED DLLNAME)
      SET(WRAP_CMD ${WRAP_CMD} "--dllname" ${DLLNAME})
    ENDIF(DEFINED DLLNAME)
    SET(  WRAP_CMD ${WRAP_CMD} "--classes" ${MISSING_CLASSES})
    IF(DEFINED MISSING_METHODS)
      SET(WRAP_CMD ${WRAP_CMD} "--methodpointers" "${MISSING_METHODS}")
    ENDIF(DEFINED MISSING_METHODS)
    SET(  WRAP_CMD ${WRAP_CMD} "--available_classes_file" "${GENERATED_DIR}/available_classes.txt")
    IF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
      WRAP_MESSAGE("***** available external classes *****")
      SET(WRAP_CMD ${WRAP_CMD} "--available_external_classes" "${AVAILABLE_EXTERNAL_CLASSES}")
      IF(DEFINED EXTERNAL_DLLNAME)
        SET(WRAP_CMD ${WRAP_CMD} "--external_dllname" ${EXTERNAL_DLLNAME} )
      ENDIF(DEFINED EXTERNAL_DLLNAME)
    ENDIF(DEFINED AVAILABLE_EXTERNAL_CLASSES)
    IF(DEFINED HAS_FUNCTIONS)
      SET(WRAP_CMD ${WRAP_CMD} "--functions" "${MISSING_FUNCTIONS}")
      SET(WRAP_CMD ${WRAP_CMD} "--available_functions_file" "${GENERATED_DIR}/available_functions.txt")
    ENDIF(DEFINED HAS_FUNCTIONS)
    #SET(WRAP_CMD ${WRAP_CMD} "--wrap_includes" ${WrapWxWidgetsDir})
    SET(  WRAP_CMD ${WRAP_CMD} "--outputdir" ${GENERATED_DIR})
    SET(  WRAP_CMD ${WRAP_CMD} "--addwrap")
    SET(  WRAP_CMD ${WRAP_CMD} "--profile")
    SET(  WRAP_CMD ${WRAP_CMD} "--templates")
    SET(  WRAP_CMD ${WRAP_CMD} "--templatefile_dir" ${AMILab_SOURCE_DIR}/../PythonWrap/)
    IF(GENERATE_HTML_HELP)
      # flag to generate html help
      SET(WRAP_CMD ${WRAP_CMD} "--generate-html")
      # base URL html help
      SET(WRAP_CMD ${WRAP_CMD} "--url" "${CLASSES_URL_LIST}")
      #HTML directory
      SET(WRAP_CMD ${WRAP_CMD} "--outputhtmldir" ${HTML_DIR})
    ENDIF(GENERATE_HTML_HELP)
    SET(  WRAP_CMD ${WRAP_CMD} "-q")

    # Write the command to the standard output for information
    SET(WRAP_CMD_TXT "")
    FOREACH( C ${WRAP_CMD})
      SET( WRAP_CMD_TXT "${WRAP_CMD_TXT} ${C}")
    ENDFOREACH( C ${WRAP_CMD})
    WRAP_MESSAGE("WRAP_CMD: ${WRAP_CMD_TXT}")

    IF(EXISTS  ${GENERATED_DIR}/../classes.txt)
      SET( CLASSES_FILES ${GENERATED_DIR}/../classes.txt)
    ENDIF(EXISTS  ${GENERATED_DIR}/../classes.txt)
    IF(EXISTS  ${GENERATED_DIR}/../../classes_common.txt)
      SET( CLASSES_FILES ${CLASSES_FILES} ${GENERATED_DIR}/../../classes_common.txt)
    ENDIF(EXISTS  ${GENERATED_DIR}/../../classes_common.txt)

    ADD_CUSTOM_COMMAND(
      OUTPUT
        ${OUTPUT_LIST} 
        ${GENERATED_DIR}/addwrap_${LIBNAME}.h
        ${GENERATED_DIR}/addwrap_${LIBNAME}.cpp
      COMMAND
        ${WRAP_CMD}
      DEPENDS
        ${CLASSES_FILES}
      VERBATIM
    )
  ENDIF ( (${NB_MISSING_CLASSES}   GREATER 0)                 OR 
          (${NB_MISSING_FUNCTIONS} GREATER 0)                 OR
          (${NB_MISSING_METHODS}   GREATER 0)                 OR
          (NOT EXISTS ${GENERATED_DIR}/addwrap_${LIBNAME}.h)  OR
          (NOT EXISTS ${GENERATED_DIR}/addwrap_${LIBNAME}.cpp))
ENDMACRO( WRAP_CODE )

