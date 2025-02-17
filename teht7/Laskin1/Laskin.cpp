#include "Laskin.h"

Laskin::Laskin(QWidget *parent) : QWidget(parent), count(0) {
    // Luodaan widgetit
    countButton = new QPushButton("Count", this);
    resetButton = new QPushButton("Reset", this);
    display = new QLineEdit(this);

    display->setText(QString::number(count));
    display->setReadOnly(true);

    resetButton->setEnabled(false); // Aluksi pois käytöstä

    // Asetetaan layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(countButton);
    layout->addWidget(resetButton);
    layout->addWidget(display);
    setLayout(layout);

    // Kytketään signaalit ja slotit
    connect(countButton, &QPushButton::clicked, this, &Laskin::incrementCount);
    connect(resetButton, &QPushButton::clicked, this, &Laskin::resetCount);

    // Ikkunan ominaisuudet
    setWindowTitle("Laskin");
    resize(200, 100);
}

void Laskin::incrementCount() {
    count++;
    display->setText(QString::number(count));
    resetButton->setEnabled(true);
}

void Laskin::resetCount() {
    count = 0;
    display->setText(QString::number(count));
    resetButton->setEnabled(false);
}
