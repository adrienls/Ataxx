//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_BOARD_H
#define ATAXX_BOARD_H

#include <array>
#include "Pawn.h"

using std::array;

class Board {
private:
    array<array<Pawn*, 7>, 7> grid;
    unsigned char nbRedPawn;
    unsigned char nbBluePawn;
public:
    Board(const array<array<Pawn *, 7>, 7> &grid);
    virtual ~Board();
    const array<array<Pawn *, 7>, 7> &getGrid() const;
    void setGrid(const array<array<Pawn *, 7>, 7> &grid);
    unsigned char getNbRedPawn() const {return nbRedPawn;}
    unsigned char getNbBluePawn() const {return nbBluePawn;}
    void addPawn(Pawn* pawn);
    void changeColor(unsigned char row, unsigned char column);
    void changeColor(array<unsigned char, 2> position);
};

#endif //ATAXX_BOARD_H
