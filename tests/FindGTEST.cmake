#
# Find GTEST
#
# Try to find GTEST : Open Asset Import Library.
# This module defines the following variables:
# - GTEST_INCLUDE_DIRS
# - GTEST_LIBRARIES
# - GTEST_FOUND
#
# The following variables can be set as arguments for the module.
# - GTEST_ROOT_DIR : Root library directory of GTEST
#

# Additional modules
include(FindPackageHandleStandardArgs)
find_package(Threads REQUIRED)

if (WIN32)
    # Find include files
    message("Windows is not supported yet")
else()
    # Find include files
    find_path(
            GTEST_INCLUDE_DIR
            NAMES gtest/gtest.h
            PATHS
            ${CMAKE_CURRENT_LIST_DIR}/../lib/gtest/include
            DOC "The directory where gtest/gtest.h resides")

    find_library(
            GTEST_LIBRARY
            NAMES gtest
            PATHS
            ${CMAKE_CURRENT_LIST_DIR}/../lib/gtest/lib
            DOC "The Google test library")

    # Find library files
    find_library(
            GTEST_MAIN_LIBRARY
            NAMES gtest_main
            PATHS
            ${CMAKE_CURRENT_LIST_DIR}/../lib/gtest/lib
            DOC "The Google_main test library")

    find_library(
            GMOCK_LIBRARY
            NAMES gmock
            PATHS
            ${CMAKE_CURRENT_LIST_DIR}/../lib/gtest/lib
            DOC "The Google mock library")
endif()

# Handle REQUIRD argument, define *_FOUND variable
find_package_handle_standard_args(GTEST DEFAULT_MSG GTEST_INCLUDE_DIR GTEST_LIBRARY GTEST_MAIN_LIBRARY GMOCK_LIBRARY CMAKE_THREAD_LIBS_INIT)

# Define GLFW_LIBRARIES and GLFW_INCLUDE_DIRS
if (GTEST_FOUND)
    set(GTEST_LIBRARIES ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} ${GMOCK_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
    set(GTEST_INCLUDE_DIRS ${GTEST_INCLUDE_DIR})
endif()

# Hide some variables
mark_as_advanced(GTEST_INCLUDE_DIR GTEST_LIBRARY)