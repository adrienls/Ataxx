cmake_minimum_required(VERSION 3.12)
project(Ataxx)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ataxx main.cpp Model/Board.cpp Model/Board.h Model/Cell.h Controller/exception/invalid_value.h Controller/exception/bad_board_coordinates.h Controller/exception/used_square.h Controller/arguments.cpp Controller/arguments.h Controller/MainApp.cpp Controller/MainApp.h Model/Subject.cpp Model/Subject.h View/Observer.h)