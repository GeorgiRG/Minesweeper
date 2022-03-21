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
    explicit MessageBoxes(QWidget *parent = nullptr);


    void RestartGame();

    int gameSize;
    int mineAmount;

private:
    QLineEdit *input1;
    QLineEdit *input2;
    QGridLayout *boxLayout;
    QPushButton *startButton;

private slots:
    void startedGame();
};

#endif // MESSAGEBOXES_H
