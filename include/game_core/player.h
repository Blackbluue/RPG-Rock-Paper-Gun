#pragma once

#include "game_core/hand.h"
#include <map>

class Player {
  private:
    unsigned short m_lvl{};   // The player's current level
    unsigned int m_cur_exp{}; // The player's current experience points
    unsigned int m_req_exp{}; // The experience points required to level up
    int m_hp{10};             // The player's current HP
    std::map<HandShape, Hand> m_hands{}; // The player's hands mapped by shape
    HandShape m_active_hand{ROCK}; // The currently active hand for the player
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
    unsigned short get_Lvl();

    /**
     * Increase the player's level by 1.
     *
     * If reset_exp is true, the player's current experience points are reset to
     * 0. Because leveling up without resetting the experience points can lead
     * to errors in progression, this should generally never be done without a
     * good reason.
     *
     * @param reset_exp Whether to reset the player's current experience points
     * to 0 after leveling up.
     */
    void level_up(bool reset_exp = true);

    /**
     * Reset the player's level to the initial value.
     */
    void reset_level();

    /**
     * Get the current experience points of the player.
     *
     * @return The current experience points.
     */
    unsigned int get_cur_exp();

    /**
     * Get the experience points required to level up.
     *
     * @return The required experience points.
     */
    unsigned int get_req_exp();

    /**
     * Increase the player's experience points.
     *
     * If the player's experience points exceed the required amount to level up,
     * the player levels up and the excess experience points are carried over.
     * The required experience points for the next level up increase by a growth
     * rate after each level up.
     *
     * @param exp The amount of experience points to gain.
     */
    void gain_exp(unsigned int exp);

    /**
     * Reset the player's experience points to the initial values.
     *
     * Resetting experience points does not alter the player's level.
     */
    void reset_exp();

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

    Hand randomHand(bool set_active = false);

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
