#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QObject>
#include <QtGui>
#include "messageboxes.h"
#include "game.h"
#include <iostream>

MessageBoxes::MessageBoxes(int gameOver, QWidget *parent)
    : QWidget(parent)
{
    if(!gameOver) {
        input1 = new QLineEdit("Specify game size(number), max size is 10(10x10 actual)");
        input2 = new QLineEdit("Specify mine amount(number), max amount is 99");
        boxLayout = new QGridLayout(this);
        startButton = new QPushButton("Start game");

        this -> setFixedSize(400, 200);
        this -> setWindowTitle("New game settings");

        boxLayout -> addWidget(input1);

        boxLayout -> addWidget(input2);

        boxLayout -> addWidget(startButton);
        QObject::connect(startButton, SIGNAL(pressed()), this, SLOT(startedGame()));
        this -> show();
    }
    else{
        this -> setFixedSize(400, 200);
        this -> setWindowTitle("Game Over!");
        boxLayout = new QGridLayout(this);
        startButton = new QPushButton("Press to restart game");
        boxLayout -> addWidget(startButton);
        startButton -> setFixedSize(200, 100);
        QObject::connect(startButton, SIGNAL(pressed()), this, SLOT(restartGame()));

        this -> show();

    }
}

void MessageBoxes::restartGame() {
    game* newGame = new game();
    this -> close();
}

void MessageBoxes::startedGame(){
    emit startGame(this -> input1->text().toInt(), this -> input2->text().toInt());
    this -> close();
}

