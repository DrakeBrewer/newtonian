# Ensure that Google Test is found
#find_package(GTest REQUIRED)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(replay_table_test
    replayTable_test.cpp
#../replayTableData.cpp
)

# Link Google Test libraries
target_link_libraries(replay_table_test
    GTest::gtest_main
    rigid_body
    vector3d
    world
    delta_time
    replay_table_lib
)

#include_directories(
#    ${CMAKE_SOURCE_DIR}/lib/vector3d
#    ${CMAKE_SOURCE_DIR}/src/physics/object
#    ${CMAKE_SOURCE_DIR}/src/rigidBody
#
# Enable testing for the test executable
enable_testing()

# Add a test
add_test(NAME replay_table_test COMMAND replay_table_test)

