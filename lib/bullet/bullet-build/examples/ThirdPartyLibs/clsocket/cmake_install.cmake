# Install script for directory: /Users/joonas/CLionProjects/OpenGL/lib/bullet/examples/ThirdPartyLibs/clsocket

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/joonas/CLionProjects/OpenGL/lib/bullet/bullet-build/examples/ThirdPartyLibs/clsocket/libclsocket.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libclsocket.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libclsocket.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libclsocket.a")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/joonas/CLionProjects/OpenGL/lib/bullet/examples/ThirdPartyLibs/clsocket/src/ActiveSocket.h"
    "/Users/joonas/CLionProjects/OpenGL/lib/bullet/examples/ThirdPartyLibs/clsocket/src/Host.h"
    "/Users/joonas/CLionProjects/OpenGL/lib/bullet/examples/ThirdPartyLibs/clsocket/src/PassiveSocket.h"
    "/Users/joonas/CLionProjects/OpenGL/lib/bullet/examples/ThirdPartyLibs/clsocket/src/SimpleSocket.h"
    "/Users/joonas/CLionProjects/OpenGL/lib/bullet/examples/ThirdPartyLibs/clsocket/src/StatTimer.h"
    )
endif()

