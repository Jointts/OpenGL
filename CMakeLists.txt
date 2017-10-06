cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp Display.cpp Display.h Utils.cpp Utils.h shaders opengl.rc opengl.ico ShaderProgram.cpp ShaderProgram.h Engine.cpp Engine.h RenderManager.cpp RenderManager.h ControllerManager.cpp ControllerManager.h camera/CameraManager.cpp camera/CameraManager.h DisplayManager.cpp DisplayManager.h Model.cpp Model.h Mesh.cpp Mesh.h Mesh.cpp Mesh.h lights/DirectionalLight.cpp lights/DirectionalLight.h geometry/Plane.cpp geometry/Plane.h water/Water.cpp water/Water.h ShaderManager.cpp ShaderManager.h physics/PhysicsManager.cpp physics/PhysicsManager.h camera/MainCamera.cpp camera/MainCamera.h camera/Camera.cpp camera/Camera.h camera/GuiCamera.cpp camera/GuiCamera.h geometry/Quad.cpp geometry/Quad.h FreeType.cpp FreeType.h DebugDrawer.h Entity.cpp Entity.h Tree.cpp Tree.h Terrain.cpp Terrain.h Time.cpp Time.h physics/WorldPhysics.cpp physics/WorldPhysics.h physics/GuiPhysics.cpp physics/GuiPhysics.h EntityController.cpp EntityController.h EntityManager.cpp EntityManager.h Pawn.cpp Pawn.h Player.cpp Player.h exceptions/PlayerAlreadyExistsException.h DuplicatedVertexPlane.cpp DuplicatedVertexPlane.h gui/GuiManager.cpp gui/GuiManager.h)
add_executable(Game lib/glad/src/glad.c ${SOURCE_FILES} ${SOURCES})
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(GLFW_INCLUDE_DIR "C:/Program Files (x86)/GLFW/include")
set(ASSIMP_INCLUDE_DIRS "C:/Program Files (x86)/Assimp/include")
set(ZLIB_LIBRARIES "C:/Program Files (x86)/Assimp/lib/libzlibstatic.a")
set(ASSIMP_LIBRARIES "C:/Program Files (x86)/Assimp/lib/libassimp.dll.a")
set(BULLET_ROOT "C:/Program Files (x86)/BULLET_PHYSICS/")
set(FREETYPE_INCLUDE_DIRS "C:/Program Files (x86)/freetype/include/")
set(FREETYPE_LIBRARIES "C:/Program Files (x86)/freetype/lib/libfreetype.a")
set(LIBNOISE_INCLUDE_DIRS "C:/Users/Joonas/Desktop/noise/include")
set(LIBNOISE_LIBRARIES "C:/Users/Joonas/Desktop/noise/win32/Debug/libnoise.dll.a")
set(CMAKE_VERBOSE_MAKEFILE on)

include_directories("lib/glad/include")

target_link_libraries(Game ${ZLIB_LIBRARIES})
include_directories(${ASSIMP_INCLUDE_DIRS})
target_link_libraries(Game ${ASSIMP_LIBRARIES})

find_package (BULLET REQUIRED)
if (BULLET_FOUND)
    include_directories(${BULLET_INCLUDE_DIRS})
    target_link_libraries (Game ${BULLET_LIBRARIES})
endif (BULLET_FOUND)

include_directories(${LIBNOISE_INCLUDE_DIRS})
target_link_libraries (Game ${LIBNOISE_LIBRARIES})

include_directories(${FREETYPE_INCLUDE_DIRS})
target_link_libraries (Game ${FREETYPE_LIBRARIES})


find_package(GLFW REQUIRED)
if (GLFW_FOUND)
    include_directories(${GLFW_INCLUDE_DIRS})
    target_link_libraries (Game ${GLFW_LIBRARIES})
endif(GLFW_FOUND)

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
