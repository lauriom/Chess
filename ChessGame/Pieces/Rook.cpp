//
// Created by Lauri on 10/01/2020.
//

#include "Rook.h"

Rook::Rook(bool isWhite) : Piece(isWhite) {
    id = rook;
    name = ("bR");  // initialized to black
    if(isPieceWhite()){ // sets to White
        name[0] = 'w';
    }
}
