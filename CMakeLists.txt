cmake_minimum_required(VERSION 3.14)
project(snake_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#主程序
add_executable(snake
	src/main.cpp
	src/snake.cpp
	src/food.cpp
	src/input.cpp
	src/renderer.cpp
	src/game.cpp)

#连接线程库
find_package(Threads REQUIRED)
target_link_libraries(snake PRIVATE Threads::Threads)

#测试
option(BUILD_TESTS "bulid tests" ON)
if(BUILD_TESTS)
	add_executable(snake_tests
		tests/test_main.cpp
		src/snake.cpp)

	target_include_directories(snake_tests PRIVATE src)
	target_compile_definitions(snake_tests PRIVATE CATCH_CONFIG_MAIN)
endif()