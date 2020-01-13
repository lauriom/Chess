//
// Created by Lauri on 22/12/2019.
//

#include "GameController.h"



GameController::GameController() {
    board = std::make_unique<Board> ();
}

void GameController::startGame() {
    cout << "\n\nStarting new game\n"
            "input is expected in XY XY\n"
            "where first XY is piece to move and second XY is destination (example: a2 a3)\n"
            "Type help to list all commands, save to save board state, exit to leave" <<endl;

    playGame();
}

/*
 * resumes saved game by passing all moves to board
 */
void GameController::resumeGame() {
    int yStart,xStart ,yEnd, xEnd;
    for (auto s : moveHistory) {
        yStart = s[0] - 16;
        xStart = s[1] - 16;
        yEnd = s[3] - 16;
        xEnd = s[4] - 16;
        board->movePiece(yStart, xStart, yEnd, xEnd);
        whiteTurn = !whiteTurn;
    }
    playGame();
}

void GameController::playGame() {
    board->printBoard();
    cout << (whiteTurn ? "White moves" : "Black moves") << endl;

    while(userInput() || !board->isCheckMate()) { // loops untill checkmate is triggered or user inputs exit
        cout << (whiteTurn ? "White moves" : "Black moves") << endl;
        board->printBoard();
    }

    // ends game
   // goes back to main
}


bool GameController::userInput() {
    int yStart,xStart ,yEnd, xEnd;

    string s;
    getline(cin,s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);


    if(!userInput2(s)) { return false;} // cut up the function, handles the extra commands

        while (!(isalpha(s[0]) && isdigit(s[1]) && isspace(s[2]) && isalpha(s[3]) && isdigit(s[4]))) {
            cout << "input is expected in 'XY XY'\n"
                    "where first XY is piece to move and second XY is destination (example: 'a2 a3')" << endl;
            getline(cin, s);

            transform(s.begin(), s.end(), s.begin(), ::toupper);
            if(!userInput2(s)) { return false;}
        }
        bool validMoveFound = false;
        for(auto s2 : board->possibleMoves(whiteTurn)){
            if(s == s2){
                validMoveFound = true;
            }
        }
        if(validMoveFound) {
            cout << "Great move!" <<endl;
            yStart = s[0] - 65;
            xStart = s[1] - 49;
            yEnd = s[3] - 65;
            xEnd = s[4] - 49;
            cout << "VALIDMOVE DEBUG " <<yStart <<endl;
            board->movePiece(xStart,yStart ,xEnd, yEnd);
            moveHistory.push_back(s);
            whiteTurn = !whiteTurn; // successful move swapping player
        } else {
            cout << "Illegal move\n"
                    "type 'list' to view legal moves" << endl;
            // returns without swapping player turn
        }

        return true;

}

bool GameController::userInput2(string s) {
    if (s.find("SAVE") != std::string::npos) {
        GameSave gameSave;
        gameSave.saveGame(moveHistory);
    }
    else if (s.find("HELP") != std::string::npos) {
        cout << "commands:\n"
                "'save' to save game\n"
                "'list' to list legal available moves\n"
                "'exit' to exit without saving" << endl;
    } else if(s.find("LIST")!= std::string::npos){
        cout <<"printing list" << endl;
        for (auto move : board->possibleMoves(whiteTurn)){
            cout << move << endl;
        }
    }
    else if(s.find("EXIT") != std::string::npos) {
        return false;
    }
    return true;
}

