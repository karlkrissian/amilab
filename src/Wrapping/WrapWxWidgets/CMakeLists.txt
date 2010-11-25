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

SET(counter 1)
SET(counter_file 0)
SET(num 10)
SET(output_src)
SET(wx_source_list "")
SET(output_dir_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/Generated/")
FOREACH(loop_var ${wx_SRCS})

  SET(include_header "#include \"${loop_var}\"\n")
  SET(output_src ${output_src} ${include_header})

  IF(counter EQUAL num)

    SET(name_output "wrap_wx${AMI_WXWIDGETS_VERSION}_${counter_file}.cpp")
    FILE(WRITE "${output_dir_path}${name_output}" ${output_src})
    SET(wx_source_list ${wx_source_list} "Generated/${name_output}")
    SET(counter 1)
    MATH(EXPR counter_file "${counter_file}+1")
    SET(output_src "")

  ELSE(counter EQUAL num)
    MATH(EXPR counter "${counter}+1")
  ENDIF(counter EQUAL num)
  
ENDFOREACH(loop_var)

MESSAGE("wxWidgets ${AMI_WXWIDGETS_VERSION} wrap files: ${wx_source_list}\n")

SET(  WrapWxWidgets_SRCS
  wrap_wxsamples.cpp
  wrap_wxfunctions.cpp
  ${wx_source_list}
#  ${wx_SRCS}
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
