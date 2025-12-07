/********************************************************************************
** Form generated from reading UI file 'DialogGrilleValide.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGRILLEVALIDE_H
#define UI_DIALOGGRILLEVALIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogGrilleValide
{
public:
    QLabel *label;
    QPushButton *Ok;

    void setupUi(QDialog *DialogGrilleValide)
    {
        if (DialogGrilleValide->objectName().isEmpty())
            DialogGrilleValide->setObjectName(QString::fromUtf8("DialogGrilleValide"));
        DialogGrilleValide->resize(200, 100);
        DialogGrilleValide->setMinimumSize(QSize(200, 100));
        DialogGrilleValide->setMaximumSize(QSize(200, 100));
        label = new QLabel(DialogGrilleValide);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 181, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        Ok = new QPushButton(DialogGrilleValide);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setGeometry(QRect(110, 70, 80, 26));

        retranslateUi(DialogGrilleValide);
        QObject::connect(Ok, SIGNAL(clicked()), DialogGrilleValide, SLOT(accept()));

        QMetaObject::connectSlotsByName(DialogGrilleValide);
    } // setupUi

    void retranslateUi(QDialog *DialogGrilleValide)
    {
        DialogGrilleValide->setWindowTitle(QCoreApplication::translate("DialogGrilleValide", "DialogGrilleValide", nullptr));
        label->setText(QCoreApplication::translate("DialogGrilleValide", "La grille est valide !", nullptr));
        Ok->setText(QCoreApplication::translate("DialogGrilleValide", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogGrilleValide: public Ui_DialogGrilleValide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGRILLEVALIDE_H
