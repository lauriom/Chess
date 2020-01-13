//
// Created by Lauri on 11/01/2020.
//

#ifndef CHESS_GAMESAVE_H
#define CHESS_GAMESAVE_H
using namespace std;

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

class GameSave {
public:
    void saveGame(const vector <string> &v);
    vector<string> loadGame();

};


#endif //CHESS_GAMESAVE_H
