//
// Created by adrien on 10/06/19.
//

#ifndef ATAXX_RESTART_H
#define ATAXX_RESTART_H

#include "invalid_value.h"

class restart : public invalid_value{
public:
    restart() = delete;
    restart(const restart& e) noexcept : restart(e.getFunctionName(), e.getValue()) {}
    restart(const string& functionName, const string& value) noexcept
            : invalid_value(functionName, value, "Game is restarting.") {}
    virtual ~restart() = default;
};

#endif //ATAXX_RESTART_H
