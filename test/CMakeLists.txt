add_definitions(-O2 -g -pedantic -W -Wall -Wextra)

include_directories(.)
if (USE_LIBDW)
  link_libraries(dw)
  add_definitions(mmm_tests PUBLIC BACKWARD_HAS_DW)
endif()

file(GLOB_RECURSE sources . *.cpp)
function (add_mmm_test name src)
  #message("Adding mmm_${source_name}_test using ${src}")
  add_executable(mmm_${name}_test main.cpp unittest.cpp ${src})
  add_test(mmm_${name}_test mmm_${name}_test)
endfunction()

foreach(source ${sources})
  file(RELATIVE_PATH src ${CMAKE_CURRENT_SOURCE_DIR} ${source})
  string(REGEX REPLACE "/" "_" source_name ${src})
  string(REGEX REPLACE ".cpp" "" source_name ${source_name})
  add_mmm_test(${source_name} ${src})
endforeach()


add_executable(mmm_tests
  main.cpp
  unittest.cpp
  ${sources}
)

add_test(mmm_tests mmm_tests)

