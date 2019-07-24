#ifndef FLOORTILE_H
#define FLOORTILE_H
#include "cell.h"
#include "stuff.h"

class TextDisplay;


class FloorTile final : protected Cell {
    public:
    FloorTile(int x, int y);
    char getChar() override;
};

#endif

