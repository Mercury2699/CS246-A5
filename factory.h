#ifndef FACTORY_H
#define FACTORY_H
#include <cstdlib>
#include <ctime>
#include <memory>

#include "item.h"
#include "potion.h"
#include "player.h"
#include "enemy.h"
#include "treasure.h"
#include "floor.h"
#include "cell.h"

struct Factory {
    Factory();
    std::shared_ptr<Player> spawnPlayer(char);
    std::shared_ptr<Enemy> genEnemy();
    std::shared_ptr<Potion> genPotion();
    std::shared_ptr<Treasure> genTreasure();
    void genFloor(std::vector<std::shared_ptr<Floor>>&);
    void genDragon(std::shared_ptr<Cell>, std::shared_ptr<Floor>);
};


#endif



