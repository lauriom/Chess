//
// Created by Lauri on 11/01/2020.
//

#include "GameSave.h"

void GameSave::saveGame(const vector <string>& v) {
    ofstream chessFile("save.txt");
    for(const auto& s : v){
        chessFile << s << endl;
    }

    chessFile.close();
}

vector <string> GameSave::loadGame() {
    vector<string> moves;
    string temp;
    ifstream chessFile("save.txt");
    if(chessFile) {
        while (getline(chessFile, temp)) {
            moves.push_back(temp);

        }
    }

    chessFile.close();
}
