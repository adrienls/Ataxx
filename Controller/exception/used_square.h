//
// Created by adrien on 19/05/19.
//

#ifndef ATAXX_USEDSQUARE_H
#define ATAXX_USEDSQUARE_H

#include "invalid_value.h"

class used_square : public invalid_value{
public:
    used_square() = delete;
    used_square(const used_square& e) noexcept : used_square(e.getFunctionName(), e.getValue()) {}
    used_square(const string& functionName, const string& value) noexcept
    : invalid_value(functionName, value, "Board square is already used.") {}
    virtual ~used_square() = default;
};

#endif //ATAXX_USEDSQUARE_H
