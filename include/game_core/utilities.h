#pragma once

#include "game_core/game_state.h"
#include "game_core/hand.h"
#include "game_core/player.h"

/**
 * Calculate the score between 2 hands.
 *
 * Any extra modifiers and debuffs are applied to the score calculation,
 * and the advantage score is added accordingly. The return value is the
 * difference between the 2 players' scores, where a positive value indicates a
 * p1 win, a negative value indicates a p1 loss, and zero indicates a tie.
 *
 * @param p1 Player 1's hand to calculate the score for.
 * @param p2 Player 2's hand to calculate the score for.
 * @return The calculated score based on the hand shapes and modifiers.
 */
int calc_score(Hand p1, Hand p2);

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
