//
// Created by adrien on 18/05/19.
//

#include "Board.h"
#include "../Controller/exception/used_square.h"
#include "../Controller/exception/bad_board_coordinates.h"
#include "../Controller/exception/bad_owner.h"
#include "../Controller/exception/no_more_move.h"
#include "../Controller/exception/not_available_move.h"

using std::to_string;

Board::Board() noexcept{
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

void Board::coordinatesValidation(unsigned short row, unsigned short column) {
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

Cell& Board::getPawn(unsigned short row, unsigned short column){
    Board::coordinatesValidation(row, column);
    return this->grid[row][column];
}

void Board::addPawn(Cell newPawn, unsigned short row, unsigned short column) {
    if(!isAvailableMove(row, column)){
        throw not_available_move("addPawn", to_string(row) + " " + to_string(column));
    }
    Cell& currentPawn = getPawn(row, column);
    if(currentPawn != empty){
        throw used_square("addPawn()", to_string(currentPawn));
    }
    currentPawn = newPawn;
    (newPawn == Red)? nbRedPawn++ : nbBluePawn++;
    //increment the number of colored pawn depending of the color of the newly added newPawn

    changeAdjacentCellsColor(newPawn, row, column);

    displayOrAvailableMoves = true;
    notifyObservers();
}

void Board::changeColor(unsigned short row, unsigned short column) {
    Cell& currentPawn = getPawn(row, column);
    if(currentPawn == Blue){
        currentPawn = Red;
        nbRedPawn++;
        nbBluePawn--;
    }
    else if(currentPawn == Red){
        currentPawn = Blue;
        nbRedPawn--;
        nbBluePawn++;
    }
}

void Board::movePawn(unsigned short originalRow, unsigned short originalColumn, unsigned short destinationRow, unsigned short destinationColumn){
    if(!isAvailableMove(destinationRow, destinationColumn)){
        throw not_available_move("addPawn", to_string(destinationRow) + " " + to_string(destinationColumn));
    }
    Cell& currentPawn = getPawn(originalRow, originalColumn);
    Cell& newPawn = getPawn(destinationRow, destinationColumn);
    if(newPawn != empty){
        //makes sure the target cell for the pawn is available
        throw used_square("movePawn()", to_string(newPawn));
    }
    //moves the pawn and free the old cell
    newPawn = currentPawn;
    currentPawn = empty;

    changeAdjacentCellsColor(newPawn, destinationRow, destinationColumn);

    displayOrAvailableMoves = true;
    notifyObservers();
}

void Board::changeAdjacentCellsColor(const Cell& newPawn, unsigned short destinationRow, unsigned short destinationColumn){
    for(short row = destinationRow-1; row <= destinationRow+1; row++){
        //makes sure the row is still on the board
        if(row >=0 && row <= 6){
            for(short column = destinationColumn-1; column <= destinationColumn+1; column++){
                //makes sure the column is still on the board
                if(column >=0 && column <= 6){
                    //avoid changing the color of the recently moved pawn
                    if(row != destinationRow || column != destinationColumn){
                        Cell& adjacentPawn = this->grid[row][column];
                        //change the color of every adjacent cell if the color is different and the cell is not empty
                        if(adjacentPawn != newPawn && adjacentPawn != empty){
                            changeColor((unsigned short)row, (unsigned short)column);
                        }
                    }
                }
            }
        }
    }
}

void Board::availableMoves(unsigned short selectedRow, unsigned short selectedColumn){
    coordinatesValidation(selectedRow, selectedColumn);
    //checks the selected pawn is on the board
    for(short row = selectedRow-2; row <= selectedRow+2; row++){//check the two rows before and after the current one
        //makes sure the row is still on the board
        if(row >=0 && row <= 6){
            for(short column = selectedColumn-2; column <= selectedColumn+2; column++){//check the two columns before and after the current one
                //makes sure the column is still on the board
                if(column >=0 && column <= 6){
                    //avoid adding the selected pawn to the vector
                    //so it continues if one of the two coordinate is different
                    if(row != selectedRow || column != selectedColumn){
                        if(this->grid[row][column] == empty){
                            //add all the cells that are not empty and in a range of two cells in the vector
                            this->availableCells.push_back({(unsigned short)row, (unsigned short)column});
                        }
                    }
                }
            }
        }
    }
}

void Board::verifyOwnership(bool turn, unsigned short selectedRow, unsigned short selectedColumn){
    coordinatesValidation(selectedRow, selectedColumn);
    Cell currentColor = (turn)? Red : Blue;
    if(grid[selectedRow][selectedColumn] != currentColor){
        throw bad_owner("verifyOwnership", to_string(grid[selectedRow][selectedColumn]));
    }
}

void Board::setSelectedPawn(bool turn, unsigned short selectedRow, unsigned short selectedColumn){
    this->availableCells.clear();
    verifyOwnership(turn, selectedRow, selectedColumn);
    this->selectedPawn[0] = selectedRow;
    this->selectedPawn[1] = selectedColumn;
    availableMoves(selectedRow, selectedColumn);
    if(availableCells.empty()){
        throw no_more_move("setSelectedPawn", "availableCells is empty");
    }
    displayOrAvailableMoves = false;
    notifyObservers();
}

bool Board::isAdjacent(unsigned short selectedRow, unsigned short selectedColumn, unsigned short testRow, unsigned short testColumn) noexcept{
    coordinatesValidation(selectedRow, selectedColumn);
    //checks the selected pawn is on the board
    for(short row = selectedRow-1; row <= selectedRow+1; row++){//check the row before and after the current one
        //makes sure the row is still on the board
        if(row >=0 && row <= 6){
            for(short column = selectedColumn-1; column <= selectedColumn+1; column++){//check the column before and after the current one
                //makes sure the column is still on the board
                if(column >=0 && column <= 6){
                    //avoid adding the selected pawn to the vector
                    //so it continues if one of the two coordinate is different
                    if(row != selectedRow || column != selectedColumn){
                        if(row == testRow && column == testColumn){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Board::isAvailableMove(array<unsigned short, 2> position){
    for(auto move : availableCells){
        if(move == position){
            return true;
        }
    }
    return false;
}