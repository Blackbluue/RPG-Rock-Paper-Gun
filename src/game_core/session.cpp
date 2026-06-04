#include "game_core/session.h"

Session::Session(GameState gameState)
    : m_gameState(gameState), match_count(0) {}
int Session::getMatchCount() { return match_count; }

bool Session::playMatch(Player opponent) {
    // TODO: implement main game loop for playing a match
    return true; // Placeholder return value
}

void Session::grantReward(Player opponent) {
    // TODO: implement reward granting logic after winning a match
}

void Session::updateGameState() {
    // TODO: implement game state updates after match
}
