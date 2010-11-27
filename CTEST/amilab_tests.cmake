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

SET(options "test_fibonacci.amil"                       "test_factorial.amil"       
            "test_prime_number.amil"                    "test_greatest_common_divisor.amil"
            "test_abs_function.amil"                    "test_round_function.amil"
            "test_area_of_circle.amil"                  "test_inc_and_dec_operator.amil" 
            "test_trigonometric_functions.amil"         "test_int_type.amil" 
            "test_float_type.amil"                      "test_double_type.amil" 
            "test_bool_type.amil"
    # DESSINIMAGE
            "test_dessinimage_compare.amil"             "test_dessinimage_isocontour.amil"    
            "test_dessinimage_update.amil"              "test_dessinimage_drawcircle.amil"
            "test_dessinimage_window_size.amil"         "test_dessinimage_position.amil"
            "test_dessinimage_zoom.amil"                "test_dessinimage_getimage.amil"
            "test_dessinimage_setCompTransf.amil"       "test_dessinimage_vect.amil"
    # VIEWER3D
            "test_viewer3d_window_size.amil"            "test_viewer3d_add_remove_reference.amil"
            "test_viewer3d_set_bg_ls_ld_la.amil"        "test_viewer3d_rotate_swapBuffers.amil" 
            "test_viewer3d_printmatrices.amil"          "test_viewer3d_compare.amil"
            "test_viewer3d_set_and_get_transform.amil"  "test_viewer3d_getimage.amil"           
            "test_gltransfmatrix.amil"            
    # IMAGE
            "test_image_creation_scalar.amil"           "test_image_creation_vectorial.amil"
            "test_image_translation_scalar.amil"        "test_image_translation_vectorial.amil"
            "test_image_txtytz_vectorial.amil"          "test_image_txtytz_scalar.amil"
            "test_image_setvoxelsize_scalar.amil"       "test_image_setvoxelsize_vectorial.amil"
            "test_image_conversion_double.amil"         "test_image_conversion_float.amil"
            "test_image_conversion_uint.amil"           "test_image_conversion_int.amil"
            "test_image_conversion_ushort.amil"         "test_image_conversion_short.amil"
            "test_image_conversion_uchar.amil"          "test_image_conversion_char.amil"
            "test_image_vdim.amil"                      "test_image_type.amil"
    # FILE
            "test_file_readwrite.amil"                  "test_file_readwrite_float.amil"
            "test_file_rewind.amil"                     "test_file_read.amil"
    # WXSTRING
            "test_wxString_append.amil"                 "test_wxString_remove.amil"
            "test_wxString_clear.amil"                  "test_wxString_replaceall.amil"
            "test_wxString_cmp.amil"                    "test_wxString_replacefirst.amil"
            "test_wxString_constructor.amil"            "test_wxString_setchar.amil"
            "test_wxString_isempty.amil"                "test_wxString_substring.amil"
            "test_wxString_issameas.amil"               "test_wxString_trim.amil"
            "test_wxString_length.amil"                 "test_wxString_truncate.amil"
            "test_wxString_empty.amil"                  "test_wxString_find.amil"
            "test_wxString_matches.amil"                "test_wxString_make_lower.amil"
            "test_wxString_make_upper.amil"             "test_wxString_fromascii_fromutf8.amil"
            "test_wxString_toascii.amil"                "test_wxString_todouble.amil"
            "test_wxString_tolong.amil"                 "test_wxString_toutf8.amil"
            "test_wxString.copy_constructor.amil"       "test_wxString_operators.amil"
            "test_wxString_constructor.amil"            "test_wxString_trycast.amil"
    # WXFILENAME
            "test_wxfilename_constructor.amil"          "test_wxfilename_assign.amil"
            "test_wxfilename_assigncwd.amil"            "test_wxfilename_assigndir.amil"
            "test_wxfilename_assignhomedir.amil"        "test_wxfilename_appenddir.amil"
            "test_wxfilename_setandget.amil"            "test_wxfilename_clear.amil"
            "test_wxfilename_touch.amil"                "test_wxfilename_directory.amil"
            "test_wxfilename_iscasesensitive.amil"      "test_wxfilename_absolute_relative.amil"
            "test_wxfilename_hasextandname.amil"        "test_wxfilename_file.amil"
            "test_wxfilename_isok.amil"                 "test_wxfilename_sameas.amil"
            "test_wxfilename_operators.amil"            "test_wxfilename_copy_constructor.amil"
    # CONTINUOUSMORPHOLOGY
            "test_continuousmorphology.amil")

FOREACH(option ${options})
  ADD_AMILAB_TESTS(${option} "-quit" "${PROJECT_SOURCE_DIR}/../tests/Operations/Basics/${option}")
ENDFOREACH(option)
