# NervousEngine
Game engine written in OpenGL and C++

## Prerequisites (supplied through NE-LIBS)
  * CMake 3.6>=
  * GNU GCC compiler
  * Linux
## Project startup instructions
  * git submodule update (adds 3rd party libraries) or git clone this repo with --recursive
  * cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles"
  * make
### Project uses the following 3rd party libraries
  * Bullet
  * Libnoise
  * Glfw
  * Glad
  * Glm
  * Assimp
  * Google test
