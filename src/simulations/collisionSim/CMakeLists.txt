add_executable(collision_sim
	main.cpp
	rigidBody.cpp
)

target_link_libraries(collision_sim
	delta_time
)
