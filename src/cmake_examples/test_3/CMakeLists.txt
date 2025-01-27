# Includes two source files
add_executable(calc
    main.cpp
    calc.cpp
)
# Includes header files from the current directory
target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
