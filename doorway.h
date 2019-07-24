#ifndef DOORWAY_H
#define DOORWAY_H
#include "cell.h"


class Doorway final : protected Cell {
    public:
    Doorway(int x, int y);
    char getChar() override;
};

#endif



