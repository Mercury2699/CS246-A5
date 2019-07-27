#include <iostream>
#include "factory.h"


//Players
#include "human.h"
#include "orc.h"
#include "elves.h"
#include "dwarf.h"

// Enemies
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "phoenix.h"
#include "dragon.h"
#include "merchant.h"
#include "goblin.h"

using std::make_shared;

Factory::Factory() {
    srand(time(nullptr));
}


std::shared_ptr<Player> Factory::spawnPlayer(std::string race) {
    std::shared_ptr<Player> pc;
    if (race == "h" ) {
        pc = make_shared<Human>();
    } else if (race == "e") {
        pc = make_shared<Elves>();
    } else if (race == "o") {
        pc = make_shared<Orc>();
    } else if (race == "d") {
        pc = make_shared<Dwarf>();
    }
    return pc;
}


std::shared_ptr<Enemy> Factory::genEnemy() {
    int NPCRand = rand() % 18;
    
    if ( NPCRand <= 3 ) { // if (NPCRand == 0, 1, 2, 3)
        return make_shared<Werewolf>();
    } else if ( NPCRand <= 6 ) { // if (NPCRand == 4, 5, 6)
        return make_shared<Vampire>();
    } else if ( NPCRand <= 11) { // if (NPCRand == 7, 8, 9, 10, 11)
        return make_shared<Goblin>();
    } else if ( NPCRand <= 13) { // if (NPCRand == 12,13) 
        return make_shared<Troll>();
    } else if ( NPCRand <= 15) { // if (NPCRand == 14,15)
        return make_shared<Phoenix>();
    } else { // if (NPCRand == 16,17)
        return make_shared<Merchant>();
    }
}

std::shared_ptr<Potion> Factory::genPotion() {
    int randPotion = rand() % 6;

    if ( randPotion == 0 ) {
        return make_shared<RestorHP>();
    } else if ( randPotion == 1 ) {
        return make_shared<BoostAtk>();
    } else if ( randPotion == 2 ) {
        return make_shared<BoostDef>();
    } else if ( randPotion == 3 ) {
        return make_shared<PoisonHP>();
    } else if ( randPotion == 4 ) {
        return make_shared<WoundAtk>();
    } else { // if ( randPotion == 5 )
        return make_shared<WoundAtk>();
    }
}

std::shared_ptr<Treasure> Factory::genTreasure(){
    int randTreasure = rand() % 8;

    if ( randTreasure <= 4 ){
        return make_shared<Treasure>(1);
    } else if ( randTreasure <= 6 ) {
        return make_shared<Treasure>(2);
    } else { // ( randTreasure == 7 )
        return make_shared<Treasure>(6);
    }
}

void Factory::genDragon(std::shared_ptr<Cell> target, std::shared_ptr<Floor> floor){
    std::string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
    int randDir = rand() % 8;
    std::shared_ptr<Dragon> newDragon= make_shared<Dragon>();
    while (!floor->setCell(floor->target(target, directions[randDir]), newDragon)) {
        randDir = rand() % 8;
    }
}

void Factory::genFloor(std::vector<std::shared_ptr<Floor>>& f) {

   for (int i = 0; i < 5; i++) {
    
    std::vector<std::vector<std::shared_ptr<Cell>>> cham = f[i]->getChambers();
    
    std::vector<std::shared_ptr<Cell>> tiles = f[i]->getTiles();

    // player spawned
    int randChamber = rand() % cham.size();
    int x = rand() % cham[randChamber].size();
    f[i]->setCell(cham[randChamber][x], f[0]->getPlayer());

    // stair spawned
    int differChameber = rand() % cham.size();
    while (differChameber == randChamber) {
        differChameber = rand() % cham.size();
    }
    int y = rand() % cham[differChameber].size();
    f[i]->setCell(cham[differChameber][y], make_shared<Stair>());

    // random generate barrier suit
    int hasBarrier = 0;

    if (i == 0) {
        int randFloor = rand() % 5;
        std::vector<std::shared_ptr<Cell>> tempTiles = f[randFloor]->getTiles();
        int randBarrier = rand() % tempTiles.size();
        std::shared_ptr<BarrierSuit> newBarrier = make_shared<BarrierSuit>();
        while(!f[i]->setCell(tempTiles[randBarrier], newBarrier)) {
            randBarrier = rand() % tempTiles.size();
        }
        genDragon(tempTiles[randBarrier], f[randFloor]);
        hasBarrier++;
    }

    // random generate potion
    for (int j = 0; j < 10; j++) {
        int randPotion = rand() % tiles.size();
        std::shared_ptr<Potion> newPotion = genPotion();
        while(!f[i]->setCell(tiles[randPotion], newPotion)) {
            randPotion = rand() % tiles.size();
        }
    }

    // random generate treasure
    int dragonNum = 0;
    for (int k = 0; k < 10; k++) {
        int randTreasure = rand() % tiles.size();
        std::shared_ptr<Treasure> newTreasure = genTreasure();
        while(!f[i]->setCell(tiles[randTreasure], newTreasure)) {
            randTreasure = rand() % tiles.size();
        }
        if (newTreasure->isDragonHoard()) {
            genDragon(tiles[randTreasure], f[i]);
            dragonNum++;
        }
    }

    // random generate enemy
    int randNum = rand() % (20 - dragonNum - hasBarrier);
    for (int l = 0; l < 20 - dragonNum - hasBarrier; l++) {
        int randEnemy = rand() % tiles.size();
        std::shared_ptr<Enemy> newEnemy = genEnemy();
        if (l == randNum) {
            newEnemy->assignCompass();
        }
        while(!f[i]->setCell(tiles[randEnemy], newEnemy)) {
            randEnemy = rand() % tiles.size();
        }
    }
   }
}


