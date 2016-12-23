

set(command "C:/Program Files/CMake/bin/cmake.exe;-DCMAKE_BUILD_TYPE=Release;-Dgtest_force_shared_crt=ON;-Dgtest_disable_pthreads:BOOL=ON;-DBUILD_GTEST=ON;-GMinGW Makefiles;C:/Users/Joonas/ClionProjects/OpenGL/assimp/assimp-build/test/gtest/src/gtest")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "C:/Users/Joonas/ClionProjects/OpenGL/assimp/assimp-build/test/gtest/src/gtest-stamp/gtest-configure-out.log"
  ERROR_FILE "C:/Users/Joonas/ClionProjects/OpenGL/assimp/assimp-build/test/gtest/src/gtest-stamp/gtest-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  C:/Users/Joonas/ClionProjects/OpenGL/assimp/assimp-build/test/gtest/src/gtest-stamp/gtest-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "gtest configure command succeeded.  See also C:/Users/Joonas/ClionProjects/OpenGL/assimp/assimp-build/test/gtest/src/gtest-stamp/gtest-configure-*.log")
  message(STATUS "${msg}")
endif()
