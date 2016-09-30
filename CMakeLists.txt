cmake_minimum_required(VERSION 3.6)
project(OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CMAKE_PREFIX_PATH C:/Users/Joonas/ClionProjects/OpenGL/glew/build/cmake)

set(SOURCE_FILES main.cpp Display.cpp Display.h Input.cpp Input.h Utils.cpp Utils.h shaders opengl.rc opengl.ico ShaderProgram.cpp ShaderProgram.h Engine.cpp Engine.h)
add_executable(OpenGL ${SOURCE_FILES})

# There is a more proper way to link glad, go to the website and link the include and src folder
# GLFW however seems to either require linking !!!all source files!!! or building it through CMakeLists.txt
find_package(OpenGL REQUIRED)
include_directories("C:/Users/Joonas/ClionProjects/OpenGL/glad/include")
include_directories("C:/Users/Joonas/ClionProjects/OpenGL/glfw/include")
add_subdirectory("C:/Users/Joonas/ClionProjects/OpenGL/glad/")
add_subdirectory("C:/Users/Joonas/ClionProjects/OpenGL/glfw/")
target_link_libraries(OpenGL glad)
target_link_libraries(OpenGL glfw)

include_directories(${CMAKE_SOURCE_DIR}/stb_image)
link_directories(${CMAKE_SOURCE_DIR}/stb_image)

include_directories(${CMAKE_SOURCE_DIR}/glm/glm)
link_directories(${CMAKE_SOURCE_DIR}/glm/glm)

# For copying shaderProgram since cmake wont let include anything other than c/c++ headers and source
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/vertex.glsl ${CMAKE_CURRENT_BINARY_DIR}/shaders COPYONLY)
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/fragment.glsl ${CMAKE_CURRENT_BINARY_DIR}/shaders COPYONLY)
file(COPY ${CMAKE_HOME_DIRECTORY}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

