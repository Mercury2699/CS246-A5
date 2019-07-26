#include <fstream>
#include <sstream>
#include "textDisplay.h"
#include "player.h"

using namespace std;

TextDisplay::TextDisplay(string map){
    ifstream m(map);
    char c;
    vector<char> row;
    while (m.get(c)){
        if(c == '\n'){
            theDisplay.emplace_back(row);
            row.clear();
        } else if (c >= 65 && c <= 97 ) {
            row.emplace_back('.');
        } else {
            row.emplace_back(c);
        }
    }
    m.close();
}

void TextDisplay::notify(int x, int y, char type){
    theDisplay[x][y] = type;
}

void TextDisplay::setPC(std::shared_ptr<Player> p){
    pc = p;
}

void TextDisplay::addAction(std::string a){
    action += a;
}

void TextDisplay::clearAction(){
    action = "";
}

ostream &operator<<(ostream & out, const TextDisplay & td){
    for (auto i : td.theDisplay){
        for (auto j : i){
            out << j;
        }
        out << endl;
    }
    out << "Race: " << td.pc->getRace() << " Gold: " << td.pc->getTreasure() << endl;
    out << "HP: " << td.pc->getHP() << endl;
    out << "Atk: " << td.pc->getAtk() << endl;
    out << "Def: " << td.pc->getDef() << endl;
    out << "Action: " << td.action << endl;
    return out;
}







