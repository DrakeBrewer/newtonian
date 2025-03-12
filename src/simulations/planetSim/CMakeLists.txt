#cmake_minimum_required(VERSION 3.10)
#project(PlanetSim)


#cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.8.2/mingw_64" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B build
set(CMAKE_CXX_STANDARD 17) 

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(planetSim
	planetSim.cpp
)

include_directories(C:/Qt/6.8.2/mingw_64/include)
include_directories(C:/Qt/6.8.2/mingw_64/include/QtWidgets)
include_directories(C:/Qt/6.8.2/mingw_64/include/QtCore)


target_link_libraries(planetSim PRIVATE Qt6::Widgets)

add_executable(thomas_blackBoxTest
	thomas_blackBoxTest.cpp
)

target_include_directories(thomas_blackBoxTest PRIVATE
    ${gtest_SOURCE_DIR}/googletest/include
)

target_link_libraries(thomas_blackBoxTest
	#planetSim
	GTest::gtest_main
)

add_executable(thomas_whiteBoxTest
	thomas_whiteBoxTest.cpp
)

target_include_directories(thomas_whiteBoxTest PRIVATE
    ${gtest_SOURCE_DIR}/googletest/include
)

target_link_libraries(thomas_whiteBoxTest
	#planetSim
	GTest::gtest_main
)

add_executable(thomas_integrationTest
	thomas_integrationTest.cpp
)

target_include_directories(thomas_integrationTest PRIVATE
    ${gtest_SOURCE_DIR}/googletest/include
)

target_link_libraries(thomas_integrationTest
	#planetSim
	GTest::gtest_main
)

add_tests(thomas_blackBoxTest)
add_tests(thomas_whiteBoxTest)
add_tests(thomas_integrationTest)