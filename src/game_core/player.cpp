#include "game_core/player.hpp"

#include "game_core/utilities.hpp"


constexpr auto INITIAL_HP      = 10;
constexpr auto INITIAL_LEVEL   = 1;
constexpr auto INITIAL_EXP     = 0;
constexpr auto INITIAL_REQ_EXP = 10;
constexpr auto EXP_GROWTH_RATE = 1.3;

Player::Player()
    : m_lvl(INITIAL_LEVEL),
      m_cur_exp(INITIAL_EXP),
      m_req_exp(INITIAL_REQ_EXP),
      m_hp(INITIAL_HP),
      m_active_hand(HandShape::ROCK) {
    m_hands[HandShape::ROCK]     = Hand(HandShape::ROCK);
    m_hands[HandShape::PAPER]    = Hand(HandShape::PAPER);
    m_hands[HandShape::SCISSORS] = Hand(HandShape::SCISSORS);
}

void Player::level_up(bool reset_exp) {
    ++m_lvl;
    if (reset_exp) {
        m_cur_exp = INITIAL_EXP;
    }
    m_req_exp = static_cast<unsigned int>(m_req_exp * EXP_GROWTH_RATE);
}

void Player::reset_level() {
    m_lvl     = INITIAL_LEVEL;
    m_cur_exp = INITIAL_EXP;
    m_req_exp = INITIAL_REQ_EXP;
}

void Player::gain_exp(unsigned int exp) {
    m_cur_exp += exp;
    while (m_cur_exp >= m_req_exp) {
        m_cur_exp -= m_req_exp;
        // still calculating exp gain, so cannot reset exp yet
        level_up(false);
    }
}

Hand Player::random_hand(bool set_active) {
    HandShape shape =
        static_cast<HandShape>(random_number(0, m_hands.size() - 1));
    if (set_active) {
        m_active_hand = shape;
    }
    return m_hands[shape];
}

void Player::fight_round(Player opponent) {
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

void Player::get_enemy_input(Player player) {
    // TODO: let opponent perform other actions before choosing hand
    random_hand(true);
}
