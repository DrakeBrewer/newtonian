

add_executable(fluid_sim
        mainFluid.cpp
        fluidSim.cpp
)


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
