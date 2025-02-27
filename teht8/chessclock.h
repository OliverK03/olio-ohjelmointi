#ifndef SHAKKIKELLO_H
#define SHAKKIKELLO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QProgressBar>

class ChessClock : public QWidget {
    Q_OBJECT

public:
    ChessClock(QWidget *parent = nullptr);

private slots:
    void updateTime();
    void switchToPlayerOne();
    void switchToPlayerTwo();
    void startClock();
    void stopClock();
    void setFiveMinutes();
    void setTwoMinutes();

private:
    QTimer *timer;
    QLabel *playerOneLabel;
    QLabel *playerTwoLabel;
    QLabel *statusLabel;
    QProgressBar *playerOneProgress;
    QProgressBar *playerTwoProgress;
    QPushButton *switchPlayerOneButton;
    QPushButton *switchPlayerTwoButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *twoMinButton;
    QPushButton *fiveMinButton;
    QTime playerOneTime;
    QTime playerTwoTime;
    bool playerOneTurn;
    int totalTime;
};

#endif // CHESSCLOCK_H
