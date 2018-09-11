set(SRC_FILES display/Display.cpp display/Display.h Utils.cpp Utils.h shaders
        shaders/ShaderProgram.cpp shaders/ShaderProgram.h Engine.cpp Engine.h renderer/RenderManager.cpp
        renderer/RenderManager.h camera/CameraManager.cpp
        camera/CameraManager.h display/DisplayManager.cpp display/DisplayManager.h Model.cpp Model.h Mesh.cpp Mesh.h
        Mesh.cpp Mesh.h lights/DirectionalLight.cpp lights/DirectionalLight.h geometry/Plane.cpp geometry/Plane.h
        shaders/ShaderManager.cpp shaders/ShaderManager.h physics/PhysicsManager.cpp
        physics/PhysicsManager.h camera/MainCamera.cpp camera/MainCamera.h camera/Camera.h
        camera/GuiCamera.cpp camera/GuiCamera.h geometry/Quad.cpp geometry/Quad.h
        DebugDrawer.h Entity.cpp Entity.h Time.cpp Time.h physics/WorldPhysics.cpp
        physics/WorldPhysics.h EntityController.cpp EntityController.h EntityManager.cpp EntityManager.h Pawn.cpp
        Pawn.h Player.cpp Player.h exceptions/PlayerAlreadyExistsException.h geometry/DuplicatedVertexPlane.cpp
        geometry/DuplicatedVertexPlane.h gui/GuiManager.cpp gui/GuiManager.h gui/GuiWidget.cpp gui/GuiWidget.h
        lights/PointLight.cpp lights/PointLight.h gui/GuiEventHandler.cpp gui/GuiEventHandler.h gui/GuiFrameBuffer.cpp
        gui/GuiFrameBuffer.h gui/GuiRenderer.cpp gui/GuiRenderer.h gui/Button.cpp gui/Button.h gui/GuiEvents.cpp
        gui/GuiEvents.h
        lights/LightManager.cpp lights/LightManager.h Animation.h Animation.cpp
        gui/Text.cpp gui/Text.h gui/FontManager.cpp gui/FontManager.h gui/CharacterInstance.cpp gui/CharacterInstance.h
        gui/Font.cpp gui/Font.h controller/MouseController.cpp controller/MouseController.h gui/Slider.cpp gui/Slider.h geometry/Recticle.cpp geometry/Recticle.h
        controller/PosEvent.h controller/KeyState.h scripts/Lua.cpp EventType.h scripts/Lua.h Event.h controller/ControllerManager.cpp controller/ControllerManager.h controller/KeyBoardController.h controller/KeyBoardController.cpp EventHandler.cpp EventHandler.h Listener.h controller/BaseController.cpp controller/BaseController.h camera/CameraController.cpp camera/CameraController.h)

SET(SOURCE "")
foreach(file ${SRC_FILES})
    LIST(APPEND SOURCE "src/${file}")
endforeach(file)

SET(SOURCE ${SOURCE} PARENT_SCOPE)

