//
// Created by adrien on 03/06/19.
//

#ifndef ATAXX_CONSOLEVIEW_H
#define ATAXX_CONSOLEVIEW_H

#include "../Observer.h"
#include "../../Model/Board.h"

class ConsoleView : public Observer{
private:
    void displayConsole(const array<array<Cell, 7>, 7>& grid) noexcept;
public:
    ConsoleView() noexcept = default;//TODO Mettre Subject* subjet dans le constructeur d'Observer
    virtual ~ConsoleView() noexcept = default;

    virtual void update(Subject *subject) override;
};


#endif //ATAXX_CONSOLEVIEW_H
