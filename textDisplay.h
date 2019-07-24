#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include "floor.h"

using std::vector;
using std::shared_ptr;
using std::string;
using std::ostream;

class Player;

class TextDisplay {
    vector<vector<char>> theDisplay;
    shared_ptr<Player> pc;
    string action = "";

    public:
    TextDisplay(string map = "map.txt");
    void notify(int x, int y, char type);
    friend ostream &operator<<(ostream &out, const Floor &);
    friend ostream &operator<<(ostream &out, const TextDisplay &);
};

#endif
