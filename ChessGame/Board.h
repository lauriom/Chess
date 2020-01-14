//
// Created by Lauri on 22/12/2019.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <iostream>
#include <array>
#include <memory>
#include <vector>

#include "PieceIDs.h"
#include "Piece.h"


using  namespace  std;
class Board {
public:
    Board();
    void resetBoard();
    void printBoard();


    vector<string> possibleMoves(bool isWhite);
    void movePiece(int yStart, int xStart , int yEnd,int xEnd);

    bool isCheckMate() const;
    bool isCheck() const;


private:
    bool ischeck = false;
    bool ischeckmate = false;

    string arrayPosToString(int x, int y, int xDes, int yDes);

private:
    array<array<unique_ptr<Piece>,8>,8> board;


};


#endif //CHESS_BOARD_H
