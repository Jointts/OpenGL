

if(${make} MATCHES "^/")
  execute_process(
    COMMAND cygpath -w ${make}
    OUTPUT_VARIABLE cygpath_make
    ERROR_VARIABLE cygpath_make
    RESULT_VARIABLE cygpath_error
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  if(NOT cygpath_error)
    set(make ${cygpath_make})
  endif()
endif()

set(command "${make}")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "C:/Users/Joonas/ClionProjects/OpenGL/assimp/test/gtest/src/gtest-stamp/gtest-build-out.log"
  ERROR_FILE "C:/Users/Joonas/ClionProjects/OpenGL/assimp/test/gtest/src/gtest-stamp/gtest-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  C:/Users/Joonas/ClionProjects/OpenGL/assimp/test/gtest/src/gtest-stamp/gtest-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "gtest build command succeeded.  See also C:/Users/Joonas/ClionProjects/OpenGL/assimp/test/gtest/src/gtest-stamp/gtest-build-*.log")
  message(STATUS "${msg}")
endif()
