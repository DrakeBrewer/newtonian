add_library(vector3d
	vector3d.cpp
)

target_include_directories(vector3d PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
