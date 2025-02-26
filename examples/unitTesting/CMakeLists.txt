# This will be closer to the normal workflow
# for writing unit tests
###########################################
add_library(example
	random.cpp
)

add_executable(example_test
	random_test.cpp
)

target_link_libraries(
	example_test
	GTest::gtest_main
	example
)
###########################################

add_executable(hello_test
	hello_test.cpp
)

target_link_libraries(
	hello_test
	GTest::gtest_main
)

add_executable(math_test
	math_test.cpp
)

target_link_libraries(
	math_test
	GTest::gtest_main
)

add_tests(example_test)
add_tests(hello_test)
add_tests(math_test)

