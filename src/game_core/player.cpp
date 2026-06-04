#include "game_core/player.h"

Player::Player()
    : m_lvl(1), m_hp(10), m_rock(ROCK), m_paper(PAPER), m_scissors(SCISSORS),
      m_active_hand(m_rock) {}
int Player::get_Lvl() { return m_lvl; }
void Player::level_up() { ++m_lvl; }
int Player::getHp() { return m_hp; }
void Player::adjustHp(int change) { m_hp += change; }
Hand Player::getActiveHand() { return m_active_hand; }

void fight(Player p1, Player p2) {
    // TODO: apply adjustments before calculating score
    int score = calc_score(p1.getActiveHand(), p2.getActiveHand());
    // TODO: implement dynamic damage logic
    int damage = -1;

    if (score > 0) {
        p2.adjustHp(damage);
    } else if (score < 0) {
        p1.adjustHp(damage);
    }
    // TODO: apply after-battle-calculation effects
}
