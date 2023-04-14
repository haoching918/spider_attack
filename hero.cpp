#include "hero.h"
#include "player.h"
#include <sstream>
using namespace constants;
Ally::Ally(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase,
           int threatFor, intPair coord) : Entity(id, type, x, y, shieldLife, isControlled, health, vx, vy, nearBase,
                                                  threatFor, coord) {}

bool Ally::goCoord(intPair coord) {
    if (hasCommand) {
        return false;
    }
    std::stringstream ss;
    ss << "MOVE " << coord.first << " " << coord.second;
    command = ss.str();
    hasCommand = true;
    return true;
}

bool Ally::goDefaultCoord(Player &player){
    return goCoord(player.getDefaultCoord(id%3));
}

bool Ally::goEntity(int id, Player &p) {
    if (p.monsters.find(id) != p.monsters.end()) {
        return goCoord(p.monsters[id].getCoord());
    } else if (p.allies.find(id) != p.allies.end()) {
        return goCoord(p.allies[id].getCoord());
    } else if (p.enemies.find(id) != p.enemies.end()) {
        return goCoord(p.enemies[id].getCoord());
    }
    return false;
}

bool Ally::spellWind(int x, int y) {
    if (Player::mana < SPELLCOSTS or hasCommand) {
        return false;
    } else {
        std::stringstream ss;
        ss << "SPELL WIND " << x << " " << y;
        Player::mana -= SPELLCOSTS;
        command = ss.str();
        hasCommand = true;
    }
    return true;
}
bool Ally::spellWind(intPair coord){
    return Ally::spellWind(coord.first, coord.second);
}

bool Ally::control(int id, int x, int y, Player &p) {
    Entity *e;
    if (p.monsters.find(id) != p.monsters.end()) {
        e = dynamic_cast<Entity *>(&p.monsters[id]);
    } else if (p.allies.find(id) != p.allies.end()) {
        e = dynamic_cast<Entity *>(&p.allies[id]);
    } else if (p.enemies.find(id) != p.enemies.end()) {
        e = dynamic_cast<Entity *>(&p.enemies[id]);
    }
    if (Player::mana < SPELLCOSTS or e->getIsControlled() || e->distToCoord(getCoord()) > CTRLRADIUS  or hasCommand) {
        return false;
    } else {
        std::stringstream oss;
        oss << "SPELL CONTROL " << id << " " << x << ' ' << y;
        Player::mana -= SPELLCOSTS;
        command = oss.str();
        hasCommand = true;
    }
    return true;
}

bool Ally::shield(int id, Player &p) {
    Entity *e;
    if (p.monsters.find(id) != p.monsters.end()) {
        e = dynamic_cast<Entity *>(&p.monsters[id]);
    } else if (p.allies.find(id) != p.allies.end()) {
        e = dynamic_cast<Entity *>(&p.allies[id]);
    } else if (p.enemies.find(id) != p.enemies.end()) {
        e = dynamic_cast<Entity *>(&p.enemies[id]);
    }

    if (Player::mana < SPELLCOSTS || e->getShieldLife() > 0 or e->distToCoord(getCoord()) > SHLDRADIUS || hasCommand) {
        return false;
    } else {
        std::stringstream oss;
        oss << "SPELL SHIELD " << id;
        Player::mana -= SPELLCOSTS;
        command = oss.str();
        hasCommand = true;
    }
    return true;
}

Enemy::Enemy(int id, int type, int x, int y, int shieldLife, int isControlled, int health, int vx, int vy, int nearBase,
             int threatFor, intPair coord) : Entity(id, type, x, y, shieldLife, isControlled, health, vx, vy, nearBase,
                                                    threatFor, coord) {}

std::string Ally::getCommand() const {
    return command;
}

std::ostream &operator<<(std::ostream &os, const Ally &a) {
    os << a.getCommand() << '\n';
    return os;
}