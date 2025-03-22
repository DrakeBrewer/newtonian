add_library(rigid_body
	rigidBody.cpp
)

target_include_directories(rigid_body PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
