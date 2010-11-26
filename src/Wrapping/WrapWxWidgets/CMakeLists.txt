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

SET(output_src)
FOREACH(loop_var ${wx_SRCS})
  SET(include_header "#include \"${loop_var}\"")
  SET(output_src ${output_src} ${include_header})
ENDFOREACH(loop_var)

SET(wx_source_list "")
SET(output_dir_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/Generated/")
LIST(LENGTH output_src output_src_length)
SET(N 9)

WHILE(output_src_length)

  SET(include_list "")
  FOREACH(counter RANGE ${N})

    IF(output_src_length)
      LIST(GET output_src -1 element_src)
      SET(include_list "${include_list} ${element_src}\n")
      LIST(REMOVE_AT output_src -1)
      LIST(LENGTH output_src output_src_length)
    ENDIF(output_src_length)

  ENDFOREACH(counter)

  SET(name_output "wrap_wx${AMI_WXWIDGETS_VERSION}_${output_src_length}.cpp")
  FILE(WRITE "${output_dir_path}${name_output}" ${include_list})
  SET(wx_source_list ${wx_source_list} "Generated/${name_output}")

ENDWHILE(output_src_length)

MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${wx_source_list}\n")

SET(  WrapWxWidgets_SRCS
  wrap_wxsamples.cpp
  wrap_wxfunctions.cpp
#  ${wx_source_list}
  ${wx_SRCS}
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
