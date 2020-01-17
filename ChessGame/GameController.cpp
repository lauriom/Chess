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
void GameController::loadGame() {

    unique_ptr<vector<string>> tempHist = SaveLoad::loadGame();

    if (tempHist->empty()) { // checks if file is empty/exists
        cerr << "No save file found" << endl;
        return;
    }

    for (auto s : *tempHist) {
        if (!(isalpha(s[0]) && isdigit(s[1]) && isalpha(s[3]) && isdigit(s[4]))) {// check's format
            cerr << "Save corrupted.\n"
                    "Please start new Game" << endl;
            SaveLoad::deleteGame();
            return;
        }
        doMove(s); // moves pieces
    }
    playGame(); // startGame
}
/**
 * controls flow of game
 */
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
 * @param move ammount to go back
 */
void GameController::undoMove(int move) {
    if (move == 0) {
        return;
    }
    for (int i = 0; i < move; i++) {
        moveHistory.pop_back(); // removes moves from vectors endd
    }
    board = std::make_unique<Board>(); // creates new board
    for (auto &m : moveHistory) {
        doMove(m);
    }
}

/**
 * Handles userinput during game.
 * @return false if exit is inputted, else true
 */
bool GameController::userInput() {

    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);


    if (!userInput2(s)) { return false; } // cut up the function, handles the extra commands

    while (!(isalpha(s[0]) && isdigit(s[1]) && isspace(s[2]) && isalpha(s[3]) && isdigit(s[4]) &&
             s.size() <= 5)) { // checks that user input is acceptable
        cout << "input is expected in 'XY XY'\n"
                "where first XY is piece to move and second XY is destination (example: 'a2 a3')" << endl;
        getline(cin, s);

        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (!userInput2(s)) { return false; }
    }

    for (const auto &s2 : board->possibleMoves(whiteTurn)) {
        if (s == s2) { // goes trough array and does a string comparison to find if moves are valid
            doMove(s);
            return true;
        }
    }
    cout << "Illegal move\n"
            "type 'list' to view legal moves" << endl;
    return true;
}

/**
 * checks user input for special commands
 * @param s userinput
 * @return false if exit is inputted, else true
 */
bool GameController::userInput2(const string &s) {
    if (s.find("SAVE") != std::string::npos) {
        SaveLoad::saveGame(moveHistory);
        cout << "Game Saved\n\n" << endl;
    } else if (s == "HELP") {
        cout << "commands:\n"
                "'save' to save game\n"
                "'list' to list legal available moves\n"
                "'undo x' to undo last x moves\n"
                "'exit' to exit without saving" << endl;
    } else if (s == "LIST") {
        cout << "printing list" << endl;
        for (const auto &move : board->possibleMoves(whiteTurn)) {
            cout << move << endl;
        }
    } else if ((s.find("UNDO") != std::string::npos)) {
        int i = s[5] - 48;
        if (i < moveHistory.size() && i > 0 && i < 10) {
            undoMove(i);
            board->printBoard();
        } else {
            cout << "Incorrect format for 'undo' command\n"
                    "Format is 'undo x' where x is a number\n"
                    "between 1-9, and smaller than total moves of match" << endl;
        }
    } else if (s == "EXIT") {
        return false;
    }
    return true;
}

/**
 * transforms char's into ints to use in array,
 * x and y are flipped between doMove and movePiece [x][y] -> [y][x]
 * @param s string of users input in acceptable format
 */
void GameController::doMove(string s) {
    int yStart, xStart, yEnd, xEnd;
    xStart = s[0] - 65;
    yStart = 56 - s[1];
    xEnd = s[3] - 65;
    yEnd = 56 - s[4];

    board->movePiece(xStart, yStart, xEnd, yEnd);
    moveHistory.push_back(s);
    whiteTurn = !whiteTurn; // swaps player
}



