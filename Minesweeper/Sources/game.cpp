#include <QGridLayout>
#include <QPushButton>
#include <random>
#include <string>
#include <iostream>
#include "game.h"
#include "messageboxes.h"

game::game(QWidget *parent)
    : QWidget(parent)
{
    MessageBoxes* msgbox = new MessageBoxes(0);
    connect(msgbox, &MessageBoxes::startGame, this, &game::buildGame);
}

void game::buildGame(const int size, const int mines){
    if(size != 0 && mines != 0){
        this -> size = size;
        this -> mines = mines;
        std::cout << size << "  " << mines << std::endl;
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
                QPushButton *btn = new QPushButton();
                btn -> setText("");
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
                buttongrid[size*size - i - 1]-> setText("MINE");
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
    else{
        std::cout << "Error" << std::endl;
    }


}

void game::buttonPressed(int pos) {

    if(minefield[pos] == 1){
            this -> setDisabled(true);
            this -> setStyleSheet("background-color:grey;");
            MessageBoxes* msgbox = new MessageBoxes(1);
            this -> close();
    }
    //open empty buttons
    else{
       this -> checkMines(pos, false, false, false, false);
    }
}


void game::checkMines(int pos, bool left, bool top, bool right, bool bottom){
    //
    //find the location of the button
    //top check
    if (pos - size < 0 && top != true){
        top = true;
        if(pos == 0){
            left = true;
        }
        else if (pos == size-1){
            right = true;
        }
    }
    //bottom check
    else if(pos + size >= size * size - 1 && bottom != true){
        bottom = true;
        if(pos == size * (size -1)){
            left = true;
        }
        else if(pos == size * size - 1){
            right = true;
        }
    }
    //left check
    else if(pos % size == 0 && left != true){
        left = true;
    }
    //right check
    else if(pos % size == size - 1 && right != true){
        right = true;
    }


    //start checking for mines
    int mineAmount = 0;
    std::cout << "checking mines " << pos << std::endl;

    //moves left first, same pattern for other locations
    if(!left){
        if(buttongrid[pos - 1] -> isEnabled()){
            std::cout << "left "  << std::endl;

            if(minefield[pos - 1] == 1 ){
                mineAmount++;
            }
            else{
                //opposite direction is set to true so it doesn't go back
                checkMines(pos - 1, left, top, right=true, bottom);
            }
        }
    }
    if(!right){
        if(buttongrid[pos + 1] -> isEnabled()){
            std::cout << "right "  << std::endl;

            if(minefield[pos + 1] == 1){
                mineAmount++;
            }
            else{
                checkMines(pos + 1, left=true, top, right, bottom);
            }
        }
    }
    if(!top){
        if(buttongrid[pos - size] -> isEnabled()){
            std::cout << "top "  << std::endl;

            if(minefield[pos - size] == 1){
                mineAmount++;
            }
            else{
                checkMines(pos - size, left, top, right, bottom=true);
            }
        }
    }

    if(!bottom){
        if(buttongrid[pos + size] -> isEnabled()){
            std::cout << "bottom "  << std::endl;

            if(minefield[pos + size] == 1){
                mineAmount++;
            }
            else{
                checkMines(pos + size, left, top=true, right, bottom);
            }
        }
    }

    //change the button according to the nearby mines amount
    if(mineAmount == 0){
        buttongrid[pos] -> setText("");
        buttongrid[pos] -> setDisabled(true);

    }
    else{
        if(mineAmount < 2){
            buttongrid[pos] -> setStyleSheet("color: orange;font-weight:bold;font-size:16pt");
        }
        else{
            buttongrid[pos] -> setStyleSheet("color: red;font-weight:bold;font-size:16pt");

        }
        QString result = QString::fromStdString(std::to_string(mineAmount));
        buttongrid[pos] -> setText(result);
        buttongrid[pos] -> setDisabled(true);

    }

}


