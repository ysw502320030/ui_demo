#ifndef DIALOGSPINE_H
#define DIALOGSPINE_H

#include <QDialog>

#include <QtCore/QTimer>
#include <QtCharts/QChart>
//#include "QChart"

#include "QVBoxLayout"
//#include "QChart"
#include "QChartView"
#include "QSplineSeries"

#include <QtCore/QTimer>
#include <QTextEdit>
#include <QFile>
#include <QPushButton>
#include <QSocketNotifier>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

//#include <QQueue>

//#include "dialogtable.h"
#include "sharedvariable.h"
#include "datathread.h"

using namespace QtCharts;
using namespace std;

namespace Ui {
class DialogSpine;
}

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

class DialogSpine : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSpine(QWidget *parent = nullptr);
    ~DialogSpine();

public slots:
    void handleTimeout();
    void handle_readNotification(int socket);
//    void inform_handleTimeout();
    void enlarge_scale();
    void shrink_scale();

public:
    Ui::DialogSpine *ui;
    QChart *chart;
    QChartView *ChartView;
    QSplineSeries *series;
    QWidget *vWidget;

    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;

//    struct Data_to_UI
//    {
//        double freq_new_raw[10];
//        float thA[10];
//        float rate[10];
//        float delta_time;
//    };

//    struct Data_to_UI ui_data;
//    struct Data_to_UI *ui_data2;

    QSocketNotifier *in_fifo_notifier;

    int ret = 0;
    int fd;

    const double minCurrent = -2;
          double maxCurrent = 0;
    const float factor = 2;

//    QQueue<Data_to_UI > q ;

//    DialogTable mTable;

//    Datathread *mdatathread;

public:
//    void init_display_queue(QQueue<Data_to_UI> &myQueue);

signals:
//    void entry_added(QQueue<Data_to_UI > &mQueue);             // <-- the new signal
    void signal_to_handleTimeout();
};

#endif // DIALOGSPINE_H
