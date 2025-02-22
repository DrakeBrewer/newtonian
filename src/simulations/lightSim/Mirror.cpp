#include "Mirror.hpp"
#include <cmath>

void Mirror::interactWithRay(LightRay& ray){
    double normalX = 0.0;
    double normalY = 1.0;

    double dot = ray.x * normalX + ray.y * normalY;

    ray.dx = ray.dx - 2 * dot * normalX; // Law of reflection
    ray.dy = ray.dx - 2 * dot * normalY;
    // R = D - 2 *(D dot N) * N
    // Gives you new direction vectors to based on the angle of refelction.:
}
