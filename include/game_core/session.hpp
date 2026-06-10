#pragma once

#include "game_core/game_state.hpp"
#include "game_core/player.hpp"

class Session {
  private:
    GameState m_gameState{}; // The game state for the session
    int m_matchs_won{};      // The number of matches won in the session
  public:
    /**
     * Construct a new Session object.
     *
     * Initializes the session and prepares for a new match.
     */
    Session(GameState game_state) : m_gameState(game_state) {}

    /**
     * Get the number of matches won in the session.
     *
     * @return The current match count.
     */
    int get_matchs_won() { return m_matchs_won; }

    /**
     * Reset the match count to 0.
     */
    void reset_matches() { m_matchs_won = 0; }

    /**
     * Play a new match in the game.
     *
     * This function will handle the main game loop, including drawing cards,
     * playing cards, picking hands, calculating scores, applying effects, and
     * checking for end conditions.
     *
     * @param opponent The opponent player (e.g., an AI opponent).
     * @return True if the player wins the match, false otherwise.
     */
    bool play_match(Player opponent);

    /**
     * Grant rewards to the player after winning a match.
     *
     * This function will apply rewards such as experience points, level-ups,
     * and new cards to the player's game state after winning a match.
     *
     * @param opponent The opponent player that was defeated.
     */
    void grant_reward(Player opponent);

    /**
     * Update the game state with the player's progression after a match.
     *
     * This function will update the save state specific information not tied
     * directly to the player's attributes.
     */
    void update_game_state();
};
