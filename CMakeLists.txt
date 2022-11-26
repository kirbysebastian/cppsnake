cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
project(cppsnake VERSION 1.0.0)
message(STATUS "Configuring project ${PROJECT_NAME}:c++${CMAKE_CXX_STANDARD}")

add_subdirectory(src)
add_subdirectory(src/controllers)
add_subdirectory(src/snake)

add_executable(${PROJECT_NAME}
	main.cpp
)

set(PROJECT_LIBS
	src-lib
	managers-lib
	controllers-lib
	snake-lib
)
message(STATUS ${PROJECT_LIBS})

target_link_libraries(${PROJECT_NAME} PRIVATE
	${PROJECT_LIBS}
	sfml-graphics
	sfml-window
	sfml-system
)

target_include_directories(${PROJECT_NAME} PRIVATE
	include
)

