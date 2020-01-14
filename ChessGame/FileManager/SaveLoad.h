//
// Created by Lauri on 11/01/2020.
//

#ifndef CHESS_SAVELOAD_H
#define CHESS_SAVELOAD_H
using namespace std;

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

class SaveLoad {
public:
    void saveGame(const vector<string> &v);
    void deleteGame();
    vector<string> loadGame();

};


#endif //CHESS_SAVELOAD_H
