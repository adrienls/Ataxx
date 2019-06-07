//
// Created by adrien on 07/06/19.
//

#ifndef ATAXX_NOT_AVAILABLE_MOVE_H
#define ATAXX_NOT_AVAILABLE_MOVE_H

#include "invalid_value.h"

class not_available_move : public invalid_value{
public:
    not_available_move() = delete;
    not_available_move(const not_available_move& e) noexcept : not_available_move(e.getFunctionName(), e.getValue()) {}
    not_available_move(const string& functionName, const string& value) noexcept
    : invalid_value(functionName, value, "This is not an available move!") {}
    virtual ~not_available_move() = default;
};

#endif //ATAXX_NOT_AVAILABLE_MOVE_H
