//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_WRONGPOSITION_H
#define ATAXX_WRONGPOSITION_H

#include "invalid_value.h"

class bad_board_coordinates : public invalid_value{
public:
    bad_board_coordinates() = delete;
    bad_board_coordinates(const bad_board_coordinates& e) noexcept : bad_board_coordinates(e.getFunctionName(), e.getValue()) {}
    bad_board_coordinates(const string& functionName, const string& value) noexcept
    : invalid_value(functionName, value, "Pawn coordinates are out of the board. Coordinates need to be between 0 and 6.") {}
    virtual ~bad_board_coordinates() = default;
};

#endif //ATAXX_WRONGPOSITION_H
