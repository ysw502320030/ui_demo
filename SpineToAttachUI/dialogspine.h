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

#include <QComboBox>

#include "deviationlabel.h"

#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

using namespace QtCharts;
using namespace std;

namespace Ui {
class DialogSpine;
}

//class MainWindow;

typedef QList<QComboBox*> ComboBoxList;

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
    void UpdateSpine();
    void FocusToPreWidget();
    void FocusToNextWidget();

public:
    Ui::DialogSpine *ui;
    QChart *chart;
    QChartView *ChartView;
//    QSplineSeries *series;
    QWidget *vWidget;

    QTimer m_timer;

//    QSplineSeries *m_series;
//    QSplineSeries *m_series_2,*m_series_3,*m_series_4;

    QLineSeries *m_series, *m_series_2, *m_series_3, *m_series_4;

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

    int pointsNumForOneLine = 500;

    enum x_time_range{x_one_min =1,x_three_min=3,x_ten_min=10,x_thirty_min=30,x_sixty_min=60,
                      x_three_hour=180,x_ten_hour=600,x_thirty_hour=1800} xRange;

    int x_range_group[8] = {x_one_min,x_three_min,x_ten_min,x_thirty_min,x_sixty_min,x_three_hour,x_ten_hour,x_thirty_hour};

    ControlList graphSettingList;
    ComboBoxList yRangeWidgetList;

    int autoYRangePreLocation[4]={0};

    float yRangeFactor =0.9;
    int yRangeTotalTypes = 8;
    float yRangeGroup[8] = {0.1,0.3,1,3,10,30,100,300};

    float setRate[4],biasPercent[4],biasPencentGroup[5] = {0, 0.1, 0.5, 1, 1};

    QList<float> y_list, y_list_2,y_list_3,y_list_4;

    QTimer xRangeTimer;

    int movingIDX;

//    MainWindow *mWindow;

//    QQueue<Data_to_UI > q ;1

//    DialogTable mTable;

//    Datathread *mdatathread;

public:
//    void init_display_queue(QQueue<Data_to_UI> &myQueue);
    void EventFilterInit();
    void UpdateTextLabel();
    void CheckYRange(float rate1, float rate2, float rate3, float rate4);
    void CheckYRangeSub(float rate, int nIndex);
    void UpdateDeviationLabel();
    int  GetXRangeIndex();

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
    void CloseGraphSetting();
    void XRangeChangeSignal();

private slots:
    void on_comboBox_4_ch1Zoom_currentIndexChanged(int index);
    void on_comboBox_3_ch2Zoom_currentIndexChanged(int index);
    void on_comboBox_2_ch3Zoom_currentIndexChanged(int index);
    void on_comboBox_5_change_xRange_currentIndexChanged(int index);
    void on_pushButton_clr_clicked();
    void on_pushButton_exit_clicked();
//    void on_comboBox_4_ch1Zoom_currentIndexChanged(int index);
    void on_comboBox_ch4Zoom_currentIndexChanged(int index);
};

//#include <mainwindow.h>

extern DialogSpine *dialogSpine;

#endif // DIALOGSPINE_H
