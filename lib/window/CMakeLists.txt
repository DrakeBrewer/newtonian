find_package(Qt6 REQUIRED COMPONENTS
	Core
	Widgets
)

qt_standard_project_setup()

add_library(window
	window.cpp
)

target_link_libraries(window
PRIVATE
	Qt6::Core
	Qt6::Widgets
)

target_include_directories(window PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(window PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
