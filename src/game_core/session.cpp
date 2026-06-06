#include "game_core/session.h"
#include "game_core/utilities.h"

Session::Session(GameState gameState) : m_gameState(gameState) {}
int Session::getMatchCount() { return match_count; }

bool Session::playMatch(Player opponent) {
    while (m_gameState.getPlayer().getHp() > 0 && opponent.getHp() > 0) {
        getPlayerInput(m_gameState);
        getEnemyInput(m_gameState.getPlayer(), opponent);
        m_gameState.getPlayer().fightRound(opponent);
    }
    if (m_gameState.getPlayer().getHp() > 0) {
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
