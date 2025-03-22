# Rigid Body Tests
add_executable(rigid_body_test
	rigidBody_test.cpp
)

target_link_libraries(
	rigid_body_test
	GTest::gtest_main
	rigid_body
	vector3d
	world
)

add_tests(rigid_body_test)

# Collision Tests
add_executable(collision_test
	collision_test.cpp
)

target_link_libraries(
	collision_test
	GTest::gtest_main
	rigid_body
	delta_time
	vector3d
	world
)

add_tests(collision_test)
