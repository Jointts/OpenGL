cmake_minimum_required(VERSION 3.6)
project(SummitEngine)

# To debug linker paths, turn off for development
set(CMAKE_VERBOSE_MAKEFILE ON)
option(BUILD_TESTS "Build all tests" ON)
set(WARNING_FLAGS "-Wall -Wextra -Wformat=2 -Wno-format-nonliteral -Wshadow -Wpointer-arith -Wcast-qual -Wno-missing-braces")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 ${WARNING_FLAGS}")

add_subdirectory(src)
add_executable(SummitEngine src/main.cpp lib/glad/src/glad.c ${SOURCE} src/controller/PosEvent.h)
set(LIBRARY_TO_LINK SummitEngine)
include(${CMAKE_CURRENT_SOURCE_DIR}/lib/CMakeLists.txt)


# Shader and resource copying
file(COPY ${CMAKE_CURRENT_LIST_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_LIST_DIR}/src/scripts/lua DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_LIST_DIR}/src/shaders/glsl DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders/)


if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()