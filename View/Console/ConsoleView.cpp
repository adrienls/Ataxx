//
// Created by adrien on 03/06/19.
//

#include "ConsoleView.h"
using std::cout;
using std::endl;
using std::cin;

void ConsoleView::update(Subject* subject) {
    Board* board = dynamic_cast<Board*>(subject);
    const array<array<Cell, 7>, 7>& grid = board->getGrid();
    displayConsole(grid);
}

void ConsoleView::displayConsole(const array<array<Cell, 7>, 7>& grid) noexcept{
    for(const array<Cell, 7>& row : grid){
        for(const Cell& cell: row){
            cout << cell << "  ";
        }
        cout << endl;
    }
}

void ConsoleView::getUsernames(string& firstUsername, string& secondUsername) {
    cout << "Please enter the username of the Red player: ";
    cin >> firstUsername;
    cout << "Please enter the username of the Blue player: ";
    cin >> secondUsername;
    cout << endl;
}

void ConsoleView::finalResult(Subject* subject) {
    Board* board = dynamic_cast<Board*>(subject);
    cout << endl << "Red Player " << board->getRedPlayer()->getUsername() << " has: " << board->getNbBluePawn()
    << endl << "Blue Player " << board->getBluePlayer()->getUsername() << " has: " << board->getNbRedPawn() << endl;
}