add_definitions(-O2 -g -pedantic -W -Wall -Wextra)

include_directories(.)
if (USE_LIBDW)
  link_libraries(dw)
  add_definitions(-DBACKWARD_HAS_DW)
endif()

include(Catch.cmake)

option(MMM_BUILD_UNIT_TESTS_SINGLE "build only the given test" OFF)
if(MMM_BUILD_UNIT_TESTS_SINGLE)
  set(sources ${MMM_BUILD_UNIT_TESTS_SINGLE})
  message("building single source: ${sources}")
else()
  file(GLOB_RECURSE sources . *.cpp)
endif()

add_executable(mmm_tests main.cpp ${sources})

if(NOT CATCH_FOUND)
  add_dependencies(mmm_tests catch-lib)
endif(NOT CATCH_FOUND)

add_test(NAME mmm_tests COMMAND mmm_tests --use-colour yes)
