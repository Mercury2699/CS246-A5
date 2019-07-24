#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "cell.h"

struct EmptyCell final : private Cell {
    EmptyCell(int x, int y):
        Cell{x, y}{}
    char getChar() override {return ' ';};
    bool checkOccupancy() override { return true; }
};

#endif

