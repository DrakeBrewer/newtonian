#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include "rigidBody.hpp"

class Vector3dTest : public ::testing::Test {
protected:
	// This allows for clean slate for each test
	// regarding these variables
	void SetUp() override {
		v0 = Vector3d();
		v1 = Vector3d(10, 20, 30);
		v2 = Vector3d(0, 0, 0);
	}

	Vector3d v0;
	Vector3d v1;
	Vector3d v2;
};

// Black Box tests for different cases of crossProduct method of vector3d class
// Orthogonal vector
TEST_F(Vector3dTest, CrossProductOrtho) {
	// Orthogonal vectors
	Vector3d oVec = Vector3d(21.6, 21.6, -21.6);
	Vector3d ortho = v1.crossProduct(oVec);
	float magProd = v1.magnitude() * oVec.magnitude();

	// sin(90) = 1
	ASSERT_NEAR(ortho.magnitude(), magProd, 0.001);
}

// Parallel vector
TEST_F(Vector3dTest, CrossProductParallel) {
	Vector3d parallel = v1.crossProduct(Vector3d(20, 40, 60));

	ASSERT_FLOAT_EQ(parallel.x, 0.0f);
	ASSERT_FLOAT_EQ(parallel.y, 0.0f);
	ASSERT_FLOAT_EQ(parallel.z, 0.0f);
}

// Zero vector
TEST_F(Vector3dTest, CrossProductZero) {
	Vector3d zero = v1.crossProduct(v2);
	ASSERT_FLOAT_EQ(zero.x, 0.0f);
	ASSERT_FLOAT_EQ(zero.y, 0.0f);
	ASSERT_FLOAT_EQ(zero.z, 0.0f);
}

TEST_F(Vector3dTest, DefaultInit) {
	ASSERT_FLOAT_EQ(0.0f, v0.x);
	ASSERT_FLOAT_EQ(0.0f, v0.y);
	ASSERT_FLOAT_EQ(0.0f, v0.z);
}


TEST_F(Vector3dTest, DotProductOrtho) {
	GTEST_SKIP();
}

TEST_F(Vector3dTest, Magnitude) {
	GTEST_SKIP();
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
