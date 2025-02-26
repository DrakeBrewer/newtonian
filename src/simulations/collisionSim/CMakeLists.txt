add_executable(collision_sim
	main.cpp
	rigidBody.cpp
	world.cpp
)

target_link_libraries(collision_sim
	delta_time
)

add_executable(rigid_body_test
	rigidBody_test.cc
)

target_link_libraries(
	rigid_body_test
	GTest::gtest_main
)

add_tests(rigid_body_test)
