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


private: //functions

    string arrayPosToString(int x, int y, int xDes, int yDes);

    vector<string> KingMoves(int yPos,int xPos);

private: // values


    bool ischeck = false;
    bool ischeckmate = false;
    array<array<unique_ptr<Piece>,8>,8> board;
};


#endif //CHESS_BOARD_H
