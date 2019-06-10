//
// Created by adrien on 03/06/19.
//

#ifndef ATAXX_CONSOLEVIEW_H
#define ATAXX_CONSOLEVIEW_H

#include <string>
#include "../Observer.h"
#include "../../Model/Board.h"

using std::string;

class ConsoleView : public Observer{
private:
    static void displayGrid(const array<array<Cell, 7>, 7> &grid) noexcept;
    static void nbPawn(unsigned short nbRedPawn, unsigned short nbBluePawn) noexcept;
    static void availableMoves(Board* board) noexcept;
public:
    ConsoleView() = default;
    virtual ~ConsoleView() = default;

    virtual void update(Subject *subject) override;
    static const string selectPawn(const string& option, bool turn, unsigned short& row, unsigned short& column) noexcept;
    static void printMessage(const string& message);
};


#endif //ATAXX_CONSOLEVIEW_H
