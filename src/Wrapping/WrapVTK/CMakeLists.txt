# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

MESSAGE("***** Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTK/
  ${AMILAB_SOURCE_DIR}/Graphic/wxVTKSamples/
  ${AMILAB_SOURCE_DIR}/wxParams
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxWidgets/${AMI_WXWIDGETS_VERSION}
  ${AMILAB_SOURCE_DIR}/Wrapping/WrapWxVTK
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/${AMI_VTK_VERSION}
)

INCLUDE( ${VTK_USE_FILE} )

INCLUDE( ${wxWidgets_USE_FILE})

file(GLOB vtk_HDRS  "${AMI_VTK_VERSION}/*.h"  )
file(GLOB vtk_SRCS  "${AMI_VTK_VERSION}/*.cpp")

MESSAGE("Wrapping VTK...")

SET(source_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK")
SET(new_source_code_list "")
GenerateSourcesWrapping (new_source_code_list ${source_path} "${vtk_SRCS}")

MESSAGE("VTK wrap files: ${new_source_code_list}\n")

# SET(output_src)
# FOREACH(loop_var ${vtk_SRCS})
#   SET(include_header "#include \"${loop_var}\"")
#   SET(output_src ${output_src} ${include_header})
# ENDFOREACH(loop_var)
# 
# SET(vtk_source_list "")
# SET(output_dir_path "${AMILAB_SOURCE_DIR}/Wrapping/WrapVTK/Generated/")
# LIST(LENGTH output_src output_src_length)
# SET(N 9)
# 
# WHILE(output_src_length)
# 
#   SET(include_list "")
#   FOREACH(counter RANGE ${N})
# 
#     IF(output_src_length)
#       LIST(GET output_src -1 element_src)
#       SET(include_list "${include_list} ${element_src}\n")
#       LIST(REMOVE_AT output_src -1)
#       LIST(LENGTH output_src output_src_length)
#     ENDIF(output_src_length)
# 
#   ENDFOREACH(counter)
# 
#   SET(name_output "wrap_vtk${AMI_VTK_VERSION}_${output_src_length}.cpp")
#   FILE(WRITE "${output_dir_path}${name_output}" ${include_list})
#   SET(vtk_source_list ${vtk_source_list} "Generated/${name_output}")
# 
# ENDWHILE(output_src_length)


SET(  WrapVTK_SRCS
  vtkwrap.cpp
  wrapVTK.cpp
)

SET(WrapVTK_HDRS
	../include/vtkwrap.h
	../include/wrapVTK.h
)

SET(WrapVTK_SRCS
     ${WrapVTK_SRCS}
     ${WrapVTK_HDRS}
     ${new_source_code_list}
     #${vtk_SRCS}
     ${vtk_HDRS}
)

my_add_library ( WrapVTK)
