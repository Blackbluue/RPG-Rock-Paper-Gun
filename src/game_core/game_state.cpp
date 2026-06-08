#include "game_core/game_state.h"

GameState::GameState(bool debug) : m_debug(debug) {}
bool GameState::isDebug() { return m_debug; }
Player GameState::getPlayer() { return m_player; }
