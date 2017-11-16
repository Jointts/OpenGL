//
// Created by Joonas on 30/07/2017.
//

#ifndef OPENGL_PLAYERALREADYEXISTSEXCEPTION_H
#define OPENGL_PLAYERALREADYEXISTSEXCEPTION_H


#include <exception>
#include <stdexcept>

class PlayerAlreadyExistsException : public std::runtime_error {
public:

    PlayerAlreadyExistsException() : runtime_error("Player constructor has been called more than once") {}

    PlayerAlreadyExistsException(std::string const &error) : runtime_error(error) {}
};


#endif //OPENGL_PLAYERALREADYEXISTSEXCEPTION_H
