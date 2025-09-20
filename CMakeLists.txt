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

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(snake PRIVATE sfml-graphics sfml-window sfml-system)
target_link_libraries(snake_tests PRIVATE sfml-graphics sfml-window sfml-system)

# 假设 SFML DLL 在 SFML_DIR/bin 下
set(SFML_DLL_DIR "D:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/bin") # 修改为你的实际路径

add_custom_command(TARGET snake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SFML_DLL_DIR}/sfml-graphics-d-2.dll
        ${SFML_DLL_DIR}/sfml-window-d-2.dll
        ${SFML_DLL_DIR}/sfml-system-d-2.dll
        $<TARGET_FILE_DIR:snake>
)