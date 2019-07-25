#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "floor.h"
#include "emptyCell.h"
#include "doorway.h"
#include "floorTile.h"
#include "wall.h"
#include "passage.h"
#include "item.h"
#include "treasure.h"
#include "enemy.h"
#include "human.h"
#include "elves.h"
#include "dwarf.h"
#include "orc.h"

#include "vampire.h"
#include "werewolf.h"
#include "dragon.h"
#include "phoenix.h"
#include "troll.h"
#include "goblin.h"

using namespace std;

Floor::Floor(std::string file){
    ifstream m(file);
    char c;
    int x = 0, y = 0;
    vector<shared_ptr<Cell>> row;
    while (m.get(c)){
        if(c == '\n'){
            theGrid.emplace_back(row);
            row.clear();
            x = 0;
            y++;
        } else if (c == ' ') {
            auto p = make_shared<EmptyCell>(x, y);
            row.emplace_back(p);
        } else if (c == '-') {
            row.emplace_back(make_shared<Cell>(new Wall(x, y, true)));
        } else if (c == '|') {
            row.emplace_back(make_shared<Cell>(new Wall(x, y, false)));
        } else if (c == '+') {
            row.emplace_back(make_shared<Cell>(new Doorway(x, y)));
        } else if (c == '#') {
            row.emplace_back(make_shared<Cell>(new Passage(x, y)));
        } else {
            shared_ptr<FloorTile> cur1 = make_shared<FloorTile>(x ,y);
            row.emplace_back(cur1);
            shared_ptr<FloorTile> cur2 = cur1;
            floorTiles.emplace_back(cur2);
            shared_ptr<FloorTile> cur3 = cur1;
            if (c == 'A') chambers[0].emplace_back(cur3);
            else if (c == 'B') chambers[1].emplace_back(cur3);
            else if (c == 'C') chambers[2].emplace_back(cur3);
            else if (c == 'D') chambers[3].emplace_back(cur3);
            else chambers[4].emplace_back(cur3);
        }
        x++;
    }
    m.close();
}

Floor::ReadFile(std::string file){
    ifstream m(file);
    char c;
    int x = 0, y = 0;
    vector<Cell> row;
    while (m.get(c)){
        if(c == '\n'){
            theGrid.emplace_back(row);
            row.clear();
            x = 0;
            y++;
        } else if (c == ' ') {
            row.emplace_back(make_shared<Cell>(new EmptyCell(x, y)));
        } else if (c == '-') {
            row.emplace_back(make_shared<Cell>(new Wall(x, y, true)));
        } else if (c == '|') {
            row.emplace_back(make_shared<Cell>(new Wall(x, y, false)));
        } else if (c == '+') {
            row.emplace_back(make_shared<Cell>(new Doorway(x, y)));
        } else if (c == '#') {
            row.emplace_back(make_shared<Cell>(new Passage(x, y)));            
        } else {
            row.emplace_back(make_shared<Cell>(new FloorTile(x, y)));
            if (c == '0'){
                row[x]->setOccupant(new RestorHP{});
                row[x]->setOccupancy(true);
            } else if (c == '1'){
                row[x]->setOccupant(make_shared<Item>(new BoostAtk{}));
                row[x]->setOccupancy(true);
            } else if (c == '2'){
                row[x]->setOccupant(make_shared<Item>(new BoostDef{}));
                row[x]->setOccupancy(true);
            } else if (c == '3'){
                row[x]->setOccupant(make_shared<Item>(new PoisonHP{}));
                row[x]->setOccupancy(true);
            } else if (c == '4'){
                row[x]->setOccupant(make_shared<Item>(new WoundAtk{}));
                row[x]->setOccupancy(true);
            } else if (c == '5'){
                row[x]->setOccupant(make_shared<Item>(new WoundDef{}));
                row[x]->setOccupancy(true);
            } else if (c == '6'){
                row[x]->setOccupant(make_shared<Item>(new Treasure{1}));
            } else if (c == '7'){
                row[x]->setOccupant(make_shared<Item>(new Treasure{2}));
            } else if (c == '8'){
                row[x]->setOccupant(make_shared<Item>(new Treasure{4}));
            } else if (c == '9'){
                row[x]->setOccupant(make_shared<Item>(new Treasure{6}));
            } else if (c == 'W'){
                row[x]->setOccupant(make_shared<Enemy>(new Werewolf{nullptr});
                row[x]->setOccupancy(true);
            } else if (c == 'V'){
                row[x]->setOccupant(make_shared<Enemy>(new Vampire{nullptr});
                row[x]->setOccupancy(true);
            } else if (c == 'N'){
                row[x]->setOccupant(make_shared<Enemy>(new Goblin{nullptr});
                row[x]->setOccupancy(true);
            } else if (c == 'T'){
                row[x]->setOccupant(make_shared<Enemy>(new Troll{nullptr});
                row[x]->setOccupancy(true);
            } else if (c == 'X'){
                row[x]->setOccupant(make_shared<Enemy>(new Phoenix{nullptr});
                row[x]->setOccupancy(true);
            } else if (c == 'M'){
                row[x]->setOccupant(make_shared<Enemy>(new Merchant{});
                row[x]->setOccupancy(true);
            } else if (c == 'D'){
                row[x]->setOccupant(make_shared<Enemy>(new Dragon{nullptr}});
                row[x]->setOccupancy(true);
            } else if (c == '@'){
                row[x]->setOccupant(make_shared<Player>(new Player));
                row[x]->setOccupancy(true);
            } else if (c == '\\'){
                row[x]->setOccupant(make_shared<Stair>(new Stair);
            } else //do nothing
        }
       
    }
    m.close();
}

std::shared_ptr<Cell> Floor::target(std::shared_ptr<Cell> cur, std::string direction) {
    int curX = cur->getX();
    int curY = cur->getY();
    int targetX, targetY = 0;
    if (direction == "N") {
        targetX = curX;
        targetY = curY - 1;
    } else if (direction == "S") {
        targetX = curX;
        targetY = curY + 1;
    } else if (direction == "E") {
        targetX = curX + 1;
        targetY = curY;
    } else if (direction == "W") {
        targetX = curX - 1;
        targetY = curY;
    } else if (direction == "NE") {
        targetX = curX + 1;
        targetY = curY - 1;
    } else if (direction == "NW") {
        targetX = curX - 1;
        targetY = curY - 1;
    } else if (direction == "SE") {
        targetX = curX + 1;
        targetY = curY + 1;
    } else {
        targetX = curX - 1;
        targetY = curY + 1;
    }
    return theGrid[targetX][targetY];
}
void Floor::playerMove(std::string direction) {
    int curX = pc->getCell()->getX();
    int curY = pc->getCell()->getY();
    std::shared_ptr<Cell> targetCell = target(pc->getCell(), direction);
    int targetX = targetCell->getX();
    int targetY = targetCell->getY();
    if (targetCell->checkOccupancy(false)) return;
    std::shared_ptr<Stuff> s = theGrid[curX][curY]->detachStuff();
    pc->setCell(theGrid[targetX][targetY]);
    theGrid[targetX][targetY]->attachStuff(pc);
    checkEvents();
}

bool isClose(std::shared_ptr<Cell> c1, std::shared_ptr<Cell> c2) {
    if (std::abs(c1->getX() - c2->getX()) <= 1 && std::abs(c1->getY() - c2->getY()) <= 1) return true;
    else return false;
}

bool Floor::checkEvents() {
    if (pc->isDead()) return true;
    if (pc->getCell()->getOccupant()->getType() == Type::Str) return false;
    if (pc->getCell()->getOccupant()->getType() == Type::Trsr) {
            shared_ptr<Treasure> t = make_shared<Treasure>(pc->getCell()->getOccupant().get());
            t->effect(pc);
    }
    //if (pc->getCell()->getOccupant()->)
    for (auto cur : floorTiles) {
        if(cur->getOccupant()->getType() == Type::Enmy) {
            shared_ptr<Enemy> e = make_shared<Enemy>(cur->getOccupant().get());
            if(!e->isDead() && isClose(cur, pc->getCell())) {
                pc->beAttacked(e);
                if (pc->isDead()) return true;
            } else if(isClose(cur, pc->getCell()) && e->isDead()) {
                if (e->getChar() == 'M') {
                    cur->attachStuff(make_shared<Treasure>(3));
                    cur->setOccupancy(false);
                }
                pc->setTreasure(pc->getTreasure() + 1);
                if (e->checkCompass()) {
                    shared_ptr<Compass> c = make_shared<Compass>();
                    cur->attachStuff(c);
                    cur->setOccupancy(false);
                    for (auto current : floorTiles) {
                        if (current->getOccupant()->getType() == Type::Str) {
                            // shared_ptr<Stair> s = reinterpret_cast<Stair *>(current->getOccupant().get());
                            Stair * s = static_cast<Stair *>(current->getOccupant().get());
                            s->enableDisplay();
                            break;
                        }
                    }
                }
            } else continue;
        } 
    }
    return false;
}

void Floor::playerAtk(std::string direction) {
    shared_ptr<Cell> targetCell = target(pc->getCell(), direction);
    if (targetCell->getOccupant()->getType() != Type::Enmy) return;
    shared_ptr<Enemy> e = make_shared<Enemy>(targetCell->getOccupant().get());
    e->beAttacked(pc);
    checkEvents();
    pc->beAttacked(e);
    checkEvents();
}

void Floor::playerUse(std::string direction) {
    shared_ptr<Cell> targetCell = target(pc->getCell(), direction);
    if (targetCell->getOccupant()->getType() != Type::Ptn) return;
    shared_ptr<Potion> p = make_shared<Potion>(targetCell->getOccupant().get());
    p->effect(pc);
}

void Floor::startGame(std::string race) {
    if (race == "h") pc = make_shared<Human>();
    else if (race == "e") pc = make_shared<Elves>();
    else if (race == "d") pc = make_shared<Dwarf>();
    else pc = make_shared<Orc>();
}

void Floor::moveEnemies() {
    for (auto cur : floorTiles) {
        if (cur->getOccupant()->getType() == Type::Enmy) {
            vector<shared_ptr<Cell>> validMove;
            string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
            for (int i = 0; i < 8; ++i) {
                if (target(cur, directions[i])->checkOccupancy(true)) validMove.emplace_back(target(cur, directions[i]));
            } 
            srand(time(nullptr));
            int index = rand() % validMove.size();
            shared_ptr<Cell> des = validMove[index];
            theGrid[des->getX()][des->getY()]->attachStuff(cur->getOccupant());
        }
    }
}

void Floor::setCell(int x, int y, std::shared_ptr<Stuff> s) {
    theGrid[x][y]->attachStuff(s);
    if (s->getType() == Type::Trsr || s->getType() == Type::Str || s->getChar() == 'c') {
        theGrid[x][y]->setOccupancy(false); // lets the user step on
    }
}

std::shared_ptr<Player> Floor::getPlayer() {
    return pc;
}

std::vector<std::shared_ptr<Cell>> Floor::getTiles() {
    return floorTiles;
}

std::vector<std::vector<std::shared_ptr<Cell>>> Floor::getChambers() {
    return chambers;
}

