add_executable(rigid_body_test
	rigidBody_test.cpp
)

target_link_libraries(
	rigid_body_test
	GTest::gtest_main
	rigid_body
)

add_tests(rigid_body_test)
