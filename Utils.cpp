//
// Created by joonas on 19.09.16.
//

#include <ios>
#include <fstream>
#include <iostream>
//#include <direct.h>
#include <glad/glad.h>
#include <glm/ext.hpp>
#include <assimp/DefaultLogger.hpp>
#include <stb_image.h>
#include <LinearMath/btTransform.h>
#include <zconf.h>
#include "Utils.h"

std::string Utils::readFile(const char *filePath) {
    std::string content;
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
//        fprintf(stdout, "Current working dir: %s\n", cwd);
    } else
        perror("getcwd() error");

    std::string path = (std::string) cwd + "/" + filePath;

    std::ifstream fileStream(path, std::ios::in);

    if (!fileStream.is_open()) {
        std::cerr << "Could not read file " << path << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

GLuint Utils::TextureFromFile(const char *path, bool alpha) {
    int stbi_channel = STBI_rgb;
    GLint gl_channel = GL_RGB;

    if (alpha) {
        stbi_channel = STBI_rgb_alpha;
        gl_channel = GL_RGBA;
    }

    // Change this line to normal if you not want to analyse the import process
    //Assimp::Logger::LogSeverity severity = Assimp::Logger::NORMAL;
    Assimp::Logger::LogSeverity severity = Assimp::Logger::VERBOSE;

    // Create a logger instance for Console Output
    Assimp::DefaultLogger::create("", severity, aiDefaultLogStream_STDOUT);

    int width;
    int height;
    int bytesPerPixel;
    GLuint textureID;
    Assimp::DefaultLogger::get()->info("Loading texture from: " + std::string(path));
    unsigned char *pixelData = stbi_load(path, &width, &height, &bytesPerPixel, stbi_channel);

    if (!pixelData) {
        Assimp::DefaultLogger::get()->warn("Texture with path '" + std::string(path) + "' cannot be loaded");
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, gl_channel, width, height, 0, (GLenum) gl_channel, GL_UNSIGNED_BYTE, pixelData);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(pixelData);
    return textureID;
}

glm::vec3 Utils::color_RGB(float r, float g, float b) {
    return glm::vec3(r / 255, g / 255, b / 255);
}

glm::vec3 Utils::GetNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3) {
    glm::vec3 temp1, temp2;
    glm::vec3 normal;

    temp1 = v1 - v2;
    temp2 = v2 - v3;

    normal = glm::cross(temp2, temp1);
    glm::normalize(normal);

    return normal;
}

glm::mat4 Utils::BulletToGlm(const btScalar mat4[16]) {
    return glm::mat4(mat4[0], mat4[1], mat4[2], mat4[3],
                     mat4[4], mat4[5], mat4[6], mat4[7],
                     mat4[8], mat4[9], mat4[10], mat4[11],
                     mat4[12], mat4[13], mat4[14], mat4[15]);
}

btTransform Utils::glmToBullet(const glm::mat4 &mat4) {
    btTransform t;
    t.setFromOpenGLMatrix(reinterpret_cast<const glm::mat4::value_type *>(&mat4));
    return t;
}
