#include "game_core/player.h"

class Player {
private:
    int m_lvl;
    int m_hp;
    Hand m_rock;
    Hand m_paper;
    Hand m_scissors;

public:
    Player(void) {
        m_lvl = 1;
        m_hp = 10;
        m_rock = Hand(ROCK);
        m_paper = Hand(PAPER);
        m_scissors = Hand(SCISSORS);
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
};
