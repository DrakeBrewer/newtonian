#include "gtest/gtest.h"
#include <cmath>
#include <gtest/gtest.h>
#include "rigidBody.hpp"
#include "vector3d.hpp"

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

TEST_F(Vector3dTest, AdditionOverload) {
	Vector3d vec = Vector3d(5, 5, 5);
	Vector3d expected = Vector3d(15, 25, 35);

	ASSERT_FLOAT_EQ(expected.x, (v1+vec).x);
	ASSERT_FLOAT_EQ(expected.y, (v1+vec).y);
	ASSERT_FLOAT_EQ(expected.z, (v1+vec).z);
}

TEST_F(Vector3dTest, SubtractionOverload) {
	Vector3d vec = Vector3d(10.0f, 1.0f, 14.0f);
	Vector3d expected = Vector3d(0.0f, 19.0f, 16.0f);

	ASSERT_FLOAT_EQ(expected.x, (v1-vec).x);
	ASSERT_FLOAT_EQ(expected.y, (v1-vec).y);
	ASSERT_FLOAT_EQ(expected.z, (v1-vec).z);
}

TEST_F(Vector3dTest, NegationOverload) {
	Vector3d expected = Vector3d(-10.0f, -20.0f, -30.0f);
	
	ASSERT_FLOAT_EQ(expected.x, -v1.x);
	ASSERT_FLOAT_EQ(expected.y, -v1.y);
	ASSERT_FLOAT_EQ(expected.z, -v1.z);
}

TEST_F(Vector3dTest, MultiplacationOverload) {
	Vector3d expected = Vector3d(30.0f, 60.0f, 90.0f);
	float scalar = 3.0f;

	ASSERT_FLOAT_EQ(expected.x, (v1*scalar).x);
	ASSERT_FLOAT_EQ(expected.y, (v1*scalar).y);
	ASSERT_FLOAT_EQ(expected.z, (v1*scalar).z);
}

TEST_F(Vector3dTest, MultiplacationOverloadReverseOrder) {
	Vector3d expected = Vector3d(30.0f, 60.0f, 90.0f);
	float scalar = 3.0f;

	ASSERT_FLOAT_EQ(expected.x, (scalar*v1).x);
	ASSERT_FLOAT_EQ(expected.y, (scalar*v1).y);
	ASSERT_FLOAT_EQ(expected.z, (scalar*v1).z);
}

TEST_F(Vector3dTest, DivisionOverload) {
	Vector3d expected = Vector3d(2.0f, 4.0f, 6.0f);
	float scalar = 5.0f;

	ASSERT_FLOAT_EQ(expected.x, (v1/scalar).x);
	ASSERT_FLOAT_EQ(expected.y, (v1/scalar).y);
	ASSERT_FLOAT_EQ(expected.z, (v1/scalar).z);
}

TEST_F(Vector3dTest, Normalize) {
	Vector3d vec = v1;
	v1.normalize();
	
	float mag = std::sqrt(
		(vec.x * vec.x) +
		(vec.y * vec.y) +
		(vec.z * vec.z)
	);

	float xNormd = vec.x / mag;
	float yNormd = vec.y / mag;
	float zNormd = vec.z / mag;

	ASSERT_FLOAT_EQ(xNormd, v1.x);
	ASSERT_FLOAT_EQ(yNormd, v1.y);
	ASSERT_FLOAT_EQ(zNormd, v1.z);

	// Calculated via calculator
	ASSERT_FLOAT_EQ(0.2672612419f, v1.x);
	ASSERT_FLOAT_EQ(0.53452248382485f, v1.y);
	ASSERT_FLOAT_EQ(0.80178372573727f, v1.z);
}

TEST_F(Vector3dTest, Normalized) {
	Vector3d normd = v1.normalized();

	// Calculated via calculator
	ASSERT_FLOAT_EQ(0.2672612419f, normd.x);
	ASSERT_FLOAT_EQ(0.53452248382485f, normd.y);
	ASSERT_FLOAT_EQ(0.80178372573727f, normd.z);

	ASSERT_FLOAT_EQ(10.0f, v1.x);
	ASSERT_FLOAT_EQ(20.0f, v1.y);
	ASSERT_FLOAT_EQ(30.0f, v1.z);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
