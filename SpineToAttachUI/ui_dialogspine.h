/********************************************************************************
** Form generated from reading UI file 'dialogspine.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSPINE_H
#define UI_DIALOGSPINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DialogSpine
{
public:
    QToolButton *toolButton;
    QToolButton *toolButton_2;

    void setupUi(QDialog *DialogSpine)
    {
        if (DialogSpine->objectName().isEmpty())
            DialogSpine->setObjectName(QString::fromUtf8("DialogSpine"));
        DialogSpine->resize(930, 580);
        toolButton = new QToolButton(DialogSpine);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 190, 21, 21));
        QFont font;
        font.setPointSize(20);
        toolButton->setFont(font);
        toolButton_2 = new QToolButton(DialogSpine);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(10, 220, 21, 21));
        toolButton_2->setFont(font);

        retranslateUi(DialogSpine);

        QMetaObject::connectSlotsByName(DialogSpine);
    } // setupUi

    void retranslateUi(QDialog *DialogSpine)
    {
        DialogSpine->setWindowTitle(QApplication::translate("DialogSpine", "Dialog", nullptr));
        toolButton->setText(QApplication::translate("DialogSpine", "+", nullptr));
        toolButton_2->setText(QApplication::translate("DialogSpine", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSpine: public Ui_DialogSpine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSPINE_H
