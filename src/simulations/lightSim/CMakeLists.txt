add_library(light_body
	lightBody.cpp
)

target_link_libraries(light_body
	vector3d
	rigid_body
)

target_include_directories(light_body PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(lightTest
   lightTest.cpp
)

target_link_libraries(lightTest
   light_body
)

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
   ${CMAKE_SOURCE_DIR}/lib/vector3d
   ${CMAKE_SOURCE_DIR}/src/simulations/lightSim
)

