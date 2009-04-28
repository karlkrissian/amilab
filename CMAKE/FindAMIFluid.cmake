# - Find the Amifluid library
# This module searches for the Amifluid library .
#
# This module defines these variables:
#
#  AMIFLUID_FOUND
#      True if the Amifluid library was found
#  AMIFLUID_LIBRARY
#      The location of the Amifluid library
#  AMIFLUID_INCLUDE_DIR
#      The include directory of the Amifluid library
#
#


#
# Find the header file
#
FIND_PATH(AMIFLUID_INCLUDE_DIR ami.h)

#
# Find the library
#

SET(names AMIFluid)
    
FIND_LIBRARY(AMIFLUID_LIBRARY ${names}
    DOC "AMILab for Fluid library")

FIND_PATH(AMIFLUID_INCLUDE AMIFluid/ami.h)
SET(AMIFLUID_INCLUDE_DIR ${AMIFLUID_INCLUDE}/AMIFluid)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Amifluid DEFAULT_MSG
    AMIFLUID_LIBRARY AMIFLUID_INCLUDE_DIR)

IF(AMIFLUID_INCLUDE_DIR AND AMIFLUID_LIBRARY)
    SET(AMIFLUID_INCLUDE_DIRS ${AMIFLUID_INCLUDE_DIR})
    SET(AMIFLUID_LIBRARIES    ${AMIFLUID_LIBRARY})
ENDIF(AMIFLUID_INCLUDE_DIR AND AMIFLUID_LIBRARY)

#MARK_AS_ADVANCED(AMIFLUID_INCLUDE_DIR)
#MARK_AS_ADVANCED(AMIFLUID_LIBRARY)
