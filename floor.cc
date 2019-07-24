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

void Floor::playerMove(std::string direction) {
    int curX = pc->getX();
    int curY = pc->getY();
    int targetX, targetY = 0;
    if (direction == "N") {
        if (theGrid[curX][curY - 1].get()->checkOccupancy()) return;
        targetX = curX;
        targetY = curY - 1;
    } else if (direction == "S") {
        if (theGrid[curX][curY + 1].get()->checkOccupancy()) return;
        targetX = curX;
        targetY = curY + 1;
    } else if (direction == "E") {
        if (theGrid[curX + 1][curY].get()->checkOccupancy()) return;
        targetX = curX + 1;
        targetY = curY;
    } else if (direction == "W") {
        if (theGrid[curX - 1][curY].get()->checkOccupancy()) return;
        targetX = curX - 1;
        targetY = curY;
    } else if (direction == "NE") {
        if (theGrid[curX + 1][curY - 1].get()->checkOccupancy()) return;
        targetX = curX + 1;
        targetY = curY - 1;
    } else if (direction == "NW") {
        if (theGrid[curX - 1][curY - 1].get()->checkOccupancy()) return;
        targetX = curX - 1;
        targetY = curY - 1;
    } else if (direction == "SE") {
        if (theGrid[curX + 1][curY + 1].get()->checkOccupancy()) return;
        targetX = curX + 1;
        targetY = curY + 1;
    } else {
        if (theGrid[curX - 1][curY + 1].get()->checkOccupancy()) return;
        targetX = curX - 1;
        targetY = curY + 1;
    }
    theGrid[curX][curY].get()->setOccupant(nullptr);
    theGrid[curX][curY].get()->setOccupancy(false);
    pc->setPosn(targetX, targetY);
    theGrid[targetX][targetY].get()->setOccupant(pc);
    theGrid[targetX][targetY].get()->notifyObserver();
    checkEvents(targetX, targetY);
}














