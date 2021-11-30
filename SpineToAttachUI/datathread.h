#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QtCore>
#include <QtCore/QTimer>
#include "sharedvariable.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <QSocketNotifier>
#include <QThread>

//#include "dialogspine.h"
//#include "dialogtable.h"

class Datathread : public QObject
{
    Q_OBJECT
public:
    Datathread();

public slots:
    void dataObtained();
    void init_notifier();
public:
    QTimer m_timer;

//    struct Data_to_UI ui_data;
//    struct Data_to_UI *ui_data2;

    QSocketNotifier *in_fifo_notifier;

    int ret = 0;
    int fd;

//    QQueue<Data_to_UI > q ;

//    DialogTable *mtable;

public:
    void init_display_queue(QQueue<Data_to_UI> &myQueue);

signals:
    void entry_data_to_spine();
    void test_signal();
//    void signal_to_table(QQueue<Data_to_UI> &myQueue);
    void signal_to_table();

};

extern Datathread *worker;
extern QThread *mthread;

#endif // DATATHREAD_H
