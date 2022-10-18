#include <iostream>
#include <QApplication>
#include <qmainwindow.h>
#include <QLineEdit>
#include "messageboxes.h"
#include "game.h"

void RestartGame(MessageBoxes *msgbox);
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    game gameWindow;
    return app.exec();
}
