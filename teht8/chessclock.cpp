#include "chessclock.h"

ChessClock::ChessClock(QWidget *parent) : QWidget(parent), playerOneTurn(true) {
    timer = new QTimer(this);
    totalTime = 0;
    playerOneTime = QTime(0, 5, 0);
    playerTwoTime = QTime(0, 5, 0);

    // Player Time Labels
    playerOneLabel = new QLabel(playerOneTime.toString("mm:ss"), this);
    playerTwoLabel = new QLabel(playerTwoTime.toString("mm:ss"), this);
    playerOneLabel->setAlignment(Qt::AlignCenter);
    playerTwoLabel->setAlignment(Qt::AlignCenter);
    playerOneLabel->setStyleSheet("font-size: 30px; color: #4CAF50;");
    playerTwoLabel->setStyleSheet("font-size: 30px; color: #f44336;");

    // Player Progress Bars
    playerOneProgress = new QProgressBar(this);
    playerOneProgress->setRange(0, totalTime);
    playerOneProgress->setValue(totalTime);
    playerOneProgress->setTextVisible(false);  // Hide text in progress bar

    playerTwoProgress = new QProgressBar(this);
    playerTwoProgress->setRange(0, totalTime);
    playerTwoProgress->setValue(totalTime);
    playerTwoProgress->setTextVisible(false);

    // Status Label
    statusLabel = new QLabel("Select playtime and press start clock.", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("font-size: 18px; color: #333;");

    // Buttons
    switchPlayerOneButton = new QPushButton("Switch to player 1", this);
    switchPlayerTwoButton = new QPushButton("Switch to player 2", this);
    startButton = new QPushButton("Start Clock", this);
    stopButton = new QPushButton("Stop Clocks", this);
    fiveMinButton = new QPushButton("5 min", this);
    twoMinButton = new QPushButton("2 min", this);

    // Styling buttons and progress bars
    startButton->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px; border-radius: 5px;");
    stopButton->setStyleSheet("background-color: #f44336; color: white; padding: 10px; border-radius: 5px;");
    switchPlayerOneButton->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px; border-radius: 5px;");
    switchPlayerTwoButton->setStyleSheet("background-color: #f44336; color: white; padding: 10px; border-radius: 5px;");
    twoMinButton->setStyleSheet("background-color: #8BC34A; color: white; padding: 10px; border-radius: 5px;");
    fiveMinButton->setStyleSheet("background-color: #03A9F4; color: white; padding: 10px; border-radius: 5px;");
    playerOneProgress->setStyleSheet("QProgressBar { border: 2px solid #4CAF50; border-radius: 5px; text-align: center; }");
    playerTwoProgress->setStyleSheet("QProgressBar { border: 2px solid #f44336; border-radius: 5px; text-align: center; }");

    // Layouts
    QHBoxLayout *timeLayout = new QHBoxLayout();
    timeLayout->addWidget(playerOneLabel);
    timeLayout->addWidget(playerOneProgress);
    timeLayout->addStretch();
    timeLayout->addWidget(playerTwoProgress);
    timeLayout->addWidget(playerTwoLabel);

    QVBoxLayout *playerOneLayout = new QVBoxLayout();
    playerOneLayout->addWidget(playerOneLabel);
    playerOneLayout->addWidget(playerOneProgress);
    playerOneLayout->addWidget(switchPlayerOneButton);

    QVBoxLayout *playerTwoLayout = new QVBoxLayout();
    playerTwoLayout->addWidget(playerTwoLabel);
    playerTwoLayout->addWidget(playerTwoProgress);
    playerTwoLayout->addWidget(switchPlayerTwoButton);

    QHBoxLayout *playersLayout = new QHBoxLayout();
    playersLayout->addLayout(playerOneLayout);
    playersLayout->addStretch();
    playersLayout->addLayout(playerTwoLayout);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(timeLayout);
    layout->addLayout(playersLayout);
    layout->addWidget(statusLabel);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);
    layout->addWidget(twoMinButton);
    layout->addWidget(fiveMinButton);
    setLayout(layout);

    // Widget Styling
    setStyleSheet("background-color: #87CEFA; padding: 20px; border-radius: 10px;");

    connect(timer, &QTimer::timeout, this, &ChessClock::updateTime);
    connect(switchPlayerOneButton, &QPushButton::clicked, this, &ChessClock::switchToPlayerOne);
    connect(switchPlayerTwoButton, &QPushButton::clicked, this, &ChessClock::switchToPlayerTwo);
    connect(startButton, &QPushButton::clicked, this, &ChessClock::startClock);
    connect(stopButton, &QPushButton::clicked, this, &ChessClock::stopClock);
    connect(fiveMinButton, &QPushButton::clicked, this, &ChessClock::setFiveMinutes);
    connect(twoMinButton, &QPushButton::clicked, this, &ChessClock::setTwoMinutes);
}

void ChessClock::updateTime() {
    if (playerOneTime == QTime(0, 0) || playerTwoTime == QTime(0, 0)) {
        statusLabel->setText("Game Over!");
        stopClock();
        return;
    }

    if (playerOneTurn) {
        playerOneTime = playerOneTime.addSecs(-1);
        playerOneLabel->setText(playerOneTime.toString("mm:ss"));
        playerOneProgress->setValue(playerOneTime.minute() * 60 + playerOneTime.second());
    } else {
        playerTwoTime = playerTwoTime.addSecs(-1);
        playerTwoLabel->setText(playerTwoTime.toString("mm:ss"));
        playerTwoProgress->setValue(playerTwoTime.minute() * 60 + playerTwoTime.second());
    }
}

void ChessClock::switchToPlayerOne() {
    playerOneTurn = true;
}

void ChessClock::switchToPlayerTwo() {
    playerOneTurn = false;
}

void ChessClock::setFiveMinutes() {
    totalTime = 5 * 60;
    playerOneTime = QTime(0, 5, 0);
    playerTwoTime = QTime(0, 5, 0);
    playerOneLabel->setText(playerOneTime.toString("mm:ss"));
    playerTwoLabel->setText(playerTwoTime.toString("mm:ss"));
    playerOneProgress->setRange(0, totalTime);
    playerOneProgress->setValue(totalTime);
    playerTwoProgress->setRange(0, totalTime);
    playerTwoProgress->setValue(totalTime);
    statusLabel->setText("Ready to play");
}

void ChessClock::setTwoMinutes() {
    totalTime = 2 * 60;
    playerOneTime = QTime(0, 2, 0);
    playerTwoTime = QTime(0, 2, 0);
    playerOneLabel->setText(playerOneTime.toString("mm:ss"));
    playerTwoLabel->setText(playerTwoTime.toString("mm:ss"));
    playerOneProgress->setRange(0, totalTime);
    playerOneProgress->setValue(totalTime);
    playerTwoProgress->setRange(0, totalTime);
    playerTwoProgress->setValue(totalTime);
    statusLabel->setText("Ready to play");
}

void ChessClock::startClock() {
    if (!timer->isActive()) {
        timer->start(1000);
        statusLabel->setText("Game ongoing");
    }
}

void ChessClock::stopClock() {
    timer->stop();
    statusLabel->setText("Clocks Stopped! Press Start Clock to continue");
}
