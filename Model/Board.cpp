//
// Created by adrien on 18/05/19.
//

#include "Board.h"
#include "../Controller/exception/used_square.h"
#include "../Controller/exception/bad_board_coordinates.h"
#include "../Controller/exception/empty_square.h"

Board::Board() noexcept {
    for(array<Cell, 7>& row : this->grid){
        for(Cell& pawn : row){
            pawn = empty;
        }
    }
    this->grid[0][0] = Red;
    this->grid[0][6] = Blue;
    this->grid[6][0] = Blue;
    this->grid[6][6] = Red;
}

void Board::coordinatesValidation(unsigned char row, unsigned char column) {
    if(row > 6){
        throw bad_board_coordinates<unsigned char>("coordinatesValidation(): row too big", row);
    }
    if(row < 0){
        throw bad_board_coordinates<unsigned char>("coordinatesValidation(): row too small", row);
    }
    if(column > 6){
        throw bad_board_coordinates<unsigned char>("coordinatesValidation(): column too big", column);
    }
    if(column < 0){
        throw bad_board_coordinates<unsigned char>("coordinatesValidation(): column too small", column);
    }
}

unsigned char Board::getNbRedPawn() const noexcept {
    return nbRedPawn;
}
unsigned char Board::getNbBluePawn() const noexcept {
    return nbBluePawn;
}

const Cell Board::getPawn(unsigned char row, unsigned char column) const {
    Board::coordinatesValidation(row, column);
    return this->grid[row][column];
}
const Cell Board::getPawn(array<unsigned char, 2> position) const {
    return getPawn(position[0], position[1]);
}

void Board::addPawn(Cell newPawn, unsigned char row, unsigned char column) {
    Board::coordinatesValidation(row, column);
    Cell& currentPawn = this->grid[row][column];
    if(currentPawn != empty){
        throw used_square<Cell>("addPawn()", currentPawn);
    }
    currentPawn = newPawn;
    (newPawn == Red)? this->nbRedPawn++ : this->nbBluePawn++;
    //increment the number of colored pawn depending of the color of the newly added newPawn
}
void Board::addPawn(Cell pawn, array<unsigned char, 2> position){
    Board::addPawn(pawn, position[0], position[1]);
}

void Board::changeColor(unsigned char row, unsigned char column) {
    Board::coordinatesValidation(row, column);
    Cell& currentPawn = this->grid[row][column];
    if(currentPawn == empty){
        throw empty_square<Cell>("changeColor()", currentPawn);
    }
    currentPawn = (currentPawn == Red)? Blue : Red;
    if(currentPawn == Red){
        this->nbRedPawn++;
        this->nbBluePawn--;
    }
    else{
        this->nbRedPawn--;
        this->nbBluePawn++;
    }
}
void Board::changeColor(array<unsigned char, 2> position){
    changeColor(position[0], position[1]);
}

void Board::movePawn(unsigned char originalRow, unsigned char originalColumn, unsigned char destinationRow, unsigned char destinationColumn){
    coordinatesValidation(originalRow, originalColumn);
    coordinatesValidation(destinationRow, destinationColumn);
    Cell& currentPawn = this->grid[originalRow][originalColumn];
    Cell& newPawn = this->grid[destinationRow][destinationColumn];
    if(newPawn != empty){
        throw used_square<Cell>("movePawn()", newPawn);
    }
    newPawn = currentPawn;
    currentPawn = empty;
}
void Board::movePawn(array<unsigned char, 2> origin, array<unsigned char, 2> destination){
    movePawn(origin[0], origin[1], destination[0], destination[1]);
}