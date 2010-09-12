# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
${AMILAB_SOURCE_DIR}/Common 
${AMILAB_SOURCE_DIR}/Math 
${Boost_INCLUDE_DIR})
 
SET(Math_SRCS
)

SET(Math_HDRS
)

SET(Math_SRCS
	 ${Math_SRCS}
     ${Math_HDRS}
)

my_add_library (Math )
