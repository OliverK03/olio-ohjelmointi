/********************************************************************************
** Form generated from reading UI file 'Laskin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASKIN_H
#define UI_LASKIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Laskin
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Laskin)
    {
        if (Laskin->objectName().isEmpty())
            Laskin->setObjectName("Laskin");
        Laskin->resize(800, 600);
        centralwidget = new QWidget(Laskin);
        centralwidget->setObjectName("centralwidget");
        Laskin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Laskin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Laskin->setMenuBar(menubar);
        statusbar = new QStatusBar(Laskin);
        statusbar->setObjectName("statusbar");
        Laskin->setStatusBar(statusbar);

        retranslateUi(Laskin);

        QMetaObject::connectSlotsByName(Laskin);
    } // setupUi

    void retranslateUi(QMainWindow *Laskin)
    {
        Laskin->setWindowTitle(QCoreApplication::translate("Laskin", "Laskin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Laskin: public Ui_Laskin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASKIN_H
