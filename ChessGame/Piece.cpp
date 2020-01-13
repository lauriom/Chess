//
// Created by Lauri on 22/12/2019.
//

#include "Piece.h"

Piece::Piece(bool iswhite) : isWhite(iswhite){
id = 7;
}

bool Piece::isPieceWhite() {
    return isWhite;
}

std::string Piece::getName() {
    return name;
}

int Piece::getID() {
    return id;
}




