#include "game_core/player.h"
#include "game_core/utilities.h"

Player::Player() {
    m_hands[ROCK] = Hand(ROCK);
    m_hands[PAPER] = Hand(PAPER);
    m_hands[SCISSORS] = Hand(SCISSORS);
}
int Player::get_Lvl() { return m_lvl; }
void Player::level_up() { ++m_lvl; }
int Player::getHp() { return m_hp; }
void Player::adjustHp(int change) { m_hp += change; }
Hand Player::getActiveHand() { return m_hands[m_active_hand]; }

Hand Player::randomHand(bool set_active) {
    HandShape shape =
        static_cast<HandShape>(random_number(0, m_hands.size() - 1));
    if (set_active) {
        m_active_hand = shape;
    }
    return m_hands[shape];
}

void Player::fightRound(Player opponent) {
    // TODO: apply adjustments before calculating score
    int score = m_hands[m_active_hand].calc_score(
        opponent.m_hands[opponent.m_active_hand]);
    // TODO: implement dynamic damage logic
    int damage = -1;

    if (score > 0) {
        opponent.adjustHp(damage);
    } else if (score < 0) {
        adjustHp(damage);
    }
    // TODO: apply after-round-calculation effects
}
