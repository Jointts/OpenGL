cmake_minimum_required(VERSION 3.6)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp display/Display.cpp display/Display.h Utils.cpp Utils.h shaders opengl.rc opengl.ico shaders/ShaderProgram.cpp shaders/ShaderProgram.h Engine.cpp Engine.h renderer/RenderManager.cpp renderer/RenderManager.h ControllerManager.cpp ControllerManager.h camera/CameraManager.cpp camera/CameraManager.h display/DisplayManager.cpp display/DisplayManager.h Model.cpp Model.h Mesh.cpp Mesh.h Mesh.cpp Mesh.h lights/DirectionalLight.cpp lights/DirectionalLight.h geometry/Plane.cpp geometry/Plane.h water/Water.cpp water/Water.h shaders/ShaderManager.cpp shaders/ShaderManager.h physics/PhysicsManager.cpp physics/PhysicsManager.h camera/MainCamera.cpp camera/MainCamera.h camera/Camera.cpp camera/Camera.h camera/GuiCamera.cpp camera/GuiCamera.h geometry/Quad.cpp geometry/Quad.h fonts/FreeType.cpp fonts/FreeType.h DebugDrawer.h Entity.cpp Entity.h Tree.cpp Tree.h Time.cpp Time.h physics/WorldPhysics.cpp physics/WorldPhysics.h EntityController.cpp EntityController.h EntityManager.cpp EntityManager.h Pawn.cpp Pawn.h Player.cpp Player.h exceptions/PlayerAlreadyExistsException.h geometry/DuplicatedVertexPlane.cpp geometry/DuplicatedVertexPlane.h gui/GuiManager.cpp gui/GuiManager.h gui/GuiWidget.cpp gui/GuiWidget.h lights/PointLight.cpp lights/PointLight.h gui/GuiEventListener.cpp gui/GuiEventListener.h gui/GuiFrameBuffer.cpp gui/GuiFrameBuffer.h gui/GuiRenderer.cpp gui/GuiRenderer.h gui/Button.cpp gui/Button.h gui/GuiEvents.cpp gui/GuiEvents.h gamestate/GameStateManager.cpp gamestate/GameStateManager.h gamestate/GameState.cpp gamestate/GameState.h gamestate/MenuGameState.cpp gamestate/MenuGameState.h Serializable.cpp Serializable.h lights/LightManager.cpp lights/LightManager.h)
#audio/AudioManager.cpp audio/AudioManager.h audio/AudioSystem.cpp audio/AudioSystem.h
add_executable(Game lib/glad/src/glad.c ${SOURCE_FILES} ${SOURCES})
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(GLFW_INCLUDE_DIR "C:/Program Files (x86)/GLFW/include")
set(ASSIMP_INCLUDE_DIRS "C:/Program Files (x86)/Assimp/include")
set(ZLIB_LIBRARIES "C:/Program Files (x86)/Assimp/lib/libzlibstatic.a")
set(ASSIMP_LIBRARIES "C:/Program Files (x86)/Assimp/lib/libassimp.dll.a")
set(BULLET_ROOT "C:/Program Files (x86)/BULLET_PHYSICS/")
set(FREETYPE_INCLUDE_DIRS "C:/Program Files (x86)/freetype/include/")
set(FREETYPE_LIBRARIES "C:/Program Files (x86)/freetype/lib/libfreetype.a")
set(LIBNOISE_INCLUDE_DIRS "C:/Users/Joonas/Desktop/Sitt/noise/include")
set(LIBNOISE_LIBRARIES "C:/Users/Joonas/Desktop/Sitt/noise/win32/Debug/libnoise.dll.a")
set(FMOD_STUDIO_INCLUDE_DIRS "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/studio/inc/")
set(FMOD_STUDIO_LIBRARIES
        "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/studio/lib/libfmodstudio.a"
        )
set(FMOD_LOWLEVEL_INCLUDE_DIRS "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/lowlevel/inc/")
set(FMOD_LOWLEVEL_LIBRARIES
        "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/lowlevel/lib/libfmod.a"
        )
set(CMAKE_VERBOSE_MAKEFILE on)
link_directories("C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/studio/lib/" "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/lowlevel/lib/")

include_directories("lib/glad/include")

target_link_libraries(Game ${ZLIB_LIBRARIES})
include_directories(${ASSIMP_INCLUDE_DIRS})
target_link_libraries(Game ${ASSIMP_LIBRARIES})

find_package (BULLET REQUIRED)
if (BULLET_FOUND)
    include_directories(${BULLET_INCLUDE_DIRS})
    target_link_libraries (Game ${BULLET_LIBRARIES})
endif (BULLET_FOUND)

#add_library(fmod_studio STATIC IMPORTED)
#set_target_properties(fmod_studio PROPERTIES
#        IMPORTED_LOCATION "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/studio/lib/libfmodstudio.a"
#        INTERFACE_INCLUDE_DIRECTORIES "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/studio/inc/"
#        )
#target_link_libraries(Game fmod_studio)
#
#add_library(fmod STATIC IMPORTED)
#set_target_properties(fmod PROPERTIES
#        IMPORTED_LOCATION "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/lowlevel/lib/libfmod.a"
#        INTERFACE_INCLUDE_DIRECTORIES "C:/Program Files (x86)/FMOD SoundSystem/FMOD Studio API Windows/api/lowlevel/inc/"
#        )
#target_link_libraries(Game fmod)

#Asus RT-AC58


#find_package (FMOD REQUIRED)
#if (FMOD_FOUND)
#    include_directories(${FMOD_INCLUDE_DIRS})
#    target_link_libraries (Game ${FMOD_LIBRARIES})
#endif (FMOD_FOUND)

include_directories(${LIBNOISE_INCLUDE_DIRS})
target_link_libraries (Game ${LIBNOISE_LIBRARIES})

include_directories(${FREETYPE_INCLUDE_DIRS})
target_link_libraries (Game ${FREETYPE_LIBRARIES})

#include_directories(${FMOD_LOWLEVEL_INCLUDE_DIRS})
#target_link_libraries (Game ${FMOD_LOWLEVEL_LIBRARIES})
#include_directories(${FMOD_STUDIO_INCLUDE_DIRS})
#target_link_libraries (Game ${FMOD_STUDIO_LIBRARIES})

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
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/glsl/vertex.glsl ${CMAKE_CURRENT_BINARY_DIR}/glsl/shaders COPYONLY)
configure_file(${CMAKE_HOME_DIRECTORY}/shaders/glsl/fragment.glsl ${CMAKE_CURRENT_BINARY_DIR}/glsl/shaders COPYONLY)

# NB shader copying still seems to fuck up at times, its just safer to always copy the shaders folder to the build
