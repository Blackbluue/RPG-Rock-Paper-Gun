#pragma once

#include "game_core/player.hpp"

class GameState {
  public:
    /**
     * Construct a new GameState object.
     *
     * @param debug Whether to launch the game in debug mode.
     */
    GameState(bool debug = false) : m_debug(debug) {}

    /**
     * Check if the game is in debug mode.
     *
     * @return True if the game is in debug mode, false otherwise.
     */
    bool is_debug() { return m_debug; }

    /**
     * Get the player in the game state.
     *
     * @return The player object representing the current player.
     */
    Player get_player() { return m_player; }

  private:
    bool m_debug{};    // Whether the game is in debug mode
    Player m_player{}; // The player with their saved attributes
};
