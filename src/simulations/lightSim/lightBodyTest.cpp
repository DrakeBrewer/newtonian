#include "vector3d.hpp"
#include "lightBody.hpp"
#include "collision.hpp"
#include "rigidBody.hpp"
#include "shapes.hpp"
#include <cassert>
#include <iostream>

int main(){
  float eps = 1e-5f;

  {}
  // 1) Test Vector3d::reflect
  Vector3d I(1,-1, 0);
  I.normalize();
  Vector3d Nfloor(0,1,0);
  Vector3d R = I.reflect(Nfloor);
  // Incident down‑and‑right across an upward‑facing surface should end up 
  // up‑and‑right.  So R.y > 0
  assert(R.y > 0);

  // 2) Test rayVsShape with a simple horizontal line segment
  Rectangle floorRect(10 /*w*/, 1 /*h*/, Vector3d(0,0,0), 1.0f, /*static=*/true);
  LightBody ray( Vector3d(0,0,2) /*o*/, Vector3d(0,0,-1) /*d*/, /*wavelength*/500e-9f );
  SATCollisionSystem sat;

  bool hit = sat.checkCollision(&ray, &floorRect);
  assert(hit);
  // data.overlap should equal 1.5 (distance from z=2 to z=1/2 = 2 - .5)
  std::cout<<"overlap="<<sat.data.overlap<<"\n"; 
  assert(std::abs(sat.data.overlap - 1.5f) < 1e-3f);

  // 3) apply resolveCollision and see that the ray’s direction flips upward
  std::cout<<"old dir = <"<<ray.direction.x<<","<< ray.direction.y<<","<<ray.direction.z<<">\n";
  sat.resolveCollision(&ray, &floorRect);
  std::cout<<"new dir = <"<<ray.direction.x<<","<< ray.direction.y<<","<<ray.direction.z<<">\n";
  assert(ray.direction.z > 0);

  assert(std::fabs(ray.direction.x - 0.0f) < eps);
  assert(std::fabs(ray.direction.y - 0.0f) < eps);
  assert(std::fabs(ray.direction.z - 1.0f) < eps);

  std::cout<<"All tests passed!\n";
  return 0;
}

