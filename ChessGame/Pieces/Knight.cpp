//
// Created by Lauri on 10/01/2020.
//

#include "Knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite) {
    id = knight;
    name = ("bN");  // initialized to black
    if(isPieceWhite()){ // sets to White
        name[0] = 'w';
    }
}
