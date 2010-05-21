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
# First test: test_levelsets.
#
ADD_TEST(test_levelsets
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/Segmentation/test_levelsets.amil")

#
# Second test: test_readwrite.
#
ADD_TEST(test_readwrite_vtk
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".vtk")

ADD_TEST(test_readwrite_mhd
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".mhd")

ADD_TEST(test_readwrite_ami
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".ami")

ADD_TEST(test_readwrite_ami.gz
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite.amil" ".ami.gz")

#
# Third test: test_readwrite_picture.
#
ADD_TEST(test_readwrite_picture_png
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".png")

ADD_TEST(test_readwrite_picture_jpg
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".jpg")

ADD_TEST(test_readwrite_picture_tiff
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".tiff")

ADD_TEST(test_readwrite_picture_bmp
         "${PROJECT_BINARY_DIR}/${AMILAB_BIN}"
         "${PROJECT_SOURCE_DIR}/../tests/InputOutput/test_readwrite_picture.amil" ".bmp")

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
                     PROPERTIES PASS_REGULAR_EXPRESSION "${passRegex}"
                                FAIL_REGULAR_EXPRESSION "${failRegex}"
                                LABELS "AMILab")
