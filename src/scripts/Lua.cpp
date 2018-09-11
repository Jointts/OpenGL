//
// Created by jointts on 23.08.18.
//

#include "Lua.h"
#include <iostream>

sol::state lua;

void Lua::BindLua() {
    // open some common libraries
    lua.open_libraries(sol::lib::base, sol::lib::package);
    lua.script("print('Lua initialized')");
    const std::string packagePath = lua["package"]["path"];
    lua["package"]["path"] = packagePath + ";/home/jointts/CLionProjects/SE/cmake-build-debug/lua/?.lua";
}

void Lua::LoadScript(const char * path) {
    std::stringstream ss;

    ss << prefix << path << ".lua";

    auto script = lua.script_file(ss.str(), &sol::script_default_on_error);

    assert(script.valid());
}

// TODO: This might need cascading reload to dependencies
void Lua::ReloadScript(const char * path) {
    std::stringstream ss;

    ss << "reloadScript('" << path << "')";
    std::string script = ss.str();

    lua.script(script, &sol::script_default_on_error);
}
