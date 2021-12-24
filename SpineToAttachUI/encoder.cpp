#include "encoder.h"
#include <QDebug>

encoder *mEncoder;

encoder::encoder()
{
#if __arm__

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

    in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
    connect(in_fifo_notifier, &QSocketNotifier::activated,
    this, &encoder::handle_readNotification);

    in_fifo_notifier_encoder = new QSocketNotifier(fd_encoder, QSocketNotifier::Read, this);
    connect(in_fifo_notifier_encoder, &QSocketNotifier::activated,
    this, &encoder::encoder_handler);

#endif
}

void encoder::handle_readNotification(int /*socket*/)
{
    unsigned char data;

    ret = read(fd, &data, sizeof(data));

    if(ret >= 0){
        qDebug() << "button key is" << data;
        QMouseEvent *mouseClick = new QMouseEvent(QEvent::MouseButtonPress, QCursor::pos(), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
        QWidget *widget1 = QApplication::focusWidget();
        QCoreApplication::postEvent ((QObject*)widget1, mouseClick);
    }
}

void encoder::encoder_handler(int /*socket*/)
{
//    for(int i =0;i<10;i++)
//    {
//        QThread::sleep(1);

        int i =0;

        i=i+1;

        float databuf[16];
    //    struct Data_to_UI ui_data;

        ret_encoder = read(fd_encoder, &in_ev, sizeof(struct input_event));

//        if(ret_encoder >= 0){
//            qDebug() << "key is" << in_ev.value;
//        }

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
