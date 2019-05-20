//
// Created by adrien on 19/05/19.
//

#ifndef ATAXX_EMPTYSQUARE_H
#define ATAXX_EMPTYSQUARE_H

#include "invalid_value.h"

template <typename Error>
class empty_square : invalid_value<Error>{
public:
    empty_square() = delete;
    empty_square(const string &functionName, Error value) :
    invalid_value<Error>(functionName, value, "Empty board square, no modification is possible.") {}
    virtual ~empty_square() = default;
};


#endif //ATAXX_EMPTYSQUARE_H
