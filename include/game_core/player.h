#pragma once
#include "game_core/hand.h"


class Player {
public:
    /**
     * Construct a new Player object with default HP and hand configurations.
     *
     * The player's HP is initialized to 10, and the player has one of each hand
     * shape (rock, paper, scissors) with default scores and debuffs.
     */
    Player(void);

    /**
     * Get the current level of the player.
     *
     * @return The current level.
     */
    int get_Lvl(void);

    /**
     * Increase the player's level by 1.
     */
    void level_up(void);

    /**
     * Get the current HP of the player.
     *
     * @return The current HP.
     */
    int getHp(void);

    /**
     * Adjust the HP of the player.
     *
     * @param change The amount to adjust the HP by (positive or negative).
     */
    void adjustHp(int change);

    /**
     * Get the currently active hand of the player.
     *
     * @return The active hand.
     */
    Hand getActiveHand(void);

    /**
     * Set the active hand of the player.
     *
     * @param hand The hand to set as active.
     */
    void setActiveHand(Hand hand);
};

/**
 * Simulate a fight between two players based on their active hands.
 *
 * The function calculates the score of the fight using the active hands of
 * both players and applies damage accordingly.
 *
 * @param p1 The first player.
 * @param p2 The second player.
 */
void fight(Player p1, Player p2);
