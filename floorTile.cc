#include "floorTile.h"

FloorTile::FloorTile(int x, int y):
    Cell{x, y}{}

char FloorTile::getChar() const {
    if(checkOccupancy())
        return getOccupant()->getChar();
    return '.';
}

