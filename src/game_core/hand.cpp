#include "game_core/hand.h"

constexpr auto SCORE_BASE = 1; // Base score for each hand
constexpr auto SCORE_MOD = 0;  // Default score modifier for each hand
constexpr auto DEBUFF = 0;     // Default debuff for each hand
// added to hand score when the hand wins against the opponent's hand.
constexpr auto ADVANTAGE = 10;

Hand::Hand()
    : m_score_base(SCORE_BASE), m_score_mod(SCORE_MOD), m_debuff(DEBUFF),
      m_shape(HandShape::ROCK) {}
Hand::Hand(HandShape shape)
    : m_score_base(SCORE_BASE), m_score_mod(SCORE_MOD), m_debuff(DEBUFF),
      m_shape(shape) {}
int Hand::getScoreBase() { return m_score_base; }
void Hand::setScoreBase(int score_base) { m_score_base = score_base; }
int Hand::getScoreMod() { return m_score_mod; }
void Hand::setScoreMod(int score_mod) { m_score_mod = score_mod; }
int Hand::getDebuff() { return m_debuff; }
void Hand::setDebuff(int debuff) { m_debuff = debuff; }
void Hand::setShape(HandShape shape) { m_shape = shape; }
HandShape Hand::getShape() { return m_shape; }

int Hand::calc_score(Hand opponent) {
    int p1_score = m_score_base + m_score_mod - opponent.m_debuff;
    int p2_score = opponent.m_score_base + opponent.m_score_mod - m_debuff;

    if (m_shape == opponent.m_shape) {
        return p1_score - p2_score;
    } else if ((m_shape == HandShape::ROCK &&
                opponent.m_shape == HandShape::SCISSORS) ||
               (m_shape == HandShape::PAPER &&
                opponent.m_shape == HandShape::ROCK) ||
               (m_shape == HandShape::SCISSORS &&
                opponent.m_shape == HandShape::PAPER)) {
        return (p1_score + ADVANTAGE) - p2_score;
    } else {
        return p1_score - (p2_score + ADVANTAGE);
    }
}
