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

void Factory::spawnPlayer() {
    srand( time(nullptr) );
    int randNum = rand() % floorTiles.size();
    pc->setCurrPos( floorTiles[randNum] );
}


std::shared_ptr<Enemy> Factory::genEnemy() {
    srand( time(nullptr) );
    int NPCRand = rand() % 18;
    
    if ( NPCRand <= 3 ) {
        return make_shared<Enemy>(Werewolf{nullptr});
    } else if ( NPCRand <= 6 ) {
        return make_shared<Enemy>(Vampire{nullptr});
    } else if ( NPCRand <= 11) {
        return make_shared<Enemy>(Goblin{nullptr});
    } else if ( NPCRand <= 13) {
        return make_shared<Enemy>(Troll{nullptr});
    } else if ( NPCRand <= 15) {
        return make_shared<Enemy>(Phoenix{nullptr});
    } else {
        return make_shared<Enemy>(Merchant{});
    }
}

std::shared_ptr<Potion> Factory::genPotion() {
    srand(time(0));
    int RandNum = rand() % 6;

    if ( RandNum == 0 ) {
        return make_shared<Potion>(RestorHP{});
    } else if ( RandNum == 1 ) {
        return make_shared<Potion>(BoostAtk{});
    } else if ( RandNum == 2 ) {
        return make_shared<Potion>(BoostDef{});
    } else if ( RandNum == 3 ) {
        return make_shared<Potion>(PoisonHP{});
    } else if ( RandNum == 4 ) {
        return make_shared<Potion>(WoundAtk{});
    } else { // if ( RandNum == 5 )
        return make_shared<Potion>(WoundDef{});
    }
}

std::shared_ptr<Treasure> Factory::genTreasure(){
    srand(time(0));
    int RandNum = rand() % 4;

    if (RandNum == 0){
        return make_shared<Treasure>(Treasure{1});
    } else if (RandNum == 1) {
        return make_shared<Treasure>(Treasure{2});
    } else if (RandNum == 2) {
        return make_shared<Treasure>(Treasure{4});
    } else { // RandNum == 3s
        return make_shared<Treasure>(Treasure{6});
    }
}

void Factory::genFloor(std::shared_ptr<Floor> f){

}


