#ifndef HERO__
#define HERO__
#include "entity.h"
#include <string>

class Player;

class Ally : public Entity {
private:
    std::string command;
    bool hasCommand = false;

public:
    bool goCoord(intPair coord);
    bool goDefaultCoord(Player &player);
    bool goEntity(int id, Player &player);
    bool spellWind(int x, int y);
    bool spellWind(intPair coord);
    bool control(int id, int x, int y, Player &player);
    bool shield(int id, Player &player);
    std::string getCommand() const;
    Ally(){};
    Ally(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor, intPair baseCoord);
};

class Enemy : public Entity {
public:
    Enemy(){};
    Enemy(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor, intPair baseCoord);
};

std::ostream& operator << (std::ostream & os,const Ally & a);
#endif