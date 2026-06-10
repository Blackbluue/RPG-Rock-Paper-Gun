#include "game_core/session.hpp"

bool Session::play_match(Player opponent) {
    auto round = 1;
    Player player = m_gameState.get_player();

    while (player.get_hp() > 0 && opponent.get_hp() > 0) {
        if (!m_gameState.is_debug()) {
            // TODO: get player input
            opponent.get_enemy_input(player);
        } else {
            // randomize all choices in debug mode for testing purposes
            player.random_hand(true);
            opponent.random_hand(true);
        }
        player.fight_round(opponent);
        ++round;
        if (m_gameState.is_debug() && round == 11) {
            // kill player after 10 rounds to stop excessively long matches
            player.adjust_hp(-player.get_hp());
        }
    }
    if (player.get_hp() > 0) {
        ++m_matchs_won;
        return true; // Player wins
    } else {
        return false; // Opponent wins
    }
}

void Session::grant_reward(Player opponent) {
    // TODO: implement reward granting logic after winning a match
}

void Session::update_game_state() {
    // TODO: implement game state updates after match
}
