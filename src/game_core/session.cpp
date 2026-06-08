#include "game_core/session.h"

bool Session::play_match(Player opponent) {
    auto round = 1;
    Player player = m_gameState.getPlayer();

    while (player.get_hp() > 0 && opponent.get_hp() > 0) {
        if (!m_gameState.isDebug()) {
            // TODO: get player input
            opponent.getEnemyInput(player);
        } else {
            // randomize all choices in debug mode for testing purposes
            player.random_hand(true);
            opponent.random_hand(true);
        }
        player.fightRound(opponent);
        ++round;
        if (m_gameState.isDebug() && round == 11) {
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
