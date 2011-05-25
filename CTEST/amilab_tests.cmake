#
# Tests for AMILab proyect.
#

#
# Enable testing for AMILab proyect.
#
ENABLE_TESTING()

#
# Include CDash dashboard testing module.
#
INCLUDE(CTest)

#
# Define a regular expression to determine when the test fails or passes.
#
SET(failRegex "Test Failed !!!")
SET(passRegex "Test Succeeded !!!")

#-------------------------------------------------------------------------------
#
# MACRO: ADD_AMILAB_TESTS.
# ARGUMENTS:
#     name-test: Test name. 
#     amilab-options: Options to invoke AMiLab.
#     test: Test to run.
#     test-arg: Arguments for use with the test 
# DESCRIPTION: Add a test run with CTest. The macro use ARGN to indicate the
#              parameters of the test.
#
#-------------------------------------------------------------------------------
MACRO(ADD_AMILAB_TESTS name-test amilab-options test)
#-------------------------------------------------------------------------------

ADD_TEST(${name-test}
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         ${amilab-options}
         ${test} ${ARGN})

#
# Use the set_property command for to modify the pass/fail flag of the test.
#
SET_TESTS_PROPERTIES(${name-test}
                     PROPERTIES PASS_REGULAR_EXPRESSION "${passRegex}"
                                FAIL_REGULAR_EXPRESSION "${failRegex}"
                                LABELS "AMILab")

ENDMACRO(ADD_AMILAB_TESTS)
#-------------------------------------------------------------------------------

SET(AMIOPTIONS -hide -noscriptsmenu -quit)

#
# Test: Segmentation.
#
ADD_AMILAB_TESTS(test_levelsets ${AMIOPTIONS} "${PROJECT_SOURCE_DIR}/../tests/Segmentation/test_levelsets.amil")
#
# test: InputOutput.
#
SET(options ".vtk" ".mhd" ".ami" ".ami.gz")


FOREACH(option ${options})
  ADD_AMILAB_TESTS(test_readwrite${option} ${AMIOPTIONS} "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ${option})
ENDFOREACH(option)

SET(options ".png" ".jpg" ".tiff" ".bmp")

FOREACH(option ${options})
  ADD_AMILAB_TESTS(test_readwrite_picture${option} ${AMIOPTIONS} "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ${option})
ENDFOREACH(option)

#
# Test: Basics
#
SET(options "FirstParam" "SecondParam" "ThirdParam" "FourthParam" "FifthParam")

ADD_AMILAB_TESTS(parameter.amil ${AMIOPTIONS} "${PROJECT_SOURCE_DIR}/../tests/Basics/parameter.amil" ${options})

SET(options "file.amil"     "inc_and_dec_operator.amil"
            "routines.amil" "trigonometric_functions.amil"
   )

FOREACH(option ${options})
  ADD_AMILAB_TESTS(${option} ${AMIOPTIONS} "${PROJECT_SOURCE_DIR}/../tests/Basics/${option}")
ENDFOREACH(option)

#
# Test: PrimitivesType
#
SET(options "logical.amil"
            "numeric.amil"
   )     
FOREACH(option ${options})
  ADD_AMILAB_TESTS(${option} ${AMIOPTIONS} "${PROJECT_SOURCE_DIR}/../tests/PrimitivesType/${option}")
ENDFOREACH(option)


#
# Test: wxWidgets
#
SET(options "wxFileName.amil"
            "wxString.amil"
   )     
FOREACH(option ${options})
  ADD_AMILAB_TESTS(${option} ${AMIOPTIONS} "${PROJECT_SOURCE_DIR}/../tests/Wrapping/wxWidgets/${option}")
ENDFOREACH(option)

