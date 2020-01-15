#include "Board.h"


Board::Board() {
    generateBoard();
}

/**
 * Prints chessboard with ascii  graphics
 */
void Board::printBoard() {
    cout << "    A  B  C  D  E  F  G  H" << endl;
    cout << "  --------------------------" << endl;

    int i = 8;
    for (auto &row : board) {
        cout << i << " |";
        for (auto &elem : row) {
            if (elem == nullptr) {
                cout << "   ";
            } else {
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
void Board::generateBoard() {

    // creates black pieces
    board[0][0] = std::make_unique<Piece>(rook, false);
    board[0][7] = std::make_unique<Piece>(rook, false);

    board[0][1] = std::make_unique<Piece>(knight, false);
    board[0][6] = std::make_unique<Piece>(knight, false);

    board[0][2] = std::make_unique<Piece>(bishop, false);
    board[0][5] = std::make_unique<Piece>(bishop, false);

    board[0][3] = std::make_unique<Piece>(queen, false);
    board[0][4] = std::make_unique<Piece>(king, false);


    for (auto &elem : board[1]) {
        elem = std::make_unique<Piece>(pawn, false);
    }

    //creates white pieces

    for (auto &elem : board[6]) {
        //elem = std::make_unique<Piece>(pawn, true);
    }

    board[7][0] = std::make_unique<Piece>(rook, true);
    board[7][7] = std::make_unique<Piece>(rook, true);

    board[7][1] = std::make_unique<Piece>(knight, true);
    board[7][6] = std::make_unique<Piece>(knight, true);

    board[7][2] = std::make_unique<Piece>(bishop, true);
    board[7][5] = std::make_unique<Piece>(bishop, true);

    board[7][3] = std::make_unique<Piece>(queen, true);
    board[7][4] = std::make_unique<Piece>(king, true);

}

/**
 * moves piece,
 * flips the values from xy to yx
 * as the chess move format is xy and array is yx
 * @param xStart
 * @param yStart
 * @param xEnd
 * @param yEnd
 */
void Board::movePiece(int xStart, int yStart, int xEnd, int yEnd) {
    //clog << xStart << " " << yStart<< " " <<xEnd << " " << yEnd << endl;
    board[yEnd][xEnd] = move(board[yStart][xStart]);  // TODO: fix
}

/**
 * contains movement info for all pieces
 * @param isWhiteTurn 's turn
 * @return vector containing strigns containing valid  moves
 * TODO: split up switch into multiple functions, FINISH MOVES FOR PIECES
 */
vector<string> Board::possibleMoves(bool isWhiteTurn) {
    vector<string> moves;
    vector<string> temp;
    int xPos = 0, yPos = 0;
    if (!isCheck()) {
        for (auto &row : board) {
            for (auto &elem : row) {
                if (elem != nullptr) {
                    if (isWhiteTurn == elem->isPieceWhite()) {
                        switch (elem->getID()) {
                            case king: // move case for king piece TODO: does moving cause check?
                                for (int y = -1; y <= 1; y++) {
                                    for (int x = -1; x <= 1; x++) {
                                        if (xPos + x >= 0 && xPos + x <= 7 && yPos + y >= 0 && yPos + y <= 7) {
                                            if (board[yPos + y][xPos + x].get() != nullptr) {
                                                if (board[yPos + y][xPos + x]->isPieceWhite() != board[yPos][xPos]->isPieceWhite()) {
                                                    // clog << " Not null and not same color" << endl;
                                                    moves.push_back(arrayPosToString(yPos, xPos, yPos + y, xPos + x));
                                                }
                                            } else {
                                                // clog << "piece is null " << endl;
                                                moves.push_back(arrayPosToString(yPos, xPos, yPos + y, xPos + x));
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
                            case pawn:

                                if (elem->isPieceWhite()) {

                                } else {

                                }
                                break;
                        }
                    }
                }
                xPos++;
            }
            yPos++;
            xPos = 0;
        }

    } else { // sees what moves resolve check, if none then sets checkmate

    }
    return moves;
}



/**
 * converts array positions to board positions A-H  1-8
 * @param x axis of source
 * @param y axis of source
 * @param xDes axis of destination
 * @param yDes axis of destination
 * @return string in format 'xy xy'
 */
string Board::arrayPosToString(int y, int x, int yDes, int xDes) {
    string s;
    s.push_back(x + 65);
    s.push_back(56 - y);
    s.push_back(' ');
    s.push_back(xDes + 65);
    s.push_back(56 - yDes);
    return s;
}

bool Board::isCheck() const {
    return ischeck;
}

bool Board::isCheckMate() const {
    return ischeckmate;
}






