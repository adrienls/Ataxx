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
    Board() noexcept;
    virtual ~Board() = default;

    inline unsigned char getNbRedPawn() const noexcept;
    inline unsigned char getNbBluePawn() const noexcept;

    inline const Cell getPawn(unsigned char row, unsigned char column) const;
    inline const Cell getPawn(array<unsigned char, 2> position) const;

    void addPawn(Cell newPawn, unsigned char row, unsigned char column);
    inline void addPawn(Cell pawn, array<unsigned char, 2> position);

    void changeColor(unsigned char row, unsigned char column);
    inline void changeColor(array<unsigned char, 2> position);

    void movePawn(unsigned char originalRow, unsigned char originalColumn, unsigned char destinationRow, unsigned char destinationColumn);
    inline void movePawn(array<unsigned char, 2> origin, array<unsigned char, 2> destination);
};

#endif //ATAXX_BOARD_H
