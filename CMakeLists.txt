cmake_minimum_required (VERSION 3.16)

project (
	"RPG-Rock-Paper-Gun"
	VERSION 0.1
	LANGUAGES CXX
	DESCRIPTION "Rock paper scissors game with RPG elements."
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/src/game_core")
add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/src/gui")
add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/tests")

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/resources"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources"
)
