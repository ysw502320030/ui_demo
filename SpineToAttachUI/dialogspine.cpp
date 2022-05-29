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

    OutPutInfo("spine");
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

//    m_series = new QSplineSeries(this);
    m_series = new QLineSeries(this);
    chart = new QChart();
    QPen green(Qt::green);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

//    m_series_2 = new QSplineSeries(this);
    m_series_2 = new QLineSeries(this);
    QPen black(Qt::gray);
    m_series_2->setPen(black);
    m_series_2->append(m_x, m_y);

//    m_series_3 = new QSplineSeries(this);
    m_series_3 = new QLineSeries(this);
    QPen blue(Qt::blue);
    m_series_3->setPen(blue);
    m_series_3->append(m_x, m_y);

//    m_series_4 = new QSplineSeries(this);
    m_series_4 = new QLineSeries(this);
    QPen yellow(Qt::cyan);
    m_series_4->setPen(yellow);
    m_series_4->append(m_x, m_y);

    chart->addSeries(m_series);
    chart->addSeries(m_series_2);
    chart->addSeries(m_series_3);
    chart->addSeries(m_series_4);

    chart->addAxis(m_axisX,Qt::AlignBottom);
    chart->addAxis(m_axisY,Qt::AlignLeft);

//    chart->addAxis(m_axisX2,Qt::AlignBottom);
    chart->addAxis(m_axisY2,Qt::AlignRight);
    chart->addAxis(m_axisY3,Qt::AlignLeft);
    chart->addAxis(m_axisY4,Qt::AlignRight);

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

    m_series_4->attachAxis(m_axisX);
    m_series_4->attachAxis(m_axisY4);

//    m_series->setUseOpenGL(true);
//    m_series_2->setUseOpenGL(true);
//    m_series_3->setUseOpenGL(true);
//    m_series_4->setUseOpenGL(true);

    m_axisX->setTickCount(5);
//    m_axisX->setRange(0, 10);
    m_axisX->setRange(0, pointsNumForOneLine);

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

    m_axisY4->setRange(-0.1, 1);
//    m_axisY4->setTickCount(0);
    m_axisY4->setLabelFormat("%.3s");

    m_axisY2->setGridLineVisible(false);
    m_axisY3->setGridLineVisible(false);
    m_axisY4->setGridLineVisible(false);

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

    ui->verticalLayoutWidget->setStyleSheet("::focus{ background: gray; color: white;}");
    ui->gridLayoutWidget->setStyleSheet("::focus{ background: gray; color: white;}");
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
    OutPutInfo("sizeof(float) %d", sizeof(float));
    if(fd < 0) {
        OutPutInfo("open failed");
        OutPutInfo("err %s", strerror(errno));
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

        connect(this, SIGNAL(XRangeChangeSignal()),worker, SLOT(OnXRangeChanged()));

        connect(worker, SIGNAL(CoordinateDataPrepared()),this, SLOT(UpdateSpine()));

//        if(!mthread->isRunning())
        mthread->start();

//        connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
//        connect(worker, SIGNAL(finished()), mthread, SLOT(quit()));
//        connect(mthread, SIGNAL(finished()), mthread, SLOT(deleteLater()));
        OutPutInfo("spine end");
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

        EventFilterInit();

        yRangeWidgetList<< ui->comboBox_4_ch1Zoom << ui->comboBox_3_ch2Zoom
                     << ui->comboBox_2_ch3Zoom << ui->comboBox_ch4Zoom;

        ui->comboBox_yRangeSel->setCurrentText("Auto/OFF");

//        ui->horizontalLayoutWidget_4->raise();
        ui->label_deviation1->raise();

        ui->label_deviation_test->raise();
        ui->label_deviation_test_2->raise();
        ui->label_deviation_test_3->raise();
        ui->label_deviation_test_4->raise();


//        RevealDeviationLabel();

        ui->label_setRate1->setText("2");
        ui->label_64_SettingRateCH2->setText("11");
        ui->label_51_SettingRateCH3->setText("21");
        ui->label_36_SettingRateCH4->setText("25");
//        ui->label_36_SettingRateCH4->setText();

        setRate[0] = ui->label_setRate1->text().toFloat();
        setRate[1] = ui->label_64_SettingRateCH2->text().toFloat();
        setRate[2] = ui->label_51_SettingRateCH3->text().toFloat();
        setRate[3] = ui->label_36_SettingRateCH4->text().toFloat();

        ui->comboBox_5_change_xRange->setCurrentIndex(2);

        movingIDX = 0;

        ui->label_layer_th_setval->setText("15");

        qDebug("size of data_to_ui is %d \n", sizeof(ui_data));

        thState = th_normal;

//        QObject::connect(&xRangeTimer, &QTimer::timeout, this, &DialogSpine::UpdateSpine);
//        xRangeTimer.setInterval(120*10);
//        xRangeTimer.start();

//        ui->comboBox_4_ch1Zoom->view()->installEventFilter(this);

//        QWidget* _widgetOnTheTop1;
//        _widgetOnTheTop1 = new QPushButton(this);
//        _widgetOnTheTop1->setGeometry(30,30,150,150);
//        _widgetOnTheTop1->show();
//        FocusFirstWidget();
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

         //qDebug() << 19 << timer_interval.elapsed();
         //timer_interval.start();
         OutPutInfo("chart->plotArea().width() .2f" ,chart->plotArea().width());


         static ulong count =0;
//         static float zi = 0;
//         zi = zi+0.1;
//         qDebug() <<  "14 data handle" << zi;
         qreal x = chart->plotArea().width() / m_axisX->tickCount();
         qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
         m_x += y;
         m_x2 += y;
//          m_y = QRandomGenerator::global()->bounded(5) - 2.5;
         m_y = ui_data.rate[1];
         m_y2 = ui_data.rate[9];
         m_y3 = ui_data.rate[7];
//         m_y = zi+0.1;
//         m_series->append(m_x, m_y);
//         m_series_2->append(m_x2, m_y2);
//         m_series_3->append(m_x, m_y3);


         y_list.append(m_y);
         y_list_2.append(m_y2);
         y_list_3.append(m_y3);

         if(y_list.length()>pointsForOneMin+1)
         {
             y_list.removeFirst();
             y_list_2.removeFirst();
             y_list_3.removeFirst();
         }

         QList<QPointF> points,points_2,points_3;
         points.clear();
         points_2.clear();
         points_3.clear();

         for(int i=0;i<y_list.length();i++)
         {

             points.append(QPointF(i,y_list.at(i)));
             points_2.append(QPointF(i,y_list_2.at(i)));
             points_3.append(QPointF(i,y_list_3.at(i)));

//             queuePoints.enqueue(QPointF(i,q.at(i)));
         }

         m_series->replace(points);
         m_series_2->replace(points_2);
         m_series_3->replace(points_3);


//         m_series->append(count, m_y);
//         m_series_2->append(count, m_y2);
//         m_series_3->append(count, m_y3);

//         if (count++ >= pointsForOneMin*xRange)
//             chart->scroll(chart->plotArea().width()/pointsForOneMin/xRange, 0);

////         if (count++ >= m_axisX->tickCount())
////             chart->scroll(x, 0);

////         if (m_x == 100)
////             m_timer.stop();
////      }

         UpdateTextLabel();

         if(ui->comboBox_yRangeSel->currentIndex() == 0)    //AutoRangeYIsON
            CheckYRange(ui_data.rate[1],ui_data.rate[9],ui_data.rate[7],0);

         if(ui->comboBox_deviation->currentIndex() != 0)
            UpdateDeviationLabel();

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

    OutPutInfo("enlarge lable + clicked");
    maxCurrent = m_axisY->max()/factor;
    chart->axisY()->setRange(minCurrent, maxCurrent);
 }

 void DialogSpine::shrink_scale()
 {

    OutPutInfo( "shrink lable + clicked");
    maxCurrent = m_axisY->max()*factor;
    chart->axisY()->setRange(minCurrent, maxCurrent);
 }
void DialogSpine::test_label_clicked()
{
    OutPutInfo( "label + clicked");
}

void DialogSpine::on_comboBox_4_ch1Zoom_currentIndexChanged(int index)
{
//    float maxY = arg1.toFloat();
    float maxY = yRangeGroup[index];
    OutPutInfo("maxY %.2f", maxY);

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

void DialogSpine::on_comboBox_3_ch2Zoom_currentIndexChanged(int index)
{
//    float maxY = arg1.toFloat();
    float maxY = yRangeGroup[index];
    OutPutInfo("maxY %.2f", maxY);

//    m_axisY2->setTickCount(12);

    m_axisY2->setRange(-0.1*maxY, maxY);
}

void DialogSpine::on_comboBox_2_ch3Zoom_currentIndexChanged(int index)
{
//    float maxY = arg1.toFloat();
    float maxY = yRangeGroup[index];
    OutPutInfo("maxY %.2f", maxY);

//    m_axisY3->setTickCount(12);

    m_axisY3->setRange(-0.1*maxY, maxY);
}

void DialogSpine::on_comboBox_5_change_xRange_currentIndexChanged(int index)
{
//    xRange =(x_time_range) x_range_group[index];
//    m_axisX->setRange(0, pointsForOneMin*xRange);

//    xRangeTimer.stop();

//    UpdateSpine();

//    switch (index) {
//    case 0:
//        xRangeTimer.setInterval(120);
//        break;
//    case 1:
//        xRangeTimer.setInterval(360);
//        break;
//    case 2:
//        xRangeTimer.setInterval(1200);
//        break;
//    case 3:
//        xRangeTimer.setInterval(3600);
//        break;
//    case 4:
//        xRangeTimer.setInterval(7200);
//        break;
//    case 5:
//        xRangeTimer.setInterval(120*180);
//        break;
//    case 6:
//        xRangeTimer.setInterval(120*600);
//        break;
//    case 7:
//        xRangeTimer.setInterval(120*1800);
//        break;
//    default:
//        OutPutInfo() << "abnormal selection";
//        break;
//    }

//    xRangeTimer.start();

    emit XRangeChangeSignal();
}

void DialogSpine::createList()
{
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
            OutPutInfo("37");
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
            OutPutInfo("37");
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
            OutPutInfo("38");
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
        OutPutInfo("F1");
        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
        QWidget *widget1 = QApplication::focusWidget();
        QCoreApplication::postEvent ((QObject*)widget1, event);
        qDebug() << "focused widget " << widget1;
    }

    else if (mKeyPress->key()==Qt::Key_F2)
    {
//        this->releaseKeyboard();
        OutPutInfo("F2");
        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
        QWidget *widget1 = QApplication::focusWidget();
        QCoreApplication::postEvent ((QObject*)widget1, event);
        qDebug() << "focused widget " << widget1;
    }
}

void DialogSpine::FocusFirstWidget()
{
  ui->comboBox_yRangeSel->setFocus();
}

void DialogSpine::on_pushButton_clr_clicked()
{
//    ui->comboBox_4_ch1Zoom->setFocus();
    OutPutInfo("CLR button been clicked ");
}

void DialogSpine::EventFilterInit()
{
    ui->comboBox_yRangeSel->view()->installEventFilter(this);
    ui->comboBox_deviation->view()->installEventFilter(this);
    ui->comboBox_5_change_xRange->view()->installEventFilter(this);
    ui->comboBox_4_ch1Zoom->view()->installEventFilter(this);
    ui->comboBox_3_ch2Zoom->view()->installEventFilter(this);
    ui->comboBox_2_ch3Zoom->view()->installEventFilter(this);
    ui->comboBox_ch4Zoom->view()->installEventFilter(this);
}

void DialogSpine::on_pushButton_exit_clicked()
{
    table->selectControl(graphSettingList[0]);
    emit CloseGraphSetting();
}

void DialogSpine::UpdateTextLabel()
{

    OutPutInfo("the elapsed time for text updating is %.2f" , timer_interval.elapsed());
    ui->label_senPct1->setText(QString::number(timer_interval.elapsed(), 'f', 3));
    timer_interval.start();

    ui->label_rate1->setText(QString::number(ui_data.rate[1], 'f', 2));
    ui->label_63_RateCH2->setText(QString::number(ui_data.rate[9], 'f', 2));
    ui->label_50_RateCH3->setText(QString::number(ui_data.rate[7], 'f', 2));
    ui->label_40_RateCH4->setText(QString::number(ui_data.rate[6], 'f', 2));

    ui->label_pwr1->setText(QString::number(ui_data.powerInfo, 'f', 2));
    ui->label_mode1->setText(ui_data.ctrl_type_info);
    ui->label_status1->setText(ui_data.chan_info);
    ui->label_procStatus->setText(ui_data.proc_info);
    ui->label_layer_th->setText(QString::number(ui_data.thickness_layer[1], 'f', 2));

    ui->label_powerCH2->setText(ui_data.procState);

    //qDebug( "ui_data.thickness_layer[1] is %.2f, ui_data.layerTHAcheived is %d", ui_data.thickness_layer[1],ui_data.layerTHAcheived);

    //if((ui_data.layerTHAcheived == 1) || (ui_data.thickness_layer[1] >= ui->label_layer_th_setval->text().toFloat())) {
    //    static int kz =0;
    //    emit sigThicknessAchieved();
    //    qDebug( "emit sigThicknessAchieved() %d", ++kz);
    //}

    //switch (thState) {
    //
    //    case th_normal:
    //        if(ui_data.thickness_layer[1] >= ui->label_layer_th_setval->text().toFloat())
    //        {
    //            thState = th_achieved_once;
    //        }
    //        break;
    //
    //    case th_achieved_once:
    //        static int kz =0;
    //        emit sigThicknessAchieved();
    //        thState = th_achieved_more;
    //        qDebug( "emit sigThicknessAchieved() %d", ++kz);
    //        break;
    //
    //    case th_achieved_more:
    //        if(ui_data.thickness_layer[1] == 0)
    //            thState = th_normal;
    //        break;
    //
    //    default:
    //        break;
    //}


    //kk=!kk;
    //if(kk==1)   ui->label_status1->setText("OFF");
    //if(kk==0)   ui->label_status1->setText(">Pwr");
    //
    //ui->label_status1->repaint();
    //QString::fromWCharArray(ui_data.proc_info,wcslen(ui_data.proc_info));
}

void DialogSpine::CheckYRange(float rate1, float rate2, float rate3, float rate4)
{
    CheckYRangeSub(rate1,0);
    CheckYRangeSub(rate2,1);
    CheckYRangeSub(rate3,2);
    CheckYRangeSub(rate4,3);
}

void DialogSpine::CheckYRangeSub(float rate, int nIndex)
{
    autoYRangePreLocation[nIndex] = yRangeWidgetList[nIndex]->currentIndex();

    for(int i = 0; i < yRangeTotalTypes; i++)
    {
        if(rate > yRangeFactor*yRangeGroup[i] && rate < yRangeFactor*yRangeGroup[i+1])
        {
            if(i+1 != autoYRangePreLocation[nIndex])
            {
                yRangeWidgetList[nIndex]->setCurrentIndex(i+1);
                autoYRangePreLocation[nIndex] = i+1;
                break;
            }

        }
        else if(i ==7 && rate > yRangeGroup[i])
        {
            yRangeWidgetList[nIndex]->setCurrentIndex(i);
            autoYRangePreLocation[nIndex] = i;
        }

        else if(i ==0 && rate < yRangeGroup[i])
        {
            yRangeWidgetList[nIndex]->setCurrentIndex(i);
            autoYRangePreLocation[nIndex] = i;
            break;
        }

    }
}

void DialogSpine::UpdateDeviationLabel()
{
    float currentRate[4];

    currentRate[0] = ui_data.rate[1];
    currentRate[1] = ui_data.rate[9];
    currentRate[2] = ui_data.rate[7];
    currentRate[3] = ui_data.rate[6];

    int nIdx = ui->comboBox_deviation->currentIndex();
    float biasPercentFull =biasPencentGroup[nIdx];

    for(int i =0; i <channelNum; i++)                                //CurrentTestFor3Channels
    {
        biasPercent[i] = (currentRate[i] -setRate[i])/(biasPercentFull*setRate[i]);

        if(qAbs(currentRate[i] -setRate[i]) > biasPercentFull*setRate[i])
        {
            if(biasPercent[i] > 0)
                biasPercent[i] = 1;
            else if(biasPercent[i] < 0)
            {
                biasPercent[i] = -1;
            }
        }
    }

    ui->label_deviation_test->setValue(biasPercent[0]);
    ui->label_deviation_test_2->setValue(biasPercent[1]);
    ui->label_deviation_test_3->setValue(biasPercent[2]);
    ui->label_deviation_test_4->setValue(biasPercent[3]);
}

void DialogSpine::UpdateSpine()
{
//    QList<QPointF> points[4];

//    for(int i=0;i<channelNum;i++)
//        points[i].clear();

//    int index = ui->comboBox_5_change_xRange->currentIndex();

//    switch (index) {
//    case 0:
//        for(int i=0; i < bufferOneMin[0].length(); i++)
//        {
////            points[0].append(QPointF(i,bufferOneMin[0].at(i)));
////            points[1].append(QPointF(i,bufferOneMin[1].at(i)));
////            points[2].append(QPointF(i,bufferOneMin[2].at(i)));
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferOneMin[j].at(i)));
//        }
//        break;
//    case 1:
//        for(int i=0; i < bufferThreeMin[0].length(); i++)
//        {
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferThreeMin[j].at(i)));
//        }
//        break;
//    case 2:
//        for(int i=0; i < bufferTenMin[0].length(); i++)
//        {
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferTenMin[j].at(i)));
//        }
//        break;
//    case 3:
//        for(int i=0; i < bufferThirtyMin[0].length(); i++)
//        {
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferThirtyMin[j].at(i)));
//        }
//        break;
//    case 4:
//        for(int i=0; i < bufferSixtyMin[0].length(); i++)
//        {
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferSixtyMin[j].at(i)));
//        }
//        break;
//    case 5:
//        for(int i=0; i < bufferThreeHour[0].length(); i++)
//        {
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferThreeHour[j].at(i)));
//        }
//        break;
//    case 6:
//        for(int i=0; i < bufferTenHour[0].length(); i++)
//        {
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferTenHour[j].at(i)));
//        }
//        break;
//    case 7:
//        for(int i=0; i < bufferThirtyHour[0].length(); i++)
//        {
//            for(int j=0; j<channelNum;j++)
//                points[j].append(QPointF(i,bufferThirtyHour[j].at(i)));
//        }
//        break;
//    default:
//        qDebug() << "abnormal selection";
//        break;
//    }

    m_series->replace(points[0]);
    m_series_2->replace(points[1]);
    m_series_3->replace(points[2]);
    m_series_4->replace(points[3]);

    UpdateTextLabel();

    if(ui->comboBox_yRangeSel->currentIndex() == 0)    //AutoRangeYIsON
       CheckYRange(ui_data.rate[1],ui_data.rate[9],ui_data.rate[7],ui_data.rate[6]);

    if(ui->comboBox_deviation->currentIndex() != 0)
       UpdateDeviationLabel();
}

//void DialogSpine::on_comboBox_4_ch1Zoom_currentIndexChanged(int index)
//{

//}

void DialogSpine::on_comboBox_ch4Zoom_currentIndexChanged(int index)
{
        float maxY = yRangeGroup[index];
        OutPutInfo("maxY" ,maxY);

        m_axisY4->setRange(-0.1*maxY, maxY);
}

int DialogSpine::GetXRangeIndex()
{
    return ui->comboBox_5_change_xRange->currentIndex();
}

void DialogSpine::FocusToPreWidget()
{
    movingIDX = movingIDX -1 ;

    switch (movingIDX) {
        case 0:
            ui->comboBox_yRangeSel->setFocus();
            break;
        case 1:
            ui->comboBox_deviation->setFocus();
            break;
        case 2:
            ui->comboBox_5_change_xRange->setFocus();
            break;
        case 3:
            ui->comboBox_4_ch1Zoom->setFocus();
            break;
        case 4:
            ui->comboBox_3_ch2Zoom->setFocus();
            break;
        case 5:
            ui->comboBox_2_ch3Zoom->setFocus();
            break;
        case 6:
            ui->comboBox_ch4Zoom->setFocus();
            break;
        case 7:
            ui->pushButton_clr->setFocus();
            break;
        case 8:
            ui->pushButton_exit->setFocus();
            break;
        default:
            break;
    }

//    table->toUpWhole();
}

void DialogSpine::FocusToNextWidget()
{
    movingIDX = movingIDX + 1 ;

    switch (movingIDX) {
        case 0:
            ui->comboBox_yRangeSel->setFocus();
            break;
        case 1:
            ui->comboBox_deviation->setFocus();
            break;
        case 2:
            ui->comboBox_5_change_xRange->setFocus();
            break;
        case 3:
            ui->comboBox_4_ch1Zoom->setFocus();
            break;
        case 4:
            ui->comboBox_3_ch2Zoom->setFocus();
            break;
        case 5:
            ui->comboBox_2_ch3Zoom->setFocus();
            break;
        case 6:
            ui->comboBox_ch4Zoom->setFocus();
            break;
        case 7:
            ui->pushButton_clr->setFocus();
            break;
        case 8:
            ui->pushButton_exit->setFocus();
            break;
        default:
            break;
    }
//    table->toDownWhole();

}
