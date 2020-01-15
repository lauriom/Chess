//
// Created by Lauri on 22/12/2019.
//

#ifndef CHESS_GAMECONTROLLER_H
#define CHESS_GAMECONTROLLER_H

using namespace std;

#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <algorithm>

#include "Board.h"
#include "Misc/SaveLoad.h"



class GameController {
public:
    GameController();

    void startGame();

    void resumeGame();

private:
    void playGame();

    bool userInput();

    bool userInput2(string s);

    unique_ptr<Board> board;
    bool whiteTurn = true;
    vector<string> moveHistory;

};


#endif //CHESS_GAMECONTROLLER_H
