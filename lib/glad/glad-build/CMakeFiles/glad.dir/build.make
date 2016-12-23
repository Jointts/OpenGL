# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Joonas\ClionProjects\OpenGL\glad

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build

# Include any dependencies generated for this target.
include CMakeFiles/glad.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glad.dir/flags.make

src/glad.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating GLAD"
	cd /d C:\Users\Joonas\ClionProjects\OpenGL\glad && C:\Users\Joonas\AppData\Local\Programs\Python\Python36\python.exe -m glad --profile=compatibility --out-path=C:/Users/Joonas/ClionProjects/OpenGL/glfw/glad-build --api= --generator=c --extensions= --spec=gl

include/glad/glad.h: src/glad.c
	@$(CMAKE_COMMAND) -E touch_nocreate include\glad\glad.h

CMakeFiles/glad.dir/src/glad.c.obj: CMakeFiles/glad.dir/flags.make
CMakeFiles/glad.dir/src/glad.c.obj: CMakeFiles/glad.dir/includes_C.rsp
CMakeFiles/glad.dir/src/glad.c.obj: src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/glad.dir/src/glad.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glad.dir\src\glad.c.obj   -c C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build\src\glad.c

CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	C:\MinGW\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build\src\glad.c > CMakeFiles\glad.dir\src\glad.c.i

CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	C:\MinGW\mingw64\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build\src\glad.c -o CMakeFiles\glad.dir\src\glad.c.s

CMakeFiles/glad.dir/src/glad.c.obj.requires:

.PHONY : CMakeFiles/glad.dir/src/glad.c.obj.requires

CMakeFiles/glad.dir/src/glad.c.obj.provides: CMakeFiles/glad.dir/src/glad.c.obj.requires
	$(MAKE) -f CMakeFiles\glad.dir\build.make CMakeFiles/glad.dir/src/glad.c.obj.provides.build
.PHONY : CMakeFiles/glad.dir/src/glad.c.obj.provides

CMakeFiles/glad.dir/src/glad.c.obj.provides.build: CMakeFiles/glad.dir/src/glad.c.obj


# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.obj"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

libglad.a: CMakeFiles/glad.dir/src/glad.c.obj
libglad.a: CMakeFiles/glad.dir/build.make
libglad.a: CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libglad.a"
	$(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glad.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glad.dir/build: libglad.a

.PHONY : CMakeFiles/glad.dir/build

CMakeFiles/glad.dir/requires: CMakeFiles/glad.dir/src/glad.c.obj.requires

.PHONY : CMakeFiles/glad.dir/requires

CMakeFiles/glad.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean.cmake
.PHONY : CMakeFiles/glad.dir/clean

CMakeFiles/glad.dir/depend: src/glad.c
CMakeFiles/glad.dir/depend: include/glad/glad.h
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Joonas\ClionProjects\OpenGL\glad C:\Users\Joonas\ClionProjects\OpenGL\glad C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build C:\Users\Joonas\ClionProjects\OpenGL\glfw\glad-build\CMakeFiles\glad.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glad.dir/depend

