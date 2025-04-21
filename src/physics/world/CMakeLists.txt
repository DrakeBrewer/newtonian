add_library(world
	world.cpp
)

target_link_libraries(world
	rigid_body
	collision
)

target_include_directories(world PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
