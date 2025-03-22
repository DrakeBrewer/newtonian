add_executable(vector3d_test
	vector3d_test.cpp
)

target_link_libraries(
	vector3d_test
	GTest::gtest_main
	rigid_body
)

add_tests(vector3d_test)
