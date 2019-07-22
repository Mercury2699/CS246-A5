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
            row.emplace_back(new FloorTile(td, x ,y));
        }
        x++;
    }
    m.close();
}














