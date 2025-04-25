#include <limits>
#include <vector>
#include "collision.hpp"
#include "rigidBody.hpp"
#include "vector3d.hpp"
#include "lightBody.hpp"

static bool isPolygon(RigidBody *body) {
	return dynamic_cast<Rectangle*>(body) || dynamic_cast<Triangle*>(body);
}

static std::vector<Vector3d> getVertices(RigidBody *body) {
	std::vector<Vector3d> vertices;

	Rectangle *r = dynamic_cast<Rectangle*>(body);
	if (r) {
		for (int i = 0; i < 4; i++) {
			vertices.push_back(r->vertices[i]);
		}

		return vertices;
	}

	Triangle *t = dynamic_cast<Triangle*>(body);
	if (t) {
		for (int i = 0; i < 3; i++) {
			vertices.push_back(t->vertices[i]);
		}

		return vertices;
	}

	return vertices;
}

static Vector3d getPerpAxis(Vector3d edge) {
	Vector3d perpendicular = Vector3d(-edge.z, 0, edge.x);
	float mag = perpendicular.magnitude();

	if (mag > 0.001f) {
		perpendicular = perpendicular / mag;
	}

	return perpendicular;
}

static std::vector<Vector3d> getAxes(RigidBody *body) {
	std::vector<Vector3d> axes;

	std::vector<Vector3d> vertices = getVertices(body);
	int numVertices = vertices.size();
	if (numVertices < 3) {
		return axes;
	}
	
	for (int i = 0; i < numVertices; i++) {
		Vector3d edge = vertices[(i + 1) % numVertices] - vertices[i];
		Vector3d perp = getPerpAxis(edge);
		axes.push_back(perp);
	}

	return axes;
};

static bool hasOverlap(float minA, float minB, float maxA, float maxB, float &overlap) {
	if (maxA < minB || maxB < minA) {
		return false;
	}

	float overlap1 = maxA - minB;
	float overlap2 = maxB - minA;

	overlap = std::min(overlap1, overlap2);
	return true;
}

static void projectShape(RigidBody *body, Vector3d axis, float &min, float &max) {
	min = std::numeric_limits<float>::max();
	max = std::numeric_limits<float>::lowest();

	if (isPolygon(body)) {
		std::vector<Vector3d> vertices = getVertices(body);
		if (vertices.empty()) {
			return;
		}

		for (Vector3d &v : vertices) {
			float proj = v.dotProduct(axis);
			min = std::min(min, proj);
			max = std::max(max, proj);
		}
	} else {
		Ellipse *ellipse = dynamic_cast<Ellipse*>(body);
		if (ellipse) {
			float proj = ellipse->position.dotProduct(axis);

			min = proj - ellipse->radius;
			max = proj + ellipse->radius;
		}
	} 
}

CollisionSystem::CollisionSystem() {
	this->data.hasCollision = false;
	this->data.overlap = 0;
	this->data.normal = Vector3d(0, 0, 0);
	this->data.contactPoint = Vector3d(0, 0, 0);
}

bool CollisionSystem::checkCollision(RigidBody *bodyA, RigidBody *bodyB) {
	this->data.hasCollision = false;
	return false;
}

bool SATCollisionSystem::checkCollision(RigidBody *bodyA, RigidBody *bodyB) {
	this->data.hasCollision = false;

	auto rayA = dynamic_cast<LightBody*>(bodyA);
	auto rayB = dynamic_cast<LightBody*>(bodyB);
	
	// if both rays, ignore
	if(rayA && rayB){
		return false;
	}
	// rayA hitting a shape
	if(rayA) {
		return rayVsShape(rayA, bodyB);
	}
	// rayB hitting a shape
	if(rayB) {
		bool hit = rayVsShape(rayB, bodyA);
		if(hit) this->data.normal = -this->data.normal;
		return hit;
	}
	
	Ellipse *ellipseA = dynamic_cast<Ellipse*>(bodyA);
	Ellipse *ellipseB = dynamic_cast<Ellipse*>(bodyB);

	if (ellipseA && ellipseB) {
		return this->ellipseVsEllipse(ellipseA, ellipseB);
	} else if (ellipseA && isPolygon(bodyB)) {
		return this->ellipseVsPolygon(ellipseA, bodyB);
	} else if (ellipseB && isPolygon(bodyA)) {
		// TODO: invert normal because of order?
		return this->ellipseVsPolygon(ellipseB, bodyA);
	} else if (isPolygon(bodyA) && isPolygon(bodyB)) {
		return this->polygonVsPolygon(bodyA, bodyB);
	}

	return false;
}

void SATCollisionSystem::resolveCollision(RigidBody *bodyA, RigidBody *bodyB) {
	if (!this->data.hasCollision || (bodyA->isStatic && bodyB->isStatic)) {
		return;
	}

	// handle photon reflection
	if(auto light = dynamic_cast<LightBody*>(bodyA)) {
		float overlap = this->data.overlap;
		float slop = 1e-6f;
		float pushDist = overlap + slop;
		// reflect velocity about the normal of the collision plane
		//light->velocity = light->velocity.reflect(this->data.normal);
		//std::cout<<"Relfecting off of: <"<<this->data.normal.x<<", "<<this->data.normal.y<<", "<<this->data.normal.z<<">\n";

		light->reflect(this->data.normal);
		// push just outside the surface
		light->position = this->data.contactPoint + this->data.normal * pushDist;
		return;
	}
	// light may be bodyA or bodyB
	if(auto light = dynamic_cast<LightBody*>(bodyB)) {
		float overlap = this->data.overlap;
		float slop = 1e-6f;
		float pushDist = overlap + slop;

		//std::cout<<"Relfecting off of: <"<<data.normal.x<<", "<<data.normal.y<<", "<<data.normal.z<<">\n";
		light->reflect(-this->data.normal);
		light->position = this->data.contactPoint - this->data.normal * pushDist;
		return;
	}

	Vector3d relVelocity = bodyB->velocity - bodyA->velocity;

	float velocityOnNormal = relVelocity.dotProduct(this->data.normal);
	// Velocities are moving away from/each other, so we don't care
	if (velocityOnNormal > 0) {
		return;
	}

	// TODO: make this part of the rigid body class
	float e = 0.8f;

	// See: https://www.chrishecker.com/images/e/e7/Gdmphys3.pdf for more on this
	float j = -(1.0f + e) * velocityOnNormal;
	float invMassA = bodyA->isStatic ? 0 : 1.0f / bodyA->mass;
	float invMassB = bodyB->isStatic ? 0 : 1.0f / bodyB->mass;
	j /= invMassA + invMassB;

	Vector3d impulse = j * this->data.normal;

	if (!bodyA->isStatic) {
		bodyA->velocity = bodyA->velocity - (impulse / bodyA->mass);
	}

	if (!bodyB->isStatic) {
		bodyB->velocity = bodyB->velocity + (impulse / bodyB->mass);
	}

	// Correction for overlap on collision
	float percent = 0.5f;
	float slop = 0.001f; // tolerance for overlap
	Vector3d correction = std::max(this->data.overlap - slop, 0.0f) / 
		(invMassA + invMassB) * 
		percent * this->data.normal;

	if (!bodyA->isStatic) {
		bodyA->position = bodyA->position - (correction * invMassA);
	}

	if (!bodyB->isStatic) {
		bodyB->position = bodyB->position + (correction * invMassB);
	}
}

bool SATCollisionSystem::rayVsShape(LightBody *ray, RigidBody *shape) {
	Vector3d O /*origin*/ = ray->position;
	Vector3d D /*direction*/ = ray->direction.normalized(); 
	//std::cout<<"rayPos: <"<<ray->position.x<<", "<<ray->position.y<<", "<<ray->position.z<<">\n";
	//std::cout<<"rayDir: "<<ray->direction.x<<", "<<ray->direction.y<<", "<<ray->direction.z<<">\n";

	float maxT = ray->speed * ray->lastDelta;

	if(isPolygon(shape)) {
		std::vector<Vector3d> verts = getVertices(shape);
		const float EPS = 1e-6f;

		float bestT = std::numeric_limits<float>::infinity();
		Vector3d bestNormal, bestPoint;

		for(int i = 0; i < verts.size(); ++i) {
			Vector3d A = verts[i];
			Vector3d B = verts[(i+1) % verts.size()];
			Vector3d edge = B-A;

			// Only consider x-z planes of edge
			float Ax = A.x, Az = A.z;
			float Bx = B.x, Bz = B.z;
			// origin and direction points of ray
			float Ox = O.x, Oz = O.z;
			float Dx = D.x, Dz = D.z;

			// segment direction E = B - A
			float Ex = Bx - Ax, Ez = Bz - Az;

			//solve O + tD = A + uE
			//		tD - uE = A - O
			//
			float denom = Dx*Ez - Dz*Ex;
			if (std::fabs(denom) < EPS) continue; //parallel

			float t = ((Ax - Ox)*Ez - (Az - Oz)*Ex) / denom;
			if (t <= 0 || t > maxT) continue; //behind ray

			float u = ((Ax - Ox)*Dz - (Az - Oz)*Dx) / denom;
			if (u < 0 || u > 1) continue; // outside segment

			if(t < bestT) {
				bestT = t;
				bestPoint = Vector3d(Ox + Dx*t, 0, Oz + Dz*t);

				// edge normal perpendicular to (Ex, Ez)
				Vector3d perp(-Ez, 0, Ex);
				perp.normalize();
				// make sure its points against the direction;
				if (perp.dotProduct(D) > 0) perp = -perp;

				bestNormal = perp;
			}
		}
		
		if(bestT < std::numeric_limits<float>::infinity()) {

			this->data.hasCollision = true;
			this->data.overlap = bestT;
			this->data.contactPoint = bestPoint;
			this->data.normal = bestNormal;
			//std::cout<<"has Collision\n";
			//std::cout<<"bestNormal: <"<< bestNormal.x << ", " << bestNormal.y<<", "<<bestNormal.z<<">\n";
			return true;
		}

		//std::cout<<"no Collision\n";
		return false;
	}

	if(auto ellipse = dynamic_cast<Ellipse*>(shape)) {
		float cx = ellipse->position.x;
		float cz = ellipse->position.z;
		float r = ellipse->radius;

		float Ox = O.x - cx, Oz = O.z - cz;
		float Dx = D.x, Dz = D.z;

		float a = Dx*Dx + Dz*Dz;
		float b = 2*(Ox*Dx + Oz*Dz);
		float c = Ox*Ox + Oz*Oz - r*r;

		float disc = b*b - 4*a*c;
		if (disc < 0) return false;

		float sqrtD = std::sqrt(disc);
		float t1 = (-b - sqrtD)/(2*a);
		float t2 = (-b + sqrtD)/(2*a);

		float t = (t1>0 ? t1 : (t2>0 ? t2 : -1));
		if (t <= 0) return false;
		if (t > maxT) return false;


		Vector3d hitPoint = O + D * t;
		Vector3d normal = (hitPoint - Vector3d(cx,0,cz)).normalized();

		this->data.hasCollision = true;
		this->data.overlap = t;
		this->data.normal = normal;
		this->data.contactPoint = hitPoint;
		return true;
	}

	return false;
}

bool SATCollisionSystem::ellipseVsEllipse(Ellipse *ellipseA, Ellipse *ellipseB) {
	Vector3d centerDiff = ellipseB->position - ellipseA->position;

	float distance = centerDiff.magnitude();
	float sumRadii = ellipseA->radius + ellipseB->radius;

	if (distance < sumRadii) {
		this->data.hasCollision = true;
		this->data.overlap = sumRadii - distance;

		// Avoid division by zero
		if (distance > 0.001f) {
			this->data.normal = centerDiff / distance; // Normalize
		} else {
			this->data.normal = Vector3d(1, 0, 0); // Default direction if centers are too close
		}

		// Calculate contact point (in the middle of the overlap)
		this->data.contactPoint = ellipseA->position + this->data.normal *
			(ellipseA->radius - this->data.overlap * 0.5f);

		return true;
	}

	return false;;
}

bool SATCollisionSystem::ellipseVsPolygon(Ellipse *ellipse, RigidBody *polygon) {
	return false;
}

bool SATCollisionSystem::polygonVsPolygon(RigidBody *polygonA, RigidBody *polygonB) {
	this->data.hasCollision = true;
	this->data.overlap = std::numeric_limits<float>::max();

	std::vector<Vector3d> verticesA = getVertices(polygonA);
	std::vector<Vector3d> verticesB = getVertices(polygonB);
	if (verticesA.empty() || verticesB.empty()) {
		return false;
	}

	int numVsA = verticesA.size();
	int numVsB = verticesB.size();

	for (int i = 0; i < numVsA; i++) {
		Vector3d v1 = verticesA[i];
		Vector3d v2 = verticesA[(i + 1) % numVsA];
		Vector3d edge = v2 - v1;
		Vector3d axis = Vector3d(edge.z, 0, -edge.x);

		float mag = axis.magnitude();
		if (mag > 0.001f) {
			axis = axis / mag;
		} else {
			continue;
		}

		float minA, maxA, minB, maxB;
		projectShape(polygonA, axis, minA, maxA);
		projectShape(polygonB, axis, minB, maxB);

		// There's a separating axis, no collision
		float overlap;
		if (!hasOverlap(minA, minB, maxA, maxB, overlap)) {
			this->data.hasCollision = false;
			return false;
		}

		if (overlap < this->data.overlap) {
			this->data.overlap = overlap;
			this->data.normal = axis;
		}
	}

	for (int i = 0; i < numVsB; i++) {
		Vector3d v1 = verticesB[i];
		Vector3d v2 = verticesB[(i + 1) % numVsB];
		Vector3d edge = v2 - v1;
		Vector3d axis = Vector3d(-edge.z, 0, edge.x);

		float mag = axis.magnitude();
		if (mag > 0.001f) {
			axis = axis / mag;
		} else {
			continue;
		}

		float minA, maxA, minB, maxB;
		projectShape(polygonA, axis, minA, maxA);
		projectShape(polygonB, axis, minB, maxB);

		// There's a separating axis, no collision
		float overlap;
		if (!hasOverlap(minA, minB, maxA, maxB, overlap)) {
			this->data.hasCollision = false;
			return false;
		}

		if (overlap < this->data.overlap) {
			this->data.overlap = overlap;
			this->data.normal = axis;
		}
	}
	
	Vector3d centerDiff = polygonB->position - polygonA->position;
	if (centerDiff.dotProduct(this->data.normal) < 0) {
		this->data.normal = -this->data.normal;
	}

	this->data.contactPoint = polygonA->position +
		(polygonB->position - polygonA->position) * 0.5f;

	return true;
}
