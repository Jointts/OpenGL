set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")
set(TEST_SOURCE_FILES GuiManagerTest.cpp)

set(ACTUAL_SOURCES "../lib/glad/src/glad.c")
foreach(file ${SOURCE})
    LIST(APPEND ACTUAL_SOURCES "../${file}")
endforeach(file)

add_executable(Tests ${TEST_SOURCE_FILES} ${ACTUAL_SOURCES})
set(LIBRARY_TO_LINK Tests)
include(${CMAKE_CURRENT_SOURCE_DIR}/../lib/CMakeLists.txt)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

find_package(GTEST REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries (Tests PUBLIC ${GTEST_LIBRARIES})
endif(GTEST_FOUND)