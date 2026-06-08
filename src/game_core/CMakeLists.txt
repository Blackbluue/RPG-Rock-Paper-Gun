# LIBRARIES
add_library (game_core
    ${CMAKE_CURRENT_SOURCE_DIR}/game_state.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/session.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utilities.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE game_core)
