#include "floorTile.h"

FloorTile::FloorTile(int x, int y) {
    this->x = x;
    this->y = y;
}

bool FloorTile::checkOccupancy(){
    return (isOccupied && occupant);
}

void FloorTile::setObserver(TextDisplay * td){
    this->td = td;
}

void FloorTile::notifyObserver(){
    td->notify(x,y,getChar());
}

Stuff * FloorTile::getOccupant(){
    return occupant;
}

char FloorTile::getChar() {
    if(checkOccupancy())
        return getOccupant()->getChar();
    return '.';
}

