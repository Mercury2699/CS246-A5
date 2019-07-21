#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "cell.h"

struct EmptyCell : public Cell {
    EmptyCell(TextDisplay *, int, int);
    char getState() override;
};

#endif

