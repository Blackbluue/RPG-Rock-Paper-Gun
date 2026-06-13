#include "game_core/hand.hpp"

#include <map>
#include <string_view>

// added to hand score when the hand wins against the opponent's hand.
constexpr auto                                             ADVANTAGE = 3;
const std::map<HandShape, std::map<std::string_view, int>> DEFAULT_HANDS{
    {    HandShape::ROCK,{{"score_base", 4}, {"score_mod", 1}, {"debuff", 0}}                         },
    {   HandShape::PAPER, {{"score_base", 0}, {"score_mod", 2}, {"debuff", 4}}},
    {HandShape::SCISSORS,
     {{"score_base", 1}, {"score_mod", 3}, {"debuff", 0}}                     }
};

Hand::Hand()
    : m_score_base(DEFAULT_HANDS.at(HandShape::ROCK).at("score_base")),
      m_score_mod(DEFAULT_HANDS.at(HandShape::ROCK).at("score_mod")),
      m_debuff(DEFAULT_HANDS.at(HandShape::ROCK).at("debuff")),
      m_shape(HandShape::ROCK) {}
Hand::Hand(HandShape shape)
    : m_score_base(DEFAULT_HANDS.at(shape).at("score_base")),
      m_score_mod(DEFAULT_HANDS.at(shape).at("score_mod")),
      m_debuff(DEFAULT_HANDS.at(shape).at("debuff")),
      m_shape(shape) {}

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
