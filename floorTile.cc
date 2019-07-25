#include "floorTile.h"

FloorTile::FloorTile(int x, int y):
    Cell{x, y}{}

char FloorTile::getChar() const {
    if(occupant)
        return occupant->getChar();
    return '.';
}

bool FloorTile::checkOccupancy() const {
	return isOccupied; 
}

