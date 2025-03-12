cmake_minimum_required(VERSION 3.10)
project(OrbitalMechanics)

# Add Google Test as a subdirectory (since it's a submodule now)
add_subdirectory(../../../extern/googletest ../../../build/googletest)

# Add the OrbitalMechanics library
add_library(orbital_mechanics
    orbitalMechanics.cpp
	orbitSimulation.cpp
)

# Add the test executable
add_executable(testing_suite testingSuite.cpp)

# Link Google Test and your orbital mechanics library
target_link_libraries(testing_suite PRIVATE orbital_mechanics gtest gtest_main)

# Enable testing
enable_testing()

# Discover tests and run them
include(GoogleTest)
gtest_discover_tests(testing_suite)
