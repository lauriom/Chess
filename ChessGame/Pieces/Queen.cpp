//
// Created by Lauri on 10/01/2020.
//

#include "Queen.h"

Queen::Queen(bool isWhite) : Piece(isWhite) {
    id = queen;
    name = ("bQ");  // initialized to black
    if(isPieceWhite()){ // sets to White
        name[0] = 'w';
    }
}
