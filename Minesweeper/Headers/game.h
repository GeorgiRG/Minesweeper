#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QIntValidator>
#include <QSignalMapper>
#include <vector>

class game: public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);

    //void buildGame();
    int minefield[100] = {0};

private:
    //int* checkLocation(int pos, bool left = false, bool top = false, bool right = false, bool bottom = false);
    void checkMines(int pos, bool left, bool top, bool right, bool bottom);
    int size = 0;
    int mines = 0;
    QWidget* window;
    QGridLayout *gameLayout;
    QPushButton *gameButton;
    QSignalMapper *signalMapper;
    QPushButton *buttongrid[100];
    //int minefield[100];

public slots:
    void buttonPressed(int pos);
    void buildGame(const int size, const int mines);
};

#endif // GAME_H

