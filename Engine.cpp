//
// Created by Joonas on 29/09/2016.
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "Engine.h"
#include "renderer/RenderManager.h"
#include "physics/PhysicsManager.h"
#include "Time.h"
#include "EntityManager.h"
#include "Tree.h"
#include "gui/GuiWidget.h"
#include "gui/GuiManager.h"
#include "gui/Button.h"
#include "gui/GuiEvents.h"
#include "gamestate/GameStateManager.h"
#include "Utils.h"
#include "lights/DirectionalLight.h"
#include "lights/PointLight.h"
#include "geometry/DuplicatedVertexPlane.h"
#include "maths/PoissonDiscSampler.h"
#include <glm/gtc/matrix_transform.inl>
#include "geometry/Hexagon.h"
#include "game/Tile.h"
#include "maths/PoissonGenerator.h"
#include "gui/Text.h"
//#include "audio/AudioManager.h"

int Engine::Start()
{
	DisplayManager::getInstance();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	ControllerManager::getInstance();
	CameraManager::getInstance();
	//    PhysicsManager* physicsManager = PhysicsManager::getInstance()->physicsManager;
	//    physicsManager->worldPhysics->InitPhysics();
//
	Model* forest = new Model("res/forest.FBX");
	Tile* tile = new Tile(0, glm::vec2(1, 0), TILE_FOREST);
	Tile* tile2 = new Tile(0, glm::vec2(1, 1), TILE_FOREST);

	//    PhysicsManager::getInstance()->Tick();
	//  Utter crap class, just for testing subclass pointers
	//    Tree* tree = new Tree("res/tree_1.FBX", false);
	//Player* player = new Player("res/models/fox.FBX", true);
	//    player->Translate(glm::vec3(-10.0f, 5.0f, 10.0f));
	//player->Scale(glm::vec3(0.01f, 0.01f, 0.01f));
	//    player->setMovementSpeed(0.1f);
	//    tree->Translate(glm::vec3(5, 5, 5));
	//    Entity* entity = new Entity("res/rock_1.FBX", true);
	//    entity->Translate(glm::vec3(10, 5, 10));
	//Entity* entity2 = new Entity("res/bunny/RRabbit.FBX", true);

	Button* button = new Button(100, 100);
	button->setMarginLeft(50.0f);
	button->setMarginBottom(50.0f);
	button->collisionColor = glm::vec3(226, 65, 65);
	button->clickEvent = std::bind(&GuiEvents::DEBUG_GUI);
	button->setTexture(static_cast<GLchar *>("res/nice_circle.png"));

	glm::vec3 lightColor = Utils::color_RGB(255.0f, 255.0f, 255.0f);
	GLfloat lightStrength = 0.5f;
	glm::vec3 lightPos = {1.0f, 1.0f, 1.0f};
	auto directional_light = new DirectionalLight(lightColor, lightStrength, lightPos);

	glm::vec3 position = glm::vec3(6.0f, 0.0f, 0.0f);
	glm::vec3 diffuse = Utils::color_RGB(255.f, 127.f, 80.f);
	float constant = 1.0f;
	float linear = 0.35f;
	float quadratic = 0.44f;
	auto point_light = new PointLight(position, diffuse, constant, linear, quadratic);

	Hexagon *hexagon = new Hexagon(0, glm::vec2(0, 0));
	hexagon->SetTexture("res/tile.png");

	std::vector<Point*> poissonSamples = PoissonDiscSampler::GetSamples(250, 25, 30);
	std::vector<Model*> models = {};

	PoissonGenerator::DefaultPRNG PRNG;
	const auto Points = PoissonGenerator::GeneratePoissonPoints(500, PRNG, 30, false);
	Model* character = new Model("res/model.dae");
//	character->SetAnimation(0);

//	for(PoissonGenerator::sPoint point : Points)
//	{
//		Model* model = new Model("res/tree_1.FBX");
//		models.push_back(model);
//		model->Translate(glm::vec3(point.x * 64, 0 , point.y * 64));
//		model->Scale(glm::vec3(0.2, 0.2, 0.2));
//	}

	GameStateManager::getInstance();
	Text* text = new Text("Nigger (from Alabama)", "LATO_LIGHT");

	/*    FreeType* freeType = new FreeType();
	    freeType->Initalize();*/
	//Water *water = new Water(200, 200, 0, false);
	//plane->generateHeightMap = true;
	//Plane *water = new Plane(200, 200, 0, false);
	//    Terrain *terrain = new Terrain(100, 100, 0, true);
	//terrain->terrain->GenerateRivers();
	//terrain->generateCollision();
	//terrain->AddTexture("res/van_gogh.jpg");
	DuplicatedVertexPlane* duplicatedVertexPlane = new DuplicatedVertexPlane(64, 64, false);
	duplicatedVertexPlane->calculatePointHeight(glm::vec2(1.5f, 2.25f));
//	Quad* quad = new Quad(5, 5);


	//    duplicatedVertexPlane->setImage("res/van_gogh.jpg");

	while (!glfwWindowShouldClose(DisplayManager::getInstance()->display->window))
	{
//		ControllerManager::mouseOneClickEventPropagate = false;
		glfwPollEvents();
		Time::calculateFrameTime();
		glEnable(GL_MULTISAMPLE);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		RenderManager::getInstance()->DrawGui();
//		glBindFramebuffer(0, GL_FRAMEBUFFER);
//		glDisable(GL_CULL_FACE);
		RenderManager::getInstance()->DrawGui();
		text->Draw();
		RenderManager::getInstance()->RenderBaseShader();
		duplicatedVertexPlane->Draw();
		character->Draw();

		//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//		quad->Draw(NULL, NULL);

		//		rock->Draw();
//
		glEnable(GL_DEPTH_TEST);
		for(Model* model : models)
		{
			model->Draw();
		}
		//        PhysicsManager::getInstance()->Tick();
		//        AudioManager::getInstance()->getInstance();
		//
		GuiManager::getInstance()->guiEventListener->CheckEvents();
//		hexagon->Draw();
//		tile->Draw();
//		tile2->Draw();
		//        terrain->Draw();
		//tree->Rotate(0.003f, glm::vec3(0.0f, 1.0f, 0.0f));
		//plane->Draw();
		//RenderManager::getInstance()->RenderCelShader();
		//water->Draw();
		//        guiWidget->Draw();
		//        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		glfwSwapBuffers(DisplayManager::getInstance()->display->window);
	}

	return -1;
}
