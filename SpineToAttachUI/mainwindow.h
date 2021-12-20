#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogspine.h"
#include "dialogtable.h"
#include "dialogtable2.h"
#include "encoder.h"
#include <QThread>

#include <QKeyEvent>
#include <linux/input.h>

#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int firstIndex=0;

//public:
//    //重写实现按键事件
//    void keyPressEvent(QKeyEvent *e);

public slots:
    void ChooseWidgets();
    void pushButton2Clicked();
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;
    QTimer m_timer;

public:
    QThread qThread;

public:
    int fd,fd_encoder;
    int ret = 0,ret_encoder=0;
    struct input_event in_ev = {};

    QMenu *menu = new QMenu();
    QMenu *menu_2 = new QMenu();
    QMap<QMenu*, QPushButton*> map;

private:
    QSocketNotifier *in_fifo_notifier;
    QSocketNotifier *in_fifo_notifier_encoder;
    void encoder_handler();

//    struct Data_to_UI ui_data;
//    struct Data_to_UI *ui_data2;

//    QSocketNotifier *in_fifo_notifier;

//    int ret = 0;
//    int fd;

//    QQueue<Data_to_UI > q ;

signals:
    /* 工人开始工作（做些耗时的操作 ） */
    void startWork(const QString &);
    void startWork_test();
};
#endif // MAINWINDOW_H
