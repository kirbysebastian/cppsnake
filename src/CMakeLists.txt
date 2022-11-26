cmake_minimum_required(VERSION 3.16)

add_subdirectory(managers)

add_library(src-lib
	application.cpp
)

target_link_libraries(src-lib
	managers-lib
)

target_include_directories(src-lib PRIVATE
	${CMAKE_SOURCE_DIR}/include
)

