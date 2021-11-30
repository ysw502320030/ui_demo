/********************************************************************************
** Form generated from reading UI file 'dialogtable2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTABLE2_H
#define UI_DIALOGTABLE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogTable2
{
public:
    QTableWidget *qTableWidget2;

    void setupUi(QDialog *DialogTable2)
    {
        if (DialogTable2->objectName().isEmpty())
            DialogTable2->setObjectName(QString::fromUtf8("DialogTable2"));
        DialogTable2->resize(852, 300);
        qTableWidget2 = new QTableWidget(DialogTable2);
        qTableWidget2->setObjectName(QString::fromUtf8("qTableWidget2"));
        qTableWidget2->setGeometry(QRect(-5, 1, 571, 301));

        retranslateUi(DialogTable2);

        QMetaObject::connectSlotsByName(DialogTable2);
    } // setupUi

    void retranslateUi(QDialog *DialogTable2)
    {
        DialogTable2->setWindowTitle(QApplication::translate("DialogTable2", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTable2: public Ui_DialogTable2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTABLE2_H
