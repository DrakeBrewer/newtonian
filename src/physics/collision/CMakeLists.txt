add_library(collision
	collision.cpp
)

target_link_libraries(collision
	rigid_body
	vector3d
	world
)

target_include_directories(collision PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
