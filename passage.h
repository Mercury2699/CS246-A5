#ifndef PASS_H
#define PASS_H
#include "cell.h"
#include "stuff.h"

class TextDisplay;

class Passage final : protected Cell {
    public:
    Passage(int x, int y);
    char getChar() override;
};

#endif

