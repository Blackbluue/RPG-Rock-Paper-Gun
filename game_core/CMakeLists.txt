
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")

# Add source to this project's executable.
add_executable (RPG-Rock-Paper-Gun "${CMAKE_CURRENT_SOURCE_DIR}/src/RPG-Rock-Paper-Gun.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RPG-Rock-Paper-Gun PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.