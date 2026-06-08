#include "game_core/player.h"
#include "game_core/utilities.h"

constexpr auto INITIAL_HP = 10;
constexpr auto INITIAL_LEVEL = 1;
constexpr auto INITIAL_EXP = 0;
constexpr auto INITIAL_REQ_EXP = 10;
constexpr auto EXP_GROWTH_RATE = 1.3;

Player::Player()
    : m_lvl(INITIAL_LEVEL), m_cur_exp(INITIAL_EXP), m_req_exp(INITIAL_REQ_EXP),
      m_hp(INITIAL_HP), m_active_hand(HandShape::ROCK) {
    m_hands[HandShape::ROCK] = Hand(HandShape::ROCK);
    m_hands[HandShape::PAPER] = Hand(HandShape::PAPER);
    m_hands[HandShape::SCISSORS] = Hand(HandShape::SCISSORS);
}
unsigned short Player::get_Lvl() { return m_lvl; }

void Player::level_up(bool reset_exp) {
    ++m_lvl;
    if (reset_exp) {
        m_cur_exp = INITIAL_EXP;
    }
    m_req_exp = static_cast<unsigned int>(m_req_exp * EXP_GROWTH_RATE);
}

void Player::reset_level() {
    m_lvl = INITIAL_LEVEL;
    m_cur_exp = INITIAL_EXP;
    m_req_exp = INITIAL_REQ_EXP;
}

unsigned int Player::get_cur_exp() { return m_cur_exp; }
unsigned int Player::get_req_exp() { return m_req_exp; }

void Player::gain_exp(unsigned int exp) {
    m_cur_exp += exp;
    while (m_cur_exp >= m_req_exp) {
        m_cur_exp -= m_req_exp;
        // still calculating exp gain, so cannot reset exp yet
        level_up(false);
    }
}

void Player::reset_exp() { m_cur_exp = INITIAL_EXP; }

int Player::get_hp() { return m_hp; }
void Player::adjust_hp(int change) { m_hp += change; }
Hand Player::get_active_hand() { return m_hands[m_active_hand]; }
void Player::set_active_hand(HandShape hand) { m_active_hand = hand; }

std::map<HandShape, Hand> Player::get_hands() { return m_hands; }

Hand Player::random_hand(bool set_active) {
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
        opponent.adjust_hp(damage);
    } else if (score < 0) {
        adjust_hp(damage);
    }
    // TODO: apply after-round-calculation effects
}

void Player::getEnemyInput(Player player) {
    // TODO: let opponent perform other actions before choosing hand
    random_hand(true);
}
