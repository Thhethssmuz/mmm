include(ExternalProject)
find_package(Git REQUIRED)

find_package(CATCH)
if(NOT CATCH_FOUND)
  ExternalProject_Add(catch-lib
    PREFIX ${CMAKE_BINARY_DIR}/catch
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    TIMEOUT 10
    # UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
  )
  ExternalProject_Get_Property(catch-lib source_dir)
  set(CATCH_INCLUDE_DIRS ${source_dir}/include CACHE INTERNAL "Path to include folder for Catch")
endif(NOT CATCH_FOUND)

include_directories(SYSTEM AFTER "${CATCH_INCLUDE_DIRS}")
