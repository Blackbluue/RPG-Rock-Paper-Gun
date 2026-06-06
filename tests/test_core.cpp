#include "game_core/hand.h"
#include "game_core/player.h"
#include <gtest/gtest.h> // for Google Test framework
#include <map>

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

    player.set_active_hand(ROCK);
    EXPECT_EQ(player.get_active_hand().getShape(), ROCK);

    player.set_active_hand(PAPER);
    EXPECT_EQ(player.get_active_hand().getShape(), PAPER);

    player.set_active_hand(SCISSORS);
    EXPECT_EQ(player.get_active_hand().getShape(), SCISSORS);

    for (int i{10}; i > 0; --i) {
        player.random_hand();
        // ensure random_hand function does not change active hand
        EXPECT_EQ(player.get_active_hand().getShape(), SCISSORS);
    }
    for (int i{10}; i > 0; --i) {
        Hand rand_hand = player.random_hand(true);
        // ensure random_hand function changes active hand
        EXPECT_EQ(player.get_active_hand().getShape(), rand_hand.getShape());
    }

    std::map<HandShape, Hand> hands = player.get_hands();
    EXPECT_EQ(hands.size(), 3);
    EXPECT_EQ(hands[ROCK].getShape(), ROCK);
    EXPECT_EQ(hands[PAPER].getShape(), PAPER);
    EXPECT_EQ(hands[SCISSORS].getShape(), SCISSORS);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
