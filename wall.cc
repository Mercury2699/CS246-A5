#include "wall.h"

Wall::Wall(TextDisplay * td, int x, int y, bool isHor):
    Cell{td, x, y}, isHorizontal{isHor} {}

char Wall::getState(){
    if (isHorizontal) return '-';
    return '|';
}








