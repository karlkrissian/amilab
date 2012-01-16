# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found.  Any number of sources could be listed here.


# Make sure the compiler can find include files from our Hello library.
include_directories (
  ${AMILAB_SOURCE_DIR}/Wrapping/include
  ${AMILAB_SOURCE_DIR}/CommonBase
  ${AMILAB_SOURCE_DIR}/Common/include
  ${AMILAB_SOURCE_DIR}/LanguageBase
  #${AMILAB_SOURCE_DIR}/Language
  ${Boost_INCLUDE_DIR}
  )

#INCLUDE( ${wxWidgets_USE_FILE})

add_subdirectory ( WrapImports        )
add_subdirectory ( WrapCommon         )
add_subdirectory ( WrapBasicTypes     )
add_subdirectory ( WrapAMIFluid       )
add_subdirectory ( WrapITK            )
add_subdirectory ( WrapVTK            )
add_subdirectory ( WrapmyVTK          )
add_subdirectory ( WrapFilters        )
add_subdirectory ( WrapSystem         )
add_subdirectory ( WrapWII            )
add_subdirectory ( WrapInterface      )
add_subdirectory ( WrapWxWidgets      )
IF (AMI_WRAP_ULTRASOUND)
  add_subdirectory ( WrapUltrasound  )
ENDIF(AMI_WRAP_ULTRASOUND)
add_subdirectory ( WrapIO             )
#add_subdirectory ( WrapImage          )
#add_subdirectory ( WrapSurface        )
#add_subdirectory ( WrapDessinImage    )
#add_subdirectory ( WrapViewer3D       )
#add_subdirectory ( WrapGLTransfMatrix )
add_subdirectory ( WrapWxVTK          )
add_subdirectory ( WrapExamples       )
add_subdirectory ( WrapAlgorithms     )
add_subdirectory ( WrapLanguage       )
IF (AMI_WRAP_MICRONTRACKER)
  add_subdirectory ( WrapMicronTracker  )
ENDIF(AMI_WRAP_MICRONTRACKER)

