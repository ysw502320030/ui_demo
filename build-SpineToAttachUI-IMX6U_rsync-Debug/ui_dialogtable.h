/********************************************************************************
** Form generated from reading UI file 'dialogtable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTABLE_H
#define UI_DIALOGTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogTable
{
public:
    QTableWidget *qTableWidget;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DialogTable)
    {
        if (DialogTable->objectName().isEmpty())
            DialogTable->setObjectName(QString::fromUtf8("DialogTable"));
        DialogTable->resize(930, 580);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogTable->sizePolicy().hasHeightForWidth());
        DialogTable->setSizePolicy(sizePolicy);
        qTableWidget = new QTableWidget(DialogTable);
        qTableWidget->setObjectName(QString::fromUtf8("qTableWidget"));
        qTableWidget->setGeometry(QRect(39, 0, 532, 281));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qTableWidget->sizePolicy().hasHeightForWidth());
        qTableWidget->setSizePolicy(sizePolicy1);
        qTableWidget->setMaximumSize(QSize(532, 281));
        lineEdit = new QLineEdit(DialogTable);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(370, 430, 113, 22));

        retranslateUi(DialogTable);

        QMetaObject::connectSlotsByName(DialogTable);
    } // setupUi

    void retranslateUi(QDialog *DialogTable)
    {
        DialogTable->setWindowTitle(QApplication::translate("DialogTable", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTable: public Ui_DialogTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTABLE_H
