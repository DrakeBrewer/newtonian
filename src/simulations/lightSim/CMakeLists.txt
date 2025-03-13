# Testing Suite #

add_executable(testSuite
   lightTestSuite.cpp
   LightRay.cpp
   LightScene.cpp
)

target_link_libraries(testSuite
    GTest::gtest_main
    deltaTime
)

include_directories(
   ${CMAKE_SOURCE_DIR}/src/simulations/collisionSim)
   ${CMAKE_SOURCE_DIR}/src/simulations/lightSim
)

add_tests(testSuite)


# add_executable(light_sim 
#    LightBase.cpp
#    LightParticle.cpp
#    LightRay.cpp
#    LightWave.cpp
#    LightStuct.hpp
#    lightScene.cpp
#    Medium.hpp
#    Mirror.cpp
# )

# target_link_libraries(light_sim
#     delta_time
#     rigidBody
# )

# include_directories(${CMAKE_SOURCE_DIR}/src/simulations/collisionSim)
