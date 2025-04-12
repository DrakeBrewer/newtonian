cmake_minimum_required(VERSION 3.31)

project(ReplayTableProject)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(test)

add_library(replay_table_lib
    replayTableData.cpp
)

add_executable(replay_table
    replayTableData.cpp
    mainQt.cpp 
    QtApp.cpp
)


target_link_libraries(replay_table
    rigid_body
    delta_time
    vector3d
    object
    world
    physics_engine
)

target_link_libraries(replay_table Qt6::Widgets)

target_include_directories(replay_table PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#enable_testing()

