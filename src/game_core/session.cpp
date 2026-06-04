#include "game_core/session.h"
#include "game_core/hand.h"

// added to hand score when the hand wins against the opponent's hand.
constexpr auto ADVANTAGE = 10;

/* PRIVATE FUNCTIONS */

/**
 * Calculate the score between 2 hands.
 *
 * Any extra modifiers and debuffs are applied to the score calculation,
 * and the advantage score is added accordingly. The return value is the
 * difference between the 2 players' scores, where a positive value indicates a
 * p1 win, a negative value indicates a p1 loss, and zero indicates a tie.
 *
 * @param p1 Player 1's hand to calculate the score for.
 * @param p2 Player 2's hand to calculate the score for.
 * @return The calculated score based on the hand shapes and modifiers.
 */
int calc_score(Hand p1, Hand p2) {
    int p1_score = p1.getScoreBase() + p1.getScoreMod() - p2.getDebuff();
    int p2_score = p2.getScoreBase() + p2.getScoreMod() - p1.getDebuff();

    if (p1.getShape() == p2.getShape()) {
        return p1_score - p2_score;
    } else if ((p1.getShape() == ROCK && p2.getShape() == SCISSORS) ||
               (p1.getShape() == PAPER && p2.getShape() == ROCK) ||
               (p1.getShape() == SCISSORS && p2.getShape() == PAPER)) {
        return (p1_score + ADVANTAGE) - p2_score;
    } else {
        return p1_score - (p2_score + ADVANTAGE);
    }
}

/**
 * Simulate a fight between two players based on their active hands.
 *
 * The function calculates the score of the fight using the active hands of
 * both players and applies damage accordingly.
 *
 * @param p1 The first player.
 * @param p2 The second player.
 */
void fightRound(Player p1, Player p2) {
    // TODO: apply adjustments before calculating score
    int score = calc_score(p1.getActiveHand(), p2.getActiveHand());
    // TODO: implement dynamic damage logic
    int damage = -1;

    if (score > 0) {
        p2.adjustHp(damage);
    } else if (score < 0) {
        p1.adjustHp(damage);
    }
    // TODO: apply after-round-calculation effects
}

/* PUBLIC FUNCTIONS */

Session::Session(GameState gameState)
    : m_gameState(gameState), match_count(0) {}
int Session::getMatchCount() { return match_count; }

bool Session::playMatch(Player opponent) {
    while (m_gameState.getPlayer().getHp() > 0 && opponent.getHp() > 0) {
        // TODO: add hook to allow for player input to change active hand
        // TODO: get random hand for opponent
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
