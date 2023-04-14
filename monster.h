#ifndef MONSTER__
#define MONSTER__

#include "entity.h"

class Monster : public Entity {
public:
    Monster() {};
    Monster(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase,
            int threatFor,intPair baseCoord);
};

#endif