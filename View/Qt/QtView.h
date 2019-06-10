//
// Created by adrien on 08/06/19.
//

#ifndef ATAXX_QTVIEW_H
#define ATAXX_QTVIEW_H


#include <QtWidgets/QMainWindow>
#include "../../Model/Board.h"

class QtView : public QMainWindow, public Observer{
private:
    Board* board;
public:
    explicit QtView(Board *board, QWidget *parent = nullptr, const Qt::WindowFlags& flags = Qt::WindowFlags());

    virtual void update(Subject *subject) override;
};


#endif //ATAXX_QTVIEW_H
