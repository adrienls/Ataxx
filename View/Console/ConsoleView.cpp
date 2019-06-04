//
// Created by adrien on 03/06/19.
//

#include "ConsoleView.h"
using std::cout;
using std::endl;

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