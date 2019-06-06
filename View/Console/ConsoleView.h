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
    ConsoleView() noexcept = default;//TODO Mettre Subject* subjet dans le constructeur d'Observer
    virtual ~ConsoleView() noexcept = default;

    virtual void update(Subject *subject) override;
    static const string selectPawn(const string& player, unsigned short& row, unsigned short& column) noexcept;
};


#endif //ATAXX_CONSOLEVIEW_H
