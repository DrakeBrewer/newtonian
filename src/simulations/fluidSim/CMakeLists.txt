

#project(FluidSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(fluidSim
        mainFluid.cpp
        #QtApp.cpp
        fluidSim.cpp
)

#target_link_libraries(fluidSim PRIVATE Qt6::Widgets)

############Testing Suite##############

add_executable(fluid_sim_test
        testingSuite.cpp
        fluidSim.cpp
)

target_link_libraries(
        fluid_sim_test
        GTest::gtest_main
)

add_tests(fluid_sim_test)
