#ifndef DIALOGTABLE2_H
#define DIALOGTABLE2_H

#include <QDialog>

#include "controltable.h"
#include <QKeyEvent>

#include "keyBoard.h"

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

private:
    void createTable();

private:
    Ui::DialogTable2 *ui;
    ControlTable * table;
    keyBoard *newKeyBoard;
};

#endif // DIALOGTABLE2_H
