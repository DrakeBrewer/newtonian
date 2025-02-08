// CMake taken from QT Widgets Tutorial - Creating a Window
cmake_minimum_required(VERSION 3.28.3)
project(toplevel LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(toplevel
    window.cpp
)

target_link_libraries(toplevel PRIVATE
    Qt::Core
    Qt6::Gui
    Qt6::Widgets
)

install(TARGETS toplevel
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET toplevel
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
