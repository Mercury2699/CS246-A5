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
            row.emplace_back(new EmptyCell(x, y));
        } else if (c == '-') {
            row.emplace_back(new Wall(x, y, true));
        } else if (c == '|') {
            row.emplace_back(new Wall(x, y, false));
        } else if (c == '+') {
            row.emplace_back(new Doorway(x, y));
        } else if (c == '#') {
            row.emplace_back(new Passage(x, y));
        } else if (c == '.') {
            row.emplace_back(new FloorTile(x ,y));
        }
        x++;
    }
    m.close();
}

void setObserver(TextDisplay *td) {
    this->td = td;
}

Cell *Floor::target(Cell *cur, std::string direction) {
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
    return theGrid[targetX][targetY].get();
}
void Floor::playerMove(std::string direction) {
    int curX = pc->getX();
    int curY = pc->getY();
    Cell *targetCell = target(theGrid[curX][curY].get(), direction);
    int targetX = targetCell->getX();
    int targetY = targetCell->getY();
    if (targetCell->checkOccupancy()) return;
    theGrid[curX][curY].get()->setOccupant(nullptr);
    theGrid[curX][curY].get()->setOccupancy(false);
    pc->setPosn(targetX, targetY);
    theGrid[targetX][targetY].get()->setOccupant(pc);
    theGrid[targetX][targetY].get()->notifyObserver();
    checkEvents(theGrid[targetX][targetY].get());
}

bool isClose(Cell *c1, Cell *c2) {
    if (std::abs(c1->getX() - c2->getX()) <= 1 && std::abs(c1->getY() - c2->getY()) <= 1) return true;
    else return false;
}

void Floor::checkEvents(Cell *c) {
    for (auto cur : enemies) {
        if(isClose(cur.get(), c)) pc->beAttacked(cur.get()->getOccupant());
    }
}

void playerAtk(std::string direction) {
}














