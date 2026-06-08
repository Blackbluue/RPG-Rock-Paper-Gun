#include "game_core/session.h"

Session::Session(GameState gameState) : m_gameState(gameState) {}
int Session::getMatchCount() { return match_count; }

bool Session::playMatch(Player opponent) {
    Player player = m_gameState.getPlayer();
    while (player.get_hp() > 0 && opponent.get_hp() > 0) {
        if (m_gameState.isDebug()) {
            player.random_hand(true);
        } else {
            // TODO: get player input
        }
        opponent.getEnemyInput(player);
        player.fightRound(opponent);
    }
    if (player.get_hp() > 0) {
        ++match_count;
        return true; // Player wins
    } else {
        return false; // Opponent wins
    }
}

void Session::grantReward(Player opponent) {
    // TODO: implement reward granting logic after winning a match
}

void Session::updateGameState() {
    // TODO: implement game state updates after match
}
