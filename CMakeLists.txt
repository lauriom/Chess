cmake_minimum_required(VERSION 3.14)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp ChessGame/Board.cpp ChessGame/Board.h ChessGame/Piece.cpp ChessGame/Piece.h ChessGame/GameController.cpp ChessGame/GameController.h ChessGame/PieceIDs.h ChessGame/Misc/SaveLoad.cpp ChessGame/Misc/SaveLoad.h)