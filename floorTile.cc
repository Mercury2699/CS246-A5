#include "floorTile.h"

FloorTile::FloorTile(int x, int y):
    Cell{x, y}{}

char FloorTile::getChar() const {
    if(occupant)
        return occupant->getChar();
    return '.';
}

bool FloorTile::checkOccupancy(bool forEnemy) const {
    if(forEnemy) {
		if (occupant){
			return true;
		} else {
			return false;
		}
	}
	return isOccupied; 
}

