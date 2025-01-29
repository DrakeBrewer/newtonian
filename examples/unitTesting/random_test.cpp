#include <gtest/gtest.h>
#include "random.hpp"

// Should pass
TEST(FunctionTests, test_math_func) {
    EXPECT_EQ(square_and_double(2), 8);
}

// Should fail
TEST(FunctionTests, HelloThere) {
	EXPECT_EQ(hello_world("World"), "Hello Moon");
}

