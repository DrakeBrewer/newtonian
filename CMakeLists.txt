cmake_minimum_required(VERSION 3.31)

project(newtonian LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    # TODO: Update this to a more recent version.
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()
include(GoogleTest)

# Allows for build of exclusively unit tests for 
#   faster build time when testing
function(add_tests test)
    gtest_discover_tests(${test}
      # Below allows us to run tests within directories.
      # If you only want to run tests in build/src/physics/friction,
      #     you can do so from that directory.
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    add_dependencies(unit_tests ${test})
endfunction()

add_custom_target(unit_tests ALL)

add_subdirectory(lib)
add_subdirectory(examples)
add_subdirectory(src)
