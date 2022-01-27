#ifndef ENCODER_H
#define ENCODER_H

#include <linux/input.h>
#include <QSocketNotifier>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <QKeyEvent>

#include <QtWidgets/qtwidgetsglobal.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qapplication.h>
#if QT_CONFIG(tabwidget)
#include <QtWidgets/qtabwidget.h>
#endif
#include <QtCore/qcoreapplication.h>
#include <QtCore/QTimer>


class encoder: public QObject
{
    Q_OBJECT

public:
    encoder();

public:
    int fd,fd_encoder;
    int ret = 0,ret_encoder=0;
    struct input_event in_ev = {};
    QTimer *encoderTimer, *btnKeyTimer, *testTimer;
//    QTimer encoderTimer;
//    QTimer btnKeyTimer;

signals:
    void signal_LTurn();
    void signal_RTurn();

public:
    QSocketNotifier *in_fifo_notifier;
    QSocketNotifier *in_fifo_notifier_encoder;
//    void encoder_handler(int socket);
//    void handle_readNotification(int socket);
public slots:
    void encoder_handler();
    void handle_readNotification();
    void InitFunc();

};

extern encoder *mEncoder;

#endif // ENCODER_H
