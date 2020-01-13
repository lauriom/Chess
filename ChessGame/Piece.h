//
// Created by Lauri on 22/12/2019.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H


#define king 0
#define queen 1
#define rook 2
#define knight 3
#define bishop 4
#define pawn 5

#include <iostream>
#include <string>

class Piece {
public:
Piece(bool iswhite);
bool isPieceWhite();
std::string getName();
int getID();

private:
    bool isWhite;
protected:
    int id;
    std::string name;
};


#endif //CHESS_PIECE_H
