//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_BOARD_H
#define ATAXX_BOARD_H

#include <array>
#include <vector>
#include "Cell.h"
#include "Subject.h"
#include "Player.h"

using std::array;
using std::vector;

class Board : public Subject{
private:
    array<array<Cell, 7>, 7> grid;
    vector<array<unsigned char, 2>> availableCells;
    Player* redPlayer;
    Player* bluePlayer;

    static void coordinatesValidation(unsigned char row, unsigned char column);
    static void coordinatesValidation(array<unsigned char, 2> position){//TODO Demander pour le pb inline dans le cpp --> undefined reference
        coordinatesValidation(position[0], position[1]);
    }

    Cell& getPawn(unsigned char row, unsigned char column);
    Cell& getPawn(array<unsigned char, 2> position){
        return getPawn(position[0], position[1]);
    }

    void changeColor(unsigned char row, unsigned char column);
    void changeColor(array<unsigned char, 2> position){
        changeColor(position[0], position[1]);
    }

public:
    Board(Player* redPlayer, Player* bluePlayer) noexcept;
    virtual ~Board() override = default;

    const array<array<Cell, 7>, 7> &getGrid() const noexcept{
        return this->grid;
    }
    unsigned short getNbRedPawn() const noexcept{
        return this->redPlayer->getNbPawn();
    }
    unsigned short getNbBluePawn() const noexcept{
        return this->bluePlayer->getNbPawn();
    }

    Player *getRedPlayer() const {
        return redPlayer;
    }
    Player *getBluePlayer() const {
        return bluePlayer;
    }

    void addPawn(Cell newPawn, unsigned char row, unsigned char column);
    void addPawn(Cell pawn, array<unsigned char, 2> position){
        addPawn(pawn, position[0], position[1]);
    }

    void movePawn(unsigned char originalRow, unsigned char originalColumn, unsigned char destinationRow, unsigned char destinationColumn);
    void movePawn(array<unsigned char, 2> origin, array<unsigned char, 2> destination){
        movePawn(origin[0], origin[1], destination[0], destination[1]);
    }

    const vector<array<unsigned char, 2>>& availableMoves(unsigned char selectedRow, unsigned char selectedColumn);
    const vector<array<unsigned char, 2>>& availableMoves(array<unsigned char, 2> position){
        return availableMoves(position[0], position[1]);
    }
};

#endif //ATAXX_BOARD_H
