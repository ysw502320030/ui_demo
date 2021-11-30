#ifndef DIALOGTABLE_H
#define DIALOGTABLE_H

#include <QDialog>
#include <QQueue>
#include "sharedvariable.h"
//#include "dialogspine.h"

//class DialogSpine;

#include "datathread.h"

namespace Ui {
class DialogTable;
}

class DialogTable : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTable(QWidget *parent = nullptr);
    ~DialogTable();
//    DialogSpine mSpine;
//    struct Data_to_UI
//    {
//        double freq_new_raw[10];
//        float thA[10];
//        float rate[10];
//        float delta_time;
//    };



signals:
    void test_signal_table();


private:
    Ui::DialogTable *ui;

public slots:
    void TableNotUpdate();
    void TableNotUpdate2();
//    void DataToTable(QQueue<Data_to_UI > &mQueue);
    void DataToTable();
};

#endif // DIALOGTABLE_H
