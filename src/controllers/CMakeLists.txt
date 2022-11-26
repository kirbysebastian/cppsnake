cmake_minimum_required(VERSION 3.16)

add_library(controllers-lib
	snake_controller.cpp
)

target_include_directories(controllers-lib PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

