#include "Board.h"

/**
 * Board class manages the pieces & checks move validation.
 */


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
        elem = std::make_unique<Piece>(pawn, true);
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
    board[yEnd][xEnd] = move(board[yStart][xStart]);
}

/**
 * contains movement info for all pieces
 * provides 'list' commands info and validates moves
 * @param isWhiteTurn 's turn
 * @return vector containing strigns containing valid moves
 */
vector<string> Board::possibleMoves(bool isWhiteTurn) {
    vector<string> moves, temp;
    int xPos = 0, yPos = 0;
    for (auto &row : board) {
        for (auto &elem : row) {
            if (elem != nullptr) {
                if (isWhiteTurn == elem->isPieceWhite()) {
                    switch (elem->getID()) {
                        case king: {
                            moves.emplace_back("King:");
                            for (int y = -1; y <= 1; y++) {
                                for (int x = -1; x <= 1; x++) {
                                    if (xPos + x >= 0 && xPos + x <= 7 && yPos + y >= 0 && yPos + y <= 7) {
                                        if (board[yPos + y][xPos + x].get() !=
                                            nullptr) { // checks if space is empty
                                            if (board[yPos + y][xPos + x]->isPieceWhite() !=
                                                board[yPos][xPos]->isPieceWhite()) { // can eat  piece
                                                moves.push_back(arrayPosToString(yPos, xPos, yPos + y, xPos + x));
                                            }
                                        } else { // TODO: CHECK IF CAUSES CHECK
                                            moves.push_back(arrayPosToString(yPos, xPos, yPos + y, xPos + x));
                                        }
                                    }
                                }
                            }
                        }
                            break;

                        case queen: { // movement for queen, uses rooks and bishops movement
                            moves.emplace_back("Queen:");
                            temp = rookMove(yPos, xPos);
                            moves.insert(moves.end(), temp.begin(), temp.end());
                            temp = bishopMove(yPos, xPos);
                            moves.insert(moves.end(), temp.begin(), temp.end());
                        }
                            break;

                        case bishop: { // movement for bishop
                            moves.emplace_back("Bishop:");
                            temp = bishopMove(yPos, xPos);
                            moves.insert(moves.end(), temp.begin(), temp.end());
                        }
                            break;

                        case knight: {// movement for knight
                            moves.emplace_back("Knight:");

                            int yDir = 2, xDir = 1;
                            for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < 2; j++) {// moves up 2 in y axis then int x axis by 1
                                    if (yPos + (yDir) >= 0 && yPos + (yDir) <= 7 &&
                                        xPos + (xDir) >= 0 && xPos + (xDir) <= 7) {  // array bounds check
                                        if (board[yPos + (yDir)][xPos + (xDir)].get() == nullptr) { // checks if is empty
                                            moves.push_back(
                                                    arrayPosToString(yPos, xPos, yPos + (yDir), xPos + (xDir)));
                                        } else if (board[yPos + (yDir)][xPos + (xDir)]->isPieceWhite() !=
                                                   elem->isPieceWhite()) {
                                            moves.push_back(
                                                    arrayPosToString(yPos, xPos, yPos + (yDir), xPos + (xDir)));
                                        }
                                    }
                                    xDir *= -1;
                                }
                                yDir *= -1;
                            }

                            yDir = 1;
                            xDir = 2;
                            for (int i = 0; i < 2; i++) {// moves by 2 in x axis then in y axis by 1
                                for (int j = 0; j < 2; j++) {
                                    if (yPos + (yDir) >= 0 && yPos + (yDir) <= 7 &&
                                        xPos + (xDir) >= 0 && xPos + (xDir) <= 7) {// array bounds check
                                        if (board[yPos + (yDir)][xPos + (xDir)].get() == nullptr) { // is empty?
                                            moves.push_back(
                                                    arrayPosToString(yPos, xPos, yPos + (yDir), xPos + (xDir)));
                                        } else if (board[yPos + (yDir)][xPos + (xDir)]->isPieceWhite() !=
                                                   elem->isPieceWhite()) { // is friend?
                                            moves.push_back(
                                                    arrayPosToString(yPos, xPos, yPos + (yDir), xPos + (xDir)));
                                        }
                                    }
                                    xDir *= -1;
                                }
                                yDir *= -1;
                            }

                        }
                            break;

                        case rook: { // movement for rook
                            moves.emplace_back("Rook:");
                            temp = rookMove(yPos, xPos);
                            moves.insert(moves.end(), temp.begin(), temp.end());
                        }
                            break;

                        case pawn: {
                            moves.emplace_back("Pawn");
                            // TODO : promotion
                            int yDir = 1; // sets direction of movement
                            if (elem->isPieceWhite()) {
                                yDir *= -1;
                            }
                            if (yPos + yDir > 0 && yPos + yDir < 7) {
                                if (board[yPos + yDir][xPos].get() == nullptr) { // forward movement,
                                    moves.push_back(arrayPosToString(yPos, xPos, yPos + yDir, xPos));
                                }
                                if (xPos - 1 < 0 || xPos + 1 > 7) {
                                    if (board[yPos + yDir][xPos - 1].get() != nullptr) { // attack movement
                                        if (board[yPos + yDir][xPos - 1]->isPieceWhite() != elem->isPieceWhite())
                                            moves.push_back(arrayPosToString(yPos, xPos, yPos + yDir, xPos - 1));
                                    }
                                    if (board[yPos + yDir][xPos + 1].get() != nullptr) { // attack movement
                                        if (board[yPos + yDir][xPos + 1]->isPieceWhite() != elem->isPieceWhite())
                                            moves.push_back(arrayPosToString(yPos, xPos, yPos + yDir, xPos + 1));
                                    }
                                }
                            }

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
    return moves;
}

/**
 * used for rook and queen
 * @param yPos
 * @param xPos
 * @return vector containing string containing rooks possible moves
 */
vector<string> Board::rookMove(int yPos, int xPos) {
    vector<string> moves;

    int dir = 1;
    for (int i = 0; i < 2; i++) { // checks y axis
        for (int lenght = 1; lenght < 8; lenght++) { // checks y axis movement
            if (yPos + (lenght * dir) >= 0 && yPos + (lenght * dir) <= 7) {
                if (board[yPos + (lenght * dir)][xPos].get() == nullptr) { // checks if space is empty
                    moves.push_back(
                            arrayPosToString(yPos, xPos, yPos + (lenght * dir), xPos));
                } else { // spot taken by something, stops loop
                    if (board[yPos + (lenght * dir)][xPos]->isPieceWhite() !=
                        board[yPos][xPos]->isPieceWhite()) { // checks if piece can be taken
                        moves.push_back(
                                arrayPosToString(yPos, xPos, yPos + (lenght * dir), xPos));
                    }
                    break; // breaks loop if ally or enemy encountered
                }
            }
        }
        dir *= -1; // swaps direction
    } // checks x axis
    for (int i = 0; i < 2; i++) {
        for (int lenght = 1; lenght < 8; lenght++) { // checks y axis movement
            if (xPos + (lenght * dir) >= 0 && xPos + (lenght * dir) <= 7) {
                if (board[yPos][xPos + (lenght * dir)].get() == nullptr) { // checks if space is empty
                    moves.push_back(
                            arrayPosToString(yPos, xPos, yPos, xPos + (lenght * dir)));
                } else { // spot taken by something, stops loop
                    if (board[yPos][xPos + (lenght * dir)]->isPieceWhite() !=
                        board[yPos][xPos]->isPieceWhite()) { // checks if piece can be taken
                        moves.push_back(
                                arrayPosToString(yPos, xPos, yPos, xPos + (lenght * dir)));
                    }
                    break; // breaks loop if ally or enemy encountered
                }
            }
        }
        dir *= -1; // swaps direction
    }
    return moves;
}

/**
 * used for bishop and queen
 * @param yPos
 * @param xPos
 * @return vector containing string containing bishops possible moves
 */
vector<string> Board::bishopMove(int yPos, int xPos) {
    vector<string> moves;
    int dir = 1;
    for (int i = 0; i < 2; i++) { // moves top right and bottom left
        for (int lenght = 1; lenght < 8; lenght++) { // checks y axis movement
            if (yPos + (lenght * dir) >= 0 && yPos + (lenght * dir) <= 7 &&
                xPos + (lenght * dir) >= 0 && xPos + (lenght * dir) <= 7) {
                if (board[yPos + (lenght * dir)][xPos + (lenght * dir)].get() == nullptr) { // checks if space is empty
                    moves.push_back(
                            arrayPosToString(yPos, xPos, yPos + (lenght * dir), xPos + (lenght * dir)));
                } else { // spot taken by something, stops loop
                    if (board[yPos + (lenght * dir)][xPos + (lenght * dir)]->isPieceWhite() !=
                        board[yPos][xPos]->isPieceWhite()) { // checks if piece can be taken
                        moves.push_back(
                                arrayPosToString(yPos, xPos, yPos + (lenght * dir), xPos + (lenght * dir)));
                    }
                    break; // breaks loop if ally or enemy encountered
                }
            }
        }
        dir *= -1; // swaps direction
    }

    for (int i = 0; i < 2; i++) { // moves top right and bottom left
        for (int lenght = 1; lenght < 8; lenght++) { // checks y axis movement
            if ((yPos - (lenght * dir) >= 0) && (yPos - (lenght * dir) <= 7) &&
                (xPos + (lenght * dir) >= 0) && (xPos + (lenght * dir) <= 7)) {
                if (board[yPos - (lenght * dir)][xPos + (lenght * dir)].get() == nullptr) { // checks if space is empty
                    moves.push_back(
                            arrayPosToString(yPos, xPos, yPos - (lenght * dir), xPos + (lenght * dir)));
                } else { // spot taken by something, stops loop
                    if (board[yPos - (lenght * dir)][xPos + (lenght * dir)]->isPieceWhite() !=
                        board[yPos][xPos]->isPieceWhite()) { // checks if piece can be taken
                        moves.push_back(
                                arrayPosToString(yPos, xPos, yPos - (lenght * dir), xPos + (lenght * dir)));
                    }
                    break; // breaks loop if ally or enemy encountered
                }
            }
        }
        dir *= -1; // swaps direction
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







