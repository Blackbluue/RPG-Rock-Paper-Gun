#include "game_core/utilities.h"

// added to hand score when the hand wins against the opponent's hand.
constexpr auto ADVANTAGE = 10;

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

void getPlayerInput(GameState gameState) {
    // TODO: implement player input handling to change active hand
}

void getEnemyInput(Player player, Player opponent) {
    // TODO: implement enemy AI to choose active hand
}
