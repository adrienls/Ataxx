//
// Created by adrien on 19/05/19.
//

#ifndef ATAXX_EMPTYSQUARE_H
#define ATAXX_EMPTYSQUARE_H

#include "InvalidValue.h"

template <typename Error>
class EmptySquare : InvalidValue<Error>{
public:
    EmptySquare(const string &functionName, Error value) : InvalidValue<Error>(functionName, value) {}
    virtual ~EmptySquare() = default;
    const string specificMessage() override {
        return "Empty board square, no modification is possible.";
    }
};


#endif //ATAXX_EMPTYSQUARE_H
