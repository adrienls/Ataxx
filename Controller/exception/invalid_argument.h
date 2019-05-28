//
// Created by adrien on 28/05/19.
//

#ifndef ATAXX_INVALID_ARGUMENT_H
#define ATAXX_INVALID_ARGUMENT_H

#include "invalid_value.h"

template<typename Error>
class invalid_argument : public invalid_value<Error>{
public:
    invalid_argument() = delete;
    invalid_argument(const invalid_argument& e) noexcept : invalid_argument(e.getFunctionName(), e.getValue()) {}
    invalid_argument(const string &functionName, Error value) noexcept :
            invalid_value<Error>(functionName, value, "Invalid arguments were input. Please use --help to check the valid arguments.") {}
    virtual ~invalid_argument() = default;
};

#endif //ATAXX_INVALID_ARGUMENT_H
