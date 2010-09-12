# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
${AMILAB_SOURCE_DIR}/Common 
${AMILAB_SOURCE_DIR}/DistTransf 
)

SET(DistTransf_SRCS dist_squared.cpp)

SET(DistTransf_HDRS dist_squared.hpp)

SET(DistTransf_SRCS
     ${DistTransf_SRCS}
     ${DistTransf_HDRS}
)

my_add_library (DistTransf)
