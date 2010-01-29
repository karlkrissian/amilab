# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/SplineThevenaz
  )

SET(SplineThevenaz_SRCS
  coeff.c 
  interpol.c
)

SET(SplineThevenaz_HDRS
	coeff.h
	interpol.h
)

SET(SplineThevenaz_SRCS
     ${SplineThevenaz_SRCS}
     ${SplineThevenaz_HDRS}
)

my_add_library ( SplineThevenaz)
