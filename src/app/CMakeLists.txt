find_package(Qt6 REQUIRED COMPONENTS
	Core
	Widgets
)

qt_standard_project_setup()

add_executable(newtonian
	main.cpp
)

target_link_libraries(newtonian
PUBLIC
	window
	physics_renderer
PRIVATE
	Qt6::Core
	Qt6::Widgets
)

set_target_properties(newtonian PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
