#ifndef DOORWAY_H
#define DOORWAY_H
#include "cell.h"

class Doorway : public Cell {
    Doorway(TextDisplay * td, int x, int y) : Cell{td, x, y} {}

    char getState() override {
        return '+';
    }
};

#endif
