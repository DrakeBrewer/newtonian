cmake_minimum_required(VERSION 3.10)

# Define the project name
project(ReplayTableProject)

# Add subdirectory for your tests
add_subdirectory(test)

add_library(replay_table_lib
    replayTableData.cpp
)
add_executable(replay_table
    replayTableMain.cpp
    replayTableData.cpp
)


target_link_libraries(replay_table
    rigid_body
    delta_time
    vector3d
    object
    world
)


# Include the replayTable directory to ensure proper header file inclusion
target_include_directories(replay_table PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Enable testing
#enable_testing()

