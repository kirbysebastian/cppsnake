cmake_minimum_required(VERSION 3.16)

add_library(snake-lib
	snake.cpp
)

target_include_directories(snake-lib PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

