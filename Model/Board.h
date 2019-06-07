//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_BOARD_H
#define ATAXX_BOARD_H

#include <array>
#include <vector>
#include "Cell.h"
#include "Subject.h"

using std::array;
using std::vector;

class Board : public Subject{
private:
    array<array<Cell, 7>, 7> grid;
    vector<array<unsigned short, 2>> availableCells;
    array<unsigned short, 2> selectedPawn;
    bool displayOrAvailableMoves = true;//when true use display function in the console
    unsigned short nbRedPawn = 2;
    unsigned short nbBluePawn = 2;

    static void coordinatesValidation(unsigned short row, unsigned short column);
    static void coordinatesValidation(array<unsigned short, 2> position){
        coordinatesValidation(position[0], position[1]);
    }

    void verifyOwnership(bool turn, unsigned short selectedRow, unsigned short selectedColumn);

    void availableMoves(unsigned short selectedRow, unsigned short selectedColumn);
    void availableMoves(array<unsigned short, 2> position){
        availableMoves(position[0], position[1]);
    }

    Cell& getPawn(unsigned short row, unsigned short column);
    Cell& getPawn(array<unsigned short, 2> position){
        return getPawn(position[0], position[1]);
    }

    void changeColor(unsigned short row, unsigned short column);
    void changeColor(array<unsigned short, 2> position){
        changeColor(position[0], position[1]);
    }

public:
    Board() noexcept;
    virtual ~Board() override = default;

    const array<array<Cell, 7>, 7> &getGrid() const noexcept{
        return this->grid;
    }
    unsigned short getNbRedPawn() const noexcept{
        return this->nbRedPawn;
    }
    unsigned short getNbBluePawn() const noexcept{
        return this->nbBluePawn;
    }
    bool isDisplayOrAvailableMoves() const {
        return displayOrAvailableMoves;
    }

    const array<unsigned short, 2> &getSelectedPawn() const {
        return selectedPawn;
    }
    const vector<array<unsigned short, 2>> &getAvailableCells() const {
        return availableCells;
    }
    bool isAvailableMove(array<unsigned short, 2> position);
    bool isAvailableMove(unsigned short selectedRow, unsigned short selectedColumn){
        return isAvailableMove({selectedRow, selectedColumn});
    }

    static bool isAdjacent(unsigned short selectedRow, unsigned short selectedColumn, unsigned short testRow, unsigned short testColumn) noexcept;
    static bool isAdjacent(array<unsigned short, 2> originalPosition, array<unsigned short, 2> destinationPosition) noexcept{
        return isAdjacent(originalPosition[0], originalPosition[1], destinationPosition[0], destinationPosition[1]);
    }

    void setSelectedPawn(bool turn, unsigned short selectedRow, unsigned short selectedColumn);
    void setSelectedPawn(bool turn, const array<unsigned short, 2> &selectedPawn) {
        setSelectedPawn(turn, selectedPawn[0], selectedPawn[1]);
    }

    void addPawn(Cell newPawn, unsigned short row, unsigned short column);
    void addPawn(Cell pawn, array<unsigned short, 2> position){
        addPawn(pawn, position[0], position[1]);
    }

    void movePawn(unsigned short originalRow, unsigned short originalColumn, unsigned short destinationRow, unsigned short destinationColumn);
    void movePawn(array<unsigned short, 2> origin, array<unsigned short, 2> destination){
        movePawn(origin[0], origin[1], destination[0], destination[1]);
    }
};

#endif //ATAXX_BOARD_H
