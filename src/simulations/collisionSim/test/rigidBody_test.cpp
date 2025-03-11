#include <gtest/gtest.h>
#include "rigidBody.hpp"

class RigidBodyTest : public ::testing::Test {
protected:
	void SetUp() override {
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
			false
		);
	};

	RigidBody obj0 = RigidBody();
	RigidBody obj1;
	RigidBody obj2;
};

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

TEST_F(RigidBodyTest, UpdateMovesObject) {
	Vector3d initialVel = obj1.velocity;
	Vector3d initialPos = obj1.position;

	double delta = 0.5;
	obj1.update(delta);

	Vector3d expectedVel;
	expectedVel.x = initialVel.x + obj1.acceleration.x * delta;
	expectedVel.y = initialVel.y + obj1.acceleration.y * delta;
	expectedVel.z = initialVel.z + obj1.acceleration.z * delta;

	Vector3d expectedPos;
	expectedPos.x = initialPos.x + expectedVel.x * delta;
	expectedPos.y = initialPos.y + expectedVel.y * delta;
	expectedPos.z = initialPos.z + expectedVel.z * delta;

	EXPECT_EQ(expectedPos.x, obj1.position.x);
	EXPECT_EQ(expectedPos.y, obj1.position.y);
	EXPECT_EQ(expectedPos.z, obj1.position.z);
}

TEST_F(RigidBodyTest, ForceApplies) {
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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
