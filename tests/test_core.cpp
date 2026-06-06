#include "game_core/player.h"
#include <gtest/gtest.h> // for Google Test framework

TEST(PlayerTest, level) {
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
