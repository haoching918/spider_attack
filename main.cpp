#include <iostream>
#include "player.h"

using namespace std;


int main() {
    int baseX, baseY;
    cin >> baseX >> baseY;
    cin.ignore();
    int herosPerPlayer;
    cin >> herosPerPlayer;
    cin.ignore();
    Player player(baseX, baseY, 3);
    player.setDefaultCoord(pair(500,500),pair(500,300),pair(300,500));
    while (1) {
        player.resetEntity();
        cin >> player;
        auto v = player.monsterNearBy(player.getBaseCoord(true), constants::BASERADIUS);
        auto near700 = player.monsterNearBy(player.getBaseCoord(true), 700);
        for (auto &[id, hero]: player.allies) {
            if (not near700.empty()) {
                hero.spellWind(player.enemyBaseX, player.enemyBaseY);
            }
            hero.goDefaultCoord(player);
            cout << hero;
        }
    }
    return 0;
}