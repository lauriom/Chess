//
// Created by Lauri on 22/12/2019.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <iostream>
#include <array>
#include "Piece.h"
#include <memory>

using  namespace  std;
class Board {
public:
    Board(){
        int i  =  10;
        for (auto &row : board){
            for (auto & elem : row){
                elem = unique_ptr<Piece>(new Piece(i++));
            }
        }
    };
private:
    array<array<unique_ptr<Piece>,8>,8> board;
};


#endif //CHESS_BOARD_H
