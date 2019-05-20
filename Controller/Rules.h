//
// Created by adrien on 20/05/19.
//

#ifndef ATAXX_RULES_H
#define ATAXX_RULES_H

#include "../Model/Board.h"

class Rules {
private:
    Board grid;
public:
    Rules();
    virtual ~Rules() = default;
};


#endif //ATAXX_RULES_H
