#include "rigidBody.hpp"
#include "deltaTime.hpp"
#include "world.hpp"
#include <iostream>

void testCollision() {
    // Create two rectangles with known overlapping positions
    Rectangle* rectA = new Rectangle(100, 100, Vector3d(0, 0, 0), 1, false);
    Rectangle* rectB = new Rectangle(100, 100, Vector3d(101, 0, 101), 1, false);
    
    // Force update their vertices
    rectA->updateVertices();
    rectB->updateVertices();
    
    // Create collision system and test directly
    SATCollisionSystem* collision = new SATCollisionSystem();
    bool collided = collision->checkCollision(rectA, rectB);
    
    std::cout << "Rectangle A at (" << rectA->position.x << "," << rectA->position.z 
              << ") with size " << rectA->width << "x" << rectA->height << std::endl;
    std::cout << "Rectangle B at (" << rectB->position.x << "," << rectB->position.z 
              << ") with size " << rectB->width << "x" << rectB->height << std::endl;
    std::cout << "Collision result: " << (collided ? "COLLIDED" : "NO COLLISION") << std::endl;
    
    // Clean up
    delete rectA;
    delete rectB;
    delete collision;
}

int main(int argc, char **argv) {
	testCollision();
	
}
