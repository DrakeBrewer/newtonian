#cmake_minimum_required(VERSION 3.10)
#project(PlanetSim)

set(CMAKE_CXX_STANDARD 17) 

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(planetSim
	planetSim.cpp
)

include_directories(C:/Qt/6.8.2/mingw_64/include)
include_directories(C:/Qt/6.8.2/mingw_64/include/QtWidgets)
include_directories(C:/Qt/6.8.2/mingw_64/include/QtCore)


target_link_libraries(planetSim PRIVATE Qt6::Widgets)
