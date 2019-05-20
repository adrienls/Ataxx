//
// Created by adrien on 18/05/19.
//

#include "Board.h"
#include "../Controller/exception/used_square.h"
#include "../Controller/exception/bad_board_coordinates.h"
#include "../Controller/exception/empty_square.h"

Board::Board(const array<array<Cell, 7>, 7> &grid) : grid(grid) {
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