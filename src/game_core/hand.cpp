#include "game_core/hand.h"

Hand::Hand(HandShape shape)
    : m_score_base(1), m_score_mod(0), m_debuff(0), m_shape(shape) {}
int Hand::getScoreBase() { return m_score_base; }
void Hand::setScoreBase(int score_base) { m_score_base = score_base; }
int Hand::getScoreMod() { return m_score_mod; }
void Hand::setScoreMod(int score_mod) { m_score_mod = score_mod; }
int Hand::getDebuff() { return m_debuff; }
void Hand::setDebuff(int debuff) { m_debuff = debuff; }
void Hand::setShape(HandShape shape) { m_shape = shape; }
HandShape Hand::getShape() { return m_shape; }
