#include "game_core/session.h"
#include "game_core/utilities.h"

Session::Session(GameState gameState)
    : m_gameState(gameState), match_count(0) {}
int Session::getMatchCount() { return match_count; }

bool Session::playMatch(Player opponent) {
    while (m_gameState.getPlayer().getHp() > 0 && opponent.getHp() > 0) {
        getPlayerInput(m_gameState);
        getEnemyInput(m_gameState.getPlayer(), opponent);
        fightRound(m_gameState.getPlayer(), opponent);
    }
    return true; // Placeholder return value
}

void Session::grantReward(Player opponent) {
    // TODO: implement reward granting logic after winning a match
}

void Session::updateGameState() {
    // TODO: implement game state updates after match
}
