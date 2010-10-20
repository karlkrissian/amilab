

#-------------------------------------------------------------------------------
MACRO( InitPrintSources)
#-------------------------------------------------------------------------------
    FILE(WRITE ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/source_list.txt "")
ENDMACRO( InitPrintSources)
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
MACRO( PrintSources var)
#-------------------------------------------------------------------------------
  FILE(APPEND ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/source_list.txt "\n")
  FOREACH(sourcefile ${${var}_SRCS} )
    IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${sourcefile})
      FILE(RELATIVE_PATH filename ${${CMAKE_PROJECT_NAME}_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${sourcefile})
    ELSE( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${sourcefile})
      # sourcefile already contains the full path
      FILE(RELATIVE_PATH filename ${${CMAKE_PROJECT_NAME}_SOURCE_DIR} ${sourcefile})
    ENDIF( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${sourcefile})
    FILE(APPEND ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/source_list.txt "src/${filename}\n")
    # look for a header file
  ENDFOREACH( sourcefile)

  FILE(GLOB ${var}_INC RELATIVE ${${CMAKE_PROJECT_NAME}_SOURCE_DIR} *.h *.hpp *.hxx *.ypp *.lpp *.tpp CMakeLists.txt)
  FOREACH(sourcefile ${${var}_INC} )
    FILE(APPEND ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/source_list.txt "src/${sourcefile}\n")
    # look for a header file
  ENDFOREACH( sourcefile)
ENDMACRO(PrintSources)
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
MACRO( my_add_library var)
#-------------------------------------------------------------------------------
  add_library (${var}   ${${var}_SRCS})
  PrintSources(${var})
ENDMACRO(my_add_library)
#-------------------------------------------------------------------------------
