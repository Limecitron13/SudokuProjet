/********************************************************************************
** Form generated from reading UI file 'DialogGrilleInvalide.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGRILLEINVALIDE_H
#define UI_DIALOGGRILLEINVALIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogGrilleInvalide
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QPushButton *Ok;

    void setupUi(QDialog *DialogGrilleInvalide)
    {
        if (DialogGrilleInvalide->objectName().isEmpty())
            DialogGrilleInvalide->setObjectName(QString::fromUtf8("DialogGrilleInvalide"));
        DialogGrilleInvalide->resize(200, 100);
        DialogGrilleInvalide->setMinimumSize(QSize(200, 100));
        DialogGrilleInvalide->setMaximumSize(QSize(200, 100));
        buttonBox = new QDialogButtonBox(DialogGrilleInvalide);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogGrilleInvalide);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 181, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        label->setFont(font);
        Ok = new QPushButton(DialogGrilleInvalide);
        Ok->setObjectName(QString::fromUtf8("Ok"));
        Ok->setGeometry(QRect(120, 70, 80, 24));

        retranslateUi(DialogGrilleInvalide);
        QObject::connect(Ok, SIGNAL(clicked()), DialogGrilleInvalide, SLOT(accept()));

        QMetaObject::connectSlotsByName(DialogGrilleInvalide);
    } // setupUi

    void retranslateUi(QDialog *DialogGrilleInvalide)
    {
        DialogGrilleInvalide->setWindowTitle(QCoreApplication::translate("DialogGrilleInvalide", "DialogGrilleInvalide", nullptr));
        label->setText(QCoreApplication::translate("DialogGrilleInvalide", "La grille est invalide !", nullptr));
        Ok->setText(QCoreApplication::translate("DialogGrilleInvalide", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogGrilleInvalide: public Ui_DialogGrilleInvalide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGRILLEINVALIDE_H
