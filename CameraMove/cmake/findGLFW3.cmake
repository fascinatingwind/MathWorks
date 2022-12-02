# Locate the glfw3 library
#
# This module defines the following variables:
#
# GLFW3_LIBRARY the name of the library;
# GLFW3_INCLUDE_DIR where to find glfw include files.
# GLFW3_FOUND true if both the GLFW3_LIBRARY and GLFW3_INCLUDE_DIR have been found.
#
# To help locate the library and include file, you can define a
# variable called GLFW3_ROOT which points to the root of the glfw library
# installation.
#
# default search dirs
#
# Cmake file from: https://github.com/daw42/glslcookbook
# Check system environment for root search directory


# Check environment for root search directory
set(GLFW3_ROOT $ENV{GLFW3_ROOT} )

# Put user specified location at beginning of search
if(GLFW3_ROOT)
	set(GLFW3_INCLUDE_DIR "${GLFW3_ROOT}/include")
	FIND_LIBRARY(GLFW3_LIBRARY NAMES glfw3 glfw PATHS "${GLFW3_ROOT}/lib" )
endif(GLFW3_ROOT)

# Search for the library

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLFW3 DEFAULT_MSG GLFW3_LIBRARY GLFW3_INCLUDE_DIR)
