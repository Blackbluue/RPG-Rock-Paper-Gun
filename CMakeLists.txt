# CMakeLists.txt : CMake project for RPG-Rock-Paper-Gun, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)

project (
	"RPG-Rock-Paper-Gun"
	VERSION 0.1
	LANGUAGES CXX
	DESCRIPTION "Rock paper scissors game with RPG elements."
)

# Set the desired C++ standard (e.g., 11, 14, 17, 20, 23, 26)
set(CMAKE_CXX_STANDARD 23)

# Enforce the standard (fails to configure if the compiler doesn't support it)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# Include sub-projects.
add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/src/game_core")
add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/tests")

