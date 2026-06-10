#pragma once

#include "game_core/hand.hpp"
#include <map>

class Player {
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
    unsigned short get_Lvl() { return m_lvl; }

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
    unsigned int get_cur_exp() { return m_cur_exp; }

    /**
     * Get the experience points required to level up.
     *
     * @return The required experience points.
     */
    unsigned int get_req_exp() { return m_req_exp; }

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
    void reset_exp() { m_cur_exp = 0; }

    /**
     * Get the current HP of the player.
     *
     * @return The current HP.
     */
    int get_hp() { return m_hp; }

    /**
     * Adjust the HP of the player.
     *
     * @param change The amount to adjust the HP by (positive or negative).
     */
    void adjust_hp(int change) { m_hp += change; }

    /**
     * Get the currently active hand of the player.
     *
     * @return The active hand.
     */
    Hand get_active_hand() { return m_hands[m_active_hand]; }

    /**
     * Set the active hand of the player.
     *
     * @param hand The hand to set as active.
     */
    void set_active_hand(HandShape hand) { m_active_hand = hand; }

    /**
     * Get the player's hands mapped by their shapes.
     *
     * Note: Do not add/remove hands from this map, as the player is expected to
     * always have one of each hand shape. Replacing the Hand objects with new
     * ones of the correct type is fine, but the keys should not be changed.
     *
     * @return A map of hand shapes to their corresponding Hand objects.
     */
    std::map<HandShape, Hand> get_hands() { return m_hands; }

    /**
     * Get a random hand from the player.
     *
     * If set_active is true, the randomly selected hand is also set as the
     * player's active hand.
     *
     * @param set_active Whether to set the randomly selected hand as the
     * active hand.
     * @return The randomly selected hand.
     */
    Hand random_hand(bool set_active = false);

    /**
     * Simulate a fight between two players based on their active hands.
     *
     * The function calculates the score of the fight using the active hands of
     * both players and applies damage accordingly.
     *
     * @param opponent The second player.
     */
    void fight_round(Player opponent);

    /**
     * Get enemy input to change the active hand.
     *
     * This function will simulate enemy input to change their active hand
     * before a fight round. The implementation can be based on random selection
     * or a simple AI algorithm.
     *
     * @param player The player whose opponent's input is being simulated.
     */
    void get_enemy_input(Player player);

  private:
    unsigned short m_lvl{};   // The player's current level
    unsigned int m_cur_exp{}; // The player's current experience points
    unsigned int m_req_exp{}; // The experience points required to level up
    int m_hp{};               // The player's current HP
    std::map<HandShape, Hand> m_hands{}; // The player's hands mapped by shape
    HandShape m_active_hand{}; // The currently active hand for the player
};
