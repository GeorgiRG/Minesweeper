#include <QGridLayout>
#include <QPushButton>
#include <random>
#include "game.h"
#include "messageboxes.h"

game::game(int size, int mines, QWidget *parent)
    : QWidget(parent)
{

}

void game::buildGame(int size, int mines){
    //create main window and grid layout
    this -> setWindowTitle("Minesweeper");
    this -> setFixedSize(size*100, size*100);
    signalMapper = new QSignalMapper(this); //mapping for buttons
    QGridLayout *gameLayout = new QGridLayout(this);
    gameLayout -> setSpacing(0);
    gameLayout -> setContentsMargins(0,0,0,0);

    //init buttons
    for(int i=0;i < size;i++) {

        for(int j=0; j<size; j++){
            QPushButton *btn = new QPushButton;
            btn -> setText(":)");
            btn -> setFixedSize(100,100);
            int tempPos = i*size + j;
            connect(btn, &QPushButton::pressed, this, [this, tempPos] { buttonPressed(tempPos); });
            buttongrid[i*size + j] = btn;
            signalMapper -> setMapping(btn, tempPos);
            gameLayout -> addWidget(buttongrid[i*size + j], i, j); //array pos, grid row, grid column
        }
    }


    //create the minefield
    srand(time(NULL));
    int counter = 0;
    int mineCopy = mines;
    for (int i=size*size - 1;i>=0;i--) {

        if((rand() % (i + 1) <= mineCopy)) {    //goes down button amount, button becomes a mine if random int is 1
            buttongrid[size*size - i - 1]-> setText("scary");
            //buttongrid[size*size - i - 1]-> setDisabled(true);
            mineCopy -= 1;
            minefield[counter] = 1;
        }
        else{
            minefield[counter] = 0;
        }
        counter += 1;
    }

    this->show();

}

void game::buttonPressed(int pos) {
    //QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    //QString smth;
    //smth.setNum(a);
    //buttonSender->setText(smth); // retrive the text from the but
    if(minefield[pos] == 1){
            buttongrid[pos] -> setText("boom");

            //this -> destroy();
    }
    //open empty buttons
    else{
        buttongrid[pos] -> setDisabled(true);
       // this -> checkMines(pos);
    }


}
/*
void game::checkMines(int pos){
    //check left
    for(int i=pos - 1; i>=0; i--){
        if(minefield[i] == 1){
            buttongrid[i] =
        }
    }

}
*/
