# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Graph
  )

SET( Graph_SRCS
  dijkstra.cpp
)

my_add_library ( Graph)
