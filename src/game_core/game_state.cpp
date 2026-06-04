#include "game_core/game_state.h"

GameState::GameState() : m_player() {}
Player GameState::getPlayer() { return m_player; }
