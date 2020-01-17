//
// Created by Lauri on 11/01/2020.
//

#include <sstream>
#include "SaveLoad.h"

/**
 * @param v vector of strings to save
 */
void SaveLoad::saveGame(const vector<string> &v) {
    ofstream chessFile("save.txt");
    for (const auto &s : v) {
        chessFile << s << endl;
    }
    chessFile.close();
}

/**
 * loads moves from file, assumes file has not been tampered with
 * @return a vector of strings
 */
unique_ptr<vector<string>> SaveLoad::loadGame() {
    unique_ptr<vector<string>> moves = make_unique<vector<string>>();
    string temp;
    ifstream chessFile("save.txt");

    if (chessFile.is_open()) {
        std::string line;
        while (getline(chessFile, line)) {
            moves->push_back(line);
        }
        chessFile.close();
    }
    return moves;
}

void SaveLoad::deleteGame() {
    if (remove("save.txt") != 0)
        cerr << "Error deleting save" << endl;
    else
        cout << "File successfully deleted" << endl;
}
