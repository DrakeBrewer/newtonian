add_library(delta_time
	deltaTime.cpp
)

target_include_directories(delta_time PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
