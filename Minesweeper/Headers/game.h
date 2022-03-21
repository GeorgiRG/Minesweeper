#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QIntValidator>
#include <QSignalMapper>
#include <vector>

class game: public QWidget
{
    Q_OBJECT

public:
    explicit game(int size, int mines, QWidget *parent = nullptr);

    void buildGame(int size, int mines);
    int minefield[100] = {0};

private:
    void checkMines(int pos);
    int size = size;
    int mines = mines;
    QPushButton *gameButton;
    QSignalMapper *signalMapper;
    QPushButton *buttongrid[100];
    //int minefield[100];

private slots:
    void buttonPressed(int pos);
};

#endif // GAME_H
