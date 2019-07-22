#include <fstream>
#include <sstream>
#include "floor.h"
#include "emptyCell.h"
#include "doorway.h"
#include "floorTile.h"
#include "wall.h"
#include "passage.h"


using namespace std;

Floor::Floor() {
    for(int i = 0; i < 30; i++){
        vector<Cell> row;
        for(int j = 0; j < 79; j++){
            row.emplace_back(new EmptyCell(td, i, j));
        }
        theGrid.emplace_back(row);
        row.clear();
    }
}

void Floor::init(std::string file){
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
            row.emplace_back(new EmptyCell(td, x, y));
        } else if (c == '-') {
            row.emplace_back(new Wall(td, x, y, true));
        } else if (c == '|') {
            row.emplace_back(new Wall(td, x, y, false));
        } else if (c == '+') {
            row.emplace_back(new Doorway(td, x, y));
        } else if (c == '#') {
            row.emplace_back(new Passage(td, x, y));
        } else if (c == '.') {
            row.emplace_back(new FloorTile(td, x ,y));
        }
        x++;
    }
    m.close();
}














