#include "game_core/utilities.h"

void fightRound(Player p1, Player p2) {
    // TODO: apply adjustments before calculating score
    int score = p1.getActiveHand().calc_score(p2.getActiveHand());
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
