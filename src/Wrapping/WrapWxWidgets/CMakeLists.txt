# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/AMILab
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_WXWIDGETS_VERSION}
)

INCLUDE( ${wxWidgets_USE_FILE})


file(GLOB wx_HDRS  "${AMI_WXWIDGETS_VERSION}/*.h"  )
file(GLOB wx_SRCS  "${AMI_WXWIDGETS_VERSION}/*.cpp")

MESSAGE("Wrapping wxWidgets...")

#-------------------------------------------------------------------------------
#Input parameters:
# n: Number of include in each file
# source_code_path: Path to the source code.
# output_src: Source code listing.
#-------------------------------------------------------------------------------
#Output parameters:
# new_source_list: Source code to generate.
#-------------------------------------------------------------------------------
SET(n 9)
SET(source_code_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/")
SET(output_src "")
SET(new_source_list "")
SET(file_source_list "")

FOREACH(loop_var ${wx_SRCS})
  SET(include_header "#include \"${loop_var}\"")
  SET(output_src ${output_src} ${include_header})
ENDFOREACH(loop_var)

SET(counter_file 0)
SET(output_dir_path "${source_code_path}Generated/")
LIST(LENGTH output_src output_src_length)

IF(EXISTS ${output_dir_path})
  MESSAGE("Exists ${output_dir_path} directory")
ELSE(EXISTS ${output_dir_path})
  MESSAGE("Create ${output_dir_path} directory")
  FILE(MAKE_DIRECTORY ${output_dir_path})
ENDIF(EXISTS ${output_dir_path})

WHILE(output_src_length)

  SET(include_list "")
  FOREACH(counter RANGE ${n})

    IF(output_src_length)
      LIST(GET output_src -1 element_src)
      SET(include_list "${include_list} ${element_src}\n")
      LIST(REMOVE_AT output_src -1)
      LIST(LENGTH output_src output_src_length)
    ENDIF(output_src_length)

  ENDFOREACH(counter)

  SET(name_output "wrap_${counter_file}.cpp")
  MATH(EXPR counter_file "${counter_file}+1")

  IF(EXISTS ${output_dir_path}${name_output})
    MESSAGE("Exists ${output_dir_path}${name_output}")
    FILE(READ ${output_dir_path}${name_output} output_compare)
    IF(${output_compare} STREQUAL ${include_list})
      SET(file_source_list ${file_source_list} "${output_dir_path}${name_output}\n")
    ELSE(${output_compare} STREQUAL ${include_list})
      MESSAGE("Create ${output_dir_path}${name_output}")
      FILE(WRITE "${output_dir_path}${name_output}" ${include_list})
      SET(new_source_list ${new_source_list} "${output_dir_path}${name_output}")
      SET(file_source_list ${file_source_list} "${output_dir_path}${name_output}\n")
    ENDIF(${output_compare} STREQUAL ${include_list})
  ELSE(EXISTS ${output_dir_path}${name_output})
    MESSAGE("Create ${output_dir_path}${name_output}")
    FILE(WRITE "${output_dir_path}${name_output}" ${include_list})
    SET(new_source_list ${new_source_list} "${output_dir_path}${name_output}")
    SET(file_source_list ${file_source_list} "${output_dir_path}${name_output}\n")
  ENDIF(EXISTS ${output_dir_path}${name_output})

ENDWHILE(output_src_length)

FILE(WRITE "${output_dir_path}wrap_source_list.txt" ${file_source_list})

MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${new_source_list}\n")

SET(  WrapWxWidgets_SRCS
  wrap_wxsamples.cpp
  wrap_wxfunctions.cpp
  ${new_source_list}
  #${wx_SRCS}
)


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

IF (AMI_USE_PRECOM_HEADERS)
  IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_PCH_RULE(${AMILAB_SOURCE_DIR}/Wrapping/include/WrapWxWidgets_header.h WrapWxWidgets_SRCS)
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )
ENDIF(AMI_USE_PRECOM_HEADERS)


my_add_library ( WrapWxWidgets)
