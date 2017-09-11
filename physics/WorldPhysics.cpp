//
// Created by Joonas on 01/05/2017.
//

#include <BulletCollision/BroadphaseCollision/btBroadphaseInterface.h>
#include <BulletCollision/BroadphaseCollision/btDbvtBroadphase.h>
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <BulletCollision/CollisionDispatch/btCollisionDispatcher.h>
#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>
#include <detail/type_mat.hpp>
#include <ext.hpp>
#include <BulletCollision/BroadphaseCollision/btAxisSweep3.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include "WorldPhysics.h"
#include "../DebugDrawer.h"
#include "../camera/CameraManager.h"
#include "../Entity.h"
#include "../Tree.h"
#include "../Terrain.h"
#include "../EntityManager.h"

Entity *WorldPhysics::lastHitEntity = 0;

void WorldPhysics::InitPhysics() {
    // Initialize Bullet. This strictly follows http://bulletphysics.org/mediawiki-1.5.8/index.php/Hello_World,
    // even though we won't use most of this stuff.

    // Build the broadphase
    btBroadphaseInterface *broadphase = new btDbvtBroadphase();

    // Set up the collision configuration and dispatcher
    btDefaultCollisionConfiguration *collisionConfiguration = new btDefaultCollisionConfiguration();
    btCollisionDispatcher *dispatcher = new btCollisionDispatcher(collisionConfiguration);

    // The actual physics solver
    btSequentialImpulseConstraintSolver *solver = new btSequentialImpulseConstraintSolver;

    btVector3 worldMin(-1000,-1000,-1000);
    btVector3 worldMax(1000,1000,1000);
    btAxisSweep3* sweepBP = new btAxisSweep3(worldMin,worldMax);
    btAxisSweep3 *m_overlappingPairCache = sweepBP;

    // The world.
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, m_overlappingPairCache, solver, collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0, -9.81f, 0));
    dynamicsWorld->getDispatchInfo().m_allowedCcdPenetration=0.0001f;
    sweepBP->getOverlappingPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());

    DebugDrawer* debugDrawer = new DebugDrawer();
    debugDrawer->setup();

    debugDrawer->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
    dynamicsWorld->setDebugDrawer(debugDrawer);
}

void WorldPhysics::RayCast(double mouseX, double mouseY) {
    GLint viewportWidth = 1440;
    GLint viewportHeight = 900;

    //  Since OpenGL coordinates start from the lower left corner, we need to correct the Y coordinate
    mouseY = viewportHeight - mouseY;

    glm::vec3 mouseScreenStartPos(mouseX, mouseY, 0.0f);
    glm::vec3 mouseScreenEndPos(mouseX, mouseY, 1.0f);

    glm::mat4 projection = CameraManager::getInstance()->mainCamera->perspective;
    glm::mat4 view = CameraManager::getInstance()->mainCamera->view;
    glm::mat4 model = glm::mat4();
    glm::vec4 viewport(0.0f, 0.0f, viewportWidth, viewportHeight);

    // Transform screen-space coordinates to world-space (Start and End Ray)
    glm::vec3 projectedMouseStartPos = glm::unProject(mouseScreenStartPos, view * model, projection, viewport);
    glm::vec3 projectedMouseEndPos = glm::unProject(mouseScreenEndPos, view * model, projection, viewport);

    //  Convert vectors to bullet vectors
    btVector3 bulletStartPos(projectedMouseStartPos.x, projectedMouseStartPos.y, projectedMouseStartPos.z);
    btVector3 bulletEndPos(projectedMouseEndPos.x, projectedMouseEndPos.y, projectedMouseEndPos.z);

    //  Cast the ray to the world space
    btCollisionWorld::ClosestRayResultCallback rayCallBack(bulletStartPos, bulletEndPos);
    dynamicsWorld->rayTest(bulletStartPos, bulletEndPos, rayCallBack);


    if(rayCallBack.hasHit()) {
        Entity* hitEntity = static_cast<Entity*>(rayCallBack.m_collisionObject->getUserPointer());

        //  If hitEntity is NULL then it isnt a type or subtype of Entity, ignore interaction
        if(hitEntity && hitEntity->entityType == EntityType::BASIC){
            getHitEntityType(hitEntity);
            hitEntity->model->drawOutline = true;
            lastHitEntity = hitEntity;
        }
        // If hitEntity is NULL, it means it isnt a subtype of entity, it must be Terrain
        if(hitEntity == NULL && mouseOneClicked){
            if(EntityManager::getInstance()->player){
                EntityManager::getInstance()->player->entityController->MoveToCoord(glm::vec3(
                        rayCallBack.m_hitPointWorld.getX(),
                        rayCallBack.m_hitPointWorld.getY(),
                        rayCallBack.m_hitPointWorld.getZ()
                ));
            }
        }
    }else{
        if(!lastHitEntity) return;
        lastHitEntity->model->drawOutline = false;
    }
}

void WorldPhysics::getHitEntityType(Entity *hitEntity) {
    //  Dynamic cast sends NULL if its actually not type of Tree, static_cast doesnt give a fuck and casts it always
    Tree* tree = dynamic_cast<Tree*> (hitEntity);

    if(tree){
        printf("Its a tree");
        tree->printShit();
    }else{
        printf("Its something else");
    }
}

void WorldPhysics::Tick(){
    DebugDrawer* debugDrawer = (DebugDrawer*) dynamicsWorld->getDebugDrawer();

    if(EntityManager::player) EntityManager::player->entityController->CheckPosition();

    dynamicsWorld->stepSimulation(1 / 60.f, 10);

    dynamicsWorld->debugDrawWorld();
    debugDrawer->Draw();
}

void WorldPhysics::AddPlayer(){

}
