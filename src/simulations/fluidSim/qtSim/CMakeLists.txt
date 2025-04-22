cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON) # needed here or doesn't work

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(FluidSimQt
        mainQt.cpp

        fluidRenderer.cpp
        fluidBody.cpp
        fluidShapes.cpp
        fluidWorld.cpp
        fluidEngine.cpp
        fluidPhysicsView.cpp
)

target_link_libraries(FluidSimQt 
PRIVATE 
        Qt6::Widgets
PUBLIC
        rigid_body
)

