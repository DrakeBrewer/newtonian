add_subdirectory(test)

add_library(rigid_body
	rigidBody.cpp
)

target_link_libraries(rigid_body
	vector3d
)

target_include_directories(rigid_body PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
