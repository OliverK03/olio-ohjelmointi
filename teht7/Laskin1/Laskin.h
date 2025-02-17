#ifndef LASKIN_H
#define LASKIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class Laskin : public QWidget {
    Q_OBJECT

public:
    Laskin(QWidget *parent = nullptr);

private slots:
    void incrementCount();
    void resetCount();

private:
    int count;
    QPushButton *countButton;
    QPushButton *resetButton;
    QLineEdit *display;
};

#endif // LASKIN_H
