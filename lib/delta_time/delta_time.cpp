#include <ctime>
#include <chrono>

#include "delta_time.hpp"

/*
 * delta_time
 * @brief Calculates the delta time for frame independent state increments
 * @return time since last call to function
 */
double delta_time() {
	// Removes the need to track things with a class
	static auto prev_time = std::chrono::steady_clock::now();
	auto curr_time = std::chrono::steady_clock::now();

	return std::chrono::duration<double>(curr_time - prev_time).count();
}
