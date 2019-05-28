//
// Created by adrien on 28/05/19.
//

#ifndef ATAXX_INVALID_ARGUMENT_H
#define ATAXX_INVALID_ARGUMENT_H

#include "invalid_value.h"

class too_many_arguments : public invalid_value{
public:
    too_many_arguments() = delete;
    too_many_arguments(const too_many_arguments& e) noexcept : too_many_arguments(e.getFunctionName(), e.getValue()) {}
    too_many_arguments(const string& functionName, const string& value) noexcept
    : invalid_value(functionName, value, "Invalid arguments were input. Please use --help to check the valid arguments.") {}
    virtual ~too_many_arguments() = default;
};

#endif //ATAXX_INVALID_ARGUMENT_H
