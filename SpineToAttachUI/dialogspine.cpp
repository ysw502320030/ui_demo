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


    m_series = new QSplineSeries(this);
    chart = new QChart();
    QPen green(Qt::red);
    m_series->setPen(green);
    m_series->append(m_x, m_y);
    chart->addSeries(m_series);
    chart->addAxis(m_axisX,Qt::AlignBottom);
    chart->addAxis(m_axisY,Qt::AlignLeft);

    chart->setTitle("Dynamic spline chart");
    chart->legend()->hide();
//    chart->setAnimationOptions(QChart::AllAnimations);

//    chart->setContentsMargins(0, 0, 0, 0);
////    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setBackgroundRoundness(0);
    chart->setMargins(QMargins());



    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(5);
    m_axisX->setRange(0, 10);
    m_axisY->setRange(-2, 10);
	m_axisY->setTitleText("Rate");

    ChartView = new QChartView(this);
    ChartView->setChart(chart);
    ChartView->setBackgroundBrush(Qt::white);

    container = new QVBoxLayout();
    container->addWidget(ChartView);
    container->setContentsMargins(0, 0, 0, 0);
    setLayout(container);
//    vWidget->setLayout(container);
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

        ui->toolButton->raise();
        ui->toolButton_2->raise();

        connect(ui->toolButton, SIGNAL(clicked()),
                         this, SLOT(enlarge_scale()));
        connect(ui->toolButton_2, SIGNAL(clicked()),
                         this, SLOT(shrink_scale()));

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


         static int count =0;
         static float zi = 0;
         zi = zi+0.1;
         qDebug() <<  "14 data handle" << zi;
         qreal x = chart->plotArea().width() / m_axisX->tickCount();
         qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
         m_x += y;
//          m_y = QRandomGenerator::global()->bounded(5) - 2.5;
         m_y = ui_data.rate[8];
//         m_y = zi+0.1;
         m_series->append(m_x, m_y);
         if (count++ >= m_axisX->tickCount())
             chart->scroll(x, 0);
//         if (m_x == 100)
//             m_timer.stop();

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
