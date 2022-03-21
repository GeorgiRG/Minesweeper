#include <iostream>
#include <QApplication>
//#include <QtWidgets>
//#include <QtCore>
#include <QLineEdit>
#include "messageboxes.h"
#include "game.h"

void RestartGame(MessageBoxes *msgbox);
int main(int argc, char *argv[])
{
    int lol;
    int obl;
    QApplication app(argc, argv);
    game gameWindow(5,5);
    gameWindow.buildGame(5, 5);
    MessageBoxes msgbox;
    RestartGame(&msgbox);
    lol = msgbox.mineAmount;
    obl = msgbox.gameSize;
    std::cout << "Hello"<< lol << std::endl << obl << std::endl;
    for(int i = 0; i < 40; i++){
        std::cout << gameWindow.minefield[i] << "";
    }
    std::cout << "mine end" <<std::endl;
    return app.exec();
}

void RestartGame(MessageBoxes *msgbox){
    msgbox -> RestartGame();

}
