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
    if (y <= theDisplay.size()){
        if (x <= theDisplay[y].size())
            theDisplay[y][x] = type;
    }
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
    clear();
    for (unsigned int i = 0; i < td.theDisplay.size(); ++i){
        for (unsigned int j = 0; j < td.theDisplay[i].size(); ++j){
            mvaddch(i, j, td.theDisplay[i][j]);
            refresh();
        }
    }
    move(25, 0);
    stringstream s;
    s << "Race: " << td.pc->getRace() << " Gold: " << td.pc->getTreasure() << endl;
    move(26, 0);
    clrtoeol();
    mvprintw(26, 0, "%s", s.str().c_str());
    s.str("");
    s << "HP: " << td.pc->getHP() << endl;
    move(27, 0);
    clrtoeol();
    mvprintw(27, 0, "%s", s.str().c_str());
    s.str("");
    s << "Atk: " << td.pc->getAtk() << endl;
    move(28, 0);
    clrtoeol();
    mvprintw(28, 0, "%s", s.str().c_str());
    s.str("");
    s << "Def: " << td.pc->getDef() << endl;
    move(29, 0);
    clrtoeol();
    mvprintw(29, 0, "%s", s.str().c_str());
    s.str("");
    s << "Action: " << td.action << endl;
    move(30, 0);
    clrtoeol();
    mvprintw(30, 0, "%s", s.str().c_str());
    
    return out;
}


