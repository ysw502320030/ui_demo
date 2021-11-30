#ifndef DIALOGTABLE2_H
#define DIALOGTABLE2_H

#include <QDialog>

namespace Ui {
class DialogTable2;
}

class DialogTable2 : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTable2(QWidget *parent = nullptr);
    ~DialogTable2();

private:
    Ui::DialogTable2 *ui;
};

#endif // DIALOGTABLE2_H
