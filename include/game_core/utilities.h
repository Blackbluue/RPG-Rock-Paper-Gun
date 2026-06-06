#pragma once

#include "game_core/game_state.h"
#include "game_core/player.h"

/**
 * Generate a random number within a specified range.
 *
 * This function generates a random integer between the given minimum and
 * maximum values, inclusive.
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random integer between min and max.
 */
int random_number(int min, int max);

/**
 * Get player input to change the active hand.
 *
 * This function will handle player input to allow them to change their active
 * hand before a fight round. The implementation will depend on the input
 * method (e.g., console input, GUI buttons, etc.).
 *
 * @param gameState The current game state containing the player information.
 */
void getPlayerInput(GameState gameState);

/**
 * Get enemy input to change the active hand.
 *
 * This function will simulate enemy input to change their active hand before a
 * fight round. The implementation can be based on random selection or a simple
 * AI algorithm.
 *
 * @param player The player whose opponent's input is being simulated.
 * @param opponent The opponent player whose active hand will be changed.
 */
void getEnemyInput(Player player, Player opponent);
