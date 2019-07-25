#include "floorTile.h"

FloorTile::FloorTile(int x, int y):
    Cell{x, y}{}

char FloorTile::getChar() const {
    if(checkOccupancy())
        return getOccupant()->getChar();
    return '.';
}

bool FloorTile::checkOccupancy() const {
    if (getOccupant() == nullptr) return false;
    else if (getOccupant()->getType() == Type::Trsr || getOccupant()->getChar() == 'B' ||
    getOccupant()->getType() == Type::Stair ) return false;
    else return true;
}

