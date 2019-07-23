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

void FloorTile::attachStuff(Stuff * s){
    isOccupied = true;
    occupant = s;
    notifyObserver();
}

Stuff* FloorTile::detachStuff(){
    Stuff * temp = occupant;
    isOccupied = false;
    occupant = nullptr;
    notifyObserver();
    return temp;
}

char FloorTile::getChar() {
    if(checkOccupancy())
        return getOccupant()->getChar();
    return '.';
}

