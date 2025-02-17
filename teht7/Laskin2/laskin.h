#ifndef LASKIN_H
#define LASKIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class Laskin : public QWidget {
    Q_OBJECT

public:
    Laskin(QWidget *parent = nullptr);

private slots:
    void numberPressed();
    void operationPressed();
    void calculateResult();
    void clearFields();

private:
    QLineEdit *num1, *num2, *result;
    QPushButton *N0, *N1, *N2, *N3, *N4, *N5, *N6, *N7, *N8, *N9;
    QPushButton *add, *sub, *mul, *div;
    QPushButton *clear, *enter;

    QString currentOperator;
};

#endif // LASKIN_H
