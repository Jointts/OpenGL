cmake_minimum_required(VERSION 3.6)
project(Tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")
set(SOURCE_FILES POCTest.cpp)

add_executable(Tests ${SOURCE_FILES})
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package(GTEST REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries (Tests ${GTEST_LIBRARIES})
endif(GTEST_FOUND)