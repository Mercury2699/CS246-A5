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
// items
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


Floor::Floor(string file) : 
    chambers(5) {
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
            continue;
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
        } else if (c >= 65 && c <= 97) { // c is A-Z
            shared_ptr<FloorTile> cur1 = make_shared<FloorTile>(x ,y);
            row.emplace_back(cur1);
            shared_ptr<FloorTile> cur2 = cur1;
            floorTiles.emplace_back(cur2);
            shared_ptr<FloorTile> cur3 = cur1;
            if (c == 'A') chambers[0].emplace_back(cur3);
            else if (c == 'B') chambers[1].emplace_back(cur3);
            else if (c == 'C') chambers[2].emplace_back(cur3);
            else if (c == 'D') chambers[3].emplace_back(cur3);
            else chambers[4].emplace_back(cur3); // c == 'E'
        }
        x++;
    }
    m.close();
}

Floor::Floor(std::shared_ptr<Player> pc, ifstream &s) {
    this->pc = pc;
    vector<shared_ptr<Cell>> row;
    for (int y = 0; y < 25; ++y) {
        for (int x = 0; x < 80; ++x) {
            char c;
            s.get(c);
            if(c == '\n'){
                theGrid.emplace_back(row);
                row.clear();
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
                    row[x]->attachStuff(pc);
                } else if (c == '/'){
                    row[x]->attachStuff(make_shared<Stair>());
                }
            }
        }
    }
}

void Floor::setTD(std::shared_ptr<TextDisplay> t){
    this->td = t;
    for ( auto i : theGrid) {
        for ( auto j : i) {
            j->setObserver(t);
        }
    }
}

void Floor::setPC(std::shared_ptr<Player> p){
    this->pc = p;
}

void Floor::notifyObserver(){
    for ( auto i : theGrid) {
        for ( auto j : i) {
            j->notifyObserver();
        }
    }
} 

shared_ptr<Cell> Floor::target(shared_ptr<Cell> cur, string direction) {
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
    return theGrid[targetY][targetX];
}

shared_ptr<Cell> Floor::getCellPC() {
    for (auto i : theGrid) {
        for (auto j : i) { 
            if (j->getOccupant()) {
                if (j->getOccupant()->getType() == Type::Plyr) {
                    return j;
                }
            }
        }
    }
    return nullptr;
}

int Floor::playerMove(std::string direction) {
    std::shared_ptr<Cell> targetCell = target(getCellPC(), direction);
    if (targetCell->getChar() == '-' ||
        targetCell->getChar() == '|' ||
        targetCell->getChar() == ' '){
        td->addAction("PC hits the wall. ");
        return 3; // not successful move
    } else if (targetCell->checkOccupancy()) {
        if (targetCell->getOccupant()){
            if (targetCell->getOccupant()->getType() == Type::Trsr){
                playerUse(direction);
                return 0; // successful move and collected treasure
            } else if (targetCell->getOccupant()->getType() == Type::Str) {
                return 1; // next floor
            }
            stringstream s;
            s << "There is a " << targetCell->getOccupant()->getChar() << " in PC's way. ";
            td->addAction(s.str());
            return 3;
        }
    }
    std::shared_ptr<Stuff> s = getCellPC()->detachStuff();
    targetCell->attachStuff(pc);
    td->addAction("PC moves to " + direction + ". ");
    return 0;
}

bool isClose(std::shared_ptr<Cell> c1, std::shared_ptr<Cell> c2) {
    if (std::abs(c1->getX() - c2->getX()) <= 1 && std::abs(c1->getY() - c2->getY()) <= 1) return true;
    else return false;
}

void Floor::checkEvents() {
    vector<shared_ptr<Cell>> neighbours;
    string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
    for (int i = 0; i < 8; ++i) {
        neighbours.emplace_back(target(getCellPC(), directions[i]));
    }
    for (auto cur : neighbours) {
        if(cur->getOccupant()){
            std::stringstream s;
            if (cur->getOccupant()->isDragonHoard()) {
                for (auto i : neighbours) {
                    if (i->getOccupant()) {
                        if (i->getOccupant()->getChar() == 'D') {
                            std::shared_ptr<Stuff> e = i->getOccupant();
                            int miss = rand() % 2; // 0 or 1: Enemy has a 50% chance of missing.
                            if (!miss) {
                                pc->beAttacked(e);
                                double damage = ceil((100 / (100 + static_cast<double>(pc->getDef()))) * e->getAtk());
                                s << e->getChar() << " deals " << damage << " damages to PC. ";
                                td->addAction(s.str());
                            } else {
                                s << e->getChar() << " missed. ";
                                td->addAction(s.str());
                            }
                            break;
                        }
                    }
                }
            } else if(cur->getOccupant()->getType() == Type::Enmy) {
                shared_ptr<Stuff> e = cur->getOccupant();
                if(!e->isDead()) {
                    if (e->getChar() == 'D') continue;
                    // e->toggleMoved();
                    if (e->getChar() == 'M') {
                        if (!pc->hasKilledMerch()) continue;
                    }
                    int miss = rand() % 2; // 0 or 1: Enemy has a 50% chance of missing.
                        if (!miss) {
                            pc->beAttacked(e);
                            double damage = ceil((100 / (100 + static_cast<double>(pc->getDef()))) * e->getAtk());
                            s << e->getChar() << " deals " << damage << " damages to PC. ";
                            td->addAction(s.str());
                        } else {
                            s << e->getChar() << " missed. ";
                            td->addAction(s.str());
                        }
                    if (pc->isDead()) return;
                } else { // Some enemy died.
                    if (e->getChar() == 'M') { // Merchant Died
                        cur->detachStuff();
                        cur->attachStuff(make_shared<Treasure>(4));
                        td->addAction("PC has slained a Merchant. ");
                    } else if (e->getChar() == 'D') { // Dragon Died
                        string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
                        for (int i = 0; i < 8; ++i) {
                            if (target(cur, directions[i])->checkOccupancy()) {
                                if (target(cur, directions[i])->getOccupant()) {
                                    if (target(cur, directions[i])->getOccupant()->isDragonHoard()) {
                                        target(cur, directions[i])->getOccupant()->setCollect();
                                    }
                                }
                            }
                        }
                        td->addAction("Wow! PC has slained a Dragon! ");
                    } else {
                        pc->addTreasure(1);
                        s << "PC has slained a " << e->getChar() << ". ";
                        td->addAction(s.str());
                    }
                    if (e->checkCompass()) {
                        cur->detachStuff();
                        cur->attachStuff(make_shared<Compass>());
                    }
                    if (cur->checkOccupancy()) {
                        if (cur->getOccupant()->getType() == Type::Enmy) {
                            cur->detachStuff();
                        }
                    }
                }
            } 
        }
    }
}

void Floor::playerAtk(std::string direction) {
    shared_ptr<Cell> targetCell = target(getCellPC(), direction);
    shared_ptr<Stuff> e = targetCell->getOccupant();
    stringstream s;
    if (e) {
        if (e->getType() != Type::Enmy) {
            return td->addAction("PC cannot attack non-Enemy stuff! ");
        }
        e->beAttacked(pc);
        if (e->getChar() == 'M') {
            pc->setKilledMerch(true);
        }
        double damage = ceil((100 / (100 + static_cast<double>(e->getDef()))) * pc->getAtk());
        s << "PC deals " << damage << " damages to " << e->getChar() << ". " << std::endl;
        td->addAction(s.str());
    } else {
        td->addAction("PC cannot attack an Empty Cell! ");
    }
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
    if(targetCell->getOccupant()){
        if (targetCell->getOccupant()->getType() == Type::Ptn) {
            targetCell->getOccupant()->effect(pc);
            td->addAction("PC used a " + targetCell->getOccupant()->getName() + ". ");
             targetCell->detachStuff();
        } else if (targetCell->getOccupant()->getType() == Type::Trsr) {
            if (targetCell->getOccupant()->isDragonHoard()) {
                    return td->addAction("PC cannot take a DragonHoard without killing the Dragon! ");
            } else {
                td->addAction("PC collected a " + targetCell->getOccupant()->getName() + ". ");
                targetCell->detachStuff()->effect(pc);
            }
        } else if (targetCell->getOccupant()->getChar() == 'C') {
            targetCell->detachStuff();
            for (auto current : floorTiles) { // find the Stair
                if(current->getOccupant()){
                    if (current->getOccupant()->getType() == Type::Str) {
                        current->getOccupant()->enableDisplay();
                        td->addAction("PC found the compass. The stair is now visible.");
                        current->notifyObserver();
                        break;
                    }
                }
            }
        } else if (targetCell->getOccupant()->getChar() == 'B') {
            if (!targetCell->getOccupant()->isDragonHoard()) {
                targetCell->getOccupant()->effect(pc);
                targetCell->detachStuff();
                td->addAction("PC collected a Barrier Suit! ");
            } else {
                td->addAction("PC cannot collect a Barrier Suit without killing the Dragon! ");
            }
        }
        playerMove(getDirection(getCellPC(), targetCell));
    }
}

void Floor::moveEnemies() {
    for (auto row : theGrid) {
        for (auto col : row) {
            if (col->getOccupant()) {
                if (col->getOccupant()->getType() == Type::Enmy) {
                    // string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
                    // for (int i = 0; i < 8; ++i) {
                    //     if (target(col, directions[i])->getX() == getCellPC()->getX() &&
                    //     target(col, directions[i])->getY() == getCellPC()->getY()) {
                    //         col->getOccupant()->toggleMoved();
                    //     }
                    // }
                    if (isClose(col, getCellPC())) col->getOccupant()->toggleMoved();
                    if (col->getOccupant()->getMoved()) continue;
                    vector<shared_ptr<Cell>> validMove;
                    string directions[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
                    for (int i = 0; i < 8; ++i) {
                        if (!target(col, directions[i])->checkOccupancy() && target(col, directions[i])->getChar() != '+') validMove.emplace_back(target(col, directions[i]));
                    }
                    int index = rand() % validMove.size();
                    shared_ptr<Cell> des = validMove[index];
                    des->attachStuff(col->detachStuff());
                    des->getOccupant()->toggleMoved();
                }
            }
        }
    }
    for (auto row : theGrid) {
        for (auto col : row) {
            if (col->getOccupant()) {
                if (col->getOccupant()->getType() == Type::Enmy && col->getOccupant()->getChar() != 'D'
                && col->getOccupant()->getMoved()) {
                    col->getOccupant()->toggleMoved();
                }
            }
        }
    }
}

bool Floor::setCell(shared_ptr<Cell> c, shared_ptr<Stuff> s) {
    if (c->checkOccupancy()) return false;
    c->attachStuff(s);
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



