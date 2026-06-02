#include "game_core/player.h"

class Player {
private:
    int m_lvl;  // The player's current level
    int m_hp;  // The player's current HP
    Hand m_rock;  // The player's rock hand
    Hand m_paper;  // The player's paper hand
    Hand m_scissors;  // The player's scissors hand
    Hand m_active_hand;  // The currently active hand for the player

public:
    Player(void) {
        m_lvl = 1;
        m_hp = 10;
        m_rock = Hand(ROCK);
        m_paper = Hand(PAPER);
        m_scissors = Hand(SCISSORS);
        m_active_hand = nullptr;
    }

    int get_Lvl(void) {
        return m_lvl;
    }

    void level_up(void) {
        m_lvl++;
    }

    int getHp(void) {
        return m_hp;
    }

    void adjustHp(int change) {
        m_hp += change;
    }

    Hand getActiveHand(void) {
        return m_active_hand;
    }

    void setActiveHand(Hand hand) {
        m_active_hand = hand;
    }
};

void fight(Player p1, Player p2) {
    // TODO: apply adjustments before calculating score
    int score = calc_score(p1.getActiveHand(), p2.getActiveHand());
    // TODO: implement dynamic damage logic
    int damage = -1;

    if (score > 0) {
        p2.adjustHp(damage);
    } else if (score < 0) {
        p1.adjustHp(damage);
    }
    // TODO: apply after-battle-calculation effects
}
