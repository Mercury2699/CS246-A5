#include "wall.h"

Wall::Wall(int x, int y, bool isHor):
    Cell{x, y}, isHorizontal{isHor} {}

char Wall::getState(){
    if (isHorizontal) return '-';
    return '|';
}








