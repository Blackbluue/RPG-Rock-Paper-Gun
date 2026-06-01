
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")

# LIBRARIES
add_library (RPG-Rock-Paper-Gun "${CMAKE_CURRENT_SOURCE_DIR}/src/RPG-Rock-Paper-Gun.cpp")

# TESTS
add_executable (core_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/core_test.cpp")
target_link_libraries(core_test RPG-Rock-Paper-Gun)
