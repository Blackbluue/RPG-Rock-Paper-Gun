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
};
