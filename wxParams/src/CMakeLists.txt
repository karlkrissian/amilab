# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.

# Make sure the compiler can find include files from our Hello library.

INCLUDE(${wxWidgets_USE_FILE})

SET(  wxParams_SRCS 
    MyToolBar.cpp  
    ParamBox.cpp    
    widget.cpp            
    wxEnumerationParameter.cpp  
    palette.cpp    
    ParamPanel.cpp  
    wxColorParameter.cpp  
    wxParamTypes.cpp
)

add_library (wxParams  ${wxParams_SRCS})

