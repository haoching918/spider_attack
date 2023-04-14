#ifndef PLAYER__
#define PLAYER__
#include "hero.h"
#include "monster.h"
#include "utils.h"
#include <map>
#include <vector>

class Player {
public:
    static int health, enemyHealth;
    static int mana, enemyMana;

    const int allyBaseX, allyBaseY, enemyBaseX, enemyBaseY, heroesNum;
    std::map<int, Monster> monsters;
    std::map<int, Ally> allies;
    std::map<int, Enemy> enemies;
    std::vector<intPair> allyDefaultCoord;
    int side;
    //  ⚾⚾⚾
    intPair getBaseCoord(bool isAlly) const;
    std::vector<int> monsterNearBy(intPair coord, int range) const;
    std::vector<int> enemyNearBy(intPair coord, int range) const;
    std::vector<int> allyNearBy(intPair coord, int range) const;
    std::vector<int> shieldedMonsterNearBy(intPair coord, int range) const;
    void resetEntity();
    void setDefaultCoord(intPair allyCoord1, intPair allyCoord2, intPair allyCoord3);
    intPair getDefaultCoord(int id);
    Player(int baseX, int baseY, int heroes);
};

std::istream &operator>>(std::istream &is, Player &player);
#endif