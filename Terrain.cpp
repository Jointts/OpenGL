//
// Created by Joonas on 21/04/2017.
//

#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btDefaultMotionState.h>
#include <iostream>
#include <zconf.h>
#include "Terrain.h"
#include "physics/PhysicsManager.h"
#include <algorithm>

int lastVertex = NULL;
int iterations = 0;

void Terrain::generateCollision() {

    int width = sizeX + 1;
    int height = sizeZ + 1;

    float minHeight = 0.1f;
    float maxHeight = 0.1f;

    btCollisionShape *heightfieldShape =
            new btHeightfieldTerrainShape (width, height, heightCoords.data(), btScalar(1),
                                          btScalar(-1.5f), btScalar(1.5f), 1, PHY_FLOAT, false);
    btAssert(heightfieldShape && "null heightfield");

    //  Correct the offset from bullet (originally centers the entire collision object to 0 coord)
    btTransform startTransform;
    startTransform.setIdentity();
    startTransform.setOrigin(btVector3(width / 2 - 0.5f, 0, height / 2 - 0.5f));

    heightfieldShape->setLocalScaling(btVector4(1.0f,4.0f,1.0f, 1.0f));


    btDefaultMotionState *motionstate = new btDefaultMotionState(startTransform);

    btScalar mass = 0;

    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
            mass,               // mass, in kg. 0 -> Static object, will never move.
            motionstate,
            heightfieldShape,        // collision shape of body
            btVector3(0, 0, 0)    // local inertia
    );


    rigidBody = new btRigidBody(rigidBodyCI);
}

void Terrain::GenerateRivers() {

    std::vector<int> possibleRiverStartIndices = GetPossibleRiverStartIndices();
    std::vector<int> chosenRiverStartIndices = ChooseRiverStartIndices(possibleRiverStartIndices);

    for (auto &&riverStartIndex : chosenRiverStartIndices) {
        CarvePath(riverStartIndex);
        traversedVertices = {};
    }

    setupMesh(vertices, indices);
}

std::vector<int> Terrain::GetPossibleRiverStartIndices(){
    std::vector<int> riverIndices;
    float riverGenerationHeight = 1.5f;
    int vertexIndex = 0;
    for (auto &&vertex : vertices) {
        if(vertex.position.y >= riverGenerationHeight){
            riverIndices.push_back(vertexIndex);
        }
        vertexIndex++;
    }
    return riverIndices;
}

std::vector<int> Terrain::ChooseRiverStartIndices(std::vector<int> allIndices) {
    std::vector<int> riverStartIndices;
    int numOfStartPoints = (int) allIndices.size();
    for(int x = 0; x < 20; x++){
        int chosenVertex = allIndices[rand() % numOfStartPoints];
        riverStartIndices.push_back(chosenVertex);
    }
    return riverStartIndices;
}

void Terrain::CarvePath(int index){
    float endElevation = -5.0f;

    int actualRowSize = 25 + 1;

    int upperRow = index - actualRowSize;

    int bottomRow = index + actualRowSize;

    if(bottomRow + 1 > 25 * 25 || upperRow - 1 < 0){
        return;
    }

    std::vector<int> surroundingIndices;

    surroundingIndices.push_back(upperRow - 1);
    surroundingIndices.push_back(upperRow);
    surroundingIndices.push_back(upperRow + 1);
    surroundingIndices.push_back(index - 1);
    surroundingIndices.push_back(index + 1);
    surroundingIndices.push_back(bottomRow - 1);
    surroundingIndices.push_back(bottomRow);
    surroundingIndices.push_back(bottomRow + 1);

    // We do not want to carve already traversed vertices, so we filter the previous ones out
    for (auto &&vertex : traversedVertices) {
        if(traversedVertices.size() > 0 && std::find(surroundingIndices.begin(), surroundingIndices.end(), vertex.second) != surroundingIndices.end()){
            std::remove(std::begin(surroundingIndices), std::end(surroundingIndices), vertex.second);
        }
    }

    std::vector<float> surroundingIndicesY;

    for (auto &&surroundingIndex : surroundingIndices) {
        surroundingIndicesY.push_back(vertices[surroundingIndex].position.y);
    }

    std::vector<float>::iterator it;

    it = std::min_element(surroundingIndicesY.begin(), surroundingIndicesY.end());

    long vertexToDigIndexTemp = std::distance(surroundingIndicesY.begin(), it);

    int vertexToDigIndex = surroundingIndices[vertexToDigIndexTemp];

    float indexElevation = vertices[index].position.y;

    if(indexElevation <= endElevation)
        return;

    vertices[vertexToDigIndex].position.y -= 2.0f;

    traversedVertices.insert({iterations, vertexToDigIndex});

    iterations++;

    printf("Iterations: %d", iterations);

    CarvePath(vertexToDigIndex);
}

Terrain::Terrain(int sizeX, int sizeZ, int tileSize, bool generateHeightMap) : Plane(sizeX, sizeZ, tileSize,
                                                                                     generateHeightMap) {}
