#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QObject>
#include <QtGui>
#include "messageboxes.h"
#include <iostream>

MessageBoxes::MessageBoxes(QWidget *parent)
    : QWidget(parent)
{
    gameSize = 0;
    mineAmount = 0;

    input1 = new QLineEdit("Specify game size(number), max size is 10");
    input2 = new QLineEdit("Specify mine amount(number), max amount is 99");
    boxLayout = new QGridLayout(this);
    startButton = new QPushButton("Start game");

    this -> setFixedSize(400, 200);
    this -> setWindowTitle("New game settings");

    boxLayout -> addWidget(input1);

    boxLayout -> addWidget(input2);


    boxLayout -> addWidget(startButton);
    QObject::connect(startButton, SIGNAL(pressed()), this, SLOT(startedGame()));
}

void MessageBoxes::RestartGame() {
    this -> show();

    //int *values[2];
    //return *values;

}

void MessageBoxes::startedGame(){
    this->gameSize = this -> input1->text().toInt();
    this->mineAmount = this -> input2 -> text().toInt();
    std::cout << "Hello"<< gameSize << std::endl << mineAmount << std::endl;
    this->hide();
}
