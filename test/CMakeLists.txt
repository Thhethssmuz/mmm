add_definitions(-O2 -g -pedantic -W -Wall -Wextra)

include_directories(.)
if (USE_LIBDW)
  link_libraries(dw)
  add_definitions(-DBACKWARD_HAS_DW)
endif()

include(Catch.cmake)

# individual tests
# function (add_mmm_test name src)
#   add_executable(mmm_${name}_test main.cpp unittest.cpp ${src})
#   add_test(mmm_${name}_test mmm_${name}_test)
# endfunction()

# create one for each cpp file
file(GLOB_RECURSE sources . *.cpp)
# foreach(source ${sources})
#   file(RELATIVE_PATH src ${CMAKE_CURRENT_SOURCE_DIR} ${source})
#   string(REGEX REPLACE "/" "_" source_name ${src})
#   string(REGEX REPLACE ".cpp" "" source_name ${source_name})
#   add_mmm_test(${source_name} ${src})
# endforeach()

# all tests in one executable
add_executable(mmm_tests main.cpp ${sources})

if(NOT CATCH_FOUND)
  add_dependencies(mmm_tests catch-lib)
endif(NOT CATCH_FOUND)

add_test(mmm_tests mmm_tests)
