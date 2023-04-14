#include "player.h"
#include <algorithm>
#include <iostream>

using namespace std;

int Player::health = 0;
int Player::mana = 0;
int Player::enemyHealth = 0;
int Player::enemyMana = 0;

Player::Player(int baseX, int baseY, int heroes) : allyBaseX(baseX), allyBaseY(baseY), heroesNum(heroes),
                                                   enemyBaseX(baseX == 0 ? 17630 : 0),
                                                   enemyBaseY(baseX == 0 ? 9000 : 0) {
    side = baseX < 100 ? 1 : -1;
}

intPair Player::getBaseCoord(bool isAlly) const {
    if (isAlly)
        return make_pair(allyBaseX, allyBaseY);
    else
        return make_pair(enemyBaseX, enemyBaseY);
}

std::vector<int> Player::monsterNearBy(intPair coord, int range) const {
    vector<intPair> idAndDist;
    for (auto &[id, m]: monsters) {
        if (m.distToCoord(coord) <= range) {
            idAndDist.push_back(intPair(id, m.distToCoord(coord)));
        }
    }
    sort(idAndDist.begin(), idAndDist.end(), [&](const intPair &a, const intPair &b) {
        return a.second < b.second;
    });
    vector<int> result;
    result.reserve(result.size());
    for (auto &i: idAndDist) {
        result.push_back(i.first);
    }

    return result;
}

std::vector<int> Player::shieldedMonsterNearBy(intPair coord, int range) const {
    vector<intPair> idAndDist;
    for (auto &[id, m]: monsters) {
        if (m.distToCoord(coord) <= range and m.getShieldLife() > 0) {
            idAndDist.emplace_back(id, m.distToCoord(coord));
        }
    }
    sort(idAndDist.begin(), idAndDist.end(), [&](const intPair &a, const intPair &b) {
        return a.second < b.second;
    });
    vector<int> result;
    result.reserve(result.size());
    for (auto &i: idAndDist) {
        result.push_back(i.first);
    }

    return result;
}

std::vector<int> Player::enemyNearBy(intPair coord, int range) const {
    vector<intPair> idAndDist;
    for (auto &[id, e]: enemies) {
        if (e.distToCoord(coord) <= range) {
            idAndDist.push_back(intPair(id, e.distToCoord(coord)));
        }
    }
    sort(idAndDist.begin(), idAndDist.end(), [&](const intPair &a, const intPair &b) {
        return a.second < b.second;
    });
    vector<int> result;
    result.reserve(result.size());
    for (auto &i: idAndDist) {
        result.push_back(i.first);
    }
    return result;
}

std::vector<int> Player::allyNearBy(intPair coord, int range) const {
    vector<intPair> idAndDist;
    for (auto &[id, a]: allies) {
        if (a.distToCoord(coord) <= range) {
            idAndDist.push_back(intPair(id, a.distToCoord(coord)));
        }
    }
    sort(idAndDist.begin(), idAndDist.end(), [&](const intPair &a, const intPair &b) {
        return a.second < b.second;
    });
    vector<int> result;
    result.reserve(result.size());
    for (auto &i: idAndDist) {
        result.push_back(i.first);
    }
    return result;
}

void Player::setDefaultCoord(intPair allyCoord1, intPair allyCoord2, intPair allyCoord3) {
    allyDefaultCoord.clear();
    allyDefaultCoord.emplace_back(allyCoord1);
    allyDefaultCoord.emplace_back(allyCoord2);
    allyDefaultCoord.emplace_back(allyCoord3);
}

intPair Player::getDefaultCoord(int id) {
    if (allies.find(id) != allies.end()) {
        return allyDefaultCoord[id % 3];
    }else{
        std::cerr << "invalid id of allies\n";
        return allyDefaultCoord[id % 3];
    }

}

void Player::resetEntity() {
    monsters.clear();
    allies.clear();
    enemies.clear();
}

std::istream &operator>>(std::istream &is, Player &player) {
    int mana, health;
    cin >> health >> mana;
    Player::health = health;
    Player::mana = mana;
    cin >> health >> mana;
    Player::enemyHealth = health;
    Player::enemyMana = mana;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        int id, type, x, y, shieldLife, isControlled, health, vx, vy, nearBase, threatFor;
        is >> id >> type >> x >> y >> shieldLife >> isControlled >> health >> vx >> vy >> nearBase >> threatFor;

        switch (type) {
            case 0: {
                Monster m(id, type, x, y, shieldLife, isControlled, health, vx, vy, nearBase, threatFor,player.getBaseCoord(true));
                player.monsters[id] = m;
                break;
            }
            case 1: {
                player.allies[id] = Ally(id, type, x, y, shieldLife, isControlled, health, vx, vy, nearBase, threatFor,player.getBaseCoord(true));
                break;
            }
            case 2: {
                player.enemies[id] = Enemy(id, type, x, y, shieldLife, isControlled, health, vx, vy, nearBase, threatFor, player.getBaseCoord(true));
                break;
            }
            default:
                break;
        }
    }
    return is;
}
