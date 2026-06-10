#pragma once

enum class HandShape {
    ROCK,    // beat scissors, lose to paper
    PAPER,   // beat rock, lose to scissors
    SCISSORS // beat paper, lose to rock
};

class Hand {
  public:
    /**
     * Construct a new Hand object with default values.
     *
     * The hand shape is initialized to ROCK, the base score is initialized to
     * 1, and the score modifier and debuff are initialized to 0.
     */
    Hand();

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
    int get_score_base() { return m_score_base; }

    /**
     * Set the base score of the hand.
     *
     * @param score_base The new base score to set.
     */
    void set_score_base(int score_base) { m_score_base = score_base; }

    /**
     * Get the score modifier of the hand.
     *
     * @return The current score modifier.
     */
    int get_score_mod() { return m_score_mod; }

    /**
     * Set the score modifier of the hand.
     *
     * @param score_mod The new score modifier to set.
     */
    void set_score_mod(int score_mod) { m_score_mod = score_mod; }

    /**
     * Get the debuff applied to the opponent when calculating score.
     *
     * @return The current debuff value.
     */
    int get_debuff() { return m_debuff; }

    /**
     * Set the debuff applied to the opponent when calculating score.
     *
     * @param debuff The new debuff value to set.
     */
    void set_debuff(int debuff) { m_debuff = debuff; }

    /**
     * Get the shape of the hand.
     *
     * @return The current hand shape.
     */
    HandShape get_shape() { return m_shape; }

    /**
     * Set the shape of the hand.
     *
     * @param shape The new hand shape to set.
     */
    void set_shape(HandShape shape) { m_shape = shape; }

    /**
     * Calculate the score between this hand and an opponent's hand.
     *
     * Any extra modifiers and debuffs are applied to the score calculation,
     * and the advantage score is added accordingly. The return value is the
     * difference between the 2 players' scores, where a positive value
     * indicates a win for this hand, a negative value indicates a loss, and
     * zero indicates a tie.
     *
     * @param opponent The opponent's hand to calculate the score against.
     * @return The calculated score based on the hand shapes and modifiers.
     */
    int calc_score(Hand opponent);

  private:
    int m_score_base{};  // Base score of the hand
    int m_score_mod{};   // Score modifier to add to the base score
    int m_debuff{};      // Debuff applied to the opponent score
    HandShape m_shape{}; // The shape of the hand (rock, paper, scissors)
};
