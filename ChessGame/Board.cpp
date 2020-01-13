#include "Board.h"

#include <memory>

Board::Board() {
   resetBoard();
}

void Board::printBoard() {
    cout << "    A  B  C  D  E  F  G  H" << endl;
    cout << "  --------------------------" << endl;

    int i = 8;
    for (auto &row : board) {
        cout << i << " |";
        for (auto &elem : row) {
            if (elem == nullptr){
                cout << "   ";
            }else {
                std::cout << elem->getName() << " ";
            }
        }
        cout << "|" << i-- << endl;
    }
    cout << "  --------------------------" << endl;
    cout << "    A  B  C  D  E  F  G  H" << endl;
}


/**
 * initializes board
 * unique ptr = operator resets() the pointer and assigns a new piece
 * for empty spaces just calls reset()
 */
void Board::resetBoard() {

    // creates black pieces
    board[0][0] = std::make_unique<Rook>( false);
    board[0][7] = std::make_unique<Rook>( false);

    board[0][1] = std::make_unique<Knight>(false);
    board[0][6] = std::make_unique<Knight>(false);

    board[0][2] = std::make_unique<Bishop>(false);
    board[0][5] = std::make_unique<Bishop>(false);

    board[0][3] = std::make_unique<Queen>(false);
    board[0][4] = std::make_unique<King>(false);


    for (auto &elem : board [1]){
       elem = std::make_unique<Pawn>( false);
    }

    //creates white pieces

    for (auto &elem : board [6]){
       elem = std::make_unique<Pawn>( true);
    }

    board[7][0] = std::make_unique<Rook>( true);
    board[7][7] = std::make_unique<Rook>( true);

    board[7][1] = std::make_unique<Knight>(true);
    board[7][6] = std::make_unique<Knight>(true);

    board[7][2] = std::make_unique<Bishop>(true);
    board[7][5] = std::make_unique<Bishop>(true);

    board[7][3] = std::make_unique<Queen>(true);
    board[7][4] = std::make_unique<King>(true);

}
/*
 * moves piece from start to end coordinates
 * assumes input is sanitized
 */
void Board::movePiece(int yStart, int xStart, int yEnd, int xEnd) {
    board[xEnd][yEnd] = move(board[xStart][yStart]);
}
/**
 * contains movement info for all pieces
 * @param isWhite 's turn
 * @return vector containing strigns containing valid  moves
 * TODO: split up switch into multiple functions, FINISH MOVES FOR PIECES
 */
vector<string> Board::possibleMoves(bool isWhite) {
    vector<string> moves;
    string temp;
    int xPos = 0, yPos = 0;
    if (!isCheck()) {
        for (auto &row : board) {
            for (auto &elem : row) {
                if (elem != nullptr) {
                    switch (elem->getID()) {
                        case king: // move case for king piece TODO: does moving cause check?
                            // king has a movement vector of 1 in all directions, loops check 3x3 grid and that it dosnt go out of bounds
                            for (int x = -1; x <= 1; x++){
                                    for (int y = -1; y <= 1; y++) {
                                        if (xPos+x >= 0 && xPos+x  <= 7 && yPos+y >= 0 && yPos+y  <= 7) {
                                            if((board[xPos+x][yPos+y].get() == nullptr)){ // TODO: fix
                                                // checks if space is empty, if yes can move there
                                                moves.push_back(arrayPosToString(xPos, yPos, xPos + x, yPos + y));
                                            }else if(board[xPos+x][yPos+y]->isPieceWhite() != elem->isPieceWhite()){ // check if contains own color
                                               moves.push_back(arrayPosToString(xPos, yPos, xPos + x, yPos + y));

                                            }
                                         }
                                    }
                            }

                            break;

                        case queen:

                            break;
                        case bishop:


                            break;
                        case knight:


                            break;
                        case rook:


                            break;
                        case pawn: // move case for pawn peice TODO: promotion, maybe? currently gets stuck when reaching end of map

                            if (elem->isPieceWhite()) {

                            }else{

                            }
                            break;
                    }
                }
                xPos++;
            }
            yPos++;
            xPos = 0;
        }
    } else{ // sees what moves resolve check, if none then sets checkmate

    }
    return moves;
}
/**
 *
 * @param x axis of source
 * @param y axis of source
 * @param xDes axis of destination
 * @param yDes axis of destination
 * @return string in format 'xy xy'
 */
string Board::arrayPosToString(int x, int y, int xDes, int yDes) {
    string s;
    //cout << x <<y<< xDes <<yDes << endl;
    s.push_back(x+65);
    s.push_back(y+49);
    s.push_back(' ');
    s.push_back(xDes+65);
    s.push_back(yDes+49);

    return s;
}

bool Board::isCheck() const {
    return ischeck;
}
bool Board::isCheckMate() const {
    return ischeckmate;
}




