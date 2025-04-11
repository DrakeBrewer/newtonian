find_package(Qt6 REQUIRED COMPONENTS
	Core
	Widgets
)

qt_standard_project_setup()

add_library(physics_renderer
	renderer.cpp
	shapes.cpp
	physicsView.cpp
)

target_link_libraries(physics_renderer
PUBLIC
	world
	rigid_body
PRIVATE
	Qt6::Core
	Qt6::Widgets
)

target_include_directories(physics_renderer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(window PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
