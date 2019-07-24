#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <memory>
#include <string>
// #include "floor.h"

class Player;

class TextDisplay {
    std::vector<std::vector<char>> theDisplay;
    std::shared_ptr<Player> pc;
    std::string action = "";

    public:
    TextDisplay(std::string map = "map.txt");
    void notify(int x, int y, char type);
    // friend std::ostream &operator<<(std::ostream &out, const Floor &);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &);
};

#endif
