//
// Created by Lauri on 22/12/2019.
//

#include "Piece.h"

/**
 * constructor for piece,
 * initializes name based on inputted parameters
 * @param id determines piece type
 * @param iswhite true/false
 */
Piece::Piece(int id, bool iswhite) : isWhite(iswhite), id(id) {
    switch (id) {
        case king:
            name = "bK";
            break;
        case queen:
            name = "bQ";
            break;
        case bishop:
            name = "bB";
            break;
        case knight:
            name = "bN";
            break;
        case rook:
            name = "bR";
            break;
        case pawn:
            name = "bP";
            break;
    }
    if (iswhite) { // sets piece color to white
        name[0] = 'w';
    }
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




