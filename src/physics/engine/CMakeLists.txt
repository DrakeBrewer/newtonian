find_package(Qt6 REQUIRED COMPONENTS
	Core
	Widgets
)

qt_standard_project_setup()

add_library(physics_engine
	engine.cpp
)

target_link_libraries(physics_engine
PUBLIC
	world
	rigid_body
	physics_renderer
PRIVATE
	Qt6::Core
	Qt6::Widgets
)

target_include_directories(physics_engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(physics_engine PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
