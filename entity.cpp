#include "entity.h"
#include "player.h"

Entity::Entity(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor, std::pair<int, int> coord) : id(id), type(type), x(x), y(y), shieldLife(shieldLife), isControlled(isControlled), health(health), vx(vx), vy(vy), nearBase(nearBase), threatFor(threatFor) {
    disToBase = distance(coord, intPair(x, y));
}
intPair Entity::getCoord() const {
    return intPair(x, y);
}

int Entity::distToCoord(intPair coord) const {
    return distance(coord, getCoord());
}

bool Entity::getIsControlled() const {
    return isControlled;
}

int Entity::getShieldLife() const {
    return shieldLife;
}