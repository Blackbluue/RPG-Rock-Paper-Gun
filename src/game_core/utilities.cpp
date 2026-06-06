#include "game_core/utilities.h"
#include <random>

int random_number(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void getPlayerInput(GameState gameState) {
    // TODO: implement player input handling to change active hand
}

void getEnemyInput(Player player, Player opponent) {
    // TODO: implement enemy AI to choose active hand
}
