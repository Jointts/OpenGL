//
// Created by joonas on 19.09.16.
//

#include <ios>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <glad/glad.h>
#include <ext.hpp>
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

glm::vec3 Utils::color_RGB(float r, float g, float b){
    return glm::vec3(r / 255, g / 255, b / 255);
}

glm::vec3 Utils::GetNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3)
{
    glm::vec3 temp1, temp2;
    glm::vec3 normal;

    temp1 = v1 - v2;
    temp2 = v2 - v3;

    normal = glm::cross(temp1, temp2);
    glm::normalize(normal);

    return normal;
}
