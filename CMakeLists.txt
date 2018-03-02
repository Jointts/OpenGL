cmake_minimum_required(VERSION 3.6)
project(NervousEngine)

# To debug linker paths
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(SOURCE_FILES main.cpp display/Display.cpp display/Display.h Utils.cpp Utils.h shaders opengl.rc opengl.ico
        shaders/ShaderProgram.cpp shaders/ShaderProgram.h Engine.cpp Engine.h renderer/RenderManager.cpp
        renderer/RenderManager.h ControllerManager.cpp ControllerManager.h camera/CameraManager.cpp
        camera/CameraManager.h display/DisplayManager.cpp display/DisplayManager.h Model.cpp Model.h Mesh.cpp Mesh.h
        Mesh.cpp Mesh.h lights/DirectionalLight.cpp lights/DirectionalLight.h geometry/Plane.cpp geometry/Plane.h
        water/Water.cpp water/Water.h shaders/ShaderManager.cpp shaders/ShaderManager.h physics/PhysicsManager.cpp
        physics/PhysicsManager.h camera/MainCamera.cpp camera/MainCamera.h camera/Camera.cpp camera/Camera.h
        camera/GuiCamera.cpp camera/GuiCamera.h geometry/Quad.cpp geometry/Quad.h fonts/FreeType.cpp fonts/FreeType.h
        DebugDrawer.h Entity.cpp Entity.h Tree.cpp Tree.h Time.cpp Time.h physics/WorldPhysics.cpp
        physics/WorldPhysics.h EntityController.cpp EntityController.h EntityManager.cpp EntityManager.h Pawn.cpp
        Pawn.h Player.cpp Player.h exceptions/PlayerAlreadyExistsException.h geometry/DuplicatedVertexPlane.cpp
        geometry/DuplicatedVertexPlane.h gui/GuiManager.cpp gui/GuiManager.h gui/GuiWidget.cpp gui/GuiWidget.h
        lights/PointLight.cpp lights/PointLight.h gui/GuiEventListener.cpp gui/GuiEventListener.h gui/GuiFrameBuffer.cpp
        gui/GuiFrameBuffer.h gui/GuiRenderer.cpp gui/GuiRenderer.h gui/Button.cpp gui/Button.h gui/GuiEvents.cpp
        gui/GuiEvents.h gamestate/GameStateManager.cpp gamestate/GameStateManager.h gamestate/GameState.cpp
        gamestate/GameState.h gamestate/MenuGameState.cpp gamestate/MenuGameState.h Serializable.cpp Serializable.h
        lights/LightManager.cpp lights/LightManager.h Animation.h Animation.cpp)
add_executable(NervousEngine ${SOURCE_FILES} lib/glad/src/glad.c)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
include(${CMAKE_CURRENT_SOURCE_DIR}/lib/CMakeLists.txt)
