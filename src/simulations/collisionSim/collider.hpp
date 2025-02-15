#pragma once

class Collider {
	virtual bool checkCollision() = 0;
	virtual void resolveCollision() = 0;
};
