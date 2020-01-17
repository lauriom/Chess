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
#include <memory>

class SaveLoad {
public:
    static void saveGame(const vector<string> &v);
    static void deleteGame();
    static unique_ptr<vector<string>> loadGame();

};


#endif //CHESS_SAVELOAD_H
