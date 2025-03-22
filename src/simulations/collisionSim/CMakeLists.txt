add_executable(collision_sim
	main.cpp
)

target_link_libraries(collision_sim
	delta_time
	rigid_body
	world
)

target_include_directories(rigid_body PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

