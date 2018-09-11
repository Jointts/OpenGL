//
// Created by jointts on 23.08.18.
//

#ifndef SUMMITENGINE_LUA_H
#define SUMMITENGINE_LUA_H

#include <sol.hpp>
#include "Lua.h"

class Lua {
private:
    static constexpr char* prefix = "lua/";
public:
    static void BindLua();
    static void LoadScript(const char *path);
    static void ReloadScript(const char *path);
};


#endif //SUMMITENGINE_LUA_H
