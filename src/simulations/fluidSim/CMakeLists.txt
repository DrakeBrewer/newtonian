
cmake_minimum_required(VERSION 3.16)

project(FluidSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(FluidSimQt
        mainQt.cpp
        mainWindow.cpp
        mainWindow.hpp
        
        fluidSim.cpp
)

target_link_libraries(FluidSimQt PRIVATE Qt6::Widgets)

add_executable(FluidSim
        mainFluid.cpp    
        fluidSim.cpp
)

#-------------Testing Suite-------------#

#add_executable(fluid_sim_test
#        testingSuite.cpp
#        fluidSim.cpp
#)

#target_link_libraries(
#        fluid_sim_test
#        GTest::gtest_main
#)

#add_tests(fluid_sim_test)

