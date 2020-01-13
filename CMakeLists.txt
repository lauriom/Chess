cmake_minimum_required(VERSION 3.14)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp ChessGame/Board.cpp ChessGame/Board.h ChessGame/Piece.cpp ChessGame/Piece.h ChessGame/GameController.cpp ChessGame/GameController.h ChessGame/PieceHeaders.h ChessGame/Pieces/King.cpp ChessGame/Pieces/King.h ChessGame/Pieces/Queen.cpp ChessGame/Pieces/Queen.h ChessGame/Pieces/Bishop.cpp ChessGame/Pieces/Bishop.h ChessGame/Pieces/Rook.cpp ChessGame/Pieces/Rook.h ChessGame/Pieces/Knight.cpp ChessGame/Pieces/Knight.h ChessGame/Pieces/Pawn.cpp ChessGame/Pieces/Pawn.h ChessGame/FileManager/GameSave.cpp ChessGame/FileManager/GameSave.h)