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
    srand( time(nullptr) );
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
    srand(time(0));
    int RandNum = rand() % 6;

    if ( RandNum == 0 ) {
        return make_shared<RestorHP>();
    } else if ( RandNum == 1 ) {
        return make_shared<BoostAtk>();
    } else if ( RandNum == 2 ) {
        return make_shared<BoostDef>();
    } else if ( RandNum == 3 ) {
        return make_shared<PoisonHP>();
    } else if ( RandNum == 4 ) {
        return make_shared<WoundAtk>();
    } else { // if ( RandNum == 5 )
        return make_shared<WoundAtk>();
    }
}

std::shared_ptr<Treasure> Factory::genTreasure(){
    srand( time(0) );
    int RandNum = rand() % 4;

    if ( RandNum == 0 ){
        return make_shared<Treasure>(1);
    } else if ( RandNum == 1 ) {
        return make_shared<Treasure>(2);
    } else if ( RandNum == 2 ) {
        return make_shared<Treasure>(4);
    } else { // if ( RandNum == 3 )
        return make_shared<Treasure>(6);
    }
}


void Factory::genFloor(std::vector<std::shared_ptr<Floor>>& f) {
    int i = 0;
    // set random seed
    srand( time(0) );

    // player spawned -- first floor
    int randChamber = rand() % f[i]->getChambers().size();
    int x = rand() % f[i]->getChambers()[randChamber].size();
    std::shared_ptr<Cell> playerPos = f[i]->getChambers()[randChamber][x];
    f[0]->setCell(playerPos, f[i]->getPlayer());

    // stair spawned -- first floor
    int differChameber = rand() % f[i]->getChambers().size();
    while (differChameber == randChamber) {
        differChameber = rand() % f[i]->getChambers().size();
    }
    int y = rand() % f[i]->getChambers()[differChameber].size();
    std::shared_ptr<Cell> stairPos = f[i]->getChambers()[differChameber][y];
    std::shared_ptr<Stair> stair = make_shared<Stair>();
    f[i]->setCell(stairPos, stair);

    // random generate potion
    std::vector<std::shared_ptr<Cell>> tiles = f[i]->getTiles();
    for (int j = 0; j < 10; j++) {
        int randPotion = rand() % tiles.size();
        while(!f[i]->setCell(tiles[randPotion], genPotion())) {
            randPotion = rand() % tiles.size();
        }
    }

    // random generate treasure
    for (int k = 0; k < 10; k++) {
        int randTreasure = rand() % tiles.size();
        while(!f[i]->setCell(tiles[randTreasure], genTreasure())) {
            randTreasure = rand() % tiles.size();
        }
    }

    // random generate enemy
    for (int l = 0; l < 20; l++) {
        int randEnemy = rand() % tiles.size();
        while(!f[i]->setCell(tiles[randEnemy], genEnemy())) {
            randEnemy = rand() % tiles.size();
        }
    }
    f[i]->notifyObserver();
}


