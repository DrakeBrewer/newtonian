cmake_minimum_required(VERSION 3.31)

project(newtonian LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source directory
add_subdirectory(src)

# Include GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Define the custom unit test function
function(add_unit_test test_name test_sources)
    add_executable(${test_name} ${test_sources})
    target_link_libraries(${test_name} GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(${test_name})
endfunction()

# Add unit tests
add_unit_test(hello_test hello_test.cc)
add_unit_test(math_test math_test.cc)

# Add a target to run all tests
add_custom_target(run_unit_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS hello_test math_test
)

