//
// Created by adrien on 06/06/19.
//

#ifndef ATAXX_INVALID_INPUT_H
#define ATAXX_INVALID_INPUT_H

#include "invalid_value.h"

class invalid_input : public invalid_value{
public:
    invalid_input() = delete;
    invalid_input(const invalid_input& e) noexcept : invalid_input(e.getFunctionName(), e.getValue()) {}
    invalid_input(const string& functionName, const string& value) noexcept
            : invalid_value(functionName, value, "Your input is not valid! You have to enter coordinates.") {}
    virtual ~invalid_input() = default;
};


#endif //ATAXX_INVALID_INPUT_H
