#ifndef PASS_H
#define PASS_H
#include "cell.h"

class Passage : public Cell {
    Passage(TextDisplay * td, int x, int y) : Cell{td,x,y} {}
};
#endif
