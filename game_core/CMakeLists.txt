
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")

# LIBRARIES
add_library (RPG-Rock-Paper-Gun "${CMAKE_CURRENT_SOURCE_DIR}/src/RPG-Rock-Paper-Gun.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RPG-Rock-Paper-Gun PROPERTY CXX_STANDARD 23)
endif()

# TESTS
add_executable (core_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/core_test.cpp")
target_link_libraries(core_test RPG-Rock-Paper-Gun)
