//
// Created by adrien on 03/06/19.
//

#ifndef ATAXX_CONSOLEVIEW_H
#define ATAXX_CONSOLEVIEW_H

#include "../View.h"
#include "../../Model/Board.h"

class ConsoleView : public View{
private:
    void displayConsole(const array<array<Cell, 7>, 7>& grid) noexcept;
public:
    ConsoleView() noexcept = default;//TODO Mettre Subject* subjet dans le constructeur d'Observer
    virtual ~ConsoleView() noexcept = default;

    virtual void update(Subject *subject) override;
    virtual void getUsernames(string& firstUsername, string& secondUsername) override;
    virtual void finalResult(Subject* subject) override;
};


#endif //ATAXX_CONSOLEVIEW_H
