#include <fstream>
#include <sstream>
#include "textDisplay.h"

using namespace std;

TextDisplay::TextDisplay(string map = "map.txt"){
    ifstream m(map);
    char c;
    vector<char> row;
    while (m.get(c)){
        if(c == '\n'){
            theDisplay.emplace_back(row);
            row.clear();
        } else {
            row.emplace_back(c);
        }
    }
    m.close();
}

void TextDisplay::notify(int x, int y, char type){
    theDisplay[x][y] = type;
}

ostream &operator<<(ostream & out, const TextDisplay & td){
    for (auto i : td.theDisplay){
        for (auto j : i){
            cout << j;
        }
        cout << endl;
    }
}







