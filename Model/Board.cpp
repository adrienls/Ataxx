//
// Created by adrien on 18/05/19.
//

#include "Board.h"
#include "../Controller/exception/UsedSquare.h"
#include "../Controller/exception/EmptySquare.h"

Board::Board(const array<array<Pawn *, 7>, 7> &grid) : grid(grid), nbRedPawn(2), nbBluePawn(2) {
    for(array<Pawn*, 7> row : this->grid){
        for(Pawn* pawn : row){
            pawn = nullptr;
        }
    }
    this->grid[0][0] = new Pawn(Red, 0, 0);
    this->grid[0][6] = new Pawn(Blue, 0, 6);
    this->grid[6][0] = new Pawn(Blue, 0, 6);
    this->grid[6][6] = new Pawn(Red, 6, 6);
}
Board::~Board() {
    for(array<Pawn*, 7> row : this->grid){
        for(Pawn* pawn : row){
            delete pawn;
        }
    }
}

const array<array<Pawn *, 7>, 7> &Board::getGrid() const {
    return grid;
}
void Board::setGrid(const array<array<Pawn *, 7>, 7> &grid) {
    Board::grid = grid;
}

void Board::addPawn(Pawn *pawn) {
    unsigned char row = pawn->getRow();
    unsigned char column = pawn->getColumn();
    if(this->grid[row][column] == nullptr){
        this->grid[row][column] = pawn;
        (pawn->getColor() == Red)? this->nbRedPawn++ : this->nbBluePawn++;
        //increment the number of colored pawn depending of the color of the newly added pawn
    }
    else{
        throw UsedSquare<Pawn*>("addPawn()", this->grid[row][column]);
    }
}
void Board::changeColor(unsigned char row, unsigned char column) {
    Pawn* currentPawn = this->grid[row][column];
    if(currentPawn != nullptr){
        Color newColor = (currentPawn->getColor() == Red)? Blue : Red;
        currentPawn->setColor(newColor);
        if(newColor == Red){
            this->nbRedPawn++;
            this->nbBluePawn--;
        }
        else{
            this->nbRedPawn--;
            this->nbBluePawn++;
        }
    }
    else{
        throw EmptySquare<Pawn*>("changeColor()", currentPawn);
    }
}
void Board::changeColor(array<unsigned char, 2> position) {
    Board::changeColor(position[0], position[1]);
}