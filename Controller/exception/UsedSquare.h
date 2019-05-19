//
// Created by adrien on 19/05/19.
//

#ifndef ATAXX_USEDSQUARE_H
#define ATAXX_USEDSQUARE_H

#include "InvalidValue.h"

template<typename Error>
class UsedSquare : public InvalidValue<Error>{
public:
    UsedSquare(const string &functionName, Error value) : InvalidValue<Error>(functionName, value) {}
    virtual ~UsedSquare() = default;
    const string specificMessage() override {
        return "Board square is already used.";
    }
};

#endif //ATAXX_USEDSQUARE_H
