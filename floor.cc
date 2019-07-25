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

using namespace std;

Floor::Floor(std::string file){
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
            row.emplace_back(make_shared<EmptyCell>(x, y));
        } else if (c == '-') {
            row.emplace_back(make_shared<Wall>(x, y, true));
        } else if (c == '|') {
            row.emplace_back(make_shared<Wall>(x, y, false));
        } else if (c == '+') {
            row.emplace_back(make_shared<Doorway>(x, y));
        } else if (c == '#') {
            row.emplace_back(make_shared<Passage>(x, y));
        } else {
            shared_ptr<Cell> cur1 = make_shared<FloorTile>(x ,y);
            row.emplace_back(cur1);
            shared_ptr<Cell> cur2 = cur1;
            floorTiles.emplace_back(cur2);
            shared_ptr<Cell> cur3 = cur1;
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
                            shared_ptr<Stair> s = make_shared<Stair>(current->getOccupant().get());
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
    for (auto row : theGrid) {
        for (auto col : row) {
            if (col->getOccupant()->getType() == Type::Enmy) {
                vector<shared_ptr<Cell>> validMove;
                string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
                for (int i = 0; i < 8; ++i) {
                   if (target(col, directions[i])->checkOccupancy(true)) validMove.emplace_back(target(col, directions[i]));
                } 
            srand(time(nullptr));
            int index = rand() % validMove.size();
            shared_ptr<Cell> des = validMove[index];
            theGrid[des->getX()][des->getY()]->attachStuff(col->getOccupant());
            shared_ptr<Enemy> e = make_shared<Enemy>(col->getOccupant().get());
            e->toggleMoved();
            }
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

