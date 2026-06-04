#include "game_core/game_state.h"

GameState::GameState(LaunchType launchType = LaunchType::GUI)
    : m_launchType(launchType), m_player() {}
Player GameState::getPlayer() { return m_player; }
