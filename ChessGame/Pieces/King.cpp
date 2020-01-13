//
// Created by Lauri on 10/01/2020.
//

#include "King.h"

King::King(bool isWhite) : Piece(isWhite) {
    id = king;
    name = ("bK");  // initialized to black
    if(isPieceWhite()){ // sets to White
        name[0] = 'w';
    }
}
