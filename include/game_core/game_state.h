#pragma once

#include "game_core/player.h"

class GameState {
  private:
    Player m_player; // The player in the game
  public:
    /**
     * Construct a new GameState object.
     *
     * Initializes the game state and prepares for a new match.
     */
    GameState();

    /**
     * Get the player in the game state.
     *
     * @return The player object representing the current player.
     */
    Player getPlayer();
};
