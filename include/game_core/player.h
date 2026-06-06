#pragma once

#include "game_core/hand.h"
#include <map>

class Player {
  private:
    int m_lvl;                         // The player's current level
    int m_hp;                          // The player's current HP
    std::map<HandShape, Hand> m_hands; // The player's hands mapped by shape
    HandShape m_active_hand; // The currently active hand for the player
  public:
    /**
     * Construct a new Player object with default HP and hand configurations.
     *
     * The player's HP is initialized to 10, and the player has one of each hand
     * shape (rock, paper, scissors) with default scores and debuffs.
     */
    Player();

    /**
     * Get the current level of the player.
     *
     * @return The current level.
     */
    int get_Lvl();

    /**
     * Increase the player's level by 1.
     */
    void level_up();

    /**
     * Get the current HP of the player.
     *
     * @return The current HP.
     */
    int getHp();

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
    Hand getActiveHand();

    /**
     * Set the active hand of the player.
     *
     * @param hand The hand to set as active.
     */
    void setActiveHand(HandShape hand);

    /**
     * Simulate a fight between two players based on their active hands.
     *
     * The function calculates the score of the fight using the active hands of
     * both players and applies damage accordingly.
     *
     * @param opponent The second player.
     */
    void fightRound(Player opponent);
};
