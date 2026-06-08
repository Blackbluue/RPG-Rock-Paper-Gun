#include "game_core/game_state.h"
#include "game_core/hand.h"
#include "game_core/player.h"
#include "game_core/session.h"
#include <gtest/gtest.h> // for Google Test framework
#include <map>

void test_hand(Hand to_test, Hand winner, Hand loser, HandShape shape) {
    EXPECT_EQ(to_test.get_shape(), shape);
    EXPECT_GT(to_test.calc_score(loser),
              0); // to_test should win against loser
    EXPECT_LT(to_test.calc_score(winner),
              0); // to_test should lose against winner
    EXPECT_EQ(to_test.calc_score(to_test),
              0); // to_test should tie against itself
}

TEST(HandTest, test_hand) {
    Hand rock(HandShape::ROCK);
    Hand paper(HandShape::PAPER);
    Hand scissors(HandShape::SCISSORS);

    test_hand(rock, paper, scissors, HandShape::ROCK);

    test_hand(paper, scissors, rock, HandShape::PAPER);

    test_hand(scissors, rock, paper, HandShape::SCISSORS);
}

TEST(PlayerTest, test_level) {
    Player player;

    // Test direct level manipulation
    EXPECT_EQ(player.get_Lvl(), 1);
    player.level_up();
    player.level_up();
    player.level_up();
    player.level_up();
    EXPECT_EQ(player.get_Lvl(), 5);
    player.reset_level();
    EXPECT_EQ(player.get_Lvl(), 1);

    // Test experience gain and level up
    EXPECT_EQ(player.get_cur_exp(), 0);
    unsigned int no_lvl_up = player.get_req_exp() - 1;
    player.gain_exp(no_lvl_up);
    EXPECT_EQ(player.get_cur_exp(), no_lvl_up);
    player.gain_exp(1);
    EXPECT_EQ(player.get_Lvl(), 2);
    EXPECT_EQ(player.get_cur_exp(), 0);
    player.gain_exp(no_lvl_up);
    EXPECT_EQ(player.get_Lvl(), 2);
    EXPECT_EQ(player.get_cur_exp(), no_lvl_up);
    player.reset_exp();
    EXPECT_EQ(player.get_Lvl(), 2);
    EXPECT_EQ(player.get_cur_exp(), 0);
    player.gain_exp(player.get_req_exp() + no_lvl_up);
    EXPECT_EQ(player.get_Lvl(), 3);
    EXPECT_EQ(player.get_cur_exp(), no_lvl_up);
    player.reset_level();
    EXPECT_EQ(player.get_Lvl(), 1);
    EXPECT_EQ(player.get_cur_exp(), 0);
}

TEST(PlayerTest, test_hp) {
    Player player;

    int initial_hp = player.get_hp();
    player.adjust_hp(5);
    EXPECT_EQ(player.get_hp(), initial_hp + 5);
    player.adjust_hp(-3);
    EXPECT_EQ(player.get_hp(), initial_hp + 2);
}

TEST(PlayerTest, test_hands) {
    Player player;

    player.set_active_hand(HandShape::ROCK);
    EXPECT_EQ(player.get_active_hand().get_shape(), HandShape::ROCK);

    player.set_active_hand(HandShape::PAPER);
    EXPECT_EQ(player.get_active_hand().get_shape(), HandShape::PAPER);

    player.set_active_hand(HandShape::SCISSORS);
    EXPECT_EQ(player.get_active_hand().get_shape(), HandShape::SCISSORS);

    for (int i{10}; i > 0; --i) {
        player.random_hand();
        // ensure random_hand function does not change active hand
        EXPECT_EQ(player.get_active_hand().get_shape(), HandShape::SCISSORS);
    }
    for (int i{10}; i > 0; --i) {
        Hand rand_hand = player.random_hand(true);
        // ensure random_hand function changes active hand
        EXPECT_EQ(player.get_active_hand().get_shape(), rand_hand.get_shape());
    }

    std::map<HandShape, Hand> hands = player.get_hands();
    EXPECT_EQ(hands.size(), 3);
    EXPECT_EQ(hands[HandShape::ROCK].get_shape(), HandShape::ROCK);
    EXPECT_EQ(hands[HandShape::PAPER].get_shape(), HandShape::PAPER);
    EXPECT_EQ(hands[HandShape::SCISSORS].get_shape(), HandShape::SCISSORS);
}

TEST(SessionTest, test_session) {
    constexpr auto MATCH_LIMIT = 100;
    auto matches_won = 0;
    GameState gs{true}; // debug mode
    Session session{gs};
    Player player = gs.get_player();
    Player opponent{};

    for (int i{0}; i > MATCH_LIMIT; ++i) {
        EXPECT_EQ(session.get_matchs_won(), matches_won);
        bool match_won = session.play_match(opponent);
        if (match_won) {
            EXPECT_EQ(session.get_matchs_won(), ++matches_won);
            EXPECT_GT(player.get_hp(), 0);
            EXPECT_LE(opponent.get_hp(), 0);
        } else {
            EXPECT_LE(player.get_hp(), 0);
            EXPECT_GT(opponent.get_hp(), 0);
            EXPECT_EQ(session.get_matchs_won(), matches_won);
        }
    }
    session.reset_matches();
    EXPECT_EQ(session.get_matchs_won(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
