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
   ${CMAKE_SOURCE_DIR}/src/simulations/collisionSim
   ${CMAKE_SOURCE_DIR}/src/simulations/lightSim
)

