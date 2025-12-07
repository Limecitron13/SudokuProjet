/********************************************************************************
** Form generated from reading UI file 'FenetrePrincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPRINCIPAL_H
#define UI_FENETREPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenetrePrincipal
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FenetrePrincipal)
    {
        if (FenetrePrincipal->objectName().isEmpty())
            FenetrePrincipal->setObjectName(QString::fromUtf8("FenetrePrincipal"));
        FenetrePrincipal->resize(800, 600);
        centralwidget = new QWidget(FenetrePrincipal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FenetrePrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FenetrePrincipal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        FenetrePrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(FenetrePrincipal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FenetrePrincipal->setStatusBar(statusbar);

        retranslateUi(FenetrePrincipal);

        QMetaObject::connectSlotsByName(FenetrePrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *FenetrePrincipal)
    {
        FenetrePrincipal->setWindowTitle(QCoreApplication::translate("FenetrePrincipal", "FenetrePrincipal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenetrePrincipal: public Ui_FenetrePrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPRINCIPAL_H
