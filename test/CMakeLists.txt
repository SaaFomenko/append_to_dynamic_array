cmake_minimum_required(VERSION 3.5)

project(test_append_array)

add_subdirectory("lib")
file(GLOB
	append_source "../*.cpp"
	print_source "lib/print_dynamic_array/*.cpp"
	userin_source "lib/userin/*.cpp")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(${PROJECT_NAME}_lib STATIC 
	${append_source}
	${print_source} 
	${userin_source})

add_executable(${PROJECT_NAME}.exe main.cpp 
	${append_source}
	${print_source} 
	${userin_source})

target_link_libraries(${PROJECT_NAME}.exe ${PROJECT_NAME}_lib) 
