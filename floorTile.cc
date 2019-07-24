#include "floorTile.h"

FloorTile::FloorTile(int x, int y):
    Cell{x, y}{}

char FloorTile::getChar() {
    if(checkOccupancy())
        return getOccupant()->getChar();
    return '.';
}

