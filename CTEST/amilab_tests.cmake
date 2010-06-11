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

#
# Test: Segmentation.
#
ADD_AMILAB_TESTS(test_levelsets "-quit" "${PROJECT_SOURCE_DIR}/../tests/Segmentation/test_levelsets.amil")

#
# test: InputOutput.
#
SET(options ".vtk" ".mhd" ".ami" ".ami.gz")

FOREACH(option ${options})
  ADD_AMILAB_TESTS(test_readwrite${option} "-quit" "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ${option})
ENDFOREACH(option)

SET(options ".png" ".jpg" ".tiff" ".bmp")

FOREACH(option ${options})
  ADD_AMILAB_TESTS(test_readwrite_picture${option} "-quit" "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ${option})
ENDFOREACH(option)

#
# Test: Operations --> Basics
#
SET(options "FirstParam" "SecondParam" "ThirdParam" "FourthParam" "FifthParam")

ADD_AMILAB_TESTS(test_parameter "-quit" "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_parameter.amil" ${options})

SET(options "test_fibonacci.amil" "test_prime_number.amil" "test_factorial.amil" "test_greatest_common_divisor.amil"
            "test_float_type.amil" "test_double_type.amil" "test_inc_and_dec_operator.amil" "test_abs_function.amil"
            "test_round_function.amil" "test_area_of_circle.amil" "test_trigonometric_functions.amil")

FOREACH(option ${options})
  ADD_AMILAB_TESTS(${option} "-quit" "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/${option}")
ENDFOREACH(option)

SET(options "test_dessinimage_compare.amil"    "test_dessinimage_isocontour.amil"  "test_dessinimage_update.amil"
            "test_dessinimage_drawcircle.amil" "test_dessinimage_window_size.amil" "test_dessinimage_position.amil"
            "test_dessinimage_zoom.amil"       "test_dessinimage_getimage.amil"    "test_dessinimage_setCompTransf.amil"
            "test_dessinimage_vect.amil"
   )

FOREACH(option ${options})
  ADD_AMILAB_TESTS(${option} "-quit" "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/${option}")
ENDFOREACH(option)

