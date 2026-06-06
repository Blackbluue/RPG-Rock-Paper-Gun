#pragma once

#include "game_core/player.h"

enum LaunchType {
    GUI,   // Launch the game with a graphical user interface
    TEXT,  // Launch the game with a text-based interface
    DEBUG, // Launch the game in debug mode with additional logging and features
};

class GameState {
  private:
    LaunchType m_launchType{GUI}; // The type of launch for the game
    Player m_player{};            // The player with their saved attributes
  public:
    /**
     * Construct a new GameState object.
     *
     * Initializes the game state and prepares for a new match.
     *
     * @param launchType The type of launch for the game.
     */
    GameState(LaunchType launchType = LaunchType::GUI);

    /**
     * Get the player in the game state.
     *
     * @return The player object representing the current player.
     */
    Player getPlayer();
};
