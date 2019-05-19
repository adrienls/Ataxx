//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_PAWN_H
#define ATAXX_PAWN_H

#include <array>
using std::array;
enum Color {Red, Blue};

class Pawn {
private:
    Color color;
    array<unsigned char, 2> position;
public:
    Pawn(const Color &color, const array<unsigned char, 2> &position);
    Pawn(const Color &color, const unsigned char &row, const unsigned char &column);
    virtual ~Pawn() = default;

    const Color &getColor() const;
    void setColor(const Color &color);
    const array<unsigned char, 2> &getPosition() const;
    void setPosition(const array<unsigned char, 2> &position);
    const unsigned char &getRow() const;
    void setRow(const unsigned char &row);
    const unsigned char &getColumn() const;
    void setColumn(const unsigned char &column);
};

#endif //ATAXX_PAWN_H
