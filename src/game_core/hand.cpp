#include "game_core/hand.h"
// Advantage score is added to hand score when the hand wins against the opponent's hand.
constexpr auto ADVANTAGE = 10;

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
};

int calc_score(Hand p1, Hand p2) {
    int p1_score = p1.getScoreBase() + p1.getScoreMod() - p2.getDebuff();
    int p2_score = p2.getScoreBase() + p2.getScoreMod() - p1.getDebuff();

    if (p1.getShape() == p2.getShape()) {
        return p1_score - p2_score;
    } else if ((p1.getShape() == ROCK && p2.getShape() == SCISSORS) ||
        (p1.getShape() == PAPER && p2.getShape() == ROCK) ||
        (p1.getShape() == SCISSORS && p2.getShape() == PAPER)) {
        return (p1_score + ADVANTAGE) - p2_score;
    } else {
        return p1_score - (p2_score + ADVANTAGE);
    }
}
