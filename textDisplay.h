#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <string>
#include "floor.h"

using std::vector;

class TextDisplay {
    vector<vector<char>> theDisplay;
    public:
    TextDisplay(std::string map = "map.txt");
    void notify(int x, int y, char type);
    friend std::ostream &operator<<(std::ostream &out, const Floor &);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &);
};
#endif
