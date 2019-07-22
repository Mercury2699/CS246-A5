#ifndef PASS_H
#define PASS_H
#include "cell.h"

struct Passage : public Cell {
    Passage(TextDisplay * td, int x, int y) : Cell{td,x,y} {}
    char getState() override { return '#';}
};
#endif
