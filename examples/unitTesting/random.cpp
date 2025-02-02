#include "random.hpp"

std::string hello_world(const std::string name) {
	std::string ret = "Hello ";
	return ret.append(name);
}

int square_and_double(int n) {
	return 2*(n*n);
}
