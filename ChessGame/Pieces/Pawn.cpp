//
// Created by Lauri on 10/01/2020.
//

#include "Pawn.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) {
    id = pawn;
    name = ("bP");  // initialized to black
    if(isPieceWhite()){ // sets to White
        name[0] = 'w';
    }
}
