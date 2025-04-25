find_package(Qt6 REQUIRED COMPONENTS
   Core
   Widgets
)

qt_standard_project_setup()

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

add_executable(lightSimQT
   lightSim.cpp
   lightBody.cpp
)

target_link_libraries(lightSimQT
PUBLIC
   window
   physics_renderer
   rigid_body
   physics_engine
PRIVATE
   Qt6::Core
   Qt6::Widgets
)

set_target_properties(lightSimQT PROPERTIES
   WIN32_EXECUTABLE ON
   MACOSX_BUNDLE ON
)

add_executable(lightTest
   lightTest.cpp
)

target_link_libraries(lightTest
   light_body
)

add_executable(lightBodyTest
   lightBodyTest.cpp
)

target_link_libraries(lightBodyTest
PUBLIC
   light_body
   collision
   physics_renderer
PRIVATE
   Qt6::Core
   Qt6::Widgets
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

