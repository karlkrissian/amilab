## This file should be placed in the root directory of your project.
## Then modify the CMakeLists.txt file in the root directory of your
## project to incorporate the testing dashboard.
## # The following are required to uses Dart and the Cdash dashboard
##   ENABLE_TESTING()
##   INCLUDE(CTest)
set(CTEST_PROJECT_NAME "AMILab")
set(CTEST_NIGHTLY_START_TIME "02:30:00 WET")
#set(CTEST_NIGHTLY_START_TIME "15:03:00 CEST")


FILE(TO_CMAKE_PATH ${CMAKE_CXX_COMPILER} CMAKE_CXX_COMPILER_FILE)

MESSAGE( "CMAKE_CXX_COMPILER_FILE = ${CMAKE_CXX_COMPILER_FILE}")

STRING( REGEX REPLACE ".*/([^/]+)$" "\\1" CMAKE_CXX_COMPILER_NAME ${CMAKE_CXX_COMPILER_FILE} )

MESSAGE( "CMAKE_CXX_COMPILER_NAME = ${CMAKE_CXX_COMPILER_NAME}")

SET(BUILDNAME "${AMILAB_BIN}-${CMAKE_CXX_COMPILER_NAME}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
IF(SRCDIR_WC_TRUNK)
  SET(BUILDNAME "${BUILDNAME}-trunk")
ELSEIF(SRCDIR_WC_BRANCH)
  SET(BUILDNAME "${BUILDNAME}-branch-${SRCDIR_WC_BRANCH}")
ENDIF(SRCDIR_WC_BRANCH)

set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "www.ctm.ulpgc.es")
set(CTEST_DROP_LOCATION "/CDash/submit.php?project=AMILab")
set(CTEST_DROP_SITE_CDASH TRUE)
