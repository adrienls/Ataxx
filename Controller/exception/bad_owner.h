//
// Created by adrien on 06/06/19.
//

#ifndef ATAXX_BAD_OWNER_H
#define ATAXX_BAD_OWNER_H

#include "invalid_value.h"

class bad_owner : public invalid_value{
public:
    bad_owner() = delete;
    bad_owner(const bad_owner& e) noexcept : bad_owner(e.getFunctionName(), e.getValue()) {}
    bad_owner(const string& functionName, const string& value) noexcept
    : invalid_value(functionName, value, "This is not your pawn!") {}
    virtual ~bad_owner() = default;
};

#endif //ATAXX_BAD_OWNER_H
