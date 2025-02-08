add_library(father_time
	delta_time.cpp
)

target_include_directories(father_time PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
