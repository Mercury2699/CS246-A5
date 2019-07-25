#include <fstream>
#include <sstream>
#include "floor.h"
#include "emptyCell.h"
#include "doorway.h"
#include "floorTile.h"
#include "wall.h"
#include "passage.h"


using namespace std;

Floor::Floor(std::string file){
    ifstream m(file);
    char c;
    int x, y;
    vector<Cell> row;
    while (m.get(c)){
        if(c == '\n'){
            theGrid.emplace_back(row);
            row.clear();
            x = 0;
            y++;
        } else if (c == ' ') {
            row.emplace_back(std::make_shared<Cell>(new EmptyCell(x, y)));
        } else if (c == '-') {
            row.emplace_back(std::make_shared<Cell>(new Wall(x, y, true)));
        } else if (c == '|') {
            row.emplace_back(std::make_shared<Cell>(new Wall(x, y, false)));
        } else if (c == '+') {
            row.emplace_back(std::make_shared<Cell>(new Doorway(x, y)));
        } else if (c == '#') {
            row.emplace_back(std::make_shared<Cell>(new Passage(x, y)));
        } else {
            std::shared_ptr<Cell> cur1 = std::make_shared<Cell>Cell(new FloorTile(x ,y));
            row.emplace_back(cur);
            std::shared_ptr<Cell> cur2 = cur1;
            floorTiles.emplace_back(cur2);
            std::shared_ptr<Cell> cur3 = cur1;
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
    int targetX = targetY = 0;
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
    int curX = pc->getX();
    int curY = pc->getY();
    std::shared_ptr<Cell> targetCell = target(theGrid[curX][curY], direction);
    int targetX = targetCell->getX();
    int targetY = targetCell->getY();
    if (targetCell->checkOccupancy()) return;
    theGrid[curX][curY]->setOccupant(nullptr);
    theGrid[curX][curY]->setOccupancy(false);
    pc->setCell(theGrid[targetX][targetY]);
    theGrid[targetX][targetY]->setOccupant(pc);
    theGrid[targetX][targetY]->notifyObserver();
    checkEvents(theGrid[targetX][targetY]);
}

bool isClose(std::shared_ptr<Cell> c1, std::shared_ptr<Cell> c2) {
    if (std::abs(c1->getX() - c2->getX()) <= 1 && std::abs(c1->getY() - c2->getY()) <= 1) return true;
    else return false;
}

bool Floor::checkEvents(std::shared_ptr<Cell> cur) {
    if (pc->isDead()) return true;
    if (cur->getOccupant()->getType() == Type::Stair) return false;
    for (auto cur : floorTiles) {
        if(cur->getOccupant()->getType() == Type::Enmy) {
            Enemy *e = std::static_cast<Enemy*>(cur->getOccupant());
            if(!e->isDead() && isClose(cur, pc->getCell())) {
                pc->beAttacked(e);
                if (pc->isDead()) return true;
            } else if(e->isDead()) {
                pc->setTreasure(pc->getTreasure() + 1);
                if (e->hasCompass()) {
                    for (auto current : floorTiles) {
                        if (current->getOccupant()->getType == Type::Stair) {
                            Stair *s = std::static_cast<Stair*>(current->getOccupant());
                            s->setDisplay(true);
                            break;
                        }
                    }
                }
            } else continue;
        } else if (cur->getOccupant()->getType == Type::Trsr) {
            Treasure *t = std::static_cast<Treasure*>(cur->getOccupant());
            t->effect(pc);
        }
    }
    return false;
}

void Floor::playerAtk(std::string direction) {
    std::shared_ptr<Cell>
}