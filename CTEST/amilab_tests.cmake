#
# Tests for AMILab proyect.
#


#-------------------------------------------------------------------------------
#
# MACRO: ADD_AMILAB_TESTS.
# ARGUMENTS:
#     name-test: Test name. 
#     amilab-options: Options to invoke AMiLab.
#     test: Test to run.
#     test-arg: Arguments for use with the test 
#     pass-regex: Regular expression to determine whether a test was successful.
#     fail-regex: Regular expression for when a test fails.
# DESC
#-------------------------------------------------------------------------------
MACRO(ADD_AMILAB_TESTS name-test amilab-options test test-arg)
#-------------------------------------------------------------------------------

ADD_TEST(${name-test}
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         ${amilab-options}
         ${test} ${test-arg})

SET_TESTS_PROPERTIES(${name-test}
                     PROPERTIES PASS_REGULAR_EXPRESSION "${passRegex}"
                                FAIL_REGULAR_EXPRESSION "${failRegex}"
                                LABELS "AMILab")

ENDMACRO(ADD_AMILAB_TESTS)
#-------------------------------------------------------------------------------

message ("\n\n${CMAKE_BUILD_TOOL}\n\n")
#
# Enable testing for AMILab proyect.
#
ENABLE_TESTING()

#
# Include CDash dashboard testing module.
#
INCLUDE(CTest)

#
# First test: Segmentation.
#
ADD_TEST(test_levelsets
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Segmentation/test_levelsets.amil")

#
# Second test: InputOutput.
#
ADD_TEST(test_readwrite_vtk
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".vtk")

ADD_TEST(test_readwrite_mhd
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".mhd")

ADD_TEST(test_readwrite_ami
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".ami")

ADD_TEST(test_readwrite_ami.gz
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".ami.gz")

ADD_TEST(test_readwrite_picture_png
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".png")

ADD_TEST(test_readwrite_picture_jpg
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".jpg")

ADD_TEST(test_readwrite_picture_tiff
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".tiff")

ADD_TEST(test_readwrite_picture_bmp
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".bmp")

#
# Third test: Operations --> Basics
#
ADD_TEST(test_fibonacci.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_fibonacci.amil")

ADD_TEST(test_prime_number.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_prime_number.amil")

ADD_TEST(test_factorial.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_factorial.amil")

ADD_TEST(test_greatest_common_divisor.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_greatest_common_divisor.amil")

ADD_TEST(test_parameter.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_parameter.amil" "FirstParam" "SecondParam" "ThirdParam" "FourthParam" "FifthParam")

ADD_TEST(test_float_type.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_float_type.amil")

ADD_TEST(test_double_type.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_double_type.amil")

ADD_TEST(test_inc_and_dec_operator.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_inc_and_dec_operator.amil")

ADD_TEST(test_abs_function.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_abs_function.amil")

ADD_TEST(test_round_function.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_round_function.amil")

ADD_TEST(test_area_of_circle.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_area_of_circle.amil")

ADD_TEST(test_trigonometric_functions.amil
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "-quit"
         "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/test_trigonometric_functions.amil")

#
# Define a regular expression to determine when the test fails or passes.
#
SET(failRegex "Test Failed !!!")
SET(passRegex "Test Succeeded !!!")

#
# Use the set_property command for to modify the pass/fail flag of the test.
#
SET_TESTS_PROPERTIES(test_levelsets 
                     test_readwrite_vtk test_readwrite_mhd test_readwrite_ami test_readwrite_ami.gz
                     test_readwrite_picture_png test_readwrite_picture_jpg test_readwrite_picture_tiff test_readwrite_picture_bmp
                     test_fibonacci.amil test_prime_number.amil test_factorial.amil test_greatest_common_divisor.amil
                     test_parameter.amil test_float_type.amil test_double_type.amil test_inc_and_dec_operator.amil test_abs_function.amil
                     test_round_function.amil test_area_of_circle.amil test_trigonometric_functions.amil
                     PROPERTIES PASS_REGULAR_EXPRESSION "${passRegex}"
                                FAIL_REGULAR_EXPRESSION "${failRegex}"
                                LABELS "AMILab")
