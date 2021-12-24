#include "dialogspine.h"
#include "ui_dialogspine.h"


#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>
#include <QtWidgets/QLabel>

DialogSpine::DialogSpine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSpine),
    m_series(0),
    m_series_2(0),
    m_series_3(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(0),
    m_y(1)
{
    qDebug() << "spine" << "";
    ui->setupUi(this);

//    QObject::connect(&m_timer, &QTimer::timeout, this, &DialogSpine::handleTimeout);
//    m_timer.setInterval(1000);

//    QWidget* _widgetOnTheTop;
//    _widgetOnTheTop = new QLabel(this);
//    _widgetOnTheTop->setGeometry(10,10,100,35);
//    _widgetOnTheTop->show();



    setMinimumSize(300,200);
    QVBoxLayout *container;
    vWidget = new QWidget();

    m_axisX2 = new QValueAxis();
    m_axisY2 = new QValueAxis();

    m_axisY3 = new QValueAxis();
    m_axisY4 = new QValueAxis();

    m_series = new QSplineSeries(this);
    chart = new QChart();
    QPen green(Qt::green);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

    m_series_2 = new QSplineSeries(this);
    QPen black(Qt::black);
    m_series_2->setPen(black);
    m_series_2->append(m_x, m_y);

    m_series_3 = new QSplineSeries(this);
    QPen blue(Qt::blue);
    m_series_3->setPen(blue);
    m_series_3->append(m_x, m_y);

    chart->addSeries(m_series);
    chart->addSeries(m_series_2);
    chart->addSeries(m_series_3);

    chart->addAxis(m_axisX,Qt::AlignBottom);
    chart->addAxis(m_axisY,Qt::AlignLeft);

//    chart->addAxis(m_axisX2,Qt::AlignBottom);
    chart->addAxis(m_axisY2,Qt::AlignRight);
    chart->addAxis(m_axisY3,Qt::AlignLeft);
//    chart->addAxis(m_axisY4,Qt::AlignRight);

//    chart->setTitle("Dynamic spline chart");
    chart->legend()->hide();
//    chart->setAnimationOptions(QChart::AllAnimations);

//    chart->setContentsMargins(0, 0, 0, 0);
////    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setBackgroundRoundness(0);
    chart->setMargins(QMargins());



    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);

    m_series_2->attachAxis(m_axisX);
    m_series_2->attachAxis(m_axisY2);

    m_series_3->attachAxis(m_axisX);
    m_series_3->attachAxis(m_axisY3);

    m_series->setUseOpenGL(true);
    m_series_2->setUseOpenGL(true);
    m_series_3->setUseOpenGL(true);

    m_axisX->setTickCount(5);
//    m_axisX->setRange(0, 10);
    m_axisX->setRange(0, pointsForOneMin);

//    m_axisX2->setTickCount(5);
//    m_axisX2->setRange(0, 10);

    int maxY =10;
    m_axisY->setRange(-0.1, 1);
    m_axisY->setTickCount(12);
    m_axisY->setLabelFormat("%.3s");

    m_axisY2->setRange(-0.1, 1);
//    m_axisY2->setTickCount(12);
    m_axisY2->setLabelFormat("%.3s");

    m_axisY3->setRange(-0.1, 1);
//    m_axisY3->setTickCount(12);
    m_axisY3->setLabelFormat("%.3s");

//    m_axisY4->setRange(-0.1, 1);
//    m_axisY4->setTickCount(0);
//    m_axisY4->setLabelFormat("%.3s");

    m_axisY2->setGridLineVisible(false);
    m_axisY3->setGridLineVisible(false);
//    m_axisY4->setGridLineVisible(false);

//    m_axisY->setTickType(QValueAxis::TickType::TicksDynamic);
//    m_axisY->setTickAnchor(0);
//    m_axisY->setTickInterval(1);
//    m_axisY->setTickCount(6);

//    m_axisY->append(QString::number(-1), -1);

//    for(float i=0;i<=1;i=i+0.2)
//        m_axisY->append(QString::number(i*maxY), i*maxY);

//    m_axisY->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

//    m_axisY->append("slow", 0);
//    m_axisY->append("med", 5);
//    m_axisY->append("fast", 10);

//    m_axisY->

//	m_axisY->setTitleText("Rate");

    ChartView = new QChartView(this);
    ChartView->setChart(chart);
    ChartView->setBackgroundBrush(Qt::white);

    ui->horizontalLayoutWidget->setStyleSheet("background-color:gray;");
//    ui->widget->setStyleSheet("background-color:gray;");



    container = new QVBoxLayout();
    container->addWidget(ui->verticalLayoutWidget);
    container->addWidget(ChartView);
    container->addWidget(ui->horizontalLayoutWidget_2);
    container->addWidget(ui->gridLayoutWidget);
    container->addWidget(ui->horizontalLayoutWidget_3);
    container->addWidget(ui->horizontalLayoutWidget);
//    container->setContentsMargins(0, 0, 0, 0);


//    ui->verticalLayoutWidget->setStyleSheet("QComboBox::focus{ background: black; color: white;}");
    ui->verticalLayoutWidget->setStyleSheet("::focus{ background: black; color: white;}");
    ui->gridLayoutWidget->setStyleSheet("::focus{ background: black; color: white;}");
    setLayout(container);


//    connect(ui->label_6, SIGNAL(clicked()), this, SLOT(test_label_clicked()));

//    setCentralWidget(vWidget);

//#if __arm__
//    fd=::open("/temp_using/topeet", O_RDWR);
//    in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier, &QSocketNotifier::activated,
//        this, &DialogSpine::handle_readNotification);
//#else
//    fd=::open("/home/alientek/other/code/Qt/02/01_qfile/topeet", O_RDWR);
//    in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier, &QSocketNotifier::activated,
//        this, &DialogSpine::handleTimeout);
//    m_timer.start();
//#endif
    qDebug() << 9 << sizeof(float);
    if(fd < 0) {
        qDebug() << 10 << "open failed";
        qDebug() << "err" << strerror(errno);
        return;
    }

//    mdatathread = new Datathread;



//    connect(mdatathread,                             // emitter
//         &Datathread::test_signal,       // signal
//         this,                                // receiver
//         &DialogSpine::handleTimeout);  // slot

 //    connect(mdatathread,                             // emitter
 //        SIGNAL(test_signal()),       // signal
 //        this,                                // receiver
 //        SLOT(handleTimeout()));  // slot

//        connect(this,                             // emitter
//            SIGNAL(signal_to_handleTimeout()),       // signal
//            this,                                // receiver
//            SLOT(handleTimeout()));  // slot

//        QThread *thread = new QThread(this);
//        Datathread *worker = new Datathread;

        worker->moveToThread(mthread);
        connect(mthread, SIGNAL(started()), worker, SLOT(init_notifier()));

        connect(worker,                             // emitter
            SIGNAL(test_signal()),       // signal
            this,                                // receiver
            SLOT(handleTimeout()));  // slot
//        if(!mthread->isRunning())
        mthread->start();

//        connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
//        connect(worker, SIGNAL(finished()), mthread, SLOT(quit()));
//        connect(mthread, SIGNAL(finished()), mthread, SLOT(deleteLater()));
        qDebug() << "spine end" << "";
//        ui_data = {0};

//        QLabel* _widgetOnTheTop;
//        _widgetOnTheTop = new QLabel(this);
//        _widgetOnTheTop->setText("aka");
//        _widgetOnTheTop->setGeometry(10,10,100,35);
//        _widgetOnTheTop->show();
        factorCH1=1;factorCH2=1;factorCH3=1;factorCH4=1;
        ui->comboBox_4_ch1Zoom->setCurrentText("1");
        ui->comboBox_3_ch2Zoom->setCurrentText("1");
        ui->comboBox_2_ch3Zoom->setCurrentText("1");

//        ui->toolButton->raise();
//        ui->toolButton_2->raise();


        ui->widget->setStyleSheet("background-color:white;");
        ui->widget->raise();
        ui->widget_2->setStyleSheet("background-color:white;");
        ui->widget_2->raise();
        ui->label_72->raise();

        ui->label_73_YAxis->raise();

        connect(ui->toolButton, SIGNAL(clicked()),
                         this, SLOT(enlarge_scale()));
        connect(ui->toolButton_2, SIGNAL(clicked()),
                         this, SLOT(shrink_scale()));

        xRange = x_one_min;

        createList();

        ui->comboBox_4_ch1Zoom->view()->installEventFilter(this);

//        QWidget* _widgetOnTheTop1;
//        _widgetOnTheTop1 = new QPushButton(this);
//        _widgetOnTheTop1->setGeometry(30,30,150,150);
//        _widgetOnTheTop1->show();
 }

 DialogSpine::~DialogSpine()
 {
     delete ui;
 }

 void DialogSpine::handleTimeout()
 {
 //    qreal x = chart->plotArea().width() / m_axisX->tickCount();
 //    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
 //    m_x += y;
 //    m_y = QRandomGenerator::global()->bounded(5) - 2.5;
 //    m_series->append(m_x, m_y);
 //    chart->scroll(x, 0);
 //    if (m_x == 100)
 //        m_timer.stop();
 ////    mTable.TableNotUpdate2();
 ////    emit entry_added(q);


     //    struct Data_to_UI ui_data;

 //        ret = read(fd, &ui_data, sizeof(ui_data));
 //        if(ret >= 0){
 //            qDebug() << 11 << ui_data.freq_new_raw[8];
 ////            init_display_queue(q);
 //    //        if(q.size()<=3)
 //    //        {
 //    //            q.enqueue(ui_data);
 //    //            qDebug() << 12 << &q.head();
 //    //        }
 //        }
 //    //    textEdit->append(QString::number(ui_data.freq_new_raw[8]));

     static int interval_cout =0;

     interval_cout++;

//     if (interval_cout == 5)
//     {
         interval_cout=0;

         qDebug() << 19 << timer_interval.elapsed();
         timer_interval.start();
         qDebug() << 20 << chart->plotArea().width();


         static ulong count =0;
//         static float zi = 0;
//         zi = zi+0.1;
//         qDebug() <<  "14 data handle" << zi;
         qreal x = chart->plotArea().width() / m_axisX->tickCount();
         qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
         m_x += y;
         m_x2 += y;
//          m_y = QRandomGenerator::global()->bounded(5) - 2.5;
         m_y = ui_data.rate[8];
         m_y2 = ui_data.rate[9];
         m_y3 = ui_data.rate[7];
//         m_y = zi+0.1;
//         m_series->append(m_x, m_y);
//         m_series_2->append(m_x2, m_y2);
//         m_series_3->append(m_x, m_y3);

         m_series->append(count, m_y);
         m_series_2->append(count, m_y2);
         m_series_3->append(count, m_y3);

         if (count++ >= pointsForOneMin*xRange)
             chart->scroll(chart->plotArea().width()/pointsForOneMin/xRange, 0);

//         if (count++ >= m_axisX->tickCount())
//             chart->scroll(x, 0);

//         if (m_x == 100)
//             m_timer.stop();
//      }
 }

// void DialogSpine::inform_handleTimeout()
// {
//     emit signal_to_handleTimeout();

// }


// void DialogSpine::init_display_queue(QQueue<Data_to_UI> &myQueue)
// {
////     if(myQueue.size()<=3)
////     {
////         myQueue.enqueue(ui_data);
////         qDebug() << 12 << &myQueue.head();
////     }
////     if(myQueue.size() == 4)
////     {
////         //display the 4 node to table
//// //        emit entry_added(myQueue);
////         //delete the end,ie.the oldest one
////         myQueue.dequeue();
////     }

//// //    mTable.TableNotUpdate2();


// }

 void DialogSpine::handle_readNotification(int /*socket*/)
 {
// //    float databuf[16];
// //    struct Data_to_UI ui_data;

//     ret = read(fd, &ui_data, sizeof(ui_data));
//     if(ret >= 0){
//         qDebug() << 11 << ui_data.freq_new_raw[8];
//         init_display_queue(q);
// //        if(q.size()<=3)
// //        {
// //            q.enqueue(ui_data);
// //            qDebug() << 12 << &q.head();
// //        }
//     }
// //    textEdit->append(QString::number(ui_data.freq_new_raw[8]));


//     static int count =0;
//     qreal x = chart->plotArea().width() / m_axisX->tickCount();
//     qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
//     m_x += y;
// //	  m_y = QRandomGenerator::global()->bounded(5) - 2.5;
//     m_y = ui_data.rate[8];
//     m_series->append(m_x, m_y);
//     if (count++ >= m_axisX->tickCount())
//         chart->scroll(x, 0);
//     if (m_x == 100)
//         m_timer.stop();


 }

 void DialogSpine::enlarge_scale()
 {

    qDebug() << 15 << "enlarge lable + clicked";
    maxCurrent = m_axisY->max()/factor;
    chart->axisY()->setRange(minCurrent, maxCurrent);
 }

 void DialogSpine::shrink_scale()
 {

    qDebug() << 15 << "shrink lable + clicked";
    maxCurrent = m_axisY->max()*factor;
    chart->axisY()->setRange(minCurrent, maxCurrent);
 }
void DialogSpine::test_label_clicked()
{
    qDebug() << 16 << "label + clicked";
}

void DialogSpine::on_comboBox_4_ch1Zoom_currentIndexChanged(const QString &arg1)
{
    float maxY = arg1.toFloat();
    qDebug() << 16 << maxY;

    m_axisY->setTickCount(12);

    m_axisY->setRange(-0.1*maxY, maxY);

//    m_axisY->setLabelFormat("%.3s");

//    m_axisY->setLabelsVisible(true);


//    m_axisY->setTick

//    factorCH1 = 1 / maxY;

//    qDebug() << 17 << factorCH1;

//    m_axisY->append(QString::number(-0.1*maxY), -0.1*maxY);

//    for(float i=0;i<=1;i=i+0.2)
//        m_axisY->append(QString::number(i*maxY), i*maxY);

//    m_axisY->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

}

void DialogSpine::on_comboBox_3_ch2Zoom_currentIndexChanged(const QString &arg1)
{
    float maxY = arg1.toFloat();
    qDebug() << 17 << maxY;

//    m_axisY2->setTickCount(12);

    m_axisY2->setRange(-0.1*maxY, maxY);
}

void DialogSpine::on_comboBox_2_ch3Zoom_currentIndexChanged(const QString &arg1)
{
    float maxY = arg1.toFloat();
    qDebug() << 18 << maxY;

//    m_axisY3->setTickCount(12);

    m_axisY3->setRange(-0.1*maxY, maxY);
}

void DialogSpine::on_comboBox_5_change_xRange_currentIndexChanged(int index)
{
    xRange =(x_time_range) x_range_group[index];
    m_axisX->setRange(0, pointsForOneMin*xRange);
}

void DialogSpine::createList()
{
    ControlList graphSettingList;

    graphSettingList  << ui->comboBox_yRangeSel << ui->comboBox_deviation
                      << ui->comboBox_5_change_xRange
                      << ui->comboBox_4_ch1Zoom << ui->comboBox_3_ch2Zoom
                      << ui->comboBox_2_ch3Zoom << ui->comboBox_ch4Zoom
                      << ui->pushButton_clr << ui->pushButton_exit;

    table = new ControlTable(this);
    table->setTableWhole(graphSettingList);

    ui->horizontalLayout_graphics->installEventFilter(this);
//    ui->comboBox_4_ch1Zoom->view()->setMin
//    ui->hori
}

void DialogSpine::keyPressEvent(QKeyEvent *e)
{
    this->grabKeyboard();
    if (e->key()==Qt::Key_F1)
    {
        this->releaseKeyboard();

        QWidget *widget2 = QApplication::focusWidget();
        QString widgetName = widget2->metaObject()->className();
        if(QString("QComboBoxListView") == widget2->metaObject()->className())
        {
            qDebug() << "37" << 37;
            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, event);
            return;
        }

        table->toUpWhole();
    }
    else if (e->key()==Qt::Key_F2)
    {
        this->releaseKeyboard();

        QWidget *widget2 = QApplication::focusWidget();
        QString widgetName = widget2->metaObject()->className();
        if(QString("QComboBoxListView") == widget2->metaObject()->className())
        {
            qDebug() << "37" << 37;
            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, event);
            return;
        }

        table->toDownWhole();
    }
}

bool DialogSpine::eventFilter(QObject *watched, QEvent *event)
{
    if(QString("QComboBoxListView") == watched->metaObject()->className())
    {
        if(event->type()==QEvent::KeyPress)
        {
            qDebug() << "38" << 38;
            KeyRemapping((QKeyEvent *)event);
        }
    }
}

void DialogSpine::KeyRemapping(QKeyEvent *event)
{
    this->grabKeyboard();
    QKeyEvent *mKeyPress = (QKeyEvent *)event;
    if(mKeyPress->key()==Qt::Key_F1)
    {
//        this->releaseKeyboard();
        qDebug() << "F1" << 36;
        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
        QWidget *widget1 = QApplication::focusWidget();
        QCoreApplication::postEvent ((QObject*)widget1, event);
        qDebug() << "focused widget " << widget1;
    }

    else if (mKeyPress->key()==Qt::Key_F2)
    {
//        this->releaseKeyboard();
        qDebug() << "F2" << 36;
        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
        QWidget *widget1 = QApplication::focusWidget();
        QCoreApplication::postEvent ((QObject*)widget1, event);
        qDebug() << "focused widget " << widget1;
    }
}

//void DialogSpine::FocusFirstWidget()
//{

//}
