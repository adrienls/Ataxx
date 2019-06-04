//
// Created by adrien on 04/06/19.
//

#ifndef ATAXX_INVALID_COLOR_H
#define ATAXX_INVALID_COLOR_H

#include "invalid_value.h"

class invalid_color : public invalid_value{
public:
    invalid_color() = delete;
    invalid_color(const invalid_value &e) noexcept : invalid_color(e.getFunctionName(), e.getValue()) {}
    invalid_color(const string &functionName, const string &value) noexcept
    : invalid_value(functionName, value, "Invalid color. A pawn can only be red or blue!") {}
    virtual ~invalid_color() = default;
};

#endif //ATAXX_INVALID_COLOR_H
