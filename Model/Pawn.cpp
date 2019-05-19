//
// Created by adrien on 18/05/19.
//

#include "Pawn.h"
#include "../Controller/exception/InvalidBoardCoordinates.h"

Pawn::Pawn(const Color &color, const array<unsigned char, 2> &position) : color(color) {
    Pawn::setPosition(position);
}
Pawn::Pawn(const Color &color, const unsigned char &row, const unsigned char &column) : color(color) {
    Pawn::setRow(row);
    Pawn::setColumn(column);
}

const Color &Pawn::getColor() const {
    return color;
}
void Pawn::setColor(const Color &color) {
    Pawn::color = color;
}

const array<unsigned char, 2> &Pawn::getPosition() const {
    return position;
}
void Pawn::setPosition(const array<unsigned char, 2> &position) {
    Pawn::setRow(position[0]);
    Pawn::setColumn(position[1]);
}

const unsigned char &Pawn::getRow() const{
    return position[0];
}
void Pawn::setRow(const unsigned char &row){
    if(position[0] > 6 || position[0] < 0){
        throw InvalidBoardCoordinates("setRow()", position[0]);
    }
    Pawn::position[0] = row;
}

const unsigned char &Pawn::getColumn() const {
    return position[1];
}
void Pawn::setColumn(const unsigned char &column){
    if(position[1] > 6 || position[1] < 0){
        throw InvalidBoardCoordinates("setColumn()", position[1]);
    }
    Pawn::position[1] = column;
}