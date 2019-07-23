#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "cell.h"

struct EmptyCell final : private Cell {
    EmptyCell(int x, int y) {
        this->x = x;
        this->y = y;
    }
    char getChar() override {return ' ';};
};

#endif

