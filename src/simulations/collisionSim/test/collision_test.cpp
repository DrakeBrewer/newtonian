#include <gtest/gtest.h>
#include "rigidBody.hpp"
#include "world.hpp"
#include "deltaTime.hpp"

class CollisionTest : public ::testing::Test {
protected:
	// Resets state after each test
	void SetUp() override {
		world = new PhysicsWorld();
	};

	void TearDown() override {
		delete world;
	}

	PhysicsWorld *world;
};

// Integration Test basic, just making sure things are resolving
// Testing Physics world unit and Collision detection unit
TEST_F(CollisionTest, CollisionResolutionBasic) {
	RigidBody *obj0 = new RigidBody(
		Vector3d(0, 0, 10),
		Vector3d(1, 0, 0),
		Vector3d(0, 0, 0),
		10,
		false);

	RigidBody *obj1 = new RigidBody(
		Vector3d(10, 0, 10),
		Vector3d(-1, 0, 0),
		Vector3d(0, 0, 0),
		10,
		false);

	world->addBody(obj0);
	world->addBody(obj1);

	for (int i = 0; i < 50; i++) {
		double dt = deltaTime();
		world->tick(dt);
	}

	EXPECT_LT(obj0->velocity.x, 0.0f);
	EXPECT_GT(obj1->velocity.x, 0.0f);
}

// Integration test2 with high velocity
// Testing Physics world unit and Collision detection unit
TEST_F(CollisionTest, CollisionResolutionFast) {
	RigidBody *obj0 = new RigidBody(
		Vector3d(0, 0, 10),
		Vector3d(100, 0, 0),
		Vector3d(0, 0, 0),
		10,
		false);

	RigidBody *obj1 = new RigidBody(
		Vector3d(1000, 0, 10),
		Vector3d(-100, 0, 0),
		Vector3d(0, 0, 0),
		10,
		false);

	world->addBody(obj0);
	world->addBody(obj1);

	for (int i = 0; i < 50; i++) {
		double dt = deltaTime();
		world->tick(dt);
	}

	EXPECT_LT(obj0->velocity.x, 0.0f);
	EXPECT_GT(obj1->velocity.x, 0.0f);
}

// Integration test3 one object in the collision
// Testing Physics world unit and Collision detection unit
TEST_F(CollisionTest, CollisionResolutionStatic) {
	RigidBody *obj0 = new RigidBody(
		Vector3d(0, 0, 10),
		Vector3d(0, 0, 0),
		Vector3d(0, 0, 0),
		10,
		true);

	RigidBody *obj1 = new RigidBody(
		Vector3d(100, 0, 10),
		Vector3d(-10, 0, 0),
		Vector3d(0, 0, 0),
		10,
		false);

	world->addBody(obj0);
	world->addBody(obj1);

	for (int i = 0; i < 10; i++) {
		double dt = deltaTime();
		world->tick(dt);
	}

	EXPECT_LT(obj0->velocity.x, 0.0f);
	EXPECT_GT(obj1->velocity.x, 0.0f);
}
