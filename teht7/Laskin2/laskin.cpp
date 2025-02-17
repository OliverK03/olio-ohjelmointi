#include "Laskin.h"
#include <QHBoxLayout>

Laskin::Laskin(QWidget *parent) : QWidget(parent), currentOperator("") {
    // **Labelit**
    QLabel *label1 = new QLabel("Number 1:");
    QLabel *label2 = new QLabel("Number 2:");
    QLabel *labelResult = new QLabel("Result:");

    // **Numerokentät**
    num1 = new QLineEdit();
    num2 = new QLineEdit();
    result = new QLineEdit();
    result->setReadOnly(true);  // Estetään tuloksen muokkaus

    // **Numeronapit**
    N0 = new QPushButton("0"); N1 = new QPushButton("1");
    N2 = new QPushButton("2"); N3 = new QPushButton("3");
    N4 = new QPushButton("4"); N5 = new QPushButton("5");
    N6 = new QPushButton("6"); N7 = new QPushButton("7");
    N8 = new QPushButton("8"); N9 = new QPushButton("9");

    // **Operaationapit**
    add = new QPushButton("+");
    sub = new QPushButton("-");
    mul = new QPushButton("*");
    div = new QPushButton("/");

    // **Toimintonapit**
    clear = new QPushButton("Clear");
    enter = new QPushButton("Enter");

    // **Layout**
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(label1, 0, 0);
    grid->addWidget(num1, 0, 1, 1, 3);
    grid->addWidget(label2, 1, 0);
    grid->addWidget(num2, 1, 1, 1, 3);
    grid->addWidget(labelResult, 2, 0);
    grid->addWidget(result, 2, 1, 1, 3);

    // **Numeronapit**
    grid->addWidget(N7, 3, 0);
    grid->addWidget(N8, 3, 1);
    grid->addWidget(N9, 3, 2);
    grid->addWidget(N4, 4, 0);
    grid->addWidget(N5, 4, 1);
    grid->addWidget(N6, 4, 2);
    grid->addWidget(N1, 5, 0);
    grid->addWidget(N2, 5, 1);
    grid->addWidget(N3, 5, 2);
    grid->addWidget(N0, 6, 1);

    // **Operaatiot**
    grid->addWidget(add, 3, 3);
    grid->addWidget(sub, 4, 3);
    grid->addWidget(mul, 5, 3);
    grid->addWidget(div, 6, 3);

    // **Toimintonapit**
    grid->addWidget(clear, 6, 0);
    grid->addWidget(enter, 6, 2);

    setLayout(grid);
    setWindowTitle("Laskin");

    // **Signaalien yhdistäminen**
    QList<QPushButton*> numberButtons = {N0, N1, N2, N3, N4, N5, N6, N7, N8, N9};
    for (QPushButton *button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &Laskin::numberPressed);
    }

    QList<QPushButton*> opButtons = {add, sub, mul, div};
    for (QPushButton *button : opButtons) {
        connect(button, &QPushButton::clicked, this, &Laskin::operationPressed);
    }

    connect(enter, &QPushButton::clicked, this, &Laskin::calculateResult);
    connect(clear, &QPushButton::clicked, this, &Laskin::clearFields);
}

// **Numeroiden lisääminen syötekenttään**
void Laskin::numberPressed() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    // Jos num2 on valittu (eli operaation jälkeen), lisää sinne, muuten num1
    if (num2->hasFocus() || !currentOperator.isEmpty()) {
        num2->setText(num2->text() + button->text());
    } else {
        num1->setText(num1->text() + button->text());
    }
}


// **Operaation tallentaminen**
void Laskin::operationPressed() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    currentOperator = button->text();
    result->setText(currentOperator);  // Näytetään valittu operaatio

    // Siirretään kohdistus num2-kenttään
    num2->setFocus();
}



// **Laskutoimituksen suorittaminen**
void Laskin::calculateResult() {
    if (num1->text().isEmpty() || num2->text().isEmpty() || currentOperator.isEmpty()) {
        result->setText("Error");
        return;
    }

    double n1 = num1->text().toDouble();
    double n2 = num2->text().toDouble();
    double res = 0.0;

    if (currentOperator == "+") res = n1 + n2;
    else if (currentOperator == "-") res = n1 - n2;
    else if (currentOperator == "*") res = n1 * n2;
    else if (currentOperator == "/") {
        if (n2 == 0) {
            result->setText("Div by 0");
            return;
        }
        res = n1 / n2;
    }

    result->setText(QString::number(res));

    // Siirretään syöttö takaisin num1-kenttään uuden laskun aloittamista varten
    num1->setFocus();
}



// **Syötteiden tyhjentäminen**
void Laskin::clearFields() {
    num1->clear();
    num2->clear();
    result->clear();
    currentOperator.clear();
    num1->setFocus();  // Siirretään fokus takaisin num1-kenttään
}

