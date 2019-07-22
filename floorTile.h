#ifndef FLOORTILE_H
#define FLOORTILE_H
#include "cell.h"

struct FloorTile : public Cell {
    FloorTile(TextDisplay * td, int x, int y) : Cell{td, x, y} {}
    
    char getState() override {
        if(checkOccupancy())
            return getOccupant()->getState();
        return '.';
    }
};
#endif
