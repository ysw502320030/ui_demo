/********************************************************************************
** Form generated from reading UI file 'dialogtable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTABLE_H
#define UI_DIALOGTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogTable
{
public:
    QTableWidget *qTableWidget;

    void setupUi(QDialog *DialogTable)
    {
        if (DialogTable->objectName().isEmpty())
            DialogTable->setObjectName(QString::fromUtf8("DialogTable"));
        DialogTable->resize(400, 300);
        qTableWidget = new QTableWidget(DialogTable);
        qTableWidget->setObjectName(QString::fromUtf8("qTableWidget"));
        qTableWidget->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(DialogTable);

        QMetaObject::connectSlotsByName(DialogTable);
    } // setupUi

    void retranslateUi(QDialog *DialogTable)
    {
        DialogTable->setWindowTitle(QCoreApplication::translate("DialogTable", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTable: public Ui_DialogTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTABLE_H
