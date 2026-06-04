#pragma once

enum HandShape {
    ROCK,    // beat scissors, lose to paper
    PAPER,   // beat rock, lose to scissors
    SCISSORS // beat paper, lose to rock
};

class Hand {
  private:
    int m_score_base;  // Base score of the hand
    int m_score_mod;   // Score modifier to add to the base score
    int m_debuff;      // Debuff applied to the opponent score when calculating
                       // final score
    HandShape m_shape; // The shape of the hand (rock, paper, scissors)
  public:
    /**
     * Construct a new Hand object with the specified shape.
     *
     * The base score is initialized to 1, the score modifier and debuff are
     * initialized to 0.
     *
     * @param shape The shape of the hand (ROCK, PAPER, or SCISSORS).
     */
    Hand(HandShape shape);

    /**
     * Get the base score of the hand.
     *
     * @return The current base score.
     */
    int getScoreBase();

    /**
     * Set the base score of the hand.
     *
     * @param score_base The new base score to set.
     */
    void setScoreBase(int score_base);

    /**
     * Get the score modifier of the hand.
     *
     * @return The current score modifier.
     */
    int getScoreMod();

    /**
     * Set the score modifier of the hand.
     *
     * @param score_mod The new score modifier to set.
     */
    void setScoreMod(int score_mod);

    /**
     * Get the debuff applied to the opponent when calculating score.
     *
     * @return The current debuff value.
     */
    int getDebuff();

    /**
     * Set the debuff applied to the opponent when calculating score.
     *
     * @param debuff The new debuff value to set.
     */
    void setDebuff(int debuff);

    /**
     * Get the shape of the hand.
     *
     * @return The current hand shape.
     */
    HandShape getShape();

    /**
     * Set the shape of the hand.
     *
     * @param shape The new hand shape to set.
     */
    void setShape(HandShape shape);
};

/**
 * Calculate the score between 2 hands.
 *
 * Any extra modifiers and debuffs are applied to the score calculation,
 * and the advantage score is added accordingly. The return value is the
 * difference between the 2 players' scores, where a positive value indicates a
 * p1 win, a negative value indicates a p1 loss, and zero indicates a tie.
 *
 * @param p1 Player 1's hand to calculate the score for.
 * @param p2 Player 2's hand to calculate the score for.
 * @return The calculated score based on the hand shapes and modifiers.
 */
int calc_score(Hand p1, Hand p2);
