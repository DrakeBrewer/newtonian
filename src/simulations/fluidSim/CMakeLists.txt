#cmake_minimum_required(VERSION 3.16)

project(FluidSim)

add_subdirectory(qtSim)

add_executable(FluidSim
        mainFluid.cpp    
        fluidSim.cpp
        #fluidSim2.cpp
)

target_link_libraries(FluidSim
	rigid_body
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

