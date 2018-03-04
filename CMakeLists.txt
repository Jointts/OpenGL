cmake_minimum_required(VERSION 3.6)
project(NervousEngine)

# To debug linker paths, turn off for development
set(CMAKE_VERBOSE_MAKEFILE ON)
option(BUILD_TESTS "Build all tests" ON)
set(WARNING_FLAGS "-Wall -Wextra -Wformat=2 -Wno-format-nonliteral -Wshadow -Wpointer-arith -Wcast-qual -Wno-missing-braces")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 ${WARNING_FLAGS}")
set(SOURCE_FILES src/main.cpp src/display/Display.cpp src/display/Display.h src/Utils.cpp src/Utils.h src/shaders opengl.rc opengl.ico
        src/shaders/ShaderProgram.cpp src/shaders/ShaderProgram.h src/Engine.cpp src/Engine.h src/renderer/RenderManager.cpp
        src/renderer/RenderManager.h src/ControllerManager.cpp src/ControllerManager.h src/camera/CameraManager.cpp
        src/camera/CameraManager.h src/display/DisplayManager.cpp src/display/DisplayManager.h src/Model.cpp src/Model.h src/Mesh.cpp src/Mesh.h
        src/Mesh.cpp src/Mesh.h src/lights/DirectionalLight.cpp src/lights/DirectionalLight.h src/geometry/Plane.cpp src/geometry/Plane.h
        src/water/Water.cpp src/water/Water.h src/shaders/ShaderManager.cpp src/shaders/ShaderManager.h src/physics/PhysicsManager.cpp
        src/physics/PhysicsManager.h src/camera/MainCamera.cpp src/camera/MainCamera.h src/camera/Camera.cpp src/camera/Camera.h
        src/camera/GuiCamera.cpp src/camera/GuiCamera.h src/geometry/Quad.cpp src/geometry/Quad.h src/fonts/FreeType.cpp src/fonts/FreeType.h
        src/DebugDrawer.h src/Entity.cpp src/Entity.h src/Tree.cpp src/Tree.h src/Time.cpp src/Time.h src/physics/WorldPhysics.cpp
        src/physics/WorldPhysics.h src/EntityController.cpp src/EntityController.h src/EntityManager.cpp src/EntityManager.h src/Pawn.cpp
        src/Pawn.h src/Player.cpp src/Player.h src/exceptions/PlayerAlreadyExistsException.h src/geometry/DuplicatedVertexPlane.cpp
        src/geometry/DuplicatedVertexPlane.h src/gui/GuiManager.cpp src/gui/GuiManager.h src/gui/GuiWidget.cpp src/gui/GuiWidget.h
        src/lights/PointLight.cpp src/lights/PointLight.h src/gui/GuiEventListener.cpp src/gui/GuiEventListener.h src/gui/GuiFrameBuffer.cpp
        src/gui/GuiFrameBuffer.h src/gui/GuiRenderer.cpp src/gui/GuiRenderer.h src/gui/Button.cpp src/gui/Button.h src/gui/GuiEvents.cpp
        src/gui/GuiEvents.h src/gamestate/GameStateManager.cpp src/gamestate/GameStateManager.h src/gamestate/GameState.cpp
        src/gamestate/GameState.h src/gamestate/MenuGameState.cpp src/gamestate/MenuGameState.h src/Serializable.cpp src/Serializable.h
        src/lights/LightManager.cpp src/lights/LightManager.h src/Animation.h src/Animation.cpp src/game/Tile.cpp src/game/Tile.h src/geometry/Hexagon.cpp
        src/geometry/Hexagon.h src/gui/Text.cpp src/gui/Text.h src/gui/FontManager.cpp src/gui/FontManager.hsrc/ src/gui/CharacterInstance.cpp src/gui/CharacterInstance.h
        src/gui/Font.cpp src/gui/Font.h)
add_executable(NervousEngine ${SOURCE_FILES} lib/glad/src/glad.c)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
include(${CMAKE_CURRENT_SOURCE_DIR}/lib/CMakeLists.txt)

# Shader and resource copying
file(COPY ${CMAKE_CURRENT_LIST_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_LIST_DIR}/src/shaders/glsl DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders/)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
