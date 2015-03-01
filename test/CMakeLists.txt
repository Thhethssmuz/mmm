add_definitions(-O2 -g -pedantic -W -Wall -Wextra)

include_directories(.)

file(GLOB_RECURSE sources . *.cpp)
add_executable(mmm_tests
  main.cpp
  unittest.cpp
  ${sources}
)

if (USE_LIBDW)
  target_link_libraries(mmm_tests dw)
  target_compile_definitions(mmm_tests PUBLIC BACKWARD_HAS_DW)
endif()

add_test(mmm_tests mmm_tests)

