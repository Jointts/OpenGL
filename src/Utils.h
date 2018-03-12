//
// Created by joonas on 19.09.16.
//

#ifndef SUMMIT_ENGINE_UTILS_H
#define SUMMIT_ENGINE_UTILS_H

#include "string"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <LinearMath/btScalar.h>
#include <LinearMath/btTransform.h>


class Utils {
public:
    static std::string readFile(const char *filePath);

    static glm::vec3 color_RGB(float r, float g, float b);

    static glm::vec3 GetNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);

    static GLuint TextureFromFile(const char *path, bool alpha);

    static glm::mat4 BulletToGlm(const btScalar *mat4);

    static btTransform glmToBullet(const glm::mat4 &mat4);
};


#endif //SUMMIT_ENGINE_UTILS_H
