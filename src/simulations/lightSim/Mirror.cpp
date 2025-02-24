#include "Mirror.hpp"
#include "LightRay.hpp"
#include <cmath>

void Mirror::interact(LightBase& light) const {
    LightRay* ray = dynamic_cast<LightRay*>(&light);
    if(ray) {
	std::cout << "Mirror reflecting ray.\n";
	ray->reflect();
    } else {
	std::cout << "Mirror cannot interact with this light type.\n";
    }
}
