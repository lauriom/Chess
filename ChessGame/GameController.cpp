//
// Created by Lauri on 22/12/2019.
//

#include "GameController.h"



GameController::GameController() {
    board = std::make_unique<Board>();
}

/**
 *  prints instructions and starts game
 */
void GameController::startGame() {
    cout << "\n\nStarting new game\n"
            "input is expected in XY XY\n"
            "where first XY is piece to move and second XY is destination (example: a2 a3)\n"
            "Type help to list all commands, save to save board state, exit to leave" << endl;

    playGame();
}

/**
 * loads game from save.txt,
 * goes trough evey move and starts game from previous state
 */
void GameController::resumeGame() {
    unique_ptr<SaveLoad> save{new SaveLoad};

    moveHistory = save->loadGame();

    int yStart, xStart, yEnd, xEnd;

    if(moveHistory.empty()){
        cout << "No save file found"<< endl;
        return;
    }


    for (auto &s : moveHistory) {
        cout << s << endl;
        if (!(isalpha(s[0]) && isdigit(s[1]) && isalpha(s[3]) && isdigit(s[4]))) {
            cerr << "Save corrupted.\n"
                    "Please start new Game" << endl;
            save->deleteGame();
            return;
        }
        // converts ascii number/char to array positions
        xStart = s[0] - 65;
        yStart = 56 - s[1];
        xEnd = s[3] - 65;
        yEnd = 56 - s[4];

        board->movePiece(xStart, yStart, xEnd, yEnd);
        whiteTurn = !whiteTurn;

    }
    playGame();
}

void GameController::playGame() {
    board->printBoard();
    cout << (whiteTurn ? "White moves" : "Black moves") << endl;

    while (userInput() && !board->isCheckMate()) { // loops untill checkmate is triggered or user inputs exit
        board->printBoard();
        cout << (whiteTurn ? "White moves" : "Black moves") << endl;

    }

    // ends game
    // goes back to main
}

/**
 * Handles userinput during game.
 * @return false if exit is inputted, else true
 */
bool GameController::userInput() {
    int yStart, xStart, yEnd, xEnd;

    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);


    if (!userInput2(s)) { return false; } // cut up the function, handles the extra commands

    while (!(isalpha(s[0]) && isdigit(s[1]) && isspace(s[2]) && isalpha(s[3]) && isdigit(s[4]))) {
        cout << "input is expected in 'XY XY'\n"
                "where first XY is piece to move and second XY is destination (example: 'a2 a3')" << endl;
        getline(cin, s);

        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (!userInput2(s)) { return false; }
    }
    bool validMoveFound = false;
    for (const auto& s2 : board->possibleMoves(whiteTurn)) {
        if (s == s2) {
            validMoveFound = true;
        }
    }
    if (validMoveFound) {
        cout << "Great move!" << endl;
        xStart = s[0] - 65;
        yStart = 56 - s[1];
        xEnd = s[3] - 65;
        yEnd = 56 - s[4];

        board->movePiece(xStart, yStart, xEnd, yEnd);
        moveHistory.push_back(s);
        whiteTurn = !whiteTurn; // successful move swapping player

    } else {
        cout << "Illegal move\n"
                "type 'list' to view legal moves" << endl;
        // returns without swapping player turn
    }

    return true;

}

/**
 * checks user input for special commands
 * @param s userinput
 * @return false if exit is inputted, else true
 */
bool GameController::userInput2(const string& s) {
    if (s.find("SAVE") != std::string::npos) {
        SaveLoad gameSave;
        gameSave.saveGame(moveHistory);
        cout << "Game Saved\n\n" <<endl;
    } else if (s.find("HELP") != std::string::npos) {
        cout << "commands:\n"
                "'save' to save game\n"
                "'list' to list legal available moves\n"
                "'exit' to exit without saving" << endl;
    } else if (s.find("LIST") != std::string::npos) {
        cout << "printing list" << endl;
        for (const auto &move : board->possibleMoves(whiteTurn)) {
            cout << move << endl;
        }
    } else if (s.find("EXIT") != std::string::npos) {
        return false;
    }
    return true;
}

