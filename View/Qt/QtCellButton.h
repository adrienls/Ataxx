//
// Created by adrien on 08/06/19.
//

#ifndef ATAXX_QTCELLBUTTON_H
#define ATAXX_QTCELLBUTTON_H

#include <QtWidgets/QPushButton>
#include "../../Model/Cell.h"
#include "../../Model/Board.h"

class QtCellButton : public QPushButton{
private:
    Cell cell;
    unsigned short row;
    unsigned short column;
public:
    QtCellButton(Cell cell, unsigned short row, unsigned short column, QWidget *parent = nullptr)
            : QPushButton(parent), cell(cell), row(row), column(column) {}
    QtCellButton(Cell cell, unsigned short row, unsigned short column, const QString &text, QWidget *parent = nullptr)
            : QPushButton(text, parent), cell(cell), row(row), column(column) {}
    QtCellButton(Cell cell, unsigned short row, unsigned short column, const QIcon& icon, const QString &text, QWidget *parent = nullptr)
            : QPushButton(icon, text, parent), cell(cell), row(row), column(column) {}

    Cell getCell() const noexcept{
        return cell;
    }
    unsigned short getRow() const noexcept{
        return row;
    }
    unsigned short getColumn() const noexcept{
        return column;
    }

    void addToBoard(Board* board){
        board->addPawn(cell, row, column);
    }
};

#endif //ATAXX_QTCELLBUTTON_H
