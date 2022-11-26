cmake_minimum_required(VERSION 3.16)

add_library(managers-lib
	game_manager.cpp
)

target_include_directories(managers-lib PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

