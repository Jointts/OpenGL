cmake_minimum_required(VERSION 3.6)
project(OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp Display.cpp Display.h Utils.cpp Utils.h shaders opengl.rc opengl.ico ShaderProgram.cpp ShaderProgram.h Engine.cpp Engine.h RenderManager.cpp RenderManager.h ControllerManager.cpp ControllerManager.h camera/CameraManager.cpp camera/CameraManager.h DisplayManager.cpp DisplayManager.h Model.cpp Model.h Mesh.cpp Mesh.h Mesh.cpp Mesh.h lights/DirectionalLight.cpp lights/DirectionalLight.h geometry/Plane.cpp geometry/Plane.h water/Water.cpp water/Water.h ShaderManager.cpp ShaderManager.h physics/PhysicsManager.cpp physics/PhysicsManager.h camera/MainCamera.cpp camera/MainCamera.h camera/Camera.cpp camera/Camera.h camera/GuiCamera.cpp camera/GuiCamera.h geometry/Quad.cpp geometry/Quad.h FreeType.cpp FreeType.h DebugDrawer.cpp DebugDrawer.h Entity.cpp Entity.h Tree.cpp Tree.h Terrain.cpp Terrain.h Time.cpp Time.h gui/GuiWidget.cpp gui/GuiWidget.h physics/WorldPhysics.cpp physics/WorldPhysics.h physics/GuiPhysics.cpp physics/GuiPhysics.h EntityController.cpp EntityController.h EntityManager.cpp EntityManager.h)
add_executable(OpenGL ${SOURCE_FILES} lib/glad/src/glad.c)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

# There is a more proper way to link glad, go to the website and link the include and src folder
# GLFW however seems to either require linking !!!all source files!!! or building it through CMakeLists.txt
include_directories("lib/glad/include")
include_directories("ib/glfw/include")
add_subdirectory("lib/glfw/")

find_package(ASSIMP REQUIRED)
if(ASSIMP_FOUND)
    include_directories(${ASSIMP_INCLUDE_DIRS})
    target_link_libraries(OpenGL ${ASSIMP_LIBRARIES})
endif(ASSIMP_FOUND)

find_package (bullet REQUIRED)
if (BULLET_FOUND)
    include_directories(${BULLET_INCLUDE_DIRS})
    target_link_libraries (OpenGL ${BULLET_LIBRARIES})
endif (BULLET_FOUND)

find_package(LIBNOISE REQUIRED)
if (BULLET_FOUND)
    include_directories(${LIBNOISE_INCLUDE_DIRS})
    target_link_libraries (OpenGL ${LIBNOISE_LIBRARIES})
endif (BULLET_FOUND)

find_package(FREETYPE REQUIRED)
if (FREETYPE_FOUND)
    include_directories(${FREETYPE_INCLUDE_DIRS})
    target_link_libraries (OpenGL ${FREETYPE_LIBRARIES})
endif (FREETYPE_FOUND)

target_link_libraries(OpenGL glfw)

set(CMAKE_BUILD_TYPE "debug")
include_directories(${CMAKE_SOURCE_DIR}/lib/stb_image)
link_directories(${CMAKE_SOURCE_DIR}/lib/stb_image)

include_directories(${CMAKE_SOURCE_DIR}/lib/glm/glm)
link_directories(${CMAKE_SOURCE_DIR}/lib/glm/glm)

# For copying shaderProgramID since cmake wont let include anything other than c/c++ headers and source
file(COPY ${CMAKE_HOME_DIRECTORY}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_HOME_DIRECTORY}/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/vertex.glsl ${CMAKE_CURRENT_BINARY_DIR}/shaders COPYONLY)
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/fragment.glsl ${CMAKE_CURRENT_BINARY_DIR}/shaders COPYONLY)

# NB shader copying still seems to fuck up at times, its just safer to always copy the shaders folder to the build
# directory.

