#include <fstream>
#include <sstream>
#include <cstdlib> // includes ctime
// cells
#include "floor.h"
#include "emptyCell.h"
#include "doorway.h"
#include "floorTile.h"
#include "wall.h"
#include "passage.h"

#include "item.h"
#include "treasure.h"
// player char
#include "human.h"
#include "elves.h"
#include "dwarf.h"
#include "orc.h"
// enemies
#include "vampire.h"
#include "werewolf.h"
#include "dragon.h"
#include "merchant.h"
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
            row.emplace_back(make_shared<Wall>(x, y, true));
        } else if (c == '|') {
            row.emplace_back(make_shared<Wall>(x, y, false));
        } else if (c == '+') {
            row.emplace_back(make_shared<Doorway>(x, y));
        } else if (c == '#') {
            row.emplace_back(make_shared<Passage>(x, y));
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

void Floor::ReadFile(std::string file){
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
            row.emplace_back(make_shared<FloorTile>(x, y));
            if (c == '0'){
                row[x]->attachStuff(make_shared<RestorHP>());
            } else if (c == '1'){
                row[x]->attachStuff(make_shared<BoostAtk>());
            } else if (c == '2'){
                row[x]->attachStuff(make_shared<BoostDef>());
            } else if (c == '3'){
                row[x]->attachStuff(make_shared<PoisonHP>());
            } else if (c == '4'){
                row[x]->attachStuff(make_shared<WoundAtk>());
            } else if (c == '5'){
                row[x]->attachStuff(make_shared<WoundDef>());
            } else if (c == '6'){
                row[x]->attachStuff(make_shared<Treasure>(1));
            } else if (c == '7'){
                row[x]->attachStuff(make_shared<Treasure>(2));
            } else if (c == '8'){
                row[x]->attachStuff(make_shared<Treasure>(4));
            } else if (c == '9'){
                row[x]->attachStuff(make_shared<Treasure>(6));
            } else if (c == 'W'){
                row[x]->attachStuff(make_shared<Werewolf>());
            } else if (c == 'V'){
                row[x]->attachStuff(make_shared<Vampire>());
            } else if (c == 'N'){
                row[x]->attachStuff(make_shared<Goblin>());
            } else if (c == 'T'){
                row[x]->attachStuff(make_shared<Troll>());
            } else if (c == 'X'){
                row[x]->attachStuff(make_shared<Phoenix>());
            } else if (c == 'M'){
                row[x]->attachStuff(make_shared<Merchant>());
            } else if (c == 'D'){
                row[x]->attachStuff(make_shared<Dragon>());
            } else if (c == '@'){
                // 记下Player位置
            } else if (c == '\\'){
                row[x]->attachStuff(make_shared<Stair>());
            } else {
                
            }
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

shared_ptr<Cell> Floor::getCellPC() {
    for (auto cur : floorTiles) {
        if (cur->getOccupant()->getType() == Type::Plyr) {
            return cur;
        }
    }
    return nullptr;
}

void Floor::playerMove(std::string direction) {
    int curX = getCellPC()->getX();
    int curY = getCellPC()->getY();
    std::shared_ptr<Cell> targetCell = target(getCellPC(), direction);
    int targetX = targetCell->getX();
    int targetY = targetCell->getY();
    if (targetCell->checkOccupancy()) return;
    std::shared_ptr<Stuff> s = theGrid[curX][curY]->detachStuff();
    theGrid[targetX][targetY]->attachStuff(pc);
    checkEvents();
}

bool isClose(std::shared_ptr<Cell> c1, std::shared_ptr<Cell> c2) {
    if (std::abs(c1->getX() - c2->getX()) <= 1 && std::abs(c1->getY() - c2->getY()) <= 1) return true;
    else return false;
}

bool Floor::checkEvents() {
    if (pc->isDead()) return true;
    if (getCellPC()->getOccupant()->getType() == Type::Str) return false;
    if (getCellPC()->getOccupant()->getType() == Type::Trsr) {
        getCellPC()->getOccupant()->effect(pc);
    }
    if (getCellPC()->getOccupant()->getChar() == 'C') {
        for (auto current : floorTiles) {
            if (current->getOccupant()->getType() == Type::Str) {
                current->getOccupant()->enableDisplay();
                break;
            }
        }
    }
    for (auto cur : floorTiles) {
        if(cur->getOccupant()->getType() == Type::Enmy) {
            shared_ptr<Stuff> e = cur->getOccupant();
            if(!e->isDead() && isClose(cur, getCellPC())) {
                pc->beAttacked(e);
                if (pc->isDead()) return true;
            } else if(e->isDead()) {
                if (e->getChar() == 'M') {
                    cur->attachStuff(make_shared<Treasure>(3));
                    cur->setOccupancy(false);
                } else if (e->getChar() == 'D') {
                    continue;
                } else {
                    pc->setTreasure(pc->getTreasure() + 1);
                }
                if (e->checkCompass()) {
                    shared_ptr<Compass> c = make_shared<Compass>();
                    cur->attachStuff(c);
                    cur->setOccupancy(false);
                }
            }
        } 
    }
    return false;
}

void Floor::playerAtk(std::string direction) {
    shared_ptr<Cell> targetCell = target(getCellPC(), direction);
    if (targetCell->getOccupant()->getType() != Type::Enmy) return;
    targetCell->getOccupant()->beAttacked(pc);
    checkEvents();
    pc->beAttacked(targetCell->getOccupant());
    checkEvents();
}

string getDirection(shared_ptr<Cell> c1, shared_ptr<Cell> c2) {
    int x1 = c1->getX();
    int y1 = c1->getY();
    int x2 = c2->getX();
    int y2 = c2->getY();
    if (x1 == x2) {
        if (y2 == y1 + 1) return "S";
        else if (y2 == y1 - 1) return "N";
    } else if (x2 == x1 + 1) {
        if (y2 == y1) return "E";
        else if (y2 == y1 + 1) return "SE";
        else return "NE";
    } else {
        if (y2 == y1) return "W";
        else if (y2 == y1 + 1) return "SW";
        else return "NW";
    }
    return "";
}
void Floor::playerUse(std::string direction) {
    shared_ptr<Cell> targetCell = target(getCellPC(), direction);
    if (targetCell->getOccupant()->getType() == Type::Ptn) {
        targetCell->getOccupant()->effect(pc);
    } else if (targetCell->getOccupant()->getType() == Type::Trsr) {
        if (targetCell->getOccupant()->isDragonHoard()) return;
        else {
            targetCell->getOccupant()->effect(pc);
            playerMove(getDirection(getCellPC(), targetCell));
        }
    } else return;
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
                if (col->getOccupant()->getMoved()) continue;
                vector<shared_ptr<Cell>> validMove;
                string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
                for (int i = 0; i < 8; ++i) {
                   if (target(col, directions[i])->checkOccupancy()) validMove.emplace_back(target(col, directions[i]));
                } 
                srand(time(nullptr));
                int index = rand() % validMove.size();
                shared_ptr<Cell> des = validMove[index];
                theGrid[des->getX()][des->getY()]->attachStuff(theGrid[col->getX()][col->getY()]->detachStuff());
                des->getOccupant()->toggleMoved();
            }
        }
    }
}

bool Floor::setCell(shared_ptr<Cell> c, shared_ptr<Stuff> s) {
    int x = c->getX();
    int y = c->getY();
    if (c->checkOccupancy()) return false;
    theGrid[x][y]->attachStuff(s);
    if (s->getType() == Type::Trsr || s->getType() == Type::Str || s->getChar() == 'c') {
        theGrid[x][y]->setOccupancy(false); // lets the user step on
    }
    return true;
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

