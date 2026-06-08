#pragma once

#include "game_core/player.h"

class GameState {
  private:
    bool m_debug{};    // Whether the game is in debug mode
    Player m_player{}; // The player with their saved attributes
  public:
    /**
     * Construct a new GameState object.
     *
     * @param debug Whether to launch the game in debug mode.
     */
    GameState(bool debug = false);

    /**
     * Check if the game is in debug mode.
     *
     * @return True if the game is in debug mode, false otherwise.
     */
    bool isDebug();

    /**
     * Get the player in the game state.
     *
     * @return The player object representing the current player.
     */
    Player getPlayer();
};
