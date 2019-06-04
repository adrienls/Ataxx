//
// Created by adrien on 04/06/19.
//

#ifndef ATAXX_PLAYER_H
#define ATAXX_PLAYER_H

#include <string>
#include "Cell.h"
#include "../Controller/exception/invalid_color.h"

using std::string;
using std::to_string;

class Player {
private:
    string username;
    unsigned short nbPawn = 2;
    bool myTurn;
    bool victory = false;
    Cell color;
public:
    Player(const string &username, bool yourTurn, Cell color) : username(username), myTurn(yourTurn), color(color) {
        if(color == empty){
            throw invalid_color("Player() constructor", to_string(empty));
        }
    }
    virtual ~Player() = default;

    const string &getUsername() const noexcept{
        return username;
    }

    Cell getColor() const noexcept{
        return color;
    }

    unsigned short getNbPawn() const noexcept{
        return nbPawn;
    }
    void incrementNbPawn() noexcept{
        this->nbPawn++;
    }
    void decrementNbPawn() noexcept{
        this->nbPawn--;
    }

    bool isMyTurn() const noexcept{
        return myTurn;
    }
    void changeTurn() noexcept{
        this->myTurn = !this->myTurn;
    }

    bool isVictory() const noexcept{
        return victory;
    }
    void setVictory() noexcept{
        this->victory = !this->victory;
    }
};


#endif //ATAXX_PLAYER_H
