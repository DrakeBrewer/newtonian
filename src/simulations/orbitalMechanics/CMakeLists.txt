# cmake_minimum_required(VERSION 3.10)
# project(OrbitalMechanics)

# # Add Google Test as a subdir and also add orbitalMechanics.cpp and orbitSimulation.cpp to add_library
# add_subdirectory(../../../extern/googletest ../../../build/googletest)
# add_library(orbital_mechanics
#     orbitalMechanics.cpp
# 	orbitSimulation.cpp
# )

# # Add the test executable, testing_suite
# add_executable(testing_suite testingSuite.cpp)

# # Link Google Test, enable and run it
# target_link_libraries(testing_suite PRIVATE orbital_mechanics gtest gtest_main)
# enable_testing()
# include(GoogleTest)
# gtest_discover_tests(testing_suite)
