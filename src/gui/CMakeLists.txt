include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)

add_library (game_gui
    ${CMAKE_CURRENT_SOURCE_DIR}/application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/button.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main_menu_context.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/resource_loader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ui_element.cpp
)
target_link_libraries(game_gui PRIVATE SFML::Graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE game_gui)
