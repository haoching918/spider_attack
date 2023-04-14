#include "player.h"
#include <iostream>

using namespace std;

int main() {
    int baseX, baseY;
    cin >> baseX >> baseY;
    cin.ignore();
    int herosPerPlayer;
    cin >> herosPerPlayer;
    cin.ignore();
    Player player(baseX, baseY, 3);                                         // construct a new player
    player.setDefaultCoord(pair(500, 500), pair(500, 300), pair(300, 500)); // set default coordinates to each allies
    while (1) {
        player.resetEntity();                                                                                // reset all entity information
        cin >> player;                                                                                       // input all round information
        auto monsterNearBase = player.monsterNearBy(player.getBaseCoord(1), constants::BASERADIUS);          // get a list of monster id near by base coord in range 5000
        auto enemiesNearBase = player.enemyNearBy(player.getBaseCoord(1), constants::BASERADIUS);            // get a list of enemy id near by base coord in range 5000
        auto alliesNearMonster = player.monsterNearBy(player.monsters[monsterNearBase[0]].getCoord(), 2000); // get a list of allies near by nearest monster to base in range 2000
        for (auto &[id, h] : player.allies) {                                                                // iterate over all allies
            if (true) {
                h.spellWind(player.getBaseCoord(0));                                                                     // spell wind to enemies base
                h.control(enemiesNearBase[0], player.getBaseCoord(0).first, player.getBaseCoord(1).second, player); // spell control enemies nearest to base go to enemies base
                h.shield(id, player);                                                                               // spell shield to self
                h.goDefaultCoord(player);                                                                                     // go to defaut coord
                h.goEntity(monsterNearBase[0], player);                                                                  // go nearest monster's coord
                h.goCoord(player.monsters[monsterNearBase[1]].getCoord());                                               // go to second monster's coord
            }
        }
        for (auto &[id, h] : player.allies) { // output heros's command
            cout << h;
        }
    }
    return 0;
}