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
    void generateBoard();
    void printBoard();


    vector<string> possibleMoves(bool isWhiteTurn);
    void movePiece(int xStart, int yStart , int xEnd,int yEnd);

    bool isCheckMate() const;
    bool isCheck() const;


private:

    string arrayPosToString(int y, int x, int yDes, int xDes);

    bool ischeck = false;
    bool ischeckmate = false;
    array<array<unique_ptr<Piece>,8>,8> board;
    vector<string> bishopMove(int yPos,int xPos);
    vector<string> rookMove(int yPos, int xPos);
};


#endif //CHESS_BOARD_H
