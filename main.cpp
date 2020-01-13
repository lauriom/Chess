#include <iostream>
using namespace std;

#include "ChessGame/GameController.h"


bool menu(){
    cout << "Press 1 to start the game" << endl;
    cout << "Press 2 to load the game" << endl;
    cout << "Press 4 to exit the game" << endl;
    unique_ptr<GameController> game{new GameController};

    string s;
    cin >> s;
    int i = s[0] - 48; // removes 48 from ascii chart vals so the number is itself


    cin.clear();
    switch (i){
        case 1:
            game->startGame();
            break;
        case 2:
            game->resumeGame();
            break;
        case 4:
            return false;
        default:
            cout << "Unknown command" << endl;
    }
    return true;
}
int main() {
    cout << "Welcome to Lauri's chess game" << endl;

    while (menu()){}

    return 0;
}