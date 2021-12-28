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

#include "controltable.h"

#include <QAbstractItemView>



using namespace QtCharts;
using namespace std;

namespace Ui {
class DialogSpine;
}

//class MainWindow;

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
    void FocusFirstWidget();

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

    QElapsedTimer timer_interval;

    int pointsForOneMin = 375;  //  60S/0.16S = 375

    enum x_time_range{x_one_min =1,x_three_min=3,x_ten_min=10,x_thirty_min=30,x_sixty_min=60,
                      x_three_hour=180,x_ten_hour=600,x_thirty_hour=1800} xRange;

    int x_range_group[8] = {x_one_min,x_three_min,x_ten_min,x_thirty_min,x_sixty_min,x_three_hour,x_ten_hour,x_thirty_hour};

//    MainWindow *mWindow;

//    QQueue<Data_to_UI > q ;1

//    DialogTable mTable;

//    Datathread *mdatathread;

public:
//    void init_display_queue(QQueue<Data_to_UI> &myQueue);
    void EventFilterInit();

private:
    ControlTable * table;

private:
    void createList();
    void keyPressEvent(QKeyEvent *e);
    bool eventFilter(QObject *watched, QEvent *event);
    void KeyRemapping(QKeyEvent *event);

signals:
//    void entry_added(QQueue<Data_to_UI > &mQueue);             // <-- the new signal
    void signal_to_handleTimeout();
private slots:
    void on_comboBox_4_ch1Zoom_currentIndexChanged(const QString &arg1);
    void on_comboBox_3_ch2Zoom_currentIndexChanged(const QString &arg1);
    void on_comboBox_2_ch3Zoom_currentIndexChanged(const QString &arg1);
    void on_comboBox_5_change_xRange_currentIndexChanged(int index);
    void on_pushButton_clr_clicked();
};

//#include <mainwindow.h>

extern DialogSpine *dialogSpine;

#endif // DIALOGSPINE_H
