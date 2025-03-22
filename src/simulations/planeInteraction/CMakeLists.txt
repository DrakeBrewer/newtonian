cmake_minimum_required(VERSION 3.10)
project(PlaneInteractionSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# Find Qt6 Widgets (adjust the prefix path if necessary)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Build your simulation library from core files
add_library(plane_interaction
    planeInteractionSim.cpp
    planeInteractionMech.cpp
)

# Build the main executable using your main file (planeIntMain.cpp)
# This main file is assumed to handle both console mode and Qt mode.
add_executable(PlaneInteractionSim
    planeIntMain.cpp
    QtApp.cpp
    QtApp.hpp
)

# Link the simulation library and Qt Widgets
target_link_libraries(PlaneInteractionSim PRIVATE plane_interaction Qt6::Widgets)
