//
// Created by Lauri on 10/01/2020.
//

#include "Bishop.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite) {
    id = bishop;
    name = ("bB");  // initialized to black
    if(isPieceWhite()){ // sets to White
        name[0] = 'w';
    }
}

