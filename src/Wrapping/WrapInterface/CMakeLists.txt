# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${wxParams_INCLUDE_DIRS}
  ${AMILAB_SOURCE_DIR}/Common
  ${AMILAB_SOURCE_DIR}/Graphic/include
  ${AMILAB_SOURCE_DIR}/Algorithms/include
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/wxStcFrame
  ${AMILAB_SOURCE_DIR}/AMILab
  ${AMILAB_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${PTHREADS_INCLUDE_DIR}
)

INCLUDE( ${wxWidgets_USE_FILE})

SET(  WrapInterface_SRCS
  wrap_MainFrame.cpp
#  wrap_imagedraw.cpp 
  wrap_parampanel.cpp 
  wrap_wxDrawingWindow.cpp 
  wrap_wxEditor.cpp 
  wrap_wxStcFrame.cpp 
  wrap_FenetreDessin.cpp 
  wrap_dwControlPoint.cpp
  wrap_dwPoint2D.cpp
  wrap_dwCurve.cpp
  wrap_dwControlledCurve.cpp
)

SET(WrapInterface_HDRS
  ../include/wrap_MainFrame.h
#  wrap_imagedraw.h
  ../include/wrap_parampanel.h 
  ../include/wrap_wxDrawingWindow.h
  ../include/wrap_wxEditor.h
  ../include/wrap_wxStcFrame.h 
  ../include/wrap_FenetreDessin.h
  ../include/wrap_dwControlPoint.h
  ../include/wrap_dwPoint2D.h
  ../include/wrap_dwCurve.h
  ../include/wrap_dwControlledCurve.h
)

SET(WrapInterface_SRCS
     ${WrapInterface_SRCS}
     ${WrapInterface_HDRS}
)

my_add_library ( WrapInterface)
