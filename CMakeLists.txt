cmake_minimum_required(VERSION 3.12)
project(Ataxx)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ataxx main.cpp Model/Board.cpp Model/Board.h Model/Pawn.cpp Model/Pawn.h Controller/exception/InvalidValue.h Controller/exception/InvalidBoardCoordinates.h Controller/exception/UsedSquare.h Controller/exception/EmptySquare.h)