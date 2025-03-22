# Rigid Body Tests
add_executable(rigid_body_test
	rigidBody_test.cpp
)

target_link_libraries(
	rigid_body_test
	GTest::gtest_main
	rigid_body
	world
)

add_tests(rigid_body_test)

# Vector Tests
add_executable(vector3d_test
	vector3d_test.cpp
)

target_link_libraries(
	vector3d_test
	GTest::gtest_main
	rigid_body
)

add_tests(vector3d_test)

# Collision Tests
add_executable(collision_test
	collision_test.cpp
)

target_link_libraries(
	collision_test
	GTest::gtest_main
	rigid_body
	delta_time
	world
)

add_tests(collision_test)
