//
// Created by Lauri on 22/12/2019.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H


#include "PieceIDs.h"

#include <iostream>
#include <string>

class Piece {
public:
Piece(int id,bool iswhite);
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
