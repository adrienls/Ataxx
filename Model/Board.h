//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_BOARD_H
#define ATAXX_BOARD_H

#include <array>
#include <vector>
#include "Cell.h"

using std::array;
using std::vector;

class Board {
private:
    array<array<Cell, 7>, 7> grid;
    vector<array<unsigned char, 2>> availableCells;
    unsigned char nbRedPawn = 2;
    unsigned char nbBluePawn = 2;

    static void coordinatesValidation(unsigned char row, unsigned char column);
    static void coordinatesValidation(array<unsigned char, 2> position);

    inline Cell& getPawn(unsigned char row, unsigned char column);
    inline Cell& getPawn(array<unsigned char, 2> position);

    void changeColor(unsigned char row, unsigned char column);
    inline void changeColor(array<unsigned char, 2> position);

public:
    Board() noexcept;
    virtual ~Board() = default;

    inline unsigned char getNbRedPawn() const noexcept;
    inline unsigned char getNbBluePawn() const noexcept;

    void addPawn(Cell newPawn, unsigned char row, unsigned char column);
    inline void addPawn(Cell pawn, array<unsigned char, 2> position);

    void movePawn(unsigned char originalRow, unsigned char originalColumn, unsigned char destinationRow, unsigned char destinationColumn);
    inline void movePawn(array<unsigned char, 2> origin, array<unsigned char, 2> destination);

    const vector<array<unsigned char, 2>>& availableMoves(unsigned char selectedRow, unsigned char selectedColumn);
    inline const vector<array<unsigned char, 2>>& availableMoves(array<unsigned char, 2> position);
};

#endif //ATAXX_BOARD_H
