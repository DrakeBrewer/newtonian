add_executable(newtonian_app
	main.cpp
)

target_link_libraries(
	newtonian_app
	orbital_mechanics
	plane_interaction
)
