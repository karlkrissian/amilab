# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.

MESSAGE("CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
include_directories (
  ${CMAKE_CURRENT_SOURCE_DIR}/../../Pixmaps
)

INCLUDE(${wxWidgets_USE_FILE})

SET(  wxParams_SRCS
    MyToolBar.cpp
    ParamBox.cpp
    widget.cpp
    wxEnumerationParameter.cpp
    palette.cpp
    ParamPanel.cpp
    wxColorParameter.cpp
    myTextCtrl.cpp
    mySpinCtrl.cpp
    mySlider.cpp
    mySpinButton.cpp
    wxParamTypes.cpp
    wxIntegerParameter.cpp
    wxFloatParameter.cpp
    CoutwxString.cpp
)


SET(  wxParams_HDRS
  MyToolBar.h
  ParamBox.hpp
  widget.hpp
  wxEnumerationParameter.h
  ParamPanel.hpp
  wxColorParameter.h
  myTextCtrl.h
  mySpinCtrl.h
  mySlider.h
  mySpinButton.h
  wxParamTypes.hpp
  wxIntegerParameter.h
  wxFloatParameter.h
  wxNumericParameter.h
  CoutwxString.h
  wxStringSelectionParameter.h
  couleur.hpp
  palette.hpp
  StructParams.hpp    
)


SET(  wxParams_SRCS
  ${wxParams_SRCS}
  ${wxParams_HDRS}
)

add_library (wxParams  ${wxParams_SRCS})

# INSTALL(TARGETS wxParams
#   LIBRARY DESTINATION lib
#   ARCHIVE DESTINATION lib
# )
