cmake_minimum_required(VERSION 3.12)
project(Ataxx)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 CONFIG REQUIRED Core Gui Widgets)
add_executable(Ataxx main.cpp Model/Board.cpp Model/Board.h Model/Cell.h Controller/exception/invalid_value.h Controller/exception/bad_board_coordinates.h Controller/exception/used_square.h Controller/arguments.cpp Controller/arguments.h Controller/MainApp.cpp Controller/MainApp.h Model/Subject.cpp Model/Subject.h View/Observer.h View/Console/ConsoleView.cpp View/Console/ConsoleView.h Controller/exception/bad_owner.h Controller/exception/invalid_input.h Controller/exception/no_more_move.h Controller/exception/not_available_move.h View/Qt/QtCellButton.h View/Qt/QtView.cpp View/Qt/QtView.h Controller/exception/restart.h)

target_link_libraries(Ataxx Qt5::Widgets)