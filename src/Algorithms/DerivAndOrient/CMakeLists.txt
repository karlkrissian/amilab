
include_directories (
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/Graphic
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/LanguageBase
  ${AMILAB_SOURCE_DIR}/Language
  )

SET(  DerivAndOrient_SRCS
 LocalStructure.cpp
)

SET(DerivAndOrient_HDRS
 LocalStructure.h
)

SET(DerivAndOrient_SRCS
     ${DerivAndOrient_SRCS}
     ${DerivAndOrient_HDRS}
)

my_add_library (DerivAndOrient)
