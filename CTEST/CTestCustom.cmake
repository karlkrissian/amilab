SET(CTEST_CUSTOM_MAXIMUM_PASSED_TEST_OUTPUT_SIZE 0)
SET(CTEST_CUSTOM_MAXIMUM_FAILED_TEST_OUTPUT_SIZE 0)

SET(CTEST_CUSTOM_ERROR_EXCEPTION
  ${CTEST_CUSTOM_ERROR_EXCEPTION}
  "[0-9][0-9]*: aviso: "
)

SET(CTEST_CUSTOM_WARNING_MATCH
    ${CTEST_CUSTOM_WARNING_MATCH}
    "^.*aviso:.*$"
    "{standard input}:[0-9][0-9]*: Warning: ")

SET(CTEST_CUSTOM_MAXIMUM_NUMBER_OF_WARNINGS 10000)
SET(CTEST_CUSTOM_MAXIMUM_NUMBER_OF_ERRORS   10000)

SET(CTEST_START_WITH_EMPTY_BINARY_DIRECTORY TRUE)
SET(CTEST_OUTPUT_ON_FAILURE TRUE)
