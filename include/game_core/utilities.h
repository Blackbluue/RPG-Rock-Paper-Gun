#pragma once

#include "game_core/game_state.h"
#include "game_core/hand.h"
#include "game_core/player.h"

/**
 * Simulate a fight between two players based on their active hands.
 *
 * The function calculates the score of the fight using the active hands of
 * both players and applies damage accordingly.
 *
 * @param p1 The first player.
 * @param p2 The second player.
 */
void fightRound(Player p1, Player p2);

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
