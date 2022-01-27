#ifndef DIALOGTABLE2_H
#define DIALOGTABLE2_H

#include <QDialog>

#include "controltable.h"
#include <QKeyEvent>

#include "keyBoard.h"

#include "encoder.h"

namespace Ui {
class DialogTable2;
}

class DialogTable2 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTable2(QWidget *parent = nullptr);
    ~DialogTable2();

public:
    void keyPressEvent(QKeyEvent *e);

public slots:
    void LeftStepMove();
    void RightStepMove();

private:
    void createTable();

private:
    Ui::DialogTable2 *ui;
    ControlTable * table;
    keyBoard *newKeyBoard;
    QTimer encoderTimer;
    QTimer btnKeyTimer;
};

#endif // DIALOGTABLE2_H
