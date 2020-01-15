//
// Created by Lauri on 11/01/2020.
//

#include <sstream>
#include "SaveLoad.h"

/**
 * @param v vector of strings to save
 */
void SaveLoad::saveGame(const vector <string> &v) {
    ofstream chessFile("save.txt");
    for (const auto &s : v) {
        chessFile << s << endl;
    }

    chessFile.close();
}
/**
 * loads
 * @return a vector of strings
 */
vector <string> SaveLoad::loadGame() {
    vector <string> moves;
    string temp;
    ifstream chessFile("save.txt");

    if (chessFile.is_open()) {
        std::string line;
        while (getline(chessFile, line)) {
            // using printf() in all tests for consistency
            moves.push_back(line);
        }
        chessFile.close();
    }
    return moves;
}

void SaveLoad::deleteGame() {
    if( remove( "save.txt" ) != 0 )
        perror( "Error deleting save" );
    else
        puts( "File successfully deleted" );
}
