#ifndef MESSAGEBOXES_H
#define MESSAGEBOXES_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>


class MessageBoxes: public QWidget
{
    Q_OBJECT

public:
    int inputGameSize = 0 , inputMineAmount = 0, started = 0;
    explicit MessageBoxes(int gameOver = 0, QWidget *parent = nullptr);


    void RestartGame();

private:
    QLineEdit *input1;
    QLineEdit *input2;
    QGridLayout *boxLayout;
    QPushButton *startButton;

signals:
    void startGame(int size, int mines);
private slots:
    void startedGame();
    void restartGame();
};

#endif // MESSAGEBOXES_H
