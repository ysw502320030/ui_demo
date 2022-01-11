/********************************************************************************
** Form generated from reading UI file 'dialogspine.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSPINE_H
#define UI_DIALOGSPINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DialogSpine
{
public:

    void setupUi(QDialog *DialogSpine)
    {
        if (DialogSpine->objectName().isEmpty())
            DialogSpine->setObjectName(QString::fromUtf8("DialogSpine"));
        DialogSpine->resize(400, 300);

        retranslateUi(DialogSpine);

        QMetaObject::connectSlotsByName(DialogSpine);
    } // setupUi

    void retranslateUi(QDialog *DialogSpine)
    {
        DialogSpine->setWindowTitle(QCoreApplication::translate("DialogSpine", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSpine: public Ui_DialogSpine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSPINE_H
