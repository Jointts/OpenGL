cmake_minimum_required(VERSION 3.6)
project(OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CMAKE_PREFIX_PATH C:/Users/Joonas/ClionProjects/OpenGL/glew/build/cmake)

set(SOURCE_FILES main.cpp Display.cpp Display.h Utils.cpp Utils.h shaders opengl.rc opengl.ico ShaderProgram.cpp ShaderProgram.h Engine.cpp Engine.h RenderManager.cpp RenderManager.h ControllerManager.cpp ControllerManager.h CameraManager.cpp CameraManager.h DisplayManager.cpp DisplayManager.h Model.cpp Model.h Mesh.cpp Mesh.h Mesh.cpp Mesh.h terrain/Terrain.cpp terrain/Terrain.h lights/DirectionalLight.cpp lights/DirectionalLight.h water/WaterShader.cpp water/WaterShader.h geometry/Plane.cpp geometry/Plane.h water/Water.cpp water/Water.h ShaderManager.cpp ShaderManager.h shaders/terrain/TerrainShader.h shaders/terrain/TerrainShader.h)
add_executable(OpenGL ${SOURCE_FILES})

# There is a more proper way to link glad, go to the website and link the include and src folder
# GLFW however seems to either require linking !!!all source files!!! or building it through CMakeLists.txt
find_package(OpenGL REQUIRED)
include_directories("C:/Users/Joonas/ClionProjects/OpenGL/lib/glad/include")
include_directories("C:/Users/Joonas/ClionProjects/OpenGL/lib/glfw/include")
include_directories("C:/Users/Joonas/ClionProjects/OpenGL/lib/assimp/contrib/zlib")
include_directories("C:/Users/Joonas/ClionProjects/OpenGL/lib/assimp/include/")
add_subdirectory("C:/Users/Joonas/ClionProjects/OpenGL/lib/glfw/")

target_link_libraries(OpenGL ${CMAKE_SOURCE_DIR}/lib/glad/glad-build/libglad.a)
target_link_libraries(OpenGL glfw)

set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_BUILD_SAMPLES OFF)
set(ASSIMP_BUILD_TESTS OFF)
set(CMAKE_BUILD_TYPE "release")
set(ENABLE_BOOST_WORKAROUND OFF)
add_subdirectory("C:/Users/Joonas/ClionProjects/OpenGL/lib/assimp/")
target_link_libraries(OpenGL assimp)

set(CMAKE_BUILD_TYPE "debug")
include_directories(${CMAKE_SOURCE_DIR}/lib/stb_image)
link_directories(${CMAKE_SOURCE_DIR}/lib/stb_image)

include_directories(${CMAKE_SOURCE_DIR}/lib/glm/glm)
link_directories(${CMAKE_SOURCE_DIR}/lib/glm/glm)

# For copying shaderProgramID since cmake wont let include anything other than c/c++ headers and source
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/vertex.glsl ${CMAKE_CURRENT_BINARY_DIR}/shaders COPYONLY)
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/fragment.glsl ${CMAKE_CURRENT_BINARY_DIR}/shaders COPYONLY)
file(COPY ${CMAKE_HOME_DIRECTORY}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

