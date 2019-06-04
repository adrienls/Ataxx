//
// Created by adrien on 03/06/19.
//

#include "ConsoleView.h"
using std::cout;
using std::endl;
using std::cin;

void ConsoleView::update(Subject* subject) {
    Board* board = dynamic_cast<Board*>(subject);
    displayGrid(board->getGrid());
    nbPawn(board->getNbRedPawn(), board->getNbBluePawn());

}

void ConsoleView::displayGrid(const array<array<Cell, 7>, 7> &grid) noexcept{
    for(const array<Cell, 7>& row : grid){
        for(const Cell& cell: row){
            cout << cell << "  ";
        }
        cout << endl;
    }
}

void ConsoleView::nbPawn(unsigned short nbRedPawn, unsigned short nbBluePawn) noexcept{
    cout << endl << "Red Player has: " << nbRedPawn
         << endl << "Blue Player has: " << nbBluePawn << endl;
}

void ConsoleView::selectPawn(string player, unsigned char &row, unsigned char &column) noexcept{
    cout << "Please select a pawn coordinates: " << endl << player << "> ";
    cin >> row >> column;//TODO use stringstream and check user data
    cout << endl;
}

void ConsoleView::availableCells(const vector<array<unsigned char, 2>>& cells) noexcept{
    cout << "ok" << endl;
}