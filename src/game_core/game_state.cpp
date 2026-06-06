#include "game_core/game_state.h"

GameState::GameState(LaunchType launchType) : m_launchType(launchType) {}
Player GameState::getPlayer() { return m_player; }
