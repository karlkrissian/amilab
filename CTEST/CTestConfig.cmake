## This file should be placed in the root directory of your project.
## Then modify the CMakeLists.txt file in the root directory of your
## project to incorporate the testing dashboard.
## # The following are required to uses Dart and the Cdash dashboard
##   ENABLE_TESTING()
##   INCLUDE(CTest)
set(CTEST_PROJECT_NAME "AMILab")
set(CTEST_NIGHTLY_START_TIME "02:30:00 WET")
#set(CTEST_NIGHTLY_START_TIME "15:03:00 CEST")

set(BUILDNAME "${AMILAB_BIN}-${CMAKE_SYSTEM}") 
set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "www.ctm.ulpgc.es")
set(CTEST_DROP_LOCATION "/CDash/submit.php?project=AMILab")
set(CTEST_DROP_SITE_CDASH TRUE)
