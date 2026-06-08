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

add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/src/game_core")
add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/tests")
