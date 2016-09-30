//
// Created by joonas on 19.09.16.
//

#include <bits/ios_base.h>
#include <ios>
#include <fstream>
#include <iostream>
#include <unistd.h>
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
