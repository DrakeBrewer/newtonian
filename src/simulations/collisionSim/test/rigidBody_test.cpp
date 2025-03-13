#include <gtest/gtest.h>
#include "rigidBody.hpp"

class RigidBodyTest : public ::testing::Test {
protected:
	// Handles setup for each test
	void SetUp() override {
		obj0 = RigidBody();
		obj1 = RigidBody(
			Vector3d(20, 25, 100),
			Vector3d(20, 0, 10),
			Vector3d(10, 10, 10),
			25,
			false
		);

		obj2 = RigidBody(
			Vector3d(0, -55, -100),
			Vector3d(0, 0, 0),
			Vector3d(0, 0, -9.81),
			25,
			true
		);
	};

	RigidBody obj0;
	RigidBody obj1;
	RigidBody obj2;
};

// White Box Tests
// Branch coverage
// Tests static rigid body and dynamic rigid body
// Static branch: Nothing happens (intended)
// Dynamic branch: Rigid body acceleration changes
// Part 1: Force affects acceleration of non-static body
TEST_F(RigidBodyTest, ForceApplies) {
	Vector3d force = Vector3d(0, 0, 50);
	Vector3d accInit = obj1.acceleration;
	obj1.applyForce(force);

	Vector3d expectedAcc = accInit;
	expectedAcc.x += force.x / obj1.mass;
	expectedAcc.y += force.y / obj1.mass;
	expectedAcc.z += force.z / obj1.mass;

	EXPECT_FLOAT_EQ(expectedAcc.x, obj1.acceleration.x);
	EXPECT_FLOAT_EQ(expectedAcc.y, obj1.acceleration.y);
	EXPECT_FLOAT_EQ(expectedAcc.z, obj1.acceleration.z);
}

// Part 2: Force does not affect acceleration of static body
TEST_F(RigidBodyTest, ForceAppliesStaticBody) {
	Vector3d force = Vector3d(0, 0, 50);
	Vector3d accInit = obj2.acceleration;
	obj2.applyForce(force);

	Vector3d expectedAcc = accInit;
	expectedAcc.x += force.x / obj2.mass;
	expectedAcc.y += force.y / obj2.mass;
	expectedAcc.z += force.z / obj2.mass;

	EXPECT_FLOAT_EQ(expectedAcc.x, obj2.acceleration.x);
	EXPECT_FLOAT_EQ(expectedAcc.y, obj2.acceleration.y);
	EXPECT_FLOAT_EQ(expectedAcc.z, obj2.acceleration.z);
}

TEST_F(RigidBodyTest, ForceAppliesLargeForce) {
	Vector3d force = Vector3d(0, 0, 500);
	obj2.applyForce(force);

	Vector3d expectedAcc;
	expectedAcc.x = force.x / obj2.mass;
	expectedAcc.y = force.y / obj2.mass;
	expectedAcc.z = force.z / obj2.mass;

	EXPECT_EQ(expectedAcc.x, obj2.acceleration.x);
	EXPECT_EQ(expectedAcc.y, obj2.acceleration.y);
	EXPECT_EQ(expectedAcc.z, obj2.acceleration.z);
}

TEST_F(RigidBodyTest, ForceAppliesSmallForce) {
	Vector3d force = Vector3d(0, 0, 500);
	obj2.applyForce(force);

	Vector3d expectedAcc;
	expectedAcc.x = force.x / obj2.mass;
	expectedAcc.y = force.y / obj2.mass;
	expectedAcc.z = force.z / obj2.mass;

	EXPECT_EQ(expectedAcc.x, obj2.acceleration.x);
	EXPECT_EQ(expectedAcc.y, obj2.acceleration.y);
	EXPECT_EQ(expectedAcc.z, obj2.acceleration.z);
}

TEST_F(RigidBodyTest, DefaultInit) {
	EXPECT_FLOAT_EQ(0.0f, obj0.position.x);
	EXPECT_FLOAT_EQ(0.0f, obj0.position.y);
	EXPECT_FLOAT_EQ(0.0f, obj0.position.z);

	EXPECT_FLOAT_EQ(0.0f, obj0.velocity.x);
	EXPECT_FLOAT_EQ(0.0f, obj0.velocity.y);
	EXPECT_FLOAT_EQ(0.0f, obj0.velocity.z);

	EXPECT_FLOAT_EQ(0.0f, obj0.acceleration.x);
	EXPECT_FLOAT_EQ(0.0f, obj0.acceleration.y);
	EXPECT_FLOAT_EQ(0.0f, obj0.acceleration.z);

	EXPECT_FLOAT_EQ(0.0f, obj0.mass);
	EXPECT_EQ(false, obj0.isStatic);
}

// Black box test
// TODO: This way or compare against a recorded
// initial position
TEST_F(RigidBodyTest, UpdateMovesObject) {
	obj1.update(0.5);

	EXPECT_EQ(32.5f, obj1.position.x);
	EXPECT_EQ(27.5f, obj1.position.y);
	EXPECT_EQ(107.5, obj1.position.z);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
