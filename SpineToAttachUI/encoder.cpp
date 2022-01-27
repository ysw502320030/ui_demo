#include "encoder.h"
#include <QDebug>

encoder *mEncoder;

encoder::encoder()
{
#if __arm__ or 1

    fd=open("/dev/btn_key", O_RDWR);
    if(fd < 0) {
        qDebug() << 10 << "open failed";
        return;
    }

    fd_encoder=open("/dev/input/event2", O_RDWR);
    if(fd_encoder < 0) {
        qDebug() << 10 << "fd_encoder open failed";
        return;
    }

    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    int flagsEncoder = fcntl(fd_encoder, F_GETFL, 0);
    fcntl(fd_encoder, F_SETFL, flagsEncoder | O_NONBLOCK);

//    in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier, &QSocketNotifier::activated,
//    this, &encoder::handle_readNotification);
//
//    in_fifo_notifier_encoder = new QSocketNotifier(fd_encoder, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier_encoder, &QSocketNotifier::activated,
//    this, &encoder::encoder_handler);

    testTimer = new QTimer(this);
    connect(testTimer, &QTimer::timeout, this, &encoder::InitFunc);
    testTimer->setInterval(300);
    testTimer->start();

    encoderTimer = new QTimer(this);
    connect(encoderTimer, &QTimer::timeout, this, &encoder::encoder_handler);
    encoderTimer->setInterval(100);
    encoderTimer->start();

    btnKeyTimer = new QTimer(this);
    connect(btnKeyTimer, &QTimer::timeout, this, &encoder::handle_readNotification);
    btnKeyTimer->setInterval(200);
    btnKeyTimer->start();

//    connect(&encoderTimer, &QTimer::timeout, this, &encoder::encoder_handler);
//    encoderTimer.setInterval(200);
//    encoderTimer.start();

#endif
}

void encoder::InitFunc()
{
//    btnKeyTimer = new QTimer(this);
//    connect(btnKeyTimer, &QTimer::timeout, mEncoder, &encoder::handle_readNotification);
//    btnKeyTimer->setInterval(300);
//    btnKeyTimer->start();

//    encoderTimer = new QTimer(this);
//    connect(encoderTimer, &QTimer::timeout, mEncoder, &encoder::encoder_handler);
//    encoderTimer->setInterval(200);
//    encoderTimer->start();
    qDebug() << "you test here" << "data";

//    ret_encoder = read(fd_encoder, &in_ev, sizeof(struct input_event));
//    if(ret_encoder >= 0){
//        qDebug() << "key is" << in_ev.value;
//
//        if(ret_encoder >= 0){
//            qDebug() << "key is" << in_ev.value;
//
//            if(in_ev.value == 1)
//            {
//                qDebug() << "key is +" << in_ev.value;
//                QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
//                QWidget *widget1 = QApplication::focusWidget();
//                QCoreApplication::postEvent ((QObject*)widget1, event);
////            emit signal_LTurn();
//            }
//            else if(in_ev.value == -1)
//            {
//                qDebug() << "key is -" << in_ev.value;
//                QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_F1, Qt::NoModifier);
//                QWidget *widget1 = QApplication::focusWidget();
//                QCoreApplication::postEvent ((QObject*)widget1, event);
////            emit signal_RTurn();
//            }
//            else
//                ;
//        }
//    }
}

//void encoder::handle_readNotification(int /*socket*/)
void encoder::handle_readNotification()
{
    unsigned char data;

    ret = read(fd, &data, sizeof(data));

    if(ret >= 0){
        qDebug() << "button key is" << data;
//        QMouseEvent *mouseClick = new QMouseEvent(QEvent::MouseButtonPress, QCursor::pos(), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
//        QWidget *widget1 = QApplication::focusWidget();
//        QCoreApplication::postEvent ((QObject*)widget1, mouseClick);

//        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
//        QWidget *widget1 = QApplication::focusWidget();
//        QCoreApplication::postEvent ((QObject*)widget1, event);

        qDebug() << "widget is " << QApplication::focusWidget();

        if(QApplication::focusWidget()->metaObject()->className() == QString("QComboBoxListView") ||
           QApplication::focusWidget()->metaObject()->className() == QString("QMenu")             ||
           QApplication::focusWidget()->metaObject()->className() == QString("QPushButton")          )
        {
            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, event);
        }
        else
        {
            QMouseEvent *mouseClick = new QMouseEvent(QEvent::MouseButtonPress, QCursor::pos(), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, mouseClick);
        }

        qDebug() << "program reach here " << "65";
    }
}

//void encoder::encoder_handler(int /*socket*/)
void encoder::encoder_handler()
{
//    for(int i =0;i<10;i++)
//    {
//        QThread::sleep(1);

        int i =0;

        i=i+1;

        float databuf[16];
    //    struct Data_to_UI ui_data;

        ret_encoder = read(fd_encoder, &in_ev, sizeof(struct input_event));

        if(ret_encoder >= 0){
            qDebug() << "key is" << in_ev.value;

            if(in_ev.value == 1)
            {
                qDebug() << "key is +" << in_ev.value;
                QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
                QWidget *widget1 = QApplication::focusWidget();
                QCoreApplication::postEvent ((QObject*)widget1, event);
//            emit signal_LTurn();
            }
            else if(in_ev.value == -1)
            {
                qDebug() << "key is -" << in_ev.value;
                QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_F1, Qt::NoModifier);
                QWidget *widget1 = QApplication::focusWidget();
                QCoreApplication::postEvent ((QObject*)widget1, event);
//            emit signal_RTurn();
            }
            else
                ;
        }
}
