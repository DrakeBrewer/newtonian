find_package(Qt6 REQUIRED COMPONENTS
	Core
	Widgets
)

qt_standard_project_setup()

add_executable(collision_sim
	main.cpp
	window.cpp
)

target_link_libraries(collision_sim
PRIVATE
	Qt6::Core
	Qt6::Widgets
)

set_target_properties(collision_sim PROPERTIES
