#include "datathread.h"

Datathread *worker = new Datathread;
QThread *mthread = new QThread();
//worker->moveToThread(mthread);

Datathread::Datathread(): QObject()
{
//    QObject::connect(&m_timer, &QTimer::timeout, this, &Datathread::DataSamplingTimerFunc);
//    m_timer.setInterval(120);
//    m_timer.start();

//    qDebug()<<"thread auto run"<<endl;
//    emit test_signal();
//   mspine = new DialogSpine;
//    mtable = new DialogTable();

//    Datathread *worker = new Datathread;
//    QThread *mthread = new QThread();
//    worker->moveToThread(mthread);
}

void Datathread::dataObtained()
{
    static float i=0;
    i=i+0.1;

    //read fifo data and emit signal to show spine
    ret = read(fd, &ui_data, sizeof(ui_data));
    if(ret >= 0){
        qDebug() << 11 << ui_data.freq_new_raw[8];
            init_display_queue(q);
//        if(q.size()<=3)
//        {
//            q.enqueue(ui_data);
//            qDebug() << 12 << &q.head();
//        }
    }
//    textEdit->append(QString::number(ui_data.freq_new_raw[8]));


//    static int count =0;
//    static float zi = 0;
//    zi = zi+0.1;
//    qreal x = chart->plotArea().width() / m_axisX->tickCount();
//    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
//    m_x += y;
////	  m_y = QRandomGenerator::global()->bounded(5) - 2.5;
//    m_y = ui_data.rate[8];
//    m_series->append(m_x, m_y);
//    if (count++ >= m_axisX->tickCount())
//        chart->scroll(x, 0);
//    if (m_x == 100)
//        m_timer.stop();
//    while(1)
//    {
        emit test_signal();
//        QThread::msleep(100);
//    }

}

void Datathread::init_notifier()
{
    #if __arm__
        fd=::open("/temp_using/topeet", O_RDWR);
//        in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//        connect(in_fifo_notifier, &QSocketNotifier::activated,
//            this, &Datathread::dataObtained);
    #else
        fd=::open("/home/alientek/other/code/Qt/02/01_qfile/topeet", O_RDWR);
//        int flags = fcntl(fd, F_GETFL, 0);
//        fcntl(fd, F_SETFL, flags | O_NONBLOCK);

//        in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//        connect(in_fifo_notifier, &QSocketNotifier::activated,
//            this, &Datathread::dataObtained);
    #endif

    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    m_timer = new QTimer(this);
    QObject::connect(m_timer, &QTimer::timeout, this, &Datathread::DataSamplingTimerFunc);
    m_timer->setInterval(120);
    m_timer->start();

//    while(1)
//    {
//        ret = read(fd, &ui_data, sizeof(ui_data));
//        if(ret >= 0){
////            qDebug() << 11 << ui_data.freq_new_raw[8];
//            emit test_signal();
//        }

//        QThread::msleep(100);

//    }

//    connect(this,                             // emitter
//        &Datathread::test_signal,       // signal
//        mspine,                                // receiver
//        &DialogSpine::inform_handleTimeout);  // slot


//        connect(this,                             // emitter
//            &Datathread::signal_to_table,       // signal
//            mtable,                                // receiver
//            &DialogTable::TableNotUpdate);  // slot
}

void Datathread::init_display_queue(QQueue<Data_to_UI> &myQueue)
{
//     if(q.size()<=3)
//     {
//         q.enqueue(ui_data);
//         qDebug() << 12 << &q.head();
//     }
//     if(q.size() == 4)
//     {
//         //display the 4 node to table
         emit signal_to_table();
//         //delete the end,ie.the oldest one
////         myQueue.dequeue();
//     }
}

void Datathread::DataSamplingTimerFunc()
{
    static long samplingTimerCount = 0;

    static float rateToSend[4];

    samplingTimerCount++;

    ret = read(fd, &ui_data, sizeof(ui_data));
    if(ret >= 0){
        qDebug() << "new freq is" <<  QString::number(ui_data.rate[8], 'f', 3);
        rateToSend[0] = ui_data.rate[8];
        rateToSend[1] = ui_data.rate[9];
        rateToSend[2] = ui_data.rate[7];
        rateToSend[3] = ui_data.rate[6];
    }
    else
    {
        qDebug() << "old freq is" <<  QString::number(rateToSend[0], 'f', 3);
    }

//    bufferOneMin.append(frequencyToSend[0]);
//    bufferOneMin_2.append(frequencyToSend[1]);
//    bufferOneMin_3.append(frequencyToSend[2]);

    for(int i=0;i<channelNum;i++)
        bufferOneMin[i].append(rateToSend[i]);
    
    if(bufferOneMin[0].length()>pointsNumForOneLine+1)
    {
//        bufferOneMin.removeFirst();
//        bufferOneMin_2.removeFirst();
//        bufferOneMin_3.removeFirst();

        for(int i=0;i<channelNum;i++)
            bufferOneMin[i].removeFirst();
    }

    if(samplingTimerCount % 3 == 0)
    {
        for(int i=0;i<channelNum;i++)
            bufferThreeMin[i].append(rateToSend[i]);

        if(bufferThreeMin[0].length()>pointsNumForOneLine+1)
        {
            for(int i=0;i<channelNum;i++)
                bufferThreeMin[i].removeFirst();
        }
    }
    
    if(samplingTimerCount % 10 == 0)
    {
        for(int i=0;i<channelNum;i++)
            bufferTenMin[i].append(rateToSend[i]);

        if(bufferTenMin[0].length()>pointsNumForOneLine+1)
        {
            for(int i=0;i<channelNum;i++)
                bufferTenMin[i].removeFirst();
        }
    }

    if(samplingTimerCount % 30 == 0)
    {
        for(int i=0;i<channelNum;i++)
            bufferThirtyMin[i].append(rateToSend[i]);

        if(bufferThirtyMin[0].length()>pointsNumForOneLine+1)
        {
            for(int i=0;i<channelNum;i++)
                bufferThirtyMin[i].removeFirst();
        }
    }

    if(samplingTimerCount % 60 == 0)
    {
        for(int i=0;i<channelNum;i++)
            bufferSixtyMin[i].append(rateToSend[i]);

        if(bufferSixtyMin[0].length()>pointsNumForOneLine+1)
        {
            for(int i=0;i<channelNum;i++)
                bufferSixtyMin[i].removeFirst();
        }
    }

    if(samplingTimerCount % 180 == 0)
    {
        for(int i=0;i<channelNum;i++)
            bufferThreeHour[i].append(rateToSend[i]);

        if(bufferThreeHour[0].length()>pointsNumForOneLine+1)
        {
            for(int i=0;i<channelNum;i++)
                bufferThreeHour[i].removeFirst();
        }
    }

    if(samplingTimerCount % 600 == 0)
    {
        for(int i=0;i<channelNum;i++)
            bufferTenHour[i].append(rateToSend[i]);

        if(bufferTenHour[0].length()>pointsNumForOneLine+1)
        {
            for(int i=0;i<channelNum;i++)
                bufferTenHour[i].removeFirst();
        }
    }

    if(samplingTimerCount % 1800 == 0)
    {
        for(int i=0;i<channelNum;i++)
            bufferThirtyHour[i].append(rateToSend[i]);

        if(bufferThirtyHour[0].length()>pointsNumForOneLine+1)
        {
            for(int i=0;i<channelNum;i++)
                bufferThirtyHour[i].removeFirst();
        }
    }

    qDebug() << "samplingTimerCount" << samplingTimerCount;

    qDebug() << "bufferOneMin" << bufferOneMin[0];
    qDebug() << "bufferThreeMin" << bufferThreeMin[0];
    qDebug() << "bufferTenMin" << bufferTenMin[0];
    qDebug() << "bufferThirtyMin" << bufferThirtyMin[0];
    qDebug() << "bufferSixtyMin" << bufferSixtyMin[0];
    qDebug() << "bufferThreeHour" << bufferThreeHour[0];
    qDebug() << "bufferTenHour" << bufferTenHour[0];
    qDebug() << "bufferThirtyHour" << bufferThirtyHour[0];

}

