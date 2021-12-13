#ifndef DIALOGSPINE_H
#define DIALOGSPINE_H

#include <QDialog>

#include <QtCore/QTimer>
#include <QtCharts/QChart>
//#include "QChart"
#include <QtCharts/QCategoryAxis>

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
    void test_label_clicked();

public:
    Ui::DialogSpine *ui;
    QChart *chart;
    QChartView *ChartView;
    QSplineSeries *series;
    QWidget *vWidget;

    QTimer m_timer;
    QSplineSeries *m_series;

    QSplineSeries *m_series_2,*m_series_3,*m_series_4;

    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    QValueAxis *m_axisX2;
    QValueAxis *m_axisY2;

    QValueAxis *m_axisY3;
    QValueAxis *m_axisY4;

//    QCategoryAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;

    qreal m_x2,m_y2,m_x3,m_y3,m_x4,m_y4;

    qreal factorCH1,factorCH2,factorCH3,factorCH4;

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
private slots:
    void on_comboBox_4_ch1Zoom_currentIndexChanged(const QString &arg1);
    void on_comboBox_3_ch2Zoom_currentIndexChanged(const QString &arg1);
    void on_comboBox_2_ch3Zoom_currentIndexChanged(const QString &arg1);
};

#endif // DIALOGSPINE_H
