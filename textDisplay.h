#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include <memory>
#include <string>

class Player;

class TextDisplay {
    std::vector<std::vector<char>> theDisplay;
    Player * pc;
    std::string action = "";
    
    public:
    TextDisplay(std::string map = "map.txt");
    void notify(int x, int y, char type);
    void addAction(std::string);
    void setPC(Player *);
    void clearAction();
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &);
};

#endif
