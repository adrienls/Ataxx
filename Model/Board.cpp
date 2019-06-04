//
// Created by adrien on 18/05/19.
//

#include "Board.h"
#include "../Controller/exception/used_square.h"
#include "../Controller/exception/bad_board_coordinates.h"

using std::to_string;

Board::Board(Player* redPlayer, Player* bluePlayer) noexcept : redPlayer(redPlayer), bluePlayer(bluePlayer){
    for(array<Cell, 7>& row : this->grid){
        for(Cell& pawn : row){
            pawn = empty;
        }
    }
    this->grid[0][0] = Red;
    this->grid[0][6] = Blue;
    this->grid[6][0] = Blue;
    this->grid[6][6] = Red;
    notifyObservers();
}

void Board::coordinatesValidation(unsigned char row, unsigned char column) {
    if(row > 6){
        throw bad_board_coordinates("coordinatesValidation(): row too big", to_string(row));
    }
    if(row < 0){
        throw bad_board_coordinates("coordinatesValidation(): row too small", to_string(row));
    }
    if(column > 6){
        throw bad_board_coordinates("coordinatesValidation(): column too big", to_string(column));
    }
    if(column < 0){
        throw bad_board_coordinates("coordinatesValidation(): column too small", to_string(column));
    }
}

Cell& Board::getPawn(unsigned char row, unsigned char column){
    Board::coordinatesValidation(row, column);
    return this->grid[row][column];
}

void Board::addPawn(Cell newPawn, unsigned char row, unsigned char column) {
    Cell& currentPawn = getPawn(row, column);
    if(currentPawn != empty){
        throw used_square("addPawn()", to_string(currentPawn));
    }
    currentPawn = newPawn;
    (newPawn == Red)? redPlayer->incrementNbPawn() : bluePlayer->incrementNbPawn();
    //increment the number of colored pawn depending of the color of the newly added newPawn
    notifyObservers();
}

void Board::changeColor(unsigned char row, unsigned char column) {
    Cell& currentPawn = getPawn(row, column);
    if(currentPawn == Blue){
        currentPawn = Red;
        redPlayer->incrementNbPawn();
        bluePlayer->decrementNbPawn();
    }
    else if(currentPawn == Red){
        currentPawn = Blue;
        redPlayer->decrementNbPawn();
        bluePlayer->incrementNbPawn();
    }
}

void Board::movePawn(unsigned char originalRow, unsigned char originalColumn, unsigned char destinationRow, unsigned char destinationColumn){
    Cell& currentPawn = getPawn(originalRow, originalColumn);
    Cell& newPawn = getPawn(destinationRow, destinationColumn);
    if(newPawn != empty){
        //makes sure the target cell for the pawn is available
        throw used_square("movePawn()", to_string(newPawn));
    }
    //moves the pawn and free the old cell
    newPawn = currentPawn;
    currentPawn = empty;
    for(unsigned char row = destinationRow-1; row != destinationRow+1; row++){
        //makes sure the row is still on the board
        if(row >=0 && row <= 6){
            for(unsigned char column = destinationColumn-1; column != destinationColumn+1; column++){
                //makes sure the column is still on the board
                if(column >=0 && column <= 6){
                    //avoid changing the color of the recently moved pawn
                    if(row != destinationRow && column != destinationColumn){
                        Cell& adjacentPawn = this->grid[row][column];
                        //change the color of every adjacent cell if the color is different and the cell is not empty
                        if(adjacentPawn != newPawn && adjacentPawn != empty){
                            changeColor(row, column);
                        }
                    }
                }
            }
        }
    }
    notifyObservers();
}

const vector<array<unsigned char, 2>>& Board::availableMoves(unsigned char selectedRow, unsigned char selectedColumn){
    coordinatesValidation(selectedRow, selectedColumn);
    //checks the selected pawn is on the board
    for(unsigned char row = selectedRow-2; row != selectedRow+2; row++){
        //makes sure the row is still on the board
        if(row >=0 && row <= 6){
            for(unsigned char column = selectedColumn-2; column != selectedColumn+2; column++){
                //makes sure the column is still on the board
                if(column >=0 && column <= 6){
                    //avoid adding the selected pawn to the vector
                    if(row != selectedRow && column != selectedColumn){
                        if(this->grid[row][column] == empty){
                            //add all the cells that are not empty and in a range of two cells in the vector
                            this->availableCells.push_back({row, column});
                        }
                    }
                }
            }
        }
    }
    //return a vector with the position of all the available moves
    return this->availableCells;
}
