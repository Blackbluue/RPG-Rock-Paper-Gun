#include "game_core/player.h"

Player::Player()
    : m_lvl(1), m_hp(10), m_rock(ROCK), m_paper(PAPER), m_scissors(SCISSORS),
      m_active_hand(m_rock) {}
int Player::get_Lvl() { return m_lvl; }
void Player::level_up() { ++m_lvl; }
int Player::getHp() { return m_hp; }
void Player::adjustHp(int change) { m_hp += change; }
Hand Player::getActiveHand() { return m_active_hand; }
