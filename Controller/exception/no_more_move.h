//
// Created by adrien on 07/06/19.
//

#ifndef ATAXX_NO_MORE_MOVE_H
#define ATAXX_NO_MORE_MOVE_H

#include "invalid_value.h"

class no_more_move : public invalid_value{
public:
    no_more_move() = delete;
    no_more_move(const no_more_move& e) noexcept : no_more_move(e.getFunctionName(), e.getValue()) {}
    no_more_move(const string& functionName, const string& value) noexcept
            : invalid_value(functionName, value, "No more possible move. Game over!") {}
    virtual ~no_more_move() = default;
};

#endif //ATAXX_NO_MORE_MOVE_H
