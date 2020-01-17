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

    void loadGame();

private:
    void playGame();
    void doMove(string s);
    void undoMove(int move);

    bool userInput();
    bool userInput2(const string& s);

    bool whiteTurn = true;
    vector<string> moveHistory;
    unique_ptr<Board> board;

};


#endif //CHESS_GAMECONTROLLER_H
