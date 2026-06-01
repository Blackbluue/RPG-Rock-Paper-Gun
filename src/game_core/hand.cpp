#include "game_core/hand.h"
// Advantage score is added to hand score when the hand wins against the opponent's hand.
constexpr auto ADVANTAGE_SCORE = 10;

class Hand {
private:
    int m_score_base;  // Base score of the hand
    int m_score_mod;  // Score modifier to add to the base score
    int m_debuff;  // Debuff applied to the opponent scorewhen calculating final score
    HandShape m_shape;

public:

    Hand(HandShape shape) {
        m_score_base = 1;
        m_score_mod = 0;
        m_debuff = 0;
        m_shape = shape;
    }

    int getScoreBase(void) {
        return m_score_base;
    }

    void setScoreBase(int score_base) {
        m_score_base = score_base;
    }

    int getScoreMod(void) {
        return m_score_mod;
    }

    void setScoreMod(int score_mod) {
        m_score_mod = score_mod;
    }

    int getDebuff(void) {
        return m_debuff;
    }

    void setDebuff(int debuff) {
        m_debuff = debuff;
    }

    HandShape getShape(void) {
        return m_shape;
    }

    void setShape(HandShape shape) {
        m_shape = shape;
    }

    int calc_score(Hand opponent) {
        int score = m_score_base + m_score_mod - opponent.m_debuff;
        int opp_score = opponent.m_score_base + opponent.m_score_mod - m_debuff;

        if (m_shape == opponent.m_shape) {
            return score - opp_score;
        } else if ((m_shape == ROCK && opponent.m_shape == SCISSORS) ||
            (m_shape == PAPER && opponent.m_shape == ROCK) ||
            (m_shape == SCISSORS && opponent.m_shape == PAPER)) {
            return (score + ADVANTAGE_SCORE) - opp_score;
        } else {
            return score - (opp_score + ADVANTAGE_SCORE);
        }
    }
};
