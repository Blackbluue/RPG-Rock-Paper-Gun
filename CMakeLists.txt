# CMakeList.txt : CMake project for RPG-Rock-Paper-Gun, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (
	"RPG-Rock-Paper-Gun"
	VERSION 0.1
	LANGUAGES CXX
	DESCRIPTION "Rock paper scissors game with RPG elements."
)

# Include sub-projects.
add_subdirectory ("game_core")

