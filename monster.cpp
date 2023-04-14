#include"monster.h"
#include "utils.h"
Monster::Monster(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase, int threatFor,intPair coord) : Entity(id, type, x, y, shieldLife, isControlled, health, vx, vy, nearBase, threatFor,coord) {}