#include <fstream>
#include <sstream>
#include "floor.h"
#include "emptyCell.h"
#include "doorway.h"
#include "floorTile.h"
#include "wall.h"
#include "passage.h"

using namespace std;

void Floor::init(std::string file = "map.txt"){
    ifstream m(file);
    char c;
    int x, y;
    vector<Cell> row;
    while (m.get(c)){
        if(c == '\n'){
            cells.emplace_back(row);
            row.clear();
            x = 0;
            y++;
        } else if (c == ' ') {
            row.emplace_back(EmptyCell(td, x, y));
        } else if (c == '-') {
            row.emplace_back(Wall(td, x, y, true));
        } else if (c == '|') {
            row.emplace_back(Wall(td, x, y, false));
        } else if (c == '+') {
            row.emplace_back(c);
        } else if (c == '#') {
            row.emplace_back(c);
        } else if (c == '.') {
            row.emplace_back(c);
        }
        x++;
    }
    m.close();
}














