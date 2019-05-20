//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_BOARD_H
#define ATAXX_BOARD_H

#include <array>
#include "Cell.h"

using std::array;

class Board {
private:
    array<array<Cell, 7>, 7> grid;
    unsigned char nbRedPawn = 2;
    unsigned char nbBluePawn = 2;
    static void coordinatesValidation(unsigned char row, unsigned char column);
public:
    Board(const array<array<Cell, 7>, 7> &grid);
    virtual ~Board() = default;

    unsigned char getNbRedPawn() const {return nbRedPawn;}
    unsigned char getNbBluePawn() const {return nbBluePawn;}

    const Cell getPawn(unsigned char row, unsigned char column) const {
        Board::coordinatesValidation(row, column);
        return this->grid[row][column];
    }
    const Cell getPawn(array<unsigned char, 2> position) const {
        return getPawn(position[0], position[1]);
    }

    void addPawn(Cell newPawn, unsigned char row, unsigned char column);
    void addPawn(Cell pawn, array<unsigned char, 2> position){
        Board::addPawn(pawn, position[0], position[1]);
    }

    void changeColor(unsigned char row, unsigned char column);
    void changeColor(array<unsigned char, 2> position){
        changeColor(position[0], position[1]);
    }
};

#endif //ATAXX_BOARD_H
