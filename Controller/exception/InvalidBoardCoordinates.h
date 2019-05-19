//
// Created by adrien on 18/05/19.
//

#ifndef ATAXX_WRONGPOSITION_H
#define ATAXX_WRONGPOSITION_H

#include "InvalidValue.h"

template<typename Error>
class InvalidBoardCoordinates : public InvalidValue<Error>{
public:
    InvalidBoardCoordinates(const string &functionName, Error value) : InvalidValue<Error>(functionName, value) {}
    virtual ~InvalidBoardCoordinates() = default;
    const string specificMessage() override {
        return "Pawn coordinates are out of the board. Coordinates need to be between 0 and 6.";
    }
};

#endif //ATAXX_WRONGPOSITION_H
