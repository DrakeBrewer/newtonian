add_subdirectory(test)

add_executable(collision_sim
	main.cpp
)

add_library(rigid_body
	rigidBody.cpp
	world.cpp
)

target_link_libraries(collision_sim
	delta_time
	rigid_body
)

target_include_directories(rigid_body PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

