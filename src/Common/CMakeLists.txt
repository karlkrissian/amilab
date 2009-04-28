# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (${AMILAB_SOURCE_DIR}/Common)

SET(Common_SRCS
chaine.cpp Duree.cpp Erreurs.cpp ficparam.cpp  StringUtils.cpp
)

# own macro to add the library and print the source files
# using xxx_SRCS variable
my_add_library (Common)
