add_library(collision_system
	collisionSystem.cpp
)

target_link_libraries(collision_system
	vector3d
	rigid_body
)

target_include_directories(collision_system PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
