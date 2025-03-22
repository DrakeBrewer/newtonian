cmake_minimum_required(VERSION 3.10)

project(OrbitalMechanics)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_subdirectory(../../../extern/googletest ../../../build/googletest)
add_library(orbital_mechanics
    orbitalMechanics.cpp
	orbitSimulation.cpp
)
add_executable(testing_suite testingSuite.cpp)
target_link_libraries(testing_suite PRIVATE orbital_mechanics gtest gtest_main)

add_executable(gui_app
    mainQt.cpp
    MainWindow.cpp
    orbitalMechanics.cpp
    orbitSimulation.cpp
)
target_link_libraries(gui_app PRIVATE Qt6::Widgets orbital_mechanics)

enable_testing()
include(GoogleTest)
gtest_discover_tests(testing_suite)
