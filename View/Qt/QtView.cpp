//
// Created by adrien on 08/06/19.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include "QtView.h"

QtView::QtView(Board *board, QWidget *parent, const Qt::WindowFlags &flags) : QMainWindow(parent, flags), board(board) {

    this->setWindowTitle("Ataxx");
    this->setMinimumWidth(500);
    this->setMinimumHeight(500);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);

    for(unsigned short row = 0; row <= 6; row++){
        for(unsigned short column = 0; column <= 6; column++){
            QPushButton* cell = new QPushButton();
        }
    }


}

void QtView::update(Subject *subject) {

}
