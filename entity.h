#ifndef ENTITY__
#define ENTITY__
#include "utils.h"
class Entity {
    friend class Player;

protected:
    int disToBase;
    int x;
    int y;
    int id;
    int type;
    int shieldLife;
    int isControlled;
    int health;
    int vx;
    int vy;
    int nearBase;
    int threatFor;

public:
    intPair getCoord() const;
    int distToCoord(intPair coord) const;
    bool getIsControlled() const;
    int getShieldLife() const;
    Entity(){};
    Entity(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor, intPair baseCoord);
};
#endif